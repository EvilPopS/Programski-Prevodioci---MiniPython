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
    _BREAK = 262,                  /* _BREAK  */
    _CONTINUE = 263,               /* _CONTINUE  */
    _DEF = 264,                    /* _DEF  */
    _ELIF = 265,                   /* _ELIF  */
    _ELSE = 266,                   /* _ELSE  */
    _EXCEPT = 267,                 /* _EXCEPT  */
    _FINALLY = 268,                /* _FINALLY  */
    _FOR = 269,                    /* _FOR  */
    _IF = 270,                     /* _IF  */
    _IN = 271,                     /* _IN  */
    _NOT = 272,                    /* _NOT  */
    _OR = 273,                     /* _OR  */
    _PASS = 274,                   /* _PASS  */
    _RETURN = 275,                 /* _RETURN  */
    _TRY = 276,                    /* _TRY  */
    _WHILE = 277,                  /* _WHILE  */
    _COMMA = 278,                  /* _COMMA  */
    _COLON = 279,                  /* _COLON  */
    _LPAREN = 280,                 /* _LPAREN  */
    _RPAREN = 281,                 /* _RPAREN  */
    _ASSIGN = 282,                 /* _ASSIGN  */
    _ADD_SUB_OP = 283,             /* _ADD_SUB_OP  */
    _MUL_DIV_OP = 284,             /* _MUL_DIV_OP  */
    _LOP = 285,                    /* _LOP  */
    _RELOP = 286,                  /* _RELOP  */
    _ID = 287,                     /* _ID  */
    _NUM_BOOL = 288,               /* _NUM_BOOL  */
    _STRING = 289,                 /* _STRING  */
    _NONE = 290,                   /* _NONE  */
    VAR_ID = 291                   /* VAR_ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "analyzer.y"

  int i;
  char *s;

#line 105 "analyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ANALYZER_TAB_H_INCLUDED  */
