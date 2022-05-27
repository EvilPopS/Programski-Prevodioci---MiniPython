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
  
  char char_buffer[CHAR_BUFFER_LENGTH];

  // Broji u koliko se ugnjezdenih petlja nalazi pa na osnovu toga dozvoljava ( >0 ) odnosno ne dozvoljava ( ==0) 'break' ili 'continue
  int loopCounter = 0;
  
  // Kod definisanja funkcije parametri bez definisane vrednosti ne smeju da se nalaze posle param sa def vrednostima
  bool valuedParamDef = false;
  
  int funcInds[32];
  int funcCounter = -1;
  
  
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

%token <i> _AROP _LOP _RELOP

%token <s> _ID
%token <s> _NUM_BOOL _STRING _NONE


%type <i> num_exp num_exp_start exp function_call literal


%define parse.error verbose

%nonassoc VAR_ID 
%nonassoc _LPAREN

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
	| function_call
	| _BREAK
		{
			if (loopCounter == 0)
				throwErr("'break' must be inside while statement!");
		}
	| _CONTINUE
		{
			if (loopCounter == 0)
				throwErr("'continue' must be inside while statement!");
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
        if(lookup_symbol($1, VAR|PAR) == NO_INDEX)
           insert_symbol($1, VAR, $3, NO_ATR, NO_ATR);
      }
	; 

return_statement
	: _RETURN
	| _RETURN num_exp
	;

function_call
	: _ID _LPAREN arguments _RPAREN
      {
        int funcInd = lookup_symbol($1, FUN);
        if(funcInd == NO_INDEX)
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
	: _DEF _ID _LPAREN parameters _RPAREN _COLON _NEW_LINE body
	;

parameters 
	: /* no params */
	| _ID 
	| param_with_default_val
	| parameters _COMMA _ID
		{
			if (valuedParamDef)
				throwErr("Parameters without default values cannot be defined after parameter with set default value.");
		}
	| parameters _COMMA param_with_default_val
	;
	
param_with_default_val
	: _ID _ASSIGN num_exp
		{
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
	: num_exp_start { $$ = $1; }
	| num_exp _AROP num_exp_start
		{
			int lt = get_type($1);
			int rt = get_type($3);

			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Cannot operate with values of type 'None'!");
				else if (lt == STRING && rt == STRING) {
					if ($2 != ADD)
						err("Cannot apply '-', '/' or '*' on strings, only '+'!");
					$$ = STRING;
				}
				else if ((lt == NUM_BOOL && rt == STRING) || (lt == STRING && rt == NUM_BOOL)) {
					if ($2 != MUL)
						err("Cannot apply '-', '/' or '+' on strings, only '*'!");
					$$ = STRING;
				}
				else
					$$ = NUM_BOOL;
			}
			else 
				$$ = UNKNOWN;
		}
	| num_exp _LOP num_exp_start
		{
		
		}
	| num_exp _RELOP num_exp_start
	;

num_exp_start
	: negation exp  { $$ = $2; }
	;

negation
	: /* no negation */
	| negation _NOT
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
	: _NUM_BOOL	{ $$ = insert_literal($1, NUM_BOOL); }
	| _STRING	{ $$ = insert_literal($1, STRING); }
	| _NONE		{ $$ = insert_literal($1, NONE); }
	;

	
%%

int main() {
  yyparse();
}

int yyerror(const char *s) {
  fprintf(stderr, "line %d: SYNTAX ERROR %s\n", yylineno, s);
} 

void throwErr(const char* mess) {
	err("Error on line: %d >> %s", yylineno, mess);
}
