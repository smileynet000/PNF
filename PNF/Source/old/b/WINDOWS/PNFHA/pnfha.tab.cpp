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

#line 842 "pnfha.tab.cpp" /* yacc.c:339  */

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
    ID = 300,
    VAR = 301,
    PRINT = 302,
    PRINTLN = 303,
    EPRINT = 304,
    EPRINTLN = 305,
    END = 306,
    ASM = 307,
    TYPE = 308,
    READ = 309,
    LOAD = 310,
    LTYPE = 311,
    GOTO = 312,
    GTYPE = 313,
    ST = 314,
    PUSH = 315,
    POP = 316,
    TYPEOF = 317,
    RTYPE = 318,
    ATOC = 319,
    SWITCH = 320,
    CSWITCH = 321,
    CRASH = 322,
    VERSION = 323,
    VTYPE = 324,
    HALT = 325,
    MODT = 326,
    RETURN = 327,
    GOSUB = 328,
    SUB = 329,
    EVENT = 330,
    STYPE = 331,
    ATYPE = 332,
    CTYPE = 333,
    CMTYPE = 334,
    BFMODEC = 335,
    FMODEC = 336,
    UNREGISTER = 337,
    REGISTER = 338,
    REREGISTER = 339,
    STORE = 340,
    IF = 341,
    ELSE = 342,
    CASE = 343,
    CCASE = 344,
    DEFAULT = 345,
    CDEFAULT = 346,
    BREAK = 347,
    LABEL = 348,
    WHILE = 349,
    ADDRESSOF = 350,
    ADD2V = 351,
    STOREA = 352,
    DOWHILE = 353,
    DOFOR = 354,
    FOR = 355,
    FVAR = 356,
    FOREVER = 357,
    CONTINUE = 358,
    CHECK = 359,
    HCMNT = 360,
    FMODE = 361,
    FOPEN = 362,
    FCLOSE = 363,
    FEOF = 364,
    FPRINT = 365,
    FPRINTLN = 366,
    FREAD = 367,
    MEML = 368,
    ENUM = 369,
    ENUMV = 370,
    VTYPE2 = 371,
    RANGE = 372,
    RTYPE2 = 373,
    OPDOT = 374,
    RANGEV = 375,
    OPLSQ = 376,
    OPRSQ = 377,
    ARRAY = 378,
    BLANK = 379,
    PNFASM = 380,
    LENGTH = 381,
    DUP = 382,
    THEN = 383,
    ENDIF = 384,
    DONEIF = 385,
    ATOSP = 386,
    SPTOA = 387,
    FUNCTION = 388,
    FUNCDEF = 389,
    FUNCCALL = 390,
    FRET = 391,
    FPARAMETER = 392,
    DEFAULTV = 393,
    DEFAULTV2 = 394,
    UNTIL = 395,
    UNLESS = 396,
    DOUNTIL = 397,
    PBIN = 398,
    PPBIN = 399,
    PLIB = 400,
    PINCLUDE = 401,
    PIMPORT = 402,
    PDEFINE = 403,
    PMACRO = 404,
    PENDM = 405,
    PUNDEF = 406,
    PIFDEF = 407,
    PIFNDEF = 408,
    PELSE = 409,
    PENDIF = 410,
    PPDATE = 411,
    PPTIME = 412,
    PPLINE = 413,
    PPFILE = 414,
    PPCDATE = 415,
    PPCTIME = 416,
    PPINCLUDE = 417,
    PPIMPORT = 418,
    PPDEFINE = 419,
    PPMACRO = 420,
    PPENDM = 421,
    PPUNDEF = 422,
    PPIFDEF = 423,
    PPIFNDEF = 424,
    PPELSE = 425,
    PPENDIF = 426,
    PPPDATE = 427,
    PPPTIME = 428,
    PPPLINE = 429,
    PPPFILE = 430,
    PPPCDATE = 431,
    PPPCTIME = 432
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

#line 1068 "pnfha.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   1799

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  181
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  194
/* YYNRULES -- Number of rules.  */
#define YYNRULES  559
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1014

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   435

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
     175,   176,   177,   178,   179,   180
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   985,   985,   986,   989,   989,   994,   995,   998,   998,
    1003,  1006,  1008,  1010,  1012,  1014,  1016,  1018,  1021,  1022,
    1025,  1032,  1039,  1046,  1079,  1087,  1097,  1103,  1109,  1114,
    1125,  1131,  1140,  1147,  1152,  1124,  1168,  1176,  1185,  1192,
    1197,  1167,  1212,  1213,  1212,  1234,  1238,  1277,  1306,  1311,
    1237,  1323,  1338,  1344,  1322,  1358,  1358,  1363,  1367,  1366,
    1410,  1411,  1410,  1421,  1421,  1426,  1430,  1461,  1429,  1476,
    1477,  1476,  1487,  1487,  1497,  1496,  1506,  1511,  1516,  1522,
    1521,  1541,  1551,  1557,  1540,  1578,  1588,  1595,  1603,  1609,
    1578,  1628,  1638,  1644,  1627,  1668,  1678,  1685,  1693,  1699,
    1668,  1719,  1723,  1733,  1741,  1751,  1719,  1771,  1784,  1793,
    1799,  1808,  1818,  1770,  1834,  1833,  1853,  1857,  1862,  1869,
    1870,  1878,  1880,  1882,  1884,  1886,  1888,  1890,  1895,  1905,
    1908,  1924,  1938,  1954,  1970,  1973,  1987,  1993,  1999,  2005,
    2011,  2017,  2025,  2032,  2039,  2045,  2051,  2057,  2063,  2071,
    2080,  2088,  2095,  2103,  2111,  2115,  2128,  2135,  2142,  2149,
    2155,  2162,  2169,  2176,  2182,  2188,  2194,  2200,  2204,  2217,
    2242,  2249,  2253,  2324,  2364,  2401,  2478,  2557,  2637,  2675,
    2713,  2751,  2789,  2802,  2840,  2878,  2906,  2934,  2962,  2990,
    2993,  3004,  3015,  3026,  3037,  3049,  3048,  3068,  3094,  3095,
    3144,  3193,  3242,  3291,  3333,  3375,  3417,  3459,  3501,  3543,
    3585,  3627,  3669,  3711,  3753,  3795,  3837,  3879,  3921,  3963,
    4005,  4047,  4089,  4131,  4173,  4215,  4257,  4299,  4363,  4427,
    4472,  4517,  4562,  4607,  4652,  4697,  4742,  4787,  4832,  4877,
    4922,  4967,  5012,  5057,  5102,  5147,  5192,  5237,  5274,  5319,
    5364,  5409,  5454,  5512,  5572,  5576,  5583,  5587,  5594,  5599,
    5618,  5628,  5582,  5643,  5650,  5661,  5704,  5747,  5873,  6018,
    6153,  6158,  6163,  6168,  6175,  6233,  6314,  6349,  6354,  6359,
    6366,  6378,  6393,  6409,  6421,  6429,  6420,  6443,  6451,  6457,
    6482,  6506,  6529,  6553,  6554,  6558,  6557,  6603,  6605,  6698,
    6810,  6912,  7028,  7073,  7132,  7177,  7236,  7254,  7262,  7280,
    7288,  7288,  7302,  7309,  7309,  7316,  7334,  7342,  7360,  7369,
    7387,  7368,  7407,  7412,  7420,  7506,  7588,  7592,  7640,  7690,
    7693,  7755,  7962,  7966,  8014,  8064,  8068,  8116,  8168,  8173,
    8178,  8183,  8188,  8193,  8198,  8203,  8208,  8213,  8218,  8223,
    8228,  8233,  8238,  8243,  8248,  8253,  8258,  8263,  8268,  8273,
    8278,  8283,  8288,  8293,  8298,  8303,  8308,  8313,  8318,  8322,
    8328,  8374,  8385,  8391,  8437,  8448,  8454,  8500,  8506,  8552,
    8557,  8603,  8609,  8655,  8667,  8726,  8799,  8807,  8816,  8953,
    9046,  9074,  9085,  9102,  9113,  9124,  9299,  9318,  9332,  9345,
    9359,  9369,  9380,  9379,  9413,  9412,  9446,  9445,  9479,  9478,
    9513,  9533,  9638,  9644,  9650,  9656,  9662,  9668,  9674,  9680,
    9686,  9692,  9698,  9704,  9710,  9716,  9722,  9728,  9734,  9740,
    9746,  9752,  9758,  9764,  9770,  9776,  9782,  9788,  9794,  9800,
    9810,  9820,  9826,  9832,  9838,  9844,  9850,  9856,  9862,  9868,
    9874,  9880,  9886,  9892,  9898,  9904,  9910,  9916,  9922,  9928,
    9929,  9937,  9948,  9954,  9963,  9936,  9983,  9991,  9997, 10005,
   10018, 10024, 10028, 10032, 10040, 10048, 10065, 10073, 10088, 10094,
   10100, 10231, 10265, 10384, 10608, 10629, 10662, 10671, 10704, 10712,
   10726, 10739, 10749, 10761, 10779, 10807, 10885, 10895, 10914, 10941,
   10964, 10987, 11010, 11029, 11051, 11084, 11101, 11118, 11128, 11138,
   11149, 11159, 11178, 11184, 11185, 11189, 11188, 11243, 11242, 11299,
   11305, 11311, 11317, 11323, 11331, 11337, 11343, 11349, 11355, 11362,
   11368, 11374, 11380, 11386, 11392, 11398, 11404, 11410, 11416, 11422,
   11428, 11434, 11440, 11446, 11452, 11458, 11464, 11471, 11477, 11483,
   11489, 11495, 11501, 11507, 11513, 11519, 11525, 11531, 11537, 11543
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
  "OPQUES", "OPCOLON", "OPSUB", "OPSTR", "ID", "VAR", "PRINT", "PRINTLN",
  "EPRINT", "EPRINTLN", "END", "ASM", "TYPE", "READ", "LOAD", "LTYPE",
  "GOTO", "GTYPE", "ST", "PUSH", "POP", "TYPEOF", "RTYPE", "ATOC",
  "SWITCH", "CSWITCH", "CRASH", "VERSION", "VTYPE", "HALT", "MODT",
  "RETURN", "GOSUB", "SUB", "EVENT", "STYPE", "ATYPE", "CTYPE", "CMTYPE",
  "BFMODEC", "FMODEC", "UNREGISTER", "REGISTER", "REREGISTER", "STORE",
  "IF", "ELSE", "CASE", "CCASE", "DEFAULT", "CDEFAULT", "BREAK", "LABEL",
  "WHILE", "ADDRESSOF", "ADD2V", "STOREA", "DOWHILE", "DOFOR", "FOR",
  "FVAR", "FOREVER", "CONTINUE", "CHECK", "HCMNT", "FMODE", "FOPEN",
  "FCLOSE", "FEOF", "FPRINT", "FPRINTLN", "FREAD", "MEML", "ENUM", "ENUMV",
  "VTYPE2", "RANGE", "RTYPE2", "OPDOT", "RANGEV", "OPLSQ", "OPRSQ",
  "ARRAY", "BLANK", "PNFASM", "LENGTH", "DUP", "THEN", "ENDIF", "DONEIF",
  "ATOSP", "SPTOA", "FUNCTION", "FUNCDEF", "FUNCCALL", "FRET",
  "FPARAMETER", "DEFAULTV", "DEFAULTV2", "UNTIL", "UNLESS", "DOUNTIL",
  "PBIN", "PPBIN", "PLIB", "PINCLUDE", "PIMPORT", "PDEFINE", "PMACRO",
  "PENDM", "PUNDEF", "PIFDEF", "PIFNDEF", "PELSE", "PENDIF", "PPDATE",
  "PPTIME", "PPLINE", "PPFILE", "PPCDATE", "PPCTIME", "PPINCLUDE",
  "PPIMPORT", "PPDEFINE", "PPMACRO", "PPENDM", "PPUNDEF", "PPIFDEF",
  "PPIFNDEF", "PPELSE", "PPENDIF", "PPPDATE", "PPPTIME", "PPPLINE",
  "PPPFILE", "PPPCDATE", "PPPCTIME", "\"\\n\"", "\"<\"", "\">\"",
  "$accept", "input", "line", "$@1", "statement", "$@2", "stmt",
  "expression_statement", "declaration_statement", "command_statement",
  "label_statement", "control_statement", "if_statement", "$@3", "$@4",
  "$@5", "$@6", "$@7", "unless_statement", "$@8", "$@9", "$@10", "$@11",
  "$@12", "opt_else", "$@13", "eif", "switch_statement", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "$@20", "case_statements", "$@21",
  "case_statement", "$@22", "opt_default_statement", "$@23",
  "case_statements2", "$@24", "case_statement2", "$@25", "$@26",
  "opt_default_statement2", "$@27", "loop_statement", "$@28", "$@29",
  "$@30", "while_loop", "$@31", "$@32", "$@33", "whileb_loop", "$@34",
  "$@35", "$@36", "$@37", "$@38", "until_loop", "$@39", "$@40", "$@41",
  "untilb_loop", "$@42", "$@43", "$@44", "$@45", "$@46", "for_loop",
  "$@47", "$@48", "$@49", "$@50", "$@51", "forb_loop", "$@52", "$@53",
  "$@54", "$@55", "$@56", "$@57", "forever_loop", "$@58",
  "statement_block", "statements", "expression", "void_expression",
  "boolean_expression", "number_expression", "character_expression",
  "string_expression", "id_expression", "relational_expression", "@59",
  "mixed_expression", "function_expression", "function_command", "$@60",
  "$@61", "$@62", "$@63", "$@64", "$@65", "actual_function_parameters",
  "dv", "opt_expressions", "opt_expression", "declaration",
  "variable_declaration", "enumv_declaration", "rangev_declaration",
  "array_declaration", "enum_declaration", "$@67", "$@68", "enum_strings",
  "range_declaration", "label_declaration", "function_declaration", "$@69",
  "nothing", "parameter_declaration", "parameter_declaration2",
  "parameter_declaration5", "parameter_declaration6", "opt_var",
  "opt_var2", "opt_default_value", "dvalue", "optdefaultv", "opt_var5",
  "opt_var6", "function_declaration2", "$@70", "$@71", "function_body",
  "vars", "vars2", "vars3", "vars5", "vars6", "command", "print_command",
  "read_command", "end_command", "asm_command", "load_command", "$@72",
  "$@73", "$@74", "$@75", "goto_command", "operator_command",
  "top_command", "$@76", "$@77", "$@78", "$@79", "st_command",
  "stack_command", "typeof_command", "rm_command", "crash_command",
  "version_command", "halt_command", "modt_command", "subroutine_command",
  "register_command", "store_command", "break_command", "address_command",
  "add2v_command", "continue_command", "check_command", "comment_command",
  "file_command", "meml_command", "pnfasm_command", "array_length_command",
  "dup_command", "fret_command", "parameter_command", "psig", "$@80",
  "psig2", "$@81", "signature", "signature2", "pp_directive",
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
     435
};
# endif

#define YYPACT_NINF -743

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-743)))

#define YYTABLE_NINF -118

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -743,   998,  -743,  -743,  -743,  -144,    24,  1174,  -743,  1174,
     669,   669,   245,   499,   581,   750,   750,   750,   750,   750,
     320,   929,  -743,  -743,  1552,  1552,  1552,  1552,  -743,  1544,
    1544,  -743,  -743,  -743,  -743,   152,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,   750,    62,  1518,    25,   563,   657,   152,
     152,   750,    37,    55,    11,    60,  -743,  -743,  -743,    32,
    -743,    93,   124,    62,    98,  -743,   128,  -743,   203,   149,
     163,   139,   -35,   147,   155,   199,   218,   248,   197,  -743,
    -743,   251,  -743,  -743,   253,   257,   264,   267,   275,  -743,
     152,   152,   288,  -743,   326,   322,   255,   263,   369,   402,
     331,  -743,  -743,   304,   383,   404,  -743,   414,   425,  -743,
    -743,  -743,   -33,   -32,   416,   423,  -743,   436,   437,   444,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   -27,   -18,
     445,   447,  -743,   448,   450,   451,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,   421,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,   396,  -743,   394,  -743,   351,  -743,
     395,  -743,  -743,  -743,   455,  -743,   289,  1703,  1507,   481,
    1682,  -743,  -743,  -743,  -743,   459,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,   461,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
     456,  -743,  -743,   421,   669,   669,   581,   750,   581,   320,
     669,  -743,  1638,  1615,  1766,  1638,  1615,  1766,   581,   581,
     245,   581,   245,   349,  1766,   750,   750,   750,   750,  -743,
    1638,   581,  1766,  1727,  1727,  1727,  1727,  1727,   320,   320,
     320,  1638,  1766,  1552,  1552,   929,  1727,  1558,   489,  1552,
    1727,  1558,  1727,  1558,  1727,  1558,  1727,  1558,   142,  1544,
     349,  1727,  1558,   349,  1727,  1558,   499,  1746,   474,   261,
    1582,  1656,    20,  1630,   477,   480,    -2,   479,  1727,    62,
     489,   750,  1552,  1552,  1552,  1552,  1552,   929,   750,   750,
     750,   750,   750,   750,   750,   750,   750,   750,   750,   142,
     142,  -743,   496,  -743,   490,  -743,  -743,  -743,  -743,  -743,
    1727,   495,   491,  1452,   482,   750,   502,   419,   503,   512,
     487,   714,  -743,   152,  1174,   489,  -743,  -743,   501,  1727,
     508,   510,  -743,   513,   483,   515,  -743,   497,  -743,   517,
     443,   525,  1174,  -743,  -743,   520,  1174,  -743,  1174,   315,
      62,   492,    62,  -743,  -743,  -743,   523,   545,   538,   540,
     542,    30,   543,  -743,  -743,   552,     3,   547,    44,  1174,
    -743,   548,  -743,   550,   554,  -743,  -743,  -743,  -743,  -743,
     556,  -743,   558,   564,  -743,  -743,  -743,  -743,  -743,   573,
    -743,   464,  -743,  -743,   575,  -743,  -743,    23,   319,  -743,
    -743,   780,   808,   844,   856,   868,   750,   880,   915,   917,
     934,  1349,  1351,  1363,  1368,  1388,  1402,  1407,  1427,  1432,
    -743,  -743,   133,   138,   228,   366,    39,   411,   454,   175,
    -743,  -743,   581,   581,   581,   581,   581,   581,   581,   581,
     581,  -743,  -743,   553,  1606,  1669,   750,   750,   750,   750,
     750,   750,   750,   750,   750,   750,   750,    39,    39,    39,
      39,    39,    39,   378,   142,   142,    21,    62,   142,  -743,
    -743,   568,   569,   570,   578,   582,   594,   595,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  1727,  1727,  1558,  1727,
    1558,  1727,  1558,  1727,  1558,  1727,  1558,  1727,  1558,   489,
    1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,
    1727,   349,   349,   152,  -743,    62,  -743,  1452,   349,  1727,
    1558,   489,    90,  1727,  -743,   605,   524,    71,   750,  -743,
    1727,   613,   223,  -743,  -743,  -743,  -743,   750,   603,   750,
    -743,   611,   529,   236,  -743,   421,   421,  1452,  1727,   489,
    -743,   489,  -743,   626,   630,   633,   628,   541,   750,   631,
     111,  -743,   636,    -1,  -743,  -743,   637,   210,   250,   488,
     500,  -743,   504,   509,  -743,  -743,  -743,   640,  -743,  1174,
    1174,  -743,  -743,   653,  -743,  -743,  -743,  1773,  -743,  1773,
    -743,  1773,  -743,   221,  -743,   221,   221,  -743,   269,  -743,
     269,  -743,   391,  -743,   391,  -743,  1727,  -743,  1727,  -743,
    1727,  -743,  1727,  -743,  1727,  -743,  1727,  -743,  1727,  -743,
    -743,  -743,  -743,    39,    39,    39,  -743,  1615,  -743,  1615,
    -743,   435,  -743,   435,   435,  -743,  -743,  -743,  -743,  -743,
    -743,  1766,  1766,   165,   165,   165,   424,   424,   654,  -743,
     635,  -743,   489,  -743,  -743,  1727,   576,    43,  -743,   648,
     302,  1489,   664,  -743,  1727,  -743,  1727,  -743,    52,  -743,
     600,   349,  1727,  1558,   489,  -743,   665,   666,   678,  -743,
     375,  -743,  -743,   668,   306,   659,   670,   673,   686,   667,
     677,   679,  -743,  -743,  -743,  -743,  -743,  1174,  1174,  -743,
      -8,   -16,  1174,  -743,  -743,  -743,   750,  -743,   506,   671,
     681,   684,  1452,  -743,   695,  -743,   621,   604,   701,   696,
    -743,   614,   698,  -743,   685,   692,   693,  -743,   710,   700,
     116,  -743,   715,   704,   619,   421,   421,  1174,  -743,  -743,
     132,  -743,  -743,   820,  -743,  -743,   719,   709,   349,  1727,
    1558,   489,  -743,  -743,  -743,  -743,  -743,  -743,   712,   639,
    -743,  -743,   725,   718,   130,   703,  -743,   726,   308,   135,
     716,  -743,   728,   740,   421,   742,   743,  -743,  -743,  -743,
     168,   729,  -743,  -743,  -743,  -743,   697,   697,   702,   702,
    1174,  1174,   751,   748,   752,   194,   745,  -743,   754,   312,
    -743,  -743,   753,   758,   747,  -743,   760,   327,  -743,  -743,
    1174,  -743,  -743,   777,  -743,  -743,  1174,  -743,   764,   332,
    -743,  -743,  -743,  -743,  -743,  -743,   152,   723,  -743,  -743,
     152,   735,  -743,  -743,   421,   229,  -743,  -743,  -743,  -743,
     769,   362,  -743,  -743,   778,  -743,   793,  -743,  -743,   798,
     799,  -743,   796,   421,  1174,  1174,  -743,  1174,  1174,   356,
     801,  -743,   803,  -743,   810,  -743,  -743,   812,  -743,   721,
    -743,   813,  -743,   811,   809,  -743,   816,   826,   814,   823,
     819,   744,   421,   421,  1174,   421,   421,  -743,   824,   833,
     837,  -743,  -743,   839,  -743,   852,  -743,  1174,   835,   858,
     846,  -743,  -743,   851,  -743,  -743,  -743,   854,  -743,   421,
     866,   869,  1174,  -743,   857,  1174,  1174,   870,  -743,  1174,
    -743,   818,   371,   878,  -743,  -743,   867,   859,    77,   861,
     818,  -743,  -743,   421,   862,   421,   421,  -743,  1174,   421,
    -743,  -743,  -743,   152,  -743,  -743,   895,  -743,   881,  -743,
     893,  -743,  -743,  -743,   871,  -743,  -743,  -743,   908,  -743,
     421,  1174,   822,  1174,   898,  -743,  -743,   878,   897,  -743,
      95,   822,  1174,   -13,  -743,  -743,   421,   910,  -743,  -743,
     923,   913,  -743,  -743,   421,  -743,   925,  -743,  -743,   904,
    -743,  -743,  -743,  -743
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     7,     3,     0,     6,    72,     5,    72,
     428,   429,   432,   456,   453,   424,   426,   418,   420,   422,
     416,   412,   457,   458,   435,   437,   436,   438,   460,   433,
     434,   455,   454,   430,   431,     0,     8,   128,   130,   135,
     155,   168,    12,     0,     0,   172,     0,   369,   372,   375,
     377,     0,     0,     0,     0,     0,   466,   467,   468,     0,
     470,   473,     0,     0,     0,   476,     0,   478,     0,     0,
       0,     0,     0,     0,     0,     0,   493,     0,     0,   496,
     107,     0,   114,   497,     0,     0,     0,     0,     0,   507,
     379,   381,     0,   508,     0,     0,     0,     0,     0,     0,
       0,   471,   472,   313,     0,     0,   512,     0,     0,   521,
     522,   523,     0,     0,     0,     0,   530,     0,     0,     0,
     534,   535,   536,   537,   538,   539,   540,   541,     0,     0,
       0,     0,   548,     0,     0,     0,   552,   553,   554,   555,
     556,   557,   558,   559,     9,    13,    14,    16,    15,    11,
      26,    27,    28,    29,     0,    74,     0,    76,     0,    77,
       0,    78,    79,    17,     0,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   254,     0,   270,   277,   278,   279,
     272,   273,   271,   293,   294,     0,   338,   339,   340,   341,
     342,   343,   344,   459,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   513,   514,
       0,    18,    19,    10,     0,     0,     0,     0,     0,     0,
       0,   172,   144,   163,   185,   146,   165,   187,     0,     0,
       0,     0,     0,   131,   174,     0,     0,     0,     0,   247,
     151,     0,   173,   425,   427,   419,   421,   423,     0,     0,
       0,   141,   182,     0,     0,     0,   413,   414,   415,     0,
     443,   449,   445,   451,   444,   450,   446,   452,     0,     0,
     439,   441,   447,   440,   442,   448,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,   417,     0,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,   274,   371,     0,   370,   374,   373,   376,   378,
     386,     0,     0,   390,     0,     0,     0,     0,     0,     0,
       0,     0,   469,     0,    72,   474,   475,   477,     0,   479,
     290,   291,   481,     0,     0,     0,   486,     0,   488,     0,
       0,     0,    72,   494,   292,     0,    72,   276,    72,     0,
       0,     0,     0,   506,   380,   382,     0,     0,     0,     0,
       0,     0,     0,   511,   314,     0,     0,     0,     0,    72,
     524,     0,   526,     0,     0,   529,   531,   532,   533,   542,
       0,   544,     0,     0,   547,   549,   550,   551,   461,     0,
      73,     0,    86,    96,     0,    80,    20,     0,     0,   145,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   166,     0,     0,     0,     0,     0,     0,     0,     0,
     186,   188,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     134,     0,     0,     0,     0,     0,     0,     0,   154,   167,
     171,   189,   198,   255,   118,   116,   241,   207,   219,   208,
     220,   205,   217,   206,   218,   204,   216,   203,   215,   227,
     248,   249,   237,   239,   238,   240,   253,   235,   236,   243,
     242,   199,   201,     0,   383,     0,   384,     0,   391,   392,
     393,   394,     0,   396,   397,     0,     0,     0,     0,   411,
     410,     0,     0,   480,    24,    25,   482,     0,     0,   487,
     489,     0,     0,     0,   495,   108,   115,     0,   502,   503,
     504,   505,   385,     0,     0,     0,     0,     0,     0,     0,
       0,   323,     0,     0,   256,   332,     0,     0,     0,     0,
       0,   528,     0,     0,   546,   462,    81,     0,    75,    72,
      72,   102,   200,   132,   202,   133,   244,   148,   213,   142,
     214,   143,   211,   138,   212,   139,   140,   210,   137,   209,
     136,   250,   152,   251,   153,   231,   192,   233,   194,   232,
     193,   234,   195,   252,   197,   229,   190,   230,   191,   246,
     150,   245,   149,     0,     0,     0,   225,   161,   226,   162,
     223,   158,   224,   159,   160,   222,   157,   221,   156,   228,
     169,   183,   184,   179,   180,   181,   178,   177,   175,   176,
     515,   275,   387,   395,   389,   388,   398,     0,   335,     0,
       0,     0,     0,    51,   484,   483,   485,   490,     0,    30,
       0,   499,   498,   500,   501,   284,     0,     0,   282,   510,
       0,   509,   326,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,   525,   527,   543,   545,    72,    72,    91,
       0,     0,    72,   196,   517,   297,     0,   401,     0,     0,
       0,     0,     0,    46,     0,   492,     0,     0,     0,     0,
     280,     0,     0,   283,     0,     0,     0,   324,     0,     0,
       0,   333,     0,     0,     0,   463,    82,    72,    87,    97,
       0,   297,   516,     0,   400,   336,     0,     0,   402,   404,
     406,   408,    55,    63,   491,    31,   109,   287,   285,     0,
     281,   327,     0,     0,     0,     0,   329,     0,     0,     0,
       0,    37,     0,     0,    92,     0,     0,   103,   518,   399,
       0,     0,   297,   297,   297,   297,    47,     0,    52,     0,
      72,    72,     0,     0,     0,     0,     0,   307,     0,     0,
     298,   325,     0,     0,     0,   316,     0,     0,   302,   334,
      72,   464,    83,     0,    88,    98,    72,   318,     0,     0,
     304,   337,   403,   405,   407,   409,     0,    60,    57,    56,
       0,    69,    65,    64,    32,     0,   288,   286,   289,   309,
       0,     0,   300,   328,     0,   295,     0,   330,   257,     0,
       0,   519,     0,    38,    72,    72,    93,    72,    72,     0,
       0,   520,     0,    58,     0,    48,    66,     0,    53,     0,
     110,     0,   319,     0,     0,   297,     0,     0,     0,     0,
       0,     0,   465,    84,    72,    89,    99,   104,     0,     0,
       0,    61,    49,     0,    70,     0,    33,    72,     0,     0,
       0,   306,   296,     0,   258,   331,   315,     0,    39,    94,
       0,     0,    72,   317,     0,    72,    72,     0,    67,    72,
      54,    42,     0,   310,     8,   320,     0,     0,     0,     0,
      42,    90,   100,   105,     0,    59,    62,    50,    72,    71,
      43,    34,   111,     0,   308,   311,     0,   297,     0,   299,
       0,   269,   259,   263,   264,   265,   303,    40,     0,   305,
      68,    72,     0,    72,     0,   322,   321,   310,     0,   260,
       0,     0,    72,     0,    45,    35,   112,     0,   301,   267,
       0,     0,   266,    41,   106,    44,     0,   312,   261,     0,
     113,   297,   268,   262
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -743,  -743,  -743,  -743,   957,  -743,    -9,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,    13,  -743,   -30,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,   161,  -743,  -743,
    -743,  -743,  -743,   160,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -287,   -46,
     936,    42,    -3,   174,    75,   537,  -743,  -743,   940,   941,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
     -12,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -742,  -743,  -743,  -743,  -743,  -743,
    -743,   -10,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,   296,     7,   144,   145,   146,   147,
     148,   149,   150,   737,   810,   889,   941,   982,   151,   754,
     830,   901,   950,   991,   961,   981,   995,   152,   772,   847,
     912,   937,   734,   851,   915,   806,   807,   848,   910,   885,
     936,   808,   809,   852,   913,   958,   888,   939,   153,   154,
     411,   415,   410,   718,   793,   875,   155,   156,   599,   795,
     877,   930,   598,   757,   833,   904,   157,   158,   600,   796,
     878,   931,   159,   160,   722,   836,   932,   978,   161,   366,
     690,   811,   917,   983,  1006,   162,   368,   163,   297,   164,
     165,   166,   167,   168,   169,   170,   171,   723,   172,   173,
     174,   708,   897,   948,   989,  1000,  1011,   972,   973,   974,
     975,   175,   176,   177,   178,   179,   180,   739,   813,   778,
     181,   182,   183,   895,   762,   819,   861,   827,   839,   820,
     862,   964,   965,   385,   828,   840,   184,   919,   967,   945,
     583,   704,   788,   587,   680,   185,   186,   187,   188,   189,
     190,   802,   803,   804,   805,   191,   192,   193,   595,   717,
     792,   874,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   725,   219,   761,
     220,   340,   221,   222
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     223,   325,   327,   328,   329,   390,   392,   232,   235,   504,
     250,   399,   253,   254,   255,   256,   257,   261,   266,   798,
     401,   270,   272,   274,   276,   408,   281,   284,   408,   278,
     706,  -117,   290,   408,     8,   449,   487,   581,     9,   707,
     298,   353,   643,   644,   374,   375,   245,   246,   330,   582,
     227,   500,   500,   488,   243,   245,   246,   247,    38,   227,
     842,   843,   844,   845,     9,   349,   247,   333,   602,   645,
     322,   280,   283,   248,   334,   331,    40,   289,   585,    39,
     224,   225,   248,   240,   286,   228,   758,   335,    39,   354,
     586,   229,   299,   245,   246,   342,   268,   227,   224,   225,
      41,   240,   286,   228,   247,   678,    44,    35,   332,   229,
     292,    37,    38,    39,    40,    41,  1005,   679,   341,   300,
     248,    44,   287,   343,   759,    35,    39,   336,   337,    37,
      38,    39,    40,    41,   338,   673,   643,   644,   345,    44,
     287,   643,   644,   674,   339,   702,   391,   393,   278,   577,
     786,   578,   400,   922,   344,   224,   225,   703,   240,   286,
     228,   402,   787,   645,   817,   727,   229,   346,   645,   825,
      40,   797,   488,   408,   735,    40,   818,    38,   646,   457,
     458,   826,    35,   648,   233,   236,    37,    38,    39,    40,
      41,   347,   459,   460,   350,   267,    44,   287,   271,   273,
     275,   277,   837,   282,   285,   299,   245,   246,   351,   291,
     227,   356,   105,    41,   838,   352,   970,   247,   357,    44,
     659,   232,   235,   355,   250,   986,   261,   464,   859,   362,
     105,   643,   644,   248,  1001,   471,   472,   473,   474,    39,
     860,   710,   232,   235,   261,   464,   475,   476,   238,   239,
     711,   240,   358,   228,   683,   232,   235,   464,   645,   241,
     232,   235,   464,   363,   408,    40,   464,   689,   890,  1013,
     408,   359,   360,   650,   365,   242,   464,   408,   361,   348,
      38,   712,   243,   250,   483,   473,   474,   105,   417,   418,
     231,   408,   490,   364,   475,   476,   367,   551,   506,   507,
     509,   511,   513,   515,   517,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   417,   418,   245,   246,
     243,   483,   227,   258,   259,   278,   226,   227,   228,   247,
     539,   369,   543,   730,   229,   552,   370,   745,   550,   823,
     486,   376,   731,   865,   371,   248,   746,   372,   824,   488,
     260,    39,   866,   563,    38,   373,    39,   565,   871,   566,
     378,   531,   532,   881,   604,   231,   568,   872,   567,   643,
     644,   377,   882,   379,   486,   538,   484,   485,   419,   420,
     588,   380,   519,   466,   467,   468,   469,   470,   426,   471,
     472,   473,   474,   892,   383,   907,   645,   408,   233,   236,
     475,   476,   893,    40,   465,   484,   485,   381,   541,   490,
     962,   652,   408,   386,   643,   644,   475,   476,   607,   609,
     611,   613,   615,   616,   618,   620,   622,   624,   626,   628,
     630,   632,   634,   636,   638,   640,   642,   233,   236,   465,
     382,   645,   384,   465,   388,   569,   387,   571,    40,   481,
     482,   459,   460,   465,   394,   389,   655,   643,   644,   603,
     605,   395,   408,   607,   609,   611,   613,   615,   618,   620,
     622,   624,   640,   642,   396,   397,   508,   510,   512,   514,
     516,   518,   398,   403,   645,   404,   405,   671,   406,   407,
     409,    40,   412,   413,   416,   414,   449,   743,   461,   657,
     462,   463,   245,   246,   487,   489,   227,   540,   502,   419,
     420,   503,   505,   247,   466,   467,   468,   469,   470,   426,
     471,   472,   473,   474,   660,   533,   603,   605,   534,   248,
     483,   475,   476,   535,   464,    39,   536,   545,   542,   675,
     544,   546,   547,   548,   249,   681,   553,   234,   237,   244,
     554,   252,   555,   559,   684,   560,   686,   262,   556,   557,
     558,   561,   660,   562,   692,   564,   224,   225,   572,   240,
     286,   228,   293,   570,   573,   700,   574,   229,   575,   483,
     576,   579,   580,   584,   238,   239,   589,   226,   590,   228,
     720,   721,   591,    35,   592,   241,   593,    37,    38,    39,
      40,    41,   594,   596,   597,   601,   670,    44,   287,   691,
     672,   251,   486,   625,   627,   629,   647,   649,   651,   653,
     654,   656,   658,   631,   419,   420,   231,   633,   764,   466,
     467,   468,   469,   470,   426,   471,   472,   473,   474,   635,
     637,   323,   694,   676,   682,   677,   475,   476,   685,   687,
     688,   647,   649,   651,   653,   656,   658,   966,   695,   696,
     224,   225,   697,   240,   286,   228,   698,   699,   713,   701,
     719,   229,   224,   225,   728,   226,   227,   228,   705,   709,
     714,   485,   460,   229,   715,   736,   324,    35,   724,   716,
     729,    37,    38,    39,    40,    41,   733,   726,   105,   230,
     738,    44,   287,   740,   741,    39,    40,   742,   755,   756,
     744,   465,   747,   760,   231,   748,   750,   245,   246,   749,
     751,   227,   752,   763,   765,   753,   766,   773,   247,   769,
     767,   776,   775,   779,   777,   326,   780,   782,   781,   783,
     784,   693,   785,   774,   248,   789,   790,   791,   794,   800,
      39,   801,   812,   245,   246,   815,   821,   227,   814,   549,
     816,   234,   237,   244,   247,   252,   262,   293,   822,   829,
     831,   832,   834,   835,   768,   234,   237,   244,   262,   293,
     248,   857,   841,   245,   246,   846,    39,   227,   293,   856,
     858,   850,   105,   869,   247,   234,   237,   293,   863,   864,
     883,   854,   855,   868,   886,   870,   867,   771,   876,   880,
     248,   245,   246,   884,   891,   227,    39,   233,   236,   465,
     894,   873,   247,   419,   420,   606,   887,   879,   466,   467,
     468,   469,   470,   426,   471,   472,   473,   474,   248,   896,
     898,   899,   900,   908,    39,   475,   476,   245,   246,   909,
     916,   227,   911,   608,   914,   918,   924,   920,   247,   245,
     246,   923,   921,   227,   927,   902,   903,   925,   905,   906,
     247,   245,   246,   928,   248,   227,   926,   933,   934,   935,
      39,   938,   247,   245,   246,   940,   248,   227,   943,   610,
     944,   946,    39,   947,   247,   929,   949,   951,   248,   954,
     952,   612,   971,   957,    39,   960,   770,   963,   942,   968,
     248,   990,   969,   614,   976,   979,    39,   984,   245,   246,
     245,   246,   227,   953,   227,   617,   955,   956,   985,   247,
     959,   247,   263,   264,   987,   988,   227,   245,   246,   992,
     997,   227,   799,   247,   971,   248,  1007,   248,   247,   980,
     999,    39,   994,    39,  1008,  1009,  1010,  1012,     6,   265,
     619,  1003,   621,   977,   248,    39,    40,    41,   849,   853,
      39,   288,   993,    44,   996,   294,   295,   998,  1002,   623,
       0,     0,     0,  1004,     0,     0,     0,     0,     0,   661,
     662,   663,   664,   665,   666,   667,   668,   669,     2,     3,
       0,    -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,     0,    -8,     0,
      -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,     0,     0,
       0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,     0,    -8,    -8,     0,    -8,     0,    -8,    -8,    -8,
      -8,     0,    -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,    -8,    -8,     0,     0,     0,     0,     0,     0,
      -8,    -8,    -8,    -8,    -8,     0,     0,     0,     0,     0,
      -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,     0,    -8,     0,     0,    -8,     0,
       0,    -8,     0,    -8,     0,    -8,     0,     0,     0,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,     0,     0,     0,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -4,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,    35,     0,    36,     0,    37,    38,
      39,    40,    41,    42,     0,     0,     0,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,    53,    54,
       0,    55,     0,    56,    57,    58,    59,     0,    60,    61,
      62,    63,    64,     0,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,    76,    77,     0,    78,
      79,     0,   -85,    80,  -101,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,    96,     0,     0,    97,     0,     0,    98,     0,    99,
       0,   100,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,     0,     0,     0,   108,   -95,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   245,   246,   245,   246,   227,     0,   227,     0,
       0,     0,     0,   247,     0,   247,   245,   246,     0,     0,
     227,   245,   246,     0,     0,   227,     0,   247,     0,   248,
       0,   248,   247,     0,     0,    39,     0,    39,     0,     0,
       0,   245,   246,   248,   625,   227,   627,     0,   248,    39,
       0,     0,   247,     0,    39,   245,   246,     0,   629,   227,
     245,   246,     0,   631,   227,     0,   247,     0,   248,     0,
       0,   247,     0,     0,    39,     0,     0,     0,     0,     0,
     245,   246,   248,   633,   227,   245,   246,   248,    39,   227,
       0,   247,     0,    39,     0,     0,   247,   635,     0,     0,
       0,     0,   637,     0,     0,   263,   264,   248,   278,   227,
       0,     0,   248,    39,     0,     0,   247,     0,    39,     0,
       0,     0,   639,     0,     0,     0,     0,   641,     0,     0,
       0,     0,   537,     0,     0,     0,     0,    38,    39,    40,
      41,     0,   419,   420,     0,     0,    44,   466,   467,   468,
     469,   470,   426,   471,   472,   473,   474,     0,     0,     0,
     440,   441,     0,     0,   475,   476,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,   301,   302,   303,   304,
     305,   732,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   263,   264,     0,
     278,   227,     0,     0,     0,   263,   264,     0,   247,   227,
     321,   440,   441,     0,     0,     0,   247,   477,   478,   479,
     480,   446,   481,   482,   279,     0,     0,     0,     0,    38,
      39,    40,   269,     0,     0,   419,   420,     0,    39,    40,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     491,   492,   493,   494,   495,   496,   497,   438,   439,   419,
     420,     0,     0,   498,   466,   467,   468,   469,   470,   426,
     471,   472,   473,   474,   477,   478,   479,   480,   446,   481,
     482,   475,   476,   450,   451,     0,     0,   498,     0,   452,
     453,   454,   455,   456,   457,   458,   466,   467,   468,   469,
     470,   426,   471,   472,   473,   474,     0,   459,   460,   440,
     441,   501,     0,   475,   476,   442,   443,   444,   445,   446,
     447,   448,   440,   441,     0,     0,     0,     0,   477,   478,
     479,   480,   446,   481,   482,   450,   451,   499,     0,     0,
       0,   452,   453,   454,   455,   456,   457,   458,     0,     0,
     499,     0,     0,     0,     0,     0,   419,   420,     0,   459,
     460,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     419,   420,     0,     0,     0,   466,   467,   468,   469,   470,
     426,   471,   472,   473,   474,     0,     0,     0,     0,     0,
       0,     0,   475,   476,   301,   302,   303,   304,   305,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   452,   453,   454,   455,   456,
     457,   458,   467,   468,   469,   470,   426,   471,   472,   473,
     474,     0,     0,   459,   460,     0,     0,     0,   475,   476
};

static const yytype_int16 yycheck[] =
{
       9,    47,    48,    49,    50,    38,    38,    10,    11,   296,
      13,    38,    15,    16,    17,    18,    19,    20,    21,   761,
      38,    24,    25,    26,    27,    41,    29,    30,    41,     6,
      31,    33,    35,    41,   178,    15,    15,    34,    40,    40,
      43,    76,     3,     4,    90,    91,     3,     4,    51,    46,
       7,    31,    31,    30,    12,     3,     4,    14,    35,     7,
     802,   803,   804,   805,    40,    68,    14,    56,    45,    30,
      45,    29,    30,    30,    63,    38,    37,    35,    34,    36,
       3,     4,    30,     6,     7,     8,    94,    76,    36,   124,
      46,    14,    30,     3,     4,    63,    21,     7,     3,     4,
      38,     6,     7,     8,    14,    34,    44,    30,    53,    14,
      35,    34,    35,    36,    37,    38,   129,    46,    58,    44,
      30,    44,    45,    30,   140,    30,    36,   116,   117,    34,
      35,    36,    37,    38,   123,    45,     3,     4,    63,    44,
      45,     3,     4,    53,   133,    34,   179,   179,     6,   119,
      34,   121,   179,   895,    30,     3,     4,    46,     6,     7,
       8,   179,    46,    30,    34,   122,    14,    69,    30,    34,
      37,    39,    30,    41,   122,    37,    46,    35,    45,    14,
      15,    46,    30,    45,    10,    11,    34,    35,    36,    37,
      38,    63,    27,    28,    45,    21,    44,    45,    24,    25,
      26,    27,    34,    29,    30,    30,     3,     4,    45,    35,
       7,    56,   135,    38,    46,    76,   139,    14,    63,    44,
      45,   224,   225,    76,   227,   967,   229,   230,    34,    30,
     135,     3,     4,    30,   139,    14,    15,    16,    17,    36,
      46,    31,   245,   246,   247,   248,    25,    26,     3,     4,
      40,     6,    97,     8,    31,   258,   259,   260,    30,    14,
     263,   264,   265,    45,    41,    37,   269,    31,    39,  1011,
      41,   116,   117,    45,    77,    30,   279,    41,   123,    76,
      35,    31,   240,   286,   242,    16,    17,   135,    27,    28,
      45,    41,    31,    45,    25,    26,    45,   343,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,    27,    28,     3,     4,
     278,   279,     7,     3,     4,     6,     6,     7,     8,    14,
     333,    78,   335,    31,    14,   344,    79,    31,   341,    31,
     265,    53,    40,    31,    80,    30,    40,    80,    40,    30,
      30,    36,    40,   362,    35,    80,    36,   366,    31,   368,
      38,   319,   320,    31,    45,    45,   369,    40,    53,     3,
       4,    45,    40,   118,   299,   333,    27,    28,     3,     4,
     389,   118,   307,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    31,    63,    39,    30,    41,   224,   225,
      25,    26,    40,    37,   230,    27,    28,    38,   333,    31,
      39,    45,    41,    30,     3,     4,    25,    26,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   263,   264,   265,
      38,    30,   138,   269,    30,   370,    42,   372,    37,    14,
      15,    27,    28,   279,    38,    30,    45,     3,     4,   417,
     418,    38,    41,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,    38,    38,   302,   303,   304,   305,
     306,   307,    38,    38,    30,    38,    38,   533,    38,    38,
      94,    37,    98,   142,    39,   100,    15,   122,    39,    45,
      39,    45,     3,     4,    15,    31,     7,   333,    31,     3,
       4,    31,    33,    14,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,   449,    29,   484,   485,    38,    30,
     488,    25,    26,    38,   537,    36,    45,   118,    56,   542,
      38,    38,    30,    56,    45,   548,    45,    10,    11,    12,
      42,    14,    42,    56,   557,    38,   559,    20,    45,    76,
      45,   118,   487,    38,   567,    45,     3,     4,    45,     6,
       7,     8,    35,    81,    29,   578,    38,    14,    38,   537,
      38,    38,    30,    36,     3,     4,    38,     6,    38,     8,
     599,   600,    38,    30,    38,    14,    38,    34,    35,    36,
      37,    38,    38,    30,   140,    30,    53,    44,    45,   567,
     535,    30,   537,    45,    45,    45,   442,   443,   444,   445,
     446,   447,   448,    45,     3,     4,    45,    45,   122,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    45,
      45,    78,   567,    38,    31,   121,    25,    26,    45,    38,
     121,   477,   478,   479,   480,   481,   482,   944,    32,    29,
       3,     4,    29,     6,     7,     8,    38,   126,   180,    38,
      30,    14,     3,     4,   677,     6,     7,     8,    42,    42,
     180,    28,    28,    14,   180,   688,   123,    30,    53,   180,
      42,    34,    35,    36,    37,    38,    32,   121,   135,    30,
     100,    44,    45,    38,    38,    36,    37,    29,   717,   718,
      42,   537,    53,   722,    45,    45,    30,     3,     4,    46,
      53,     7,    45,   726,    53,    46,    45,    32,    14,   732,
      46,    30,   128,   119,    38,    78,    38,    45,    53,    46,
      30,   567,    42,   122,    30,    30,    42,   128,   757,    30,
      36,    42,    40,     3,     4,    30,    53,     7,   119,    45,
      42,   224,   225,   226,    14,   228,   229,   230,    42,    53,
      42,    31,    30,    30,   732,   238,   239,   240,   241,   242,
      30,    33,    53,     3,     4,    88,    36,     7,   251,    38,
      38,    89,   135,    46,    14,   258,   259,   260,    53,    45,
     846,   810,   811,    45,   850,    45,    53,   732,    31,    45,
      30,     3,     4,    90,    45,     7,    36,   643,   644,   645,
      42,   830,    14,     3,     4,    45,    91,   836,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    30,    46,
      42,    42,    46,    42,    36,    25,    26,     3,     4,    46,
     129,     7,    42,    45,    42,    42,    30,    46,    14,     3,
       4,    45,    53,     7,    45,   874,   875,    53,   877,   878,
      14,     3,     4,   129,    30,     7,    53,    53,    45,    42,
      36,    42,    14,     3,     4,    33,    30,     7,    53,    45,
      32,    45,    36,    42,    14,   904,    42,    31,    30,    42,
      31,    45,   948,    33,    36,    87,   732,    29,   917,    42,
      30,    40,    53,    45,    53,    53,    36,   963,     3,     4,
       3,     4,     7,   932,     7,    45,   935,   936,    33,    14,
     939,    14,     3,     4,    53,    42,     7,     3,     4,    31,
      42,     7,   122,    14,   990,    30,    36,    30,    14,   958,
      53,    36,   130,    36,    31,    42,    31,    53,     1,    30,
      45,   991,    45,   950,    30,    36,    37,    38,   807,   809,
      36,    35,   981,    44,   983,    35,    35,   987,   990,    45,
      -1,    -1,    -1,   992,    -1,    -1,    -1,    -1,    -1,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      32,    -1,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    57,    -1,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,    -1,    -1,   120,    -1,
      -1,   123,    -1,   125,    -1,   127,    -1,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    32,    -1,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,    57,    -1,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,    -1,    -1,   120,    -1,    -1,   123,    -1,   125,
      -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     3,     4,     3,     4,     7,    -1,     7,    -1,
      -1,    -1,    -1,    14,    -1,    14,     3,     4,    -1,    -1,
       7,     3,     4,    -1,    -1,     7,    -1,    14,    -1,    30,
      -1,    30,    14,    -1,    -1,    36,    -1,    36,    -1,    -1,
      -1,     3,     4,    30,    45,     7,    45,    -1,    30,    36,
      -1,    -1,    14,    -1,    36,     3,     4,    -1,    45,     7,
       3,     4,    -1,    45,     7,    -1,    14,    -1,    30,    -1,
      -1,    14,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
       3,     4,    30,    45,     7,     3,     4,    30,    36,     7,
      -1,    14,    -1,    36,    -1,    -1,    14,    45,    -1,    -1,
      -1,    -1,    45,    -1,    -1,     3,     4,    30,     6,     7,
      -1,    -1,    30,    36,    -1,    -1,    14,    -1,    36,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    -1,     3,     4,    -1,    -1,    44,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
       3,     4,    -1,    -1,    25,    26,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    42,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     3,     4,    -1,
       6,     7,    -1,    -1,    -1,     3,     4,    -1,    14,     7,
      42,     3,     4,    -1,    -1,    -1,    14,     9,    10,    11,
      12,    13,    14,    15,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    30,    -1,    -1,     3,     4,    -1,    36,    37,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     3,
       4,    -1,    -1,    31,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     9,    10,    11,    12,    13,    14,
      15,    25,    26,     3,     4,    -1,    -1,    31,    -1,     9,
      10,    11,    12,    13,    14,    15,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    27,    28,     3,
       4,    31,    -1,    25,    26,     9,    10,    11,    12,    13,
      14,    15,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,     3,     4,    31,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    27,
      28,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       3,     4,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     9,    10,    11,    12,    13,
      14,    15,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    27,    28,    -1,    -1,    -1,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   182,     0,     1,   183,   184,   185,   186,   178,    40,
       3,     4,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    30,    32,    34,    35,    36,
      37,    38,    39,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    54,    55,    57,    59,    60,    61,    62,
      64,    65,    66,    67,    68,    70,    71,    72,    73,    74,
      75,    82,    83,    84,    85,    86,    92,    93,    95,    96,
      99,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   117,   120,   123,   125,
     127,   131,   132,   133,   134,   135,   136,   137,   141,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   187,   188,   189,   190,   191,   192,
     193,   199,   208,   229,   230,   237,   238,   247,   248,   253,
     254,   259,   266,   268,   270,   271,   272,   273,   274,   275,
     276,   277,   279,   280,   281,   292,   293,   294,   295,   296,
     297,   301,   302,   303,   317,   326,   327,   328,   329,   330,
     331,   336,   337,   338,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   369,
     371,   373,   374,   187,     3,     4,     6,     7,     8,    14,
      30,    45,   273,   274,   276,   273,   274,   276,     3,     4,
       6,    14,    30,   272,   276,     3,     4,    14,    30,    45,
     273,    30,   276,   273,   273,   273,   273,   273,     3,     4,
      30,   273,   276,     3,     4,    30,   273,   274,   275,    30,
     273,   274,   273,   274,   273,   274,   273,   274,     6,    30,
     272,   273,   274,   272,   273,   274,     7,    45,   271,   272,
     273,   274,   275,   276,   279,   280,   185,   269,   273,    30,
     275,     8,     9,    10,    11,    12,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    42,    45,    78,   123,   270,    78,   270,   270,   270,
     273,    38,    53,    56,    63,    76,   116,   117,   123,   133,
     372,    58,    63,    30,    30,   275,    69,    63,    76,   273,
      45,    45,    76,    76,   124,    76,    56,    63,    97,   116,
     117,   123,    30,    45,    45,    77,   260,    45,   267,    78,
      79,    80,    80,    80,   270,   270,    53,    45,    38,   118,
     118,    38,    38,    63,   138,   314,    30,    42,    30,    30,
      38,   179,    38,   179,    38,    38,    38,    38,    38,    38,
     179,    38,   179,    38,    38,    38,    38,    38,    41,    94,
     233,   231,    98,   142,   100,   232,    39,    27,    28,     3,
       4,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       3,     4,     9,    10,    11,    12,    13,    14,    15,    15,
       3,     4,     9,    10,    11,    12,    13,    14,    15,    27,
      28,    39,    39,    45,   273,   274,     8,     9,    10,    11,
      12,    14,    15,    16,    17,    25,    26,     9,    10,    11,
      12,    14,    15,   272,    27,    28,   275,    15,    30,    31,
      31,    18,    19,    20,    21,    22,    23,    24,    31,    31,
      31,    31,    31,    31,   269,    33,   273,   273,   274,   273,
     274,   273,   274,   273,   274,   273,   274,   273,   274,   275,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   272,   272,    29,    38,    38,    45,    30,   272,   273,
     274,   275,    56,   273,    38,   118,    38,    30,    56,    45,
     273,   270,   187,    45,    42,    42,    45,    76,    45,    56,
      38,   118,    38,   187,    45,   187,   187,    53,   273,   275,
      81,   275,    45,    29,    38,    38,    38,   119,   121,    38,
      30,    34,    46,   321,    36,    34,    46,   324,   187,    38,
      38,    38,    38,    38,    38,   339,    30,   140,   243,   239,
     249,    30,    45,   272,    45,   272,    45,   273,    45,   273,
      45,   273,    45,   273,    45,   273,   273,    45,   273,    45,
     273,    45,   273,    45,   273,    45,   273,    45,   273,    45,
     273,    45,   273,    45,   273,    45,   273,    45,   273,    45,
     273,    45,   273,     3,     4,    30,    45,   274,    45,   274,
      45,   274,    45,   274,   274,    45,   274,    45,   274,    45,
     275,   276,   276,   276,   276,   276,   276,   276,   276,   276,
      53,   270,   275,    45,    53,   273,    38,   121,    34,    46,
     325,   273,    31,    31,   273,    45,   273,    38,   121,    31,
     261,   272,   273,   274,   275,    32,    29,    29,    38,   126,
     273,    38,    34,    46,   322,    42,    31,    40,   282,    42,
      31,    40,    31,   180,   180,   180,   180,   340,   234,    30,
     187,   187,   255,   278,    53,   368,   121,   122,   273,    42,
      31,    40,    42,    32,   213,   122,   273,   194,   100,   298,
      38,    38,    29,   122,    42,    31,    40,    53,    45,    46,
      30,    53,    45,    46,   200,   187,   187,   244,    94,   140,
     187,   370,   305,   273,   122,    53,    45,    46,   272,   273,
     274,   275,   209,    32,   122,   128,    30,    38,   300,   119,
      38,    53,    45,    46,    30,    42,    34,    46,   323,    30,
      42,   128,   341,   235,   187,   240,   250,    39,   305,   122,
      30,    42,   332,   333,   334,   335,   216,   217,   222,   223,
     195,   262,    40,   299,   119,    30,    42,    34,    46,   306,
     310,    53,    42,    31,    40,    34,    46,   308,   315,    53,
     201,    42,    31,   245,    30,    30,   256,    34,    46,   309,
     316,    53,   305,   305,   305,   305,    88,   210,   218,   218,
      89,   214,   224,   224,   187,   187,    38,    33,    38,    34,
      46,   307,   311,    53,    45,    31,    40,    53,    45,    46,
      45,    31,    40,   187,   342,   236,    31,   241,   251,   187,
      45,    31,    40,   270,    90,   220,   270,    91,   227,   196,
      39,    45,    31,    40,    42,   304,    46,   283,    42,    42,
      46,   202,   187,   187,   246,   187,   187,    39,    42,    46,
     219,    42,   211,   225,    42,   215,   129,   263,    42,   318,
      46,    53,   305,    45,    30,    53,    53,    45,   129,   187,
     242,   252,   257,    53,    45,    42,   221,   212,    42,   228,
      33,   197,   187,    53,    32,   320,    45,    42,   284,    42,
     203,    31,    31,   187,    42,   187,   187,    33,   226,   187,
      87,   205,    39,    29,   312,   313,   269,   319,    42,    53,
     139,   270,   288,   289,   290,   291,    53,   205,   258,    53,
     187,   206,   198,   264,   270,    33,   305,    53,    42,   285,
      40,   204,    31,   187,   130,   207,   187,    42,   312,    53,
     286,   139,   291,   207,   187,   129,   265,    36,    31,    42,
      31,   287,    53,   305
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   181,   182,   182,   184,   183,   183,   183,   186,   185,
     185,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     188,   189,   190,   191,   191,   191,   192,   192,   192,   192,
     194,   195,   196,   197,   198,   193,   200,   201,   202,   203,
     204,   199,   205,   206,   205,   207,   209,   210,   211,   212,
     208,   213,   214,   215,   208,   217,   216,   216,   219,   218,
     220,   221,   220,   223,   222,   222,   225,   226,   224,   227,
     228,   227,   230,   229,   231,   229,   229,   229,   229,   232,
     229,   234,   235,   236,   233,   238,   239,   240,   241,   242,
     237,   244,   245,   246,   243,   248,   249,   250,   251,   252,
     247,   254,   255,   256,   257,   258,   253,   260,   261,   262,
     263,   264,   265,   259,   267,   266,   268,   269,   269,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   271,   271,
     272,   272,   272,   272,   272,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   275,   275,
     275,   275,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     277,   277,   277,   277,   277,   278,   277,   277,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   280,   280,   282,   283,   284,   285,
     286,   287,   281,   288,   289,   290,   290,   290,   290,   291,
     292,   292,   292,   292,   293,   293,   293,   293,   293,   293,
     294,   295,   295,   296,   298,   299,   297,   300,   300,   301,
     302,   302,   302,   302,   302,   304,   303,   305,   306,   306,
     307,   307,   308,   308,   309,   309,   310,   310,   311,   311,
     312,   312,   313,   314,   314,   315,   315,   316,   316,   318,
     319,   317,   320,   321,   321,   321,   322,   322,   322,   323,
     323,   323,   324,   324,   324,   325,   325,   325,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   328,   328,   329,   330,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   332,   331,   333,   331,   334,   331,   335,   331,
     336,   336,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   339,   340,   341,   342,   338,   343,   344,   344,   345,
     346,   346,   346,   346,   347,   348,   349,   350,   351,   351,
     351,   352,   352,   352,   352,   353,   353,   353,   353,   353,
     353,   353,   353,   354,   354,   355,   356,   357,   358,   358,
     358,   358,   358,   359,   360,   360,   360,   360,   361,   362,
     363,   364,   365,   366,   366,   368,   367,   370,   369,   371,
     372,   373,   373,   373,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374
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
       1,     1,     1,     1,     2,     4,     2,     1,     1,     1,
       5,     6,     4,     5,     0,     0,     8,     1,     3,     8,
       2,     2,     2,     1,     1,     0,    10,     0,     1,     6,
       1,     7,     1,     6,     1,     6,     4,     1,     5,     1,
       0,     1,     4,     0,     1,     4,     1,     4,     1,     0,
       0,    13,     3,     1,     3,     5,     1,     3,     5,     1,
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
       1,     0,     0,     0,     0,     9,     1,     1,     1,     2,
       1,     1,     1,     1,     2,     2,     1,     2,     1,     2,
       3,     2,     3,     4,     4,     4,     2,     3,     2,     3,
       4,     6,     5,     1,     2,     3,     1,     1,     4,     4,
       4,     4,     3,     3,     3,     3,     2,     1,     1,     4,
       4,     2,     1,     1,     1,     0,     5,     0,     6,     8,
       8,     1,     1,     1,     2,     4,     2,     4,     3,     2,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     2,     4,     3,     2,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 986 "pnfha.ypp" /* yacc.c:1646  */
    { ASTNode start("START"); tree.add_node(start); }
#line 3096 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 989 "pnfha.ypp" /* yacc.c:1646  */
    {
	 ASTNode line("line");
         tree.add_node(line);
	}
#line 3105 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 995 "pnfha.ypp" /* yacc.c:1646  */
    { yyerrok; }
#line 3111 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 998 "pnfha.ypp" /* yacc.c:1646  */
    {
		 ASTNode statement("statement");
  		 tree.add_node(statement);
		}
#line 3120 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 1006 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1; 
		    	                    statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3127 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 1008 "pnfha.ypp" /* yacc.c:1646  */
    { conprint("VOID TVOID 0V\n"); statementoutcount.insert(); 
                         statementoutcount[statementoutcount.length() - 1] = outcount - 1; statementlineno.insert(); statementlineno[statementlineno.length() - 1]                          = yylineno; }
#line 3134 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 1010 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					  statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3141 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 1012 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					   statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3148 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 1014 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3155 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 1016 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				       statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3162 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 1018 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; inblock = true;
				   }
#line 3170 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 1026 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode expression_statement("expression_statement");
			 tree.add_node(expression_statement);
			}
#line 3179 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 1033 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration_statement("declaration_statement");
			 tree.add_node(declaration_statement);
			}
#line 3188 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 1040 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command_statement("command_statement");
			 tree.add_node(command_statement);
			}
#line 3197 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 1047 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3234 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 1080 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode label_statement("label_statement");

			 conprint("LBL TVOID 0V\n");

			 tree.add_node(label_statement);
			}
#line 3246 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 1088 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode label_statement("label_statement");

			 conprint("ELBL TVOID 0V\n");

			 tree.add_node(label_statement);
			}
#line 3258 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 1098 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			}
#line 3268 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 1104 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			}
#line 3278 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 1110 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");
			 tree.add_node(control_statement);
			}
#line 3287 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 1115 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");

			 breakinforever = false;

			 tree.add_node(control_statement);
			}
#line 3299 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 1125 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp1("if_statementp1");

			 tree.add_node(if_statementp1);		
			}
#line 3309 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 1131 "pnfha.ypp" /* yacc.c:1646  */
    {			 
			 ASTNode if_statementp2("if_statementp2");
			
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			}
#line 3322 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 1140 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			}
#line 3333 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 1147 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			}
#line 3342 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 1152 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			}
#line 3352 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 1158 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			}
#line 3364 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 1168 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp1("if_statementp1");

			 conprint("NOT TVOID 0V\n");	

			 tree.add_node(if_statementp1);		
			}
#line 3376 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 1176 "pnfha.ypp" /* yacc.c:1646  */
    {			 
			 ASTNode if_statementp2("if_statementp2");
		
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			}
#line 3389 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 1185 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			}
#line 3400 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 1192 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			}
#line 3409 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 1197 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			}
#line 3419 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 1203 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			}
#line 3431 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 1213 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp5("if_statementp5");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 // Code for else will be inserted here if exists...
			 tree.add_node(if_statementp5);
			}
#line 3445 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 1224 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp7("if_statementp7");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");

			 tree.add_node(if_statementp7);
			}
#line 3458 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 1238 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3501 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 1277 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3534 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 1306 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp3("switch_statementp3");

			 tree.add_node(switch_statementp3);
			}
#line 3544 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 1311 "pnfha.ypp" /* yacc.c:1646  */
    {

			}
#line 3552 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 1315 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			}
#line 3564 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 1323 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3582 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 1338 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp2("switch_statementp2");
			 
			 tree.add_node(switch_statementp2);
			}
#line 3592 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 1344 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp3("switch_statementp3");
			 tree.add_node(switch_statementp3);
			}
#line 3601 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 1349 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			}
#line 3613 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 1358 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			}
#line 3622 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 1367 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3664 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1405 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 3672 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1411 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			}
#line 3681 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1416 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 3689 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1421 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			}
#line 3698 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1430 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3733 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1461 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statementp2("case_statementp2");

			 tree.add_node(case_statementp2);
			}
#line 3743 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1467 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statementp3("case_statementp3");

			 conprint("SWCEND TVOID 0V\n");

			 tree.add_node(case_statementp3);
			}
#line 3755 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1477 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			}
#line 3764 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1482 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 3772 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1487 "pnfha.ypp" /* yacc.c:1646  */
    {
			 loopexpr = true;
			 inloop2 = true;
			}
#line 3781 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1492 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3790 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1497 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3799 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1502 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3808 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1507 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3817 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1512 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3826 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1517 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3835 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1522 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 
			 loopexpr = false;
			 inloop = true;		 

			 tree.add_node(loop_statement);
			}
#line 3848 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1530 "pnfha.ypp" /* yacc.c:1646  */
    {
			 inloop2 = false;
			 inwhile = false;
			 indowhile = false;
			 infor2 = false;
			 indofor = false;
			 inforever = false;
			}
#line 3861 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1541 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp1("while_loopp1");

			 inwhile = true;
			 ++whilecounter;
			 conprint("LBL TSTRING \"while_test_%u\"\n", whilecounter);

			 tree.add_node(while_loopp1);
			}
#line 3875 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1551 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp2("while_loopp2");

			 tree.add_node(while_loopp2);
			}
#line 3885 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1557 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp3("while_loopp3");

			 conprint("CGOTOL TSTRING \"while_body_%u\"\n", whilecounter);
			 conprint("GOTOL TSTRING \"while_end_%u\"\n", whilecounter);

			 conprint("LBL TSTRING \"while_body_%u\"\n", whilecounter);

			 tree.add_node(while_loopp3);
			}
#line 3900 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1568 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp4("while_loopp4");

			 conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 conprint("LBL TSTRING \"while_end_%u\"\n", whilecounter);

			 tree.add_node(while_loopp4);
			}
#line 3913 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1578 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp1("do_while_loopp1");

			 indowhile = true;
			 ++dowhilecounter;
			 conprint("LBL TSTRING \"do_while_body_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp1);
			}
#line 3927 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1588 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp2("do_while_loopp2");

			 tree.add_node(do_while_loopp2);
			}
#line 3937 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1595 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp3("do_while_loopp3");

			 conprint("LBL TSTRING \"do_while_test_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp3);
			}
#line 3949 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1603 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp4("do_while_loopp4");

			 tree.add_node(do_while_loopp4);
			}
#line 3959 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1609 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp5("do_while_loopp5");

			 conprint("CGOTOL TSTRING \"do_while_body_%u\"\n", dowhilecounter);
			 conprint("GOTOL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp5);
			}
#line 3972 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1618 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp6("do_while_loopp6");

			 conprint("LBL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp6);
			}
#line 3984 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1628 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode until_loopp1("until_loopp1");

			 inuntil = true;
			 ++untilcounter;
			 conprint("LBL TSTRING \"until_test_%u\"\n", untilcounter);

			 tree.add_node(until_loopp1);
			}
#line 3998 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1638 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode until_loopp2("until_loopp2");

			 tree.add_node(until_loopp2);
			}
#line 4008 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1644 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode until_loopp3("until_loopp3");


			 conprint("NOT TVOID 0V\n");

			 conprint("CGOTOL TSTRING \"until_body_%u\"\n", untilcounter);
			 conprint("GOTOL TSTRING \"until_end_%u\"\n", untilcounter);

			 conprint("LBL TSTRING \"until_body_%u\"\n", untilcounter);

			 tree.add_node(until_loopp3);
			}
#line 4026 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1658 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode until_loopp4("until_loopp4");

			 conprint("GOTOL TSTRING \"until_test_%u\"\n", untilcounter);
			 conprint("LBL TSTRING \"until_end_%u\"\n", untilcounter);

			 tree.add_node(until_loopp4);
			}
#line 4039 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1668 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp1("do_until_loopp1");

			 indountil = true;
			 ++dountilcounter;
			 conprint("LBL TSTRING \"do_until_body_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp1);
			}
#line 4053 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1678 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp2("do_until_loopp2");

			 tree.add_node(do_until_loopp2);
			}
#line 4063 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1685 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp3("do_until_loopp3");

			 conprint("LBL TSTRING \"do_until_test_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp3);
			}
#line 4075 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1693 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp4("do_until_loopp4");

			 tree.add_node(do_until_loopp4);
			}
#line 4085 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1699 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp5("do_until_loopp5");

			 conprint("CGOTOL TSTRING \"do_until_body_%u\"\n", dountilcounter);
			 conprint("GOTOL TSTRING \"do_until_end_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp5);
			}
#line 4098 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1708 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_until_loopp6("do_until_loopp6");

			 conprint("NOT TVOID 0V\n");

			 conprint("LBL TSTRING \"do_until_end_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp6);
			}
#line 4112 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1719 "pnfha.ypp" /* yacc.c:1646  */
    {
			 infor = true;
			}
#line 4120 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1723 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp1("for_loopp1");

			 infor2 = true;
			 ++forcounter;
			 conprint("LBL TSTRING \"for_initialization_%u\"\n", forcounter);

			 tree.add_node(for_loopp1);
			}
#line 4134 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1733 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp2("for_loopp2");

			 conprint("LBL TSTRING \"for_condition_%u\"\n", forcounter);

			 tree.add_node(for_loopp2);
			}
#line 4146 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1741 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp3("for_loopp3");

			 conprint("CGOTOL TSTRING \"for_body_%u\"\n", forcounter);
			 conprint("GOTOL TSTRING \"for_end_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_increment_statement_%u\"\n", forcounter);

			 tree.add_node(for_loopp3);
			}
#line 4160 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1751 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp4("for_loopp4");

			 conprint("GOTOL TSTRING \"for_condition_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_body_%u\"\n", forcounter);

			 tree.add_node(for_loopp4);
			}
#line 4173 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1760 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp5("for_loopp5");

			 conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_end_%u\"\n", forcounter);

			 tree.add_node(for_loopp5);
			}
#line 4186 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1771 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp1("forb_loopp1");

			 indofor = true;
			 infor = true;
			 ++doforcounter;

			 conprint("GOTOL TSTRING \"dofor_initialization_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_body_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp1);
			}
#line 4203 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1784 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp2("forb_loopp2");

			 conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_initialization_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp2);
			}
#line 4216 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1793 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp3("forb_loopp3");

			 tree.add_node(forb_loopp3);
			}
#line 4226 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1799 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp4("forb_loopp4");

			 conprint("GOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_condition_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp4);
			}
#line 4239 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1808 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp5("forb_loopp5");

			 conprint("CGOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("GOTOL TSTRING \"dofor_end_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp5);
			}
#line 4253 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1818 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp6("forb_loopp6");
			 tree.add_node(forb_loopp6);
			}
#line 4262 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1823 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp7("forb_loopp7");

			 conprint("GOTOL TSTRING \"dofor_condition_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_end_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp7);
			}
#line 4275 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1834 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forever_loopp1("forever_loopp1");

			 breakinforever = true;
			 ++forevercounter;
			 conprint("LBL TSTRING \"forever_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp1);			
			}
#line 4289 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1844 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forever_loopp2("forever_loopp2");

			 conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);
			 conprint("LBL TSTRING \"forever_end_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp2);			
			}
#line 4302 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1853 "pnfha.ypp" /* yacc.c:1646  */
    { PNF_String str((yyvsp[-1]).to_string().get()); (yyval).put(str); ASTNode statement_block("statement_block"); 
                                                  tree.add_node(statement_block); }
#line 4309 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1858 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			}
#line 4318 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1863 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			}
#line 4327 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1869 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = TVOID; ASTNode expression("expression"); tree.add_node(expression); }
#line 4333 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1871 "pnfha.ypp" /* yacc.c:1646  */
    {
		 (yyval) = (yyvsp[0]);
		 savenumber = (yyval);
		 exptype = TBOOLEAN;
		 ASTNode expression("expression");
		 tree.add_node(expression);
		}
#line 4345 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1878 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); savenumber = (yyval); exptype = TNUMBER; ASTNode expression("expression");
                                      tree.add_node(expression); }
#line 4352 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1880 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); savenumber = (yyval); exptype = TCHARACTER; ASTNode expression("expression"); 
                                         tree.add_node(expression); }
#line 4359 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1882 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); savenumber = (PNF_String)strip_quotes((yyval).to_string().get()); exptype = TSTRING; ASTNode expression("expression"); 
                                      tree.add_node(expression); }
#line 4366 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1884 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
                                  tree.add_node(expression); }
#line 4373 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1886 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = TBOOLEAN; ASTNode expression("expression"); 
					  tree.add_node(expression); }
#line 4380 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1888 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
				     tree.add_node(expression); }
#line 4387 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1890 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); tree.add_node(expression); 		
		}
#line 4394 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1896 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_String s("0V");
			 (yyval).put(s);

			 exptruth = false;

			 ASTNode void_expression("void_expression");
			 tree.add_node(void_expression);
			}
#line 4408 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1905 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4414 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1909 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4434 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1925 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4452 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1939 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4472 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
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
			 b2.opor(b);
			 (yyval).put(b2);
			}
#line 4492 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1970 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4498 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1974 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4516 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1988 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().add(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4526 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1994 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().sub(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4536 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 2000 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().mul(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4546 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 2006 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().div(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4556 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 2012 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().mod(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4566 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 2018 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char * str = "-";
			 strcat(str, (yyvsp[0]).to_string().get().getString().c_str());
			 PNF_String s(str);
			 PNF_Variable v(s);
			 (yyval) = v;
			}
#line 4578 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 2026 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[0]).to_number().get();
			 PNF_Number n((yyvsp[-2]).to_number());
			 n.pow(d);
			 (yyval).put(n);
			}
#line 4589 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 2033 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-2]).to_number().get();
			 PNF_Number n((yyvsp[0]).to_number());
			 n.root(d);			 
			 (yyval).put(n);
			}
#line 4600 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 2040 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[0]).to_number().get());
			 n.inc(1);
			 (yyval).put(n);
			}
#line 4610 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 2046 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[-1]).to_number().get());
			 (yyval).put(n);
			 n.inc(1);
			}
#line 4620 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 2052 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[0]).to_number().get());
			 n.dec(1);
			 (yyval).put(n);
			}
#line 4630 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 2058 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[-1]).to_number().get());
			 (yyval).put(n);
			 n.dec(1);
			}
#line 4640 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 2064 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 & d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4652 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 2072 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 | d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4664 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 2081 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 ^ d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4676 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 2089 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d = (int)(yyvsp[0]).to_number().get();
			 d = ~d;
			 PNF_Number n(d);
			 (yyval).put(n);
			}
#line 4687 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 2096 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 << d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4699 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 2104 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 >> d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4711 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 2111 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4717 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 2116 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4734 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 2129 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.add((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4745 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 2136 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.sub((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4756 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 2143 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.mul((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4767 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 2150 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.div((yyvsp[0]).to_character().get());
			 (yyval).put(c);			}
#line 4777 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 2156 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.mod((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4788 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 2163 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[0]).to_character().get();
			 PNF_Character c((yyvsp[-2]).to_character());
			 c.pow(d);
			 (yyval).put(c);
			}
#line 4799 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 2170 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c((yyvsp[0]).to_character());
			 c.root(d);
			 (yyval).put(c);
			}
#line 4810 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 2177 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[0]).to_character().get());
			 n.inc(1);
			 (yyval).put(n);
			}
#line 4820 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 2183 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[-1]).to_character().get());
			 (yyval).put(n);
			 n.inc(1);
			}
#line 4830 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 2189 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[0]).to_character().get());
			 n.dec(1);
			 (yyval).put(n);
			}
#line 4840 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 2195 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[-1]).to_character().get());
			 (yyval).put(n);
			 n.dec(1);
			}
#line 4850 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 2200 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4856 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 2205 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4873 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 2218 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4902 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 2243 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String str = (yyvsp[0]).to_string().get();
			 String str2 = "\"" + str + "\"";
			 PNF_String s(str2);
			 (yyval).put(s);
			}
#line 4913 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 2249 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4919 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 2254 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4994 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 2325 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5038 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 2365 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5079 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 2402 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5160 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 2479 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5243 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2558 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5327 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2638 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5369 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2676 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5411 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2714 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5453 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2752 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5495 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2790 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5512 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2803 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5554 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2841 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5596 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2879 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5628 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2907 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5660 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2935 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5692 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2963 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5724 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2990 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 5730 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2994 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 == d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5745 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 3005 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 != d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5760 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 3016 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 < d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5775 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 3027 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 > d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5790 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 3038 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 <= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5805 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 3049 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 >= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5820 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 3059 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String str = (yyval).to_boolean().get();
			 if (str == "false")
			  exptruth = false;
			 else if (str == "true")
			  exptruth = true;
			 else
			  exptruth = true;
			}
#line 5834 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 3069 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5861 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 3094 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 5867 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 3096 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5920 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 3145 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5973 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 3194 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6026 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 3243 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6079 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 3292 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6125 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 3334 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6171 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 3376 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6217 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 3418 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6263 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 3460 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6309 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 3502 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6355 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 3544 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6401 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 3586 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6447 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 3628 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6493 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 3670 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6539 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 3712 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6585 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 3754 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6631 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 3796 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6677 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 3838 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6723 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 3880 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6769 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 3922 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6815 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 3964 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6861 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 4006 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6907 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 4048 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6953 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 4090 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6999 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 4132 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7045 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 4174 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7091 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 4216 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7137 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 4258 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7183 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 4300 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7251 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 4364 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7319 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 4428 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7368 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 4473 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7417 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 4518 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7466 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 4563 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7515 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 4608 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7564 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 4653 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7613 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 4698 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7662 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 4743 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7711 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 4788 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7760 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 4833 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7809 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 4878 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7858 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 4923 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7907 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 4968 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7956 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 5013 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8005 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 5058 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8054 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 5103 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8103 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 5148 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8152 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 5193 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8201 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 5238 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8242 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 5275 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8291 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 5320 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8340 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 5365 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8389 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 5410 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8438 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 5455 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8500 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 5513 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8562 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 5573 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);
			}
#line 8570 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 5577 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-1]);
			}
#line 8578 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 5583 "pnfha.ypp" /* yacc.c:1646  */
    {
			 funcnum = (unsigned long)(yyvsp[0]).to_number().get();
			}
#line 8586 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 5587 "pnfha.ypp" /* yacc.c:1646  */
    {
			 fsaveid2 = (yyvsp[0]);

			 conprint("FCALL TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
			 conprint("FCPARAMS TVOID 0V\n");
			}
#line 8597 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 5594 "pnfha.ypp" /* yacc.c:1646  */
    {
			 pnum3 = 0;
			 pnum4 = 0;
			}
#line 8606 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 5599 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8630 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 5618 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if(fncdefault)
			 {
			  fncdefault = false;
			  conprint("FNCDEFAULT2 TVOID 0V\n");
			 }

			 conprint("FECPARAMS TVOID 0V\n");
			}
#line 8644 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 5628 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("FECALL TVOID 0V\n");
			}
#line 8652 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 5632 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets3.length() - 1; i > 0; --i)
			  frets3.remove();
			 frets3[0] = "";

			 for (unsigned long i = fparams3.length() - 1; i > 0; --i)
			  fparams3.remove();
			 fparams3[0] = "";
			}
#line 8666 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 5644 "pnfha.ypp" /* yacc.c:1646  */
    {

				}
#line 8674 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 5651 "pnfha.ypp" /* yacc.c:1646  */
    {
				 (yyval) = (yyvsp[0]);				 

				 for (unsigned long i = 0; i < funcps[funcps.length() - 1].length(); ++i)
			 	 {
			 	  funcps[funcps.length() - 1][i].value((yyvsp[0]));
			 	 }
				}
#line 8687 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 5662 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8734 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 5705 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8781 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 5748 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8911 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 5874 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9041 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 6019 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9087 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 6154 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			}
#line 9096 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 6159 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			}
#line 9105 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 6164 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9114 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 6169 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 9123 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 6176 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9185 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 6234 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9270 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 6315 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9309 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 6350 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 9318 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 6355 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 9327 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 6360 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 9336 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 6367 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enumv_declaration("enumv_declaration");

			 conprint("ENUMS TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("ENUM TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 conprint("SENUM TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());

			 tree.add_node(enumv_declaration);
			}
#line 9350 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 6379 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9369 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 6394 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9387 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 6410 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode array_declaration("array_declaration");

			 conprint("ASTART TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("AEND TNUMBER %g\n", (yyvsp[-1]).to_number().get());

			 tree.add_node(array_declaration);
			}
#line 9400 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 6421 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_declarationp1("enum_declarationp1");

			 conprint("ESTART TSTRING \"%s\"\n", (yyvsp[-2]).to_string().get().getString().c_str());

			 tree.add_node(enum_declarationp1);
			}
#line 9412 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 6429 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_declarationp2("enum_declarationp2");
			 tree.add_node(enum_declarationp2);
			}
#line 9421 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 6434 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_declarationp3("enum_declarationp3");

			 conprint("EEND TVOID 0V\n");

			 tree.add_node(enum_declarationp3);
			}
#line 9433 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 6444 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_strings("enum_strings");

			 conprint("ENAME TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());

			 tree.add_node(enum_strings);
			}
#line 9445 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 6452 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("ENAME TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			}
#line 9453 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 6458 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9480 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 6483 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9508 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 6507 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9535 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 6530 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9563 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 6558 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9603 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 6594 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets.length() - 1; i > 0; --i)
			  frets.remove();

			 for (unsigned long i = fparams.length() - 1; i > 0; --i)
			  fparams.remove();
			}
#line 9615 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 6606 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9712 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 6699 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9826 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 6811 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9932 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 6913 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10050 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 7029 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10099 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 7074 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10160 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 7133 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10209 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 7178 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10270 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 7237 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10292 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 7255 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 10302 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 7263 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10324 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 7281 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 10334 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 7289 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);


			 funcps[fsaveindex + 1].insert();
			 funcps[fsaveindex + 1][pnum5].value((yyval));


			 funcstk.get_function(fsaveindex + 1).defaultv(pnum5, (yyval));
			 funcstk.get_function(fsaveindex + 1).syncdefaultp(pnum5);
			}
#line 10350 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 7303 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-2]);
			 pnum5 = (unsigned long)(yyvsp[0]).to_number().get();
			}
#line 10359 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 7310 "pnfha.ypp" /* yacc.c:1646  */
    {
			 fncdefault = true;
			 conprint("FNCDEFAULT TVOID 0V\n");
			}
#line 10368 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 7317 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10390 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 7335 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 10400 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 7343 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10422 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 7361 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 10432 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 7369 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10454 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 7387 "pnfha.ypp" /* yacc.c:1646  */
    {
			 unsigned long index = funcstk.find(fsaveid.to_string().get(), frets2, fparams2);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 conprint("LBL TSTRING \"%s_END\"\n", funcstk.get_function(index).rname().getString().c_str());
			}
#line 10469 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 7398 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets2.length() - 1; i > 0; --i)
			  frets2.remove();

			 for (unsigned long i = fparams2.length() - 1; i > 0; --i)
			  fparams2.remove();
			}
#line 10481 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 7413 "pnfha.ypp" /* yacc.c:1646  */
    {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");

			 exptype = TVOID;
			}
#line 10493 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 7421 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10583 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 7507 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10667 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 7589 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;
			}
#line 10675 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 7593 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10727 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 7641 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10779 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 7691 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;			}
#line 10786 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 7694 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10852 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 7756 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10925 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 7963 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;
			}
#line 10933 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 7967 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10985 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 8015 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11037 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 8065 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;
			}
#line 11045 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 8069 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11097 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 8117 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11149 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 8169 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11158 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 8174 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11167 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 8179 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11176 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 8184 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11185 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 8189 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11194 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 8194 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11203 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 8199 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11212 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 8204 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11221 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 8209 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11230 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 8214 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11239 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 8219 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11248 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 8224 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11257 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 8229 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11266 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 8234 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11275 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 8239 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11284 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 8244 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11293 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 8249 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11302 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 8254 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11311 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 8259 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11320 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 8264 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11329 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 8269 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11338 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 8274 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11347 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 8279 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11356 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 8284 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11365 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 8289 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11374 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 8294 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11383 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 8299 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11392 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 8304 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11401 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 8309 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11410 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 8314 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11419 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 8323 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("PRINT TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11429 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 8329 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11479 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 8375 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[0]).to_string().get() == "ver")
			  conprint("VPRINT TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			}
#line 11494 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 8386 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("PRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11504 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 8392 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11554 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 8438 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[0]).to_string().get() == "ver")
			  conprint("VPRINTLN TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			}
#line 11569 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 8449 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINT TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11579 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 8455 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11629 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 8501 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11639 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 8507 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11689 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 8553 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINT TVOID 0V\n");
			}
#line 11698 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 8558 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11748 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 8604 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11758 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 8610 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11808 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 8656 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 conprint("APRINT TVOID 0V\n");

			 tree.add_node(print_command);
			}
#line 11821 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 8668 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11884 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 8727 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11958 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 8800 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode end_command("end_command");
			 conprint("QUIT TVOID %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(end_command);
			}
#line 11968 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 8808 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode asm_command("asm_command");
			 conprint("%s %s %s\n", strip_quotes((yyvsp[-2]).to_string().get()).getString().c_str(), 
					      strip_quotes((yyvsp[-1]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[0]).to_string().get()).getString().c_str());
			 tree.add_node(asm_command);
			}
#line 11979 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 8817 "pnfha.ypp" /* yacc.c:1646  */
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
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12120 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 8954 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12217 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 9047 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12249 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 9075 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TBOOLEAN %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12264 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 9086 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12285 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 9103 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12300 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 9114 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12315 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 9125 "pnfha.ypp" /* yacc.c:1646  */
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
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 12494 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 9300 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12517 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 9319 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12535 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 9333 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12552 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 9346 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12570 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 9360 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[-1]).to_number().get());
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			}
#line 12584 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 9370 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			}
#line 12598 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 9380 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12627 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 9405 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 12639 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 9413 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12668 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 9438 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 12680 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 9446 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12709 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 9471 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 12721 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 9479 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12750 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 9504 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 12762 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 9514 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12786 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 9534 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12893 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 9639 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12903 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 9645 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12913 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 9651 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 12923 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 9657 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(operator_command);
			}
#line 12933 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 9663 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12943 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 9669 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12953 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 9675 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12963 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 9681 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12973 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 9687 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12983 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 9693 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12993 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 9699 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13003 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 9705 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13013 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 9711 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13023 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 9717 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13033 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 9723 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13043 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 9729 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13053 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 9735 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("INC TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13063 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 9741 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("DEC TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13073 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 9747 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("AND TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13083 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 9753 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("OR TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13093 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 9759 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NOT TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13103 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 9765 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13113 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 9771 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13123 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 9777 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13133 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 9783 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13143 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 9789 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13153 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 9795 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 13163 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 9801 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[0]).to_boolean().get();

			 conprint("EQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			}
#line 13177 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 9811 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[0]).to_boolean().get();

			 conprint("NEQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			}
#line 13191 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 9821 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13201 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 9827 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13211 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 9833 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13221 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 9839 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13231 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 9845 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13241 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 9851 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 13251 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 9857 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13261 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 9863 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13271 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 9869 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13281 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 9875 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13291 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 9881 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13301 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 9887 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 13311 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 9893 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTAND TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13321 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 9899 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTOR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13331 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 9905 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTXOR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13341 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 9911 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTNOT TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13351 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 9917 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSL TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13361 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 9923 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 13371 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 9930 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("CMP TVOID 0V");
			}
#line 13379 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 9937 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp1("top_commandp1");

			 intop = true;
			 ++topcounter;

			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp1);
			}
#line 13395 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 9948 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp2("top_commandp2");			 

			 tree.add_node(top_commandp2);
			}
#line 13405 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 9954 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp3("top_commandp3");

			conprint("IFEND TVOID 0V\n"); 
			conprint("ENDIF TVOID 0V\n");

			 tree.add_node(top_commandp3);
			}
#line 13418 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 9963 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp4("top_commandp4");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp4);
			}
#line 13431 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 9972 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp5("top_commandp5");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");
			 conprint("EIF TVOID 0V\n");

			 tree.add_node(top_commandp5);
			}
#line 13445 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 9984 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode st_command("st_command");
			 conprint("ST TVOID 0V\n");
			 tree.add_node(st_command);
			}
#line 13455 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 9992 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode stack_command("stack_command");
			 conprint("PUSH TVOID 0V\n");
			 tree.add_node(stack_command);
			}
#line 13465 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 9998 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode stack_command("stack_command");
			 conprint("POP TVOID 0V\n");
			 tree.add_node(stack_command);
			}
#line 13475 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 10006 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13490 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 10019 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode rm_command("rm_command");
			 conprint("ATOC TVOID 0V\n");
			 tree.add_node(rm_command);
			}
#line 13500 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 10025 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("ATOSP TVOID 0V\n");
			}
#line 13508 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 10029 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SPTOA TVOID 0V\n");
			}
#line 13516 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 10033 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode rm_command("rm_command");
			 conprint("SWITCH TVOID 0V\n");
			 tree.add_node(rm_command);
			}
#line 13526 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 10041 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode crash_command("crash_command");
			 conprint("CRASH TSTRING %s", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(crash_command);
			}
#line 13536 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 10049 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode version_command("version_command");

			 if ((yyvsp[0]).to_string().get().getString() == "pnf")
  			  conprint("VERSION TVOID 0V\n");
			 else if ((yyvsp[0]).to_string().get() == "pnfasm")
			  conprint("version TVOID 0V\n");
			 else if ((yyvsp[0]).to_string().get().getString() == "normal")
  			  ; // Not used yet. This is the first version.
                         else
			  yyerror("Invalid version type.");

			 tree.add_node(version_command);
			}
#line 13555 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 10066 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode halt_command("halt_command");
			 conprint("HALT TVOID 0V\n");
			 tree.add_node(halt_command);
			}
#line 13565 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 10074 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13582 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 10089 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("RET TVOID 0V\n");
			 tree.add_node(subroutine_command);
			}
#line 13592 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 10095 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("CALL TVOID %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(subroutine_command);
			}
#line 13602 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 10101 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13735 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 10232 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13773 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 10266 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13896 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 10385 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14124 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 10609 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14147 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 10630 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14184 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 10663 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if ((yyvsp[0]).to_string().get().getString() == "stk")
			 {
			  conprint("STORESTACK TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid store type.");
			}
#line 14197 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 10672 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14234 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 10705 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode store_command("store_command");

			 conprint("STOREA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 14246 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 10713 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14264 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 10727 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14281 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 10740 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[-1]).to_number().get());
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 14295 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 10750 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 14309 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 10762 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14331 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 10780 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14361 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 10808 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14441 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 10886 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode add2v_command("add2v_command");

			 conprint("ADD2V TVOID 0V\n");

		         tree.add_node(add2v_command);
			}
#line 14453 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 10896 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14474 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 10915 "pnfha.ypp" /* yacc.c:1646  */
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
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 14505 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 10942 "pnfha.ypp" /* yacc.c:1646  */
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
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 14532 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 10965 "pnfha.ypp" /* yacc.c:1646  */
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
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 14559 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 10988 "pnfha.ypp" /* yacc.c:1646  */
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
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 14586 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 11011 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14607 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 11030 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14631 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 11052 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14668 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 11085 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14689 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 11102 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14710 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 11119 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode file_command("file_command");

			 conprint("FIEOF TVOID 0V\n");

			 tree.add_node(file_command);
			}
#line 14722 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 11129 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode meml_command("meml_command");

			 conprint("MEML TVOID 0V\n");

			 tree.add_node(meml_command);
			}
#line 14734 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 11139 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pnfasm_command("pnfasm_command");

			 conprint("pnf %s %s %s\n", strip_quotes((yyvsp[-2]).to_string().get()).getString().c_str(), 
						 strip_quotes((yyvsp[-1]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[0]).to_string().get()).getString().c_str());

			 tree.add_node(pnfasm_command);
			}
#line 14747 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 11150 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode array_length_command("array_length_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 conprint("ALENGTH TVOID 0V\n");

			 tree.add_node(array_length_command);
			}
#line 14760 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 11160 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14781 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 11179 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("FRET TVOID 0V\n");
			}
#line 14789 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 11189 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14837 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 11233 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			}
#line 14849 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 11243 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14900 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 11290 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			}
#line 14912 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 11300 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-3]);
			}
#line 14920 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 11306 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-3]);
			}
#line 14928 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 11312 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#BIN#\n");
			 tree.add_node(pp_directive);
			}
#line 14938 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 11318 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#PBIN#\n");
			 tree.add_node(pp_directive);
			}
#line 14948 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 11324 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#LIB#\n");
			 tree.add_node(pp_directive);
			}
#line 14958 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 11332 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include %s", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 14968 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 11338 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include <%s>", (yyvsp[-2]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14978 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 11344 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 14988 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 11350 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import <%s>\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 14998 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 11356 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#define %s %s\n", (yyvsp[-1]).to_string().get().getString().c_str(), 
						    (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15009 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 11363 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#macro %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15019 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 11369 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endm\n");
			 tree.add_node(pp_statement);
		 	}
#line 15029 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 11375 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#undef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15039 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 11381 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#ifdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15049 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 11387 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#infdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15059 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 11393 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#else\n"); 
			 tree.add_node(pp_statement);
			}
#line 15069 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 11399 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endif\n"); 
			 tree.add_node(pp_statement);
			}
#line 15079 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 11405 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_DATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15089 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 11411 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_TIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15099 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 11417 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_LINE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15109 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 11423 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_FILE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15119 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 11429 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CDATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15129 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 11435 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CTIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15139 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 11441 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
		 	 conprint("%%include %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15149 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 11447 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%include <%s>\n", (yyvsp[-2]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15159 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 11453 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15169 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 11459 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import <%s>\n", (yyvsp[-2]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15179 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 11465 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%define %s %s\n", (yyvsp[-1]).to_string().get().getString().c_str(), 
						     (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15190 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 11472 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%macro %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15200 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 11478 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endm\n"); 
			 tree.add_node(pp_statement);
			}
#line 15210 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 11484 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%undef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15220 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 550:
#line 11490 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%ifdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15230 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 11496 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%infdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 15240 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 11502 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%else\n"); 
			 tree.add_node(pp_statement);
			}
#line 15250 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 553:
#line 11508 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endif\n"); 
			 tree.add_node(pp_statement);
			}
#line 15260 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 554:
#line 11514 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_DATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15270 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 555:
#line 11520 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_TIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15280 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 556:
#line 11526 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_LINE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15290 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 557:
#line 11532 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_FILE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15300 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 558:
#line 11538 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CDATE()\n");
			 tree.add_node(pp_statement);
			}
#line 15310 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 559:
#line 11544 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CTIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 15320 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;


#line 15324 "pnfha.tab.cpp" /* yacc.c:1646  */
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
#line 11550 "pnfha.ypp" /* yacc.c:1906  */

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
