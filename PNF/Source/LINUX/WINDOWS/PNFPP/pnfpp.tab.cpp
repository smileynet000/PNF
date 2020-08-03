
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
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "pnfpp.ypp"

/* Prologue */
#include <desLib/desLib.hpp>

#include <process.h>
#include <cctype>
#include <ctime>


#define YYSTYPE String


class PNFPP_Def
{
 protected:
  String itsname;
  String itsvalue;
  unsigned long itsline;


 public:
  PNFPP_Def(String name = "", String value = "", unsigned long line = 0);
  PNFPP_Def(int value);
  PNFPP_Def(const PNFPP_Def & def);
  ~PNFPP_Def();

  void name(String name);
  String name();

  void value(String value);
  String value();

  void line(unsigned long line);
  unsigned long line();


  PNFPP_Def & operator =(const PNFPP_Def & def);
};

PNFPP_Def::PNFPP_Def(String name, String value, unsigned long line)
{
 itsname = name;
 itsvalue = value;
 itsline = line;
}

PNFPP_Def::PNFPP_Def(int value)
{
 itsname = "";
 itsvalue = "";
 itsline = 0;
}

PNFPP_Def::~PNFPP_Def()
{

}

PNFPP_Def::PNFPP_Def(const PNFPP_Def & def)
{
 itsname = def.itsname;
 itsvalue = def.itsvalue;
 itsline = def.itsline;
}

void PNFPP_Def::name(String name)
{
 itsname = name;
}

String PNFPP_Def::name()
{
 return itsname;
}

void PNFPP_Def::value(String value)
{
 itsvalue = value;
}

String PNFPP_Def::value()
{
 return itsvalue;
}

void PNFPP_Def::line(unsigned long line)
{
 itsline = line;
}

unsigned long PNFPP_Def::line()
{
 return itsline;
}

PNFPP_Def & PNFPP_Def::operator =(const PNFPP_Def & def)
{
 if (this == &def)
  return *this;

 itsname = def.itsname;
 itsvalue = def.itsvalue;

 return *this;
}

class PNFPP_Macro
{
 protected:
  String itsname;
  Array<String> itsparameters;
  Array<String> itsvalues;


 public:
  PNFPP_Macro(String n = "");
  PNFPP_Macro(int value);

  PNFPP_Macro(const PNFPP_Macro & macro);
  
  ~PNFPP_Macro();


  String name();
  void name(String n);

  Array<String> parameters();
  void parameters(Array<String> p);

  String parameter(unsigned long index);
  void parameter(unsigned long index, String p);

  Array<String> & values();
  String value(unsigned long index);
  void value(unsigned long index, String v);
};

PNFPP_Macro::PNFPP_Macro(String n)
{
 itsname = n;
}

PNFPP_Macro::PNFPP_Macro(int value)
{

}

PNFPP_Macro::PNFPP_Macro(const PNFPP_Macro & macro)
{
 itsname = macro.itsname;
 itsvalues = macro.itsvalues;
 itsparameters = macro.itsparameters;
}
  
PNFPP_Macro::~PNFPP_Macro()
{

}

String PNFPP_Macro::name()
{
 return itsname;
}

void PNFPP_Macro::name(String n)
{
 itsname = n;
}

Array<String> PNFPP_Macro::parameters()
{
 return itsparameters;
}

void PNFPP_Macro::parameters(Array<String> p)
{
 itsparameters = p;
}

String PNFPP_Macro::parameter(unsigned long index)
{
 if (index >= itsparameters.length())
 {
  char * num = ltoa(index, num, 10);
  throw Exception((String)"get: Macro index out of bounds. index = " + num, __FILE__, __LINE__);
 }
 
 return itsparameters[index];
}

void PNFPP_Macro::parameter(unsigned long index, String p)
{
 if (index >= itsparameters.length())
 {
  for (unsigned long i = 0; i <= index; ++i)
   itsparameters.insert();
 }
 
 itsparameters[index] = p;
}

Array<String> & PNFPP_Macro::values()
{
 return itsvalues;
}


String PNFPP_Macro::value(unsigned long index)
{
 if (index >= itsvalues.length())
 {
  char * num = ltoa(index, num, 10);
  throw Exception((String)"get: Macro index out of bounds. index = " + num, __FILE__, __LINE__);
 }

 return itsvalues[index];
}

void PNFPP_Macro::value(unsigned long index, String v)
{
 if (index >= itsvalues.length())
 {
  char * num = ltoa(index, num, 10);
  throw Exception((String)"put: Macro index out of bounds. index = " + num, __FILE__, __LINE__);
 }
 itsvalues[index] = v;
}


void yyerror(char const * c);
int yylex();

int Main(Array<String> args);

String strip_quotes(String str);
String remove_extension(String file);
String get_extension(String file);
String add_quotes(String str);

int conprint(const char * format, ...);
void generate_code();
void generate_defines();
void strip_spaces();


String input_file = "";

FILE * output;

unsigned long outcount = 0;


Array<String> files;
Array<PNFPP_Def> definitions;

Array<PNFPP_Macro> macros;
unsigned long macroindex = 0;
unsigned long macrovalueindex = 0;
Array<String> macrobuffer;
Array< Array<String> > replacements;
Array< Array<String> > macrovalues;
unsigned long parametercounter = 0;
unsigned long pcounter = 0;
unsigned long macrocount = 0;
unsigned long macrocounter = 0;
Array<unsigned long> macrocounterv;

unsigned long lineno = 1;


/* Line 189 of yacc.c  */
#line 344 "pnfpp.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
     OPLT = 258,
     OPGT = 259,
     OPST = 260,
     OPTK = 261,
     OPPAREN = 262,
     LPAREN = 263,
     RPAREN = 264,
     COMMA = 265,
     TSTRING = 266,
     STRING = 267,
     INCLUDE = 268,
     IMPORT = 269,
     DEFINE = 270,
     MACRO = 271,
     ENDM = 272,
     UNDEF = 273,
     IFDEF = 274,
     IFNDEF = 275,
     ELSE = 276,
     ENDIF = 277,
     PDATE = 278,
     PTIME = 279,
     PLINE = 280,
     PFILE = 281,
     PCDATE = 282,
     PCTIME = 283
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 427 "pnfpp.tab.cpp"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   81

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  98

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    30,    35,    38,    43,    47,
      53,    58,    61,    63,    65,    67,    69,    72,    74,    76,
      77,    78,    86,    87,    88,    89,   100,   102,   106,   108,
     111,   114,   115,   116,   123,   125,   129,   131,   133,   134,
     140,   141,   149,   150,   156,   157,   165,   167,   169,   171,
     173,   175
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      31,     0,    -1,    -1,    32,    31,    -1,    29,    -1,    33,
      -1,    37,    -1,     1,    -1,    34,    -1,    35,    -1,    36,
      -1,    40,    -1,    53,    -1,    60,    -1,    13,    12,    -1,
      13,     3,    12,     4,    -1,    14,    12,    -1,    14,     3,
      12,     4,    -1,    15,    12,    38,    -1,    15,    12,    39,
       6,    39,    -1,    15,    12,     5,    38,    -1,    18,    12,
      -1,    12,    -1,    11,    -1,    12,    -1,    38,    -1,     5,
      38,    -1,    41,    -1,    49,    -1,    -1,    -1,    16,    12,
       7,    42,    48,    43,    17,    -1,    -1,    -1,    -1,    16,
      12,     8,    44,    47,     9,    45,    48,    46,    17,    -1,
      12,    -1,    47,    10,    47,    -1,    11,    -1,    48,    11,
      -1,    12,     7,    -1,    -1,    -1,    12,     8,    50,    52,
      51,     9,    -1,    12,    -1,    52,    10,    52,    -1,    54,
      -1,    57,    -1,    -1,    19,    12,    48,    55,    22,    -1,
      -1,    19,    12,    48,    21,    48,    56,    22,    -1,    -1,
      20,    12,    48,    58,    22,    -1,    -1,    20,    12,    48,
      21,    48,    59,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   312,   312,   313,   316,   317,   318,   319,   325,   326,
     327,   328,   329,   330,   333,   383,   437,   504,   577,   606,
     637,   666,   682,   686,   692,   751,   755,   761,   762,   766,
     787,   765,   798,   816,   820,   797,   832,   840,   846,   868,
     892,   911,   929,   910,   991,   996,  1003,  1004,  1008,  1007,
    1026,  1025,  1050,  1049,  1068,  1067,  1091,  1097,  1103,  1107,
    1111,  1115
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPLT", "OPGT", "OPST", "OPTK",
  "OPPAREN", "LPAREN", "RPAREN", "COMMA", "TSTRING", "STRING", "INCLUDE",
  "IMPORT", "DEFINE", "MACRO", "ENDM", "UNDEF", "IFDEF", "IFNDEF", "ELSE",
  "ENDIF", "PDATE", "PTIME", "PLINE", "PFILE", "PCDATE", "PCTIME", "'\\n'",
  "$accept", "input", "line", "command", "include_command",
  "import_command", "define_command", "string2", "string", "string_cmd",
  "macro_command", "macro_definition", "$@1", "$@2", "$@3", "$@4", "$@5",
  "parameter_list", "tstrings", "macro_call", "$@6", "$@7",
  "parameter_list2", "if_command", "ifdef", "$@8", "$@9", "ifndef", "$@10",
  "$@11", "predefined_command", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    32,    32,    33,    33,
      33,    33,    33,    33,    34,    34,    35,    35,    36,    36,
      36,    36,    37,    37,    38,    39,    39,    40,    40,    42,
      43,    41,    44,    45,    46,    41,    47,    47,    48,    48,
      49,    50,    51,    49,    52,    52,    53,    53,    55,    54,
      56,    54,    58,    57,    59,    57,    60,    60,    60,    60,
      60,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     2,     4,     3,     5,
       4,     2,     1,     1,     1,     1,     2,     1,     1,     0,
       0,     7,     0,     0,     0,    10,     1,     3,     1,     2,
       2,     0,     0,     6,     1,     3,     1,     1,     0,     5,
       0,     7,     0,     5,     0,     7,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,    23,    22,     0,     0,     0,     0,     0,     0,
       0,    56,    57,    58,    59,    60,    61,     4,     0,     0,
       5,     8,     9,    10,     6,    11,    27,    28,    12,    46,
      47,    13,    40,    41,     0,    14,     0,    16,     0,     0,
      21,     0,     0,     1,     3,     0,     0,     0,     0,    24,
      18,     0,    29,    32,    38,    48,    52,    44,    42,    15,
      17,    20,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,    25,    19,    30,    36,     0,    50,    49,
      54,    53,    45,    43,    26,     0,    33,     0,     0,     0,
      31,     0,    37,    51,    55,    34,     0,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    18,    19,    20,    21,    22,    23,    24,    50,    51,
      25,    26,    63,    85,    64,    91,    96,    77,    55,    27,
      45,    71,    58,    28,    29,    67,    88,    30,    69,    89,
      31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int8 yypact[] =
{
      16,   -48,   -48,     0,     2,     6,    -6,    -2,    21,    25,
      26,   -48,   -48,   -48,   -48,   -48,   -48,   -48,    47,    16,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,    36,   -48,    38,   -48,    -1,    12,
     -48,    40,    40,   -48,   -48,    42,    48,    51,    44,   -48,
      52,    53,   -48,   -48,   -48,    -9,    -8,   -48,    50,   -48,
     -48,    55,    41,    40,    45,   -48,    40,    43,    40,    46,
      42,    54,    44,   -48,   -48,    56,   -48,    13,    56,   -48,
      56,   -48,    50,   -48,   -48,    49,   -48,    45,    57,    58,
     -48,    40,    59,   -48,   -48,    56,    60,   -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,    62,   -48,   -48,   -48,   -48,   -48,   -48,   -47,     8,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -25,   -42,   -48,
     -48,   -48,     1,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -27
static const yytype_int8 yytable[] =
{
      56,    61,    65,    65,    48,    34,    38,    32,    33,    36,
      39,    49,    66,    68,    35,    73,    -2,     1,    37,    52,
      53,    75,    86,    87,    78,    84,    80,     2,     3,     4,
       5,     6,     7,    40,     8,     9,    10,    41,    42,    11,
      12,    13,    14,    15,    16,    17,    72,    43,    46,    95,
      47,    54,    59,    49,    57,    60,    49,    76,   -25,    62,
      70,   -26,    92,    83,     0,    79,    90,    65,    81,    87,
      74,    82,     0,     0,     0,     0,     0,    97,     0,    93,
      94,    44
};

static const yytype_int8 yycheck[] =
{
      42,    48,    11,    11,     5,     3,    12,     7,     8,     3,
      12,    12,    21,    21,    12,    62,     0,     1,    12,     7,
       8,    63,     9,    10,    66,    72,    68,    11,    12,    13,
      14,    15,    16,    12,    18,    19,    20,    12,    12,    23,
      24,    25,    26,    27,    28,    29,     5,     0,    12,    91,
      12,    11,     4,    12,    12,     4,    12,    12,     6,     6,
      10,     6,    87,     9,    -1,    22,    17,    11,    22,    10,
      62,    70,    -1,    -1,    -1,    -1,    -1,    17,    -1,    22,
      22,    19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    11,    12,    13,    14,    15,    16,    18,    19,
      20,    23,    24,    25,    26,    27,    28,    29,    31,    32,
      33,    34,    35,    36,    37,    40,    41,    49,    53,    54,
      57,    60,     7,     8,     3,    12,     3,    12,    12,    12,
      12,    12,    12,     0,    31,    50,    12,    12,     5,    12,
      38,    39,     7,     8,    11,    48,    48,    12,    52,     4,
       4,    38,     6,    42,    44,    11,    21,    55,    21,    58,
      10,    51,     5,    38,    39,    48,    12,    47,    48,    22,
      48,    22,    52,     9,    38,    43,     9,    10,    56,    59,
      17,    45,    47,    22,    22,    48,    46,    17
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:

/* Line 1455 of yacc.c  */
#line 320 "pnfpp.ypp"
    {
	 yyerrok;
	;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 334 "pnfpp.ypp"
    {
			 Array<String> args;
   
    			 args[0] = (char *)"PNFPP";
		         args.insert();
			 args[1] = strip_quotes((yyvsp[(2) - (2)]));
			 args.insert();
			 args[2] = remove_extension(strip_quotes((yyvsp[(2) - (2)]))) + ".pnfpp";
    			 args.insert();
    			 args[args.length() - 1] = (char *)"";
 
   			 char ** args2 = new char * [args.length()];
    			 for (unsigned long i = 0; i < args.length(); ++i)
     			  args2[i] = (char *)args[i].getString().c_str();
    
    			 args2[args.length() - 1] = NULL;
   
   
   			 int ret = _spawnvp(_P_WAIT, "PNFPP", args2);
    			 delete args2;
   
   			 if (ret == -1 && errno != 0)
    			 {
   	 		  ret = 1;
   	 		  error(ERRORMSG, (char*)"Error running PNFPP program.");
    			 }
			 if (ret == -1)
			 {
			  yyerror("File cannot include itself.");
			  exit(-1);
			 }

			 fin.open((remove_extension(strip_quotes((yyvsp[(2) - (2)]))) + ".pnfpp").getString().c_str());
			 if (!fin)
			  yyerror("Can't open file.");

			 String str;
			 unsigned long i = 0;
			 do
			 {
			  if (i != 0)
			   conprint("\n");

			  fin >> str;
			  conprint("%s", str.getString().c_str());
			  ++i;
			 } while (!fin.eof());
			 fin.close();
			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 384 "pnfpp.ypp"
    {
			 String extension = get_extension(strip_quotes((yyvsp[(3) - (4)])));
			 (yyvsp[(3) - (4)]) = "..\\include\\" + remove_extension(strip_quotes((yyvsp[(3) - (4)])));
			 Array<String> args;
   
    			 args[0] = (char *)"PNFPP";
		         args.insert();
			 args[1] = (yyvsp[(3) - (4)]) + extension;
			 args.insert();
			 args[2] = (yyvsp[(3) - (4)]) + ".pnfpp";
    			 args.insert();
    			 args[args.length() - 1] = (char *)"";
 
   			 char ** args2 = new char * [args.length()];
    			 for (unsigned long i = 0; i < args.length(); ++i)
     			  args2[i] = (char *)args[i].getString().c_str();
    
    			 args2[args.length() - 1] = NULL;
   
   
   			 int ret = _spawnvp(_P_WAIT, "PNFPP", args2);
    			 delete args2;
   
   			 if (ret == -1 && errno != 0)
    			 {
   	 		  ret = 1;
   	 		  error(ERRORMSG, (char*)"Error running PNFPP program.");
    			 }
			 if (ret == -1)
			 {
			  yyerror("File cannot include itself.");
			  exit(-1);
			 }

			 fin.open(((yyvsp[(3) - (4)]) + ".pnfpp").getString().c_str());
			 if (!fin)
			  yyerror("Can't open file for fin.");

			 String str;
			 unsigned long i = 0;
			 do
			 {
			  if (i != 0)
			   conprint("\n");

			  fin >> str;
			  conprint("%s", str.getString().c_str());
			  ++i;
			 } while (!fin.eof());
			 fin.close();
			;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 438 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < files.length(); ++i)
			 {
			  if (files[i] == (yyvsp[(2) - (2)]))
			   found = true;
			 }

			 if (found == true)
			  ;
			 else
			 {
			  Array<String> args;
   
     			  args[0] = (char *)"PNFPP";
		          args.insert();
			  args[1] = strip_quotes((yyvsp[(2) - (2)]));
			  args.insert();
			  args[2] = remove_extension(strip_quotes((yyvsp[(2) - (2)]))) + ".pnfpp";
    			  args.insert();
    			  args[args.length() - 1] = (char *)"";
 
   			  char ** args2 = new char * [args.length()];
    			  for (unsigned long i = 0; i < args.length(); ++i)
     			   args2[i] = (char *)args[i].getString().c_str();
    
    			  args2[args.length() - 1] = NULL;
   
   
   			  int ret = _spawnvp(_P_WAIT, "PNFPP", args2);
    			  delete args2;
   
   			  if (ret == -1 && errno != 0)
    			  {
   	 		   ret = 1;
   	 		   error(ERRORMSG, (char*)"Error running PNFPP program.");
    			  }
			  if (ret == -1)
			  {
			   yyerror("File cannot include itself.");
			   exit(-1);
			  }

 			  fin.open((remove_extension(strip_quotes((yyvsp[(2) - (2)]))) + ".pnfpp").getString().c_str());
			  if (!fin)
			   yyerror("Can't open file.");

 			  String str;
			  unsigned long i = 0;
			  do
			  {
			   if (i != 0)
			    conprint("\n");

			   fin >> str;
			   conprint("%s", str.getString().c_str());
			   ++i;
			  } while (!fin.eof());


			  if (files.length() > 1)
			   files.insert();

                          files[files.length() - 1] = (yyvsp[(2) - (2)]);
			 }
			;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 505 "pnfpp.ypp"
    {
			 String extension = get_extension(strip_quotes((yyvsp[(3) - (4)])));
			 (yyvsp[(3) - (4)]) = "..\\include\\" + remove_extension(strip_quotes((yyvsp[(3) - (4)])));


			 bool found = false;
			 for (unsigned long i = 0; i < files.length(); ++i)
			 {
			  if (files[i] == (yyvsp[(3) - (4)]))
			   found = true;
			 }

			 if (found == true)
			  ;
			 else
			 {
			  Array<String> args;
   
    			  args[0] = (char *)"PNFPP";
		          args.insert();
			  args[1] = (yyvsp[(3) - (4)]) + extension;
			  args.insert();
			  args[2] = (yyvsp[(3) - (4)]) + ".pnfpp";
    			  args.insert();
    			  args[args.length() - 1] = (char *)"";
 
   			  char ** args2 = new char * [args.length()];
    			  for (unsigned long i = 0; i < args.length(); ++i)
     			   args2[i] = (char *)args[i].getString().c_str();
    
    			  args2[args.length() - 1] = NULL;
   
   
   			  int ret = _spawnvp(_P_WAIT, "PNFPP", args2);
    			  delete args2;
   
   			  if (ret == -1 && errno != 0)
    			  {
   	 		   ret = 1;
   	 		   error(ERRORMSG, (char*)"Error running PNFPP program.");
    			  }
			  if (ret == -1)
			  {
			   yyerror("File cannot include itself.");
			   exit(-1);
			  }

			  fin.open(((yyvsp[(3) - (4)]) + ".pnfpp").getString().c_str());
			  if (!fin)
			   yyerror("Can't open file.");

			  String str;
			  unsigned long i = 0;
			  do
			  {
			   if (i != 0)
			    conprint("\n");

			   fin >> str;
			   conprint("%s", str.getString().c_str());
			   ++i;
			  } while (!fin.eof());


 			  if (files.length() > 1)
			   files.insert();

                          files[files.length() - 1] = (yyvsp[(3) - (4)]);
			 }
		 	;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 578 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (definitions[i].name() == strip_quotes((yyvsp[(2) - (3)])))
			  {
			   if (definitions[i].value() != strip_quotes((yyvsp[(3) - (3)])))
			    definitions[i].value(strip_quotes((yyvsp[(3) - (3)])));

			   found = true;
			  }
			 }

			 if (found == false)
			 {
			  definitions[definitions.length() - 1].name(strip_quotes((yyvsp[(2) - (3)])));
			  definitions[definitions.length() - 1].value(strip_quotes((yyvsp[(3) - (3)])));
			  definitions.insert();
			 }

			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (strip_quotes((yyvsp[(3) - (3)])) == definitions[i].name())
			   definitions[definitions.length() - 2].value(definitions[i].value());
			 }
			
			 conprint("#define %s %s", (yyvsp[(2) - (3)]).getString().c_str(), (yyvsp[(3) - (3)]).getString().c_str());
			;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 607 "pnfpp.ypp"
    {
			 String tokenized = add_quotes((yyvsp[(3) - (5)]) + (yyvsp[(5) - (5)]));

			 bool found = false;
			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (definitions[i].name() == strip_quotes((yyvsp[(2) - (5)])))
			  {
			   if (definitions[i].value() != strip_quotes(tokenized))
			    definitions[i].value(strip_quotes(tokenized));

			   found = true;
			  }
			 }

			 if (found == false)
			 {
			  definitions[definitions.length() - 1].name(strip_quotes((yyvsp[(2) - (5)])));
			  definitions[definitions.length() - 1].value(strip_quotes(tokenized));
			  definitions.insert();
			 }

			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (strip_quotes(tokenized) == definitions[i].name())
			   definitions[definitions.length() - 2].value(definitions[i].value());
			 }
			
			 conprint("#define %s %s", (yyvsp[(2) - (5)]).getString().c_str(), tokenized.getString().c_str());
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 638 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (definitions[i].name() == strip_quotes((yyvsp[(2) - (4)])))
			  {
			   if (definitions[i].value() != (yyvsp[(4) - (4)]))
			    definitions[i].value((yyvsp[(4) - (4)]));

			   found = true;
			  }
			 }

			 if (found == false)
			 {
			  definitions[definitions.length() - 1].name(strip_quotes((yyvsp[(2) - (4)])));
			  definitions[definitions.length() - 1].value((yyvsp[(4) - (4)]));
			  definitions.insert();
			 }

			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (strip_quotes((yyvsp[(4) - (4)])) == definitions[i].name())
			   definitions[definitions.length() - 2].value(add_quotes(definitions[i].value()));
			 }
			
			 conprint("#define %s %s", (yyvsp[(2) - (4)]).getString().c_str(), add_quotes((yyvsp[(4) - (4)])).getString().c_str());
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 667 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (definitions[i].name() == strip_quotes((yyvsp[(2) - (2)])))
			  {
			   definitions[i].line(outcount);

			   found = true;
			  }
			 }
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 683 "pnfpp.ypp"
    {
			 conprint("%s", (yyvsp[(1) - (1)]).getString().c_str());
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 687 "pnfpp.ypp"
    {
			 conprint("%s", (yyvsp[(1) - (1)]).getString().c_str());
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 693 "pnfpp.ypp"
    {
			 String str = (yyvsp[(1) - (1)]);
			 String str2 = "";
			 bool saw = false;
			 for (unsigned long i = 0; i < str.length(); ++i)
			 {
			  if (str[i] == '\\')
			  {
			   if ((i - 1) > 0)
			   {
			    if (str[i - 1] == '\\')
			     saw = true;
			   }

			   if ((i + 1) == str.length())
			    yyerror("Unterminated escape sequence.");
			   else
			   {
			    switch (str[i + 1])
			    {
			     case '\\':
			      str2 += '\\';
			      break;

			     case 'n':
			      str2 += '\n';
			      break;

			     default:
			      if (isdigit((int)str[i + 1]) && !saw)
			      {
			       String str3 = "";
			       unsigned long j;
			       for (j = i + 1; isdigit((int)str[j]) && j < str.length(); ++j)
			       {
				str3 += str[j];
				i = j;
			       }
			       unsigned long num = atol(str3.getString().c_str());
			       str2 += (char)num;
			      }
			      else if (isdigit((int)str[i + 1]) && saw)
			       continue;
			      else
			       yyerror("Unknown escape sequence.");
			      break;
			    } // End switch
			   } // End else (if ((i + 1) == str.length()))
			  } // End if (str[i] == '\\')
			  else
			  {
			   str2 += str[i];
			  } // End else (if (str[i] == '\\'))
			 } // End for loop
			 (yyval) = str2;
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 752 "pnfpp.ypp"
    {
			 (yyval) = strip_quotes((yyvsp[(1) - (1)]));
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 756 "pnfpp.ypp"
    {
			 (yyval) = (yyvsp[(2) - (2)]);
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 766 "pnfpp.ypp"
    {
			 ++macrocounter;
			 macrocounterv[macrocounterv.length() - 1] = macrocounter;
			 macrocounterv.insert();

			 Array<String> strs;
			 strs[0] = "";

			 bool found = false;
			 for (unsigned long i = 0; i < macros.length(); ++i)
			 {
			  if (macros[i].name() == strip_quotes((yyvsp[(2) - (3)])))
			   found = true;
			 }

			 if (found)
			  yyerror("Macro already defined.");

			 macros[macros.length() - 1].name(strip_quotes((yyvsp[(2) - (3)])));
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 787 "pnfpp.ypp"
    {
			 for (unsigned long i = 0; i < macros[macros.length() - 1].values().length(); ++i)
 			  macros[macros.length() - 1].value(i, (yyvsp[(5) - (5)]));

			 macrovalues[macrovalues.length() - 1] = macros[macros.length() - 1].values();
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 794 "pnfpp.ypp"
    {
			 macros.insert();
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 798 "pnfpp.ypp"
    {
			 ++macrocounter;
			 macrocounterv[macrocounterv.length() - 1] = macrocounter;
			 macrocounterv.insert();

			 bool found = false;
			 for (unsigned long i = 0; i < macros.length(); ++i)
			 {
			  if (macros[i].name() == strip_quotes((yyvsp[(2) - (3)])))
			   found = true;
			 }

			 if (found)
			  yyerror("Macro already defined.");

			 macros[macros.length() - 1].name(strip_quotes((yyvsp[(2) - (3)])));
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 816 "pnfpp.ypp"
    {
			 pcounter = 0;
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 820 "pnfpp.ypp"
    {			 
			 macrovalues[macrovalues.length() - 1] = macros[macros.length() - 1].values();
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 824 "pnfpp.ypp"
    {
			 macros.insert();
			 replacements.insert();
			 macrovalues.insert();
			 pcounter = 0;
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 833 "pnfpp.ypp"
    {			 
  		         replacements[replacements.length() - 1].insert();
			 (yyval) = strip_quotes((yyvsp[(1) - (1)]));

			 macros[macros.length() - 1].parameter(pcounter, (yyval));			 
			 ++pcounter;
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 841 "pnfpp.ypp"
    {
			 (yyval) = (yyvsp[(1) - (3)]) + " " + (yyvsp[(3) - (3)]);			
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 847 "pnfpp.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 Array<String> strs;
			 strs[0] = "";
			 for (unsigned long i = 0, j = 0; i < (yyval).length(); ++i)
			 {
			  if ((yyval)[i] == ' ')
			  {
			   macros[macros.length() - 1].values().insert();
			   macrovalues[macrovalues.length() - 1].insert();
			   ++j;
			   strs.insert();
			   strs[j] = "";
			   continue;
			  }
			  strs[j] += (yyval)[i];
			 }

			 macros[macros.length() - 1].values() = strs;
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 869 "pnfpp.ypp"
    {
			 (yyval) = (yyvsp[(1) - (2)]) + " " + (yyvsp[(2) - (2)]);

			 Array<String> strs;
			 strs[0] = "";
			 for (unsigned long i = 0, j = 0; i < (yyval).length(); ++i)
			 {
			  if ((yyval)[i] == ' ')
			  {
			   macros[macros.length() - 1].values().insert();
			   macrovalues[macrovalues.length() - 1].insert();
			   ++j;
			   strs.insert();
			   strs[j] = "";
			   continue;
			  }
			  strs[j] += (yyval)[i];
			 }

			 macros[macros.length() - 1].values() = strs;
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 893 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < macros.length(); ++i)
			 {
			  if (macros[i].name() == strip_quotes((yyvsp[(1) - (2)])))
			  {
			   macroindex = i;
			   found = true;
			  }
			 }

			 if (!found)
			  yyerror("Macro not defined.");


			 conprint("%s", macros[macroindex].value(0).getString().c_str());
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 911 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < macros.length(); ++i)
			 {
			  if (macros[i].name() == strip_quotes((yyvsp[(1) - (2)])))
			  {
			   macroindex = i;
			   found = true;
			  }
			 }

			 if (!found)
			  yyerror("Macro not defined.");


			 macrovalues[macroindex] = macros[macroindex].values();
			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 929 "pnfpp.ypp"
    {
			 Array<String> strs;
			 strs[0] = "";
			 for (unsigned i = 0, j = 0; i < (yyvsp[(4) - (4)]).length(); ++i)
			 {
			  if ((yyvsp[(4) - (4)])[i] == ' ')
			  {
			   ++j;
			   strs.insert();
			   strs[j] = "";
			   continue;
			  }
			  strs[j] += (yyvsp[(4) - (4)])[i];
			 }

			 replacements[macroindex] = strs;

			 for (unsigned long i = 0; i < macros[macroindex].parameters().length(); ++i)
			 {
			  for (unsigned long j = 0; j < macrovalues[macroindex].length(); ++j)
			  {
			   if (macros[macroindex].parameter(i) == macrovalues[macroindex][j])
			   {
			    macrovalues[macroindex][j] = replacements[macroindex][i];
			   }
			  }
			 }
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 958 "pnfpp.ypp"
    {
			 Array<String> strs;
			 for (unsigned long i = 0; i < macrovalues[macroindex].length(); ++i)
			 {
			  strs[strs.length() - 1] =  " " + macrovalues[macroindex][i];
			  strs.insert();
			 }
			 parametercounter = 0;

			 for (unsigned long i = 0; i < strs.length(); i++)
			 {
			  for (unsigned long j = 0; j < strs[i].length(); ++j)
			  {
			   if (strs[i][j] == ' ' && i == 0 && j == 0)
			    continue;
			   else
			   {
			    if (macrocount == 0)
			    {
			     conprint("%d", macrocounterv[macrocounterv.length() - 1]);
			     conprint("macro: %c", strs[i][j]);
			    }
			    else
			     conprint("%c", strs[i][j]);
			    ++macrocount;
			   }
			  }
			 }
			 macrocount = 0;			
			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 992 "pnfpp.ypp"
    {
			 (yyval) = strip_quotes((yyvsp[(1) - (1)]));
			 ++parametercounter;
			;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 997 "pnfpp.ypp"
    {
			 (yyval) = (yyvsp[(1) - (3)]) + " " + (yyvsp[(3) - (3)]);
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1008 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (definitions[i].name() == strip_quotes((yyvsp[(2) - (3)])))
			  {
			   if (definitions[i].line() == 0)
			    found = true;
			  }
			 }

			 if (found == true)
			 {
			  conprint("%s", (yyvsp[(3) - (3)]).getString().c_str());
			 }
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1026 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (definitions[i].name() == strip_quotes((yyvsp[(2) - (5)])))
			  {
			   if (definitions[i].line() == 0)
			    found = true;
			  }
			 }

			 if (found == true)
			 {
			  conprint("%s", (yyvsp[(3) - (5)]).getString().c_str());
			 }
			 else
			 {
			  conprint("%s", (yyvsp[(5) - (5)]).getString().c_str());
			 }
			;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1050 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (definitions[i].name() == strip_quotes((yyvsp[(2) - (3)])))
			  {
			   if (definitions[i].line() == 0)
			    found = true;
			  }
			 }

			 if (found == false)
			 {
			  conprint("%s", (yyvsp[(3) - (3)]).getString().c_str());
			 }
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1068 "pnfpp.ypp"
    {
			 bool found = false;
			 for (unsigned long i = 0; i < definitions.length(); ++i)
			 {
			  if (definitions[i].name() == strip_quotes((yyvsp[(2) - (5)])))
			  {
			   if (definitions[i].line() == 0)
			    found = true;
			  }
			 }

			 if (found == false)
			 {
			  conprint("%s", (yyvsp[(3) - (5)]).getString().c_str());
			 }
			 else
			 {
			  conprint("%s", (yyvsp[(5) - (5)]).getString().c_str());
			 }
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1092 "pnfpp.ypp"
    {
			 time_t t = time(0);
    			 struct tm * now = localtime(&t);
   			 conprint("%d-%d-%d", (now->tm_year + 1900), (now->tm_mon + 1), now->tm_mday);
			;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1098 "pnfpp.ypp"
    {
			 time_t t = time(0);
    			 struct tm * now = localtime(&t);
   			 conprint("%d:%d:%d", now->tm_hour, now->tm_min, now->tm_sec);
			;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1104 "pnfpp.ypp"
    {
			 conprint("%d", lineno);
			;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1108 "pnfpp.ypp"
    {
			 conprint("%s", input_file.getString().c_str());
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1112 "pnfpp.ypp"
    {
			 conprint("%s", __DATE__);
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1116 "pnfpp.ypp"
    {
			 conprint("%s", __TIME__);
			;}
    break;



/* Line 1455 of yacc.c  */
#line 2698 "pnfpp.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
#line 1122 "pnfpp.ypp"

/* Additional C/C++ Code */
String strip_quotes(String str)
{
 String str2 = "";

 for (unsigned long i = 0; i < str.length(); ++i)
 {
  if (i == 0)
   continue;
  else if (i == str.length() - 1)
   continue;
  else
   str2 += str[i];
 }

 return str2;
}

String remove_extension(String file)
{
 String ret;

 file = strrev((char *)file.getString().c_str());
 unsigned long pos = file.getString().find('.');
 if (pos == string::npos)
  ret = strrev((char *)file.getString().c_str());

 ret = file.getString().substr(pos + 1);
 ret = strrev((char *)ret.getString().c_str());


 return ret;
}

String get_extension(String file)
{
 String extension;

 unsigned long index = file.getString().find(".");
 if (index == string::npos)
 {
  extension = file;
  return extension;
 }

 extension = file.getString().substr(index);


 return extension;
}

String add_quotes(String str)
{
 String str2 = "\"";
 for (unsigned long i = 0; i < str.length(); ++i)
  str2 += str[i];
 str2 += '\"';


 return str2;
}
