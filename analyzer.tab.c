/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "analyzer.y"

	#include <stdio.h>
	#include <stdbool.h>
	#include <stdlib.h>
	#include "defs.h"
	#include "symtab.h"
	#include "codegen.h"
  
	int yylex(void);
	int yyparse(void);
	int yyerror(const char *);
	extern int yylineno;
	int error_count = 0;
	unsigned scope = 0;
	
	int out_lin = 0;
	
	int labNumStates[64];
	int lab_num_count = -1;
	int max_lab_num = -1;
	
	int nextLabNumStates[64];
	int next_lab_num_count = -1;

  	FILE *output;
  
	char char_buffer[CHAR_BUFFER_LENGTH];

	// Broji u koliko se ugnjezdenih petlja nalazi pa na osnovu toga dozvoljava ( >0 ) odnosno ne dozvoljava ( ==0) 'break' ili 'continue
	int loopCounter = 0;

	// Kod definisanja funkcije parametri bez definisane vrednosti ne smeju da se nalaze posle param sa def vrednostima
	bool valuedParamDef = false;

	// Za funkcije
	int funcInds[32]; 
	int currFuncInd = -1; 	
	int defParamNum = 0;
	int nonDefParamNum = 0;
	bool hasReturn = false;
	int argsNum = 0;
	int funcCallInd = -1;

	// Za varijable
	int varNumsInds[64]; 
	int var_num_ind = 0;

	// Kod komparacije
	int currRelOp = -1;
	int cmpCounter = 0;

	// While petlja
	bool firstTimeEnterLoop = true; 
	int regToClear = -1;
	
	// Za multi assign
	int mAssignVarsCounter = 0;
	int mAssignValuesCounter = 0;
	int mAssignCurrVal = 0;
	int mAssignVarInds[64];
	
  

#line 135 "analyzer.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "analyzer.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__NEW_LINE = 3,                  /* _NEW_LINE  */
  YYSYMBOL__INDENT = 4,                    /* _INDENT  */
  YYSYMBOL__DEDENT = 5,                    /* _DEDENT  */
  YYSYMBOL__AND = 6,                       /* _AND  */
  YYSYMBOL__BREAK = 7,                     /* _BREAK  */
  YYSYMBOL__CONTINUE = 8,                  /* _CONTINUE  */
  YYSYMBOL__DEF = 9,                       /* _DEF  */
  YYSYMBOL__ELIF = 10,                     /* _ELIF  */
  YYSYMBOL__ELSE = 11,                     /* _ELSE  */
  YYSYMBOL__EXCEPT = 12,                   /* _EXCEPT  */
  YYSYMBOL__FINALLY = 13,                  /* _FINALLY  */
  YYSYMBOL__FOR = 14,                      /* _FOR  */
  YYSYMBOL__IF = 15,                       /* _IF  */
  YYSYMBOL__IN = 16,                       /* _IN  */
  YYSYMBOL__NOT = 17,                      /* _NOT  */
  YYSYMBOL__OR = 18,                       /* _OR  */
  YYSYMBOL__PASS = 19,                     /* _PASS  */
  YYSYMBOL__RETURN = 20,                   /* _RETURN  */
  YYSYMBOL__TRY = 21,                      /* _TRY  */
  YYSYMBOL__WHILE = 22,                    /* _WHILE  */
  YYSYMBOL__COMMA = 23,                    /* _COMMA  */
  YYSYMBOL__COLON = 24,                    /* _COLON  */
  YYSYMBOL__LPAREN = 25,                   /* _LPAREN  */
  YYSYMBOL__RPAREN = 26,                   /* _RPAREN  */
  YYSYMBOL__ASSIGN = 27,                   /* _ASSIGN  */
  YYSYMBOL__ADD_SUB_OP = 28,               /* _ADD_SUB_OP  */
  YYSYMBOL__MUL_DIV_OP = 29,               /* _MUL_DIV_OP  */
  YYSYMBOL__LOP = 30,                      /* _LOP  */
  YYSYMBOL__RELOP = 31,                    /* _RELOP  */
  YYSYMBOL__ID = 32,                       /* _ID  */
  YYSYMBOL__NUM_BOOL = 33,                 /* _NUM_BOOL  */
  YYSYMBOL__STRING = 34,                   /* _STRING  */
  YYSYMBOL__NONE = 35,                     /* _NONE  */
  YYSYMBOL_VAR_ID = 36,                    /* VAR_ID  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_file = 38,                      /* file  */
  YYSYMBOL_statement_list = 39,            /* statement_list  */
  YYSYMBOL_statement = 40,                 /* statement  */
  YYSYMBOL_simple_statement = 41,          /* simple_statement  */
  YYSYMBOL_compound_statement = 42,        /* compound_statement  */
  YYSYMBOL_assign_statement = 43,          /* assign_statement  */
  YYSYMBOL_multi_assign_statement = 44,    /* multi_assign_statement  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_multi_assign_vars = 46,         /* multi_assign_vars  */
  YYSYMBOL_multi_assign_values = 47,       /* multi_assign_values  */
  YYSYMBOL_return_statement = 48,          /* return_statement  */
  YYSYMBOL_function_call = 49,             /* function_call  */
  YYSYMBOL_arguments = 50,                 /* arguments  */
  YYSYMBOL_args = 51,                      /* args  */
  YYSYMBOL_function_def = 52,              /* function_def  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_parameters = 55,                /* parameters  */
  YYSYMBOL_param_with_default_val = 56,    /* param_with_default_val  */
  YYSYMBOL_if_statement = 57,              /* if_statement  */
  YYSYMBOL_if_part = 58,                   /* if_part  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_60_5 = 60,                      /* @5  */
  YYSYMBOL_elif_part = 61,                 /* elif_part  */
  YYSYMBOL_62_6 = 62,                      /* @6  */
  YYSYMBOL_while_statement = 63,           /* while_statement  */
  YYSYMBOL_64_7 = 64,                      /* $@7  */
  YYSYMBOL_while_part = 65,                /* while_part  */
  YYSYMBOL_66_8 = 66,                      /* @8  */
  YYSYMBOL_67_9 = 67,                      /* @9  */
  YYSYMBOL_try_except_statement = 68,      /* try_except_statement  */
  YYSYMBOL_try_part = 69,                  /* try_part  */
  YYSYMBOL_70_10 = 70,                     /* @10  */
  YYSYMBOL_except_part = 71,               /* except_part  */
  YYSYMBOL_72_11 = 72,                     /* $@11  */
  YYSYMBOL_except_finally_body = 73,       /* except_finally_body  */
  YYSYMBOL_74_12 = 74,                     /* @12  */
  YYSYMBOL_finally_or_else_part = 75,      /* finally_or_else_part  */
  YYSYMBOL_else_part = 76,                 /* else_part  */
  YYSYMBOL_77_13 = 77,                     /* @13  */
  YYSYMBOL_body = 78,                      /* body  */
  YYSYMBOL_79_14 = 79,                     /* $@14  */
  YYSYMBOL_num_exp = 80,                   /* num_exp  */
  YYSYMBOL_exp = 81,                       /* exp  */
  YYSYMBOL_literal = 82                    /* literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   115,   115,   116,   117,   121,   122,   126,   127,   131,
     132,   133,   134,   135,   140,   145,   149,   150,   151,   152,
     156,   171,   170,   184,   198,   209,   219,   228,   239,   257,
     282,   283,   287,   293,   303,   313,   302,   335,   336,   341,
     342,   350,   354,   363,   373,   380,   372,   398,   400,   399,
     420,   419,   441,   452,   440,   477,   482,   481,   496,   498,
     497,   507,   512,   511,   525,   526,   527,   531,   533,   532,
     547,   546,   559,   560,   584,   616,   648,   658,   695,   696,
     703,   704,   708,   709,   710
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_NEW_LINE", "_INDENT",
  "_DEDENT", "_AND", "_BREAK", "_CONTINUE", "_DEF", "_ELIF", "_ELSE",
  "_EXCEPT", "_FINALLY", "_FOR", "_IF", "_IN", "_NOT", "_OR", "_PASS",
  "_RETURN", "_TRY", "_WHILE", "_COMMA", "_COLON", "_LPAREN", "_RPAREN",
  "_ASSIGN", "_ADD_SUB_OP", "_MUL_DIV_OP", "_LOP", "_RELOP", "_ID",
  "_NUM_BOOL", "_STRING", "_NONE", "VAR_ID", "$accept", "file",
  "statement_list", "statement", "simple_statement", "compound_statement",
  "assign_statement", "multi_assign_statement", "$@1", "multi_assign_vars",
  "multi_assign_values", "return_statement", "function_call", "arguments",
  "args", "function_def", "$@2", "$@3", "parameters",
  "param_with_default_val", "if_statement", "if_part", "$@4", "@5",
  "elif_part", "@6", "while_statement", "$@7", "while_part", "@8", "@9",
  "try_except_statement", "try_part", "@10", "except_part", "$@11",
  "except_finally_body", "@12", "finally_or_else_part", "else_part", "@13",
  "body", "$@14", "num_exp", "exp", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      44,    83,   -68,   -68,   -11,   -68,   -68,    -3,    -1,   -68,
      14,    38,    83,   -68,    39,   -68,   -68,   -68,    21,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,    83,   -68,
      -3,    -3,    -3,    33,   -68,   -68,   -68,   -68,   129,   -68,
     -68,    57,    -3,    29,   -68,    -3,   -68,   -68,   -68,    43,
      54,     5,    71,    66,    63,    26,    40,   125,    -3,    -3,
      -3,    -3,   -68,   111,   -68,    99,   129,   -68,    -3,    70,
      -3,    72,   -68,   -68,    75,   -21,    75,   -68,    62,    92,
     -68,    77,   -68,    40,    20,    96,    98,    -3,   -68,   -68,
     129,    -4,    -3,   119,   104,   106,   -68,   -68,   -68,   -68,
      84,   -13,   -68,   -68,   -68,   -68,   -68,   129,    -3,   129,
     109,   -68,   -68,    75,    -3,    85,    95,    96,    83,    96,
     129,   -68,    96,    96,   -68,   129,    84,   -68,   123,   -68,
      65,   -68,    96,   -68,   -68,   -68,   -68,   -68,    96,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    13,    14,     0,    44,    15,    27,     0,    52,
       0,     0,     3,     5,     0,     8,     9,    10,    21,    11,
      12,    16,    17,    47,    18,    50,    19,    58,     4,    34,
       0,     0,     0,    79,    82,    83,    84,    80,    28,    72,
      78,     0,     0,     0,    30,     0,     1,     6,     7,     0,
       0,    67,    67,    64,     0,     0,    73,     0,     0,     0,
       0,     0,    56,     0,    23,     0,    20,    24,     0,    22,
       0,     0,    43,    51,     0,     0,     0,    55,    37,     0,
      81,    74,    75,    76,    77,     0,     0,     0,    29,    31,
      32,     0,     0,     0,     0,     0,    66,    59,    61,    65,
      38,     0,    39,    45,    70,    57,    53,    33,     0,    26,
       0,    68,    62,     0,     0,     0,     0,     0,     0,     0,
      25,    48,     0,     0,    60,    42,    40,    41,     0,    46,
       0,    54,     0,    69,    63,    35,    71,    49,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,     3,   -10,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,     0,   -68,   -68,   -68,   -68,   -68,   -68,    12,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -67,   -68,   -68,    76,
     -68,    -9,   -68,   -25,   -68,   -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    17,    50,    18,
      69,    19,    37,    65,    89,    21,    54,   138,   101,   102,
      22,    23,    30,   117,    51,   132,    24,    52,    25,    42,
     119,    26,    27,    85,    53,   113,    96,   123,    77,    72,
     122,   105,   118,    38,    39,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    20,    47,    95,    28,    55,    56,    57,    98,    99,
     115,    97,    20,   116,    31,    70,    71,    63,    47,   108,
      66,    29,    32,    41,    58,    59,    60,    61,    20,    33,
      34,    35,    36,    81,    82,    83,    84,    43,    46,    44,
      90,    45,    48,    91,    49,    93,   124,     1,    58,    59,
      79,     2,     3,     4,    58,    59,    60,    61,    44,     5,
      62,    64,   107,     6,     7,     8,     9,   109,    58,    59,
     136,    61,     2,     3,     4,    67,    10,    74,    75,    76,
       5,    68,    71,   120,     6,     7,     8,     9,    78,   125,
       2,     3,     4,    92,   100,   103,    94,    10,     5,    95,
     104,   106,     6,     7,     8,     9,    59,   111,   129,   112,
     131,   114,   121,   133,   134,    10,    31,   126,    20,   128,
      47,   130,    87,   137,    32,    88,   135,   127,    73,   139,
      20,    33,    34,    35,    36,    86,     0,     0,     0,    58,
      59,    60,    61,   110,     0,     0,     0,    58,    59,    60,
      61,    80,     0,    58,    59,    60,    61,    58,    59,    60,
      61
};

static const yytype_int16 yycheck[] =
{
       0,     1,    12,    24,     1,    30,    31,    32,    75,    76,
      23,    32,    12,    26,    17,    10,    11,    42,    28,    23,
      45,    32,    25,    24,    28,    29,    30,    31,    28,    32,
      33,    34,    35,    58,    59,    60,    61,    23,     0,    25,
      65,    27,     3,    68,    23,    70,   113,     3,    28,    29,
      24,     7,     8,     9,    28,    29,    30,    31,    25,    15,
       3,    32,    87,    19,    20,    21,    22,    92,    28,    29,
       5,    31,     7,     8,     9,    32,    32,    11,    12,    13,
      15,    27,    11,   108,    19,    20,    21,    22,    25,   114,
       7,     8,     9,    23,    32,     3,    24,    32,    15,    24,
       4,     3,    19,    20,    21,    22,    29,     3,   117,     3,
     119,    27,     3,   122,   123,    32,    17,    32,   118,    24,
     130,   118,    23,   132,    25,    26,     3,   115,    52,   138,
     130,    32,    33,    34,    35,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    24,    -1,    -1,    -1,    28,    29,    30,
      31,    26,    -1,    28,    29,    30,    31,    28,    29,    30,
      31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,     8,     9,    15,    19,    20,    21,    22,
      32,    38,    39,    40,    41,    42,    43,    44,    46,    48,
      49,    52,    57,    58,    63,    65,    68,    69,    39,    32,
      59,    17,    25,    32,    33,    34,    35,    49,    80,    81,
      82,    24,    66,    23,    25,    27,     0,    40,     3,    23,
      45,    61,    64,    71,    53,    80,    80,    80,    28,    29,
      30,    31,     3,    80,    32,    50,    80,    32,    27,    47,
      10,    11,    76,    76,    11,    12,    13,    75,    25,    24,
      26,    80,    80,    80,    80,    70,    24,    23,    26,    51,
      80,    80,    23,    80,    24,    24,    73,    32,    73,    73,
      32,    55,    56,     3,     4,    78,     3,    80,    23,    80,
      24,     3,     3,    72,    27,    23,    26,    60,    79,    67,
      80,     3,    77,    74,    73,    80,    32,    56,    24,    78,
      39,    78,    62,    78,    78,     3,     5,    78,    54,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    38,    39,    39,    40,    40,    41,
      41,    41,    41,    41,    41,    41,    42,    42,    42,    42,
      43,    45,    44,    46,    46,    47,    47,    48,    48,    49,
      50,    50,    51,    51,    53,    54,    52,    55,    55,    55,
      55,    55,    56,    57,    59,    60,    58,    61,    62,    61,
      64,    63,    66,    67,    65,    68,    70,    69,    71,    72,
      71,    71,    74,    73,    75,    75,    75,    76,    77,    76,
      79,    78,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    81,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     3,     3,     3,     4,     3,     1,     2,     4,
       0,     2,     1,     2,     0,     0,    10,     0,     1,     1,
       3,     3,     3,     3,     0,     0,     7,     0,     0,     7,
       0,     3,     0,     0,     7,     3,     0,     5,     0,     0,
       5,     3,     0,     4,     0,     2,     2,     0,     0,     5,
       0,     4,     1,     2,     3,     3,     3,     3,     1,     1,
       1,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* statement_list: statement  */
#line 121 "analyzer.y"
                    {code("\n");}
#line 1580 "analyzer.tab.c"
    break;

  case 6: /* statement_list: statement_list statement  */
#line 122 "analyzer.y"
                                   {code("\n");}
#line 1586 "analyzer.tab.c"
    break;

  case 11: /* simple_statement: return_statement  */
#line 133 "analyzer.y"
                                { hasReturn = true; }
#line 1592 "analyzer.tab.c"
    break;

  case 13: /* simple_statement: _BREAK  */
#line 136 "analyzer.y"
                {
			if (loopCounter == 0)
				err("'break' must be inside while statement!");
		}
#line 1601 "analyzer.tab.c"
    break;

  case 14: /* simple_statement: _CONTINUE  */
#line 141 "analyzer.y"
                {
			if (loopCounter == 0)
				err("'continue' must be inside while statement!");
		}
#line 1610 "analyzer.tab.c"
    break;

  case 20: /* assign_statement: _ID _ASSIGN num_exp  */
#line 157 "analyzer.y"
                {
			int index = lookup_symbol_all_kinds((yyvsp[-2].s));
			if(index == NO_INDEX || get_kind(index) == FUN) {
				index = insert_symbol((yyvsp[-2].s), VAR, get_type((yyvsp[0].i)), ++varNumsInds[var_num_ind], NO_ATR, scope);
				code("\n\t\tSUBS\t%%15,$%d,%%15", 4);
			}
			else 
				set_type(index, get_type((yyvsp[0].i)));
			gen_mov((yyvsp[0].i), index);
		}
#line 1625 "analyzer.tab.c"
    break;

  case 21: /* $@1: %empty  */
#line 171 "analyzer.y"
                {
			code("\n\t\tSUBS\t%%15,$%d,%%15", 4*mAssignVarsCounter);
		}
#line 1633 "analyzer.tab.c"
    break;

  case 22: /* multi_assign_statement: multi_assign_vars $@1 multi_assign_values  */
#line 175 "analyzer.y"
                {
			if (mAssignVarsCounter != mAssignValuesCounter)
				err("You must assign equal number of values to number of identifiers in multi assign statement!");
			mAssignVarsCounter = 0;
			mAssignValuesCounter = 0;
		}
#line 1644 "analyzer.tab.c"
    break;

  case 23: /* multi_assign_vars: _ID _COMMA _ID  */
#line 185 "analyzer.y"
                { 
			int index = lookup_symbol_all_kinds((yyvsp[-2].s));
			if(index == NO_INDEX || get_kind(index) == FUN)
				mAssignVarInds[mAssignVarsCounter++] = insert_symbol((yyvsp[-2].s), VAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
			else
				mAssignVarInds[mAssignVarsCounter++] = index;

			index = lookup_symbol_all_kinds((yyvsp[0].s));
			if(index == NO_INDEX || get_kind(index) == FUN)
				mAssignVarInds[mAssignVarsCounter++] = insert_symbol((yyvsp[0].s), VAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
			else
				mAssignVarInds[mAssignVarsCounter++] = index;
		}
#line 1662 "analyzer.tab.c"
    break;

  case 24: /* multi_assign_vars: multi_assign_vars _COMMA _ID  */
#line 199 "analyzer.y"
                { 
			int index = lookup_symbol_all_kinds((yyvsp[0].s));
			if(index == NO_INDEX || get_kind(index) == FUN)
				mAssignVarInds[mAssignVarsCounter++] = insert_symbol((yyvsp[0].s), VAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
			else
				mAssignVarInds[mAssignVarsCounter++] = index;		
		}
#line 1674 "analyzer.tab.c"
    break;

  case 25: /* multi_assign_values: _ASSIGN num_exp _COMMA num_exp  */
#line 210 "analyzer.y"
                { 	
			int index = mAssignVarInds[mAssignValuesCounter++];
			set_type(index, get_type((yyvsp[-2].i)));
			gen_mov((yyvsp[-2].i), index);

			index = mAssignVarInds[mAssignValuesCounter++];
			set_type(index, get_type((yyvsp[0].i)));
			gen_mov((yyvsp[0].i), index);
		}
#line 1688 "analyzer.tab.c"
    break;

  case 26: /* multi_assign_values: multi_assign_values _COMMA num_exp  */
#line 220 "analyzer.y"
                {
			int index = mAssignVarInds[mAssignValuesCounter++];
			set_type(index, get_type((yyvsp[0].i)));
			gen_mov((yyvsp[0].i), index);
		}
#line 1698 "analyzer.tab.c"
    break;

  case 27: /* return_statement: _RETURN  */
#line 229 "analyzer.y"
                {
			if (currFuncInd < 0)
				err("'return' must be inside a function definition!");
			
			int funcInd = funcInds[currFuncInd];
			if(hasReturn && get_type(funcInd) != NONE)
				set_type(funcInd, UNKNOWN);

        	code("\n\t\tJMP \t@%s_exit", get_name(funcInds[currFuncInd]));	
		}
#line 1713 "analyzer.tab.c"
    break;

  case 28: /* return_statement: _RETURN num_exp  */
#line 240 "analyzer.y"
                {
			if (currFuncInd < 0)
				err("'return' must be inside a function definition!");
			
			int funcInd = funcInds[currFuncInd];
			if(hasReturn && get_type(funcInd) != (yyvsp[0].i))
				set_type(funcInd, UNKNOWN);
			else if(!hasReturn)
				set_type(funcInd, (yyvsp[0].i));
				
	        gen_mov((yyvsp[0].i), FUN_REG);
	        code("\n\t\tJMP \t@%s_exit", get_name(funcInds[currFuncInd]));	

		}
#line 1732 "analyzer.tab.c"
    break;

  case 29: /* function_call: _ID _LPAREN arguments _RPAREN  */
#line 258 "analyzer.y"
      {
        funcCallInd = lookup_symbol_all_kinds((yyvsp[-3].s));
        if (funcCallInd == NO_INDEX || get_kind(funcCallInd) != FUN)
           err("There is no defined function of name %s", (yyvsp[-3].s));
          
        int nonDefParams = get_atr1(funcCallInd);
        int defParams = get_atr2(funcCallInd);
        if (argsNum > nonDefParams+defParams)
        	err("Function given more arguments than the definition has parameters!");
        else if (argsNum < nonDefParams)
        	err("Function given less arguments than the definition has non default parameters!");

        code("\n\t\tCALL\t%s", get_name(funcCallInd));

		int numOfArgs = defParams + nonDefParams;
        if(numOfArgs > 0)
          code("\n\t\tADDS\t%%15,$%d,%%15", numOfArgs * 4);
          
        set_type(FUN_REG, get_type(funcCallInd));
        (yyval.i) = FUN_REG;
      }
#line 1758 "analyzer.tab.c"
    break;

  case 31: /* arguments: arguments args  */
#line 283 "analyzer.y"
                         { argsNum++; }
#line 1764 "analyzer.tab.c"
    break;

  case 32: /* args: num_exp  */
#line 288 "analyzer.y"
                {
			free_if_reg((yyvsp[0].i));
			code("\n\t\tPUSH\t");
			gen_sym_name((yyvsp[0].i));
		}
#line 1774 "analyzer.tab.c"
    break;

  case 33: /* args: _COMMA num_exp  */
#line 294 "analyzer.y"
                {
			free_if_reg((yyvsp[0].i));
			code("\n\t\tPUSH\t");
			gen_sym_name((yyvsp[0].i));	
		}
#line 1784 "analyzer.tab.c"
    break;

  case 34: /* $@2: %empty  */
#line 303 "analyzer.y"
                {
		    currFuncInd++;
			funcInds[currFuncInd] = insert_symbol((yyvsp[0].s), FUN, NONE, NO_ATR, NO_ATR, scope);
	  		scope++;
      	
		    code("\n%s:", (yyvsp[0].s));
		    code("\n\t\tPUSH\t%%14");
		    code("\n\t\tMOV \t%%15,%%14");
		}
#line 1798 "analyzer.tab.c"
    break;

  case 35: /* $@3: %empty  */
#line 313 "analyzer.y"
                {
			set_atr1(funcInds[currFuncInd], nonDefParamNum);
			set_atr2(funcInds[currFuncInd], defParamNum);
	    	nonDefParamNum = 0;
	    	defParamNum = 0;
			code("\n@%s_body:", get_name(funcInds[currFuncInd]));
		}
#line 1810 "analyzer.tab.c"
    break;

  case 36: /* function_def: _DEF _ID $@2 _LPAREN parameters _RPAREN _COLON _NEW_LINE $@3 body  */
#line 321 "analyzer.y"
                {
		    clear_symbols(funcInds[currFuncInd] + 1);
		    currFuncInd--;
		    scope--;
		    hasReturn = false;
	  	
	  	    code("\n@%s_exit:", (yyvsp[-8].s));
		    code("\n\t\tMOV \t%%14,%%15");
		    code("\n\t\tPOP \t%%14");
		    code("\n\t\tRET");
		}
#line 1826 "analyzer.tab.c"
    break;

  case 38: /* parameters: _ID  */
#line 337 "analyzer.y"
                { 
			insert_symbol((yyvsp[0].s), PAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
			nonDefParamNum++; 
		}
#line 1835 "analyzer.tab.c"
    break;

  case 40: /* parameters: parameters _COMMA _ID  */
#line 343 "analyzer.y"
                {
			if (valuedParamDef)
				err("Parameters without default values cannot be defined after parameter with set default value.");

			insert_symbol((yyvsp[0].s), PAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
			nonDefParamNum++; 
		}
#line 1847 "analyzer.tab.c"
    break;

  case 42: /* param_with_default_val: _ID _ASSIGN num_exp  */
#line 355 "analyzer.y"
                {
			insert_symbol((yyvsp[-2].s), PAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
			valuedParamDef = true;
			defParamNum++;
		}
#line 1857 "analyzer.tab.c"
    break;

  case 43: /* if_statement: if_part elif_part else_part  */
#line 364 "analyzer.y"
                { 
			code("\n@if_end%d:", labNumStates[lab_num_count]);
			lab_num_count--;
			next_lab_num_count--;
		}
#line 1867 "analyzer.tab.c"
    break;

  case 44: /* $@4: %empty  */
#line 373 "analyzer.y"
                {
			labNumStates[++lab_num_count] = ++max_lab_num;
			nextLabNumStates[++next_lab_num_count] = 0;
			
			code("\n@if_start%d:", labNumStates[lab_num_count]);		
		}
#line 1878 "analyzer.tab.c"
    break;

  case 45: /* @5: %empty  */
#line 380 "analyzer.y"
                {
			(yyval.i) = get_last_element()+1; 
			scope++;
			
			free_if_reg((yyvsp[-2].i));
	        code("\n\t\t%s\t@next%d_%d", opp_jumps[currRelOp], labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]);	
			code("\n@if_body%d:", labNumStates[lab_num_count]);	
		}
#line 1891 "analyzer.tab.c"
    break;

  case 46: /* if_part: _IF $@4 num_exp _COLON _NEW_LINE @5 body  */
#line 389 "analyzer.y"
                {
			clear_symbols((yyvsp[-1].i));
			scope--;

			code("\n@next%d_%d:", labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]++);
		}
#line 1902 "analyzer.tab.c"
    break;

  case 48: /* @6: %empty  */
#line 400 "analyzer.y"
                {
			(yyval.i) = get_last_element()+1; 
			scope++;
			
			free_if_reg((yyvsp[-2].i));

		    code("\n\t\t%s\t@next%d_%d", opp_jumps[currRelOp], labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]);	
		}
#line 1915 "analyzer.tab.c"
    break;

  case 49: /* elif_part: elif_part _ELIF num_exp _COLON _NEW_LINE @6 body  */
#line 409 "analyzer.y"
                {
			clear_symbols((yyvsp[-1].i));	
			scope--;
			
			code("\n@next%d_%d:", labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]++);
		}
#line 1926 "analyzer.tab.c"
    break;

  case 50: /* $@7: %empty  */
#line 420 "analyzer.y"
                {
			code("\n@while_else_start%d:", labNumStates[lab_num_count]);
			if (regToClear != -1) {
				free_if_reg(regToClear);
				regToClear = -1;
			}
	  	}
#line 1938 "analyzer.tab.c"
    break;

  case 51: /* while_statement: while_part $@7 else_part  */
#line 428 "analyzer.y"
                { 
			code("\n@while_end%d:", labNumStates[lab_num_count]); 
			clear_symbols((yyvsp[-2].i));	
			scope--;
			loopCounter--;
			
			lab_num_count--;
			next_lab_num_count--;
		}
#line 1952 "analyzer.tab.c"
    break;

  case 52: /* @8: %empty  */
#line 441 "analyzer.y"
                {
			labNumStates[++lab_num_count] = ++max_lab_num;
			nextLabNumStates[++next_lab_num_count] = 0;
			
			(yyval.i) = take_reg();
		    code("\n\t\tMOV \t$0,");
		    gen_sym_name((yyval.i));
		    regToClear = (yyval.i);
			code("\n@while_start%d:", labNumStates[lab_num_count]);
		}
#line 1967 "analyzer.tab.c"
    break;

  case 53: /* @9: %empty  */
#line 452 "analyzer.y"
                {
			(yyval.i) = get_last_element()+1; 
			scope++;
			loopCounter++;
		
	        code("\n\t\t%s\t@while_body%d", jumps[currRelOp], labNumStates[lab_num_count]);	

			code("\n\t\tCMPS \t");
			gen_sym_name((yyvsp[-3].i));
			code(",$0");
            code("\n\t\t%s\t@while_else_start%d", jumps[4], labNumStates[lab_num_count]);
            code("\n\t\tJMP \t@while_end%d", labNumStates[lab_num_count]);

			code("\n@while_body%d:", labNumStates[lab_num_count]);
		    code("\n\t\tMOV \t$1,");
		    gen_sym_name((yyvsp[-3].i));
		}
#line 1989 "analyzer.tab.c"
    break;

  case 54: /* while_part: _WHILE @8 num_exp _COLON _NEW_LINE @9 body  */
#line 470 "analyzer.y"
                {
	        code("\n\t\tJMP \t@while_start%d", labNumStates[lab_num_count]);
	        (yyval.i) = (yyvsp[-1].i);	  	
	  	}
#line 1998 "analyzer.tab.c"
    break;

  case 56: /* @10: %empty  */
#line 482 "analyzer.y"
                {
			(yyval.i) = get_last_element()+1; 
			scope++;
			loopCounter++;
		}
#line 2008 "analyzer.tab.c"
    break;

  case 57: /* try_part: _TRY _COLON _NEW_LINE @10 body  */
#line 488 "analyzer.y"
                {
			clear_symbols((yyvsp[-1].i));	
			scope--;
			loopCounter--;
		}
#line 2018 "analyzer.tab.c"
    break;

  case 59: /* $@11: %empty  */
#line 498 "analyzer.y"
                {
  	      	int index = lookup_symbol_all_kinds((yyvsp[0].s));
		    if(index == NO_INDEX)
		       insert_symbol((yyvsp[0].s), VAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
		    else 
		    	if (get_kind(index) == FUN)
		    		insert_symbol((yyvsp[0].s), VAR, UNKNOWN, +varNumsInds[var_num_ind], NO_ATR, scope);
	  	}
#line 2031 "analyzer.tab.c"
    break;

  case 62: /* @12: %empty  */
#line 512 "analyzer.y"
                {
			(yyval.i) = get_last_element()+1; 
			scope++;
			loopCounter++;
		}
#line 2041 "analyzer.tab.c"
    break;

  case 63: /* except_finally_body: _COLON _NEW_LINE @12 body  */
#line 518 "analyzer.y"
                {
			clear_symbols((yyvsp[-1].i));	
			scope--;
			loopCounter--;
		}
#line 2051 "analyzer.tab.c"
    break;

  case 68: /* @13: %empty  */
#line 533 "analyzer.y"
                {
			(yyval.i) = get_last_element()+1; 
			scope++;			
		}
#line 2060 "analyzer.tab.c"
    break;

  case 69: /* else_part: _ELSE _COLON _NEW_LINE @13 body  */
#line 538 "analyzer.y"
                {
			clear_symbols((yyvsp[-1].i));	
			scope--;
			code("\n@next%d_%d:", labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]);
		}
#line 2070 "analyzer.tab.c"
    break;

  case 70: /* $@14: %empty  */
#line 547 "analyzer.y"
                { 
			var_num_ind++; 
		}
#line 2078 "analyzer.tab.c"
    break;

  case 71: /* body: _INDENT $@14 statement_list _DEDENT  */
#line 551 "analyzer.y"
                {
            varNumsInds[var_num_ind] = 0;
			var_num_ind--;
	  	}
#line 2087 "analyzer.tab.c"
    break;

  case 72: /* num_exp: exp  */
#line 559 "analyzer.y"
                { (yyval.i) = (yyvsp[0].i); }
#line 2093 "analyzer.tab.c"
    break;

  case 73: /* num_exp: _NOT num_exp  */
#line 561 "analyzer.y"
                { 
			currRelOp = 4;
			(yyval.i) = take_reg();
			set_type((yyval.i), NUM_BOOL);
			
			code("\n\t\tCMPS \t");
			gen_sym_name((yyvsp[0].i));
			code(",$0");
			
            code("\n\t\t%s\t@true%d", jumps[4], cmpCounter);
            code("\n@false%d:", cmpCounter);

		    code("\n\t\tMOV \t$0, ");
		    gen_sym_name((yyval.i));

            code("\n\t\tJMP \t@cmp_end%d", cmpCounter);
            code("\n@true%d:", cmpCounter);

		    code("\n\t\tMOV \t$1, ");
		    gen_sym_name((yyval.i));		    

            code("\n@cmp_end%d:", cmpCounter++);
		}
#line 2121 "analyzer.tab.c"
    break;

  case 74: /* num_exp: num_exp _ADD_SUB_OP num_exp  */
#line 585 "analyzer.y"
                {
			int lt = get_type((yyvsp[-2].i));
			int rt = get_type((yyvsp[0].i));
			int newType = UNKNOWN;
			
			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Invalid operator for operands of type 'None'!");
				else if (lt == STRING && rt == STRING) {
					if ((yyvsp[-1].i) == SUB)
						err("Invalid operator '-' for operands of type 'string' and 'string'!");
					newType = STRING;
				}
				else if (lt == NUM_BOOL && rt == NUM_BOOL)
					newType = NUM_BOOL;
				else
					err("Invalid operator '+'/'-' for operands of type 'number'/'boolean' and 'string'!");
			}
			
			// Code gen part
		    code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i)]);
		    gen_sym_name((yyvsp[-2].i));
		    code(", ");
		    gen_sym_name((yyvsp[0].i));
		    code(", ");
		    free_if_reg((yyvsp[0].i));
		    free_if_reg((yyvsp[-2].i));
		    (yyval.i) = take_reg();
		    gen_sym_name((yyval.i));
		    set_type((yyval.i), newType);
		}
#line 2157 "analyzer.tab.c"
    break;

  case 75: /* num_exp: num_exp _MUL_DIV_OP num_exp  */
#line 617 "analyzer.y"
                {
			int lt = get_type((yyvsp[-2].i));
			int rt = get_type((yyvsp[0].i));
			int newType = UNKNOWN;
			
			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Invalid operator for operands of type 'None'!");
				else if (lt == STRING && rt == STRING)
					err("Invalid operator for operands of type 'string' and 'string'!");
				else if ((lt == NUM_BOOL && rt == STRING) || (lt == STRING && rt == NUM_BOOL)) {
					if ((yyvsp[-1].i) == DIV)
						err("Invalid operator for operands of type 'string' and 'number'/'boolean'!");
					newType = STRING;
				}
				else
					newType = NUM_BOOL;
			}
			
			// Code gen part
		    code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i)]);
		    gen_sym_name((yyvsp[-2].i));
		    code(", ");
		    gen_sym_name((yyvsp[0].i));
		    code(", ");
		    free_if_reg((yyvsp[0].i));
		    free_if_reg((yyvsp[-2].i));
		    (yyval.i) = take_reg();
		    gen_sym_name((yyval.i));
		    set_type((yyval.i), newType);
		}
#line 2193 "analyzer.tab.c"
    break;

  case 76: /* num_exp: num_exp _LOP num_exp  */
#line 649 "analyzer.y"
                {
			int lt = get_type((yyvsp[-2].i));
			int rt = get_type((yyvsp[0].i));

			if ((yyvsp[-1].i) == AND)
				return rt;
			else 
				return lt;			
		}
#line 2207 "analyzer.tab.c"
    break;

  case 77: /* num_exp: num_exp _RELOP num_exp  */
#line 659 "analyzer.y"
                {
			int lt = get_type((yyvsp[-2].i));
			int rt = get_type((yyvsp[0].i));
			int newType = UNKNOWN;
			
			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Invalid operator for operands of type 'None'!");
				else if ((lt == NUM_BOOL && rt == STRING) || (lt == STRING && rt == NUM_BOOL))
					err("Invalid operator for operands of type 'number'/'boolean' and 'string'!");
				else
					newType = NUM_BOOL;
			}
				
			currRelOp = (yyvsp[-1].i);
		    (yyval.i) = take_reg();
		    set_type((yyval.i), newType);
			
			gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
            code("\n\t\t%s\t@true%d", jumps[currRelOp], cmpCounter);
            code("\n@false%d:", cmpCounter);

		    code("\n\t\tMOV \t$0, ");
		    gen_sym_name((yyval.i));

            code("\n\t\tJMP \t@cmp_end%d", cmpCounter);
            code("\n@true%d:", cmpCounter);

		    code("\n\t\tMOV \t$1, ");
		    gen_sym_name((yyval.i));		    

            code("\n@cmp_end%d:", cmpCounter++);
		}
#line 2245 "analyzer.tab.c"
    break;

  case 78: /* exp: literal  */
#line 695 "analyzer.y"
                         { (yyval.i) = (yyvsp[0].i); }
#line 2251 "analyzer.tab.c"
    break;

  case 79: /* exp: _ID  */
#line 697 "analyzer.y"
                {
			int idInd = lookup_symbol_var_par((yyvsp[0].s));
			if (idInd == NO_INDEX)
				err("Variable '%s' does not exist!", (yyvsp[0].s));
			(yyval.i) = idInd; 
		}
#line 2262 "analyzer.tab.c"
    break;

  case 80: /* exp: function_call  */
#line 703 "analyzer.y"
                                { (yyval.i) = (yyvsp[0].i); }
#line 2268 "analyzer.tab.c"
    break;

  case 81: /* exp: _LPAREN num_exp _RPAREN  */
#line 704 "analyzer.y"
                                        { (yyval.i) = (yyvsp[-1].i); }
#line 2274 "analyzer.tab.c"
    break;

  case 82: /* literal: _NUM_BOOL  */
#line 708 "analyzer.y"
                        { (yyval.i) = insert_literal((yyvsp[0].s), NUM_BOOL, scope); }
#line 2280 "analyzer.tab.c"
    break;

  case 83: /* literal: _STRING  */
#line 709 "analyzer.y"
                        { (yyval.i) = insert_literal((yyvsp[0].s), STRING, scope); }
#line 2286 "analyzer.tab.c"
    break;

  case 84: /* literal: _NONE  */
#line 710 "analyzer.y"
                        { (yyval.i) = insert_literal((yyvsp[0].s), NONE, scope); }
#line 2292 "analyzer.tab.c"
    break;


#line 2296 "analyzer.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 714 "analyzer.y"


int main() {
	int synerr;
	init_symtab();

	output = fopen("output.asm", "w+");
	synerr = yyparse();

	clear_symtab();
	fclose(output);
		
	if(synerr)
		return -1;  //syntax error
	else if(error_count)
		return error_count & 127; //semantic errors
	else
		return 0; //OK 
}
int yyerror(const char *s) {
  fprintf(stderr, "line %d: SYNTAX ERROR %s\n", yylineno, s);
  error_count++;
  return 0;
}
