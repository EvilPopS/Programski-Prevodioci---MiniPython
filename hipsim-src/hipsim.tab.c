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
#line 19 "hipsim.y"


#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <libgen.h> //basename
#include <unistd.h> //isatty
#include "defs.h"
#include "simulator.h"

int yyparse(void);
int yylex(void);
int yyerror(char *s);
void warning(char *s);

extern int yylineno;
extern int code_cnt;
extern int source_cnt;
extern int max_steps;
extern Processor processor;
char char_buffer[CHAR_BUFFER_LENGTH];
int error_count = 0;
extern Symtab symtab[SYMTAB_LEN];      //tabela simbola (labela)
int mainarg = 0;


#line 101 "hipsim.tab.c"

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

#include "hipsim.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__WORD = 3,                      /* _WORD  */
  YYSYMBOL__PUSH = 4,                      /* _PUSH  */
  YYSYMBOL__POP = 5,                       /* _POP  */
  YYSYMBOL__CALL = 6,                      /* _CALL  */
  YYSYMBOL__RET = 7,                       /* _RET  */
  YYSYMBOL__CMP = 8,                       /* _CMP  */
  YYSYMBOL__JMP = 9,                       /* _JMP  */
  YYSYMBOL__JEQ = 10,                      /* _JEQ  */
  YYSYMBOL__JNE = 11,                      /* _JNE  */
  YYSYMBOL__JGT = 12,                      /* _JGT  */
  YYSYMBOL__JLT = 13,                      /* _JLT  */
  YYSYMBOL__JGE = 14,                      /* _JGE  */
  YYSYMBOL__JLE = 15,                      /* _JLE  */
  YYSYMBOL__JC = 16,                       /* _JC  */
  YYSYMBOL__JNC = 17,                      /* _JNC  */
  YYSYMBOL__JO = 18,                       /* _JO  */
  YYSYMBOL__JNO = 19,                      /* _JNO  */
  YYSYMBOL__ADD = 20,                      /* _ADD  */
  YYSYMBOL__SUB = 21,                      /* _SUB  */
  YYSYMBOL__MUL = 22,                      /* _MUL  */
  YYSYMBOL__DIV = 23,                      /* _DIV  */
  YYSYMBOL__MOV = 24,                      /* _MOV  */
  YYSYMBOL__HALT = 25,                     /* _HALT  */
  YYSYMBOL__REGISTER = 26,                 /* _REGISTER  */
  YYSYMBOL__CONSTANT = 27,                 /* _CONSTANT  */
  YYSYMBOL__NUMBER = 28,                   /* _NUMBER  */
  YYSYMBOL__LABEL_DEF = 29,                /* _LABEL_DEF  */
  YYSYMBOL__LABEL = 30,                    /* _LABEL  */
  YYSYMBOL__ADDRESS = 31,                  /* _ADDRESS  */
  YYSYMBOL__COMMA = 32,                    /* _COMMA  */
  YYSYMBOL__LPAREN = 33,                   /* _LPAREN  */
  YYSYMBOL__RPAREN = 34,                   /* _RPAREN  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_variable_list = 37,             /* variable_list  */
  YYSYMBOL_variable = 38,                  /* variable  */
  YYSYMBOL_39_1 = 39,                      /* @1  */
  YYSYMBOL_code_list = 40,                 /* code_list  */
  YYSYMBOL_code_line = 41,                 /* code_line  */
  YYSYMBOL_label_def = 42,                 /* label_def  */
  YYSYMBOL_asm_line = 43,                  /* asm_line  */
  YYSYMBOL_arithmetic = 44,                /* arithmetic  */
  YYSYMBOL_flowcontrol = 45,               /* flowcontrol  */
  YYSYMBOL_stack = 46,                     /* stack  */
  YYSYMBOL_label = 47,                     /* label  */
  YYSYMBOL_output = 48,                    /* output  */
  YYSYMBOL_input = 49                      /* input  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,   105,   106,   111,   110,   123,   124,   128,
     129,   133,   142,   143,   144,   145,   153,   159,   165,   171,
     177,   186,   192,   197,   202,   207,   212,   217,   222,   227,
     232,   237,   242,   250,   256,   262,   267,   275,   285,   290,
     295,   300,   304,   309,   318
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_WORD", "_PUSH",
  "_POP", "_CALL", "_RET", "_CMP", "_JMP", "_JEQ", "_JNE", "_JGT", "_JLT",
  "_JGE", "_JLE", "_JC", "_JNC", "_JO", "_JNO", "_ADD", "_SUB", "_MUL",
  "_DIV", "_MOV", "_HALT", "_REGISTER", "_CONSTANT", "_NUMBER",
  "_LABEL_DEF", "_LABEL", "_ADDRESS", "_COMMA", "_LPAREN", "_RPAREN",
  "$accept", "program", "variable_list", "variable", "@1", "code_list",
  "code_line", "label_def", "asm_line", "arithmetic", "flowcontrol",
  "stack", "label", "output", "input", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-6)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -25,     5,    14,   -25,   -24,    41,   -22,   -25,   -24,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -24,   -24,   -24,   -24,   -24,   -25,     7,   -25,    80,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -21,   -25,   -25,
     -15,   -25,   -25,   -25,   -25,   -25,     8,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,    10,    23,
      24,    25,    26,    56,   -25,   -25,    34,    32,   -24,   -24,
     -24,   -24,   -24,    41,    42,    38,   -25,   -25,    43,    44,
      45,    46,   -25,   -25,   -25,    41,    41,    41,    41,   -25,
     -25,   -25,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    11,     4,     2,     7,
       9,    10,    12,    13,    14,    38,    42,     0,    37,    43,
       0,    41,    44,    33,    34,    35,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,     0,
       0,     0,     0,     0,    11,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    21,     0,     0,
       0,     0,    20,     6,    39,     0,     0,     0,     0,    16,
      17,    18,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   -25,   -25,   -25,    51,   -25,   -25,   -25,
     -25,   -25,    35,    -5,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    27,    63,    28,    29,    30,    31,    32,
      33,    34,    41,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    46,    35,    36,    37,     3,    38,    39,    38,    40,
      -5,    67,    66,    58,    59,    60,    61,    62,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      68,    45,    69,    26,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    70,    71,    72,    73,    74,
      75,    77,    78,    79,    80,    81,    76,    35,    82,    37,
      83,    38,    84,     0,    40,    85,    86,    87,    88,    65,
      89,    90,    91,    92,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,    64
};

static const yytype_int8 yycheck[] =
{
       5,     8,    26,    27,    28,     0,    30,    31,    30,    33,
       3,    26,    33,    20,    21,    22,    23,    24,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      32,     6,    32,    29,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    32,    32,    32,    32,     3,
      26,    68,    69,    70,    71,    72,    34,    26,    73,    28,
      28,    30,    34,    -1,    33,    32,    32,    32,    32,    28,
      85,    86,    87,    88,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    29,    38,    40,    41,
      42,    43,    44,    45,    46,    26,    27,    28,    30,    31,
      33,    47,    48,    49,    48,    47,    49,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    49,    49,
      49,    49,    49,    39,    29,    41,    33,    26,    32,    32,
      32,    32,    32,    32,     3,    26,    34,    49,    49,    49,
      49,    49,    48,    28,    34,    32,    32,    32,    32,    48,
      48,    48,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    39,    38,    40,    40,    41,
      41,    42,    43,    43,    43,    43,    44,    44,    44,    44,
      44,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    46,    46,    47,    48,    48,
      48,    48,    49,    49,    49
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     4,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     6,     6,     6,     6,
       4,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     4,
       3,     1,     1,     1,     1
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
  case 2: /* program: variable_list code_list  */
#line 99 "hipsim.y"
        {
            add_entry_code(mainarg);
        }
#line 1195 "hipsim.tab.c"
    break;

  case 5: /* @1: %empty  */
#line 111 "hipsim.y"
        { (yyval.i) = yylineno; }
#line 1201 "hipsim.tab.c"
    break;

  case 6: /* variable: _LABEL_DEF @1 _WORD _NUMBER  */
#line 113 "hipsim.y"
        {
            uchar data[256];
            int i,len = (yyvsp[0].i)*4;
            for (i=0; i<len; i++) data[i] = 0;
            insert_source("%s:\t\t\tWORD %ld",(yyvsp[-3].s),(yyvsp[0].i));
            insert_data(data,len, (yyvsp[-3].s), (yyvsp[-2].i));
        }
#line 1213 "hipsim.tab.c"
    break;

  case 11: /* label_def: _LABEL_DEF  */
#line 134 "hipsim.y"
        {
            insert_source("%s:",(yyvsp[0].s));
            insert_label((yyvsp[0].s), code_cnt, yylineno, SYM_JUMP);
            source_cnt++;
        }
#line 1223 "hipsim.tab.c"
    break;

  case 15: /* asm_line: _HALT  */
#line 146 "hipsim.y"
        {
            insert_source("\t\t\tHALT");
            insert_code(INS_HALT, NO_TYPE, yylineno);
        }
#line 1232 "hipsim.tab.c"
    break;

  case 16: /* arithmetic: _ADD input _COMMA input _COMMA output  */
#line 154 "hipsim.y"
        {
            insert_source("\t\t\tADD%c %s, %s, %s", type_char((yyvsp[-5].i)), (yyvsp[-4].s), (yyvsp[-2].s), (yyvsp[0].s));
            insert_code(INS_ADD, (yyvsp[-5].i), yylineno);
            free((yyvsp[-4].s)); free((yyvsp[-2].s)); free((yyvsp[0].s));
        }
#line 1242 "hipsim.tab.c"
    break;

  case 17: /* arithmetic: _SUB input _COMMA input _COMMA output  */
#line 160 "hipsim.y"
        {
            insert_source("\t\t\tSUB%c %s, %s, %s", type_char((yyvsp[-5].i)), (yyvsp[-4].s), (yyvsp[-2].s), (yyvsp[0].s));
            insert_code(INS_SUB, (yyvsp[-5].i), yylineno);
            free((yyvsp[-4].s)); free((yyvsp[-2].s)); free((yyvsp[0].s));
        }
#line 1252 "hipsim.tab.c"
    break;

  case 18: /* arithmetic: _MUL input _COMMA input _COMMA output  */
#line 166 "hipsim.y"
        {
            insert_source("\t\t\tMUL%c %s, %s, %s", type_char((yyvsp[-5].i)), (yyvsp[-4].s), (yyvsp[-2].s), (yyvsp[0].s));
            insert_code(INS_MUL, (yyvsp[-5].i), yylineno);
            free((yyvsp[-4].s)); free((yyvsp[-2].s)); free((yyvsp[0].s));
        }
#line 1262 "hipsim.tab.c"
    break;

  case 19: /* arithmetic: _DIV input _COMMA input _COMMA output  */
#line 172 "hipsim.y"
        {
            insert_source("\t\t\tDIV%c %s, %s, %s", type_char((yyvsp[-5].i)), (yyvsp[-4].s), (yyvsp[-2].s), (yyvsp[0].s));
            insert_code(INS_DIV, (yyvsp[-5].i), yylineno);
            free((yyvsp[-4].s)); free((yyvsp[-2].s)); free((yyvsp[0].s));
        }
#line 1272 "hipsim.tab.c"
    break;

  case 20: /* arithmetic: _MOV input _COMMA output  */
#line 178 "hipsim.y"
        {
            insert_source("\t\t\tMOV %s, %s", (yyvsp[-2].s), (yyvsp[0].s));
            insert_code(INS_MOV, NO_TYPE, yylineno);
            free((yyvsp[-2].s)); free((yyvsp[0].s));
        }
#line 1282 "hipsim.tab.c"
    break;

  case 21: /* flowcontrol: _CMP input _COMMA input  */
#line 187 "hipsim.y"
        {
            insert_source("\t\t\tCMP%c %s, %s", type_char((yyvsp[-3].i)), (yyvsp[-2].s), (yyvsp[0].s));
            insert_code(INS_CMP, (yyvsp[-3].i), yylineno);
            free((yyvsp[-2].s)); free((yyvsp[0].s));
        }
#line 1292 "hipsim.tab.c"
    break;

  case 22: /* flowcontrol: _JMP label  */
#line 193 "hipsim.y"
        {
            insert_source("\t\t\tJMP %s", (yyvsp[0].s));
            insert_code(INS_JMP, NO_TYPE, yylineno);
        }
#line 1301 "hipsim.tab.c"
    break;

  case 23: /* flowcontrol: _JEQ label  */
#line 198 "hipsim.y"
        {
            insert_source("\t\t\tJEQ %s", (yyvsp[0].s));
            insert_code(INS_JEQ, NO_TYPE, yylineno);
        }
#line 1310 "hipsim.tab.c"
    break;

  case 24: /* flowcontrol: _JNE label  */
#line 203 "hipsim.y"
        {
            insert_source("\t\t\tJNE %s", (yyvsp[0].s));
            insert_code(INS_JNE, NO_TYPE, yylineno);
        }
#line 1319 "hipsim.tab.c"
    break;

  case 25: /* flowcontrol: _JGT label  */
#line 208 "hipsim.y"
        {
            insert_source("\t\t\tJGT%c %s", type_char((yyvsp[-1].i)), (yyvsp[0].s));
            insert_code(INS_JGT, (yyvsp[-1].i), yylineno);
        }
#line 1328 "hipsim.tab.c"
    break;

  case 26: /* flowcontrol: _JLT label  */
#line 213 "hipsim.y"
        {
            insert_source("\t\t\tJLT%c %s", type_char((yyvsp[-1].i)), (yyvsp[0].s));
            insert_code(INS_JLT, (yyvsp[-1].i), yylineno);
        }
#line 1337 "hipsim.tab.c"
    break;

  case 27: /* flowcontrol: _JGE label  */
#line 218 "hipsim.y"
        {
            insert_source("\t\t\tJGE%c %s", type_char((yyvsp[-1].i)), (yyvsp[0].s));
            insert_code(INS_JGE, (yyvsp[-1].i), yylineno);
        }
#line 1346 "hipsim.tab.c"
    break;

  case 28: /* flowcontrol: _JLE label  */
#line 223 "hipsim.y"
        {
            insert_source("\t\t\tJLE%c %s", type_char((yyvsp[-1].i)), (yyvsp[0].s));
            insert_code(INS_JLE, (yyvsp[-1].i), yylineno);
        }
#line 1355 "hipsim.tab.c"
    break;

  case 29: /* flowcontrol: _JC label  */
#line 228 "hipsim.y"
        {
            insert_source("\t\t\tJC %s", (yyvsp[0].s));
            insert_code(INS_JC, NO_TYPE, yylineno);
        }
#line 1364 "hipsim.tab.c"
    break;

  case 30: /* flowcontrol: _JNC label  */
#line 233 "hipsim.y"
        {
            insert_source("\t\t\tJNC %s", (yyvsp[0].s));
            insert_code(INS_JNC, NO_TYPE, yylineno);
        }
#line 1373 "hipsim.tab.c"
    break;

  case 31: /* flowcontrol: _JO label  */
#line 238 "hipsim.y"
        {
            insert_source("\t\t\tJO %s", (yyvsp[0].s));
            insert_code(INS_JO, NO_TYPE, yylineno);
        }
#line 1382 "hipsim.tab.c"
    break;

  case 32: /* flowcontrol: _JNO label  */
#line 243 "hipsim.y"
        {
            insert_source("\t\t\tJNO %s", (yyvsp[0].s));
            insert_code(INS_JNO, NO_TYPE, yylineno);
        }
#line 1391 "hipsim.tab.c"
    break;

  case 33: /* stack: _PUSH input  */
#line 251 "hipsim.y"
        {
            insert_source("\t\t\tPUSH %s", (yyvsp[0].s));
            insert_code(INS_PUSH, NO_TYPE, yylineno);
            free((yyvsp[0].s));
        }
#line 1401 "hipsim.tab.c"
    break;

  case 34: /* stack: _POP output  */
#line 257 "hipsim.y"
        {
            insert_source("\t\t\tPOP %s", (yyvsp[0].s));
            insert_code(INS_POP, NO_TYPE, yylineno);
            free((yyvsp[0].s));
        }
#line 1411 "hipsim.tab.c"
    break;

  case 35: /* stack: _CALL label  */
#line 263 "hipsim.y"
        {
            insert_source("\t\t\tCALL %s", (yyvsp[0].s));
            insert_code(INS_CALL, NO_TYPE, yylineno);
        }
#line 1420 "hipsim.tab.c"
    break;

  case 36: /* stack: _RET  */
#line 268 "hipsim.y"
        {
            insert_source("\t\t\tRET");
            insert_code(INS_RET, NO_TYPE, yylineno);
        }
#line 1429 "hipsim.tab.c"
    break;

  case 37: /* label: _LABEL  */
#line 276 "hipsim.y"
        {
            int l;
            (yyval.s) = make_opstr("%s",(yyvsp[0].s));
            l = use_label((yyvsp[0].s), yylineno);
            add_operand(OP_DATA,0,l);
        }
#line 1440 "hipsim.tab.c"
    break;

  case 38: /* output: _REGISTER  */
#line 286 "hipsim.y"
        {
            add_operand(OP_REGISTER,(yyvsp[0].i),0);
            (yyval.s) = make_opstr("%%%ld",(yyvsp[0].i));
        }
#line 1449 "hipsim.tab.c"
    break;

  case 39: /* output: _NUMBER _LPAREN _REGISTER _RPAREN  */
#line 291 "hipsim.y"
        {
            add_operand(OP_INDEX,(yyvsp[-1].i),(yyvsp[-3].i));
            (yyval.s) = make_opstr("%ld(%%%ld)",(yyvsp[-3].i),(yyvsp[-1].i));
        }
#line 1458 "hipsim.tab.c"
    break;

  case 40: /* output: _LPAREN _REGISTER _RPAREN  */
#line 296 "hipsim.y"
        {
            add_operand(OP_INDIRECT,(yyvsp[-1].i),0);
            (yyval.s) = make_opstr("(%%%ld)",(yyvsp[-1].i));
        }
#line 1467 "hipsim.tab.c"
    break;

  case 42: /* input: _CONSTANT  */
#line 305 "hipsim.y"
        {
            add_operand(OP_CONSTANT,0,(yyvsp[0].i));
            (yyval.s) = make_opstr("$%ld",(yyvsp[0].i));
        }
#line 1476 "hipsim.tab.c"
    break;

  case 43: /* input: _ADDRESS  */
#line 310 "hipsim.y"
        {
            int l;
            (yyval.s) = make_opstr("$%s",(yyvsp[0].s));
            l = use_label((yyvsp[0].s), yylineno);
            /* if (symtab[l].usage == LAB_UNDEFINED)
                parsererror("Undeclared global variable %s",$1); */
            add_operand(OP_CONSTANT,0,symtab[l].address);
        }
#line 1489 "hipsim.tab.c"
    break;


#line 1493 "hipsim.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 321 "hipsim.y"


int yyerror(char *s) {
    fprintf(stderr, "\nSimulator: ASM parsing error in line %d: %s\n", yylineno, s);
    error_count++;
    return 0;
}

int main(int argc, char *argv[]) {
    int i;
    char c;
    char run_complete = FALSE;
    char syntax_check = FALSE;
    char *print_variable = 0;
    //yydebug = 1;  //debagovanje parsera

    //parsiranje opcija programa
    opterr=0;
    while (1) {
        c = getopt(argc, argv, ":hcra:p:s:");
        if (c == -1) break;
        switch(c) {
            case 'h' : {
                    cprintf("\n{BLU}Hypothetic processor simulator{NRM} v%s",VERSION);
                    cprintf("\n\nUsage: {BLU}%s{NRM} [options] {BLU}< asm_file{NRM}", basename(strdup(argv[0])));
                    cprintf("\nIf started without options, simulator will run asm code");
                    cprintf("\nstep by step. Possible options are:");
                    cprintf("\n{GRN}-h{NRM}     - this help");
                    cprintf("\n{GRN}-c{NRM}     - syntax check of asm code, without execution");
                    cprintf("\n{GRN}-r{NRM}     - complete run of the program, only exit code (%%%d) output",FUNCTION_REGISTER);
                    cprintf("\n{GRN}-p VAR{NRM} - complete run of the program, only global var output");
                    cprintf("\n{GRN}-a VAR{NRM} - value of argument passed to main function (default: 0)");
                    cprintf("\n{GRN}-s NUM{NRM} - maximal number of execution steps for complete run");
                    cprintf("\n         (simulator will return code %d if this number is reached)\n\n",STEP_ERROR);
                    exit(0);
                    break; }
            case 'c' : {
                    syntax_check = TRUE;
                    break; }
            case 'r' : {
                    run_complete = TRUE;
                    break; }
            case 'a' : {
                    mainarg = atoi(optarg);
                    break; }
            case 'p' : {
                    run_complete = TRUE;
                    print_variable = optarg;
                    break; }
            case 's' : {
                    max_steps = atoi(optarg);
                    break; }
            case '?' : {
                    argerror("Unknown option %c",optopt);
                    break; }
            case ':' : {
                    argerror("Argument missing for option %c",optopt);
                    break; }
            default : {
                    argerror("Unknown getopt return code 0x%X",c);
                    break; }
        }
    }

    //proveri da li postoji ulazni fajl
    if (isatty(fileno(stdin))) {
        argerror("No input file was specified.");
    }

    //parsiranje asemblerskog koda
    init_simulator();
    if ( ! yyparse() ) {
        check_labels();
        if (print_variable && !check_global(print_variable)) {
            argerror("Undeclared global variable %s",print_variable);
        }
    }

    //preusmeravanje terminala na stdin
    freopen("/dev/tty", "rw", stdin);

    if (error_count) {
        if (!run_complete)
            cprintf("\n{RED}There were error(s) in ASM source.{NRM}", error_count);
        printf("\n");
        exit(PARSE_ERROR);
    } else if (syntax_check)
            cprintf("{GRN}OK{NRM}");
    else {
        if (run_complete) {
            run();
            if (max_steps != 0) {
                if (print_variable)
                    printf("%d",get_global(print_variable));
                else
                    printf("%d",processor.reg[FUNCTION_REGISTER]);
            } else
                cprintf("\n{RED}Program terminated.{NRM}");
        } else {
            while (!processor.halt) {
                system("clear");
                print_source(PRINT_SRCLINES);
                print_global();
                print_registers();
                print_stack(PRINT_STKLINES);
                printf("\nPress any key to continue, ctrl+c for exit...");
                getch();
                run_once();
            }
            system("clear");
            print_source(PRINT_SRCLINES);
            print_global();
            print_registers();
            print_stack(PRINT_STKLINES);
            cprintf("\n\n{BLU}Program exit code (%%%d): {GRN}%d{NRM}\n",
                    FUNCTION_REGISTER, processor.reg[FUNCTION_REGISTER]);
            printf("\nAll OK.\n");
        }
    }
    printf("\n");
    if (error_count)
        return PARSE_ERROR;
    else if (max_steps != 0)
        return NO_ERROR;
    else
        //izvršeno max_steps koraka, a program se nije završio
        return STEP_ERROR;
}

