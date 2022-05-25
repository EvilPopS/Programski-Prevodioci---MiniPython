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
%token _FINALLY _FALSE _FOR _FROM
%token _IF _IMPORT _IN _IS
%token _NONE _NOT
%token _OR
%token _PASS
%token _RETURN
%token _TRUE _TRY
%token _WHILE

%token _COMMA _COLON

%token _LPAREN _RPAREN
%token _ASSIGN

%token _AROP

%token _RELOP

%token _ID
%token _INT
%token _FLOAT
%token _STRING

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
	;

compound_statement
	: if_statement
	;
	
assign_statement
	: _ID _ASSIGN num_exp
	; 

if_statement
	: if_part elif_part else_part
	;

if_part
	: _IF rel_exp _COLON _NEW_LINE body
	;
	
elif_part
	: /* no elif part*/
	| elif_part elif_statement
	;

elif_statement
	: _ELIF rel_exp _COLON _NEW_LINE body
	;
	
else_part
	: /* no else part*/
	|_ELSE _COLON _NEW_LINE body
	;

body
	: _INDENT statement_list _DEDENT
	;
		
rel_exp
	: num_exp _RELOP num_exp
	;
  
num_exp
	: exp
	| num_exp _AROP exp
	/* Ja mislim da treba i za _RELOP jer to vraca boolean tip */
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
	;
	
%%

int main() {
  yyparse();
}

int yyerror(const char *s) {
  fprintf(stderr, "line %d: SYNTAX ERROR %s\n", yylineno, s);
} 
