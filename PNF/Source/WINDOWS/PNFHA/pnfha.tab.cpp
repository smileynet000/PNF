
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
			 7. Debugged...
			 8. Added default parameters...
			 9. Debugged...
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

void actual_parameters(PNF_Variable v);
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
unsigned long pnum4 = 0;
unsigned long pnum5 = 0;
unsigned long rnum = 0;
unsigned long funcnum = 0;


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


bool fncdefault = false;


ASTTree tree;


/* Line 189 of yacc.c  */
#line 842 "pnfha.tab.cpp"

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
     DEFAULTV = 392,
     DEFAULTV2 = 393,
     PBIN = 394,
     PPBIN = 395,
     PLIB = 396,
     PINCLUDE = 397,
     PIMPORT = 398,
     PDEFINE = 399,
     PMACRO = 400,
     PENDM = 401,
     PUNDEF = 402,
     PIFDEF = 403,
     PIFNDEF = 404,
     PELSE = 405,
     PENDIF = 406,
     PPDATE = 407,
     PPTIME = 408,
     PPLINE = 409,
     PPFILE = 410,
     PPCDATE = 411,
     PPCTIME = 412,
     PPINCLUDE = 413,
     PPIMPORT = 414,
     PPDEFINE = 415,
     PPMACRO = 416,
     PPENDM = 417,
     PPUNDEF = 418,
     PPIFDEF = 419,
     PPIFNDEF = 420,
     PPELSE = 421,
     PPENDIF = 422,
     PPPDATE = 423,
     PPPTIME = 424,
     PPPLINE = 425,
     PPPFILE = 426,
     PPPCDATE = 427,
     PPPCTIME = 428
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
#line 1057 "pnfha.tab.cpp"

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
#define YYLAST   1715

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  177
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  178
/* YYNRULES -- Number of rules.  */
#define YYNRULES  537
/* YYNRULES -- Number of states.  */
#define YYNSTATES  971

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   431

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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176
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
     760,   778,   780,   782,   786,   792,   794,   798,   799,   802,
     804,   806,   808,   810,   813,   818,   821,   823,   825,   827,
     833,   840,   845,   851,   852,   853,   862,   864,   868,   877,
     880,   883,   886,   888,   890,   891,   902,   903,   905,   912,
     914,   922,   924,   931,   933,   940,   945,   947,   953,   955,
     956,   958,   963,   964,   966,   971,   973,   978,   980,   981,
     982,   996,  1000,  1002,  1006,  1012,  1014,  1018,  1024,  1026,
    1030,  1036,  1038,  1042,  1048,  1050,  1054,  1060,  1062,  1064,
    1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,  1084,
    1086,  1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1104,
    1106,  1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,  1124,
    1127,  1130,  1132,  1135,  1138,  1140,  1143,  1145,  1148,  1150,
    1153,  1155,  1158,  1162,  1166,  1170,  1173,  1178,  1183,  1188,
    1191,  1195,  1199,  1203,  1207,  1212,  1216,  1220,  1225,  1233,
    1240,  1246,  1247,  1256,  1257,  1266,  1267,  1276,  1277,  1286,
    1290,  1294,  1296,  1299,  1302,  1305,  1307,  1310,  1312,  1315,
    1317,  1320,  1322,  1325,  1327,  1330,  1332,  1335,  1337,  1339,
    1341,  1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,  1360,
    1363,  1366,  1369,  1372,  1375,  1378,  1381,  1384,  1387,  1390,
    1393,  1396,  1399,  1401,  1403,  1405,  1407,  1409,  1411,  1413,
    1414,  1415,  1416,  1417,  1427,  1429,  1431,  1433,  1436,  1438,
    1440,  1442,  1444,  1447,  1450,  1452,  1455,  1457,  1460,  1464,
    1467,  1471,  1476,  1481,  1486,  1489,  1493,  1496,  1500,  1505,
    1512,  1518,  1520,  1523,  1527,  1529,  1531,  1536,  1541,  1546,
    1551,  1555,  1559,  1563,  1567,  1570,  1572,  1574,  1579,  1584,
    1587,  1589,  1591,  1593,  1594,  1600,  1601,  1608,  1617,  1626,
    1628,  1630,  1632,  1635,  1640,  1643,  1648,  1652,  1655,  1657,
    1660,  1663,  1666,  1668,  1670,  1672,  1674,  1676,  1678,  1680,
    1682,  1685,  1690,  1693,  1698,  1702,  1705,  1707,  1710,  1713,
    1716,  1718,  1720,  1722,  1724,  1726,  1728,  1730
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     178,     0,    -1,    -1,   178,   179,    -1,    -1,   180,   174,
      -1,   181,    -1,     1,    -1,    -1,   182,   183,    -1,   181,
      39,   183,    -1,   188,    -1,    38,    -1,   184,    -1,   185,
      -1,   187,    -1,   186,    -1,   247,    -1,   353,    -1,   354,
      -1,   249,    38,    -1,   272,    38,    -1,   306,    38,    -1,
      44,    41,    -1,    73,    44,    41,    -1,    74,    44,    41,
      -1,   189,    -1,   198,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    29,   183,    30,   190,   127,   191,   183,
     192,   128,   193,   195,   194,   197,    -1,    -1,    -1,    86,
     196,   183,   128,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      64,    29,   249,    30,    31,   199,   206,   200,   210,   201,
     202,    32,    -1,    -1,    -1,    -1,    65,    29,   183,    30,
     203,    31,   212,   204,   217,   205,    32,    -1,    -1,   207,
     208,    -1,   206,   208,    -1,    -1,    87,   249,   209,    41,
     183,    -1,    -1,    -1,    89,    41,   211,   183,    -1,    -1,
     213,   214,    -1,   212,   214,    -1,    -1,    -1,    88,   249,
     215,    41,   216,   183,    -1,    -1,    -1,    90,    41,   218,
     183,    -1,    -1,   220,   222,    -1,   226,    -1,   232,    -1,
     238,    -1,    -1,   245,   221,    -1,    -1,    -1,    -1,    93,
      29,   223,   183,   224,    30,   225,   183,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    97,   228,   183,    93,   229,    29,
     230,   183,   231,    30,    -1,    -1,    -1,    -1,    -1,    -1,
     233,    99,    29,   234,   183,    38,   235,   183,    38,   236,
     183,   237,    30,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,   239,   183,   240,    99,    29,   241,   183,    38,
     242,   183,    38,   243,   183,   244,    30,    -1,    -1,   101,
     246,   183,    -1,    31,   248,    32,    -1,   181,    -1,   181,
     248,    -1,   250,    -1,   251,    -1,   252,    -1,   253,    -1,
     254,    -1,   255,    -1,   256,    -1,   258,    -1,   259,    -1,
      33,    -1,    29,   250,    30,    -1,    34,    -1,     7,   251,
      -1,   251,    26,   251,    -1,   251,    27,   251,    -1,    29,
     251,    30,    -1,    35,    -1,   252,    14,   252,    -1,   252,
      15,   252,    -1,   252,    13,   252,    -1,   252,    12,   252,
      -1,   252,    11,   252,    -1,    15,   252,    -1,   252,    10,
     252,    -1,   252,     9,   252,    -1,     4,   252,    -1,   252,
       4,    -1,     3,   252,    -1,   252,     3,    -1,   252,     8,
     252,    -1,   252,    24,   252,    -1,   252,    25,   252,    -1,
       6,   252,    -1,   252,    17,   252,    -1,   252,    16,   252,
      -1,    29,   252,    30,    -1,    36,    -1,   253,    14,   253,
      -1,   253,    15,   253,    -1,   253,    13,   253,    -1,   253,
      12,   253,    -1,   253,    11,   253,    -1,   253,    10,   253,
      -1,   253,     9,   253,    -1,     4,   253,    -1,   253,     4,
      -1,     3,   253,    -1,   253,     3,    -1,    29,   253,    30,
      -1,    37,    -1,   254,    14,   254,    -1,    43,   254,    -1,
      29,   254,    30,    -1,    44,    -1,     8,   255,    -1,     7,
     255,    -1,   255,    26,   255,    -1,   255,    27,   255,    -1,
     255,    14,   255,    -1,   255,    15,   255,    -1,   255,    13,
     255,    -1,   255,    12,   255,    -1,   255,    11,   255,    -1,
      15,   255,    -1,   255,    10,   255,    -1,   255,     9,   255,
      -1,     4,   255,    -1,   255,     4,    -1,     3,   255,    -1,
     255,     3,    -1,    29,   255,    30,    -1,   252,    23,   252,
      -1,   252,    22,   252,    -1,   252,    21,   252,    -1,   252,
      19,   252,    -1,   252,    20,   252,    -1,    -1,   252,    18,
     252,   257,    -1,    29,   258,    30,    -1,    44,    26,   251,
      -1,   251,    26,    44,    -1,    44,    27,   251,    -1,   251,
      27,    44,    -1,    44,    14,   252,    -1,    44,    15,   252,
      -1,    44,    13,   252,    -1,    44,    12,   252,    -1,    44,
      10,   252,    -1,    44,     9,   252,    -1,   252,    14,    44,
      -1,   252,    15,    44,    -1,   252,    13,    44,    -1,   252,
      12,    44,    -1,   252,    10,    44,    -1,   252,     9,    44,
      -1,    44,    14,   253,    -1,    44,    15,   253,    -1,    44,
      13,   253,    -1,    44,    12,   253,    -1,    44,    10,   253,
      -1,    44,     9,   253,    -1,   253,    14,    44,    -1,   253,
      15,    44,    -1,   253,    13,    44,    -1,   253,    12,    44,
      -1,   253,    10,    44,    -1,   253,     9,    44,    -1,    44,
      14,   254,    -1,   254,    14,    44,    -1,   252,    23,    44,
      -1,   252,    22,    44,    -1,   252,    21,    44,    -1,   252,
      19,    44,    -1,   252,    20,    44,    -1,   252,    18,    44,
      -1,    44,    23,   252,    -1,    44,    22,   252,    -1,    44,
      21,   252,    -1,    44,    19,   252,    -1,    44,    20,   252,
      -1,    44,    18,   252,    -1,    44,     8,   252,    -1,    44,
      24,   252,    -1,    44,    25,   252,    -1,   252,     8,    44,
      -1,   252,    24,    44,    -1,   252,    25,    44,    -1,     6,
      44,    -1,    44,    17,   252,    -1,    44,    16,   252,    -1,
     252,    17,    44,    -1,   252,    16,    44,    -1,   260,    -1,
      29,   259,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,    41,    35,   261,    29,   303,    30,    44,   262,    29,
     263,   267,   264,   265,    30,   266,   285,    -1,   268,    -1,
     269,    -1,   138,    41,    52,    -1,   269,    39,   138,    41,
      52,    -1,   270,    -1,   269,    39,   270,    -1,    -1,   271,
     249,    -1,   273,    -1,   282,    -1,   277,    -1,   281,    -1,
      45,    44,    -1,    45,    44,    28,   249,    -1,   100,    44,
      -1,   274,    -1,   275,    -1,   276,    -1,   114,    37,    37,
      28,    37,    -1,   119,   117,    37,    37,    28,    37,    -1,
     119,   117,    37,    37,    -1,   122,    37,   120,   252,   121,
      -1,    -1,    -1,   113,    44,    28,    31,   278,   280,   279,
      32,    -1,    37,    -1,   280,    39,    37,    -1,   116,   117,
      37,    28,    37,   118,   118,    37,    -1,    73,    44,    -1,
      74,    44,    -1,    92,    44,    -1,   283,    -1,   297,    -1,
      -1,   133,    29,   301,    30,    44,    29,   286,    30,   284,
     285,    -1,    -1,   290,    -1,   286,    39,    45,    44,    41,
      52,    -1,   291,    -1,   287,    39,    45,    44,    41,    52,
     292,    -1,   295,    -1,   288,    39,    45,    44,    41,    52,
      -1,   296,    -1,   289,    39,    45,    44,    41,    52,    -1,
      45,    44,    41,    52,    -1,    33,    -1,    45,    44,    41,
      52,   292,    -1,    33,    -1,    -1,   293,    -1,    28,   249,
      41,    35,    -1,    -1,   137,    -1,    45,    44,    41,    52,
      -1,    33,    -1,    45,    44,    41,    52,    -1,    33,    -1,
      -1,    -1,   132,   294,    29,   302,    30,    44,    29,   287,
      30,   298,   300,   299,   285,    -1,    31,   248,    32,    -1,
      33,    -1,    45,    41,    52,    -1,   301,    39,    45,    41,
      52,    -1,    33,    -1,    45,    41,    52,    -1,   302,    39,
      45,    41,    52,    -1,    33,    -1,    45,    41,    52,    -1,
     303,    39,    45,    41,    52,    -1,    33,    -1,    45,    41,
      52,    -1,   304,    39,    45,    41,    52,    -1,    33,    -1,
      45,    41,    52,    -1,   305,    39,    45,    41,    52,    -1,
     307,    -1,   308,    -1,   309,    -1,   310,    -1,   311,    -1,
     316,    -1,   317,    -1,   323,    -1,   324,    -1,   325,    -1,
     326,    -1,   327,    -1,   328,    -1,   329,    -1,   330,    -1,
     331,    -1,   332,    -1,   333,    -1,   334,    -1,   335,    -1,
     336,    -1,   337,    -1,   338,    -1,   339,    -1,   340,    -1,
     341,    -1,   342,    -1,   343,    -1,   344,    -1,   345,    -1,
     346,    -1,    46,    -1,    46,   249,    -1,    46,    77,    -1,
      47,    -1,    47,   249,    -1,    47,    77,    -1,    48,    -1,
      48,   249,    -1,    49,    -1,    49,   249,    -1,   109,    -1,
     109,   249,    -1,   110,    -1,   110,   249,    -1,    46,   122,
      37,    -1,    53,    52,    44,    -1,   111,    52,    44,    -1,
      50,   252,    -1,    51,    37,    37,   254,    -1,    54,    62,
      55,   252,    -1,    54,    62,    55,    52,    -1,    54,    55,
      -1,    54,    55,   251,    -1,    54,    55,   252,    -1,    54,
      55,   253,    -1,    54,    55,   254,    -1,    54,    62,    55,
      44,    -1,    54,    75,   252,    -1,    54,   115,    37,    -1,
      54,   116,   117,    37,    -1,    54,   116,   117,    37,   120,
     252,   121,    -1,    54,   122,    37,   120,   252,   121,    -1,
      54,   122,    37,   120,   121,    -1,    -1,    54,   352,    55,
     252,    41,   251,   312,   285,    -1,    -1,    54,   352,    55,
     252,    41,   252,   313,   285,    -1,    -1,    54,   352,    55,
     252,    41,   253,   314,   285,    -1,    -1,    54,   352,    55,
     252,    41,   254,   315,   285,    -1,    56,    57,   252,    -1,
      56,    57,    44,    -1,    14,    -1,    14,   252,    -1,    14,
     253,    -1,    14,   254,    -1,    15,    -1,    42,   252,    -1,
      13,    -1,    13,   252,    -1,    12,    -1,    12,   252,    -1,
      11,    -1,    11,   252,    -1,    10,    -1,    10,   252,    -1,
       9,    -1,     9,   252,    -1,     4,    -1,     3,    -1,    26,
      -1,    27,    -1,     7,    -1,    23,    -1,    22,    -1,    21,
      -1,    19,    -1,    20,    -1,    18,    -1,    23,   251,    -1,
      22,   251,    -1,    23,   252,    -1,    22,   252,    -1,    21,
     252,    -1,    19,   252,    -1,    20,   252,    -1,    18,   252,
      -1,    23,   253,    -1,    22,   253,    -1,    21,   253,    -1,
      19,   253,    -1,    20,   253,    -1,    18,   253,    -1,     8,
      -1,    24,    -1,    25,    -1,     6,    -1,    17,    -1,    16,
      -1,   318,    -1,    -1,    -1,    -1,    -1,   183,    40,   319,
     320,   183,   321,    41,   322,   183,    -1,    58,    -1,    59,
      -1,    60,    -1,    61,    62,    -1,    63,    -1,   130,    -1,
     131,    -1,    64,    -1,    66,   254,    -1,    67,    68,    -1,
      69,    -1,    70,    62,    -1,    71,    -1,    72,   252,    -1,
      72,    75,    44,    -1,    81,    75,    -1,    82,    75,    44,
      -1,    83,    75,    44,    44,    -1,    82,   123,    75,   252,
      -1,    84,    62,    55,   252,    -1,    84,    55,    -1,    84,
      62,    55,    -1,    84,    96,    -1,    84,   115,    37,    -1,
      84,   116,   117,    37,    -1,    84,   122,    37,   120,   252,
     121,    -1,    84,   122,    37,   120,   121,    -1,    91,    -1,
      91,    44,    -1,    94,    76,    44,    -1,    95,    -1,   102,
      -1,   103,    77,    52,   252,    -1,   103,    77,    52,   251,
      -1,   103,    77,    52,   253,    -1,   103,    77,    52,   254,
      -1,   103,    77,   252,    -1,   104,    78,   254,    -1,   105,
      79,    80,    -1,   106,    79,   254,    -1,   107,    79,    -1,
     108,    -1,   112,    -1,   124,    37,    37,    37,    -1,   122,
      37,   118,   125,    -1,   126,    62,    -1,   135,    -1,   347,
      -1,   349,    -1,    -1,   351,    44,    52,   348,   285,    -1,
      -1,   351,    44,    52,    52,   350,   285,    -1,   136,    29,
     304,    30,    44,    29,   288,    30,    -1,   132,    29,   305,
      30,    44,    29,   289,    30,    -1,   139,    -1,   140,    -1,
     141,    -1,   142,    37,    -1,   142,   175,    37,   176,    -1,
     143,    37,    -1,   143,   175,    37,   176,    -1,   144,    37,
      37,    -1,   145,    37,    -1,   146,    -1,   147,    37,    -1,
     148,    37,    -1,   149,    37,    -1,   150,    -1,   151,    -1,
     152,    -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,
     157,    -1,   158,    37,    -1,   158,   175,    37,   176,    -1,
     159,    37,    -1,   159,   175,    37,   176,    -1,   160,    37,
      37,    -1,   161,    37,    -1,   162,    -1,   163,    37,    -1,
     164,    37,    -1,   165,    37,    -1,   166,    -1,   167,    -1,
     168,    -1,   169,    -1,   170,    -1,   171,    -1,   172,    -1,
     173,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   974,   974,   975,   978,   978,   983,   984,   987,   987,
     992,   995,   997,   999,  1001,  1003,  1005,  1007,  1010,  1011,
    1014,  1021,  1028,  1035,  1068,  1076,  1086,  1092,  1097,  1108,
    1114,  1123,  1130,  1135,  1107,  1150,  1151,  1150,  1172,  1176,
    1215,  1244,  1249,  1175,  1261,  1276,  1282,  1260,  1296,  1296,
    1301,  1305,  1304,  1348,  1349,  1348,  1359,  1359,  1364,  1368,
    1399,  1367,  1414,  1415,  1414,  1425,  1425,  1434,  1439,  1444,
    1450,  1449,  1469,  1479,  1485,  1468,  1506,  1516,  1523,  1531,
    1537,  1506,  1555,  1559,  1569,  1577,  1587,  1555,  1607,  1620,
    1629,  1635,  1644,  1654,  1606,  1670,  1669,  1689,  1693,  1698,
    1705,  1706,  1714,  1716,  1718,  1720,  1722,  1724,  1726,  1731,
    1741,  1744,  1760,  1774,  1790,  1806,  1809,  1823,  1829,  1835,
    1841,  1847,  1853,  1861,  1868,  1875,  1881,  1887,  1893,  1899,
    1907,  1916,  1924,  1931,  1939,  1947,  1951,  1964,  1971,  1978,
    1985,  1991,  1998,  2005,  2012,  2018,  2024,  2030,  2036,  2040,
    2053,  2078,  2085,  2089,  2160,  2200,  2237,  2314,  2393,  2473,
    2511,  2549,  2587,  2625,  2638,  2676,  2714,  2742,  2770,  2798,
    2826,  2829,  2840,  2851,  2862,  2873,  2885,  2884,  2907,  2908,
    2957,  3006,  3055,  3104,  3146,  3188,  3230,  3272,  3314,  3356,
    3398,  3440,  3482,  3524,  3566,  3608,  3650,  3692,  3734,  3776,
    3818,  3860,  3902,  3944,  3986,  4028,  4070,  4112,  4176,  4240,
    4285,  4330,  4375,  4420,  4465,  4510,  4555,  4600,  4645,  4690,
    4735,  4780,  4825,  4870,  4915,  4960,  5005,  5050,  5087,  5132,
    5177,  5222,  5269,  5273,  5280,  5284,  5291,  5296,  5305,  5315,
    5279,  5328,  5335,  5344,  5428,  5514,  5518,  5541,  5541,  5723,
    5728,  5733,  5738,  5745,  5803,  5884,  5919,  5924,  5929,  5936,
    5948,  5963,  5979,  5991,  5999,  5990,  6013,  6021,  6027,  6052,
    6076,  6099,  6123,  6124,  6128,  6127,  6173,  6175,  6268,  6380,
    6482,  6598,  6643,  6702,  6747,  6806,  6824,  6832,  6850,  6858,
    6858,  6871,  6878,  6878,  6885,  6903,  6911,  6929,  6938,  6956,
    6937,  6976,  6981,  6989,  7075,  7157,  7161,  7209,  7259,  7262,
    7324,  7531,  7535,  7583,  7633,  7637,  7685,  7737,  7742,  7747,
    7752,  7757,  7762,  7767,  7772,  7777,  7782,  7787,  7792,  7797,
    7802,  7807,  7812,  7817,  7822,  7827,  7832,  7837,  7842,  7847,
    7852,  7857,  7862,  7867,  7872,  7877,  7882,  7887,  7891,  7897,
    7943,  7954,  7960,  8006,  8017,  8023,  8069,  8075,  8121,  8126,
    8172,  8178,  8224,  8236,  8295,  8368,  8376,  8385,  8522,  8615,
    8643,  8654,  8671,  8682,  8693,  8868,  8887,  8901,  8914,  8928,
    8938,  8949,  8948,  8982,  8981,  9015,  9014,  9048,  9047,  9082,
    9102,  9207,  9213,  9219,  9225,  9231,  9237,  9243,  9249,  9255,
    9261,  9267,  9273,  9279,  9285,  9291,  9297,  9303,  9309,  9315,
    9321,  9327,  9333,  9339,  9345,  9351,  9357,  9363,  9369,  9379,
    9389,  9395,  9401,  9407,  9413,  9419,  9425,  9431,  9437,  9443,
    9449,  9455,  9461,  9467,  9473,  9479,  9485,  9491,  9497,  9502,
    9513,  9519,  9528,  9501,  9548,  9556,  9562,  9570,  9583,  9589,
    9593,  9597,  9605,  9613,  9630,  9638,  9653,  9659,  9665,  9796,
    9830,  9949, 10173, 10194, 10227, 10236, 10269, 10277, 10291, 10304,
   10314, 10326, 10344, 10372, 10450, 10460, 10479, 10506, 10529, 10552,
   10575, 10594, 10616, 10649, 10666, 10683, 10693, 10703, 10714, 10724,
   10743, 10749, 10750, 10754, 10753, 10808, 10807, 10864, 10870, 10876,
   10882, 10888, 10896, 10902, 10908, 10914, 10920, 10927, 10933, 10939,
   10945, 10951, 10957, 10963, 10969, 10975, 10981, 10987, 10993, 10999,
   11005, 11011, 11017, 11023, 11029, 11036, 11042, 11048, 11054, 11060,
   11066, 11072, 11078, 11084, 11090, 11096, 11102, 11108
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
  "FUNCTION", "FUNCDEF", "FUNCCALL", "FRET", "FPARAMETER", "DEFAULTV",
  "DEFAULTV2", "PBIN", "PPBIN", "PLIB", "PINCLUDE", "PIMPORT", "PDEFINE",
  "PMACRO", "PENDM", "PUNDEF", "PIFDEF", "PIFNDEF", "PELSE", "PENDIF",
  "PPDATE", "PPTIME", "PPLINE", "PPFILE", "PPCDATE", "PPCTIME",
  "PPINCLUDE", "PPIMPORT", "PPDEFINE", "PPMACRO", "PPENDM", "PPUNDEF",
  "PPIFDEF", "PPIFNDEF", "PPELSE", "PPENDIF", "PPPDATE", "PPPTIME",
  "PPPLINE", "PPPFILE", "PPPCDATE", "PPPCTIME", "\"\\n\"", "\"<\"",
  "\">\"", "$accept", "input", "line", "$@1", "statement", "$@2", "stmt",
  "expression_statement", "declaration_statement", "command_statement",
  "label_statement", "control_statement", "if_statement", "$@3", "$@4",
  "$@5", "$@6", "$@7", "opt_else", "$@8", "eif", "switch_statement", "$@9",
  "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "case_statements",
  "$@16", "case_statement", "$@17", "opt_default_statement", "$@18",
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
  "$@49", "$@50", "$@51", "actual_function_parameters", "dv",
  "opt_expressions", "opt_expression", "@53", "declaration",
  "variable_declaration", "enumv_declaration", "rangev_declaration",
  "array_declaration", "enum_declaration", "$@54", "$@55", "enum_strings",
  "range_declaration", "label_declaration", "function_declaration", "$@56",
  "nothing", "parameter_declaration", "parameter_declaration2",
  "parameter_declaration5", "parameter_declaration6", "opt_var",
  "opt_var2", "opt_default_value", "dvalue", "optdefaultv", "opt_var5",
  "opt_var6", "function_declaration2", "$@57", "$@58", "function_body",
  "vars", "vars2", "vars3", "vars5", "vars6", "command", "print_command",
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
     425,   426,   427,   428,   429,   430,   431
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   177,   178,   178,   180,   179,   179,   179,   182,   181,
     181,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     184,   185,   186,   187,   187,   187,   188,   188,   188,   190,
     191,   192,   193,   194,   189,   195,   196,   195,   197,   199,
     200,   201,   202,   198,   203,   204,   205,   198,   207,   206,
     206,   209,   208,   210,   211,   210,   213,   212,   212,   215,
     216,   214,   217,   218,   217,   220,   219,   219,   219,   219,
     221,   219,   223,   224,   225,   222,   227,   228,   229,   230,
     231,   226,   233,   234,   235,   236,   237,   232,   239,   240,
     241,   242,   243,   244,   238,   246,   245,   247,   248,   248,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   250,
     250,   251,   251,   251,   251,   251,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   254,
     254,   254,   254,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   256,   256,   256,   256,   256,   257,   256,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   259,   259,   261,   262,   263,   264,   265,   266,
     260,   267,   268,   268,   268,   269,   269,   271,   270,   272,
     272,   272,   272,   273,   273,   273,   273,   273,   273,   274,
     275,   275,   276,   278,   279,   277,   280,   280,   281,   282,
     282,   282,   282,   282,   284,   283,   285,   286,   286,   287,
     287,   288,   288,   289,   289,   290,   290,   291,   291,   292,
     292,   293,   294,   294,   295,   295,   296,   296,   298,   299,
     297,   300,   301,   301,   301,   302,   302,   302,   303,   303,
     303,   304,   304,   304,   305,   305,   305,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   308,   309,   310,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   312,   311,   313,   311,   314,   311,   315,   311,   316,
     316,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   319,
     320,   321,   322,   318,   323,   324,   324,   325,   326,   326,
     326,   326,   327,   328,   329,   330,   331,   331,   331,   332,
     332,   332,   332,   333,   333,   333,   333,   333,   333,   333,
     333,   334,   334,   335,   336,   337,   338,   338,   338,   338,
     338,   339,   340,   340,   340,   340,   341,   342,   343,   344,
     345,   346,   346,   348,   347,   350,   349,   351,   352,   353,
     353,   353,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354
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
       3,     3,     1,     3,     0,     0,     0,     0,     0,     0,
      17,     1,     1,     3,     5,     1,     3,     0,     2,     1,
       1,     1,     1,     2,     4,     2,     1,     1,     1,     5,
       6,     4,     5,     0,     0,     8,     1,     3,     8,     2,
       2,     2,     1,     1,     0,    10,     0,     1,     6,     1,
       7,     1,     6,     1,     6,     4,     1,     5,     1,     0,
       1,     4,     0,     1,     4,     1,     4,     1,     0,     0,
      13,     3,     1,     3,     5,     1,     3,     5,     1,     3,
       5,     1,     3,     5,     1,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     3,     3,     3,     2,     4,     4,     4,     2,
       3,     3,     3,     3,     4,     3,     3,     4,     7,     6,
       5,     0,     8,     0,     8,     0,     8,     0,     8,     3,
       3,     1,     2,     2,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     0,     0,     9,     1,     1,     1,     2,     1,     1,
       1,     1,     2,     2,     1,     2,     1,     2,     3,     2,
       3,     4,     4,     4,     2,     3,     2,     3,     4,     6,
       5,     1,     2,     3,     1,     1,     4,     4,     4,     4,
       3,     3,     3,     3,     2,     1,     1,     4,     4,     2,
       1,     1,     1,     0,     5,     0,     6,     8,     8,     1,
       1,     1,     2,     4,     2,     4,     3,     2,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     2,     4,     3,     2,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     7,     3,     0,     6,    65,     5,    65,
     408,   407,   435,   411,   432,   405,   403,   401,   399,   397,
     391,   395,   437,   436,   417,   415,   416,   414,   413,   412,
     433,   434,   409,   410,     0,     8,   109,   111,   116,   136,
     149,    12,     0,     0,   153,     0,   348,   351,   354,   356,
       0,     0,     0,     0,     0,   444,   445,   446,     0,   448,
     451,     0,     0,     0,   454,     0,   456,     0,     0,     0,
       0,     0,     0,     0,     0,   471,     0,     0,   474,    88,
       0,    95,   475,     0,     0,     0,     0,     0,   485,   358,
     360,     0,   486,     0,     0,     0,     0,     0,     0,     0,
     449,   450,   292,     0,     0,   490,     0,   499,   500,   501,
       0,     0,     0,     0,   508,     0,     0,     0,   512,   513,
     514,   515,   516,   517,   518,   519,     0,     0,     0,     0,
     526,     0,     0,     0,   530,   531,   532,   533,   534,   535,
     536,   537,     9,    13,    14,    16,    15,    11,    26,    27,
      28,     0,    67,     0,    68,     0,    69,    70,    17,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   232,
       0,   249,   256,   257,   258,   251,   252,   250,   272,   273,
       0,   317,   318,   319,   320,   321,   322,   323,   438,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   491,   492,     0,    18,    19,    10,     0,
       0,     0,     0,     0,     0,     0,   153,   127,   146,   168,
     125,   144,   166,     0,     0,     0,     0,   227,   132,     0,
       0,     0,     0,     0,   112,   155,     0,   154,   406,   404,
     402,   400,   398,     0,     0,     0,   392,   393,   394,     0,
       0,     0,   122,   163,     0,   425,   431,   423,   429,   424,
     430,   422,   428,     0,     0,   419,   421,   427,   418,   420,
     426,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,   396,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,   253,   350,     0,   349,
     353,   352,   355,   357,   365,     0,     0,   369,     0,     0,
       0,     0,     0,     0,     0,     0,   447,     0,    65,   452,
     453,   455,     0,   457,   269,   270,   459,     0,     0,     0,
     464,     0,   466,     0,     0,     0,    65,   472,   271,     0,
      65,   255,    65,     0,     0,     0,     0,   484,   359,   361,
       0,     0,     0,     0,     0,     0,     0,   489,   293,     0,
       0,     0,     0,   502,     0,   504,     0,     0,   507,   509,
     510,   511,   520,     0,   522,     0,     0,   525,   527,   528,
     529,   439,     0,    66,    77,     0,    71,    20,     0,     0,
     128,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   145,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     115,     0,     0,     0,     0,     0,     0,   135,   148,   152,
     170,   178,   233,    99,    97,   221,   188,   200,   187,   199,
     186,   198,   185,   197,   183,   195,   207,   184,   196,   229,
     228,   220,   218,   219,   217,   216,   215,   222,   223,   179,
     181,     0,   362,     0,   363,     0,   370,   371,   372,   373,
       0,   375,   376,     0,     0,     0,     0,   390,   389,     0,
       0,   458,    24,    25,   460,     0,     0,   465,   467,     0,
       0,     0,   473,    89,    96,     0,   480,   481,   482,   483,
     364,     0,     0,     0,     0,     0,     0,     0,     0,   302,
       0,     0,   234,   311,     0,     0,     0,     0,   506,     0,
       0,   524,   440,    72,    65,    83,   180,   113,   182,   114,
     224,   129,   194,   124,   193,   123,   121,   192,   120,   191,
     119,   189,   117,   190,   118,   231,   134,   230,   133,   214,
     176,   212,   174,   213,   175,   211,   173,   210,   172,   209,
     171,   225,   130,   226,   131,     0,     0,     0,   206,   143,
     205,   142,   141,   204,   140,   203,   139,   201,   137,   202,
     138,   208,   150,   165,   164,   162,   161,   160,   158,   159,
     156,   157,   493,   254,   366,   374,   368,   367,   377,     0,
     314,     0,     0,     0,     0,    44,   462,   461,   463,   468,
       0,    29,     0,   477,   476,   478,   479,   263,     0,     0,
     261,   488,     0,   487,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   503,   505,   521,   523,    65,    65,
       0,    65,   177,   495,   276,     0,   380,     0,     0,     0,
       0,     0,    39,     0,   470,     0,     0,     0,     0,   259,
       0,     0,   262,     0,     0,     0,   303,     0,     0,     0,
     312,     0,     0,   441,    73,    78,     0,   276,   494,     0,
     379,   315,     0,     0,   381,   383,   385,   387,    48,    56,
     469,    30,    90,   266,   264,     0,   260,   306,     0,     0,
       0,     0,   308,     0,     0,     0,     0,     0,     0,     0,
      84,   496,   378,     0,     0,   276,   276,   276,   276,    40,
       0,    45,     0,    65,    65,     0,     0,     0,     0,     0,
     286,     0,     0,   277,   304,     0,     0,     0,   295,     0,
       0,   281,   313,   442,    74,    79,    65,   297,     0,     0,
     283,   316,   382,   384,   386,   388,     0,    53,    50,    49,
       0,    62,    58,    57,    31,     0,   267,   265,   268,   288,
       0,     0,   279,   307,     0,   274,     0,   309,   235,     0,
       0,   497,     0,    65,    65,    65,     0,     0,   498,     0,
      51,     0,    41,    59,     0,    46,     0,    91,     0,   298,
       0,     0,   276,     0,     0,     0,     0,     0,   443,    75,
      80,    85,     0,     0,     0,    54,    42,     0,    63,     0,
      32,    65,     0,     0,     0,   285,   275,     0,   236,   310,
     294,     0,     0,    65,   296,     0,    65,    65,     0,    60,
      65,    47,    35,     0,   289,     8,   299,     0,     0,   247,
       0,    81,    86,     0,    52,    55,    43,    65,    64,    36,
      33,    92,     0,   287,   290,     0,   276,     0,   278,     0,
     237,   241,   242,   245,     0,   282,     0,   284,    61,    65,
       0,    65,     0,   301,   300,   289,     0,   238,   247,   248,
      65,     0,    38,    34,    93,     0,   280,   243,     0,     0,
     246,    87,    37,     0,   291,   239,     0,    94,   276,   244,
     240
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,   291,     7,   142,   143,   144,   145,
     146,   147,   148,   716,   783,   856,   902,   940,   920,   939,
     953,   149,   748,   817,   876,   898,   713,   821,   879,   779,
     780,   818,   874,   852,   897,   781,   782,   822,   877,   917,
     855,   900,   150,   151,   406,   403,   699,   768,   844,   152,
     153,   584,   769,   845,   892,   154,   155,   701,   806,   893,
     936,   156,   360,   672,   784,   881,   941,   963,   157,   362,
     158,   292,   159,   160,   161,   162,   163,   164,   165,   166,
     702,   167,   168,   169,   690,   864,   909,   947,   958,   968,
     930,   931,   932,   933,   934,   170,   171,   172,   173,   174,
     175,   718,   786,   754,   176,   177,   178,   862,   738,   792,
     831,   800,   809,   793,   832,   923,   924,   379,   801,   810,
     179,   883,   926,   906,   571,   686,   764,   575,   662,   180,
     181,   182,   183,   184,   185,   775,   776,   777,   778,   186,
     187,   188,   582,   698,   767,   843,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   704,   214,   737,   215,   334,   216,   217
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -680
static const yytype_int16 yypact[] =
{
    -680,   936,  -680,  -680,  -680,  -122,    30,  1108,  -680,  1108,
     610,   610,   533,   774,    56,  1386,  1386,  1386,  1386,  1386,
    1382,   756,  -680,  -680,   899,   899,   899,   899,  1475,  1475,
    -680,  -680,  -680,  -680,   594,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  1386,   142,  1450,    48,    47,   103,   594,   594,
    1386,   111,    65,    60,    63,  -680,  -680,  -680,   106,  -680,
     136,   162,   142,   148,  -680,   168,  -680,   320,   204,   211,
     200,   -46,   202,   -21,   259,   268,   272,   256,  -680,  -680,
     286,  -680,  -680,   265,   258,   269,   277,   280,  -680,   594,
     594,   292,  -680,   332,   340,   271,   273,   357,   359,   347,
    -680,  -680,   295,   407,   404,  -680,   410,  -680,  -680,  -680,
     -31,   -30,   406,   411,  -680,   412,   413,   414,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,   -26,   -25,   428,   434,
    -680,   435,   436,   439,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,   440,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,   351,  -680,   350,  -680,   376,  -680,  -680,  -680,   443,
    -680,    11,  1630,   666,   464,  1610,  -680,  -680,  -680,  -680,
     445,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
     446,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,   444,  -680,  -680,   440,   610,
     610,  1386,    56,    56,   756,   610,  -680,  1558,  1437,   254,
    1558,  1437,   254,  1386,  1386,  1386,  1386,  -680,  1558,    56,
      56,   774,    56,   774,   116,   254,    56,   254,  1653,  1653,
    1653,  1653,  1653,   899,   899,  1382,  1653,   720,   473,   756,
     756,   756,  1558,   254,   899,  1653,   720,  1653,   720,  1653,
     720,  1653,   720,    59,  1475,   116,  1653,   720,   116,  1653,
     720,   533,  1671,   470,     9,  1504,  1575,    14,  1550,   471,
     472,    84,   476,  1653,   142,   473,  1386,   899,   899,   899,
     899,  1382,   899,  1386,  1386,  1386,  1386,  1386,  1386,  1386,
    1386,  1386,  1386,    59,    59,  -680,   475,  -680,   468,  -680,
    -680,  -680,  -680,  -680,  1653,   474,   465,   659,   455,  1386,
     483,   408,   484,   495,   478,   629,  -680,   594,  1108,   473,
    -680,  -680,   487,  1653,   485,   486,  -680,   491,   463,   496,
    -680,   489,  -680,   509,   430,   512,  1108,  -680,  -680,   507,
    1108,  -680,  1108,   526,   142,   477,   142,  -680,  -680,  -680,
     510,   528,   521,   522,   523,    69,   529,  -680,  -680,   534,
      23,   530,    34,  -680,   535,  -680,   536,   537,  -680,  -680,
    -680,  -680,  -680,   539,  -680,   542,   543,  -680,  -680,  -680,
    -680,  -680,   538,  -680,  -680,   541,  -680,  -680,    97,   144,
    -680,  -680,   780,   784,   823,  1386,   841,   845,   889,   894,
    1279,  1283,  1287,  1300,  1322,  1330,  1335,  1343,  1365,  1378,
    -680,  -680,    83,   192,   126,   242,   316,   402,   438,   123,
    -680,  -680,    56,    56,    56,    56,    56,    56,    56,    56,
      56,  -680,  -680,   519,  1527,  1588,  1386,  1386,  1386,  1386,
    1386,  1386,  1386,  1386,  1386,  1386,  1386,   126,   126,   126,
     126,   126,   126,   403,    59,    59,    19,   142,    59,  -680,
    -680,   540,   550,   551,   552,   560,   561,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  1653,  1653,   720,  1653,   720,
    1653,   720,  1653,   720,  1653,   720,   473,  1653,   720,  1653,
    1653,  1653,  1653,  1653,  1653,  1653,  1653,  1653,  1653,   116,
     116,   594,  -680,   142,  -680,   659,   116,  1653,   720,   473,
     335,  1653,  -680,   544,   488,    80,  1386,  -680,  1653,   553,
     230,  -680,  -680,  -680,  -680,  1386,   562,  1386,  -680,   570,
     490,   244,  -680,   440,   440,   659,  1653,   473,  -680,   473,
    -680,   580,   584,   591,   583,   497,  1386,   587,    88,  -680,
     585,   133,  -680,  -680,   593,   253,   460,   466,  -680,   467,
     479,  -680,  -680,  -680,  1108,  -680,  -680,   613,  -680,  -680,
    -680,  1690,  -680,  1690,  -680,  1690,   383,  -680,   383,  -680,
     383,  -680,   356,  -680,   356,  -680,   266,  -680,   266,  -680,
    1653,  -680,  1653,  -680,  1653,  -680,  1653,  -680,  1653,  -680,
    1653,  -680,  -680,  -680,  -680,   126,   126,   126,  -680,  1437,
    -680,  1437,   300,  -680,   300,  -680,   300,  -680,  -680,  -680,
    -680,  -680,  -680,   254,   254,    16,    16,    16,   348,   348,
     614,  -680,   569,  -680,   473,  -680,  -680,  1653,   547,    99,
    -680,   615,   283,  1420,   628,  -680,  1653,  -680,  1653,  -680,
     155,  -680,   572,   116,  1653,   720,   473,  -680,   623,   624,
     644,  -680,   190,  -680,  -680,   650,   301,   645,   654,   655,
     670,   649,   660,   662,  -680,  -680,  -680,  -680,  1108,  1108,
     -19,  1108,  -680,  -680,  -680,  1386,  -680,   482,   656,   676,
     677,   659,  -680,   690,  -680,   702,   598,   710,   714,  -680,
     634,   716,  -680,   704,   717,   709,  -680,   736,   725,   141,
    -680,   738,   727,   440,   440,  -680,   170,  -680,  -680,   733,
    -680,  -680,   740,   732,   116,  1653,   720,   473,  -680,  -680,
    -680,  -680,  -680,  -680,   741,   661,  -680,  -680,   763,   752,
     164,   742,  -680,   755,   304,   179,   746,   760,   772,   775,
    -680,  -680,  -680,   205,   753,  -680,  -680,  -680,  -680,   719,
     719,   722,   722,  1108,  1108,   770,   779,   777,   228,   764,
    -680,   768,   307,  -680,  -680,   765,   776,   785,  -680,   778,
     339,  -680,  -680,  -680,  -680,  -680,  1108,  -680,   781,   362,
    -680,  -680,  -680,  -680,  -680,  -680,   594,   743,  -680,  -680,
     594,   731,  -680,  -680,   440,   173,  -680,  -680,  -680,  -680,
     787,   398,  -680,  -680,   792,  -680,   794,  -680,  -680,   796,
     802,  -680,   801,  1108,  1108,  1108,   189,   809,  -680,   808,
    -680,   814,  -680,  -680,   816,  -680,   734,  -680,   818,  -680,
     819,   811,  -680,   817,   836,   821,   825,   822,   440,   440,
     440,  -680,   827,   824,   828,  -680,  -680,   830,  -680,   843,
    -680,  1108,   829,   851,   839,  -680,  -680,   853,  -680,  -680,
    -680,   855,   856,  1108,  -680,   858,  1108,  1108,   869,  -680,
    1108,  -680,   820,   216,   879,  -680,  -680,   870,   860,   782,
     861,  -680,   440,   863,   440,   440,  -680,  1108,   440,  -680,
    -680,  -680,   594,  -680,  -680,   878,  -680,   864,  -680,   876,
    -680,  -680,   880,  -680,   594,  -680,   891,  -680,   440,  1108,
     793,  1108,   884,  -680,  -680,   879,   875,  -680,   826,  -680,
    1108,   -20,  -680,  -680,   440,   896,  -680,  -680,   938,   925,
    -680,   440,  -680,   945,  -680,  -680,   924,  -680,  -680,  -680,
    -680
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -680,  -680,  -680,  -680,   976,  -680,    -9,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,   208,  -680,  -680,  -680,  -680,  -680,   209,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -290,   -44,   959,    44,    -2,   215,    27,   143,  -680,
    -680,   964,   970,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,    64,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -679,  -680,
    -680,  -680,  -680,  -680,  -680,    66,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680,
    -680,  -680,  -680,  -680,  -680,  -680,  -680,  -680
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -99
static const yytype_int16 yytable[] =
{
     218,   493,   319,   321,   322,   323,   383,   385,   227,   230,
     238,   392,   394,   248,   249,   250,   251,   252,   256,   262,
     401,   401,   265,   267,   269,   271,   276,   279,   439,   347,
     447,   448,   285,   477,   350,   408,   409,   408,   409,   480,
     293,   351,   449,   450,   489,   368,   369,   258,   324,   489,
     219,   220,     8,   281,   241,   223,   569,   244,   771,   239,
     240,   287,   224,   222,   223,   343,   273,   573,   570,     9,
     295,   242,   275,   278,   735,   352,    34,   348,   284,   574,
      36,    37,    38,    39,    40,   246,   625,   626,   478,   339,
      43,   282,   316,    37,   353,   354,   812,   813,   814,   815,
     226,   355,   233,   234,   273,   221,   219,   220,   962,   281,
     241,   223,   627,   660,   235,   327,   -98,   326,   224,    39,
     335,   684,   328,     9,   317,   661,   478,   628,   236,   625,
     626,    37,    34,   685,    38,   329,    36,    37,    38,    39,
      40,   586,   474,   475,   384,   386,    43,   282,   325,   393,
     395,   273,   294,   229,   232,   627,   245,   247,   233,   234,
      40,   221,    39,   688,   263,   337,    43,   641,   336,   318,
     235,   294,   689,   478,   762,   330,   331,   288,    37,    40,
     320,   104,   332,   886,   236,    43,   763,   565,   588,   566,
      38,   338,   333,   410,   411,   625,   626,   790,   456,   457,
     458,   415,   459,   460,   461,   462,   463,   464,   770,   791,
     401,   857,   798,   401,   465,   466,   340,   227,   230,   238,
     706,   627,   262,   454,   799,   228,   231,   871,    39,   401,
     341,   227,   230,   262,   454,   257,   630,   104,   807,   266,
     268,   270,   272,   277,   280,   625,   626,   944,   344,   286,
     808,   227,   230,   454,   921,   345,   401,   227,   230,   454,
     665,   829,   454,   442,   443,   444,   445,   446,   447,   448,
     401,   627,   454,   830,   671,   346,   714,   349,    39,   238,
     449,   450,   476,   692,   401,   244,   633,   473,   356,   970,
     465,   466,   693,   539,   495,   496,   498,   500,   502,   504,
     507,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   722,   357,   709,   471,   472,   358,   244,   473,   625,
     626,   476,   710,   233,   234,   527,   221,   531,   506,   540,
     361,   724,   359,   538,   796,   235,   364,   835,   233,   234,
     725,   221,   363,   797,   370,   627,   836,   551,   365,   236,
     235,   553,    39,   554,   529,    38,   366,   519,   520,   367,
     635,   556,   229,   232,   236,   245,   247,   263,   288,   841,
      38,   526,   463,   464,   449,   450,   371,   372,   842,   655,
     465,   466,   229,   232,   245,   263,   288,   656,   373,   288,
     374,   557,   848,   559,   375,   342,   376,   461,   462,   463,
     464,   849,   229,   232,   288,   625,   626,   465,   466,   377,
     591,   593,   595,   596,   598,   600,   602,   604,   606,   608,
     610,   612,   614,   616,   618,   620,   622,   624,   859,   474,
     475,   627,   378,   480,   228,   231,   380,   860,    39,   382,
     455,   625,   626,   387,   402,   381,   637,   404,   388,   389,
     390,   391,   587,   589,   591,   593,   595,   598,   600,   602,
     604,   606,   608,   622,   624,   396,   642,   627,   228,   231,
     455,   397,   398,   399,    39,   405,   400,   653,   439,   455,
     401,   407,   639,   451,   452,   410,   411,   477,   453,   455,
     456,   457,   458,   415,   459,   460,   461,   462,   463,   464,
     479,   491,   492,   521,   642,   522,   465,   466,   494,   524,
     530,   523,   497,   499,   501,   503,   505,   508,   587,   589,
     532,   534,   473,   454,   535,   533,   542,   543,   657,   233,
     234,   541,   221,   536,   663,   544,   233,   234,   545,   221,
     546,   235,   528,   666,   547,   668,   548,   549,   235,   550,
     654,   552,   476,   674,   560,   236,   561,   558,   562,   563,
     564,    38,   236,   568,   682,   572,   567,   583,    38,   473,
     585,   652,   576,   577,   578,   700,   579,   237,   555,   580,
     581,   658,   676,   664,   609,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   611,   613,   615,   219,   220,   673,
     281,   241,   223,   740,   617,   619,   667,   669,   659,   224,
     670,   677,   678,   219,   220,   925,   221,   222,   223,   679,
     680,   703,   681,    34,   683,   224,   687,    36,    37,    38,
      39,    40,   233,   234,   691,   221,   694,    43,   282,   225,
     475,   450,   695,   696,   235,    38,    39,   629,   631,   632,
     634,   636,   638,   640,   226,   697,   708,   707,   236,   712,
     719,   720,   253,   254,    38,   221,   273,   705,   715,   430,
     431,   717,   721,   537,   235,   432,   433,   434,   435,   436,
     437,   438,   629,   631,   634,   636,   638,   640,   525,   733,
     734,   723,   736,    37,    38,    39,    40,   726,   727,   729,
     728,   730,    43,   739,   731,   410,   411,   732,   741,   745,
     456,   457,   458,   415,   459,   460,   461,   462,   463,   464,
     742,   749,   743,   430,   431,   751,   465,   466,   104,   467,
     468,   434,   469,   470,   471,   472,   410,   411,   747,   752,
     455,   456,   457,   458,   415,   459,   460,   461,   462,   463,
     464,   753,   755,   756,   759,   744,   757,   465,   466,   259,
     260,   758,   221,   222,   223,   760,   761,   765,   766,   773,
     675,   224,   850,   774,   824,   825,   853,   239,   240,   787,
     785,   241,   223,   233,   234,   261,   221,   233,   234,   242,
     221,    38,   788,   789,   794,   235,   795,   846,   802,   235,
     226,   803,   804,   243,   805,   811,   816,   826,    37,   236,
     820,   827,   834,   236,   828,    38,   833,   837,   226,    38,
     838,   854,   840,   750,   590,   847,   233,   234,   592,   221,
     839,   858,   851,   861,   868,   869,   870,   865,   235,   863,
     228,   231,   455,   866,   233,   234,   867,   221,   233,   234,
     872,   221,   236,   873,   772,   875,   235,   878,    38,   882,
     235,   887,   880,   885,   884,   888,   891,   594,   895,   896,
     236,   899,   903,   889,   236,   901,    38,   890,   942,   894,
      38,   904,   905,   907,   912,   597,   911,   914,   915,   599,
     949,   918,   233,   234,   908,   221,   910,   233,   234,   913,
     221,   916,   253,   254,   235,   221,   919,   922,   938,   235,
     943,   927,   928,   935,   235,   937,   945,   946,   236,   948,
     929,   950,   952,   236,    38,   955,   746,   957,   264,    38,
     951,   964,   954,   601,    38,    39,     2,     3,   603,    -8,
      -8,   961,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,   959,    -8,   966,    -8,   965,    -8,
      -8,    -8,    -8,    -8,    -8,   967,   969,     6,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,   819,    -8,
      -8,   823,    -8,   283,    -8,    -8,    -8,    -8,   289,    -8,
      -8,    -8,    -8,    -8,   290,    -8,    -8,    -8,    -8,    -8,
      -8,   956,   960,     0,     0,     0,     0,    -8,    -8,    -8,
      -8,    -8,     0,     0,     0,     0,     0,    -8,    -8,    -8,
      -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,     0,    -8,     0,     0,    -8,     0,     0,    -8,     0,
      -8,     0,    -8,     0,     0,     0,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,     0,     0,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -4,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    34,     0,    35,
       0,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
       0,    52,    53,     0,    54,     0,    55,    56,    57,    58,
       0,    59,    60,    61,    62,    63,     0,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,     0,     0,     0,     0,     0,    75,
      76,     0,    77,    78,     0,   -76,    79,   -82,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,     0,     0,    96,     0,     0,
      97,     0,    98,     0,    99,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   233,   234,     0,   221,   233,   234,     0,   221,
     233,   234,     0,   221,   235,     0,     0,     0,   235,     0,
       0,     0,   235,   233,   234,     0,   221,     0,   236,     0,
       0,     0,   236,     0,    38,   235,   236,     0,    38,     0,
       0,     0,    38,   605,     0,   233,   234,   607,   221,   236,
       0,   609,     0,   233,   234,    38,   221,   235,   233,   234,
       0,   221,     0,     0,   611,   235,   233,   234,     0,   221,
     235,   236,     0,     0,     0,     0,     0,    38,   235,   236,
       0,     0,     0,     0,   236,    38,   613,     0,   233,   234,
      38,   221,   236,     0,   615,     0,     0,     0,    38,   617,
     235,   233,   234,     0,   221,   253,   254,   619,   221,   233,
     234,     0,   221,   235,   236,     0,     0,   235,     0,     0,
      38,   235,     0,     0,     0,     0,     0,   236,     0,   621,
       0,   255,     0,    38,     0,   236,     0,    38,    39,    40,
       0,    38,   623,   410,   411,    43,     0,     0,   456,   457,
     458,   415,   459,   460,   461,   462,   463,   464,     0,     0,
       0,     0,     0,     0,   465,   466,   467,   468,   434,   469,
     470,   471,   472,     0,     0,     0,     0,     0,   296,   297,
     298,   711,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   253,   254,
       0,   221,   273,     0,     0,     0,     0,     0,     0,     0,
     235,   315,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,     0,     0,   410,   411,    37,
      38,    39,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   481,   482,   483,   484,   485,   486,   428,   429,
     410,   411,     0,     0,   487,   456,   457,   458,   415,   459,
     460,   461,   462,   463,   464,     0,     0,     0,     0,     0,
       0,   465,   466,   440,   441,     0,     0,   487,     0,   442,
     443,   444,   445,   446,   447,   448,   456,   457,   458,   415,
     459,   460,   461,   462,   463,   464,   449,   450,   430,   431,
     490,     0,   465,   466,   432,   433,   434,   435,   436,   437,
     438,   430,   431,     0,     0,     0,     0,   467,   468,   434,
     469,   470,   471,   472,     0,   488,     0,     0,     0,     0,
       0,     0,     0,   440,   441,     0,     0,     0,   488,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
       0,     0,     0,   410,   411,     0,   449,   450,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   410,   411,     0,     0,
       0,   456,   457,   458,   415,   459,   460,   461,   462,   463,
     464,     0,     0,     0,     0,     0,     0,   465,   466,   296,
     297,   298,     0,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   457,
     458,   415,   459,   460,   461,   462,   463,   464,     0,     0,
       0,     0,     0,     0,   465,   466
};

static const yytype_int16 yycheck[] =
{
       9,   291,    46,    47,    48,    49,    37,    37,    10,    11,
      12,    37,    37,    15,    16,    17,    18,    19,    20,    21,
      40,    40,    24,    25,    26,    27,    28,    29,    14,    75,
      14,    15,    34,    14,    55,    26,    27,    26,    27,    30,
      42,    62,    26,    27,    30,    89,    90,    20,    50,    30,
       3,     4,   174,     6,     7,     8,    33,    13,   737,     3,
       4,    34,    15,     7,     8,    67,     7,    33,    45,    39,
      43,    15,    28,    29,    93,    96,    29,   123,    34,    45,
      33,    34,    35,    36,    37,    29,     3,     4,    29,    62,
      43,    44,    44,    34,   115,   116,   775,   776,   777,   778,
      44,   122,     3,     4,     7,     6,     3,     4,   128,     6,
       7,     8,    29,    33,    15,    55,    32,    52,    15,    36,
      57,    33,    62,    39,    77,    45,    29,    44,    29,     3,
       4,    34,    29,    45,    35,    75,    33,    34,    35,    36,
      37,    44,    26,    27,   175,   175,    43,    44,    37,   175,
     175,     7,    29,    10,    11,    29,    13,    14,     3,     4,
      37,     6,    36,    30,    21,    29,    43,    44,    62,   122,
      15,    29,    39,    29,    33,   115,   116,    34,    34,    37,
      77,   134,   122,   862,    29,    43,    45,   118,    44,   120,
      35,    29,   132,     3,     4,     3,     4,    33,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    38,    45,
      40,    38,    33,    40,    24,    25,    68,   219,   220,   221,
     121,    29,   224,   225,    45,    10,    11,    38,    36,    40,
      62,   233,   234,   235,   236,    20,    44,   134,    33,    24,
      25,    26,    27,    28,    29,     3,     4,   926,    44,    34,
      45,   253,   254,   255,    38,    44,    40,   259,   260,   261,
      30,    33,   264,     9,    10,    11,    12,    13,    14,    15,
      40,    29,   274,    45,    30,    75,   121,    75,    36,   281,
      26,    27,   255,    30,    40,   241,    44,   243,    29,   968,
      24,    25,    39,   337,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   121,    44,    30,    14,    15,    44,   273,   274,     3,
       4,   294,    39,     3,     4,   327,     6,   329,   301,   338,
      44,    30,    76,   335,    30,    15,    78,    30,     3,     4,
      39,     6,    77,    39,    52,    29,    39,   356,    79,    29,
      15,   360,    36,   362,   327,    35,    79,   313,   314,    79,
      44,   363,   219,   220,    29,   222,   223,   224,   225,    30,
      35,   327,    16,    17,    26,    27,    44,    37,    39,    44,
      24,    25,   239,   240,   241,   242,   243,    52,   117,   246,
     117,   364,    30,   366,    37,    75,    37,    14,    15,    16,
      17,    39,   259,   260,   261,     3,     4,    24,    25,    62,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,    30,    26,
      27,    29,   137,    30,   219,   220,    29,    39,    36,    29,
     225,     3,     4,    37,    93,    41,    44,    97,    37,    37,
      37,    37,   408,   409,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,    37,   439,    29,   253,   254,
     255,    37,    37,    37,    36,    99,    37,   521,    14,   264,
      40,    38,    44,    38,    38,     3,     4,    14,    44,   274,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      30,    30,    30,    28,   477,    37,    24,    25,    32,    44,
      55,    37,   297,   298,   299,   300,   301,   302,   474,   475,
      37,    37,   478,   525,    29,   117,    41,    41,   530,     3,
       4,    44,     6,    55,   536,    44,     3,     4,    75,     6,
      44,    15,   327,   545,    55,   547,    37,   117,    15,    37,
     523,    44,   525,   555,    44,    29,    28,    80,    37,    37,
      37,    35,    29,    29,   566,    35,    37,    29,    35,   525,
      29,    52,    37,    37,    37,   584,    37,    44,    52,    37,
      37,    37,   555,    30,    44,   442,   443,   444,   445,   446,
     447,   448,   449,   450,    44,    44,    44,     3,     4,   555,
       6,     7,     8,   121,    44,    44,    44,    37,   120,    15,
     120,    31,    28,     3,     4,   905,     6,     7,     8,    28,
      37,    52,   125,    29,    37,    15,    41,    33,    34,    35,
      36,    37,     3,     4,    41,     6,   176,    43,    44,    29,
      27,    27,   176,   176,    15,    35,    36,   432,   433,   434,
     435,   436,   437,   438,    44,   176,    41,   659,    29,    31,
      37,    37,     3,     4,    35,     6,     7,   120,   670,     3,
       4,    99,    28,    44,    15,     9,    10,    11,    12,    13,
      14,    15,   467,   468,   469,   470,   471,   472,    29,   698,
     699,    41,   701,    34,    35,    36,    37,    52,    44,    29,
      45,    52,    43,   705,    44,     3,     4,    45,    52,   711,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      44,    31,    45,     3,     4,   127,    24,    25,   134,     9,
      10,    11,    12,    13,    14,    15,     3,     4,   711,    29,
     525,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    37,   118,    37,    45,   711,    52,    24,    25,     3,
       4,    44,     6,     7,     8,    29,    41,    29,    41,    29,
     555,    15,   816,    41,   783,   784,   820,     3,     4,   118,
      39,     7,     8,     3,     4,    29,     6,     3,     4,    15,
       6,    35,    29,    41,    52,    15,    41,   806,    52,    15,
      44,    41,    30,    29,    29,    52,    87,    37,    34,    29,
      88,    32,    44,    29,    37,    35,    52,    52,    44,    35,
      44,    90,    44,   121,    44,    44,     3,     4,    44,     6,
      45,    44,    89,    41,   843,   844,   845,    41,    15,    45,
     625,   626,   627,    41,     3,     4,    45,     6,     3,     4,
      41,     6,    29,    45,   121,    41,    15,    41,    35,    41,
      15,    44,   128,    52,    45,    29,    44,    44,    44,    41,
      29,    41,   881,    52,    29,    32,    35,    52,   922,    52,
      35,    52,    31,    44,   893,    44,    30,   896,   897,    44,
     934,   900,     3,     4,    41,     6,    41,     3,     4,    41,
       6,    32,     3,     4,    15,     6,    86,    28,   917,    15,
      32,    41,    52,    52,    15,    52,    52,    41,    29,    39,
     138,    30,   129,    29,    35,    41,   711,    52,    29,    35,
     939,    35,   941,    44,    35,    36,     0,     1,    44,     3,
       4,   950,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   138,    29,    41,    31,    30,    33,
      34,    35,    36,    37,    38,    30,    52,     1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,   780,    53,
      54,   782,    56,    34,    58,    59,    60,    61,    34,    63,
      64,    65,    66,    67,    34,    69,    70,    71,    72,    73,
      74,   945,   948,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,    -1,    -1,   119,    -1,    -1,   122,    -1,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,    -1,    -1,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    31,
      -1,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    54,    -1,    56,    -1,    58,    59,    60,    61,
      -1,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    91,
      92,    -1,    94,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,
     122,    -1,   124,    -1,   126,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,    -1,    -1,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     3,     4,    -1,     6,     3,     4,    -1,     6,
       3,     4,    -1,     6,    15,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    15,     3,     4,    -1,     6,    -1,    29,    -1,
      -1,    -1,    29,    -1,    35,    15,    29,    -1,    35,    -1,
      -1,    -1,    35,    44,    -1,     3,     4,    44,     6,    29,
      -1,    44,    -1,     3,     4,    35,     6,    15,     3,     4,
      -1,     6,    -1,    -1,    44,    15,     3,     4,    -1,     6,
      15,    29,    -1,    -1,    -1,    -1,    -1,    35,    15,    29,
      -1,    -1,    -1,    -1,    29,    35,    44,    -1,     3,     4,
      35,     6,    29,    -1,    44,    -1,    -1,    -1,    35,    44,
      15,     3,     4,    -1,     6,     3,     4,    44,     6,     3,
       4,    -1,     6,    15,    29,    -1,    -1,    15,    -1,    -1,
      35,    15,    -1,    -1,    -1,    -1,    -1,    29,    -1,    44,
      -1,    29,    -1,    35,    -1,    29,    -1,    35,    36,    37,
      -1,    35,    44,     3,     4,    43,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,     8,     9,
      10,    41,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     3,     4,
      -1,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,     3,     4,    34,
      35,    36,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       3,     4,    -1,    -1,    30,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,     3,     4,    -1,    -1,    30,    -1,     9,
      10,    11,    12,    13,    14,    15,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    26,    27,     3,     4,
      30,    -1,    24,    25,     9,    10,    11,    12,    13,    14,
      15,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    30,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    26,    27,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     3,     4,    -1,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   178,     0,     1,   179,   180,   181,   182,   174,    39,
       3,     4,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    29,    31,    33,    34,    35,    36,
      37,    38,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    53,    54,    56,    58,    59,    60,    61,    63,
      64,    65,    66,    67,    69,    70,    71,    72,    73,    74,
      81,    82,    83,    84,    85,    91,    92,    94,    95,    98,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   119,   122,   124,   126,
     130,   131,   132,   133,   134,   135,   136,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   183,   184,   185,   186,   187,   188,   189,   198,
     219,   220,   226,   227,   232,   233,   238,   245,   247,   249,
     250,   251,   252,   253,   254,   255,   256,   258,   259,   260,
     272,   273,   274,   275,   276,   277,   281,   282,   283,   297,
     306,   307,   308,   309,   310,   311,   316,   317,   318,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   349,   351,   353,   354,   183,     3,
       4,     6,     7,     8,    15,    29,    44,   252,   253,   255,
     252,   253,   255,     3,     4,    15,    29,    44,   252,     3,
       4,     7,    15,    29,   251,   255,    29,   255,   252,   252,
     252,   252,   252,     3,     4,    29,   252,   253,   254,     3,
       4,    29,   252,   255,    29,   252,   253,   252,   253,   252,
     253,   252,   253,     7,    29,   251,   252,   253,   251,   252,
     253,     6,    44,   250,   251,   252,   253,   254,   255,   258,
     259,   181,   248,   252,    29,   254,     8,     9,    10,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    41,    44,    77,   122,   249,
      77,   249,   249,   249,   252,    37,    52,    55,    62,    75,
     115,   116,   122,   132,   352,    57,    62,    29,    29,   254,
      68,    62,    75,   252,    44,    44,    75,    75,   123,    75,
      55,    62,    96,   115,   116,   122,    29,    44,    44,    76,
     239,    44,   246,    77,    78,    79,    79,    79,   249,   249,
      52,    44,    37,   117,   117,    37,    37,    62,   137,   294,
      29,    41,    29,    37,   175,    37,   175,    37,    37,    37,
      37,    37,    37,   175,    37,   175,    37,    37,    37,    37,
      37,    40,    93,   222,    97,    99,   221,    38,    26,    27,
       3,     4,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       3,     4,     9,    10,    11,    12,    13,    14,    15,    14,
       3,     4,     9,    10,    11,    12,    13,    14,    15,    26,
      27,    38,    38,    44,   252,   253,     8,     9,    10,    12,
      13,    14,    15,    16,    17,    24,    25,     9,    10,    12,
      13,    14,    15,   251,    26,    27,   254,    14,    29,    30,
      30,    18,    19,    20,    21,    22,    23,    30,    30,    30,
      30,    30,    30,   248,    32,   252,   252,   253,   252,   253,
     252,   253,   252,   253,   252,   253,   254,   252,   253,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   251,
     251,    28,    37,    37,    44,    29,   251,   252,   253,   254,
      55,   252,    37,   117,    37,    29,    55,    44,   252,   249,
     183,    44,    41,    41,    44,    75,    44,    55,    37,   117,
      37,   183,    44,   183,   183,    52,   252,   254,    80,   254,
      44,    28,    37,    37,    37,   118,   120,    37,    29,    33,
      45,   301,    35,    33,    45,   304,    37,    37,    37,    37,
      37,    37,   319,    29,   228,    29,    44,   251,    44,   251,
      44,   252,    44,   252,    44,   252,   252,    44,   252,    44,
     252,    44,   252,    44,   252,    44,   252,    44,   252,    44,
     252,    44,   252,    44,   252,    44,   252,    44,   252,    44,
     252,    44,   252,    44,   252,     3,     4,    29,    44,   253,
      44,   253,   253,    44,   253,    44,   253,    44,   253,    44,
     253,    44,   254,   255,   255,   255,   255,   255,   255,   255,
     255,   255,    52,   249,   254,    44,    52,   252,    37,   120,
      33,    45,   305,   252,    30,    30,   252,    44,   252,    37,
     120,    30,   240,   251,   252,   253,   254,    31,    28,    28,
      37,   125,   252,    37,    33,    45,   302,    41,    30,    39,
     261,    41,    30,    39,   176,   176,   176,   176,   320,   223,
     183,   234,   257,    52,   348,   120,   121,   252,    41,    30,
      39,    41,    31,   203,   121,   252,   190,    99,   278,    37,
      37,    28,   121,    41,    30,    39,    52,    44,    45,    29,
      52,    44,    45,   183,   183,    93,   183,   350,   285,   252,
     121,    52,    44,    45,   251,   252,   253,   254,   199,    31,
     121,   127,    29,    37,   280,   118,    37,    52,    44,    45,
      29,    41,    33,    45,   303,    29,    41,   321,   224,   229,
      38,   285,   121,    29,    41,   312,   313,   314,   315,   206,
     207,   212,   213,   191,   241,    39,   279,   118,    29,    41,
      33,    45,   286,   290,    52,    41,    30,    39,    33,    45,
     288,   295,    52,    41,    30,    29,   235,    33,    45,   289,
     296,    52,   285,   285,   285,   285,    87,   200,   208,   208,
      88,   204,   214,   214,   183,   183,    37,    32,    37,    33,
      45,   287,   291,    52,    44,    30,    39,    52,    44,    45,
      44,    30,    39,   322,   225,   230,   183,    44,    30,    39,
     249,    89,   210,   249,    90,   217,   192,    38,    44,    30,
      39,    41,   284,    45,   262,    41,    41,    45,   183,   183,
     183,    38,    41,    45,   209,    41,   201,   215,    41,   205,
     128,   242,    41,   298,    45,    52,   285,    44,    29,    52,
      52,    44,   231,   236,    52,    44,    41,   211,   202,    41,
     218,    32,   193,   183,    52,    31,   300,    44,    41,   263,
      41,    30,   183,    41,   183,   183,    32,   216,   183,    86,
     195,    38,    28,   292,   293,   248,   299,    41,    52,   138,
     267,   268,   269,   270,   271,    52,   237,    52,   183,   196,
     194,   243,   249,    32,   285,    52,    41,   264,    39,   249,
      30,   183,   129,   197,   183,    41,   292,    52,   265,   138,
     270,   183,   128,   244,    35,    30,    41,    30,   266,    52,
     285
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
#line 975 "pnfha.ypp"
    { ASTNode start("START"); tree.add_node(start); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 978 "pnfha.ypp"
    {
	 ASTNode line("line");
         tree.add_node(line);
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 984 "pnfha.ypp"
    { yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 987 "pnfha.ypp"
    {
		 ASTNode statement("statement");
  		 tree.add_node(statement);
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 995 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1; 
		    	                    statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 997 "pnfha.ypp"
    { conprint("VOID TVOID 0V\n"); statementoutcount.insert(); 
                         statementoutcount[statementoutcount.length() - 1] = outcount - 1; statementlineno.insert(); statementlineno[statementlineno.length() - 1]                          = yylineno; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 999 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					  statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 1001 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					   statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 1003 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 1005 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				       statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 1007 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; inblock = true;
				   ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 1015 "pnfha.ypp"
    {
			 ASTNode expression_statement("expression_statement");
			 tree.add_node(expression_statement);
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 1022 "pnfha.ypp"
    {
			 ASTNode declaration_statement("declaration_statement");
			 tree.add_node(declaration_statement);
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 1029 "pnfha.ypp"
    {
			 ASTNode command_statement("command_statement");
			 tree.add_node(command_statement);
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 1036 "pnfha.ypp"
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
#line 1069 "pnfha.ypp"
    {
			 ASTNode label_statement("label_statement");

			 conprint("LBL TVOID 0V\n");

			 tree.add_node(label_statement);
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1077 "pnfha.ypp"
    {
			 ASTNode label_statement("label_statement");

			 conprint("ELBL TVOID 0V\n");

			 tree.add_node(label_statement);
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 1087 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 1093 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");
			 tree.add_node(control_statement);
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1098 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");

			 breakinforever = false;

			 tree.add_node(control_statement);
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1108 "pnfha.ypp"
    {
			 ASTNode if_statementp1("if_statementp1");

			 tree.add_node(if_statementp1);		
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1114 "pnfha.ypp"
    {			 
			 ASTNode if_statementp2("if_statementp2");
			
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1123 "pnfha.ypp"
    {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1130 "pnfha.ypp"
    {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1135 "pnfha.ypp"
    {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1141 "pnfha.ypp"
    {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1151 "pnfha.ypp"
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
#line 1162 "pnfha.ypp"
    {
			 ASTNode if_statementp7("if_statementp7");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");

			 tree.add_node(if_statementp7);
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1176 "pnfha.ypp"
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
#line 1215 "pnfha.ypp"
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
#line 1244 "pnfha.ypp"
    {
			 ASTNode switch_statementp3("switch_statementp3");

			 tree.add_node(switch_statementp3);
			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1249 "pnfha.ypp"
    {

			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1253 "pnfha.ypp"
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1261 "pnfha.ypp"
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
#line 1276 "pnfha.ypp"
    {
			 ASTNode switch_statementp2("switch_statementp2");
			 
			 tree.add_node(switch_statementp2);
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1282 "pnfha.ypp"
    {
			 ASTNode switch_statementp3("switch_statementp3");
			 tree.add_node(switch_statementp3);
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1287 "pnfha.ypp"
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1296 "pnfha.ypp"
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1305 "pnfha.ypp"
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
#line 1343 "pnfha.ypp"
    {
			 conprint("SWCEND TVOID 0V\n");
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1349 "pnfha.ypp"
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1354 "pnfha.ypp"
    {
			 conprint("SWCEND TVOID 0V\n");
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1359 "pnfha.ypp"
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1368 "pnfha.ypp"
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
#line 1399 "pnfha.ypp"
    {
			 ASTNode case_statementp2("case_statementp2");

			 tree.add_node(case_statementp2);
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1405 "pnfha.ypp"
    {
			 ASTNode case_statementp3("case_statementp3");

			 conprint("SWCEND TVOID 0V\n");

			 tree.add_node(case_statementp3);
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1415 "pnfha.ypp"
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1420 "pnfha.ypp"
    {
			 conprint("SWCEND TVOID 0V\n");
			;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1425 "pnfha.ypp"
    {
			 loopexpr = true;
			 inloop2 = true;
			;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1430 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1435 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1440 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1445 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1450 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 
			 loopexpr = false;
			 inloop = true;		 

			 tree.add_node(loop_statement);
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1458 "pnfha.ypp"
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
#line 1469 "pnfha.ypp"
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
#line 1479 "pnfha.ypp"
    {
			 ASTNode while_loopp2("while_loopp2");

			 tree.add_node(while_loopp2);
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1485 "pnfha.ypp"
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
#line 1496 "pnfha.ypp"
    {
			 ASTNode while_loopp4("while_loopp4");

			 conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 conprint("LBL TSTRING \"while_end_%u\"\n", whilecounter);

			 tree.add_node(while_loopp4);
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1506 "pnfha.ypp"
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
#line 1516 "pnfha.ypp"
    {
			 ASTNode do_while_loopp2("do_while_loopp2");

			 tree.add_node(do_while_loopp2);
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1523 "pnfha.ypp"
    {
			 ASTNode do_while_loopp3("do_while_loopp3");

			 conprint("LBL TSTRING \"do_while_test_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp3);
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1531 "pnfha.ypp"
    {
			 ASTNode do_while_loopp4("do_while_loopp4");

			 tree.add_node(do_while_loopp4);
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1537 "pnfha.ypp"
    {
			 ASTNode do_while_loopp5("do_while_loopp5");

			 conprint("CGOTOL TSTRING \"do_while_body_%u\"\n", dowhilecounter);
			 conprint("GOTOL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp5);
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1546 "pnfha.ypp"
    {
			 ASTNode do_while_loopp6("do_while_loopp6");

			 conprint("LBL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp6);
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1555 "pnfha.ypp"
    {
			 infor = true;
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1559 "pnfha.ypp"
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
#line 1569 "pnfha.ypp"
    {
			 ASTNode for_loopp2("for_loopp2");

			 conprint("LBL TSTRING \"for_condition_%u\"\n", forcounter);

			 tree.add_node(for_loopp2);
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1577 "pnfha.ypp"
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
#line 1587 "pnfha.ypp"
    {
			 ASTNode for_loopp4("for_loopp4");

			 conprint("GOTOL TSTRING \"for_condition_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_body_%u\"\n", forcounter);

			 tree.add_node(for_loopp4);
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1596 "pnfha.ypp"
    {
			 ASTNode for_loopp5("for_loopp5");

			 conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_end_%u\"\n", forcounter);

			 tree.add_node(for_loopp5);
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1607 "pnfha.ypp"
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
#line 1620 "pnfha.ypp"
    {
			 ASTNode forb_loopp2("forb_loopp2");

			 conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_initialization_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp2);
			;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1629 "pnfha.ypp"
    {
			 ASTNode forb_loopp3("forb_loopp3");

			 tree.add_node(forb_loopp3);
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1635 "pnfha.ypp"
    {
			 ASTNode forb_loopp4("forb_loopp4");

			 conprint("GOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_condition_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp4);
			;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1644 "pnfha.ypp"
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
#line 1654 "pnfha.ypp"
    {
			 ASTNode forb_loopp6("forb_loopp6");
			 tree.add_node(forb_loopp6);
			;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1659 "pnfha.ypp"
    {
			 ASTNode forb_loopp7("forb_loopp7");

			 conprint("GOTOL TSTRING \"dofor_condition_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_end_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp7);
			;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1670 "pnfha.ypp"
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
#line 1680 "pnfha.ypp"
    {
			 ASTNode forever_loopp2("forever_loopp2");

			 conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);
			 conprint("LBL TSTRING \"forever_end_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp2);			
			;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1689 "pnfha.ypp"
    { PNF_String str((yyvsp[(2) - (3)]).to_string().get()); (yyval).put(str); ASTNode statement_block("statement_block"); 
                                                  tree.add_node(statement_block); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1694 "pnfha.ypp"
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1699 "pnfha.ypp"
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1705 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TVOID; ASTNode expression("expression"); tree.add_node(expression); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1707 "pnfha.ypp"
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
#line 1714 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); savenumber = (yyval); exptype = TNUMBER; ASTNode expression("expression");
                                      tree.add_node(expression); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1716 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); savenumber = (yyval); exptype = TCHARACTER; ASTNode expression("expression"); 
                                         tree.add_node(expression); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1718 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); savenumber = (PNF_String)strip_quotes((yyval).to_string().get()); exptype = TSTRING; ASTNode expression("expression"); 
                                      tree.add_node(expression); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1720 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
                                  tree.add_node(expression); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1722 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TBOOLEAN; ASTNode expression("expression"); 
					  tree.add_node(expression); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1724 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
				     tree.add_node(expression); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1726 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); tree.add_node(expression); 		
		;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1732 "pnfha.ypp"
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
#line 1741 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1745 "pnfha.ypp"
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
#line 1761 "pnfha.ypp"
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
#line 1775 "pnfha.ypp"
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
#line 1791 "pnfha.ypp"
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
#line 1806 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1810 "pnfha.ypp"
    { 
			 (yyval) = (yyvsp[(1) - (1)]);

			 double d = (yyval).to_number().get();

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
#line 1824 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().add(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1830 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().sub(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1836 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mul(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1842 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().div(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1848 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mod(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1854 "pnfha.ypp"
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
#line 1862 "pnfha.ypp"
    {
			 double d = (yyvsp[(3) - (3)]).to_number().get();
			 PNF_Number n((yyvsp[(1) - (3)]).to_number());
			 n.pow(d);
			 (yyval).put(n);
			;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1869 "pnfha.ypp"
    {
			 double d = (yyvsp[(1) - (3)]).to_number().get();
			 PNF_Number n((yyvsp[(3) - (3)]).to_number());
			 n.root(d);			 
			 (yyval).put(n);
			;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1876 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1882 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1888 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1894 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1900 "pnfha.ypp"
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
#line 1908 "pnfha.ypp"
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
#line 1917 "pnfha.ypp"
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
#line 1925 "pnfha.ypp"
    {
			 int d = (int)(yyvsp[(2) - (2)]).to_number().get();
			 d = ~d;
			 PNF_Number n(d);
			 (yyval).put(n);
			;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1932 "pnfha.ypp"
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
#line 1940 "pnfha.ypp"
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
#line 1947 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1952 "pnfha.ypp"
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
#line 1965 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.add((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1972 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.sub((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1979 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mul((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1986 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.div((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);			;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1992 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mod((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1999 "pnfha.ypp"
    {
			 char d = (yyvsp[(3) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(1) - (3)]).to_character());
			 c.pow(d);
			 (yyval).put(c);
			;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 2006 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(3) - (3)]).to_character());
			 c.root(d);
			 (yyval).put(c);
			;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 2013 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 2019 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 2025 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 2031 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 2036 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 2041 "pnfha.ypp"
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
#line 2054 "pnfha.ypp"
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
#line 2079 "pnfha.ypp"
    {
			 String str = (yyvsp[(2) - (2)]).to_string().get();
			 String str2 = "\"" + str + "\"";
			 PNF_String s(str2);
			 (yyval).put(s);
			;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 2085 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 2090 "pnfha.ypp"
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
#line 2161 "pnfha.ypp"
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
#line 2201 "pnfha.ypp"
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
#line 2238 "pnfha.ypp"
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
#line 2315 "pnfha.ypp"
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
#line 2394 "pnfha.ypp"
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
#line 2474 "pnfha.ypp"
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
#line 2512 "pnfha.ypp"
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
#line 2550 "pnfha.ypp"
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
#line 2588 "pnfha.ypp"
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
#line 2626 "pnfha.ypp"
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
#line 2639 "pnfha.ypp"
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
#line 2677 "pnfha.ypp"
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
#line 2715 "pnfha.ypp"
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
#line 2743 "pnfha.ypp"
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
#line 2771 "pnfha.ypp"
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
#line 2799 "pnfha.ypp"
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
#line 2826 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 2830 "pnfha.ypp"
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
#line 2841 "pnfha.ypp"
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
#line 2852 "pnfha.ypp"
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
#line 2863 "pnfha.ypp"
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
#line 2874 "pnfha.ypp"
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
#line 2885 "pnfha.ypp"
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
#line 2895 "pnfha.ypp"
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
#line 2907 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 2909 "pnfha.ypp"
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
#line 2958 "pnfha.ypp"
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
#line 3007 "pnfha.ypp"
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
#line 3056 "pnfha.ypp"
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
#line 3105 "pnfha.ypp"
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
#line 3147 "pnfha.ypp"
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
#line 3189 "pnfha.ypp"
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
#line 3231 "pnfha.ypp"
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
#line 3273 "pnfha.ypp"
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
#line 3315 "pnfha.ypp"
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
#line 3357 "pnfha.ypp"
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
#line 3399 "pnfha.ypp"
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
#line 3441 "pnfha.ypp"
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
#line 3483 "pnfha.ypp"
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
#line 3525 "pnfha.ypp"
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
#line 3567 "pnfha.ypp"
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
#line 3609 "pnfha.ypp"
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
#line 3651 "pnfha.ypp"
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
#line 3693 "pnfha.ypp"
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
#line 3735 "pnfha.ypp"
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
#line 3777 "pnfha.ypp"
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
#line 3819 "pnfha.ypp"
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
#line 3861 "pnfha.ypp"
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
#line 3903 "pnfha.ypp"
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
#line 3945 "pnfha.ypp"
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
#line 3987 "pnfha.ypp"
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
#line 4029 "pnfha.ypp"
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
#line 4071 "pnfha.ypp"
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
#line 4113 "pnfha.ypp"
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
#line 4177 "pnfha.ypp"
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
#line 4241 "pnfha.ypp"
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
#line 4286 "pnfha.ypp"
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
#line 4331 "pnfha.ypp"
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
#line 4376 "pnfha.ypp"
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
#line 4421 "pnfha.ypp"
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
#line 4466 "pnfha.ypp"
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
#line 4511 "pnfha.ypp"
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
#line 4556 "pnfha.ypp"
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
#line 4601 "pnfha.ypp"
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
#line 4646 "pnfha.ypp"
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
#line 4691 "pnfha.ypp"
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
#line 4736 "pnfha.ypp"
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
#line 4781 "pnfha.ypp"
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
#line 4826 "pnfha.ypp"
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
#line 4871 "pnfha.ypp"
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
#line 4916 "pnfha.ypp"
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
#line 4961 "pnfha.ypp"
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
#line 5006 "pnfha.ypp"
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
#line 5051 "pnfha.ypp"
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
#line 5088 "pnfha.ypp"
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
#line 5133 "pnfha.ypp"
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
#line 5178 "pnfha.ypp"
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
#line 5223 "pnfha.ypp"
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
#line 5270 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 5274 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 5280 "pnfha.ypp"
    {
			 funcnum = (unsigned long)(yyvsp[(3) - (3)]).to_number().get();
			;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 5284 "pnfha.ypp"
    {
			 fsaveid2 = (yyvsp[(8) - (8)]);

			 conprint("FCALL TSTRING \"%s\"\n", (yyvsp[(8) - (8)]).to_string().get().getString().c_str());
			 conprint("FCPARAMS TVOID 0V\n");
			;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 5291 "pnfha.ypp"
    {
			 pnum3 = 0;
			 pnum4 = 0;
			;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 5296 "pnfha.ypp"
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

  case 238:

/* Line 1455 of yacc.c  */
#line 5305 "pnfha.ypp"
    {
			 if(fncdefault)
			 {
			  fncdefault = false;
			  conprint("FNCDEFAULT2 TVOID 0V\n");
			}

			 conprint("FECPARAMS TVOID 0V\n");
			;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 5315 "pnfha.ypp"
    {
			 conprint("FECALL TVOID 0V\n");
			;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 5319 "pnfha.ypp"
    {
			 for (unsigned long i = frets3.length() - 1; i > 0; --i)
			  frets3.remove();

			 for (unsigned long i = fparams3.length() - 1; i > 0; --i)
			  fparams3.remove();			
			;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 5329 "pnfha.ypp"
    {

				;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 5336 "pnfha.ypp"
    {
				 (yyval) = (yyvsp[(1) - (1)]);				 

				 for (unsigned long i = 0; i < funcps[funcps.length() - 1].length(); ++i)
			 	 {
			 	  funcps[funcps.length() - 1][i].value((yyvsp[(1) - (1)]));
			 	 }
				;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 5345 "pnfha.ypp"
    {
				 PNF_Type_Enum t;
			  	 if ((yyvsp[(3) - (3)]).to_string().get() == "void")
				  t = TVOID;
				 else if ((yyvsp[(3) - (3)]).to_string().get() == "boolean")
				  t = TBOOLEAN;
				 else if ((yyvsp[(3) - (3)]).to_string().get() == "number")
				  t = TNUMBER;
				 else if ((yyvsp[(3) - (3)]).to_string().get() == "character")
				  t = TCHARACTER;
				 else if ((yyvsp[(3) - (3)]).to_string().get() == "string")
				  t = TSTRING;
				 else
				 {
				  yyerror("Invalid Type.");
				  exit(-1);
				 }

				 switch (t)
				 {
				  case TVOID:
				  {
				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TVOID 0V\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");				   
				  }
				  break;
				  
				  case TBOOLEAN:
				  {
				   fparams3[fparams3.length() - 1] = "BOOLEAN";
			           fparams3.insert();

				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TBOOLEAN false\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");		
				  }
				  break;

				  case TNUMBER:
				  {
				   fparams3[fparams3.length() - 1] = "NUMBER";
			           fparams3.insert();

				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TNUMBER 0\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");		   
				  }
				  break;

				  case TCHARACTER:
				  {
				   fparams3[fparams3.length() - 1] = "CHARACTER";
			           fparams3.insert();

				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TCHARACTER ''\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");
				  }
				  break;

				  case TSTRING:
				  {
				   fparams3[fparams3.length() - 1] = "STRING";
			           fparams3.insert();

				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TSTRING \"\" 0\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");
				  }
				  break;

				  default:
				   yyerror("Invalid type.");
				 }
				 ++pnum3;
				 ++pnum4;
				;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 5429 "pnfha.ypp"
    {
				 PNF_Type_Enum t;
			  	 if ((yyvsp[(5) - (5)]).to_string().get() == "void")
				  t = TVOID;
				 else if ((yyvsp[(5) - (5)]).to_string().get() == "boolean")
				  t = TBOOLEAN;
				 else if ((yyvsp[(5) - (5)]).to_string().get() == "number")
				  t = TNUMBER;
				 else if ((yyvsp[(5) - (5)]).to_string().get() == "character")
				  t = TCHARACTER;
				 else if ((yyvsp[(5) - (5)]).to_string().get() == "string")
				  t = TSTRING;
				 else
				 {
				  yyerror("Invalid Type.");
				  exit(-1);
				 }

				 switch (t)
				 {
				  case TVOID:
				  {
				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TVOID 0V\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");				   
				  }
				  break;
				  
				  case TBOOLEAN:
				  {
				   fparams3[fparams3.length() - 1] = "BOOLEAN";
			           fparams3.insert();

				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TBOOLEAN false\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");		
				  }
				  break;

				  case TNUMBER:
				  {
				   fparams3[fparams3.length() - 1] = "NUMBER";
			           fparams3.insert();

				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TNUMBER 0\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");		   
				  }
				  break;

				  case TCHARACTER:
				  {
				   fparams3[fparams3.length() - 1] = "CHARACTER";
			           fparams3.insert();

				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TCHARACTER ''\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");
				  }
				  break;

				  case TSTRING:
				  {
				   fparams3[fparams3.length() - 1] = "STRING";
			           fparams3.insert();

				   conprint("ALOAD TNUMBER %d\n", funcnum);
				   conprint("PNUM TNUMBER %d\n", pnum3);
				   conprint("PARAMF TSTRING \"\" 0\n");
				   conprint("FNCDEFAULTSYNC TVOID 0V\n");
				  }
				  break;

				  default:
				   yyerror("Invalid type.");
				 }
				 ++pnum3;
				 ++pnum4;
				;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 5515 "pnfha.ypp"
    {
				 ++pnum4;
				;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 5519 "pnfha.ypp"
    {
				 ++pnum4;
				;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 5541 "pnfha.ypp"
    {
				 /*
				 // Patch the code
				 fsaveindex = ((fsaveindex >= 12) || !saw_12) ? fsaveindex + 1 : fsaveindex;
				 if (!saw_12 && (fsaveindex == 12))
				  saw_12 = true;
				*/	 	 
				;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 5550 "pnfha.ypp"
    {
				 (yyval) = (yyvsp[(1) - (2)]);
				 saveexp = savenumber;


				 conprint("FNCLOAD TNUMBER %d\n", funcnum);

				 conprint("PNUM TNUMBER %d\n", pnum4);
				 switch (exptype)
				 {
				  case TVOID:
				   conprint("FNCSPARAM TVOID 0V\n");
				   break;

				  case TBOOLEAN:
				   conprint("FNCSPARAM TBOOLEAN 0V\n");
				   break;

				  case TNUMBER:
				   conprint("FNCSPARAM TNUMBER 0V\n");
				   break;

				  case TCHARACTER:
				   conprint("FNCSPARAM TCHARACTER 0V\n");
				   break;

				  case TSTRING:
				   conprint("FNCSPARAM TSTRING 0V\n");
				   break;

				  default:
				  {
				   yyerror("Invalid type.");
				   exit(-1);
				  }
				 }


 				 switch (exptype)
				 {
				  case TVOID:
				  {
				  }
				  break;
				  
				  case TBOOLEAN:
				  {
				   fparams3[fparams3.length() - 1] = "BOOLEAN";
			           fparams3.insert();
				  }
				  break;

				  case TNUMBER:
				  {
				   fparams3[fparams3.length() - 1] = "NUMBER";
			           fparams3.insert();			   
				  }
				  break;

				  case TCHARACTER:
				  {
				   fparams3[fparams3.length() - 1] = "CHARACTER";
			           fparams3.insert();
				  }
				  break;

				  case TSTRING:
				  {
				   fparams3[fparams3.length() - 1] = "STRING";
			           fparams3.insert();
				  }
				  break;

				  default:
				   yyerror("Invalid type.");
				 }
	
				 conprint("FNCSTORE TNUMBER %d\n", funcnum);
				 actual_parameters(saveexp);
				;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 5724 "pnfha.ypp"
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 5729 "pnfha.ypp"
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 5734 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 5739 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 5746 "pnfha.ypp"
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

  case 254:

/* Line 1455 of yacc.c  */
#line 5804 "pnfha.ypp"
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

  case 255:

/* Line 1455 of yacc.c  */
#line 5885 "pnfha.ypp"
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

  case 256:

/* Line 1455 of yacc.c  */
#line 5920 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 5925 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 5930 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 5937 "pnfha.ypp"
    {
			 ASTNode enumv_declaration("enumv_declaration");

			 conprint("ENUMS TSTRING %s\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 conprint("ENUM TSTRING %s\n", (yyvsp[(5) - (5)]).to_string().get().getString().c_str());
			 conprint("SENUM TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());

			 tree.add_node(enumv_declaration);
			;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 5949 "pnfha.ypp"
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

  case 261:

/* Line 1455 of yacc.c  */
#line 5964 "pnfha.ypp"
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

  case 262:

/* Line 1455 of yacc.c  */
#line 5980 "pnfha.ypp"
    {
			 ASTNode array_declaration("array_declaration");

			 conprint("ASTART TSTRING %s\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 conprint("AEND TNUMBER %g\n", (yyvsp[(4) - (5)]).to_number().get());

			 tree.add_node(array_declaration);
			;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 5991 "pnfha.ypp"
    {
			 ASTNode enum_declarationp1("enum_declarationp1");

			 conprint("ESTART TSTRING \"%s\"\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());

			 tree.add_node(enum_declarationp1);
			;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 5999 "pnfha.ypp"
    {
			 ASTNode enum_declarationp2("enum_declarationp2");
			 tree.add_node(enum_declarationp2);
			;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 6004 "pnfha.ypp"
    {
			 ASTNode enum_declarationp3("enum_declarationp3");

			 conprint("EEND TVOID 0V\n");

			 tree.add_node(enum_declarationp3);
			;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 6014 "pnfha.ypp"
    {
			 ASTNode enum_strings("enum_strings");

			 conprint("ENAME TSTRING %s\n", (yyvsp[(1) - (1)]).to_string().get().getString().c_str());

			 tree.add_node(enum_strings);
			;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 6022 "pnfha.ypp"
    {
			 conprint("ENAME TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 6028 "pnfha.ypp"
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

  case 269:

/* Line 1455 of yacc.c  */
#line 6053 "pnfha.ypp"
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
#line 6077 "pnfha.ypp"
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

  case 271:

/* Line 1455 of yacc.c  */
#line 6100 "pnfha.ypp"
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

  case 274:

/* Line 1455 of yacc.c  */
#line 6128 "pnfha.ypp"
    {
			 funcps.insert();

			 funcptr->name((yyvsp[(5) - (8)]).to_string().get());			 
			 funcstk.add_function(*funcptr);
			 delete funcptr;
			 funcptr = NULL;			 
	
			 saveid3 = (yyvsp[(5) - (8)]);
			 unsigned long index = funcstk.find((yyvsp[(5) - (8)]).to_string().get(), frets, fparams);
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
			 
			 
			 conprint("ALOAD TSTRING \"%s\"\n", (yyvsp[(5) - (8)]).to_string().get().getString().c_str());
			 conprint("FNCSNAME TVOID 0V\n");
			 conprint("FNCSDEF TSTRING \"%s\"\n", funcstk.get_function(index).rname().getString().c_str());
			 conprint("FNCSTORE TVOID 0V\n");
			 conprint("FNCDELETE TVOID 0V\n")
			;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 6164 "pnfha.ypp"
    {
			 for (unsigned long i = frets.length() - 1; i > 0; --i)
			  frets.remove();

			 for (unsigned long i = fparams.length() - 1; i > 0; --i)
			  fparams.remove();
			;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 6176 "pnfha.ypp"
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

  case 278:

/* Line 1455 of yacc.c  */
#line 6269 "pnfha.ypp"
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

  case 279:

/* Line 1455 of yacc.c  */
#line 6381 "pnfha.ypp"
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


			 if (fncdefault)
			 {
			  conprint("FNCLOAD TNUMBER %d\n", fsaveindex + 1);

			  switch (exptype)
			  {
			   case TVOID:
			   {
			    conprint("ALOAD TVOID 0V\n");
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   case TBOOLEAN:
			   {
			    conprint("ALOAD TBOOLEAN %s\n", funcstk.get_function(fsaveindex + 1).defaultv(pnum5).to_boolean().get().getString().c_str());
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   case TNUMBER:
			   {
			    conprint("ALOAD TNUMBER %g\n", funcstk.get_function(fsaveindex + 1).defaultv(pnum5).to_number().get());
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   case TCHARACTER:
			   {
			    conprint("ALOAD TCHARACTER %c\n", funcstk.get_function(fsaveindex + 1).defaultv(pnum5).to_character().get());
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   case TSTRING:
			   {
			    conprint("ALOAD TSTRING %s\n", funcstk.get_function(fsaveindex + 1).defaultv(pnum5).to_string().get().getString().c_str());
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   default:
			   {
			    yyerror((char *)"Invalid Type.");
			    exit(-1);
			   }
			  }

			  conprint("FNCSTORE TNUMBER %d\n", fsaveindex + 1);
			 }
			;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 6483 "pnfha.ypp"
    {
			 String type = (yyvsp[(6) - (7)]).to_string().get();
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


			 if (fncdefault)
			 {
			  conprint("FNCLOAD TNUMBER %d\n", fsaveindex + 1);

			  switch (exptype)
			  {
			   case TVOID:
			   {
			    conprint("ALOAD TVOID 0V\n");
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   case TBOOLEAN:
			   {
			    conprint("ALOAD TBOOLEAN %s\n", funcstk.get_function(fsaveindex + 1).defaultv(pnum5).to_boolean().get().getString().c_str());
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   case TNUMBER:
			   {
			    conprint("ALOAD TNUMBER %g\n", funcstk.get_function(fsaveindex + 1).defaultv(pnum5).to_number().get());
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   case TCHARACTER:
			   {
			    conprint("ALOAD TCHARACTER %c\n", funcstk.get_function(fsaveindex + 1).defaultv(pnum5).to_character().get());
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   case TSTRING:
			   {
			    conprint("ALOAD TSTRING %s\n", funcstk.get_function(fsaveindex + 1).defaultv(pnum5).to_string().get().getString().c_str());
			    conprint("PNUM TNUMBER %d\n", pnum5);
			    conprint("FNCSDEFAULTV2 TVOID 0V\n");
			   }
			   break;

			   default:
			   {
			    yyerror((char *)"Invalid Type.");
			    exit(-1);
			   }
			  }

			  conprint("FNCSTORE TNUMBER %d\n", fsaveindex + 1);
			 }
			;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 6599 "pnfha.ypp"
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

  case 282:

/* Line 1455 of yacc.c  */
#line 6644 "pnfha.ypp"
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

  case 283:

/* Line 1455 of yacc.c  */
#line 6703 "pnfha.ypp"
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

  case 284:

/* Line 1455 of yacc.c  */
#line 6748 "pnfha.ypp"
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

  case 285:

/* Line 1455 of yacc.c  */
#line 6807 "pnfha.ypp"
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
#line 6825 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 6833 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (5)]);

			 String type = (yyvsp[(4) - (5)]).to_string().get();
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
#line 6851 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 6859 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);


			 funcps[fsaveindex + 1].insert();
			 funcps[fsaveindex + 1][pnum5].value((yyval));


			 funcstk.get_function(fsaveindex + 1).defaultv(pnum5, (yyval));
			;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 6872 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (4)]);
			 pnum5 = (unsigned long)(yyvsp[(4) - (4)]).to_number().get();
			;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 6879 "pnfha.ypp"
    {
			 fncdefault = true;
			 conprint("FNCDEFAULT TVOID 0V\n");
			;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 6886 "pnfha.ypp"
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

  case 295:

/* Line 1455 of yacc.c  */
#line 6904 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 6912 "pnfha.ypp"
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

  case 297:

/* Line 1455 of yacc.c  */
#line 6930 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 6938 "pnfha.ypp"
    {
			 pnum5 = 0;


			 fsaveid = (yyvsp[(6) - (9)]);
			 unsigned long index = funcstk.find((yyvsp[(6) - (9)]).to_string().get(), frets2, fparams2);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 fsaveindex = index;

			 conprint("GOTOL TSTRING \"%s_END\"\n", funcstk.get_function(index).rname().getString().c_str());
			 conprint("LBL TSTRING \"%s\"\n", funcstk.get_function(index).rname().getString().c_str());
			;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 6956 "pnfha.ypp"
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

  case 300:

/* Line 1455 of yacc.c  */
#line 6967 "pnfha.ypp"
    {
			 for (unsigned long i = frets2.length() - 1; i > 0; --i)
			  frets2.remove();

			 for (unsigned long i = fparams2.length() - 1; i > 0; --i)
			  fparams2.remove();
			;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 6982 "pnfha.ypp"
    {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");

			 exptype = TVOID;
			;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 6990 "pnfha.ypp"
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

  case 304:

/* Line 1455 of yacc.c  */
#line 7076 "pnfha.ypp"
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

  case 305:

/* Line 1455 of yacc.c  */
#line 7158 "pnfha.ypp"
    {
			 exptype = TVOID;
			;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 7162 "pnfha.ypp"
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

  case 307:

/* Line 1455 of yacc.c  */
#line 7210 "pnfha.ypp"
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

  case 308:

/* Line 1455 of yacc.c  */
#line 7260 "pnfha.ypp"
    {
			 exptype = TVOID;			;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 7263 "pnfha.ypp"
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

  case 310:

/* Line 1455 of yacc.c  */
#line 7325 "pnfha.ypp"
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

  case 311:

/* Line 1455 of yacc.c  */
#line 7532 "pnfha.ypp"
    {
			 exptype = TVOID;
			;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 7536 "pnfha.ypp"
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

  case 313:

/* Line 1455 of yacc.c  */
#line 7584 "pnfha.ypp"
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

  case 314:

/* Line 1455 of yacc.c  */
#line 7634 "pnfha.ypp"
    {
			 exptype = TVOID;
			;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 7638 "pnfha.ypp"
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

  case 316:

/* Line 1455 of yacc.c  */
#line 7686 "pnfha.ypp"
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

  case 317:

/* Line 1455 of yacc.c  */
#line 7738 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 7743 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 7748 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 7753 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 7758 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 7763 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 7768 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 7773 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 7778 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 7783 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 7788 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 7793 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 7798 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 7803 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 7808 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 7813 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 7818 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 7823 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 7828 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 7833 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 7838 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 7843 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 7848 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 7853 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 7858 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 7863 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 7868 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 7873 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 7878 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 7883 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 7892 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("PRINT TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 7898 "pnfha.ypp"
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

  case 350:

/* Line 1455 of yacc.c  */
#line 7944 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "ver")
			  conprint("VPRINT TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 7955 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("PRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 7961 "pnfha.ypp"
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

  case 353:

/* Line 1455 of yacc.c  */
#line 8007 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "ver")
			  conprint("VPRINTLN TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 8018 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINT TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 8024 "pnfha.ypp"
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

  case 356:

/* Line 1455 of yacc.c  */
#line 8070 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 8076 "pnfha.ypp"
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

  case 358:

/* Line 1455 of yacc.c  */
#line 8122 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINT TVOID 0V\n");
			;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 8127 "pnfha.ypp"
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

  case 360:

/* Line 1455 of yacc.c  */
#line 8173 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 8179 "pnfha.ypp"
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

  case 362:

/* Line 1455 of yacc.c  */
#line 8225 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 conprint("APRINT TVOID 0V\n");

			 tree.add_node(print_command);
			;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 8237 "pnfha.ypp"
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

  case 364:

/* Line 1455 of yacc.c  */
#line 8296 "pnfha.ypp"
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

  case 365:

/* Line 1455 of yacc.c  */
#line 8369 "pnfha.ypp"
    {
			 ASTNode end_command("end_command");
			 conprint("QUIT TVOID %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(end_command);
			;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 8377 "pnfha.ypp"
    {
			 ASTNode asm_command("asm_command");
			 conprint("%s %s %s\n", strip_quotes((yyvsp[(2) - (4)]).to_string().get()).getString().c_str(), 
					      strip_quotes((yyvsp[(3) - (4)]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[(4) - (4)]).to_string().get()).getString().c_str());
			 tree.add_node(asm_command);
			;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 8386 "pnfha.ypp"
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

  case 368:

/* Line 1455 of yacc.c  */
#line 8523 "pnfha.ypp"
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

  case 369:

/* Line 1455 of yacc.c  */
#line 8616 "pnfha.ypp"
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

  case 370:

/* Line 1455 of yacc.c  */
#line 8644 "pnfha.ypp"
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

  case 371:

/* Line 1455 of yacc.c  */
#line 8655 "pnfha.ypp"
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

  case 372:

/* Line 1455 of yacc.c  */
#line 8672 "pnfha.ypp"
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

  case 373:

/* Line 1455 of yacc.c  */
#line 8683 "pnfha.ypp"
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

  case 374:

/* Line 1455 of yacc.c  */
#line 8694 "pnfha.ypp"
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

  case 375:

/* Line 1455 of yacc.c  */
#line 8869 "pnfha.ypp"
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

  case 376:

/* Line 1455 of yacc.c  */
#line 8888 "pnfha.ypp"
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

  case 377:

/* Line 1455 of yacc.c  */
#line 8902 "pnfha.ypp"
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

  case 378:

/* Line 1455 of yacc.c  */
#line 8915 "pnfha.ypp"
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

  case 379:

/* Line 1455 of yacc.c  */
#line 8929 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[(5) - (6)]).to_number().get());
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 8939 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 8949 "pnfha.ypp"
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

  case 382:

/* Line 1455 of yacc.c  */
#line 8974 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 8982 "pnfha.ypp"
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

  case 384:

/* Line 1455 of yacc.c  */
#line 9007 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 9015 "pnfha.ypp"
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

  case 386:

/* Line 1455 of yacc.c  */
#line 9040 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 9048 "pnfha.ypp"
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

  case 388:

/* Line 1455 of yacc.c  */
#line 9073 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 9083 "pnfha.ypp"
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

  case 390:

/* Line 1455 of yacc.c  */
#line 9103 "pnfha.ypp"
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

  case 391:

/* Line 1455 of yacc.c  */
#line 9208 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 9214 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 9220 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TCHARACTER %c\n", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 9226 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(operator_command);
			;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 9232 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 9238 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 9244 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 9250 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 9256 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 9262 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 9268 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 9274 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 9280 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 9286 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 9292 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 9298 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 9304 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("INC TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 9310 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("DEC TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 9316 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("AND TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 9322 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("OR TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 9328 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NOT TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 9334 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 9340 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 9346 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 9352 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 9358 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 9364 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 9370 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[(2) - (2)]).to_boolean().get();

			 conprint("EQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 9380 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[(2) - (2)]).to_boolean().get();

			 conprint("NEQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 9390 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 9396 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 9402 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 9408 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 9414 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 9420 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 9426 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 9432 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 9438 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 9444 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 9450 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 9456 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 9462 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTAND TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 9468 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTOR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 9474 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTXOR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 9480 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTNOT TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 9486 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSL TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 9492 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 9502 "pnfha.ypp"
    {
			 ASTNode top_commandp1("top_commandp1");

			 intop = true;
			 ++topcounter;

			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp1);
			;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 9513 "pnfha.ypp"
    {
			 ASTNode top_commandp2("top_commandp2");			 

			 tree.add_node(top_commandp2);
			;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 9519 "pnfha.ypp"
    {
			 ASTNode top_commandp3("top_commandp3");

			conprint("IFEND TVOID 0V\n"); 
			conprint("ENDIF TVOID 0V\n");

			 tree.add_node(top_commandp3);
			;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 9528 "pnfha.ypp"
    {
			 ASTNode top_commandp4("top_commandp4");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp4);
			;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 9537 "pnfha.ypp"
    {
			 ASTNode top_commandp5("top_commandp5");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");
			 conprint("EIF TVOID 0V\n");

			 tree.add_node(top_commandp5);
			;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 9549 "pnfha.ypp"
    {
			 ASTNode st_command("st_command");
			 conprint("ST TVOID 0V\n");
			 tree.add_node(st_command);
			;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 9557 "pnfha.ypp"
    {
			 ASTNode stack_command("stack_command");
			 conprint("PUSH TVOID 0V\n");
			 tree.add_node(stack_command);
			;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 9563 "pnfha.ypp"
    {
			 ASTNode stack_command("stack_command");
			 conprint("POP TVOID 0V\n");
			 tree.add_node(stack_command);
			;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 9571 "pnfha.ypp"
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

  case 448:

/* Line 1455 of yacc.c  */
#line 9584 "pnfha.ypp"
    {
			 ASTNode rm_command("rm_command");
			 conprint("ATOC TVOID 0V\n");
			 tree.add_node(rm_command);
			;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 9590 "pnfha.ypp"
    {
			 conprint("ATOSP TVOID 0V\n");
			;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 9594 "pnfha.ypp"
    {
			 conprint("SPTOA TVOID 0V\n");
			;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 9598 "pnfha.ypp"
    {
			 ASTNode rm_command("rm_command");
			 conprint("SWITCH TVOID 0V\n");
			 tree.add_node(rm_command);
			;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 9606 "pnfha.ypp"
    {
			 ASTNode crash_command("crash_command");
			 conprint("CRASH TSTRING %s", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(crash_command);
			;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 9614 "pnfha.ypp"
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

  case 454:

/* Line 1455 of yacc.c  */
#line 9631 "pnfha.ypp"
    {
			 ASTNode halt_command("halt_command");
			 conprint("HALT TVOID 0V\n");
			 tree.add_node(halt_command);
			;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 9639 "pnfha.ypp"
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

  case 456:

/* Line 1455 of yacc.c  */
#line 9654 "pnfha.ypp"
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("RET TVOID 0V\n");
			 tree.add_node(subroutine_command);
			;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 9660 "pnfha.ypp"
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("CALL TVOID %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(subroutine_command);
			;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 9666 "pnfha.ypp"
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

  case 459:

/* Line 1455 of yacc.c  */
#line 9797 "pnfha.ypp"
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

  case 460:

/* Line 1455 of yacc.c  */
#line 9831 "pnfha.ypp"
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

  case 461:

/* Line 1455 of yacc.c  */
#line 9950 "pnfha.ypp"
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

  case 462:

/* Line 1455 of yacc.c  */
#line 10174 "pnfha.ypp"
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

  case 463:

/* Line 1455 of yacc.c  */
#line 10195 "pnfha.ypp"
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

  case 464:

/* Line 1455 of yacc.c  */
#line 10228 "pnfha.ypp"
    {
			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "stk")
			 {
			  conprint("STORESTACK TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid store type.");
			;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 10237 "pnfha.ypp"
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

  case 466:

/* Line 1455 of yacc.c  */
#line 10270 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 conprint("STOREA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 10278 "pnfha.ypp"
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

  case 468:

/* Line 1455 of yacc.c  */
#line 10292 "pnfha.ypp"
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

  case 469:

/* Line 1455 of yacc.c  */
#line 10305 "pnfha.ypp"
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[(5) - (6)]).to_number().get());
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 10315 "pnfha.ypp"
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 10327 "pnfha.ypp"
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

  case 472:

/* Line 1455 of yacc.c  */
#line 10345 "pnfha.ypp"
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

  case 473:

/* Line 1455 of yacc.c  */
#line 10373 "pnfha.ypp"
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

  case 474:

/* Line 1455 of yacc.c  */
#line 10451 "pnfha.ypp"
    {
			 ASTNode add2v_command("add2v_command");

			 conprint("ADD2V TVOID 0V\n");

		         tree.add_node(add2v_command);
			;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 10461 "pnfha.ypp"
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

  case 476:

/* Line 1455 of yacc.c  */
#line 10480 "pnfha.ypp"
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

  case 477:

/* Line 1455 of yacc.c  */
#line 10507 "pnfha.ypp"
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

  case 478:

/* Line 1455 of yacc.c  */
#line 10530 "pnfha.ypp"
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

  case 479:

/* Line 1455 of yacc.c  */
#line 10553 "pnfha.ypp"
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

  case 480:

/* Line 1455 of yacc.c  */
#line 10576 "pnfha.ypp"
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

  case 481:

/* Line 1455 of yacc.c  */
#line 10595 "pnfha.ypp"
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

  case 482:

/* Line 1455 of yacc.c  */
#line 10617 "pnfha.ypp"
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

  case 483:

/* Line 1455 of yacc.c  */
#line 10650 "pnfha.ypp"
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

  case 484:

/* Line 1455 of yacc.c  */
#line 10667 "pnfha.ypp"
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

  case 485:

/* Line 1455 of yacc.c  */
#line 10684 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 conprint("FIEOF TVOID 0V\n");

			 tree.add_node(file_command);
			;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 10694 "pnfha.ypp"
    {
			 ASTNode meml_command("meml_command");

			 conprint("MEML TVOID 0V\n");

			 tree.add_node(meml_command);
			;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 10704 "pnfha.ypp"
    {
			 ASTNode pnfasm_command("pnfasm_command");

			 conprint("pnf %s %s %s\n", strip_quotes((yyvsp[(2) - (4)]).to_string().get()).getString().c_str(), 
						 strip_quotes((yyvsp[(3) - (4)]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[(4) - (4)]).to_string().get()).getString().c_str());

			 tree.add_node(pnfasm_command);
			;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 10715 "pnfha.ypp"
    {
			 ASTNode array_length_command("array_length_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			 conprint("ALENGTH TVOID 0V\n");

			 tree.add_node(array_length_command);
			;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 10725 "pnfha.ypp"
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

  case 490:

/* Line 1455 of yacc.c  */
#line 10744 "pnfha.ypp"
    {
			 conprint("FRET TVOID 0V\n");
			;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 10754 "pnfha.ypp"
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

  case 494:

/* Line 1455 of yacc.c  */
#line 10798 "pnfha.ypp"
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			;}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 10808 "pnfha.ypp"
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

  case 496:

/* Line 1455 of yacc.c  */
#line 10855 "pnfha.ypp"
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			;}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 10865 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(5) - (8)]);
			;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 10871 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(5) - (8)]);
			;}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 10877 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#BIN#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 10883 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#PBIN#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 10889 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#LIB#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 10897 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include %s", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 10903 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include <%s>", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 10909 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 10915 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 10921 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), 
						    (yyvsp[(3) - (3)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 10928 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 10934 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endm\n");
			 tree.add_node(pp_statement);
		 	;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 10940 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 10946 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 10952 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#infdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 10958 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#else\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 10964 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endif\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 10970 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_DATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 10976 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_TIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 10982 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_LINE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 10988 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_FILE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 10994 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CDATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 11000 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CTIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 11006 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
		 	 conprint("%%include %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 11012 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%include <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 11018 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 11024 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 11030 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), 
						     (yyvsp[(3) - (3)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 11037 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 11043 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endm\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 11049 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 11055 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 11061 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%infdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 11067 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%else\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 11073 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endif\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 11079 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_DATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 11085 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_TIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 11091 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_LINE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 11097 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_FILE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 11103 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CDATE()\n");
			 tree.add_node(pp_statement);
			;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 11109 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CTIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;



/* Line 1455 of yacc.c  */
#line 15617 "pnfha.tab.cpp"
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
#line 11115 "pnfha.ypp"

/* Additional C/C++ Code */
void actual_parameters(PNF_Variable v)
{
 switch (exptype)
 {
  case TVOID:
   conprint("ALOAD TNUMBER %d\n", funcnum);
   conprint("PNUM TNUMBER %d\n", pnum4);
   conprint("PARAMF TVOID 0V\n");
   break;

  case TBOOLEAN:
   conprint("ALOAD TNUMBER %d\n", funcnum);
   conprint("PNUM TNUMBER %d\n", pnum4);
   conprint("PARAMF TBOOLEAN %s\n", v.to_boolean().get().getString().c_str());
   break;

  case TNUMBER:
  {
   conprint("ALOAD TNUMBER %d\n", funcnum);
   conprint("PNUM TNUMBER %d\n", pnum4);
   double d = v.to_number().get();
   conprint("PARAMF TNUMBER %g\n", d);
  }
  break;

  case TCHARACTER:
  {
   conprint("ALOAD TNUMBER %d\n", funcnum);
   conprint("PNUM TNUMBER %d\n", pnum4);
   conprint("PARAMF TCHARACTER '%c'\n", v.to_character().get());
  }
  break;

  case TSTRING:
   conprint("ALOAD TNUMBER %d\n", funcnum);
   conprint("PNUM TNUMBER %d\n", pnum4);
   conprint("PARAMF TSTRING \"%s\"\n", v.to_string().get().getString().c_str());
   break;

 default:
  yyerror("Invalid type.");
 }


 ++pnum3;
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
