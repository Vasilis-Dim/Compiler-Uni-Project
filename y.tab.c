
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "gram.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "sym_tab.h"
#include "gener.h"
#include "err_code.h"


extern void printerr(errconbr errmess);

extern void savefunc(funcdef func);
extern char *GetYYText(void);
extern char *yytext;
extern int line;

extern int yyylex();
extern int yyparse();
extern int yylineno;
extern void yyerror(char*);

symbol_table proc_st;

#define YYERROR_VERBOSE

#define YYPRINT(file, type, value)   yyprint (file, type, &value);


#define SYMTABSIZE 		100
#define IDLENGTH		15 
#define NOTHING			-1
#define INDENTOFFSET	2


#ifdef DEBUG
char *NodeName[] =
{
"N_PROGRAM", "N_IDENTIFIER", "N_BLOCK", "N_DECLARATIONS", "N_DECLOOP", "N_VARLIST", "N_VARLOOP",
"N_SUBPROGRAMS", "N_SUBLOOP", "N_FUNC", "N_FUNCBODY", "N_FORMALPARS", "N_FORMALPARLIST", "N_FORMALPARLIST_LOOP", "N_FORMALPARITEM", "N_BRACK_OR_STAT", 
"N_BRACKETS_SEQ", "N_SEQUENCE", "N_SEQLOOP", "N_STATEMENT", "N_ASSIGNMENT_STAT", "N_IF_STAT", "N_ELSEPART", "N_WHILE_STAT",  "N_DOUBLE_WHILE_STAT",
"N_LOOP_STAT", "N_FORCASE_STAT", "N_INCASE_STAT", "N_WHEN_LOOP", "N_WHEN_STAT", "N_EXIT_STAT", "N_RETURN_STAT", "N_PRINT_STAT", "N_INPUT_STAT", "N_CALL_STAT",
"N_ACTUALPARS", "N_ACTUALPARLIST", "N_ACTLOOP", "N_ACTUALPARITEM", "N_CONDITION", "N_BOOLTLOOP", "N_BOOLTERM", "N_BOOLFLOOP", "N_BOOLFACTOR", "N_EXPRESSION",
"N_ADDOPERTERMLOOP", "N_TERM", "N_MULOPERTERMLOOP", "N_FACTOR", "N_IDTAIL", "N_RELATIONAL_OPER", "N_ADD_OPER", "N_MUL_OPER", "N_OPTIONAL_SIGN", "N_PRIMARY"
};
#endif


enum ParseTreeNodeType { N_PROGRAM, N_IDENTIFIER, N_BLOCK, N_DECLARATIONS, N_DECLOOP, N_VARLIST, N_VARLOOP,
N_SUBPROGRAMS, N_SUBLOOP, N_FUNC, N_FUNCBODY, N_FORMALPARS, N_FORMALPARLIST, N_FORMALPARLIST_LOOP, N_FORMALPARITEM, N_BRACK_OR_STAT, 
N_BRACKETS_SEQ, N_SEQUENCE, N_SEQLOOP, N_STATEMENT, N_ASSIGNMENT_STAT, N_IF_STAT, N_ELSEPART, N_WHILE_STAT,  N_DOUBLE_WHILE_STAT,
N_LOOP_STAT, N_FORCASE_STAT, N_INCASE_STAT, N_WHEN_LOOP, N_WHEN_STAT, N_EXIT_STAT, N_RETURN_STAT, N_PRINT_STAT, N_INPUT_STAT, N_CALL_STAT,
N_ACTUALPARS, N_ACTUALPARLIST, N_ACTLOOP, N_ACTUALPARITEM, N_CONDITION, N_BOOLTLOOP, N_BOOLTERM, N_BOOLFLOOP, N_BOOLFACTOR, N_EXPRESSION,
N_ADDOPERTERMLOOP, N_TERM, N_MULOPERTERMLOOP, N_FACTOR, N_IDTAIL, N_RELATIONAL_OPER, N_ADD_OPER, N_MUL_OPER, N_OPTIONAL_SIGN,N_PRIMARY
};

	
struct treeNode {
	union {
    int item;
    char *stem;
   	};

	int nodeIdentifier;
	struct treeNode *first;
	struct treeNode *second;
	struct treeNode *third;
};	
	
void PrintTree(struct treeNode*);

	
	
struct symTabNode {
	int id;
	int blockNumber;
	char identifier[IDLENGTH];
} ;



typedef struct treeNode TREE_NODE;
typedef TREE_NODE *TERNARY_TREE;


typedef struct  symTabNode  SYMTABNODE;
typedef SYMTABNODE    *SYMTABNODEPTR;


SYMTABNODEPTR symTab[SYMTABSIZE];
int currentSymTabSize = 0;

TERNARY_TREE int_node(int, int, TERNARY_TREE, TERNARY_TREE, TERNARY_TREE);
TERNARY_TREE string_node(char *, int, TERNARY_TREE, TERNARY_TREE, TERNARY_TREE);


#ifdef DEBUG
void PrintTree(TERNARY_TREE);
#endif




/* Line 189 of yacc.c  */
#line 177 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CALL = 258,
     ASSIGN = 259,
     NOT = 260,
     AND = 261,
     OR = 262,
     STRING_LITERAL = 263,
     PLUS = 264,
     MINUS = 265,
     STAR = 266,
     DIV = 267,
     IN = 268,
     INOUT = 269,
     INPUT = 270,
     PRINT = 271,
     SEMICOLON = 272,
     COMMA = 273,
     COLON = 274,
     PROGRAM = 275,
     DECLARE = 276,
     DEFAULT = 277,
     FUNCTION = 278,
     PROCEDURE = 279,
     L_THAN = 280,
     G_THAN = 281,
     EQUAL = 282,
     L_EQ_THAN = 283,
     G_EQ_THAN = 284,
     NEQUAL = 285,
     LPAREN = 286,
     RPAREN = 287,
     LSQUARE_BRACK = 288,
     RSQUARE_BRACK = 289,
     LBRACK = 290,
     RBRACK = 291,
     ELSE = 292,
     IF = 293,
     RETURN = 294,
     WHILE = 295,
     DOUBLEWHILE = 296,
     LOOP = 297,
     FORCASE = 298,
     INCASE = 299,
     WHEN = 300,
     EXIT = 301,
     DEC_CONST = 302,
     IDENTIFIER = 303
   };
#endif
/* Tokens.  */
#define CALL 258
#define ASSIGN 259
#define NOT 260
#define AND 261
#define OR 262
#define STRING_LITERAL 263
#define PLUS 264
#define MINUS 265
#define STAR 266
#define DIV 267
#define IN 268
#define INOUT 269
#define INPUT 270
#define PRINT 271
#define SEMICOLON 272
#define COMMA 273
#define COLON 274
#define PROGRAM 275
#define DECLARE 276
#define DEFAULT 277
#define FUNCTION 278
#define PROCEDURE 279
#define L_THAN 280
#define G_THAN 281
#define EQUAL 282
#define L_EQ_THAN 283
#define G_EQ_THAN 284
#define NEQUAL 285
#define LPAREN 286
#define RPAREN 287
#define LSQUARE_BRACK 288
#define RSQUARE_BRACK 289
#define LBRACK 290
#define RBRACK 291
#define ELSE 292
#define IF 293
#define RETURN 294
#define WHILE 295
#define DOUBLEWHILE 296
#define LOOP 297
#define FORCASE 298
#define INCASE 299
#define WHEN 300
#define EXIT 301
#define DEC_CONST 302
#define IDENTIFIER 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 105 "gram.y"

	char *name;
	char *cVal;
	int iVal;
	struct treeNode *tVal;
	express expr;
    funcdef funcentr;
	int op;



/* Line 214 of yacc.c  */
#line 321 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 333 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    15,    17,    19,    24,    27,
      28,    31,    35,    36,    38,    41,    42,    43,    48,    49,
      54,    57,    60,    64,    67,    71,    72,    75,    78,    80,
      82,    86,    89,    93,    94,    96,    98,   100,   102,   104,
     106,   108,   110,   112,   114,   116,   118,   119,   123,   130,
     133,   134,   140,   148,   151,   157,   160,   163,   164,   172,
     174,   179,   184,   189,   193,   196,   200,   203,   207,   208,
     211,   214,   217,   221,   222,   225,   229,   230,   235,   239,
     243,   247,   251,   252,   255,   259,   260,   262,   266,   269,
     271,   272,   274,   276,   278,   280,   282,   284,   286,   288,
     290,   292,   294
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    20,    51,    52,    -1,    48,    -1,    53,
      55,    59,    71,    54,    -1,    35,    -1,    36,    -1,    21,
      57,    17,    56,    -1,    55,    56,    -1,    -1,    51,    58,
      -1,    18,    51,    58,    -1,    -1,    60,    -1,    61,    60,
      -1,    -1,    -1,    24,    51,    64,    62,    -1,    -1,    23,
      51,    64,    63,    -1,    65,    52,    -1,    31,    32,    -1,
      31,    66,    32,    -1,    68,    67,    -1,    18,    68,    67,
      -1,    -1,    13,    51,    -1,    14,    51,    -1,    70,    -1,
      73,    -1,    35,    71,    36,    -1,    73,    72,    -1,    17,
      73,    72,    -1,    -1,    74,    -1,    75,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    -1,    51,
       4,    98,    -1,    38,    31,    93,    32,    69,    76,    -1,
      37,    69,    -1,    -1,    40,    31,    93,    32,    69,    -1,
      41,    31,    93,    32,    69,    37,    69,    -1,    42,    69,
      -1,    43,    82,    22,    19,    69,    -1,    44,    82,    -1,
      83,    82,    -1,    -1,    45,    19,    31,    93,    32,    19,
      69,    -1,    46,    -1,    39,    31,    98,    32,    -1,    16,
      31,    98,    32,    -1,    15,    31,    51,    32,    -1,     3,
      51,    89,    -1,    31,    32,    -1,    31,    90,    32,    -1,
      92,    91,    -1,    18,    92,    91,    -1,    -1,    13,    98,
      -1,    14,    51,    -1,    95,    94,    -1,     7,    95,    94,
      -1,    -1,    97,    96,    -1,     6,    97,    96,    -1,    -1,
       5,    33,    93,    34,    -1,    33,    93,    34,    -1,    98,
     104,    98,    -1,   107,   100,    99,    -1,   105,   100,    99,
      -1,    -1,   102,   101,    -1,   106,   102,   101,    -1,    -1,
      47,    -1,    31,    98,    32,    -1,    51,   103,    -1,    89,
      -1,    -1,    27,    -1,    25,    -1,    28,    -1,    30,    -1,
      29,    -1,    26,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,   105,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   160,   186,   193,   199,   204,   211,   216,
     222,   229,   234,   240,   247,   252,   259,   258,   266,   265,
     275,   282,   286,   293,   300,   305,   311,   315,   322,   326,
     333,   340,   347,   352,   358,   362,   366,   370,   374,   378,
     382,   386,   390,   394,   398,   402,   407,   413,   420,   427,
     432,   438,   445,   452,   459,   466,   473,   478,   484,   491,
     498,   505,   512,   519,   526,   530,   537,   544,   549,   555,
     559,   566,   573,   578,   584,   591,   596,   602,   606,   610,
     617,   624,   629,   635,   642,   647,   653,   657,   661,   668,
     673,   679,   683,   687,   691,   695,   699,   706,   710,   717,
     721,   728,   733
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CALL", "ASSIGN", "NOT", "AND", "OR",
  "STRING_LITERAL", "PLUS", "MINUS", "STAR", "DIV", "IN", "INOUT", "INPUT",
  "PRINT", "SEMICOLON", "COMMA", "COLON", "PROGRAM", "DECLARE", "DEFAULT",
  "FUNCTION", "PROCEDURE", "L_THAN", "G_THAN", "EQUAL", "L_EQ_THAN",
  "G_EQ_THAN", "NEQUAL", "LPAREN", "RPAREN", "LSQUARE_BRACK",
  "RSQUARE_BRACK", "LBRACK", "RBRACK", "ELSE", "IF", "RETURN", "WHILE",
  "DOUBLEWHILE", "LOOP", "FORCASE", "INCASE", "WHEN", "EXIT", "DEC_CONST",
  "IDENTIFIER", "$accept", "program", "identifier", "block", "begin_bl",
  "end_bl", "declarations", "decloop", "varlist", "varloop", "subprograms",
  "subloop", "func", "$@1", "$@2", "funcbody", "formalpars",
  "formalparlist", "formalparlist_loop", "formalparitem", "brack_or_stat",
  "brackets_seq", "sequence", "seqloop", "statement", "assignment_stat",
  "if_stat", "elsepart", "while_stat", "double_while_stat", "loop_stat",
  "forcase_stat", "incase_stat", "when_loop", "when_stat", "exit_stat",
  "return_stat", "print_stat", "input_stat", "call_stat", "actualpars",
  "actualparlist", "actloop", "actualparitem", "condition", "booltloop",
  "boolterm", "boolfloop", "boolfactor", "expression", "addopertermloop",
  "term", "mulopertermloop", "factor", "idtail", "relational_oper",
  "add_oper", "mul_oper", "optional_sign", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    53,    54,    55,    56,    56,
      57,    58,    58,    59,    60,    60,    62,    61,    63,    61,
      64,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      70,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    76,
      76,    77,    78,    79,    80,    81,    82,    82,    83,    84,
      85,    86,    87,    88,    89,    89,    90,    91,    91,    92,
      92,    93,    94,    94,    95,    96,    96,    97,    97,    97,
      98,    99,    99,   100,   101,   101,   102,   102,   102,   103,
     103,   104,   104,   104,   104,   104,   104,   105,   105,   106,
     106,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     5,     1,     1,     4,     2,     0,
       2,     3,     0,     1,     2,     0,     0,     4,     0,     4,
       2,     2,     3,     2,     3,     0,     2,     2,     1,     1,
       3,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     6,     2,
       0,     5,     7,     2,     5,     2,     2,     0,     7,     1,
       4,     4,     4,     3,     2,     3,     2,     3,     0,     2,
       2,     2,     3,     0,     2,     3,     0,     4,     3,     3,
       3,     3,     0,     2,     3,     0,     1,     3,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     5,     2,     0,     0,
      15,    12,     0,     0,     0,    46,    13,    15,     0,    10,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    57,    57,    59,     0,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    14,
      12,     9,     7,     0,    18,     0,    16,     0,     0,   102,
     102,   102,   102,   102,    46,    53,    28,    29,     0,     0,
      57,    55,   102,     6,     4,    46,    31,    11,     8,     0,
       0,    21,     0,    25,    19,    20,    17,     0,    63,     0,
      97,    98,     0,   101,     0,     0,   102,     0,    73,    76,
       0,     0,     0,     0,     0,     0,     0,    56,    47,    33,
      26,    27,    22,     0,    23,   102,     0,    64,     0,    68,
      62,    61,   102,    86,    90,    82,    85,   102,     0,    46,
     102,    71,   102,    74,    92,    96,    91,    93,    95,    94,
     102,    60,    46,    46,    30,   102,    46,    32,    25,    69,
      70,    65,     0,    66,     0,    89,    88,    80,     0,    99,
     100,    83,     0,     0,    78,    50,    73,    76,    79,    51,
       0,     0,    54,    24,    68,    87,    82,    85,    77,    46,
      48,    72,    75,    46,     0,    67,    81,    84,    49,    52,
      46,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    34,     7,     8,    74,    51,    52,    12,    19,
      15,    16,    17,    86,    84,    54,    55,    82,   114,    83,
      65,    66,    35,    76,    67,    37,    38,   180,    39,    40,
      41,    42,    43,    69,    70,    44,    45,    46,    47,    48,
      88,   118,   153,   119,    97,   131,    98,   133,    99,   100,
     157,   125,   161,   126,   156,   140,    93,   162,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -124
static const yytype_int8 yypact[] =
{
      -9,   -27,    28,  -124,    -4,  -124,  -124,  -124,    23,   -27,
       6,    16,    29,   -27,   -27,    98,  -124,     6,   -27,  -124,
      23,    19,    19,   -27,    20,    22,    31,    33,    34,    38,
      56,     9,     9,  -124,    54,    37,    53,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
      16,    23,  -124,    11,  -124,    -4,  -124,    43,   -27,    27,
       5,    27,     5,     5,    98,  -124,  -124,  -124,    57,    55,
       9,  -124,    27,  -124,  -124,    98,  -124,  -124,  -124,   -27,
     -27,  -124,    48,    63,  -124,  -124,  -124,    13,  -124,    50,
    -124,  -124,    51,  -124,   -15,    42,     5,    58,    78,    81,
      80,    60,    71,    79,    52,    85,    70,  -124,  -124,    53,
    -124,  -124,  -124,    26,  -124,    27,   -27,  -124,    86,    94,
    -124,  -124,    27,  -124,    43,    27,    30,     5,    83,    56,
       5,  -124,     5,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
      27,  -124,    56,    56,  -124,     5,    56,  -124,    63,  -124,
    -124,  -124,    35,  -124,    87,  -124,  -124,  -124,   -15,  -124,
    -124,  -124,   -15,    88,  -124,    84,    78,    81,  -124,  -124,
      89,    91,  -124,  -124,    94,  -124,    27,    30,  -124,    56,
    -124,  -124,  -124,    56,   101,  -124,  -124,  -124,  -124,  -124,
      56,  -124
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -124,  -124,    -1,    69,  -124,  -124,   117,    76,  -124,    82,
    -124,   111,  -124,  -124,  -124,   107,  -124,  -124,   -18,    18,
    -123,  -124,    90,    24,   -12,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,   -23,  -124,  -124,  -124,  -124,  -124,  -124,
      10,  -124,   -39,    -7,   -61,   -19,    21,   -24,    17,   -54,
     -28,    -8,   -25,    -6,  -124,  -124,  -121,  -124,  -124
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       4,   102,   103,    36,   158,    92,   165,   101,    11,    71,
      95,     1,    21,    22,    90,    91,   122,    50,   108,   169,
     170,     3,    57,   172,    79,    80,   115,   116,     5,    13,
      14,     6,   123,     3,    18,   128,    90,    91,    96,    79,
      80,   159,   160,    81,     9,   117,    20,   107,   115,   116,
      53,    58,    36,    59,    68,   158,   188,    89,    72,    23,
     189,   149,    60,   109,    61,    62,   163,   191,   154,    63,
      75,    24,    25,    73,    87,   127,   105,   106,   110,   111,
     112,   113,   120,   121,   171,   130,   168,   132,   144,   146,
     129,    64,   141,   124,    26,    27,    28,    29,    30,    31,
      32,    23,    33,   142,     3,   134,   135,   136,   137,   138,
     139,   143,   152,    24,    25,   150,   145,   164,   151,   175,
     190,   179,   178,   184,    85,    10,   183,    78,    49,    56,
     173,   148,    77,   147,   155,   185,    26,    27,    28,    29,
      30,    31,    32,   182,    33,   174,     3,   181,   186,   167,
     176,   166,   187,     0,   104,     0,   177,   124,     0,     0,
       0,   124
};

static const yytype_int16 yycheck[] =
{
       1,    62,    63,    15,   125,    59,   129,    61,     9,    32,
       5,    20,    13,    14,     9,    10,    31,    18,    72,   142,
     143,    48,    23,   146,    13,    14,    13,    14,     0,    23,
      24,    35,    47,    48,    18,    96,     9,    10,    33,    13,
      14,    11,    12,    32,    21,    32,    17,    70,    13,    14,
      31,    31,    64,    31,    45,   176,   179,    58,     4,     3,
     183,   115,    31,    75,    31,    31,   127,   190,   122,    31,
      17,    15,    16,    36,    31,    33,    19,    22,    79,    80,
      32,    18,    32,    32,   145,     7,   140,     6,    36,    19,
      32,    35,    32,    94,    38,    39,    40,    41,    42,    43,
      44,     3,    46,    32,    48,    25,    26,    27,    28,    29,
      30,    32,    18,    15,    16,   116,    31,    34,    32,    32,
      19,    37,    34,    32,    55,     8,    37,    51,    17,    22,
     148,   113,    50,   109,   124,   174,    38,    39,    40,    41,
      42,    43,    44,   167,    46,   152,    48,   166,   176,   132,
     158,   130,   177,    -1,    64,    -1,   162,   158,    -1,    -1,
      -1,   162
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    50,    48,    51,     0,    35,    52,    53,    21,
      55,    51,    57,    23,    24,    59,    60,    61,    18,    58,
      17,    51,    51,     3,    15,    16,    38,    39,    40,    41,
      42,    43,    44,    46,    51,    71,    73,    74,    75,    77,
      78,    79,    80,    81,    84,    85,    86,    87,    88,    60,
      51,    55,    56,    31,    64,    65,    64,    51,    31,    31,
      31,    31,    31,    31,    35,    69,    70,    73,    45,    82,
      83,    82,     4,    36,    54,    17,    72,    58,    56,    13,
      14,    32,    66,    68,    63,    52,    62,    31,    89,    51,
       9,    10,    98,   105,   107,     5,    33,    93,    95,    97,
      98,    98,    93,    93,    71,    19,    22,    82,    98,    73,
      51,    51,    32,    18,    67,    13,    14,    32,    90,    92,
      32,    32,    31,    47,    51,   100,   102,    33,    93,    32,
       7,    94,     6,    96,    25,    26,    27,    28,    29,    30,
     104,    32,    32,    32,    36,    31,    19,    72,    68,    98,
      51,    32,    18,    91,    98,    89,   103,    99,   105,    11,
      12,   101,   106,    93,    34,    69,    95,    97,    98,    69,
      69,    93,    69,    67,    92,    32,   100,   102,    34,    37,
      76,    94,    96,    37,    32,    91,    99,   101,    69,    69,
      19,    69
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 153 "gram.y"
    {
			TERNARY_TREE ParseTree;
		    ParseTree = int_node((yyvsp[(2) - (3)].tVal),N_PROGRAM,(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
		}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 161 "gram.y"
    {
				(yyval.tVal)=GetYYText();
				(yyval.tVal) = string_node((yyvsp[(1) - (1)].cVal),N_IDENTIFIER,NULL,NULL,NULL);
			}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 187 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BLOCK,(yyvsp[(2) - (5)].tVal),(yyvsp[(3) - (5)].tVal),(yyvsp[(4) - (5)].tVal));
		}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 205 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_DECLARATIONS,(yyvsp[(2) - (4)].tVal),(yyvsp[(4) - (4)].tVal),NULL);	
		}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 212 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_DECLOOP,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);
		}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 216 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_DECLOOP,NULL,NULL,NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 223 "gram.y"
    {
			(yyval.tVal) = string_node((yyvsp[(1) - (2)].tVal),N_VARLIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);	
		}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 230 "gram.y"
    {
			(yyval.tVal) = string_node((yyvsp[(2) - (3)].tVal),N_VARLOOP,(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);	
		}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 234 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_VARLOOP,NULL,NULL,NULL);
		}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 241 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_SUBPROGRAMS,(yyvsp[(1) - (1)].tVal),NULL,NULL);	
		}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 248 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_SUBLOOP,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);	
		}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 252 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_SUBLOOP,NULL,NULL,NULL);
		}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 259 "gram.y"
    {
			savefunc((yyvsp[(3) - (3)].tVal));
		}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 262 "gram.y"
    {
			(yyval.tVal) = string_node((yyvsp[(2) - (4)].tVal),N_FUNC,(yyvsp[(2) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL);
		}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 266 "gram.y"
    {	
			savefunc((yyvsp[(3) - (3)].tVal));
		}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 269 "gram.y"
    {
			(yyval.tVal) = string_node((yyvsp[(2) - (4)].tVal),N_FUNC,(yyvsp[(2) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL);	
		}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 276 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_FUNCBODY,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);	
		}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 283 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_FORMALPARS,NULL,NULL,NULL);	
		}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 287 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_FORMALPARS,(yyvsp[(2) - (3)].tVal),NULL,NULL);	
		}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 294 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_FORMALPARLIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);
		}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 301 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_FORMALPARLIST_LOOP,(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);	
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 305 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_FORMALPARLIST_LOOP,NULL,NULL,NULL);
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 312 "gram.y"
    {
			(yyval.tVal) = string_node((yyvsp[(2) - (2)].tVal),N_FORMALPARITEM,(yyvsp[(2) - (2)].tVal),NULL,NULL);
		}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 316 "gram.y"
    {
			(yyval.tVal) = string_node((yyvsp[(2) - (2)].tVal),N_FORMALPARITEM,(yyvsp[(2) - (2)].tVal),NULL,NULL);	
		}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 323 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BRACK_OR_STAT,(yyvsp[(1) - (1)].tVal),NULL,NULL);	
		}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 327 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BRACK_OR_STAT,(yyvsp[(1) - (1)].tVal),NULL,NULL);	
		}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 334 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BRACKETS_SEQ,(yyvsp[(2) - (3)].tVal),NULL,NULL);	
		}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 341 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_SEQUENCE,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);	
		}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 348 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_SEQLOOP,(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);	
		}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 352 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_SEQLOOP,NULL,NULL,NULL);	
		}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 359 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 363 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 367 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 371 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 375 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 379 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 383 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 387 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 391 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);	
		}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 395 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);	
		}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 399 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);	
		}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 403 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);	
		}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 407 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_STATEMENT,NULL,NULL,NULL);
		}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 414 "gram.y"
    {
			(yyval.tVal) = string_node((yyvsp[(1) - (3)].tVal),N_ASSIGNMENT_STAT,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);	
		}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 421 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_IF_STAT,(yyvsp[(3) - (6)].tVal),(yyvsp[(5) - (6)].tVal),(yyvsp[(6) - (6)].tVal));	
		}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 428 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ELSEPART,(yyvsp[(2) - (2)].tVal),NULL,NULL);	
		}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 432 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ELSEPART,NULL,NULL,NULL);
		}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 439 "gram.y"
    {	
			(yyval.tVal) = int_node(NOTHING,N_WHILE_STAT,(yyvsp[(3) - (5)].tVal),(yyvsp[(5) - (5)].tVal),NULL);	
		}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 446 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_DOUBLE_WHILE_STAT,(yyvsp[(3) - (7)].tVal),(yyvsp[(5) - (7)].tVal),(yyvsp[(7) - (7)].tVal));	
		}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 453 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_LOOP_STAT,(yyvsp[(2) - (2)].tVal),NULL,NULL);	
		}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 460 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_FORCASE_STAT,(yyvsp[(2) - (5)].tVal),(yyvsp[(5) - (5)].tVal),NULL);	
		}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 467 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_INCASE_STAT,(yyvsp[(2) - (2)].tVal),NULL,NULL);	
		}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 474 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_WHEN_LOOP,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);	
		}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 478 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_WHEN_LOOP,NULL,NULL,NULL);	
		}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 485 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_WHEN_STAT,(yyvsp[(4) - (7)].tVal),(yyvsp[(7) - (7)].tVal),NULL);	
		}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 492 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_EXIT_STAT,NULL,NULL,NULL);	
		}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 499 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_RETURN_STAT,(yyvsp[(3) - (4)].tVal),NULL,NULL); 
		}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 506 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_PRINT_STAT,(yyvsp[(3) - (4)].tVal),NULL,NULL); 
		}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 513 "gram.y"
    {
			(yyval.tVal) = string_node((yyvsp[(3) - (4)].tVal),N_INPUT_STAT,(yyvsp[(3) - (4)].tVal),NULL,NULL); 
		}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 520 "gram.y"
    {
			(yyval.tVal) = string_node((yyvsp[(2) - (3)].tVal),N_CALL_STAT,(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL); 
		}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 527 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ACTUALPARS,NULL,NULL,NULL);
		}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 531 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ACTUALPARS,(yyvsp[(2) - (3)].tVal),NULL,NULL);	
		}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 538 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ACTUALPARLIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);	
		}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 545 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ACTLOOP,(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
		}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 549 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ACTLOOP,NULL,NULL,NULL);
		}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 556 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ACTUALPARITEM,(yyvsp[(2) - (2)].tVal),NULL,NULL);
		}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 560 "gram.y"
    {
			(yyval.tVal) = int_node((yyvsp[(2) - (2)].tVal),N_ACTUALPARITEM,(yyvsp[(2) - (2)].tVal),NULL,NULL);
		}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 567 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_CONDITION,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);	 
		}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 574 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BOOLTLOOP,(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);	
		}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 578 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BOOLTLOOP,NULL,NULL,NULL);	
		}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 585 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BOOLTERM,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);	
		}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 592 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BOOLFLOOP,(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);  
		}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 596 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BOOLFLOOP,NULL,NULL,NULL);
		}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 603 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BOOLFACTOR,(yyvsp[(3) - (4)].tVal),NULL,NULL);
		}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 607 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BOOLFACTOR,(yyvsp[(2) - (3)].tVal),NULL,NULL);
		}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 611 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_BOOLFACTOR,(yyvsp[(1) - (3)].tVal),(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal)); 
		}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 618 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal));
		}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 625 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ADDOPERTERMLOOP,(yyvsp[(1) - (3)].tVal),(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal));
		}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 629 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_ADDOPERTERMLOOP,NULL,NULL,NULL);
		}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 636 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_TERM,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);
		}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 643 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_MULOPERTERMLOOP,(yyvsp[(1) - (3)].tVal),(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal));
			}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 647 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_MULOPERTERMLOOP,NULL,NULL,NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 654 "gram.y"
    {
			(yyval.tVal) = int_node((yyvsp[(1) - (1)].iVal),N_FACTOR,NULL,NULL,NULL );
		}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 658 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_FACTOR,(yyvsp[(2) - (3)].tVal),NULL,NULL);
		}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 662 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_FACTOR,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL);
		}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 669 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_IDTAIL,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 673 "gram.y"
    {
			(yyval.tVal) = int_node(NOTHING,N_IDTAIL,NULL,NULL,NULL);
		}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 680 "gram.y"
    {
				(yyval.tVal) = string_node("==",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 684 "gram.y"
    {
				(yyval.tVal) = string_node("<",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 688 "gram.y"
    {
				(yyval.tVal) = string_node("<=",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 692 "gram.y"
    {
				(yyval.tVal) = string_node("<>",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 696 "gram.y"
    {
				(yyval.tVal) = string_node(">=",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 700 "gram.y"
    {
				(yyval.tVal) = string_node(">",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 707 "gram.y"
    {
			(yyval.tVal) = string_node("+",N_ADD_OPER,NULL,NULL,NULL);
	    }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 711 "gram.y"
    {
		    (yyval.tVal) = string_node("-",N_ADD_OPER,NULL,NULL,NULL);
	    }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 718 "gram.y"
    {
			(yyval.tVal) = string_node("*",N_MUL_OPER,NULL,NULL,NULL);
	    }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 722 "gram.y"
    {
			(yyval.tVal) = string_node("/",N_MUL_OPER,NULL,NULL,NULL);
	    }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 729 "gram.y"
    {
		   (yyval.tVal) = int_node(NOTHING,N_OPTIONAL_SIGN,(yyvsp[(1) - (1)].tVal),NULL,NULL);
	    }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 733 "gram.y"
    {
		   (yyval.tVal) = int_node(NOTHING,N_OPTIONAL_SIGN,NULL,NULL,NULL);
	    }
    break;



/* Line 1455 of yacc.c  */
#line 2597 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 738 "gram.y"



TERNARY_TREE int_node(int iVal, int case_identifier, TERNARY_TREE p1,TERNARY_TREE p2, TERNARY_TREE p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = iVal;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
}


TERNARY_TREE string_node(char *sVal, int case_identifier, TERNARY_TREE p1, TERNARY_TREE p2, TERNARY_TREE p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->stem = sVal;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
}


#ifdef DEBUG
void PrintTree(TERNARY_TREE t)
{
    static unsigned depth;
    static unsigned previous;
    unsigned i;

    if (t == NULL) return;
    
    fprintf(stderr, "%3d %3d\t", depth, depth - previous);
    previous = depth;
    
    for (i = depth; i--;) fprintf(stderr, "| ");
    switch (t->nodeIdentifier) {
    case N_PROGRAM:
        
        fprintf(stderr, "PROGRAM : %s\n", symTab[t->item]->identifier);
        break;
    		
    case N_RELATIONAL_OPER:
	case N_ADD_OPER:
    case N_MUL_OPER:
        fprintf(stderr, "%s : %s\n", NodeName[t->nodeIdentifier], t->stem);
        return;

    default:
        
        if (t->nodeIdentifier >= 0 && t->nodeIdentifier < sizeof(NodeName)) {
            fprintf(stderr, "%s\n", NodeName[t->nodeIdentifier]);
        } else {
            fprintf(stderr, "UNKNOWN: %d\n", t->nodeIdentifier);
        }
        
        if (t->item > 0 && t->item < SYMTABSIZE) {
            if (symTab[t->item]->identifier) {
                fprintf(stderr, "%3d   1\t", ++depth);
                previous = depth;
                for (i = depth--; i--;) fprintf(stderr, "| ");
                fprintf(stderr, "IDENTIFIER : %s\n", symTab[t->item]->identifier);
            }
        }
        break;
    }
    
    ++depth;
    PrintTree(t->first);
    PrintTree(t->second);
    PrintTree(t->third);
    --depth;
}
#endif


int column;
extern int column;
extern void yyrestart( FILE *input_file );
extern FILE *new_file; 
int yydebug;


FILE *Source; 
int main(int argc, char *argv[])
{
if (argc!=2) printf("\nUsage: ph_2 <input file name> \n");
	else
		if ((new_file=fopen(argv[1],"r"))==NULL) 
			printf("\n<%s> not found.\n",argv[1]);
		else 
			{
				yyrestart(new_file); 
				return yyparse();
				fclose(new_file);
			}
symbol_table newst;
newst=create_st();
int yydebug=1;
return yyparse();
}


void yyerror(s)
char *s;
{
    fflush(stdout);
    printf("\nLine <%d>: %s\n",line,s);
    freestack_st();
	exit(1);
}


static void
yyprint (file, type, value)
     FILE *file;
     int type;
     YYSTYPE value;
{
    if (type == IDENTIFIER)
    fprintf (stderr," = %s", value.name);
 
}


void printerr(errconbr errmess)
{
	if (errmess!=NULL)
	{
		line=errmess->line;
		yyerror(errmess->mess);
	}
}


char *GetYYText(void)
{
char *ch;
ch=(char *)malloc(sizeof(char)*(strlen(yytext)+1));
strcpy(ch,yytext);
return ch;
}


void savefunc(funcdef func)
{
if (func->error!=NULL)
  {
	char *errmess=(char *)malloc(sizeof(char)*100);
	switch(func->error->code){
		case FPAR_NOT_FOUND		: sprintf(errmess,"Formal parameter '%s' not found",func->error->formal_pname); break;
		case FPAR_MORETONE		: sprintf(errmess,"Formal parameter '%s' is declared more than one times",func->error->formal_pname); break;
		case FPAR_NOT_FPARLIST	: sprintf(errmess,"Parameter '%s' not in formal parameter list",func->error->formal_pname); break;
	}
	yyerror(errmess);
 }
else if (!enter(proc_st,func->entr)) yyerror("Function redefinition");
}
