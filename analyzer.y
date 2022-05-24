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

%token _NEW_LINE
%token _INDENT
%token _AND
%token _AS
%token _BREAK
%token _CONTINUE
%token _DEF
%token _ELIF
%token _ELSE
%token _EXCEPT
%token _FINALLY
%token _FALSE
%token _FOR
%token _FROM
%token _IF
%token _IMPORT
%token _IN
%token _IS
%token _NONE
%token _NOT
%token _OR
%token _PASS
%token _RETURN
%token _TRUE
%token _TRY
%token _WHILE

%token _COMMA
%token _COLON

%token _LPAREN
%token _RPAREN
%token _ASSIGN

%token _PL
%token _MIN
%token _MUL
%token _DIV

%token _LS
%token _GR
%token _LS_EQ
%token _GR_EQ
%token _EQ
%token _NEQ

%token _ID
%token _INT
%token _FLOAT
%token _STRING

%define parse.error verbose
%%

file
	: /* empty */
	| new_line_start
	| statement_list _NEW_LINE
	;

statement_list
	: statement 
	| statement_list statement 
	;

statement
	: simple_statement 
		{
			if (currIndentLvl != indentCount)
				err(500, "Indentation error!");
			indentCount = 0;
		}
	| new_line_start simple_statement
	| compound_statement
	| new_line_start compound_statement
	;

simple_statement
	: assign_statement
	;

compound_statement
	: _RETURN
	;
	
assign_statement
	: _ID _ASSIGN num_exp 
	; 

new_line_start
	: _NEW_LINE 
	| new_line_start _INDENT
		{
			indentCount++;
		}
	;
  
num_exp
	: exp
	/* ovde ce ici relacioni operator */
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
