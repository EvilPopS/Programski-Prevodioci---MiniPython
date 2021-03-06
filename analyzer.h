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

#ifndef YY_YY_SYNTAX_SEMANTIC_ANLY_TAB_H_INCLUDED
# define YY_YY_SYNTAX_SEMANTIC_ANLY_TAB_H_INCLUDED
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
    _AND = 260,                    /* _AND  */
    _AS = 261,                     /* _AS  */
    _BREAK = 262,                  /* _BREAK  */
    _CONTINUE = 263,               /* _CONTINUE  */
    _DEF = 264,                    /* _DEF  */
    _ELIF = 265,                   /* _ELIF  */
    _ELSE = 266,                   /* _ELSE  */
    _EXCEPT = 267,                 /* _EXCEPT  */
    _FINALLY = 268,                /* _FINALLY  */
    _FALSE = 269,                  /* _FALSE  */
    _FOR = 270,                    /* _FOR  */
    _FROM = 271,                   /* _FROM  */
    _IF = 272,                     /* _IF  */
    _IMPORT = 273,                 /* _IMPORT  */
    _IN = 274,                     /* _IN  */
    _IS = 275,                     /* _IS  */
    _NONE = 276,                   /* _NONE  */
    _NOT = 277,                    /* _NOT  */
    _OR = 278,                     /* _OR  */
    _PASS = 279,                   /* _PASS  */
    _RETURN = 280,                 /* _RETURN  */
    _TRUE = 281,                   /* _TRUE  */
    _TRY = 282,                    /* _TRY  */
    _WHILE = 283,                  /* _WHILE  */
    _COMMA = 284,                  /* _COMMA  */
    _COLON = 285,                  /* _COLON  */
    _LPARENT = 286,                /* _LPARENT  */
    _RPARENT = 287,                /* _RPARENT  */
    _ASSIGN = 288,                 /* _ASSIGN  */
    _PL = 289,                     /* _PL  */
    _MIN = 290,                    /* _MIN  */
    _MUL = 291,                    /* _MUL  */
    _DIV = 292,                    /* _DIV  */
    _LS = 293,                     /* _LS  */
    _GR = 294,                     /* _GR  */
    _LS_EQ = 295,                  /* _LS_EQ  */
    _GR_EQ = 296,                  /* _GR_EQ  */
    _EQ = 297,                     /* _EQ  */
    _NEQ = 298,                    /* _NEQ  */
    _ID = 299,                     /* _ID  */
    _INT = 300,                    /* _INT  */
    _FLOAT = 301                   /* _FLOAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_SEMANTIC_ANLY_TAB_H_INCLUDED  */
