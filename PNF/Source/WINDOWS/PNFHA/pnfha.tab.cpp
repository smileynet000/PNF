
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
/*
Copyright (C) 2019 Dennis Earl Smiley

This file is part of pnfha.

    pnfha is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    pnfha is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with pnfha.  If not, see <https://www.gnu.org/licenses/>. 
*/
/*
CHANGELOG
=========

5/3/19 Origional a-a-a - 1. The first version.
			 2. Fixed bug.
			 3. Added functions.
			 4. Debugged functions...
			 5. Finished debugging function parameters.
			 6. Added return type specification instructions.
*/
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

void actual_parameters();
void actual_parameters2();

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
Array<CLabel> parameterTable;

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


unsigned long pnum = 0;
unsigned long pnum3 = 0;
unsigned long rnum = 0;


Function_Stack funcstk;
Function * funcptr = NULL;


Array<String> frets;
Array<String> fparams;

Array<String> frets2;
Array<String> fparams2;

Array<String> frets3;
Array<String> fparams3;

Array<String> frets4;
Array<String> fparams4;

Array<String> frets5;
Array<String> fparams5;

Array<String> frets6;
Array<String> fparams6;


PNF_Variable fsaveid;
PNF_Variable fsaveid2;
PNF_Variable fsaveid3;

PNF_Variable saveid3;

PNF_Variable saveexp;
PNF_Variable saveexp2;

unsigned long fsaveindex = 0;
bool saw_12 = false;
unsigned long fsavepindex = 0;
unsigned long fsaveindex2 = 0;

PNF_Variable savenumber;


Array < Array<Var> > funcps;


ASTTree tree;


/* Line 189 of yacc.c  */
#line 833 "pnfha.tab.cpp"

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
     THEN = 382,
     ENDIF = 383,
     DONEIF = 384,
     ATOSP = 385,
     SPTOA = 386,
     FUNCTION = 387,
     FUNCDEF = 388,
     FUNCCALL = 389,
     FRET = 390,
     FPARAMETER = 391,
     PBIN = 392,
     PPBIN = 393,
     PLIB = 394,
     PINCLUDE = 395,
     PIMPORT = 396,
     PDEFINE = 397,
     PMACRO = 398,
     PENDM = 399,
     PUNDEF = 400,
     PIFDEF = 401,
     PIFNDEF = 402,
     PELSE = 403,
     PENDIF = 404,
     PPDATE = 405,
     PPTIME = 406,
     PPLINE = 407,
     PPFILE = 408,
     PPCDATE = 409,
     PPCTIME = 410,
     PPINCLUDE = 411,
     PPIMPORT = 412,
     PPDEFINE = 413,
     PPMACRO = 414,
     PPENDM = 415,
     PPUNDEF = 416,
     PPIFDEF = 417,
     PPIFNDEF = 418,
     PPELSE = 419,
     PPENDIF = 420,
     PPPDATE = 421,
     PPPTIME = 422,
     PPPLINE = 423,
     PPPFILE = 424,
     PPPCDATE = 425,
     PPPCTIME = 426
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
#line 1046 "pnfha.tab.cpp"

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
#define YYLAST   1727

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  175
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  173
/* YYNRULES -- Number of rules.  */
#define YYNRULES  528
/* YYNRULES -- Number of states.  */
#define YYNSTATES  943

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   429

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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    13,    15,    16,
      19,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    44,    47,    50,    53,    57,    61,    63,    65,    67,
      68,    69,    70,    71,    72,    87,    88,    89,    94,    96,
      97,    98,    99,   100,   113,   114,   115,   116,   128,   129,
     132,   135,   136,   142,   143,   144,   149,   150,   153,   156,
     157,   158,   165,   166,   167,   172,   173,   176,   178,   180,
     182,   183,   186,   187,   188,   189,   198,   199,   200,   201,
     202,   203,   215,   216,   217,   218,   219,   220,   235,   236,
     237,   238,   239,   240,   241,   258,   259,   263,   267,   269,
     272,   274,   276,   278,   280,   282,   284,   286,   288,   290,
     292,   296,   298,   301,   305,   309,   313,   315,   319,   323,
     327,   331,   335,   338,   342,   346,   349,   352,   355,   358,
     362,   366,   370,   373,   377,   381,   385,   387,   391,   395,
     399,   403,   407,   411,   415,   418,   421,   424,   427,   431,
     433,   437,   440,   444,   446,   449,   452,   456,   460,   464,
     468,   472,   476,   480,   483,   487,   491,   494,   497,   500,
     503,   507,   511,   515,   519,   523,   527,   528,   533,   537,
     541,   545,   549,   553,   557,   561,   565,   569,   573,   577,
     581,   585,   589,   593,   597,   601,   605,   609,   613,   617,
     621,   625,   629,   633,   637,   641,   645,   649,   653,   657,
     661,   665,   669,   673,   677,   681,   685,   689,   693,   697,
     701,   705,   709,   713,   717,   721,   725,   729,   732,   736,
     740,   744,   748,   750,   754,   755,   756,   757,   758,   759,
     772,   773,   777,   778,   781,   785,   787,   789,   791,   793,
     796,   801,   804,   806,   808,   810,   816,   823,   828,   834,
     835,   836,   845,   847,   851,   860,   863,   866,   869,   871,
     873,   874,   883,   884,   886,   893,   895,   902,   904,   911,
     913,   920,   925,   927,   932,   934,   939,   941,   946,   948,
     949,   950,   961,   965,   967,   971,   977,   979,   983,   989,
     991,   995,  1001,  1003,  1007,  1013,  1015,  1019,  1025,  1027,
    1029,  1031,  1033,  1035,  1037,  1039,  1041,  1043,  1045,  1047,
    1049,  1051,  1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,
    1069,  1071,  1073,  1075,  1077,  1079,  1081,  1083,  1085,  1087,
    1089,  1092,  1095,  1097,  1100,  1103,  1105,  1108,  1110,  1113,
    1115,  1118,  1120,  1123,  1127,  1131,  1135,  1138,  1143,  1148,
    1153,  1156,  1160,  1164,  1168,  1172,  1177,  1181,  1185,  1190,
    1198,  1205,  1211,  1212,  1221,  1222,  1231,  1232,  1241,  1242,
    1251,  1255,  1259,  1261,  1264,  1267,  1270,  1272,  1275,  1277,
    1280,  1282,  1285,  1287,  1290,  1292,  1295,  1297,  1300,  1302,
    1304,  1306,  1308,  1310,  1312,  1314,  1316,  1318,  1320,  1322,
    1325,  1328,  1331,  1334,  1337,  1340,  1343,  1346,  1349,  1352,
    1355,  1358,  1361,  1364,  1366,  1368,  1370,  1372,  1374,  1376,
    1378,  1379,  1380,  1381,  1382,  1392,  1394,  1396,  1398,  1401,
    1403,  1405,  1407,  1409,  1412,  1415,  1417,  1420,  1422,  1425,
    1429,  1432,  1436,  1441,  1446,  1451,  1454,  1458,  1461,  1465,
    1470,  1477,  1483,  1485,  1488,  1492,  1494,  1496,  1501,  1506,
    1511,  1516,  1520,  1524,  1528,  1532,  1535,  1537,  1539,  1544,
    1549,  1552,  1554,  1556,  1558,  1559,  1565,  1566,  1573,  1580,
    1587,  1589,  1591,  1593,  1596,  1601,  1604,  1609,  1613,  1616,
    1618,  1621,  1624,  1627,  1629,  1631,  1633,  1635,  1637,  1639,
    1641,  1643,  1646,  1651,  1654,  1659,  1663,  1666,  1668,  1671,
    1674,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1691
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     176,     0,    -1,    -1,   176,   177,    -1,    -1,   178,   172,
      -1,   179,    -1,     1,    -1,    -1,   180,   181,    -1,   179,
      39,   181,    -1,   186,    -1,    38,    -1,   182,    -1,   183,
      -1,   185,    -1,   184,    -1,   245,    -1,   346,    -1,   347,
      -1,   247,    38,    -1,   268,    38,    -1,   299,    38,    -1,
      44,    41,    -1,    73,    44,    41,    -1,    74,    44,    41,
      -1,   187,    -1,   196,    -1,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    29,   181,    30,   188,   127,   189,   181,
     190,   128,   191,   193,   192,   195,    -1,    -1,    -1,    86,
     194,   181,   128,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      64,    29,   247,    30,    31,   197,   204,   198,   208,   199,
     200,    32,    -1,    -1,    -1,    -1,    65,    29,   181,    30,
     201,    31,   210,   202,   215,   203,    32,    -1,    -1,   205,
     206,    -1,   204,   206,    -1,    -1,    87,   247,   207,    41,
     181,    -1,    -1,    -1,    89,    41,   209,   181,    -1,    -1,
     211,   212,    -1,   210,   212,    -1,    -1,    -1,    88,   247,
     213,    41,   214,   181,    -1,    -1,    -1,    90,    41,   216,
     181,    -1,    -1,   218,   220,    -1,   224,    -1,   230,    -1,
     236,    -1,    -1,   243,   219,    -1,    -1,    -1,    -1,    93,
      29,   221,   181,   222,    30,   223,   181,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    97,   226,   181,    93,   227,    29,
     228,   181,   229,    30,    -1,    -1,    -1,    -1,    -1,    -1,
     231,    99,    29,   232,   181,    38,   233,   181,    38,   234,
     181,   235,    30,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,   237,   181,   238,    99,    29,   239,   181,    38,
     240,   181,    38,   241,   181,   242,    30,    -1,    -1,   101,
     244,   181,    -1,    31,   246,    32,    -1,   179,    -1,   179,
     246,    -1,   248,    -1,   249,    -1,   250,    -1,   251,    -1,
     252,    -1,   253,    -1,   254,    -1,   256,    -1,   257,    -1,
      33,    -1,    29,   248,    30,    -1,    34,    -1,     7,   249,
      -1,   249,    26,   249,    -1,   249,    27,   249,    -1,    29,
     249,    30,    -1,    35,    -1,   250,    14,   250,    -1,   250,
      15,   250,    -1,   250,    13,   250,    -1,   250,    12,   250,
      -1,   250,    11,   250,    -1,    15,   250,    -1,   250,    10,
     250,    -1,   250,     9,   250,    -1,     4,   250,    -1,   250,
       4,    -1,     3,   250,    -1,   250,     3,    -1,   250,     8,
     250,    -1,   250,    24,   250,    -1,   250,    25,   250,    -1,
       6,   250,    -1,   250,    17,   250,    -1,   250,    16,   250,
      -1,    29,   250,    30,    -1,    36,    -1,   251,    14,   251,
      -1,   251,    15,   251,    -1,   251,    13,   251,    -1,   251,
      12,   251,    -1,   251,    11,   251,    -1,   251,    10,   251,
      -1,   251,     9,   251,    -1,     4,   251,    -1,   251,     4,
      -1,     3,   251,    -1,   251,     3,    -1,    29,   251,    30,
      -1,    37,    -1,   252,    14,   252,    -1,    43,   252,    -1,
      29,   252,    30,    -1,    44,    -1,     8,   253,    -1,     7,
     253,    -1,   253,    26,   253,    -1,   253,    27,   253,    -1,
     253,    14,   253,    -1,   253,    15,   253,    -1,   253,    13,
     253,    -1,   253,    12,   253,    -1,   253,    11,   253,    -1,
      15,   253,    -1,   253,    10,   253,    -1,   253,     9,   253,
      -1,     4,   253,    -1,   253,     4,    -1,     3,   253,    -1,
     253,     3,    -1,    29,   253,    30,    -1,   250,    23,   250,
      -1,   250,    22,   250,    -1,   250,    21,   250,    -1,   250,
      19,   250,    -1,   250,    20,   250,    -1,    -1,   250,    18,
     250,   255,    -1,    29,   256,    30,    -1,    44,    26,   249,
      -1,   249,    26,    44,    -1,    44,    27,   249,    -1,   249,
      27,    44,    -1,    44,    14,   250,    -1,    44,    15,   250,
      -1,    44,    13,   250,    -1,    44,    12,   250,    -1,    44,
      10,   250,    -1,    44,     9,   250,    -1,   250,    14,    44,
      -1,   250,    15,    44,    -1,   250,    13,    44,    -1,   250,
      12,    44,    -1,   250,    10,    44,    -1,   250,     9,    44,
      -1,    44,    14,   251,    -1,    44,    15,   251,    -1,    44,
      13,   251,    -1,    44,    12,   251,    -1,    44,    10,   251,
      -1,    44,     9,   251,    -1,   251,    14,    44,    -1,   251,
      15,    44,    -1,   251,    13,    44,    -1,   251,    12,    44,
      -1,   251,    10,    44,    -1,   251,     9,    44,    -1,    44,
      14,   252,    -1,   252,    14,    44,    -1,   250,    23,    44,
      -1,   250,    22,    44,    -1,   250,    21,    44,    -1,   250,
      19,    44,    -1,   250,    20,    44,    -1,   250,    18,    44,
      -1,    44,    23,   250,    -1,    44,    22,   250,    -1,    44,
      21,   250,    -1,    44,    19,   250,    -1,    44,    20,   250,
      -1,    44,    18,   250,    -1,    44,     8,   250,    -1,    44,
      24,   250,    -1,    44,    25,   250,    -1,   250,     8,    44,
      -1,   250,    24,    44,    -1,   250,    25,    44,    -1,     6,
      44,    -1,    44,    17,   250,    -1,    44,    16,   250,    -1,
     250,    17,    44,    -1,   250,    16,    44,    -1,   258,    -1,
      29,   257,    30,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     296,    44,   259,    29,   260,   264,   261,   262,    30,   263,
     281,    -1,    -1,   266,   265,   281,    -1,    -1,   267,   247,
      -1,   266,    39,   247,    -1,   269,    -1,   278,    -1,   273,
      -1,   277,    -1,    45,    44,    -1,    45,    44,    28,   247,
      -1,   100,    44,    -1,   270,    -1,   271,    -1,   272,    -1,
     114,    37,    37,    28,    37,    -1,   119,   117,    37,    37,
      28,    37,    -1,   119,   117,    37,    37,    -1,   122,    37,
     120,   250,   121,    -1,    -1,    -1,   113,    44,    28,    31,
     274,   276,   275,    32,    -1,    37,    -1,   276,    39,    37,
      -1,   116,   117,    37,    28,    37,   118,   118,    37,    -1,
      73,    44,    -1,    74,    44,    -1,    92,    44,    -1,   279,
      -1,   290,    -1,    -1,   133,   294,    44,    29,   282,    30,
     280,   281,    -1,    -1,   286,    -1,   282,    39,    45,    44,
      41,    52,    -1,   287,    -1,   283,    39,    45,    44,    41,
      52,    -1,   288,    -1,   284,    39,    45,    44,    41,    52,
      -1,   289,    -1,   285,    39,    45,    44,    41,    52,    -1,
      45,    44,    41,    52,    -1,    33,    -1,    45,    44,    41,
      52,    -1,    33,    -1,    45,    44,    41,    52,    -1,    33,
      -1,    45,    44,    41,    52,    -1,    33,    -1,    -1,    -1,
     132,   295,    44,    29,   283,    30,   291,   293,   292,   281,
      -1,    31,   246,    32,    -1,    33,    -1,    45,    41,    52,
      -1,   294,    39,    45,    41,    52,    -1,    33,    -1,    45,
      41,    52,    -1,   295,    39,    45,    41,    52,    -1,    33,
      -1,    45,    41,    52,    -1,   296,    39,    45,    41,    52,
      -1,    33,    -1,    45,    41,    52,    -1,   297,    39,    45,
      41,    52,    -1,    33,    -1,    45,    41,    52,    -1,   298,
      39,    45,    41,    52,    -1,   300,    -1,   301,    -1,   302,
      -1,   303,    -1,   304,    -1,   309,    -1,   310,    -1,   316,
      -1,   317,    -1,   318,    -1,   319,    -1,   320,    -1,   321,
      -1,   322,    -1,   323,    -1,   324,    -1,   325,    -1,   326,
      -1,   327,    -1,   328,    -1,   329,    -1,   330,    -1,   331,
      -1,   332,    -1,   333,    -1,   334,    -1,   335,    -1,   336,
      -1,   337,    -1,   338,    -1,   339,    -1,    46,    -1,    46,
     247,    -1,    46,    77,    -1,    47,    -1,    47,   247,    -1,
      47,    77,    -1,    48,    -1,    48,   247,    -1,    49,    -1,
      49,   247,    -1,   109,    -1,   109,   247,    -1,   110,    -1,
     110,   247,    -1,    46,   122,    37,    -1,    53,    52,    44,
      -1,   111,    52,    44,    -1,    50,   250,    -1,    51,    37,
      37,   252,    -1,    54,    62,    55,   250,    -1,    54,    62,
      55,    52,    -1,    54,    55,    -1,    54,    55,   249,    -1,
      54,    55,   250,    -1,    54,    55,   251,    -1,    54,    55,
     252,    -1,    54,    62,    55,    44,    -1,    54,    75,   250,
      -1,    54,   115,    37,    -1,    54,   116,   117,    37,    -1,
      54,   116,   117,    37,   120,   250,   121,    -1,    54,   122,
      37,   120,   250,   121,    -1,    54,   122,    37,   120,   121,
      -1,    -1,    54,   345,    55,   250,    41,   249,   305,   281,
      -1,    -1,    54,   345,    55,   250,    41,   250,   306,   281,
      -1,    -1,    54,   345,    55,   250,    41,   251,   307,   281,
      -1,    -1,    54,   345,    55,   250,    41,   252,   308,   281,
      -1,    56,    57,   250,    -1,    56,    57,    44,    -1,    14,
      -1,    14,   250,    -1,    14,   251,    -1,    14,   252,    -1,
      15,    -1,    42,   250,    -1,    13,    -1,    13,   250,    -1,
      12,    -1,    12,   250,    -1,    11,    -1,    11,   250,    -1,
      10,    -1,    10,   250,    -1,     9,    -1,     9,   250,    -1,
       4,    -1,     3,    -1,    26,    -1,    27,    -1,     7,    -1,
      23,    -1,    22,    -1,    21,    -1,    19,    -1,    20,    -1,
      18,    -1,    23,   249,    -1,    22,   249,    -1,    23,   250,
      -1,    22,   250,    -1,    21,   250,    -1,    19,   250,    -1,
      20,   250,    -1,    18,   250,    -1,    23,   251,    -1,    22,
     251,    -1,    21,   251,    -1,    19,   251,    -1,    20,   251,
      -1,    18,   251,    -1,     8,    -1,    24,    -1,    25,    -1,
       6,    -1,    17,    -1,    16,    -1,   311,    -1,    -1,    -1,
      -1,    -1,   181,    40,   312,   313,   181,   314,    41,   315,
     181,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    62,
      -1,    63,    -1,   130,    -1,   131,    -1,    64,    -1,    66,
     252,    -1,    67,    68,    -1,    69,    -1,    70,    62,    -1,
      71,    -1,    72,   250,    -1,    72,    75,    44,    -1,    81,
      75,    -1,    82,    75,    44,    -1,    83,    75,    44,    44,
      -1,    82,   123,    75,   250,    -1,    84,    62,    55,   250,
      -1,    84,    55,    -1,    84,    62,    55,    -1,    84,    96,
      -1,    84,   115,    37,    -1,    84,   116,   117,    37,    -1,
      84,   122,    37,   120,   250,   121,    -1,    84,   122,    37,
     120,   121,    -1,    91,    -1,    91,    44,    -1,    94,    76,
      44,    -1,    95,    -1,   102,    -1,   103,    77,    52,   250,
      -1,   103,    77,    52,   249,    -1,   103,    77,    52,   251,
      -1,   103,    77,    52,   252,    -1,   103,    77,   250,    -1,
     104,    78,   252,    -1,   105,    79,    80,    -1,   106,    79,
     252,    -1,   107,    79,    -1,   108,    -1,   112,    -1,   124,
      37,    37,    37,    -1,   122,    37,   118,   125,    -1,   126,
      62,    -1,   135,    -1,   340,    -1,   342,    -1,    -1,   344,
      44,    52,   341,   281,    -1,    -1,   344,    44,    52,    52,
     343,   281,    -1,   136,   297,    44,    29,   284,    30,    -1,
     132,   298,    44,    29,   285,    30,    -1,   137,    -1,   138,
      -1,   139,    -1,   140,    37,    -1,   140,   173,    37,   174,
      -1,   141,    37,    -1,   141,   173,    37,   174,    -1,   142,
      37,    37,    -1,   143,    37,    -1,   144,    -1,   145,    37,
      -1,   146,    37,    -1,   147,    37,    -1,   148,    -1,   149,
      -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,   154,
      -1,   155,    -1,   156,    37,    -1,   156,   173,    37,   174,
      -1,   157,    37,    -1,   157,   173,    37,   174,    -1,   158,
      37,    37,    -1,   159,    37,    -1,   160,    -1,   161,    37,
      -1,   162,    37,    -1,   163,    37,    -1,   164,    -1,   165,
      -1,   166,    -1,   167,    -1,   168,    -1,   169,    -1,   170,
      -1,   171,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   963,   963,   964,   967,   967,   972,   973,   976,   976,
     981,   984,   986,   988,   990,   992,   994,   996,   999,  1000,
    1003,  1010,  1017,  1024,  1057,  1065,  1075,  1081,  1086,  1097,
    1103,  1112,  1119,  1124,  1096,  1139,  1140,  1139,  1161,  1165,
    1204,  1233,  1238,  1164,  1250,  1265,  1271,  1249,  1285,  1285,
    1290,  1294,  1293,  1337,  1338,  1337,  1348,  1348,  1353,  1357,
    1388,  1356,  1403,  1404,  1403,  1414,  1414,  1423,  1428,  1433,
    1439,  1438,  1458,  1468,  1474,  1457,  1495,  1505,  1512,  1520,
    1526,  1495,  1544,  1548,  1558,  1566,  1576,  1544,  1596,  1609,
    1618,  1624,  1633,  1643,  1595,  1659,  1658,  1678,  1682,  1687,
    1694,  1695,  1703,  1705,  1707,  1709,  1711,  1713,  1715,  1720,
    1730,  1733,  1749,  1763,  1779,  1795,  1798,  1813,  1819,  1825,
    1831,  1837,  1843,  1851,  1858,  1865,  1871,  1877,  1883,  1889,
    1897,  1906,  1914,  1921,  1929,  1937,  1941,  1954,  1961,  1968,
    1975,  1981,  1988,  1995,  2002,  2008,  2014,  2020,  2026,  2030,
    2043,  2068,  2075,  2079,  2150,  2190,  2227,  2304,  2383,  2463,
    2501,  2539,  2577,  2615,  2628,  2666,  2704,  2732,  2760,  2788,
    2816,  2819,  2830,  2841,  2852,  2863,  2875,  2874,  2897,  2898,
    2947,  2996,  3045,  3094,  3136,  3178,  3220,  3262,  3304,  3346,
    3388,  3430,  3472,  3514,  3556,  3598,  3640,  3682,  3724,  3766,
    3808,  3850,  3892,  3934,  3976,  4018,  4060,  4102,  4166,  4230,
    4275,  4320,  4365,  4410,  4455,  4500,  4545,  4590,  4635,  4680,
    4725,  4770,  4815,  4860,  4905,  4950,  4995,  5040,  5077,  5122,
    5167,  5212,  5259,  5263,  5270,  5277,  5280,  5289,  5293,  5269,
    5307,  5306,  5339,  5339,  5406,  5541,  5546,  5551,  5556,  5563,
    5621,  5702,  5737,  5742,  5747,  5754,  5766,  5781,  5797,  5809,
    5817,  5808,  5831,  5839,  5845,  5870,  5894,  5917,  5941,  5942,
    5946,  5945,  5989,  5991,  6084,  6196,  6241,  6300,  6345,  6404,
    6449,  6508,  6526,  6534,  6552,  6560,  6578,  6586,  6604,  6613,
    6626,  6612,  6646,  6651,  6659,  6745,  6827,  6831,  6879,  6929,
    6932,  6994,  7201,  7205,  7253,  7303,  7307,  7355,  7407,  7412,
    7417,  7422,  7427,  7432,  7437,  7442,  7447,  7452,  7457,  7462,
    7467,  7472,  7477,  7482,  7487,  7492,  7497,  7502,  7507,  7512,
    7517,  7522,  7527,  7532,  7537,  7542,  7547,  7552,  7557,  7561,
    7567,  7613,  7624,  7630,  7676,  7687,  7693,  7739,  7745,  7791,
    7796,  7842,  7848,  7894,  7906,  7965,  8038,  8046,  8055,  8192,
    8285,  8313,  8324,  8341,  8352,  8363,  8538,  8557,  8571,  8584,
    8598,  8608,  8619,  8618,  8652,  8651,  8685,  8684,  8718,  8717,
    8752,  8772,  8877,  8883,  8889,  8895,  8901,  8907,  8913,  8919,
    8925,  8931,  8937,  8943,  8949,  8955,  8961,  8967,  8973,  8979,
    8985,  8991,  8997,  9003,  9009,  9015,  9021,  9027,  9033,  9039,
    9049,  9059,  9065,  9071,  9077,  9083,  9089,  9095,  9101,  9107,
    9113,  9119,  9125,  9131,  9137,  9143,  9149,  9155,  9161,  9167,
    9172,  9183,  9189,  9198,  9171,  9218,  9226,  9232,  9240,  9253,
    9259,  9263,  9267,  9275,  9283,  9300,  9308,  9323,  9329,  9335,
    9466,  9500,  9619,  9843,  9864,  9897,  9906,  9939,  9947,  9961,
    9974,  9984,  9996, 10014, 10042, 10120, 10130, 10149, 10176, 10199,
   10222, 10245, 10264, 10286, 10319, 10336, 10353, 10363, 10373, 10384,
   10394, 10413, 10419, 10420, 10424, 10423, 10478, 10477, 10534, 10540,
   10546, 10552, 10558, 10566, 10572, 10578, 10584, 10590, 10597, 10603,
   10609, 10615, 10621, 10627, 10633, 10639, 10645, 10651, 10657, 10663,
   10669, 10675, 10681, 10687, 10693, 10699, 10706, 10712, 10718, 10724,
   10730, 10736, 10742, 10748, 10754, 10760, 10766, 10772, 10778
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
  "PNFASM", "LENGTH", "DUP", "THEN", "ENDIF", "DONEIF", "ATOSP", "SPTOA",
  "FUNCTION", "FUNCDEF", "FUNCCALL", "FRET", "FPARAMETER", "PBIN", "PPBIN",
  "PLIB", "PINCLUDE", "PIMPORT", "PDEFINE", "PMACRO", "PENDM", "PUNDEF",
  "PIFDEF", "PIFNDEF", "PELSE", "PENDIF", "PPDATE", "PPTIME", "PPLINE",
  "PPFILE", "PPCDATE", "PPCTIME", "PPINCLUDE", "PPIMPORT", "PPDEFINE",
  "PPMACRO", "PPENDM", "PPUNDEF", "PPIFDEF", "PPIFNDEF", "PPELSE",
  "PPENDIF", "PPPDATE", "PPPTIME", "PPPLINE", "PPPFILE", "PPPCDATE",
  "PPPCTIME", "\"\\n\"", "\"<\"", "\">\"", "$accept", "input", "line",
  "$@1", "statement", "$@2", "stmt", "expression_statement",
  "declaration_statement", "command_statement", "label_statement",
  "control_statement", "if_statement", "$@3", "$@4", "$@5", "$@6", "$@7",
  "opt_else", "$@8", "eif", "switch_statement", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "case_statements", "$@16",
  "case_statement", "$@17", "opt_default_statement", "$@18",
  "case_statements2", "$@19", "case_statement2", "$@20", "$@21",
  "opt_default_statement2", "$@22", "loop_statement", "$@23", "$@24",
  "while_loop", "$@25", "$@26", "$@27", "whileb_loop", "$@28", "$@29",
  "$@30", "$@31", "$@32", "for_loop", "$@33", "$@34", "$@35", "$@36",
  "$@37", "forb_loop", "$@38", "$@39", "$@40", "$@41", "$@42", "$@43",
  "forever_loop", "$@44", "statement_block", "statements", "expression",
  "void_expression", "boolean_expression", "number_expression",
  "character_expression", "string_expression", "id_expression",
  "relational_expression", "@45", "mixed_expression",
  "function_expression", "function_command", "$@46", "$@47", "$@48",
  "$@49", "$@50", "actual_function_parameters", "@51", "opt_expression",
  "$@53", "declaration", "variable_declaration", "enumv_declaration",
  "rangev_declaration", "array_declaration", "enum_declaration", "$@54",
  "$@55", "enum_strings", "range_declaration", "label_declaration",
  "function_declaration", "$@56", "nothing", "parameter_declaration",
  "parameter_declaration2", "parameter_declaration5",
  "parameter_declaration6", "opt_var", "opt_var2", "opt_var5", "opt_var6",
  "function_declaration2", "$@57", "$@58", "function_body", "vars",
  "vars2", "vars3", "vars5", "vars6", "command", "print_command",
  "read_command", "end_command", "asm_command", "load_command", "$@59",
  "$@60", "$@61", "$@62", "goto_command", "operator_command",
  "top_command", "$@63", "$@64", "$@65", "$@66", "st_command",
  "stack_command", "typeof_command", "rm_command", "crash_command",
  "version_command", "halt_command", "modt_command", "subroutine_command",
  "register_command", "store_command", "break_command", "address_command",
  "add2v_command", "continue_command", "check_command", "comment_command",
  "file_command", "meml_command", "pnfasm_command", "array_length_command",
  "dup_command", "fret_command", "parameter_command", "psig", "$@67",
  "psig2", "$@68", "signature", "signature2", "pp_directive",
  "pp_statement", 0
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   175,   176,   176,   178,   177,   177,   177,   180,   179,
     179,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     182,   183,   184,   185,   185,   185,   186,   186,   186,   188,
     189,   190,   191,   192,   187,   193,   194,   193,   195,   197,
     198,   199,   200,   196,   201,   202,   203,   196,   205,   204,
     204,   207,   206,   208,   209,   208,   211,   210,   210,   213,
     214,   212,   215,   216,   215,   218,   217,   217,   217,   217,
     219,   217,   221,   222,   223,   220,   225,   226,   227,   228,
     229,   224,   231,   232,   233,   234,   235,   230,   237,   238,
     239,   240,   241,   242,   236,   244,   243,   245,   246,   246,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   248,
     248,   249,   249,   249,   249,   249,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   252,
     252,   252,   252,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   254,   254,   254,   254,   254,   255,   254,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   257,   257,   259,   260,   261,   262,   263,   258,
     265,   264,   267,   266,   266,   268,   268,   268,   268,   269,
     269,   269,   269,   269,   269,   270,   271,   271,   272,   274,
     275,   273,   276,   276,   277,   278,   278,   278,   278,   278,
     280,   279,   281,   282,   282,   283,   283,   284,   284,   285,
     285,   286,   286,   287,   287,   288,   288,   289,   289,   291,
     292,   290,   293,   294,   294,   294,   295,   295,   295,   296,
     296,   296,   297,   297,   297,   298,   298,   298,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   301,   301,   302,   303,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   305,   304,   306,   304,   307,   304,   308,   304,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     312,   313,   314,   315,   311,   316,   317,   317,   318,   319,
     319,   319,   319,   320,   321,   322,   323,   324,   324,   324,
     325,   325,   325,   325,   326,   326,   326,   326,   326,   326,
     326,   326,   327,   327,   328,   329,   330,   331,   331,   331,
     331,   331,   332,   333,   333,   333,   333,   334,   335,   336,
     337,   338,   339,   339,   341,   340,   343,   342,   344,   345,
     346,   346,   346,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     3,     1,     1,     1,     0,
       0,     0,     0,     0,    14,     0,     0,     4,     1,     0,
       0,     0,     0,    12,     0,     0,     0,    11,     0,     2,
       2,     0,     5,     0,     0,     4,     0,     2,     2,     0,
       0,     6,     0,     0,     4,     0,     2,     1,     1,     1,
       0,     2,     0,     0,     0,     8,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,     0,     0,    16,     0,     3,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     2,     2,     2,     3,
       3,     3,     2,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     1,
       3,     2,     3,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     0,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     1,     3,     0,     0,     0,     0,     0,    12,
       0,     3,     0,     2,     3,     1,     1,     1,     1,     2,
       4,     2,     1,     1,     1,     5,     6,     4,     5,     0,
       0,     8,     1,     3,     8,     2,     2,     2,     1,     1,
       0,     8,     0,     1,     6,     1,     6,     1,     6,     1,
       6,     4,     1,     4,     1,     4,     1,     4,     1,     0,
       0,    10,     3,     1,     3,     5,     1,     3,     5,     1,
       3,     5,     1,     3,     5,     1,     3,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     3,     3,     3,     2,     4,     4,     4,
       2,     3,     3,     3,     3,     4,     3,     3,     4,     7,
       6,     5,     0,     8,     0,     8,     0,     8,     0,     8,
       3,     3,     1,     2,     2,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     0,     0,     9,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     2,     1,     2,     1,     2,     3,
       2,     3,     4,     4,     4,     2,     3,     2,     3,     4,
       6,     5,     1,     2,     3,     1,     1,     4,     4,     4,
       4,     3,     3,     3,     3,     2,     1,     1,     4,     4,
       2,     1,     1,     1,     0,     5,     0,     6,     6,     6,
       1,     1,     1,     2,     4,     2,     4,     3,     2,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     2,     4,     3,     2,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     7,     3,     0,     6,    65,     5,    65,
     399,   398,   426,   402,   423,   396,   394,   392,   390,   388,
     382,   386,   428,   427,   408,   406,   407,   405,   404,   403,
     424,   425,   400,   401,     0,     8,   109,   111,   116,   136,
     149,    12,     0,     0,   153,     0,   339,   342,   345,   347,
       0,     0,     0,     0,     0,   435,   436,   437,     0,   439,
     442,     0,     0,     0,   445,     0,   447,     0,     0,     0,
       0,     0,     0,     0,     0,   462,     0,     0,   465,    88,
       0,    95,   466,     0,     0,     0,     0,     0,   476,   349,
     351,     0,   477,     0,     0,     0,     0,     0,     0,     0,
     440,   441,     0,     0,     0,   481,     0,   490,   491,   492,
       0,     0,     0,     0,   499,     0,     0,     0,   503,   504,
     505,   506,   507,   508,   509,   510,     0,     0,     0,     0,
     517,     0,     0,     0,   521,   522,   523,   524,   525,   526,
     527,   528,     9,    13,    14,    16,    15,    11,    26,    27,
      28,     0,    67,     0,    68,     0,    69,    70,    17,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   232,
       0,   245,   252,   253,   254,   247,   248,   246,   268,   269,
       0,   308,   309,   310,   311,   312,   313,   314,   429,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   482,   483,     0,    18,    19,    10,     0,
       0,     0,     0,     0,     0,     0,   153,   127,   146,   168,
     125,   144,   166,     0,     0,     0,     0,   227,   132,     0,
       0,     0,     0,     0,   112,   155,     0,   154,   397,   395,
     393,   391,   389,     0,     0,     0,   383,   384,   385,     0,
       0,     0,   122,   163,     0,   416,   422,   414,   420,   415,
     421,   413,   419,     0,     0,   410,   412,   418,   409,   411,
     417,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,   387,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,   249,   341,     0,   340,
     344,   343,   346,   348,   356,     0,     0,   360,     0,     0,
       0,     0,     0,     0,     0,     0,   438,     0,    65,   443,
     444,   446,     0,   448,   265,   266,   450,     0,     0,     0,
     455,     0,   457,     0,     0,     0,    65,   463,   267,     0,
      65,   251,    65,     0,     0,     0,     0,   475,   350,   352,
       0,     0,     0,     0,     0,     0,     0,   480,   296,     0,
       0,   293,     0,     0,   299,     0,     0,   302,     0,     0,
     493,     0,   495,     0,     0,   498,   500,   501,   502,   511,
       0,   513,     0,     0,   516,   518,   519,   520,   430,     0,
      66,    77,     0,    71,    20,     0,     0,   128,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   145,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   115,     0,     0,
       0,     0,     0,     0,   135,   148,   152,   170,   178,   233,
      99,    97,   221,   188,   200,   187,   199,   186,   198,   185,
     197,   183,   195,   207,   184,   196,   229,   228,   220,   218,
     219,   217,   216,   215,   222,   223,   179,   181,     0,   353,
       0,   354,     0,   361,   362,   363,   364,     0,   366,   367,
       0,     0,   305,     0,     0,     0,   381,   380,     0,     0,
     449,    24,    25,   451,     0,     0,   456,   458,     0,     0,
       0,   464,    89,    96,     0,   471,   472,   473,   474,   355,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,     0,     0,     0,
       0,   497,     0,     0,   515,   431,    72,    65,    83,   180,
     113,   182,   114,   224,   129,   194,   124,   193,   123,   121,
     192,   120,   191,   119,   189,   117,   190,   118,   231,   134,
     230,   133,   214,   176,   212,   174,   213,   175,   211,   173,
     210,   172,   209,   171,   225,   130,   226,   131,     0,     0,
       0,   206,   143,   205,   142,   141,   204,   140,   203,   139,
     201,   137,   202,   138,   208,   150,   165,   164,   162,   161,
     160,   158,   159,   156,   157,   484,   250,   357,   365,   359,
     358,   368,     0,     0,     0,     0,     0,     0,    44,   453,
     452,   454,   459,     0,    29,     0,   468,   467,   469,   470,
     259,     0,     0,   257,   479,     0,   478,   297,     0,     0,
     294,     0,     0,   300,     0,     0,   303,     0,     0,   494,
     496,   512,   514,    65,    65,     0,    65,   177,   486,   272,
       0,   371,     0,   306,     0,     0,     0,    39,     0,   461,
       0,     0,     0,     0,   255,     0,     0,   258,     0,   284,
       0,     0,   275,     0,   282,     0,     0,   273,     0,   235,
       0,   286,     0,     0,   277,   432,    73,    78,     0,   272,
     485,     0,   370,     0,   288,     0,     0,   279,   372,   374,
     376,   378,    48,    56,   460,    30,    90,   262,   260,     0,
     256,   298,     0,   289,     0,   295,     0,   270,     0,   301,
     242,   304,     0,   488,     0,     0,     0,     0,    84,   487,
     369,   307,     0,   489,     0,   272,   272,   272,   272,    40,
       0,    45,     0,    65,    65,     0,     0,     0,     0,     0,
       0,     0,   272,     0,   236,   240,     0,     0,     0,   433,
      74,    79,    65,     0,     0,   373,   375,   377,   379,     0,
      53,    50,    49,     0,    62,    58,    57,    31,     0,   263,
     261,   264,   283,     8,   290,     0,   281,   271,     0,   237,
       0,   272,   243,   285,     0,    65,    65,    65,     0,   287,
       0,    51,     0,    41,    59,     0,    46,     0,    91,     0,
     272,     0,     0,     0,   244,   241,     0,   434,    75,    80,
      85,     0,     0,    54,    42,     0,    63,     0,    32,    65,
     292,   291,   276,   274,   238,   278,     0,    65,   280,    65,
      65,     0,    60,    65,    47,    35,     0,   272,    81,    86,
      52,    55,    43,    65,    64,    36,    33,    92,   239,     0,
      61,    65,     0,    65,    65,     0,    38,    34,    93,    87,
      37,     0,    94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,   291,     7,   142,   143,   144,   145,
     146,   147,   148,   731,   813,   877,   915,   932,   926,   931,
     937,   149,   772,   840,   894,   911,   728,   844,   897,   809,
     810,   841,   892,   873,   910,   811,   812,   845,   895,   923,
     876,   913,   150,   151,   413,   410,   714,   796,   866,   152,
     153,   597,   797,   867,   906,   154,   155,   716,   832,   907,
     929,   156,   360,   685,   814,   899,   933,   941,   157,   362,
     158,   292,   159,   160,   161,   162,   163,   164,   165,   166,
     717,   167,   168,   169,   705,   790,   859,   883,   917,   824,
     861,   825,   826,   170,   171,   172,   173,   174,   175,   733,
     816,   778,   176,   177,   178,   822,   760,   746,   741,   753,
     766,   747,   742,   754,   767,   179,   819,   880,   854,   383,
     380,   386,   389,   544,   180,   181,   182,   183,   184,   185,
     805,   806,   807,   808,   186,   187,   188,   595,   713,   795,
     865,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   719,   214,   759,   215,
     334,   216,   217
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -755
static const yytype_int16 yypact[] =
{
    -755,   926,  -755,  -755,  -755,  -137,    41,  1096,  -755,  1096,
     722,   722,   158,   735,    34,   679,   679,   679,   679,   679,
    1381,   712,  -755,  -755,  1480,  1480,  1480,  1480,  1472,  1472,
    -755,  -755,  -755,  -755,   614,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,   679,   157,  1447,    78,    54,   176,   614,   614,
     679,   108,    99,    37,   140,  -755,  -755,  -755,   145,  -755,
     186,   230,   157,   195,  -755,   204,  -755,    67,   232,   235,
     212,   -47,   252,   112,   302,   290,   291,   269,  -755,  -755,
     314,  -755,  -755,   295,   316,   312,   323,   328,  -755,   614,
     614,   360,  -755,   369,   378,   320,   322,   403,   404,   380,
    -755,  -755,    22,    60,    80,  -755,   127,  -755,  -755,  -755,
     -27,   -26,   409,   411,  -755,   412,   413,   422,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   -17,    -7,   434,   435,
    -755,   436,   437,   438,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,   440,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,   351,  -755,   384,  -755,   392,  -755,  -755,  -755,   454,
    -755,   243,  1635,   475,   479,  1615,  -755,  -755,  -755,  -755,
     458,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
     471,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,   469,  -755,  -755,   440,   722,
     722,   679,    34,    34,   712,   722,  -755,  1563,   443,  1695,
    1563,   443,  1695,   679,   679,   679,   679,  -755,  1563,    34,
      34,   735,    34,   735,   344,  1695,    34,  1695,  1658,  1658,
    1658,  1658,  1658,  1480,  1480,  1381,  1658,   534,   500,   712,
     712,   712,  1563,  1695,  1480,  1658,   534,  1658,   534,  1658,
     534,  1658,   534,    74,  1472,   344,  1658,   534,   344,  1658,
     534,   158,  1676,   487,   213,  1509,  1580,    13,  1555,   488,
     489,   136,   490,  1658,   157,   500,   679,  1480,  1480,  1480,
    1480,  1381,  1480,   679,   679,   679,   679,   679,   679,   679,
     679,   679,   679,    74,    74,  -755,   492,  -755,   486,  -755,
    -755,  -755,  -755,  -755,  1658,   493,   480,   601,   470,   679,
     495,   416,   498,   192,   473,   756,  -755,   614,  1096,   500,
    -755,  -755,   482,  1658,   499,   509,  -755,   497,   461,   508,
    -755,   484,  -755,   523,   445,   529,  1096,  -755,  -755,   527,
    1096,  -755,  1096,   313,   157,   505,   157,  -755,  -755,  -755,
     542,   545,   550,   552,   555,   126,   565,  -755,  -755,   562,
      40,  -755,   568,    65,  -755,   569,   146,  -755,   574,   159,
    -755,   582,  -755,   586,   587,  -755,  -755,  -755,  -755,  -755,
     588,  -755,   589,   590,  -755,  -755,  -755,  -755,  -755,   577,
    -755,  -755,   599,  -755,  -755,   170,   231,  -755,  -755,   784,
     826,   830,   679,   834,   847,   877,  1265,  1269,  1273,  1286,
    1308,  1316,  1321,  1329,  1351,  1364,  1368,  -755,  -755,   244,
     286,    30,   308,   310,   370,   407,   152,  -755,  -755,    34,
      34,    34,    34,    34,    34,    34,    34,    34,  -755,  -755,
     579,  1532,  1593,   679,   679,   679,   679,   679,   679,   679,
     679,   679,   679,   679,    30,    30,    30,    30,    30,    30,
     408,    74,    74,    18,   157,    74,  -755,  -755,   595,   596,
     597,   598,   608,   609,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  1658,  1658,   534,  1658,   534,  1658,   534,  1658,
     534,  1658,   534,   500,  1658,   534,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  1658,  1658,   344,   344,   614,  -755,
     157,  -755,   601,   344,  1658,   534,   500,   220,  1658,  -755,
     619,   512,  -755,   592,   162,   679,  -755,  1658,   604,     6,
    -755,  -755,  -755,  -755,   679,   626,   679,  -755,   634,   553,
      10,  -755,   440,   440,   601,  1658,   500,  -755,   500,  -755,
     641,   646,   649,   642,   556,   679,   647,   636,   633,   657,
     637,   645,   662,   640,   648,  -755,   643,   658,   677,   535,
     536,  -755,   537,   538,  -755,  -755,  -755,  1096,  -755,  -755,
     686,  -755,  -755,  -755,  1702,  -755,  1702,  -755,  1702,   364,
    -755,   364,  -755,   364,  -755,   376,  -755,   376,  -755,   352,
    -755,   352,  -755,  1658,  -755,  1658,  -755,  1658,  -755,  1658,
    -755,  1658,  -755,  1658,  -755,  -755,  -755,  -755,    30,    30,
      30,  -755,   443,  -755,   443,   156,  -755,   156,  -755,   156,
    -755,  -755,  -755,  -755,  -755,  -755,  1695,  1695,   335,   335,
     335,   371,   371,   694,  -755,   670,  -755,   500,  -755,  -755,
    1658,   620,    71,   672,   699,   716,  1417,   715,  -755,  1658,
    -755,  1658,  -755,   115,  -755,   650,   344,  1658,   534,   500,
    -755,   717,   718,   724,  -755,   124,  -755,  -755,   720,   196,
    -755,   726,   209,  -755,   727,   734,  -755,   729,   229,  -755,
    -755,  -755,  -755,  1096,  1096,   -21,  1096,  -755,  -755,  -755,
     679,  -755,   491,  -755,   732,   288,   601,  -755,   743,  -755,
     566,   638,   746,   739,  -755,   635,   740,  -755,   728,  -755,
     738,    26,  -755,   731,  -755,   742,    55,  -755,   741,  -755,
     744,  -755,   748,    84,  -755,   440,   440,  -755,   280,  -755,
    -755,   651,  -755,   745,  -755,   751,    90,  -755,   344,  1658,
     534,   500,  -755,  -755,  -755,  -755,  -755,  -755,   762,   660,
    -755,  -755,   761,  -755,   758,  -755,   765,  -755,   764,  -755,
    -755,  -755,   769,  -755,   766,   771,   754,   785,  -755,  -755,
    -755,  -755,   775,  -755,   772,  -755,  -755,  -755,  -755,   733,
     733,   730,   730,  1096,  1096,   787,   790,   788,   774,   796,
     791,   779,  -755,   795,  -755,   803,   614,   792,   799,  -755,
    -755,  -755,  1096,   794,   804,  -755,  -755,  -755,  -755,   614,
     763,  -755,  -755,   614,   757,  -755,  -755,   440,   300,  -755,
    -755,  -755,  -755,  -755,  -755,   813,  -755,  -755,   819,  -755,
     614,  -755,  -755,  -755,   823,  1096,  1096,  1096,   303,  -755,
     825,  -755,   827,  -755,  -755,   831,  -755,   747,  -755,   835,
    -755,   821,   832,   841,  -755,  -755,   833,   440,   440,   440,
    -755,   836,   838,  -755,  -755,   845,  -755,   855,  -755,  1096,
    -755,  -755,  -755,  -755,  -755,  -755,   859,  1096,  -755,  1096,
    1096,   861,  -755,  1096,  -755,   808,   319,  -755,  -755,   440,
     440,   440,  -755,  1096,   440,  -755,  -755,  -755,  -755,   869,
     440,  1096,   773,  1096,  1096,   -11,  -755,  -755,   440,   440,
    -755,   873,  -755
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -755,  -755,  -755,  -755,   876,  -755,    -9,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,    95,  -755,  -755,  -755,  -755,  -755,    96,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -285,   -45,   875,    82,    -3,   257,    81,   144,  -755,
    -755,   879,   881,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -754,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -99
static const yytype_int16 yytable[] =
{
     218,   319,   321,   322,   323,   799,   500,   227,   230,   238,
     390,   392,   248,   249,   250,   251,   252,   256,   262,   408,
     399,   265,   267,   269,   271,   276,   279,   446,   347,   408,
     401,   285,   484,   638,   639,     8,   678,   239,   240,   293,
     684,   222,   223,   496,   368,   369,   408,   324,   496,   242,
     408,   835,   836,   837,   838,   378,   783,   219,   220,   640,
     281,   241,   223,   246,   343,   784,    39,   379,   857,   224,
     233,   234,   757,   221,   233,   234,   348,   221,   226,   578,
       9,   273,   235,    34,   579,   787,   235,    36,    37,    38,
      39,    40,   327,   381,   788,   244,   236,    43,   282,   328,
     236,   258,    38,   485,   581,   382,    38,   885,    37,   582,
     275,   278,   329,   384,   793,   287,   284,   940,   233,   234,
     803,   221,   316,   794,   295,   385,   901,   417,   418,   804,
     235,   317,   463,   464,   465,   422,   466,   467,   468,   469,
     470,   471,   342,   339,   236,   325,   391,   393,   472,   473,
      38,   326,   330,   331,   229,   232,   400,   245,   247,   332,
     387,   233,   234,   928,   221,   263,   402,   350,   -98,   333,
     478,   479,   388,   235,   351,     9,   318,   273,   288,   219,
     220,   294,   281,   241,   223,   584,   294,   236,   104,    40,
     585,   224,   721,    38,    40,    43,   654,   335,   587,   485,
      43,   674,   237,   588,    37,    34,   675,   336,   352,    36,
      37,    38,    39,    40,   599,   337,   227,   230,   238,    43,
     282,   262,   461,   233,   234,   542,   221,   353,   354,   739,
     227,   230,   262,   461,   355,   235,   729,   543,   273,   415,
     416,   740,   744,   487,   574,   737,   575,   638,   639,   236,
     227,   230,   461,   320,   745,    38,   227,   230,   461,   338,
     485,   461,   751,   340,   668,    37,   341,   228,   231,   415,
     416,   461,   669,   640,   752,   601,   344,   257,   238,   345,
      39,   266,   268,   270,   272,   277,   280,   346,   641,   638,
     639,   286,   548,   502,   503,   505,   507,   509,   511,   514,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     104,   638,   639,   638,   639,   640,   233,   234,   798,   221,
     408,   764,    39,   244,   534,   480,   538,   349,   235,   549,
     643,   356,   547,   765,   357,   358,   483,   640,   878,   640,
     408,   890,   236,   408,    39,   359,    39,   560,    38,   454,
     455,   562,   646,   563,   648,   244,   480,   927,   361,   408,
     565,   456,   457,   229,   232,   564,   245,   247,   263,   288,
     481,   482,   363,   638,   639,   483,   472,   473,   468,   469,
     470,   471,   513,   229,   232,   245,   263,   288,   472,   473,
     288,   365,   470,   471,   364,   526,   527,   456,   457,   640,
     472,   473,   366,   229,   232,   288,    39,   367,   536,   533,
     638,   639,   370,   371,   650,   372,   604,   606,   608,   609,
     611,   613,   615,   617,   619,   621,   623,   625,   627,   629,
     631,   633,   635,   637,   481,   482,   640,   373,   487,   374,
     375,   376,   377,    39,   409,   566,   394,   568,   395,   396,
     397,   652,   474,   475,   441,   476,   477,   478,   479,   398,
     604,   606,   608,   611,   613,   615,   617,   619,   621,   635,
     637,   403,   404,   405,   406,   407,   228,   231,   437,   438,
     408,   411,   462,   666,   439,   440,   441,   442,   443,   444,
     445,   412,   414,   446,   417,   418,   458,   600,   602,   463,
     464,   465,   422,   466,   467,   468,   469,   470,   471,   459,
     228,   231,   462,   460,   484,   472,   473,   486,   498,   499,
     528,   462,   501,   529,   531,   537,   550,   655,   545,   461,
     530,   462,   539,   540,   670,   541,   554,   437,   438,   556,
     551,   553,   676,   474,   475,   441,   476,   477,   478,   479,
     552,   679,   555,   681,   504,   506,   508,   510,   512,   515,
     557,   687,   558,   600,   602,   655,   559,   480,   879,   417,
     418,   561,   695,   570,   463,   464,   465,   422,   466,   467,
     468,   469,   470,   471,   535,   567,   569,   571,   715,   572,
     472,   473,   573,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   576,   577,   253,   254,   596,   221,   273,   580,
     583,   667,   762,   483,   480,   586,   235,   219,   220,   589,
     281,   241,   223,   590,   591,   592,   593,   594,   598,   224,
     532,   665,   672,   673,   677,    37,    38,    39,    40,   622,
     624,   626,   628,    34,    43,   689,   686,    36,    37,    38,
      39,    40,   630,   632,   417,   418,   671,    43,   282,   463,
     464,   465,   422,   466,   467,   468,   469,   470,   471,   722,
     680,   682,   690,   683,   691,   472,   473,   692,   698,   693,
     730,   694,   233,   234,   696,   221,   699,   774,   697,   700,
     701,   702,   703,   704,   235,   706,   642,   644,   645,   647,
     649,   651,   653,   707,   755,   756,   708,   758,   236,   709,
     710,   711,   712,   482,    38,   259,   260,   761,   221,   222,
     223,   457,   718,   769,   723,   219,   220,   224,   221,   222,
     223,   642,   644,   647,   649,   651,   653,   224,   239,   240,
     720,   261,   241,   223,   724,   725,   727,    38,   104,   732,
     242,   225,   736,   779,   734,   735,   226,    38,    39,   233,
     234,   738,   221,   749,   243,   775,   226,   743,   748,    37,
     750,   235,   800,   763,   773,   776,   777,   780,   817,   226,
     781,   862,   782,   785,   830,   236,   786,   233,   234,   462,
     221,    38,   792,   789,   871,   802,   791,   801,   874,   235,
     546,   815,   818,   820,   847,   848,   821,   771,   768,   823,
     827,   828,   829,   236,   831,   884,   833,   834,   843,    38,
     839,   688,   850,   868,   849,   851,   852,   853,   603,   233,
     234,   856,   221,   233,   234,   855,   221,   233,   234,   858,
     221,   235,   860,   864,   863,   235,   869,   875,   870,   235,
     233,   234,   872,   221,   881,   236,   887,   888,   889,   236,
     882,    38,   235,   236,   886,    38,   891,   900,   893,    38,
     605,   904,   896,   902,   607,   898,   236,     6,   610,   909,
     233,   234,    38,   221,   903,   905,   912,   914,   908,   918,
     916,   612,   235,   922,   925,   228,   231,   462,   919,   934,
     920,   921,   936,   942,   924,   842,   236,     0,   846,   283,
       0,     0,    38,   289,   930,   290,     0,     0,     0,     0,
       0,   614,   935,     0,   938,   939,     2,     3,     0,    -8,
      -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,     0,    -8,     0,    -8,     0,    -8,
      -8,    -8,    -8,    -8,    -8,     0,     0,     0,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,     0,    -8,
      -8,     0,    -8,   770,    -8,    -8,    -8,    -8,     0,    -8,
      -8,    -8,    -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,
      -8,     0,     0,     0,     0,     0,     0,    -8,    -8,    -8,
      -8,    -8,     0,     0,     0,     0,     0,    -8,    -8,    -8,
      -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,     0,    -8,     0,     0,    -8,     0,     0,    -8,     0,
      -8,     0,    -8,     0,     0,     0,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -4,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,    34,     0,    35,     0,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     0,    52,
      53,     0,    54,     0,    55,    56,    57,    58,     0,    59,
      60,    61,    62,    63,     0,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,     0,     0,     0,     0,     0,    75,    76,     0,
      77,    78,     0,   -76,    79,   -82,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,     0,     0,    96,     0,     0,    97,     0,
      98,     0,    99,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   233,   234,
       0,   221,   233,   234,     0,   221,   233,   234,     0,   221,
     235,     0,     0,     0,   235,     0,     0,     0,   235,   233,
     234,     0,   221,     0,   236,     0,     0,     0,   236,     0,
      38,   235,   236,     0,    38,     0,     0,     0,    38,   616,
       0,   233,   234,   618,   221,   236,     0,   620,     0,   233,
     234,    38,   221,   235,   233,   234,     0,   221,     0,     0,
     622,   235,   233,   234,     0,   221,   235,   236,     0,     0,
       0,     0,     0,    38,   235,   236,     0,     0,     0,     0,
     236,    38,   624,     0,   233,   234,    38,   221,   236,     0,
     626,     0,     0,     0,    38,   628,   235,   233,   234,     0,
     221,   233,   234,   630,   221,     0,     0,     0,     0,   235,
     236,     0,     0,   235,   253,   254,    38,   221,     0,     0,
       0,     0,     0,   236,     0,   632,   235,   236,     0,    38,
       0,     0,     0,    38,     0,     0,     0,     0,   634,     0,
     255,     0,   636,     0,     0,     0,    38,    39,    40,     0,
     417,   418,     0,     0,    43,   463,   464,   465,   422,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,     0,
       0,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   296,   297,   298,   726,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   253,   254,     0,   221,   273,
       0,     0,     0,   253,   254,     0,   221,   235,   315,     0,
       0,     0,     0,     0,     0,   235,     0,     0,     0,     0,
       0,   274,     0,     0,     0,     0,    37,    38,    39,   264,
       0,     0,   417,   418,     0,    38,    39,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   488,   489,   490,
     491,   492,   493,   435,   436,   417,   418,     0,     0,   494,
     463,   464,   465,   422,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,     0,     0,   472,   473,   447,   448,
       0,     0,   494,     0,   449,   450,   451,   452,   453,   454,
     455,   463,   464,   465,   422,   466,   467,   468,   469,   470,
     471,   456,   457,   437,   438,   497,     0,   472,   473,   439,
     440,   441,   442,   443,   444,   445,   437,   438,     0,     0,
       0,     0,   474,   475,   441,   476,   477,   478,   479,     0,
     495,     0,     0,     0,     0,     0,     0,     0,   447,   448,
       0,     0,     0,   495,   449,   450,   451,   452,   453,   454,
     455,     0,     0,     0,     0,     0,     0,     0,   417,   418,
       0,   456,   457,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   417,   418,     0,     0,     0,   463,   464,   465,   422,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
       0,     0,   472,   473,   296,   297,   298,     0,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   449,   450,   451,   452,   453,   454,
     455,   464,   465,   422,   466,   467,   468,   469,   470,   471,
       0,   456,   457,     0,     0,     0,   472,   473
};

static const yytype_int16 yycheck[] =
{
       9,    46,    47,    48,    49,   759,   291,    10,    11,    12,
      37,    37,    15,    16,    17,    18,    19,    20,    21,    40,
      37,    24,    25,    26,    27,    28,    29,    14,    75,    40,
      37,    34,    14,     3,     4,   172,    30,     3,     4,    42,
      30,     7,     8,    30,    89,    90,    40,    50,    30,    15,
      40,   805,   806,   807,   808,    33,    30,     3,     4,    29,
       6,     7,     8,    29,    67,    39,    36,    45,   822,    15,
       3,     4,    93,     6,     3,     4,   123,     6,    44,    39,
      39,     7,    15,    29,    44,    30,    15,    33,    34,    35,
      36,    37,    55,    33,    39,    13,    29,    43,    44,    62,
      29,    20,    35,    29,    39,    45,    35,   861,    34,    44,
      28,    29,    75,    33,    30,    34,    34,   128,     3,     4,
      30,     6,    44,    39,    43,    45,   880,     3,     4,    39,
      15,    77,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    75,    62,    29,    37,   173,   173,    24,    25,
      35,    52,   115,   116,    10,    11,   173,    13,    14,   122,
      33,     3,     4,   917,     6,    21,   173,    55,    32,   132,
      14,    15,    45,    15,    62,    39,   122,     7,    34,     3,
       4,    29,     6,     7,     8,    39,    29,    29,   134,    37,
      44,    15,   121,    35,    37,    43,    44,    57,    39,    29,
      43,    39,    44,    44,    34,    29,    44,    62,    96,    33,
      34,    35,    36,    37,    44,    29,   219,   220,   221,    43,
      44,   224,   225,     3,     4,    33,     6,   115,   116,    33,
     233,   234,   235,   236,   122,    15,   121,    45,     7,    26,
      27,    45,    33,    30,   118,   121,   120,     3,     4,    29,
     253,   254,   255,    77,    45,    35,   259,   260,   261,    29,
      29,   264,    33,    68,    44,    34,    62,    10,    11,    26,
      27,   274,    52,    29,    45,    44,    44,    20,   281,    44,
      36,    24,    25,    26,    27,    28,    29,    75,    44,     3,
       4,    34,   337,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     134,     3,     4,     3,     4,    29,     3,     4,    38,     6,
      40,    33,    36,   241,   327,   243,   329,    75,    15,   338,
      44,    29,   335,    45,    44,    44,   255,    29,    38,    29,
      40,    38,    29,    40,    36,    76,    36,   356,    35,    14,
      15,   360,    44,   362,    44,   273,   274,    38,    44,    40,
     363,    26,    27,   219,   220,    52,   222,   223,   224,   225,
      26,    27,    77,     3,     4,   294,    24,    25,    14,    15,
      16,    17,   301,   239,   240,   241,   242,   243,    24,    25,
     246,    79,    16,    17,    78,   313,   314,    26,    27,    29,
      24,    25,    79,   259,   260,   261,    36,    79,   327,   327,
       3,     4,    52,    44,    44,    37,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,    26,    27,    29,   117,    30,   117,
      37,    37,    62,    36,    93,   364,    37,   366,    37,    37,
      37,    44,     9,    10,    11,    12,    13,    14,    15,    37,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,    37,    37,    37,    37,    37,   219,   220,     3,     4,
      40,    97,   225,   528,     9,    10,    11,    12,    13,    14,
      15,    99,    38,    14,     3,     4,    38,   415,   416,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    38,
     253,   254,   255,    44,    14,    24,    25,    30,    30,    30,
      28,   264,    32,    37,    44,    55,    44,   446,    55,   532,
      37,   274,    37,   117,   537,    37,    75,     3,     4,    55,
      41,    44,   545,     9,    10,    11,    12,    13,    14,    15,
      41,   554,    44,   556,   297,   298,   299,   300,   301,   302,
      37,   564,   117,   481,   482,   484,    37,   485,   853,     3,
       4,    44,   575,    28,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,   327,    80,    44,    37,   597,    37,
      24,    25,    37,   449,   450,   451,   452,   453,   454,   455,
     456,   457,    37,    41,     3,     4,    29,     6,     7,    41,
      41,   530,   121,   532,   532,    41,    15,     3,     4,    37,
       6,     7,     8,    37,    37,    37,    37,    37,    29,    15,
      29,    52,   120,    41,    30,    34,    35,    36,    37,    44,
      44,    44,    44,    29,    43,   564,   564,    33,    34,    35,
      36,    37,    44,    44,     3,     4,    37,    43,    44,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,   672,
      44,    37,    31,   120,    28,    24,    25,    28,    45,    37,
     683,   125,     3,     4,    37,     6,    29,   121,    52,    52,
      45,    29,    52,    45,    15,    52,   439,   440,   441,   442,
     443,   444,   445,    45,   713,   714,    29,   716,    29,   174,
     174,   174,   174,    27,    35,     3,     4,   720,     6,     7,
       8,    27,    52,   726,    52,     3,     4,    15,     6,     7,
       8,   474,   475,   476,   477,   478,   479,    15,     3,     4,
     120,    29,     7,     8,    45,    29,    31,    35,   134,    99,
      15,    29,    28,   118,    37,    37,    44,    35,    36,     3,
       4,    41,     6,    29,    29,   127,    44,    41,    41,    34,
      41,    15,   121,    41,    31,    29,    37,    37,   118,    44,
      52,   826,    44,    52,    30,    29,    44,     3,     4,   532,
       6,    35,    44,    52,   839,    44,    52,    52,   843,    15,
      44,    39,    41,    45,   813,   814,    41,   726,   726,    45,
      41,    45,    41,    29,    29,   860,    41,    45,    88,    35,
      87,   564,    32,   832,    37,    37,    52,    31,    44,     3,
       4,    52,     6,     3,     4,    44,     6,     3,     4,    44,
       6,    15,    39,    44,    52,    15,    52,    90,    44,    15,
       3,     4,    89,     6,    41,    29,   865,   866,   867,    29,
      41,    35,    15,    29,    41,    35,    41,    32,    41,    35,
      44,    30,    41,    52,    44,   128,    29,     1,    44,    41,
       3,     4,    35,     6,    52,    52,    41,    32,    52,    30,
     899,    44,    15,    32,    86,   638,   639,   640,   907,    30,
     909,   910,   129,    30,   913,   810,    29,    -1,   812,    34,
      -1,    -1,    35,    34,   923,    34,    -1,    -1,    -1,    -1,
      -1,    44,   931,    -1,   933,   934,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    31,    -1,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    53,
      54,    -1,    56,   726,    58,    59,    60,    61,    -1,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,    -1,    -1,   119,    -1,    -1,   122,    -1,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    31,    -1,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    53,
      54,    -1,    56,    -1,    58,    59,    60,    61,    -1,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    91,    92,    -1,
      94,    95,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,    -1,    -1,   119,    -1,    -1,   122,    -1,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     3,     4,
      -1,     6,     3,     4,    -1,     6,     3,     4,    -1,     6,
      15,    -1,    -1,    -1,    15,    -1,    -1,    -1,    15,     3,
       4,    -1,     6,    -1,    29,    -1,    -1,    -1,    29,    -1,
      35,    15,    29,    -1,    35,    -1,    -1,    -1,    35,    44,
      -1,     3,     4,    44,     6,    29,    -1,    44,    -1,     3,
       4,    35,     6,    15,     3,     4,    -1,     6,    -1,    -1,
      44,    15,     3,     4,    -1,     6,    15,    29,    -1,    -1,
      -1,    -1,    -1,    35,    15,    29,    -1,    -1,    -1,    -1,
      29,    35,    44,    -1,     3,     4,    35,     6,    29,    -1,
      44,    -1,    -1,    -1,    35,    44,    15,     3,     4,    -1,
       6,     3,     4,    44,     6,    -1,    -1,    -1,    -1,    15,
      29,    -1,    -1,    15,     3,     4,    35,     6,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    44,    15,    29,    -1,    35,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    44,    -1,
      29,    -1,    44,    -1,    -1,    -1,    35,    36,    37,    -1,
       3,     4,    -1,    -1,    43,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    10,    41,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     3,     4,    -1,     6,     7,
      -1,    -1,    -1,     3,     4,    -1,     6,    15,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    29,
      -1,    -1,     3,     4,    -1,    35,    36,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     3,     4,    -1,    -1,    30,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,     3,     4,
      -1,    -1,    30,    -1,     9,    10,    11,    12,    13,    14,
      15,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    26,    27,     3,     4,    30,    -1,    24,    25,     9,
      10,    11,    12,    13,    14,    15,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    30,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    26,    27,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     3,     4,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     9,    10,    11,    12,    13,    14,
      15,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    26,    27,    -1,    -1,    -1,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   176,     0,     1,   177,   178,   179,   180,   172,    39,
       3,     4,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    29,    31,    33,    34,    35,    36,
      37,    38,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    53,    54,    56,    58,    59,    60,    61,    63,
      64,    65,    66,    67,    69,    70,    71,    72,    73,    74,
      81,    82,    83,    84,    85,    91,    92,    94,    95,    98,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   119,   122,   124,   126,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   181,   182,   183,   184,   185,   186,   187,   196,
     217,   218,   224,   225,   230,   231,   236,   243,   245,   247,
     248,   249,   250,   251,   252,   253,   254,   256,   257,   258,
     268,   269,   270,   271,   272,   273,   277,   278,   279,   290,
     299,   300,   301,   302,   303,   304,   309,   310,   311,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   342,   344,   346,   347,   181,     3,
       4,     6,     7,     8,    15,    29,    44,   250,   251,   253,
     250,   251,   253,     3,     4,    15,    29,    44,   250,     3,
       4,     7,    15,    29,   249,   253,    29,   253,   250,   250,
     250,   250,   250,     3,     4,    29,   250,   251,   252,     3,
       4,    29,   250,   253,    29,   250,   251,   250,   251,   250,
     251,   250,   251,     7,    29,   249,   250,   251,   249,   250,
     251,     6,    44,   248,   249,   250,   251,   252,   253,   256,
     257,   179,   246,   250,    29,   252,     8,     9,    10,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    41,    44,    77,   122,   247,
      77,   247,   247,   247,   250,    37,    52,    55,    62,    75,
     115,   116,   122,   132,   345,    57,    62,    29,    29,   252,
      68,    62,    75,   250,    44,    44,    75,    75,   123,    75,
      55,    62,    96,   115,   116,   122,    29,    44,    44,    76,
     237,    44,   244,    77,    78,    79,    79,    79,   247,   247,
      52,    44,    37,   117,   117,    37,    37,    62,    33,    45,
     295,    33,    45,   294,    33,    45,   296,    33,    45,   297,
      37,   173,    37,   173,    37,    37,    37,    37,    37,    37,
     173,    37,   173,    37,    37,    37,    37,    37,    40,    93,
     220,    97,    99,   219,    38,    26,    27,     3,     4,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     3,     4,     9,
      10,    11,    12,    13,    14,    15,    14,     3,     4,     9,
      10,    11,    12,    13,    14,    15,    26,    27,    38,    38,
      44,   250,   251,     8,     9,    10,    12,    13,    14,    15,
      16,    17,    24,    25,     9,    10,    12,    13,    14,    15,
     249,    26,    27,   252,    14,    29,    30,    30,    18,    19,
      20,    21,    22,    23,    30,    30,    30,    30,    30,    30,
     246,    32,   250,   250,   251,   250,   251,   250,   251,   250,
     251,   250,   251,   252,   250,   251,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   249,   249,    28,    37,
      37,    44,    29,   249,   250,   251,   252,    55,   250,    37,
     117,    37,    33,    45,   298,    55,    44,   250,   247,   181,
      44,    41,    41,    44,    75,    44,    55,    37,   117,    37,
     181,    44,   181,   181,    52,   250,   252,    80,   252,    44,
      28,    37,    37,    37,   118,   120,    37,    41,    39,    44,
      41,    39,    44,    41,    39,    44,    41,    39,    44,    37,
      37,    37,    37,    37,    37,   312,    29,   226,    29,    44,
     249,    44,   249,    44,   250,    44,   250,    44,   250,   250,
      44,   250,    44,   250,    44,   250,    44,   250,    44,   250,
      44,   250,    44,   250,    44,   250,    44,   250,    44,   250,
      44,   250,    44,   250,    44,   250,    44,   250,     3,     4,
      29,    44,   251,    44,   251,   251,    44,   251,    44,   251,
      44,   251,    44,   251,    44,   252,   253,   253,   253,   253,
     253,   253,   253,   253,   253,    52,   247,   252,    44,    52,
     250,    37,   120,    41,    39,    44,   250,    30,    30,   250,
      44,   250,    37,   120,    30,   238,   249,   250,   251,   252,
      31,    28,    28,    37,   125,   250,    37,    52,    45,    29,
      52,    45,    29,    52,    45,   259,    52,    45,    29,   174,
     174,   174,   174,   313,   221,   181,   232,   255,    52,   341,
     120,   121,   250,    52,    45,    29,    41,    31,   201,   121,
     250,   188,    99,   274,    37,    37,    28,   121,    41,    33,
      45,   283,   287,    41,    33,    45,   282,   286,    41,    29,
      41,    33,    45,   284,   288,   181,   181,    93,   181,   343,
     281,   250,   121,    41,    33,    45,   285,   289,   249,   250,
     251,   252,   197,    31,   121,   127,    29,    37,   276,   118,
      37,    52,    44,    30,    39,    52,    44,    30,    39,    52,
     260,    52,    44,    30,    39,   314,   222,   227,    38,   281,
     121,    52,    44,    30,    39,   305,   306,   307,   308,   204,
     205,   210,   211,   189,   239,    39,   275,   118,    41,   291,
      45,    41,   280,    45,   264,   266,   267,    41,    45,    41,
      30,    29,   233,    41,    45,   281,   281,   281,   281,    87,
     198,   206,   206,    88,   202,   212,   212,   181,   181,    37,
      32,    37,    52,    31,   293,    44,    52,   281,    44,   261,
      39,   265,   247,    52,    44,   315,   223,   228,   181,    52,
      44,   247,    89,   208,   247,    90,   215,   190,    38,   246,
     292,    41,    41,   262,   247,   281,    41,   181,   181,   181,
      38,    41,   207,    41,   199,   213,    41,   203,   128,   240,
      32,   281,    52,    52,    30,    52,   229,   234,    52,    41,
     209,   200,    41,   216,    32,   191,   181,   263,    30,   181,
     181,   181,    32,   214,   181,    86,   193,    38,   281,   235,
     181,   194,   192,   241,    30,   181,   129,   195,   181,   181,
     128,   242,    30
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
#line 964 "pnfha.ypp"
    { ASTNode start("START"); tree.add_node(start); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 967 "pnfha.ypp"
    {
	 ASTNode line("line");
         tree.add_node(line);
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 973 "pnfha.ypp"
    { yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 976 "pnfha.ypp"
    {
		 ASTNode statement("statement");
  		 tree.add_node(statement);
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 984 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1; 
		    	                    statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 986 "pnfha.ypp"
    { conprint("VOID TVOID 0V\n"); statementoutcount.insert(); 
                         statementoutcount[statementoutcount.length() - 1] = outcount - 1; statementlineno.insert(); statementlineno[statementlineno.length() - 1]                          = yylineno; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 988 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					  statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 990 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					   statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 992 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 994 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				       statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 996 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; inblock = true;
				   ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 1004 "pnfha.ypp"
    {
			 ASTNode expression_statement("expression_statement");
			 tree.add_node(expression_statement);
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 1011 "pnfha.ypp"
    {
			 ASTNode declaration_statement("declaration_statement");
			 tree.add_node(declaration_statement);
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 1018 "pnfha.ypp"
    {
			 ASTNode command_statement("command_statement");
			 tree.add_node(command_statement);
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 1025 "pnfha.ypp"
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
			    conprint("LBL TVOID 0V\n");
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
#line 1058 "pnfha.ypp"
    {
			 ASTNode label_statement("label_statement");

			 conprint("LBL TVOID 0V\n");

			 tree.add_node(label_statement);
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1066 "pnfha.ypp"
    {
			 ASTNode label_statement("label_statement");

			 conprint("ELBL TVOID 0V\n");

			 tree.add_node(label_statement);
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 1076 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 1082 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");
			 tree.add_node(control_statement);
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1087 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");

			 breakinforever = false;

			 tree.add_node(control_statement);
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1097 "pnfha.ypp"
    {
			 ASTNode if_statementp1("if_statementp1");

			 tree.add_node(if_statementp1);		
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1103 "pnfha.ypp"
    {			 
			 ASTNode if_statementp2("if_statementp2");
			
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1112 "pnfha.ypp"
    {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1119 "pnfha.ypp"
    {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1124 "pnfha.ypp"
    {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1130 "pnfha.ypp"
    {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1140 "pnfha.ypp"
    {
			 ASTNode if_statementp5("if_statementp5");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 // Code for else will be inserted here if exists...
			 tree.add_node(if_statementp5);
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1151 "pnfha.ypp"
    {
			 ASTNode if_statementp7("if_statementp7");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");

			 tree.add_node(if_statementp7);
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1165 "pnfha.ypp"
    {
			 ASTNode switch_statementp1("switch_statementp1");

			 switchfound = true;
			 ++switchcounter;
			 switchcasecounter = 0;
			 inswitch = true;

			 switch (exptype)
			 {
			  case TBOOLEAN:
			   conprint("ALOAD TBOOLEAN %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			   switchexptype = TBOOLEAN;
     			   break;

			  case TNUMBER:
			   conprint("ALOAD TNUMBER %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			   switchexptype = TNUMBER;
			   break;

			  case TCHARACTER:
			   conprint("ALOAD TCHARACTER %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			   switchexptype = TCHARACTER;
			   break;

			  case TSTRING:
			   conprint("ALOAD TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			   switchexptype = TSTRING;
			   break;

			  default:
			   yyerror("Invalid switch statement.");
			 }
			 conprint("SWITCH2 TVOID 0V\n");
                         conprint("SWBEGIN TVOID 0V\n");

			 tree.add_node(switch_statementp1);
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1204 "pnfha.ypp"
    {
			 ASTNode switch_statementp2("switch_statementp2");


			 switch (exptype)
                         {
			  case TBOOLEAN:
                           switchexptype = TBOOLEAN;
			   break;

                          case TNUMBER:
			   switchexptype = TNUMBER;
			   break;

			  case TCHARACTER:
			   switchexptype = TCHARACTER;
			   break;

			  case TSTRING:			   
			   switchexptype = TSTRING;
			   break;

			  default:
			   yyerror("Invalid switch statement.");
			 };

			 tree.add_node(switch_statementp2);
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1233 "pnfha.ypp"
    {
			 ASTNode switch_statementp3("switch_statementp3");

			 tree.add_node(switch_statementp3);
			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1238 "pnfha.ypp"
    {

			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1242 "pnfha.ypp"
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1250 "pnfha.ypp"
    {
			 ASTNode switch_statementp1("switch_statementp1");

			 switchfound = true;
			 ++switchcounter;
			 switchcasecounter = 0;
			 inswitch = true;

			 conprint("SWITCH2 TVOID 0V\n");
			 conprint("SWBEGIN TVOID 0V\n");

			 tree.add_node(switch_statementp1);
			;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1265 "pnfha.ypp"
    {
			 ASTNode switch_statementp2("switch_statementp2");
			 
			 tree.add_node(switch_statementp2);
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1271 "pnfha.ypp"
    {
			 ASTNode switch_statementp3("switch_statementp3");
			 tree.add_node(switch_statementp3);
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1276 "pnfha.ypp"
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1285 "pnfha.ypp"
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1294 "pnfha.ypp"
    {
			 ASTNode case_statement("case_statement");

			 ++switchcasecounter;

			 if (switchexptype != exptype)
			  yyerror("Non-Matching Switch Expression");

			 
 			 switch (exptype)
			 {
			  case TBOOLEAN:
			   conprint("SWCASE TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_boolean().get().getString().c_str());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

			  case TNUMBER:
			   conprint("SWCASE TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

			  case TCHARACTER:
			   conprint("SWCASE TCHARCTER %c\n", (yyvsp[(2) - (2)]).to_character().get());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

		 	  case TSTRING:
			   conprint("SWCASE TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

			  default:
			   yyerror("Invalid switch statement.");
			};

			 tree.add_node(case_statement);
			;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1332 "pnfha.ypp"
    {
			 conprint("SWCEND TVOID 0V\n");
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1338 "pnfha.ypp"
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1343 "pnfha.ypp"
    {
			 conprint("SWCEND TVOID 0V\n");
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1348 "pnfha.ypp"
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1357 "pnfha.ypp"
    {
			 ASTNode case_statementp1("case_statement");

			 ++switchcasecounter;

			 switch (exptype)
			 {
			  case TBOOLEAN:
			   conprint("SWCASE TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_boolean().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("SWCASE TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			   break;

			  case TCHARACTER:
			   conprint("SWCASE TCHARACTER %c\n", (yyvsp[(2) - (2)]).to_character().get());
			   break;

			  case TSTRING:
			   conprint("SWCASE TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid type.");
			 }
			 conprint("SWCBEGIN TVOID 0V\n");
			
			 tree.add_node(case_statementp1);
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1388 "pnfha.ypp"
    {
			 ASTNode case_statementp2("case_statementp2");

			 tree.add_node(case_statementp2);
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1394 "pnfha.ypp"
    {
			 ASTNode case_statementp3("case_statementp3");

			 conprint("SWCEND TVOID 0V\n");

			 tree.add_node(case_statementp3);
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1404 "pnfha.ypp"
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1409 "pnfha.ypp"
    {
			 conprint("SWCEND TVOID 0V\n");
			;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1414 "pnfha.ypp"
    {
			 loopexpr = true;
			 inloop2 = true;
			;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1419 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1424 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1429 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1434 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1439 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 
			 loopexpr = false;
			 inloop = true;		 

			 tree.add_node(loop_statement);
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1447 "pnfha.ypp"
    {
			 inloop2 = false;
			 inwhile = false;
			 indowhile = false;
			 infor2 = false;
			 indofor = false;
			 inforever = false;
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1458 "pnfha.ypp"
    {
			 ASTNode while_loopp1("while_loopp1");

			 inwhile = true;
			 ++whilecounter;
			 conprint("LBL TSTRING \"while_test_%u\"\n", whilecounter);

			 tree.add_node(while_loopp1);
			;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1468 "pnfha.ypp"
    {
			 ASTNode while_loopp2("while_loopp2");

			 tree.add_node(while_loopp2);
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1474 "pnfha.ypp"
    {
			 ASTNode while_loopp3("while_loopp3");

			 conprint("CGOTOL TSTRING \"while_body_%u\"\n", whilecounter);
			 conprint("GOTOL TSTRING \"while_end_%u\"\n", whilecounter);

			 conprint("LBL TSTRING \"while_body_%u\"\n", whilecounter);

			 tree.add_node(while_loopp3);
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1485 "pnfha.ypp"
    {
			 ASTNode while_loopp4("while_loopp4");

			 conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 conprint("LBL TSTRING \"while_end_%u\"\n", whilecounter);

			 tree.add_node(while_loopp4);
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1495 "pnfha.ypp"
    {
			 ASTNode do_while_loopp1("do_while_loopp1");

			 indowhile = true;
			 ++dowhilecounter;
			 conprint("LBL TSTRING \"do_while_body_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp1);
			;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1505 "pnfha.ypp"
    {
			 ASTNode do_while_loopp2("do_while_loopp2");

			 tree.add_node(do_while_loopp2);
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1512 "pnfha.ypp"
    {
			 ASTNode do_while_loopp3("do_while_loopp3");

			 conprint("LBL TSTRING \"do_while_test_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp3);
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1520 "pnfha.ypp"
    {
			 ASTNode do_while_loopp4("do_while_loopp4");

			 tree.add_node(do_while_loopp4);
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1526 "pnfha.ypp"
    {
			 ASTNode do_while_loopp5("do_while_loopp5");

			 conprint("CGOTOL TSTRING \"do_while_body_%u\"\n", dowhilecounter);
			 conprint("GOTOL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp5);
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1535 "pnfha.ypp"
    {
			 ASTNode do_while_loopp6("do_while_loopp6");

			 conprint("LBL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp6);
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1544 "pnfha.ypp"
    {
			 infor = true;
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1548 "pnfha.ypp"
    {
			 ASTNode for_loopp1("for_loopp1");

			 infor2 = true;
			 ++forcounter;
			 conprint("LBL TSTRING \"for_initialization_%u\"\n", forcounter);

			 tree.add_node(for_loopp1);
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1558 "pnfha.ypp"
    {
			 ASTNode for_loopp2("for_loopp2");

			 conprint("LBL TSTRING \"for_condition_%u\"\n", forcounter);

			 tree.add_node(for_loopp2);
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1566 "pnfha.ypp"
    {
			 ASTNode for_loopp3("for_loopp3");

			 conprint("CGOTOL TSTRING \"for_body_%u\"\n", forcounter);
			 conprint("GOTOL TSTRING \"for_end_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_increment_statement_%u\"\n", forcounter);

			 tree.add_node(for_loopp3);
			;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1576 "pnfha.ypp"
    {
			 ASTNode for_loopp4("for_loopp4");

			 conprint("GOTOL TSTRING \"for_condition_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_body_%u\"\n", forcounter);

			 tree.add_node(for_loopp4);
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1585 "pnfha.ypp"
    {
			 ASTNode for_loopp5("for_loopp5");

			 conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_end_%u\"\n", forcounter);

			 tree.add_node(for_loopp5);
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1596 "pnfha.ypp"
    {
			 ASTNode forb_loopp1("forb_loopp1");

			 indofor = true;
			 infor = true;
			 ++doforcounter;

			 conprint("GOTOL TSTRING \"dofor_initialization_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_body_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp1);
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1609 "pnfha.ypp"
    {
			 ASTNode forb_loopp2("forb_loopp2");

			 conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_initialization_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp2);
			;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1618 "pnfha.ypp"
    {
			 ASTNode forb_loopp3("forb_loopp3");

			 tree.add_node(forb_loopp3);
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1624 "pnfha.ypp"
    {
			 ASTNode forb_loopp4("forb_loopp4");

			 conprint("GOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_condition_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp4);
			;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1633 "pnfha.ypp"
    {
			 ASTNode forb_loopp5("forb_loopp5");

			 conprint("CGOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("GOTOL TSTRING \"dofor_end_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp5);
			;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1643 "pnfha.ypp"
    {
			 ASTNode forb_loopp6("forb_loopp6");
			 tree.add_node(forb_loopp6);
			;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1648 "pnfha.ypp"
    {
			 ASTNode forb_loopp7("forb_loopp7");

			 conprint("GOTOL TSTRING \"dofor_condition_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_end_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp7);
			;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1659 "pnfha.ypp"
    {
			 ASTNode forever_loopp1("forever_loopp1");

			 breakinforever = true;
			 ++forevercounter;
			 conprint("LBL TSTRING \"forever_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp1);			
			;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1669 "pnfha.ypp"
    {
			 ASTNode forever_loopp2("forever_loopp2");

			 conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);
			 conprint("LBL TSTRING \"forever_end_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp2);			
			;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1678 "pnfha.ypp"
    { PNF_String str((yyvsp[(2) - (3)]).to_string().get()); (yyval).put(str); ASTNode statement_block("statement_block"); 
                                                  tree.add_node(statement_block); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1683 "pnfha.ypp"
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1688 "pnfha.ypp"
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1694 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TVOID; ASTNode expression("expression"); tree.add_node(expression); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1696 "pnfha.ypp"
    {
		 (yyval) = (yyvsp[(1) - (1)]);
		 savenumber = (yyval);
		 exptype = TBOOLEAN;
		 ASTNode expression("expression");
		 tree.add_node(expression);
		;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1703 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); savenumber = (yyval); exptype = TNUMBER; ASTNode expression("expression");
                                      tree.add_node(expression); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1705 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); savenumber = (yyval); exptype = TCHARACTER; ASTNode expression("expression"); 
                                         tree.add_node(expression); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1707 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); savenumber = (PNF_String)strip_quotes((yyval).to_string().get()); exptype = TSTRING; ASTNode expression("expression"); 
                                      tree.add_node(expression); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1709 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
                                  tree.add_node(expression); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1711 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TBOOLEAN; ASTNode expression("expression"); 
					  tree.add_node(expression); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1713 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
				     tree.add_node(expression); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1715 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); tree.add_node(expression); 		
		;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1721 "pnfha.ypp"
    {
			 PNF_String s("0V");
			 (yyval).put(s);

			 exptruth = false;

			 ASTNode void_expression("void_expression");
			 tree.add_node(void_expression);
			;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1730 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1734 "pnfha.ypp"
    { 
			 (yyval) = (yyvsp[(1) - (1)]);

			 String str = (yyval).to_boolean().get();
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

  case 112:

/* Line 1455 of yacc.c  */
#line 1750 "pnfha.ypp"
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

  case 113:

/* Line 1455 of yacc.c  */
#line 1764 "pnfha.ypp"
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

  case 114:

/* Line 1455 of yacc.c  */
#line 1780 "pnfha.ypp"
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

  case 115:

/* Line 1455 of yacc.c  */
#line 1795 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1799 "pnfha.ypp"
    { 
			 (yyval) = (yyvsp[(1) - (1)]);

			 double d = (yyval).to_number().get();
			 cout << "d: " << d << endl;

                         if (d == 0)
                          exptruth = false;
                         else
                          exptruth = true;

			 ASTNode number_expression("number_expression");
                         tree.add_node(number_expression);
			;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1814 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().add(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1820 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().sub(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1826 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mul(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1832 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().div(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1838 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mod(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1844 "pnfha.ypp"
    {
			 char * str = "-";
			 strcat(str, (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 PNF_String s(str);
			 PNF_Variable v(s);
			 (yyval) = v;
			;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1852 "pnfha.ypp"
    {
			 double d = (yyvsp[(3) - (3)]).to_number().get();
			 PNF_Number n((yyvsp[(1) - (3)]).to_number());
			 n.pow(d);
			 (yyval).put(n);
			;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1859 "pnfha.ypp"
    {
			 double d = (yyvsp[(1) - (3)]).to_number().get();
			 PNF_Number n((yyvsp[(3) - (3)]).to_number());
			 n.root(d);			 
			 (yyval).put(n);
			;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1866 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1872 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1878 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1884 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1890 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 & d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1898 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 | d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1907 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 ^ d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1915 "pnfha.ypp"
    {
			 int d = (int)(yyvsp[(2) - (2)]).to_number().get();
			 d = ~d;
			 PNF_Number n(d);
			 (yyval).put(n);
			;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1922 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 << d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1930 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 >> d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1937 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1942 "pnfha.ypp"
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

  case 137:

/* Line 1455 of yacc.c  */
#line 1955 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.add((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1962 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.sub((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1969 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mul((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1976 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.div((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);			;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1982 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mod((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1989 "pnfha.ypp"
    {
			 char d = (yyvsp[(3) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(1) - (3)]).to_character());
			 c.pow(d);
			 (yyval).put(c);
			;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1996 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(3) - (3)]).to_character());
			 c.root(d);
			 (yyval).put(c);
			;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 2003 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 2009 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 2015 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 2021 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 2026 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 2031 "pnfha.ypp"
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

  case 150:

/* Line 1455 of yacc.c  */
#line 2044 "pnfha.ypp"
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

  case 151:

/* Line 1455 of yacc.c  */
#line 2069 "pnfha.ypp"
    {
			 String str = (yyvsp[(2) - (2)]).to_string().get();
			 String str2 = "\"" + str + "\"";
			 PNF_String s(str2);
			 (yyval).put(s);
			;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 2075 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 2080 "pnfha.ypp"
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

  case 154:

/* Line 1455 of yacc.c  */
#line 2151 "pnfha.ypp"
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

  case 155:

/* Line 1455 of yacc.c  */
#line 2191 "pnfha.ypp"
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

  case 156:

/* Line 1455 of yacc.c  */
#line 2228 "pnfha.ypp"
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

  case 157:

/* Line 1455 of yacc.c  */
#line 2305 "pnfha.ypp"
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

  case 158:

/* Line 1455 of yacc.c  */
#line 2384 "pnfha.ypp"
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

  case 159:

/* Line 1455 of yacc.c  */
#line 2464 "pnfha.ypp"
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

  case 160:

/* Line 1455 of yacc.c  */
#line 2502 "pnfha.ypp"
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

  case 161:

/* Line 1455 of yacc.c  */
#line 2540 "pnfha.ypp"
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

  case 162:

/* Line 1455 of yacc.c  */
#line 2578 "pnfha.ypp"
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

  case 163:

/* Line 1455 of yacc.c  */
#line 2616 "pnfha.ypp"
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

  case 164:

/* Line 1455 of yacc.c  */
#line 2629 "pnfha.ypp"
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

  case 165:

/* Line 1455 of yacc.c  */
#line 2667 "pnfha.ypp"
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

  case 166:

/* Line 1455 of yacc.c  */
#line 2705 "pnfha.ypp"
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

  case 167:

/* Line 1455 of yacc.c  */
#line 2733 "pnfha.ypp"
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

  case 168:

/* Line 1455 of yacc.c  */
#line 2761 "pnfha.ypp"
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

  case 169:

/* Line 1455 of yacc.c  */
#line 2789 "pnfha.ypp"
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

  case 170:

/* Line 1455 of yacc.c  */
#line 2816 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 2820 "pnfha.ypp"
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

  case 172:

/* Line 1455 of yacc.c  */
#line 2831 "pnfha.ypp"
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

  case 173:

/* Line 1455 of yacc.c  */
#line 2842 "pnfha.ypp"
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

  case 174:

/* Line 1455 of yacc.c  */
#line 2853 "pnfha.ypp"
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

  case 175:

/* Line 1455 of yacc.c  */
#line 2864 "pnfha.ypp"
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

  case 176:

/* Line 1455 of yacc.c  */
#line 2875 "pnfha.ypp"
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

  case 177:

/* Line 1455 of yacc.c  */
#line 2885 "pnfha.ypp"
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

  case 178:

/* Line 1455 of yacc.c  */
#line 2897 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 2899 "pnfha.ypp"
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

  case 180:

/* Line 1455 of yacc.c  */
#line 2948 "pnfha.ypp"
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

  case 181:

/* Line 1455 of yacc.c  */
#line 2997 "pnfha.ypp"
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

  case 182:

/* Line 1455 of yacc.c  */
#line 3046 "pnfha.ypp"
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

  case 183:

/* Line 1455 of yacc.c  */
#line 3095 "pnfha.ypp"
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

  case 184:

/* Line 1455 of yacc.c  */
#line 3137 "pnfha.ypp"
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

  case 185:

/* Line 1455 of yacc.c  */
#line 3179 "pnfha.ypp"
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

  case 186:

/* Line 1455 of yacc.c  */
#line 3221 "pnfha.ypp"
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

  case 187:

/* Line 1455 of yacc.c  */
#line 3263 "pnfha.ypp"
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

  case 188:

/* Line 1455 of yacc.c  */
#line 3305 "pnfha.ypp"
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

  case 189:

/* Line 1455 of yacc.c  */
#line 3347 "pnfha.ypp"
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

  case 190:

/* Line 1455 of yacc.c  */
#line 3389 "pnfha.ypp"
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

  case 191:

/* Line 1455 of yacc.c  */
#line 3431 "pnfha.ypp"
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

  case 192:

/* Line 1455 of yacc.c  */
#line 3473 "pnfha.ypp"
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

  case 193:

/* Line 1455 of yacc.c  */
#line 3515 "pnfha.ypp"
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

  case 194:

/* Line 1455 of yacc.c  */
#line 3557 "pnfha.ypp"
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

  case 195:

/* Line 1455 of yacc.c  */
#line 3599 "pnfha.ypp"
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

  case 196:

/* Line 1455 of yacc.c  */
#line 3641 "pnfha.ypp"
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

  case 197:

/* Line 1455 of yacc.c  */
#line 3683 "pnfha.ypp"
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

  case 198:

/* Line 1455 of yacc.c  */
#line 3725 "pnfha.ypp"
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

  case 199:

/* Line 1455 of yacc.c  */
#line 3767 "pnfha.ypp"
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

  case 200:

/* Line 1455 of yacc.c  */
#line 3809 "pnfha.ypp"
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

  case 201:

/* Line 1455 of yacc.c  */
#line 3851 "pnfha.ypp"
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

  case 202:

/* Line 1455 of yacc.c  */
#line 3893 "pnfha.ypp"
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

  case 203:

/* Line 1455 of yacc.c  */
#line 3935 "pnfha.ypp"
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

  case 204:

/* Line 1455 of yacc.c  */
#line 3977 "pnfha.ypp"
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

  case 205:

/* Line 1455 of yacc.c  */
#line 4019 "pnfha.ypp"
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

  case 206:

/* Line 1455 of yacc.c  */
#line 4061 "pnfha.ypp"
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

  case 207:

/* Line 1455 of yacc.c  */
#line 4103 "pnfha.ypp"
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

  case 208:

/* Line 1455 of yacc.c  */
#line 4167 "pnfha.ypp"
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

  case 209:

/* Line 1455 of yacc.c  */
#line 4231 "pnfha.ypp"
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

  case 210:

/* Line 1455 of yacc.c  */
#line 4276 "pnfha.ypp"
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

  case 211:

/* Line 1455 of yacc.c  */
#line 4321 "pnfha.ypp"
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

  case 212:

/* Line 1455 of yacc.c  */
#line 4366 "pnfha.ypp"
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

  case 213:

/* Line 1455 of yacc.c  */
#line 4411 "pnfha.ypp"
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

  case 214:

/* Line 1455 of yacc.c  */
#line 4456 "pnfha.ypp"
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

  case 215:

/* Line 1455 of yacc.c  */
#line 4501 "pnfha.ypp"
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

  case 216:

/* Line 1455 of yacc.c  */
#line 4546 "pnfha.ypp"
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

  case 217:

/* Line 1455 of yacc.c  */
#line 4591 "pnfha.ypp"
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

  case 218:

/* Line 1455 of yacc.c  */
#line 4636 "pnfha.ypp"
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

  case 219:

/* Line 1455 of yacc.c  */
#line 4681 "pnfha.ypp"
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

  case 220:

/* Line 1455 of yacc.c  */
#line 4726 "pnfha.ypp"
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

  case 221:

/* Line 1455 of yacc.c  */
#line 4771 "pnfha.ypp"
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

  case 222:

/* Line 1455 of yacc.c  */
#line 4816 "pnfha.ypp"
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

  case 223:

/* Line 1455 of yacc.c  */
#line 4861 "pnfha.ypp"
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

  case 224:

/* Line 1455 of yacc.c  */
#line 4906 "pnfha.ypp"
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

  case 225:

/* Line 1455 of yacc.c  */
#line 4951 "pnfha.ypp"
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

  case 226:

/* Line 1455 of yacc.c  */
#line 4996 "pnfha.ypp"
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

  case 227:

/* Line 1455 of yacc.c  */
#line 5041 "pnfha.ypp"
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

  case 228:

/* Line 1455 of yacc.c  */
#line 5078 "pnfha.ypp"
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

  case 229:

/* Line 1455 of yacc.c  */
#line 5123 "pnfha.ypp"
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

  case 230:

/* Line 1455 of yacc.c  */
#line 5168 "pnfha.ypp"
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

  case 231:

/* Line 1455 of yacc.c  */
#line 5213 "pnfha.ypp"
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

  case 232:

/* Line 1455 of yacc.c  */
#line 5260 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 5264 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 5270 "pnfha.ypp"
    {
			 fsaveid2 = (yyvsp[(3) - (3)]);

			 conprint("FCALL TSTRING \"%s\"\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 conprint("FCPARAMS TVOID 0V\n");
			;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 5277 "pnfha.ypp"
    {
			;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 5280 "pnfha.ypp"
    {
			 unsigned long index = funcstk.find(fsaveid2.to_string().get(), frets3, fparams3);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }
			 fsaveindex = index;
			;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 5289 "pnfha.ypp"
    {
			 conprint("FECPARAMS TVOID 0V\n");
			;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 5293 "pnfha.ypp"
    {
			 conprint("FECALL TVOID 0V\n");
			;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 5297 "pnfha.ypp"
    {
			 for (unsigned long i = frets3.length() - 1; i > 0; --i)
			  frets3.remove();

			 for (unsigned long i = fparams3.length() - 1; i > 0; --i)
			  fparams3.remove();			
			;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 5307 "pnfha.ypp"
    {
				 (yyval) = (yyvsp[(1) - (1)]);
				 saveexp = (yyval);

				 for (unsigned long i = 0; i < funcps[funcps.length() - 1].length(); ++i)
			 	 {
			 	  funcps[funcps.length() - 1][i].value((yyvsp[(1) - (1)]));
			 	 }
				;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 5317 "pnfha.ypp"
    {

				;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 5339 "pnfha.ypp"
    {
				 // Patch the code
				 fsaveindex = ((fsaveindex >= 12) || !saw_12) ? fsaveindex + 1 : fsaveindex;
				 if (!saw_12 && (fsaveindex == 12))
				  saw_12 = true;

			 	 conprint("FNCLOAD TNUMBER %d\n", fsaveindex);
				 conprint("PNUM TNUMBER %d\n", fsavepindex);
				;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 5349 "pnfha.ypp"
    {
				 (yyval) = savenumber;
				 saveexp = (yyval);
				 cout << "fsaveindex: " << fsaveindex << " saveexp: " << saveexp.to_number().get() << endl;

				 pnum = 0;
 				 switch (exptype)
				 {
				  case TVOID:
				  {
			           conprint("FNCSPARAM TVOID 0V\n");
				  }
				  break;
				  
				  case TBOOLEAN:
				  {
				   fparams3[fparams3.length() - 1] = "BOOLEAN";
			           fparams3.insert();

				   conprint("FNCSPARAM TBOOLEAN 0V\n");
				  }
				  break;

				  case TNUMBER:
				  {
				   fparams3[fparams3.length() - 1] = "NUMBER";
			           fparams3.insert();

				   conprint("FNCSPARAM TNUMBER 0V\n");				   
				  }
				  break;

				  case TCHARACTER:
				  {
				   fparams3[fparams3.length() - 1] = "CHARACTER";
			           fparams3.insert();

				   conprint("FNCSPARAM TCHARACTER 0V\n");
				  }
				  break;

				  case TSTRING:
				  {
				   fparams3[fparams3.length() - 1] = "STRING";
			           fparams3.insert();

				   conprint("FNCSPARAM TSTRING 0V\n");
				  }
				  break;

				  default:
				   yyerror("Invalid type.");
				 }
	
				 conprint("FNCSTORE TNUMBER %d\n", fsaveindex);
				 actual_parameters();
				;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 5407 "pnfha.ypp"
    {
				 (yyval) = (yyvsp[(3) - (3)]);
				 saveexp = (yyval);

				 switch (exptype)
				 {
				  case TVOID:
				   conprint("FNCSPARAM TVOID 0V\n");
				   break;

				  case TBOOLEAN:
				   fparams3[fparams3.length() - 1] = "BOOLEAN";
				   fparams3.insert();
				   conprint("FNCSPARAM TBOOLEAN 0V\n");
				   break;

				  case TNUMBER:
				   fparams3[fparams3.length() - 1] = "NUMBER";
			           fparams3.insert();
				   conprint("FNCSPARAM TNUMBER 0V\n");
				   break;

				  case TCHARACTER:
				   fparams3[fparams3.length() - 1] = "CHARACTER";
			           fparams3.insert();
				   conprint("FNCSPARAM TCHARACTER 0V\n");
				   break;

				  case TSTRING:
				   fparams3[fparams3.length() - 1] = "STRING";
			           fparams3.insert();
				   conprint("FNCSPARAM TSTRING 0V\n");
				   break;

				  default:
				   yyerror("Invalid type.");
				 }
				 conprint("FNCSTORE TNUMBER %d\n", fsaveindex);

				 actual_parameters();
				;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 5542 "pnfha.ypp"
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 5547 "pnfha.ypp"
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 5552 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 5557 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 5564 "pnfha.ypp"
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
   			    conprint("ALOAD TVOID 0V\n");
			    break;

			   case TBOOLEAN:
   			    conprint("ALOAD TBOOLEAN %s\n", p.to_boolean().get().getString().c_str());
			    break;

			   case TNUMBER:
   			    conprint("ALOAD TNUMBER %g\n", p.to_number().get());
			    break;

			   case TCHARACTER:
   			    conprint("ALOAD TCHARACTER %c\n", p.to_character().get());
			    break;

			   case TSTRING:
   			    conprint("ALOAD TSTRING %s\n", p.to_string().get().getString().c_str());
			    break;
			  }
			  conprint("VSTORE TVOID 0V\n");
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

  case 250:

/* Line 1455 of yacc.c  */
#line 5622 "pnfha.ypp"
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
			     (yyval).put("0V");
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
   			    conprint("ALOAD TVOID 0V\n");
			    break;

			   case TBOOLEAN:
   			    conprint("ALOAD TBOOLEAN %s\n", (yyval).to_boolean().get().getString().c_str());
			    break;

			   case TNUMBER:
   			    conprint("ALOAD TNUMBER %g\n", (yyval).to_number().get());
			    break;

			   case TCHARACTER:
   			    conprint("ALOAD TCHARACTER \'%c\'\n", (yyval).to_character().get());
			    break;

			   case TSTRING:
   			    conprint("ALOAD TSTRING \"%s\"\n", (yyval).to_string().get().getString().c_str());
			    break;
			  }
			  conprint("VSTORE TVOID 0V\n");
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

  case 251:

/* Line 1455 of yacc.c  */
#line 5703 "pnfha.ypp"
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

  case 252:

/* Line 1455 of yacc.c  */
#line 5738 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 5743 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 5748 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 5755 "pnfha.ypp"
    {
			 ASTNode enumv_declaration("enumv_declaration");

			 conprint("ENUMS TSTRING %s\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 conprint("ENUM TSTRING %s\n", (yyvsp[(5) - (5)]).to_string().get().getString().c_str());
			 conprint("SENUM TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());

			 tree.add_node(enumv_declaration);
			;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 5767 "pnfha.ypp"
    {
			 ASTNode rangev_declaration("rangev_declaration");

			 if ((yyvsp[(2) - (6)]).to_string().get() == "rtype1")
			 {
			  conprint("RSTART1 TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			  conprint("RANGE1 TNUMBER %s\n", strip_quotes((yyvsp[(6) - (6)]).to_string().get()).getString().c_str());
			  conprint("REND1 TSTRING %s\n", (yyvsp[(4) - (6)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(rangev_declaration);
			;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 5782 "pnfha.ypp"
    {
			 ASTNode rangev_declaration("rangev_declaration");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "rtype2")
			 {
			  conprint("RSTART2 TSTRING %s\n", (yyvsp[(3) - (4)]).to_string().get().getString().c_str());
			  conprint("RANGE2 TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(rangev_declaration);
			;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 5798 "pnfha.ypp"
    {
			 ASTNode array_declaration("array_declaration");

			 conprint("ASTART TSTRING %s\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 conprint("AEND TNUMBER %g\n", (yyvsp[(4) - (5)]).to_number().get());

			 tree.add_node(array_declaration);
			;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 5809 "pnfha.ypp"
    {
			 ASTNode enum_declarationp1("enum_declarationp1");

			 conprint("ESTART TSTRING \"%s\"\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());

			 tree.add_node(enum_declarationp1);
			;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 5817 "pnfha.ypp"
    {
			 ASTNode enum_declarationp2("enum_declarationp2");
			 tree.add_node(enum_declarationp2);
			;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 5822 "pnfha.ypp"
    {
			 ASTNode enum_declarationp3("enum_declarationp3");

			 conprint("EEND TVOID 0V\n");

			 tree.add_node(enum_declarationp3);
			;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 5832 "pnfha.ypp"
    {
			 ASTNode enum_strings("enum_strings");

			 conprint("ENAME TSTRING %s\n", (yyvsp[(1) - (1)]).to_string().get().getString().c_str());

			 tree.add_node(enum_strings);
			;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 5840 "pnfha.ypp"
    {
			 conprint("ENAME TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 5846 "pnfha.ypp"
    {
			 ASTNode range_declaration("range_declaration");

			 if ((yyvsp[(2) - (8)]).to_string().get() == "rtype1")
			 {
			  conprint("RDSTART1 TSTRING %s\n", (yyvsp[(3) - (8)]).to_string().get().getString().c_str());
			  conprint("RFROM1 TNUMBER %s\n", strip_quotes((yyvsp[(5) - (8)]).to_string().get()).getString().c_str());
			  conprint("RTO1 TNUMBER %s\n", strip_quotes((yyvsp[(8) - (8)]).to_string().get()).getString().c_str());
			  conprint("RDEND1 TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (8)]).to_string().get() == "rtype2")
			 {
			  conprint("RDSTART2 TSTRING %s\n", (yyvsp[(3) - (8)]).to_string().get().getString().c_str());
			  conprint("RFROM2 TNUMBER %s\n", strip_quotes((yyvsp[(5) - (8)]).to_string().get()).getString().c_str());
			  conprint("RTO2 TNUMBER %s\n", strip_quotes((yyvsp[(8) - (8)]).to_string().get()).getString().c_str());
			  conprint("RDEND2 TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(range_declaration);
			;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 5871 "pnfha.ypp"
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

  case 266:

/* Line 1455 of yacc.c  */
#line 5895 "pnfha.ypp"
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

  case 267:

/* Line 1455 of yacc.c  */
#line 5918 "pnfha.ypp"
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

  case 270:

/* Line 1455 of yacc.c  */
#line 5946 "pnfha.ypp"
    {
			 funcps.insert();

			 funcptr->name((yyvsp[(3) - (6)]).to_string().get());			 
			 funcstk.add_function(*funcptr);
			 delete funcptr;
			 funcptr = NULL;			 
	
			 saveid3 = (yyvsp[(3) - (6)]);
			 unsigned long index = funcstk.find((yyvsp[(3) - (6)]).to_string().get(), frets, fparams);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 for (unsigned long i = 0; i < funcstk.get_function(index).params().length(); ++i)
			 {
			  funcps[index].insert();
			  funcps[index][i].name(funcstk.get_function(index).pname(i));
			 }

			 for (unsigned long i = 0; i < funcstk.get_function(index).params().length(); ++i)
			 {
			  funcps[index][i].value(funcstk.get_function(index).param(i));
			 }
			 
			 conprint("ALOAD TSTRING \"%s\"\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			 conprint("FNCSNAME TVOID 0V\n");
			 conprint("FNCSDEF TSTRING \"%s\"\n", funcstk.get_function(index).rname().getString().c_str());
			 conprint("FNCSTORE TVOID 0V\n");
			 conprint("FNCDELETE TVOID 0V\n")
			;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 5980 "pnfha.ypp"
    {
			 for (unsigned long i = frets.length() - 1; i > 0; --i)
			  frets.remove();

			 for (unsigned long i = fparams.length() - 1; i > 0; --i)
			  fparams.remove();
			;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 5992 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 pnum = 0;
			 switch (exptype)
			 {
			  case TVOID:
			  {
			   PNF_Void v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "VOID";
			   fparams.insert();

			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TVOID 0V\n");
			   conprint("FNCSPARAM TVOID 0V\n");
			  }
			  break;

			  case TBOOLEAN:
			  {
			   PNF_Boolean v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "BOOLEAN";
			   fparams.insert();

			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TBOOLEAN false\n");
			   conprint("FNCSPARAM TBOOLEAN 0V\n");
			  }
			  break;

			  case TNUMBER:
			  {
			   PNF_Number v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "NUMBER";
			   fparams.insert();

			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TNUMBER 0\n");
			   conprint("FNCSPARAM TNUMBER 0V\n");
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "CHARACTER";
			   fparams.insert();


			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TCHARACTER '0'\n");
			   conprint("FNCSPARAM TCHARACTER 0V\n");
			  }
			  break;

			  case TSTRING:
			  {			   
			   PNF_String v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "STRING";
			   fparams.insert();


			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TSTRING \"\"\n");
			   conprint("FNCSPARAM TSTRING 0V\n");
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 6085 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(4) - (6)]);


			 String type = (yyvsp[(6) - (6)]).to_string().get();
			 if (type == "void")
			  exptype = TVOID;
			 else if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TVOID:
			  {
			   PNF_Void v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "VOID";
			   fparams.insert();


			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TVOID 0V\n");
			   conprint("FNCSPARAM TVOID 0V\n");
			  }
			  break;

			  case TBOOLEAN:
			  {
			   PNF_Boolean v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "BOOLEAN";
			   fparams.insert();


			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TBOOLEAN false\n");
			   conprint("FNCSPARAM TBOOLEAN 0V\n");
			  }
			  break;

			  case TNUMBER:
			  {
			   PNF_Number v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "NUMBER";
			   fparams.insert();


			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TNUMBER 0\n");
			   conprint("FNCSPARAM TNUMBER 0V\n");
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "CHARACTER";
			   fparams.insert();


			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TCHARACTER '0'\n");
			   conprint("FNCSPARAM TCHARACTER 0V\n");
			  }
			  break;

			  case TSTRING:
			  {
			   PNF_String v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, (yyval).to_string().get());

			   fparams[fparams.length() - 1] = "STRING";
			   fparams.insert();


			   conprint("PNUM TNUMBER %d\n", pnum++);
			   conprint("ALOAD TSTRING \"\"\n");
			   conprint("FNCSPARAM TSTRING 0V\n");
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 6197 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 switch (exptype)
			 {
			  case TVOID:
			  {
			   fparams2[fparams2.length() - 1] = "VOID";
			   fparams2.insert();
			  }
			  break;

			  case TBOOLEAN:
			  {
			   fparams2[fparams2.length() - 1] = "BOOLEAN";
			   fparams2.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   fparams2[fparams2.length() - 1] = "NUMBER";
			   fparams2.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   fparams2[fparams2.length() - 1] = "CHARACTER";
			   fparams2.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   fparams2[fparams2.length() - 1] = "STRING";
			   fparams2.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 6242 "pnfha.ypp"
    {
			 String type = (yyvsp[(6) - (6)]).to_string().get();
			 if (type == "void")
			  exptype = TVOID;
			 else if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TVOID:
			  {
			   fparams2[fparams2.length() - 1] = "VOID";
			   fparams2.insert();
			  }
			  break;

			  case TBOOLEAN:
			  {
			   fparams2[fparams2.length() - 1] = "BOOLEAN";
			   fparams2.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   fparams2[fparams2.length() - 1] = "NUMBER";
			   fparams2.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   fparams2[fparams2.length() - 1] = "CHARACTER";
			   fparams2.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   fparams2[fparams2.length() - 1] = "STRING";
			   fparams2.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 6301 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 switch (exptype)
			 {
			  case TVOID:
			  {
			   fparams5[fparams5.length() - 1] = "VOID";
			   fparams5.insert();
			  }
			  break;

			  case TBOOLEAN:
			  {
			   fparams5[fparams5.length() - 1] = "BOOLEAN";
			   fparams5.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   fparams5[fparams5.length() - 1] = "NUMBER";
			   fparams5.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   fparams5[fparams5.length() - 1] = "CHARACTER";
			   fparams5.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   fparams5[fparams5.length() - 1] = "STRING";
			   fparams5.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 6346 "pnfha.ypp"
    {
			 String type = (yyvsp[(6) - (6)]).to_string().get();
			 if (type == "void")
			  exptype = TVOID;
			 else if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TVOID:
			  {
			   fparams5[fparams5.length() - 1] = "VOID";
			   fparams5.insert();
			  }
			  break;

			  case TBOOLEAN:
			  {
			   fparams5[fparams5.length() - 1] = "BOOLEAN";
			   fparams5.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   fparams5[fparams5.length() - 1] = "NUMBER";
			   fparams5.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   fparams5[fparams5.length() - 1] = "CHARACTER";
			   fparams5.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   fparams5[fparams5.length() - 1] = "STRING";
			   fparams5.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 6405 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 switch (exptype)
			 {
			  case TVOID:
			  {
			   fparams6[fparams6.length() - 1] = "VOID";
			   fparams6.insert();
			  }
			  break;

			  case TBOOLEAN:
			  {
			   fparams6[fparams6.length() - 1] = "BOOLEAN";
			   fparams6.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   fparams6[fparams6.length() - 1] = "NUMBER";
			   fparams6.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   fparams6[fparams6.length() - 1] = "CHARACTER";
			   fparams6.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   fparams6[fparams6.length() - 1] = "STRING";
			   fparams6.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 6450 "pnfha.ypp"
    {
			 String type = (yyvsp[(6) - (6)]).to_string().get();
			 if (type == "void")
			  exptype = TVOID;
			 else if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TVOID:
			  {
			   fparams6[fparams6.length() - 1] = "VOID";
			   fparams6.insert();
			  }
			  break;

			  case TBOOLEAN:
			  {
			   fparams6[fparams6.length() - 1] = "BOOLEAN";
			   fparams6.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   fparams6[fparams6.length() - 1] = "NUMBER";
			   fparams6.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   fparams6[fparams6.length() - 1] = "CHARACTER";
			   fparams6.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   fparams6[fparams6.length() - 1] = "STRING";
			   fparams6.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 6509 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (4)]);

			 String type = (yyvsp[(4) - (4)]).to_string().get();
			 if (type == "void")
			  exptype = TVOID;
			 else if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");
			;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 6527 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 6535 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (4)]);

			 String type = (yyvsp[(4) - (4)]).to_string().get();
			 if (type == "void")
			  exptype = TVOID;
			 else if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");
			;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 6553 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 6561 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (4)]);

			 String type = (yyvsp[(4) - (4)]).to_string().get();
			 if (type == "void")
			  exptype = TVOID;
			 else if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");
			;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 6579 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 6587 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (4)]);

			 String type = (yyvsp[(4) - (4)]).to_string().get();
			 if (type == "void")
			  exptype = TVOID;
			 else if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");
			;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 6605 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 6613 "pnfha.ypp"
    {
			 fsaveid = (yyvsp[(3) - (6)]);
			 unsigned long index = funcstk.find((yyvsp[(3) - (6)]).to_string().get(), frets2, fparams2);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 conprint("GOTOL TSTRING \"%s_END\"\n", funcstk.get_function(index).rname().getString().c_str());
			 conprint("LBL TSTRING \"%s\"\n", funcstk.get_function(index).rname().getString().c_str());
			;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 6626 "pnfha.ypp"
    {
			 unsigned long index = funcstk.find(fsaveid.to_string().get(), frets2, fparams2);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 conprint("LBL TSTRING \"%s_END\"\n", funcstk.get_function(index).rname().getString().c_str());
			;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 6637 "pnfha.ypp"
    {
			 for (unsigned long i = frets2.length() - 1; i > 0; --i)
			  frets2.remove();

			 for (unsigned long i = fparams2.length() - 1; i > 0; --i)
			  fparams2.remove();
			;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 6652 "pnfha.ypp"
    {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");

			 exptype = TVOID;
			;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 6660 "pnfha.ypp"
    {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");


			 String type = (yyvsp[(3) - (3)]).to_string().get();
			 if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 rnum = 0;
			 switch (exptype)
			 {			  
			  case TBOOLEAN:
			  {
			   PNF_Boolean v(false);
			   PNF_Variable v2(v);
			   funcptr->ret(rnum, v2);

			   frets[frets.length() - 1] = "BOOLEAN";
			   frets.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("ALOAD TBOOLEAN false\n");
			   conprint("FNCSRET TBOOLEAN 0V\n");
			  }
			  break;

			  case TNUMBER:
			  {
			   PNF_Number v(0);
			   PNF_Variable v2(v);
			   funcptr->ret(rnum, v2);

			   frets[frets.length() - 1] = "NUMBER";
			   frets.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("ALOAD TNUMBER 0\n");
			   conprint("FNCSRET TNUMBER 0V\n");
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character v('\0');
			   PNF_Variable v2(v);
			   funcptr->ret(rnum, v2);

			   frets[frets.length() - 1] = "CHARACTER";
			   frets.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("ALOAD TCHARACTER \'\'\n");
			   conprint("FNCSRET TCHARACTER 0V\n");
			  }
			  break;

			  case TSTRING:
			  {
			   PNF_String v("");
			   PNF_Variable v2(v);
			   funcptr->ret(rnum, v2);

			   frets[frets.length() - 1] = "STRING";
			   frets.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("ALOAD TSTRING \"\"\n");
			   conprint("FNCSRET TSTRING 0V\n");
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 6746 "pnfha.ypp"
    {
			 String type = (yyvsp[(5) - (5)]).to_string().get();
			 if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TBOOLEAN:
			  {
			   PNF_Boolean v(false);
			   PNF_Variable v2(v);
			   funcptr->ret(rnum, v2);

			   frets[frets.length() - 1] = "BOOLEAN";
			   frets.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("ALOAD TBOOLEAN false\n");
			   conprint("FNCSRET TBOOLEAN 0V\n");
			  }
			  break;

			  case TNUMBER:
			  {
			   PNF_Number v(0);
			   PNF_Variable v2(v);
			   funcptr->ret(rnum, v2);

			   frets[frets.length() - 1] = "NUMBER";
			   frets.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("ALOAD TNUMBER 0\n");
			   conprint("FNCSRET TNUMBER 0V\n");
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character v('\0');
			   PNF_Variable v2(v);
			   funcptr->ret(rnum, v2);

			   frets[frets.length() - 1] = "CHARACTER";
			   frets.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("ALOAD TCHARACTER \'\'\n");
			   conprint("FNCSRET TCHARACTER 0V\n");
			  }
			  break;

			  case TSTRING:
			  {
			   PNF_String v("");
			   PNF_Variable v2(v);
			   funcptr->ret(rnum, v2);

			   frets[frets.length() - 1] = "STRING";
			   frets.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("ALOAD TSTRING \"\"\n");
			   conprint("FNCSRET TSTRING 0V\n");
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 6828 "pnfha.ypp"
    {
			 exptype = TVOID;
			;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 6832 "pnfha.ypp"
    {
			 String type = (yyvsp[(3) - (3)]).to_string().get();
			 if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TBOOLEAN:
			  {
			   frets2[frets2.length() - 1] = "BOOLEAN";
			   frets2.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   frets2[frets2.length() - 1] = "NUMBER";
			   frets2.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   frets2[frets2.length() - 1] = "CHARACTER";
			   frets2.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   frets2[frets2.length() - 1] = "STRING";
			   frets2.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 6880 "pnfha.ypp"
    {
			 String type = (yyvsp[(5) - (5)]).to_string().get();
			 if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TBOOLEAN:
			  {
			   frets2[frets2.length() - 1] = "BOOLEAN";
			   frets2.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   frets2[frets2.length() - 1] = "NUMBER";
			   frets2.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   frets2[frets2.length() - 1] = "CHARACTER";
			   frets2.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   frets2[frets2.length() - 1] = "STRING";
			   frets2.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 6930 "pnfha.ypp"
    {
			 exptype = TVOID;			;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 6933 "pnfha.ypp"
    {
			 String type = (yyvsp[(3) - (3)]).to_string().get();
			 if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");


			 rnum = 0;
			 switch (exptype)
			 {
			  case TBOOLEAN:
			  {
			   frets3[frets3.length() - 1] = "BOOLEAN";
			   frets3.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("RETURNF2 TBOOLEAN 0V\n");
			  }
			  break;

			  case TNUMBER:
			  {
			   frets3[frets3.length() - 1] = "NUMBER";
			   frets3.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("RETURNF2 TNUMBER 0V\n");
			  }
			  break;

			  case TCHARACTER:
			  {
			   frets3[frets3.length() - 1] = "CHARACTER";
			   frets3.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("RETURNF2 TCHARACTER 0V\n");
			  }
			  break;

			  case TSTRING:
			  {
			   frets3[frets3.length() - 1] = "STRING";
			   frets3.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("RETURNF2 TSTRING 0V\n");
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 6995 "pnfha.ypp"
    {
			 String type = (yyvsp[(5) - (5)]).to_string().get();
			 if (type == "void")
			  exptype = TVOID;
			 else if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TVOID:
			  {		  
			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("RETURNF2 TVOID 0V\n");
			  }
			  break;

			  case TBOOLEAN:
			  {
			   frets3[frets3.length() - 1] = "BOOLEAN";
			   frets3.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("RETURNF2 TBOOLEAN 0V\n");
			  }
			  break;

			  case TNUMBER:
			  {
			   frets3[frets3.length() - 1] = "NUMBER";
			   frets3.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("RETURNF2 TNUMBER 0V\n");
			  }
			  break;

			  case TCHARACTER:
			  {
			   frets3[frets3.length() - 1] = "CHARACTER";
			   frets3.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("RETURNF2 TCHARACTER 0V\n");
			  }
			  break;

			  case TSTRING:
			  {
			   frets3[frets3.length() - 1] = "STRING";
			   frets3.insert();

			   conprint("RNUM TNUMBER %d\n", rnum++);
			   conprint("RETURNF2 TSTRING 0V\n");
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 7202 "pnfha.ypp"
    {
			 exptype = TVOID;
			;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 7206 "pnfha.ypp"
    {
			 String type = (yyvsp[(3) - (3)]).to_string().get();
			 if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TBOOLEAN:
			  {
			   frets5[frets5.length() - 1] = "BOOLEAN";
			   frets5.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   frets5[frets5.length() - 1] = "NUMBER";
			   frets5.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   frets5[frets5.length() - 1] = "CHARACTER";
			   frets5.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   frets5[frets5.length() - 1] = "STRING";
			   frets5.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 7254 "pnfha.ypp"
    {
			 String type = (yyvsp[(5) - (5)]).to_string().get();
			 if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TBOOLEAN:
			  {
			   frets5[frets5.length() - 1] = "BOOLEAN";
			   frets5.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   frets5[frets5.length() - 1] = "NUMBER";
			   frets5.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   frets5[frets5.length() - 1] = "CHARACTER";
			   frets5.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   frets5[frets5.length() - 1] = "STRING";
			   frets5.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 7304 "pnfha.ypp"
    {
			 exptype = TVOID;
			;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 7308 "pnfha.ypp"
    {
			 String type = (yyvsp[(3) - (3)]).to_string().get();
			 if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TBOOLEAN:
			  {
			   frets6[frets6.length() - 1] = "BOOLEAN";
			   frets6.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   frets6[frets6.length() - 1] = "NUMBER";
			   frets6.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   frets6[frets6.length() - 1] = "CHARACTER";
			   frets6.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   frets6[frets6.length() - 1] = "STRING";
			   frets6.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 7356 "pnfha.ypp"
    {
			 String type = (yyvsp[(5) - (5)]).to_string().get();
			 if (type == "boolean")
			  exptype = TBOOLEAN;
			 else if (type == "number")
			  exptype = TNUMBER;
			 else if (type == "character")
			  exptype = TCHARACTER;
			 else if (type == "string")
			  exptype = TSTRING;
			 else
			  yyerror("Invalid type.");

			 switch (exptype)
			 {
			  case TBOOLEAN:
			  {
			   frets6[frets6.length() - 1] = "BOOLEAN";
			   frets6.insert();
			  }
			  break;

			  case TNUMBER:
			  {
			   frets6[frets6.length() - 1] = "NUMBER";
			   frets6.insert();
			  }
			  break;

			  case TCHARACTER:
			  {
			   frets6[frets6.length() - 1] = "CHARACTER";
			   frets6.insert();
			  }
			  break;

			  case TSTRING:
			  {
			   frets6[frets6.length() - 1] = "STRING";
			   frets6.insert();
			  }
			  break;

			  default:
			   yyerror("Invalid type.");
			 }
			;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 7408 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 7413 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 7418 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 7423 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 7428 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 7433 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 7438 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 7443 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 7448 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 7453 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 7458 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 7463 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 7468 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 7473 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 7478 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 7483 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 7488 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 7493 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 7498 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 7503 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 7508 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 7513 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 7518 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 7523 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 7528 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 7533 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 7538 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 7543 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 7548 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 7553 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 7562 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("PRINT TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 7568 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("PRINT TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("PRINT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
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

			   conprint("PRINT TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
			   conprint("PRINT TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 7614 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "ver")
			  conprint("VPRINT TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 7625 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("PRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 7631 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("PRINTLN TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("PRINTLN TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
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

			   conprint("PRINTLN TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
                           conprint("PRINTLN TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 7677 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "ver")
			  conprint("VPRINTLN TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 7688 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINT TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 7694 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("EPRINT TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("EPRINT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
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

			   conprint("EPRINT TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
			   conprint("EPRINT TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 7740 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 7746 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("EPRINTLN TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("EPRINTLN TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
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

			   conprint("EPRINTLN TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
			   conprint("EPRINTLN TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 7792 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINT TVOID 0V\n");
			;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 7797 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("FPRINT TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("FPRINT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
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

			   conprint("FPRINT TCHARACTER \'%s\'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
			   conprint("FPRINT TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 7843 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 7849 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("FPRINTLN TBOOLEAN %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("FPRINTLN TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
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

			   conprint("FPRINTLN TCHARACTER '%s'\n", str2.getString().c_str());
			  }
			  break;

			  case TSTRING:
                           conprint("FPRINTLN TSTRING \"%s\"\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 7895 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 conprint("APRINT TVOID 0V\n");

			 tree.add_node(print_command);
			;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 7907 "pnfha.ypp"
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
			  conprint("READ TBOOLEAN 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "number")
			 {
			  conprint("READ TNUMBER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "character")
			 {
			  conprint("READ TCHARACTER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "string")
			 {
			  conprint("READ TSTRING 0V\n");
			  ++varcount;
			 }
			 else
			  yyerror("Invalid type specifier.");


			 conprint("ATOC TVOID 0V\n");
			 conprint("VADD TVOID %u\n", address);
			 conprint("SWITCH TVOID 0V\n");
			 conprint("STOREA TVOID 0V\n");

			 tree.add_node(read_command);
			;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 7966 "pnfha.ypp"
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
			  conprint("FREAD TBOOLEAN 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "number")
			 {
			  conprint("FREAD TNUMBER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "character")
			 {
			  conprint("FREAD TCHARACTER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "string")
			 {
			  conprint("FREAD TSTRING 0V\n");
			  ++varcount;
			 }
			 else
			  yyerror("Invalid type specifier.");


			 conprint("ATOC TVOID 0V\n");
			 conprint("VADD TVOID %u\n", address);
			 conprint("SWITCH TVOID 0V\n");
			 conprint("STOREA TVOID 0V\n");


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

  case 356:

/* Line 1455 of yacc.c  */
#line 8039 "pnfha.ypp"
    {
			 ASTNode end_command("end_command");
			 conprint("QUIT TVOID %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(end_command);
			;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 8047 "pnfha.ypp"
    {
			 ASTNode asm_command("asm_command");
			 conprint("%s %s %s\n", strip_quotes((yyvsp[(2) - (4)]).to_string().get()).getString().c_str(), 
					      strip_quotes((yyvsp[(3) - (4)]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[(4) - (4)]).to_string().get()).getString().c_str());
			 tree.add_node(asm_command);
			;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 8056 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(3) - (4)]).to_string().get().getString() == "memory")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			  {
			   switch ((yyvsp[(4) - (4)]).getType())
			   {
			    case TBOOLEAN:
    			     conprint("LOAD TBOOLEAN %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TNUMBER:
    	 		     conprint("LOAD TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("LOAD TCHARACTER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TSTRING:
    			     conprint("LOAD TSTRING %g\n", (yyvsp[(4) - (4)]).to_number().get());
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
    			     conprint("LOADC TBOOLEAN %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TNUMBER:
    	 		     conprint("LOADC TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("LOADC TCHARACTER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TSTRING:
    			     conprint("LOADC TSTRING %g\n", (yyvsp[(4) - (4)]).to_number().get());
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
    			     conprint("VLOAD TBOOLEAN %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TNUMBER:
    			     conprint("VLOAD TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("VLOAD TCHARACTER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TSTRING:
    			     conprint("VLOAD TSTRING %g\n", (yyvsp[(4) - (4)]).to_number().get());
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
    			     conprint("VLOADC TBOOLEAN %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TNUMBER:
    			     conprint("VLOADC TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("VLOADC TCHARACTER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			     break;

			    case TSTRING:
    			     conprint("VLOADC TSTRING %g\n", (yyvsp[(4) - (4)]).to_number().get());
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
			   conprint("ARLOAD TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "aload")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
 			   conprint("ALOAD TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
                           yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "stk")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
                           conprint("LOADSP TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 8193 "pnfha.ypp"
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
    			     conprint("ELOAD TBOOLEAN 0V\n");
	 		     break;

			    case TNUMBER:
    			     conprint("ELOAD TNUMBER 0V\n");
			     break;

			    case TCHARACTER:
    			     conprint("ELOAD TCHARACTER 0V\n");
			     break;

			    case TSTRING:
    			     conprint("ELOAD TSTRING 0V\n");
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
    			     conprint("ELOADC TBOOLEAN 0V\n");
	 		     break;

			    case TNUMBER:
    			     conprint("ELOADC TNUMBER 0V\n");
			     break;

			    case TCHARACTER:
    			     conprint("ELOADC TCHARACTER 0V\n");
			     break;

			    case TSTRING:
    			     conprint("ELOADC TSTRING 0V\n");
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

  case 360:

/* Line 1455 of yacc.c  */
#line 8286 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "typeof")
			 {
			   conprint("TLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "iname")
			 {
			  conprint("INLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "icount")
			 {
			  conprint("ICLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "argn")
			 {
			  conprint("ARNLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "stk")
			  conprint("LOADSTACK TVOID 0V\n");	 
			 else
			  yyerror("Invalid load type.");
			;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 8314 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TBOOLEAN %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 8325 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TNUMBER %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "rvalue")
			 {
			  conprint("RNUM TNUMBER %d\n", (unsigned long)(yyvsp[(3) - (3)]).to_number().get());
			  conprint("RETURNV TVOID 0V\n");
			 }			 
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 8342 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TCHARACTER %c\n", (yyvsp[(3) - (3)]).to_character().get());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 8353 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 8364 "pnfha.ypp"
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
    			     conprint("LOAD TBOOLEAN %g\n", p.to_number().get());
			     break;

			    case TNUMBER:
    	 		     conprint("LOAD TNUMBER %g\n", p.to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("LOAD TCHARACTER %g\n", p.to_number().get());
			     break;

			    case TSTRING:
    			     conprint("LOAD TSTRING %g\n", p.to_number().get());
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
    			     conprint("LOADC TBOOLEAN %g\n", p.to_number().get());
			     break;

			    case TNUMBER:
    	 		     conprint("LOADC TNUMBER %g\n", p.to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("LOADC TCHARACTER %g\n", p.to_number().get());
			     break;

			    case TSTRING:
    			     conprint("LOADC TSTRING %g\n", p.to_number().get());
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
    			     conprint("VLOAD TBOOLEAN %u\n", paddress);
			     break;

			    case TNUMBER:			     
    			     conprint("VLOAD TNUMBER %u\n", paddress);
			     break;

			    case TCHARACTER:
    			     conprint("VLOAD TCHARACTER %u\n", paddress);
			     break;

			    case TSTRING:
    			     conprint("VLOAD TSTRING %u\n", paddress);
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
    			     conprint("VLOADC TBOOLEAN %u\n", paddress);
			     break;

			    case TNUMBER:
    			     conprint("VLOADC TNUMBER %u\n", paddress);
			     break;

			    case TCHARACTER:
    			     conprint("VLOADC TCHARACTER %u\n", paddress);
			     break;

			    case TSTRING:
    			     conprint("VLOADC TSTRING %u\n", paddress);
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
			   conprint("ARLOAD TVOID %g\n", p.to_number().get());
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
			     conprint("ALOAD TBOOLEAN %s\n", p.to_string().get().getString().c_str());
			     break;

			    case TNUMBER:
			     conprint("ALOAD TNUMBER %g\n", p.to_number().get());
			     break;

			    case TCHARACTER:
			     conprint("ALOAD TCHARACTER %c\n", p.to_character().get());
			     break;

			    case TSTRING:
			     conprint("ALOAD TSTRING %s\n", p.to_string().get().getString().c_str());
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

  case 366:

/* Line 1455 of yacc.c  */
#line 8539 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "heve")
			  conprint("HEGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "sheve")
			  conprint("SHEGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "eve")
			  conprint("EGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "exe")
			  conprint("EXGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "int")
			  conprint("IGET TVOID %g", (yyvsp[(3) - (3)]).to_number().get());
		  	 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(load_command);
			;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 8558 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "venum")
			 {
			  conprint("EPREP TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			  conprint("LOADE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid VTYPE2.");

			 tree.add_node(load_command);
			;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 8572 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[(3) - (4)]).to_string().get() == "rtype1")
			 {
			  conprint("RLOAD1 TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(load_command);
			;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 8585 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[(3) - (7)]).to_string().get() == "rtype2")
			 {
			  conprint("RPREP2 TSTRING %s\n", (yyvsp[(4) - (7)]).to_string().get().getString().c_str());
			  conprint("RLOAD2 TNUMBER %g\n", (yyvsp[(6) - (7)]).to_number().get());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(load_command);
			;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 8599 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[(5) - (6)]).to_number().get());
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 8609 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 8619 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 
			 if ((yyvsp[(3) - (6)]).to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)(yyvsp[(4) - (6)]).to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TBOOLEAN %s\n", (yyvsp[(6) - (6)]).to_boolean().get().getString().c_str());
			  conprint("FNCSRET TBOOLEAN 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 8644 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 8652 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 
			 if ((yyvsp[(3) - (6)]).to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)(yyvsp[(4) - (6)]).to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TNUMBER %g\n", (yyvsp[(6) - (6)]).to_number().get());
			  conprint("FNCSRET TNUMBER 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 8677 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 8685 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 
			 if ((yyvsp[(3) - (6)]).to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)(yyvsp[(4) - (6)]).to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TCHARACTER %c\n", (yyvsp[(6) - (6)]).to_character().get());
			  conprint("FNCSRET TCHARACTER 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 8710 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 8718 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 
			 if ((yyvsp[(3) - (6)]).to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)(yyvsp[(4) - (6)]).to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TSTRING %s\n", (yyvsp[(6) - (6)]).to_string().get().getString().c_str());
			  conprint("FNCSRET TSTRING 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 8743 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 8753 "pnfha.ypp"
    {
			 ASTNode goto_command("goto_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "normal")
			 {
			  conprint("GOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "condition")
			  conprint("CGOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "zero")
			  conprint("ZGOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "positive")
			  conprint("PGOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "negative")
			  conprint("NGOTO TVOID %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 else
			  yyerror("Invalid goto type.");

			 tree.add_node(goto_command);
			;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 8773 "pnfha.ypp"
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
			    conprint("GOTOL TVOID %u\n", labelTable[i].address());
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
			    conprint("CGOTOL TVOID %u\n", labelTable[i].address());
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
			    conprint("ZGOTOL TVOID %u\n", labelTable[i].address());
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
			    conprint("PGOTOL TVOID %u\n", labelTable[i].address());
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
			    conprint("NGOTOL TVOID %u\n", labelTable[i].address());
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

  case 382:

/* Line 1455 of yacc.c  */
#line 8878 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 8884 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 8890 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TCHARACTER %c\n", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 8896 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(operator_command);
			;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 8902 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 8908 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 8914 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 8920 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 8926 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 8932 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 8938 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 8944 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 8950 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 8956 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 8962 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 8968 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 8974 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("INC TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 8980 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("DEC TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 8986 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("AND TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 8992 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("OR TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 8998 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NOT TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 9004 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 9010 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 9016 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 9022 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 9028 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 9034 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 9040 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[(2) - (2)]).to_boolean().get();

			 conprint("EQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 9050 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[(2) - (2)]).to_boolean().get();

			 conprint("NEQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 9060 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 9066 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 9072 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 9078 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 9084 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 9090 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 9096 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 9102 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 9108 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 9114 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 9120 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 9126 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 9132 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTAND TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 9138 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTOR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 9144 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTXOR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 9150 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTNOT TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 9156 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSL TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 9162 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 9172 "pnfha.ypp"
    {
			 ASTNode top_commandp1("top_commandp1");

			 intop = true;
			 ++topcounter;

			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp1);
			;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 9183 "pnfha.ypp"
    {
			 ASTNode top_commandp2("top_commandp2");			 

			 tree.add_node(top_commandp2);
			;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 9189 "pnfha.ypp"
    {
			 ASTNode top_commandp3("top_commandp3");

			conprint("IFEND TVOID 0V\n"); 
			conprint("ENDIF TVOID 0V\n");

			 tree.add_node(top_commandp3);
			;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 9198 "pnfha.ypp"
    {
			 ASTNode top_commandp4("top_commandp4");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp4);
			;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 9207 "pnfha.ypp"
    {
			 ASTNode top_commandp5("top_commandp5");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");
			 conprint("EIF TVOID 0V\n");

			 tree.add_node(top_commandp5);
			;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 9219 "pnfha.ypp"
    {
			 ASTNode st_command("st_command");
			 conprint("ST TVOID 0V\n");
			 tree.add_node(st_command);
			;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 9227 "pnfha.ypp"
    {
			 ASTNode stack_command("stack_command");
			 conprint("PUSH TVOID 0V\n");
			 tree.add_node(stack_command);
			;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 9233 "pnfha.ypp"
    {
			 ASTNode stack_command("stack_command");
			 conprint("POP TVOID 0V\n");
			 tree.add_node(stack_command);
			;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 9241 "pnfha.ypp"
    {
			 ASTNode typeof_command("typeof_command");
			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "%accumulator")
  			  conprint("TYPEOF TVOID 0V\n");
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "%calc")
  			  conprint("CTYPEOF TVOID 0V\n");
                         else
			  yyerror("Invalid register type.");
			 tree.add_node(typeof_command);
			;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 9254 "pnfha.ypp"
    {
			 ASTNode rm_command("rm_command");
			 conprint("ATOC TVOID 0V\n");
			 tree.add_node(rm_command);
			;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 9260 "pnfha.ypp"
    {
			 conprint("ATOSP TVOID 0V\n");
			;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 9264 "pnfha.ypp"
    {
			 conprint("SPTOA TVOID 0V\n");
			;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 9268 "pnfha.ypp"
    {
			 ASTNode rm_command("rm_command");
			 conprint("SWITCH TVOID 0V\n");
			 tree.add_node(rm_command);
			;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 9276 "pnfha.ypp"
    {
			 ASTNode crash_command("crash_command");
			 conprint("CRASH TSTRING %s", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(crash_command);
			;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 9284 "pnfha.ypp"
    {
			 ASTNode version_command("version_command");

			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "pnf")
  			  conprint("VERSION TVOID 0V\n");
			 else if ((yyvsp[(2) - (2)]).to_string().get() == "pnfasm")
			  conprint("version TVOID 0V\n");
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "normal")
  			  ; // Not used yet. This is the first version.
                         else
			  yyerror("Invalid version type.");

			 tree.add_node(version_command);
			;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 9301 "pnfha.ypp"
    {
			 ASTNode halt_command("halt_command");
			 conprint("HALT TVOID 0V\n");
			 tree.add_node(halt_command);
			;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 9309 "pnfha.ypp"
    {
			 ASTNode modt_command("modt_command");

			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "%accumulator")
  			  conprint("MODT TVOID 0V\n");
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "%calc")
  			  conprint("MODCT TVOID 0V\n");
                         else
			  yyerror("Invalid register type.");

			 tree.add_node(modt_command);
			;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 9324 "pnfha.ypp"
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("RET TVOID 0V\n");
			 tree.add_node(subroutine_command);
			;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 9330 "pnfha.ypp"
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("CALL TVOID %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(subroutine_command);
			;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 9336 "pnfha.ypp"
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
			    conprint("CALLL TVOID %g\n", d);
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
			    conprint("HEVENT TVOID %g\n", d);
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
			    conprint("SHEVENT TVOID %g\n", d);
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
			    conprint("EVENT TVOID %g\n", d);
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
			    conprint("EXCEPTION TVOID %g\n", d);
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
			    conprint("INT TVOID %g\n", d);
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

  case 450:

/* Line 1455 of yacc.c  */
#line 9467 "pnfha.ypp"
    {
 			 ASTNode register_command("register_command");

			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "heve")
			 {
			  conprint("HEREM TVOID 0V\n");
 			  CELabel::dechevents();
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "sheve")
			 {
			  conprint("SHEREM TVOID 0V\n");
 			  CELabel::decshevents();
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "eve")
			 {
			  conprint("EREM TVOID 0V\n");
 			  CELabel::decevents();
                         }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "exe")
			 {
			  conprint("EXREM TVOID 0V\n");
 			  CELabel::decexceptions();
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get().getString() == "int")
			 {
			  conprint("IREM TVOID 0V\n");
 			  CELabel::decints();
                         }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 9501 "pnfha.ypp"
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
			    conprint("HEADD TVOID %g\n", d);
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
			    conprint("SHEADD TVOID %g\n", d);
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
			    conprint("EADD TVOID %g\n", d);
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
			    conprint("EXADD TVOID %g\n", d);
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
			    conprint("IADD TVOID %g\n", d);
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

  case 452:

/* Line 1455 of yacc.c  */
#line 9620 "pnfha.ypp"
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


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("HEED TVOID %g\n", d2);
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


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("SHEED TVOID %g\n", d2);
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


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("EED TVOID %g\n", d2);
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


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("EXED TVOID %g\n", d2);
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


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("IED TVOID %g\n", d2);
			 }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 9844 "pnfha.ypp"
    {
			 ASTNode register_command("register_command");

			 if ((yyvsp[(3) - (4)]).to_string().get() == "heve")
			  conprint("HEADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else if ((yyvsp[(3) - (4)]).to_string().get() == "sheve")
			  conprint("SHEADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else if ((yyvsp[(3) - (4)]).to_string().get() == "eve")
			  conprint("EADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else if ((yyvsp[(3) - (4)]).to_string().get() == "exe")
			  conprint("EXADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else if ((yyvsp[(3) - (4)]).to_string().get() == "int")
			  conprint("IADDB TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			 else
			  yyerror("Invalid STYPE.");

			 tree.add_node(register_command);
			;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 9865 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get().getString() == "memory")
			   conprint("STORE TVOID %g", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "variable")
			  {
			   conprint("VSTORE TVOID %g", (yyvsp[(4) - (4)]).to_number().get());
			  }
			  else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "stk")
			   conprint("STORESP TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid store type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%calc")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get().getString() == "memory")
			   conprint("STOREC TVOID %g", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "variable")
			  {
			   conprint("VSTOREC TVOID %g", (yyvsp[(4) - (4)]).to_number().get());
			  }
			  else
			   yyerror("Invalid store type.");
			 }
			 else
			  yyerror("Invalid register type.");

			 tree.add_node(store_command);
			;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 9898 "pnfha.ypp"
    {
			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "stk")
			 {
			  conprint("STORESTACK TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid store type.");
			;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 9907 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "%accumulator")
			 {
			  if ((yyvsp[(3) - (3)]).to_string().get().getString() == "variable")
			  {
			   conprint("VSTORE TVOID 0V");
			   ++varcount;
			  }
			  else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "tend")
			   conprint("ESTORE TVOID 0V");
			  else
			   yyerror("Invalid store type.");
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "%calc")
			 {
			  if ((yyvsp[(3) - (3)]).to_string().get().getString() == "variable")
			  {
			   conprint("VSTOREC TVOID 0V");
		 	   ++varcount;
			  }
			  else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "tend")
			   conprint("ESTOREC TVOID 0V");
			  else
			   yyerror("Invalid store type.");
			 }
			 else
			  yyerror("Invalid register type.");

			 tree.add_node(store_command);
			;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 9940 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 conprint("STOREA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 9948 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "venum")
			 {
			  conprint("EPREP TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			  conprint("STOREE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid VTYPE2.");

			 tree.add_node(store_command);
			;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 9962 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[(3) - (4)]).to_string().get() == "rtype1")
			 {
			  conprint("RSTORE1 TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(store_command);
			;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 9975 "pnfha.ypp"
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[(5) - (6)]).to_number().get());
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 9985 "pnfha.ypp"
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 9997 "pnfha.ypp"
    {
			 ASTNode break_command("break_command");

			 if (inswitch)
			  conprint("SWBREAK TVOID 0V\n");
			 else if (inwhile)
			  conprint("GOTOL TSTRING \"while_end_%u\"\n", whilecounter);
			 else if (indowhile)
			  conprint("GOTOL TSTRING \"dowhile_end_%u\"\n", dowhilecounter);
			 else if (infor)
			  conprint("GOTOL TSTRING \"for_end_%u\"\n", forcounter);
			 else if (indofor)
			  conprint("GOTOL TSTRING \"dofor_end_%u\"\n", doforcounter);
			 else if (breakinforever)
			  conprint("GOTOL TSTRING \"forever_end_%u\"\n", forevercounter);
  			 tree.add_node(break_command);
			;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 10015 "pnfha.ypp"
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
			    conprint("GOTOL TVOID %u\n", labelTable[i].address());
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

  case 464:

/* Line 1455 of yacc.c  */
#line 10043 "pnfha.ypp"
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

			   conprint("VADD TVOID %u\n", address);
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
			  conprint("LADD TVOID %u\n", address);
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
			  conprint("EADD TVOID %u\n", address);
			 }
			 else
			 {
			  yyerror("Invalid address type.");
			 }

			 tree.add_node(address_command);
			;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 10121 "pnfha.ypp"
    {
			 ASTNode add2v_command("add2v_command");

			 conprint("ADD2V TVOID 0V\n");

		         tree.add_node(add2v_command);
			;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 10131 "pnfha.ypp"
    {
			 ASTNode continue_command("continue_command");

			 if (inwhile)
			  conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 else if (indowhile)
			  conprint("GOTOL TSTRING \"dowhile_body_%u\"\n", dowhilecounter);
			 else if (infor)
			  conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 else if (indofor)
			  conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 else if (breakinforever)
			  conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);

		         tree.add_node(continue_command);
			;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 10150 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "void")
			   conprint("VCHECK TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get() == "number")
			   conprint("VCHECK TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "void")
			   conprint("VSUPP TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get() == "number")
			   conprint("VSUPP TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 10177 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "boolean")
			   conprint("VCHECK TBOOLEAN %s\n", (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "boolean")
			   conprint("VSUPP TBOOLEAN %s\n", (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 10200 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "character")
			   conprint("VCHECK TCHARACTER %c\n", (yyvsp[(4) - (4)]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "character")
			   conprint("VSUPP TCHARACTER %c\n", (yyvsp[(4) - (4)]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 10223 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (4)]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "string")
			   conprint("VCHECK TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "ver")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "string")
			   conprint("VSUPP TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 10246 "pnfha.ypp"
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "instruction")
			 {
   		          conprint("ISUPP TNUMBER %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 if ((yyvsp[(2) - (3)]).to_string().get() == "type")
			 {
			  conprint("TSUPP TNUMBER %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 10265 "pnfha.ypp"
    {
			 ASTNode comment_command("comment_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "l2")
			 {
			  String str = strip_quotes((yyvsp[(3) - (3)]).to_string().get());
			  conprint(";\\ %s\n", str.getString().c_str());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get() == "l1")
			 {
			  conprint("COMMENT TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else
			 {
			  yyerror("Invalid comment type.");
                         }

		         tree.add_node(comment_command);
			;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 10287 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "input")
			 {
			  if ((yyvsp[(3) - (3)]).to_string().get() == "in")
			   conprint("FIMODE TSTRING \"in\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "binary")
			   conprint("FIMODE TSTRING \"binary\"\n");
			  else
			   yyerror("Invalid file mode command.");
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get() == "output")
			 {
			  if ((yyvsp[(3) - (3)]).to_string().get() == "out")
			   conprint("FOMODE TSTRING \"out\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "binary")
			   conprint("FOMODE TSTRING \"binary\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "ate")
			   conprint("FOMODE TSTRING \"ate\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "app")
			   conprint("FOMODE TSTRING \"app\"\n");
			  else if ((yyvsp[(3) - (3)]).to_string().get() == "trunc")
			   conprint("FOMODE TSTRING \"trunc\"\n");
			  else
			   yyerror("Invalid file mode command.");
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 10320 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 if ((yyvsp[(2) - (3)]).to_string().get() == "input")
			 {
			  conprint("FIOPEN TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get() == "output")
			 {
  			  conprint("FOOPEN TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 10337 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "input")
			 {
			  conprint("FICLOSE TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get() == "output")
			 {
  			  conprint("FOCLOSE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 10354 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 conprint("FIEOF TVOID 0V\n");

			 tree.add_node(file_command);
			;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 10364 "pnfha.ypp"
    {
			 ASTNode meml_command("meml_command");

			 conprint("MEML TVOID 0V\n");

			 tree.add_node(meml_command);
			;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 10374 "pnfha.ypp"
    {
			 ASTNode pnfasm_command("pnfasm_command");

			 conprint("pnf %s %s %s\n", strip_quotes((yyvsp[(2) - (4)]).to_string().get()).getString().c_str(), 
						 strip_quotes((yyvsp[(3) - (4)]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[(4) - (4)]).to_string().get()).getString().c_str());

			 tree.add_node(pnfasm_command);
			;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 10385 "pnfha.ypp"
    {
			 ASTNode array_length_command("array_length_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			 conprint("ALENGTH TVOID 0V\n");

			 tree.add_node(array_length_command);
			;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 10395 "pnfha.ypp"
    {
			 ASTNode dup_command("dup_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "%accumulator")
			 {
			  conprint("DUP TVOID 0V\n");
			 }
			 else if ((yyvsp[(2) - (2)]).to_string().get() == "%calc")
			 {
			  conprint("CDUP TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid register.");

			 tree.add_node(dup_command);
			;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 10414 "pnfha.ypp"
    {
			 conprint("FRET TVOID 0V\n");
			;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 10424 "pnfha.ypp"
    {
			 unsigned long index = funcstk.find(fsaveid.to_string().get(), frets5, fparams5);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 bool declared = false;
			 unsigned long pindex = 0;
			 for (unsigned long i = 0; i < funcps[index].length(); ++i)
			 {
			  if (funcps[index][i].name() == (yyvsp[(2) - (3)]).to_string().get())
			  {
			   declared = true;
			   pindex = i;
			   break;
			  }
			 }

			 if (!declared)
			 {
			  yyerror("Parameter not declared.");
			  exit(-1);
			 }
	
			 conprint("PNUM TNUMBER %d\n", pindex);
			 conprint("ALOAD TNUMBER %d\n", index);
			
			 String str = (yyvsp[(3) - (3)]).to_string().get();
			 if (str == "void")
			   conprint("PARAMF2 TVOID 0V\n");
		         else if (str == "boolean")
			   conprint("PARAMF2 TBOOLEAN 0V\n");
			 else if (str == "number")
			   conprint("PARAMF2 TNUMBER 0V\n");
			 else if (str == "character")
			   conprint("PARAMF2 TCHARACTER 0V\n");
			 else if (str == "string")
			   conprint("PARAMF2 TSTRING 0V\n");
			 else
			   yyerror("Invalid type.");
			;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 10468 "pnfha.ypp"
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 10478 "pnfha.ypp"
    {
			 unsigned long index = funcstk.find(fsaveid.to_string().get(), frets5, fparams5);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 bool declared = false;
			 unsigned long pindex = 0;
			 for (unsigned long i = 0; i < funcps[index].length(); ++i)
			 {
			  if (funcps[index][i].name() == (yyvsp[(2) - (4)]).to_string().get())
			  {
			   declared = true;
			   pindex = i;
			   break;
			  }
			 }

			 if (!declared)
			 {
			  yyerror("Parameter not declared.");
			  exit(-1);
			 }

			 conprint("FNCLOAD TNUMBER %d\n", index);

			 conprint("PNUM TNUMBER %d\n", pindex);

			 String type = (yyvsp[(4) - (4)]).to_string().get();
			 if (type == "void")
 			  conprint("FNCSPARAM TVOID 0V\n");
			 else if (type == "boolean")
 			  conprint("FNCSPARAM TBOOLEAN 0V\n");
			 else if (type == "number")
 			  conprint("FNCSPARAM TNUMBER 0V\n");
			 else if (type == "character")
 			  conprint("FNCSPARAM TCHARACTER 0V\n");
			 else if (type == "string")
 			  conprint("FNCSPARAM TSTRING 0V\n");
			 else
			  yyerror("Invalid type.");

			 conprint("FNCSTORE TNUMBER %d\n", index);
			;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 10525 "pnfha.ypp"
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 10535 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(3) - (6)]);
			;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 10541 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(3) - (6)]);
			;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 10547 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#BIN#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 10553 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#PBIN#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 10559 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#LIB#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 10567 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include %s", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 10573 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include <%s>", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 10579 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 10585 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 10591 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), 
						    (yyvsp[(3) - (3)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 10598 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 10604 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endm\n");
			 tree.add_node(pp_statement);
		 	;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 10610 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 10616 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 10622 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#infdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 10628 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#else\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 10634 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endif\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 10640 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_DATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 10646 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_TIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 10652 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_LINE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 10658 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_FILE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 10664 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CDATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 10670 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CTIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 10676 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
		 	 conprint("%%include %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 10682 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%include <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 10688 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 10694 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 10700 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), 
						     (yyvsp[(3) - (3)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 10707 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 10713 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endm\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 10719 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 10725 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 10731 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%infdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 10737 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%else\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 10743 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endif\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 10749 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_DATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 10755 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_TIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 10761 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_LINE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 10767 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_FILE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 10773 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CDATE()\n");
			 tree.add_node(pp_statement);
			;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 10779 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CTIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;



/* Line 1455 of yacc.c  */
#line 15246 "pnfha.tab.cpp"
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
#line 10785 "pnfha.ypp"

/* Additional C/C++ Code */
void actual_parameters()
{
 pnum3++;
 switch (exptype)
 {
  case TVOID:
   conprint("ALOAD TNUMBER %d\n", fsaveindex);
   conprint("PNUM TNUMBER %d\n", pnum++);
   conprint("PARAMF TVOID 0V\n");
   break;

  case TBOOLEAN:
   conprint("ALOAD TNUMBER %d\n", fsaveindex);
   conprint("PNUM TNUMBER %d\n", pnum++);
   conprint("PARAMF TBOOLEAN %s\n", saveexp.to_boolean().get().getString().c_str());
   break;

  case TNUMBER:
  {
   conprint("ALOAD TNUMBER %d\n", fsaveindex);
   conprint("PNUM TNUMBER %d\n", pnum++);
   double d = saveexp.to_number().get();
   unsigned long n = (unsigned long)d;
   conprint("PARAMF TNUMBER %d\n", n);
  }
  break;

  case TCHARACTER:
  {
   conprint("ALOAD TNUMBER %d\n", fsaveindex);
   conprint("PNUM TNUMBER %d\n", pnum++);
   conprint("PARAMF TCHARACTER '%c'\n", saveexp.to_character().get());
  }
  break;

  case TSTRING:
   conprint("ALOAD TNUMBER %d\n", fsaveindex);
   conprint("PNUM TNUMBER %d\n", pnum++);
   conprint("PARAMF TSTRING \"%s\"\n", saveexp.to_string().get().getString().c_str());
   break;

 default:
  yyerror("Invalid type.");
			 }
}

void actual_parameters2()
{
 pnum3++;
 switch (exptype)
 {
  case TVOID:
   conprint("ALOAD TNUMBER %d\n", fsaveindex2);
   conprint("PNUM TNUMBER %d\n", pnum++);
   conprint("PARAMF TVOID 0V\n");
   break;

  case TBOOLEAN:
   conprint("ALOAD TNUMBER %d\n", fsaveindex2);
   conprint("PNUM TNUMBER %d\n", pnum++);
   conprint("PARAMF TBOOLEAN %s\n", saveexp2.to_boolean().get().getString().c_str());
   break;

  case TNUMBER:
  {
   conprint("ALOAD TNUMBER %d\n", fsaveindex2);
   conprint("PNUM TNUMBER %d\n", pnum++);
   double d = saveexp2.to_number().get();
   unsigned long n = (unsigned long)d;
   conprint("PARAMF TNUMBER %d\n", n);
  }
  break;

  case TCHARACTER:
  {
   conprint("ALOAD TNUMBER %d\n", fsaveindex2);
   conprint("PNUM TNUMBER %d\n", pnum++);
   conprint("PARAMF TCHARACTER '%s'\n", ((String)saveexp2.to_character().get()).getString().c_str());
  }
  break;

  case TSTRING:
   conprint("ALOAD TNUMBER %d\n", fsaveindex2);
   conprint("PNUM TNUMBER %d\n", pnum++);
   conprint("PARAMF TSTRING \"%s\"\n", saveexp2.to_string().get().getString().c_str());
   break;

 default:
  yyerror("Invalid type.");
			 }
}
