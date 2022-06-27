%option noyywrap yylineno

%{
   #include "analyzer.tab.h"
   #include "defs.h"
   #include <stdbool.h>
   
  void resetIndentation();
  void incOrdDecIndentation();
  
  int prevIndentLvl = 0;
  int curIndentLvl = 0;
  
  int retDedent = 0;
  int retIndent = 0; 
%}

%%
	{		
		if (retIndent > 0) {
			retIndent--;
			return _INDENT;
		}
		else if (retDedent > 0) {
			retDedent--;
			return _DEDENT;
		}
	}

" "+    				{ /* skip */ }
\#.*					{ /* skip */ }

[\n][ \n\t]*[\n]		{ 
							resetIndentation();	  	  	  
				  	  	    return _NEW_LINE;
						}

[\n][ \n\t]*[\n][\t]+	{
							int ind = strlen(yytext)-1;
							while (yytext[ind] == '\t') {
								ind --;
								curIndentLvl++;
							}

							incOrdDecIndentation();
				  	  		return _NEW_LINE;
						}					
 

[\n]	    { 
				resetIndentation();	  	  	  
	  	  	    return _NEW_LINE;
			}

[\n][\t]+   {   
				curIndentLvl = strlen(yytext)-1;
				incOrdDecIndentation();
	  	  		return _NEW_LINE;
	  	    }

"and"       { yylval.i = AND; return _LOP;}
"break"     { return _BREAK; }
"continue"  { return _CONTINUE; }
"def"       { return _DEF; }  
"elif"      { return _ELIF; }
"else"      { return _ELSE; }
"except"    { return _EXCEPT; }
"finally"   { return _FINALLY; }
"False"     { yylval.s = strdup("0"); return _NUM_BOOL; }
"if"        { return _IF; }
"in"        { return _IN; }
"is"        { yylval.i = IS; return _RELOP; }
"None"      { yylval.i = NONE; return _NONE; }
"not"       { return _NOT; }
"or"        { yylval.i = OR; return _LOP; }
"pass"      { return _PASS; }
"return"    { return _RETURN;}
"True"      { yylval.s = strdup("1"); return _NUM_BOOL; }
"try"       { return _TRY; }
"while"   	{ return _WHILE; }
	
","		{ return _COMMA; }
":"		{ return _COLON; }

"("     { return _LPAREN; }
")"     { return _RPAREN; }
"="		{ return _ASSIGN;}

"+"     { yylval.i = ADD; return _ADD_SUB_OP;}
"-"     { yylval.i = SUB; return _ADD_SUB_OP; }
"*"		{ yylval.i = MUL; return _MUL_DIV_OP; }
"/"		{ yylval.i = DIV; return _MUL_DIV_OP; }

"<"     { yylval.i = LS;   return _RELOP; }
">"     { yylval.i = GR;   return _RELOP; }
"<="    { yylval.i = LSEQ; return _RELOP; }
">="    { yylval.i = GREQ; return _RELOP; }
"=="    { yylval.i = EQ;   return _RELOP; }
"!="    { yylval.i = NEQ;  return _RELOP; }

[a-zA-Z_][a-zA-Z0-9_]* 			{ yylval.s = strdup(yytext); return _ID; }
[0-9]{1,10}     				{ yylval.s = strdup(yytext); return _NUM_BOOL; }
[0-9]{0,9}"."[0-9]{1,9}     	{ yylval.s = strdup(yytext); return _NUM_BOOL; }
[0-9]{1,9}"."[0-9]{0,9}     	{ yylval.s = strdup(yytext); return _NUM_BOOL; }
\"[^"\n]*\"     				{ yylval.s = strdup(yytext); return _STRING; }
\'[^'\n]*\'     				{ yylval.s = strdup(yytext); return _STRING; }

.			{ printf("line %d: LEXICAL ERROR on char %c\n", yylineno, *yytext);}

%%

void resetIndentation() {
	if (prevIndentLvl > 0) {
		retDedent = prevIndentLvl;
		prevIndentLvl = 0;
	} 
}

void incOrdDecIndentation() {
	if (prevIndentLvl < curIndentLvl) {
		retIndent = curIndentLvl - prevIndentLvl;
		prevIndentLvl = curIndentLvl;
	} 
	else if (prevIndentLvl > curIndentLvl) {
		retDedent = prevIndentLvl - curIndentLvl;
		prevIndentLvl = curIndentLvl;
	}
	curIndentLvl = 0;

}



