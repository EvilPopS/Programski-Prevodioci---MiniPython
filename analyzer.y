%{
  #include <stdio.h>
  #include <err.h>
  int yylex(void);
  int yyparse(void);
  int yyerror(const char *);
  extern int yylineno;
  
  int currIndentLvl = 0;
  int indentCount = 0;
%}

%union {
  int i;
  char *s;
}

%token _NEW_LINE _INDENT _DEDENT 

%token _AND _AS
%token _BREAK
%token _CONTINUE
%token _DEF
%token _ELIF _ELSE _EXCEPT
%token _FINALLY _FALSE _FOR
%token _IF _IN _IS
%token _NONE _NOT
%token _OR
%token _PASS
%token _RETURN
%token _TRUE _TRY
%token _WHILE

%token _COMMA _COLON

%token _LPAREN _RPAREN
%token _ASSIGN

%token _AROP _LOP _RELOP

%token _ID
%token _INT _FLOAT _STRING _BOOL

%define parse.error verbose
%%

file
	: /* empty */
	| statement_list
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
	| _BREAK /* postavicemo counter za while loop koji broji u koliko petlji se nalazi kompajler i dok nije 0 moze da stoji break*/
	| _CONTINUE /* isto ko za break, isti brojac */
	| _PASS
	;

compound_statement
	: if_statement
	| while_statement
	| try_except_statement
	;
	
assign_statement
	: _ID _ASSIGN num_exp
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
	: _WHILE num_exp _COLON _NEW_LINE body
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
	| _ID
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
