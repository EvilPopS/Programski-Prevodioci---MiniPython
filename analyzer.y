%{
  #include <stdio.h>
  int yylex(void);
  int yyparse(void);
  int yyerror(char *);
  extern int yylineno;
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

%token _LPARENT
%token _RPARENT
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

%%

exp_list
	: exp
	| exp_list _NEW_LINE
	| exp_list exp
	;

exp
	: _ID _ASSIGN _INT {printf("Izraz");}
	| exp _PL _INT {printf("Plus");}
	;
	
	
%%

int main() {
  yyparse();
}

int yyerror(char *s) {
  fprintf(stderr, "line %d: SYNTAX ERROR %s\n", yylineno, s);
} 
