%option noyywrap

%{
   #include <string.h>
%}

%%
" "+                 { /* skip */ }

[\n]+		     { printf("NEW LINE\n"); }
[\t]+		     { printf("INDENT\n"); }

"and"                { printf("AND\n"); }
"as"                 { printf("AS\n"); }
"break"              { printf("BREAK\n"); }
"continue"           { printf("CONTINUE\n"); }
"def"                { printf("DEF\n"); }
"elif"               { printf("ELIF\n"); }
"else"               { printf("ELSE\n"); }
"except"             { printf("EXCEPT\n"); }
"finally"            { printf("FINALLY\n"); }
"False"              { printf("FALSE \n"); }
"for"                { printf("FOR\n"); }
"from"               { printf("FROM\n"); }
"if"                 { printf("IF\n"); }
"import"             { printf("IMPORT\n"); }
"in"                 { printf("IN\n"); }
"is"                 { printf("IS\n"); }
"None"               { printf("NONE\n"); }
"not"                { printf("NOT\n"); }
"or"                 { printf("OR\n"); }
"pass"               { printf("PASS\n"); }
"return"             { printf("RETURN\n");}
"True"               { printf("TRUE\n"); }
"try"                { printf("TRY\n"); }
"while"              { printf("WHILE\n"); }
	
","		     { printf("COMMA\n"); }
":"		     { printf("COLON\n"); }

"("                  { printf("LPARENT\n"); }
")"                  { printf("RPARENT\n"); }
"="                  { printf("ASSIGN\n");}

"+"                  { printf("PLUS\n");}
"-"                  { printf("MINUS\n"); }
"*"		     { printf("MULTIPLY\n"); }
"/"		     { printf("DIVIDE\n"); }

"<"                  { printf("LESSER\n"); }
">"                  { printf("GREATER\n"); }
"<="                 { printf("LESSER OR EQUAL\n"); }
">="                 { printf("GREATER OR EQUAL\n"); }
"=="                 { printf("EQUAL\n"); }
"!="                 { printf("NOT EQUAL\n"); }

[a-zA-Z_][a-zA-Z0-9_]* 		{ printf("IDENTIFIER\n"); }
[+]?[0-9]{1,10}     		{ printf("INTEGER\n"); }
[+]?[0-9]{0,9}"."[0-9]{1,9}     { printf("FLOAT\n"); }
[+]?[0-9]{1,9}"."[0-9]{0,9}     { printf("FLOAT\n"); }


#.*               	{ /* skip */ }
.                    	{ printf("line %d: LEXICAL ERROR on char %c\n", yylineno, *yytext);}

%%
int main() {
  yylex();
}
