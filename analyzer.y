%{
	#include <stdio.h>
	#include <stdbool.h>
	#include "defs.h"
	#include "symtab.h"

	int yylex(void);
	int yyparse(void);
	int yyerror(const char *);
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
	int defParamNum = 0;
	int nonDefParamNum = 0;
	bool hasReturn = false;
	int argsNum = 0;
	
  
  
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
	| return_statement	{ hasReturn = true; }
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
        	if (get_kind(index) == FUN)
        		insert_symbol($1, VAR, $3, NO_ATR, NO_ATR, scope);
      }
	; 

return_statement
	: _RETURN
		{
			if (currFuncInd < 0)
				err("'return' must be inside a function definition!");
			int funcInd = funcInds[currFuncInd];
			if(hasReturn && get_type(funcInd) != NONE)
				set_type(funcInd, UNKNOWN);			
		}
	| _RETURN num_exp
		{
			if (currFuncInd < 0)
				err("'return' must be inside a function definition!");
			int funcInd = funcInds[currFuncInd];
			if(hasReturn && get_type(funcInd) != $2)
				set_type(funcInd, UNKNOWN);
			else if(!hasReturn)
				set_type(funcInd, $2);
		}
	;

function_call
	: _ID _LPAREN arguments _RPAREN
      {
        int funcInd = lookup_symbol_all_kinds($1);
        if (funcInd == NO_INDEX || get_kind(funcInd) != FUN)
           err("There is no defined function of name %s", $1);
          
        int nonDefParams = get_atr1(funcInd);
        int defParams = get_atr2(funcInd);
        if (argsNum > nonDefParams+defParams)
        	err("Function given more arguments than the definition has parameters!");
        else if (argsNum < nonDefParams)
        	err("Function given less arguments than the definition has non deafult parameters!");

      	$$ = get_type(funcInd);
      }
	;
	
arguments
	: /* no arguments */
	| arguments args { argsNum++; }
	;
	
args
	: num_exp
	| _COMMA num_exp
	;

function_def
	: _DEF _ID 
		{
		    currFuncInd++;
			funcInds[currFuncInd] = insert_symbol($2, FUN, NONE, NO_ATR, NO_ATR, scope);
	  		scope++;
		}
	  _LPAREN parameters _RPAREN _COLON _NEW_LINE 
		{
			set_atr1(funcInds[currFuncInd], nonDefParamNum);
			set_atr2(funcInds[currFuncInd], defParamNum);
	    	nonDefParamNum = 0;
	    	defParamNum = 0;
		}	
	  body 
	  	{
		    clear_symbols(funcInds[currFuncInd] + 1);
		    currFuncInd--;
		    scope--;
		    hasReturn = false;
	  	}
	;

parameters 
	: /* no params */
	| _ID  						
		{ 
			insert_symbol($1, PAR, UNKNOWN, NO_ATR, NO_ATR, scope);
			nonDefParamNum++; 
		}
	| param_with_default_val
	| parameters _COMMA _ID		
		{
			if (valuedParamDef)
				err("Parameters without default values cannot be defined after parameter with set default value.");

			insert_symbol($3, PAR, UNKNOWN, NO_ATR, NO_ATR, scope);
			nonDefParamNum++; 
		}
	| parameters _COMMA param_with_default_val
	;
	
param_with_default_val
	: _ID _ASSIGN num_exp
		{
			insert_symbol($1, PAR, UNKNOWN, NO_ATR, NO_ATR, scope);
			valuedParamDef = true;
			defParamNum++;
		}
	;

if_statement
	: if_part elif_part else_part
	;

if_part
	: _IF num_exp _COLON _NEW_LINE
		{
			$<i>$ = get_last_element()+1; 
			scope++;
		}
	 body
		{
			clear_symbols($<i>5);	
			scope--;
		}
	;
	
elif_part
	: /* no elif part*/
	| elif_part _ELIF num_exp _COLON _NEW_LINE
		{
			$<i>$ = get_last_element()+1; 
			scope++;
		}
	 body
		{
			clear_symbols($<i>6);	
			scope--;
		}

	;

while_statement
	: while_part else_part
	;

while_part
	: _WHILE num_exp _COLON _NEW_LINE 
		{
			$<i>$ = get_last_element()+1; 
			scope++;
			loopCounter++;
		}
	  body
		{
			clear_symbols($<i>5);	
			scope--;
			loopCounter--;
		}
	;

try_except_statement
	: try_part except_part finally_or_else_part
	;

try_part
	: _TRY _COLON _NEW_LINE 
		{
			$<i>$ = get_last_element()+1; 
			scope++;
			loopCounter++;
		}
	  body
		{
			clear_symbols($<i>4);	
			scope--;
			loopCounter--;
		} 
	;

except_part
	: /* no except block */
	| except_part _EXCEPT _ID
	  	{
  	      	int index = lookup_symbol_all_kinds($3);
		    if(index == NO_INDEX)
		       insert_symbol($3, VAR, UNKNOWN, NO_ATR, NO_ATR, scope);
		    else 
		    	if (get_kind(index) == FUN)
		    		insert_symbol($3, VAR, UNKNOWN, NO_ATR, NO_ATR, scope);
	  	}
	  except_finally_body
	| except_part _EXCEPT except_finally_body
	;

except_finally_body
	: _COLON _NEW_LINE
		{
			$<i>$ = get_last_element()+1; 
			scope++;
			loopCounter++;
		}
	  body
		{
			clear_symbols($<i>3);	
			scope--;
			loopCounter--;
		}
	;
finally_or_else_part
	: /* no else or finally part */
	| _FINALLY except_finally_body
	| _ELSE except_finally_body
	;

else_part
	: /* no else part*/
	|_ELSE _COLON _NEW_LINE 
		{
			$<i>$ = get_last_element()+1; 
			scope++;
		}
	 body
		{
			clear_symbols($<i>4);	
			scope--;
		}
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
			int idInd = lookup_symbol_var_par($1);
			if (idInd == NO_INDEX)
				err("Variable '%s' does not exist!", $1);
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
