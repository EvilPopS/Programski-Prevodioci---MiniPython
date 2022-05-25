/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ANALYZER_TAB_H_INCLUDED
# define YY_YY_ANALYZER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _NEW_LINE = 258,               /* _NEW_LINE  */
    _INDENT = 259,                 /* _INDENT  */
    _DEDENT = 260,                 /* _DEDENT  */
    _AND = 261,                    /* _AND  */
    _AS = 262,                     /* _AS  */
    _BREAK = 263,                  /* _BREAK  */
    _CONTINUE = 264,               /* _CONTINUE  */
    _DEF = 265,                    /* _DEF  */
    _ELIF = 266,                   /* _ELIF  */
    _ELSE = 267,                   /* _ELSE  */
    _EXCEPT = 268,                 /* _EXCEPT  */
    _FINALLY = 269,                /* _FINALLY  */
    _FALSE = 270,                  /* _FALSE  */
    _FOR = 271,                    /* _FOR  */
    _FROM = 272,                   /* _FROM  */
    _IF = 273,                     /* _IF  */
    _IMPORT = 274,                 /* _IMPORT  */
    _IN = 275,                     /* _IN  */
    _IS = 276,                     /* _IS  */
    _NONE = 277,                   /* _NONE  */
    _NOT = 278,                    /* _NOT  */
    _OR = 279,                     /* _OR  */
    _PASS = 280,                   /* _PASS  */
    _RETURN = 281,                 /* _RETURN  */
    _TRUE = 282,                   /* _TRUE  */
    _TRY = 283,                    /* _TRY  */
    _WHILE = 284,                  /* _WHILE  */
    _COMMA = 285,                  /* _COMMA  */
    _COLON = 286,                  /* _COLON  */
    _LPAREN = 287,                 /* _LPAREN  */
    _RPAREN = 288,                 /* _RPAREN  */
    _ASSIGN = 289,                 /* _ASSIGN  */
    _AROP = 290,                   /* _AROP  */
    _LOP = 291,                    /* _LOP  */
    _RELOP = 292,                  /* _RELOP  */
    _ID = 293,                     /* _ID  */
    _INT = 294,                    /* _INT  */
    _FLOAT = 295,                  /* _FLOAT  */
    _STRING = 296,                 /* _STRING  */
    _BOOL = 297                    /* _BOOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "analyzer.y"

  int i;
  char *s;

#line 111 "analyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ANALYZER_TAB_H_INCLUDED  */
