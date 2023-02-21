
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
#line 1 "pnfha.ypp"

/* Prologue */
#include <deslib/deslib.hpp>
#include <cmath>
#include <sstream>
#include <typeinfo>

#include "..\pnf.hpp"


#define YYSTYPE PNF_Variable
#define YYDEBUG 1


int main(int argc, char ** argv);
void yyerror(char const * c);
String get_extension(String fileName);
String strip_extension(String fileName);
void preprocess(String arg);
int conprint(const char * format, ...);
void movelineno(unsigned long index, unsigned long line);
void sort(Array<unsigned long> & array);
void sort_lines(Array<String> & array);
int yylex();
String strip_quotes(String str);
FILE * output;

PNF_Type_Enum exptype;


class Var
{
 private:
  String itsname;
  PNF_Variable itsvalue;
  unsigned long itsaddress;

 public:
  Var();
  Var(int v);


  void name(String name);
  String name();

  void value(PNF_Variable value);
  PNF_Variable value();

  void address(unsigned long a);
  unsigned long address();

  Var operator=(const Var & v);
};

Var::Var()
{
 itsname = "";
 itsvalue.to_number().put(0);
 itsaddress = 0;
}

Var::Var(int v)
{
 itsname = "";
 PNF_Number n(v);
 PNF_Variable p(n);
 itsvalue = p;
 itsaddress = 0;
}

void Var::name(String name)
{
 itsname = name;
}

String Var::name()
{
 return itsname;
}

void Var::value(PNF_Variable value)
{
 itsvalue = value;
}

PNF_Variable Var::value()
{
 return itsvalue;
}

void Var::address(unsigned long a)
{
 itsaddress = a;
}

unsigned long Var::address()
{
 return itsaddress;
}

Var Var::operator=(const Var & v)
{
 if (this == &v)
  return *this;

 itsname = v.itsname;
 itsvalue = v.itsvalue;
 itsaddress = v.itsaddress;
  
  
 return (*this);
}


class CLabel
{
 private:
  String itsname;
  unsigned long itsaddress;
  bool itsdeclared;

 public:
  CLabel();
  CLabel(int i);


  void name(String name);
  String name();

  void address(unsigned long a);
  unsigned long address();

  void declared(bool d);
  bool declared();
};

CLabel::CLabel()
{
 itsname = "";
 itsaddress = 0;
}

CLabel::CLabel(int i)
{
 itsname = "";
 itsaddress = i;
 itsdeclared = false;
}

void CLabel::name(String name)
{
 itsname = name;
}

String CLabel::name()
{
 return itsname;
}

void CLabel::address(unsigned long a)
{
 itsaddress = a;
}

unsigned long CLabel::address()
{
 return itsaddress;
}

void CLabel::declared(bool d)
{
 itsdeclared = d;
}

bool CLabel::declared()
{
 return itsdeclared;
}

class CELabel : public CLabel
{
 protected:
  static unsigned long itshevents;
  static unsigned long itsshevents;
  static unsigned long itsevents;
  static unsigned long itsexceptions;
  static unsigned long itsints;

 
 public:
  CELabel();
  CELabel(int i);

  static void inchevents();
  static void dechevents();
  static unsigned long hevents();

  static void incshevents();
  static void decshevents();
  static unsigned long shevents();

  static void incevents();
  static void decevents();
  static unsigned long events();

  static void incexceptions();
  static void decexceptions();
  static unsigned long exceptions();

  static void incints();
  static void decints();
  static unsigned long ints();
};


unsigned long CELabel::itshevents = 0;
unsigned long CELabel::itsshevents = 0;
unsigned long CELabel::itsevents = 0;
unsigned long CELabel::itsexceptions = 0;
unsigned long CELabel::itsints = 0;

CELabel::CELabel() : CLabel()
{

}

CELabel::CELabel(int i) : CLabel(i)
{

}

void CELabel::inchevents()
{
 ++itshevents;
}

void CELabel::dechevents()
{
 --itshevents;
}

unsigned long CELabel::hevents()
{
 return itshevents;
}

void CELabel::incshevents()
{
 ++itsshevents;
}

void CELabel::decshevents()
{
 --itsshevents;
}

unsigned long CELabel::shevents()
{
 return itsshevents;
}

void CELabel::incevents()
{
 ++itsevents;
}

void CELabel::decevents()
{
 --itsevents;
}

unsigned long CELabel::events()
{
 return itsevents;
}

void CELabel::incexceptions()
{
 ++itsexceptions;
}

void CELabel::decexceptions()
{
 --itsexceptions;
}

unsigned long CELabel::exceptions()
{
 return itsexceptions;
}

void CELabel::incints()
{
 ++itsints;
}

void CELabel::decints()
{
 --itsints;
}

unsigned long CELabel::ints()
{
 return itsints;
}

class ASTNode
{
 protected:
  String name;
  Array<String> value;
  unsigned long valuecount;


 public:
  ASTNode(const String n = "");
  ASTNode(char * n);
  ASTNode(const Array<String> v, const String n = "");
	
  ASTNode(ASTNode & n);

  ~ASTNode();

  
  String getName();
  Array<String> getValue();

  void setName(const String n);
  void setValue(const Array<String> v);

  void setNode(const ASTNode n);


  int conprint(const char * format, ...);


  ASTNode operator=(ASTNode & n);
};

ASTNode::ASTNode(const String n)
{
 name = n;
 valuecount = 0;
}

ASTNode::ASTNode(char * n)
{
 name = n;
 valuecount = 0;
}

ASTNode::ASTNode(const Array<String> v, const String n)
{
 name = n;
 value = v;
 valuecount = value.length();
}

ASTNode::ASTNode(ASTNode & n)
{
 name = n.getName();
 
 for (unsigned long i = 0; i < n.value.length(); ++i)
 {
  if (i != 0)
   value.insert();

  value[i] = n.value[i];
 }
}

ASTNode::~ASTNode()
{
 
}

String ASTNode::getName()
{
 return name;
}

Array<String> ASTNode::getValue()
{
 return value;
}

void ASTNode::setName(String n)
{
 name = n;
}

void ASTNode::setValue(Array<String> v)
{
 for (unsigned long i = 0; i < v.length(); ++i)
 {
  if (i != 0)
   value.insert();

  value[i] = v[i];
 }
}

void ASTNode::setNode(ASTNode n)
{
 name = n.getName();
 
 for (unsigned long i = 0; i < n.value.length(); ++i)
 {
  if (i != 0)
   value.insert();

  value[i] = n.value[i];
 }
}

int ASTNode::conprint(const char * format, ...)
{
 char outbuffer[256];


 va_list arg;
 int done = 0;

 va_start(arg, format);

 value.insert();
 done = vsnprintf(outbuffer, 256, format, arg);
 String str = "";
 if (outbuffer != NULL)
  str += outbuffer;
 value[valuecount] = str;
 ++valuecount;

 va_end(arg);


 return done;
}

ASTNode ASTNode::operator=(ASTNode & n)
{
 if (this == &n)
  return *this;

 name = n.name;
 value = n.value;

 return *this; 
}

class ASTTree
{
 protected:
  Array<ASTNode *> nodes;


 public:
  ASTTree();
  ASTTree(ASTTree & t);
  ~ASTTree();


  void add_node(ASTNode & node);
  void remove_node();
  void remove_node(String n);

  ASTNode & getNode(String n);
  ASTNode & getNode(unsigned long offset);
  void setNode(String n, ASTNode & node);
  void setNode(unsigned long offset, ASTNode & node);

  unsigned long nodenumber();
};

ASTTree::ASTTree()
{
 nodes[0] = 0;
}

ASTTree::ASTTree(ASTTree & t)
{
 nodes = t.nodes;
}

ASTTree::~ASTTree()
{
 for (unsigned long i = 1; i < nodenumber(); ++i)
  remove_node();
}

void ASTTree::add_node(ASTNode & node)
{
 if (nodes.length() == 1 && nodes[0] == NULL)
  nodes[0] = new ASTNode (node);
 else
 {
  nodes.insert();
  nodes[nodes.length() - 1] = new ASTNode(node);
 }
}

void ASTTree::remove_node()
{
 if (nodes.length() > 1)
 {
  delete nodes[nodes.length() - 1];
  nodes[nodes.length() - 1] = NULL;
  nodes.remove();
 }
 else if (nodes.length() == 1 && nodes[0] != NULL)
 {
  delete nodes[0];
  nodes[0] = NULL;
 }
 else
 {
  cout << "* ERROR: Called ASTTree::remove_node(), but nothing to do." << endl;
  exit(-1);
 }
}

void ASTTree::remove_node(String n)
{
 for (unsigned long i = 0; i < nodes.length(); ++i)
 {
  if (nodes[i]->getName().getString() == n.getString())
  {
   nodes.remove(i);
  }
 }
}

ASTNode & ASTTree::getNode(String n)
{
 for (unsigned long i = 0; i < nodes.length(); ++i)
 {
  if (nodes[i]->getName().getString() == n.getString())
   return *nodes[i];
 }
}
 
ASTNode & ASTTree::getNode(unsigned long offset)
{
 if (offset < nodes.length())
 {
  return *nodes[offset];
 }
 else if (offset < 0 || offset > nodes.length())
 {
  String errormsg = "Index out of bounds. node = ";
  String temp;
  char temp2[33];
  itoa(offset, temp2, 10);
  temp = temp2;
  errormsg += temp;
  cout << "* ERROR: " << errormsg.getString().c_str() << endl;
  exit(-1);
 }
}

void ASTTree::setNode(String n, ASTNode & node)
{
 for (unsigned long i = 0; i < nodes.length(); ++i)
 {
  if (nodes[i]->getName().getString() == n.getString())
  {
   nodes[i] = NULL;
   nodes[i] = new ASTNode(node);
  }
 }
}

void ASTTree::setNode(unsigned long offset, ASTNode & node)
{
 if (offset < nodes.length())
 {
  nodes[offset] = NULL;
  nodes[offset] = new ASTNode(node);
 }
 else
 {
  String errormsg = "Index out of bounds. node = ";
  String temp;
  char temp2[33];
  itoa(offset, temp2, 10);
  temp = temp2;
  errormsg += temp;
  cout << "* ERROR: " << errormsg.getString().c_str() << endl;
  exit(-1);
 }
}

unsigned long ASTTree::nodenumber()
{
 return nodes.length();
}


unsigned long scope = 0;
Array< Array<Var> > varTable;
Array<CLabel> labelTable;
Array<CELabel> eventLabelTable;

unsigned long ifcounter = 0;
String ifcounternum = "";
unsigned long ifnest = 0;
unsigned long elsecounter = 0;
unsigned long ifgoto = 0;

Array<String> out;
char outbuffer[256];
unsigned long outcount;

Array<unsigned long> statementoutcount = 0;
unsigned long ifbegin = 0;
unsigned long ifbeginlineno = 0;
unsigned long elsebegin = 0;
unsigned long elsebeginlineno = 0;
unsigned long endifbegin = 0;
Array<unsigned long> statementlineno = 0;


unsigned long varcount = 0;

bool inblock = false;
bool blockinstmt = false;
bool blockinelse = false;
bool blockinif = false;
bool inif = false;


unsigned long switchcounter = 0;
PNF_Type_Enum switchexptype = TVOID;
unsigned long switchcasecounter = 0;
bool inswitch = false;
bool switchfound = false;

bool inloop = false;
unsigned long midloop = 0;
bool loopexpr = false;
bool infor = false;
unsigned short inforfor = 3;

unsigned long whilecounter = 0;

unsigned long dowhilecounter = 0;

unsigned long forcounter = 0;

unsigned long doforcounter = 0;

unsigned long forevercounter = 0;


bool inloop2 = false;
bool inwhile = false;
bool indowhile = false;
bool infor2 = false;
bool indofor = false;
bool inforever = false;


bool exptruth = false;


unsigned long topcounter = 0;

bool intop = false;
unsigned long intopfor = 2;


bool breakinforever = false;


ASTTree tree;


/* Line 189 of yacc.c  */
#line 751 "pnfha.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     OPDEC = 258,
     OPINC = 259,
     NEG = 260,
     OPBTNOT = 261,
     OPNOT = 262,
     OPAMP = 263,
     OPROOT = 264,
     OPPOWER = 265,
     OPMODULUS = 266,
     OPDIV = 267,
     OPTIMES = 268,
     OPPLUS = 269,
     OPMINUS = 270,
     OPBTSR = 271,
     OPBTSL = 272,
     OPGEQU = 273,
     OPGTR = 274,
     OPLEQU = 275,
     OPLSS = 276,
     OPNEQU = 277,
     OPEQU = 278,
     OPBTOR = 279,
     OPBTXOR = 280,
     OPAND = 281,
     OPOR = 282,
     OPEQUAL = 283,
     LEFTP = 284,
     RIGHTP = 285,
     LEFTB = 286,
     RIGHTB = 287,
     VOIDV = 288,
     BOOLEANV = 289,
     NUMBERV = 290,
     CHARACTERV = 291,
     STRINGV = 292,
     SEND = 293,
     COMMA = 294,
     OPQUES = 295,
     OPCOLON = 296,
     OPSUB = 297,
     OPSTR = 298,
     ID = 299,
     VAR = 300,
     PRINT = 301,
     PRINTLN = 302,
     EPRINT = 303,
     EPRINTLN = 304,
     END = 305,
     ASM = 306,
     TYPE = 307,
     READ = 308,
     LOAD = 309,
     LTYPE = 310,
     GOTO = 311,
     GTYPE = 312,
     ST = 313,
     PUSH = 314,
     POP = 315,
     TYPEOF = 316,
     RTYPE = 317,
     ATOC = 318,
     SWITCH = 319,
     CSWITCH = 320,
     CRASH = 321,
     VERSION = 322,
     VTYPE = 323,
     HALT = 324,
     MODT = 325,
     RETURN = 326,
     GOSUB = 327,
     SUB = 328,
     EVENT = 329,
     STYPE = 330,
     ATYPE = 331,
     CTYPE = 332,
     CMTYPE = 333,
     BFMODEC = 334,
     FMODEC = 335,
     UNREGISTER = 336,
     REGISTER = 337,
     REREGISTER = 338,
     STORE = 339,
     IF = 340,
     ELSE = 341,
     CASE = 342,
     CCASE = 343,
     DEFAULT = 344,
     CDEFAULT = 345,
     BREAK = 346,
     LABEL = 347,
     WHILE = 348,
     ADDRESSOF = 349,
     ADD2V = 350,
     STOREA = 351,
     DOWHILE = 352,
     DOFOR = 353,
     FOR = 354,
     FVAR = 355,
     FOREVER = 356,
     CONTINUE = 357,
     CHECK = 358,
     HCMNT = 359,
     FMODE = 360,
     FOPEN = 361,
     FCLOSE = 362,
     FEOF = 363,
     FPRINT = 364,
     FPRINTLN = 365,
     FREAD = 366,
     MEML = 367,
     ENUM = 368,
     ENUMV = 369,
     VTYPE2 = 370,
     RANGE = 371,
     RTYPE2 = 372,
     OPDOT = 373,
     RANGEV = 374,
     OPLSQ = 375,
     OPRSQ = 376,
     ARRAY = 377,
     BLANK = 378,
     PNFASM = 379,
     LENGTH = 380,
     DUP = 381,
     PBIN = 382,
     PPBIN = 383,
     PLIB = 384,
     PINCLUDE = 385,
     PIMPORT = 386,
     PDEFINE = 387,
     PMACRO = 388,
     PENDM = 389,
     PUNDEF = 390,
     PIFDEF = 391,
     PIFNDEF = 392,
     PELSE = 393,
     PENDIF = 394,
     PPDATE = 395,
     PPTIME = 396,
     PPLINE = 397,
     PPFILE = 398,
     PPCDATE = 399,
     PPCTIME = 400,
     PPINCLUDE = 401,
     PPIMPORT = 402,
     PPDEFINE = 403,
     PPMACRO = 404,
     PPENDM = 405,
     PPUNDEF = 406,
     PPIFDEF = 407,
     PPIFNDEF = 408,
     PPELSE = 409,
     PPENDIF = 410,
     PPPDATE = 411,
     PPPTIME = 412,
     PPPLINE = 413,
     PPPFILE = 414,
     PPPCDATE = 415,
     PPPCTIME = 416
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 954 "pnfha.tab.cpp"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  446
/* YYNRULES -- Number of states.  */
#define YYNSTATES  759

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   419

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    13,    15,    16,
      19,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    44,    47,    50,    53,    57,    61,    63,    65,    67,
      68,    69,    70,    71,    82,    83,    86,    87,    88,    89,
     101,   102,   103,   104,   116,   117,   120,   123,   124,   130,
     131,   135,   136,   139,   142,   143,   144,   151,   152,   156,
     157,   160,   162,   164,   166,   167,   170,   171,   172,   173,
     182,   183,   184,   185,   186,   187,   199,   200,   201,   202,
     203,   204,   219,   220,   221,   222,   223,   224,   225,   242,
     243,   247,   251,   253,   256,   258,   260,   262,   264,   266,
     268,   270,   272,   274,   278,   280,   283,   287,   291,   295,
     297,   301,   305,   309,   313,   317,   320,   324,   328,   331,
     334,   337,   340,   344,   348,   352,   355,   359,   363,   367,
     369,   373,   377,   381,   385,   389,   393,   397,   400,   403,
     406,   409,   413,   415,   419,   422,   426,   428,   431,   434,
     438,   442,   446,   450,   454,   458,   462,   465,   469,   473,
     476,   479,   482,   485,   489,   493,   497,   501,   505,   509,
     510,   515,   519,   523,   527,   531,   535,   539,   543,   547,
     551,   555,   559,   563,   567,   571,   575,   579,   583,   587,
     591,   595,   599,   603,   607,   611,   615,   619,   623,   627,
     631,   635,   639,   643,   647,   651,   655,   659,   663,   667,
     671,   675,   679,   683,   687,   691,   695,   699,   703,   707,
     711,   714,   718,   722,   726,   730,   732,   734,   736,   738,
     741,   746,   749,   751,   753,   755,   761,   768,   773,   779,
     780,   781,   790,   792,   796,   805,   808,   811,   814,   816,
     818,   820,   822,   824,   826,   828,   830,   832,   834,   836,
     838,   840,   842,   844,   846,   848,   850,   852,   854,   856,
     858,   860,   862,   864,   866,   868,   870,   872,   874,   877,
     880,   882,   885,   888,   890,   893,   895,   898,   900,   903,
     905,   908,   912,   916,   920,   923,   928,   933,   938,   941,
     945,   949,   953,   957,   962,   966,   970,   975,   983,   990,
     996,  1000,  1004,  1006,  1009,  1012,  1015,  1017,  1020,  1022,
    1025,  1027,  1030,  1032,  1035,  1037,  1040,  1042,  1045,  1047,
    1049,  1051,  1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,
    1070,  1073,  1076,  1079,  1082,  1085,  1088,  1091,  1094,  1097,
    1100,  1103,  1106,  1109,  1111,  1113,  1115,  1117,  1119,  1121,
    1123,  1124,  1125,  1126,  1127,  1137,  1139,  1141,  1143,  1146,
    1148,  1150,  1153,  1156,  1158,  1161,  1163,  1166,  1170,  1173,
    1177,  1182,  1187,  1192,  1196,  1199,  1203,  1208,  1215,  1221,
    1223,  1226,  1230,  1232,  1234,  1239,  1244,  1249,  1254,  1258,
    1262,  1266,  1270,  1273,  1275,  1277,  1282,  1287,  1290,  1292,
    1294,  1296,  1299,  1304,  1307,  1312,  1316,  1319,  1321,  1324,
    1327,  1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,  1346,
    1349,  1354,  1357,  1362,  1366,  1369,  1371,  1374,  1377,  1380,
    1382,  1384,  1386,  1388,  1390,  1392,  1394
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     166,     0,    -1,    -1,   166,   167,    -1,    -1,   168,   162,
      -1,   169,    -1,     1,    -1,    -1,   170,   171,    -1,   169,
      39,   171,    -1,   176,    -1,    38,    -1,   172,    -1,   173,
      -1,   175,    -1,   174,    -1,   229,    -1,   287,    -1,   288,
      -1,   231,    38,    -1,   241,    38,    -1,   252,    38,    -1,
      44,    41,    -1,    73,    44,    41,    -1,    74,    44,    41,
      -1,   177,    -1,   183,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    85,   178,    29,   231,    30,   179,   171,   180,   182,
     181,    -1,    -1,    86,   171,    -1,    -1,    -1,    -1,    64,
      29,   231,    30,    31,   184,   190,   185,   194,   186,    32,
      -1,    -1,    -1,    -1,    65,    29,   171,    30,   187,    31,
     195,   188,   200,   189,    32,    -1,    -1,   191,   192,    -1,
     190,   192,    -1,    -1,    87,   231,   193,    41,   171,    -1,
      -1,    89,    41,   171,    -1,    -1,   196,   197,    -1,   195,
     197,    -1,    -1,    -1,    88,   198,   171,    41,   199,   171,
      -1,    -1,    90,    41,   171,    -1,    -1,   202,   204,    -1,
     208,    -1,   214,    -1,   220,    -1,    -1,   227,   203,    -1,
      -1,    -1,    -1,    93,    29,   205,   171,   206,    30,   207,
     171,    -1,    -1,    -1,    -1,    -1,    -1,   209,    97,   210,
     171,    93,   211,    29,   212,   171,   213,    30,    -1,    -1,
      -1,    -1,    -1,    -1,   215,    99,    29,   216,   171,    38,
     217,   171,    38,   218,   171,   219,    30,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,   221,   171,   222,    99,
      29,   223,   171,    38,   224,   171,    38,   225,   171,   226,
      30,    -1,    -1,   101,   228,   171,    -1,    31,   230,    32,
      -1,   169,    -1,   169,   230,    -1,   232,    -1,   233,    -1,
     234,    -1,   235,    -1,   236,    -1,   237,    -1,   238,    -1,
     240,    -1,    33,    -1,    29,   232,    30,    -1,    34,    -1,
       7,   233,    -1,   233,    26,   233,    -1,   233,    27,   233,
      -1,    29,   233,    30,    -1,    35,    -1,   234,    14,   234,
      -1,   234,    15,   234,    -1,   234,    13,   234,    -1,   234,
      12,   234,    -1,   234,    11,   234,    -1,    15,   234,    -1,
     234,    10,   234,    -1,   234,     9,   234,    -1,     4,   234,
      -1,   234,     4,    -1,     3,   234,    -1,   234,     3,    -1,
     234,     8,   234,    -1,   234,    24,   234,    -1,   234,    25,
     234,    -1,     6,   234,    -1,   234,    17,   234,    -1,   234,
      16,   234,    -1,    29,   234,    30,    -1,    36,    -1,   235,
      14,   235,    -1,   235,    15,   235,    -1,   235,    13,   235,
      -1,   235,    12,   235,    -1,   235,    11,   235,    -1,   235,
      10,   235,    -1,   235,     9,   235,    -1,     4,   235,    -1,
     235,     4,    -1,     3,   235,    -1,   235,     3,    -1,    29,
     235,    30,    -1,    37,    -1,   236,    14,   236,    -1,    43,
     236,    -1,    29,   236,    30,    -1,    44,    -1,     8,   237,
      -1,     7,   237,    -1,   237,    26,   237,    -1,   237,    27,
     237,    -1,   237,    14,   237,    -1,   237,    15,   237,    -1,
     237,    13,   237,    -1,   237,    12,   237,    -1,   237,    11,
     237,    -1,    15,   237,    -1,   237,    10,   237,    -1,   237,
       9,   237,    -1,     4,   237,    -1,   237,     4,    -1,     3,
     237,    -1,   237,     3,    -1,    29,   237,    30,    -1,   234,
      23,   234,    -1,   234,    22,   234,    -1,   234,    21,   234,
      -1,   234,    19,   234,    -1,   234,    20,   234,    -1,    -1,
     234,    18,   234,   239,    -1,    29,   240,    30,    -1,    44,
      26,   233,    -1,   233,    26,    44,    -1,    44,    27,   233,
      -1,   233,    27,    44,    -1,    44,    14,   234,    -1,    44,
      15,   234,    -1,    44,    13,   234,    -1,    44,    12,   234,
      -1,    44,    10,   234,    -1,    44,     9,   234,    -1,   234,
      14,    44,    -1,   234,    15,    44,    -1,   234,    13,    44,
      -1,   234,    12,    44,    -1,   234,    10,    44,    -1,   234,
       9,    44,    -1,    44,    14,   235,    -1,    44,    15,   235,
      -1,    44,    13,   235,    -1,    44,    12,   235,    -1,    44,
      10,   235,    -1,    44,     9,   235,    -1,   235,    14,    44,
      -1,   235,    15,    44,    -1,   235,    13,    44,    -1,   235,
      12,    44,    -1,   235,    10,    44,    -1,   235,     9,    44,
      -1,    44,    14,   236,    -1,   236,    14,    44,    -1,   234,
      23,    44,    -1,   234,    22,    44,    -1,   234,    21,    44,
      -1,   234,    19,    44,    -1,   234,    20,    44,    -1,   234,
      18,    44,    -1,    44,    23,   234,    -1,    44,    22,   234,
      -1,    44,    21,   234,    -1,    44,    19,   234,    -1,    44,
      20,   234,    -1,    44,    18,   234,    -1,    44,     8,   234,
      -1,    44,    24,   234,    -1,    44,    25,   234,    -1,   234,
       8,    44,    -1,   234,    24,    44,    -1,   234,    25,    44,
      -1,     6,    44,    -1,    44,    17,   234,    -1,    44,    16,
     234,    -1,   234,    17,    44,    -1,   234,    16,    44,    -1,
     242,    -1,   251,    -1,   246,    -1,   250,    -1,    45,    44,
      -1,    45,    44,    28,   231,    -1,   100,    44,    -1,   243,
      -1,   244,    -1,   245,    -1,   114,    37,    37,    28,    37,
      -1,   119,   117,    37,    37,    28,    37,    -1,   119,   117,
      37,    37,    -1,   122,    37,   120,   234,   121,    -1,    -1,
      -1,   113,    44,    28,    31,   247,   249,   248,    32,    -1,
      37,    -1,   249,    39,    37,    -1,   116,   117,    37,    28,
      37,   118,   118,    37,    -1,    73,    44,    -1,    74,    44,
      -1,    92,    44,    -1,   253,    -1,   254,    -1,   255,    -1,
     256,    -1,   257,    -1,   258,    -1,   259,    -1,   265,    -1,
     266,    -1,   267,    -1,   268,    -1,   269,    -1,   270,    -1,
     271,    -1,   272,    -1,   273,    -1,   274,    -1,   275,    -1,
     276,    -1,   277,    -1,   278,    -1,   279,    -1,   280,    -1,
     281,    -1,   282,    -1,   283,    -1,   284,    -1,   285,    -1,
     286,    -1,    46,    -1,    46,   231,    -1,    46,    77,    -1,
      47,    -1,    47,   231,    -1,    47,    77,    -1,    48,    -1,
      48,   231,    -1,    49,    -1,    49,   231,    -1,   109,    -1,
     109,   231,    -1,   110,    -1,   110,   231,    -1,    46,   122,
      37,    -1,    53,    52,    44,    -1,   111,    52,    44,    -1,
      50,   234,    -1,    51,    37,    37,   236,    -1,    54,    62,
      55,   234,    -1,    54,    62,    55,    52,    -1,    54,    55,
      -1,    54,    55,   233,    -1,    54,    55,   234,    -1,    54,
      55,   235,    -1,    54,    55,   236,    -1,    54,    62,    55,
      44,    -1,    54,    75,   234,    -1,    54,   115,    37,    -1,
      54,   116,   117,    37,    -1,    54,   116,   117,    37,   120,
     234,   121,    -1,    54,   122,    37,   120,   234,   121,    -1,
      54,   122,    37,   120,   121,    -1,    56,    57,   234,    -1,
      56,    57,    44,    -1,    14,    -1,    14,   234,    -1,    14,
     235,    -1,    14,   236,    -1,    15,    -1,    42,   234,    -1,
      13,    -1,    13,   234,    -1,    12,    -1,    12,   234,    -1,
      11,    -1,    11,   234,    -1,    10,    -1,    10,   234,    -1,
       9,    -1,     9,   234,    -1,     4,    -1,     3,    -1,    26,
      -1,    27,    -1,     7,    -1,    23,    -1,    22,    -1,    21,
      -1,    19,    -1,    20,    -1,    18,    -1,    23,   233,    -1,
      22,   233,    -1,    23,   234,    -1,    22,   234,    -1,    21,
     234,    -1,    19,   234,    -1,    20,   234,    -1,    18,   234,
      -1,    23,   235,    -1,    22,   235,    -1,    21,   235,    -1,
      19,   235,    -1,    20,   235,    -1,    18,   235,    -1,     8,
      -1,    24,    -1,    25,    -1,     6,    -1,    17,    -1,    16,
      -1,   260,    -1,    -1,    -1,    -1,    -1,   171,    40,   261,
     262,   171,   263,    41,   264,   171,    -1,    58,    -1,    59,
      -1,    60,    -1,    61,    62,    -1,    63,    -1,    64,    -1,
      66,   236,    -1,    67,    68,    -1,    69,    -1,    70,    62,
      -1,    71,    -1,    72,   234,    -1,    72,    75,    44,    -1,
      81,    75,    -1,    82,    75,    44,    -1,    83,    75,    44,
      44,    -1,    82,   123,    75,   234,    -1,    84,    62,    55,
     234,    -1,    84,    62,    55,    -1,    84,    96,    -1,    84,
     115,    37,    -1,    84,   116,   117,    37,    -1,    84,   122,
      37,   120,   234,   121,    -1,    84,   122,    37,   120,   121,
      -1,    91,    -1,    91,    44,    -1,    94,    76,    44,    -1,
      95,    -1,   102,    -1,   103,    77,    52,   234,    -1,   103,
      77,    52,   233,    -1,   103,    77,    52,   235,    -1,   103,
      77,    52,   236,    -1,   103,    77,   234,    -1,   104,    78,
     236,    -1,   105,    79,    80,    -1,   106,    79,   236,    -1,
     107,    79,    -1,   108,    -1,   112,    -1,   124,    37,    37,
      37,    -1,   122,    37,   118,   125,    -1,   126,    62,    -1,
     127,    -1,   128,    -1,   129,    -1,   130,    37,    -1,   130,
     163,    37,   164,    -1,   131,    37,    -1,   131,   163,    37,
     164,    -1,   132,    37,    37,    -1,   133,    37,    -1,   134,
      -1,   135,    37,    -1,   136,    37,    -1,   137,    37,    -1,
     138,    -1,   139,    -1,   140,    -1,   141,    -1,   142,    -1,
     143,    -1,   144,    -1,   145,    -1,   146,    37,    -1,   146,
     163,    37,   164,    -1,   147,    37,    -1,   147,   163,    37,
     164,    -1,   148,    37,    37,    -1,   149,    37,    -1,   150,
      -1,   151,    37,    -1,   152,    37,    -1,   153,    37,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,
     159,    -1,   160,    -1,   161,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   871,   871,   872,   875,   875,   880,   881,   884,   884,
     889,   892,   894,   896,   898,   900,   902,   904,   907,   908,
     911,   918,   925,   932,   965,   973,   983,   988,   993,  1004,
    1024,  1049,  1080,  1003,  1089,  1089,  1135,  1175,  1192,  1134,
    1212,  1226,  1243,  1211,  1264,  1264,  1269,  1273,  1272,  1342,
    1342,  1345,  1345,  1350,  1354,  1365,  1353,  1404,  1404,  1407,
    1407,  1416,  1421,  1426,  1432,  1431,  1451,  1461,  1467,  1450,
    1488,  1498,  1505,  1513,  1519,  1488,  1537,  1541,  1551,  1559,
    1569,  1537,  1589,  1602,  1611,  1617,  1626,  1636,  1588,  1652,
    1651,  1671,  1675,  1680,  1687,  1688,  1695,  1697,  1699,  1701,
    1703,  1705,  1710,  1720,  1723,  1738,  1752,  1768,  1784,  1787,
    1801,  1807,  1813,  1819,  1825,  1831,  1839,  1846,  1853,  1859,
    1865,  1871,  1877,  1885,  1894,  1902,  1909,  1917,  1925,  1929,
    1942,  1949,  1956,  1963,  1969,  1976,  1983,  1990,  1996,  2002,
    2008,  2014,  2018,  2031,  2056,  2063,  2067,  2138,  2178,  2215,
    2292,  2371,  2451,  2489,  2527,  2565,  2603,  2616,  2654,  2692,
    2720,  2748,  2776,  2804,  2807,  2818,  2829,  2840,  2851,  2863,
    2862,  2885,  2886,  2935,  2984,  3033,  3082,  3124,  3166,  3208,
    3250,  3292,  3334,  3376,  3418,  3460,  3502,  3544,  3586,  3628,
    3670,  3712,  3754,  3796,  3838,  3880,  3922,  3964,  4006,  4048,
    4090,  4154,  4218,  4263,  4308,  4353,  4398,  4443,  4488,  4533,
    4578,  4623,  4668,  4713,  4758,  4803,  4848,  4893,  4938,  4983,
    5028,  5065,  5110,  5155,  5200,  5247,  5252,  5257,  5262,  5269,
    5327,  5408,  5443,  5448,  5453,  5460,  5472,  5487,  5503,  5515,
    5523,  5514,  5537,  5545,  5548,  5573,  5597,  5620,  5646,  5651,
    5656,  5661,  5666,  5671,  5676,  5681,  5686,  5691,  5696,  5701,
    5706,  5711,  5716,  5721,  5726,  5731,  5736,  5741,  5746,  5751,
    5756,  5761,  5766,  5771,  5776,  5781,  5786,  5794,  5800,  5846,
    5857,  5863,  5909,  5920,  5926,  5972,  5978,  6024,  6029,  6075,
    6081,  6127,  6139,  6198,  6271,  6279,  6289,  6419,  6512,  6540,
    6552,  6564,  6576,  6588,  6763,  6782,  6796,  6809,  6823,  6833,
    6845,  6865,  6970,  6976,  6982,  6988,  6994,  7000,  7006,  7012,
    7018,  7024,  7030,  7036,  7042,  7048,  7054,  7060,  7066,  7072,
    7078,  7084,  7090,  7096,  7102,  7108,  7114,  7120,  7126,  7132,
    7142,  7152,  7158,  7164,  7170,  7176,  7182,  7188,  7194,  7200,
    7206,  7212,  7218,  7224,  7230,  7236,  7242,  7248,  7254,  7260,
    7265,  7276,  7284,  7292,  7264,  7310,  7318,  7324,  7332,  7345,
    7351,  7359,  7367,  7384,  7392,  7407,  7413,  7419,  7550,  7584,
    7703,  7927,  7948,  7979,  8012,  8020,  8034,  8047,  8057,  8069,
    8088,  8116,  8194,  8204,  8223,  8250,  8273,  8296,  8319,  8338,
    8360,  8393,  8410,  8427,  8437,  8447,  8458,  8468,  8486,  8492,
    8498,  8506,  8512,  8518,  8524,  8530,  8537,  8543,  8549,  8555,
    8561,  8567,  8573,  8579,  8585,  8591,  8597,  8603,  8609,  8615,
    8621,  8627,  8633,  8639,  8646,  8652,  8658,  8664,  8670,  8676,
    8682,  8688,  8694,  8700,  8706,  8712,  8718
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPDEC", "OPINC", "NEG", "OPBTNOT",
  "OPNOT", "OPAMP", "OPROOT", "OPPOWER", "OPMODULUS", "OPDIV", "OPTIMES",
  "OPPLUS", "OPMINUS", "OPBTSR", "OPBTSL", "OPGEQU", "OPGTR", "OPLEQU",
  "OPLSS", "OPNEQU", "OPEQU", "OPBTOR", "OPBTXOR", "OPAND", "OPOR",
  "OPEQUAL", "LEFTP", "RIGHTP", "LEFTB", "RIGHTB", "VOIDV", "BOOLEANV",
  "NUMBERV", "CHARACTERV", "STRINGV", "SEND", "COMMA", "OPQUES", "OPCOLON",
  "OPSUB", "OPSTR", "ID", "VAR", "PRINT", "PRINTLN", "EPRINT", "EPRINTLN",
  "END", "ASM", "TYPE", "READ", "LOAD", "LTYPE", "GOTO", "GTYPE", "ST",
  "PUSH", "POP", "TYPEOF", "RTYPE", "ATOC", "SWITCH", "CSWITCH", "CRASH",
  "VERSION", "VTYPE", "HALT", "MODT", "RETURN", "GOSUB", "SUB", "EVENT",
  "STYPE", "ATYPE", "CTYPE", "CMTYPE", "BFMODEC", "FMODEC", "UNREGISTER",
  "REGISTER", "REREGISTER", "STORE", "IF", "ELSE", "CASE", "CCASE",
  "DEFAULT", "CDEFAULT", "BREAK", "LABEL", "WHILE", "ADDRESSOF", "ADD2V",
  "STOREA", "DOWHILE", "DOFOR", "FOR", "FVAR", "FOREVER", "CONTINUE",
  "CHECK", "HCMNT", "FMODE", "FOPEN", "FCLOSE", "FEOF", "FPRINT",
  "FPRINTLN", "FREAD", "MEML", "ENUM", "ENUMV", "VTYPE2", "RANGE",
  "RTYPE2", "OPDOT", "RANGEV", "OPLSQ", "OPRSQ", "ARRAY", "BLANK",
  "PNFASM", "LENGTH", "DUP", "PBIN", "PPBIN", "PLIB", "PINCLUDE",
  "PIMPORT", "PDEFINE", "PMACRO", "PENDM", "PUNDEF", "PIFDEF", "PIFNDEF",
  "PELSE", "PENDIF", "PPDATE", "PPTIME", "PPLINE", "PPFILE", "PPCDATE",
  "PPCTIME", "PPINCLUDE", "PPIMPORT", "PPDEFINE", "PPMACRO", "PPENDM",
  "PPUNDEF", "PPIFDEF", "PPIFNDEF", "PPELSE", "PPENDIF", "PPPDATE",
  "PPPTIME", "PPPLINE", "PPPFILE", "PPPCDATE", "PPPCTIME", "\"\\n\"",
  "\"<\"", "\">\"", "$accept", "input", "line", "$@1", "statement", "$@2",
  "stmt", "expression_statement", "declaration_statement",
  "command_statement", "label_statement", "control_statement",
  "if_statement", "$@3", "$@4", "$@5", "$@6", "opt_else",
  "switch_statement", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12",
  "case_statements", "$@13", "case_statement", "$@14",
  "opt_default_statement", "case_statements2", "$@15", "case_statement2",
  "$@16", "$@17", "opt_default_statement2", "loop_statement", "$@18",
  "$@19", "while_loop", "$@20", "$@21", "$@22", "whileb_loop", "$@23",
  "$@24", "$@25", "$@26", "$@27", "for_loop", "$@28", "$@29", "$@30",
  "$@31", "$@32", "forb_loop", "$@33", "$@34", "$@35", "$@36", "$@37",
  "$@38", "forever_loop", "$@39", "statement_block", "statements",
  "expression", "void_expression", "boolean_expression",
  "number_expression", "character_expression", "string_expression",
  "id_expression", "relational_expression", "@40", "mixed_expression",
  "declaration", "variable_declaration", "enumv_declaration",
  "rangev_declaration", "array_declaration", "enum_declaration", "$@41",
  "$@42", "enum_strings", "range_declaration", "label_declaration",
  "command", "print_command", "read_command", "end_command", "asm_command",
  "load_command", "goto_command", "operator_command", "top_command",
  "$@43", "$@44", "$@45", "$@46", "st_command", "stack_command",
  "typeof_command", "rm_command", "crash_command", "version_command",
  "halt_command", "modt_command", "subroutine_command", "register_command",
  "store_command", "break_command", "address_command", "add2v_command",
  "continue_command", "check_command", "comment_command", "file_command",
  "meml_command", "pnfasm_command", "array_length_command", "dup_command",
  "pp_directive", "pp_statement", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   165,   166,   166,   168,   167,   167,   167,   170,   169,
     169,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     172,   173,   174,   175,   175,   175,   176,   176,   176,   178,
     179,   180,   181,   177,   182,   182,   184,   185,   186,   183,
     187,   188,   189,   183,   191,   190,   190,   193,   192,   194,
     194,   196,   195,   195,   198,   199,   197,   200,   200,   202,
     201,   201,   201,   201,   203,   201,   205,   206,   207,   204,
     209,   210,   211,   212,   213,   208,   215,   216,   217,   218,
     219,   214,   221,   222,   223,   224,   225,   226,   220,   228,
     227,   229,   230,   230,   231,   231,   231,   231,   231,   231,
     231,   231,   232,   232,   233,   233,   233,   233,   233,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   236,   236,   236,   236,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   238,   238,   238,   238,   238,   239,
     238,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   241,   241,   241,   241,   242,
     242,   242,   242,   242,   242,   243,   244,   244,   245,   247,
     248,   246,   249,   249,   250,   251,   251,   251,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   254,   254,   255,   256,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     258,   258,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     261,   262,   263,   264,   260,   265,   266,   266,   267,   268,
     268,   269,   270,   271,   272,   273,   273,   273,   274,   274,
     274,   274,   275,   275,   275,   275,   275,   275,   275,   276,
     276,   277,   278,   279,   280,   280,   280,   280,   280,   281,
     282,   282,   282,   282,   283,   284,   285,   286,   287,   287,
     287,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     3,     1,     1,     1,     0,
       0,     0,     0,    10,     0,     2,     0,     0,     0,    11,
       0,     0,     0,    11,     0,     2,     2,     0,     5,     0,
       3,     0,     2,     2,     0,     0,     6,     0,     3,     0,
       2,     1,     1,     1,     0,     2,     0,     0,     0,     8,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,    16,     0,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     2,     3,     3,     2,     2,
       2,     2,     3,     3,     3,     2,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     1,     3,     2,     3,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     1,     1,     1,     1,     2,
       4,     2,     1,     1,     1,     5,     6,     4,     5,     0,
       0,     8,     1,     3,     8,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     3,     3,     3,     2,     4,     4,     4,     2,     3,
       3,     3,     3,     4,     3,     3,     4,     7,     6,     5,
       3,     3,     1,     2,     2,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     0,     0,     9,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     2,     1,     2,     3,     2,     3,
       4,     4,     4,     3,     2,     3,     4,     6,     5,     1,
       2,     3,     1,     1,     4,     4,     4,     4,     3,     3,
       3,     3,     2,     1,     1,     4,     4,     2,     1,     1,
       1,     2,     4,     2,     4,     3,     2,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     2,     4,     3,     2,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     7,     3,     0,     6,    59,     5,    59,
     329,   328,   356,   332,   353,   326,   324,   322,   320,   318,
     312,   316,   358,   357,   338,   336,   337,   335,   334,   333,
     354,   355,   330,   331,     0,     8,   102,   104,   109,   129,
     142,    12,     0,     0,   146,     0,   277,   280,   283,   285,
       0,     0,     0,     0,     0,   365,   366,   367,     0,   369,
     370,     0,     0,     0,   373,     0,   375,     0,     0,     0,
       0,     0,     0,     0,    29,   389,     0,     0,   392,    82,
       0,    89,   393,     0,     0,     0,     0,     0,   403,   287,
     289,     0,   404,     0,     0,     0,     0,     0,     0,     0,
     408,   409,   410,     0,     0,     0,     0,   417,     0,     0,
       0,   421,   422,   423,   424,   425,   426,   427,   428,     0,
       0,     0,     0,   435,     0,     0,     0,   439,   440,   441,
     442,   443,   444,   445,   446,     9,    13,    14,    16,    15,
      11,    26,    27,    28,     0,    61,     0,    62,     0,    63,
      64,    17,     0,    94,    95,    96,    97,    98,    99,   100,
     101,     0,   225,   232,   233,   234,   227,   228,   226,     0,
     248,   249,   250,   251,   252,   253,   254,   359,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
      18,    19,    10,     0,     0,     0,     0,     0,     0,     0,
     146,   120,   139,   161,   118,   137,   159,     0,     0,     0,
       0,   220,   125,     0,     0,     0,     0,     0,   105,   148,
       0,   147,   327,   325,   323,   321,   319,     0,     0,     0,
     313,   314,   315,     0,     0,     0,   115,   156,     0,   346,
     352,   344,   350,   345,   351,   343,   349,     0,     0,   340,
     342,   348,   339,   341,   347,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     8,     0,   317,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,   229,
     279,     0,   278,   282,   281,   284,   286,   294,     0,     0,
     298,     0,     0,     0,     0,     0,     0,   368,     0,    59,
     371,   372,   374,     0,   376,   245,   246,   378,     0,     0,
       0,     0,   384,     0,     0,     0,     0,   390,   247,     0,
      59,   231,    59,     0,     0,     0,     0,   402,   288,   290,
       0,     0,     0,     0,     0,     0,     0,   407,   411,     0,
     413,     0,     0,   416,   418,   419,   420,   429,     0,   431,
       0,     0,   434,   436,   437,   438,   360,     0,    60,    71,
       0,    65,    20,     0,     0,   121,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   138,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   108,     0,     0,     0,     0,     0,
       0,   128,   141,   145,   163,   171,    93,    91,   214,   181,
     193,   180,   192,   179,   191,   178,   190,   176,   188,   200,
     177,   189,   222,   221,   213,   211,   212,   210,   209,   208,
     215,   216,   172,   174,     0,   291,     0,   292,     0,   299,
     300,   301,   302,     0,   304,   305,     0,     0,   311,   310,
       0,     0,   377,    24,    25,   379,     0,     0,   383,   385,
       0,     0,     0,   391,    83,    90,     0,   398,   399,   400,
     401,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   415,     0,     0,   433,   361,    66,    59,    77,   173,
     106,   175,   107,   217,   122,   187,   117,   186,   116,   114,
     185,   113,   184,   112,   182,   110,   183,   111,   224,   127,
     223,   126,   207,   169,   205,   167,   206,   168,   204,   166,
     203,   165,   202,   164,   218,   123,   219,   124,     0,     0,
       0,   199,   136,   198,   135,   134,   197,   133,   196,   132,
     194,   130,   195,   131,   201,   143,   158,   157,   155,   154,
     153,   151,   152,   149,   150,   230,   295,   303,   297,   296,
     306,     0,     0,    40,   381,   380,   382,   386,     0,     0,
       0,   395,   394,   396,   397,   239,     0,     0,   237,   406,
       0,   405,   412,   414,   430,   432,    59,    59,     0,    59,
     170,     0,   309,     0,    36,     0,   388,     0,    30,     0,
       0,   235,     0,     0,   238,   362,    67,    72,     0,     0,
     308,    44,    51,   387,    59,    84,   242,   240,     0,   236,
       0,     0,     0,    78,   307,    37,     0,    41,     0,    31,
      59,     0,     0,     0,   363,    68,    73,    59,     0,    49,
      46,    45,    54,    57,    53,    52,    34,     0,   243,   241,
     244,    59,    59,    59,     0,    47,     0,    38,    59,     0,
      42,    59,    32,    85,   364,    69,    74,    79,     0,    59,
       0,     0,    59,     0,    35,    33,    59,     0,    59,    59,
      50,    39,    55,    58,    43,     0,    75,    80,    48,    59,
      86,     0,    56,    59,    59,    87,    81,     0,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,   274,     7,   135,   136,   137,   138,
     139,   140,   141,   336,   674,   706,   735,   722,   142,   671,
     699,   730,   655,   703,   733,   685,   686,   700,   728,   717,
     687,   688,   704,   718,   749,   720,   143,   144,   381,   378,
     647,   681,   712,   145,   146,   547,   682,   713,   737,   147,
     148,   649,   697,   738,   751,   149,   340,   630,   690,   736,
     753,   757,   150,   342,   151,   275,   152,   153,   154,   155,
     156,   157,   158,   159,   650,   160,   161,   162,   163,   164,
     165,   166,   660,   692,   677,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   545,   646,   680,   711,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
    -136,   764,  -136,  -136,  -136,  -135,     8,   924,  -136,   924,
     585,   585,   481,   628,   447,   604,   604,   604,   604,   604,
    1246,   619,  -136,  -136,  1311,  1311,  1311,  1311,  1303,  1303,
    -136,  -136,  -136,  -136,   569,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,   604,    86,  1278,    11,    25,   216,   569,   569,
     604,    29,    39,   240,    37,  -136,  -136,  -136,    56,  -136,
      93,    98,    86,    62,  -136,   129,  -136,   460,   127,   164,
     153,   -56,   162,   114,  -136,   177,   182,   170,  -136,  -136,
     204,  -136,  -136,   179,   169,   178,   188,   189,  -136,   569,
     569,   206,  -136,   218,   229,   155,   157,   234,   260,   239,
    -136,  -136,  -136,   -32,   -28,   266,   267,  -136,   268,   274,
     276,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   -27,
     -19,   279,   280,  -136,   281,   283,   284,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,   282,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,   230,  -136,   228,  -136,   231,  -136,
    -136,  -136,   294,  -136,   151,  1466,  1543,   322,  1446,  -136,
    -136,   309,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   312,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,   282,   585,   585,   604,   447,   447,   619,   585,
    -136,  1394,  1433,  1245,  1394,  1433,  1245,   604,   604,   604,
     604,  -136,  1394,   447,   447,   628,   447,   628,   176,  1245,
     447,  1245,  1489,  1489,  1489,  1489,  1489,  1311,  1311,  1246,
    1489,  1556,   339,   619,   619,   619,  1394,  1245,  1311,  1489,
    1556,  1489,  1556,  1489,  1556,  1489,  1556,    67,  1303,   176,
    1489,  1556,   176,  1489,  1556,   481,  1507,   327,     9,  1340,
    1411,    23,  1386,   328,   100,   332,  1489,    86,   339,   604,
    1311,  1311,  1311,  1311,  1246,  1311,   604,   604,   604,   604,
     604,   604,   604,   604,   604,   604,    67,    67,  -136,   340,
    -136,   336,  -136,  -136,  -136,  -136,  -136,  1489,   343,   333,
    1233,   326,   604,   345,   286,   367,   655,  -136,   569,   924,
     339,  -136,  -136,   361,  1489,   375,   376,  -136,   374,   344,
     377,   365,  -136,   387,   308,   404,   413,  -136,  -136,   399,
     924,  -136,   924,   113,    86,   366,    86,  -136,  -136,  -136,
     401,   428,   422,   430,   441,    44,   442,  -136,  -136,   443,
    -136,   445,   451,  -136,  -136,  -136,  -136,  -136,   455,  -136,
     463,   476,  -136,  -136,  -136,  -136,  -136,   436,  -136,  -136,
     468,  -136,  -136,    36,    49,  -136,  -136,   663,   671,   690,
     604,   707,  1083,  1087,  1091,  1104,  1126,  1134,  1139,  1147,
    1169,  1182,  1186,  1190,  1203,  -136,  -136,   325,   331,    48,
     334,   454,   457,   550,     5,  -136,  -136,   447,   447,   447,
     447,   447,   447,   447,   447,   447,  -136,  -136,  1363,  1424,
     604,   604,   604,   604,   604,   604,   604,   604,   604,   604,
     604,    48,    48,    48,    48,    48,    48,   163,    67,    67,
      27,    86,    67,  -136,  -136,   471,   479,   480,   483,   485,
     486,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  1489,  1489,
    1556,  1489,  1556,  1489,  1556,  1489,  1556,  1489,  1556,   339,
    1489,  1556,  1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,
    1489,  1489,   176,   176,   569,  -136,    86,  -136,  1233,   176,
    1489,  1556,   339,   505,  1489,  -136,   494,   412,  -136,  1489,
     506,    84,  -136,  -136,  -136,  -136,   604,   493,   604,  -136,
     502,   431,   569,  -136,   282,   282,  1233,  1489,   339,  -136,
     339,  -136,   512,   520,   522,   515,   433,   604,   518,   396,
     402,  -136,   405,   406,  -136,  -136,  -136,   924,  -136,  -136,
     544,  -136,  -136,  -136,  1526,  -136,  1526,  -136,  1526,   423,
    -136,   423,  -136,   423,  -136,   109,  -136,   109,  -136,    51,
    -136,    51,  -136,  1489,  -136,  1489,  -136,  1489,  -136,  1489,
    -136,  1489,  -136,  1489,  -136,  -136,  -136,  -136,    48,    48,
      48,  -136,  1433,  -136,  1433,   183,  -136,   183,  -136,   183,
    -136,  -136,  -136,  -136,  -136,  -136,  1245,  1245,   146,   146,
     146,   185,   185,   547,  -136,  -136,   339,  -136,  -136,  1489,
     458,   134,   549,  -136,  1489,  -136,  1489,  -136,   203,   555,
     491,   176,  1489,  1556,   339,  -136,   559,   560,   571,  -136,
      96,  -136,  -136,  -136,  -136,  -136,   924,   924,   -14,   924,
    -136,   604,  -136,   142,  -136,   570,  -136,   171,  -136,   580,
     574,  -136,   497,   579,  -136,   282,   282,  -136,   103,   398,
    -136,  -136,  -136,  -136,   924,  -136,  -136,   589,   500,  -136,
     600,   612,   601,  -136,  -136,   557,   557,   558,   558,   282,
     924,   608,   620,   618,  -136,  -136,  -136,   924,   569,   567,
    -136,  -136,  -136,   578,  -136,  -136,   587,   130,  -136,  -136,
    -136,   924,   924,   924,   154,  -136,   623,  -136,   924,   630,
    -136,   924,  -136,  -136,   282,   282,   282,  -136,   635,   924,
     647,   202,   924,   648,   282,  -136,   924,   652,   924,   924,
     282,  -136,  -136,   282,  -136,   187,  -136,   282,   282,   924,
    -136,   653,   282,   924,   924,   282,   282,   657,  -136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,   659,  -136,    -9,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,    -1,  -136,  -136,
    -136,  -136,     1,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,   417,   -45,   661,    69,    -4,
      61,    30,   338,  -136,  -136,   667,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
     202,   302,   304,   305,   306,   358,   211,   214,   222,   360,
     367,   232,   233,   234,   235,   236,   240,   246,   369,   328,
     249,   251,   253,   255,   260,   263,   376,     8,   203,   204,
     269,   265,   225,   207,   277,   383,   384,   414,   276,   454,
     208,   451,    40,   257,   348,   349,   307,     9,    43,   604,
     242,   588,   589,   463,    34,   299,   257,   463,    36,    37,
      38,    39,    40,   324,   271,   452,   308,   329,    43,   266,
      37,   212,   215,   278,   257,   439,   440,   590,   452,   667,
     549,   241,   228,    37,    39,   250,   252,   254,   256,   261,
     264,   309,   320,   551,   316,   270,   452,   259,   262,   385,
     386,    37,   300,   268,   430,   431,   432,   390,   433,   434,
     435,   436,   437,   438,   623,   277,   217,   218,   317,   205,
     439,   440,   318,    40,   376,   437,   438,   319,   219,    43,
     321,   359,   -92,   439,   440,   361,   368,   217,   218,     9,
     205,   683,   220,   376,   370,   385,   386,   301,    38,   219,
     430,   431,   432,   390,   433,   434,   435,   436,   437,   438,
     422,   423,   536,   220,   537,   526,   439,   440,   723,    38,
     376,   325,   424,   425,   385,   386,   331,   383,   384,   430,
     431,   432,   390,   433,   434,   435,   436,   437,   438,   448,
     449,   322,   727,   454,   376,   439,   440,   445,   446,   211,
     214,   222,   448,   449,   246,   428,   217,   218,   326,   205,
     332,   424,   425,   211,   214,   246,   428,   664,   219,   203,
     204,   337,   265,   225,   207,   750,   338,   376,   327,   333,
     334,   208,   220,   211,   214,   428,   335,   330,    38,   211,
     214,   428,   376,   742,   428,    34,   339,   344,   341,    36,
      37,    38,    39,    40,   428,   652,   343,   345,   350,    43,
     266,   222,   351,   670,   212,   215,   352,   346,   347,   450,
     429,   355,   353,   510,   354,   468,   469,   471,   473,   475,
     477,   480,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   673,   303,   228,   310,   447,   356,   212,   215,
     429,   357,   311,   362,   363,   364,   500,   450,   504,   429,
     511,   365,   509,   366,   479,   312,   371,   372,   373,   429,
     374,   375,   376,   377,   656,   379,   228,   447,   588,   589,
     380,   524,   382,   525,   588,   589,   414,   588,   589,   527,
     502,   470,   472,   474,   476,   478,   481,   426,   213,   216,
     427,   229,   231,   451,   590,   313,   314,   453,   465,   247,
     590,    39,   315,   590,   467,   492,   493,    39,   494,   591,
      39,   501,   272,   495,   528,   593,   530,   497,   596,   499,
     496,   503,   505,   554,   556,   558,   559,   561,   563,   565,
     567,   569,   571,   573,   575,   577,   579,   581,   583,   585,
     587,   385,   386,   506,   507,   512,   430,   431,   432,   390,
     433,   434,   435,   436,   437,   438,   513,   514,   515,   516,
     518,   517,   439,   440,   519,   520,   554,   556,   558,   561,
     563,   565,   567,   569,   571,   585,   587,   435,   436,   437,
     438,   521,   522,   523,   605,   531,   529,   439,   440,   615,
     223,   224,   550,   552,   206,   207,   532,   588,   589,   533,
     588,   589,   226,   217,   218,   546,   205,   534,   592,   594,
     595,   597,   599,   601,   603,   219,   230,   629,   535,   538,
     539,   605,   540,   590,   217,   218,   590,   205,   541,   220,
      39,   210,   542,    39,   428,    38,   219,   548,   598,   619,
     543,   600,   592,   594,   597,   599,   601,   603,   217,   218,
     220,   205,   624,   544,   626,   572,    38,   550,   552,   684,
     219,   447,   632,   574,   576,   221,   616,   578,   450,   580,
     582,   620,   621,   640,   220,   323,   622,   625,   648,   627,
      38,   213,   216,   635,   229,   231,   247,   272,   636,   617,
     637,   628,   638,   588,   589,   641,   634,   618,   639,   429,
     642,   213,   216,   229,   247,   272,   643,   447,   272,   644,
     645,   449,   203,   204,   425,   265,   225,   207,   651,   590,
     654,   213,   216,   272,   208,   658,    39,   633,   203,   204,
     659,   205,   206,   207,   602,   631,   661,   662,    34,   663,
     208,   672,    36,    37,    38,    39,    40,   217,   218,   675,
     205,   676,    43,   266,   209,   678,   679,   653,   693,   219,
      38,    39,   243,   244,   657,   205,   206,   207,   691,   210,
     696,   223,   224,   220,   208,   225,   207,   665,   666,    38,
     668,   694,   695,   226,   698,   708,   702,   669,   245,   212,
     215,   429,   709,   715,    38,   710,   716,   227,   217,   218,
       6,   205,    37,   210,   729,   689,   217,   218,   719,   205,
     219,   732,   210,   721,   217,   218,   739,   205,   219,   741,
     744,   707,   746,   754,   220,   701,   219,   758,   714,   705,
      38,   466,   220,   217,   218,   267,   205,     0,    38,   508,
     220,   273,   724,   725,   726,   219,    38,   553,     0,   731,
     217,   218,   734,   205,     0,   555,     0,     0,     0,   220,
     740,     0,   219,   743,     0,    38,     0,   745,     0,   747,
     748,     0,     0,     0,   557,     0,   220,     0,     0,     0,
     752,     0,    38,     0,   755,   756,     0,     0,     0,     0,
       0,   560,     0,     0,     0,   606,   607,   608,   609,   610,
     611,   612,   613,   614,     2,     3,     0,    -8,    -8,     0,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,     0,    -8,     0,    -8,     0,    -8,    -8,    -8,
      -8,    -8,    -8,     0,     0,     0,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,     0,
      -8,     0,    -8,    -8,    -8,    -8,     0,    -8,    -8,    -8,
      -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,     0,
       0,     0,     0,     0,     0,    -8,    -8,    -8,    -8,    -8,
       0,     0,     0,     0,     0,    -8,    -8,    -8,    -8,    -8,
       0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,     0,
      -8,     0,     0,    -8,     0,     0,    -8,     0,    -8,     0,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -4,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,    34,     0,    35,     0,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,    52,    53,     0,
      54,     0,    55,    56,    57,    58,     0,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,    75,    76,     0,    77,    78,
       0,   -70,    79,   -76,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,     0,     0,    96,     0,     0,    97,     0,    98,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   217,   218,     0,   205,
     217,   218,     0,   205,   217,   218,     0,   205,   219,     0,
       0,     0,   219,     0,     0,     0,   219,   217,   218,     0,
     205,     0,   220,     0,     0,     0,   220,     0,    38,   219,
     220,     0,    38,     0,     0,     0,    38,   562,     0,   217,
     218,   564,   205,   220,     0,   566,     0,   217,   218,    38,
     205,   219,   217,   218,     0,   205,     0,     0,   568,   219,
     217,   218,     0,   205,   219,   220,     0,     0,     0,     0,
       0,    38,   219,   220,     0,     0,     0,     0,   220,    38,
     570,     0,   217,   218,    38,   205,   220,     0,   572,     0,
       0,     0,    38,   574,   219,   217,   218,     0,   205,   217,
     218,   576,   205,   217,   218,     0,   205,   219,   220,     0,
       0,   219,     0,     0,    38,   219,   217,   218,     0,   205,
       0,   220,     0,   578,     0,   220,     0,    38,   219,   220,
       0,    38,     0,     0,     0,    38,   580,     0,     0,     0,
     582,     0,   220,     0,   584,     0,   237,   238,    38,   205,
     257,     0,     0,     0,     0,     0,     0,   586,   219,   237,
     238,     0,   205,     0,   417,   418,   419,   420,   421,   422,
     423,   219,   498,     0,     0,     0,     0,    37,    38,    39,
      40,   424,   425,     0,     0,   239,    43,     0,     0,     0,
       0,    38,    39,    40,     0,     0,   279,   280,   281,    43,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   237,   238,     0,   205,
     257,     0,     0,     0,   237,   238,     0,   205,   219,   298,
       0,     0,     0,     0,     0,     0,   219,     0,     0,     0,
       0,     0,   258,     0,     0,     0,     0,    37,    38,    39,
     248,     0,     0,   385,   386,     0,    38,    39,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   455,   456,
     457,   458,   459,   460,   403,   404,   385,   386,     0,     0,
     461,   430,   431,   432,   390,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,     0,     0,   439,   440,   415,
     416,     0,     0,   461,     0,   417,   418,   419,   420,   421,
     422,   423,   430,   431,   432,   390,   433,   434,   435,   436,
     437,   438,   424,   425,   405,   406,   464,     0,   439,   440,
     407,   408,   409,   410,   411,   412,   413,   405,   406,     0,
       0,     0,     0,   441,   442,   409,   443,   444,   445,   446,
       0,   462,   441,   442,   409,   443,   444,   445,   446,   415,
     416,     0,     0,     0,   462,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,     0,     0,     0,   385,
     386,     0,   424,   425,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   385,   386,     0,     0,     0,   430,   431,   432,
     390,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,     0,     0,   439,   440,   279,   280,   281,     0,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   431,   432,   390,   433,   434,
     435,   436,   437,   438,     0,     0,   405,   406,     0,     0,
     439,   440,   407,   408,   409,   410,   411,   412,   413,   405,
     406,     0,     0,     0,     0,   441,   442,   409,   443,   444,
     445,   446
};

static const yytype_int16 yycheck[] =
{
       9,    46,    47,    48,    49,    37,    10,    11,    12,    37,
      37,    15,    16,    17,    18,    19,    20,    21,    37,    75,
      24,    25,    26,    27,    28,    29,    40,   162,     3,     4,
      34,     6,     7,     8,    29,    26,    27,    14,    42,    30,
      15,    14,    37,     7,    89,    90,    50,    39,    43,    44,
      20,     3,     4,    30,    29,    44,     7,    30,    33,    34,
      35,    36,    37,    67,    34,    29,    37,   123,    43,    44,
      34,    10,    11,    43,     7,    24,    25,    29,    29,    93,
      44,    20,    13,    34,    36,    24,    25,    26,    27,    28,
      29,    52,    62,    44,    57,    34,    29,    28,    29,     3,
       4,    34,    77,    34,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    30,    29,     3,     4,    62,     6,
      24,    25,    29,    37,    40,    16,    17,    29,    15,    43,
      68,   163,    32,    24,    25,   163,   163,     3,     4,    39,
       6,    38,    29,    40,   163,     3,     4,   122,    35,    15,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      14,    15,   118,    29,   120,    52,    24,    25,    38,    35,
      40,    44,    26,    27,     3,     4,    62,    26,    27,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    26,
      27,    62,    38,    30,    40,    24,    25,    14,    15,   203,
     204,   205,    26,    27,   208,   209,     3,     4,    44,     6,
      96,    26,    27,   217,   218,   219,   220,   121,    15,     3,
       4,    44,     6,     7,     8,    38,    44,    40,    75,   115,
     116,    15,    29,   237,   238,   239,   122,    75,    35,   243,
     244,   245,    40,    41,   248,    29,    76,    78,    44,    33,
      34,    35,    36,    37,   258,   121,    77,    79,    52,    43,
      44,   265,    44,   121,   203,   204,    37,    79,    79,   239,
     209,    37,   117,   318,   117,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   121,    77,   225,    55,   227,    37,   237,   238,
     239,    62,    62,    37,    37,    37,   310,   277,   312,   248,
     319,    37,   316,    37,   284,    75,    37,    37,    37,   258,
      37,    37,    40,    93,   121,    97,   257,   258,     3,     4,
      99,   340,    38,   342,     3,     4,    14,     3,     4,   343,
     310,   280,   281,   282,   283,   284,   285,    38,    10,    11,
      38,    13,    14,    14,    29,   115,   116,    30,    30,    21,
      29,    36,   122,    29,    32,   296,   297,    36,    28,    44,
      36,   310,    34,    37,   344,    44,   346,    44,    44,   310,
      37,    55,    37,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,     3,     4,   117,    37,    44,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    41,    41,    44,    75,
      55,    44,    24,    25,    37,   117,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,    14,    15,    16,
      17,    37,    29,    44,   414,    44,    80,    24,    25,   494,
       3,     4,   383,   384,     7,     8,    28,     3,     4,    37,
       3,     4,    15,     3,     4,    29,     6,    37,   407,   408,
     409,   410,   411,   412,   413,    15,    29,   522,    37,    37,
      37,   451,    37,    29,     3,     4,    29,     6,    37,    29,
      36,    44,    37,    36,   498,    35,    15,    29,    44,   503,
      37,    44,   441,   442,   443,   444,   445,   446,     3,     4,
      29,     6,   516,    37,   518,    44,    35,   448,   449,   121,
      15,   452,   526,    44,    44,    44,   496,    44,   498,    44,
      44,    37,   120,   537,    29,    75,    30,    44,   547,    37,
      35,   203,   204,    31,   206,   207,   208,   209,    28,    44,
      28,   120,    37,     3,     4,    37,   526,    52,   125,   498,
     164,   223,   224,   225,   226,   227,   164,   498,   230,   164,
     164,    27,     3,     4,    27,     6,     7,     8,   120,    29,
      31,   243,   244,   245,    15,    30,    36,   526,     3,     4,
      99,     6,     7,     8,    44,   526,    37,    37,    29,    28,
      15,    31,    33,    34,    35,    36,    37,     3,     4,    29,
       6,    37,    43,    44,    29,   118,    37,   621,   118,    15,
      35,    36,     3,     4,   628,     6,     7,     8,    39,    44,
      29,     3,     4,    29,    15,     7,     8,   646,   647,    35,
     649,    41,    30,    15,    87,    37,    88,   651,    29,   588,
     589,   590,    32,   698,    35,    37,    89,    29,     3,     4,
       1,     6,    34,    44,    41,   674,     3,     4,    90,     6,
      15,    41,    44,    86,     3,     4,    41,     6,    15,    32,
      32,   690,    30,    30,    29,   686,    15,    30,   697,   688,
      35,   274,    29,     3,     4,    34,     6,    -1,    35,    44,
      29,    34,   711,   712,   713,    15,    35,    44,    -1,   718,
       3,     4,   721,     6,    -1,    44,    -1,    -1,    -1,    29,
     729,    -1,    15,   732,    -1,    35,    -1,   736,    -1,   738,
     739,    -1,    -1,    -1,    44,    -1,    29,    -1,    -1,    -1,
     749,    -1,    35,    -1,   753,   754,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,   417,   418,   419,   420,   421,
     422,   423,   424,   425,     0,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    31,    -1,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    -1,
      56,    -1,    58,    59,    60,    61,    -1,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,    -1,    -1,   119,    -1,    -1,   122,    -1,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    31,    -1,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    -1,
      56,    -1,    58,    59,    60,    61,    -1,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    91,    92,    -1,    94,    95,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,    -1,    -1,   119,    -1,    -1,   122,    -1,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,     3,     4,    -1,     6,
       3,     4,    -1,     6,     3,     4,    -1,     6,    15,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    15,     3,     4,    -1,
       6,    -1,    29,    -1,    -1,    -1,    29,    -1,    35,    15,
      29,    -1,    35,    -1,    -1,    -1,    35,    44,    -1,     3,
       4,    44,     6,    29,    -1,    44,    -1,     3,     4,    35,
       6,    15,     3,     4,    -1,     6,    -1,    -1,    44,    15,
       3,     4,    -1,     6,    15,    29,    -1,    -1,    -1,    -1,
      -1,    35,    15,    29,    -1,    -1,    -1,    -1,    29,    35,
      44,    -1,     3,     4,    35,     6,    29,    -1,    44,    -1,
      -1,    -1,    35,    44,    15,     3,     4,    -1,     6,     3,
       4,    44,     6,     3,     4,    -1,     6,    15,    29,    -1,
      -1,    15,    -1,    -1,    35,    15,     3,     4,    -1,     6,
      -1,    29,    -1,    44,    -1,    29,    -1,    35,    15,    29,
      -1,    35,    -1,    -1,    -1,    35,    44,    -1,    -1,    -1,
      44,    -1,    29,    -1,    44,    -1,     3,     4,    35,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    44,    15,     3,
       4,    -1,     6,    -1,     9,    10,    11,    12,    13,    14,
      15,    15,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    26,    27,    -1,    -1,    29,    43,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,     8,     9,    10,    43,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     3,     4,    -1,     6,
       7,    -1,    -1,    -1,     3,     4,    -1,     6,    15,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      29,    -1,    -1,     3,     4,    -1,    35,    36,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     3,     4,    -1,    -1,
      30,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,     3,
       4,    -1,    -1,    30,    -1,     9,    10,    11,    12,    13,
      14,    15,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    26,    27,     3,     4,    30,    -1,    24,    25,
       9,    10,    11,    12,    13,    14,    15,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    30,     9,    10,    11,    12,    13,    14,    15,     3,
       4,    -1,    -1,    -1,    30,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    26,    27,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     3,     4,    -1,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,     3,     4,    -1,    -1,
      24,    25,     9,    10,    11,    12,    13,    14,    15,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   166,     0,     1,   167,   168,   169,   170,   162,    39,
       3,     4,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    29,    31,    33,    34,    35,    36,
      37,    38,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    53,    54,    56,    58,    59,    60,    61,    63,
      64,    65,    66,    67,    69,    70,    71,    72,    73,    74,
      81,    82,    83,    84,    85,    91,    92,    94,    95,    98,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   119,   122,   124,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   171,   172,   173,   174,   175,
     176,   177,   183,   201,   202,   208,   209,   214,   215,   220,
     227,   229,   231,   232,   233,   234,   235,   236,   237,   238,
     240,   241,   242,   243,   244,   245,   246,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   171,     3,     4,     6,     7,     8,    15,    29,
      44,   234,   235,   237,   234,   235,   237,     3,     4,    15,
      29,    44,   234,     3,     4,     7,    15,    29,   233,   237,
      29,   237,   234,   234,   234,   234,   234,     3,     4,    29,
     234,   235,   236,     3,     4,    29,   234,   237,    29,   234,
     235,   234,   235,   234,   235,   234,   235,     7,    29,   233,
     234,   235,   233,   234,   235,     6,    44,   232,   233,   234,
     235,   236,   237,   240,   169,   230,   234,    29,   236,     8,
       9,    10,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    41,    44,
      77,   122,   231,    77,   231,   231,   231,   234,    37,    52,
      55,    62,    75,   115,   116,   122,    57,    62,    29,    29,
     236,    68,    62,    75,   234,    44,    44,    75,    75,   123,
      75,    62,    96,   115,   116,   122,   178,    44,    44,    76,
     221,    44,   228,    77,    78,    79,    79,    79,   231,   231,
      52,    44,    37,   117,   117,    37,    37,    62,    37,   163,
      37,   163,    37,    37,    37,    37,    37,    37,   163,    37,
     163,    37,    37,    37,    37,    37,    40,    93,   204,    97,
      99,   203,    38,    26,    27,     3,     4,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     3,     4,     9,    10,    11,
      12,    13,    14,    15,    14,     3,     4,     9,    10,    11,
      12,    13,    14,    15,    26,    27,    38,    38,   234,   235,
       8,     9,    10,    12,    13,    14,    15,    16,    17,    24,
      25,     9,    10,    12,    13,    14,    15,   233,    26,    27,
     236,    14,    29,    30,    30,    18,    19,    20,    21,    22,
      23,    30,    30,    30,    30,    30,   230,    32,   234,   234,
     235,   234,   235,   234,   235,   234,   235,   234,   235,   236,
     234,   235,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   233,   233,    28,    37,    37,    44,    29,   233,
     234,   235,   236,    55,   234,    37,   117,    37,    44,   234,
     231,   171,    44,    41,    41,    44,    75,    44,    55,    37,
     117,    37,    29,    44,   171,   171,    52,   234,   236,    80,
     236,    44,    28,    37,    37,    37,   118,   120,    37,    37,
      37,    37,    37,    37,    37,   261,    29,   210,    29,    44,
     233,    44,   233,    44,   234,    44,   234,    44,   234,   234,
      44,   234,    44,   234,    44,   234,    44,   234,    44,   234,
      44,   234,    44,   234,    44,   234,    44,   234,    44,   234,
      44,   234,    44,   234,    44,   234,    44,   234,     3,     4,
      29,    44,   235,    44,   235,   235,    44,   235,    44,   235,
      44,   235,    44,   235,    44,   236,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   231,   236,    44,    52,   234,
      37,   120,    30,    30,   234,    44,   234,    37,   120,   231,
     222,   233,   234,   235,   236,    31,    28,    28,    37,   125,
     234,    37,   164,   164,   164,   164,   262,   205,   171,   216,
     239,   120,   121,   234,    31,   187,   121,   234,    30,    99,
     247,    37,    37,    28,   121,   171,   171,    93,   171,   234,
     121,   184,    31,   121,   179,    29,    37,   249,   118,    37,
     263,   206,   211,    38,   121,   190,   191,   195,   196,   171,
     223,    39,   248,   118,    41,    30,    29,   217,    87,   185,
     192,   192,    88,   188,   197,   197,   180,   171,    37,    32,
      37,   264,   207,   212,   171,   231,    89,   194,   198,    90,
     200,    86,   182,    38,   171,   171,   171,    38,   193,    41,
     186,   171,    41,   189,   171,   181,   224,   213,   218,    41,
     171,    32,    41,   171,    32,   171,    30,   171,   171,   199,
      38,   219,   171,   225,    30,   171,   171,   226,    30
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
        case 3:

/* Line 1455 of yacc.c  */
#line 872 "pnfha.ypp"
    { ASTNode start("START"); tree.add_node(start); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 875 "pnfha.ypp"
    {
	 ASTNode line("line");
         tree.add_node(line);
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 881 "pnfha.ypp"
    { yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 884 "pnfha.ypp"
    {
		 ASTNode statement("statement");
  		 tree.add_node(statement);
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 892 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1; 
		    	                    statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 894 "pnfha.ypp"
    { ASTNode stmt("stmt"); stmt.conprint("VOID TVOID 0V\n"); tree.add_node(stmt); statementoutcount.insert(); 
                         statementoutcount[statementoutcount.length() - 1] = outcount - 1; statementlineno.insert(); statementlineno[statementlineno.length() - 1]                          = yylineno; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 896 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					  statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 898 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					   statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 900 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 902 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				       statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 904 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; inblock = true;
				   ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 912 "pnfha.ypp"
    {
			 ASTNode expression_statement("expression_statement");
			 tree.add_node(expression_statement);
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 919 "pnfha.ypp"
    {
			 ASTNode declaration_statement("declaration_statement");
			 tree.add_node(declaration_statement);
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 926 "pnfha.ypp"
    {
			 ASTNode command_statement("command_statement");
			 tree.add_node(command_statement);
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 933 "pnfha.ypp"
    {
			 ASTNode label_statement("label_statement");

			 bool declared = false;
			 String str;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  str = labelTable[i].name();
			  if ((yyvsp[(1) - (2)]).to_string().get().getString() == labelTable[i].name().getString())
			  {
			   declared = true;
			   if (labelTable[i].declared() == true)
 			   {
			    str += " implemented already.";
			    yyerror(str.getString().c_str());
			   }
			   else
			   {
                            labelTable[i].declared(true);
			    label_statement.conprint("LBL TVOID 0V\n");
			   }
			  }
			 }

			 if (!declared)
			 {	  
			  str += " not declared.";
			  yyerror(str.getString().c_str());
			 }

			 tree.add_node(label_statement);
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 966 "pnfha.ypp"
    {
			 ASTNode label_statement("label_statement");

			 label_statement.conprint("LBL TVOID 0V\n");

			 tree.add_node(label_statement);
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 974 "pnfha.ypp"
    {
			 ASTNode label_statement("label_statement");

			 label_statement.conprint("ELBL TVOID 0V\n");

			 tree.add_node(label_statement);
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 984 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");
			 tree.add_node(control_statement);
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 989 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");
			 tree.add_node(control_statement);
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 994 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");

			 breakinforever = false;

			 tree.add_node(control_statement);
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1004 "pnfha.ypp"
    {
			 inif = true;
			 ++ifcounter;
			 ifcounternum.from_long(ifcounter);
                         String nname = (String)"if_statementp1_" + ifcounternum;
			 ASTNode if_statementp1(nname);
			 ifgoto = ifcounter < 2 ? ifcounter : ifcounter + 1;

			 String if_body_str = "if_body_";
			 if_body_str += ifgoto - 1;

			 labelTable.insert();
			 labelTable[labelTable.length() - 1].name(if_body_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 2);

			 if_statementp1.conprint("; Begin if :%u\n", ifcounter);

			 tree.add_node(if_statementp1);		
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1024 "pnfha.ypp"
    {
			 String nname = (String)"if_statementp2_" + ifcounternum;
			 ASTNode if_statementp2(nname);


			 PNF_Boolean b(exptruth);
			 String str = b.get();
			 if_statementp2.conprint("ALOAD TBOOLEAN %s\n", str.getString().c_str());
			 if_statementp2.conprint("CGOTOL TSTRING \"iftrue_%u\"\n", ifcounter);
			 if_statementp2.conprint("GOTOL TSTRING \"iffalse_or_end_%u\"\n", ifcounter);

			 if_statementp2.conprint("\n\n; Begin if code :%u\n", ifcounter);
			 if_statementp2.conprint("LBL TSTRING \"iftrue_%u\"\n", ifcounter);

			 labelTable.insert();
			 String iftrue_str_num;
			 iftrue_str_num.from_long(ifcounter);
			 String iftrue_str = (String)"iftrue_" + iftrue_str_num;
			 labelTable[labelTable.length() - 1].name(iftrue_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 2);


			 tree.add_node(if_statementp2);
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1049 "pnfha.ypp"
    {
			 String nname = (String)"if_statementp3_" + ifcounternum;
			 ASTNode if_statementp3(nname);
			 // Code for if will be inserted here...
			 if_statementp3.conprint("; End if code :%u\n", ifcounter);
			 ifbegin = outcount;

			 String after_if_str = "after_if_";
 			 after_if_str += ifgoto - 1;

			 labelTable.insert();
			 labelTable[labelTable.length() - 1].name(after_if_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 2);
			 endifbegin = outcount - 1;

			 if_statementp3.conprint("GOTOL TSTRING \"end_%u\"\n", ifcounter);


			 if_statementp3.conprint("\n\n; Begin iffalse_or_end :%u\n", ifcounter);
			 if_statementp3.conprint("LBL TSTRING \"iffalse_or_end_%u\"\n", ifcounter);

			 labelTable.insert();
			 String iffalse_or_end_str_num;
			 iffalse_or_end_str_num.from_long(ifcounter);
			 String iffalse_or_end_str = (String)"iffalse_or_end_" + iffalse_or_end_str_num;
			 labelTable[labelTable.length() - 1].name(iffalse_or_end_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 2);

			 tree.add_node(if_statementp3);
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1080 "pnfha.ypp"
    {
			 --ifcounter;
			 ++ifnest;
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1084 "pnfha.ypp"
    {
			 inif = false;
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 1090 "pnfha.ypp"
    {
			 String nname = (String)"if_statementp5_" + ifcounternum;
			 ASTNode if_statementp5(nname);

			 ++elsecounter;


			 // Code for else will be inserted here if exists...
			 if_statementp5.conprint("; End if or else code :%u\n", ifcounter);
			 elsebegin = outcount;

			 String else_body_str = "else_body_";
			 else_body_str += ifcounter;
			 String after_if_str = "after_if_";
 			 after_if_str += ifgoto - 1;

			 labelTable.remove();

			 labelTable.insert();
			 labelTable[labelTable.length() - 1].name(else_body_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 2);

			 labelTable.insert();
			 labelTable[labelTable.length() - 1].name(after_if_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 2);

			 if_statementp5.conprint("GOTOL TSTRING \"end_%u\"\n", ifcounter);


			 if_statementp5.conprint("\n\nLBL TSTRING \"end_%u\"\n", ifcounter);
			 if_statementp5.conprint("; End if :%u\n", ifcounter);

			 labelTable.insert();
			 String end_str_num;
			 end_str_num.from_long(ifcounter);
			 String end_str = (String)"end_" + end_str_num;
			 labelTable[labelTable.length() - 1].name(end_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 2);


			 tree.add_node(if_statementp5);
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1135 "pnfha.ypp"
    {
			 ASTNode switch_statementp1("switch_statementp1");

			 switchfound = true;
			 ++switchcounter;
			 switchcasecounter = 0;
			 inswitch = true;

			 switch (exptype)
			 {
			  case TVOID:
			   switch_statementp1.conprint("ALOAD TVOID %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			   switchexptype = TVOID;
			   break;

			  case TBOOLEAN:
			   switch_statementp1.conprint("ALOAD TBOOLEAN %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			   switchexptype = TBOOLEAN;
     			   break;

			  case TNUMBER:
			   switch_statementp1.conprint("ALOAD TNUMBER %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			   switchexptype = TNUMBER;
			   break;

			  case TCHARACTER:
			   switch_statementp1.conprint("ALOAD TCHARACTER %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			   switchexptype = TCHARACTER;
			   break;

			  case TSTRING:
			   switch_statementp1.conprint("ALOAD TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			   switchexptype = TSTRING;
			   break;
			 }
			 switch_statementp1.conprint("ATOC TVOID 0V\n");

			 tree.add_node(switch_statementp1);
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1175 "pnfha.ypp"
    {
			 ASTNode switch_statementp2("switch_statementp2");


			 switch_statementp2.conprint("GOTOL TSTRING \"default_switch_%u\"\n", switchcounter);
			 switch_statementp2.conprint("LBL TSTRING \"default_switch_%u\"\n", switchcounter);

			 labelTable.insert();
			 String default_switch_str_num;
			 default_switch_str_num.from_long(switchcounter);
			 String default_switch_str = (String)"default_switch_" + default_switch_str_num;
			 labelTable[labelTable.length() - 1].name(default_switch_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 3);

			 tree.add_node(switch_statementp2);
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 1192 "pnfha.ypp"
    {
			 ASTNode switch_statementp3("switch_statementp3");
			 tree.add_node(switch_statementp3);
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1197 "pnfha.ypp"
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 switch_statementp4.conprint("LBL TSTRING \"after_switch_%u\"\n", switchcounter);

			 labelTable.insert();
			 String after_switch_str_num;
			 after_switch_str_num.from_long(switchcounter);
			 String after_switch_str = (String)"after_switch_" + after_switch_str_num;
			 labelTable[labelTable.length() - 1].name(after_switch_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 3);

			 tree.add_node(switch_statementp4);
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1212 "pnfha.ypp"
    {
			 ASTNode switch_statementp1("switch_statementp1");

			 switchfound = true;
			 ++switchcounter;
			 switchcasecounter = 0;
			 inswitch = true;

			 switch_statementp1.conprint("ATOC TVOID 0V\n");

			 tree.add_node(switch_statementp1);
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1226 "pnfha.ypp"
    {
			 ASTNode switch_statementp2("switch_statementp2");


			 switch_statementp2.conprint("GOTOL TSTRING \"default_switch_%u\"\n", switchcounter);
			 switch_statementp2.conprint("LBL TSTRING \"default_switch_%u\"\n", switchcounter);

			 labelTable.insert();
			 String default_switch_str_num;
			 default_switch_str_num.from_long(switchcounter);
			 String default_switch_str = (String)"default_switch_" + default_switch_str_num;
			 labelTable[labelTable.length() - 1].name(default_switch_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 3);

			 tree.add_node(switch_statementp2);
			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1243 "pnfha.ypp"
    {
			 ASTNode switch_statementp3("switch_statementp3");
			 tree.add_node(switch_statementp3);
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1248 "pnfha.ypp"
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 switch_statementp4.conprint("LBL TSTRING \"after_switch_%u\"\n", switchcounter);

			 labelTable.insert();
			 String after_switch_str_num;
			 after_switch_str_num.from_long(switchcounter);
			 String after_switch_str = (String)"after_switch_" + after_switch_str_num;
			 labelTable[labelTable.length() - 1].name(after_switch_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 3);

			 tree.add_node(switch_statementp4);
			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1264 "pnfha.ypp"
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1273 "pnfha.ypp"
    {
			 ASTNode case_statement("case_statement");

			 ++switchcasecounter;

			 if (switchexptype != exptype)
			  yyerror("Non-Matching Switch Expression");

			 case_statement.conprint("LBL TSTRING \"skip_switch_case_%u_%u\"\n", switchcounter, switchcasecounter);

			 labelTable.insert();
			 String skip_switch_case_str_num;
			 skip_switch_case_str_num.from_long(switchcounter);
			 String skip_switch_case_str_num2;
			 skip_switch_case_str_num2.from_long(switchcasecounter);
			 String skip_switch_case_str = (String)"skip_switch_case_" + skip_switch_case_str_num + (String)"_" + skip_switch_case_str_num2;
			 labelTable[labelTable.length() - 1].name(skip_switch_case_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 3);

 			 switch (exptype)
			 {
			  case TVOID:
			   case_statement.conprint("ALOAD TVOID %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   case_statement.conprint("EQU TVOID 0V\n");
			   case_statement.conprint("CGOTOL TSTRING \"switch_case_%u_%u\"\n", switchcounter, switchcasecounter);
			   break;

 			  case TBOOLEAN:
			   case_statement.conprint("ALOAD TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   case_statement.conprint("EQU TVOID 0V\n");
			   case_statement.conprint("CGOTOL TSTRING \"switch_case_%u_%u\"\n", switchcounter, switchcasecounter);
			   break;

			  case TNUMBER:
			   case_statement.conprint("ALOAD TNUMBER %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   case_statement.conprint("EQU TVOID 0V\n");
			   case_statement.conprint("CGOTOL TSTRING \"switch_case_%u_%u\"\n", switchcounter, switchcasecounter);
			   break;

			  case TCHARACTER:
			   case_statement.conprint("ALOAD TCHARACTER %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   case_statement.conprint("EQU TVOID 0V\n");
			   case_statement.conprint("CGOTOL TSTRING \"switch_case_%u_%u\"\n", switchcounter, switchcasecounter);
			   break;

		 	  case TSTRING:
			   case_statement.conprint("ALOAD TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   case_statement.conprint("EQU TVOID 0V\n");
			   case_statement.conprint("CGOTOL TSTRING \"switch_case_%u_%u\"\n", switchcounter, switchcasecounter);
			   break;
			 }

			 case_statement.conprint("GOTOL TSTRING \"skip_switch_case_%u_%u\"\n", switchcounter, switchcasecounter + 1);
			 case_statement.conprint("LBL TSTRING \"switch_case_%u_%u\"\n", switchcounter, switchcasecounter);

			 labelTable.insert();
			 String switch_case_str_num;
			 switch_case_str_num.from_long(switchcounter);
			 String switch_case_str_num2;
			 switch_case_str_num2.from_long(switchcasecounter);
			 String switch_case_str = (String)"switch_case_" + switch_case_str_num + (String)"_" + switch_case_str_num2;
			 labelTable[labelTable.length() - 1].name(switch_case_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 3);

			 tree.add_node(case_statement);
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1345 "pnfha.ypp"
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1354 "pnfha.ypp"
    {
			 ASTNode case_statementp1("case_statement");

			 ++switchcasecounter;

			 case_statementp1.conprint("LBL TSTRING \"skip_switch_case_%u_%u\"\n", switchcounter, switchcasecounter);
			
			 tree.add_node(case_statementp1);
			;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1365 "pnfha.ypp"
    {
			 ASTNode case_statementp2("case_statementp2");

			 labelTable.insert();
			 String skip_switch_case_str_num;
			 skip_switch_case_str_num.from_long(switchcounter);
			 String skip_switch_case_str_num2;
			 skip_switch_case_str_num2.from_long(switchcasecounter);
			 String skip_switch_case_str = (String)"skip_switch_case_" + skip_switch_case_str_num + (String)"_" + skip_switch_case_str_num2;
			 labelTable[labelTable.length() - 1].name(skip_switch_case_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 3);

			 case_statementp2.conprint("EQU TVOID 0V\n");
			 case_statementp2.conprint("CGOTOL TSTRING \"switch_case_%u_%u\"\n", switchcounter, switchcasecounter);

			 case_statementp2.conprint("GOTOL TSTRING \"skip_switch_case_%u_%u\"\n", switchcounter, switchcasecounter + 1);
			 case_statementp2.conprint("LBL TSTRING \"switch_case_%u_%u\"\n", switchcounter, switchcasecounter);

			 labelTable.insert();
			 String switch_case_str_num;
			 switch_case_str_num.from_long(switchcounter);
			 String switch_case_str_num2;
			 switch_case_str_num2.from_long(switchcasecounter);
			 String switch_case_str = (String)"switch_case_" + switch_case_str_num + (String)"_" + switch_case_str_num2;
			 labelTable[labelTable.length() - 1].name(switch_case_str);
			 labelTable[labelTable.length() - 1].address(labelTable.length() - 3);

			 tree.add_node(case_statementp2);
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1395 "pnfha.ypp"
    {
			 ASTNode case_statementp3("case_statementp3");

			 case_statementp3.conprint("GOTOL TSTRING \"switch_case_%u_%u\"\n", switchcounter, switchcasecounter + 1);

			 tree.add_node(case_statementp3);
			;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1407 "pnfha.ypp"
    {
			 loopexpr = true;
			 inloop2 = true;
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1412 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1417 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1422 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1427 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1432 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 
			 loopexpr = false;
			 inloop = true;		 

			 tree.add_node(loop_statement);
			;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1440 "pnfha.ypp"
    {
			 inloop2 = false;
			 inwhile = false;
			 indowhile = false;
			 infor2 = false;
			 indofor = false;
			 inforever = false;
			;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1451 "pnfha.ypp"
    {
			 ASTNode while_loopp1("while_loopp1");

			 inwhile = true;
			 ++whilecounter;
			 while_loopp1.conprint("LBL TSTRING \"while_test_%u\"\n", whilecounter);

			 tree.add_node(while_loopp1);
			;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1461 "pnfha.ypp"
    {
			 ASTNode while_loopp2("while_loopp2");

			 tree.add_node(while_loopp2);
			;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1467 "pnfha.ypp"
    {
			 ASTNode while_loopp3("while_loopp3");

			 while_loopp3.conprint("CGOTOL TSTRING \"while_body_%u\"\n", whilecounter);
			 while_loopp3.conprint("GOTOL TSTRING \"while_end_%u\"\n", whilecounter);

			 while_loopp3.conprint("LBL TSTRING \"while_body_%u\"\n", whilecounter);

			 tree.add_node(while_loopp3);
			;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1478 "pnfha.ypp"
    {
			 ASTNode while_loopp4("while_loopp4");

			 while_loopp4.conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 while_loopp4.conprint("LBL TSTRING \"while_end_%u\"\n", whilecounter);

			 tree.add_node(while_loopp4);
			;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1488 "pnfha.ypp"
    {
			 ASTNode do_while_loopp1("do_while_loopp1");

			 indowhile = true;
			 ++dowhilecounter;
			 do_while_loopp1.conprint("LBL TSTRING \"do_while_body_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp1);
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1498 "pnfha.ypp"
    {
			 ASTNode do_while_loopp2("do_while_loopp2");

			 tree.add_node(do_while_loopp2);
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1505 "pnfha.ypp"
    {
			 ASTNode do_while_loopp3("do_while_loopp3");

			 do_while_loopp3.conprint("LBL TSTRING \"do_while_test_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp3);
			;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1513 "pnfha.ypp"
    {
			 ASTNode do_while_loopp4("do_while_loopp4");

			 tree.add_node(do_while_loopp4);
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1519 "pnfha.ypp"
    {
			 ASTNode do_while_loopp5("do_while_loopp5");

			 do_while_loopp5.conprint("CGOTOL TSTRING \"do_while_body_%u\"\n", dowhilecounter);
			 do_while_loopp5.conprint("GOTOL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp5);
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1528 "pnfha.ypp"
    {
			 ASTNode do_while_loopp6("do_while_loopp6");

			 do_while_loopp6.conprint("LBL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp6);
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1537 "pnfha.ypp"
    {
			 infor = true;
			;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1541 "pnfha.ypp"
    {
			 ASTNode for_loopp1("for_loopp1");

			 infor2 = true;
			 ++forcounter;
			 for_loopp1.conprint("LBL TSTRING \"for_initialization_%u\"\n", forcounter);

			 tree.add_node(for_loopp1);
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1551 "pnfha.ypp"
    {
			 ASTNode for_loopp2("for_loopp2");

			 for_loopp2.conprint("LBL TSTRING \"for_condition_%u\"\n", forcounter);

			 tree.add_node(for_loopp2);
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1559 "pnfha.ypp"
    {
			 ASTNode for_loopp3("for_loopp3");

			 for_loopp3.conprint("CGOTOL TSTRING \"for_body_%u\"\n", forcounter);
			 for_loopp3.conprint("GOTOL TSTRING \"for_end_%u\"\n", forcounter);
			 for_loopp3.conprint("LBL TSTRING \"for_increment_statement_%u\"\n", forcounter);

			 tree.add_node(for_loopp3);
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1569 "pnfha.ypp"
    {
			 ASTNode for_loopp4("for_loopp4");

			 for_loopp4.conprint("GOTOL TSTRING \"for_condition_%u\"\n", forcounter);
			 for_loopp4.conprint("LBL TSTRING \"for_body_%u\"\n", forcounter);

			 tree.add_node(for_loopp4);
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1578 "pnfha.ypp"
    {
			 ASTNode for_loopp5("for_loopp5");

			 for_loopp5.conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 for_loopp5.conprint("LBL TSTRING \"for_end_%u\"\n", forcounter);

			 tree.add_node(for_loopp5);
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1589 "pnfha.ypp"
    {
			 ASTNode forb_loopp1("forb_loopp1");

			 indofor = true;
			 infor = true;
			 ++doforcounter;

			 forb_loopp1.conprint("GOTOL TSTRING \"dofor_initialization_%u\"\n", doforcounter);
			 forb_loopp1.conprint("LBL TSTRING \"dofor_body_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp1);
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1602 "pnfha.ypp"
    {
			 ASTNode forb_loopp2("forb_loopp2");

			 forb_loopp2.conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 forb_loopp2.conprint("LBL TSTRING \"dofor_initialization_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp2);
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1611 "pnfha.ypp"
    {
			 ASTNode forb_loopp3("forb_loopp3");

			 tree.add_node(forb_loopp3);
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1617 "pnfha.ypp"
    {
			 ASTNode forb_loopp4("forb_loopp4");

			 forb_loopp4.conprint("GOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 forb_loopp4.conprint("LBL TSTRING \"dofor_condition_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp4);
			;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1626 "pnfha.ypp"
    {
			 ASTNode forb_loopp5("forb_loopp5");

			 forb_loopp5.conprint("CGOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 forb_loopp5.conprint("GOTOL TSTRING \"dofor_end_%u\"\n", doforcounter);
			 forb_loopp5.conprint("LBL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp5);
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1636 "pnfha.ypp"
    {
			 ASTNode forb_loopp6("forb_loopp6");
			 tree.add_node(forb_loopp6);
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1641 "pnfha.ypp"
    {
			 ASTNode forb_loopp7("forb_loopp7");

			 forb_loopp7.conprint("GOTOL TSTRING \"dofor_condition_%u\"\n", doforcounter);
			 forb_loopp7.conprint("LBL TSTRING \"dofor_end_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp7);
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1652 "pnfha.ypp"
    {
			 ASTNode forever_loopp1("forever_loopp1");

			 breakinforever = true;
			 ++forevercounter;
			 forever_loopp1.conprint("LBL TSTRING \"forever_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp1);			
			;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1662 "pnfha.ypp"
    {
			 ASTNode forever_loopp2("forever_loopp2");

			 forever_loopp2.conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);
			 forever_loopp2.conprint("LBL TSTRING \"forever_end_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp2);			
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1671 "pnfha.ypp"
    { PNF_String str((yyvsp[(2) - (3)]).to_string().get()); (yyval).put(str); ASTNode statement_block("statement_block"); 
                                                  tree.add_node(statement_block); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1676 "pnfha.ypp"
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1681 "pnfha.ypp"
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1687 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TVOID; ASTNode expression("expression"); tree.add_node(expression); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1689 "pnfha.ypp"
    {
		 (yyval) = (yyvsp[(1) - (1)]);
		 exptype = TBOOLEAN;
		 ASTNode expression("expression");
		 tree.add_node(expression);
		;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1695 "pnfha.ypp"
    { (yyval).put((yyvsp[(1) - (1)]).to_number()); exptype = TNUMBER; ASTNode expression("expression");
                                      tree.add_node(expression); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1697 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TCHARACTER; ASTNode expression("expression"); 
                                         tree.add_node(expression); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1699 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TSTRING; ASTNode expression("expression"); 
                                      tree.add_node(expression); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1701 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
                                  tree.add_node(expression); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1703 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TBOOLEAN; ASTNode expression("expression"); 
					  tree.add_node(expression); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1705 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
				     tree.add_node(expression); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1711 "pnfha.ypp"
    {
			 PNF_String s("0V");
			 (yyval).put(s);

			 exptruth = false;

			 ASTNode void_expression("void_expression");
			 tree.add_node(void_expression);
			;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1720 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1724 "pnfha.ypp"
    { 
			 (yyval) = (yyvsp[(1) - (1)]);

			 String str = (yyval).to_string().get();
			 if (str == "true")
			  exptruth = true;
                         else if (str == "false")
                          exptruth = false;
			 else
			  exptruth = true;

			 ASTNode boolean_expression("boolean_expression"); 
			 tree.add_node(boolean_expression);
			;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1739 "pnfha.ypp"
    {
			 bool b;
			 String str = (yyvsp[(2) - (2)]).to_boolean().get();

			 if (str.getString() == "true")
			  b = true;
			 else
			  b = false;

			 PNF_Boolean b2(b);
			 b2.opnot();
			 (yyval).put(b2);
			;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1753 "pnfha.ypp"
    {
			 String bl = (yyvsp[(3) - (3)]).to_boolean().get();
			 bool b;
			
			 if (bl.getString() == "true")
			  b = true;
			 else if (bl.getString() == "false")
			  b = false;
			 else
			  b = false;

			 PNF_Boolean b2((yyvsp[(1) - (3)]).to_boolean());
			 b2.opand(b);
			 (yyval).put(b2);
			;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1769 "pnfha.ypp"
    {
			 String bl = (yyvsp[(3) - (3)]).to_boolean().get();
			 bool b;
			
			 if (bl.getString() == "true")
			  b = true;
			 else if (bl.getString() == "false")
			  b = false;
			 else
			  b = false;

			 PNF_Boolean b2((yyvsp[(1) - (3)]).to_boolean());
			 b2.opor(b);
			 (yyval).put(b2);
			;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1784 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1788 "pnfha.ypp"
    { 
			 (yyval).put(yylval.to_number());

			 double d = (yyval).to_number().get();

                         if (d == 0)
                          exptruth = false;
                         else
                          exptruth = true;

			 ASTNode number_expression("number_expression");
                         tree.add_node(number_expression);
			;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1802 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().add(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1808 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().sub(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1814 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mul(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1820 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().div(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1826 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mod(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1832 "pnfha.ypp"
    {
			 char * str = "-";
			 strcat(str, (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 PNF_String s(str);
			 PNF_Variable v(s);
			 (yyval) = v;
			;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1840 "pnfha.ypp"
    {
			 double d = (yyvsp[(3) - (3)]).to_number().get();
			 PNF_Number n((yyvsp[(1) - (3)]).to_number());
			 n.pow(d);
			 (yyval).put(n);
			;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1847 "pnfha.ypp"
    {
			 double d = (yyvsp[(1) - (3)]).to_number().get();
			 PNF_Number n((yyvsp[(3) - (3)]).to_number());
			 n.root(d);			 
			 (yyval).put(n);
			;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1854 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1860 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1866 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1872 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1878 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 & d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1886 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 | d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1895 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 ^ d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1903 "pnfha.ypp"
    {
			 int d = (int)(yyvsp[(2) - (2)]).to_number().get();
			 d = ~d;
			 PNF_Number n(d);
			 (yyval).put(n);
			;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1910 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 << d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1918 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 >> d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1925 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1930 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);
			 char ch = (yyval).to_character().get();

			 if (ch == '\0')
                          exptruth = false;
			 else
			  exptruth = true;

			 ASTNode character_expression("character_expression"); 
			 tree.add_node(character_expression);
			;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1943 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.add((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1950 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.sub((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1957 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mul((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1964 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.div((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);			;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1970 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mod((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1977 "pnfha.ypp"
    {
			 char d = (yyvsp[(3) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(1) - (3)]).to_character());
			 c.pow(d);
			 (yyval).put(c);
			;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1984 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(3) - (3)]).to_character());
			 c.root(d);
			 (yyval).put(c);
			;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1991 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1997 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 2003 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 2009 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 2014 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 2019 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);
		
			 String str = (yyval).to_string().get();
			 if (str == "")
			  exptruth = false;
			 else
			  exptruth = true;

			 ASTNode string_expression("string_expression"); 
			 tree.add_node(string_expression);
			;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 2032 "pnfha.ypp"
    {
			 String d = (yyvsp[(1) - (3)]).to_string().get();
			 PNF_String s(d);
			 s.add((yyvsp[(3) - (3)]).to_string().get());

			 String str = s.get();
			 String str2 = "";
	   	         for (unsigned long i = 0, j = 0; i < str.length(); ++i)
			 {
			  if (str[i] == '\"')
			   continue;
			  else
			  {
			   str2 += str[i];
			   ++j;
			  }
			 }

			 String str3 = '\"';
			 str3 += str2;
			 str3 += '\"';
			 s.put(str3);
			 (yyval).put(s);
			;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 2057 "pnfha.ypp"
    {
			 String str = (yyvsp[(2) - (2)]).to_string().get();
			 String str2 = "\"" + str + "\"";
			 PNF_String s(str2);
			 (yyval).put(s);
			;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 2063 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 2068 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (1)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   (yyval) = varTable[scope][i].value();

			   switch ((yyval).getType())
			   {
			    case TVOID:
			     exptruth = false;
			     break;

			    case TBOOLEAN:
			    {
			     String str = (yyval).to_boolean().get();
			     if (str == "true")
			      exptruth = true;
			     else if (str == "false")
			      exptruth = false;
			     else
			      exptruth = true;
			     }
			     break;

			    case TNUMBER:
			    {
			     double d = (yyval).to_number().get();
			     if (d == 0)
			      exptruth = false;
			     else
			      exptruth = true;
			     }
			     break;

			    case TCHARACTER:
			    {
			     char ch = (yyval).to_character().get();
			     if (ch == '\0')
			      exptruth = false;
			     else
			      exptruth = true;
			     }
			     break;

			    case TSTRING:
			    {
			     String str = (yyval).to_string().get();
			     if (str == "")
			      exptruth = false;
			     else
			      exptruth = true;
			     }
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(1) - (1)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 ASTNode id_expression("id_expression");
			 tree.add_node(id_expression);
			;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 2139 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(2) - (2)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Number n(varTable[scope][i].address());
			   (yyval).put(n);
			  }
			 }

			 if (!declared)
			 {
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (strcmp(labelTable[i].name().getString().c_str(), (yyvsp[(2) - (2)]).to_string().get().getString().c_str()) == 0)
			   {
			    declared = true;
			    PNF_Number n(labelTable[i].address());
			    (yyval).put(n);
			   }
 			  }


			  if (!declared)
			  {
			   for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			   {
			    if (strcmp(eventLabelTable[i].name().getString().c_str(), (yyvsp[(2) - (2)]).to_string().get().getString().c_str()) == 0)
			    {
			     declared = true;
			     PNF_Number n(eventLabelTable[i].address());
			     (yyval).put(n);
			    }
  			   }
			  }
			 }
			;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 2179 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(2) - (2)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Boolean b;
			   if (varTable[scope][i].value().getType() != TBOOLEAN)
             		    b.put(true);
			   else
			   {
			    bool b2;
			    String str = varTable[scope][i].value().to_boolean().get();
			    if (str.getString() == "true")
			     b2 = true;
			    else if (str.getString() == "false")
			     b2 = false;
			    else
			     b2 = true;

			    b.put(b2);
			   }

			   b.opnot();
			   (yyval).put(b);
			   varTable[scope][i].value(b);			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(2) - (2)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
			;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 2216 "pnfha.ypp"
    {
			 bool declared1 = false;
			 bool declared2 = false;
  		   	 PNF_Boolean b1;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared1 = true;
			   if (varTable[scope][i].value().getType() != TBOOLEAN)
             		    b1.put(true);
			   else
			   {
			    bool b2;
			    String str = varTable[scope][i].value().to_boolean().get();
			    if (str.getString() == "true")
			     b2 = true;
			    else if (str.getString() == "false")
			     b2 = false;
			    else
			     b2 = true;

			    b1.put(b2);
			   }
			  }
			 }

			 if (!declared1)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 PNF_Boolean b3;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared2 = true;
			   if (varTable[scope][i].value().getType() != TBOOLEAN)
             		    b3.put(true);
			   else
			   {
			    bool b4;
			    String str = varTable[scope][i].value().to_boolean().get();
			    if (str.getString() == "true")
			     b4 = true;
			    else if (str.getString() == "false")
			     b4 = false;
			    else
			     b4 = true;
			    b3.put(b4);
			   }
			  }
			 }

			 if (!declared2)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 bool b5;
			 String str = b3.get();
			 if (str.getString() == "true")
			  b5 = true;
			 else if (str.getString() == "false")
			  b5 = false;
			 else
			  b5 = true;

			 b1.opand(b5);
			 (yyval).put(b1);
			;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 2293 "pnfha.ypp"
    {
			 bool declared1 = false;
			 bool declared2 = false;
			 PNF_Boolean b1;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared1 = true;
			   if (varTable[scope][i].value().getType() != TBOOLEAN)
             		    b1.put(true);
			   else
			   {
			    String str = varTable[scope][i].value().to_boolean().get();
			    bool b2;
			    if (str.getString() == "true")
			     b2 = true;
			    else if (str.getString() == "false")
			     b2 = false;
			    else
			     b2 = true;

			    b1.put(b2);
			   }
			  }
			 }

			 if (!declared1)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }


   		         PNF_Boolean b3;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared2 = true;
			   if (varTable[scope][i].value().getType() != TBOOLEAN)
             		    b3.put(true);
			   else
			   {
			    String str = varTable[scope][i].value().to_boolean().get();
			    bool b4;
			    if (str.getString() == "true")
			     b4 = true;
			    else if (str.getString() == "false")
			     b4 = false;
			    else
			     b4 = true;

			    b3.put(b4);
			   }
			  }
			 }

			 if (!declared2)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 bool b5;
			 String str = b3.get();
			 if (str.getString() == "true")
			  b5 = true;
			 else if (str.getString() == "false")
			  b5 = false;
			 else
			  b5 = true;

			 b1.opor(b5);
			 (yyval).put(b1);
			;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 2372 "pnfha.ypp"
    {
			 switch ((yyvsp[(1) - (3)]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[(3) - (3)]).to_number().get();
			   PNF_Number n((yyvsp[(1) - (3)]).to_number());
			   n.add(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[(3) - (3)]).to_character().get();
			   PNF_Character n((yyvsp[(1) - (3)]).to_character());
			   n.add(d);
			   (yyval).put(n);
			  }
			  break;

			  case TSTRING:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TSTRING)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }

			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   String str2 = "";
			   for (unsigned long i = 0; i < str.length(); ++i)
 			   {
			    if (str[i] == '\"')
			     continue;
			    str2 += str[i];
			   }

			   str = (yyvsp[(1) - (3)]).to_string().get();
			   String str3 = "";
			   for (unsigned long i = 0; i < str.length(); ++i)
 			   {
			    if (str[i] == '\"')
			     continue;
			    str3 += str[i];
			   }

			   PNF_String s(str3);
			   s.add(str2);

			   str = s.get();
			   String str4 = "\"";
			   for (unsigned long i = 0; i < str.length(); ++i)
 			   {			    
			    str4 += str[i];
			   }
			   str4 += "\"";
			   s.put(str4);

			   (yyval).put(s);
			  }
			  break;

			  default:
			   PNF_Number n(0);
			   (yyval).put(n);
			   break;
			 }
			;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 2452 "pnfha.ypp"
    {
			 switch ((yyvsp[(1) - (3)]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[(3) - (3)]).to_number().get();
			   PNF_Number n((yyvsp[(1) - (3)]).to_number());
			   n.sub(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[(3) - (3)]).to_character().get();
			   PNF_Character n((yyvsp[(1) - (3)]).to_character());
			   n.sub(d);
			   (yyval).put(n);
			  }
			  break;			

			  default:
			   PNF_Number n(0);
			   (yyval).put(n);
			   break;
			 }
			;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 2490 "pnfha.ypp"
    {
			 switch ((yyvsp[(1) - (3)]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[(3) - (3)]).to_number().get();
			   PNF_Number n((yyvsp[(1) - (3)]).to_number());
			   n.mul(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[(3) - (3)]).to_character().get();
			   PNF_Character n((yyvsp[(1) - (3)]).to_character());
			   n.mul(d);
			   (yyval).put(n);
			  }
			  break;				

			  default:
			   PNF_Number n(0);
			   (yyval).put(n);
			   break;
			 }
			;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 2528 "pnfha.ypp"
    {
			 switch ((yyvsp[(1) - (3)]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[(3) - (3)]).to_number().get();
			   PNF_Number n((yyvsp[(1) - (3)]).to_number());
			   n.div(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[(3) - (3)]).to_character().get();
			   PNF_Character n((yyvsp[(1) - (3)]).to_character());
			   n.div(d);
			   (yyval).put(n);
			  }
			  break;			

			  default:
			   PNF_Number n(0);
			   (yyval).put(n);
			   break;
			 }
			;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 2566 "pnfha.ypp"
    {
			 switch ((yyvsp[(1) - (3)]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[(3) - (3)]).to_number().get();
			   PNF_Number n((yyvsp[(1) - (3)]).to_number());
			   n.mod(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[(3) - (3)]).to_character().get();
			   PNF_Character n((yyvsp[(1) - (3)]).to_character());
			   n.mod(d);
			   (yyval).put(n);
			  }
			  break;	

			  default:
			   PNF_Number n(0);
			   (yyval).put(n);
			   break;
			 }
			;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 2604 "pnfha.ypp"
    {
			 if ((yyvsp[(2) - (2)]).getType() != TNUMBER)
			 {
			  PNF_Number n(0);
                          (yyval).put(n);
			 }
			 double d = (yyvsp[(2) - (2)]).to_number().get();
			 d = -d;
			 PNF_Number n(d);
			 PNF_Variable v(n);
			 (yyval) = v;
			;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 2617 "pnfha.ypp"
    {
			 switch ((yyvsp[(1) - (3)]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[(3) - (3)]).to_number().get();
			   PNF_Number n((yyvsp[(1) - (3)]).to_number());
			   n.pow(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[(3) - (3)]).to_character().get();
			   PNF_Character n((yyvsp[(1) - (3)]).to_character());
			   n.pow(d);
			   (yyval).put(n);
			  }
			  break;	

			  default:
			   PNF_Number n(0);
			   (yyval).put(n);
			   break;
			 }
			;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 2655 "pnfha.ypp"
    {
			 switch ((yyvsp[(1) - (3)]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[(1) - (3)]).to_number().get();
			   PNF_Number n((yyvsp[(3) - (3)]).to_number());
			   n.root(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[(1) - (3)]).to_character().get();
			   PNF_Character n((yyvsp[(3) - (3)]).to_character());
			   n.root(d);
			   (yyval).put(n);
			  }
			  break;	

			  default:
			   PNF_Number n(0);
			   (yyval).put(n);
			   break;
			 }
			;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 2693 "pnfha.ypp"
    {
			 switch ((yyvsp[(2) - (2)]).getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			   n.inc(1);
			   (yyval).put(n);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c((yyvsp[(2) - (2)]).to_character().get());
			   c.inc(1);
			   (yyval).put(c);
			  }
	                  break;
			  
			  default:
			  {
			   PNF_Number n(0);
                           (yyval).put(n);
			  }
			  break;
			 }
			;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 2721 "pnfha.ypp"
    {
			 switch ((yyvsp[(2) - (2)]).getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			   (yyval).put(n);
			   n.inc(1);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c((yyvsp[(2) - (2)]).to_character().get());
			   (yyval).put(c);
			   c.inc(1);
			  }
	                  break;
			  
			  default:
			  {
			   PNF_Number n(0);
                           (yyval).put(n);
			  }
			  break;
			 }
			;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 2749 "pnfha.ypp"
    {
			 switch ((yyvsp[(2) - (2)]).getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			   n.dec(1);
			   (yyval).put(n);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c((yyvsp[(2) - (2)]).to_character().get());
			   c.dec(1);
			   (yyval).put(c);
			  }
	                  break;
			  
			  default:
			  {
			   PNF_Number n(0);
                           (yyval).put(n);
			  }
			  break;
			 }
			;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 2777 "pnfha.ypp"
    {
			 switch ((yyvsp[(2) - (2)]).getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			   (yyval).put(n);
			   n.dec(1);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c((yyvsp[(2) - (2)]).to_character().get());
			   (yyval).put(c);
			   c.dec(1);
			  }
	                  break;
			  
			  default:
			  {
			   PNF_Number n(0);
                           (yyval).put(n);
			  }
			  break;
			 }
			;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 2804 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 2808 "pnfha.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 == d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 2819 "pnfha.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 != d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 2830 "pnfha.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 < d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 2841 "pnfha.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 > d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 2852 "pnfha.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 <= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 2863 "pnfha.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 >= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 2873 "pnfha.ypp"
    {
			 String str = (yyval).to_boolean().get();
			 if (str == "false")
			  exptruth = false;
			 else if (str == "true")
			  exptruth = true;
			 else
			  exptruth = true;
			;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 2885 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 2887 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Boolean b1;
			   if (varTable[scope][i].value().getType() != TBOOLEAN)
             		    b1.put(true);
			   else
			   {
			    bool b2;
			    String str = varTable[scope][i].value().to_boolean().get();
			    if (str.getString() == "true")
			     b2 = true;
			    else if (str.getString() == "false")
			     b2 = false;
			    else
			     b2 = true;

			    b1.put(b2);
			   }

			   bool b2;
			   String str = (yyvsp[(3) - (3)]).to_boolean().get();
			   if (str.getString() == "true")
			    b2 = true;
			   else if (str.getString() == "false")
			    b2 = false;
			   else
			    b2 = true;

			   b1.opand(b2);

			   (yyval).put(b1);
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 2936 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Boolean b1;
			   if (varTable[scope][i].value().getType() != TBOOLEAN)
             		    b1.put(true);
			   else
			   {
			    bool b2;
			    String str = varTable[scope][i].value().to_boolean().get();
			    if (str.getString() == "true")
			     b2 = true;
			    else if (str.getString() == "false")
			     b2 = false;
			    else
			     b2 = true;

			    b1.put(b2);
			   }

			   bool b2;
			   String str = (yyvsp[(1) - (3)]).to_boolean().get();
			   if (str.getString() == "true")
			    b2 = true;
			   else if (str.getString() == "false")
			    b2 = false;
			   else
			    b2 = true;

			   b1.opand(b2);

			   (yyval).put(b1);
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 2985 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Boolean b1;
			   if (varTable[scope][i].value().getType() != TBOOLEAN)
             		    b1.put(true);
			   else
			   {
			    bool b2;
			    String str = varTable[scope][i].value().to_boolean().get();
			    if (str.getString() == "true")
                             b2 = true;
			    else if (str.getString() == "false")
			     b2 = false;
			    else
			     b2 = true;

			    b1.put(b2);
			   }

			   bool b2;
			   String str = (yyvsp[(3) - (3)]).to_boolean().get();
			   if (str.getString() == "true")
			    b2 = true;
			   else if (str.getString() == "false")
			    b2 = false;
			   else
			    b2 = true;

			   b1.opor(b2);

			   (yyval).put(b1);
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 3034 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Boolean b1;
			   if (varTable[scope][i].value().getType() != TBOOLEAN)
             		    b1.put(true);
			   else
			   {
			    bool b2;
			    String str = varTable[scope][i].value().to_boolean().get();
			    if (str.getString() == "true")
			     b2 = true;
			    else if (str.getString() == "false")
			     b2 = false;
			    else
			     b2 = true;

			    b1.put(b2);
			   }

			   bool b2;
			   String str = (yyvsp[(1) - (3)]).to_boolean().get();
			   if (str.getString() == "true")
			    b2 = true;
			   else if (str.getString() == "false")
			    b2 = false;
			   else
			    b2 = true;

			   b1.opor(b2);

			   (yyval).put(b1);
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 3083 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(3) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.add(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 3125 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(3) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.sub(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 3167 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(3) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.mul(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 3209 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(3) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.div(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 3251 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(3) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.pow(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 3293 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = varTable[scope][i].value().to_number().get();
			     PNF_Number n((yyvsp[(3) - (3)]).to_number());
			     n.root(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 3335 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(1) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.add(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 3377 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(1) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.sub(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 3419 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(1) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.mul(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 3461 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(1) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.div(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 3503 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[(1) - (3)]).to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.pow(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 3545 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = varTable[scope][i].value().to_number().get();
			     PNF_Number n((yyvsp[(1) - (3)]).to_number());
			     n.root(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 3587 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(3) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.add(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 3629 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(3) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.sub(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 3671 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(3) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.mul(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 3713 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(3) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.div(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 3755 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(3) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.pow(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 3797 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = varTable[scope][i].value().to_character().get();
			     PNF_Character n((yyvsp[(3) - (3)]).to_character());
			     n.root(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 3839 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(1) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.add(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 3881 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(1) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.sub(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 3923 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(1) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.mul(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 3965 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(1) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.div(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 4007 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[(1) - (3)]).to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.pow(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 4049 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = varTable[scope][i].value().to_character().get();
			     PNF_Character n((yyvsp[(1) - (3)]).to_character());
			     n.root(d);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 4091 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TSTRING:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TSTRING)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     String d = (yyvsp[(3) - (3)]).to_string().get();
			     String str = "";
			     for (unsigned is = 0; is < d.length(); ++is)
			     {
			      if (d[is] == '\"')
			       continue;
			      str += d[is];
			     }
			     String str2 = varTable[scope][i].value().to_string().get();
			     String str3 = "";
			     for (unsigned is = 0; is < str2.length(); ++is)
			     {
			      if (str2[is] == '\"')
			       continue;
			      str3 += str2[is];
			     }

			     PNF_String n(str3);
			     n.add(str);
	  		     String str4 = "\"";
			     str4 += n.get();
			     str4 += "\"";
			     PNF_String n2(str4);
			     (yyval).put(n2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 4155 "pnfha.ypp"
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TSTRING:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TSTRING)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     String d = (yyvsp[(1) - (3)]).to_string().get();
			     String str = "";
			     for (unsigned is = 0; is < d.length(); ++is)
			     {
			      if (d[is] == '\"')
			       continue;
			      str += d[is];
			     }
			     String str2 = varTable[scope][i].value().to_string().get();
			     String str3 = "";
			     for (unsigned is = 0; is < str2.length(); ++is)
			     {
			      if (str2[is] == '\"')
			       continue;
			      str3 += str2[is];
			     }

			     PNF_String n(str3);
			     n.add(str);
	  		     String str4 = "\"";
			     str4 += n.get();
			     str4 += "\"";
			     PNF_String n2(str4);
			     (yyval).put(n2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 4219 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(1) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 == d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 4264 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(1) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 != d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 4309 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(1) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 < d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 4354 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(1) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 > d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 4399 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(1) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 <= d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 4444 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(1) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 >= d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 4489 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(3) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 == d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 4534 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(3) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 != d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 4579 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(3) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 < d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 4624 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(3) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 > d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 4669 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(3) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 <= d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 4714 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[(3) - (3)]).to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 >= d2;
			     PNF_Boolean b2(b);
			     (yyval).put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 4759 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(3) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 & d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 4804 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(3) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 | d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 4849 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(3) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 ^ d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 4894 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 & d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 4939 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 | d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 4984 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 ^ d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 5029 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(2) - (2)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     int d1 = (int)varTable[scope][i].value().to_number().get();
			     int d2 = ~d1;
			     PNF_Number n(d1);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(2) - (2)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 5066 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(3) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 << d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 5111 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(3) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(3) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 >> d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 5156 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 << d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 5201 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 >> d2;
			     PNF_Number n(d3);
			     (yyval).put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     (yyval).put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 5248 "pnfha.ypp"
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 5253 "pnfha.ypp"
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 5258 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 5263 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 5270 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration"); 

			 bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(2) - (2)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Number n(0);
			   PNF_Variable p(n);
			   varTable[scope][i].value(p);
			   (yyval).put(varTable[scope][i].value().to_number());
			  }
			 }

			 if (!declared)
			 {
			  varTable[scope].insert();
			  varTable[scope][varTable[scope].length() - 1].name((yyvsp[(2) - (2)]).to_string().get());
			  PNF_Number n(0);
			  PNF_Variable p(n);
			  varTable[scope][varTable[scope].length() - 1].value(p);

			  switch (p.getType())
		    	  {
			   case TVOID:
   			    variable_declaration.conprint("ALOAD TVOID 0V\n");
			    break;

			   case TBOOLEAN:
   			    variable_declaration.conprint("ALOAD TBOOLEAN %s\n", p.to_boolean().get().getString().c_str());
			    break;

			   case TNUMBER:
   			    variable_declaration.conprint("ALOAD TNUMBER %g\n", p.to_number().get());
			    break;

			   case TCHARACTER:
   			    variable_declaration.conprint("ALOAD TCHARACTER \'%s\'\n", p.to_string().get().getString().c_str());
			    break;

			   case TSTRING:
   			    variable_declaration.conprint("ALOAD TSTRING %s\n", p.to_string().get().getString().c_str());
			    break;
			  }
			  variable_declaration.conprint("VSTORE TVOID 0V\n");
			  ++varcount;
			  (yyval).put(varTable[scope][varTable[scope].length() - 1].value().to_number());

			  if (varTable[scope].length() - 2 <= 0)
		  	   varTable[scope][varTable[scope].length() - 1].address(scope + 0);
			  else
			   varTable[scope][varTable[scope].length() - 1].address(scope + (varTable[scope][varTable[scope].length() - 2].address() + 1));
			 }
		         tree.add_node(variable_declaration);
			;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 5328 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration"); 

			 bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(2) - (4)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   varTable[scope][i].value((yyvsp[(4) - (4)]));
			
			   switch ((yyvsp[(4) - (4)]).getType())
			   {
			    case TVOID:
			     (yyval).put(varTable[scope][i].value().to_void());
			     break;
			
			    case TBOOLEAN:
			     (yyval).put(varTable[scope][i].value().to_boolean());
			     break;

			    case TNUMBER:
			     (yyval).put(varTable[scope][i].value().to_number());
			     break;

			    case TCHARACTER:
			     (yyval).put(varTable[scope][i].value().to_character());
			     break;

			    case TSTRING:
			     (yyval).put(varTable[scope][i].value().to_string());
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  varTable[scope].insert();

			  varTable[scope][varTable[scope].length() - 1].name((yyvsp[(2) - (4)]).to_string().get());
			  varTable[scope][varTable[scope].length() - 1].value((yyvsp[(4) - (4)]));

			  (yyval) = (yyvsp[(4) - (4)]);

			  switch ((yyval).getType())
		    	  {
			   case TVOID:
   			    variable_declaration.conprint("ALOAD TVOID 0V\n");
			    break;

			   case TBOOLEAN:
   			    variable_declaration.conprint("ALOAD TBOOLEAN %s\n", (yyval).to_boolean().get().getString().c_str());
			    break;

			   case TNUMBER:
   			    variable_declaration.conprint("ALOAD TNUMBER %g\n", (yyval).to_number().get());
			    break;

			   case TCHARACTER:
   			    variable_declaration.conprint("ALOAD TCHARACTER \'%c\'\n", (yyval).to_character().get());
			    break;

			   case TSTRING:
   			    variable_declaration.conprint("ALOAD TSTRING %s\n", (yyval).to_string().get().getString().c_str());
			    break;
			  }
			  variable_declaration.conprint("VSTORE TVOID 0V\n");
			  ++varcount;

			  unsigned long paddress = 0;
			  if (varTable[scope].length() - 2 <= 0)
		  	   paddress = scope + 0;
			  else
			   paddress = scope + (varTable[scope][varTable[scope].length() - 2].address() + 1);			  
			
			  varTable[scope][varTable[scope].length() - 1].address(paddress);
			 }
		         tree.add_node(variable_declaration);
			;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 5409 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration"); 

			 bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(2) - (2)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Number n(0);
			   PNF_Variable p(n);
			   varTable[scope][i].value(p);
			   (yyval).put(varTable[scope][i].value().to_number());
			  }
			 }

			 if (!declared)
			 {
			  varTable[scope].insert();
			  varTable[scope][varTable[scope].length() - 1].name((yyvsp[(2) - (2)]).to_string().get());
			  PNF_Number n(0);
			  PNF_Variable p(n);
			  varTable[scope][varTable[scope].length() - 1].value(p);

			  ++varcount;
			  (yyval).put(varTable[scope][varTable[scope].length() - 1].value().to_number());

			  if (varTable[scope].length() - 2 <= 0)
		  	   varTable[scope][varTable[scope].length() - 1].address(scope + 0);
			  else
			   varTable[scope][varTable[scope].length() - 1].address(scope + (varTable[scope][varTable[scope].length() - 2].address() + 1));
			 }
		         tree.add_node(variable_declaration);
			;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 5444 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 5449 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 5454 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 5461 "pnfha.ypp"
    {
			 ASTNode enumv_declaration("enumv_declaration");

			 enumv_declaration.conprint("ENUMS TSTRING %s\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 enumv_declaration.conprint("ENUM TSTRING %s\n", (yyvsp[(5) - (5)]).to_string().get().getString().c_str());
			 enumv_declaration.conprint("SENUM TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());

			 tree.add_node(enumv_declaration);
			;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 5473 "pnfha.ypp"
    {
			 ASTNode rangev_declaration("rangev_declaration");

			 if ((yyvsp[(2) - (6)]).to_string().get() == "rtype1")
			 {
			  rangev_declaration.conprint("RSTART1 TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			  rangev_declaration.conprint("RANGE1 TNUMBER %s\n", strip_quotes((yyvsp[(6) - (6)]).to_string().get()).getString().c_str());
			  rangev_declaration.conprint("REND1 TSTRING %s\n", (yyvsp[(4) - (6)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(rangev_declaration);
			;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 5488 "pnfha.ypp"
    {
			 ASTNode rangev_declaration("rangev_declaration");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "rtype2")
			 {
			  rangev_declaration.conprint("RSTART2 TSTRING %s\n", (yyvsp[(3) - (4)]).to_string().get().getString().c_str());
			  rangev_declaration.conprint("RANGE2 TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(rangev_declaration);
			;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 5504 "pnfha.ypp"
    {
			 ASTNode array_declaration("array_declaration");

			 array_declaration.conprint("ASTART TSTRING %s\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 array_declaration.conprint("AEND TNUMBER %g\n", (yyvsp[(4) - (5)]).to_number().get());

			 tree.add_node(array_declaration);
			;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 5515 "pnfha.ypp"
    {
			 ASTNode enum_declarationp1("enum_declarationp1");

			 enum_declarationp1.conprint("ESTART TSTRING \"%s\"\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());

			 tree.add_node(enum_declarationp1);
			;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 5523 "pnfha.ypp"
    {
			 ASTNode enum_declarationp2("enum_declarationp2");
			 tree.add_node(enum_declarationp2);
			;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 5528 "pnfha.ypp"
    {
			 ASTNode enum_declarationp3("enum_declarationp3");

			 enum_declarationp3.conprint("EEND TVOID 0V\n");

			 tree.add_node(enum_declarationp3);
			;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 5538 "pnfha.ypp"
    {
			 ASTNode enum_strings("enum_strings");

			 enum_strings.conprint("ENAME TSTRING %s\n", (yyvsp[(1) - (1)]).to_string().get().getString().c_str());

			 tree.add_node(enum_strings);
			;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 5549 "pnfha.ypp"
    {
			 ASTNode range_declaration("range_declaration");

			 if ((yyvsp[(2) - (8)]).to_string().get() == "rtype1")
			 {
			  range_declaration.conprint("RDSTART1 TSTRING %s\n", (yyvsp[(3) - (8)]).to_string().get().getString().c_str());
			  range_declaration.conprint("RFROM1 TNUMBER %s\n", strip_quotes((yyvsp[(5) - (8)]).to_string().get()).getString().c_str());
			  range_declaration.conprint("RTO1 TNUMBER %s\n", strip_quotes((yyvsp[(8) - (8)]).to_string().get()).getString().c_str());
			  range_declaration.conprint("RDEND1 TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (8)]).to_string().get() == "rtype2")
			 {
			  range_declaration.conprint("RDSTART2 TSTRING %s\n", (yyvsp[(3) - (8)]).to_string().get().getString().c_str());
			  range_declaration.conprint("RFROM2 TNUMBER %s\n", strip_quotes((yyvsp[(5) - (8)]).to_string().get()).getString().c_str());
			  range_declaration.conprint("RTO2 TNUMBER %s\n", strip_quotes((yyvsp[(8) - (8)]).to_string().get()).getString().c_str());
			  range_declaration.conprint("RDEND2 TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(range_declaration);
			;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 5574 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  if ((yyvsp[(2) - (2)]).to_string().get().getString() == labelTable[i].name().getString())
			  {
			   declared = true;
			   String str = labelTable[i].name();
			   str += " declared already.";
			   yyerror(str.getString().c_str());
			  }
			 }

			 if (!declared)
			 {
			  labelTable.insert();
			  labelTable[labelTable.length() - 1].name((yyvsp[(2) - (2)]).to_string().get());
			  labelTable[labelTable.length() - 1].address(labelTable.length() - 2);
			 }

			 ASTNode label_declaration("label_declaration");
		         tree.add_node(label_declaration);
			;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 5598 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  if ((yyvsp[(2) - (2)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			  {
			   declared = true;
			   String str = eventLabelTable[i].name();
			   str += " declared already.";
			   yyerror(str.getString().c_str());
			  }
			 }

			 if (!declared)
			 {
			  eventLabelTable.insert();
			  eventLabelTable[eventLabelTable.length() - 1].name((yyvsp[(2) - (2)]).to_string().get());
			  eventLabelTable[eventLabelTable.length() - 1].address(eventLabelTable.length() - 2);
			 }
			 ASTNode label_declaration("label_declaration");
		         tree.add_node(label_declaration);
			;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 5621 "pnfha.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  if ((yyvsp[(2) - (2)]).to_string().get().getString() == labelTable[i].name().getString())
			  {
			   declared = true;
			   String str = labelTable[i].name();
			   str += " declared already.";
			   yyerror(str.getString().c_str());
			  }
			 }

			 if (!declared)
			 {
			  labelTable.insert();
			  labelTable[labelTable.length() - 1].name((yyvsp[(2) - (2)]).to_string().get());
			  labelTable[labelTable.length() - 1].address(labelTable.length() - 2);
			 }

			 ASTNode label_declaration("label_declaration");
		         tree.add_node(label_declaration);
			;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 5647 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 5652 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 5657 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 5662 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 5667 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 5672 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 5677 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 5682 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 5687 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 5692 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 5697 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 5702 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 5707 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 5712 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 5717 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 5722 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 5727 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 5732 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 5737 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 5742 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 5747 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 5752 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 5757 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 5762 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 5767 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 5772 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 5777 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 5782 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 5787 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 5795 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 print_command.conprint("PRINT TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 5801 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   print_command.conprint("PRINT TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   print_command.conprint("PRINT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[(2) - (2)]).to_string().get();
			   
			   String str2;
			   for (unsigned long i = 0, j = 0; i < str.length(); ++i)
			   {
			    if (str[i] == '\'')
			     continue;
			    else
			    {
			     str2[j] = str[i];
			     ++j;
			    }
			   }

			   print_command.conprint("PRINT TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
			   print_command.conprint("PRINT TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 5847 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "ver")
			  print_command.conprint("VPRINT TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 5858 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 print_command.conprint("PRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 5864 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   print_command.conprint("PRINTLN TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   print_command.conprint("PRINTLN TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[(2) - (2)]).to_string().get();
			   
			   String str2;
			   for (unsigned long i = 0, j = 0; i < str.length(); ++i)
			   {
			    if (str[i] == '\'')
			     continue;
			    else
			    {
			     str2[j] = str[i];
			     ++j;
			    }
			   }

			   print_command.conprint("PRINTLN TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
                           print_command.conprint("PRINTLN TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 5910 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "ver")
			  print_command.conprint("VPRINTLN TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 5921 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 print_command.conprint("EPRINT TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 5927 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   print_command.conprint("EPRINT TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   print_command.conprint("EPRINT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[(2) - (2)]).to_string().get();
			   
			   String str2;
			   for (unsigned long i = 0, j = 0; i < str.length(); ++i)
			   {
			    if (str[i] == '\'')
			     continue;
			    else
			    {
			     str2[j] = str[i];
			     ++j;
			    }
			   }

			   print_command.conprint("EPRINT TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
			   print_command.conprint("EPRINT TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 5973 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 print_command.conprint("EPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 5979 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   print_command.conprint("EPRINTLN TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   print_command.conprint("EPRINTLN TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[(2) - (2)]).to_string().get();
			   
			   String str2;
			   for (unsigned long i = 0, j = 0; i < str.length(); ++i)
			   {
			    if (str[i] == '\'')
			     continue;
			    else
			    {
			     str2[j] = str[i];
			     ++j;
			    }
			   }

			   print_command.conprint("EPRINTLN TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
			   print_command.conprint("EPRINTLN TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 6025 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 print_command.conprint("FPRINT TVOID 0V\n");
			;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 6030 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   print_command.conprint("FPRINT TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   print_command.conprint("FPRINT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[(2) - (2)]).to_string().get();
			   
			   String str2;
			   for (unsigned long i = 0, j = 0; i < str.length(); ++i)
			   {
			    if (str[i] == '\'')
			     continue;
			    else
			    {
			     str2[j] = str[i];
			     ++j;
			    }
			   }

			   print_command.conprint("FPRINT TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
			   print_command.conprint("FPRINT TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 6076 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 print_command.conprint("FPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 6082 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   print_command.conprint("FPRINTLN TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   print_command.conprint("FPRINTLN TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[(2) - (2)]).to_string().get();
			   
			   String str2;
			   for (unsigned long i = 0, j = 0; i < str.length(); ++i)
			   {
			    if (str[i] == '\'')
			     continue;
			    else
			    {
			     str2[j] = str[i];
			     ++j;
			    }
			   }

			   print_command.conprint("FPRINTLN TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
                           print_command.conprint("FPRINTLN TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 6128 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			
			 print_command.conprint("APREP TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 print_command.conprint("APRINT TVOID 0V\n");

			 tree.add_node(print_command);
			;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 6140 "pnfha.ypp"
    {
			 ASTNode read_command("read_command");

			 bool declared = false;
			 unsigned long address = 0;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
    		           address = varTable[scope][i].address();
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " is not declared.";
			  yyerror(str.getString().c_str());
			 }


			 PNF_Variable v;
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "void")
			 {
			  yyerror("Cannot read a void.");
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "boolean")
			 {
			  read_command.conprint("READ TBOOLEAN 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "number")
			 {
			  read_command.conprint("READ TNUMBER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "character")
			 {
			  read_command.conprint("READ TCHARACTER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "string")
			 {
			  read_command.conprint("READ TSTRING 0V\n");
			  ++varcount;
			 }
			 else
			  yyerror("Invalid type specifier.");


			 read_command.conprint("ATOC TVOID 0V\n");
			 read_command.conprint("VADD TVOID %u\n", address);
			 read_command.conprint("SWITCH TVOID 0V\n");
			 read_command.conprint("STOREA TVOID 0V\n");

			 tree.add_node(read_command);
			;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 6199 "pnfha.ypp"
    {
			 ASTNode read_command("read_command");

			 bool declared = false;
			 unsigned long address = 0;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
    		           address = varTable[scope][i].address();
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(3) - (3)]).to_string().get();
			  str += " is not declared.";
			  yyerror(str.getString().c_str());
			 }


			 PNF_Variable v;
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "void")
			 {
			  yyerror("Cannot read a void.");
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "boolean")
			 {
			  read_command.conprint("FREAD TBOOLEAN 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "number")
			 {
			  read_command.conprint("FREAD TNUMBER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "character")
			 {
			  read_command.conprint("FREAD TCHARACTER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "string")
			 {
			  read_command.conprint("FREAD TSTRING 0V\n");
			  ++varcount;
			 }
			 else
			  yyerror("Invalid type specifier.");


			 read_command.conprint("ATOC TVOID 0V\n");
			 read_command.conprint("VADD TVOID %u\n", address);
			 read_command.conprint("SWITCH TVOID 0V\n");
			 read_command.conprint("STOREA TVOID 0V\n");


			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str()) == 0)
			  {
			   PNF_Number n(0);
			   v.put(n);
			   varTable[scope][i].value(v);
			   varTable[scope][i].address(varcount - 1);
			  }
			 }
			 tree.add_node(read_command);
			;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 6272 "pnfha.ypp"
    {
			 ASTNode end_command("end_command");
			 end_command.conprint("QUIT TVOID %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(end_command);
			;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 6280 "pnfha.ypp"
    {
			 ASTNode asm_command("asm_command");
			 asm_command.conprint("%s %s %s\n", strip_quotes((yyvsp[(2) - (4)]).to_string().get()).getString().c_str(), 
					      strip_quotes((yyvsp[(3) - (4)]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[(4) - (4)]).to_string().get()).getString().c_str());
			 tree.add_node(asm_command);
			;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 6290 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(3) - (4)]).to_string().get().getString() == "memory")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			  {
			   switch ((yyvsp[(4) - (4)]).getType())
			   {
			    case TBOOLEAN:
    			     load_command.conprint("LOAD TBOOLEAN %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TNUMBER:
    	 		     load_command.conprint("LOAD TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TCHARACTER:
    			     load_command.conprint("LOAD TCHARACTER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TSTRING:
    			     load_command.conprint("LOAD TSTRING %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%calc")
			  {
			   switch ((yyvsp[(4) - (4)]).getType())
			   {
			    case TBOOLEAN:
    			     load_command.conprint("LOADC TBOOLEAN %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TNUMBER:
    	 		     load_command.conprint("LOADC TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TCHARACTER:
    			     load_command.conprint("LOADC TCHARACTER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TSTRING:
    			     load_command.conprint("LOADC TSTRING %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else
			   yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "variable")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			  {
			   switch ((yyvsp[(4) - (4)]).getType())
			   {
			    case TBOOLEAN:
    			     load_command.conprint("VLOAD TBOOLEAN %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TNUMBER:
    			     load_command.conprint("VLOAD TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TCHARACTER:
    			     load_command.conprint("VLOAD TCHARACTER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TSTRING:
    			     load_command.conprint("VLOAD TSTRING %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%calc")
			  {
			   switch ((yyvsp[(4) - (4)]).getType())
			   {
			    case TBOOLEAN:
    			     load_command.conprint("VLOADC TBOOLEAN %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TNUMBER:
    			     load_command.conprint("VLOADC TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TCHARACTER:
    			     load_command.conprint("VLOADC TCHARACTER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TSTRING:
    			     load_command.conprint("VLOADC TSTRING %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			 }
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "args")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			   load_command.conprint("ARLOAD TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "aload")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
 			   load_command.conprint("ALOAD TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
                           yyerror("Invalid register type.");
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 6420 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(3) - (4)]).to_string().get().getString() == "tend")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			  {
 			   PNF_Type_Enum t;
			   String str = (yyvsp[(4) - (4)]).to_string().get();
			   if (str.getString() == "void")
			    t = TVOID;
			   else if (str.getString() == "boolean")
			    t = TBOOLEAN;
			   else if (str.getString() == "number")
			    t = TNUMBER;
 	 		   else if (str.getString() == "character")
			    t = TCHARACTER;
			   else if (str.getString() == "string")
			    t = TSTRING;
			   else
			    yyerror("Invalid type specified.");

			   switch (t)
			   {
			    case TBOOLEAN:
    			     load_command.conprint("ELOAD TBOOLEAN 0V\n");
	 		     break;

			    case TNUMBER:
    			     load_command.conprint("ELOAD TNUMBER 0V\n");
			     break;

			    case TCHARACTER:
    			     load_command.conprint("ELOAD TCHARACTER 0V\n");
			     break;

			    case TSTRING:
    			     load_command.conprint("ELOAD TSTRING 0V\n");
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
		          }
			  else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%calc")
			  {
 			   PNF_Type_Enum t;
			   String str = (yyvsp[(4) - (4)]).to_string().get();
			   if (str.getString() == "void")
			    t = TVOID;
			   else if (str.getString() == "boolean")
			    t = TBOOLEAN;
			   else if (str.getString() == "number")
			    t = TNUMBER;
 	 		   else if (str.getString() == "character")
			    t = TCHARACTER;
			   else if (str.getString() == "string")
			    t = TSTRING;
			   else
			    yyerror("Invalid type specified.");

			   switch (t)
			   {
			    case TBOOLEAN:
    			     load_command.conprint("ELOADC TBOOLEAN 0V\n");
	 		     break;

			    case TNUMBER:
    			     load_command.conprint("ELOADC TNUMBER 0V\n");
			     break;

			    case TCHARACTER:
    			     load_command.conprint("ELOADC TCHARACTER 0V\n");
			     break;

			    case TSTRING:
    			     load_command.conprint("ELOADC TSTRING 0V\n");
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else
			   yyerror("Invalid load type.");
			 }
			 else
			  yyerror("Invalid register type.");

			 tree.add_node(load_command);
			;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 6513 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "typeof")
			 {
			   load_command.conprint("TLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "iname")
			 {
			  load_command.conprint("INLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "icount")
			 {
			  load_command.conprint("ICLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "aload")
			 {
			  load_command.conprint("ALOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "argn")
			 {
			  load_command.conprint("ARNLOAD TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 6541 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  load_command.conprint("ALOAD TBOOLEAN %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 6553 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  load_command.conprint("ALOAD TNUMBER %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 6565 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  load_command.conprint("ALOAD TCHARACTER %c\n", (yyvsp[(3) - (3)]).to_character().get());
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 6577 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  load_command.conprint("ALOAD TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 6589 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 PNF_Variable p;
			 unsigned long paddress = 0;
                         bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(4) - (4)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   p.put(varTable[scope][i].value());
			   paddress = varTable[scope][i].address();			   
			   break;
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(4) - (4)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 if ((yyvsp[(3) - (4)]).to_string().get().getString() == "memory")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			  {
			   switch (p.getType())
			   {
			    case TBOOLEAN:
    			     load_command.conprint("LOAD TBOOLEAN %g\n", p.to_number().get());
			     break;

			    case TNUMBER:
    	 		     load_command.conprint("LOAD TNUMBER %g\n", p.to_number().get());
			     break;

			    case TCHARACTER:
    			     load_command.conprint("LOAD TCHARACTER %g\n", p.to_number().get());
			     break;

			    case TSTRING:
    			     load_command.conprint("LOAD TSTRING %g\n", p.to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%calc")
			  {
			   switch (p.getType())
			   {
			    case TBOOLEAN:
    			     load_command.conprint("LOADC TBOOLEAN %g\n", p.to_number().get());
			     break;

			    case TNUMBER:
    	 		     load_command.conprint("LOADC TNUMBER %g\n", p.to_number().get());
			     break;

			    case TCHARACTER:
    			     load_command.conprint("LOADC TCHARACTER %g\n", p.to_number().get());
			     break;

			    case TSTRING:
    			     load_command.conprint("LOADC TSTRING %g\n", p.to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else
			   yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "variable")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			  {
			   switch (p.getType())
			   {
			    case TBOOLEAN:
    			     load_command.conprint("VLOAD TBOOLEAN %u\n", paddress);
			     break;

			    case TNUMBER:			     
    			     load_command.conprint("VLOAD TNUMBER %u\n", paddress);
			     break;

			    case TCHARACTER:
    			     load_command.conprint("VLOAD TCHARACTER %u\n", paddress);
			     break;

			    case TSTRING:
    			     load_command.conprint("VLOAD TSTRING %u\n", paddress);
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%calc")
			  {
			   switch (p.getType())
			   {
			    case TBOOLEAN:
    			     load_command.conprint("VLOADC TBOOLEAN %u\n", paddress);
			     break;

			    case TNUMBER:
    			     load_command.conprint("VLOADC TNUMBER %u\n", paddress);
			     break;

			    case TCHARACTER:
    			     load_command.conprint("VLOADC TCHARACTER %u\n", paddress);
			     break;

			    case TSTRING:
    			     load_command.conprint("VLOADC TSTRING %u\n", paddress);
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			 }
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "args")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			   load_command.conprint("ARLOAD TVOID %g\n", p.to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "aload")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			  {
			   switch (p.getType())
			   {
			    case TBOOLEAN:
			     load_command.conprint("ALOAD TBOOLEAN %s\n", p.to_string().get().getString().c_str());
			     break;

			    case TNUMBER:
			     load_command.conprint("ALOAD TNUMBER %g\n", p.to_number().get());
			     break;

			    case TCHARACTER:
			     load_command.conprint("ALOAD TCHARACTER %c\n", p.to_character().get());
			     break;

			    case TSTRING:
			     load_command.conprint("ALOAD TSTRING %s\n", p.to_string().get().getString().c_str());
			     break;

			    default:
			     yyerror("Invalid ID type.");
			     break;
			   }
			  }
			  else
                           yyerror("Invalid register type.");
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 6764 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "heve")
			  load_command.conprint("HEGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "sheve")
			  load_command.conprint("SHEGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "eve")
			  load_command.conprint("EGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "exe")
			  load_command.conprint("EXGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "int")
			  load_command.conprint("IGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
		  	 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(load_command);
			;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 6783 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "venum")
			 {
			  load_command.conprint("EPREP TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			  load_command.conprint("LOADE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid VTYPE2.");

			 tree.add_node(load_command);
			;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 6797 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[(3) - (4)]).to_string().get() == "rtype1")
			 {
			  load_command.conprint("RLOAD1 TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(load_command);
			;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 6810 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[(3) - (7)]).to_string().get() == "rtype2")
			 {
			  load_command.conprint("RPREP2 TSTRING %s\n", (yyvsp[(4) - (7)]).to_string().get().getString().c_str());
			  load_command.conprint("RLOAD2 TNUMBER %g\n", (yyvsp[(6) - (7)]).to_number().get());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(load_command);
			;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 6824 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 load_command.conprint("APREP TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			 load_command.conprint("AIPREP TNUMBER %g\n", (yyvsp[(5) - (6)]).to_number().get());
			 load_command.conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 6834 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 load_command.conprint("APREP TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			 load_command.conprint("AIPREP TVOID 0V\n");
			 load_command.conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 6846 "pnfha.ypp"
    {
			 ASTNode goto_command("goto_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "normal")
			 {
			  goto_command.conprint("GOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "condition")
			  goto_command.conprint("CGOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "zero")
			  goto_command.conprint("ZGOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "positive")
			  goto_command.conprint("PGOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "negative")
			  goto_command.conprint("NGOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 else
			  yyerror("Invalid goto type.");

			 tree.add_node(goto_command);
			;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 6866 "pnfha.ypp"
    {
			 ASTNode goto_command("goto_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "normal")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[(3) - (3)]).to_string().get().getString())
			   {
			    declared = true;
			    goto_command.conprint("GOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "condition")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[(3) - (3)]).to_string().get().getString())
			   {
			    declared = true;
			    goto_command.conprint("CGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "zero")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[(3) - (3)]).to_string().get().getString())
			   {
			    declared = true;
			    goto_command.conprint("ZGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "positive")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[(3) - (3)]).to_string().get().getString())
			   {
			    declared = true;
			    goto_command.conprint("PGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "negative")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[(3) - (3)]).to_string().get().getString())
			   {
			    declared = true;
			    goto_command.conprint("NGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid goto type.");

			 tree.add_node(goto_command);
			;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 6971 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("ADD TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 6977 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("ADD TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 6983 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("ADD TCHARACTER %c\n", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 6989 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("ADD TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(operator_command);
			;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 6995 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("SUB TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 7001 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("SUB TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 7007 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("MUL TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 7013 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("MUL TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 7019 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("DIV TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 7025 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("DIV TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 7031 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("MOD TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 7037 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("MOD TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 7043 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("POW TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 7049 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("POW TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 7055 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("ROOT TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 7061 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("ROOT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 7067 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("INC TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 7073 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("DEC TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 7079 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("AND TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 7085 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("OR TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 7091 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("NOT TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 7097 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("EQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 7103 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("NEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 7109 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("LSS TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 7115 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("GTR TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 7121 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("LEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 7127 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("GEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 7133 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[(2) - (2)]).to_boolean().get();

			 operator_command.conprint("EQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 7143 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[(2) - (2)]).to_boolean().get();

			 operator_command.conprint("NEQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 7153 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("EQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 7159 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("NEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 7165 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("LSS TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 7171 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("GTR TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 7177 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("LEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 7183 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("GEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 7189 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("EQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 7195 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("NEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 7201 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("LSS TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 7207 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("GTR TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 7213 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("LEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 7219 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("GEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 7225 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("BTAND TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 7231 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("BTOR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 7237 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("BTXOR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 7243 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("BTNOT TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 7249 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("BTSL TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 7255 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 operator_command.conprint("BTSR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 7265 "pnfha.ypp"
    {
			 ASTNode top_commandp1("top_commandp1");

			 intop = true;
			 ++topcounter;

			 top_commandp1.conprint("CGOTOL TSTRING \"top_iftrue_%u\"\n", topcounter);
			 top_commandp1.conprint("GOTOL TSTRING \"top_iffalse_%u\"\n", topcounter);

			 tree.add_node(top_commandp1);
			;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 7276 "pnfha.ypp"
    {
			 ASTNode top_commandp2("top_commandp2");

			 top_commandp2.conprint("LBL TSTRING \"top_iftrue_%u\"\n", topcounter);

			 tree.add_node(top_commandp2);
			;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 7284 "pnfha.ypp"
    {
			 ASTNode top_commandp3("top_commandp3");

			 top_commandp3.conprint("GOTOL TSTRING \"top_end_%u\"\n", topcounter);

			 tree.add_node(top_commandp3);
			;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 7292 "pnfha.ypp"
    {
			 ASTNode top_commandp4("top_commandp4");

			 top_commandp4.conprint("LBL TSTRING \"top_iffalse_%u\"\n", topcounter);

			 tree.add_node(top_commandp4);
			;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 7300 "pnfha.ypp"
    {
			 ASTNode top_commandp5("top_commandp5");

			 top_commandp5.conprint("GOTOL TSTRING \"top_end_%u\"\n", topcounter);
			 top_commandp5.conprint("LBL TSTRING \"top_end_%u\"\n", topcounter);

			 tree.add_node(top_commandp5);
			;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 7311 "pnfha.ypp"
    {
			 ASTNode st_command("st_command");
			 st_command.conprint("ST TVOID 0V\n");
			 tree.add_node(st_command);
			;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 7319 "pnfha.ypp"
    {
			 ASTNode stack_command("stack_command");
			 stack_command.conprint("PUSH TVOID 0V\n");
			 tree.add_node(stack_command);
			;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 7325 "pnfha.ypp"
    {
			 ASTNode stack_command("stack_command");
			 stack_command.conprint("POP TVOID 0V\n");
			 tree.add_node(stack_command);
			;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 7333 "pnfha.ypp"
    {
			 ASTNode typeof_command("typeof_command");
			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "%accumulator")
  			  typeof_command.conprint("TYPEOF TVOID 0V\n");
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "%calc")
  			  typeof_command.conprint("CTYPEOF TVOID 0V\n");
                         else
			  yyerror("Invalid register type.");
			 tree.add_node(typeof_command);
			;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 7346 "pnfha.ypp"
    {
			 ASTNode rm_command("rm_command");
			 rm_command.conprint("ATOC TVOID 0V\n");
			 tree.add_node(rm_command);
			;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 7352 "pnfha.ypp"
    {
			 ASTNode rm_command("rm_command");
			 rm_command.conprint("SWITCH TVOID 0V\n");
			 tree.add_node(rm_command);
			;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 7360 "pnfha.ypp"
    {
			 ASTNode crash_command("crash_command");
			 crash_command.conprint("CRASH TSTRING %s", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(crash_command);
			;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 7368 "pnfha.ypp"
    {
			 ASTNode version_command("version_command");

			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "pnf")
  			  version_command.conprint("VERSION TVOID 0V\n");
			 else if ((yyvsp[(2) - (2)]).to_string().get() == "pnfasm")
			  version_command.conprint("version TVOID 0V\n");
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "normal")
  			  ; // Not used yet. This is the first version.
                         else
			  yyerror("Invalid version type.");

			 tree.add_node(version_command);
			;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 7385 "pnfha.ypp"
    {
			 ASTNode halt_command("halt_command");
			 halt_command.conprint("HALT TVOID 0V\n");
			 tree.add_node(halt_command);
			;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 7393 "pnfha.ypp"
    {
			 ASTNode modt_command("modt_command");

			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "%accumulator")
  			  modt_command.conprint("MODT TVOID 0V\n");
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "%calc")
  			  modt_command.conprint("MODCT TVOID 0V\n");
                         else
			  yyerror("Invalid register type.");

			 tree.add_node(modt_command);
			;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 7408 "pnfha.ypp"
    {
 			 ASTNode subroutine_command("subroutine_command");
			 subroutine_command.conprint("RET TVOID 0V\n");
			 tree.add_node(subroutine_command);
			;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 7414 "pnfha.ypp"
    {
 			 ASTNode subroutine_command("subroutine_command");
			 subroutine_command.conprint("CALL TVOID %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(subroutine_command);
			;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 7420 "pnfha.ypp"
    {
 			 ASTNode subroutine_command("subroutine_command");

			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "sub")
			 {
 			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == labelTable[i].name().getString())
			   {
			    declared = true;
			    double d = labelTable[i].address();
			    subroutine_command.conprint("CALLL TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "heve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::hevents();
			    subroutine_command.conprint("HEVENT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "sheve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::shevents();
			    subroutine_command.conprint("SHEVENT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "eve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::events();
			    subroutine_command.conprint("EVENT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "exe")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::exceptions();
			    subroutine_command.conprint("EXCEPTION TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "int")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::ints();
			    subroutine_command.conprint("INT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(subroutine_command);
			;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 7551 "pnfha.ypp"
    {
 			 ASTNode register_command("register_command");

			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "heve")
			 {
			  register_command.conprint("HEREM TVOID 0V\n");
 			  CELabel::dechevents();
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "sheve")
			 {
			  register_command.conprint("SHEREM TVOID 0V\n");
 			  CELabel::decshevents();
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "eve")
			 {
			  register_command.conprint("EREM TVOID 0V\n");
 			  CELabel::decevents();
                         }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "exe")
			 {
			  register_command.conprint("EXREM TVOID 0V\n");
 			  CELabel::decexceptions();
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "int")
			 {
			  register_command.conprint("IREM TVOID 0V\n");
 			  CELabel::decints();
                         }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 7585 "pnfha.ypp"
    {
 			 ASTNode register_command("register_command");

			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "heve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = eventLabelTable[i].address();
			    register_command.conprint("HEADD TVOID %g\n", d);
			    if (CELabel::hevents() != 0)
 			     CELabel::inchevents();
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "sheve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = eventLabelTable[i].address();
			    register_command.conprint("SHEADD TVOID %g\n", d);
			    if (CELabel::shevents() != 0)
			     CELabel::incshevents();
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "eve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = eventLabelTable[i].address();
			    register_command.conprint("EADD TVOID %g\n", d);
			    if (CELabel::events() != 0)
 			     CELabel::incevents();
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "exe")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = eventLabelTable[i].address();
			    register_command.conprint("EXADD TVOID %g\n", d);
			    if (CELabel::exceptions() != 0)
			     CELabel::incexceptions();
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "int")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = eventLabelTable[i].address();
			    register_command.conprint("IADD TVOID %g\n", d);
			    if (CELabel::ints() != 0)
			     CELabel::incints();
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 7704 "pnfha.ypp"
    {
 			 ASTNode register_command("register_command");

			 if ((yyvsp[(2) - (4)]).to_string().get().getString() == "heve")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[(3) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(4) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[(4) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  register_command.conprint("EVLOAD TVOID %g\n", d1);
			  register_command.conprint("HEED TVOID %g\n", d2);
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "sheve")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[(3) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(4) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[(4) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  register_command.conprint("EVLOAD TVOID %g\n", d1);
			  register_command.conprint("SHEED TVOID %g\n", d2);
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "eve")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[(3) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(4) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[(4) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  register_command.conprint("EVLOAD TVOID %g\n", d1);
			  register_command.conprint("EED TVOID %g\n", d2);
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "exe")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[(3) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(4) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[(4) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  register_command.conprint("EVLOAD TVOID %g\n", d1);
			  register_command.conprint("EXED TVOID %g\n", d2);
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "int")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[(3) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(4) - (4)]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[(4) - (4)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  register_command.conprint("EVLOAD TVOID %g\n", d1);
			  register_command.conprint("IED TVOID %g\n", d2);
			 }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 7928 "pnfha.ypp"
    {
			 ASTNode register_command("register_command");

			 if ((yyvsp[(3) - (4)]).to_string().get() == "heve")
			  register_command.conprint("HEADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else if ((yyvsp[(3) - (4)]).to_string().get() == "sheve")
			  register_command.conprint("SHEADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else if ((yyvsp[(3) - (4)]).to_string().get() == "eve")
			  register_command.conprint("EADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else if ((yyvsp[(3) - (4)]).to_string().get() == "exe")
			  register_command.conprint("EXADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else if ((yyvsp[(3) - (4)]).to_string().get() == "int")
			  register_command.conprint("IADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else
			  yyerror("Invalid STYPE.");

			 tree.add_node(register_command);
			;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 7949 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get().getString() == "memory")
			   store_command.conprint("STORE TVOID %g", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "variable")
			  {
			   store_command.conprint("VSTORE TVOID %g", (yyvsp[(4) - (4)]).to_number().get());
			  }
			  else
			   yyerror("Invalid store type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%calc")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get().getString() == "memory")
			   store_command.conprint("STOREC TVOID %g", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "variable")
			  {
			   store_command.conprint("VSTOREC TVOID %g", (yyvsp[(4) - (4)]).to_number().get());
			  }
			  else
			   yyerror("Invalid store type.");
			 }
			 else
			  yyerror("Invalid register type.");

			 tree.add_node(store_command);
			;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 7980 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "%accumulator")
			 {
			  if ((yyvsp[(3) - (3)]).to_string().get().getString() == "variable")
			  {
			   store_command.conprint("VSTORE TVOID 0V");
			   ++varcount;
			  }
			  else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "tend")
			   store_command.conprint("ESTORE TVOID 0V");
			  else
			   yyerror("Invalid store type.");
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "%calc")
			 {
			  if ((yyvsp[(3) - (3)]).to_string().get().getString() == "variable")
			  {
			   store_command.conprint("VSTOREC TVOID 0V");
		 	   ++varcount;
			  }
			  else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "tend")
			   store_command.conprint("ESTOREC TVOID 0V");
			  else
			   yyerror("Invalid store type.");
			 }
			 else
			  yyerror("Invalid register type.");

			 tree.add_node(store_command);
			;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 8013 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 store_command.conprint("STOREA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 8021 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "venum")
			 {
			  store_command.conprint("EPREP TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			  store_command.conprint("STOREE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid VTYPE2.");

			 tree.add_node(store_command);
			;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 8035 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[(3) - (4)]).to_string().get() == "rtype1")
			 {
			  store_command.conprint("RSTORE1 TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(store_command);
			;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 8048 "pnfha.ypp"
    {
			 ASTNode store_command("store_command");

			 store_command.conprint("APREP TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			 store_command.conprint("AIPREP TNUMBER %g\n", (yyvsp[(5) - (6)]).to_number().get());
			 store_command.conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 8058 "pnfha.ypp"
    {
			 ASTNode store_command("store_command");

			 store_command.conprint("APREP TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			 store_command.conprint("AIPREP TVOID 0V\n");
			 store_command.conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 8070 "pnfha.ypp"
    {
			 ASTNode break_command("break_command");

			 if (inswitch)
			  break_command.conprint("GOTOL TSTRING \"after_switch_%u\"\n", switchcounter);
			 else if (inwhile)
			  break_command.conprint("GOTOL TSTRING \"while_end_%u\"\n", whilecounter);
			 else if (indowhile)
			  break_command.conprint("GOTOL TSTRING \"dowhile_end_%u\"\n", dowhilecounter);
			 else if (infor)
			  break_command.conprint("GOTOL TSTRING \"for_end_%u\"\n", forcounter);
			 else if (indofor)
			  break_command.conprint("GOTOL TSTRING \"dofor_end_%u\"\n", doforcounter);
			 else if (breakinforever)
			  break_command.conprint("GOTOL TSTRING \"forever_end_%u\"\n", forevercounter);

  			 tree.add_node(break_command);
			;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 8089 "pnfha.ypp"
    {
			 ASTNode break_command("break_command");

			 if (inswitch || inloop2)
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[(2) - (2)]).to_string().get().getString())
			   {
			    declared = true;
			    break_command.conprint("GOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(2) - (2)]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }

  			 tree.add_node(break_command);
			;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 8117 "pnfha.ypp"
    {
			 ASTNode address_command("address_command");

			 unsigned long address = 0;
			 bool declared = false;
			 if ((yyvsp[(2) - (3)]).to_string().get() == "avariable")
			 {
			  for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get() == varTable[scope][i].name())
			   {
			    declared = true;
			    address = varTable[scope][i].address();
			    break;
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get() + " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			  else
			  {
			   if (varTable.length() == 1)
                            --address;

			   address_command.conprint("VADD TVOID %u\n", address);
			  }
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get() == "alabel")
			 {
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get() == labelTable[i].name())
			   {
		            declared = true;
			    address = i - 1;
			    break;
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get() + " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			  address_command.conprint("LADD TVOID %u\n", address);
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get() == "aevent")
			 {
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[(3) - (3)]).to_string().get() == eventLabelTable[i].name())
			   {
		            declared = true;
			    address = i - 1;
			    break;
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[(3) - (3)]).to_string().get() + " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			  address_command.conprint("EADD TVOID %u\n", address);
			 }
			 else
			 {
			  yyerror("Invalid address type.");
			 }

			 tree.add_node(address_command);
			;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 8195 "pnfha.ypp"
    {
			 ASTNode add2v_command("add2v_command");

			 add2v_command.conprint("ADD2V TVOID 0V\n");

		         tree.add_node(add2v_command);
			;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 8205 "pnfha.ypp"
    {
			 ASTNode continue_command("continue_command");

			 if (inwhile)
			  continue_command.conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 else if (indowhile)
			  continue_command.conprint("GOTOL TSTRING \"dowhile_body_%u\"\n", dowhilecounter);
			 else if (infor)
			  continue_command.conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 else if (indofor)
			  continue_command.conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 else if (breakinforever)
			  continue_command.conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);

		         tree.add_node(continue_command);
			;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 8224 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "void")
			   check_command.conprint("VCHECK TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get() == "number")
			   check_command.conprint("VCHECK TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "void")
			   check_command.conprint("VSUPP TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get() == "number")
			   check_command.conprint("VSUPP TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 8251 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "boolean")
			   check_command.conprint("VCHECK TBOOLEAN %s\n", (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "boolean")
			   check_command.conprint("VSUPP TBOOLEAN %s\n", (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 8274 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "character")
			   check_command.conprint("VCHECK TCHARACTER %c\n", (yyvsp[(4) - (4)]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "character")
			   check_command.conprint("VSUPP TCHARACTER %c\n", (yyvsp[(4) - (4)]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 8297 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "string")
			   check_command.conprint("VCHECK TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "string")
			   check_command.conprint("VSUPP TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 8320 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "instruction")
			 {
   		          check_command.conprint("ISUPP TNUMBER %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 if ((yyvsp[(2) - (3)]).to_string().get() == "type")
			 {
			  check_command.conprint("TSUPP TNUMBER %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 8339 "pnfha.ypp"
    {
			 ASTNode comment_command("comment_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "l2")
			 {
			  String str = strip_quotes((yyvsp[(3) - (3)]).to_string().get());
			  comment_command.conprint(";\\ %s\n", str.getString().c_str());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get() == "l1")
			 {
			  comment_command.conprint("COMMENT TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else
			 {
			  yyerror("Invalid comment type.");
                         }

		         tree.add_node(comment_command);
			;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 8361 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "input")
			 {
			  if ((yyvsp[(3) - (3)]).to_string().get() == "in")
			   file_command.conprint("FIMODE TSTRING \"in\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "binary")
			   file_command.conprint("FIMODE TSTRING \"binary\"\n");
			  else
			   yyerror("Invalid file mode command.");
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get() == "output")
			 {
			  if ((yyvsp[(3) - (3)]).to_string().get() == "out")
			   file_command.conprint("FOMODE TSTRING \"out\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "binary")
			   file_command.conprint("FOMODE TSTRING \"binary\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "ate")
			   file_command.conprint("FOMODE TSTRING \"ate\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "app")
			   file_command.conprint("FOMODE TSTRING \"app\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "trunc")
			   file_command.conprint("FOMODE TSTRING \"trunc\"\n");
			  else
			   yyerror("Invalid file mode command.");
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 8394 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "input")
			 {
			  file_command.conprint("FIOPEN TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get() == "output")
			 {
  			  file_command.conprint("FOOPEN TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 8411 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "input")
			 {
			  file_command.conprint("FICLOSE TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get() == "output")
			 {
  			  file_command.conprint("FOCLOSE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 8428 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 file_command.conprint("FIEOF TVOID 0V\n");

			 tree.add_node(file_command);
			;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 8438 "pnfha.ypp"
    {
			 ASTNode meml_command("meml_command");

			 meml_command.conprint("MEML TVOID 0V\n");

			 tree.add_node(meml_command);
			;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 8448 "pnfha.ypp"
    {
			 ASTNode pnfasm_command("pnfasm_command");

			 pnfasm_command.conprint("pnf %s %s %s\n", strip_quotes((yyvsp[(2) - (4)]).to_string().get()).getString().c_str(), 
						 strip_quotes((yyvsp[(3) - (4)]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[(4) - (4)]).to_string().get()).getString().c_str());

			 tree.add_node(pnfasm_command);
			;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 8459 "pnfha.ypp"
    {
			 ASTNode array_length_command("array_length_command");
			
			 array_length_command.conprint("APREP TSTRING %s\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			 array_length_command.conprint("ALENGTH TVOID 0V\n");

			 tree.add_node(array_length_command);
			;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 8469 "pnfha.ypp"
    {
			 ASTNode dup_command("dup_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "%accumulator")
			 {
			  dup_command.conprint("DUP TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get() == "%calc")
			 {
			  dup_command.conprint("CDUP TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid register.");

			 tree.add_node(dup_command);
			;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 8487 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 pp_directive.conprint("#BIN#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 8493 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 pp_directive.conprint("#PBIN#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 8499 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 pp_directive.conprint("#LIB#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 8507 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#include %s", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 8513 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#include <%s>", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 8519 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 8525 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#import <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 8531 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), 
						    (yyvsp[(3) - (3)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 8538 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 8544 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#endm\n");
			 tree.add_node(pp_statement);
		 	;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 8550 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 8556 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 8562 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#infdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 8568 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#else\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 8574 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("#endif\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 8580 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("_DATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 8586 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("_TIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 8592 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("_LINE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 8598 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("_FILE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 8604 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("_CDATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 8610 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("_CTIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 8616 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%include %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 8622 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%include <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 8628 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 8634 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%import <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 8640 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), 
						     (yyvsp[(3) - (3)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 8647 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 8653 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%endm\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 8659 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 8665 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 8671 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%infdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 8677 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%else\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 8683 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%endif\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 8689 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%_DATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 8695 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%_TIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 8701 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%_LINE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 8707 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%_FILE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 8713 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%_CDATE()\n");
			 tree.add_node(pp_statement);
			;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 8719 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 pp_statement.conprint("%%_CTIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;



/* Line 1455 of yacc.c  */
#line 12928 "pnfha.tab.cpp"
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
#line 8725 "pnfha.ypp"

/* Additional C/C++ Code */
