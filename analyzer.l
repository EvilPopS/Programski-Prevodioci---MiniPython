%option noyywrap yylineno

%{
   #include "analyzer.tab.h"
   #include "defs.h"
   #include <stdbool.h>
   
  int prevIndentLvl = 0;
  int curIndentLvl = 0;
  
  int retDedent = 0;
  int retIndent = 0; 
%}

%%
	{;
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

[\n][ \n\t]*[\n]		{ 
						  if (prevIndentLvl > 0) {
				  			retDedent = prevIndentLvl;
				  			prevIndentLvl = 0;
				  			return _NEW_LINE;
					  	  } 
				  	  	  else 
				  	  		return _NEW_LINE;
						}

[\n][ \n\t]*[\n][\t]+	{
						  int ind = strlen(yytext)-1;
						  while (yytext[ind] == '\t') {
						  	ind --;
						  	curIndentLvl++;
						  }

				  		  if (prevIndentLvl < curIndentLvl) {
				  			retIndent = curIndentLvl - prevIndentLvl;
					  	  	prevIndentLvl = curIndentLvl;
					  	  	curIndentLvl = 0;
					  	  } 
				  	  	  else if (prevIndentLvl > curIndentLvl) {
				  	  		retDedent = prevIndentLvl - curIndentLvl;
				  	  		prevIndentLvl = curIndentLvl;
					  	  	curIndentLvl = 0;
				  	  	  }
				  		  
				  		  return _NEW_LINE;
						}					
 

[\n]	    { 
			  if (prevIndentLvl > 0) {
	  			retDedent = prevIndentLvl;
	  			prevIndentLvl = 0;
		  	  } 
	  	  	  
	  	  	  return _NEW_LINE;
			}

[\n][\t]+   {   
			  curIndentLvl = strlen(yytext)-1;
	  		  if (prevIndentLvl < curIndentLvl) {
	  			retIndent = curIndentLvl - prevIndentLvl;
		  	  	prevIndentLvl = curIndentLvl;
		  	  	curIndentLvl = 0;
		  	  } 
	  	  	  else if (prevIndentLvl > curIndentLvl) {
	  	  		retDedent = prevIndentLvl - curIndentLvl;
	  	  		prevIndentLvl = curIndentLvl;
		  	  	curIndentLvl = 0;
	  	  	  }
	  	  	  return _NEW_LINE;
	  	    }

"and"       { yylval.i = AND; return _LOP;}
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
"or"        { yylval.i = OR; return _LOP; }
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

"+"     { yylval.i = ADD; return _AROP;}
"-"     { yylval.i = SUB; return _AROP; }
"*"		{ yylval.i = MUL; return _AROP; }
"/"		{ yylval.i = DIV; return _AROP; }

"<"     { yylval.i = LS;   return _RELOP; }
">"     { yylval.i = GR;   return _RELOP; }
"<="    { yylval.i = LSEQ; return _RELOP; }
">="    { yylval.i = GREQ; return _RELOP; }
"=="    { yylval.i = EQ;   return _RELOP; }
"!="    { yylval.i = NEQ;  return _RELOP; }

[a-zA-Z_][a-zA-Z0-9_]* 			{ yylval.s = strdup(yytext); return _ID; }
[+]?[0-9]{1,10}     			{ yylval.s = strdup(yytext); return _INT; }
[+]?[0-9]{0,9}"."[0-9]{1,9}     { yylval.s = strdup(yytext); return _FLOAT; }
[+]?[0-9]{1,9}"."[0-9]{0,9}     { yylval.s = strdup(yytext); return _FLOAT; }
\".*\"     						{ yylval.s = strdup(yytext); return _STRING; }
\'.*\'     						{ yylval.s = strdup(yytext); return _STRING; }

#.*			{ /* skip */ }
.			{ printf("line %d: LEXICAL ERROR on char %c\n", yylineno, *yytext);}

%%

