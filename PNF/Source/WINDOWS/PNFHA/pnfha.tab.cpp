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

#line 836 "pnfha.tab.cpp" /* yacc.c:339  */

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
    OPEQU = 277,
    OPNEQU = 278,
    OPBTXOR = 279,
    OPBTOR = 280,
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 1058 "pnfha.tab.cpp" /* yacc.c:358  */

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
#define YYNTOKENS  177
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  177
/* YYNRULES -- Number of rules.  */
#define YYNRULES  536
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  970

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   431

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
     175,   176
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   976,   976,   977,   980,   980,   985,   986,   989,   989,
     994,   997,   999,  1001,  1003,  1005,  1007,  1009,  1012,  1013,
    1016,  1023,  1030,  1037,  1070,  1078,  1088,  1094,  1099,  1110,
    1116,  1125,  1132,  1137,  1109,  1152,  1153,  1152,  1174,  1178,
    1217,  1246,  1251,  1177,  1263,  1278,  1284,  1262,  1298,  1298,
    1303,  1307,  1306,  1350,  1351,  1350,  1361,  1361,  1366,  1370,
    1401,  1369,  1416,  1417,  1416,  1427,  1427,  1436,  1441,  1446,
    1452,  1451,  1471,  1481,  1487,  1470,  1508,  1518,  1525,  1533,
    1539,  1508,  1557,  1561,  1571,  1579,  1589,  1557,  1609,  1622,
    1631,  1637,  1646,  1656,  1608,  1672,  1671,  1691,  1695,  1700,
    1707,  1708,  1716,  1718,  1720,  1722,  1724,  1726,  1728,  1733,
    1743,  1746,  1762,  1776,  1792,  1808,  1811,  1825,  1831,  1837,
    1843,  1849,  1855,  1863,  1870,  1877,  1883,  1889,  1895,  1901,
    1909,  1918,  1926,  1933,  1941,  1949,  1953,  1966,  1973,  1980,
    1987,  1993,  2000,  2007,  2014,  2020,  2026,  2032,  2038,  2042,
    2055,  2080,  2087,  2091,  2162,  2202,  2239,  2316,  2395,  2475,
    2513,  2551,  2589,  2627,  2640,  2678,  2716,  2744,  2772,  2800,
    2828,  2831,  2842,  2853,  2864,  2875,  2887,  2886,  2909,  2910,
    2959,  3008,  3057,  3106,  3148,  3190,  3232,  3274,  3316,  3358,
    3400,  3442,  3484,  3526,  3568,  3610,  3652,  3694,  3736,  3778,
    3820,  3862,  3904,  3946,  3988,  4030,  4072,  4114,  4178,  4242,
    4287,  4332,  4377,  4422,  4467,  4512,  4557,  4602,  4647,  4692,
    4737,  4782,  4827,  4872,  4917,  4962,  5007,  5052,  5089,  5134,
    5179,  5224,  5271,  5275,  5282,  5286,  5293,  5298,  5317,  5327,
    5281,  5342,  5349,  5360,  5403,  5446,  5572,  5717,  5852,  5857,
    5862,  5867,  5874,  5932,  6013,  6048,  6053,  6058,  6065,  6077,
    6092,  6108,  6120,  6128,  6119,  6142,  6150,  6156,  6181,  6205,
    6228,  6252,  6253,  6257,  6256,  6302,  6304,  6397,  6509,  6611,
    6727,  6772,  6831,  6876,  6935,  6953,  6961,  6979,  6987,  6987,
    7001,  7008,  7008,  7015,  7033,  7041,  7059,  7068,  7086,  7067,
    7106,  7111,  7119,  7205,  7287,  7291,  7339,  7389,  7392,  7454,
    7661,  7665,  7713,  7763,  7767,  7815,  7867,  7872,  7877,  7882,
    7887,  7892,  7897,  7902,  7907,  7912,  7917,  7922,  7927,  7932,
    7937,  7942,  7947,  7952,  7957,  7962,  7967,  7972,  7977,  7982,
    7987,  7992,  7997,  8002,  8007,  8012,  8017,  8021,  8027,  8073,
    8084,  8090,  8136,  8147,  8153,  8199,  8205,  8251,  8256,  8302,
    8308,  8354,  8366,  8425,  8498,  8506,  8515,  8652,  8745,  8773,
    8784,  8801,  8812,  8823,  8998,  9017,  9031,  9044,  9058,  9068,
    9079,  9078,  9112,  9111,  9145,  9144,  9178,  9177,  9212,  9232,
    9337,  9343,  9349,  9355,  9361,  9367,  9373,  9379,  9385,  9391,
    9397,  9403,  9409,  9415,  9421,  9427,  9433,  9439,  9445,  9451,
    9457,  9463,  9469,  9475,  9481,  9487,  9493,  9499,  9509,  9519,
    9525,  9531,  9537,  9543,  9549,  9555,  9561,  9567,  9573,  9579,
    9585,  9591,  9597,  9603,  9609,  9615,  9621,  9627,  9632,  9643,
    9649,  9658,  9631,  9678,  9686,  9692,  9700,  9713,  9719,  9723,
    9727,  9735,  9743,  9760,  9768,  9783,  9789,  9795,  9926,  9960,
   10079, 10303, 10324, 10357, 10366, 10399, 10407, 10421, 10434, 10444,
   10456, 10474, 10502, 10580, 10590, 10609, 10636, 10659, 10682, 10705,
   10724, 10746, 10779, 10796, 10813, 10823, 10833, 10844, 10854, 10873,
   10879, 10880, 10884, 10883, 10938, 10937, 10994, 11000, 11006, 11012,
   11018, 11026, 11032, 11038, 11044, 11050, 11057, 11063, 11069, 11075,
   11081, 11087, 11093, 11099, 11105, 11111, 11117, 11123, 11129, 11135,
   11141, 11147, 11153, 11159, 11166, 11172, 11178, 11184, 11190, 11196,
   11202, 11208, 11214, 11220, 11226, 11232, 11238
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
  "OPGEQU", "OPEQU", "OPNEQU", "OPBTXOR", "OPBTOR", "OPAND", "OPOR",
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
  "opt_expressions", "opt_expression", "declaration",
  "variable_declaration", "enumv_declaration", "rangev_declaration",
  "array_declaration", "enum_declaration", "$@53", "$@54", "enum_strings",
  "range_declaration", "label_declaration", "function_declaration", "$@55",
  "nothing", "parameter_declaration", "parameter_declaration2",
  "parameter_declaration5", "parameter_declaration6", "opt_var",
  "opt_var2", "opt_default_value", "dvalue", "optdefaultv", "opt_var5",
  "opt_var6", "function_declaration2", "$@56", "$@57", "function_body",
  "vars", "vars2", "vars3", "vars5", "vars6", "command", "print_command",
  "read_command", "end_command", "asm_command", "load_command", "$@58",
  "$@59", "$@60", "$@61", "goto_command", "operator_command",
  "top_command", "$@62", "$@63", "$@64", "$@65", "st_command",
  "stack_command", "typeof_command", "rm_command", "crash_command",
  "version_command", "halt_command", "modt_command", "subroutine_command",
  "register_command", "store_command", "break_command", "address_command",
  "add2v_command", "continue_command", "check_command", "comment_command",
  "file_command", "meml_command", "pnfasm_command", "array_length_command",
  "dup_command", "fret_command", "parameter_command", "psig", "$@66",
  "psig2", "$@67", "signature", "signature2", "pp_directive",
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
     425,   426,   427,   428,   429,   430,   431
};
# endif

#define YYPACT_NINF -718

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-718)))

#define YYTABLE_NINF -99

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -718,   935,  -718,  -718,  -718,  -167,    -8,  1107,  -718,  1107,
     496,   496,   776,   491,    35,   257,   257,   257,   257,   257,
     555,  1477,  -718,  -718,  1574,  1574,  1574,  1574,  1566,  1566,
    -718,  -718,  -718,  -718,   619,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,   257,    37,  1541,   -10,   543,   135,   619,   619,
     257,    31,    19,   112,    30,  -718,  -718,  -718,    55,  -718,
     103,   152,    37,   105,  -718,   129,  -718,   207,   172,   188,
     168,   -45,   192,   169,   241,   233,   239,   197,  -718,  -718,
     243,  -718,  -718,   119,   202,   240,   255,   261,  -718,   619,
     619,   292,  -718,   302,   311,   253,   259,   313,   320,   300,
    -718,  -718,   235,   349,   348,  -718,   372,  -718,  -718,  -718,
     -31,   -27,   363,   370,  -718,   391,   393,   394,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,   -25,   -16,   398,   403,
    -718,   405,   406,   408,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,   368,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,   316,  -718,   340,  -718,   347,  -718,  -718,  -718,   409,
    -718,   131,  1707,   625,   436,  1687,  -718,  -718,  -718,  -718,
     427,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
     428,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,   423,  -718,  -718,   368,   496,
     496,    35,   257,    35,   555,   496,  -718,  1657,   706,  1767,
    1657,   706,  1767,    35,    35,   776,    35,   776,   310,  1767,
     257,   257,   257,   257,  -718,  1657,    35,  1767,  1730,  1730,
    1730,  1730,  1730,   555,   555,   555,  1657,  1767,  1574,  1574,
    1477,  1730,  1530,   453,  1574,  1730,  1530,  1730,  1530,  1730,
    1530,  1730,  1530,    38,  1566,   310,  1730,  1530,   310,  1730,
    1530,   491,  1748,   439,   286,  1603,   903,    20,  1649,   440,
     450,    -3,   447,  1730,    37,   453,   257,  1574,  1574,  1574,
    1574,  1574,  1477,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,    38,    38,  -718,   454,  -718,   444,  -718,
    -718,  -718,  -718,  -718,  1730,   446,   442,  1468,   429,   257,
     459,   373,   469,   478,   457,   789,  -718,   619,  1107,   453,
    -718,  -718,   464,  1730,   468,   472,  -718,   473,   443,   480,
    -718,   466,  -718,   485,   410,   492,  1107,  -718,  -718,   486,
    1107,  -718,  1107,   338,    37,   456,    37,  -718,  -718,  -718,
     489,   509,   501,   502,   507,   -14,   511,  -718,  -718,   525,
      43,   520,    74,  -718,   519,  -718,   523,   528,  -718,  -718,
    -718,  -718,  -718,   531,  -718,   533,   534,  -718,  -718,  -718,
    -718,  -718,   544,  -718,  -718,   552,  -718,  -718,   102,   146,
    -718,  -718,   808,   824,   842,   866,  1278,   257,  1280,  1292,
    1294,  1327,  1339,  1341,  1374,  1386,  1388,  1421,  1433,  1435,
    -718,  -718,   201,   245,   327,   400,   190,   449,   538,   295,
    -718,  -718,    35,    35,    35,    35,    35,    35,    35,    35,
      35,  -718,  -718,   536,  1626,  1674,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   190,   190,   190,
     190,   190,   190,   296,    38,    38,    27,    37,    38,  -718,
    -718,   539,   541,   545,   551,   553,   559,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  1730,  1730,  1530,  1730,  1530,
    1730,  1530,  1730,  1530,  1730,  1530,  1730,  1530,   453,  1730,
    1730,  1730,  1730,  1730,  1730,  1730,  1730,  1730,  1730,   310,
     310,   619,  -718,    37,  -718,  1468,   310,  1730,  1530,   453,
     314,  1730,  -718,   567,   493,    77,   257,  -718,  1730,   575,
       7,  -718,  -718,  -718,  -718,   257,   570,   257,  -718,   579,
     497,    33,  -718,   368,   368,  1468,  1730,   453,  -718,   453,
    -718,   587,   591,   593,   594,   499,   257,   595,    78,  -718,
     606,    73,  -718,  -718,   608,   117,   474,   475,  -718,   482,
     483,  -718,  -718,  -718,  1107,  -718,  -718,   633,  -718,  -718,
    -718,  1774,  -718,  1774,  -718,  1774,  -718,   577,  -718,   577,
     577,  -718,   381,  -718,   381,  -718,   335,  -718,   335,  -718,
    1730,  -718,  1730,  -718,  1730,  -718,  1730,  -718,  1730,  -718,
    1730,  -718,  -718,  -718,  -718,   190,   190,   190,  -718,   706,
    -718,   706,  -718,   350,  -718,   350,   350,  -718,  -718,  -718,
    -718,  -718,  -718,  1767,  1767,    87,    87,    87,   365,   365,
     634,  -718,   612,  -718,   453,  -718,  -718,  1730,   546,    86,
    -718,   626,   153,  1513,   638,  -718,  1730,  -718,  1730,  -718,
     126,  -718,   571,   310,  1730,  1530,   453,  -718,   635,   639,
     643,  -718,   371,  -718,  -718,   647,   167,   623,   649,   646,
     675,   653,   662,   663,  -718,  -718,  -718,  -718,  1107,  1107,
      -7,  1107,  -718,  -718,  -718,   257,  -718,   670,   655,   678,
     679,  1468,  -718,   694,  -718,   730,   599,   698,   691,  -718,
     617,   699,  -718,   685,   704,   705,  -718,   720,   710,   118,
    -718,   729,   718,   368,   368,  -718,   122,  -718,  -718,   753,
    -718,  -718,   731,   732,   310,  1730,  1530,   453,  -718,  -718,
    -718,  -718,  -718,  -718,   742,   665,  -718,  -718,   756,   746,
     120,   719,  -718,   747,   216,   121,   737,   754,   764,   769,
    -718,  -718,  -718,   143,   750,  -718,  -718,  -718,  -718,   717,
     717,   721,   721,  1107,  1107,   770,   774,   771,   144,   761,
    -718,   772,   224,  -718,  -718,   762,   773,   778,  -718,   775,
     229,  -718,  -718,  -718,  -718,  -718,  1107,  -718,   777,   236,
    -718,  -718,  -718,  -718,  -718,  -718,   619,   736,  -718,  -718,
     619,   739,  -718,  -718,   368,   175,  -718,  -718,  -718,  -718,
     782,   281,  -718,  -718,   791,  -718,   785,  -718,  -718,   798,
     799,  -718,   796,  1107,  1107,  1107,   195,   801,  -718,   802,
    -718,   803,  -718,  -718,   807,  -718,   722,  -718,   813,  -718,
     810,   805,  -718,   814,   831,   809,   811,   818,   368,   368,
     368,  -718,   812,   822,   826,  -718,  -718,   834,  -718,   844,
    -718,  1107,   827,   850,   838,  -718,  -718,   848,  -718,  -718,
    -718,   849,   853,  1107,  -718,   851,  1107,  1107,   861,  -718,
    1107,  -718,   816,   250,   868,  -718,  -718,   856,   846,    48,
     847,  -718,   368,   857,   368,   368,  -718,  1107,   368,  -718,
    -718,  -718,   619,  -718,  -718,   862,  -718,   859,  -718,   864,
    -718,  -718,  -718,   889,  -718,  -718,   870,  -718,   368,  1107,
     800,  1107,   890,  -718,  -718,   868,   882,  -718,    91,  1107,
     -12,  -718,  -718,   368,   902,  -718,  -718,   873,   922,  -718,
     368,  -718,   937,  -718,  -718,   913,  -718,  -718,  -718,  -718
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     7,     3,     0,     6,    65,     5,    65,
     406,   407,   410,   434,   431,   402,   404,   396,   398,   400,
     394,   390,   435,   436,   413,   415,   414,   416,   411,   412,
     433,   432,   408,   409,     0,     8,   109,   111,   116,   136,
     149,    12,     0,     0,   153,     0,   347,   350,   353,   355,
       0,     0,     0,     0,     0,   443,   444,   445,     0,   447,
     450,     0,     0,     0,   453,     0,   455,     0,     0,     0,
       0,     0,     0,     0,     0,   470,     0,     0,   473,    88,
       0,    95,   474,     0,     0,     0,     0,     0,   484,   357,
     359,     0,   485,     0,     0,     0,     0,     0,     0,     0,
     448,   449,   291,     0,     0,   489,     0,   498,   499,   500,
       0,     0,     0,     0,   507,     0,     0,     0,   511,   512,
     513,   514,   515,   516,   517,   518,     0,     0,     0,     0,
     525,     0,     0,     0,   529,   530,   531,   532,   533,   534,
     535,   536,     9,    13,    14,    16,    15,    11,    26,    27,
      28,     0,    67,     0,    68,     0,    69,    70,    17,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   232,
       0,   248,   255,   256,   257,   250,   251,   249,   271,   272,
       0,   316,   317,   318,   319,   320,   321,   322,   437,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   490,   491,     0,    18,    19,    10,     0,
       0,     0,     0,     0,     0,     0,   153,   125,   144,   166,
     127,   146,   168,     0,     0,     0,     0,     0,   112,   155,
       0,     0,     0,     0,   227,   132,     0,   154,   403,   405,
     397,   399,   401,     0,     0,     0,   122,   163,     0,     0,
       0,   391,   392,   393,     0,   421,   427,   423,   429,   422,
     428,   424,   430,     0,     0,   417,   419,   425,   418,   420,
     426,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,   395,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,   252,   349,     0,   348,
     352,   351,   354,   356,   364,     0,     0,   368,     0,     0,
       0,     0,     0,     0,     0,     0,   446,     0,    65,   451,
     452,   454,     0,   456,   268,   269,   458,     0,     0,     0,
     463,     0,   465,     0,     0,     0,    65,   471,   270,     0,
      65,   254,    65,     0,     0,     0,     0,   483,   358,   360,
       0,     0,     0,     0,     0,     0,     0,   488,   292,     0,
       0,     0,     0,   501,     0,   503,     0,     0,   506,   508,
     509,   510,   519,     0,   521,     0,     0,   524,   526,   527,
     528,   438,     0,    66,    77,     0,    71,    20,     0,     0,
     126,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   147,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     115,     0,     0,     0,     0,     0,     0,   135,   148,   152,
     170,   178,   233,    99,    97,   221,   187,   199,   188,   200,
     185,   197,   186,   198,   184,   196,   183,   195,   207,   228,
     229,   217,   219,   218,   220,   215,   216,   223,   222,   179,
     181,     0,   361,     0,   362,     0,   369,   370,   371,   372,
       0,   374,   375,     0,     0,     0,     0,   389,   388,     0,
       0,   457,    24,    25,   459,     0,     0,   464,   466,     0,
       0,     0,   472,    89,    96,     0,   479,   480,   481,   482,
     363,     0,     0,     0,     0,     0,     0,     0,     0,   301,
       0,     0,   234,   310,     0,     0,     0,     0,   505,     0,
       0,   523,   439,    72,    65,    83,   180,   113,   182,   114,
     224,   129,   193,   123,   194,   124,   191,   119,   192,   120,
     121,   190,   118,   189,   117,   230,   133,   231,   134,   211,
     173,   213,   175,   212,   174,   214,   176,   209,   171,   210,
     172,   226,   131,   225,   130,     0,     0,     0,   205,   142,
     206,   143,   203,   139,   204,   140,   141,   202,   138,   201,
     137,   208,   150,   164,   165,   160,   161,   162,   159,   158,
     156,   157,   492,   253,   365,   373,   367,   366,   376,     0,
     313,     0,     0,     0,     0,    44,   461,   460,   462,   467,
       0,    29,     0,   476,   475,   477,   478,   262,     0,     0,
     260,   487,     0,   486,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   502,   504,   520,   522,    65,    65,
       0,    65,   177,   494,   275,     0,   379,     0,     0,     0,
       0,     0,    39,     0,   469,     0,     0,     0,     0,   258,
       0,     0,   261,     0,     0,     0,   302,     0,     0,     0,
     311,     0,     0,   440,    73,    78,     0,   275,   493,     0,
     378,   314,     0,     0,   380,   382,   384,   386,    48,    56,
     468,    30,    90,   265,   263,     0,   259,   305,     0,     0,
       0,     0,   307,     0,     0,     0,     0,     0,     0,     0,
      84,   495,   377,     0,     0,   275,   275,   275,   275,    40,
       0,    45,     0,    65,    65,     0,     0,     0,     0,     0,
     285,     0,     0,   276,   303,     0,     0,     0,   294,     0,
       0,   280,   312,   441,    74,    79,    65,   296,     0,     0,
     282,   315,   381,   383,   385,   387,     0,    53,    50,    49,
       0,    62,    58,    57,    31,     0,   266,   264,   267,   287,
       0,     0,   278,   306,     0,   273,     0,   308,   235,     0,
       0,   496,     0,    65,    65,    65,     0,     0,   497,     0,
      51,     0,    41,    59,     0,    46,     0,    91,     0,   297,
       0,     0,   275,     0,     0,     0,     0,     0,   442,    75,
      80,    85,     0,     0,     0,    54,    42,     0,    63,     0,
      32,    65,     0,     0,     0,   284,   274,     0,   236,   309,
     293,     0,     0,    65,   295,     0,    65,    65,     0,    60,
      65,    47,    35,     0,   288,     8,   298,     0,     0,     0,
       0,    81,    86,     0,    52,    55,    43,    65,    64,    36,
      33,    92,     0,   286,   289,     0,   275,     0,   277,     0,
     247,   237,   241,   242,   243,   281,     0,   283,    61,    65,
       0,    65,     0,   300,   299,   288,     0,   238,     0,    65,
       0,    38,    34,    93,     0,   279,   245,     0,     0,   244,
      87,    37,     0,   290,   239,     0,    94,   275,   246,   240
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -718,  -718,  -718,  -718,   973,  -718,    -9,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,   196,  -718,  -718,  -718,  -718,  -718,   193,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -290,   -44,   953,    41,    -2,   174,    75,   477,  -718,
    -718,   956,   958,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,    49,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -717,  -718,  -718,
    -718,  -718,  -718,  -718,    58,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,   291,     7,   142,   143,   144,   145,
     146,   147,   148,   716,   783,   856,   902,   940,   920,   939,
     952,   149,   748,   817,   876,   898,   713,   821,   879,   779,
     780,   818,   874,   852,   897,   781,   782,   822,   877,   917,
     855,   900,   150,   151,   406,   403,   699,   768,   844,   152,
     153,   584,   769,   845,   892,   154,   155,   701,   806,   893,
     936,   156,   360,   672,   784,   881,   941,   962,   157,   362,
     158,   292,   159,   160,   161,   162,   163,   164,   165,   166,
     702,   167,   168,   169,   690,   864,   909,   947,   957,   967,
     931,   932,   933,   934,   170,   171,   172,   173,   174,   175,
     718,   786,   754,   176,   177,   178,   862,   738,   792,   831,
     800,   809,   793,   832,   923,   924,   379,   801,   810,   179,
     883,   926,   906,   571,   686,   764,   575,   662,   180,   181,
     182,   183,   184,   185,   775,   776,   777,   778,   186,   187,
     188,   582,   698,   767,   843,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     704,   214,   737,   215,   334,   216,   217
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     218,   493,   319,   321,   322,   323,   383,     8,   227,   230,
     385,   245,   392,   248,   249,   250,   251,   252,   256,   261,
     771,   394,   265,   267,   269,   271,   276,   279,   401,   -98,
     347,     9,   285,   401,   316,   439,     9,   665,   233,   234,
     293,   221,   477,   223,   273,   368,   369,   401,   324,   236,
     489,   219,   220,   238,   235,   281,   223,   489,   812,   813,
     814,   815,   224,   671,   246,   343,   294,   478,   325,   275,
     278,   326,    37,   401,    40,   284,   569,    34,   348,   226,
      43,    36,    37,    38,    39,    40,   735,   335,   570,   240,
     241,    43,   282,   222,   219,   220,   263,   235,   281,   223,
     242,   447,   448,   688,   565,   224,   566,   573,   273,   287,
     660,   684,   689,   449,   450,   243,   961,   336,   295,   574,
      34,    38,   661,   685,    36,    37,    38,    39,    40,   240,
     241,   478,   337,   222,    43,   282,    37,   339,   219,   220,
     242,   235,   281,   223,   384,   886,   586,   692,   386,   224,
     393,   762,   273,   790,   798,   243,   693,   408,   409,   395,
     770,    38,   401,   763,    34,   791,   799,   327,    36,    37,
      38,    39,    40,   340,   328,   478,   807,   829,    43,   282,
      37,   338,   104,   709,   228,   231,   929,   329,   808,   830,
     588,   341,   710,   625,   626,   262,   363,   724,   266,   268,
     270,   272,   277,   280,   625,   626,   725,   706,   286,   944,
     240,   241,   320,   857,   222,   401,   344,   227,   230,   627,
     245,   242,   256,   454,   350,   104,    39,   330,   331,   958,
     627,   351,   345,   871,   332,   401,   243,    39,   227,   230,
     256,   454,    38,   346,   333,   628,   796,   714,   625,   626,
     969,   227,   230,   454,   835,   797,   227,   230,   454,   841,
     240,   241,   454,   836,   222,   352,   848,   349,   842,   104,
     356,   242,   454,   359,   627,   849,   238,   357,   473,   245,
     364,    39,   342,   358,   353,   354,   243,   361,   921,   630,
     401,   355,    38,   539,   495,   496,   498,   500,   502,   504,
     506,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   859,   408,   409,   238,   473,   480,   240,   241,   365,
     860,   222,   474,   475,   294,   527,   480,   531,   242,   540,
     625,   626,    40,   538,   366,   476,   474,   475,    43,   641,
     367,   240,   241,   243,   370,   222,   371,   551,   372,    38,
     375,   553,   242,   554,   519,   520,   627,   376,   655,   465,
     466,   556,   377,    39,   471,   472,   656,   243,   526,   476,
     373,   632,   378,    38,   410,   411,   374,   508,   380,   456,
     457,   458,   459,   460,   417,   461,   462,   463,   464,   381,
     555,   449,   450,   228,   231,   465,   466,   463,   464,   455,
     387,   382,   529,   625,   626,   465,   466,   388,   401,   402,
     591,   593,   595,   597,   599,   600,   602,   604,   606,   608,
     610,   612,   614,   616,   618,   620,   622,   624,   389,   627,
     390,   391,   228,   231,   455,   396,    39,   404,   455,   557,
     397,   559,   398,   399,   634,   400,   405,   407,   455,   587,
     589,   439,   625,   626,   591,   593,   595,   597,   599,   602,
     604,   606,   608,   622,   624,   451,   452,   453,   477,   479,
     491,   497,   499,   501,   503,   505,   507,   653,   627,   494,
     492,   522,   521,   523,   530,    39,   524,   229,   232,   239,
     533,   247,   722,   637,   240,   241,   532,   257,   222,   219,
     220,   528,   221,   222,   223,   242,   534,   535,   541,   542,
     224,   288,   536,   543,   642,   587,   589,   544,   545,   473,
     243,   547,   548,   454,   546,   225,    38,   549,   657,   550,
     552,    38,    39,   560,   663,   244,   558,   561,   562,   563,
     226,   625,   626,   666,   564,   668,   219,   220,   567,   235,
     281,   223,   642,   674,   568,   572,   576,   224,   253,   254,
     577,   221,   222,   223,   682,   578,   473,   627,   579,   224,
     580,   581,    34,   583,    39,   700,    36,    37,    38,    39,
      40,   585,   639,   609,   255,   611,    43,   282,   652,   613,
      38,   461,   462,   463,   464,   615,   673,   617,   654,   226,
     476,   465,   466,   619,   658,   664,   629,   631,   633,   635,
     636,   638,   640,   659,   667,   925,   669,   670,   677,   678,
     317,   679,   219,   220,   681,   235,   281,   223,   430,   431,
     676,   680,   683,   224,   432,   433,   434,   435,   436,   437,
     438,   629,   631,   633,   635,   638,   640,   687,    34,   691,
     694,   695,    36,    37,    38,    39,    40,   707,   696,   697,
     475,   450,    43,   282,   703,   318,   705,   708,   715,   712,
     717,   721,   719,   410,   411,   726,   720,   104,   456,   457,
     458,   459,   460,   417,   461,   462,   463,   464,   723,   733,
     734,   728,   736,   727,   465,   466,   229,   232,   239,   455,
     247,   257,   288,   739,   729,   730,   731,   741,   732,   745,
     229,   232,   239,   257,   288,   467,   468,   469,   470,   436,
     471,   472,   742,   288,   743,   749,   751,   752,   753,   675,
     229,   232,   288,   410,   411,   755,   756,   757,   456,   457,
     458,   459,   460,   417,   461,   462,   463,   464,   758,   760,
     759,   761,   744,   104,   465,   466,   410,   411,   765,   766,
     773,   456,   457,   458,   459,   460,   417,   461,   462,   463,
     464,   794,   850,   774,   824,   825,   853,   465,   466,   233,
     234,   785,   235,   787,   223,   788,   747,   789,   795,   802,
     236,   740,   240,   241,   804,   803,   222,   846,   805,   228,
     231,   455,   811,   242,   816,   237,   827,   826,   828,   820,
      37,   240,   241,   833,   837,   222,   834,   838,   243,   840,
     226,   847,   242,   839,    38,   851,   858,   240,   241,   854,
     863,   222,   861,   537,   868,   869,   870,   243,   242,   865,
     866,   867,   872,    38,   875,   240,   241,   873,   878,   222,
     880,   750,   590,   243,   882,   884,   242,   885,   887,    38,
     888,   889,   891,   890,   894,   930,   895,   896,   592,   240,
     241,   243,   903,   222,   772,   899,   901,    38,   942,   904,
     242,   905,   907,   911,   912,   746,   594,   914,   915,   908,
     910,   918,   913,   916,   943,   243,   922,   927,   928,   935,
     949,    38,   919,   964,   930,   946,   430,   431,   938,   937,
     596,   945,   432,   433,   434,   435,   436,   437,   438,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   948,   951,
     950,   954,   953,   488,   956,     2,     3,   963,    -8,    -8,
     960,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,   965,    -8,   968,    -8,   966,    -8,    -8,
      -8,    -8,    -8,    -8,     6,   823,   819,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,   283,    -8,    -8,
     289,    -8,   290,    -8,    -8,    -8,    -8,   959,    -8,    -8,
      -8,    -8,    -8,   955,    -8,    -8,    -8,    -8,    -8,    -8,
       0,     0,     0,     0,     0,     0,    -8,    -8,    -8,    -8,
      -8,     0,     0,     0,     0,     0,    -8,    -8,    -8,    -8,
      -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
       0,    -8,     0,     0,    -8,     0,     0,    -8,     0,    -8,
       0,    -8,     0,     0,     0,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,     0,     0,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -4,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,     0,    35,     0,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     0,
      52,    53,     0,    54,     0,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,     0,    64,    65,    66,    67,
      68,    69,     0,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,    75,    76,
       0,    77,    78,     0,   -76,    79,   -82,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,     0,     0,    96,     0,     0,    97,
       0,    98,     0,    99,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   240,   241,   240,   241,   222,     0,   222,     0,     0,
       0,     0,   242,     0,   242,   240,   241,   240,   241,   222,
       0,   222,     0,     0,     0,     0,   242,   243,   242,   243,
       0,     0,     0,    38,     0,    38,     0,     0,     0,     0,
       0,   243,   598,   243,   601,     0,     0,    38,     0,    38,
     240,   241,     0,     0,   222,     0,   603,     0,   605,     0,
       0,   242,   240,   241,   240,   241,   222,     0,   222,     0,
       0,     0,     0,   242,     0,   242,   243,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,   243,     0,
     243,   607,     0,     0,    38,     0,    38,   240,   241,     0,
       0,   222,     0,   609,     0,   611,     0,     0,   242,   240,
     241,   240,   241,   222,     0,   222,     0,     0,     0,     0,
     242,     0,   242,   243,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,   243,     0,   243,   613,     0,
       0,    38,     0,    38,   240,   241,     0,     0,   222,     0,
     615,     0,   617,     0,     0,   242,   240,   241,   240,   241,
     222,     0,   222,     0,     0,     0,     0,   242,     0,   242,
     243,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,   243,     0,   243,   619,     0,     0,    38,     0,
      38,   258,   259,     0,   273,   222,     0,   621,     0,   623,
     258,   259,   242,     0,   222,     0,     0,     0,     0,     0,
       0,   242,     0,     0,     0,     0,     0,   525,     0,     0,
       0,     0,    37,    38,    39,    40,   260,     0,     0,     0,
       0,    43,    38,    39,    40,     0,   410,   411,     0,     0,
      43,   456,   457,   458,   459,   460,   417,   461,   462,   463,
     464,     0,     0,   430,   431,     0,     0,   465,   466,   467,
     468,   469,   470,   436,   471,   472,     0,     0,     0,   296,
     297,   298,   299,   300,   711,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   258,
     259,     0,   273,   222,     0,     0,     0,   258,   259,     0,
     242,   222,   315,     0,     0,     0,     0,     0,   242,     0,
       0,     0,     0,     0,     0,   274,     0,     0,     0,     0,
      37,    38,    39,   264,     0,     0,   410,   411,     0,    38,
      39,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   481,   482,   483,   484,   485,   486,   428,   429,   410,
     411,     0,     0,   487,   456,   457,   458,   459,   460,   417,
     461,   462,   463,   464,     0,     0,     0,     0,     0,     0,
     465,   466,   440,   441,     0,     0,   487,     0,   442,   443,
     444,   445,   446,   447,   448,   456,   457,   458,   459,   460,
     417,   461,   462,   463,   464,   449,   450,   430,   431,   490,
       0,   465,   466,   467,   468,   469,   470,   436,   471,   472,
     440,   441,     0,     0,     0,     0,   442,   443,   444,   445,
     446,   447,   448,     0,   488,     0,     0,     0,     0,     0,
     410,   411,     0,   449,   450,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   410,   411,     0,     0,     0,   456,   457,
     458,   459,   460,   417,   461,   462,   463,   464,     0,     0,
       0,     0,     0,     0,   465,   466,   296,   297,   298,   299,
     300,     0,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   442,   443,   444,   445,
     446,   447,   448,   457,   458,   459,   460,   417,   461,   462,
     463,   464,     0,   449,   450,     0,     0,     0,   465,   466
};

static const yytype_int16 yycheck[] =
{
       9,   291,    46,    47,    48,    49,    37,   174,    10,    11,
      37,    13,    37,    15,    16,    17,    18,    19,    20,    21,
     737,    37,    24,    25,    26,    27,    28,    29,    40,    32,
      75,    39,    34,    40,    44,    15,    39,    30,     3,     4,
      42,     6,    15,     8,     6,    89,    90,    40,    50,    14,
      30,     3,     4,    12,     6,     7,     8,    30,   775,   776,
     777,   778,    14,    30,    29,    67,    29,    29,    37,    28,
      29,    52,    34,    40,    37,    34,    33,    29,   123,    44,
      43,    33,    34,    35,    36,    37,    93,    57,    45,     3,
       4,    43,    44,     7,     3,     4,    21,     6,     7,     8,
      14,    14,    15,    30,   118,    14,   120,    33,     6,    34,
      33,    33,    39,    26,    27,    29,   128,    62,    43,    45,
      29,    35,    45,    45,    33,    34,    35,    36,    37,     3,
       4,    29,    29,     7,    43,    44,    34,    62,     3,     4,
      14,     6,     7,     8,   175,   862,    44,    30,   175,    14,
     175,    33,     6,    33,    33,    29,    39,    26,    27,   175,
      38,    35,    40,    45,    29,    45,    45,    55,    33,    34,
      35,    36,    37,    68,    62,    29,    33,    33,    43,    44,
      34,    29,   134,    30,    10,    11,   138,    75,    45,    45,
      44,    62,    39,     3,     4,    21,    77,    30,    24,    25,
      26,    27,    28,    29,     3,     4,    39,   121,    34,   926,
       3,     4,    77,    38,     7,    40,    44,   219,   220,    29,
     222,    14,   224,   225,    55,   134,    36,   115,   116,   138,
      29,    62,    44,    38,   122,    40,    29,    36,   240,   241,
     242,   243,    35,    75,   132,    44,    30,   121,     3,     4,
     967,   253,   254,   255,    30,    39,   258,   259,   260,    30,
       3,     4,   264,    39,     7,    96,    30,    75,    39,   134,
      29,    14,   274,    76,    29,    39,   235,    44,   237,   281,
      78,    36,    75,    44,   115,   116,    29,    44,    38,    44,
      40,   122,    35,   337,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    30,    26,    27,   273,   274,    30,     3,     4,    79,
      39,     7,    26,    27,    29,   327,    30,   329,    14,   338,
       3,     4,    37,   335,    79,   260,    26,    27,    43,    44,
      79,     3,     4,    29,    52,     7,    44,   356,    37,    35,
      37,   360,    14,   362,   313,   314,    29,    37,    44,    24,
      25,   363,    62,    36,    14,    15,    52,    29,   327,   294,
     117,    44,   137,    35,     3,     4,   117,   302,    29,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    41,
      52,    26,    27,   219,   220,    24,    25,    16,    17,   225,
      37,    29,   327,     3,     4,    24,    25,    37,    40,    93,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,    37,    29,
      37,    37,   258,   259,   260,    37,    36,    97,   264,   364,
      37,   366,    37,    37,    44,    37,    99,    38,   274,   408,
     409,    15,     3,     4,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,    38,    38,    44,    15,    30,
      30,   297,   298,   299,   300,   301,   302,   521,    29,    32,
      30,    37,    28,    37,    55,    36,    44,    10,    11,    12,
     117,    14,   121,    44,     3,     4,    37,    20,     7,     3,
       4,   327,     6,     7,     8,    14,    37,    29,    44,    41,
      14,    34,    55,    41,   439,   474,   475,    44,    75,   478,
      29,    55,    37,   525,    44,    29,    35,   117,   530,    37,
      44,    35,    36,    44,   536,    44,    80,    28,    37,    37,
      44,     3,     4,   545,    37,   547,     3,     4,    37,     6,
       7,     8,   477,   555,    29,    35,    37,    14,     3,     4,
      37,     6,     7,     8,   566,    37,   525,    29,    37,    14,
      37,    37,    29,    29,    36,   584,    33,    34,    35,    36,
      37,    29,    44,    44,    29,    44,    43,    44,    52,    44,
      35,    14,    15,    16,    17,    44,   555,    44,   523,    44,
     525,    24,    25,    44,    37,    30,   432,   433,   434,   435,
     436,   437,   438,   120,    44,   905,    37,   120,    31,    28,
      77,    28,     3,     4,   125,     6,     7,     8,     3,     4,
     555,    37,    37,    14,     9,    10,    11,    12,    13,    14,
      15,   467,   468,   469,   470,   471,   472,    41,    29,    41,
     176,   176,    33,    34,    35,    36,    37,   659,   176,   176,
      27,    27,    43,    44,    52,   122,   120,    41,   670,    31,
      99,    28,    37,     3,     4,    52,    37,   134,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    41,   698,
     699,    45,   701,    44,    24,    25,   219,   220,   221,   525,
     223,   224,   225,   705,    29,    52,    44,    52,    45,   711,
     233,   234,   235,   236,   237,     9,    10,    11,    12,    13,
      14,    15,    44,   246,    45,    31,   127,    29,    37,   555,
     253,   254,   255,     3,     4,   118,    37,    52,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    44,    29,
      45,    41,   711,   134,    24,    25,     3,     4,    29,    41,
      29,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    52,   816,    41,   783,   784,   820,    24,    25,     3,
       4,    39,     6,   118,     8,    29,   711,    41,    41,    52,
      14,   121,     3,     4,    30,    41,     7,   806,    29,   625,
     626,   627,    52,    14,    87,    29,    32,    37,    37,    88,
      34,     3,     4,    52,    52,     7,    44,    44,    29,    44,
      44,    44,    14,    45,    35,    89,    44,     3,     4,    90,
      45,     7,    41,    44,   843,   844,   845,    29,    14,    41,
      41,    45,    41,    35,    41,     3,     4,    45,    41,     7,
     128,   121,    44,    29,    41,    45,    14,    52,    44,    35,
      29,    52,    44,    52,    52,   909,    44,    41,    44,     3,
       4,    29,   881,     7,   121,    41,    32,    35,   922,    52,
      14,    31,    44,    30,   893,   711,    44,   896,   897,    41,
      41,   900,    41,    32,    32,    29,    28,    41,    52,    52,
      30,    35,    86,    30,   948,    41,     3,     4,   917,    52,
      44,    52,     9,    10,    11,    12,    13,    14,    15,   442,
     443,   444,   445,   446,   447,   448,   449,   450,    39,   129,
     939,    41,   941,    30,    52,     0,     1,    35,     3,     4,
     949,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    41,    29,    52,    31,    30,    33,    34,
      35,    36,    37,    38,     1,   782,   780,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    34,    53,    54,
      34,    56,    34,    58,    59,    60,    61,   948,    63,    64,
      65,    66,    67,   945,    69,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,    -1,    -1,   119,    -1,    -1,   122,    -1,   124,
      -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,    -1,    -1,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    31,    -1,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    -1,    56,    -1,    58,    59,    60,    61,    -1,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,    -1,    -1,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     3,     4,     3,     4,     7,    -1,     7,    -1,    -1,
      -1,    -1,    14,    -1,    14,     3,     4,     3,     4,     7,
      -1,     7,    -1,    -1,    -1,    -1,    14,    29,    14,    29,
      -1,    -1,    -1,    35,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    29,    44,    29,    44,    -1,    -1,    35,    -1,    35,
       3,     4,    -1,    -1,     7,    -1,    44,    -1,    44,    -1,
      -1,    14,     3,     4,     3,     4,     7,    -1,     7,    -1,
      -1,    -1,    -1,    14,    -1,    14,    29,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      29,    44,    -1,    -1,    35,    -1,    35,     3,     4,    -1,
      -1,     7,    -1,    44,    -1,    44,    -1,    -1,    14,     3,
       4,     3,     4,     7,    -1,     7,    -1,    -1,    -1,    -1,
      14,    -1,    14,    29,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    29,    44,    -1,
      -1,    35,    -1,    35,     3,     4,    -1,    -1,     7,    -1,
      44,    -1,    44,    -1,    -1,    14,     3,     4,     3,     4,
       7,    -1,     7,    -1,    -1,    -1,    -1,    14,    -1,    14,
      29,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    29,    44,    -1,    -1,    35,    -1,
      35,     3,     4,    -1,     6,     7,    -1,    44,    -1,    44,
       3,     4,    14,    -1,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    29,    -1,    -1,    -1,
      -1,    43,    35,    36,    37,    -1,     3,     4,    -1,    -1,
      43,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,     3,     4,    -1,    -1,    24,    25,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,     8,
       9,    10,    11,    12,    41,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     3,
       4,    -1,     6,     7,    -1,    -1,    -1,     3,     4,    -1,
      14,     7,    41,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      34,    35,    36,    29,    -1,    -1,     3,     4,    -1,    35,
      36,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     3,
       4,    -1,    -1,    30,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,     3,     4,    -1,    -1,    30,    -1,     9,    10,
      11,    12,    13,    14,    15,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    26,    27,     3,     4,    30,
      -1,    24,    25,     9,    10,    11,    12,    13,    14,    15,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    30,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    26,    27,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     9,    10,    11,    12,
      13,    14,    15,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    26,    27,    -1,    -1,    -1,    24,    25
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
     271,   272,   273,   274,   275,   276,   280,   281,   282,   296,
     305,   306,   307,   308,   309,   310,   315,   316,   317,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   348,   350,   352,   353,   183,     3,
       4,     6,     7,     8,    14,    29,    44,   252,   253,   255,
     252,   253,   255,     3,     4,     6,    14,    29,   251,   255,
       3,     4,    14,    29,    44,   252,    29,   255,   252,   252,
     252,   252,   252,     3,     4,    29,   252,   255,     3,     4,
      29,   252,   253,   254,    29,   252,   253,   252,   253,   252,
     253,   252,   253,     6,    29,   251,   252,   253,   251,   252,
     253,     7,    44,   250,   251,   252,   253,   254,   255,   258,
     259,   181,   248,   252,    29,   254,     8,     9,    10,    11,
      12,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    41,    44,    77,   122,   249,
      77,   249,   249,   249,   252,    37,    52,    55,    62,    75,
     115,   116,   122,   132,   351,    57,    62,    29,    29,   254,
      68,    62,    75,   252,    44,    44,    75,    75,   123,    75,
      55,    62,    96,   115,   116,   122,    29,    44,    44,    76,
     239,    44,   246,    77,    78,    79,    79,    79,   249,   249,
      52,    44,    37,   117,   117,    37,    37,    62,   137,   293,
      29,    41,    29,    37,   175,    37,   175,    37,    37,    37,
      37,    37,    37,   175,    37,   175,    37,    37,    37,    37,
      37,    40,    93,   222,    97,    99,   221,    38,    26,    27,
       3,     4,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       3,     4,     9,    10,    11,    12,    13,    14,    15,    15,
       3,     4,     9,    10,    11,    12,    13,    14,    15,    26,
      27,    38,    38,    44,   252,   253,     8,     9,    10,    11,
      12,    14,    15,    16,    17,    24,    25,     9,    10,    11,
      12,    14,    15,   251,    26,    27,   254,    15,    29,    30,
      30,    18,    19,    20,    21,    22,    23,    30,    30,    30,
      30,    30,    30,   248,    32,   252,   252,   253,   252,   253,
     252,   253,   252,   253,   252,   253,   252,   253,   254,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   251,
     251,    28,    37,    37,    44,    29,   251,   252,   253,   254,
      55,   252,    37,   117,    37,    29,    55,    44,   252,   249,
     183,    44,    41,    41,    44,    75,    44,    55,    37,   117,
      37,   183,    44,   183,   183,    52,   252,   254,    80,   254,
      44,    28,    37,    37,    37,   118,   120,    37,    29,    33,
      45,   300,    35,    33,    45,   303,    37,    37,    37,    37,
      37,    37,   318,    29,   228,    29,    44,   251,    44,   251,
      44,   252,    44,   252,    44,   252,    44,   252,    44,   252,
     252,    44,   252,    44,   252,    44,   252,    44,   252,    44,
     252,    44,   252,    44,   252,    44,   252,    44,   252,    44,
     252,    44,   252,    44,   252,     3,     4,    29,    44,   253,
      44,   253,    44,   253,    44,   253,   253,    44,   253,    44,
     253,    44,   254,   255,   255,   255,   255,   255,   255,   255,
     255,   255,    52,   249,   254,    44,    52,   252,    37,   120,
      33,    45,   304,   252,    30,    30,   252,    44,   252,    37,
     120,    30,   240,   251,   252,   253,   254,    31,    28,    28,
      37,   125,   252,    37,    33,    45,   301,    41,    30,    39,
     261,    41,    30,    39,   176,   176,   176,   176,   319,   223,
     183,   234,   257,    52,   347,   120,   121,   252,    41,    30,
      39,    41,    31,   203,   121,   252,   190,    99,   277,    37,
      37,    28,   121,    41,    30,    39,    52,    44,    45,    29,
      52,    44,    45,   183,   183,    93,   183,   349,   284,   252,
     121,    52,    44,    45,   251,   252,   253,   254,   199,    31,
     121,   127,    29,    37,   279,   118,    37,    52,    44,    45,
      29,    41,    33,    45,   302,    29,    41,   320,   224,   229,
      38,   284,   121,    29,    41,   311,   312,   313,   314,   206,
     207,   212,   213,   191,   241,    39,   278,   118,    29,    41,
      33,    45,   285,   289,    52,    41,    30,    39,    33,    45,
     287,   294,    52,    41,    30,    29,   235,    33,    45,   288,
     295,    52,   284,   284,   284,   284,    87,   200,   208,   208,
      88,   204,   214,   214,   183,   183,    37,    32,    37,    33,
      45,   286,   290,    52,    44,    30,    39,    52,    44,    45,
      44,    30,    39,   321,   225,   230,   183,    44,    30,    39,
     249,    89,   210,   249,    90,   217,   192,    38,    44,    30,
      39,    41,   283,    45,   262,    41,    41,    45,   183,   183,
     183,    38,    41,    45,   209,    41,   201,   215,    41,   205,
     128,   242,    41,   297,    45,    52,   284,    44,    29,    52,
      52,    44,   231,   236,    52,    44,    41,   211,   202,    41,
     218,    32,   193,   183,    52,    31,   299,    44,    41,   263,
      41,    30,   183,    41,   183,   183,    32,   216,   183,    86,
     195,    38,    28,   291,   292,   248,   298,    41,    52,   138,
     249,   267,   268,   269,   270,    52,   237,    52,   183,   196,
     194,   243,   249,    32,   284,    52,    41,   264,    39,    30,
     183,   129,   197,   183,    41,   291,    52,   265,   138,   270,
     183,   128,   244,    35,    30,    41,    30,   266,    52,   284
};

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
     260,   267,   268,   269,   269,   269,   269,   270,   271,   271,
     271,   271,   272,   272,   272,   272,   272,   272,   273,   274,
     274,   275,   277,   278,   276,   279,   279,   280,   281,   281,
     281,   281,   281,   283,   282,   284,   285,   285,   286,   286,
     287,   287,   288,   288,   289,   289,   290,   290,   291,   291,
     292,   293,   293,   294,   294,   295,   295,   297,   298,   296,
     299,   300,   300,   300,   301,   301,   301,   302,   302,   302,
     303,   303,   303,   304,   304,   304,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   307,   307,   308,   309,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     311,   310,   312,   310,   313,   310,   314,   310,   315,   315,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   318,   319,
     320,   321,   317,   322,   323,   323,   324,   325,   325,   325,
     325,   326,   327,   328,   329,   330,   330,   330,   331,   331,
     331,   331,   332,   332,   332,   332,   332,   332,   332,   332,
     333,   333,   334,   335,   336,   337,   337,   337,   337,   337,
     338,   339,   339,   339,   339,   340,   341,   342,   343,   344,
     345,   345,   347,   346,   349,   348,   350,   351,   352,   352,
     352,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
      17,     1,     1,     1,     3,     3,     5,     1,     1,     1,
       1,     1,     2,     4,     2,     1,     1,     1,     5,     6,
       4,     5,     0,     0,     8,     1,     3,     8,     2,     2,
       2,     1,     1,     0,    10,     0,     1,     6,     1,     7,
       1,     6,     1,     6,     4,     1,     5,     1,     0,     1,
       4,     0,     1,     4,     1,     4,     1,     0,     0,    13,
       3,     1,     3,     5,     1,     3,     5,     1,     3,     5,
       1,     3,     5,     1,     3,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     3,     3,     3,     2,     4,     4,     4,     2,     3,
       3,     3,     3,     4,     3,     3,     4,     7,     6,     5,
       0,     8,     0,     8,     0,     8,     0,     8,     3,     3,
       1,     2,     2,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       0,     0,     9,     1,     1,     1,     2,     1,     1,     1,
       1,     2,     2,     1,     2,     1,     2,     3,     2,     3,
       4,     4,     4,     2,     3,     2,     3,     4,     6,     5,
       1,     2,     3,     1,     1,     4,     4,     4,     4,     3,
       3,     3,     3,     2,     1,     1,     4,     4,     2,     1,
       1,     1,     0,     5,     0,     6,     8,     8,     1,     1,
       1,     2,     4,     2,     4,     3,     2,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     2,     4,     3,     2,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 977 "pnfha.ypp" /* yacc.c:1646  */
    { ASTNode start("START"); tree.add_node(start); }
#line 3057 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 980 "pnfha.ypp" /* yacc.c:1646  */
    {
	 ASTNode line("line");
         tree.add_node(line);
	}
#line 3066 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 986 "pnfha.ypp" /* yacc.c:1646  */
    { yyerrok; }
#line 3072 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 989 "pnfha.ypp" /* yacc.c:1646  */
    {
		 ASTNode statement("statement");
  		 tree.add_node(statement);
		}
#line 3081 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 997 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1; 
		    	                    statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3088 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 999 "pnfha.ypp" /* yacc.c:1646  */
    { conprint("VOID TVOID 0V\n"); statementoutcount.insert(); 
                         statementoutcount[statementoutcount.length() - 1] = outcount - 1; statementlineno.insert(); statementlineno[statementlineno.length() - 1]                          = yylineno; }
#line 3095 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 1001 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					  statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3102 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 1003 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					   statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3109 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 1005 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3116 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 1007 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				       statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3123 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 1009 "pnfha.ypp" /* yacc.c:1646  */
    { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; inblock = true;
				   }
#line 3131 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 1017 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode expression_statement("expression_statement");
			 tree.add_node(expression_statement);
			}
#line 3140 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 1024 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration_statement("declaration_statement");
			 tree.add_node(declaration_statement);
			}
#line 3149 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 1031 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command_statement("command_statement");
			 tree.add_node(command_statement);
			}
#line 3158 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 1038 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3195 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 1071 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode label_statement("label_statement");

			 conprint("LBL TVOID 0V\n");

			 tree.add_node(label_statement);
			}
#line 3207 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 1079 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode label_statement("label_statement");

			 conprint("ELBL TVOID 0V\n");

			 tree.add_node(label_statement);
			}
#line 3219 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 1089 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			}
#line 3229 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 1095 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");
			 tree.add_node(control_statement);
			}
#line 3238 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 1100 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode control_statement("control_statement");

			 breakinforever = false;

			 tree.add_node(control_statement);
			}
#line 3250 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 1110 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp1("if_statementp1");

			 tree.add_node(if_statementp1);		
			}
#line 3260 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 1116 "pnfha.ypp" /* yacc.c:1646  */
    {			 
			 ASTNode if_statementp2("if_statementp2");
			
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			}
#line 3273 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 1125 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			}
#line 3284 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 1132 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			}
#line 3293 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 1137 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			}
#line 3303 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 1143 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			}
#line 3315 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 1153 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp5("if_statementp5");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 // Code for else will be inserted here if exists...
			 tree.add_node(if_statementp5);
			}
#line 3329 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 1164 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode if_statementp7("if_statementp7");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");

			 tree.add_node(if_statementp7);
			}
#line 3342 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 1178 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3385 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 1217 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3418 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 1246 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp3("switch_statementp3");

			 tree.add_node(switch_statementp3);
			}
#line 3428 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 1251 "pnfha.ypp" /* yacc.c:1646  */
    {

			}
#line 3436 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 1255 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			}
#line 3448 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 1263 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3466 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 1278 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp2("switch_statementp2");
			 
			 tree.add_node(switch_statementp2);
			}
#line 3476 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 1284 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp3("switch_statementp3");
			 tree.add_node(switch_statementp3);
			}
#line 3485 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 1289 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			}
#line 3497 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 1298 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			}
#line 3506 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 1307 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3548 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 1345 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 3556 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 1351 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			}
#line 3565 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 1356 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 3573 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 1361 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			}
#line 3582 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1370 "pnfha.ypp" /* yacc.c:1646  */
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
#line 3617 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 1401 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statementp2("case_statementp2");

			 tree.add_node(case_statementp2);
			}
#line 3627 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1407 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode case_statementp3("case_statementp3");

			 conprint("SWCEND TVOID 0V\n");

			 tree.add_node(case_statementp3);
			}
#line 3639 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1417 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			}
#line 3648 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1422 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 3656 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1427 "pnfha.ypp" /* yacc.c:1646  */
    {
			 loopexpr = true;
			 inloop2 = true;
			}
#line 3665 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1432 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3674 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1437 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3683 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1442 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3692 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1447 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 3701 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1452 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode loop_statement("loop_statement");
			 
			 loopexpr = false;
			 inloop = true;		 

			 tree.add_node(loop_statement);
			}
#line 3714 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1460 "pnfha.ypp" /* yacc.c:1646  */
    {
			 inloop2 = false;
			 inwhile = false;
			 indowhile = false;
			 infor2 = false;
			 indofor = false;
			 inforever = false;
			}
#line 3727 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1471 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp1("while_loopp1");

			 inwhile = true;
			 ++whilecounter;
			 conprint("LBL TSTRING \"while_test_%u\"\n", whilecounter);

			 tree.add_node(while_loopp1);
			}
#line 3741 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1481 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp2("while_loopp2");

			 tree.add_node(while_loopp2);
			}
#line 3751 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1487 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp3("while_loopp3");

			 conprint("CGOTOL TSTRING \"while_body_%u\"\n", whilecounter);
			 conprint("GOTOL TSTRING \"while_end_%u\"\n", whilecounter);

			 conprint("LBL TSTRING \"while_body_%u\"\n", whilecounter);

			 tree.add_node(while_loopp3);
			}
#line 3766 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1498 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode while_loopp4("while_loopp4");

			 conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 conprint("LBL TSTRING \"while_end_%u\"\n", whilecounter);

			 tree.add_node(while_loopp4);
			}
#line 3779 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1508 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp1("do_while_loopp1");

			 indowhile = true;
			 ++dowhilecounter;
			 conprint("LBL TSTRING \"do_while_body_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp1);
			}
#line 3793 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1518 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp2("do_while_loopp2");

			 tree.add_node(do_while_loopp2);
			}
#line 3803 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1525 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp3("do_while_loopp3");

			 conprint("LBL TSTRING \"do_while_test_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp3);
			}
#line 3815 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1533 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp4("do_while_loopp4");

			 tree.add_node(do_while_loopp4);
			}
#line 3825 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1539 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp5("do_while_loopp5");

			 conprint("CGOTOL TSTRING \"do_while_body_%u\"\n", dowhilecounter);
			 conprint("GOTOL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp5);
			}
#line 3838 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1548 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode do_while_loopp6("do_while_loopp6");

			 conprint("LBL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp6);
			}
#line 3850 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1557 "pnfha.ypp" /* yacc.c:1646  */
    {
			 infor = true;
			}
#line 3858 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1561 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp1("for_loopp1");

			 infor2 = true;
			 ++forcounter;
			 conprint("LBL TSTRING \"for_initialization_%u\"\n", forcounter);

			 tree.add_node(for_loopp1);
			}
#line 3872 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1571 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp2("for_loopp2");

			 conprint("LBL TSTRING \"for_condition_%u\"\n", forcounter);

			 tree.add_node(for_loopp2);
			}
#line 3884 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1579 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp3("for_loopp3");

			 conprint("CGOTOL TSTRING \"for_body_%u\"\n", forcounter);
			 conprint("GOTOL TSTRING \"for_end_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_increment_statement_%u\"\n", forcounter);

			 tree.add_node(for_loopp3);
			}
#line 3898 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1589 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp4("for_loopp4");

			 conprint("GOTOL TSTRING \"for_condition_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_body_%u\"\n", forcounter);

			 tree.add_node(for_loopp4);
			}
#line 3911 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1598 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode for_loopp5("for_loopp5");

			 conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_end_%u\"\n", forcounter);

			 tree.add_node(for_loopp5);
			}
#line 3924 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1609 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp1("forb_loopp1");

			 indofor = true;
			 infor = true;
			 ++doforcounter;

			 conprint("GOTOL TSTRING \"dofor_initialization_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_body_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp1);
			}
#line 3941 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1622 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp2("forb_loopp2");

			 conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_initialization_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp2);
			}
#line 3954 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1631 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp3("forb_loopp3");

			 tree.add_node(forb_loopp3);
			}
#line 3964 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1637 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp4("forb_loopp4");

			 conprint("GOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_condition_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp4);
			}
#line 3977 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1646 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp5("forb_loopp5");

			 conprint("CGOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("GOTOL TSTRING \"dofor_end_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp5);
			}
#line 3991 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1656 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp6("forb_loopp6");
			 tree.add_node(forb_loopp6);
			}
#line 4000 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1661 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forb_loopp7("forb_loopp7");

			 conprint("GOTOL TSTRING \"dofor_condition_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_end_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp7);
			}
#line 4013 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1672 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forever_loopp1("forever_loopp1");

			 breakinforever = true;
			 ++forevercounter;
			 conprint("LBL TSTRING \"forever_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp1);			
			}
#line 4027 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1682 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode forever_loopp2("forever_loopp2");

			 conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);
			 conprint("LBL TSTRING \"forever_end_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp2);			
			}
#line 4040 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1691 "pnfha.ypp" /* yacc.c:1646  */
    { PNF_String str((yyvsp[-1]).to_string().get()); (yyval).put(str); ASTNode statement_block("statement_block"); 
                                                  tree.add_node(statement_block); }
#line 4047 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1696 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			}
#line 4056 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1701 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			}
#line 4065 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1707 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = TVOID; ASTNode expression("expression"); tree.add_node(expression); }
#line 4071 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1709 "pnfha.ypp" /* yacc.c:1646  */
    {
		 (yyval) = (yyvsp[0]);
		 savenumber = (yyval);
		 exptype = TBOOLEAN;
		 ASTNode expression("expression");
		 tree.add_node(expression);
		}
#line 4083 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1716 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); savenumber = (yyval); exptype = TNUMBER; ASTNode expression("expression");
                                      tree.add_node(expression); }
#line 4090 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1718 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); savenumber = (yyval); exptype = TCHARACTER; ASTNode expression("expression"); 
                                         tree.add_node(expression); }
#line 4097 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1720 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); savenumber = (PNF_String)strip_quotes((yyval).to_string().get()); exptype = TSTRING; ASTNode expression("expression"); 
                                      tree.add_node(expression); }
#line 4104 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1722 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
                                  tree.add_node(expression); }
#line 4111 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1724 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = TBOOLEAN; ASTNode expression("expression"); 
					  tree.add_node(expression); }
#line 4118 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1726 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); 
				     tree.add_node(expression); }
#line 4125 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1728 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); exptype = (PNF_Type_Enum)(yyval).getType(); ASTNode expression("expression"); tree.add_node(expression); 		
		}
#line 4132 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1734 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_String s("0V");
			 (yyval).put(s);

			 exptruth = false;

			 ASTNode void_expression("void_expression");
			 tree.add_node(void_expression);
			}
#line 4146 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1743 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4152 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1747 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4172 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1763 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4190 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1777 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4210 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1793 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4230 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1808 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4236 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1812 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4254 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1826 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().add(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4264 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1832 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().sub(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4274 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1838 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().mul(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4284 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1844 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().div(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4294 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1850 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-1]).to_number().get();
			 (yyvsp[-2]).to_number().mod(d);
			 (yyval) = (yyvsp[-2]);
			}
#line 4304 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1856 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char * str = "-";
			 strcat(str, (yyvsp[0]).to_string().get().getString().c_str());
			 PNF_String s(str);
			 PNF_Variable v(s);
			 (yyval) = v;
			}
#line 4316 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1864 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[0]).to_number().get();
			 PNF_Number n((yyvsp[-2]).to_number());
			 n.pow(d);
			 (yyval).put(n);
			}
#line 4327 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1871 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d = (yyvsp[-2]).to_number().get();
			 PNF_Number n((yyvsp[0]).to_number());
			 n.root(d);			 
			 (yyval).put(n);
			}
#line 4338 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1878 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[0]).to_number().get());
			 n.inc(1);
			 (yyval).put(n);
			}
#line 4348 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1884 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[-1]).to_number().get());
			 (yyval).put(n);
			 n.inc(1);
			}
#line 4358 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1890 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[0]).to_number().get());
			 n.dec(1);
			 (yyval).put(n);
			}
#line 4368 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1896 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Number n((yyvsp[-1]).to_number().get());
			 (yyval).put(n);
			 n.dec(1);
			}
#line 4378 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1902 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 & d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4390 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1910 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 | d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4402 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1919 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 ^ d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4414 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1927 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d = (int)(yyvsp[0]).to_number().get();
			 d = ~d;
			 PNF_Number n(d);
			 (yyval).put(n);
			}
#line 4425 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1934 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 << d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4437 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1942 "pnfha.ypp" /* yacc.c:1646  */
    {
			 int d1 = (int)(yyvsp[-2]).to_number().get();
			 int d2 = (int)(yyvsp[0]).to_number().get();
			 int d3 = d1 >> d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			}
#line 4449 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1949 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4455 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1954 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4472 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1967 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.add((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4483 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1974 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.sub((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4494 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1981 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.mul((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4505 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1988 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.div((yyvsp[0]).to_character().get());
			 (yyval).put(c);			}
#line 4515 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1994 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c(d);
			 c.mod((yyvsp[0]).to_character().get());
			 (yyval).put(c);
			}
#line 4526 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 2001 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[0]).to_character().get();
			 PNF_Character c((yyvsp[-2]).to_character());
			 c.pow(d);
			 (yyval).put(c);
			}
#line 4537 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 2008 "pnfha.ypp" /* yacc.c:1646  */
    {
			 char d = (yyvsp[-2]).to_character().get();
			 PNF_Character c((yyvsp[0]).to_character());
			 c.root(d);
			 (yyval).put(c);
			}
#line 4548 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 2015 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[0]).to_character().get());
			 n.inc(1);
			 (yyval).put(n);
			}
#line 4558 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 2021 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[-1]).to_character().get());
			 (yyval).put(n);
			 n.inc(1);
			}
#line 4568 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 2027 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[0]).to_character().get());
			 n.dec(1);
			 (yyval).put(n);
			}
#line 4578 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 2033 "pnfha.ypp" /* yacc.c:1646  */
    {
			 PNF_Character n((yyvsp[-1]).to_character().get());
			 (yyval).put(n);
			 n.dec(1);
			}
#line 4588 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 2038 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4594 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 2043 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4611 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 2056 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4640 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 2081 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String str = (yyvsp[0]).to_string().get();
			 String str2 = "\"" + str + "\"";
			 PNF_String s(str2);
			 (yyval).put(s);
			}
#line 4651 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 2087 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4657 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 2092 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4732 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 2163 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4776 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 2203 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4817 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 2240 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4898 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 2317 "pnfha.ypp" /* yacc.c:1646  */
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
#line 4981 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 2396 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5065 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 2476 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5107 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 2514 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5149 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 2552 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5191 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 2590 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5233 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 2628 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5250 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 2641 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5292 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 2679 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5334 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 2717 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5366 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 2745 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5398 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 2773 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5430 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 2801 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5462 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 2828 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 5468 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 2832 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 == d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5483 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 2843 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 != d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5498 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 2854 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 < d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5513 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 2865 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 > d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5528 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 2876 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 <= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5543 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 2887 "pnfha.ypp" /* yacc.c:1646  */
    {
			 double d1 = (yyvsp[-2]).to_number().get();
			 double d2 = (yyvsp[0]).to_number().get();
			 bool b = d1 >= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 5558 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2897 "pnfha.ypp" /* yacc.c:1646  */
    {
			 String str = (yyval).to_boolean().get();
			 if (str == "false")
			  exptruth = false;
			 else if (str == "true")
			  exptruth = true;
			 else
			  exptruth = true;
			}
#line 5572 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2909 "pnfha.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 5578 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2911 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5631 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2960 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5684 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 3009 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5737 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 3058 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5790 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 3107 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5836 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 3149 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5882 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 3191 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5928 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 3233 "pnfha.ypp" /* yacc.c:1646  */
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
#line 5974 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 3275 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6020 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 3317 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6066 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 3359 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6112 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 3401 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6158 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 3443 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6204 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 3485 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6250 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 3527 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6296 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 3569 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6342 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 3611 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6388 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 3653 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6434 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 3695 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6480 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 3737 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6526 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 3779 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6572 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 3821 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6618 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 3863 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6664 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 3905 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6710 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 3947 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6756 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 3989 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6802 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 4031 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6848 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 4073 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6894 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 4115 "pnfha.ypp" /* yacc.c:1646  */
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
#line 6962 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 4179 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7030 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 4243 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7079 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 4288 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7128 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 4333 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7177 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 4378 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7226 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 4423 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7275 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 4468 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7324 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 4513 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7373 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 4558 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7422 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 4603 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7471 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 4648 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7520 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 4693 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7569 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 4738 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7618 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 4783 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7667 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 4828 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7716 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 4873 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7765 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 4918 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7814 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 4963 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7863 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 5008 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7912 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 5053 "pnfha.ypp" /* yacc.c:1646  */
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
#line 7953 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 5090 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8002 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 5135 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8051 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 5180 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8100 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 5225 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8149 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 5272 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);
			}
#line 8157 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 5276 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-1]);
			}
#line 8165 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 5282 "pnfha.ypp" /* yacc.c:1646  */
    {
			 funcnum = (unsigned long)(yyvsp[0]).to_number().get();
			}
#line 8173 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 5286 "pnfha.ypp" /* yacc.c:1646  */
    {
			 fsaveid2 = (yyvsp[0]);

			 conprint("FCALL TSTRING \"%s\"\n", (yyvsp[0]).to_string().get().getString().c_str());
			 conprint("FCPARAMS TVOID 0V\n");
			}
#line 8184 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 5293 "pnfha.ypp" /* yacc.c:1646  */
    {
			 pnum3 = 0;
			 pnum4 = 0;
			}
#line 8193 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 5298 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8217 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 5317 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if(fncdefault)
			 {
			  fncdefault = false;
			  conprint("FNCDEFAULT2 TVOID 0V\n");
			 }

			 conprint("FECPARAMS TVOID 0V\n");
			}
#line 8231 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 5327 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("FECALL TVOID 0V\n");
			}
#line 8239 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 5331 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets3.length() - 1; i > 0; --i)
			  frets3.remove();
			 frets3[0] = "";

			 for (unsigned long i = fparams3.length() - 1; i > 0; --i)
			  fparams3.remove();
			 fparams3[0] = "";
			}
#line 8253 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 5343 "pnfha.ypp" /* yacc.c:1646  */
    {

				}
#line 8261 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 5350 "pnfha.ypp" /* yacc.c:1646  */
    {
				 (yyval) = (yyvsp[0]);				 

				 for (unsigned long i = 0; i < funcps[funcps.length() - 1].length(); ++i)
			 	 {
			 	  funcps[funcps.length() - 1][i].value((yyvsp[0]));
			 	 }
				}
#line 8274 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 5361 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8321 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 5404 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8368 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 5447 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8498 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 5573 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8628 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 5718 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8674 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 5853 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			}
#line 8683 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 5858 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			}
#line 8692 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 5863 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 8701 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 5868 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 8710 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 5875 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8772 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 5933 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8857 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 6014 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8896 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 6049 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 8905 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 6054 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 8914 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 6059 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 8923 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 6066 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enumv_declaration("enumv_declaration");

			 conprint("ENUMS TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("ENUM TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 conprint("SENUM TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());

			 tree.add_node(enumv_declaration);
			}
#line 8937 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 6078 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8956 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 6093 "pnfha.ypp" /* yacc.c:1646  */
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
#line 8974 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 6109 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode array_declaration("array_declaration");

			 conprint("ASTART TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("AEND TNUMBER %g\n", (yyvsp[-1]).to_number().get());

			 tree.add_node(array_declaration);
			}
#line 8987 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 6120 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_declarationp1("enum_declarationp1");

			 conprint("ESTART TSTRING \"%s\"\n", (yyvsp[-2]).to_string().get().getString().c_str());

			 tree.add_node(enum_declarationp1);
			}
#line 8999 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 6128 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_declarationp2("enum_declarationp2");
			 tree.add_node(enum_declarationp2);
			}
#line 9008 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 6133 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_declarationp3("enum_declarationp3");

			 conprint("EEND TVOID 0V\n");

			 tree.add_node(enum_declarationp3);
			}
#line 9020 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 6143 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode enum_strings("enum_strings");

			 conprint("ENAME TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());

			 tree.add_node(enum_strings);
			}
#line 9032 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 6151 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("ENAME TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			}
#line 9040 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 6157 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9067 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 6182 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9095 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 6206 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9122 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 6229 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9150 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 6257 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9190 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 6293 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets.length() - 1; i > 0; --i)
			  frets.remove();

			 for (unsigned long i = fparams.length() - 1; i > 0; --i)
			  fparams.remove();
			}
#line 9202 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 6305 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9299 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 6398 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9413 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 6510 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9519 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 6612 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9637 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 6728 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9686 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 6773 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9747 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 6832 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9796 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 6877 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9857 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 6936 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9879 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 6954 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 9889 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 6962 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9911 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 6980 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 9921 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 6988 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);


			 funcps[fsaveindex + 1].insert();
			 funcps[fsaveindex + 1][pnum5].value((yyval));


			 funcstk.get_function(fsaveindex + 1).defaultv(pnum5, (yyval));
			 funcstk.get_function(fsaveindex + 1).syncdefaultp(pnum5);
			}
#line 9937 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 7002 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-2]);
			 pnum5 = (unsigned long)(yyvsp[0]).to_number().get();
			}
#line 9946 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 7009 "pnfha.ypp" /* yacc.c:1646  */
    {
			 fncdefault = true;
			 conprint("FNCDEFAULT TVOID 0V\n");
			}
#line 9955 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 7016 "pnfha.ypp" /* yacc.c:1646  */
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
#line 9977 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 7034 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 9987 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 7042 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10009 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 7060 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[0]);

			 exptype = TVOID;
			}
#line 10019 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 7068 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10041 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 7086 "pnfha.ypp" /* yacc.c:1646  */
    {
			 unsigned long index = funcstk.find(fsaveid.to_string().get(), frets2, fparams2);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 conprint("LBL TSTRING \"%s_END\"\n", funcstk.get_function(index).rname().getString().c_str());
			}
#line 10056 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 7097 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets2.length() - 1; i > 0; --i)
			  frets2.remove();

			 for (unsigned long i = fparams2.length() - 1; i > 0; --i)
			  fparams2.remove();
			}
#line 10068 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 7112 "pnfha.ypp" /* yacc.c:1646  */
    {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");

			 exptype = TVOID;
			}
#line 10080 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 7120 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10170 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 7206 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10254 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 7288 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;
			}
#line 10262 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 7292 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10314 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 7340 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10366 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 7390 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;			}
#line 10373 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 7393 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10439 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 7455 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10512 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 7662 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;
			}
#line 10520 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 7666 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10572 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 7714 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10624 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 7764 "pnfha.ypp" /* yacc.c:1646  */
    {
			 exptype = TVOID;
			}
#line 10632 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 7768 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10684 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 7816 "pnfha.ypp" /* yacc.c:1646  */
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
#line 10736 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 7868 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10745 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 7873 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10754 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 7878 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10763 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 7883 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10772 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 7888 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10781 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 7893 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10790 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 7898 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10799 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 7903 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10808 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 7908 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10817 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 7913 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10826 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 7918 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10835 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 7923 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10844 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 7928 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10853 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 7933 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10862 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 7938 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10871 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 7943 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10880 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 7948 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10889 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 7953 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10898 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 7958 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10907 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 7963 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10916 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 7968 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10925 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 7973 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10934 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 7978 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10943 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 7983 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10952 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 7988 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10961 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 7993 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10970 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 7998 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10979 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 8003 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10988 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 8008 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 10997 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 8013 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 11006 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 8022 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("PRINT TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11016 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 8028 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11066 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 8074 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[0]).to_string().get() == "ver")
			  conprint("VPRINT TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			}
#line 11081 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 8085 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("PRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11091 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 8091 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11141 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 8137 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");

			 if ((yyvsp[0]).to_string().get() == "ver")
			  conprint("VPRINTLN TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			}
#line 11156 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 8148 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINT TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11166 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 8154 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11216 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 8200 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("EPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11226 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 8206 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11276 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 8252 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINT TVOID 0V\n");
			}
#line 11285 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 8257 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11335 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 8303 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			 conprint("FPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 11345 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 8309 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11395 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 8355 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode print_command("print_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 conprint("APRINT TVOID 0V\n");

			 tree.add_node(print_command);
			}
#line 11408 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 8367 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11471 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 8426 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11545 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 8499 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode end_command("end_command");
			 conprint("QUIT TVOID %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(end_command);
			}
#line 11555 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 8507 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode asm_command("asm_command");
			 conprint("%s %s %s\n", strip_quotes((yyvsp[-2]).to_string().get()).getString().c_str(), 
					      strip_quotes((yyvsp[-1]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[0]).to_string().get()).getString().c_str());
			 tree.add_node(asm_command);
			}
#line 11566 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 8516 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11707 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 8653 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11804 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 8746 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11836 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 8774 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TBOOLEAN %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 11851 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 8785 "pnfha.ypp" /* yacc.c:1646  */
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
#line 11872 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 8802 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 11887 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 8813 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");
			 if ((yyvsp[-1]).to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 11902 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 8824 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12081 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 8999 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12104 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 9018 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12122 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 9032 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12139 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 9045 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12157 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 9059 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[-1]).to_number().get());
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			}
#line 12171 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 9069 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			}
#line 12185 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 9079 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12214 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 9104 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 12226 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 9112 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12255 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 9137 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 12267 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 9145 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12296 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 9170 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 12308 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 9178 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12337 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 9203 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 12349 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 9213 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12373 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 9233 "pnfha.ypp" /* yacc.c:1646  */
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
#line 12480 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 9338 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12490 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 9344 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12500 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 9350 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TCHARACTER %c\n", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 12510 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 9356 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TSTRING %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(operator_command);
			}
#line 12520 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 9362 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12530 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 9368 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12540 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 9374 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12550 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 9380 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12560 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 9386 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12570 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 9392 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12580 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 9398 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12590 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 9404 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12600 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 9410 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12610 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 9416 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("POW TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12620 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 9422 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12630 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 9428 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TNUMBER %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12640 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 9434 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("INC TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12650 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 9440 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("DEC TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12660 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 9446 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("AND TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12670 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 9452 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("OR TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12680 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 9458 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NOT TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12690 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 9464 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12700 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 9470 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12710 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 9476 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12720 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 9482 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12730 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 9488 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12740 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 9494 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 12750 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 9500 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[0]).to_boolean().get();

			 conprint("EQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			}
#line 12764 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 9510 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");

			 String str = (yyvsp[0]).to_boolean().get();

			 conprint("NEQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			}
#line 12778 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 9520 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12788 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 9526 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12798 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 9532 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12808 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 9538 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12818 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 9544 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12828 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 9550 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TNUMBER %g", (yyvsp[0]).to_number().get());
			 tree.add_node(operator_command);
			}
#line 12838 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 9556 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 12848 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 9562 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 12858 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 9568 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 12868 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 9574 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 12878 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 9580 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 12888 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 9586 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TCHARACTER %c", (yyvsp[0]).to_character().get());
			 tree.add_node(operator_command);
			}
#line 12898 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 9592 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTAND TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 12908 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 9598 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTOR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 12918 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 9604 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTXOR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 12928 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 9610 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTNOT TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 12938 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 9616 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSL TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 12948 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 9622 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode operator_command("operator_command");
			 conprint("BTSR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 12958 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 9632 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp1("top_commandp1");

			 intop = true;
			 ++topcounter;

			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp1);
			}
#line 12974 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 9643 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp2("top_commandp2");			 

			 tree.add_node(top_commandp2);
			}
#line 12984 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 9649 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp3("top_commandp3");

			conprint("IFEND TVOID 0V\n"); 
			conprint("ENDIF TVOID 0V\n");

			 tree.add_node(top_commandp3);
			}
#line 12997 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 9658 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp4("top_commandp4");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp4);
			}
#line 13010 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 9667 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode top_commandp5("top_commandp5");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");
			 conprint("EIF TVOID 0V\n");

			 tree.add_node(top_commandp5);
			}
#line 13024 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 9679 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode st_command("st_command");
			 conprint("ST TVOID 0V\n");
			 tree.add_node(st_command);
			}
#line 13034 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 9687 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode stack_command("stack_command");
			 conprint("PUSH TVOID 0V\n");
			 tree.add_node(stack_command);
			}
#line 13044 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 9693 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode stack_command("stack_command");
			 conprint("POP TVOID 0V\n");
			 tree.add_node(stack_command);
			}
#line 13054 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 9701 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13069 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 9714 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode rm_command("rm_command");
			 conprint("ATOC TVOID 0V\n");
			 tree.add_node(rm_command);
			}
#line 13079 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 9720 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("ATOSP TVOID 0V\n");
			}
#line 13087 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 9724 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("SPTOA TVOID 0V\n");
			}
#line 13095 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 9728 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode rm_command("rm_command");
			 conprint("SWITCH TVOID 0V\n");
			 tree.add_node(rm_command);
			}
#line 13105 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 9736 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode crash_command("crash_command");
			 conprint("CRASH TSTRING %s", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(crash_command);
			}
#line 13115 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 9744 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13134 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 9761 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode halt_command("halt_command");
			 conprint("HALT TVOID 0V\n");
			 tree.add_node(halt_command);
			}
#line 13144 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 9769 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13161 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 9784 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("RET TVOID 0V\n");
			 tree.add_node(subroutine_command);
			}
#line 13171 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 9790 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("CALL TVOID %g\n", (yyvsp[0]).to_number().get());
			 tree.add_node(subroutine_command);
			}
#line 13181 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 9796 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13314 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 9927 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13352 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 9961 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13475 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 10080 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13703 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 10304 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13726 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 10325 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13763 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 10358 "pnfha.ypp" /* yacc.c:1646  */
    {
			 if ((yyvsp[0]).to_string().get().getString() == "stk")
			 {
			  conprint("STORESTACK TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid store type.");
			}
#line 13776 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 10367 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13813 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 10400 "pnfha.ypp" /* yacc.c:1646  */
    {
 			 ASTNode store_command("store_command");

			 conprint("STOREA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 13825 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 10408 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13843 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 10422 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13860 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 10435 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-3]).to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", (yyvsp[-1]).to_number().get());
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 13874 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 10445 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 13888 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 10457 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13910 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 10475 "pnfha.ypp" /* yacc.c:1646  */
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
#line 13940 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 10503 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14020 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 10581 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode add2v_command("add2v_command");

			 conprint("ADD2V TVOID 0V\n");

		         tree.add_node(add2v_command);
			}
#line 14032 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 10591 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14053 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 10610 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14084 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 10637 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14111 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 10660 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14138 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 10683 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14165 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 10706 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14186 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 10725 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14210 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 10747 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14247 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 10780 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14268 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 10797 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14289 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 10814 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode file_command("file_command");

			 conprint("FIEOF TVOID 0V\n");

			 tree.add_node(file_command);
			}
#line 14301 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 10824 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode meml_command("meml_command");

			 conprint("MEML TVOID 0V\n");

			 tree.add_node(meml_command);
			}
#line 14313 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 10834 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pnfasm_command("pnfasm_command");

			 conprint("pnf %s %s %s\n", strip_quotes((yyvsp[-2]).to_string().get()).getString().c_str(), 
						 strip_quotes((yyvsp[-1]).to_string().get()).getString().c_str(), strip_quotes((yyvsp[0]).to_string().get()).getString().c_str());

			 tree.add_node(pnfasm_command);
			}
#line 14326 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 10845 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode array_length_command("array_length_command");
			
			 conprint("APREP TSTRING %s\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 conprint("ALENGTH TVOID 0V\n");

			 tree.add_node(array_length_command);
			}
#line 14339 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 10855 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14360 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 10874 "pnfha.ypp" /* yacc.c:1646  */
    {
			 conprint("FRET TVOID 0V\n");
			}
#line 14368 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 10884 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14416 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 10928 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			}
#line 14428 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 10938 "pnfha.ypp" /* yacc.c:1646  */
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
#line 14479 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 10985 "pnfha.ypp" /* yacc.c:1646  */
    {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			}
#line 14491 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 10995 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-3]);
			}
#line 14499 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 11001 "pnfha.ypp" /* yacc.c:1646  */
    {
			 (yyval) = (yyvsp[-3]);
			}
#line 14507 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 11007 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#BIN#\n");
			 tree.add_node(pp_directive);
			}
#line 14517 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 11013 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#PBIN#\n");
			 tree.add_node(pp_directive);
			}
#line 14527 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 11019 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_directive("pp_directive");
			 conprint("#LIB#\n");
			 tree.add_node(pp_directive);
			}
#line 14537 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 11027 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include %s", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 14547 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 11033 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include <%s>", (yyvsp[-2]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14557 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 11039 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import %s\n", (yyvsp[0]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 14567 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 11045 "pnfha.ypp" /* yacc.c:1646  */
    { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import <%s>\n", (yyvsp[-2]).to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 14577 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 11051 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#define %s %s\n", (yyvsp[-1]).to_string().get().getString().c_str(), 
						    (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14588 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 11058 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#macro %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14598 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 11064 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endm\n");
			 tree.add_node(pp_statement);
		 	}
#line 14608 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 11070 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#undef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14618 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 11076 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#ifdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14628 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 11082 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#infdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14638 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 11088 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#else\n"); 
			 tree.add_node(pp_statement);
			}
#line 14648 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 11094 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endif\n"); 
			 tree.add_node(pp_statement);
			}
#line 14658 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 11100 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_DATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14668 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 11106 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_TIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14678 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 11112 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_LINE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14688 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 11118 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_FILE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14698 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 11124 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CDATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14708 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 11130 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CTIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14718 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 11136 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
		 	 conprint("%%include %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14728 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 11142 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%include <%s>\n", (yyvsp[-2]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14738 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 11148 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14748 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 11154 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import <%s>\n", (yyvsp[-2]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14758 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 11160 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%define %s %s\n", (yyvsp[-1]).to_string().get().getString().c_str(), 
						     (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14769 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 11167 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%macro %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14779 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 11173 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endm\n"); 
			 tree.add_node(pp_statement);
			}
#line 14789 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 11179 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%undef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14799 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 11185 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%ifdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14809 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 11191 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%infdef %s\n", (yyvsp[0]).to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 14819 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 11197 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%else\n"); 
			 tree.add_node(pp_statement);
			}
#line 14829 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 11203 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endif\n"); 
			 tree.add_node(pp_statement);
			}
#line 14839 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 11209 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_DATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14849 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 11215 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_TIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14859 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 11221 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_LINE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14869 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 11227 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_FILE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14879 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 11233 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CDATE()\n");
			 tree.add_node(pp_statement);
			}
#line 14889 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 11239 "pnfha.ypp" /* yacc.c:1646  */
    {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CTIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 14899 "pnfha.tab.cpp" /* yacc.c:1646  */
    break;


#line 14903 "pnfha.tab.cpp" /* yacc.c:1646  */
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
#line 11245 "pnfha.ypp" /* yacc.c:1906  */

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
