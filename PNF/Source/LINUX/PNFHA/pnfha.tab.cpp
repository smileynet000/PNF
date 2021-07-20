
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
			10. Bug fixes...
			11. Debugged...
 		        12. Implemented through segments...
*/
#include <desLib/deslib.hpp>
#include <cmath>
#include <sstream>
#include <typeinfo>

#include "../pnf.hpp"


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
  sprintf(temp2, "%d", offset);
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
  sprintf(temp2, "%d", offset);
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

unsigned long untilcounter = 0;

unsigned long dountilcounter = 0;


bool inloop2 = false;
bool inwhile = false;
bool indowhile = false;
bool infor2 = false;
bool indofor = false;
bool inforever = false;
bool inuntil = false;
bool indountil = false;


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
#line 851 "pnfha.tab.cpp"

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
     OPCMP = 273,
     OPGEQU = 274,
     OPGTR = 275,
     OPLEQU = 276,
     OPLSS = 277,
     OPNEQU = 278,
     OPEQU = 279,
     OPBTOR = 280,
     OPBTXOR = 281,
     OPAND = 282,
     OPOR = 283,
     OPEQUAL = 284,
     LEFTP = 285,
     RIGHTP = 286,
     LEFTB = 287,
     RIGHTB = 288,
     VOIDV = 289,
     BOOLEANV = 290,
     NUMBERV = 291,
     CHARACTERV = 292,
     STRINGV = 293,
     SEND = 294,
     COMMA = 295,
     OPQUES = 296,
     OPCOLON = 297,
     OPSUB = 298,
     OPSTR = 299,
     OPSTRTIMES = 300,
     OPRUN = 301,
     ID = 302,
     VAR = 303,
     PRINT = 304,
     PRINTLN = 305,
     EPRINT = 306,
     EPRINTLN = 307,
     END = 308,
     ASM = 309,
     TYPE = 310,
     READ = 311,
     LOAD = 312,
     LTYPE = 313,
     GOTO = 314,
     GTYPE = 315,
     ST = 316,
     PUSH = 317,
     POP = 318,
     TOP = 319,
     TYPEOF = 320,
     RTYPE = 321,
     ATOC = 322,
     SWITCH = 323,
     CSWITCH = 324,
     CRASH = 325,
     VERSION = 326,
     VTYPE = 327,
     HALT = 328,
     MODT = 329,
     RETURN = 330,
     GOSUB = 331,
     SUB = 332,
     EVENT = 333,
     STYPE = 334,
     ATYPE = 335,
     CTYPE = 336,
     CMTYPE = 337,
     BFMODEC = 338,
     FMODEC = 339,
     UNREGISTER = 340,
     REGISTER = 341,
     REREGISTER = 342,
     STORE = 343,
     IF = 344,
     ELSE = 345,
     CASE = 346,
     CCASE = 347,
     DEFAULT = 348,
     CDEFAULT = 349,
     BREAK = 350,
     LABEL = 351,
     WHILE = 352,
     ADDRESSOF = 353,
     ADD2V = 354,
     STOREA = 355,
     DOWHILE = 356,
     DOFOR = 357,
     FOR = 358,
     FVAR = 359,
     FOREVER = 360,
     CONTINUE = 361,
     CHECK = 362,
     HCMNT = 363,
     FMODE = 364,
     FOPEN = 365,
     FCLOSE = 366,
     FEOF = 367,
     FPRINT = 368,
     FPRINTLN = 369,
     FREAD = 370,
     MEML = 371,
     ENUM = 372,
     ENUMV = 373,
     VTYPE2 = 374,
     RANGE = 375,
     RTYPE2 = 376,
     OPDOT = 377,
     RANGEV = 378,
     OPLSQ = 379,
     OPRSQ = 380,
     ARRAY = 381,
     BLANK = 382,
     PNFASM = 383,
     LENGTH = 384,
     DUP = 385,
     THEN = 386,
     ENDIF = 387,
     DONEIF = 388,
     ATOSP = 389,
     SPTOA = 390,
     FUNCTION = 391,
     FUNCDEF = 392,
     FUNCCALL = 393,
     FRET = 394,
     FPARAMETER = 395,
     DEFAULTV = 396,
     DEFAULTV2 = 397,
     UNTIL = 398,
     UNLESS = 399,
     DOUNTIL = 400,
     RUNOPOP = 401,
     STRUCT = 402,
     STRUCTVAR = 403,
     UNION = 404,
     UNIONVAR = 405,
     USE = 406,
     OTYPE = 407,
     MODE = 408,
     EXTMODE = 409,
     COPY = 410,
     SEGMENT = 411,
     CETYPE = 412,
     PBIN = 413,
     PPBIN = 414,
     PLIB = 415,
     PINCLUDE = 416,
     PIMPORT = 417,
     PDEFINE = 418,
     PMACRO = 419,
     PENDM = 420,
     PUNDEF = 421,
     PIFDEF = 422,
     PIFNDEF = 423,
     PELSE = 424,
     PENDIF = 425,
     PPDATE = 426,
     PPTIME = 427,
     PPLINE = 428,
     PPFILE = 429,
     PPCDATE = 430,
     PPCTIME = 431,
     PPINCLUDE = 432,
     PPIMPORT = 433,
     PPDEFINE = 434,
     PPMACRO = 435,
     PPENDM = 436,
     PPUNDEF = 437,
     PPIFDEF = 438,
     PPIFNDEF = 439,
     PPELSE = 440,
     PPENDIF = 441,
     PPPDATE = 442,
     PPPTIME = 443,
     PPPLINE = 444,
     PPPFILE = 445,
     PPPCDATE = 446,
     PPPCTIME = 447
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
#line 1085 "pnfha.tab.cpp"

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
#define YYLAST   1916

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  196
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  214
/* YYNRULES -- Number of rules.  */
#define YYNRULES  607
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1096

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   450

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
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    13,    15,    16,
      19,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    44,    47,    50,    53,    57,    61,    63,    65,    67,
      69,    70,    71,    72,    73,    74,    89,    90,    91,    92,
      93,    94,   109,   110,   111,   116,   118,   119,   120,   121,
     122,   135,   136,   137,   138,   150,   151,   154,   157,   158,
     164,   165,   166,   171,   172,   175,   178,   179,   180,   187,
     188,   189,   194,   195,   198,   199,   203,   205,   207,   209,
     210,   213,   214,   215,   216,   225,   226,   227,   228,   229,
     230,   242,   243,   244,   245,   254,   255,   256,   257,   258,
     259,   271,   272,   273,   274,   275,   276,   291,   292,   293,
     294,   295,   296,   297,   314,   315,   319,   323,   325,   328,
     330,   332,   334,   336,   338,   340,   342,   344,   346,   348,
     352,   354,   357,   361,   365,   369,   371,   375,   379,   383,
     387,   391,   394,   398,   402,   405,   408,   411,   414,   418,
     422,   426,   429,   433,   437,   441,   443,   447,   451,   455,
     459,   463,   467,   471,   474,   477,   480,   483,   487,   489,
     493,   496,   500,   502,   505,   508,   512,   516,   520,   524,
     528,   532,   536,   539,   543,   547,   550,   553,   556,   559,
     563,   567,   571,   575,   579,   583,   584,   589,   593,   597,
     601,   605,   609,   613,   617,   621,   625,   629,   633,   637,
     641,   645,   649,   653,   657,   661,   665,   669,   673,   677,
     681,   685,   689,   693,   697,   701,   705,   709,   713,   717,
     721,   725,   729,   733,   737,   741,   745,   749,   753,   757,
     761,   765,   769,   773,   777,   781,   785,   789,   792,   796,
     800,   804,   808,   812,   816,   818,   822,   823,   824,   825,
     826,   827,   828,   846,   848,   850,   852,   856,   860,   866,
     868,   870,   872,   874,   876,   878,   880,   882,   884,   886,
     888,   891,   896,   899,   901,   903,   905,   911,   918,   923,
     929,   930,   931,   940,   942,   946,   955,   956,   961,   965,
     967,   970,   971,   976,   980,   988,   989,   994,   998,  1000,
    1003,  1004,  1009,  1013,  1021,  1024,  1027,  1030,  1032,  1034,
    1035,  1046,  1047,  1049,  1056,  1058,  1066,  1068,  1075,  1077,
    1084,  1089,  1091,  1097,  1099,  1100,  1102,  1107,  1108,  1110,
    1115,  1117,  1122,  1124,  1125,  1126,  1140,  1144,  1146,  1150,
    1156,  1158,  1162,  1168,  1170,  1174,  1180,  1182,  1186,  1192,
    1194,  1198,  1204,  1206,  1208,  1210,  1212,  1214,  1216,  1218,
    1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,  1236,  1238,
    1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,  1256,  1258,
    1260,  1262,  1264,  1266,  1268,  1270,  1272,  1274,  1276,  1279,
    1282,  1284,  1287,  1290,  1292,  1295,  1297,  1300,  1302,  1305,
    1307,  1310,  1314,  1318,  1322,  1325,  1330,  1335,  1340,  1343,
    1347,  1351,  1355,  1359,  1364,  1368,  1372,  1377,  1385,  1392,
    1398,  1399,  1408,  1409,  1418,  1419,  1428,  1429,  1438,  1442,
    1446,  1450,  1456,  1460,  1464,  1466,  1469,  1472,  1475,  1477,
    1480,  1482,  1485,  1487,  1490,  1492,  1495,  1497,  1500,  1502,
    1505,  1507,  1509,  1511,  1513,  1515,  1517,  1519,  1521,  1523,
    1525,  1527,  1530,  1533,  1536,  1539,  1542,  1545,  1548,  1551,
    1554,  1557,  1560,  1563,  1566,  1569,  1571,  1573,  1575,  1577,
    1579,  1581,  1583,  1585,  1587,  1591,  1592,  1593,  1594,  1595,
    1605,  1607,  1609,  1611,  1614,  1616,  1618,  1620,  1622,  1625,
    1629,  1632,  1635,  1637,  1640,  1642,  1645,  1649,  1652,  1656,
    1661,  1666,  1671,  1674,  1678,  1681,  1685,  1690,  1697,  1703,
    1705,  1708,  1712,  1714,  1716,  1721,  1726,  1731,  1736,  1740,
    1744,  1748,  1752,  1755,  1757,  1759,  1764,  1769,  1772,  1774,
    1776,  1778,  1779,  1785,  1786,  1793,  1802,  1811,  1815,  1819,
    1823,  1827,  1829,  1832,  1835,  1839,  1842,  1845,  1848,  1851,
    1853,  1855,  1857,  1860,  1865,  1868,  1873,  1877,  1880,  1882,
    1885,  1888,  1891,  1893,  1895,  1897,  1899,  1901,  1903,  1905,
    1907,  1910,  1915,  1918,  1923,  1927,  1930,  1932,  1935,  1938,
    1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     197,     0,    -1,    -1,   197,   198,    -1,    -1,   199,   193,
      -1,   200,    -1,     1,    -1,    -1,   201,   202,    -1,   200,
      40,   202,    -1,   207,    -1,    39,    -1,   203,    -1,   204,
      -1,   206,    -1,   205,    -1,   283,    -1,   408,    -1,   409,
      -1,   285,    39,    -1,   307,    39,    -1,   357,    39,    -1,
      47,    42,    -1,    77,    47,    42,    -1,    78,    47,    42,
      -1,   208,    -1,   214,    -1,   223,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    30,   202,    31,   209,   131,
     210,   202,   211,   132,   212,   220,   213,   222,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    30,   202,    31,   215,   131,
     216,   202,   217,   132,   218,   220,   219,   222,    -1,    -1,
      -1,    90,   221,   202,   132,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    68,    30,   285,    31,    32,   224,   231,   225,
     235,   226,   227,    33,    -1,    -1,    -1,    -1,    69,    30,
     202,    31,   228,    32,   237,   229,   242,   230,    33,    -1,
      -1,   232,   233,    -1,   231,   233,    -1,    -1,    91,   285,
     234,    42,   202,    -1,    -1,    -1,    93,    42,   236,   202,
      -1,    -1,   238,   239,    -1,   237,   239,    -1,    -1,    -1,
      92,   285,   240,    42,   241,   202,    -1,    -1,    -1,    94,
      42,   243,   202,    -1,    -1,   245,   248,    -1,    -1,   252,
     246,   258,    -1,   262,    -1,   268,    -1,   274,    -1,    -1,
     281,   247,    -1,    -1,    -1,    -1,    97,    30,   249,   202,
     250,    31,   251,   202,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   101,   254,   202,    97,   255,    30,   256,   202,   257,
      31,    -1,    -1,    -1,    -1,   143,    30,   259,   202,   260,
      31,   261,   202,    -1,    -1,    -1,    -1,    -1,    -1,   263,
     145,   264,   202,   143,   265,    30,   266,   202,   267,    31,
      -1,    -1,    -1,    -1,    -1,    -1,   269,   103,    30,   270,
     202,    39,   271,   202,    39,   272,   202,   273,    31,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   275,   202,
     276,   103,    30,   277,   202,    39,   278,   202,    39,   279,
     202,   280,    31,    -1,    -1,   105,   282,   202,    -1,    32,
     284,    33,    -1,   200,    -1,   200,   284,    -1,   286,    -1,
     287,    -1,   288,    -1,   289,    -1,   290,    -1,   291,    -1,
     292,    -1,   294,    -1,   295,    -1,    34,    -1,    30,   286,
      31,    -1,    35,    -1,     7,   287,    -1,   287,    27,   287,
      -1,   287,    28,   287,    -1,    30,   287,    31,    -1,    36,
      -1,   288,    14,   288,    -1,   288,    15,   288,    -1,   288,
      13,   288,    -1,   288,    12,   288,    -1,   288,    11,   288,
      -1,    15,   288,    -1,   288,    10,   288,    -1,   288,     9,
     288,    -1,     4,   288,    -1,   288,     4,    -1,     3,   288,
      -1,   288,     3,    -1,   288,     8,   288,    -1,   288,    25,
     288,    -1,   288,    26,   288,    -1,     6,   288,    -1,   288,
      17,   288,    -1,   288,    16,   288,    -1,    30,   288,    31,
      -1,    37,    -1,   289,    14,   289,    -1,   289,    15,   289,
      -1,   289,    13,   289,    -1,   289,    12,   289,    -1,   289,
      11,   289,    -1,   289,    10,   289,    -1,   289,     9,   289,
      -1,     4,   289,    -1,   289,     4,    -1,     3,   289,    -1,
     289,     3,    -1,    30,   289,    31,    -1,    38,    -1,   290,
      14,   290,    -1,    44,   290,    -1,    30,   290,    31,    -1,
      47,    -1,     8,   291,    -1,     7,   291,    -1,   291,    27,
     291,    -1,   291,    28,   291,    -1,   291,    14,   291,    -1,
     291,    15,   291,    -1,   291,    13,   291,    -1,   291,    12,
     291,    -1,   291,    11,   291,    -1,    15,   291,    -1,   291,
      10,   291,    -1,   291,     9,   291,    -1,     4,   291,    -1,
     291,     4,    -1,     3,   291,    -1,   291,     3,    -1,    30,
     291,    31,    -1,   288,    24,   288,    -1,   288,    23,   288,
      -1,   288,    22,   288,    -1,   288,    20,   288,    -1,   288,
      21,   288,    -1,    -1,   288,    19,   288,   293,    -1,   288,
      18,   288,    -1,    30,   294,    31,    -1,    47,    27,   287,
      -1,   287,    27,    47,    -1,    47,    28,   287,    -1,   287,
      28,    47,    -1,    47,    14,   288,    -1,    47,    15,   288,
      -1,    47,    13,   288,    -1,    47,    12,   288,    -1,    47,
      10,   288,    -1,    47,     9,   288,    -1,   288,    14,    47,
      -1,   288,    15,    47,    -1,   288,    13,    47,    -1,   288,
      12,    47,    -1,   288,    10,    47,    -1,   288,     9,    47,
      -1,    47,    14,   289,    -1,    47,    15,   289,    -1,    47,
      13,   289,    -1,    47,    12,   289,    -1,    47,    10,   289,
      -1,    47,     9,   289,    -1,   289,    14,    47,    -1,   289,
      15,    47,    -1,   289,    13,    47,    -1,   289,    12,    47,
      -1,   289,    10,    47,    -1,   289,     9,    47,    -1,    47,
      14,   290,    -1,   290,    14,    47,    -1,   288,    24,    47,
      -1,   288,    23,    47,    -1,   288,    22,    47,    -1,   288,
      20,    47,    -1,   288,    21,    47,    -1,   288,    19,    47,
      -1,    47,    24,   288,    -1,    47,    23,   288,    -1,    47,
      22,   288,    -1,    47,    20,   288,    -1,    47,    21,   288,
      -1,    47,    19,   288,    -1,    47,     8,   288,    -1,    47,
      25,   288,    -1,    47,    26,   288,    -1,   288,     8,    47,
      -1,   288,    25,    47,    -1,   288,    26,    47,    -1,     6,
      47,    -1,    47,    17,   288,    -1,    47,    16,   288,    -1,
     288,    17,    47,    -1,   288,    16,    47,    -1,   288,    18,
      47,    -1,    47,    18,   288,    -1,   296,    -1,    30,   295,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    42,
      36,   297,    30,   354,    31,    47,   298,    30,   299,   303,
     300,   301,    31,   302,   336,    -1,   304,    -1,   305,    -1,
     306,    -1,   305,    40,   306,    -1,   142,    42,    55,    -1,
     305,    40,   142,    42,    55,    -1,   285,    -1,   308,    -1,
     333,    -1,   312,    -1,   316,    -1,   317,    -1,   323,    -1,
     324,    -1,   325,    -1,   331,    -1,   332,    -1,    48,    47,
      -1,    48,    47,    29,   285,    -1,   104,    47,    -1,   309,
      -1,   310,    -1,   311,    -1,   118,    38,    38,    29,    38,
      -1,   123,   121,    38,    38,    29,    38,    -1,   123,   121,
      38,    38,    -1,   126,    38,   124,   288,   125,    -1,    -1,
      -1,   117,    47,    29,    32,   313,   315,   314,    33,    -1,
      38,    -1,   315,    40,    38,    -1,   120,   121,    38,    29,
      38,   122,   122,    38,    -1,    -1,   147,    47,   318,   319,
      -1,    32,   320,    33,    -1,   321,    -1,   320,   321,    -1,
      -1,   148,    47,   322,    39,    -1,   147,    47,    47,    -1,
     147,    47,    47,   122,    47,    29,   285,    -1,    -1,   149,
      47,   326,   327,    -1,    32,   328,    33,    -1,   329,    -1,
     328,   329,    -1,    -1,   150,    47,   330,    39,    -1,   149,
      47,    47,    -1,   149,    47,    47,   122,    47,    29,   285,
      -1,    77,    47,    -1,    78,    47,    -1,    96,    47,    -1,
     334,    -1,   348,    -1,    -1,   137,    30,   352,    31,    47,
      30,   337,    31,   335,   336,    -1,    -1,   341,    -1,   337,
      40,    48,    47,    42,    55,    -1,   342,    -1,   338,    40,
      48,    47,    42,    55,   343,    -1,   346,    -1,   339,    40,
      48,    47,    42,    55,    -1,   347,    -1,   340,    40,    48,
      47,    42,    55,    -1,    48,    47,    42,    55,    -1,    34,
      -1,    48,    47,    42,    55,   343,    -1,    34,    -1,    -1,
     344,    -1,    29,   285,    42,    36,    -1,    -1,   141,    -1,
      48,    47,    42,    55,    -1,    34,    -1,    48,    47,    42,
      55,    -1,    34,    -1,    -1,    -1,   136,   345,    30,   353,
      31,    47,    30,   338,    31,   349,   351,   350,   336,    -1,
      32,   284,    33,    -1,    34,    -1,    48,    42,    55,    -1,
     352,    40,    48,    42,    55,    -1,    34,    -1,    48,    42,
      55,    -1,   353,    40,    48,    42,    55,    -1,    34,    -1,
      48,    42,    55,    -1,   354,    40,    48,    42,    55,    -1,
      34,    -1,    48,    42,    55,    -1,   355,    40,    48,    42,
      55,    -1,    34,    -1,    48,    42,    55,    -1,   356,    40,
      48,    42,    55,    -1,   358,    -1,   359,    -1,   360,    -1,
     361,    -1,   362,    -1,   367,    -1,   368,    -1,   374,    -1,
     375,    -1,   376,    -1,   377,    -1,   378,    -1,   379,    -1,
     380,    -1,   381,    -1,   382,    -1,   383,    -1,   384,    -1,
     385,    -1,   386,    -1,   387,    -1,   388,    -1,   389,    -1,
     390,    -1,   391,    -1,   392,    -1,   393,    -1,   394,    -1,
     395,    -1,   396,    -1,   397,    -1,   404,    -1,   405,    -1,
     406,    -1,   407,    -1,    49,    -1,    49,   285,    -1,    49,
      81,    -1,    50,    -1,    50,   285,    -1,    50,    81,    -1,
      51,    -1,    51,   285,    -1,    52,    -1,    52,   285,    -1,
     113,    -1,   113,   285,    -1,   114,    -1,   114,   285,    -1,
      49,   126,    38,    -1,    56,    55,    47,    -1,   115,    55,
      47,    -1,    53,   288,    -1,    54,    38,    38,   290,    -1,
      57,    66,    58,   288,    -1,    57,    66,    58,    55,    -1,
      57,    58,    -1,    57,    58,   287,    -1,    57,    58,   288,
      -1,    57,    58,   289,    -1,    57,    58,   290,    -1,    57,
      66,    58,    47,    -1,    57,    79,   288,    -1,    57,   119,
      38,    -1,    57,   120,   121,    38,    -1,    57,   120,   121,
      38,   124,   288,   125,    -1,    57,   126,    38,   124,   288,
     125,    -1,    57,   126,    38,   124,   125,    -1,    -1,    57,
     403,    58,   288,    42,   287,   363,   336,    -1,    -1,    57,
     403,    58,   288,    42,   288,   364,   336,    -1,    -1,    57,
     403,    58,   288,    42,   289,   365,   336,    -1,    -1,    57,
     403,    58,   288,    42,   290,   366,   336,    -1,    57,   147,
      38,    -1,    57,   149,    38,    -1,   151,   152,    47,    -1,
      57,    66,    58,    55,   288,    -1,    59,    60,   288,    -1,
      59,    60,    47,    -1,    14,    -1,    14,   288,    -1,    14,
     289,    -1,    14,   290,    -1,    15,    -1,    43,   288,    -1,
      13,    -1,    13,   288,    -1,    12,    -1,    12,   288,    -1,
      11,    -1,    11,   288,    -1,    10,    -1,    10,   288,    -1,
       9,    -1,     9,   288,    -1,     4,    -1,     3,    -1,    27,
      -1,    28,    -1,     7,    -1,    24,    -1,    23,    -1,    22,
      -1,    20,    -1,    21,    -1,    19,    -1,    24,   287,    -1,
      23,   287,    -1,    24,   288,    -1,    23,   288,    -1,    22,
     288,    -1,    20,   288,    -1,    21,   288,    -1,    19,   288,
      -1,    24,   289,    -1,    23,   289,    -1,    22,   289,    -1,
      20,   289,    -1,    21,   289,    -1,    19,   289,    -1,     8,
      -1,    25,    -1,    26,    -1,     6,    -1,    17,    -1,    16,
      -1,   369,    -1,    18,    -1,    45,    -1,    46,   146,   290,
      -1,    -1,    -1,    -1,    -1,   202,    41,   370,   371,   202,
     372,    42,   373,   202,    -1,    61,    -1,    62,    -1,    63,
      -1,    65,    66,    -1,    67,    -1,   134,    -1,   135,    -1,
      68,    -1,    70,   290,    -1,    71,    72,   288,    -1,   153,
     288,    -1,   154,   288,    -1,    73,    -1,    74,    66,    -1,
      75,    -1,    76,   288,    -1,    76,    79,    47,    -1,    85,
      79,    -1,    86,    79,    47,    -1,    87,    79,    47,    47,
      -1,    86,   127,    79,   288,    -1,    88,    66,    58,   288,
      -1,    88,    58,    -1,    88,    66,    58,    -1,    88,   100,
      -1,    88,   119,    38,    -1,    88,   120,   121,    38,    -1,
      88,   126,    38,   124,   288,   125,    -1,    88,   126,    38,
     124,   125,    -1,    95,    -1,    95,    47,    -1,    98,    80,
      47,    -1,    99,    -1,   106,    -1,   107,    81,    55,   288,
      -1,   107,    81,    55,   287,    -1,   107,    81,    55,   289,
      -1,   107,    81,    55,   290,    -1,   107,    81,   288,    -1,
     108,    82,   290,    -1,   109,    83,    84,    -1,   110,    83,
     290,    -1,   111,    83,    -1,   112,    -1,   116,    -1,   128,
      38,    38,    38,    -1,   126,    38,   122,   129,    -1,   130,
      66,    -1,   139,    -1,   398,    -1,   400,    -1,    -1,   402,
      47,    55,   399,   336,    -1,    -1,   402,    47,    55,    55,
     401,   336,    -1,   140,    30,   355,    31,    47,    30,   339,
      31,    -1,   136,    30,   356,    31,    47,    30,   340,    31,
      -1,    30,   147,    31,    -1,    32,   147,    33,    -1,    30,
     149,    31,    -1,    32,   149,    33,    -1,   155,    -1,   156,
      14,    -1,   156,    15,    -1,   156,   157,   288,    -1,   156,
     155,    -1,   156,    62,    -1,   156,    63,    -1,   156,    64,
      -1,   158,    -1,   159,    -1,   160,    -1,   161,    38,    -1,
     161,   194,    38,   195,    -1,   162,    38,    -1,   162,   194,
      38,   195,    -1,   163,    38,    38,    -1,   164,    38,    -1,
     165,    -1,   166,    38,    -1,   167,    38,    -1,   168,    38,
      -1,   169,    -1,   170,    -1,   171,    -1,   172,    -1,   173,
      -1,   174,    -1,   175,    -1,   176,    -1,   177,    38,    -1,
     177,   194,    38,   195,    -1,   178,    38,    -1,   178,   194,
      38,   195,    -1,   179,    38,    38,    -1,   180,    38,    -1,
     181,    -1,   182,    38,    -1,   183,    38,    -1,   184,    38,
      -1,   185,    -1,   186,    -1,   187,    -1,   188,    -1,   189,
      -1,   190,    -1,   191,    -1,   192,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1001,  1001,  1002,  1005,  1005,  1010,  1011,  1014,  1014,
    1019,  1022,  1024,  1026,  1028,  1030,  1032,  1034,  1037,  1038,
    1041,  1048,  1055,  1062,  1095,  1103,  1113,  1119,  1125,  1130,
    1141,  1147,  1156,  1163,  1168,  1140,  1184,  1192,  1201,  1208,
    1213,  1183,  1228,  1229,  1228,  1250,  1254,  1293,  1322,  1327,
    1253,  1339,  1354,  1360,  1338,  1374,  1374,  1379,  1383,  1382,
    1426,  1427,  1426,  1437,  1437,  1442,  1446,  1477,  1445,  1492,
    1493,  1492,  1503,  1503,  1513,  1512,  1522,  1527,  1532,  1538,
    1537,  1557,  1567,  1573,  1556,  1594,  1604,  1611,  1619,  1625,
    1594,  1644,  1654,  1660,  1643,  1684,  1694,  1701,  1709,  1715,
    1684,  1735,  1739,  1749,  1757,  1767,  1735,  1787,  1800,  1809,
    1815,  1824,  1834,  1786,  1850,  1849,  1869,  1873,  1878,  1885,
    1886,  1894,  1896,  1898,  1900,  1902,  1904,  1906,  1911,  1921,
    1924,  1940,  1954,  1970,  1986,  1989,  2003,  2009,  2015,  2021,
    2027,  2033,  2041,  2048,  2055,  2061,  2067,  2073,  2079,  2087,
    2096,  2104,  2111,  2119,  2127,  2131,  2144,  2151,  2158,  2165,
    2171,  2178,  2185,  2192,  2198,  2204,  2210,  2216,  2220,  2233,
    2258,  2265,  2269,  2340,  2380,  2417,  2494,  2573,  2653,  2691,
    2729,  2767,  2805,  2818,  2856,  2894,  2922,  2950,  2978,  3006,
    3009,  3020,  3031,  3042,  3053,  3065,  3064,  3084,  3110,  3111,
    3160,  3209,  3258,  3307,  3349,  3391,  3433,  3475,  3517,  3559,
    3601,  3643,  3685,  3727,  3769,  3811,  3853,  3895,  3937,  3979,
    4021,  4063,  4105,  4147,  4189,  4231,  4273,  4315,  4379,  4443,
    4488,  4533,  4578,  4623,  4668,  4713,  4758,  4803,  4848,  4893,
    4938,  4983,  5028,  5073,  5118,  5163,  5208,  5253,  5290,  5335,
    5380,  5425,  5470,  5528,  5588,  5592,  5599,  5603,  5610,  5615,
    5634,  5644,  5598,  5659,  5666,  5677,  5720,  5763,  5889,  6034,
    6169,  6174,  6179,  6184,  6189,  6194,  6199,  6204,  6209,  6214,
    6221,  6279,  6360,  6395,  6400,  6405,  6412,  6424,  6439,  6455,
    6467,  6475,  6466,  6489,  6497,  6503,  6529,  6528,  6535,  6543,
    6544,  6548,  6547,  6554,  6561,  6608,  6607,  6614,  6622,  6623,
    6627,  6626,  6633,  6640,  6686,  6710,  6733,  6757,  6758,  6762,
    6761,  6807,  6809,  6902,  7014,  7116,  7232,  7277,  7336,  7381,
    7440,  7458,  7466,  7484,  7492,  7492,  7506,  7513,  7513,  7520,
    7538,  7546,  7564,  7573,  7591,  7572,  7611,  7616,  7624,  7710,
    7792,  7796,  7844,  7894,  7897,  7959,  8166,  8170,  8218,  8268,
    8272,  8320,  8372,  8377,  8382,  8387,  8392,  8397,  8402,  8407,
    8412,  8417,  8422,  8427,  8432,  8437,  8442,  8447,  8452,  8457,
    8462,  8467,  8472,  8477,  8482,  8487,  8492,  8497,  8502,  8507,
    8512,  8517,  8522,  8523,  8524,  8525,  8526,  8530,  8536,  8582,
    8593,  8599,  8645,  8656,  8662,  8708,  8714,  8760,  8765,  8811,
    8817,  8863,  8875,  8934,  9007,  9015,  9024,  9168,  9261,  9289,
    9300,  9317,  9329,  9341,  9523,  9542,  9556,  9569,  9583,  9593,
    9604,  9603,  9637,  9636,  9670,  9669,  9703,  9702,  9735,  9760,
    9785,  9798,  9848,  9868,  9973,  9979,  9985,  9991,  9997, 10003,
   10009, 10015, 10021, 10027, 10033, 10039, 10045, 10051, 10057, 10063,
   10069, 10075, 10081, 10087, 10093, 10099, 10105, 10111, 10117, 10123,
   10129, 10135, 10145, 10155, 10161, 10167, 10173, 10179, 10185, 10191,
   10197, 10203, 10209, 10215, 10221, 10227, 10233, 10239, 10245, 10251,
   10257, 10263, 10264, 10268, 10274, 10297, 10308, 10314, 10323, 10296,
   10343, 10351, 10357, 10365, 10378, 10384, 10388, 10392, 10400, 10408,
   10423, 10432, 10442, 10450, 10465, 10471, 10477, 10608, 10642, 10761,
   10985, 11006, 11043, 11052, 11089, 11097, 11111, 11124, 11134, 11146,
   11164, 11192, 11270, 11280, 11299, 11362, 11413, 11464, 11515, 11534,
   11556, 11589, 11606, 11623, 11633, 11643, 11654, 11664, 11683, 11689,
   11690, 11694, 11693, 11748, 11747, 11804, 11810, 11816, 11820, 11826,
   11830, 11836, 11842, 11846, 11850, 11863, 11867, 11871, 11875, 11881,
   11887, 11893, 11901, 11907, 11913, 11919, 11925, 11932, 11938, 11944,
   11950, 11956, 11962, 11968, 11974, 11980, 11986, 11992, 11998, 12004,
   12010, 12016, 12022, 12028, 12034, 12041, 12047, 12053, 12059, 12065,
   12071, 12077, 12083, 12089, 12095, 12101, 12107, 12113
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPDEC", "OPINC", "NEG", "OPBTNOT",
  "OPNOT", "OPAMP", "OPROOT", "OPPOWER", "OPMODULUS", "OPDIV", "OPTIMES",
  "OPPLUS", "OPMINUS", "OPBTSR", "OPBTSL", "OPCMP", "OPGEQU", "OPGTR",
  "OPLEQU", "OPLSS", "OPNEQU", "OPEQU", "OPBTOR", "OPBTXOR", "OPAND",
  "OPOR", "OPEQUAL", "LEFTP", "RIGHTP", "LEFTB", "RIGHTB", "VOIDV",
  "BOOLEANV", "NUMBERV", "CHARACTERV", "STRINGV", "SEND", "COMMA",
  "OPQUES", "OPCOLON", "OPSUB", "OPSTR", "OPSTRTIMES", "OPRUN", "ID",
  "VAR", "PRINT", "PRINTLN", "EPRINT", "EPRINTLN", "END", "ASM", "TYPE",
  "READ", "LOAD", "LTYPE", "GOTO", "GTYPE", "ST", "PUSH", "POP", "TOP",
  "TYPEOF", "RTYPE", "ATOC", "SWITCH", "CSWITCH", "CRASH", "VERSION",
  "VTYPE", "HALT", "MODT", "RETURN", "GOSUB", "SUB", "EVENT", "STYPE",
  "ATYPE", "CTYPE", "CMTYPE", "BFMODEC", "FMODEC", "UNREGISTER",
  "REGISTER", "REREGISTER", "STORE", "IF", "ELSE", "CASE", "CCASE",
  "DEFAULT", "CDEFAULT", "BREAK", "LABEL", "WHILE", "ADDRESSOF", "ADD2V",
  "STOREA", "DOWHILE", "DOFOR", "FOR", "FVAR", "FOREVER", "CONTINUE",
  "CHECK", "HCMNT", "FMODE", "FOPEN", "FCLOSE", "FEOF", "FPRINT",
  "FPRINTLN", "FREAD", "MEML", "ENUM", "ENUMV", "VTYPE2", "RANGE",
  "RTYPE2", "OPDOT", "RANGEV", "OPLSQ", "OPRSQ", "ARRAY", "BLANK",
  "PNFASM", "LENGTH", "DUP", "THEN", "ENDIF", "DONEIF", "ATOSP", "SPTOA",
  "FUNCTION", "FUNCDEF", "FUNCCALL", "FRET", "FPARAMETER", "DEFAULTV",
  "DEFAULTV2", "UNTIL", "UNLESS", "DOUNTIL", "RUNOPOP", "STRUCT",
  "STRUCTVAR", "UNION", "UNIONVAR", "USE", "OTYPE", "MODE", "EXTMODE",
  "COPY", "SEGMENT", "CETYPE", "PBIN", "PPBIN", "PLIB", "PINCLUDE",
  "PIMPORT", "PDEFINE", "PMACRO", "PENDM", "PUNDEF", "PIFDEF", "PIFNDEF",
  "PELSE", "PENDIF", "PPDATE", "PPTIME", "PPLINE", "PPFILE", "PPCDATE",
  "PPCTIME", "PPINCLUDE", "PPIMPORT", "PPDEFINE", "PPMACRO", "PPENDM",
  "PPUNDEF", "PPIFDEF", "PPIFNDEF", "PPELSE", "PPENDIF", "PPPDATE",
  "PPPTIME", "PPPLINE", "PPPFILE", "PPPCDATE", "PPPCTIME", "\"\\n\"",
  "\"<\"", "\">\"", "$accept", "input", "line", "$@1", "statement", "$@2",
  "stmt", "expression_statement", "declaration_statement",
  "command_statement", "label_statement", "control_statement",
  "if_statement", "$@3", "$@4", "$@5", "$@6", "$@7", "unless_statement",
  "$@8", "$@9", "$@10", "$@11", "$@12", "opt_else", "$@13", "eif",
  "switch_statement", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19",
  "$@20", "case_statements", "$@21", "case_statement", "$@22",
  "opt_default_statement", "$@23", "case_statements2", "$@24",
  "case_statement2", "$@25", "$@26", "opt_default_statement2", "$@27",
  "loop_statement", "$@28", "$@29", "$@30", "while_loop", "$@31", "$@32",
  "$@33", "whileb_loop", "$@34", "$@35", "$@36", "$@37", "$@38",
  "until_loop", "$@39", "$@40", "$@41", "untilb_loop", "$@42", "$@43",
  "$@44", "$@45", "$@46", "for_loop", "$@47", "$@48", "$@49", "$@50",
  "$@51", "forb_loop", "$@52", "$@53", "$@54", "$@55", "$@56", "$@57",
  "forever_loop", "$@58", "statement_block", "statements", "expression",
  "void_expression", "boolean_expression", "number_expression",
  "character_expression", "string_expression", "id_expression",
  "relational_expression", "@59", "mixed_expression",
  "function_expression", "function_command", "$@60", "$@61", "$@62",
  "$@63", "$@64", "$@65", "actual_function_parameters", "dv",
  "opt_expressions", "opt_expression", "declaration",
  "variable_declaration", "enumv_declaration", "rangev_declaration",
  "array_declaration", "enum_declaration", "$@67", "$@68", "enum_strings",
  "range_declaration", "struct_declaration", "$@69", "struct_body",
  "struct_var_declarations", "struct_var_declarations2", "$@70",
  "struct_declaration2", "struct_var_declaration3", "union_declaration",
  "$@71", "union_body", "union_var_declarations",
  "union_var_declarations2", "$@72", "union_declaration2",
  "union_var_declaration3", "label_declaration", "function_declaration",
  "$@73", "nothing", "parameter_declaration", "parameter_declaration2",
  "parameter_declaration5", "parameter_declaration6", "opt_var",
  "opt_var2", "opt_default_value", "dvalue", "optdefaultv", "opt_var5",
  "opt_var6", "function_declaration2", "$@74", "$@75", "function_body",
  "vars", "vars2", "vars3", "vars5", "vars6", "command", "print_command",
  "read_command", "end_command", "asm_command", "load_command", "$@76",
  "$@77", "$@78", "$@79", "goto_command", "operator_command",
  "top_command", "$@80", "$@81", "$@82", "$@83", "st_command",
  "stack_command", "typeof_command", "rm_command", "crash_command",
  "version_command", "halt_command", "modt_command", "subroutine_command",
  "register_command", "store_command", "break_command", "address_command",
  "add2v_command", "continue_command", "check_command", "comment_command",
  "file_command", "meml_command", "pnfasm_command", "array_length_command",
  "dup_command", "fret_command", "parameter_command", "psig", "$@84",
  "psig2", "$@85", "signature", "signature2", "struct_command",
  "union_command", "copy_command", "segment_command", "pp_directive",
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   196,   197,   197,   199,   198,   198,   198,   201,   200,
     200,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     203,   204,   205,   206,   206,   206,   207,   207,   207,   207,
     209,   210,   211,   212,   213,   208,   215,   216,   217,   218,
     219,   214,   220,   221,   220,   222,   224,   225,   226,   227,
     223,   228,   229,   230,   223,   232,   231,   231,   234,   233,
     235,   236,   235,   238,   237,   237,   240,   241,   239,   242,
     243,   242,   245,   244,   246,   244,   244,   244,   244,   247,
     244,   249,   250,   251,   248,   253,   254,   255,   256,   257,
     252,   259,   260,   261,   258,   263,   264,   265,   266,   267,
     262,   269,   270,   271,   272,   273,   268,   275,   276,   277,
     278,   279,   280,   274,   282,   281,   283,   284,   284,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   286,   286,
     287,   287,   287,   287,   287,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   290,   290,
     290,   290,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     292,   292,   292,   292,   292,   293,   292,   292,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   295,   295,   297,   298,   299,   300,
     301,   302,   296,   303,   304,   305,   305,   305,   305,   306,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     308,   308,   308,   308,   308,   308,   309,   310,   310,   311,
     313,   314,   312,   315,   315,   316,   318,   317,   319,   320,
     320,   322,   321,   323,   324,   326,   325,   327,   328,   328,
     330,   329,   331,   332,   333,   333,   333,   333,   333,   335,
     334,   336,   337,   337,   338,   338,   339,   339,   340,   340,
     341,   341,   342,   342,   343,   343,   344,   345,   345,   346,
     346,   347,   347,   349,   350,   348,   351,   352,   352,   352,
     353,   353,   353,   354,   354,   354,   355,   355,   355,   356,
     356,   356,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   359,   359,   360,   361,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     363,   362,   364,   362,   365,   362,   366,   362,   362,   362,
     362,   362,   367,   367,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   370,   371,   372,   373,   369,
     374,   375,   375,   376,   377,   377,   377,   377,   378,   379,
     379,   379,   380,   381,   382,   382,   382,   383,   383,   383,
     383,   384,   384,   384,   384,   384,   384,   384,   384,   385,
     385,   386,   387,   388,   389,   389,   389,   389,   389,   390,
     391,   391,   391,   391,   392,   393,   394,   395,   396,   397,
     397,   399,   398,   401,   400,   402,   403,   404,   404,   405,
     405,   406,   407,   407,   407,   407,   407,   407,   407,   408,
     408,   408,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     3,     1,     1,     1,     1,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,    14,     0,     0,     4,     1,     0,     0,     0,     0,
      12,     0,     0,     0,    11,     0,     2,     2,     0,     5,
       0,     0,     4,     0,     2,     2,     0,     0,     6,     0,
       0,     4,     0,     2,     0,     3,     1,     1,     1,     0,
       2,     0,     0,     0,     8,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     8,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,    16,     0,     3,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     2,     2,     2,     2,     3,     3,
       3,     2,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     3,     1,     3,
       2,     3,     1,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     0,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     1,     3,     0,     0,     0,     0,
       0,     0,    17,     1,     1,     1,     3,     3,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     2,     1,     1,     1,     5,     6,     4,     5,
       0,     0,     8,     1,     3,     8,     0,     4,     3,     1,
       2,     0,     4,     3,     7,     0,     4,     3,     1,     2,
       0,     4,     3,     7,     2,     2,     2,     1,     1,     0,
      10,     0,     1,     6,     1,     7,     1,     6,     1,     6,
       4,     1,     5,     1,     0,     1,     4,     0,     1,     4,
       1,     4,     1,     0,     0,    13,     3,     1,     3,     5,
       1,     3,     5,     1,     3,     5,     1,     3,     5,     1,
       3,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     3,     3,     3,     2,     4,     4,     4,     2,     3,
       3,     3,     3,     4,     3,     3,     4,     7,     6,     5,
       0,     8,     0,     8,     0,     8,     0,     8,     3,     3,
       3,     5,     3,     3,     1,     2,     2,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     0,     0,     0,     9,
       1,     1,     1,     2,     1,     1,     1,     1,     2,     3,
       2,     2,     1,     2,     1,     2,     3,     2,     3,     4,
       4,     4,     2,     3,     2,     3,     4,     6,     5,     1,
       2,     3,     1,     1,     4,     4,     4,     4,     3,     3,
       3,     3,     2,     1,     1,     4,     4,     2,     1,     1,
       1,     0,     5,     0,     6,     8,     8,     3,     3,     3,
       3,     1,     2,     2,     3,     2,     2,     2,     2,     1,
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
       2,     0,     1,     7,     3,     0,     6,    72,     5,    72,
     461,   460,   488,   464,   485,   458,   456,   454,   452,   450,
     444,   448,   490,   489,   492,   470,   468,   469,   467,   466,
     465,   486,   487,   462,   463,     0,     8,   128,   130,   135,
     155,   168,    12,     0,     0,   493,     0,   172,     0,   397,
     400,   403,   405,     0,     0,     0,     0,     0,   500,   501,
     502,     0,   504,   507,     0,     0,     0,   512,     0,   514,
       0,     0,     0,     0,     0,     0,     0,     0,   529,     0,
       0,   532,   107,     0,   114,   533,     0,     0,     0,     0,
       0,   543,   407,   409,     0,   544,     0,     0,     0,     0,
       0,     0,     0,   505,   506,   337,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,   561,     0,   569,   570,
     571,     0,     0,     0,     0,   578,     0,     0,     0,   582,
     583,   584,   585,   586,   587,   588,   589,     0,     0,     0,
       0,   596,     0,     0,     0,   600,   601,   602,   603,   604,
     605,   606,   607,     9,    13,    14,    16,    15,    11,    26,
      27,    28,    29,     0,    74,     0,    76,     0,    77,     0,
      78,    79,    17,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   254,     0,   270,   283,   284,   285,   272,
     273,   274,   275,   276,   277,   278,   279,   271,   317,   318,
       0,   362,   363,   364,   365,   366,   367,   368,   491,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   549,   550,     0,   393,   394,   395,   396,
      18,    19,    10,     0,     0,     0,     0,     0,     0,     0,
     172,   146,   165,   187,   144,   163,   185,     0,     0,     0,
       0,   247,   151,     0,     0,     0,     0,     0,   131,   174,
       0,   173,   459,   457,   455,   453,   451,     0,     0,     0,
     445,   446,   447,     0,     0,     0,   141,   182,     0,   478,
     484,   476,   482,   477,   483,   475,   481,     0,     0,   472,
     474,   480,   471,   473,   479,     0,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,   449,     0,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,   280,   399,     0,
     398,   402,   401,   404,   406,   414,     0,     0,   418,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   503,
       0,    72,   508,     0,   513,     0,   515,   314,   315,   517,
       0,     0,     0,   522,     0,   524,     0,     0,     0,    72,
     530,   316,     0,    72,   282,    72,     0,     0,     0,     0,
     542,   408,   410,     0,     0,     0,     0,     0,     0,     0,
     547,   338,     0,     0,     0,     0,    72,   296,   305,     0,
     510,   511,   562,   563,   566,   567,   568,   565,     0,   572,
       0,   574,     0,     0,   577,   579,   580,   581,   590,     0,
     592,     0,     0,   595,   597,   598,   599,   495,     0,    73,
       0,    86,    96,     0,    80,    20,     0,     0,   147,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
     164,     0,     0,     0,     0,     0,     0,     0,     0,   188,
     186,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   557,   559,
     129,   134,     0,     0,     0,     0,     0,     0,     0,   154,
     167,   171,   189,   198,   255,   558,   560,   118,   116,   494,
     241,   208,   220,   207,   219,   206,   218,   205,   217,   203,
     215,   227,   204,   216,   249,   248,   253,   240,   238,   239,
     237,   236,   235,   242,   243,   199,   201,     0,   411,     0,
     412,     0,   419,   420,   421,   422,     0,   424,   425,     0,
       0,     0,   438,   439,     0,   443,   442,     0,     0,   509,
     516,    24,    25,   518,     0,     0,   523,   525,     0,     0,
       0,   531,   108,   115,     0,   538,   539,   540,   541,   413,
       0,     0,     0,     0,     0,     0,     0,     0,   347,     0,
       0,   256,   356,     0,     0,     0,   303,     0,   312,     0,
     440,   564,     0,     0,   576,     0,     0,   594,   496,    81,
       0,    75,    72,    72,   102,   200,   132,   202,   133,   244,
     148,   214,   143,   213,   142,   140,   212,   139,   211,   138,
     209,   136,   210,   137,   251,   153,   250,   152,   252,   197,
     234,   195,   232,   193,   233,   194,   231,   192,   230,   191,
     229,   190,   245,   149,   246,   150,     0,     0,     0,   226,
     162,   225,   161,   160,   224,   159,   223,   158,   221,   156,
     222,   157,   228,   169,   184,   183,   181,   180,   179,   177,
     178,   175,   176,   551,   281,   415,   423,   417,   416,   426,
       0,   359,     0,     0,     0,     0,    51,   520,   519,   521,
     526,     0,    30,     0,   535,   534,   536,   537,   290,     0,
       0,   288,   546,     0,   545,   350,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,     0,   297,     0,
       0,   306,   573,   575,   591,   593,    72,    72,    91,     0,
       0,    72,   196,   553,   321,   441,     0,   429,     0,     0,
       0,     0,     0,    46,     0,   528,     0,     0,     0,     0,
     286,     0,     0,   289,     0,     0,     0,   348,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,   299,     0,
       0,     0,   308,   497,    82,    72,    87,    97,     0,   321,
     552,     0,   428,   360,     0,     0,   430,   432,   434,   436,
      55,    63,   527,    31,   109,   293,   291,     0,   287,   351,
       0,     0,     0,     0,   353,     0,     0,     0,     0,    37,
       0,   301,   298,   300,     0,   310,   307,   309,     0,     0,
      92,     0,     0,   103,   554,   427,     0,     0,   321,   321,
     321,   321,    47,     0,    52,     0,    72,    72,     0,     0,
       0,     0,     0,   331,     0,     0,   322,   349,     0,     0,
       0,   340,     0,     0,   326,   358,    72,   304,     0,   313,
       0,   498,    83,     0,    88,    98,    72,   342,     0,     0,
     328,   361,   431,   433,   435,   437,     0,    60,    57,    56,
       0,    69,    65,    64,    32,     0,   294,   292,   295,   333,
       0,     0,   324,   352,     0,   319,     0,   354,   257,     0,
       0,   555,     0,    38,   302,   311,    72,    72,    93,    72,
      72,     0,     0,   556,     0,    58,     0,    48,    66,     0,
      53,     0,   110,     0,   343,     0,     0,   321,     0,     0,
       0,     0,     0,     0,   499,    84,    72,    89,    99,   104,
       0,     0,     0,    61,    49,     0,    70,     0,    33,    72,
       0,     0,     0,   330,   320,     0,   258,   355,   339,     0,
      39,    94,     0,     0,    72,   341,     0,    72,    72,     0,
      67,    72,    54,    42,     0,   334,     8,   344,     0,     0,
       0,     0,    42,    90,   100,   105,     0,    59,    62,    50,
      72,    71,    43,    34,   111,     0,   332,   335,     0,   321,
       0,   323,     0,   269,   259,   263,   264,   265,   327,    40,
       0,   329,    68,    72,     0,    72,     0,   346,   345,   334,
       0,   260,     0,     0,    72,     0,    45,    35,   112,     0,
     325,   267,     0,     0,   266,    41,   106,    44,     0,   336,
     261,     0,   113,   321,   268,   262
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,   320,     7,   153,   154,   155,   156,
     157,   158,   159,   797,   886,   971,  1023,  1064,   160,   814,
     906,   983,  1032,  1073,  1043,  1063,  1077,   161,   840,   927,
     994,  1019,   794,   931,   997,   882,   883,   928,   992,   967,
    1018,   884,   885,   932,   995,  1040,   970,  1021,   162,   163,
     450,   454,   449,   777,   869,   957,   164,   165,   652,   871,
     959,  1012,   651,   825,   913,   986,   166,   167,   653,   872,
     960,  1013,   168,   169,   781,   916,  1014,  1060,   170,   393,
     743,   887,   999,  1065,  1088,   171,   395,   172,   321,   173,
     174,   175,   176,   177,   178,   179,   180,   782,   181,   182,
     183,   761,   979,  1030,  1071,  1082,  1093,  1054,  1055,  1056,
    1057,   184,   185,   186,   187,   188,   189,   799,   889,   846,
     190,   191,   637,   768,   817,   818,   908,   192,   193,   194,
     639,   771,   821,   822,   910,   195,   196,   197,   198,   977,
     830,   895,   941,   903,   919,   896,   942,  1046,  1047,   412,
     904,   920,   199,  1001,  1049,  1027,   630,   757,   856,   634,
     733,   200,   201,   202,   203,   204,   205,   878,   879,   880,
     881,   206,   207,   208,   648,   776,   868,   956,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   784,   234,   829,   235,   367,   236,   237,
     238,   239,   240,   241
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -801
static const yytype_int16 yypact[] =
{
    -801,  1070,  -801,  -801,  -801,  -120,    55,  1261,  -801,  1261,
     486,   486,   264,   702,   345,   567,   567,   567,   567,   567,
    1599,   531,  -801,  -801,  -801,  1627,  1627,  1627,  1627,  1693,
    1693,  -801,  -801,  -801,  -801,    52,     5,  -801,  -801,  -801,
    -801,  -801,  -801,   567,   164,  -801,   -30,  1667,    75,   410,
     592,   176,   176,   567,   110,    98,   169,   116,  -801,  -801,
    -801,   115,  -801,   162,   166,   164,   131,  -801,   155,  -801,
     201,   178,   227,   172,   -35,   208,    25,   267,   255,   260,
     265,  -801,  -801,   310,  -801,  -801,   291,   297,   300,   302,
     307,  -801,   176,   176,   338,  -801,   356,   367,   287,   290,
     386,   395,   373,  -801,  -801,   308,   411,   413,  -801,   422,
     426,   430,   431,   327,   567,   567,  -801,    38,  -801,  -801,
    -801,   -26,   -16,   442,   445,  -801,   446,   447,   448,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,    -8,    -7,   458,
     459,  -801,   461,   462,   464,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,   474,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,   420,  -801,   419,  -801,   379,  -801,   424,
    -801,  -801,  -801,   487,  -801,    15,  1808,  1609,   514,   643,
    -801,  -801,  -801,  -801,   490,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
     493,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,   494,  -801,  -801,  -801,  -801,
    -801,  -801,   474,   486,   486,   567,   345,   345,   531,   486,
    -801,  1872,   576,  1036,  1872,   576,  1036,   567,   567,   567,
     567,  -801,  1872,   345,   345,   702,   345,   702,   346,  1036,
     345,  1036,  1832,  1832,  1832,  1832,  1832,  1627,  1627,  1599,
    1832,  1656,   526,   531,   531,   531,  1872,  1036,  1627,  1832,
    1656,  1832,  1656,  1832,  1656,  1832,  1656,    42,  1693,   346,
    1832,  1656,   346,  1832,  1656,   264,   176,  1851,   512,   516,
     518,   392,  1723,  1771,    62,   832,   520,   522,   521,   524,
      87,   527,  1832,   164,   526,   164,   567,  1627,  1627,  1627,
    1627,  1599,  1627,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,    42,    42,  -801,   534,  -801,   530,
    -801,  -801,  -801,  -801,  -801,  1832,   536,   517,  1571,   507,
     567,   537,   451,   538,   539,   543,   563,   525,   406,  -801,
     176,  1261,   526,   567,  -801,   558,  1832,   564,   566,  -801,
     562,   532,   570,  -801,   552,  -801,   575,   498,   583,  1261,
    -801,  -801,   577,  1261,  -801,  1261,   230,   164,   541,   164,
    -801,  -801,  -801,   584,   603,   595,   596,   597,   149,   599,
    -801,  -801,   608,     6,   604,    13,  1261,   594,   598,   615,
    1832,  1832,  -801,  -801,  -801,  -801,  -801,  -801,   567,  -801,
     613,  -801,   625,   627,  -801,  -801,  -801,  -801,  -801,   628,
    -801,   629,   630,  -801,  -801,  -801,  -801,  -801,   612,  -801,
     529,  -801,  -801,   646,  -801,  -801,    27,    68,  -801,  -801,
     771,   834,   919,   567,   956,   966,   985,  1451,  1455,  1459,
    1469,  1473,  1504,  1508,  1518,  1522,  1526,  1557,  1564,  -801,
    -801,    67,   185,    81,   317,   385,   484,   515,   268,  -801,
    -801,   345,   345,   345,   345,   345,   345,   345,   345,   345,
    -801,  -801,   623,  1747,  1784,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,    81,    81,    81,    81,
      81,    81,   400,    42,    42,    93,   164,    42,  -801,  -801,
    -801,  -801,   642,   644,   645,   647,   648,   657,   661,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   526,
    1832,  1832,  1656,  1832,  1656,  1832,  1656,  1832,  1656,  1832,
    1656,   526,  1832,  1656,  1832,  1832,  1832,  1832,  1832,  1832,
    1832,  1832,  1832,  1832,  1832,   346,   346,   176,  -801,   164,
    -801,  1571,   346,  1832,  1656,   526,   340,  1832,  -801,   652,
     569,    16,  -801,  -801,   567,  -801,  1832,   680,   144,  1832,
    -801,  -801,  -801,  -801,   567,   666,   567,  -801,   676,   591,
     187,  -801,   474,   474,  1571,  1832,   526,  -801,   526,  -801,
     684,   690,   691,   683,   593,   567,   685,    95,  -801,   682,
     129,  -801,  -801,   689,   186,   188,   605,   694,   611,   703,
    -801,  1832,   546,   547,  -801,   548,   549,  -801,  -801,  -801,
     704,  -801,  1261,  1261,  -801,  -801,   708,  -801,  -801,  -801,
    1890,  -801,  1890,  -801,  1890,   806,  -801,   806,  -801,   806,
    -801,   352,  -801,   352,  -801,    40,  -801,    40,  -801,  1832,
    -801,  1832,  -801,  1832,  -801,  1832,  -801,  1832,  -801,  1832,
    -801,  1832,  -801,  -801,  -801,  -801,    81,    81,    81,  -801,
     576,  -801,   576,   295,  -801,   295,  -801,   295,  -801,  -801,
    -801,  -801,  -801,  -801,  1036,  1036,   423,   423,   423,   402,
     402,   710,  -801,   695,  -801,   526,  -801,   567,  1832,   616,
      33,  -801,   720,   222,  1636,   714,  -801,  1832,  -801,  1832,
    -801,   194,  -801,   660,   346,  1832,  1656,   526,  -801,   726,
     727,   737,  -801,   671,  -801,  -801,   729,   259,   718,   731,
     728,   749,   725,   734,   735,  -801,   738,   634,  -801,   740,
     649,  -801,  -801,  -801,  -801,  -801,  1261,  1261,  -801,    -3,
     -20,  1261,  -801,  -801,  -801,  1832,   567,  -801,   744,   742,
     748,   754,  1571,  -801,   772,  -801,   901,   672,   775,   768,
    -801,   692,   781,  -801,   769,   778,   779,  -801,   796,   792,
     107,  -801,   809,   808,   717,   833,   814,    -1,  -801,   836,
     819,   -22,  -801,   474,   474,  1261,  -801,  -801,    80,  -801,
    -801,   928,  -801,  -801,   837,   826,   346,  1832,  1656,   526,
    -801,  -801,  -801,  -801,  -801,  -801,   831,   750,  -801,  -801,
     843,   838,   122,   820,  -801,   840,   261,   125,   821,  -801,
     176,  -801,  -801,  -801,   176,  -801,  -801,  -801,   842,   854,
     474,   844,   856,  -801,  -801,  -801,   204,   839,  -801,  -801,
    -801,  -801,   802,   802,   803,   803,  1261,  1261,   858,   865,
     861,   216,   845,  -801,   855,   277,  -801,  -801,   846,   859,
     860,  -801,   872,   282,  -801,  -801,  1261,  -801,   864,  -801,
     881,  -801,  -801,   890,  -801,  -801,  1261,  -801,   877,   311,
    -801,  -801,  -801,  -801,  -801,  -801,   176,   835,  -801,  -801,
     176,   841,  -801,  -801,   474,   220,  -801,  -801,  -801,  -801,
     883,   319,  -801,  -801,   891,  -801,   898,  -801,  -801,   914,
     915,  -801,   910,   474,  -801,  -801,  1261,  1261,  -801,  1261,
    1261,   322,   921,  -801,   913,  -801,   922,  -801,  -801,   923,
    -801,   847,  -801,   925,  -801,   920,   918,  -801,   927,   945,
     929,   932,   931,   848,   474,   474,  1261,   474,   474,  -801,
     938,   935,   934,  -801,  -801,   952,  -801,   962,  -801,  1261,
     942,   967,   954,  -801,  -801,   964,  -801,  -801,  -801,   965,
    -801,   474,   973,   979,  1261,  -801,   972,  1261,  1261,   983,
    -801,  1261,  -801,   930,   326,   988,  -801,  -801,   976,   968,
     102,   969,   930,  -801,  -801,   474,   974,   474,   474,  -801,
    1261,   474,  -801,  -801,  -801,   176,  -801,  -801,   986,  -801,
     975,  -801,   980,  -801,  -801,  -801,   987,  -801,  -801,  -801,
     997,  -801,   474,  1261,   900,  1261,   992,  -801,  -801,   988,
    1000,  -801,   127,   900,  1261,    -6,  -801,  -801,   474,   999,
    -801,  -801,  1021,  1015,  -801,  -801,   474,  -801,  1027,  -801,
    -801,  1004,  -801,  -801,  -801,  -801
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -801,  -801,  -801,  -801,  1059,  -801,    -9,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,    29,  -801,   -11,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,   183,  -801,  -801,
    -801,  -801,  -801,   190,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -314,   -47,
     -34,   137,    -2,   371,   219,   545,  -801,  -801,   -28,   -15,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
       0,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,   284,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,   278,  -801,  -801,  -801,  -801,  -801,  -801,
    -800,  -801,  -801,  -801,  -801,  -801,  -801,    34,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -118
static const yytype_int16 yytable[] =
{
     242,   310,   350,   352,   353,   354,   547,   316,   251,   254,
     262,   866,   429,   272,   273,   274,   275,   276,   280,   286,
     317,   447,   431,   289,   291,   293,   295,   300,   303,   874,
     438,   440,   862,   312,   297,   447,   257,   258,   447,   245,
     628,   322,   456,   457,   380,   401,   402,   632,   259,   297,
     731,   355,   422,   423,   629,   243,   244,   527,   305,   265,
     247,   633,    38,   260,   732,   514,   515,   248,   376,    39,
     696,   697,   527,     8,   655,   297,   488,    38,   922,   923,
     924,   925,   306,   383,   696,   697,    37,    38,    39,    40,
      41,   384,   381,   541,   826,     9,    44,   698,   527,   307,
     424,   425,   426,    38,    40,   243,   244,   526,   305,   265,
     247,   698,   420,   421,   699,   657,   325,   248,    40,   873,
    -117,   447,   347,   827,   541,   385,  1087,     9,   820,   755,
     243,   244,   306,   305,   265,   247,    37,    38,    39,    40,
      41,   854,   248,   756,   386,   387,    44,   816,   356,   307,
     268,   388,   318,   357,   319,   855,   893,   306,   787,   901,
     759,    37,    38,    39,    40,    41,   299,   302,   430,   760,
     894,    44,   311,   902,   307,   736,   368,  1004,   432,   243,
     244,   369,   305,   265,   247,   447,   439,   441,   696,   697,
     107,   248,   370,   427,   323,   428,   371,   257,   258,   308,
     245,   309,    41,   373,   257,   258,   306,   245,    44,   259,
      37,    38,    39,    40,    41,   698,   259,   763,   742,   765,
      44,   374,    40,   307,   260,   377,   764,   358,   447,   447,
      39,   260,   701,   257,   258,   359,   245,    39,   917,   282,
     107,   251,   254,   262,  1052,   259,   286,   503,   360,  1068,
     939,   379,   918,   790,   314,   251,   254,   286,   503,   972,
     260,   447,   791,   324,   940,   107,    39,   257,   258,  1083,
     245,   624,   310,   625,   378,   251,   254,   503,   316,   259,
     375,   251,   254,   503,   372,   614,   503,   382,   361,   362,
     805,   317,   899,  1095,   260,   363,   503,   389,   323,   806,
      39,   900,   390,   262,   312,   364,    41,   391,   945,   520,
     521,   261,    44,   951,   107,   712,   365,   946,   366,   795,
     696,   697,   952,   597,   550,   551,   553,   555,   557,   559,
     562,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   963,   257,   258,   392,   245,   698,   263,   264,
     974,   964,   246,   247,    40,   259,   583,   394,   587,   975,
     266,   989,   598,   447,   704,  1044,   596,   447,   512,   513,
     260,   599,   396,   523,   524,   270,    39,   514,   515,   397,
     610,   252,   255,   398,   612,   399,   613,   726,   696,   697,
     400,   281,   250,   403,   615,   727,   290,   292,   294,   296,
     301,   304,   268,   404,   522,   405,   313,   635,   406,   257,
     258,   407,   245,   243,   244,   698,   305,   265,   247,   456,
     457,   259,    40,   531,   408,   248,   641,   523,   524,   498,
     499,   531,   706,   409,   268,   522,   260,   496,   497,   410,
     306,   413,    39,   311,    37,    38,    39,    40,    41,   411,
     498,   499,   415,   595,    44,   414,   416,   307,   660,   662,
     664,   665,   667,   669,   671,   673,   675,   677,   679,   681,
     683,   685,   687,   689,   691,   693,   695,   417,   418,   419,
     433,   575,   576,   434,   435,   436,   437,   696,   697,   243,
     244,   348,   245,   246,   247,   582,   442,   443,   525,   444,
     445,   248,   446,   660,   662,   664,   667,   669,   671,   673,
     675,   677,   693,   695,   698,   447,   249,   448,   696,   697,
     451,    40,    39,    40,   452,   314,   455,   453,   488,   500,
     724,   708,   501,   250,   283,   284,   349,   245,   246,   247,
     526,   502,   525,   528,   549,   698,   248,   529,   107,   530,
     561,   543,    40,   544,   545,   253,   256,   546,   269,   271,
     548,   285,   710,   577,   580,   586,   287,    39,   578,   591,
     257,   258,   589,   245,   579,   588,   590,   585,   250,   503,
     315,   592,   259,   594,   728,   516,   517,   483,   518,   519,
     520,   521,   734,   656,   658,   243,   244,   260,   305,   265,
     247,   593,   737,    39,   739,   600,   601,   248,   602,   603,
     606,   604,   745,   607,   252,   255,   616,   605,   618,   608,
     504,   609,   306,   753,   611,   617,    37,    38,    39,    40,
      41,   619,   620,   621,   622,   623,    44,   626,   627,   307,
     631,   636,   649,   779,   780,   638,   489,   490,   252,   255,
     504,   642,   491,   492,   493,   494,   495,   496,   497,   504,
     656,   658,   640,   643,   522,   644,   645,   646,   647,   504,
     498,   499,   650,   351,   458,   459,   654,   313,   723,   505,
     506,   507,   463,   508,   509,   510,   511,   512,   513,   678,
     729,   680,   682,   730,   684,   686,   514,   515,   552,   554,
     556,   558,   560,   563,   688,   263,   264,   713,   690,   265,
     247,   735,  1048,   738,   740,   741,   748,   266,   522,   749,
     750,   751,   752,   754,   758,   785,   767,   766,   788,   584,
     107,   762,   267,   769,   778,   770,   524,    38,   499,   796,
     786,   772,   773,   774,   775,   713,   793,   458,   459,   250,
     783,   744,   505,   506,   507,   463,   508,   509,   510,   511,
     512,   513,   789,   798,   800,   801,   802,   823,   824,   514,
     515,   804,   828,   807,   257,   258,   809,   245,   808,   810,
     811,   812,   816,   813,   831,   815,   259,   819,   253,   256,
     837,   269,   271,   287,   315,   834,   803,   833,   725,   820,
     525,   260,   835,   843,   841,   844,   845,    39,   253,   256,
     269,   287,   315,   907,   847,   315,   870,   909,   659,   848,
     510,   511,   512,   513,   849,   850,   852,   851,   253,   256,
     315,   514,   515,   747,   853,   489,   490,   257,   258,   857,
     245,   491,   492,   493,   494,   495,   496,   497,   859,   259,
     858,   315,   700,   702,   703,   705,   707,   709,   711,   498,
     499,   861,   860,   542,   260,   864,   865,   876,   877,   832,
      39,   888,   890,   891,   914,   897,   905,   934,   935,   965,
     892,   661,   898,   968,   911,   912,   915,   700,   702,   705,
     707,   709,   711,   926,   921,   930,   936,   953,   937,   938,
     943,   947,   944,   954,   458,   459,   948,   961,   949,   505,
     506,   507,   463,   508,   509,   510,   511,   512,   513,   950,
     955,   958,   257,   258,   962,   245,   514,   515,   966,   836,
     973,   458,   459,   976,   259,   969,   505,   506,   507,   463,
     508,   509,   510,   511,   512,   513,   978,   984,   985,   260,
     987,   988,   504,   514,   515,    39,   980,   981,   982,   257,
     258,   991,   245,   990,   993,   996,   663,  1000,  1002,   257,
     258,   259,   245,  1003,  1005,  1006,  1017,  1011,  1009,   998,
    1010,   259,  1016,  1053,  1007,   746,   260,  1008,   257,   258,
    1024,   245,    39,  1015,  1020,  1022,   260,  1025,  1066,  1026,
     259,  1028,    39,   666,  1033,  1035,  1029,  1031,  1037,  1038,
    1034,   839,  1041,   668,  1036,   260,  1039,  1045,  1050,  1067,
    1042,    39,  1070,  1051,  1058,  1053,   842,  1072,  1074,  1061,
    1069,  1062,   670,  1076,  1079,  1089,   714,   715,   716,   717,
     718,   719,   720,   721,   722,   491,   492,   493,   494,   495,
     496,   497,  1090,   875,  1075,  1081,  1078,  1091,  1092,  1094,
       6,  1059,  1085,   498,   499,  1086,   929,   252,   255,   504,
       2,     3,  1084,    -8,    -8,   933,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,   867,
      -8,   863,    -8,  1080,    -8,    -8,    -8,    -8,    -8,    -8,
       0,     0,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,     0,    -8,
       0,    -8,    -8,    -8,     0,    -8,     0,    -8,    -8,    -8,
      -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,     0,
       0,     0,     0,     0,     0,    -8,    -8,    -8,    -8,    -8,
       0,     0,     0,   838,     0,    -8,    -8,    -8,    -8,    -8,
       0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,     0,
      -8,     0,     0,    -8,     0,     0,    -8,     0,    -8,     0,
      -8,     0,     0,     0,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,     0,     0,     0,    -8,    -8,     0,    -8,     0,    -8,
       0,    -8,     0,    -8,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -4,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    35,     0,    36,     0,    37,    38,    39,    40,    41,
      42,     0,     0,     0,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     0,    55,    56,     0,
      57,     0,    58,    59,    60,     0,    61,     0,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
      77,     0,     0,     0,     0,     0,    78,    79,     0,    80,
      81,     0,   -85,    82,  -101,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       0,    98,     0,     0,    99,     0,     0,   100,     0,   101,
       0,   102,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,   110,   -95,     0,   111,     0,
     112,     0,   113,     0,   114,   115,   116,   117,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   257,   258,     0,   245,   257,   258,
       0,   245,   257,   258,     0,   245,   259,     0,     0,     0,
     259,     0,   257,   258,   259,   245,   257,   258,     0,   245,
       0,   260,     0,     0,   259,   260,     0,    39,   259,   260,
       0,    39,     0,     0,     0,    39,     0,     0,   672,   260,
       0,     0,   674,   260,     0,    39,   676,   257,   258,    39,
     245,   257,   258,     0,   245,     0,   678,     0,     0,   259,
     680,   257,   258,   259,   245,   257,   258,     0,   245,   257,
     258,     0,   245,   259,   260,     0,     0,   259,   260,     0,
      39,   259,     0,     0,    39,     0,     0,     0,   260,     0,
       0,   682,   260,     0,    39,   684,   260,     0,    39,     0,
     257,   258,    39,   245,     0,   686,     0,   257,   258,   688,
     245,     0,   259,   690,   277,   278,     0,   245,   297,   259,
       0,     0,     0,     0,     0,     0,   259,   260,     0,     0,
       0,     0,     0,    39,   260,     0,     0,     0,     0,     0,
      39,   581,   277,   278,   692,   245,    38,    39,    40,    41,
       0,   694,   479,   480,   259,    44,     0,     0,   481,   482,
     483,   484,   485,   486,   487,     0,     0,     0,     0,   279,
     277,   278,     0,   245,     0,    39,    40,    41,     0,   458,
     459,     0,   259,    44,   505,   506,   507,   463,   508,   509,
     510,   511,   512,   513,     0,     0,     0,   288,     0,   479,
     480,   514,   515,    39,    40,   516,   517,   483,   518,   519,
     520,   521,     0,     0,     0,   326,   327,   328,   792,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   277,   278,     0,   245,
     297,     0,     0,     0,     0,     0,     0,     0,   259,   346,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   298,     0,     0,   458,   459,    38,    39,
      40,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   532,   533,   534,   535,   536,   537,   538,   477,   478,
     458,   459,     0,     0,   539,   505,   506,   507,   463,   508,
     509,   510,   511,   512,   513,     0,     0,     0,     0,     0,
       0,     0,   514,   515,   479,   480,     0,     0,   539,     0,
     481,   482,   483,   484,   485,   486,   487,   479,   480,     0,
       0,     0,     0,   516,   517,   483,   518,   519,   520,   521,
       0,     0,   540,     0,     0,     0,     0,     0,     0,     0,
       0,   458,   459,     0,     0,   540,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   458,   459,     0,     0,     0,
     505,   506,   507,   463,   508,   509,   510,   511,   512,   513,
       0,     0,     0,     0,     0,     0,     0,   514,   515,   326,
     327,   328,     0,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     505,   506,   507,   463,   508,   509,   510,   511,   512,   513,
       0,     0,     0,     0,     0,     0,     0,   514,   515,   506,
     507,   463,   508,   509,   510,   511,   512,   513,     0,     0,
       0,     0,     0,     0,     0,   514,   515
};

static const yytype_int16 yycheck[] =
{
       9,    35,    49,    50,    51,    52,   320,    35,    10,    11,
      12,    33,    38,    15,    16,    17,    18,    19,    20,    21,
      35,    41,    38,    25,    26,    27,    28,    29,    30,   829,
      38,    38,    33,    35,     7,    41,     3,     4,    41,     6,
      34,    43,    27,    28,    79,    92,    93,    34,    15,     7,
      34,    53,    14,    15,    48,     3,     4,    30,     6,     7,
       8,    48,    35,    30,    48,    25,    26,    15,    70,    36,
       3,     4,    30,   193,    47,     7,    14,    35,   878,   879,
     880,   881,    30,    58,     3,     4,    34,    35,    36,    37,
      38,    66,   127,    31,    97,    40,    44,    30,    30,    47,
      62,    63,    64,    35,    37,     3,     4,    14,     6,     7,
       8,    30,   114,   115,    47,    47,   146,    15,    37,    39,
      33,    41,    47,   143,    31,   100,   132,    40,   150,    34,
       3,     4,    30,     6,     7,     8,    34,    35,    36,    37,
      38,    34,    15,    48,   119,   120,    44,   148,    38,    47,
      13,   126,   147,    55,   149,    48,    34,    30,   125,    34,
      31,    34,    35,    36,    37,    38,    29,    30,   194,    40,
      48,    44,    35,    48,    47,    31,    60,   977,   194,     3,
       4,    66,     6,     7,     8,    41,   194,   194,     3,     4,
     138,    15,    30,   155,    30,   157,    30,     3,     4,   147,
       6,   149,    38,    72,     3,     4,    30,     6,    44,    15,
      34,    35,    36,    37,    38,    30,    15,    31,    31,    31,
      44,    66,    37,    47,    30,    47,    40,    58,    41,    41,
      36,    30,    47,     3,     4,    66,     6,    36,    34,    20,
     138,   243,   244,   245,   142,    15,   248,   249,    79,  1049,
      34,    79,    48,    31,    35,   257,   258,   259,   260,    39,
      30,    41,    40,    44,    48,   138,    36,     3,     4,   142,
       6,   122,   306,   124,    47,   277,   278,   279,   306,    15,
      79,   283,   284,   285,    65,    55,   288,    79,   119,   120,
      31,   306,    31,  1093,    30,   126,   298,    30,    30,    40,
      36,    40,    47,   305,   306,   136,    38,    47,    31,    14,
      15,    47,    44,    31,   138,    47,   147,    40,   149,   125,
       3,     4,    40,   370,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,    31,     3,     4,    80,     6,    30,     3,     4,
      31,    40,     7,     8,    37,    15,   358,    47,   360,    40,
      15,    39,   371,    41,    47,    39,   368,    41,    16,    17,
      30,   373,    81,    27,    28,    30,    36,    25,    26,    82,
     389,    10,    11,    83,   393,    83,   395,    47,     3,     4,
      83,    20,    47,    55,   396,    55,    25,    26,    27,    28,
      29,    30,   265,    47,   267,    38,    35,   416,   121,     3,
       4,   121,     6,     3,     4,    30,     6,     7,     8,    27,
      28,    15,    37,    31,    38,    15,   428,    27,    28,    27,
      28,    31,    47,    38,   297,   298,    30,    14,    15,    66,
      30,    30,    36,   306,    34,    35,    36,    37,    38,   141,
      27,    28,    30,    47,    44,    42,    30,    47,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,    47,    47,   152,
      38,   344,   345,    38,    38,    38,    38,     3,     4,     3,
       4,    81,     6,     7,     8,   358,    38,    38,   279,    38,
      38,    15,    38,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,    30,    41,    30,    97,     3,     4,
     101,    37,    36,    37,   145,   306,    39,   103,    14,    39,
     577,    47,    39,    47,     3,     4,   126,     6,     7,     8,
      14,    47,   323,    31,   325,    30,    15,    31,   138,    31,
     331,    31,    37,    31,    33,    10,    11,    33,    13,    14,
      33,    30,    47,    29,    47,    58,    21,    36,    38,    30,
       3,     4,   121,     6,    38,    38,    38,   358,    47,   581,
      35,    38,    15,    58,   586,     9,    10,    11,    12,    13,
      14,    15,   594,   456,   457,     3,     4,    30,     6,     7,
       8,    38,   604,    36,   606,    47,    42,    15,    42,    47,
      58,    79,   614,    38,   243,   244,   397,    47,   399,   121,
     249,    38,    30,   625,    47,    84,    34,    35,    36,    37,
      38,    47,    29,    38,    38,    38,    44,    38,    30,    47,
      36,    47,    30,   652,   653,    47,     3,     4,   277,   278,
     279,    38,     9,    10,    11,    12,    13,    14,    15,   288,
     523,   524,    47,    38,   527,    38,    38,    38,    38,   298,
      27,    28,   143,    81,     3,     4,    30,   306,    55,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    47,
      38,    47,    47,   124,    47,    47,    25,    26,   327,   328,
     329,   330,   331,   332,    47,     3,     4,   488,    47,     7,
       8,    31,  1026,    47,    38,   124,    32,    15,   581,    29,
      29,    38,   129,    38,    42,   727,    32,   122,   730,   358,
     138,    42,    30,   122,    30,    32,    28,    35,    28,   741,
     124,   195,   195,   195,   195,   526,    32,     3,     4,    47,
      55,   614,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    42,   103,    38,    38,    29,   776,   777,    25,
      26,    42,   781,    55,     3,     4,    48,     6,    47,    30,
      55,    47,   148,    48,   786,    47,    15,    47,   243,   244,
     792,   246,   247,   248,   249,    47,   125,    55,   579,   150,
     581,    30,    48,   131,    32,    30,    38,    36,   263,   264,
     265,   266,   267,   860,   122,   270,   825,   864,    47,    38,
      14,    15,    16,    17,    55,    47,    30,    48,   283,   284,
     285,    25,    26,   614,    42,     3,     4,     3,     4,    30,
       6,     9,    10,    11,    12,    13,    14,    15,   131,    15,
      42,   306,   481,   482,   483,   484,   485,   486,   487,    27,
      28,    47,    29,    31,    30,    29,    47,    30,    42,   125,
      36,    40,   122,    30,    30,    55,    55,   886,   887,   926,
      42,    47,    42,   930,    42,    31,    30,   516,   517,   518,
     519,   520,   521,    91,    55,    92,    38,   906,    33,    38,
      55,    55,    47,    39,     3,     4,    47,   916,    48,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    47,
      39,    31,     3,     4,    47,     6,    25,    26,    93,   792,
      47,     3,     4,    42,    15,    94,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    48,   956,   957,    30,
     959,   960,   581,    25,    26,    36,    42,    42,    48,     3,
       4,    48,     6,    42,    42,    42,    47,    42,    48,     3,
       4,    15,     6,    55,    47,    30,    42,   986,    47,   132,
     132,    15,    47,  1030,    55,   614,    30,    55,     3,     4,
     999,     6,    36,    55,    42,    33,    30,    55,  1045,    32,
      15,    47,    36,    47,    31,  1014,    42,    42,  1017,  1018,
      31,   792,  1021,    47,    42,    30,    33,    29,    42,    33,
      90,    36,    42,    55,    55,  1072,   125,    40,    31,    55,
      55,  1040,    47,   133,    42,    36,   491,   492,   493,   494,
     495,   496,   497,   498,   499,     9,    10,    11,    12,    13,
      14,    15,    31,   125,  1063,    55,  1065,    42,    31,    55,
       1,  1032,  1073,    27,    28,  1074,   883,   696,   697,   698,
       0,     1,  1072,     3,     4,   885,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   821,
      30,   817,    32,  1069,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    -1,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    69,
      70,    71,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      -1,    -1,    -1,   792,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,    -1,    -1,   123,    -1,    -1,   126,    -1,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,    -1,   144,   145,    -1,   147,    -1,   149,
      -1,   151,    -1,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    -1,
      59,    -1,    61,    62,    63,    -1,    65,    -1,    67,    68,
      69,    70,    71,    -1,    73,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    98,
      99,    -1,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,   120,    -1,    -1,   123,    -1,    -1,   126,    -1,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,    -1,    -1,    -1,   144,   145,    -1,   147,    -1,
     149,    -1,   151,    -1,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     3,     4,    -1,     6,     3,     4,
      -1,     6,     3,     4,    -1,     6,    15,    -1,    -1,    -1,
      15,    -1,     3,     4,    15,     6,     3,     4,    -1,     6,
      -1,    30,    -1,    -1,    15,    30,    -1,    36,    15,    30,
      -1,    36,    -1,    -1,    -1,    36,    -1,    -1,    47,    30,
      -1,    -1,    47,    30,    -1,    36,    47,     3,     4,    36,
       6,     3,     4,    -1,     6,    -1,    47,    -1,    -1,    15,
      47,     3,     4,    15,     6,     3,     4,    -1,     6,     3,
       4,    -1,     6,    15,    30,    -1,    -1,    15,    30,    -1,
      36,    15,    -1,    -1,    36,    -1,    -1,    -1,    30,    -1,
      -1,    47,    30,    -1,    36,    47,    30,    -1,    36,    -1,
       3,     4,    36,     6,    -1,    47,    -1,     3,     4,    47,
       6,    -1,    15,    47,     3,     4,    -1,     6,     7,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    30,    -1,    -1,
      -1,    -1,    -1,    36,    30,    -1,    -1,    -1,    -1,    -1,
      36,    30,     3,     4,    47,     6,    35,    36,    37,    38,
      -1,    47,     3,     4,    15,    44,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    30,
       3,     4,    -1,     6,    -1,    36,    37,    38,    -1,     3,
       4,    -1,    15,    44,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    30,    -1,     3,
       4,    25,    26,    36,    37,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,     8,     9,    10,    42,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     3,     4,    -1,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,     3,     4,    35,    36,
      37,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       3,     4,    -1,    -1,    31,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,     3,     4,    -1,    -1,    31,    -1,
       9,    10,    11,    12,    13,    14,    15,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    31,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     3,     4,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   197,     0,     1,   198,   199,   200,   201,   193,    40,
       3,     4,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    30,    32,    34,    35,    36,
      37,    38,    39,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    56,    57,    59,    61,    62,
      63,    65,    67,    68,    69,    70,    71,    73,    74,    75,
      76,    77,    78,    85,    86,    87,    88,    89,    95,    96,
      98,    99,   102,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   120,   123,
     126,   128,   130,   134,   135,   136,   137,   138,   139,   140,
     144,   147,   149,   151,   153,   154,   155,   156,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   202,   203,   204,   205,   206,   207,   208,
     214,   223,   244,   245,   252,   253,   262,   263,   268,   269,
     274,   281,   283,   285,   286,   287,   288,   289,   290,   291,
     292,   294,   295,   296,   307,   308,   309,   310,   311,   312,
     316,   317,   323,   324,   325,   331,   332,   333,   334,   348,
     357,   358,   359,   360,   361,   362,   367,   368,   369,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   400,   402,   404,   405,   406,   407,
     408,   409,   202,     3,     4,     6,     7,     8,    15,    30,
      47,   288,   289,   291,   288,   289,   291,     3,     4,    15,
      30,    47,   288,     3,     4,     7,    15,    30,   287,   291,
      30,   291,   288,   288,   288,   288,   288,     3,     4,    30,
     288,   289,   290,     3,     4,    30,   288,   291,    30,   288,
     289,   288,   289,   288,   289,   288,   289,     7,    30,   287,
     288,   289,   287,   288,   289,     6,    30,    47,   147,   149,
     286,   287,   288,   289,   290,   291,   294,   295,   147,   149,
     200,   284,   288,    30,   290,   146,     8,     9,    10,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    42,    47,    81,   126,
     285,    81,   285,   285,   285,   288,    38,    55,    58,    66,
      79,   119,   120,   126,   136,   147,   149,   403,    60,    66,
      30,    30,   290,    72,    66,    79,   288,    47,    47,    79,
      79,   127,    79,    58,    66,   100,   119,   120,   126,    30,
      47,    47,    80,   275,    47,   282,    81,    82,    83,    83,
      83,   285,   285,    55,    47,    38,   121,   121,    38,    38,
      66,   141,   345,    30,    42,    30,    30,    47,    47,   152,
     288,   288,    14,    15,    62,    63,    64,   155,   157,    38,
     194,    38,   194,    38,    38,    38,    38,    38,    38,   194,
      38,   194,    38,    38,    38,    38,    38,    41,    97,   248,
     246,   101,   145,   103,   247,    39,    27,    28,     3,     4,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     3,
       4,     9,    10,    11,    12,    13,    14,    15,    14,     3,
       4,     9,    10,    11,    12,    13,    14,    15,    27,    28,
      39,    39,    47,   288,   289,     8,     9,    10,    12,    13,
      14,    15,    16,    17,    25,    26,     9,    10,    12,    13,
      14,    15,   287,    27,    28,   290,    14,    30,    31,    31,
      31,    31,    18,    19,    20,    21,    22,    23,    24,    31,
      31,    31,    31,    31,    31,    33,    33,   284,    33,   290,
     288,   288,   289,   288,   289,   288,   289,   288,   289,   288,
     289,   290,   288,   289,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   287,   287,    29,    38,    38,
      47,    30,   287,   288,   289,   290,    58,   288,    38,   121,
      38,    30,    38,    38,    58,    47,   288,   285,   202,   288,
      47,    42,    42,    47,    79,    47,    58,    38,   121,    38,
     202,    47,   202,   202,    55,   288,   290,    84,   290,    47,
      29,    38,    38,    38,   122,   124,    38,    30,    34,    48,
     352,    36,    34,    48,   355,   202,    47,   318,    47,   326,
      47,   288,    38,    38,    38,    38,    38,    38,   370,    30,
     143,   258,   254,   264,    30,    47,   287,    47,   287,    47,
     288,    47,   288,    47,   288,   288,    47,   288,    47,   288,
      47,   288,    47,   288,    47,   288,    47,   288,    47,   288,
      47,   288,    47,   288,    47,   288,    47,   288,    47,   288,
      47,   288,    47,   288,    47,   288,     3,     4,    30,    47,
     289,    47,   289,   289,    47,   289,    47,   289,    47,   289,
      47,   289,    47,   290,   291,   291,   291,   291,   291,   291,
     291,   291,   291,    55,   285,   290,    47,    55,   288,    38,
     124,    34,    48,   356,   288,    31,    31,   288,    47,   288,
      38,   124,    31,   276,   287,   288,   289,   290,    32,    29,
      29,    38,   129,   288,    38,    34,    48,   353,    42,    31,
      40,   297,    42,    31,    40,    31,   122,    32,   319,   122,
      32,   327,   195,   195,   195,   195,   371,   249,    30,   202,
     202,   270,   293,    55,   399,   288,   124,   125,   288,    42,
      31,    40,    42,    32,   228,   125,   288,   209,   103,   313,
      38,    38,    29,   125,    42,    31,    40,    55,    47,    48,
      30,    55,    47,    48,   215,    47,   148,   320,   321,    47,
     150,   328,   329,   202,   202,   259,    97,   143,   202,   401,
     336,   288,   125,    55,    47,    48,   287,   288,   289,   290,
     224,    32,   125,   131,    30,    38,   315,   122,    38,    55,
      47,    48,    30,    42,    34,    48,   354,    30,    42,   131,
      29,    47,    33,   321,    29,    47,    33,   329,   372,   250,
     202,   255,   265,    39,   336,   125,    30,    42,   363,   364,
     365,   366,   231,   232,   237,   238,   210,   277,    40,   314,
     122,    30,    42,    34,    48,   337,   341,    55,    42,    31,
      40,    34,    48,   339,   346,    55,   216,   285,   322,   285,
     330,    42,    31,   260,    30,    30,   271,    34,    48,   340,
     347,    55,   336,   336,   336,   336,    91,   225,   233,   233,
      92,   229,   239,   239,   202,   202,    38,    33,    38,    34,
      48,   338,   342,    55,    47,    31,    40,    55,    47,    48,
      47,    31,    40,   202,    39,    39,   373,   251,    31,   256,
     266,   202,    47,    31,    40,   285,    93,   235,   285,    94,
     242,   211,    39,    47,    31,    40,    42,   335,    48,   298,
      42,    42,    48,   217,   202,   202,   261,   202,   202,    39,
      42,    48,   234,    42,   226,   240,    42,   230,   132,   278,
      42,   349,    48,    55,   336,    47,    30,    55,    55,    47,
     132,   202,   257,   267,   272,    55,    47,    42,   236,   227,
      42,   243,    33,   212,   202,    55,    32,   351,    47,    42,
     299,    42,   218,    31,    31,   202,    42,   202,   202,    33,
     241,   202,    90,   220,    39,    29,   343,   344,   284,   350,
      42,    55,   142,   285,   303,   304,   305,   306,    55,   220,
     273,    55,   202,   221,   213,   279,   285,    33,   336,    55,
      42,   300,    40,   219,    31,   202,   133,   222,   202,    42,
     343,    55,   301,   142,   306,   222,   202,   132,   280,    36,
      31,    42,    31,   302,    55,   336
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
#line 1002 "pnfha.ypp"
    { ASTNode start("START"); tree.add_node(start); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 1005 "pnfha.ypp"
    {
	 ASTNode line("line");
         tree.add_node(line);
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 1011 "pnfha.ypp"
    { yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 1014 "pnfha.ypp"
    {
		 ASTNode statement("statement");
  		 tree.add_node(statement);
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 1022 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1; 
		    	                    statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 1024 "pnfha.ypp"
    { conprint("VOID TVOID 0V\n"); statementoutcount.insert(); 
                         statementoutcount[statementoutcount.length() - 1] = outcount - 1; statementlineno.insert(); statementlineno[statementlineno.length() - 1]                          = yylineno; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 1026 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					  statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 1028 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					   statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 1030 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 1032 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				       statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 1034 "pnfha.ypp"
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; inblock = true;
				   ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 1042 "pnfha.ypp"
    {
			 ASTNode expression_statement("expression_statement");
			 tree.add_node(expression_statement);
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 1049 "pnfha.ypp"
    {
			 ASTNode declaration_statement("declaration_statement");
			 tree.add_node(declaration_statement);
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 1056 "pnfha.ypp"
    {
			 ASTNode command_statement("command_statement");
			 tree.add_node(command_statement);
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 1063 "pnfha.ypp"
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
#line 1096 "pnfha.ypp"
    {
			 ASTNode label_statement("label_statement");

			 conprint("LBL TVOID 0V\n");

			 tree.add_node(label_statement);
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1104 "pnfha.ypp"
    {
			 ASTNode label_statement("label_statement");

			 conprint("ELBL TVOID 0V\n");

			 tree.add_node(label_statement);
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 1114 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 1120 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1126 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");
			 tree.add_node(control_statement);
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1131 "pnfha.ypp"
    {
			 ASTNode control_statement("control_statement");

			 breakinforever = false;

			 tree.add_node(control_statement);
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1141 "pnfha.ypp"
    {
			 ASTNode if_statementp1("if_statementp1");

			 tree.add_node(if_statementp1);		
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1147 "pnfha.ypp"
    {			 
			 ASTNode if_statementp2("if_statementp2");
			
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1156 "pnfha.ypp"
    {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1163 "pnfha.ypp"
    {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1168 "pnfha.ypp"
    {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 1174 "pnfha.ypp"
    {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1184 "pnfha.ypp"
    {
			 ASTNode if_statementp1("if_statementp1");

			 conprint("NOT TVOID 0V\n");	

			 tree.add_node(if_statementp1);		
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1192 "pnfha.ypp"
    {			 
			 ASTNode if_statementp2("if_statementp2");
		
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 1201 "pnfha.ypp"
    {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1208 "pnfha.ypp"
    {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1213 "pnfha.ypp"
    {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1219 "pnfha.ypp"
    {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1229 "pnfha.ypp"
    {
			 ASTNode if_statementp5("if_statementp5");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 // Code for else will be inserted here if exists...
			 tree.add_node(if_statementp5);
			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1240 "pnfha.ypp"
    {
			 ASTNode if_statementp7("if_statementp7");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");

			 tree.add_node(if_statementp7);
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1254 "pnfha.ypp"
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

  case 47:

/* Line 1455 of yacc.c  */
#line 1293 "pnfha.ypp"
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

  case 48:

/* Line 1455 of yacc.c  */
#line 1322 "pnfha.ypp"
    {
			 ASTNode switch_statementp3("switch_statementp3");

			 tree.add_node(switch_statementp3);
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1327 "pnfha.ypp"
    {

			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1331 "pnfha.ypp"
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1339 "pnfha.ypp"
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

  case 52:

/* Line 1455 of yacc.c  */
#line 1354 "pnfha.ypp"
    {
			 ASTNode switch_statementp2("switch_statementp2");
			 
			 tree.add_node(switch_statementp2);
			;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1360 "pnfha.ypp"
    {
			 ASTNode switch_statementp3("switch_statementp3");
			 tree.add_node(switch_statementp3);
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1365 "pnfha.ypp"
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1374 "pnfha.ypp"
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1383 "pnfha.ypp"
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

  case 59:

/* Line 1455 of yacc.c  */
#line 1421 "pnfha.ypp"
    {
			 conprint("SWCEND TVOID 0V\n");
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1427 "pnfha.ypp"
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1432 "pnfha.ypp"
    {
			 conprint("SWCEND TVOID 0V\n");
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1437 "pnfha.ypp"
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1446 "pnfha.ypp"
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

  case 67:

/* Line 1455 of yacc.c  */
#line 1477 "pnfha.ypp"
    {
			 ASTNode case_statementp2("case_statementp2");

			 tree.add_node(case_statementp2);
			;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1483 "pnfha.ypp"
    {
			 ASTNode case_statementp3("case_statementp3");

			 conprint("SWCEND TVOID 0V\n");

			 tree.add_node(case_statementp3);
			;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1493 "pnfha.ypp"
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1498 "pnfha.ypp"
    {
			 conprint("SWCEND TVOID 0V\n");
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1503 "pnfha.ypp"
    {
			 loopexpr = true;
			 inloop2 = true;
			;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1508 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1513 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1518 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1523 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1528 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1533 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1538 "pnfha.ypp"
    {
			 ASTNode loop_statement("loop_statement");
			 
			 loopexpr = false;
			 inloop = true;		 

			 tree.add_node(loop_statement);
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1546 "pnfha.ypp"
    {
			 inloop2 = false;
			 inwhile = false;
			 indowhile = false;
			 infor2 = false;
			 indofor = false;
			 inforever = false;
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1557 "pnfha.ypp"
    {
			 ASTNode while_loopp1("while_loopp1");

			 inwhile = true;
			 ++whilecounter;
			 conprint("LBL TSTRING \"while_test_%u\"\n", whilecounter);

			 tree.add_node(while_loopp1);
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1567 "pnfha.ypp"
    {
			 ASTNode while_loopp2("while_loopp2");

			 tree.add_node(while_loopp2);
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1573 "pnfha.ypp"
    {
			 ASTNode while_loopp3("while_loopp3");

			 conprint("CGOTOL TSTRING \"while_body_%u\"\n", whilecounter);
			 conprint("GOTOL TSTRING \"while_end_%u\"\n", whilecounter);

			 conprint("LBL TSTRING \"while_body_%u\"\n", whilecounter);

			 tree.add_node(while_loopp3);
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1584 "pnfha.ypp"
    {
			 ASTNode while_loopp4("while_loopp4");

			 conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 conprint("LBL TSTRING \"while_end_%u\"\n", whilecounter);

			 tree.add_node(while_loopp4);
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1594 "pnfha.ypp"
    {
			 ASTNode do_while_loopp1("do_while_loopp1");

			 indowhile = true;
			 ++dowhilecounter;
			 conprint("LBL TSTRING \"do_while_body_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp1);
			;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1604 "pnfha.ypp"
    {
			 ASTNode do_while_loopp2("do_while_loopp2");

			 tree.add_node(do_while_loopp2);
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1611 "pnfha.ypp"
    {
			 ASTNode do_while_loopp3("do_while_loopp3");

			 conprint("LBL TSTRING \"do_while_test_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp3);
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1619 "pnfha.ypp"
    {
			 ASTNode do_while_loopp4("do_while_loopp4");

			 tree.add_node(do_while_loopp4);
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1625 "pnfha.ypp"
    {
			 ASTNode do_while_loopp5("do_while_loopp5");

			 conprint("CGOTOL TSTRING \"do_while_body_%u\"\n", dowhilecounter);
			 conprint("GOTOL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp5);
			;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1634 "pnfha.ypp"
    {
			 ASTNode do_while_loopp6("do_while_loopp6");

			 conprint("LBL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp6);
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1644 "pnfha.ypp"
    {
			 ASTNode until_loopp1("until_loopp1");

			 inuntil = true;
			 ++untilcounter;
			 conprint("LBL TSTRING \"until_test_%u\"\n", untilcounter);

			 tree.add_node(until_loopp1);
			;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1654 "pnfha.ypp"
    {
			 ASTNode until_loopp2("until_loopp2");

			 tree.add_node(until_loopp2);
			;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1660 "pnfha.ypp"
    {
			 ASTNode until_loopp3("until_loopp3");


			 conprint("NOT TVOID 0V\n");

			 conprint("CGOTOL TSTRING \"until_body_%u\"\n", untilcounter);
			 conprint("GOTOL TSTRING \"until_end_%u\"\n", untilcounter);

			 conprint("LBL TSTRING \"until_body_%u\"\n", untilcounter);

			 tree.add_node(until_loopp3);
			;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1674 "pnfha.ypp"
    {
			 ASTNode until_loopp4("until_loopp4");

			 conprint("GOTOL TSTRING \"until_test_%u\"\n", untilcounter);
			 conprint("LBL TSTRING \"until_end_%u\"\n", untilcounter);

			 tree.add_node(until_loopp4);
			;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1684 "pnfha.ypp"
    {
			 ASTNode do_until_loopp1("do_until_loopp1");

			 indountil = true;
			 ++dountilcounter;
			 conprint("LBL TSTRING \"do_until_body_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp1);
			;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1694 "pnfha.ypp"
    {
			 ASTNode do_until_loopp2("do_until_loopp2");

			 tree.add_node(do_until_loopp2);
			;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1701 "pnfha.ypp"
    {
			 ASTNode do_until_loopp3("do_until_loopp3");

			 conprint("LBL TSTRING \"do_until_test_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp3);
			;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1709 "pnfha.ypp"
    {
			 ASTNode do_until_loopp4("do_until_loopp4");

			 tree.add_node(do_until_loopp4);
			;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1715 "pnfha.ypp"
    {
			 ASTNode do_until_loopp5("do_until_loopp5");

			 conprint("CGOTOL TSTRING \"do_until_body_%u\"\n", dountilcounter);
			 conprint("GOTOL TSTRING \"do_until_end_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp5);
			;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1724 "pnfha.ypp"
    {
			 ASTNode do_until_loopp6("do_until_loopp6");

			 conprint("NOT TVOID 0V\n");

			 conprint("LBL TSTRING \"do_until_end_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp6);
			;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1735 "pnfha.ypp"
    {
			 infor = true;
			;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1739 "pnfha.ypp"
    {
			 ASTNode for_loopp1("for_loopp1");

			 infor2 = true;
			 ++forcounter;
			 conprint("LBL TSTRING \"for_initialization_%u\"\n", forcounter);

			 tree.add_node(for_loopp1);
			;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1749 "pnfha.ypp"
    {
			 ASTNode for_loopp2("for_loopp2");

			 conprint("LBL TSTRING \"for_condition_%u\"\n", forcounter);

			 tree.add_node(for_loopp2);
			;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1757 "pnfha.ypp"
    {
			 ASTNode for_loopp3("for_loopp3");

			 conprint("CGOTOL TSTRING \"for_body_%u\"\n", forcounter);
			 conprint("GOTOL TSTRING \"for_end_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_increment_statement_%u\"\n", forcounter);

			 tree.add_node(for_loopp3);
			;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1767 "pnfha.ypp"
    {
			 ASTNode for_loopp4("for_loopp4");

			 conprint("GOTOL TSTRING \"for_condition_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_body_%u\"\n", forcounter);

			 tree.add_node(for_loopp4);
			;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1776 "pnfha.ypp"
    {
			 ASTNode for_loopp5("for_loopp5");

			 conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_end_%u\"\n", forcounter);

			 tree.add_node(for_loopp5);
			;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1787 "pnfha.ypp"
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

  case 108:

/* Line 1455 of yacc.c  */
#line 1800 "pnfha.ypp"
    {
			 ASTNode forb_loopp2("forb_loopp2");

			 conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_initialization_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp2);
			;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1809 "pnfha.ypp"
    {
			 ASTNode forb_loopp3("forb_loopp3");

			 tree.add_node(forb_loopp3);
			;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1815 "pnfha.ypp"
    {
			 ASTNode forb_loopp4("forb_loopp4");

			 conprint("GOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_condition_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp4);
			;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1824 "pnfha.ypp"
    {
			 ASTNode forb_loopp5("forb_loopp5");

			 conprint("CGOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("GOTOL TSTRING \"dofor_end_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp5);
			;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1834 "pnfha.ypp"
    {
			 ASTNode forb_loopp6("forb_loopp6");
			 tree.add_node(forb_loopp6);
			;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1839 "pnfha.ypp"
    {
			 ASTNode forb_loopp7("forb_loopp7");

			 conprint("GOTOL TSTRING \"dofor_condition_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_end_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp7);
			;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1850 "pnfha.ypp"
    {
			 ASTNode forever_loopp1("forever_loopp1");

			 breakinforever = true;
			 ++forevercounter;
			 conprint("LBL TSTRING \"forever_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp1);			
			;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1860 "pnfha.ypp"
    {
			 ASTNode forever_loopp2("forever_loopp2");

			 conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);
			 conprint("LBL TSTRING \"forever_end_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp2);			
			;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1869 "pnfha.ypp"
    { PNF_String str((yyvsp[(2) - (3)]).to_string().get()); (yyval).put(str); ASTNode statement_block("statement_block"); 
                                                  tree.add_node(statement_block); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1874 "pnfha.ypp"
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1879 "pnfha.ypp"
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1885 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TVOID; ASTNode expression("expression"); tree.add_node(expression); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1887 "pnfha.ypp"
    {
		 (yyval) = (yyvsp[(1) - (1)]);
		 savenumber = (yyval);
		 exptype = TBOOLEAN;
		 ASTNode expression("expression");
		 tree.add_node(expression);
		;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1894 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); savenumber = (yyval); exptype = TNUMBER; ASTNode expression("expression");
                                      tree.add_node(expression); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1896 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); savenumber = (yyval); exptype = TCHARACTER; ASTNode expression("expression"); 
                                         tree.add_node(expression); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1898 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); savenumber = (PNF_String)strip_quotes((yyval).to_string().get()); exptype = TSTRING; ASTNode expression("expression"); 
                                      tree.add_node(expression); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1900 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
                                  tree.add_node(expression); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1902 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = TBOOLEAN; ASTNode expression("expression"); 
					  tree.add_node(expression); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1904 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
				     tree.add_node(expression); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1906 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); tree.add_node(expression); 		
		;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1912 "pnfha.ypp"
    {
			 PNF_String s("0V");
			 (yyval).put(s);

			 exptruth = false;

			 ASTNode void_expression("void_expression");
			 tree.add_node(void_expression);
			;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1921 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1925 "pnfha.ypp"
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

  case 131:

/* Line 1455 of yacc.c  */
#line 1941 "pnfha.ypp"
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

  case 132:

/* Line 1455 of yacc.c  */
#line 1955 "pnfha.ypp"
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

  case 133:

/* Line 1455 of yacc.c  */
#line 1971 "pnfha.ypp"
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

  case 134:

/* Line 1455 of yacc.c  */
#line 1986 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1990 "pnfha.ypp"
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

  case 136:

/* Line 1455 of yacc.c  */
#line 2004 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().add(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 2010 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().sub(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 2016 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mul(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 2022 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().div(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 2028 "pnfha.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mod(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 2034 "pnfha.ypp"
    {
			 char * str = "-";
			 strcat(str, (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 PNF_String s(str);
			 PNF_Variable v(s);
			 (yyval) = v;
			;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 2042 "pnfha.ypp"
    {
			 double d = (yyvsp[(3) - (3)]).to_number().get();
			 PNF_Number n((yyvsp[(1) - (3)]).to_number());
			 n.pow(d);
			 (yyval).put(n);
			;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 2049 "pnfha.ypp"
    {
			 double d = (yyvsp[(1) - (3)]).to_number().get();
			 PNF_Number n((yyvsp[(3) - (3)]).to_number());
			 n.root(d);			 
			 (yyval).put(n);
			;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 2056 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 2062 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 2068 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 2074 "pnfha.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 2080 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 & d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 2088 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 | d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 2097 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 ^ d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 2105 "pnfha.ypp"
    {
			 int d = (int)(yyvsp[(2) - (2)]).to_number().get();
			 d = ~d;
			 PNF_Number n(d);
			 (yyval).put(n);
			;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 2112 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 << d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 2120 "pnfha.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 >> d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 2127 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 2132 "pnfha.ypp"
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

  case 156:

/* Line 1455 of yacc.c  */
#line 2145 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.add((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 2152 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.sub((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 2159 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mul((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 2166 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.div((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);			;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 2172 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mod((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 2179 "pnfha.ypp"
    {
			 char d = (yyvsp[(3) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(1) - (3)]).to_character());
			 c.pow(d);
			 (yyval).put(c);
			;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 2186 "pnfha.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(3) - (3)]).to_character());
			 c.root(d);
			 (yyval).put(c);
			;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 2193 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 2199 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 2205 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 2211 "pnfha.ypp"
    {
			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 2216 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 2221 "pnfha.ypp"
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

  case 169:

/* Line 1455 of yacc.c  */
#line 2234 "pnfha.ypp"
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

  case 170:

/* Line 1455 of yacc.c  */
#line 2259 "pnfha.ypp"
    {
			 String str = (yyvsp[(2) - (2)]).to_string().get();
			 String str2 = "\"" + str + "\"";
			 PNF_String s(str2);
			 (yyval).put(s);
			;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 2265 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 2270 "pnfha.ypp"
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

  case 173:

/* Line 1455 of yacc.c  */
#line 2341 "pnfha.ypp"
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

  case 174:

/* Line 1455 of yacc.c  */
#line 2381 "pnfha.ypp"
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

  case 175:

/* Line 1455 of yacc.c  */
#line 2418 "pnfha.ypp"
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

  case 176:

/* Line 1455 of yacc.c  */
#line 2495 "pnfha.ypp"
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

  case 177:

/* Line 1455 of yacc.c  */
#line 2574 "pnfha.ypp"
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

  case 178:

/* Line 1455 of yacc.c  */
#line 2654 "pnfha.ypp"
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

  case 179:

/* Line 1455 of yacc.c  */
#line 2692 "pnfha.ypp"
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

  case 180:

/* Line 1455 of yacc.c  */
#line 2730 "pnfha.ypp"
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

  case 181:

/* Line 1455 of yacc.c  */
#line 2768 "pnfha.ypp"
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

  case 182:

/* Line 1455 of yacc.c  */
#line 2806 "pnfha.ypp"
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

  case 183:

/* Line 1455 of yacc.c  */
#line 2819 "pnfha.ypp"
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

  case 184:

/* Line 1455 of yacc.c  */
#line 2857 "pnfha.ypp"
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

  case 185:

/* Line 1455 of yacc.c  */
#line 2895 "pnfha.ypp"
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

  case 186:

/* Line 1455 of yacc.c  */
#line 2923 "pnfha.ypp"
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

  case 187:

/* Line 1455 of yacc.c  */
#line 2951 "pnfha.ypp"
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

  case 188:

/* Line 1455 of yacc.c  */
#line 2979 "pnfha.ypp"
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

  case 189:

/* Line 1455 of yacc.c  */
#line 3006 "pnfha.ypp"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 3010 "pnfha.ypp"
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

  case 191:

/* Line 1455 of yacc.c  */
#line 3021 "pnfha.ypp"
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

  case 192:

/* Line 1455 of yacc.c  */
#line 3032 "pnfha.ypp"
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

  case 193:

/* Line 1455 of yacc.c  */
#line 3043 "pnfha.ypp"
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

  case 194:

/* Line 1455 of yacc.c  */
#line 3054 "pnfha.ypp"
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

  case 195:

/* Line 1455 of yacc.c  */
#line 3065 "pnfha.ypp"
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

  case 196:

/* Line 1455 of yacc.c  */
#line 3075 "pnfha.ypp"
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

  case 197:

/* Line 1455 of yacc.c  */
#line 3085 "pnfha.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b1 = d1 < d2;
			 bool b2 = d1 == d2;
			 bool b3 = d1 > d2;
			 double answer = 0;

			 if (b1)
			  answer = -1;
			 else if (b2)
			  answer = 0;
			 else if (b3)
			  answer = 1;
			 else
			 {
			  yyerror((char *)"Bad CMP.");
			  exit(-1);
			 }
			 PNF_Number n(answer);
			 (yyval).put(n);
			;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 3110 "pnfha.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 3112 "pnfha.ypp"
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

  case 200:

/* Line 1455 of yacc.c  */
#line 3161 "pnfha.ypp"
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

  case 201:

/* Line 1455 of yacc.c  */
#line 3210 "pnfha.ypp"
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

  case 202:

/* Line 1455 of yacc.c  */
#line 3259 "pnfha.ypp"
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

  case 203:

/* Line 1455 of yacc.c  */
#line 3308 "pnfha.ypp"
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

  case 204:

/* Line 1455 of yacc.c  */
#line 3350 "pnfha.ypp"
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

  case 205:

/* Line 1455 of yacc.c  */
#line 3392 "pnfha.ypp"
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

  case 206:

/* Line 1455 of yacc.c  */
#line 3434 "pnfha.ypp"
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

  case 207:

/* Line 1455 of yacc.c  */
#line 3476 "pnfha.ypp"
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

  case 208:

/* Line 1455 of yacc.c  */
#line 3518 "pnfha.ypp"
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

  case 209:

/* Line 1455 of yacc.c  */
#line 3560 "pnfha.ypp"
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

  case 210:

/* Line 1455 of yacc.c  */
#line 3602 "pnfha.ypp"
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

  case 211:

/* Line 1455 of yacc.c  */
#line 3644 "pnfha.ypp"
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

  case 212:

/* Line 1455 of yacc.c  */
#line 3686 "pnfha.ypp"
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

  case 213:

/* Line 1455 of yacc.c  */
#line 3728 "pnfha.ypp"
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

  case 214:

/* Line 1455 of yacc.c  */
#line 3770 "pnfha.ypp"
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

  case 215:

/* Line 1455 of yacc.c  */
#line 3812 "pnfha.ypp"
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

  case 216:

/* Line 1455 of yacc.c  */
#line 3854 "pnfha.ypp"
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

  case 217:

/* Line 1455 of yacc.c  */
#line 3896 "pnfha.ypp"
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

  case 218:

/* Line 1455 of yacc.c  */
#line 3938 "pnfha.ypp"
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

  case 219:

/* Line 1455 of yacc.c  */
#line 3980 "pnfha.ypp"
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

  case 220:

/* Line 1455 of yacc.c  */
#line 4022 "pnfha.ypp"
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

  case 221:

/* Line 1455 of yacc.c  */
#line 4064 "pnfha.ypp"
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

  case 222:

/* Line 1455 of yacc.c  */
#line 4106 "pnfha.ypp"
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

  case 223:

/* Line 1455 of yacc.c  */
#line 4148 "pnfha.ypp"
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

  case 224:

/* Line 1455 of yacc.c  */
#line 4190 "pnfha.ypp"
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

  case 225:

/* Line 1455 of yacc.c  */
#line 4232 "pnfha.ypp"
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

  case 226:

/* Line 1455 of yacc.c  */
#line 4274 "pnfha.ypp"
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

  case 227:

/* Line 1455 of yacc.c  */
#line 4316 "pnfha.ypp"
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

  case 228:

/* Line 1455 of yacc.c  */
#line 4380 "pnfha.ypp"
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

  case 229:

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

  case 230:

/* Line 1455 of yacc.c  */
#line 4489 "pnfha.ypp"
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

  case 231:

/* Line 1455 of yacc.c  */
#line 4534 "pnfha.ypp"
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

  case 232:

/* Line 1455 of yacc.c  */
#line 4579 "pnfha.ypp"
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

  case 233:

/* Line 1455 of yacc.c  */
#line 4624 "pnfha.ypp"
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

  case 234:

/* Line 1455 of yacc.c  */
#line 4669 "pnfha.ypp"
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

  case 235:

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

  case 236:

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

  case 237:

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

  case 238:

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

  case 239:

/* Line 1455 of yacc.c  */
#line 4894 "pnfha.ypp"
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

  case 240:

/* Line 1455 of yacc.c  */
#line 4939 "pnfha.ypp"
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

  case 241:

/* Line 1455 of yacc.c  */
#line 4984 "pnfha.ypp"
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

  case 242:

/* Line 1455 of yacc.c  */
#line 5029 "pnfha.ypp"
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

  case 243:

/* Line 1455 of yacc.c  */
#line 5074 "pnfha.ypp"
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

  case 244:

/* Line 1455 of yacc.c  */
#line 5119 "pnfha.ypp"
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

  case 245:

/* Line 1455 of yacc.c  */
#line 5164 "pnfha.ypp"
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

  case 246:

/* Line 1455 of yacc.c  */
#line 5209 "pnfha.ypp"
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

  case 247:

/* Line 1455 of yacc.c  */
#line 5254 "pnfha.ypp"
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

  case 248:

/* Line 1455 of yacc.c  */
#line 5291 "pnfha.ypp"
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

  case 249:

/* Line 1455 of yacc.c  */
#line 5336 "pnfha.ypp"
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

  case 250:

/* Line 1455 of yacc.c  */
#line 5381 "pnfha.ypp"
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

  case 251:

/* Line 1455 of yacc.c  */
#line 5426 "pnfha.ypp"
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

  case 252:

/* Line 1455 of yacc.c  */
#line 5471 "pnfha.ypp"
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
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b1 = d1 < d2;
			 bool b2 = d1 == d2;
			 bool b3 = d1 > d2;
			 double answer = 0;

			 if (b1)
			  answer = -1;
			 else if (b2)
			  answer = 0;
			 else if (b3)
			  answer = 1;
			 else
			 {
			  yyerror((char *)"Bad CMP.");
			  exit(-1);
			 }
			 PNF_Number n(answer);
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
			;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 5529 "pnfha.ypp"
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
			     if ((yyvsp[(1) - (3)]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b1 = d1 < d2;
			 bool b2 = d1 == d2;
			 bool b3 = d1 > d2;
			 double answer = 0;

			 if (b1)
			  answer = -1;
			 else if (b2)
			  answer = 0;
			 else if (b3)
			  answer = 1;
			 else
			 {
			  yyerror((char *)"Bad CMP.");
			  exit(-1);
			 }
			 PNF_Number n(answer);
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
			  String str = (yyvsp[(1) - (3)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }			
			;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 5589 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 5593 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 5599 "pnfha.ypp"
    {
			 funcnum = (unsigned long)(yyvsp[(3) - (3)]).to_number().get();
			;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 5603 "pnfha.ypp"
    {
			 fsaveid2 = (yyvsp[(8) - (8)]);

			 conprint("FCALL TSTRING \"%s\"\n", (yyvsp[(8) - (8)]).to_string().get().getString().c_str());
			 conprint("FCPARAMS TVOID 0V\n");
			;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 5610 "pnfha.ypp"
    {
			 pnum3 = 0;
			 pnum4 = 0;
			;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 5615 "pnfha.ypp"
    {		 
			 unsigned long index = funcstk.find(fsaveid2.to_string().get(), frets3, fparams3);
			 if (index == -1)
			 {
			  fparams3.remove();
			  index = funcstk.find(fsaveid2.to_string().get(), frets3, fparams3);
			  if (index == -1)
			  {
			   fparams3.remove();
			   index = funcstk.find(fsaveid2.to_string().get(), frets3, fparams3);
			   if (index == -1)
			   {
			    yyerror("Function not found.");
			    exit(-1);
			   }
			  }
			 }
			 fsaveindex = index;
			;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 5634 "pnfha.ypp"
    {
			 if(fncdefault)
			 {
			  fncdefault = false;
			  conprint("FNCDEFAULT2 TVOID 0V\n");
			 }

			 conprint("FECPARAMS TVOID 0V\n");
			;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 5644 "pnfha.ypp"
    {
			 conprint("FECALL TVOID 0V\n");
			;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 5648 "pnfha.ypp"
    {
			 for (unsigned long i = frets3.length() - 1; i > 0; --i)
			  frets3.remove();
			 frets3[0] = "";

			 for (unsigned long i = fparams3.length() - 1; i > 0; --i)
			  fparams3.remove();
			 fparams3[0] = "";
			;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 5660 "pnfha.ypp"
    {

				;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 5667 "pnfha.ypp"
    {
				 (yyval) = (yyvsp[(1) - (1)]);				 

				 for (unsigned long i = 0; i < funcps[funcps.length() - 1].length(); ++i)
			 	 {
			 	  funcps[funcps.length() - 1][i].value((yyvsp[(1) - (1)]));
			 	 }
				;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 5678 "pnfha.ypp"
    {
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

				 ++pnum4;
				;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 5721 "pnfha.ypp"
    {
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

				 ++pnum4;
				;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 5764 "pnfha.ypp"
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


				 ++pnum3;
				 ++pnum4;
				;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 5890 "pnfha.ypp"
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


				 ++pnum3;
				 ++pnum4;
				;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 6035 "pnfha.ypp"
    {
				 (yyval) = (yyvsp[(1) - (1)]);
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

	
				 conprint("FNCSTORE TNUMBER %d\n", funcnum);
				 actual_parameters(saveexp);
				;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 6170 "pnfha.ypp"
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 6175 "pnfha.ypp"
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 6180 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 6185 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 6190 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 6195 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 6200 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 6205 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 6210 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 6215 "pnfha.ypp"
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 6222 "pnfha.ypp"
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

  case 281:

/* Line 1455 of yacc.c  */
#line 6280 "pnfha.ypp"
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

  case 282:

/* Line 1455 of yacc.c  */
#line 6361 "pnfha.ypp"
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

  case 283:

/* Line 1455 of yacc.c  */
#line 6396 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 6401 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 6406 "pnfha.ypp"
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 6413 "pnfha.ypp"
    {
			 ASTNode enumv_declaration("enumv_declaration");

			 conprint("ENUMS TSTRING %s\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 conprint("ENUM TSTRING %s\n", (yyvsp[(5) - (5)]).to_string().get().getString().c_str());
			 conprint("SENUM TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());

			 tree.add_node(enumv_declaration);
			;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 6425 "pnfha.ypp"
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

  case 288:

/* Line 1455 of yacc.c  */
#line 6440 "pnfha.ypp"
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

  case 289:

/* Line 1455 of yacc.c  */
#line 6456 "pnfha.ypp"
    {
			 ASTNode array_declaration("array_declaration");

			 conprint("ASTART TSTRING %s\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 conprint("AEND TNUMBER %g\n", (yyvsp[(4) - (5)]).to_number().get());

			 tree.add_node(array_declaration);
			;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 6467 "pnfha.ypp"
    {
			 ASTNode enum_declarationp1("enum_declarationp1");

			 conprint("ESTART TSTRING \"%s\"\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());

			 tree.add_node(enum_declarationp1);
			;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 6475 "pnfha.ypp"
    {
			 ASTNode enum_declarationp2("enum_declarationp2");
			 tree.add_node(enum_declarationp2);
			;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 6480 "pnfha.ypp"
    {
			 ASTNode enum_declarationp3("enum_declarationp3");

			 conprint("EEND TVOID 0V\n");

			 tree.add_node(enum_declarationp3);
			;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 6490 "pnfha.ypp"
    {
			 ASTNode enum_strings("enum_strings");

			 conprint("ENAME TSTRING %s\n", (yyvsp[(1) - (1)]).to_string().get().getString().c_str());

			 tree.add_node(enum_strings);
			;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 6498 "pnfha.ypp"
    {
			 conprint("ENAME TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 6504 "pnfha.ypp"
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

  case 296:

/* Line 1455 of yacc.c  */
#line 6529 "pnfha.ypp"
    {
			 conprint("STRUCT TSTRING \"%s\"\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 6538 "pnfha.ypp"
    {
			 conprint("ENDSTRUCT TVOID 0V\n");
			;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 6548 "pnfha.ypp"
    {
				 conprint("STRUCTVAR TSTRING \"%s\"\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
				;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 6555 "pnfha.ypp"
    {
				 conprint("STRUCTNAME TSTRING \"%s\"\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str());
				 conprint("STRUCTD TSTRING \"%s\"\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
				;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 6562 "pnfha.ypp"
    {
				 conprint("STRUCTNAME TSTRING \"%s\"\n", (yyvsp[(2) - (7)]).to_string().get().getString().c_str());
				 conprint("STRUCTONAME TSTRING \"%s\"\n", (yyvsp[(3) - (7)]).to_string().get().getString().c_str());
				 conprint("STRUCTUSE TSTRING \"%s\"\n", (yyvsp[(5) - (7)]).to_string().get().getString().c_str());
				 
				 switch ((yyvsp[(7) - (7)]).getType())
				 {
				  case TVOID:
				  {
				   conprint("ALOAD TVOID 0V\n");
				  }
				  break;

				  case TBOOLEAN:
				  {
				   conprint("ALOAD TBOOLEAN %s\n", (yyvsp[(7) - (7)]).to_boolean().get().getString().c_str());
				  }
				  break;

				  case TNUMBER:
				  {
				   conprint("ALOAD TNUMBER %f\n", (yyvsp[(7) - (7)]).to_number().get());
				  }
				  break;

				  case TCHARACTER:
				  {
				   conprint("ALOAD TCHARACTER '%c'\n", (yyvsp[(6) - (7)]).to_character().get());
				  }
				  break;

				  case TSTRING:
				  {
				   conprint("ALOAD TSTRING %s\n", (yyvsp[(7) - (7)]).to_string().get().getString().c_str());
				  }
				  break;

				  default:
				   yyerror((char *)"Invalid type.");
				 }

				 conprint("STRUCTPUT TVOID 0V\n");
				;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 6608 "pnfha.ypp"
    {
			 conprint("UNION TSTRING \"%s\"\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 6617 "pnfha.ypp"
    {
			 conprint("ENDUNION TVOID 0V\n");
			;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 6627 "pnfha.ypp"
    {
				 conprint("UNIONVAR TSTRING \"%s\"\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
				;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 6634 "pnfha.ypp"
    {
				 conprint("UNIONNAME TSTRING \"%s\"\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str());
				 conprint("UNIOND TSTRING \"%s\"\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
				;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 6641 "pnfha.ypp"
    {
				 conprint("UNIONNAME TSTRING \"%s\"\n", (yyvsp[(2) - (7)]).to_string().get().getString().c_str());
				 conprint("UNIONONAME TSTRING \"%s\"\n", (yyvsp[(3) - (7)]).to_string().get().getString().c_str());
				 conprint("UNIONUSE TSTRING \"%s\"\n", (yyvsp[(5) - (7)]).to_string().get().getString().c_str());
				 
				 switch ((yyvsp[(7) - (7)]).getType())
				 {
				  case TVOID:
				  {
				   conprint("ALOAD TVOID 0V\n");
				  }
				  break;

				  case TBOOLEAN:
				  {
				   conprint("ALOAD TBOOLEAN %s\n", (yyvsp[(7) - (7)]).to_boolean().get().getString().c_str());
				  }
				  break;

				  case TNUMBER:
				  {
				   conprint("ALOAD TNUMBER %f\n", (yyvsp[(7) - (7)]).to_number().get());
				  }
				  break;

				  case TCHARACTER:
				  {
				   conprint("ALOAD TCHARACTER '%c'\n", (yyvsp[(6) - (7)]).to_character().get());
				  }
				  break;

				  case TSTRING:
				  {
				   conprint("ALOAD TSTRING %s\n", (yyvsp[(7) - (7)]).to_string().get().getString().c_str());
				  }
				  break;

				  default:
				   yyerror((char *)"Invalid type.");
				 }

				 conprint("UNIONPUT TVOID 0V\n");
				;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 6687 "pnfha.ypp"
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

  case 315:

/* Line 1455 of yacc.c  */
#line 6711 "pnfha.ypp"
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

  case 316:

/* Line 1455 of yacc.c  */
#line 6734 "pnfha.ypp"
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

  case 319:

/* Line 1455 of yacc.c  */
#line 6762 "pnfha.ypp"
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
			 conprint("FNCDELETE TVOID 0V\n");
			;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 6798 "pnfha.ypp"
    {
			 for (unsigned long i = frets.length() - 1; i > 0; --i)
			  frets.remove();

			 for (unsigned long i = fparams.length() - 1; i > 0; --i)
			  fparams.remove();
			;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 6810 "pnfha.ypp"
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

  case 323:

/* Line 1455 of yacc.c  */
#line 6903 "pnfha.ypp"
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

  case 324:

/* Line 1455 of yacc.c  */
#line 7015 "pnfha.ypp"
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

  case 325:

/* Line 1455 of yacc.c  */
#line 7117 "pnfha.ypp"
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

  case 326:

/* Line 1455 of yacc.c  */
#line 7233 "pnfha.ypp"
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

  case 327:

/* Line 1455 of yacc.c  */
#line 7278 "pnfha.ypp"
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

  case 328:

/* Line 1455 of yacc.c  */
#line 7337 "pnfha.ypp"
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

  case 329:

/* Line 1455 of yacc.c  */
#line 7382 "pnfha.ypp"
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

  case 330:

/* Line 1455 of yacc.c  */
#line 7441 "pnfha.ypp"
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

  case 331:

/* Line 1455 of yacc.c  */
#line 7459 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 7467 "pnfha.ypp"
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

  case 333:

/* Line 1455 of yacc.c  */
#line 7485 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 7493 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);


			 funcps[fsaveindex + 1].insert();
			 funcps[fsaveindex + 1][pnum5].value((yyval));


			 funcstk.get_function(fsaveindex + 1).defaultv(pnum5, (yyval));
			 funcstk.get_function(fsaveindex + 1).syncdefaultp(pnum5);
			;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 7507 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(2) - (4)]);
			 pnum5 = (unsigned long)(yyvsp[(4) - (4)]).to_number().get();
			;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 7514 "pnfha.ypp"
    {
			 fncdefault = true;
			 conprint("FNCDEFAULT TVOID 0V\n");
			;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 7521 "pnfha.ypp"
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

  case 340:

/* Line 1455 of yacc.c  */
#line 7539 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 7547 "pnfha.ypp"
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

  case 342:

/* Line 1455 of yacc.c  */
#line 7565 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);

			 exptype = TVOID;
			;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 7573 "pnfha.ypp"
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

  case 344:

/* Line 1455 of yacc.c  */
#line 7591 "pnfha.ypp"
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

  case 345:

/* Line 1455 of yacc.c  */
#line 7602 "pnfha.ypp"
    {
			 for (unsigned long i = frets2.length() - 1; i > 0; --i)
			  frets2.remove();

			 for (unsigned long i = fparams2.length() - 1; i > 0; --i)
			  fparams2.remove();
			;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 7617 "pnfha.ypp"
    {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");

			 exptype = TVOID;
			;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 7625 "pnfha.ypp"
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

  case 349:

/* Line 1455 of yacc.c  */
#line 7711 "pnfha.ypp"
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

  case 350:

/* Line 1455 of yacc.c  */
#line 7793 "pnfha.ypp"
    {
			 exptype = TVOID;
			;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 7797 "pnfha.ypp"
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

  case 352:

/* Line 1455 of yacc.c  */
#line 7845 "pnfha.ypp"
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

  case 353:

/* Line 1455 of yacc.c  */
#line 7895 "pnfha.ypp"
    {
			 exptype = TVOID;			;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 7898 "pnfha.ypp"
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

  case 355:

/* Line 1455 of yacc.c  */
#line 7960 "pnfha.ypp"
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

  case 356:

/* Line 1455 of yacc.c  */
#line 8167 "pnfha.ypp"
    {
			 exptype = TVOID;
			;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 8171 "pnfha.ypp"
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

  case 358:

/* Line 1455 of yacc.c  */
#line 8219 "pnfha.ypp"
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

  case 359:

/* Line 1455 of yacc.c  */
#line 8269 "pnfha.ypp"
    {
			 exptype = TVOID;
			;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 8273 "pnfha.ypp"
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

  case 361:

/* Line 1455 of yacc.c  */
#line 8321 "pnfha.ypp"
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

  case 362:

/* Line 1455 of yacc.c  */
#line 8373 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 8378 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 8383 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 8388 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 8393 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 8398 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 8403 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 8408 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 8413 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 8418 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 8423 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 8428 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 8433 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 8438 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 8443 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 8448 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 8453 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 8458 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 8463 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 8468 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 8473 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 8478 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 8483 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 8488 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 8493 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 8498 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 8503 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 8508 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 8513 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 8518 "pnfha.ypp"
    {
			 ASTNode command("command");
		         tree.add_node(command);
			;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 8531 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("PRINT TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 8537 "pnfha.ypp"
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

  case 399:

/* Line 1455 of yacc.c  */
#line 8583 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "ver")
			  conprint("VPRINT TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 8594 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("PRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 8600 "pnfha.ypp"
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

  case 402:

/* Line 1455 of yacc.c  */
#line 8646 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[(2) - (2)]).to_string().get() == "ver")
			  conprint("VPRINTLN TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 8657 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINT TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 8663 "pnfha.ypp"
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

  case 405:

/* Line 1455 of yacc.c  */
#line 8709 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 8715 "pnfha.ypp"
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

  case 407:

/* Line 1455 of yacc.c  */
#line 8761 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINT TVOID 0V\n");
			;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 8766 "pnfha.ypp"
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

  case 409:

/* Line 1455 of yacc.c  */
#line 8812 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 8818 "pnfha.ypp"
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

  case 411:

/* Line 1455 of yacc.c  */
#line 8864 "pnfha.ypp"
    {
			 ASTNode print_command("print_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 conprint("APRINT TVOID 0V\n");

			 tree.add_node(print_command);
			;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 8876 "pnfha.ypp"
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

  case 413:

/* Line 1455 of yacc.c  */
#line 8935 "pnfha.ypp"
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

  case 414:

/* Line 1455 of yacc.c  */
#line 9008 "pnfha.ypp"
    {
			 ASTNode end_command("end_command");
			 conprint("QUIT TVOID %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(end_command);
			;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 9016 "pnfha.ypp"
    {
			 ASTNode asm_command("asm_command");
			 conprint("%s %s %s\n", strip_quotes((yyvsp[(2) - (4)]).to_string().get()).getString().c_str(), 
					      strip_quotes((yyvsp[(3) - (4)]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[(4) - (4)]).to_string().get()).getString().c_str());
			 tree.add_node(asm_command);
			;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 9025 "pnfha.ypp"
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
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "seg1")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accumulator")
			   conprint("SEGLOAD TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror((char *)"Invalid register type.");
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 9169 "pnfha.ypp"
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

  case 418:

/* Line 1455 of yacc.c  */
#line 9262 "pnfha.ypp"
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

  case 419:

/* Line 1455 of yacc.c  */
#line 9290 "pnfha.ypp"
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

  case 420:

/* Line 1455 of yacc.c  */
#line 9301 "pnfha.ypp"
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

  case 421:

/* Line 1455 of yacc.c  */
#line 9318 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TCHARACTER %c\n", (yyvsp[(3) - (3)]).to_character().get());
			 }			 
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 9330 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TSTRING %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }			 
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 9342 "pnfha.ypp"
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
			 else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "seg2")
			 {
			  if ((yyvsp[(2) - (4)]).to_string().get().getString() == "%accmumulator")
			  {
			   conprint("SEGVLOAD TBOOLEAN %s\n", (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 9524 "pnfha.ypp"
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

  case 425:

/* Line 1455 of yacc.c  */
#line 9543 "pnfha.ypp"
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

  case 426:

/* Line 1455 of yacc.c  */
#line 9557 "pnfha.ypp"
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

  case 427:

/* Line 1455 of yacc.c  */
#line 9570 "pnfha.ypp"
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

  case 428:

/* Line 1455 of yacc.c  */
#line 9584 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[(5) - (6)]).to_number().get());
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 9594 "pnfha.ypp"
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 9604 "pnfha.ypp"
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

  case 431:

/* Line 1455 of yacc.c  */
#line 9629 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 9637 "pnfha.ypp"
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

  case 433:

/* Line 1455 of yacc.c  */
#line 9662 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 9670 "pnfha.ypp"
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

  case 435:

/* Line 1455 of yacc.c  */
#line 9695 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 9703 "pnfha.ypp"
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

  case 437:

/* Line 1455 of yacc.c  */
#line 9728 "pnfha.ypp"
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 9736 "pnfha.ypp"
    {
			 if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"get\"")
			 {
			  conprint("STRUCTGET TVOID 0V\n");
			 }
			 else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"type1\"")
			 {
			  conprint("STRUCTTYPE TVOID 0V\n");
			 }
			 else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"type2\"")
			 {
			  conprint("STRUCTTYPE2 TVOID 0V\n");
			 }
			 else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"name1\"")
			 {
			  conprint("STRUCTNAME2 TVOID 0V\n");
			 }
			 else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"name2\"")
			 {
			  conprint("STRUCTNAME3 TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid load type.");
			;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 9761 "pnfha.ypp"
    {
			 if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"get\"")
			 {
			  conprint("UNIONGET TVOID 0V\n");
			 }
			 else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"type1\"")
			 {
			  conprint("UNIONTYPE TVOID 0V\n");
			 }
			 else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"type2\"")
			 {
			  conprint("UNIONTYPE2 TVOID 0V\n");
			 }
			 else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"name1\"")
			 {
			  conprint("UNIONNAME2 TVOID 0V\n");
			 }
			 else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "\"name2\"")
			 {
			  conprint("UNIONNAME3 TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid load type.");
			;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 9786 "pnfha.ypp"
    {
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "tstruct")
			 {
			  conprint("STRUCTUSE TSTRING \"%s\"\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "tunion")
			 {
			  conprint("UNIONUSE TSTRING \"%s\"\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror((char *)"Invalid object type.");
			;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 9799 "pnfha.ypp"
    {
			 if ((yyvsp[(3) - (5)]).to_string().get().getString() == "seg2")
			 {
			  if ((yyvsp[(2) - (5)]).to_string().get().getString() == "%accumulator")
			  {
			   switch ((yyvsp[(4) - (5)]).getType())
			   {
		 	    case TVOID:
			    {
			     conprint("SEGVLOAD TVOID %g\n", (yyvsp[(5) - (5)]).to_number().get());
			    }
			    break;

			    case TBOOLEAN:
			    {
			     conprint("SEGVLOAD TBOOLEAN %g\n", (yyvsp[(5) - (5)]).to_number().get());
			    }
			    break;

			   case TNUMBER:
			    {
			     conprint("SEGVLOAD TNUMBER %g\n", (yyvsp[(5) - (5)]).to_number().get());
			    }
			    break;

			    case TCHARACTER:
			    {
			     conprint("SEGVLOAD TCHARACTER %g\n", (yyvsp[(5) - (5)]).to_number().get());
			    }
			    break;

			    case TSTRING:
			    {
			     conprint("SEGVLOAD TSTRING %g\n", (yyvsp[(5) - (5)]).to_number().get());
			    }
			    break;

			    default:
			     yyerror((char *)"Invalid type.");
			   }
			  }
			  else
			   yyerror((char *)"Invalid register type.");
			 }
			 else
			  yyerror((char *)"Invalid load type.");
			;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 9849 "pnfha.ypp"
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

  case 443:

/* Line 1455 of yacc.c  */
#line 9869 "pnfha.ypp"
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

  case 444:

/* Line 1455 of yacc.c  */
#line 9974 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 9980 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 9986 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TCHARACTER %c\n", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 9992 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TSTRING %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(operator_command);
			;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 9998 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 10004 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 10010 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 10016 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 10022 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 10028 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 10034 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 10040 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 10046 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 10052 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 10058 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 10064 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TNUMBER %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 10070 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("INC TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 10076 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("DEC TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 10082 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("AND TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 10088 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("OR TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 10094 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NOT TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 10100 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 10106 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 10112 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 10118 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 10124 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 10130 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 10136 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[(2) - (2)]).to_boolean().get();

			 conprint("EQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 10146 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[(2) - (2)]).to_boolean().get();

			 conprint("NEQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 10156 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 10162 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 10168 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 10174 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 10180 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 10186 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TNUMBER %g", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 10192 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 10198 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 10204 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 10210 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 10216 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 10222 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TCHARACTER %c", (yyvsp[(2) - (2)]).to_character().get());
			 tree.add_node(operator_command);
			;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 10228 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTAND TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 10234 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTOR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 10240 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTXOR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 10246 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTNOT TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 10252 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSL TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 10258 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSR TVOID 0V");
			 tree.add_node(operator_command);
			;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 10265 "pnfha.ypp"
    {
			 conprint("CMP TVOID 0V");
			;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 10269 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 conprint("NTIMES TVOID 0V\n");
			 tree.add_node(operator_command);
			;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 10275 "pnfha.ypp"
    {
			 ASTNode operator_command("operator_command");
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "run")
			 {
			  conprint("RUN TSTRING %s", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "jrun")
			 {
			  conprint("JRUN TSTRING %s", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "pnfrun")
			 {
			  conprint("PNFRUN TSTRING %s", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror((char *)"Bad run operator.");
			 tree.add_node(operator_command);
			;}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 10297 "pnfha.ypp"
    {
			 ASTNode top_commandp1("top_commandp1");

			 intop = true;
			 ++topcounter;

			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp1);
			;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 10308 "pnfha.ypp"
    {
			 ASTNode top_commandp2("top_commandp2");			 

			 tree.add_node(top_commandp2);
			;}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 10314 "pnfha.ypp"
    {
			 ASTNode top_commandp3("top_commandp3");

			conprint("IFEND TVOID 0V\n"); 
			conprint("ENDIF TVOID 0V\n");

			 tree.add_node(top_commandp3);
			;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 10323 "pnfha.ypp"
    {
			 ASTNode top_commandp4("top_commandp4");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp4);
			;}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 10332 "pnfha.ypp"
    {
			 ASTNode top_commandp5("top_commandp5");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");
			 conprint("EIF TVOID 0V\n");

			 tree.add_node(top_commandp5);
			;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 10344 "pnfha.ypp"
    {
			 ASTNode st_command("st_command");
			 conprint("ST TVOID 0V\n");
			 tree.add_node(st_command);
			;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 10352 "pnfha.ypp"
    {
			 ASTNode stack_command("stack_command");
			 conprint("PUSH TVOID 0V\n");
			 tree.add_node(stack_command);
			;}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 10358 "pnfha.ypp"
    {
			 ASTNode stack_command("stack_command");
			 conprint("POP TVOID 0V\n");
			 tree.add_node(stack_command);
			;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 10366 "pnfha.ypp"
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

  case 504:

/* Line 1455 of yacc.c  */
#line 10379 "pnfha.ypp"
    {
			 ASTNode rm_command("rm_command");
			 conprint("ATOC TVOID 0V\n");
			 tree.add_node(rm_command);
			;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 10385 "pnfha.ypp"
    {
			 conprint("ATOSP TVOID 0V\n");
			;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 10389 "pnfha.ypp"
    {
			 conprint("SPTOA TVOID 0V\n");
			;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 10393 "pnfha.ypp"
    {
			 ASTNode rm_command("rm_command");
			 conprint("SWITCH TVOID 0V\n");
			 tree.add_node(rm_command);
			;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 10401 "pnfha.ypp"
    {
			 ASTNode crash_command("crash_command");
			 conprint("CRASH TSTRING %s", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(crash_command);
			;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 10409 "pnfha.ypp"
    {
			 ASTNode version_command("version_command");

			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "pnf")
  			  conprint("VERSION TVOID %f\n", (yyvsp[(3) - (3)]).to_number().get());
			 else if ((yyvsp[(2) - (3)]).to_string().get() == "pnfasm")
			  conprint("version TVOID 0V\n");
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "normal")
  			  ; // Not used yet. This is the first version.
                         else
			  yyerror("Invalid version type.");

			 tree.add_node(version_command);
			;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 10424 "pnfha.ypp"
    {
			 ASTNode version_command("version_command");

			 conprint("MODE TVOID %f\n", (yyvsp[(2) - (2)]).to_number().get());


			 tree.add_node(version_command);
			;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 10433 "pnfha.ypp"
    {
			 ASTNode version_command("version_command");

			 conprint("EXTMODE TVOID %f\n", (yyvsp[(2) - (2)]).to_number().get());

			 tree.add_node(version_command);
			;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 10443 "pnfha.ypp"
    {
			 ASTNode halt_command("halt_command");
			 conprint("HALT TVOID 0V\n");
			 tree.add_node(halt_command);
			;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 10451 "pnfha.ypp"
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

  case 514:

/* Line 1455 of yacc.c  */
#line 10466 "pnfha.ypp"
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("RET TVOID 0V\n");
			 tree.add_node(subroutine_command);
			;}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 10472 "pnfha.ypp"
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("CALL TVOID %g\n", (yyvsp[(2) - (2)]).to_number().get());
			 tree.add_node(subroutine_command);
			;}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 10478 "pnfha.ypp"
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

  case 517:

/* Line 1455 of yacc.c  */
#line 10609 "pnfha.ypp"
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

  case 518:

/* Line 1455 of yacc.c  */
#line 10643 "pnfha.ypp"
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

  case 519:

/* Line 1455 of yacc.c  */
#line 10762 "pnfha.ypp"
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

  case 520:

/* Line 1455 of yacc.c  */
#line 10986 "pnfha.ypp"
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

  case 521:

/* Line 1455 of yacc.c  */
#line 11007 "pnfha.ypp"
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
			  else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "seg1")
			   conprint("SEGSTORE TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get().getString() == "seg2")
			   conprint("SEGVSTORE TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
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

  case 522:

/* Line 1455 of yacc.c  */
#line 11044 "pnfha.ypp"
    {
			 if ((yyvsp[(2) - (2)]).to_string().get().getString() == "stk")
			 {
			  conprint("STORESTACK TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid store type.");
			;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 11053 "pnfha.ypp"
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
			 else if ((yyvsp[(3) - (3)]).to_string().get().getString() == "seg2")
			 {
			  conprint("SEGVSTORE TVOID 0V\n");
			 }
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

  case 524:

/* Line 1455 of yacc.c  */
#line 11090 "pnfha.ypp"
    {
 			 ASTNode store_command("store_command");

			 conprint("STOREA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 11098 "pnfha.ypp"
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

  case 526:

/* Line 1455 of yacc.c  */
#line 11112 "pnfha.ypp"
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

  case 527:

/* Line 1455 of yacc.c  */
#line 11125 "pnfha.ypp"
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[(5) - (6)]).to_number().get());
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 11135 "pnfha.ypp"
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			;}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 11147 "pnfha.ypp"
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

  case 530:

/* Line 1455 of yacc.c  */
#line 11165 "pnfha.ypp"
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

  case 531:

/* Line 1455 of yacc.c  */
#line 11193 "pnfha.ypp"
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

  case 532:

/* Line 1455 of yacc.c  */
#line 11271 "pnfha.ypp"
    {
			 ASTNode add2v_command("add2v_command");

			 conprint("ADD2V TVOID 0V\n");

		         tree.add_node(add2v_command);
			;}
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 11281 "pnfha.ypp"
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

  case 534:

/* Line 1455 of yacc.c  */
#line 11300 "pnfha.ypp"
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
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "current_vmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "void")
			   conprint("MCHECK TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get() == "number")
			   conprint("MCHECK TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "vmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "void")
			   conprint("MSUPP TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get() == "number")
			   conprint("MSUPP TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "current_extvmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "void")
			   conprint("MEXTCHECK TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get() == "number")
			   conprint("MEXTCHECK TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "extvmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "void")
			   conprint("MEXTSUPP TVOID %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else if ((yyvsp[(3) - (4)]).to_string().get() == "number")
			   conprint("MEXTSUPP TNUMBER %g\n", (yyvsp[(4) - (4)]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 11363 "pnfha.ypp"
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
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "current_vmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "boolean")
			   conprint("MCHECK TBOOLEAN %s\n", (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "vmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "boolean")
			   conprint("MSUPP TBOOLEAN %s\n", (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "current_extvmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "boolean")
			   conprint("MEXTCHECK TBOOLEAN %s\n", (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "extvmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "boolean")
			   conprint("MEXTSUPP TBOOLEAN %s\n", (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 11414 "pnfha.ypp"
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
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "current_vmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "character")
			   conprint("MCHECK TCHARACTER %c\n", (yyvsp[(4) - (4)]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "vmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "character")
			   conprint("MSUPP TCHARACTER %c\n", (yyvsp[(4) - (4)]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "current_extvmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "character")
			   conprint("MEXTCHECK TCHARACTER %c\n", (yyvsp[(4) - (4)]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "extvmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "character")
			   conprint("MEXTSUPP TCHARACTER %c\n", (yyvsp[(4) - (4)]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 11465 "pnfha.ypp"
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
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "current_vmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "string")
			   conprint("MCHECK TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "vmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "string")
			   conprint("MSUPP TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[(2) - (4)]).to_string().get() == "current_extvmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "string")
			   conprint("MEXTCHECK TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[(2) - (4)]).to_string().get() == "extvmode")
			 {
			  if ((yyvsp[(3) - (4)]).to_string().get() == "string")
			   conprint("MEXTSUPP TSTRING %s\n", (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			;}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 11516 "pnfha.ypp"
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

  case 539:

/* Line 1455 of yacc.c  */
#line 11535 "pnfha.ypp"
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

  case 540:

/* Line 1455 of yacc.c  */
#line 11557 "pnfha.ypp"
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

  case 541:

/* Line 1455 of yacc.c  */
#line 11590 "pnfha.ypp"
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

  case 542:

/* Line 1455 of yacc.c  */
#line 11607 "pnfha.ypp"
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

  case 543:

/* Line 1455 of yacc.c  */
#line 11624 "pnfha.ypp"
    {
			 ASTNode file_command("file_command");

			 conprint("FIEOF TVOID 0V\n");

			 tree.add_node(file_command);
			;}
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 11634 "pnfha.ypp"
    {
			 ASTNode meml_command("meml_command");

			 conprint("MEML TVOID 0V\n");

			 tree.add_node(meml_command);
			;}
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 11644 "pnfha.ypp"
    {
			 ASTNode pnfasm_command("pnfasm_command");

			 conprint("pnf %s %s %s\n", strip_quotes((yyvsp[(2) - (4)]).to_string().get()).getString().c_str(), 
						 strip_quotes((yyvsp[(3) - (4)]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[(4) - (4)]).to_string().get()).getString().c_str());

			 tree.add_node(pnfasm_command);
			;}
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 11655 "pnfha.ypp"
    {
			 ASTNode array_length_command("array_length_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			 conprint("ALENGTH TVOID 0V\n");

			 tree.add_node(array_length_command);
			;}
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 11665 "pnfha.ypp"
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

  case 548:

/* Line 1455 of yacc.c  */
#line 11684 "pnfha.ypp"
    {
			 conprint("FRET TVOID 0V\n");
			;}
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 11694 "pnfha.ypp"
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

  case 552:

/* Line 1455 of yacc.c  */
#line 11738 "pnfha.ypp"
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			;}
    break;

  case 553:

/* Line 1455 of yacc.c  */
#line 11748 "pnfha.ypp"
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

  case 554:

/* Line 1455 of yacc.c  */
#line 11795 "pnfha.ypp"
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			;}
    break;

  case 555:

/* Line 1455 of yacc.c  */
#line 11805 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(5) - (8)]);
			;}
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 11811 "pnfha.ypp"
    {
			 (yyval) = (yyvsp[(5) - (8)]);
			;}
    break;

  case 557:

/* Line 1455 of yacc.c  */
#line 11817 "pnfha.ypp"
    {
			 conprint("STRUCTUSING TVOID 0V\n");
			;}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 11821 "pnfha.ypp"
    {
			 conprint("STRUCTUSINGNAME TVOID 0V\n");
			;}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 11827 "pnfha.ypp"
    {
			 conprint("UNIONUSING TVOID 0V\n");
			;}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 11831 "pnfha.ypp"
    {
			 conprint("UNIONUSINGNAME TVOID 0V\n");
			;}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 11837 "pnfha.ypp"
    {
			 conprint("CPY TVOID 0V\n");
			;}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 11843 "pnfha.ypp"
    {
			 conprint("ADDSEG TVOID 0V\n");
			;}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 11847 "pnfha.ypp"
    {
			 conprint("REMSEG TVOID 0V\n");
			;}
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 11851 "pnfha.ypp"
    {
			 if ((yyvsp[(2) - (3)]).to_string().get().getString() == "collapse")
			 {
			  conprint("COLLSEG TNUMBER %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 else if ((yyvsp[(2) - (3)]).to_string().get().getString() == "expand")
			 {
			  conprint("EXPSEG TNUMBER %g\n", (yyvsp[(3) - (3)]).to_number().get());
			 }
			 else
			  yyerror((char *)"Invalid CETYPE.");
			;}
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 11864 "pnfha.ypp"
    {
			 conprint("CPYSEG TVOID 0V\n");
			;}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 11868 "pnfha.ypp"
    {
			 conprint("PUSHSEG TVOID 0V\n");
			;}
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 11872 "pnfha.ypp"
    {
			 conprint("POPSEG TVOID 0V\n");
			;}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 11876 "pnfha.ypp"
    {
			 conprint("TOPSEG TVOID 0V\n");
			;}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 11882 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#BIN#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 11888 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#PBIN#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 11894 "pnfha.ypp"
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#LIB#\n");
			 tree.add_node(pp_directive);
			;}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 11902 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include %s", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 11908 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include <%s>", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 11914 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 11920 "pnfha.ypp"
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			;}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 11926 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), 
						    (yyvsp[(3) - (3)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 11933 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 11939 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endm\n");
			 tree.add_node(pp_statement);
		 	;}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 11945 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 11951 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 11957 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#infdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 11963 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#else\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 11969 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endif\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 11975 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_DATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 11981 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_TIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 11987 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_LINE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 11993 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_FILE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 11999 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CDATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 12005 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CTIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 12011 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
		 	 conprint("%%include %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 12017 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%include <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 12023 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 12029 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import <%s>\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 12035 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), 
						     (yyvsp[(3) - (3)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 12042 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 12048 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endm\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 12054 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 12060 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 12066 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%infdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 12072 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%else\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 12078 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endif\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 12084 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_DATE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 12090 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_TIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 12096 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_LINE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 12102 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_FILE()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 12108 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CDATE()\n");
			 tree.add_node(pp_statement);
			;}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 12114 "pnfha.ypp"
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CTIME()\n"); 
			 tree.add_node(pp_statement);
			;}
    break;



/* Line 1455 of yacc.c  */
#line 17008 "pnfha.tab.cpp"
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
#line 12120 "pnfha.ypp"

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

