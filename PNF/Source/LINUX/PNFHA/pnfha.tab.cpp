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
#line 1 "pnfha.ypp" /* yacc.c:339  */

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

#line 843 "pnfha.tab.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OPINC = 258,
    OPDEC = 259,
    NEG = 260,
    OPNOT = 261,
    OPBTNOT = 262,
    OPAMP = 263,
    OPPOWER = 264,
    OPROOT = 265,
    OPTIMES = 266,
    OPDIV = 267,
    OPMODULUS = 268,
    OPMINUS = 269,
    OPPLUS = 270,
    OPBTSL = 271,
    OPBTSR = 272,
    OPLSS = 273,
    OPLEQU = 274,
    OPGTR = 275,
    OPGEQU = 276,
    OPCMP = 277,
    OPEQU = 278,
    OPNEQU = 279,
    OPBTXOR = 280,
    OPBTOR = 281,
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 1084 "pnfha.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1905

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  196
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  214
/* YYNRULES -- Number of rules.  */
#define YYNRULES  607
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1096

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   450

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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPINC", "OPDEC", "NEG", "OPNOT",
  "OPBTNOT", "OPAMP", "OPPOWER", "OPROOT", "OPTIMES", "OPDIV", "OPMODULUS",
  "OPMINUS", "OPPLUS", "OPBTSL", "OPBTSR", "OPLSS", "OPLEQU", "OPGTR",
  "OPGEQU", "OPCMP", "OPEQU", "OPNEQU", "OPBTXOR", "OPBTOR", "OPAND",
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
  "pp_statement", YY_NULLPTR
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

#define YYPACT_NINF -824

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-824)))

#define YYTABLE_NINF -118

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -824,  1075,  -824,  -824,  -824,  -159,    22,  1266,  -824,  1266,
     395,   395,   225,   534,   488,  1545,  1545,  1545,  1545,  1545,
     410,  1566,  -824,  -824,   925,   925,   925,   925,  -824,  1658,
    1658,  -824,  -824,  -824,  -824,    36,   101,  -824,  -824,  -824,
    -824,  -824,  -824,  1545,   257,  -824,   -81,  1632,    41,   612,
     154,   726,   726,  1545,    65,    59,   227,    71,  -824,  -824,
    -824,    68,  -824,   126,   142,   257,   103,  -824,    85,  -824,
      92,   168,   180,   153,   -19,   159,   179,   219,   222,   250,
     277,  -824,  -824,   255,  -824,  -824,   298,   286,   292,   307,
     309,  -824,   726,   726,   342,  -824,   353,   367,   308,   315,
     399,   405,   364,  -824,  -824,   304,   403,   407,  -824,   417,
     420,   404,   406,   300,  1545,  1545,  -824,    23,  -824,  -824,
    -824,   -17,   -12,   418,   446,  -824,   447,   448,   449,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,    -8,    -7,   452,
     457,  -824,   459,   461,   462,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,   473,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,   419,  -824,   388,  -824,   370,  -824,   414,
    -824,  -824,  -824,   480,  -824,   261,  1809,  1621,   505,  1788,
    -824,  -824,  -824,  -824,   482,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
     495,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,   489,  -824,  -824,  -824,  -824,
    -824,  -824,   473,   395,   395,   488,  1545,   488,   410,   395,
    -824,  1744,   674,  1872,  1744,   674,  1872,   488,   488,   225,
     488,   225,   392,  1872,  1545,  1545,  1545,  1545,  -824,  1744,
     488,  1872,  1833,  1833,  1833,  1833,  1833,   410,   410,   410,
    1744,  1872,   925,   925,  1566,  1833,  1666,   527,   925,  1833,
    1666,  1833,  1666,  1833,  1666,  1833,  1666,   115,  1658,   392,
    1833,  1666,   392,  1833,  1666,   534,   726,  1852,   509,   512,
     513,   285,  1688,  1762,    46,  1736,   514,   518,   517,   519,
      14,   521,  1833,   257,   527,   257,  1545,   925,   925,   925,
     925,   925,  1566,  1545,  1545,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,   115,   115,  -824,   522,  -824,   520,
    -824,  -824,  -824,  -824,  -824,  1833,   535,   510,  1554,   498,
    1545,   536,   454,   540,   550,   544,   545,   530,   594,  -824,
     726,  1266,   527,  1545,  -824,   543,  1833,   549,   552,  -824,
     546,   524,   553,  -824,   538,  -824,   561,   484,   568,  1266,
    -824,  -824,   560,  1266,  -824,  1266,   254,   257,   537,   257,
    -824,  -824,  -824,   564,   593,   587,   589,   595,   132,   596,
    -824,  -824,   601,    19,   599,    96,  1266,   590,   591,   598,
    1833,  1833,  -824,  -824,  -824,  -824,  -824,  -824,  1545,  -824,
     602,  -824,   613,   614,  -824,  -824,  -824,  -824,  -824,   615,
    -824,   616,   619,  -824,  -824,  -824,  -824,  -824,   606,  -824,
     515,  -824,  -824,   630,  -824,  -824,    63,    94,  -824,  -824,
     625,   688,   739,   744,   778,  1545,   837,   858,   897,   971,
     985,   990,  1456,  1458,  1470,  1494,  1506,  1508,  1536,  -824,
    -824,    60,   206,   270,   318,   112,   374,   451,    79,  -824,
    -824,   488,   488,   488,   488,   488,   488,   488,   488,   488,
    -824,  -824,   610,  1712,  1775,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,  1545,  1545,   112,   112,   112,   112,
     112,   112,   287,   115,   115,    61,   257,   115,  -824,  -824,
    -824,  -824,   621,   622,   623,   626,   627,   628,   643,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,   527,
    1833,  1833,  1666,  1833,  1666,  1833,  1666,  1833,  1666,  1833,
    1666,  1833,  1666,   527,  1833,  1833,  1833,  1833,  1833,  1833,
    1833,  1833,  1833,  1833,  1833,   392,   392,   726,  -824,   257,
    -824,  1554,   392,  1833,  1666,   527,   204,  1833,  -824,   656,
     542,   121,  -824,  -824,  1545,  -824,  1833,   665,    53,  1833,
    -824,  -824,  -824,  -824,  1545,   651,  1545,  -824,   661,   576,
     163,  -824,   473,   473,  1554,  1833,   527,  -824,   527,  -824,
     669,   676,   677,   670,   574,  1545,   671,   145,  -824,   668,
     183,  -824,  -824,   675,   312,   171,   597,   689,   600,   691,
    -824,  1833,   531,   532,  -824,   541,   554,  -824,  -824,  -824,
     690,  -824,  1266,  1266,  -824,  -824,   703,  -824,  -824,  -824,
    1879,  -824,  1879,  -824,  1879,  -824,   551,  -824,   551,   551,
    -824,   294,  -824,   294,  -824,   397,  -824,   397,  -824,  1833,
    -824,  1833,  -824,  1833,  -824,  1833,  -824,  1833,  -824,  1833,
    -824,  1833,  -824,  -824,  -824,  -824,   112,   112,   112,  -824,
     674,  -824,   674,  -824,   182,  -824,   182,   182,  -824,  -824,
    -824,  -824,  -824,  -824,  1872,  1872,   125,   125,   125,   400,
     400,   709,  -824,   686,  -824,   527,  -824,  1545,  1833,   620,
      45,  -824,   710,   314,  1603,   713,  -824,  1833,  -824,  1833,
    -824,    75,  -824,   652,   392,  1833,  1666,   527,  -824,   716,
     719,   730,  -824,   785,  -824,  -824,   723,   319,   711,   724,
     729,   748,   728,   732,   755,  -824,   740,   657,  -824,   757,
     662,  -824,  -824,  -824,  -824,  -824,  1266,  1266,  -824,    -6,
      -5,  1266,  -824,  -824,  -824,  1833,  1545,  -824,   905,   751,
     760,   767,  1554,  -824,   789,  -824,   955,   695,   797,   790,
    -824,   707,   792,  -824,   776,   791,   794,  -824,   807,   801,
     147,  -824,   809,   804,   717,   818,   802,    -1,  -824,   821,
     808,    -4,  -824,   473,   473,  1266,  -824,  -824,   303,  -824,
    -824,  1032,  -824,  -824,   826,   815,   392,  1833,  1666,   527,
    -824,  -824,  -824,  -824,  -824,  -824,   819,   736,  -824,  -824,
     830,   824,   165,   813,  -824,   827,   329,   169,   816,  -824,
     726,  -824,  -824,  -824,   726,  -824,  -824,  -824,   828,   832,
     473,   844,   846,  -824,  -824,  -824,   218,   825,  -824,  -824,
    -824,  -824,   795,   795,   793,   793,  1266,  1266,   849,   856,
     852,   260,   840,  -824,   851,   330,  -824,  -824,   841,   855,
     864,  -824,   859,   333,  -824,  -824,  1266,  -824,   860,  -824,
     884,  -824,  -824,   872,  -824,  -824,  1266,  -824,   877,   341,
    -824,  -824,  -824,  -824,  -824,  -824,   726,   833,  -824,  -824,
     726,   831,  -824,  -824,   473,   344,  -824,  -824,  -824,  -824,
     887,   351,  -824,  -824,   893,  -824,   888,  -824,  -824,   895,
     896,  -824,   892,   473,  -824,  -824,  1266,  1266,  -824,  1266,
    1266,   354,   899,  -824,   894,  -824,   901,  -824,  -824,   903,
    -824,   814,  -824,   907,  -824,   904,   898,  -824,   909,   924,
     902,   918,   913,   847,   473,   473,  1266,   473,   473,  -824,
     921,   935,   942,  -824,  -824,   944,  -824,   958,  -824,  1266,
     940,   964,   953,  -824,  -824,   960,  -824,  -824,  -824,   961,
    -824,   473,   975,   979,  1266,  -824,   969,  1266,  1266,   980,
    -824,  1266,  -824,   926,   371,   988,  -824,  -824,   972,   967,
     129,   968,   926,  -824,  -824,   473,   973,   473,   473,  -824,
    1266,   473,  -824,  -824,  -824,   726,  -824,  -824,   986,  -824,
     974,  -824,   982,  -824,  -824,  -824,   987,  -824,  -824,  -824,
    1002,  -824,   473,  1266,   906,  1266,   992,  -824,  -824,   988,
     983,  -824,   525,   906,  1266,   -31,  -824,  -824,   473,  1014,
    -824,  -824,  1020,  1010,  -824,  -824,   473,  -824,  1022,  -824,
    -824,  1000,  -824,  -824,  -824,  -824
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     7,     3,     0,     6,    72,     5,    72,
     460,   461,   464,   488,   485,   456,   458,   450,   452,   454,
     448,   444,   489,   490,   467,   469,   468,   470,   492,   465,
     466,   487,   486,   462,   463,     0,     8,   128,   130,   135,
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
     172,   144,   163,   185,   146,   165,   187,     0,     0,     0,
       0,     0,   131,   174,     0,     0,     0,     0,   247,   151,
       0,   173,   457,   459,   451,   453,   455,     0,     0,     0,
     141,   182,     0,     0,     0,   445,   446,   447,     0,   475,
     481,   477,   483,   476,   482,   478,   484,     0,     0,   471,
     473,   479,   472,   474,   480,     0,     0,   172,     0,     0,
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
     510,   511,   563,   562,   566,   567,   568,   565,     0,   572,
       0,   574,     0,     0,   577,   579,   580,   581,   590,     0,
     592,     0,     0,   595,   597,   598,   599,   495,     0,    73,
       0,    86,    96,     0,    80,    20,     0,     0,   145,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     166,     0,     0,     0,     0,     0,     0,     0,     0,   186,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   557,   559,
     129,   134,     0,     0,     0,     0,     0,     0,     0,   154,
     167,   171,   189,   198,   255,   558,   560,   118,   116,   494,
     241,   207,   219,   208,   220,   205,   217,   206,   218,   204,
     216,   203,   215,   227,   248,   249,   237,   239,   238,   240,
     253,   235,   236,   243,   242,   199,   201,     0,   411,     0,
     412,     0,   419,   420,   421,   422,     0,   424,   425,     0,
       0,     0,   438,   439,     0,   443,   442,     0,     0,   509,
     516,    24,    25,   518,     0,     0,   523,   525,     0,     0,
       0,   531,   108,   115,     0,   538,   539,   540,   541,   413,
       0,     0,     0,     0,     0,     0,     0,     0,   347,     0,
       0,   256,   356,     0,     0,     0,   303,     0,   312,     0,
     440,   564,     0,     0,   576,     0,     0,   594,   496,    81,
       0,    75,    72,    72,   102,   200,   132,   202,   133,   244,
     148,   213,   142,   214,   143,   211,   138,   212,   139,   140,
     210,   137,   209,   136,   250,   152,   251,   153,   231,   192,
     233,   194,   232,   193,   234,   195,   252,   197,   229,   190,
     230,   191,   246,   150,   245,   149,     0,     0,     0,   225,
     161,   226,   162,   223,   158,   224,   159,   160,   222,   157,
     221,   156,   228,   169,   183,   184,   179,   180,   181,   178,
     177,   175,   176,   551,   281,   415,   423,   417,   416,   426,
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -824,  -824,  -824,  -824,  1058,  -824,    -9,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,    28,  -824,   -11,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,   178,  -824,  -824,
    -824,  -824,  -824,   192,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -319,   -47,
     -28,    90,    -2,   195,    83,   575,  -824,  -824,   -23,   -15,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
      32,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,   246,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,   243,  -824,  -824,  -824,  -824,  -824,  -824,
    -823,  -824,  -824,  -824,  -824,  -824,  -824,    37,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,  -824,
    -824,  -824,  -824,  -824
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     242,   547,   350,   352,   353,   354,   874,   310,   251,   254,
     447,   269,   316,   272,   273,   274,   275,   276,   280,   285,
     317,   429,   289,   291,   293,   295,   431,   300,   303,   866,
     438,   440,   862,   312,     8,   447,   447,   422,   423,   243,
     244,   322,   259,   305,   247,   401,   402,  -117,   264,   265,
     248,   355,   246,   628,     9,   922,   923,   924,   925,   266,
     380,   488,     9,   696,   697,   325,   306,   629,   376,   297,
      37,    38,    39,    40,    41,   267,   526,   541,   264,   265,
      44,    39,   246,   307,   736,   424,   425,   426,   347,   266,
     698,   826,   541,   527,   447,   264,   265,    40,    38,   246,
     297,  1087,   262,   356,   287,   267,   266,   699,   381,   323,
     655,    39,   420,   421,   357,   696,   697,    41,   314,   299,
     302,   297,   267,    44,   527,   311,   712,   324,    39,    38,
     632,   368,   243,   244,   369,   259,   305,   247,   827,   496,
     497,   657,   698,   248,   633,   527,   820,   816,   372,    40,
      38,   374,   498,   499,  1004,   731,   370,   243,   244,   306,
     259,   305,   247,    37,    38,    39,    40,    41,   248,   732,
     787,   375,   371,    44,   107,   373,   307,   430,   427,   755,
     428,   854,   432,   308,   306,   309,   439,   441,    37,    38,
      39,    40,    41,   756,   742,   855,   520,   521,    44,   893,
     795,   307,   765,   901,   447,   252,   255,   264,   265,   696,
     697,   246,   447,   894,   759,   377,   286,   902,   266,   290,
     292,   294,   296,   760,   301,   304,  1068,   378,   257,   258,
     313,   259,   379,   247,   267,   351,   698,   383,   382,   260,
      39,   251,   254,    40,   269,   384,   280,   503,   318,   389,
     319,   726,   917,   701,   624,   261,   625,   264,   265,   727,
      38,   246,   251,   254,   280,   503,   918,   107,   266,   390,
    1095,  1052,   250,   696,   697,   251,   254,   503,   310,   385,
     251,   254,   503,   316,   267,   358,   503,   323,   456,   457,
      39,   317,   107,   359,   939,    41,   503,   391,   386,   387,
     698,    44,   394,   269,   312,   388,   360,    40,   940,   614,
     512,   513,   456,   457,   523,   524,   531,   703,   531,   514,
     515,   696,   697,   597,   550,   551,   553,   555,   557,   559,
     561,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   873,   763,   447,   790,   361,   362,   698,   262,
     805,   522,   764,   363,   791,    40,   583,   392,   587,   806,
     899,   945,   598,   364,   951,   705,   596,   525,   397,   900,
     946,   599,   963,   952,   365,   398,   366,   696,   697,   396,
     610,   964,   974,   972,   612,   447,   613,   262,   522,   314,
     399,   975,   400,   989,   615,   447,   311,   403,   243,   244,
     404,   245,   246,   247,   698,   405,   525,   635,   549,   248,
    1044,    40,   447,   277,   278,   563,   245,   246,   247,   523,
     524,   708,   514,   515,   248,   249,   641,   498,   499,   406,
     410,    39,    40,   413,   575,   576,   407,   408,   252,   255,
     279,   585,   250,   409,   504,   411,    39,   415,   582,   414,
     416,   417,   419,   418,   696,   697,   433,   250,   660,   662,
     664,   666,   668,   669,   671,   673,   675,   677,   679,   681,
     683,   685,   687,   689,   691,   693,   695,   252,   255,   504,
     616,   698,   618,   504,   434,   435,   436,   437,    40,   451,
     442,   257,   258,   504,   245,   443,   247,   444,   710,   445,
     446,   313,   260,   660,   662,   664,   666,   668,   671,   673,
     675,   677,   693,   695,   447,   452,   448,   453,   270,   455,
     488,   500,   552,   554,   556,   558,   560,   562,   243,   244,
     724,   259,   305,   247,   501,   250,   502,   264,   265,   248,
     528,   246,   526,   529,   530,   543,   656,   658,   266,   544,
     545,   577,   546,   584,   548,   306,   586,   580,   578,    37,
      38,    39,    40,    41,   267,   510,   511,   512,   513,    44,
      39,   713,   307,   579,   588,   589,   514,   515,   590,   503,
     591,   268,   592,   593,   728,   253,   256,   263,   594,   271,
     600,   601,   734,   603,   602,   281,   606,   264,   265,   607,
     605,   246,   737,   604,   739,   608,   609,   611,   266,   713,
     315,   619,   745,   656,   658,   243,   244,   522,   259,   305,
     247,   617,   620,   753,   267,   621,   248,   622,   264,   265,
      39,   627,   246,   623,   626,   631,   649,   636,   638,   266,
     642,   595,   306,   779,   780,   640,    37,    38,    39,    40,
      41,   643,   644,   645,   646,   267,    44,   647,   650,   307,
     654,    39,   725,   107,   525,   723,   730,  1083,   678,   680,
     682,   522,   659,   684,   686,   688,   700,   702,   704,   706,
     707,   709,   711,   516,   517,   518,   519,   485,   520,   521,
     690,   264,   265,   348,   729,   246,   735,   747,   738,   740,
     741,   748,   266,   752,   744,   749,   750,  1048,   751,   754,
     758,   700,   702,   704,   706,   709,   711,   762,   267,   766,
     778,   767,   769,   770,    39,   785,   772,   773,   788,   243,
     244,   524,   259,   305,   247,   661,   774,   499,   349,   796,
     248,   783,   264,   265,   786,   793,   246,   264,   265,   775,
     107,   246,   789,   266,   800,   798,   306,   801,   266,   802,
      37,    38,    39,    40,    41,   804,   807,   823,   824,   267,
      44,   808,   828,   307,   267,    39,   504,   809,   810,   812,
      39,   264,   265,   811,   831,   246,   663,   815,   458,   459,
     837,   665,   266,   505,   506,   507,   508,   509,   465,   510,
     511,   512,   513,   813,   819,   816,   833,   834,   267,   746,
     514,   515,   820,   907,    39,   835,   870,   909,   253,   256,
     263,   841,   271,   281,   315,   667,   843,   844,   845,   847,
     848,   849,   253,   256,   263,   281,   315,   852,   850,   857,
     264,   265,   851,   853,   246,   315,   858,   860,   859,   861,
     864,   266,   253,   256,   315,   865,   876,   877,   890,   888,
     891,   264,   265,   912,   107,   246,   892,   267,   897,   898,
     911,   905,   266,    39,   914,   839,   915,   934,   935,   965,
     921,   315,   836,   968,   670,   930,   926,   936,   267,   937,
     938,   252,   255,   504,    39,   943,   947,   953,   944,   954,
     264,   265,   948,   958,   246,   672,   950,   961,   458,   459,
     803,   266,   949,   505,   506,   507,   508,   509,   465,   510,
     511,   512,   513,   955,   962,   969,   966,   267,   282,   283,
     514,   515,   246,    39,   973,   976,   978,   980,   981,   266,
     982,   990,   991,   993,   674,   996,   998,   984,   985,  1000,
     987,   988,  1002,  1003,  1006,   288,  1005,  1007,   458,   459,
    1009,    39,    40,   505,   506,   507,   508,   509,   465,   510,
     511,   512,   513,  1008,   264,   265,  1015,  1011,   246,  1010,
     514,   515,  1016,  1053,  1017,   266,  1020,   838,   264,   265,
    1024,  1022,   246,   264,   265,  1025,  1026,   246,  1066,   266,
    1028,   267,  1029,  1031,   266,  1035,  1033,    39,  1037,  1038,
    1034,  1036,  1041,  1039,  1050,   267,  1042,  1045,   676,  1067,
     267,    39,  1051,  1058,  1070,  1053,    39,  1072,  1061,  1069,
     832,  1062,   678,  1074,  1079,   458,   459,   680,  1081,  1076,
     505,   506,   507,   508,   509,   465,   510,   511,   512,   513,
    1089,  1090,  1091,  1092,  1075,  1094,  1078,   514,   515,     6,
    1059,   929,  1085,   863,   867,  1086,   714,   715,   716,   717,
     718,   719,   720,   721,   722,     2,     3,   933,    -8,    -8,
     842,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,  1084,    -8,  1080,    -8,     0,    -8,
      -8,    -8,    -8,    -8,    -8,     0,     0,     0,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
       0,    -8,    -8,     0,    -8,     0,    -8,    -8,    -8,     0,
      -8,     0,    -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,    -8,    -8,     0,     0,     0,   875,     0,     0,
      -8,    -8,    -8,    -8,    -8,     0,     0,     0,     0,     0,
      -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,     0,    -8,     0,     0,    -8,     0,
       0,    -8,     0,    -8,     0,    -8,     0,     0,     0,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,     0,     0,     0,    -8,
      -8,     0,    -8,     0,    -8,     0,    -8,     0,    -8,    -8,
      -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -4,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,    35,     0,    36,     0,
      37,    38,    39,    40,    41,    42,     0,     0,     0,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     0,    55,    56,     0,    57,     0,    58,    59,    60,
       0,    61,     0,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,     0,     0,     0,     0,
       0,    78,    79,     0,    80,    81,     0,   -85,    82,  -101,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,    98,     0,     0,    99,
       0,     0,   100,     0,   101,     0,   102,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
     110,   -95,     0,   111,     0,   112,     0,   113,     0,   114,
     115,   116,   117,     0,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   264,
     265,   264,   265,   246,     0,   246,     0,     0,     0,     0,
     266,     0,   266,   264,   265,     0,     0,   246,     0,     0,
       0,     0,     0,     0,   266,     0,   267,     0,   267,     0,
       0,     0,    39,     0,    39,     0,     0,   264,   265,     0,
     267,   246,     0,   682,     0,   684,    39,     0,   266,   264,
     265,   264,   265,   246,     0,   246,     0,   686,     0,     0,
     266,     0,   266,     0,   267,     0,     0,     0,     0,     0,
      39,     0,     0,     0,     0,     0,   267,     0,   267,   264,
     265,   688,    39,   246,    39,     0,     0,     0,   264,   265,
     266,     0,   246,   690,     0,   692,     0,   282,   283,   266,
     297,   246,     0,     0,     0,     0,   267,     0,   266,   282,
     283,     0,    39,   246,     0,   267,     0,     0,     0,     0,
     266,    39,     0,   694,   581,     0,     0,     0,     0,    38,
      39,    40,    41,     0,     0,     0,   284,     0,    44,     0,
       0,     0,    39,    40,    41,     0,   458,   459,     0,     0,
      44,   505,   506,   507,   508,   509,   465,   510,   511,   512,
     513,     0,     0,     0,   479,   480,     0,     0,   514,   515,
     481,   482,   483,   484,   485,   486,   487,     0,     0,     0,
     326,   327,   328,   329,   330,   792,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   282,   283,     0,   297,   246,     0,     0,     0,   479,
     480,     0,   266,     0,   346,   516,   517,   518,   519,   485,
     520,   521,     0,     0,     0,     0,     0,     0,   298,     0,
       0,   458,   459,    38,    39,    40,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   532,   533,   534,   535,
     536,   537,   538,   477,   478,   458,   459,     0,     0,   539,
     505,   506,   507,   508,   509,   465,   510,   511,   512,   513,
       0,     0,     0,     0,     0,     0,     0,   514,   515,   489,
     490,     0,     0,   539,     0,   491,   492,   493,   494,   495,
     496,   497,   505,   506,   507,   508,   509,   465,   510,   511,
     512,   513,     0,   498,   499,   479,   480,   542,     0,   514,
     515,   481,   482,   483,   484,   485,   486,   487,   479,   480,
       0,     0,     0,     0,   516,   517,   518,   519,   485,   520,
     521,   489,   490,   540,     0,     0,     0,   491,   492,   493,
     494,   495,   496,   497,     0,     0,   540,     0,     0,     0,
       0,     0,   458,   459,     0,   498,   499,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   458,   459,     0,     0,
       0,   505,   506,   507,   508,   509,   465,   510,   511,   512,
     513,     0,     0,     0,     0,     0,     0,     0,   514,   515,
     326,   327,   328,   329,   330,     0,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   491,   492,   493,   494,   495,   496,   497,   506,   507,
     508,   509,   465,   510,   511,   512,   513,     0,     0,   498,
     499,     0,     0,     0,   514,   515
};

static const yytype_int16 yycheck[] =
{
       9,   320,    49,    50,    51,    52,   829,    35,    10,    11,
      41,    13,    35,    15,    16,    17,    18,    19,    20,    21,
      35,    38,    24,    25,    26,    27,    38,    29,    30,    33,
      38,    38,    33,    35,   193,    41,    41,    14,    15,     3,
       4,    43,     6,     7,     8,    92,    93,    33,     3,     4,
      14,    53,     7,    34,    40,   878,   879,   880,   881,    14,
      79,    15,    40,     3,     4,   146,    30,    48,    70,     6,
      34,    35,    36,    37,    38,    30,    15,    31,     3,     4,
      44,    36,     7,    47,    31,    62,    63,    64,    47,    14,
      30,    97,    31,    30,    41,     3,     4,    37,    35,     7,
       6,   132,    12,    38,    21,    30,    14,    47,   127,    30,
      47,    36,   114,   115,    55,     3,     4,    38,    35,    29,
      30,     6,    30,    44,    30,    35,    47,    44,    36,    35,
      34,    60,     3,     4,    66,     6,     7,     8,   143,    14,
      15,    47,    30,    14,    48,    30,   150,   148,    65,    37,
      35,    66,    27,    28,   977,    34,    30,     3,     4,    30,
       6,     7,     8,    34,    35,    36,    37,    38,    14,    48,
     125,    79,    30,    44,   138,    72,    47,   194,   155,    34,
     157,    34,   194,   147,    30,   149,   194,   194,    34,    35,
      36,    37,    38,    48,    31,    48,    14,    15,    44,    34,
     125,    47,    31,    34,    41,    10,    11,     3,     4,     3,
       4,     7,    41,    48,    31,    47,    21,    48,    14,    24,
      25,    26,    27,    40,    29,    30,  1049,    47,     3,     4,
      35,     6,    79,     8,    30,    81,    30,    58,    79,    14,
      36,   243,   244,    37,   246,    66,   248,   249,   147,    30,
     149,    47,    34,    47,   122,    30,   124,     3,     4,    55,
      35,     7,   264,   265,   266,   267,    48,   138,    14,    47,
    1093,   142,    47,     3,     4,   277,   278,   279,   306,   100,
     282,   283,   284,   306,    30,    58,   288,    30,    27,    28,
      36,   306,   138,    66,    34,    38,   298,    47,   119,   120,
      30,    44,    47,   305,   306,   126,    79,    37,    48,    55,
      16,    17,    27,    28,    27,    28,    31,    47,    31,    25,
      26,     3,     4,   370,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,    39,    31,    41,    31,   119,   120,    30,   259,
      31,   261,    40,   126,    40,    37,   358,    80,   360,    40,
      31,    31,   371,   136,    31,    47,   368,   284,    82,    40,
      40,   373,    31,    40,   147,    83,   149,     3,     4,    81,
     389,    40,    31,    39,   393,    41,   395,   297,   298,   306,
      83,    40,    83,    39,   396,    41,   306,    55,     3,     4,
      47,     6,     7,     8,    30,    38,   323,   416,   325,    14,
      39,    37,    41,     3,     4,   332,     6,     7,     8,    27,
      28,    47,    25,    26,    14,    30,   428,    27,    28,   121,
      66,    36,    37,    30,   344,   345,   121,    38,   243,   244,
      30,   358,    47,    38,   249,   141,    36,    30,   358,    42,
      30,    47,   152,    47,     3,     4,    38,    47,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   282,   283,   284,
     397,    30,   399,   288,    38,    38,    38,    38,    37,   101,
      38,     3,     4,   298,     6,    38,     8,    38,    47,    38,
      38,   306,    14,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,    41,   145,    97,   103,    30,    39,
      15,    39,   327,   328,   329,   330,   331,   332,     3,     4,
     577,     6,     7,     8,    39,    47,    47,     3,     4,    14,
      31,     7,    15,    31,    31,    31,   456,   457,    14,    31,
      33,    29,    33,   358,    33,    30,    58,    47,    38,    34,
      35,    36,    37,    38,    30,    14,    15,    16,    17,    44,
      36,   488,    47,    38,    38,   121,    25,    26,    38,   581,
      30,    47,    38,    38,   586,    10,    11,    12,    58,    14,
      47,    42,   594,    47,    42,    20,    58,     3,     4,    38,
      47,     7,   604,    79,   606,   121,    38,    47,    14,   526,
      35,    47,   614,   523,   524,     3,     4,   527,     6,     7,
       8,    84,    29,   625,    30,    38,    14,    38,     3,     4,
      36,    30,     7,    38,    38,    36,    30,    47,    47,    14,
      38,    47,    30,   652,   653,    47,    34,    35,    36,    37,
      38,    38,    38,    38,    38,    30,    44,    38,   143,    47,
      30,    36,   579,   138,   581,    55,   124,   142,    47,    47,
      47,   581,    47,    47,    47,    47,   481,   482,   483,   484,
     485,   486,   487,     9,    10,    11,    12,    13,    14,    15,
      47,     3,     4,    81,    38,     7,    31,   614,    47,    38,
     124,    32,    14,   129,   614,    29,    29,  1026,    38,    38,
      42,   516,   517,   518,   519,   520,   521,    42,    30,   122,
      30,    32,   122,    32,    36,   727,   195,   195,   730,     3,
       4,    28,     6,     7,     8,    47,   195,    28,   126,   741,
      14,    55,     3,     4,   124,    32,     7,     3,     4,   195,
     138,     7,    42,    14,    38,   103,    30,    38,    14,    29,
      34,    35,    36,    37,    38,    42,    55,   776,   777,    30,
      44,    47,   781,    47,    30,    36,   581,    48,    30,    47,
      36,     3,     4,    55,   786,     7,    47,    47,     3,     4,
     792,    47,    14,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    48,    47,   148,    55,    47,    30,   614,
      25,    26,   150,   860,    36,    48,   825,   864,   243,   244,
     245,    32,   247,   248,   249,    47,   131,    30,    38,   122,
      38,    55,   257,   258,   259,   260,   261,    30,    47,    30,
       3,     4,    48,    42,     7,   270,    42,    29,   131,    47,
      29,    14,   277,   278,   279,    47,    30,    42,   122,    40,
      30,     3,     4,    31,   138,     7,    42,    30,    55,    42,
      42,    55,    14,    36,    30,   792,    30,   886,   887,   926,
      55,   306,   792,   930,    47,    92,    91,    38,    30,    33,
      38,   696,   697,   698,    36,    55,    55,   906,    47,    39,
       3,     4,    47,    31,     7,    47,    47,   916,     3,     4,
     125,    14,    48,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    39,    47,    94,    93,    30,     3,     4,
      25,    26,     7,    36,    47,    42,    48,    42,    42,    14,
      48,    42,    48,    42,    47,    42,   132,   956,   957,    42,
     959,   960,    48,    55,    30,    30,    47,    55,     3,     4,
      47,    36,    37,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    55,     3,     4,    55,   986,     7,   132,
      25,    26,    47,  1030,    42,    14,    42,   792,     3,     4,
     999,    33,     7,     3,     4,    55,    32,     7,  1045,    14,
      47,    30,    42,    42,    14,  1014,    31,    36,  1017,  1018,
      31,    42,  1021,    33,    42,    30,    90,    29,    47,    33,
      30,    36,    55,    55,    42,  1072,    36,    40,    55,    55,
     125,  1040,    47,    31,    42,     3,     4,    47,    55,   133,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      36,    31,    42,    31,  1063,    55,  1065,    25,    26,     1,
    1032,   883,  1073,   817,   821,  1074,   491,   492,   493,   494,
     495,   496,   497,   498,   499,     0,     1,   885,     3,     4,
     125,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,  1072,    30,  1069,    32,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    -1,    59,    -1,    61,    62,    63,    -1,
      65,    -1,    67,    68,    69,    70,    71,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    -1,   125,    -1,    -1,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,    -1,    -1,   123,    -1,
      -1,   126,    -1,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,    -1,   144,
     145,    -1,   147,    -1,   149,    -1,   151,    -1,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    32,    -1,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    -1,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    67,    68,    69,    70,    71,    -1,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    95,    96,    -1,    98,    99,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,   120,    -1,    -1,   123,
      -1,    -1,   126,    -1,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,    -1,
     144,   145,    -1,   147,    -1,   149,    -1,   151,    -1,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     3,
       4,     3,     4,     7,    -1,     7,    -1,    -1,    -1,    -1,
      14,    -1,    14,     3,     4,    -1,    -1,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    30,    -1,    30,    -1,
      -1,    -1,    36,    -1,    36,    -1,    -1,     3,     4,    -1,
      30,     7,    -1,    47,    -1,    47,    36,    -1,    14,     3,
       4,     3,     4,     7,    -1,     7,    -1,    47,    -1,    -1,
      14,    -1,    14,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    30,    -1,    30,     3,
       4,    47,    36,     7,    36,    -1,    -1,    -1,     3,     4,
      14,    -1,     7,    47,    -1,    47,    -1,     3,     4,    14,
       6,     7,    -1,    -1,    -1,    -1,    30,    -1,    14,     3,
       4,    -1,    36,     7,    -1,    30,    -1,    -1,    -1,    -1,
      14,    36,    -1,    47,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    30,    -1,    44,    -1,
      -1,    -1,    36,    37,    38,    -1,     3,     4,    -1,    -1,
      44,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,     3,     4,    -1,    -1,    25,    26,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    42,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     3,     4,    -1,     6,     7,    -1,    -1,    -1,     3,
       4,    -1,    14,    -1,    42,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,     3,     4,    35,    36,    37,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     3,     4,    -1,    -1,    31,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,     3,
       4,    -1,    -1,    31,    -1,     9,    10,    11,    12,    13,
      14,    15,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    27,    28,     3,     4,    31,    -1,    25,
      26,     9,    10,    11,    12,    13,    14,    15,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,     3,     4,    31,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    27,    28,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     3,     4,    -1,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     9,    10,    11,    12,    13,    14,    15,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    27,
      28,    -1,    -1,    -1,    25,    26
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
     408,   409,   202,     3,     4,     6,     7,     8,    14,    30,
      47,   288,   289,   291,   288,   289,   291,     3,     4,     6,
      14,    30,   287,   291,     3,     4,    14,    30,    47,   288,
      30,   291,   288,   288,   288,   288,   288,     3,     4,    30,
     288,   291,     3,     4,    30,   288,   289,   290,    30,   288,
     289,   288,   289,   288,   289,   288,   289,     6,    30,   287,
     288,   289,   287,   288,   289,     7,    30,    47,   147,   149,
     286,   287,   288,   289,   290,   291,   294,   295,   147,   149,
     200,   284,   288,    30,   290,   146,     8,     9,    10,    11,
      12,    14,    15,    16,    17,    18,    19,    20,    21,    22,
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
       4,     9,    10,    11,    12,    13,    14,    15,    15,     3,
       4,     9,    10,    11,    12,    13,    14,    15,    27,    28,
      39,    39,    47,   288,   289,     8,     9,    10,    11,    12,
      14,    15,    16,    17,    25,    26,     9,    10,    11,    12,
      14,    15,   287,    27,    28,   290,    15,    30,    31,    31,
      31,    31,    18,    19,    20,    21,    22,    23,    24,    31,
      31,    31,    31,    31,    31,    33,    33,   284,    33,   290,
     288,   288,   289,   288,   289,   288,   289,   288,   289,   288,
     289,   288,   289,   290,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   287,   287,    29,    38,    38,
      47,    30,   287,   288,   289,   290,    58,   288,    38,   121,
      38,    30,    38,    38,    58,    47,   288,   285,   202,   288,
      47,    42,    42,    47,    79,    47,    58,    38,   121,    38,
     202,    47,   202,   202,    55,   288,   290,    84,   290,    47,
      29,    38,    38,    38,   122,   124,    38,    30,    34,    48,
     352,    36,    34,    48,   355,   202,    47,   318,    47,   326,
      47,   288,    38,    38,    38,    38,    38,    38,   370,    30,
     143,   258,   254,   264,    30,    47,   287,    47,   287,    47,
     288,    47,   288,    47,   288,    47,   288,    47,   288,   288,
      47,   288,    47,   288,    47,   288,    47,   288,    47,   288,
      47,   288,    47,   288,    47,   288,    47,   288,    47,   288,
      47,   288,    47,   288,    47,   288,     3,     4,    30,    47,
     289,    47,   289,    47,   289,    47,   289,   289,    47,   289,
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
        case 3:
#line 1002 "pnfha.ypp" /* yacc.c:1646  */
    { ASTNode start("START"); tree.add_node(start); }
#line 3189 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 1005 "pnfha.ypp" /* yacc.c:1646  */
    {
	 ASTNode line("line");
         tree.add_node(line);
	}
#line 3198 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 1011 "pnfha.ypp" /* yacc.c:1646  */
    { yyerrok; }
#line 3204 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 1014 "pnfha.ypp" /* yacc.c:1646  */
    {
		 ASTNode statement("statement");
  		 tree.add_node(statement);
		}
#line 3213 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 1022 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1; 
		    	                    statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3220 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 1024 "pnfha.ypp" /* yacc.c:1646  */
    { conprint("VOID TVOID 0V\n"); statementoutcount.insert(); 
                         statementoutcount[statementoutcount.length() - 1] = outcount - 1; statementlineno.insert(); statementlineno[statementlineno.length() - 1]                          = yylineno; }
#line 3227 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 1026 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					  statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3234 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 1028 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					   statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3241 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 1030 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3248 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 1032 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				       statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3255 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 1034 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; inblock = true;
				   }
#line 3263 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 1042 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode expression_statement("expression_statement");
			 tree.add_node(expression_statement);
			}
#line 3272 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 1049 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration_statement("declaration_statement");
			 tree.add_node(declaration_statement);
			}
#line 3281 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 1056 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command_statement("command_statement");
			 tree.add_node(command_statement);
			}
#line 3290 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 1063 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode label_statement("label_statement");

			 bool declared = false;
			 String str;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  str = labelTable[i].name();
			  if ((yyvsp[-1]).to_string().get().getString() == labelTable[i].name().getString())
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
			}
#line 3327 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 1096 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode label_statement("label_statement");

			 conprint("LBL TVOID 0V\n");

			 tree.add_node(label_statement);
			}
#line 3339 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 1104 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode label_statement("label_statement");

			 conprint("ELBL TVOID 0V\n");

			 tree.add_node(label_statement);
			}
#line 3351 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 1114 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			}
#line 3361 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 1120 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			}
#line 3371 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 1126 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");
			 tree.add_node(control_statement);
			}
#line 3380 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 1131 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");

			 breakinforever = false;

			 tree.add_node(control_statement);
			}
#line 3392 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 1141 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp1("if_statementp1");

			 tree.add_node(if_statementp1);		
			}
#line 3402 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 1147 "pnfha.ypp" /* yacc.c:1646  */
    {			 
			 ASTNode if_statementp2("if_statementp2");
			
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			}
#line 3415 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 1156 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			}
#line 3426 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 1163 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			}
#line 3435 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 1168 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			}
#line 3445 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 1174 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			}
#line 3457 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 1184 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp1("if_statementp1");

			 conprint("NOT TVOID 0V\n");	

			 tree.add_node(if_statementp1);		
			}
#line 3469 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 1192 "pnfha.ypp" /* yacc.c:1646  */
    {			 
			 ASTNode if_statementp2("if_statementp2");
		
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			}
#line 3482 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 1201 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			}
#line 3493 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 1208 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			}
#line 3502 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 1213 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			}
#line 3512 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 1219 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			}
#line 3524 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 1229 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp5("if_statementp5");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 // Code for else will be inserted here if exists...
			 tree.add_node(if_statementp5);
			}
#line 3538 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 1240 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp7("if_statementp7");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");

			 tree.add_node(if_statementp7);
			}
#line 3551 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 1254 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp1("switch_statementp1");

			 switchfound = true;
			 ++switchcounter;
			 switchcasecounter = 0;
			 inswitch = true;

			 switch (exptype)
			 {
			  case TBOOLEAN:
			   conprint("ALOAD TBOOLEAN %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			   switchexptype = TBOOLEAN;
     			   break;

			  case TNUMBER:
			   conprint("ALOAD TNUMBER %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			   switchexptype = TNUMBER;
			   break;

			  case TCHARACTER:
			   conprint("ALOAD TCHARACTER %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			   switchexptype = TCHARACTER;
			   break;

			  case TSTRING:
			   conprint("ALOAD TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			   switchexptype = TSTRING;
			   break;

			  default:
			   yyerror("Invalid switch statement.");
			 }
			 conprint("SWITCH2 TVOID 0V\n");
                         conprint("SWBEGIN TVOID 0V\n");

			 tree.add_node(switch_statementp1);
			}
#line 3594 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 1293 "pnfha.ypp" /* yacc.c:1646  */
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
			}
#line 3627 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 1322 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp3("switch_statementp3");

			 tree.add_node(switch_statementp3);
			}
#line 3637 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 1327 "pnfha.ypp" /* yacc.c:1646  */
    {

			}
#line 3645 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 1331 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			}
#line 3657 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 1339 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp1("switch_statementp1");

			 switchfound = true;
			 ++switchcounter;
			 switchcasecounter = 0;
			 inswitch = true;

			 conprint("SWITCH2 TVOID 0V\n");
			 conprint("SWBEGIN TVOID 0V\n");

			 tree.add_node(switch_statementp1);
			}
#line 3675 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 1354 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp2("switch_statementp2");
			 
			 tree.add_node(switch_statementp2);
			}
#line 3685 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 1360 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp3("switch_statementp3");
			 tree.add_node(switch_statementp3);
			}
#line 3694 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 1365 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			}
#line 3706 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 1374 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			}
#line 3715 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 1383 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statement("case_statement");

			 ++switchcasecounter;

			 if (switchexptype != exptype)
			  yyerror("Non-Matching Switch Expression");

			 
 			 switch (exptype)
			 {
			  case TBOOLEAN:
			   conprint("SWCASE TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

			  case TNUMBER:
			   conprint("SWCASE TNUMBER %g\n", (yyvsp[0]).to_number().get());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

			  case TCHARACTER:
			   conprint("SWCASE TCHARCTER %c\n", (yyvsp[0]).to_character().get());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

		 	  case TSTRING:
			   conprint("SWCASE TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

			  default:
			   yyerror("Invalid switch statement.");
			};

			 tree.add_node(case_statement);
			}
#line 3757 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1421 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 3765 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1427 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			}
#line 3774 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1432 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 3782 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1437 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			}
#line 3791 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1446 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statementp1("case_statement");

			 ++switchcasecounter;

			 switch (exptype)
			 {
			  case TBOOLEAN:
			   conprint("SWCASE TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("SWCASE TNUMBER %g\n", (yyvsp[0]).to_number().get());
			   break;

			  case TCHARACTER:
			   conprint("SWCASE TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			   break;

			  case TSTRING:
			   conprint("SWCASE TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid type.");
			 }
			 conprint("SWCBEGIN TVOID 0V\n");
			
			 tree.add_node(case_statementp1);
			}
#line 3826 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1477 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statementp2("case_statementp2");

			 tree.add_node(case_statementp2);
			}
#line 3836 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1483 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statementp3("case_statementp3");

			 conprint("SWCEND TVOID 0V\n");

			 tree.add_node(case_statementp3);
			}
#line 3848 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1493 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			}
#line 3857 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1498 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 3865 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1503 "pnfha.ypp" /* yacc.c:1646  */
    {
			 loopexpr = true;
			 inloop2 = true;
			}
#line 3874 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1508 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3883 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1513 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3892 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1518 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3901 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1523 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3910 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1528 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3919 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1533 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3928 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1538 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 
			 loopexpr = false;
			 inloop = true;		 

			 tree.add_node(loop_statement);
			}
#line 3941 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1546 "pnfha.ypp" /* yacc.c:1646  */
    {
			 inloop2 = false;
			 inwhile = false;
			 indowhile = false;
			 infor2 = false;
			 indofor = false;
			 inforever = false;
			}
#line 3954 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1557 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp1("while_loopp1");

			 inwhile = true;
			 ++whilecounter;
			 conprint("LBL TSTRING \"while_test_%u\"\n", whilecounter);

			 tree.add_node(while_loopp1);
			}
#line 3968 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1567 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp2("while_loopp2");

			 tree.add_node(while_loopp2);
			}
#line 3978 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1573 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp3("while_loopp3");

			 conprint("CGOTOL TSTRING \"while_body_%u\"\n", whilecounter);
			 conprint("GOTOL TSTRING \"while_end_%u\"\n", whilecounter);

			 conprint("LBL TSTRING \"while_body_%u\"\n", whilecounter);

			 tree.add_node(while_loopp3);
			}
#line 3993 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1584 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp4("while_loopp4");

			 conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 conprint("LBL TSTRING \"while_end_%u\"\n", whilecounter);

			 tree.add_node(while_loopp4);
			}
#line 4006 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1594 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp1("do_while_loopp1");

			 indowhile = true;
			 ++dowhilecounter;
			 conprint("LBL TSTRING \"do_while_body_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp1);
			}
#line 4020 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1604 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp2("do_while_loopp2");

			 tree.add_node(do_while_loopp2);
			}
#line 4030 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1611 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp3("do_while_loopp3");

			 conprint("LBL TSTRING \"do_while_test_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp3);
			}
#line 4042 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1619 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp4("do_while_loopp4");

			 tree.add_node(do_while_loopp4);
			}
#line 4052 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1625 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp5("do_while_loopp5");

			 conprint("CGOTOL TSTRING \"do_while_body_%u\"\n", dowhilecounter);
			 conprint("GOTOL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp5);
			}
#line 4065 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1634 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp6("do_while_loopp6");

			 conprint("LBL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp6);
			}
#line 4077 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1644 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode until_loopp1("until_loopp1");

			 inuntil = true;
			 ++untilcounter;
			 conprint("LBL TSTRING \"until_test_%u\"\n", untilcounter);

			 tree.add_node(until_loopp1);
			}
#line 4091 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1654 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode until_loopp2("until_loopp2");

			 tree.add_node(until_loopp2);
			}
#line 4101 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1660 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode until_loopp3("until_loopp3");


			 conprint("NOT TVOID 0V\n");

			 conprint("CGOTOL TSTRING \"until_body_%u\"\n", untilcounter);
			 conprint("GOTOL TSTRING \"until_end_%u\"\n", untilcounter);

			 conprint("LBL TSTRING \"until_body_%u\"\n", untilcounter);

			 tree.add_node(until_loopp3);
			}
#line 4119 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1674 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode until_loopp4("until_loopp4");

			 conprint("GOTOL TSTRING \"until_test_%u\"\n", untilcounter);
			 conprint("LBL TSTRING \"until_end_%u\"\n", untilcounter);

			 tree.add_node(until_loopp4);
			}
#line 4132 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1684 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp1("do_until_loopp1");

			 indountil = true;
			 ++dountilcounter;
			 conprint("LBL TSTRING \"do_until_body_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp1);
			}
#line 4146 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1694 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp2("do_until_loopp2");

			 tree.add_node(do_until_loopp2);
			}
#line 4156 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1701 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp3("do_until_loopp3");

			 conprint("LBL TSTRING \"do_until_test_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp3);
			}
#line 4168 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1709 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp4("do_until_loopp4");

			 tree.add_node(do_until_loopp4);
			}
#line 4178 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1715 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp5("do_until_loopp5");

			 conprint("CGOTOL TSTRING \"do_until_body_%u\"\n", dountilcounter);
			 conprint("GOTOL TSTRING \"do_until_end_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp5);
			}
#line 4191 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1724 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp6("do_until_loopp6");

			 conprint("NOT TVOID 0V\n");

			 conprint("LBL TSTRING \"do_until_end_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp6);
			}
#line 4205 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1735 "pnfha.ypp" /* yacc.c:1646  */
    {
			 infor = true;
			}
#line 4213 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1739 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp1("for_loopp1");

			 infor2 = true;
			 ++forcounter;
			 conprint("LBL TSTRING \"for_initialization_%u\"\n", forcounter);

			 tree.add_node(for_loopp1);
			}
#line 4227 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1749 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp2("for_loopp2");

			 conprint("LBL TSTRING \"for_condition_%u\"\n", forcounter);

			 tree.add_node(for_loopp2);
			}
#line 4239 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1757 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp3("for_loopp3");

			 conprint("CGOTOL TSTRING \"for_body_%u\"\n", forcounter);
			 conprint("GOTOL TSTRING \"for_end_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_increment_statement_%u\"\n", forcounter);

			 tree.add_node(for_loopp3);
			}
#line 4253 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1767 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp4("for_loopp4");

			 conprint("GOTOL TSTRING \"for_condition_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_body_%u\"\n", forcounter);

			 tree.add_node(for_loopp4);
			}
#line 4266 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1776 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp5("for_loopp5");

			 conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_end_%u\"\n", forcounter);

			 tree.add_node(for_loopp5);
			}
#line 4279 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1787 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp1("forb_loopp1");

			 indofor = true;
			 infor = true;
			 ++doforcounter;

			 conprint("GOTOL TSTRING \"dofor_initialization_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_body_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp1);
			}
#line 4296 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1800 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp2("forb_loopp2");

			 conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_initialization_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp2);
			}
#line 4309 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1809 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp3("forb_loopp3");

			 tree.add_node(forb_loopp3);
			}
#line 4319 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1815 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp4("forb_loopp4");

			 conprint("GOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_condition_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp4);
			}
#line 4332 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1824 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp5("forb_loopp5");

			 conprint("CGOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("GOTOL TSTRING \"dofor_end_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp5);
			}
#line 4346 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1834 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp6("forb_loopp6");
			 tree.add_node(forb_loopp6);
			}
#line 4355 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1839 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp7("forb_loopp7");

			 conprint("GOTOL TSTRING \"dofor_condition_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_end_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp7);
			}
#line 4368 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1850 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forever_loopp1("forever_loopp1");

			 breakinforever = true;
			 ++forevercounter;
			 conprint("LBL TSTRING \"forever_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp1);			
			}
#line 4382 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1860 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forever_loopp2("forever_loopp2");

			 conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);
			 conprint("LBL TSTRING \"forever_end_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp2);			
			}
#line 4395 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1869 "pnfha.ypp" /* yacc.c:1646  */
    { PNF_String str((yyvsp[-1]).to_string().get()); (yyval).put(str); ASTNode statement_block("statement_block"); 
                                                  tree.add_node(statement_block); }
#line 4402 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1874 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			}
#line 4411 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1879 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			}
#line 4420 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1885 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = TVOID; ASTNode expression("expression"); tree.add_node(expression); }
#line 4426 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1887 "pnfha.ypp" /* yacc.c:1646  */
    {
		 (yyval) = (yyvsp[0]);
		 savenumber = (yyval);
		 exptype = TBOOLEAN;
		 ASTNode expression("expression");
		 tree.add_node(expression);
		}
#line 4438 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1894 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); savenumber = (yyval); exptype = TNUMBER; ASTNode expression("expression");
                                      tree.add_node(expression); }
#line 4445 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1896 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); savenumber = (yyval); exptype = TCHARACTER; ASTNode expression("expression"); 
                                         tree.add_node(expression); }
#line 4452 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1898 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); savenumber = (PNF_String)strip_quotes((yyval).to_string().get()); exptype = TSTRING; ASTNode expression("expression"); 
                                      tree.add_node(expression); }
#line 4459 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1900 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
                                  tree.add_node(expression); }
#line 4466 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1902 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = TBOOLEAN; ASTNode expression("expression"); 
					  tree.add_node(expression); }
#line 4473 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1904 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
				     tree.add_node(expression); }
#line 4480 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1906 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); tree.add_node(expression); 		
		}
#line 4487 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1912 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_String s("0V");
			 (yyval).put(s);

			 exptruth = false;

			 ASTNode void_expression("void_expression");
			 tree.add_node(void_expression);
			}
#line 4501 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1921 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4507 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1925 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 (yyval) = (yyvsp[0]);

			 String str = (yyval).to_boolean().get();
			 if (str == "true")
			  exptruth = true;
                         else if (str == "false")
                          exptruth = false;
			 else
			  exptruth = true;

			
			 ASTNode boolean_expression("boolean_expression"); 
			 tree.add_node(boolean_expression);
			}
#line 4527 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1941 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool b;
			 String str = (yyvsp[0]).to_boolean().get();

			 if (str.getString() == "true")
			  b = true;
			 else
			  b = false;

			 PNF_Boolean b2(b);
			 b2.opnot();
			 (yyval).put(b2);
			}
#line 4545 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1955 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String bl = (yyvsp[0]).to_boolean().get();
			 bool b;
			
			 if (bl.getString() == "true")
			  b = true;
			 else if (bl.getString() == "false")
			  b = false;
			 else
			  b = false;

			 PNF_Boolean b2((yyvsp[-2]).to_boolean());
			 b2.opand(b);
			 (yyval).put(b2);
			}
#line 4565 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1971 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String bl = (yyvsp[0]).to_boolean().get();
			 bool b;
			
			 if (bl.getString() == "true")
			  b = true;
			 else if (bl.getString() == "false")
			  b = false;
			 else
			  b = false;

			 PNF_Boolean b2((yyvsp[-2]).to_boolean());
			 b2.opor(b);
			 (yyval).put(b2);
			}
#line 4585 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1986 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4591 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1990 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 (yyval) = (yyvsp[0]);

			 double d = (yyval).to_number().get();

                         if (d == 0)
                          exptruth = false;
                         else
                          exptruth = true;

			 ASTNode number_expression("number_expression");
                         tree.add_node(number_expression);
			}
#line 4609 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 2004 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().add(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4619 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 2010 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().sub(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4629 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 2016 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().mul(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4639 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 2022 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().div(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4649 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 2028 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().mod(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4659 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 2034 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char * str = "-";
			 strcat(str, (yyvsp[0]).to_string().get().getString().c_str());
			 PNF_String s(str);
			 PNF_Variable v(s);
			 (yyval) = v;
			}
#line 4671 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 2042 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[0]).to_number().get();
			 PNF_Number n((yyvsp[-2]).to_number());
			 n.pow(d);
			 (yyval).put(n);
			}
#line 4682 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 2049 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-2]).to_number().get();
			 PNF_Number n((yyvsp[0]).to_number());
			 n.root(d);			 
			 (yyval).put(n);
			}
#line 4693 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 2056 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[0]).to_number().get());
			 n.inc(1);
			 (yyval).put(n);
			}
#line 4703 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 2062 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[-1]).to_number().get());
			 (yyval).put(n);
			 n.inc(1);
			}
#line 4713 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 2068 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[0]).to_number().get());
			 n.dec(1);
			 (yyval).put(n);
			}
#line 4723 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 2074 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[-1]).to_number().get());
			 (yyval).put(n);
			 n.dec(1);
			}
#line 4733 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 2080 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 & d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4745 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 2088 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 | d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4757 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 2097 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 ^ d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4769 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 2105 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d = (int)(yyvsp[0]).to_number().get();
			 d = ~d;
			 PNF_Number n(d);
			 (yyval).put(n);
			}
#line 4780 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 2112 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 << d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4792 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 2120 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 >> d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4804 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 2127 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4810 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 2132 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);
			 char ch = (yyval).to_character().get();

			 if (ch == '\0')
                          exptruth = false;
			 else
			  exptruth = true;

			 ASTNode character_expression("character_expression"); 
			 tree.add_node(character_expression);
			}
#line 4827 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 2145 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.add((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4838 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 2152 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.sub((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4849 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 2159 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.mul((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4860 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 2166 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.div((yyvsp[0]).to_character().get());
			 (yyval).put(c);			}
#line 4870 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 2172 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.mod((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4881 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 2179 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[0]).to_character().get();
			 PNF_Character c((yyvsp[-2]).to_character());
			 c.pow(d);
			 (yyval).put(c);
			}
#line 4892 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 2186 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c((yyvsp[0]).to_character());
			 c.root(d);
			 (yyval).put(c);
			}
#line 4903 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 2193 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[0]).to_character().get());
			 n.inc(1);
			 (yyval).put(n);
			}
#line 4913 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 2199 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[-1]).to_character().get());
			 (yyval).put(n);
			 n.inc(1);
			}
#line 4923 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 2205 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[0]).to_character().get());
			 n.dec(1);
			 (yyval).put(n);
			}
#line 4933 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 2211 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[-1]).to_character().get());
			 (yyval).put(n);
			 n.dec(1);
			}
#line 4943 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 2216 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4949 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 2221 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);
		
			 String str = (yyval).to_string().get();
			 if (str == "")
			  exptruth = false;
			 else
			  exptruth = true;

			 ASTNode string_expression("string_expression"); 
			 tree.add_node(string_expression);
			}
#line 4966 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 2234 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String d = (yyvsp[-2]).to_string().get();
			 PNF_String s(d);
			 s.add((yyvsp[0]).to_string().get());

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
			}
#line 4995 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 2259 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String str = (yyvsp[0]).to_string().get();
			 String str2 = "\"" + str + "\"";
			 PNF_String s(str2);
			 (yyval).put(s);
			}
#line 5006 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 2265 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 5012 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 2270 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 ASTNode id_expression("id_expression");
			 tree.add_node(id_expression);
			}
#line 5087 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 2341 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			   if (strcmp(labelTable[i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			    if (strcmp(eventLabelTable[i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			    {
			     declared = true;
			     PNF_Number n(eventLabelTable[i].address());
			     (yyval).put(n);
			    }
  			   }
			  }
			 }
			}
#line 5131 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 2381 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
			}
#line 5172 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 2418 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared1 = false;
			 bool declared2 = false;
  		   	 PNF_Boolean b1;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 PNF_Boolean b3;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			  String str = (yyvsp[0]).to_string().get();
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
			}
#line 5253 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 2495 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared1 = false;
			 bool declared2 = false;
			 PNF_Boolean b1;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }


   		         PNF_Boolean b3;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			  String str = (yyvsp[0]).to_string().get();
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
			}
#line 5336 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2574 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[-2]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[0]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[0]).to_number().get();
			   PNF_Number n((yyvsp[-2]).to_number());
			   n.add(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[0]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[0]).to_character().get();
			   PNF_Character n((yyvsp[-2]).to_character());
			   n.add(d);
			   (yyval).put(n);
			  }
			  break;

			  case TSTRING:
			  {
			   if ((yyvsp[0]).getType() != TSTRING)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }

			   String str = (yyvsp[0]).to_string().get();
			   String str2 = "";
			   for (unsigned long i = 0; i < str.length(); ++i)
 			   {
			    if (str[i] == '\"')
			     continue;
			    str2 += str[i];
			   }

			   str = (yyvsp[-2]).to_string().get();
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
			}
#line 5420 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2654 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[-2]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[0]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[0]).to_number().get();
			   PNF_Number n((yyvsp[-2]).to_number());
			   n.sub(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[0]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[0]).to_character().get();
			   PNF_Character n((yyvsp[-2]).to_character());
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
#line 5462 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2692 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[-2]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[0]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[0]).to_number().get();
			   PNF_Number n((yyvsp[-2]).to_number());
			   n.mul(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[0]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[0]).to_character().get();
			   PNF_Character n((yyvsp[-2]).to_character());
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
#line 5504 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2730 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[-2]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[0]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[0]).to_number().get();
			   PNF_Number n((yyvsp[-2]).to_number());
			   n.div(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[0]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[0]).to_character().get();
			   PNF_Character n((yyvsp[-2]).to_character());
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
#line 5546 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2768 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[-2]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[0]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[0]).to_number().get();
			   PNF_Number n((yyvsp[-2]).to_number());
			   n.mod(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[0]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[0]).to_character().get();
			   PNF_Character n((yyvsp[-2]).to_character());
			   n.mod(d);
			   (yyval).put(n);
			  }
			  break;	

			  default:
			   PNF_Number n(0);
			   (yyval).put(n);
			   break;
			 }
			}
#line 5588 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2806 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if ((yyvsp[0]).getType() != TNUMBER)
			 {
			  PNF_Number n(0);
                          (yyval).put(n);
			 }
			 double d = (yyvsp[0]).to_number().get();
			 d = -d;
			 PNF_Number n(d);
			 PNF_Variable v(n);
			 (yyval) = v;
			}
#line 5605 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2819 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[-2]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[0]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[0]).to_number().get();
			   PNF_Number n((yyvsp[-2]).to_number());
			   n.pow(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[0]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[0]).to_character().get();
			   PNF_Character n((yyvsp[-2]).to_character());
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
#line 5647 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2857 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[-2]).getType())
			 {
			  case TNUMBER:
			  {
			   if ((yyvsp[0]).getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   double d = (yyvsp[-2]).to_number().get();
			   PNF_Number n((yyvsp[0]).to_number());
			   n.root(d);
			   (yyval).put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if ((yyvsp[0]).getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    (yyval).put(n);
			   }
			   char d = (yyvsp[-2]).to_character().get();
			   PNF_Character n((yyvsp[0]).to_character());
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
#line 5689 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2895 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[0]).getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n((yyvsp[0]).to_number().get());
			   n.inc(1);
			   (yyval).put(n);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c((yyvsp[0]).to_character().get());
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
			}
#line 5721 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2923 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[0]).getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n((yyvsp[0]).to_number().get());
			   (yyval).put(n);
			   n.inc(1);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c((yyvsp[0]).to_character().get());
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
			}
#line 5753 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2951 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[0]).getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n((yyvsp[0]).to_number().get());
			   n.dec(1);
			   (yyval).put(n);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c((yyvsp[0]).to_character().get());
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
			}
#line 5785 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2979 "pnfha.ypp" /* yacc.c:1646  */
    {
			 switch ((yyvsp[0]).getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n((yyvsp[0]).to_number().get());
			   (yyval).put(n);
			   n.dec(1);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c((yyvsp[0]).to_character().get());
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
			}
#line 5817 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 3006 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 5823 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 3010 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 == d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5838 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 3021 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 != d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5853 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 3032 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 < d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5868 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 3043 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 > d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5883 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 3054 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 <= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5898 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 3065 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 >= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5913 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 3075 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String str = (yyval).to_boolean().get();
			 if (str == "false")
			  exptruth = false;
			 else if (str == "true")
			  exptruth = true;
			 else
			  exptruth = true;
			}
#line 5927 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 3085 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
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
#line 5954 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 3110 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 5960 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 3112 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
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
			   String str = (yyvsp[0]).to_boolean().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6013 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 3161 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			   String str = (yyvsp[-2]).to_boolean().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6066 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 3210 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
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
			   String str = (yyvsp[0]).to_boolean().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6119 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 3259 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			   String str = (yyvsp[-2]).to_boolean().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6172 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 3308 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6218 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 3350 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6264 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 3392 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6310 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 3434 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6356 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 3476 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6402 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 3518 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = varTable[scope][i].value().to_number().get();
			     PNF_Number n((yyvsp[0]).to_number());
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6448 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 3560 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6494 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 3602 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6540 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 3644 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6586 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 3686 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6632 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 3728 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6678 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 3770 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     double d = varTable[scope][i].value().to_number().get();
			     PNF_Number n((yyvsp[-2]).to_number());
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6724 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 3812 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[0]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[0]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6770 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 3854 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[0]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[0]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6816 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 3896 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[0]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[0]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6862 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 3938 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[0]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[0]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6908 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 3980 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[0]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[0]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 6954 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 4022 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[0]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = varTable[scope][i].value().to_character().get();
			     PNF_Character n((yyvsp[0]).to_character());
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7000 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 4064 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[-2]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[-2]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7046 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 4106 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[-2]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[-2]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7092 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 4148 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[-2]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[-2]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7138 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 4190 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[-2]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[-2]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7184 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 4232 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[-2]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = (yyvsp[-2]).to_character().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7230 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 4274 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if ((yyvsp[-2]).getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }
			     char d = varTable[scope][i].value().to_character().get();
			     PNF_Character n((yyvsp[-2]).to_character());
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7276 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 4316 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TSTRING:
			    {
			     if ((yyvsp[0]).getType() != TSTRING)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     String d = (yyvsp[0]).to_string().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7344 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 4380 "pnfha.ypp" /* yacc.c:1646  */
    {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TSTRING:
			    {
			     if ((yyvsp[-2]).getType() != TSTRING)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     String d = (yyvsp[-2]).to_string().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7412 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 4444 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7461 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 4489 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7510 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 4534 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7559 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 4579 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7608 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 4624 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7657 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 4669 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7706 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 4714 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7755 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 4759 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7804 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 4804 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7853 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 4849 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7902 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 4894 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7951 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 4939 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     double d1 = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8000 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 4984 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8049 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 5029 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8098 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 5074 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8147 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 5119 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8196 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 5164 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8245 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 5209 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8294 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 5254 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8335 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 5291 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8384 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 5336 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[0]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8433 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 5381 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8482 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 5426 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			     int d1 = (int)(yyvsp[-2]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8531 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 5471 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }			
			}
#line 8593 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 5529 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if ((yyvsp[-2]).getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      (yyval).put(n);
			     }


			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
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
			  String str = (yyvsp[-2]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }			
			}
#line 8655 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 5589 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);
			}
#line 8663 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 5593 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-1]);
			}
#line 8671 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 5599 "pnfha.ypp" /* yacc.c:1646  */
    {
			 funcnum = (unsigned long)(yyvsp[0]).to_number().get();
			}
#line 8679 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 5603 "pnfha.ypp" /* yacc.c:1646  */
    {
			 fsaveid2 = (yyvsp[0]);

			 conprint("FCALL TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
			 conprint("FCPARAMS TVOID 0V\n");
			}
#line 8690 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 5610 "pnfha.ypp" /* yacc.c:1646  */
    {
			 pnum3 = 0;
			 pnum4 = 0;
			}
#line 8699 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 5615 "pnfha.ypp" /* yacc.c:1646  */
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
			}
#line 8723 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 5634 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if(fncdefault)
			 {
			  fncdefault = false;
			  conprint("FNCDEFAULT2 TVOID 0V\n");
			 }

			 conprint("FECPARAMS TVOID 0V\n");
			}
#line 8737 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 5644 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("FECALL TVOID 0V\n");
			}
#line 8745 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 5648 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets3.length() - 1; i > 0; --i)
			  frets3.remove();
			 frets3[0] = "";

			 for (unsigned long i = fparams3.length() - 1; i > 0; --i)
			  fparams3.remove();
			 fparams3[0] = "";
			}
#line 8759 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 5660 "pnfha.ypp" /* yacc.c:1646  */
    {

				}
#line 8767 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 5667 "pnfha.ypp" /* yacc.c:1646  */
    {
				 (yyval) = (yyvsp[0]);				 

				 for (unsigned long i = 0; i < funcps[funcps.length() - 1].length(); ++i)
			 	 {
			 	  funcps[funcps.length() - 1][i].value((yyvsp[0]));
			 	 }
				}
#line 8780 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 5678 "pnfha.ypp" /* yacc.c:1646  */
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
				}
#line 8827 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 5721 "pnfha.ypp" /* yacc.c:1646  */
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
				}
#line 8874 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 5764 "pnfha.ypp" /* yacc.c:1646  */
    {
				 PNF_Type_Enum t;
			  	 if ((yyvsp[0]).to_string().get() == "void")
				  t = TVOID;
				 else if ((yyvsp[0]).to_string().get() == "boolean")
				  t = TBOOLEAN;
				 else if ((yyvsp[0]).to_string().get() == "number")
				  t = TNUMBER;
				 else if ((yyvsp[0]).to_string().get() == "character")
				  t = TCHARACTER;
				 else if ((yyvsp[0]).to_string().get() == "string")
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
				}
#line 9004 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 5890 "pnfha.ypp" /* yacc.c:1646  */
    {
				 PNF_Type_Enum t;
			  	 if ((yyvsp[0]).to_string().get() == "void")
				  t = TVOID;
				 else if ((yyvsp[0]).to_string().get() == "boolean")
				  t = TBOOLEAN;
				 else if ((yyvsp[0]).to_string().get() == "number")
				  t = TNUMBER;
				 else if ((yyvsp[0]).to_string().get() == "character")
				  t = TCHARACTER;
				 else if ((yyvsp[0]).to_string().get() == "string")
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
				}
#line 9134 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 6035 "pnfha.ypp" /* yacc.c:1646  */
    {
				 (yyval) = (yyvsp[0]);
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
				}
#line 9180 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 6170 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			}
#line 9189 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 6175 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			}
#line 9198 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 6180 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9207 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 6185 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9216 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 6190 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9225 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 6195 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9234 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 6200 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9243 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 6205 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9252 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 6210 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9261 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 6215 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9270 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 6222 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration"); 

			 bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			  varTable[scope][varTable[scope].length() - 1].name((yyvsp[0]).to_string().get());
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
			}
#line 9332 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 6280 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration"); 

			 bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[-2]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   varTable[scope][i].value((yyvsp[0]));
			
			   switch ((yyvsp[0]).getType())
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

			  varTable[scope][varTable[scope].length() - 1].name((yyvsp[-2]).to_string().get());
			  varTable[scope][varTable[scope].length() - 1].value((yyvsp[0]));

			  (yyval) = (yyvsp[0]);

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
			}
#line 9417 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 6361 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration"); 

			 bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
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
			  varTable[scope][varTable[scope].length() - 1].name((yyvsp[0]).to_string().get());
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
			}
#line 9456 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 6396 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 9465 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 6401 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 9474 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 6406 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 9483 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 6413 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enumv_declaration("enumv_declaration");

			 conprint("ENUMS TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("ENUM TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 conprint("SENUM TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());

			 tree.add_node(enumv_declaration);
			}
#line 9497 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 6425 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode rangev_declaration("rangev_declaration");

			 if ((yyvsp[-4]).to_string().get() == "rtype1")
			 {
			  conprint("RSTART1 TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			  conprint("RANGE1 TNUMBER %s\n", strip_quotes((yyvsp[0]).to_string().get()).getString().c_str());
			  conprint("REND1 TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(rangev_declaration);
			}
#line 9516 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 6440 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode rangev_declaration("rangev_declaration");

			 if ((yyvsp[-2]).to_string().get() == "rtype2")
			 {
			  conprint("RSTART2 TSTRING %s\n", (yyvsp[-1]).to_string().get().getString().c_str());
			  conprint("RANGE2 TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(rangev_declaration);
			}
#line 9534 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 6456 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode array_declaration("array_declaration");

			 conprint("ASTART TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("AEND TNUMBER %g\n", (yyvsp[-1]).to_number().get());

			 tree.add_node(array_declaration);
			}
#line 9547 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 6467 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_declarationp1("enum_declarationp1");

			 conprint("ESTART TSTRING \"%s\"\n", (yyvsp[-2]).to_string().get().getString().c_str());

			 tree.add_node(enum_declarationp1);
			}
#line 9559 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 6475 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_declarationp2("enum_declarationp2");
			 tree.add_node(enum_declarationp2);
			}
#line 9568 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 6480 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_declarationp3("enum_declarationp3");

			 conprint("EEND TVOID 0V\n");

			 tree.add_node(enum_declarationp3);
			}
#line 9580 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 6490 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_strings("enum_strings");

			 conprint("ENAME TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());

			 tree.add_node(enum_strings);
			}
#line 9592 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 6498 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("ENAME TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			}
#line 9600 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 6504 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode range_declaration("range_declaration");

			 if ((yyvsp[-6]).to_string().get() == "rtype1")
			 {
			  conprint("RDSTART1 TSTRING %s\n", (yyvsp[-5]).to_string().get().getString().c_str());
			  conprint("RFROM1 TNUMBER %s\n", strip_quotes((yyvsp[-3]).to_string().get()).getString().c_str());
			  conprint("RTO1 TNUMBER %s\n", strip_quotes((yyvsp[0]).to_string().get()).getString().c_str());
			  conprint("RDEND1 TVOID 0V\n");
			 }
			 else if ((yyvsp[-6]).to_string().get() == "rtype2")
			 {
			  conprint("RDSTART2 TSTRING %s\n", (yyvsp[-5]).to_string().get().getString().c_str());
			  conprint("RFROM2 TNUMBER %s\n", strip_quotes((yyvsp[-3]).to_string().get()).getString().c_str());
			  conprint("RTO2 TNUMBER %s\n", strip_quotes((yyvsp[0]).to_string().get()).getString().c_str());
			  conprint("RDEND2 TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(range_declaration);
			}
#line 9627 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 6529 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("STRUCT TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
			}
#line 9635 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 6538 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("ENDSTRUCT TVOID 0V\n");
			}
#line 9643 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 6548 "pnfha.ypp" /* yacc.c:1646  */
    {
				 conprint("STRUCTVAR TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
				}
#line 9651 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 6555 "pnfha.ypp" /* yacc.c:1646  */
    {
				 conprint("STRUCTNAME TSTRING \"%s\"\n", (yyvsp[-1]).to_string().get().getString().c_str());
				 conprint("STRUCTD TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
				}
#line 9660 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 6562 "pnfha.ypp" /* yacc.c:1646  */
    {
				 conprint("STRUCTNAME TSTRING \"%s\"\n", (yyvsp[-5]).to_string().get().getString().c_str());
				 conprint("STRUCTONAME TSTRING \"%s\"\n", (yyvsp[-4]).to_string().get().getString().c_str());
				 conprint("STRUCTUSE TSTRING \"%s\"\n", (yyvsp[-2]).to_string().get().getString().c_str());
				 
				 switch ((yyvsp[0]).getType())
				 {
				  case TVOID:
				  {
				   conprint("ALOAD TVOID 0V\n");
				  }
				  break;

				  case TBOOLEAN:
				  {
				   conprint("ALOAD TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get());
				  }
				  break;

				  case TNUMBER:
				  {
				   conprint("ALOAD TNUMBER %f\n", (yyvsp[0]).to_number().get());
				  }
				  break;

				  case TCHARACTER:
				  {
				   conprint("ALOAD TCHARACTER '%c'\n", (yyvsp[-1]).to_character().get());
				  }
				  break;

				  case TSTRING:
				  {
				   conprint("ALOAD TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
				  }
				  break;

				  default:
				   yyerror((char *)"Invalid type.");
				 }

				 conprint("STRUCTPUT TVOID 0V\n");
				}
#line 9708 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 6608 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("UNION TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
			}
#line 9716 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 6617 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("ENDUNION TVOID 0V\n");
			}
#line 9724 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 6627 "pnfha.ypp" /* yacc.c:1646  */
    {
				 conprint("UNIONVAR TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
				}
#line 9732 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 6634 "pnfha.ypp" /* yacc.c:1646  */
    {
				 conprint("UNIONNAME TSTRING \"%s\"\n", (yyvsp[-1]).to_string().get().getString().c_str());
				 conprint("UNIOND TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
				}
#line 9741 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 6641 "pnfha.ypp" /* yacc.c:1646  */
    {
				 conprint("UNIONNAME TSTRING \"%s\"\n", (yyvsp[-5]).to_string().get().getString().c_str());
				 conprint("UNIONONAME TSTRING \"%s\"\n", (yyvsp[-4]).to_string().get().getString().c_str());
				 conprint("UNIONUSE TSTRING \"%s\"\n", (yyvsp[-2]).to_string().get().getString().c_str());
				 
				 switch ((yyvsp[0]).getType())
				 {
				  case TVOID:
				  {
				   conprint("ALOAD TVOID 0V\n");
				  }
				  break;

				  case TBOOLEAN:
				  {
				   conprint("ALOAD TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get());
				  }
				  break;

				  case TNUMBER:
				  {
				   conprint("ALOAD TNUMBER %f\n", (yyvsp[0]).to_number().get());
				  }
				  break;

				  case TCHARACTER:
				  {
				   conprint("ALOAD TCHARACTER '%c'\n", (yyvsp[-1]).to_character().get());
				  }
				  break;

				  case TSTRING:
				  {
				   conprint("ALOAD TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
				  }
				  break;

				  default:
				   yyerror((char *)"Invalid type.");
				 }

				 conprint("UNIONPUT TVOID 0V\n");
				}
#line 9789 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 6687 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  if ((yyvsp[0]).to_string().get().getString() == labelTable[i].name().getString())
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
			  labelTable[labelTable.length() - 1].name((yyvsp[0]).to_string().get());
			  labelTable[labelTable.length() - 1].address(labelTable.length() - 2);
			 }

			 ASTNode label_declaration("label_declaration");
		         tree.add_node(label_declaration);
			}
#line 9817 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 6711 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
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
			  eventLabelTable[eventLabelTable.length() - 1].name((yyvsp[0]).to_string().get());
			  eventLabelTable[eventLabelTable.length() - 1].address(eventLabelTable.length() - 2);
			 }
			 ASTNode label_declaration("label_declaration");
		         tree.add_node(label_declaration);
			}
#line 9844 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 6734 "pnfha.ypp" /* yacc.c:1646  */
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  if ((yyvsp[0]).to_string().get().getString() == labelTable[i].name().getString())
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
			  labelTable[labelTable.length() - 1].name((yyvsp[0]).to_string().get());
			  labelTable[labelTable.length() - 1].address(labelTable.length() - 2);
			 }

			 ASTNode label_declaration("label_declaration");
		         tree.add_node(label_declaration);
			}
#line 9872 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 6762 "pnfha.ypp" /* yacc.c:1646  */
    {
			 funcps.insert();

			 funcptr->name((yyvsp[-3]).to_string().get());			 
			 funcstk.add_function(*funcptr);
			 delete funcptr;
			 funcptr = NULL;			 
	
			 saveid3 = (yyvsp[-3]);
			 unsigned long index = funcstk.find((yyvsp[-3]).to_string().get(), frets, fparams);
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
			 
			 
			 conprint("ALOAD TSTRING \"%s\"\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("FNCSNAME TVOID 0V\n");
			 conprint("FNCSDEF TSTRING \"%s\"\n", funcstk.get_function(index).rname().getString().c_str());
			 conprint("FNCSTORE TVOID 0V\n");
			 conprint("FNCDELETE TVOID 0V\n");
			}
#line 9912 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 6798 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets.length() - 1; i > 0; --i)
			  frets.remove();

			 for (unsigned long i = fparams.length() - 1; i > 0; --i)
			  fparams.remove();
			}
#line 9924 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 6810 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

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
			}
#line 10021 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 6903 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-2]);


			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 10135 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 7015 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

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
			}
#line 10241 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 7117 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[-1]).to_string().get();
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
			}
#line 10359 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 7233 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

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
			}
#line 10408 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 7278 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 10469 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 7337 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

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
			}
#line 10518 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 7382 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 10579 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 7441 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-2]);

			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 10601 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 7459 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 10611 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 7467 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-3]);

			 String type = (yyvsp[-1]).to_string().get();
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
			}
#line 10633 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 7485 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 10643 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 7493 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);


			 funcps[fsaveindex + 1].insert();
			 funcps[fsaveindex + 1][pnum5].value((yyval));


			 funcstk.get_function(fsaveindex + 1).defaultv(pnum5, (yyval));
			 funcstk.get_function(fsaveindex + 1).syncdefaultp(pnum5);
			}
#line 10659 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 7507 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-2]);
			 pnum5 = (unsigned long)(yyvsp[0]).to_number().get();
			}
#line 10668 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 7514 "pnfha.ypp" /* yacc.c:1646  */
    {
			 fncdefault = true;
			 conprint("FNCDEFAULT TVOID 0V\n");
			}
#line 10677 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 7521 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-2]);

			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 10699 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 7539 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 10709 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 7547 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-2]);

			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 10731 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 7565 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 10741 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 7573 "pnfha.ypp" /* yacc.c:1646  */
    {
			 pnum5 = 0;


			 fsaveid = (yyvsp[-3]);
			 unsigned long index = funcstk.find((yyvsp[-3]).to_string().get(), frets2, fparams2);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 fsaveindex = index;

			 conprint("GOTOL TSTRING \"%s_END\"\n", funcstk.get_function(index).rname().getString().c_str());
			 conprint("LBL TSTRING \"%s\"\n", funcstk.get_function(index).rname().getString().c_str());
			}
#line 10763 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 7591 "pnfha.ypp" /* yacc.c:1646  */
    {
			 unsigned long index = funcstk.find(fsaveid.to_string().get(), frets2, fparams2);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 conprint("LBL TSTRING \"%s_END\"\n", funcstk.get_function(index).rname().getString().c_str());
			}
#line 10778 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 7602 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets2.length() - 1; i > 0; --i)
			  frets2.remove();

			 for (unsigned long i = fparams2.length() - 1; i > 0; --i)
			  fparams2.remove();
			}
#line 10790 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 7617 "pnfha.ypp" /* yacc.c:1646  */
    {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");

			 exptype = TVOID;
			}
#line 10802 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 7625 "pnfha.ypp" /* yacc.c:1646  */
    {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");


			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 10892 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 7711 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 10976 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 7793 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;
			}
#line 10984 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 7797 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 11036 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 7845 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 11088 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 7895 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;			}
#line 11095 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 7898 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 11161 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 7960 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 11234 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 8167 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;
			}
#line 11242 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 8171 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 11294 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 8219 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 11346 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 8269 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;
			}
#line 11354 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 8273 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 11406 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 8321 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 11458 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 8373 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11467 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 8378 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11476 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 8383 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11485 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 8388 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11494 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 8393 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11503 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 8398 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11512 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 8403 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11521 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 8408 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11530 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 8413 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11539 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 8418 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11548 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 8423 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11557 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 8428 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11566 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 8433 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11575 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 8438 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11584 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 8443 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11593 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 8448 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11602 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 8453 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11611 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 8458 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11620 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 8463 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11629 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 8468 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11638 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 8473 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11647 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 8478 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11656 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 8483 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11665 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 8488 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11674 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 8493 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11683 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 8498 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11692 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 8503 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11701 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 8508 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11710 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 8513 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11719 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 8518 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11728 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 8531 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("PRINT TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11738 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 8537 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("PRINT TBOOLEAN %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("PRINT TNUMBER %g\n", (yyvsp[0]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[0]).to_string().get();
			   
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
			   conprint("PRINT TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 11788 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 8583 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[0]).to_string().get() == "ver")
			  conprint("VPRINT TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			}
#line 11803 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 8594 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("PRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11813 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 8600 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("PRINTLN TBOOLEAN %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("PRINTLN TNUMBER %g\n", (yyvsp[0]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[0]).to_string().get();
			   
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
                           conprint("PRINTLN TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 11863 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 8646 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[0]).to_string().get() == "ver")
			  conprint("VPRINTLN TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			}
#line 11878 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 8657 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINT TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11888 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 8663 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("EPRINT TBOOLEAN %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("EPRINT TNUMBER %g\n", (yyvsp[0]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[0]).to_string().get();
			   
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
			   conprint("EPRINT TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 11938 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 8709 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11948 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 8715 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("EPRINTLN TBOOLEAN %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("EPRINTLN TNUMBER %g\n", (yyvsp[0]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[0]).to_string().get();
			   
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
			   conprint("EPRINTLN TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 11998 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 8761 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINT TVOID 0V\n");
			}
#line 12007 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 8766 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("FPRINT TBOOLEAN %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("FPRINT TNUMBER %g\n", (yyvsp[0]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[0]).to_string().get();
			   
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
			   conprint("FPRINT TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 12057 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 8812 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 12067 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 8818 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("FPRINTLN TBOOLEAN %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("FPRINTLN TNUMBER %g\n", (yyvsp[0]).to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = (yyvsp[0]).to_string().get();
			   
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
                           conprint("FPRINTLN TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 12117 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 8864 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 conprint("APRINT TVOID 0V\n");

			 tree.add_node(print_command);
			}
#line 12130 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 8876 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode read_command("read_command");

			 bool declared = false;
			 unsigned long address = 0;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
    		           address = varTable[scope][i].address();
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[0]).to_string().get();
			  str += " is not declared.";
			  yyerror(str.getString().c_str());
			 }


			 PNF_Variable v;
			 if ((yyvsp[-1]).to_string().get().getString() == "void")
			 {
			  yyerror("Cannot read a void.");
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "boolean")
			 {
			  conprint("READ TBOOLEAN 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "number")
			 {
			  conprint("READ TNUMBER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "character")
			 {
			  conprint("READ TCHARACTER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "string")
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
			}
#line 12193 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 8935 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode read_command("read_command");

			 bool declared = false;
			 unsigned long address = 0;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
    		           address = varTable[scope][i].address();
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[0]).to_string().get();
			  str += " is not declared.";
			  yyerror(str.getString().c_str());
			 }


			 PNF_Variable v;
			 if ((yyvsp[-1]).to_string().get().getString() == "void")
			 {
			  yyerror("Cannot read a void.");
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "boolean")
			 {
			  conprint("FREAD TBOOLEAN 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "number")
			 {
			  conprint("FREAD TNUMBER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "character")
			 {
			  conprint("FREAD TCHARACTER 0V\n");
			  ++varcount;
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "string")
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
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   PNF_Number n(0);
			   v.put(n);
			   varTable[scope][i].value(v);
			   varTable[scope][i].address(varcount - 1);
			  }
			 }
			 tree.add_node(read_command);
			}
#line 12267 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 9008 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode end_command("end_command");
			 conprint("QUIT TVOID %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(end_command);
			}
#line 12277 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 9016 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode asm_command("asm_command");
			 conprint("%s %s %s\n", strip_quotes((yyvsp[-2]).to_string().get()).getString().c_str(), 
					      strip_quotes((yyvsp[-1]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[0]).to_string().get()).getString().c_str());
			 tree.add_node(asm_command);
			}
#line 12288 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 9025 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "memory")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
			  {
			   switch ((yyvsp[0]).getType())
			   {
			    case TBOOLEAN:
    			     conprint("LOAD TBOOLEAN %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TNUMBER:
    	 		     conprint("LOAD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("LOAD TCHARACTER %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TSTRING:
    			     conprint("LOAD TSTRING %g\n", (yyvsp[0]).to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else if ((yyvsp[-2]).to_string().get().getString() == "%calc")
			  {
			   switch ((yyvsp[0]).getType())
			   {
			    case TBOOLEAN:
    			     conprint("LOADC TBOOLEAN %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TNUMBER:
    	 		     conprint("LOADC TNUMBER %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("LOADC TCHARACTER %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TSTRING:
    			     conprint("LOADC TSTRING %g\n", (yyvsp[0]).to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else
			   yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "variable")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
			  {
			   switch ((yyvsp[0]).getType())
			   {
			    case TBOOLEAN:
    			     conprint("VLOAD TBOOLEAN %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TNUMBER:
    			     conprint("VLOAD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("VLOAD TCHARACTER %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TSTRING:
    			     conprint("VLOAD TSTRING %g\n", (yyvsp[0]).to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else if ((yyvsp[-2]).to_string().get().getString() == "%calc")
			  {
			   switch ((yyvsp[0]).getType())
			   {
			    case TBOOLEAN:
    			     conprint("VLOADC TBOOLEAN %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TNUMBER:
    			     conprint("VLOADC TNUMBER %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("VLOADC TCHARACTER %g\n", (yyvsp[0]).to_number().get());
			     break;

			    case TSTRING:
    			     conprint("VLOADC TSTRING %g\n", (yyvsp[0]).to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "args")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
			   conprint("ARLOAD TVOID %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
 			   conprint("ALOAD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
                           yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "stk")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
                           conprint("LOADSP TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "seg1")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
			   conprint("SEGLOAD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror((char *)"Invalid register type.");
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12436 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 9169 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "tend")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
			  {
 			   PNF_Type_Enum t;
			   String str = (yyvsp[0]).to_string().get();
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
			  else if ((yyvsp[-2]).to_string().get().getString() == "%calc")
			  {
 			   PNF_Type_Enum t;
			   String str = (yyvsp[0]).to_string().get();
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
			}
#line 12533 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 9262 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[0]).to_string().get().getString() == "typeof")
			 {
			   conprint("TLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "iname")
			 {
			  conprint("INLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "icount")
			 {
			  conprint("ICLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "argn")
			 {
			  conprint("ARNLOAD TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "stk")
			  conprint("LOADSTACK TVOID 0V\n");	 
			 else
			  yyerror("Invalid load type.");
			}
#line 12565 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 9290 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TBOOLEAN %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12580 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 9301 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "rvalue")
			 {
			  conprint("RNUM TNUMBER %d\n", (unsigned long)(yyvsp[0]).to_number().get());
			  conprint("RETURNV TVOID 0V\n");
			 }			 
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12601 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 9318 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			 }			 
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12617 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 9330 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }			 
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12633 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 9342 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 PNF_Variable p;
			 unsigned long paddress = 0;
                         bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[0]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   p.put(varTable[scope][i].value());
			   paddress = varTable[scope][i].address();			   
			   break;
			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[0]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 if ((yyvsp[-1]).to_string().get().getString() == "memory")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
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
			  else if ((yyvsp[-2]).to_string().get().getString() == "%calc")
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
			 else if ((yyvsp[-1]).to_string().get().getString() == "variable")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
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
			  else if ((yyvsp[-2]).to_string().get().getString() == "%calc")
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
			 else if ((yyvsp[-1]).to_string().get().getString() == "args")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
			   conprint("ARLOAD TVOID %g\n", p.to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
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
			 else if ((yyvsp[-1]).to_string().get().getString() == "seg2")
			 {
			  if ((yyvsp[-2]).to_string().get().getString() == "%accmumulator")
			  {
			   conprint("SEGVLOAD TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12819 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 9524 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[-1]).to_string().get().getString() == "heve")
			  conprint("HEGET TVOID %g", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get().getString() == "sheve")
			  conprint("SHEGET TVOID %g", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get().getString() == "eve")
			  conprint("EGET TVOID %g", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get().getString() == "exe")
			  conprint("EXGET TVOID %g", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get().getString() == "int")
			  conprint("IGET TVOID %g", (yyvsp[0]).to_number().get());
		  	 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(load_command);
			}
#line 12842 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 9543 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[-1]).to_string().get() == "venum")
			 {
			  conprint("EPREP TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			  conprint("LOADE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid VTYPE2.");

			 tree.add_node(load_command);
			}
#line 12860 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 9557 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[-1]).to_string().get() == "rtype1")
			 {
			  conprint("RLOAD1 TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(load_command);
			}
#line 12877 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 9570 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 if ((yyvsp[-4]).to_string().get() == "rtype2")
			 {
			  conprint("RPREP2 TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			  conprint("RLOAD2 TNUMBER %g\n", (yyvsp[-1]).to_number().get());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(load_command);
			}
#line 12895 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 9584 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[-1]).to_number().get());
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			}
#line 12909 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 9594 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			}
#line 12923 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 9604 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 
			 if ((yyvsp[-3]).to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)(yyvsp[-2]).to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			  conprint("FNCSRET TBOOLEAN 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			}
#line 12952 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 9629 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 12964 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 9637 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 
			 if ((yyvsp[-3]).to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)(yyvsp[-2]).to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  conprint("FNCSRET TNUMBER 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			}
#line 12993 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 9662 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 13005 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 9670 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 
			 if ((yyvsp[-3]).to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)(yyvsp[-2]).to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			  conprint("FNCSRET TCHARACTER 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			}
#line 13034 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 9695 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 13046 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 9703 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 
			 if ((yyvsp[-3]).to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)(yyvsp[-2]).to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			  conprint("FNCSRET TSTRING 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			}
#line 13075 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 9728 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 13087 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 9736 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if ((yyvsp[0]).to_string().get().getString() == "\"get\"")
			 {
			  conprint("STRUCTGET TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "\"type1\"")
			 {
			  conprint("STRUCTTYPE TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "\"type2\"")
			 {
			  conprint("STRUCTTYPE2 TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "\"name1\"")
			 {
			  conprint("STRUCTNAME2 TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "\"name2\"")
			 {
			  conprint("STRUCTNAME3 TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid load type.");
			}
#line 13116 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 9761 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if ((yyvsp[0]).to_string().get().getString() == "\"get\"")
			 {
			  conprint("UNIONGET TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "\"type1\"")
			 {
			  conprint("UNIONTYPE TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "\"type2\"")
			 {
			  conprint("UNIONTYPE2 TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "\"name1\"")
			 {
			  conprint("UNIONNAME2 TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "\"name2\"")
			 {
			  conprint("UNIONNAME3 TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid load type.");
			}
#line 13145 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 9786 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if ((yyvsp[-1]).to_string().get().getString() == "tstruct")
			 {
			  conprint("STRUCTUSE TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "tunion")
			 {
			  conprint("UNIONUSE TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror((char *)"Invalid object type.");
			}
#line 13162 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 9799 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if ((yyvsp[-2]).to_string().get().getString() == "seg2")
			 {
			  if ((yyvsp[-3]).to_string().get().getString() == "%accumulator")
			  {
			   switch ((yyvsp[-1]).getType())
			   {
		 	    case TVOID:
			    {
			     conprint("SEGVLOAD TVOID %g\n", (yyvsp[0]).to_number().get());
			    }
			    break;

			    case TBOOLEAN:
			    {
			     conprint("SEGVLOAD TBOOLEAN %g\n", (yyvsp[0]).to_number().get());
			    }
			    break;

			   case TNUMBER:
			    {
			     conprint("SEGVLOAD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			    }
			    break;

			    case TCHARACTER:
			    {
			     conprint("SEGVLOAD TCHARACTER %g\n", (yyvsp[0]).to_number().get());
			    }
			    break;

			    case TSTRING:
			    {
			     conprint("SEGVLOAD TSTRING %g\n", (yyvsp[0]).to_number().get());
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
			}
#line 13214 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 9849 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode goto_command("goto_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "normal")
			 {
			  conprint("GOTO TVOID %g\n", (yyvsp[0]).to_number().get());
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "condition")
			  conprint("CGOTO TVOID %g\n", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get().getString() == "zero")
			  conprint("ZGOTO TVOID %g\n", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get().getString() == "positive")
			  conprint("PGOTO TVOID %g\n", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get().getString() == "negative")
			  conprint("NGOTO TVOID %g\n", (yyvsp[0]).to_number().get());
			 else
			  yyerror("Invalid goto type.");

			 tree.add_node(goto_command);
			}
#line 13238 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 9869 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode goto_command("goto_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "normal")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[0]).to_string().get().getString())
			   {
			    declared = true;
			    conprint("GOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "condition")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[0]).to_string().get().getString())
			   {
			    declared = true;
			    conprint("CGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "zero")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[0]).to_string().get().getString())
			   {
			    declared = true;
			    conprint("ZGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "positive")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[0]).to_string().get().getString())
			   {
			    declared = true;
			    conprint("PGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "negative")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[0]).to_string().get().getString())
			   {
			    declared = true;
			    conprint("NGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid goto type.");

			 tree.add_node(goto_command);
			}
#line 13345 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 9974 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13355 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 9980 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13365 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 9986 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13375 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 9992 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(operator_command);
			}
#line 13385 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 9998 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13395 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 10004 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13405 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 10010 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13415 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 10016 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13425 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 10022 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13435 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 10028 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13445 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 10034 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13455 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 10040 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13465 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 10046 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13475 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 10052 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13485 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 10058 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13495 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 10064 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13505 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 10070 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("INC TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13515 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 10076 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("DEC TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13525 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 10082 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("AND TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13535 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 10088 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("OR TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13545 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 10094 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NOT TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13555 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 10100 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13565 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 10106 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13575 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 10112 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13585 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 10118 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13595 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 10124 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13605 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 10130 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13615 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 10136 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[0]).to_boolean().get();

			 conprint("EQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			}
#line 13629 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 10146 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[0]).to_boolean().get();

			 conprint("NEQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			}
#line 13643 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 10156 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13653 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 10162 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13663 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 10168 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13673 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 10174 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13683 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 10180 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13693 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 10186 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13703 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 10192 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13713 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 10198 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13723 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 10204 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13733 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 10210 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13743 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 10216 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13753 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 10222 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13763 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 10228 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTAND TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13773 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 10234 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTOR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13783 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 10240 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTXOR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13793 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 10246 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTNOT TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13803 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 10252 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSL TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13813 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 10258 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13823 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 10265 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("CMP TVOID 0V");
			}
#line 13831 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 10269 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NTIMES TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13841 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 10275 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "run")
			 {
			  conprint("RUN TSTRING %s", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "jrun")
			 {
			  conprint("JRUN TSTRING %s", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "pnfrun")
			 {
			  conprint("PNFRUN TSTRING %s", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror((char *)"Bad run operator.");
			 tree.add_node(operator_command);
			}
#line 13864 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 10297 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp1("top_commandp1");

			 intop = true;
			 ++topcounter;

			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp1);
			}
#line 13880 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 10308 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp2("top_commandp2");			 

			 tree.add_node(top_commandp2);
			}
#line 13890 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 10314 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp3("top_commandp3");

			conprint("IFEND TVOID 0V\n"); 
			conprint("ENDIF TVOID 0V\n");

			 tree.add_node(top_commandp3);
			}
#line 13903 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 10323 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp4("top_commandp4");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp4);
			}
#line 13916 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 10332 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp5("top_commandp5");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");
			 conprint("EIF TVOID 0V\n");

			 tree.add_node(top_commandp5);
			}
#line 13930 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 10344 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode st_command("st_command");
			 conprint("ST TVOID 0V\n");
			 tree.add_node(st_command);
			}
#line 13940 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 10352 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode stack_command("stack_command");
			 conprint("PUSH TVOID 0V\n");
			 tree.add_node(stack_command);
			}
#line 13950 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 10358 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode stack_command("stack_command");
			 conprint("POP TVOID 0V\n");
			 tree.add_node(stack_command);
			}
#line 13960 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 10366 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode typeof_command("typeof_command");
			 if ((yyvsp[0]).to_string().get().getString() == "%accumulator")
  			  conprint("TYPEOF TVOID 0V\n");
			 else if ((yyvsp[0]).to_string().get().getString() == "%calc")
  			  conprint("CTYPEOF TVOID 0V\n");
                         else
			  yyerror("Invalid register type.");
			 tree.add_node(typeof_command);
			}
#line 13975 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 10379 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode rm_command("rm_command");
			 conprint("ATOC TVOID 0V\n");
			 tree.add_node(rm_command);
			}
#line 13985 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 10385 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("ATOSP TVOID 0V\n");
			}
#line 13993 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 10389 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SPTOA TVOID 0V\n");
			}
#line 14001 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 10393 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode rm_command("rm_command");
			 conprint("SWITCH TVOID 0V\n");
			 tree.add_node(rm_command);
			}
#line 14011 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 10401 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode crash_command("crash_command");
			 conprint("CRASH TSTRING %s", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(crash_command);
			}
#line 14021 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 10409 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode version_command("version_command");

			 if ((yyvsp[-1]).to_string().get().getString() == "pnf")
  			  conprint("VERSION TVOID %f\n", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get() == "pnfasm")
			  conprint("version TVOID 0V\n");
			 else if ((yyvsp[-1]).to_string().get().getString() == "normal")
  			  ; // Not used yet. This is the first version.
                         else
			  yyerror("Invalid version type.");

			 tree.add_node(version_command);
			}
#line 14040 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 10424 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode version_command("version_command");

			 conprint("MODE TVOID %f\n", (yyvsp[0]).to_number().get());


			 tree.add_node(version_command);
			}
#line 14053 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 10433 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode version_command("version_command");

			 conprint("EXTMODE TVOID %f\n", (yyvsp[0]).to_number().get());

			 tree.add_node(version_command);
			}
#line 14065 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 10443 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode halt_command("halt_command");
			 conprint("HALT TVOID 0V\n");
			 tree.add_node(halt_command);
			}
#line 14075 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 10451 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode modt_command("modt_command");

			 if ((yyvsp[0]).to_string().get().getString() == "%accumulator")
  			  conprint("MODT TVOID 0V\n");
			 else if ((yyvsp[0]).to_string().get().getString() == "%calc")
  			  conprint("MODCT TVOID 0V\n");
                         else
			  yyerror("Invalid register type.");

			 tree.add_node(modt_command);
			}
#line 14092 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 10466 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("RET TVOID 0V\n");
			 tree.add_node(subroutine_command);
			}
#line 14102 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 10472 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("CALL TVOID %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(subroutine_command);
			}
#line 14112 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 10478 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode subroutine_command("subroutine_command");

			 if ((yyvsp[-1]).to_string().get().getString() == "sub")
			 {
 			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == labelTable[i].name().getString())
			   {
			    declared = true;
			    double d = labelTable[i].address();
			    conprint("CALLL TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "heve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::hevents();
			    conprint("HEVENT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "sheve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::shevents();
			    conprint("SHEVENT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "eve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::events();
			    conprint("EVENT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "exe")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::exceptions();
			    conprint("EXCEPTION TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "int")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::ints();
			    conprint("INT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(subroutine_command);
			}
#line 14245 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 10609 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode register_command("register_command");

			 if ((yyvsp[0]).to_string().get().getString() == "heve")
			 {
			  conprint("HEREM TVOID 0V\n");
 			  CELabel::dechevents();
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "sheve")
			 {
			  conprint("SHEREM TVOID 0V\n");
 			  CELabel::decshevents();
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "eve")
			 {
			  conprint("EREM TVOID 0V\n");
 			  CELabel::decevents();
                         }
			 else if ((yyvsp[0]).to_string().get().getString() == "exe")
			 {
			  conprint("EXREM TVOID 0V\n");
 			  CELabel::decexceptions();
			 }
			 else if ((yyvsp[0]).to_string().get().getString() == "int")
			 {
			  conprint("IREM TVOID 0V\n");
 			  CELabel::decints();
                         }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			}
#line 14283 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 10643 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode register_command("register_command");

			 if ((yyvsp[-1]).to_string().get().getString() == "heve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "sheve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "eve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "exe")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "int")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			}
#line 14406 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 10762 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode register_command("register_command");

			 if ((yyvsp[-2]).to_string().get().getString() == "heve")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[-1]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[-1]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("HEED TVOID %g\n", d2);
			 }
			 else if ((yyvsp[-2]).to_string().get().getString() == "sheve")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[-1]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[-1]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("SHEED TVOID %g\n", d2);
			 }
			 else if ((yyvsp[-2]).to_string().get().getString() == "eve")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[-1]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[-1]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("EED TVOID %g\n", d2);
			 }
			 else if ((yyvsp[-2]).to_string().get().getString() == "exe")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[-1]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[-1]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("EXED TVOID %g\n", d2);
			 }
			 else if ((yyvsp[-2]).to_string().get().getString() == "int")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[-1]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = (yyvsp[-1]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("IED TVOID %g\n", d2);
			 }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			}
#line 14634 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 10986 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode register_command("register_command");

			 if ((yyvsp[-1]).to_string().get() == "heve")
			  conprint("HEADDB TVOID %g\n", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get() == "sheve")
			  conprint("SHEADDB TVOID %g\n", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get() == "eve")
			  conprint("EADDB TVOID %g\n", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get() == "exe")
			  conprint("EXADDB TVOID %g\n", (yyvsp[0]).to_number().get());
			 else if ((yyvsp[-1]).to_string().get() == "int")
			  conprint("IADDB TVOID %g\n", (yyvsp[0]).to_number().get());
			 else
			  yyerror("Invalid STYPE.");

			 tree.add_node(register_command);
			}
#line 14657 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 11007 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[-2]).to_string().get().getString() == "%accumulator")
			 {
			  if ((yyvsp[-1]).to_string().get().getString() == "memory")
			   conprint("STORE TVOID %g", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get().getString() == "variable")
			  {
			   conprint("VSTORE TVOID %g", (yyvsp[0]).to_number().get());
			  }
			  else if ((yyvsp[-1]).to_string().get().getString() == "stk")
			   conprint("STORESP TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get().getString() == "seg1")
			   conprint("SEGSTORE TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get().getString() == "seg2")
			   conprint("SEGVSTORE TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror("Invalid store type.");
			 }
			 else if ((yyvsp[-2]).to_string().get().getString() == "%calc")
			 {
			  if ((yyvsp[-1]).to_string().get().getString() == "memory")
			   conprint("STOREC TVOID %g", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get().getString() == "variable")
			  {
			   conprint("VSTOREC TVOID %g", (yyvsp[0]).to_number().get());
			  }
			  else
			   yyerror("Invalid store type.");
			 }
			 else
			  yyerror("Invalid register type.");

			 tree.add_node(store_command);
			}
#line 14698 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 11044 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if ((yyvsp[0]).to_string().get().getString() == "stk")
			 {
			  conprint("STORESTACK TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid store type.");
			}
#line 14711 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 11053 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[-1]).to_string().get().getString() == "%accumulator")
			 {
			  if ((yyvsp[0]).to_string().get().getString() == "variable")
			  {
			   conprint("VSTORE TVOID 0V");
			   ++varcount;
			  }
			  else if ((yyvsp[0]).to_string().get().getString() == "tend")
			   conprint("ESTORE TVOID 0V");
			 else if ((yyvsp[0]).to_string().get().getString() == "seg2")
			 {
			  conprint("SEGVSTORE TVOID 0V\n");
			 }
			  else
			   yyerror("Invalid store type.");
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "%calc")
			 {
			  if ((yyvsp[0]).to_string().get().getString() == "variable")
			  {
			   conprint("VSTOREC TVOID 0V");
		 	   ++varcount;
			  }
			  else if ((yyvsp[0]).to_string().get().getString() == "tend")
			   conprint("ESTOREC TVOID 0V");
			  else
			   yyerror("Invalid store type.");
			 }
			 else
			  yyerror("Invalid register type.");

			 tree.add_node(store_command);
			}
#line 14752 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 11090 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode store_command("store_command");

			 conprint("STOREA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 14764 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 11098 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[-1]).to_string().get() == "venum")
			 {
			  conprint("EPREP TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			  conprint("STOREE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid VTYPE2.");

			 tree.add_node(store_command);
			}
#line 14782 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 11112 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode store_command("store_command");

			 if ((yyvsp[-1]).to_string().get() == "rtype1")
			 {
			  conprint("RSTORE1 TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(store_command);
			}
#line 14799 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 11125 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[-1]).to_number().get());
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 14813 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 11135 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 14827 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 11147 "pnfha.ypp" /* yacc.c:1646  */
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
			}
#line 14849 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 11165 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode break_command("break_command");

			 if (inswitch || inloop2)
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == (yyvsp[0]).to_string().get().getString())
			   {
			    declared = true;
			    conprint("GOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }

  			 tree.add_node(break_command);
			}
#line 14879 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 11193 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode address_command("address_command");

			 unsigned long address = 0;
			 bool declared = false;
			 if ((yyvsp[-1]).to_string().get() == "avariable")
			 {
			  for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get() == varTable[scope][i].name())
			   {
			    declared = true;
			    address = varTable[scope][i].address();
			    break;
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get() + " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			  else
			  {
			   if (varTable.length() == 1)
                            --address;

			   conprint("VADD TVOID %u\n", address);
			  }
			 }
			 else if ((yyvsp[-1]).to_string().get() == "alabel")
			 {
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get() == labelTable[i].name())
			   {
		            declared = true;
			    address = i - 1;
			    break;
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get() + " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			  conprint("LADD TVOID %u\n", address);
			 }
			 else if ((yyvsp[-1]).to_string().get() == "aevent")
			 {
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if ((yyvsp[0]).to_string().get() == eventLabelTable[i].name())
			   {
		            declared = true;
			    address = i - 1;
			    break;
			   }
			  }

			  if (!declared)
			  {
			   String str = (yyvsp[0]).to_string().get() + " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			  conprint("EADD TVOID %u\n", address);
			 }
			 else
			 {
			  yyerror("Invalid address type.");
			 }

			 tree.add_node(address_command);
			}
#line 14959 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 11271 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode add2v_command("add2v_command");

			 conprint("ADD2V TVOID 0V\n");

		         tree.add_node(add2v_command);
			}
#line 14971 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 11281 "pnfha.ypp" /* yacc.c:1646  */
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
			}
#line 14992 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 11300 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[-2]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[-1]).to_string().get() == "void")
			   conprint("VCHECK TVOID %g\n", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get() == "number")
			   conprint("VCHECK TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "ver")
			 {
			  if ((yyvsp[-1]).to_string().get() == "void")
			   conprint("VSUPP TVOID %g\n", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get() == "number")
			   conprint("VSUPP TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "current_vmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "void")
			   conprint("MCHECK TVOID %g\n", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get() == "number")
			   conprint("MCHECK TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "vmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "void")
			   conprint("MSUPP TVOID %g\n", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get() == "number")
			   conprint("MSUPP TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "current_extvmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "void")
			   conprint("MEXTCHECK TVOID %g\n", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get() == "number")
			   conprint("MEXTCHECK TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "extvmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "void")
			   conprint("MEXTSUPP TVOID %g\n", (yyvsp[0]).to_number().get());
			  else if ((yyvsp[-1]).to_string().get() == "number")
			   conprint("MEXTSUPP TNUMBER %g\n", (yyvsp[0]).to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 15059 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 11363 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[-2]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[-1]).to_string().get() == "boolean")
			   conprint("VCHECK TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[-2]).to_string().get() == "ver")
			 {
			  if ((yyvsp[-1]).to_string().get() == "boolean")
			   conprint("VSUPP TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "current_vmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "boolean")
			   conprint("MCHECK TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[-2]).to_string().get() == "vmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "boolean")
			   conprint("MSUPP TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "current_extvmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "boolean")
			   conprint("MEXTCHECK TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[-2]).to_string().get() == "extvmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "boolean")
			   conprint("MEXTSUPP TBOOLEAN %s\n", (yyvsp[0]).to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 15114 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 11414 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[-2]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[-1]).to_string().get() == "character")
			   conprint("VCHECK TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[-2]).to_string().get() == "ver")
			 {
			  if ((yyvsp[-1]).to_string().get() == "character")
			   conprint("VSUPP TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "current_vmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "character")
			   conprint("MCHECK TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[-2]).to_string().get() == "vmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "character")
			   conprint("MSUPP TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "current_extvmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "character")
			   conprint("MEXTCHECK TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[-2]).to_string().get() == "extvmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "character")
			   conprint("MEXTSUPP TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 15169 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 11465 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[-2]).to_string().get() == "current_ver")
			 {
			  if ((yyvsp[-1]).to_string().get() == "string")
			   conprint("VCHECK TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[-2]).to_string().get() == "ver")
			 {
			  if ((yyvsp[-1]).to_string().get() == "string")
			   conprint("VSUPP TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "current_vmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "string")
			   conprint("MCHECK TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[-2]).to_string().get() == "vmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "string")
			   conprint("MSUPP TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if ((yyvsp[-2]).to_string().get() == "current_extvmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "string")
			   conprint("MEXTCHECK TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if ((yyvsp[-2]).to_string().get() == "extvmode")
			 {
			  if ((yyvsp[-1]).to_string().get() == "string")
			   conprint("MEXTSUPP TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 15224 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 11516 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode check_command("check_command");

			 if ((yyvsp[-1]).to_string().get() == "instruction")
			 {
   		          conprint("ISUPP TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 }
			 if ((yyvsp[-1]).to_string().get() == "type")
			 {
			  conprint("TSUPP TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 15245 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 11535 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode comment_command("comment_command");

			 if ((yyvsp[-1]).to_string().get() == "l2")
			 {
			  String str = strip_quotes((yyvsp[0]).to_string().get());
			  conprint(";\\ %s\n", str.getString().c_str());
			 }
			 else if ((yyvsp[-1]).to_string().get() == "l1")
			 {
			  conprint("COMMENT TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else
			 {
			  yyerror("Invalid comment type.");
                         }

		         tree.add_node(comment_command);
			}
#line 15269 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 11557 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode file_command("file_command");

			 if ((yyvsp[-1]).to_string().get() == "input")
			 {
			  if ((yyvsp[0]).to_string().get() == "in")
			   conprint("FIMODE TSTRING \"in\"\n");
			  else if ((yyvsp[0]).to_string().get() == "binary")
			   conprint("FIMODE TSTRING \"binary\"\n");
			  else
			   yyerror("Invalid file mode command.");
			 }
			 else if ((yyvsp[-1]).to_string().get() == "output")
			 {
			  if ((yyvsp[0]).to_string().get() == "out")
			   conprint("FOMODE TSTRING \"out\"\n");
			  else if ((yyvsp[0]).to_string().get() == "binary")
			   conprint("FOMODE TSTRING \"binary\"\n");
			  else if ((yyvsp[0]).to_string().get() == "ate")
			   conprint("FOMODE TSTRING \"ate\"\n");
			  else if ((yyvsp[0]).to_string().get() == "app")
			   conprint("FOMODE TSTRING \"app\"\n");
			  else if ((yyvsp[0]).to_string().get() == "trunc")
			   conprint("FOMODE TSTRING \"trunc\"\n");
			  else
			   yyerror("Invalid file mode command.");
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			}
#line 15306 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 11590 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode file_command("file_command");

			 if ((yyvsp[-1]).to_string().get() == "input")
			 {
			  conprint("FIOPEN TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else if ((yyvsp[-1]).to_string().get() == "output")
			 {
  			  conprint("FOOPEN TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			}
#line 15327 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 11607 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode file_command("file_command");

			 if ((yyvsp[0]).to_string().get() == "input")
			 {
			  conprint("FICLOSE TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get() == "output")
			 {
  			  conprint("FOCLOSE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			}
#line 15348 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 11624 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode file_command("file_command");

			 conprint("FIEOF TVOID 0V\n");

			 tree.add_node(file_command);
			}
#line 15360 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 11634 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode meml_command("meml_command");

			 conprint("MEML TVOID 0V\n");

			 tree.add_node(meml_command);
			}
#line 15372 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 11644 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pnfasm_command("pnfasm_command");

			 conprint("pnf %s %s %s\n", strip_quotes((yyvsp[-2]).to_string().get()).getString().c_str(), 
						 strip_quotes((yyvsp[-1]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[0]).to_string().get()).getString().c_str());

			 tree.add_node(pnfasm_command);
			}
#line 15385 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 11655 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode array_length_command("array_length_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 conprint("ALENGTH TVOID 0V\n");

			 tree.add_node(array_length_command);
			}
#line 15398 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 11665 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode dup_command("dup_command");

			 if ((yyvsp[0]).to_string().get() == "%accumulator")
			 {
			  conprint("DUP TVOID 0V\n");
			 }
			 else if ((yyvsp[0]).to_string().get() == "%calc")
			 {
			  conprint("CDUP TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid register.");

			 tree.add_node(dup_command);
			}
#line 15419 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 11684 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("FRET TVOID 0V\n");
			}
#line 15427 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 11694 "pnfha.ypp" /* yacc.c:1646  */
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
			  if (funcps[index][i].name() == (yyvsp[-1]).to_string().get())
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
			
			 String str = (yyvsp[0]).to_string().get();
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
			}
#line 15475 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 11738 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			}
#line 15487 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 553:
#line 11748 "pnfha.ypp" /* yacc.c:1646  */
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
			  if (funcps[index][i].name() == (yyvsp[-2]).to_string().get())
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

			 String type = (yyvsp[0]).to_string().get();
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
			}
#line 15538 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 554:
#line 11795 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			}
#line 15550 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 555:
#line 11805 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-3]);
			}
#line 15558 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 556:
#line 11811 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-3]);
			}
#line 15566 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 557:
#line 11817 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("STRUCTUSING TVOID 0V\n");
			}
#line 15574 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 558:
#line 11821 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("STRUCTUSINGNAME TVOID 0V\n");
			}
#line 15582 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 559:
#line 11827 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("UNIONUSING TVOID 0V\n");
			}
#line 15590 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 560:
#line 11831 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("UNIONUSINGNAME TVOID 0V\n");
			}
#line 15598 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 561:
#line 11837 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("CPY TVOID 0V\n");
			}
#line 15606 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 562:
#line 11843 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("ADDSEG TVOID 0V\n");
			}
#line 15614 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 563:
#line 11847 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("REMSEG TVOID 0V\n");
			}
#line 15622 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 564:
#line 11851 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if ((yyvsp[-1]).to_string().get().getString() == "collapse")
			 {
			  conprint("COLLSEG TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 }
			 else if ((yyvsp[-1]).to_string().get().getString() == "expand")
			 {
			  conprint("EXPSEG TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 }
			 else
			  yyerror((char *)"Invalid CETYPE.");
			}
#line 15639 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 565:
#line 11864 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("CPYSEG TVOID 0V\n");
			}
#line 15647 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 566:
#line 11868 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("PUSHSEG TVOID 0V\n");
			}
#line 15655 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 567:
#line 11872 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("POPSEG TVOID 0V\n");
			}
#line 15663 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 568:
#line 11876 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("TOPSEG TVOID 0V\n");
			}
#line 15671 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 569:
#line 11882 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#BIN#\n");
			 tree.add_node(pp_directive);
			}
#line 15681 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 570:
#line 11888 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#PBIN#\n");
			 tree.add_node(pp_directive);
			}
#line 15691 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 571:
#line 11894 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#LIB#\n");
			 tree.add_node(pp_directive);
			}
#line 15701 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 572:
#line 11902 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include %s", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 15711 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 573:
#line 11908 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include <%s>", (yyvsp[-2]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15721 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 574:
#line 11914 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 15731 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 575:
#line 11920 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import <%s>\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 15741 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 576:
#line 11926 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#define %s %s\n", (yyvsp[-1]).to_string().get().getString().c_str(), 
						    (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15752 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 577:
#line 11933 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#macro %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15762 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 578:
#line 11939 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endm\n");
			 tree.add_node(pp_statement);
		 	}
#line 15772 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 579:
#line 11945 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#undef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15782 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 580:
#line 11951 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#ifdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15792 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 581:
#line 11957 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#infdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15802 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 582:
#line 11963 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#else\n"); 
			 tree.add_node(pp_statement);
			}
#line 15812 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 583:
#line 11969 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endif\n"); 
			 tree.add_node(pp_statement);
			}
#line 15822 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 584:
#line 11975 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_DATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15832 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 585:
#line 11981 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_TIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15842 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 586:
#line 11987 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_LINE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15852 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 587:
#line 11993 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_FILE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15862 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 588:
#line 11999 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CDATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15872 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 589:
#line 12005 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CTIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15882 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 590:
#line 12011 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
		 	 conprint("%%include %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15892 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 591:
#line 12017 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%include <%s>\n", (yyvsp[-2]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15902 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 592:
#line 12023 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15912 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 593:
#line 12029 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import <%s>\n", (yyvsp[-2]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15922 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 594:
#line 12035 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%define %s %s\n", (yyvsp[-1]).to_string().get().getString().c_str(), 
						     (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15933 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 595:
#line 12042 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%macro %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15943 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 596:
#line 12048 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endm\n"); 
			 tree.add_node(pp_statement);
			}
#line 15953 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 597:
#line 12054 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%undef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15963 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 598:
#line 12060 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%ifdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15973 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 599:
#line 12066 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%infdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15983 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 600:
#line 12072 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%else\n"); 
			 tree.add_node(pp_statement);
			}
#line 15993 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 601:
#line 12078 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endif\n"); 
			 tree.add_node(pp_statement);
			}
#line 16003 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 602:
#line 12084 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_DATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16013 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 603:
#line 12090 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_TIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16023 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 604:
#line 12096 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_LINE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16033 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 605:
#line 12102 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_FILE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16043 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 606:
#line 12108 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CDATE()\n");
			 tree.add_node(pp_statement);
			}
#line 16053 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 607:
#line 12114 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CTIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16063 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;


#line 16067 "pnfha.tab.cpp" /* yacc.c:1646  */
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
#line 12120 "pnfha.ypp" /* yacc.c:1906  */

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
