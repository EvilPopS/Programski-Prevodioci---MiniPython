%{
  #include <stdio.h>
  #include <err.h>
  #include <stdbool.h>
  
  int yylex(void);
  int yyparse(void);
  int yyerror(const char *);
  void throwErr(const char *);
  extern int yylineno;
  char startErrMess[] = "Error on line: " ;
  
  // Broji u koliko se ugnjezdenih petlja nalazi pa na osnovu toga dozvoljava ( >0 ) odnosno ne dozvoljava ( ==0) 'break' ili 'continue
  int loopCounter = 0;
  
  // Kod definisanja funkcije parametri bez definisane vrednosti ne smeju da se nalaze posle param sa def vrednostima
  bool valuedParamDef = false;
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
%token _IF _IN _IS
%token _NONE _NOT
%token _OR
%token _PASS
%token _RETURN
%token _TRY
%token _WHILE

%token _COMMA _COLON

%token _LPAREN _RPAREN
%token _ASSIGN

%token _AROP _LOP _RELOP

%token _ID
%token _INT _FLOAT _STRING _BOOL

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
	; 

return_statement
	: _RETURN
	| _RETURN num_exp
	;

function_call
	: _ID _LPAREN arguments _RPAREN 
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
	: num_exp_start
	| num_exp _AROP num_exp_start
	| num_exp _LOP num_exp_start
	| num_exp _RELOP num_exp_start
	;

num_exp_start
	: negation exp  
	;

negation
	: /* no negation */
	| negation _NOT
	;
	
exp
	: literal
	| _ID %prec VAR_ID
	| function_call  
	| _LPAREN num_exp _RPAREN
	;
	
literal
	: _INT 
	| _FLOAT
	| _STRING
	| _BOOL
	| _NONE
	;

	
%%

int main() {
  yyparse();
}

int yyerror(const char *s) {
  fprintf(stderr, "line %d: SYNTAX ERROR %s\n", yylineno, s);
} 

void throwErr(const char* mess) {
	err(500, "%s%d >> %s", startErrMess, yylineno, mess);
}
