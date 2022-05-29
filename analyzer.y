%{
	#include <stdio.h>
	#include <stdbool.h>
	#include "defs.h"
	#include "symtab.h"

	int yylex(void);
	int yyparse(void);
	int yyerror(const char *);
	void throwErr(const char *);
	extern int yylineno;
	int error_count = 0;
	unsigned scope = 0;

	char char_buffer[CHAR_BUFFER_LENGTH];

	// Broji u koliko se ugnjezdenih petlja nalazi pa na osnovu toga dozvoljava ( >0 ) odnosno ne dozvoljava ( ==0) 'break' ili 'continue
	int loopCounter = 0;

	// Kod definisanja funkcije parametri bez definisane vrednosti ne smeju da se nalaze posle param sa def vrednostima
	bool valuedParamDef = false;

	int funcInds[32]; 
	int currFuncInd = -1; 
	int paramNum = 0;
	
  
  
%}

%union {
  int i;
  char *s;
}

%token _NEW_LINE _INDENT _DEDENT 

%token _AND
%token _BREAK
%token _CONTINUE
%token _DEF
%token _ELIF _ELSE _EXCEPT
%token _FINALLY _FOR
%token _IF _IN
%token _NOT
%token _OR
%token _PASS
%token _RETURN
%token _TRY
%token _WHILE

%token _COMMA _COLON

%token _LPAREN _RPAREN
%token _ASSIGN

%token <i> _ADD_SUB_OP _MUL_DIV_OP _LOP _RELOP

%token <s> _ID
%token <i> _NUM_BOOL _STRING _NONE


%type <i> num_exp exp function_call literal


%define parse.error verbose


%nonassoc VAR_ID 
%nonassoc _LPAREN

%left _LOP
%right _NOT
%left _RELOP
%left _ADD_SUB_OP
%left _MUL_DIV_OP 

%%

file
	: /* empty */ 
	| statement_list
	| _NEW_LINE statement_list
	;

statement_list
	: statement 
	| statement_list statement 
	;

statement
	: simple_statement _NEW_LINE
	| compound_statement
	;

simple_statement
	: assign_statement
	| return_statement
		{
			if (currFuncInd < 0)
				err("'return' must be inside a function definition!");
		}
	| function_call
	| _BREAK
		{
			if (loopCounter == 0)
				err("'break' must be inside while statement!");
		}
	| _CONTINUE
		{
			if (loopCounter == 0)
				err("'continue' must be inside while statement!");
		}
	| _PASS
	;

compound_statement
	: function_def
	| if_statement
	| while_statement
	| try_except_statement
	;
	
assign_statement
	: _ID _ASSIGN num_exp
      {
      	int index = lookup_symbol_all_kinds($1);
        if(index == NO_INDEX)
           insert_symbol($1, VAR, $3, NO_ATR, NO_ATR, scope);
        else 
        	if (get_kind(index) == FUN || get_scope(index) != scope)
        		insert_symbol($1, VAR, $3, NO_ATR, NO_ATR, scope);
      }
	; 

return_statement
	: _RETURN
	| _RETURN num_exp
	;

function_call
	: _ID _LPAREN arguments _RPAREN
      {
        int funcInd = lookup_symbol($1, VAR|PAR);
        if(funcInd == NO_INDEX && get_kind(funcInd))
           err("There is no defined function of name %s", $1);
      	$$ = get_type(funcInd);
      }
	;
	
arguments
	: /* no arguments */
	| arguments args 
	;
	
args
	: num_exp
	| args _COMMA num_exp
	;

function_def
	: _DEF _ID 
		{
		    currFuncInd++;
			funcInds[currFuncInd] = insert_symbol($2, FUN, UNKNOWN, NO_ATR, NO_ATR, scope);
		}
	  _LPAREN parameters _RPAREN _COLON _NEW_LINE 
		{
			set_atr1(funcInds[currFuncInd], paramNum);
	    	paramNum = 0;
	  		scope++;
		}	
	  body 
	  	{
				print_symtab();
	  	        clear_symbols(funcInds[currFuncInd] + 1);
	  	        currFuncInd--;
	  	        scope--;
	  	}
	;

parameters 
	: /* no params */
	| _ID  						
		{ 
			insert_symbol($1, PAR, UNKNOWN, NO_ATR, NO_ATR, scope+1);
			paramNum++; 
		}
	| param_with_default_val	{ paramNum++; }
	| parameters _COMMA _ID		
		{
			if (valuedParamDef)
				throwErr("Parameters without default values cannot be defined after parameter with set default value.");

			insert_symbol($3, PAR, UNKNOWN, NO_ATR, NO_ATR, scope+1);
			paramNum++; 
		}
	| parameters _COMMA param_with_default_val 	{ paramNum++; }
	;
	
param_with_default_val
	: _ID _ASSIGN num_exp
		{
			insert_symbol($1, PAR, UNKNOWN, NO_ATR, NO_ATR, scope+1);
			valuedParamDef = true;
		}
	;

if_statement
	: if_part elif_part else_part
	;

if_part
	: _IF num_exp _COLON _NEW_LINE body
	;
	
elif_part
	: /* no elif part*/
	| elif_part _ELIF num_exp _COLON _NEW_LINE body
	;

while_statement
	: while_part else_part
	;

while_part
	: _WHILE num_exp _COLON _NEW_LINE 
		{
			loopCounter++;
		}
	  body
		{
			loopCounter--;
		}
	;

try_except_statement
	: try_part except_part finally_or_else_part
	;

try_part
	: _TRY _COLON _NEW_LINE body 
	;

except_part
	: /* no except block */
	| except_part _EXCEPT _ID _COLON _NEW_LINE body
	| except_part _EXCEPT _COLON _NEW_LINE body
	;
	
finally_or_else_part
	: /* no else or finally part */
	| _FINALLY _COLON _NEW_LINE body
	| _ELSE _COLON _NEW_LINE body
	;

else_part
	: /* no else part*/
	|_ELSE _COLON _NEW_LINE body
	;

body
	: _INDENT statement_list _DEDENT
	;
		

num_exp
	: exp       	{ $$ = $1; }
	| _NOT num_exp  { $$ = NUM_BOOL; }
	| num_exp _ADD_SUB_OP num_exp
		{
			int lt = $1;
			int rt = $3;

			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Invalid operator for operands of type 'None'!");
				else if (lt == STRING && rt == STRING) {
					if ($2 == SUB)
						err("Invalid operator '-' for operands of type 'string' and 'string'!");
					$$ = STRING;
				}
				else if (lt == NUM_BOOL && rt == NUM_BOOL)
					$$ = NUM_BOOL;
				else
					err("Invalid operator '+'/'-' for operands of type 'number'/'boolean' and 'string'!");
			}
			else 
				$$ = UNKNOWN;
		}
	| num_exp _MUL_DIV_OP num_exp
		{
			int lt = $1;
			int rt = $3;

			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Invalid operator for operands of type 'None'!");
				else if (lt == STRING && rt == STRING)
					err("Invalid operator for operands of type 'string' and 'string'!");
				else if ((lt == NUM_BOOL && rt == STRING) || (lt == STRING && rt == NUM_BOOL)) {
					if ($2 == DIV)
						err("Invalid operator for operands of type 'string' and 'number'/'boolean'!");
					$$ = STRING;
				}
				else
					$$ = NUM_BOOL;
			}
			else 
				$$ = UNKNOWN;
		}	
	| num_exp _LOP num_exp
		{
			int lt = $1;
			int rt = $3;

			if ($2 == AND)
				return rt;
			else 
				return lt;			
		}
	| num_exp _RELOP num_exp
		{
			int lt = $1;
			int rt = $3;

			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Invalid operator for operands of type 'None'!");
				else if ((lt == NUM_BOOL && rt == STRING) || (lt == STRING && rt == NUM_BOOL))
					err("Invalid operator for operands of type 'number'/'boolean' and 'string'!");
				else
					$$ = NUM_BOOL;
			}
			else 
				$$ = UNKNOWN;
		}
	;
	
exp
	: literal	 { $$ = $1; }
	| _ID %prec VAR_ID
		{
			int idInd = lookup_symbol($1, VAR|PAR);
			if (idInd == NO_INDEX)
				err("Variable %s does not exist!", $1);
			$$ = get_type(idInd); 
		}
	| function_call		{ $$ = $1; }
	| _LPAREN num_exp _RPAREN	{ $$ = $2; }
	;
	
literal
	: _NUM_BOOL	{ $$ = $1; }
	| _STRING	{ $$ = $1; }
	| _NONE		{ $$ = $1; }
	;

	
%%

int main() {
	int synerr;
	init_symtab();

	synerr = yyparse();

	clear_symtab();

	if(synerr)
		return -1; 
	else
		return error_count; 
}
int yyerror(const char *s) {
  fprintf(stderr, "line %d: SYNTAX ERROR %s\n", yylineno, s);
  error_count++;
  return 0;
}
