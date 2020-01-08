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
#line 1 "analysesynt.y" /* yacc.c:339  */


#include "analyse.h"

bool erreursyntx=false;
extern int lineno;
extern bool erreurlex;


#line 76 "analysesynt.tab.c" /* yacc.c:339  */

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
   by #include "analysesynt.tab.h".  */
#ifndef YY_YY_ANALYSESYNT_TAB_H_INCLUDED
# define YY_YY_ANALYSESYNT_TAB_H_INCLUDED
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
    TOK_AFFECTATION = 258,
    TOK_DIFFERENCE = 259,
    TOK_EGALITE = 260,
    TOK_INFERIEUR = 261,
    TOK_SUPERIEUR = 262,
    TOK_INFERIEUREGAL = 263,
    TOK_SUPERIEUREGAL = 264,
    TOK_PLUS = 265,
    TOK_MOINS = 266,
    TOK_FOIS = 267,
    TOK_DIVISION = 268,
    TOK_CONCAT = 269,
    TOK_POINT = 270,
    TOK_PARENTHESED = 271,
    TOK_PARENTHESEG = 272,
    TOK_CHAINECARAC = 273,
    TOK_NOMCLASSE = 274,
    TOK_NOM = 275,
    TOK_NOMBRE = 276,
    TOK_CLASS = 277,
    TOK_EXTENDS = 278,
    TOK_IS = 279,
    TOK_CROCHETG = 280,
    TOK_CROCHETD = 281,
    TOK_DEF = 282,
    TOK_DEUXPOINTS = 283,
    TOK_VIRGULE = 284,
    TOK_VAR = 285,
    TOK_POINTVIRGULE = 286,
    TOK_STATIC = 287,
    TOK_OVERRIDE = 288,
    TOK_THIS = 289,
    TOK_SUPER = 290,
    TOK_RESULT = 291,
    TOK_NEW = 292,
    TOK_RETURN = 293,
    TOK_IF = 294,
    TOK_THEN = 295,
    TOK_ELSE = 296,
    TOK_AS = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "analysesynt.y" /* yacc.c:355  */

	long nombre;
	char* chainecarac;


#line 165 "analysesynt.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALYSESYNT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 182 "analysesynt.tab.c" /* yacc.c:358  */

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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   102,   104,   106,   112,   114,   116,   118,
     120,   122,   124,   126,   128,   130,   133,   135,   137,   139,
     141,   143,   145,   147,   149,   151,   153,   155,   157,   159,
     161,   163,   165,   167,   169,   171,   173,   175,   177,   179,
     181,   183,   185,   187,   189,   191,   193,   195,   197,   199,
     201,   203,   205,   207,   209,   211,   213,   215,   218,   222,
     224,   226,   228,   231,   233,   235,   237,   239,   241,   243,
     245,   247,   249,   251,   253,   255,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   272,
     274,   277,   279,   281,   284,   286,   288,   290
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_AFFECTATION", "TOK_DIFFERENCE",
  "TOK_EGALITE", "TOK_INFERIEUR", "TOK_SUPERIEUR", "TOK_INFERIEUREGAL",
  "TOK_SUPERIEUREGAL", "TOK_PLUS", "TOK_MOINS", "TOK_FOIS", "TOK_DIVISION",
  "TOK_CONCAT", "TOK_POINT", "TOK_PARENTHESED", "TOK_PARENTHESEG",
  "TOK_CHAINECARAC", "TOK_NOMCLASSE", "TOK_NOM", "TOK_NOMBRE", "TOK_CLASS",
  "TOK_EXTENDS", "TOK_IS", "TOK_CROCHETG", "TOK_CROCHETD", "TOK_DEF",
  "TOK_DEUXPOINTS", "TOK_VIRGULE", "TOK_VAR", "TOK_POINTVIRGULE",
  "TOK_STATIC", "TOK_OVERRIDE", "TOK_THIS", "TOK_SUPER", "TOK_RESULT",
  "TOK_NEW", "TOK_RETURN", "TOK_IF", "TOK_THEN", "TOK_ELSE", "TOK_AS",
  "$accept", "axiome", "listclasse", "declclasse", "interieurclasse",
  "declconstructeur", "listparamclass", "paramclass", "declattribut",
  "declmethode", "staticoverideoption", "listparammethod", "parammethod",
  "listargs", "expression", "instruction", "identclass", "identval",
  "selection", "const", "instanciation", "envoimsg", "expwithop", "concat",
  "nonegalite", "egalite", "moinsunaire", "plusunaire", "addition",
  "soustraction", "multiplication", "superieur", "inferieur", "division",
  "superieuregal", "inferieuregal", "bloc", "declarationvar",
  "affectation", "listdeclarationvar", "listinstructions", YY_NULLPTR
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
     295,   296,   297
};
# endif

#define YYPACT_NINF -112

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-112)))

#define YYTABLE_NINF -98

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    34,   186,    82,    64,    28,  -112,  -112,  -112,  -112,
      17,   309,   309,    75,  -112,  -112,  -112,  -112,    34,    70,
     309,   223,   105,  -112,    78,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,    51,  -112,    89,    88,  -112,  -112,
    -112,  -112,    11,   121,  -112,   121,    34,   355,    19,  -112,
      12,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,    51,  -112,  -112,    34,    78,  -112,   105,
    -112,    51,   103,    91,    99,   100,  -112,   309,   105,   235,
     249,   249,    63,    63,    63,    63,   121,   121,   114,   114,
     114,   129,     6,   112,   120,    80,    11,    34,   309,   133,
     343,   109,  -112,   309,   309,  -112,  -112,    34,    34,   127,
    -112,  -112,   369,  -112,   309,   105,   137,   263,  -112,   130,
      61,  -112,  -112,  -112,  -112,  -112,   132,    65,    10,   135,
      61,    61,    61,    61,   122,  -112,    51,   141,    51,   131,
    -112,  -112,  -112,  -112,   136,  -112,   146,    11,   142,    34,
    -112,    51,   149,    34,     8,   158,   147,   150,     5,     9,
     309,  -112,    20,    51,    34,    64,    34,   309,  -112,   275,
      64,    34,  -112,  -112,  -112,   162,   303,  -112,  -112,    25,
     309,  -112,   309,    64,   165,   382,  -112,   159,    64,  -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    95,     0,     0,     7,     4,    55,    53,    54,
       0,     0,     0,     0,    59,    57,    60,    56,     0,     0,
       0,     0,    97,    39,    40,    44,    41,    45,    46,    47,
      67,    66,    65,    68,    69,    70,    71,    72,    63,    64,
      73,    74,    75,    50,    95,    48,     0,     0,     1,     5,
       3,     6,    18,    80,    40,    79,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    96,     0,     0,    94,    97,
      89,     0,     0,    17,     0,     0,    43,    38,     0,     0,
      77,    78,    85,    84,    88,    87,    81,    82,    83,    86,
      76,    58,     0,     0,     0,     0,    18,     0,     0,     0,
      37,     0,    93,    38,     0,    91,    90,     0,     0,     0,
      16,    19,     0,    61,    38,     0,     0,     0,    20,     0,
      13,    42,    36,    52,    62,    92,     0,    31,     0,     0,
      13,    13,    13,    13,    28,    29,     0,     0,     0,     0,
       8,    12,    10,    11,     0,    30,     0,    18,     0,     0,
       9,    34,     0,     0,     0,     0,    33,     0,     0,     0,
       0,    21,     0,    34,     0,     0,     0,     0,    22,     0,
       0,     0,    32,    35,    14,     0,     0,    23,    26,     0,
      38,    24,     0,     0,     0,    25,    27,     0,     0,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,   177,  -112,    26,  -112,  -103,  -112,  -112,  -112,
    -112,    16,  -112,  -111,    -6,   -80,    14,    -1,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,     0,  -112,  -112,   143,
     -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   139,   140,    82,    83,   141,   142,
     146,   165,   166,   109,    21,    22,    23,    54,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    24,   126,   120,    50,    53,    55,    57,   111,   114,
      75,   170,   177,   132,    60,    10,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   192,   175,
      15,    15,    58,   176,    52,     1,    87,   115,     2,   171,
     178,    81,   148,    77,   180,   133,    17,    17,   181,   193,
       1,    84,    88,     7,   162,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   103,     8,     9,
      85,    15,   101,    68,    69,    70,    71,    72,    73,   194,
     104,   110,    48,    49,     7,    11,    12,    17,   137,     2,
     102,   138,    13,    14,     7,    15,    16,   144,   145,     8,
       9,    59,   122,   118,   119,    84,    76,   110,   127,     8,
       9,    17,    18,    79,    80,    11,    12,    56,   110,   105,
     106,   121,    13,    14,     7,    15,    16,   107,   108,    73,
       2,   128,   129,    70,    71,    72,    73,   149,   116,     8,
       9,    17,    18,    19,    20,   156,   113,   158,   117,   123,
     125,   147,   130,   134,   136,   155,    84,   143,   157,   159,
     167,   150,   160,   161,   179,   168,   151,   152,   153,   154,
     163,   186,   167,   164,   172,   184,   173,   169,   174,   190,
     188,   197,    51,   198,   110,     0,   195,    78,   183,   182,
     185,     0,     0,   196,     0,   189,    11,    12,   199,     0,
       0,     0,     0,    13,    14,     7,    15,    16,     0,     0,
       0,     2,   -97,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    17,    18,    19,    20,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,    74,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,   112,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    11,
      12,     0,     0,     0,     0,     0,    13,    14,     7,    15,
      16,     0,     0,     0,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    17,    18,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    86,   124,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,   131,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
       0,     2,   113,   106,     4,    11,    12,    13,    88,     3,
      22,     3,     3,   124,    20,     1,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     3,    24,
      20,    20,    18,    28,    17,    22,    17,    31,    25,    31,
      31,    30,    32,    44,    24,   125,    36,    36,    28,    24,
      22,    52,    40,    19,   157,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    79,    34,    35,
      56,    20,    73,    10,    11,    12,    13,    14,    15,   190,
      81,    87,     0,     1,    19,    10,    11,    36,    27,    25,
      76,    30,    17,    18,    19,    20,    21,    32,    33,    34,
      35,    31,   108,    23,    24,   106,    28,   113,   114,    34,
      35,    36,    37,    24,    26,    10,    11,    42,   124,    16,
      29,   107,    17,    18,    19,    20,    21,    28,    28,    15,
      25,   117,   118,    12,    13,    14,    15,   138,    26,    34,
      35,    36,    37,    38,    39,   146,    17,   148,    28,    16,
      41,   137,    25,    16,    24,    33,   157,    25,    17,    28,
     161,    26,    26,    17,   170,    16,   140,   141,   142,   143,
      28,   177,   173,   159,    16,   175,    29,   163,    28,    17,
     180,    16,     5,    24,   190,    -1,   192,    44,   174,   173,
     176,    -1,    -1,   193,    -1,   181,    10,    11,   198,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    31,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    31,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    10,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    29,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    25,    44,    45,    46,    79,    19,    34,    35,
      59,    10,    11,    17,    18,    20,    21,    36,    37,    38,
      39,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     1,
      79,    45,    17,    57,    60,    57,    42,    57,    59,    31,
      57,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    31,    83,    28,    60,    82,    24,
      26,    30,    49,    50,    60,    59,    16,    17,    40,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    60,    59,    83,    60,    16,    29,    28,    28,    56,
      57,    58,    31,    17,     3,    31,    26,    28,    23,    24,
      49,    59,    57,    16,    29,    41,    56,    57,    59,    59,
      25,    16,    56,    58,    16,    31,    24,    27,    30,    47,
      48,    51,    52,    25,    32,    33,    53,    59,    32,    60,
      26,    47,    47,    47,    47,    33,    60,    17,    60,    28,
      26,    17,    49,    28,    59,    54,    55,    60,    16,    59,
       3,    31,    16,    29,    28,    24,    28,     3,    31,    57,
      24,    28,    54,    59,    79,    59,    57,    31,    79,    59,
      17,    31,     3,    24,    56,    57,    79,    16,    24,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    48,    48,    49,    49,    49,    50,
      50,    51,    51,    51,    51,    52,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    55,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    59,    59,    59,    60,    60,    61,    62,
      62,    63,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      79,    80,    80,    81,    82,    82,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     9,    11,
       2,     2,     2,     0,     7,    12,     3,     1,     0,     3,
       4,     5,     6,     7,     8,    10,     8,    10,     1,     1,
       2,     0,     3,     1,     0,     3,     3,     1,     0,     1,
       1,     1,     6,     3,     1,     1,     1,     1,     1,     2,
       1,     2,     6,     1,     1,     1,     1,     1,     3,     1,
       1,     5,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     6,     4,     2,     0,     2,     0
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
#line 100 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1441 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "analysesynt.y" /* yacc.c:1646  */
    {printf("Classe et bloc\n\n");}
#line 1447 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 104 "analysesynt.y" /* yacc.c:1646  */
    {printf("Bloc\n\n");}
#line 1453 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 106 "analysesynt.y" /* yacc.c:1646  */
    {
			erreursyntx=true;
                        fprintf(stderr,"\tERREUR : Erreur de syntaxe a la ligne %d.\n",lineno);
                       
		}
#line 1463 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 112 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1469 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1475 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 118 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1481 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 120 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1487 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 122 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1493 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1499 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 126 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1505 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1511 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1517 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 133 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1523 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 135 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1529 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 137 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1535 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 139 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1541 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 141 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1547 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 143 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1553 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 145 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1559 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 147 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1565 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 149 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1571 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1577 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 153 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1583 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 155 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1589 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 157 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1595 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 159 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1601 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 161 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1607 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 163 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1613 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 165 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1619 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 167 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1625 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 169 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1631 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 171 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1637 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 173 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1643 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 175 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1649 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 177 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1655 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 179 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1661 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1667 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 183 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1673 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 185 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1679 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 187 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1685 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 189 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1691 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 191 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1697 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 193 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1703 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 195 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1709 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 197 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1715 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 199 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1721 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 201 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1727 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 203 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1733 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 205 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1739 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 207 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1745 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 209 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1751 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 211 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1757 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 213 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1763 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 215 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1769 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 218 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1775 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 222 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1781 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 224 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1787 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 226 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1793 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 228 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1799 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 231 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1805 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 233 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1811 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 235 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1817 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 237 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1823 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 239 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1829 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 241 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1835 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 243 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1841 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 245 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1847 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 247 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1853 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 249 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1859 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 251 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1865 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 253 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1871 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 255 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1877 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 257 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1883 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 258 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1889 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 259 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1895 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 260 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1901 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 261 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1907 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 262 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1913 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 263 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1919 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 264 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1925 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 265 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1931 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 266 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1937 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 267 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1943 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 268 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1949 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 269 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1955 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 272 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1961 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 274 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1967 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 277 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1973 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 279 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1979 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 281 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1985 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 284 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1991 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 286 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 1997 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 288 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 2003 "analysesynt.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 290 "analysesynt.y" /* yacc.c:1646  */
    {}
#line 2009 "analysesynt.tab.c" /* yacc.c:1646  */
    break;


#line 2013 "analysesynt.tab.c" /* yacc.c:1646  */
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
#line 292 "analysesynt.y" /* yacc.c:1906  */


int main(void){
 
        printf("Debut de l'analyse syntaxique :\n");
        yyparse();
        printf("Fin de l'analyse !\n");
        printf("Resultat :\n");
        if(erreurlex){
                printf("\t-- Echec : Certains lexemes ne font pas partie du lexique du langage ! --\n");
                printf("\t-- Echec a l'analyse lexicale --\n");
        }
        else{
                printf("\t-- Succes a l'analyse lexicale ! --\n");
        }
        if(erreursyntx){
                printf("\t-- Echec : Certaines phrases sont syntaxiquement incorrectes ! --\n");
                printf("\t-- Echec a l'analyse syntaxique --\n");
        }
        else{
                printf("\t-- Succes a l'analyse syntaxique ! --\n");
		bool error_semantical=true;
                if(error_semantical){
                        printf("\t-- Echec : Certaines phrases sont semantiquement incorrectes ! --\n");
                        printf("\t-- Echec a l'analyse semantique --\n");
                }
                else{
                        printf("\t-- Succes a l'analyse semantique ! --\n");
                }
        }

        return EXIT_SUCCESS;
}
void yyerror(char *s) {
	erreursyntx=true;
        fprintf(stderr, "Erreur de syntaxe a la ligne %d: %s\n", lineno, s);
}
		


			















	






