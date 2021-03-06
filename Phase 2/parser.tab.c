/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include <cstdio>
	#include <iostream>
	using namespace std;
	#include <string>
	extern "C" int yylex();
	extern int yyparse();
	extern FILE **yyin;
	#include "ast.h"
	void yyerror(const char *s);

#line 78 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    RETURN = 259,
    BREAK = 260,
    IMPORT = 261,
    IF = 262,
    ELIF = 263,
    ELSE = 264,
    FOR = 265,
    WHILE = 266,
    DEF = 267,
    NOT = 268,
    SCOMMA = 269,
    COMMA = 270,
    OF = 271,
    CF = 272,
    OC = 273,
    CC = 274,
    OS = 275,
    CS = 276,
    QUEST = 277,
    COLON = 278,
    ADD = 279,
    DIV = 280,
    EQ = 281,
    GEQ = 282,
    GT = 283,
    LEQ = 284,
    LT = 285,
    MULT = 286,
    NEQ = 287,
    SUB = 288,
    AND = 289,
    OR = 290,
    MOD = 291,
    INTL = 292,
    UINTL = 293,
    CHAR = 294,
    TRUE = 295,
    FALSE = 296,
    ID = 297,
    VOID = 298,
    TINT = 299,
    TUINT = 300,
    TCHAR = 301,
    TBOOL = 302,
    STOP = 303,
    ASGN = 304,
    PASGN = 305,
    SASGN = 306,
    STATEMENT = 307,
    LOCID = 308,
    EXPRESSIONVSEXPRESSION = 309,
    EXPRESSIONVSLOCASGNEXP = 310,
    UMINUS = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "parser.y" /* yacc.c:355  */

char* value;
class ASTnode *node;

#line 180 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 197 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   689

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    57,    58,    59,    60,    63,    64,    67,
      69,    70,    72,    74,    75,    78,    79,    82,    83,    86,
      87,    88,    89,    90,    91,    94,    95,    98,   100,   102,
     104,   105,   107,   109,   110,   113,   114,   117,   118,   121,
     122,   123,   126,   128,   130,   131,   133,   134,   135,   136,
     139,   140,   141,   144,   145,   146,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   170,   171,   172,   175,   176,
     177,   178,   179,   182,   183,   184,   185,   187,   188,   191,
     192
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "RETURN", "BREAK", "IMPORT",
  "IF", "ELIF", "ELSE", "FOR", "WHILE", "DEF", "NOT", "SCOMMA", "COMMA",
  "OF", "CF", "OC", "CC", "OS", "CS", "QUEST", "COLON", "ADD", "DIV", "EQ",
  "GEQ", "GT", "LEQ", "LT", "MULT", "NEQ", "SUB", "AND", "OR", "MOD",
  "INTL", "UINTL", "CHAR", "TRUE", "FALSE", "ID", "VOID", "TINT", "TUINT",
  "TCHAR", "TBOOL", "STOP", "ASGN", "PASGN", "SASGN", "STATEMENT", "LOCID",
  "EXPRESSIONVSEXPRESSION", "EXPRESSIONVSLOCASGNEXP", "UMINUS", "$accept",
  "FinalNode", "File", "ImportList", "Import", "ListofFunctions",
  "Function", "ArgList", "VoidableArgList", "ListOfCode", "Code", "Loop",
  "TernaryOp", "ForLoop", "WhileLoop", "Return", "Break",
  "VoidableSingleStatement", "Voidable", "Conditional", "Else_Block",
  "Elif_Piece", "Else_Piece", "ListOfStatem", "Statement",
  "Initialization", "AsignOp", "Expression", "Location", "Literal",
  "Vartype", "MethodCall", "ListOfExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     381,    33,   -41,   -25,   508,   508,   508,  -141,  -141,  -141,
    -141,  -141,    21,  -141,  -141,  -141,  -141,    20,  -141,   381,
    -141,    11,  -141,    -4,  -141,  -141,   653,   -24,  -141,   -13,
    -141,   -12,    -5,    18,  -141,  -141,   503,  -141,   478,   508,
    -141,  -141,    11,    -4,  -141,   437,    11,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
    -141,  -141,  -141,   508,   -24,    40,  -141,    96,  -141,  -141,
     653,     3,   550,    11,  -141,   417,    41,   -23,   -23,   -23,
     -23,   -23,    41,   -23,   417,  -141,  -141,    41,   653,   508,
     508,  -141,    49,    47,    32,   508,  -141,   508,  -141,   653,
     572,    33,    70,  -141,   653,   624,   508,  -141,    48,   365,
    -141,   640,  -141,   467,    43,    74,    79,    80,   179,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,    45,    77,  -141,
      53,    -6,  -141,   508,    82,   421,  -141,  -141,   437,  -141,
    -141,   590,  -141,    88,    45,  -141,    84,  -141,    81,    91,
     508,    92,   437,   365,   528,   365,    62,   196,    82,   241,
    -141,    75,    94,  -141,    93,    98,  -141,    75,  -141,   100,
     508,   365,  -141,   365,   608,   258,   303,   101,  -141,  -141,
     365,   320,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    78,    82,    81,
      79,    80,    75,    83,    84,    86,    85,     0,     2,     0,
       7,     5,    10,     0,    45,    49,    46,    56,    57,     0,
      74,     0,     0,     0,    72,    56,     0,    73,     0,     0,
       1,     8,     6,     0,    11,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,     0,    50,     0,     9,     0,    71,    87,
      89,     0,     0,     3,    44,    58,    61,    66,    64,    65,
      63,    67,    60,    68,    59,    69,    70,    62,    47,     0,
       0,    15,    16,     0,     0,     0,    88,     0,    76,    48,
       0,     0,     0,    13,    90,     0,     0,    51,     0,     0,
      77,     0,    14,     0,     0,     0,     0,     0,     0,    17,
      21,    24,    25,    26,    22,    23,    20,    19,    45,    52,
       0,     0,    32,     0,     0,     0,    12,    18,     0,    30,
      31,     0,    35,     0,    36,    33,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    37,     0,    29,     0,     0,    38,    40,    39,     0,
       0,     0,    41,     0,     0,     0,     0,     0,    43,    28,
       0,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,   111,    -9,   -14,  -141,  -141,  -140,
     -94,  -141,  -141,  -141,  -141,  -141,  -141,  -141,   -27,  -141,
     -34,  -141,  -141,     2,    16,  -141,    73,    -1,     0,  -141,
       5,  -141,    31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    92,    93,   118,
     119,   120,   121,   122,   123,   124,   125,   146,   143,   126,
     166,   167,   168,   127,   128,    25,    63,    26,    35,    28,
      29,    30,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    32,    23,    34,    36,    37,    31,    44,     3,    95,
      42,    57,    58,   157,    46,   159,    24,    33,    95,    27,
      40,    43,    96,     3,   137,    60,    61,    62,    44,    64,
      65,   175,    44,   176,    73,    24,    67,    70,    72,    38,
     181,    39,   140,    66,    45,    27,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    44,
      90,    74,    88,   137,   101,   137,   102,    49,    50,    51,
      52,    53,    94,    55,   103,    57,    58,    13,    14,    15,
      16,   137,   137,   164,   165,     1,   109,   137,    99,   100,
     112,   132,   133,    45,   104,     4,   105,   134,   135,   138,
       5,   139,   150,   151,   152,   111,   108,   153,   155,    27,
     160,   170,    70,   169,   171,     6,   173,   180,    27,     7,
       8,     9,    10,    11,    12,   142,    13,    14,    15,    16,
      41,   162,   141,   172,    27,    27,   144,    89,    27,    91,
      13,    14,    15,    16,   131,     0,     0,     0,     0,   154,
      24,   147,    27,    27,   148,    27,     0,    27,    27,    27,
     144,     0,     0,     0,     0,     0,     0,     0,   156,   174,
       0,    27,     0,    27,    24,    27,    27,     0,     0,     0,
      27,    27,     1,   113,   114,     0,   115,     0,     0,   116,
     117,     0,     4,     0,     0,     0,   136,     5,     0,     1,
     113,   114,     0,   115,     0,     0,   116,   117,     0,     4,
       0,     0,     6,   161,     5,     0,     7,     8,     9,    10,
      11,    12,     0,    13,    14,    15,    16,     0,     0,     6,
       0,     0,     0,     7,     8,     9,    10,    11,    12,     0,
      13,    14,    15,    16,     1,   113,   114,     0,   115,     0,
       0,   116,   117,     0,     4,     0,     0,     0,   163,     5,
       0,     1,   113,   114,     0,   115,     0,     0,   116,   117,
       0,     4,     0,     0,     6,   178,     5,     0,     7,     8,
       9,    10,    11,    12,     0,    13,    14,    15,    16,     0,
       0,     6,     0,     0,     0,     7,     8,     9,    10,    11,
      12,     0,    13,    14,    15,    16,     1,   113,   114,     0,
     115,     0,     0,   116,   117,     0,     4,     0,     0,     0,
     179,     5,     0,     1,   113,   114,     0,   115,     0,     0,
     116,   117,     0,     4,     0,     0,     6,   182,     5,     0,
       7,     8,     9,    10,    11,    12,     0,    13,    14,    15,
      16,     0,     0,     6,     0,     0,     0,     7,     8,     9,
      10,    11,    12,     0,    13,    14,    15,    16,     1,   113,
     114,     0,   115,     0,     0,   116,   117,     0,     4,     0,
       0,     0,     0,     5,     1,     0,     0,     2,     0,     0,
       0,     0,     0,     3,     4,     0,     0,     0,     6,     5,
       0,     0,     7,     8,     9,    10,    11,    12,     0,    13,
      14,    15,    16,     0,     6,     0,     0,     0,     7,     8,
       9,    10,    11,    12,     1,    13,    14,    15,    16,     0,
       0,     0,     0,     0,     4,     0,     0,     0,     0,     5,
       1,     0,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    57,    58,    59,     6,     5,     0,     0,     7,     8,
       9,    10,    11,    12,   145,    13,    14,    15,    16,     0,
       6,     0,     0,     0,     7,     8,     9,    10,    11,    12,
       4,    13,    14,    15,    16,     5,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     5,    69,     0,     0,
       6,     0,     0,     0,     7,     8,     9,    10,    11,    12,
     130,     6,     0,     0,     0,     7,     8,     9,    10,    11,
      12,     4,    68,     0,     0,     0,     5,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     6,   158,     0,     0,     7,     8,     9,    10,    11,
      12,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    97,     0,     0,     0,     0,
       0,    98,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   106,     0,     0,
       0,     0,     0,   107,     0,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,   149,
       0,     0,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   177,     0,     0,
       0,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   110,     0,     0,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   129,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59
};

static const yytype_int16 yycheck[] =
{
       0,    42,     0,     4,     5,     6,     1,    21,    12,    15,
      19,    34,    35,   153,    23,   155,     0,    42,    15,    19,
       0,    19,    19,    12,   118,    49,    50,    51,    42,    42,
      42,   171,    46,   173,    43,    19,    18,    38,    39,    18,
     180,    20,    48,    48,    48,    45,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    73,
      20,    45,    63,   157,    15,   159,    19,    26,    27,    28,
      29,    30,    67,    32,    42,    34,    35,    44,    45,    46,
      47,   175,   176,     8,     9,     3,    16,   181,    89,    90,
      42,    48,    18,    48,    95,    13,    97,    18,    18,    22,
      18,    48,    14,    19,    23,   106,   101,    16,    16,   109,
      48,    18,   113,    19,    16,    33,    16,    16,   118,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      19,   158,   133,   167,   134,   135,   134,    64,   138,    43,
      44,    45,    46,    47,   113,    -1,    -1,    -1,    -1,   150,
     134,   135,   152,   153,   138,   155,    -1,   157,   158,   159,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   170,
      -1,   171,    -1,   173,   158,   175,   176,    -1,    -1,    -1,
     180,   181,     3,     4,     5,    -1,     7,    -1,    -1,    10,
      11,    -1,    13,    -1,    -1,    -1,    17,    18,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    11,    -1,    13,
      -1,    -1,    33,    17,    18,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    46,    47,    -1,    -1,    33,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    46,    47,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    11,    -1,    13,    -1,    -1,    -1,    17,    18,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    11,
      -1,    13,    -1,    -1,    33,    17,    18,    -1,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    46,    47,    -1,
      -1,    33,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    46,    47,     3,     4,     5,    -1,
       7,    -1,    -1,    10,    11,    -1,    13,    -1,    -1,    -1,
      17,    18,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,    -1,    -1,    33,    17,    18,    -1,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    46,
      47,    -1,    -1,    33,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    46,    47,     3,     4,
       5,    -1,     7,    -1,    -1,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    18,     3,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    33,    18,
      -1,    -1,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    46,    47,    -1,    33,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,     3,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    18,
       3,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      13,    34,    35,    36,    33,    18,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      13,    44,    45,    46,    47,    18,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    33,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    13,    19,    -1,    -1,    -1,    18,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    33,    14,    -1,    -1,    37,    38,    39,    40,    41,
      42,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    15,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    15,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    21,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,    12,    13,    18,    33,    37,    38,    39,
      40,    41,    42,    44,    45,    46,    47,    58,    59,    60,
      61,    62,    63,    80,    81,    82,    84,    85,    86,    87,
      88,    87,    42,    42,    84,    85,    84,    84,    18,    20,
       0,    61,    62,    80,    63,    48,    62,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      49,    50,    51,    83,    42,    42,    48,    18,    19,    19,
      84,    89,    84,    62,    81,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    83,
      20,    43,    64,    65,    87,    15,    19,    15,    21,    84,
      84,    15,    19,    42,    84,    84,    15,    21,    87,    16,
      21,    84,    42,     4,     5,     7,    10,    11,    66,    67,
      68,    69,    70,    71,    72,    73,    76,    80,    81,    21,
      43,    89,    48,    18,    18,    18,    17,    67,    22,    48,
      48,    84,    43,    75,    80,    43,    74,    81,    81,    19,
      14,    19,    23,    16,    84,    16,    81,    66,    14,    66,
      48,    17,    75,    17,     8,     9,    77,    78,    79,    19,
      18,    16,    77,    16,    84,    66,    66,    19,    17,    17,
      16,    66,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    60,    60,    61,
      62,    62,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    70,    71,
      72,    72,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    78,    79,    80,    80,    81,    81,    81,    81,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    85,    85,    85,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    88,    88,    89,
      89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     2,     1,     2,     3,
       1,     2,     8,     2,     4,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     6,    11,     7,
       3,     3,     2,     1,     1,     1,     1,     7,     8,     1,
       1,     2,     7,     4,     3,     1,     1,     3,     4,     1,
       2,     6,     8,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     4,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 55 "parser.y" /* yacc.c:1646  */
    {cout << "-------AST------" << endl; (yyvsp[0].node)->visit();cout << "------------------------" << endl;}
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FileNode((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); cout << "Imports + GlobalDecs + Funcs" << endl;}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FileNode(NULL, (yyvsp[-1].node), (yyvsp[0].node)); cout << "GlobalDecs + Functions" << endl;}
#line 1520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FileNode(NULL, NULL, (yyvsp[0].node)); cout << "Funcs" << endl;}
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FileNode((yyvsp[-1].node), NULL, (yyvsp[0].node)); cout << "Imports + Funcs" << endl;}
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 63 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ImportsListNode((yyvsp[0].node)); cout << "Import" << endl;}
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 64 "parser.y" /* yacc.c:1646  */
    { (yyval.node)->pb((yyvsp[0].node)); cout << "List Of Imports" << endl;}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 67 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 69 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new FunctionListNode((yyvsp[0].node)); cout << "Single Function" << endl;}
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 70 "parser.y" /* yacc.c:1646  */
    {(yyval.node)->pb((yyvsp[0].node)); cout << "List of Functions" << endl;}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 72 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new FunctionNode((yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node)); cout << "Function" << endl;}
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 74 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new ArgListNode(new SingleInitNode((yyvsp[0].node),std::string((yyvsp[-1].value)))); cout << "TYPE ID" << endl;}
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 75 "parser.y" /* yacc.c:1646  */
    {(yyval.node)->pb(new SingleInitNode((yyvsp[0].node),std::string((yyvsp[-1].value)))); cout << "List of Vartype ID" << endl;}
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 78 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 82 "parser.y" /* yacc.c:1646  */
    {cout << "LC -< C" << endl; (yyval.node) = new CodesNode((yyvsp[0].node));}
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.node)->pb((yyvsp[0].node));}
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 86 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "Code" << endl;}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "If-Else" << endl;}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "Loop" << endl;}
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "Return" << endl;}
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "Break" << endl;}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "Ternary Op" << endl;}
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "For" << endl;}
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "While" << endl;}
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TernaryNode((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node)); cout << "Tern Expr" << endl;}
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 100 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new ForNode((yyvsp[-8].node),(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node));}
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new WhileNode((yyvsp[-4].node),(yyvsp[-1].node));}
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new ReturnNode((yyvsp[-1].node));}
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new ReturnNode((yyvsp[-1].node));}
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BreakNode(); cout << "Break" << endl;}
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "VOID" << endl;}
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "Voidable -> ListOfCode" << endl;}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ConditionNode((yyvsp[-4].node),(yyvsp[-1].node)); cout << "If{*}" << endl;}
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 118 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new ConditionNode((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node)); cout << "If-El*" << endl;}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ElseBlockNode((yyvsp[0].node));}
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ElseBlockNode(); (yyval.node)->pb((yyvsp[0].node));}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->pb((yyvsp[-1].node)); cout << "Elif*" << endl;}
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new ElseIfNode((yyvsp[-4].node), (yyvsp[-1].node));}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 128 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new ElseNode((yyvsp[-1].node));}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.node)->pb((yyvsp[0].node)); cout << "S |n S" << endl;}
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new StatementsNode((yyvsp[0].node)); cout << "Statement" << endl;}
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "S->Expression" << endl;}
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new AssignmentNode((yyvsp[-2].node),std::string((yyvsp[-1].value)),(yyvsp[0].node)); cout << "Loc = Expr" << endl;}
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new InitAssignmentNode((yyvsp[-2].node),std::string((yyvsp[-1].value)),(yyvsp[0].node),std::string((yyvsp[-3].value))); cout << "Type Id = Expr" << endl;}
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "INIT" << endl;}
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new SingleInitNode((yyvsp[0].node),std::string((yyvsp[-1].value)));}
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OneDInitNode((yyvsp[-3].node),(yyvsp[-1].node),std::string((yyvsp[-4].value))) ;cout << "1d array init" << endl;}
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TwoDInitNode((yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node),std::string((yyvsp[-6].value))); cout << "2d array init" << endl;}
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 144 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value); cout << "=" << endl;}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value); cout << "+=" << endl;}
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value); cout << "-=" << endl;}
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); cout << "Location" << endl;}
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); cout << "Literal" << endl;}
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "add");  cout << "Expr + Expr"<< endl;}
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "sub");  cout << "Expr - Expr"<< endl;}
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "mult"); cout << "Expr * Expr"<< endl;}
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "div");  cout << "Expr / Expr" << endl;}
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "mod");  cout << "Expr mod Expr" << endl;}
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "leq");  cout << "Expr <= Expr" << endl;}
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "geq");  cout << "Expr >= Expr" << endl;}
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "gt");   cout << "Expr > Expr" << endl;}
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "eq");   cout << "Expr == Expr" << endl;}
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "lt");   cout << "Expr < Expr" << endl;}
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "neq");  cout << "Expr != Expr" << endl;}
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "and");  cout << "Expr and Expr" << endl;}
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BiExprNode((yyvsp[-2].node), (yyvsp[0].node), "or");   cout << "Expr or Expr" << endl;}
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); cout << "(Expr)" << endl;}
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UniExprNode((yyvsp[0].node),"not"); cout << "not Expr" << endl;}
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new UniExprNode((yyvsp[0].node), "uminus"); cout << "- Expr" << endl;}
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); cout << "MethodCall" << endl;}
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);   cout << "ID" << endl;}
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OneDArray((yyvsp[-3].node), (yyvsp[-1].node)) ;  cout << "1D Access" << endl;}
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TwoDArray((yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node)); cout << "2D Access" << endl;}
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "INTL" << endl; }
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "TRUE" << endl; }
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "FALSE" << endl;}
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "CHAR" << endl; }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); cout << "UINT" << endl; }
#line 1988 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value); cout << "int" << endl;}
#line 1994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value); cout << "uint" << endl;}
#line 2000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value); cout << "bool" << endl;}
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value); cout << "char" << endl;}
#line 2012 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MethodCallNode((yyvsp[-2].node)); }
#line 2018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MethodCallNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2024 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ListExprsNode((yyvsp[0].node)); cout << "ListOfExpr" << endl;}
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.node)->pb((yyvsp[0].node)); cout << "ListOfExpr" << endl;}
#line 2036 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2040 "parser.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 195 "parser.y" /* yacc.c:1906  */


int main(int argc, char **argv)
{
		yyparse();
		cout << "Parsing Over" << endl;
		return (0);
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}
