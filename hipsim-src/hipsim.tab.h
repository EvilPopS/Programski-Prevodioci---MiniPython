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

#ifndef YY_YY_HIPSIM_TAB_H_INCLUDED
# define YY_YY_HIPSIM_TAB_H_INCLUDED
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
    _WORD = 258,                   /* _WORD  */
    _PUSH = 259,                   /* _PUSH  */
    _POP = 260,                    /* _POP  */
    _CALL = 261,                   /* _CALL  */
    _RET = 262,                    /* _RET  */
    _CMP = 263,                    /* _CMP  */
    _JMP = 264,                    /* _JMP  */
    _JEQ = 265,                    /* _JEQ  */
    _JNE = 266,                    /* _JNE  */
    _JGT = 267,                    /* _JGT  */
    _JLT = 268,                    /* _JLT  */
    _JGE = 269,                    /* _JGE  */
    _JLE = 270,                    /* _JLE  */
    _JC = 271,                     /* _JC  */
    _JNC = 272,                    /* _JNC  */
    _JO = 273,                     /* _JO  */
    _JNO = 274,                    /* _JNO  */
    _ADD = 275,                    /* _ADD  */
    _SUB = 276,                    /* _SUB  */
    _MUL = 277,                    /* _MUL  */
    _DIV = 278,                    /* _DIV  */
    _MOV = 279,                    /* _MOV  */
    _HALT = 280,                   /* _HALT  */
    _REGISTER = 281,               /* _REGISTER  */
    _CONSTANT = 282,               /* _CONSTANT  */
    _NUMBER = 283,                 /* _NUMBER  */
    _LABEL_DEF = 284,              /* _LABEL_DEF  */
    _LABEL = 285,                  /* _LABEL  */
    _ADDRESS = 286,                /* _ADDRESS  */
    _COMMA = 287,                  /* _COMMA  */
    _LPAREN = 288,                 /* _LPAREN  */
    _RPAREN = 289                  /* _RPAREN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "hipsim.y"

    long i;
    char* s;

#line 103 "hipsim.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HIPSIM_TAB_H_INCLUDED  */
