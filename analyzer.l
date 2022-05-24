%option noyywrap

%{
   #include "analyzer.tab.h"
%}

%%
" "+    			{ /* skip */ }
[\n][ \t\n]*[\n]	{ return _NEW_LINE; }

[\n]+	{ return _NEW_LINE; }
[\t]+	{ return _INDENT; }

"and"       { return _AND; }
"as"        { return _AS; }
"break"     { return _BREAK; }
"continue"  { return _CONTINUE; }
"def"       { return _DEF; }
"elif"      { return _ELIF; }
"else"      { return _ELSE; }
"except"    { return _EXCEPT; }
"finally"   { return _FINALLY; }
"False"     { return _FALSE; }
"for"       { return _FOR; }
"from"      { return _FROM; }
"if"        { return _IF; }
"import"    { return _IMPORT; }
"in"        { return _IN; }
"is"        { return _IS; }
"None"      { return _NONE; }
"not"       { return _NOT; }
"or"        { return _OR; }
"pass"      { return _PASS; }
"return"    { return _RETURN;}
"True"      { return _TRUE; }
"try"       { return _TRY; }
"while"   	{ return _WHILE; }
	
","		{ return _COMMA; }
":"		{ return _COLON; }

"("     { return _LPAREN; }
")"     { return _RPAREN; }
"="		{ return _ASSIGN;}

"+"     { return _PL;}
"-"     { return _MIN; }
"*"		{ return _MUL; }
"/"		{ return _DIV; }

"<"     { return _LS; }
">"     { return _GR; }
"<="    { return _LS_EQ; }
">="    { return _GR_EQ; }
"=="    { return _EQ; }
"!="    { return _NEQ; }

[a-zA-Z_][a-zA-Z0-9_]* 			{ return _ID; }
[+]?[0-9]{1,10}     			{ return _INT; }
[+]?[0-9]{0,9}"."[0-9]{1,9}     { return _FLOAT; }
[+]?[0-9]{1,9}"."[0-9]{0,9}     { return _FLOAT; }
["][^\n"]["]     				{ return _STRING; }
['][^\n'][']     				{ return _STRING; }


#.*               	{ /* skip */ }
.                    	{ printf("line %d: LEXICAL ERROR on char %c\n", yylineno, *yytext);}

%%

