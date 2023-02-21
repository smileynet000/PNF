/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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

1/23/23 Origional a-a-b - 1. Implemented loops in lower level.
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

#line 850 "pnfha.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NEG = 258,                     /* NEG  */
    OPCMP = 259,                   /* OPCMP  */
    LEFTP = 260,                   /* LEFTP  */
    RIGHTP = 261,                  /* RIGHTP  */
    LEFTB = 262,                   /* LEFTB  */
    RIGHTB = 263,                  /* RIGHTB  */
    VOIDV = 264,                   /* VOIDV  */
    BOOLEANV = 265,                /* BOOLEANV  */
    NUMBERV = 266,                 /* NUMBERV  */
    CHARACTERV = 267,              /* CHARACTERV  */
    STRINGV = 268,                 /* STRINGV  */
    SEND = 269,                    /* SEND  */
    COMMA = 270,                   /* COMMA  */
    OPEQUAL = 271,                 /* OPEQUAL  */
    OPPLUS = 272,                  /* OPPLUS  */
    OPMINUS = 273,                 /* OPMINUS  */
    OPTIMES = 274,                 /* OPTIMES  */
    OPDIV = 275,                   /* OPDIV  */
    OPMODULUS = 276,               /* OPMODULUS  */
    OPPOWER = 277,                 /* OPPOWER  */
    OPROOT = 278,                  /* OPROOT  */
    OPINC = 279,                   /* OPINC  */
    OPDEC = 280,                   /* OPDEC  */
    OPAND = 281,                   /* OPAND  */
    OPAMP = 282,                   /* OPAMP  */
    OPOR = 283,                    /* OPOR  */
    OPNOT = 284,                   /* OPNOT  */
    OPQUES = 285,                  /* OPQUES  */
    OPCOLON = 286,                 /* OPCOLON  */
    OPSUB = 287,                   /* OPSUB  */
    OPEQU = 288,                   /* OPEQU  */
    OPNEQU = 289,                  /* OPNEQU  */
    OPGTR = 290,                   /* OPGTR  */
    OPLSS = 291,                   /* OPLSS  */
    OPLEQU = 292,                  /* OPLEQU  */
    OPGEQU = 293,                  /* OPGEQU  */
    OPBTOR = 294,                  /* OPBTOR  */
    OPBTXOR = 295,                 /* OPBTXOR  */
    OPBTNOT = 296,                 /* OPBTNOT  */
    OPBTSL = 297,                  /* OPBTSL  */
    OPBTSR = 298,                  /* OPBTSR  */
    OPSTR = 299,                   /* OPSTR  */
    OPSTRTIMES = 300,              /* OPSTRTIMES  */
    OPRUN = 301,                   /* OPRUN  */
    ID = 302,                      /* ID  */
    VAR = 303,                     /* VAR  */
    PRINT = 304,                   /* PRINT  */
    PRINTLN = 305,                 /* PRINTLN  */
    EPRINT = 306,                  /* EPRINT  */
    EPRINTLN = 307,                /* EPRINTLN  */
    END = 308,                     /* END  */
    ASM = 309,                     /* ASM  */
    TYPE = 310,                    /* TYPE  */
    READ = 311,                    /* READ  */
    LOAD = 312,                    /* LOAD  */
    LTYPE = 313,                   /* LTYPE  */
    GOTO = 314,                    /* GOTO  */
    GTYPE = 315,                   /* GTYPE  */
    ST = 316,                      /* ST  */
    PUSH = 317,                    /* PUSH  */
    POP = 318,                     /* POP  */
    TOP = 319,                     /* TOP  */
    TYPEOF = 320,                  /* TYPEOF  */
    RTYPE = 321,                   /* RTYPE  */
    ATOC = 322,                    /* ATOC  */
    SWITCH = 323,                  /* SWITCH  */
    CSWITCH = 324,                 /* CSWITCH  */
    CRASH = 325,                   /* CRASH  */
    VERSION = 326,                 /* VERSION  */
    VTYPE = 327,                   /* VTYPE  */
    HALT = 328,                    /* HALT  */
    MODT = 329,                    /* MODT  */
    RETURN = 330,                  /* RETURN  */
    GOSUB = 331,                   /* GOSUB  */
    SUB = 332,                     /* SUB  */
    EVENT = 333,                   /* EVENT  */
    STYPE = 334,                   /* STYPE  */
    ATYPE = 335,                   /* ATYPE  */
    CTYPE = 336,                   /* CTYPE  */
    CMTYPE = 337,                  /* CMTYPE  */
    BFMODEC = 338,                 /* BFMODEC  */
    FMODEC = 339,                  /* FMODEC  */
    UNREGISTER = 340,              /* UNREGISTER  */
    REGISTER = 341,                /* REGISTER  */
    REREGISTER = 342,              /* REREGISTER  */
    STORE = 343,                   /* STORE  */
    IF = 344,                      /* IF  */
    ELSE = 345,                    /* ELSE  */
    CASE = 346,                    /* CASE  */
    CCASE = 347,                   /* CCASE  */
    DEFAULT = 348,                 /* DEFAULT  */
    CDEFAULT = 349,                /* CDEFAULT  */
    BREAK = 350,                   /* BREAK  */
    LABEL = 351,                   /* LABEL  */
    WHILEC = 352,                  /* WHILEC  */
    ADDRESSOF = 353,               /* ADDRESSOF  */
    ADD2V = 354,                   /* ADD2V  */
    STOREA = 355,                  /* STOREA  */
    DOWHILEC = 356,                /* DOWHILEC  */
    DOFORC = 357,                  /* DOFORC  */
    FORC = 358,                    /* FORC  */
    FVAR = 359,                    /* FVAR  */
    FOREVERC = 360,                /* FOREVERC  */
    CONTINUE = 361,                /* CONTINUE  */
    CHECK = 362,                   /* CHECK  */
    HCMNT = 363,                   /* HCMNT  */
    FMODE = 364,                   /* FMODE  */
    FOPEN = 365,                   /* FOPEN  */
    FCLOSE = 366,                  /* FCLOSE  */
    FEOF = 367,                    /* FEOF  */
    FPRINT = 368,                  /* FPRINT  */
    FPRINTLN = 369,                /* FPRINTLN  */
    FREAD = 370,                   /* FREAD  */
    MEML = 371,                    /* MEML  */
    ENUM = 372,                    /* ENUM  */
    ENUMV = 373,                   /* ENUMV  */
    VTYPE2 = 374,                  /* VTYPE2  */
    RANGE = 375,                   /* RANGE  */
    RTYPE2 = 376,                  /* RTYPE2  */
    OPDOT = 377,                   /* OPDOT  */
    RANGEV = 378,                  /* RANGEV  */
    OPLSQ = 379,                   /* OPLSQ  */
    OPRSQ = 380,                   /* OPRSQ  */
    ARRAY = 381,                   /* ARRAY  */
    BLANK = 382,                   /* BLANK  */
    PNFASM = 383,                  /* PNFASM  */
    LENGTH = 384,                  /* LENGTH  */
    DUP = 385,                     /* DUP  */
    THEN = 386,                    /* THEN  */
    ENDIF = 387,                   /* ENDIF  */
    DONEIF = 388,                  /* DONEIF  */
    ATOSP = 389,                   /* ATOSP  */
    SPTOA = 390,                   /* SPTOA  */
    FUNCTION = 391,                /* FUNCTION  */
    FUNCDEF = 392,                 /* FUNCDEF  */
    FUNCCALL = 393,                /* FUNCCALL  */
    FRET = 394,                    /* FRET  */
    FPARAMETER = 395,              /* FPARAMETER  */
    DEFAULTV = 396,                /* DEFAULTV  */
    DEFAULTV2 = 397,               /* DEFAULTV2  */
    UNTILC = 398,                  /* UNTILC  */
    UNLESS = 399,                  /* UNLESS  */
    DOUNTILC = 400,                /* DOUNTILC  */
    RUNOPOP = 401,                 /* RUNOPOP  */
    STRUCT = 402,                  /* STRUCT  */
    STRUCTVAR = 403,               /* STRUCTVAR  */
    UNION = 404,                   /* UNION  */
    UNIONVAR = 405,                /* UNIONVAR  */
    USE = 406,                     /* USE  */
    OTYPE = 407,                   /* OTYPE  */
    MODE = 408,                    /* MODE  */
    EXTMODE = 409,                 /* EXTMODE  */
    COPY = 410,                    /* COPY  */
    SEGMENT = 411,                 /* SEGMENT  */
    CETYPE = 412,                  /* CETYPE  */
    WHILE = 413,                   /* WHILE  */
    DOWHILE = 414,                 /* DOWHILE  */
    UNTIL = 415,                   /* UNTIL  */
    DOUNTIL = 416,                 /* DOUNTIL  */
    FOR = 417,                     /* FOR  */
    DOFOR = 418,                   /* DOFOR  */
    FOREVER = 419,                 /* FOREVER  */
    LOOP = 420,                    /* LOOP  */
    ENDLOOP = 421,                 /* ENDLOOP  */
    WHILEBC = 422,                 /* WHILEBC  */
    UNTILBC = 423,                 /* UNTILBC  */
    FORBC = 424,                   /* FORBC  */
    WHILEB = 425,                  /* WHILEB  */
    UNTILB = 426,                  /* UNTILB  */
    FORB = 427,                    /* FORB  */
    PBIN = 428,                    /* PBIN  */
    PPBIN = 429,                   /* PPBIN  */
    PLIB = 430,                    /* PLIB  */
    PINCLUDE = 431,                /* PINCLUDE  */
    PIMPORT = 432,                 /* PIMPORT  */
    PDEFINE = 433,                 /* PDEFINE  */
    PMACRO = 434,                  /* PMACRO  */
    PENDM = 435,                   /* PENDM  */
    PUNDEF = 436,                  /* PUNDEF  */
    PIFDEF = 437,                  /* PIFDEF  */
    PIFNDEF = 438,                 /* PIFNDEF  */
    PELSE = 439,                   /* PELSE  */
    PENDIF = 440,                  /* PENDIF  */
    PPDATE = 441,                  /* PPDATE  */
    PPTIME = 442,                  /* PPTIME  */
    PPLINE = 443,                  /* PPLINE  */
    PPFILE = 444,                  /* PPFILE  */
    PPCDATE = 445,                 /* PPCDATE  */
    PPCTIME = 446,                 /* PPCTIME  */
    PPINCLUDE = 447,               /* PPINCLUDE  */
    PPIMPORT = 448,                /* PPIMPORT  */
    PPDEFINE = 449,                /* PPDEFINE  */
    PPMACRO = 450,                 /* PPMACRO  */
    PPENDM = 451,                  /* PPENDM  */
    PPUNDEF = 452,                 /* PPUNDEF  */
    PPIFDEF = 453,                 /* PPIFDEF  */
    PPIFNDEF = 454,                /* PPIFNDEF  */
    PPELSE = 455,                  /* PPELSE  */
    PPENDIF = 456,                 /* PPENDIF  */
    PPPDATE = 457,                 /* PPPDATE  */
    PPPTIME = 458,                 /* PPPTIME  */
    PPPLINE = 459,                 /* PPPLINE  */
    PPPFILE = 460,                 /* PPPFILE  */
    PPPCDATE = 461,                /* PPPCDATE  */
    PPPCTIME = 462                 /* PPPCTIME  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEG = 3,                        /* NEG  */
  YYSYMBOL_OPCMP = 4,                      /* OPCMP  */
  YYSYMBOL_LEFTP = 5,                      /* LEFTP  */
  YYSYMBOL_RIGHTP = 6,                     /* RIGHTP  */
  YYSYMBOL_LEFTB = 7,                      /* LEFTB  */
  YYSYMBOL_RIGHTB = 8,                     /* RIGHTB  */
  YYSYMBOL_VOIDV = 9,                      /* VOIDV  */
  YYSYMBOL_BOOLEANV = 10,                  /* BOOLEANV  */
  YYSYMBOL_NUMBERV = 11,                   /* NUMBERV  */
  YYSYMBOL_CHARACTERV = 12,                /* CHARACTERV  */
  YYSYMBOL_STRINGV = 13,                   /* STRINGV  */
  YYSYMBOL_SEND = 14,                      /* SEND  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_OPEQUAL = 16,                   /* OPEQUAL  */
  YYSYMBOL_OPPLUS = 17,                    /* OPPLUS  */
  YYSYMBOL_OPMINUS = 18,                   /* OPMINUS  */
  YYSYMBOL_OPTIMES = 19,                   /* OPTIMES  */
  YYSYMBOL_OPDIV = 20,                     /* OPDIV  */
  YYSYMBOL_OPMODULUS = 21,                 /* OPMODULUS  */
  YYSYMBOL_OPPOWER = 22,                   /* OPPOWER  */
  YYSYMBOL_OPROOT = 23,                    /* OPROOT  */
  YYSYMBOL_OPINC = 24,                     /* OPINC  */
  YYSYMBOL_OPDEC = 25,                     /* OPDEC  */
  YYSYMBOL_OPAND = 26,                     /* OPAND  */
  YYSYMBOL_OPAMP = 27,                     /* OPAMP  */
  YYSYMBOL_OPOR = 28,                      /* OPOR  */
  YYSYMBOL_OPNOT = 29,                     /* OPNOT  */
  YYSYMBOL_OPQUES = 30,                    /* OPQUES  */
  YYSYMBOL_OPCOLON = 31,                   /* OPCOLON  */
  YYSYMBOL_OPSUB = 32,                     /* OPSUB  */
  YYSYMBOL_OPEQU = 33,                     /* OPEQU  */
  YYSYMBOL_OPNEQU = 34,                    /* OPNEQU  */
  YYSYMBOL_OPGTR = 35,                     /* OPGTR  */
  YYSYMBOL_OPLSS = 36,                     /* OPLSS  */
  YYSYMBOL_OPLEQU = 37,                    /* OPLEQU  */
  YYSYMBOL_OPGEQU = 38,                    /* OPGEQU  */
  YYSYMBOL_OPBTOR = 39,                    /* OPBTOR  */
  YYSYMBOL_OPBTXOR = 40,                   /* OPBTXOR  */
  YYSYMBOL_OPBTNOT = 41,                   /* OPBTNOT  */
  YYSYMBOL_OPBTSL = 42,                    /* OPBTSL  */
  YYSYMBOL_OPBTSR = 43,                    /* OPBTSR  */
  YYSYMBOL_OPSTR = 44,                     /* OPSTR  */
  YYSYMBOL_OPSTRTIMES = 45,                /* OPSTRTIMES  */
  YYSYMBOL_OPRUN = 46,                     /* OPRUN  */
  YYSYMBOL_ID = 47,                        /* ID  */
  YYSYMBOL_VAR = 48,                       /* VAR  */
  YYSYMBOL_PRINT = 49,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 50,                   /* PRINTLN  */
  YYSYMBOL_EPRINT = 51,                    /* EPRINT  */
  YYSYMBOL_EPRINTLN = 52,                  /* EPRINTLN  */
  YYSYMBOL_END = 53,                       /* END  */
  YYSYMBOL_ASM = 54,                       /* ASM  */
  YYSYMBOL_TYPE = 55,                      /* TYPE  */
  YYSYMBOL_READ = 56,                      /* READ  */
  YYSYMBOL_LOAD = 57,                      /* LOAD  */
  YYSYMBOL_LTYPE = 58,                     /* LTYPE  */
  YYSYMBOL_GOTO = 59,                      /* GOTO  */
  YYSYMBOL_GTYPE = 60,                     /* GTYPE  */
  YYSYMBOL_ST = 61,                        /* ST  */
  YYSYMBOL_PUSH = 62,                      /* PUSH  */
  YYSYMBOL_POP = 63,                       /* POP  */
  YYSYMBOL_TOP = 64,                       /* TOP  */
  YYSYMBOL_TYPEOF = 65,                    /* TYPEOF  */
  YYSYMBOL_RTYPE = 66,                     /* RTYPE  */
  YYSYMBOL_ATOC = 67,                      /* ATOC  */
  YYSYMBOL_SWITCH = 68,                    /* SWITCH  */
  YYSYMBOL_CSWITCH = 69,                   /* CSWITCH  */
  YYSYMBOL_CRASH = 70,                     /* CRASH  */
  YYSYMBOL_VERSION = 71,                   /* VERSION  */
  YYSYMBOL_VTYPE = 72,                     /* VTYPE  */
  YYSYMBOL_HALT = 73,                      /* HALT  */
  YYSYMBOL_MODT = 74,                      /* MODT  */
  YYSYMBOL_RETURN = 75,                    /* RETURN  */
  YYSYMBOL_GOSUB = 76,                     /* GOSUB  */
  YYSYMBOL_SUB = 77,                       /* SUB  */
  YYSYMBOL_EVENT = 78,                     /* EVENT  */
  YYSYMBOL_STYPE = 79,                     /* STYPE  */
  YYSYMBOL_ATYPE = 80,                     /* ATYPE  */
  YYSYMBOL_CTYPE = 81,                     /* CTYPE  */
  YYSYMBOL_CMTYPE = 82,                    /* CMTYPE  */
  YYSYMBOL_BFMODEC = 83,                   /* BFMODEC  */
  YYSYMBOL_FMODEC = 84,                    /* FMODEC  */
  YYSYMBOL_UNREGISTER = 85,                /* UNREGISTER  */
  YYSYMBOL_REGISTER = 86,                  /* REGISTER  */
  YYSYMBOL_REREGISTER = 87,                /* REREGISTER  */
  YYSYMBOL_STORE = 88,                     /* STORE  */
  YYSYMBOL_IF = 89,                        /* IF  */
  YYSYMBOL_ELSE = 90,                      /* ELSE  */
  YYSYMBOL_CASE = 91,                      /* CASE  */
  YYSYMBOL_CCASE = 92,                     /* CCASE  */
  YYSYMBOL_DEFAULT = 93,                   /* DEFAULT  */
  YYSYMBOL_CDEFAULT = 94,                  /* CDEFAULT  */
  YYSYMBOL_BREAK = 95,                     /* BREAK  */
  YYSYMBOL_LABEL = 96,                     /* LABEL  */
  YYSYMBOL_WHILEC = 97,                    /* WHILEC  */
  YYSYMBOL_ADDRESSOF = 98,                 /* ADDRESSOF  */
  YYSYMBOL_ADD2V = 99,                     /* ADD2V  */
  YYSYMBOL_STOREA = 100,                   /* STOREA  */
  YYSYMBOL_DOWHILEC = 101,                 /* DOWHILEC  */
  YYSYMBOL_DOFORC = 102,                   /* DOFORC  */
  YYSYMBOL_FORC = 103,                     /* FORC  */
  YYSYMBOL_FVAR = 104,                     /* FVAR  */
  YYSYMBOL_FOREVERC = 105,                 /* FOREVERC  */
  YYSYMBOL_CONTINUE = 106,                 /* CONTINUE  */
  YYSYMBOL_CHECK = 107,                    /* CHECK  */
  YYSYMBOL_HCMNT = 108,                    /* HCMNT  */
  YYSYMBOL_FMODE = 109,                    /* FMODE  */
  YYSYMBOL_FOPEN = 110,                    /* FOPEN  */
  YYSYMBOL_FCLOSE = 111,                   /* FCLOSE  */
  YYSYMBOL_FEOF = 112,                     /* FEOF  */
  YYSYMBOL_FPRINT = 113,                   /* FPRINT  */
  YYSYMBOL_FPRINTLN = 114,                 /* FPRINTLN  */
  YYSYMBOL_FREAD = 115,                    /* FREAD  */
  YYSYMBOL_MEML = 116,                     /* MEML  */
  YYSYMBOL_ENUM = 117,                     /* ENUM  */
  YYSYMBOL_ENUMV = 118,                    /* ENUMV  */
  YYSYMBOL_VTYPE2 = 119,                   /* VTYPE2  */
  YYSYMBOL_RANGE = 120,                    /* RANGE  */
  YYSYMBOL_RTYPE2 = 121,                   /* RTYPE2  */
  YYSYMBOL_OPDOT = 122,                    /* OPDOT  */
  YYSYMBOL_RANGEV = 123,                   /* RANGEV  */
  YYSYMBOL_OPLSQ = 124,                    /* OPLSQ  */
  YYSYMBOL_OPRSQ = 125,                    /* OPRSQ  */
  YYSYMBOL_ARRAY = 126,                    /* ARRAY  */
  YYSYMBOL_BLANK = 127,                    /* BLANK  */
  YYSYMBOL_PNFASM = 128,                   /* PNFASM  */
  YYSYMBOL_LENGTH = 129,                   /* LENGTH  */
  YYSYMBOL_DUP = 130,                      /* DUP  */
  YYSYMBOL_THEN = 131,                     /* THEN  */
  YYSYMBOL_ENDIF = 132,                    /* ENDIF  */
  YYSYMBOL_DONEIF = 133,                   /* DONEIF  */
  YYSYMBOL_ATOSP = 134,                    /* ATOSP  */
  YYSYMBOL_SPTOA = 135,                    /* SPTOA  */
  YYSYMBOL_FUNCTION = 136,                 /* FUNCTION  */
  YYSYMBOL_FUNCDEF = 137,                  /* FUNCDEF  */
  YYSYMBOL_FUNCCALL = 138,                 /* FUNCCALL  */
  YYSYMBOL_FRET = 139,                     /* FRET  */
  YYSYMBOL_FPARAMETER = 140,               /* FPARAMETER  */
  YYSYMBOL_DEFAULTV = 141,                 /* DEFAULTV  */
  YYSYMBOL_DEFAULTV2 = 142,                /* DEFAULTV2  */
  YYSYMBOL_UNTILC = 143,                   /* UNTILC  */
  YYSYMBOL_UNLESS = 144,                   /* UNLESS  */
  YYSYMBOL_DOUNTILC = 145,                 /* DOUNTILC  */
  YYSYMBOL_RUNOPOP = 146,                  /* RUNOPOP  */
  YYSYMBOL_STRUCT = 147,                   /* STRUCT  */
  YYSYMBOL_STRUCTVAR = 148,                /* STRUCTVAR  */
  YYSYMBOL_UNION = 149,                    /* UNION  */
  YYSYMBOL_UNIONVAR = 150,                 /* UNIONVAR  */
  YYSYMBOL_USE = 151,                      /* USE  */
  YYSYMBOL_OTYPE = 152,                    /* OTYPE  */
  YYSYMBOL_MODE = 153,                     /* MODE  */
  YYSYMBOL_EXTMODE = 154,                  /* EXTMODE  */
  YYSYMBOL_COPY = 155,                     /* COPY  */
  YYSYMBOL_SEGMENT = 156,                  /* SEGMENT  */
  YYSYMBOL_CETYPE = 157,                   /* CETYPE  */
  YYSYMBOL_WHILE = 158,                    /* WHILE  */
  YYSYMBOL_DOWHILE = 159,                  /* DOWHILE  */
  YYSYMBOL_UNTIL = 160,                    /* UNTIL  */
  YYSYMBOL_DOUNTIL = 161,                  /* DOUNTIL  */
  YYSYMBOL_FOR = 162,                      /* FOR  */
  YYSYMBOL_DOFOR = 163,                    /* DOFOR  */
  YYSYMBOL_FOREVER = 164,                  /* FOREVER  */
  YYSYMBOL_LOOP = 165,                     /* LOOP  */
  YYSYMBOL_ENDLOOP = 166,                  /* ENDLOOP  */
  YYSYMBOL_WHILEBC = 167,                  /* WHILEBC  */
  YYSYMBOL_UNTILBC = 168,                  /* UNTILBC  */
  YYSYMBOL_FORBC = 169,                    /* FORBC  */
  YYSYMBOL_WHILEB = 170,                   /* WHILEB  */
  YYSYMBOL_UNTILB = 171,                   /* UNTILB  */
  YYSYMBOL_FORB = 172,                     /* FORB  */
  YYSYMBOL_PBIN = 173,                     /* PBIN  */
  YYSYMBOL_PPBIN = 174,                    /* PPBIN  */
  YYSYMBOL_PLIB = 175,                     /* PLIB  */
  YYSYMBOL_PINCLUDE = 176,                 /* PINCLUDE  */
  YYSYMBOL_PIMPORT = 177,                  /* PIMPORT  */
  YYSYMBOL_PDEFINE = 178,                  /* PDEFINE  */
  YYSYMBOL_PMACRO = 179,                   /* PMACRO  */
  YYSYMBOL_PENDM = 180,                    /* PENDM  */
  YYSYMBOL_PUNDEF = 181,                   /* PUNDEF  */
  YYSYMBOL_PIFDEF = 182,                   /* PIFDEF  */
  YYSYMBOL_PIFNDEF = 183,                  /* PIFNDEF  */
  YYSYMBOL_PELSE = 184,                    /* PELSE  */
  YYSYMBOL_PENDIF = 185,                   /* PENDIF  */
  YYSYMBOL_PPDATE = 186,                   /* PPDATE  */
  YYSYMBOL_PPTIME = 187,                   /* PPTIME  */
  YYSYMBOL_PPLINE = 188,                   /* PPLINE  */
  YYSYMBOL_PPFILE = 189,                   /* PPFILE  */
  YYSYMBOL_PPCDATE = 190,                  /* PPCDATE  */
  YYSYMBOL_PPCTIME = 191,                  /* PPCTIME  */
  YYSYMBOL_PPINCLUDE = 192,                /* PPINCLUDE  */
  YYSYMBOL_PPIMPORT = 193,                 /* PPIMPORT  */
  YYSYMBOL_PPDEFINE = 194,                 /* PPDEFINE  */
  YYSYMBOL_PPMACRO = 195,                  /* PPMACRO  */
  YYSYMBOL_PPENDM = 196,                   /* PPENDM  */
  YYSYMBOL_PPUNDEF = 197,                  /* PPUNDEF  */
  YYSYMBOL_PPIFDEF = 198,                  /* PPIFDEF  */
  YYSYMBOL_PPIFNDEF = 199,                 /* PPIFNDEF  */
  YYSYMBOL_PPELSE = 200,                   /* PPELSE  */
  YYSYMBOL_PPENDIF = 201,                  /* PPENDIF  */
  YYSYMBOL_PPPDATE = 202,                  /* PPPDATE  */
  YYSYMBOL_PPPTIME = 203,                  /* PPPTIME  */
  YYSYMBOL_PPPLINE = 204,                  /* PPPLINE  */
  YYSYMBOL_PPPFILE = 205,                  /* PPPFILE  */
  YYSYMBOL_PPPCDATE = 206,                 /* PPPCDATE  */
  YYSYMBOL_PPPCTIME = 207,                 /* PPPCTIME  */
  YYSYMBOL_208_n_ = 208,                   /* "\n"  */
  YYSYMBOL_209_ = 209,                     /* "<"  */
  YYSYMBOL_210_ = 210,                     /* ">"  */
  YYSYMBOL_YYACCEPT = 211,                 /* $accept  */
  YYSYMBOL_input = 212,                    /* input  */
  YYSYMBOL_line = 213,                     /* line  */
  YYSYMBOL_214_1 = 214,                    /* $@1  */
  YYSYMBOL_statement = 215,                /* statement  */
  YYSYMBOL_216_2 = 216,                    /* $@2  */
  YYSYMBOL_stmt = 217,                     /* stmt  */
  YYSYMBOL_expression_statement = 218,     /* expression_statement  */
  YYSYMBOL_declaration_statement = 219,    /* declaration_statement  */
  YYSYMBOL_command_statement = 220,        /* command_statement  */
  YYSYMBOL_label_statement = 221,          /* label_statement  */
  YYSYMBOL_control_statement = 222,        /* control_statement  */
  YYSYMBOL_if_statement = 223,             /* if_statement  */
  YYSYMBOL_224_3 = 224,                    /* $@3  */
  YYSYMBOL_225_4 = 225,                    /* $@4  */
  YYSYMBOL_226_5 = 226,                    /* $@5  */
  YYSYMBOL_227_6 = 227,                    /* $@6  */
  YYSYMBOL_228_7 = 228,                    /* $@7  */
  YYSYMBOL_unless_statement = 229,         /* unless_statement  */
  YYSYMBOL_230_8 = 230,                    /* $@8  */
  YYSYMBOL_231_9 = 231,                    /* $@9  */
  YYSYMBOL_232_10 = 232,                   /* $@10  */
  YYSYMBOL_233_11 = 233,                   /* $@11  */
  YYSYMBOL_234_12 = 234,                   /* $@12  */
  YYSYMBOL_opt_else = 235,                 /* opt_else  */
  YYSYMBOL_236_13 = 236,                   /* $@13  */
  YYSYMBOL_eif = 237,                      /* eif  */
  YYSYMBOL_switch_statement = 238,         /* switch_statement  */
  YYSYMBOL_239_14 = 239,                   /* $@14  */
  YYSYMBOL_240_15 = 240,                   /* $@15  */
  YYSYMBOL_241_16 = 241,                   /* $@16  */
  YYSYMBOL_242_17 = 242,                   /* $@17  */
  YYSYMBOL_243_18 = 243,                   /* $@18  */
  YYSYMBOL_244_19 = 244,                   /* $@19  */
  YYSYMBOL_245_20 = 245,                   /* $@20  */
  YYSYMBOL_case_statements = 246,          /* case_statements  */
  YYSYMBOL_247_21 = 247,                   /* $@21  */
  YYSYMBOL_case_statement = 248,           /* case_statement  */
  YYSYMBOL_249_22 = 249,                   /* $@22  */
  YYSYMBOL_opt_default_statement = 250,    /* opt_default_statement  */
  YYSYMBOL_251_23 = 251,                   /* $@23  */
  YYSYMBOL_case_statements2 = 252,         /* case_statements2  */
  YYSYMBOL_253_24 = 253,                   /* $@24  */
  YYSYMBOL_case_statement2 = 254,          /* case_statement2  */
  YYSYMBOL_255_25 = 255,                   /* $@25  */
  YYSYMBOL_256_26 = 256,                   /* $@26  */
  YYSYMBOL_opt_default_statement2 = 257,   /* opt_default_statement2  */
  YYSYMBOL_258_27 = 258,                   /* $@27  */
  YYSYMBOL_loop_statement = 259,           /* loop_statement  */
  YYSYMBOL_260_28 = 260,                   /* $@28  */
  YYSYMBOL_261_29 = 261,                   /* $@29  */
  YYSYMBOL_while_loop = 262,               /* while_loop  */
  YYSYMBOL_whilec_loop1 = 263,             /* whilec_loop1  */
  YYSYMBOL_264_30 = 264,                   /* $@30  */
  YYSYMBOL_265_31 = 265,                   /* $@31  */
  YYSYMBOL_266_32 = 266,                   /* $@32  */
  YYSYMBOL_while_loop1 = 267,              /* while_loop1  */
  YYSYMBOL_268_33 = 268,                   /* $@33  */
  YYSYMBOL_269_34 = 269,                   /* $@34  */
  YYSYMBOL_270_35 = 270,                   /* $@35  */
  YYSYMBOL_whileb_loop = 271,              /* whileb_loop  */
  YYSYMBOL_whilebc_loop1 = 272,            /* whilebc_loop1  */
  YYSYMBOL_273_36 = 273,                   /* $@36  */
  YYSYMBOL_274_37 = 274,                   /* $@37  */
  YYSYMBOL_275_38 = 275,                   /* $@38  */
  YYSYMBOL_276_39 = 276,                   /* $@39  */
  YYSYMBOL_277_40 = 277,                   /* $@40  */
  YYSYMBOL_278_41 = 278,                   /* $@41  */
  YYSYMBOL_whileb_loop1 = 279,             /* whileb_loop1  */
  YYSYMBOL_280_42 = 280,                   /* $@42  */
  YYSYMBOL_281_43 = 281,                   /* $@43  */
  YYSYMBOL_282_44 = 282,                   /* $@44  */
  YYSYMBOL_283_45 = 283,                   /* $@45  */
  YYSYMBOL_284_46 = 284,                   /* $@46  */
  YYSYMBOL_until_loop = 285,               /* until_loop  */
  YYSYMBOL_untilc_loop1 = 286,             /* untilc_loop1  */
  YYSYMBOL_287_47 = 287,                   /* $@47  */
  YYSYMBOL_288_48 = 288,                   /* $@48  */
  YYSYMBOL_289_49 = 289,                   /* $@49  */
  YYSYMBOL_until_loop1 = 290,              /* until_loop1  */
  YYSYMBOL_291_50 = 291,                   /* $@50  */
  YYSYMBOL_292_51 = 292,                   /* $@51  */
  YYSYMBOL_293_52 = 293,                   /* $@52  */
  YYSYMBOL_untilb_loop = 294,              /* untilb_loop  */
  YYSYMBOL_untilbc_loop1 = 295,            /* untilbc_loop1  */
  YYSYMBOL_296_53 = 296,                   /* $@53  */
  YYSYMBOL_297_54 = 297,                   /* $@54  */
  YYSYMBOL_298_55 = 298,                   /* $@55  */
  YYSYMBOL_299_56 = 299,                   /* $@56  */
  YYSYMBOL_300_57 = 300,                   /* $@57  */
  YYSYMBOL_301_58 = 301,                   /* $@58  */
  YYSYMBOL_untilb_loop1 = 302,             /* untilb_loop1  */
  YYSYMBOL_303_59 = 303,                   /* $@59  */
  YYSYMBOL_304_60 = 304,                   /* $@60  */
  YYSYMBOL_305_61 = 305,                   /* $@61  */
  YYSYMBOL_306_62 = 306,                   /* $@62  */
  YYSYMBOL_307_63 = 307,                   /* $@63  */
  YYSYMBOL_for_loop = 308,                 /* for_loop  */
  YYSYMBOL_309_64 = 309,                   /* $@64  */
  YYSYMBOL_310_65 = 310,                   /* $@65  */
  YYSYMBOL_311_66 = 311,                   /* $@66  */
  YYSYMBOL_312_67 = 312,                   /* $@67  */
  YYSYMBOL_313_68 = 313,                   /* $@68  */
  YYSYMBOL_314_69 = 314,                   /* $@69  */
  YYSYMBOL_315_70 = 315,                   /* $@70  */
  YYSYMBOL_316_71 = 316,                   /* $@71  */
  YYSYMBOL_317_72 = 317,                   /* $@72  */
  YYSYMBOL_forb_loop = 318,                /* forb_loop  */
  YYSYMBOL_319_73 = 319,                   /* $@73  */
  YYSYMBOL_320_74 = 320,                   /* $@74  */
  YYSYMBOL_321_75 = 321,                   /* $@75  */
  YYSYMBOL_322_76 = 322,                   /* $@76  */
  YYSYMBOL_323_77 = 323,                   /* $@77  */
  YYSYMBOL_324_78 = 324,                   /* $@78  */
  YYSYMBOL_forever_loop = 325,             /* forever_loop  */
  YYSYMBOL_326_79 = 326,                   /* $@79  */
  YYSYMBOL_statement_block = 327,          /* statement_block  */
  YYSYMBOL_statements = 328,               /* statements  */
  YYSYMBOL_expression = 329,               /* expression  */
  YYSYMBOL_void_expression = 330,          /* void_expression  */
  YYSYMBOL_boolean_expression = 331,       /* boolean_expression  */
  YYSYMBOL_number_expression = 332,        /* number_expression  */
  YYSYMBOL_character_expression = 333,     /* character_expression  */
  YYSYMBOL_string_expression = 334,        /* string_expression  */
  YYSYMBOL_id_expression = 335,            /* id_expression  */
  YYSYMBOL_relational_expression = 336,    /* relational_expression  */
  YYSYMBOL_337_80 = 337,                   /* @80  */
  YYSYMBOL_mixed_expression = 338,         /* mixed_expression  */
  YYSYMBOL_function_expression = 339,      /* function_expression  */
  YYSYMBOL_function_command = 340,         /* function_command  */
  YYSYMBOL_341_81 = 341,                   /* $@81  */
  YYSYMBOL_342_82 = 342,                   /* $@82  */
  YYSYMBOL_343_83 = 343,                   /* $@83  */
  YYSYMBOL_344_84 = 344,                   /* $@84  */
  YYSYMBOL_345_85 = 345,                   /* $@85  */
  YYSYMBOL_346_86 = 346,                   /* $@86  */
  YYSYMBOL_actual_function_parameters = 347, /* actual_function_parameters  */
  YYSYMBOL_dv = 348,                       /* dv  */
  YYSYMBOL_opt_expressions = 349,          /* opt_expressions  */
  YYSYMBOL_opt_expression = 350,           /* opt_expression  */
  YYSYMBOL_declaration = 351,              /* declaration  */
  YYSYMBOL_variable_declaration = 352,     /* variable_declaration  */
  YYSYMBOL_enumv_declaration = 353,        /* enumv_declaration  */
  YYSYMBOL_rangev_declaration = 354,       /* rangev_declaration  */
  YYSYMBOL_array_declaration = 355,        /* array_declaration  */
  YYSYMBOL_enum_declaration = 356,         /* enum_declaration  */
  YYSYMBOL_357_88 = 357,                   /* $@88  */
  YYSYMBOL_358_89 = 358,                   /* $@89  */
  YYSYMBOL_enum_strings = 359,             /* enum_strings  */
  YYSYMBOL_range_declaration = 360,        /* range_declaration  */
  YYSYMBOL_struct_declaration = 361,       /* struct_declaration  */
  YYSYMBOL_362_90 = 362,                   /* $@90  */
  YYSYMBOL_struct_body = 363,              /* struct_body  */
  YYSYMBOL_struct_var_declarations = 364,  /* struct_var_declarations  */
  YYSYMBOL_struct_var_declarations2 = 365, /* struct_var_declarations2  */
  YYSYMBOL_366_91 = 366,                   /* $@91  */
  YYSYMBOL_struct_declaration2 = 367,      /* struct_declaration2  */
  YYSYMBOL_struct_var_declaration3 = 368,  /* struct_var_declaration3  */
  YYSYMBOL_union_declaration = 369,        /* union_declaration  */
  YYSYMBOL_370_92 = 370,                   /* $@92  */
  YYSYMBOL_union_body = 371,               /* union_body  */
  YYSYMBOL_union_var_declarations = 372,   /* union_var_declarations  */
  YYSYMBOL_union_var_declarations2 = 373,  /* union_var_declarations2  */
  YYSYMBOL_374_93 = 374,                   /* $@93  */
  YYSYMBOL_union_declaration2 = 375,       /* union_declaration2  */
  YYSYMBOL_union_var_declaration3 = 376,   /* union_var_declaration3  */
  YYSYMBOL_label_declaration = 377,        /* label_declaration  */
  YYSYMBOL_function_declaration = 378,     /* function_declaration  */
  YYSYMBOL_379_94 = 379,                   /* $@94  */
  YYSYMBOL_nothing = 380,                  /* nothing  */
  YYSYMBOL_parameter_declaration = 381,    /* parameter_declaration  */
  YYSYMBOL_parameter_declaration2 = 382,   /* parameter_declaration2  */
  YYSYMBOL_parameter_declaration5 = 383,   /* parameter_declaration5  */
  YYSYMBOL_parameter_declaration6 = 384,   /* parameter_declaration6  */
  YYSYMBOL_opt_var = 385,                  /* opt_var  */
  YYSYMBOL_opt_var2 = 386,                 /* opt_var2  */
  YYSYMBOL_opt_default_value = 387,        /* opt_default_value  */
  YYSYMBOL_dvalue = 388,                   /* dvalue  */
  YYSYMBOL_optdefaultv = 389,              /* optdefaultv  */
  YYSYMBOL_opt_var5 = 390,                 /* opt_var5  */
  YYSYMBOL_opt_var6 = 391,                 /* opt_var6  */
  YYSYMBOL_function_declaration2 = 392,    /* function_declaration2  */
  YYSYMBOL_393_95 = 393,                   /* $@95  */
  YYSYMBOL_394_96 = 394,                   /* $@96  */
  YYSYMBOL_function_body = 395,            /* function_body  */
  YYSYMBOL_vars = 396,                     /* vars  */
  YYSYMBOL_vars2 = 397,                    /* vars2  */
  YYSYMBOL_vars3 = 398,                    /* vars3  */
  YYSYMBOL_vars5 = 399,                    /* vars5  */
  YYSYMBOL_vars6 = 400,                    /* vars6  */
  YYSYMBOL_command = 401,                  /* command  */
  YYSYMBOL_print_command = 402,            /* print_command  */
  YYSYMBOL_read_command = 403,             /* read_command  */
  YYSYMBOL_end_command = 404,              /* end_command  */
  YYSYMBOL_asm_command = 405,              /* asm_command  */
  YYSYMBOL_load_command = 406,             /* load_command  */
  YYSYMBOL_407_97 = 407,                   /* $@97  */
  YYSYMBOL_408_98 = 408,                   /* $@98  */
  YYSYMBOL_409_99 = 409,                   /* $@99  */
  YYSYMBOL_410_100 = 410,                  /* $@100  */
  YYSYMBOL_goto_command = 411,             /* goto_command  */
  YYSYMBOL_operator_command = 412,         /* operator_command  */
  YYSYMBOL_top_command = 413,              /* top_command  */
  YYSYMBOL_414_101 = 414,                  /* $@101  */
  YYSYMBOL_415_102 = 415,                  /* $@102  */
  YYSYMBOL_416_103 = 416,                  /* $@103  */
  YYSYMBOL_417_104 = 417,                  /* $@104  */
  YYSYMBOL_st_command = 418,               /* st_command  */
  YYSYMBOL_stack_command = 419,            /* stack_command  */
  YYSYMBOL_typeof_command = 420,           /* typeof_command  */
  YYSYMBOL_rm_command = 421,               /* rm_command  */
  YYSYMBOL_crash_command = 422,            /* crash_command  */
  YYSYMBOL_version_command = 423,          /* version_command  */
  YYSYMBOL_halt_command = 424,             /* halt_command  */
  YYSYMBOL_modt_command = 425,             /* modt_command  */
  YYSYMBOL_subroutine_command = 426,       /* subroutine_command  */
  YYSYMBOL_register_command = 427,         /* register_command  */
  YYSYMBOL_store_command = 428,            /* store_command  */
  YYSYMBOL_break_command = 429,            /* break_command  */
  YYSYMBOL_address_command = 430,          /* address_command  */
  YYSYMBOL_add2v_command = 431,            /* add2v_command  */
  YYSYMBOL_continue_command = 432,         /* continue_command  */
  YYSYMBOL_check_command = 433,            /* check_command  */
  YYSYMBOL_comment_command = 434,          /* comment_command  */
  YYSYMBOL_file_command = 435,             /* file_command  */
  YYSYMBOL_meml_command = 436,             /* meml_command  */
  YYSYMBOL_pnfasm_command = 437,           /* pnfasm_command  */
  YYSYMBOL_array_length_command = 438,     /* array_length_command  */
  YYSYMBOL_dup_command = 439,              /* dup_command  */
  YYSYMBOL_fret_command = 440,             /* fret_command  */
  YYSYMBOL_parameter_command = 441,        /* parameter_command  */
  YYSYMBOL_psig = 442,                     /* psig  */
  YYSYMBOL_443_105 = 443,                  /* $@105  */
  YYSYMBOL_psig2 = 444,                    /* psig2  */
  YYSYMBOL_445_106 = 445,                  /* $@106  */
  YYSYMBOL_signature = 446,                /* signature  */
  YYSYMBOL_signature2 = 447,               /* signature2  */
  YYSYMBOL_struct_command = 448,           /* struct_command  */
  YYSYMBOL_union_command = 449,            /* union_command  */
  YYSYMBOL_copy_command = 450,             /* copy_command  */
  YYSYMBOL_segment_command = 451,          /* segment_command  */
  YYSYMBOL_pp_directive = 452,             /* pp_directive  */
  YYSYMBOL_pp_statement = 453              /* pp_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   1973

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  211
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  243
/* YYNRULES -- Number of rules.  */
#define YYNRULES  642
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   465


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1018,  1018,  1019,  1022,  1022,  1027,  1028,  1031,  1031,
    1036,  1039,  1041,  1043,  1045,  1047,  1049,  1051,  1054,  1055,
    1058,  1065,  1072,  1079,  1112,  1120,  1130,  1136,  1142,  1147,
    1158,  1164,  1173,  1180,  1185,  1157,  1201,  1209,  1218,  1225,
    1230,  1200,  1245,  1246,  1245,  1267,  1271,  1310,  1339,  1344,
    1270,  1356,  1371,  1377,  1355,  1391,  1391,  1396,  1400,  1399,
    1443,  1444,  1443,  1454,  1454,  1459,  1463,  1494,  1462,  1509,
    1510,  1509,  1521,  1521,  1530,  1535,  1540,  1545,  1550,  1556,
    1555,  1574,  1575,  1579,  1589,  1595,  1578,  1617,  1628,  1634,
    1616,  1654,  1655,  1659,  1669,  1676,  1684,  1690,  1699,  1659,
    1713,  1722,  1730,  1738,  1744,  1712,  1758,  1759,  1764,  1774,
    1780,  1762,  1806,  1816,  1822,  1804,  1843,  1844,  1848,  1858,
    1865,  1873,  1879,  1888,  1848,  1905,  1914,  1922,  1930,  1936,
    1904,  1951,  1955,  1965,  1973,  1983,  1951,  2001,  2011,  2019,
    2027,  2000,  2046,  2059,  2068,  2074,  2083,  2093,  2045,  2109,
    2108,  2129,  2136,  2141,  2148,  2149,  2157,  2159,  2161,  2163,
    2165,  2167,  2169,  2174,  2184,  2187,  2203,  2217,  2233,  2249,
    2252,  2266,  2272,  2278,  2284,  2290,  2296,  2304,  2311,  2318,
    2324,  2330,  2336,  2342,  2350,  2359,  2367,  2374,  2382,  2390,
    2394,  2407,  2414,  2421,  2428,  2434,  2441,  2448,  2455,  2461,
    2467,  2473,  2479,  2483,  2496,  2521,  2528,  2532,  2603,  2643,
    2680,  2757,  2836,  2916,  2954,  2992,  3030,  3068,  3081,  3119,
    3157,  3185,  3213,  3241,  3269,  3272,  3283,  3294,  3305,  3316,
    3328,  3327,  3347,  3373,  3374,  3423,  3472,  3521,  3570,  3612,
    3654,  3696,  3738,  3780,  3822,  3864,  3906,  3948,  3990,  4032,
    4074,  4116,  4158,  4200,  4242,  4284,  4326,  4368,  4410,  4452,
    4494,  4536,  4578,  4642,  4706,  4751,  4796,  4841,  4886,  4931,
    4976,  5021,  5066,  5111,  5156,  5201,  5246,  5291,  5336,  5381,
    5426,  5471,  5516,  5553,  5598,  5643,  5688,  5733,  5791,  5851,
    5855,  5862,  5866,  5873,  5878,  5897,  5907,  5861,  5922,  5929,
    5940,  5983,  6026,  6152,  6297,  6432,  6437,  6442,  6447,  6452,
    6457,  6462,  6467,  6472,  6477,  6484,  6542,  6645,  6680,  6685,
    6690,  6697,  6709,  6724,  6740,  6752,  6760,  6751,  6774,  6782,
    6788,  6814,  6813,  6820,  6828,  6829,  6833,  6832,  6839,  6846,
    6893,  6892,  6899,  6907,  6908,  6912,  6911,  6918,  6925,  6971,
    6995,  7018,  7042,  7043,  7047,  7046,  7092,  7094,  7187,  7299,
    7401,  7517,  7562,  7621,  7666,  7725,  7743,  7751,  7769,  7777,
    7777,  7791,  7798,  7798,  7805,  7823,  7831,  7849,  7858,  7876,
    7857,  7896,  7901,  7909,  7995,  8077,  8081,  8129,  8179,  8182,
    8244,  8451,  8455,  8503,  8553,  8557,  8605,  8657,  8662,  8667,
    8672,  8677,  8682,  8687,  8692,  8697,  8702,  8707,  8712,  8717,
    8722,  8727,  8732,  8737,  8742,  8747,  8752,  8757,  8762,  8767,
    8772,  8777,  8782,  8787,  8792,  8797,  8802,  8807,  8808,  8809,
    8810,  8811,  8815,  8821,  8867,  8878,  8884,  8930,  8941,  8947,
    8993,  8999,  9045,  9050,  9096,  9102,  9148,  9160,  9219,  9292,
    9300,  9309,  9453,  9546,  9574,  9585,  9602,  9614,  9626,  9808,
    9827,  9841,  9854,  9868,  9878,  9889,  9888,  9922,  9921,  9955,
    9954,  9988,  9987, 10020, 10045, 10070, 10083, 10133, 10153, 10258,
   10264, 10270, 10276, 10282, 10288, 10294, 10300, 10306, 10312, 10318,
   10324, 10330, 10336, 10342, 10348, 10354, 10360, 10366, 10372, 10378,
   10384, 10390, 10396, 10402, 10408, 10414, 10420, 10430, 10440, 10446,
   10452, 10458, 10464, 10470, 10476, 10482, 10488, 10494, 10500, 10506,
   10512, 10518, 10524, 10530, 10536, 10542, 10548, 10549, 10553, 10559,
   10582, 10593, 10599, 10608, 10581, 10628, 10636, 10642, 10650, 10663,
   10669, 10673, 10677, 10685, 10693, 10708, 10717, 10727, 10735, 10750,
   10756, 10762, 10893, 10927, 11046, 11270, 11291, 11328, 11337, 11374,
   11382, 11396, 11409, 11419, 11431, 11449, 11477, 11555, 11565, 11584,
   11647, 11698, 11749, 11800, 11819, 11841, 11874, 11891, 11908, 11918,
   11928, 11939, 11949, 11968, 11974, 11975, 11979, 11978, 12033, 12032,
   12089, 12095, 12101, 12105, 12111, 12115, 12121, 12127, 12131, 12135,
   12148, 12152, 12156, 12160, 12166, 12172, 12178, 12186, 12192, 12198,
   12204, 12210, 12217, 12223, 12229, 12235, 12241, 12247, 12253, 12259,
   12265, 12271, 12277, 12283, 12289, 12295, 12301, 12307, 12313, 12319,
   12326, 12332, 12338, 12344, 12350, 12356, 12362, 12368, 12374, 12380,
   12386, 12392, 12398
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NEG", "OPCMP",
  "LEFTP", "RIGHTP", "LEFTB", "RIGHTB", "VOIDV", "BOOLEANV", "NUMBERV",
  "CHARACTERV", "STRINGV", "SEND", "COMMA", "OPEQUAL", "OPPLUS", "OPMINUS",
  "OPTIMES", "OPDIV", "OPMODULUS", "OPPOWER", "OPROOT", "OPINC", "OPDEC",
  "OPAND", "OPAMP", "OPOR", "OPNOT", "OPQUES", "OPCOLON", "OPSUB", "OPEQU",
  "OPNEQU", "OPGTR", "OPLSS", "OPLEQU", "OPGEQU", "OPBTOR", "OPBTXOR",
  "OPBTNOT", "OPBTSL", "OPBTSR", "OPSTR", "OPSTRTIMES", "OPRUN", "ID",
  "VAR", "PRINT", "PRINTLN", "EPRINT", "EPRINTLN", "END", "ASM", "TYPE",
  "READ", "LOAD", "LTYPE", "GOTO", "GTYPE", "ST", "PUSH", "POP", "TOP",
  "TYPEOF", "RTYPE", "ATOC", "SWITCH", "CSWITCH", "CRASH", "VERSION",
  "VTYPE", "HALT", "MODT", "RETURN", "GOSUB", "SUB", "EVENT", "STYPE",
  "ATYPE", "CTYPE", "CMTYPE", "BFMODEC", "FMODEC", "UNREGISTER",
  "REGISTER", "REREGISTER", "STORE", "IF", "ELSE", "CASE", "CCASE",
  "DEFAULT", "CDEFAULT", "BREAK", "LABEL", "WHILEC", "ADDRESSOF", "ADD2V",
  "STOREA", "DOWHILEC", "DOFORC", "FORC", "FVAR", "FOREVERC", "CONTINUE",
  "CHECK", "HCMNT", "FMODE", "FOPEN", "FCLOSE", "FEOF", "FPRINT",
  "FPRINTLN", "FREAD", "MEML", "ENUM", "ENUMV", "VTYPE2", "RANGE",
  "RTYPE2", "OPDOT", "RANGEV", "OPLSQ", "OPRSQ", "ARRAY", "BLANK",
  "PNFASM", "LENGTH", "DUP", "THEN", "ENDIF", "DONEIF", "ATOSP", "SPTOA",
  "FUNCTION", "FUNCDEF", "FUNCCALL", "FRET", "FPARAMETER", "DEFAULTV",
  "DEFAULTV2", "UNTILC", "UNLESS", "DOUNTILC", "RUNOPOP", "STRUCT",
  "STRUCTVAR", "UNION", "UNIONVAR", "USE", "OTYPE", "MODE", "EXTMODE",
  "COPY", "SEGMENT", "CETYPE", "WHILE", "DOWHILE", "UNTIL", "DOUNTIL",
  "FOR", "DOFOR", "FOREVER", "LOOP", "ENDLOOP", "WHILEBC", "UNTILBC",
  "FORBC", "WHILEB", "UNTILB", "FORB", "PBIN", "PPBIN", "PLIB", "PINCLUDE",
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
  "loop_statement", "$@28", "$@29", "while_loop", "whilec_loop1", "$@30",
  "$@31", "$@32", "while_loop1", "$@33", "$@34", "$@35", "whileb_loop",
  "whilebc_loop1", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41",
  "whileb_loop1", "$@42", "$@43", "$@44", "$@45", "$@46", "until_loop",
  "untilc_loop1", "$@47", "$@48", "$@49", "until_loop1", "$@50", "$@51",
  "$@52", "untilb_loop", "untilbc_loop1", "$@53", "$@54", "$@55", "$@56",
  "$@57", "$@58", "untilb_loop1", "$@59", "$@60", "$@61", "$@62", "$@63",
  "for_loop", "$@64", "$@65", "$@66", "$@67", "$@68", "$@69", "$@70",
  "$@71", "$@72", "forb_loop", "$@73", "$@74", "$@75", "$@76", "$@77",
  "$@78", "forever_loop", "$@79", "statement_block", "statements",
  "expression", "void_expression", "boolean_expression",
  "number_expression", "character_expression", "string_expression",
  "id_expression", "relational_expression", "@80", "mixed_expression",
  "function_expression", "function_command", "$@81", "$@82", "$@83",
  "$@84", "$@85", "$@86", "actual_function_parameters", "dv",
  "opt_expressions", "opt_expression", "declaration",
  "variable_declaration", "enumv_declaration", "rangev_declaration",
  "array_declaration", "enum_declaration", "$@88", "$@89", "enum_strings",
  "range_declaration", "struct_declaration", "$@90", "struct_body",
  "struct_var_declarations", "struct_var_declarations2", "$@91",
  "struct_declaration2", "struct_var_declaration3", "union_declaration",
  "$@92", "union_body", "union_var_declarations",
  "union_var_declarations2", "$@93", "union_declaration2",
  "union_var_declaration3", "label_declaration", "function_declaration",
  "$@94", "nothing", "parameter_declaration", "parameter_declaration2",
  "parameter_declaration5", "parameter_declaration6", "opt_var",
  "opt_var2", "opt_default_value", "dvalue", "optdefaultv", "opt_var5",
  "opt_var6", "function_declaration2", "$@95", "$@96", "function_body",
  "vars", "vars2", "vars3", "vars5", "vars6", "command", "print_command",
  "read_command", "end_command", "asm_command", "load_command", "$@97",
  "$@98", "$@99", "$@100", "goto_command", "operator_command",
  "top_command", "$@101", "$@102", "$@103", "$@104", "st_command",
  "stack_command", "typeof_command", "rm_command", "crash_command",
  "version_command", "halt_command", "modt_command", "subroutine_command",
  "register_command", "store_command", "break_command", "address_command",
  "add2v_command", "continue_command", "check_command", "comment_command",
  "file_command", "meml_command", "pnfasm_command", "array_length_command",
  "dup_command", "fret_command", "parameter_command", "psig", "$@105",
  "psig2", "$@106", "signature", "signature2", "struct_command",
  "union_command", "copy_command", "segment_command", "pp_directive",
  "pp_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-857)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-153)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -857,  1130,  -857,  -857,  -857,  -187,    68,  1335,  -857,  1335,
    -857,    67,   181,  -857,  -857,  -857,  -857,  -857,  -857,  1783,
     743,   562,   562,   562,   562,   562,   688,   688,  -857,   545,
    -857,   379,   562,  1834,  1834,   806,   806,   806,   806,  -857,
    -857,   769,  -857,  -857,    69,  -857,   -96,  1683,    22,   572,
     230,   660,   660,   562,    87,    60,    77,   108,  -857,  -857,
    -857,   106,  -857,   201,   214,    69,   114,  -857,   164,  -857,
     177,   186,   190,   159,   -60,   179,     7,   263,   229,   249,
     224,  -857,  -857,   277,  -857,  -857,   254,   270,   283,   293,
     298,  -857,   660,   660,   328,  -857,   306,   352,   266,   278,
     378,   388,   339,  -857,  -857,   268,   402,   381,  -857,   406,
     412,   416,   385,   387,   271,   562,   562,  -857,    35,  -857,
     422,  -857,   423,  -857,  -857,  -857,    -1,     0,   429,   432,
    -857,   450,   452,   454,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,     1,     2,   456,   460,  -857,   461,   462,   468,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,   475,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,   -77,  -857,
    -857,   405,  -857,  -857,  -857,  -857,  -857,  -857,   362,  -857,
    -857,   411,  -857,  -857,  -857,   506,  -857,   288,  1711,  1939,
     504,  1082,  -857,  -857,  -857,  -857,   508,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,   511,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,   480,  -857,  -857,
    -857,  -857,  -857,  -857,   475,   660,   743,   688,   688,   545,
     379,   769,  1738,   523,   526,   527,   104,  1656,  1276,    30,
    1920,   528,   529,   530,   531,    40,   533,  1783,   562,   806,
     806,   562,  1874,  1948,   519,   743,   743,   743,   545,  -857,
    1885,  1049,   562,   562,   562,  1874,  1874,  1874,  1874,  1874,
     688,  1885,   430,  1049,  1885,   430,  1049,   545,   545,   545,
     545,  1049,   379,   310,  1049,  1874,  1834,   207,   310,  1874,
    1948,   310,  1874,  1948,   806,  1874,  1948,  1874,  1948,  1874,
    1948,  1874,  1948,  -857,  1885,    69,   519,    69,   562,  1783,
     806,   806,   806,   806,   806,   207,   562,   207,  -857,   562,
     562,   562,   562,   562,   562,   562,   562,   562,   562,   521,
    -857,   532,  -857,  -857,  -857,  -857,  -857,  1874,   534,   502,
    1774,   507,   562,   551,   445,   555,   566,   563,   565,   517,
     781,  -857,   660,  1335,   519,   562,  -857,   541,  1874,   548,
     558,  -857,   546,   515,   557,  -857,   537,  -857,   585,   481,
     595,  1335,  -857,  -857,   567,  1335,  -857,  1335,   282,    69,
     539,    69,  -857,  -857,  -857,   568,   596,   604,   611,   612,
     218,   613,  -857,  -857,   622,    45,   618,    47,  -857,  1335,
     584,   586,   587,  1874,  1874,  -857,  -857,  -857,  -857,  -857,
    -857,   562,  1335,  -857,  1335,  -857,  -857,   619,  -857,   623,
     626,  -857,  -857,  -857,  -857,  -857,   629,  -857,   630,   631,
    -857,  -857,  -857,  -857,  -857,   641,   642,  -857,  -857,  -857,
    -857,  -857,   643,  -857,  -857,   107,   160,   802,   873,   908,
     976,  1013,   562,  1039,  1538,  -857,  -857,  1540,  1542,  1550,
    1575,  1577,  1585,  1587,  1612,  1620,  1622,  1624,   113,   175,
     220,   222,   308,   419,   466,  -857,  -857,   275,   545,   545,
     545,   545,   545,   545,   545,  -857,  -857,   545,   545,  -857,
    -857,   597,  -857,  -857,  -857,  -857,   588,  -857,   603,   610,
     615,   616,   617,   621,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  1811,  1481,   168,   562,   562,   562,   562,
     562,   562,   562,   562,   562,   562,   562,   308,   308,   308,
     308,   308,   308,    69,   244,   207,   207,   207,   519,  1874,
    1874,  1948,   519,  1874,  1948,  1874,  1948,  1874,  1948,  1874,
    1948,  1874,  1948,   310,  1874,   310,  1874,  1874,  1874,  1874,
    1874,  1874,  1874,  1874,  1874,  1874,   660,  -857,    69,  -857,
    1774,   310,  1874,  1948,   519,   284,  1874,  -857,   638,   535,
      81,  -857,  -857,   562,  -857,  1874,   668,    29,  1874,  -857,
    -857,  -857,  -857,   562,   628,   562,  -857,   663,   553,   153,
    -857,   475,   475,  1774,  1874,   519,  -857,   519,  -857,   672,
     665,   670,   677,   573,   562,   678,    93,  -857,   661,   258,
    -857,  -857,   664,   297,  1335,   198,   575,   687,   583,   701,
    -857,  1874,    -7,  1335,   -20,  1335,   501,   510,  -857,   512,
     513,  -857,  -857,  -857,  -857,  1335,  1335,  -857,  -857,   681,
    -857,  -857,  -857,  1874,  -857,   476,  -857,   476,  -857,   376,
    -857,   376,   376,  -857,  1912,  -857,  1912,  -857,  1912,  -857,
    1874,  -857,  1874,  -857,  1874,  -857,  1874,  -857,  1874,  -857,
    1874,  -857,  -857,  -857,  -857,  -857,    65,  -857,    65,   308,
     308,   308,  -857,  -857,  -857,  -857,  -857,   176,  -857,   176,
     176,  -857,   430,  -857,   430,  -857,  -857,   354,   354,   203,
     203,   203,  1049,  1049,   686,  -857,   666,  -857,   519,  -857,
     562,  1874,   592,    46,  -857,   693,   311,  1847,   711,  -857,
    1874,  -857,  1874,  -857,    98,  -857,   625,   310,  1874,  1948,
     519,  -857,   712,   713,   714,  -857,   437,  -857,  -857,   703,
     312,   682,   685,   690,   731,   684,   694,   692,   475,  -857,
     702,   602,  -857,   704,   606,  -857,  -857,   475,  -857,    19,
    -857,  -857,  -857,  -857,  1335,  1335,  1335,     4,   -12,  1335,
    -857,  -857,  -857,  1874,   562,  -857,   834,   697,   706,   709,
    1774,  -857,   752,  -857,   949,   632,   755,   749,  -857,   649,
     751,  -857,   710,   728,   729,  -857,   771,   747,    97,  -857,
     774,   750,   776,   652,   772,   738,     9,  -857,   773,   744,
       3,  -857,   796,   797,   799,  -857,   475,   475,   475,  -857,
    -857,    54,  -857,  -857,   987,  -857,  -857,   803,   783,   310,
    1874,  1948,   519,  -857,  -857,  -857,  -857,  -857,  -857,   787,
     699,  -857,  -857,   807,   784,   110,   768,  -857,   798,   335,
     119,   777,  -857,  -857,   660,  -857,  -857,  -857,   660,  -857,
    -857,  -857,  -857,  -857,  -857,  1335,   810,   827,   828,   837,
     839,  -857,  -857,  -857,   125,   790,  -857,  -857,  -857,  -857,
     757,   757,   770,   770,  1335,  1335,   847,   855,   851,   167,
     814,  -857,   823,   358,  -857,  -857,   816,   825,   831,  -857,
     835,   363,  -857,  -857,  1335,  1335,  -857,   867,  -857,   869,
    1335,  1335,  1335,   149,  -857,  -857,  -857,  -857,  -857,  1335,
    -857,   838,   364,  -857,  -857,  -857,  -857,  -857,  -857,   660,
     793,  -857,  -857,   660,   800,  -857,  -857,   475,   161,  -857,
    -857,  -857,  -857,   846,   380,  -857,  -857,   864,  -857,   852,
    -857,  -857,   868,   877,  -857,   861,   475,   475,  -857,  -857,
     475,   475,   475,  -857,  1335,  1335,  1335,  1335,  1335,   251,
     879,  -857,   863,  -857,   881,  -857,  -857,   886,  -857,   786,
    -857,   891,  -857,   875,   872,  -857,   882,   919,   876,   883,
     887,   805,   922,   924,  1335,   475,   475,   475,   475,   475,
    -857,   884,   893,   913,  -857,  -857,   914,  -857,   938,  -857,
    1335,   892,   941,   904,  -857,  -857,   921,  -857,  -857,  -857,
     923,  -857,  -857,  -857,   475,   950,   951,  1335,  -857,   927,
    1335,  1335,   967,  -857,  1335,  -857,   888,   264,   961,  -857,
    -857,   948,   925,   137,   928,   888,   968,   970,   979,  -857,
    -857,   475,   931,   475,   475,  -857,  1335,   475,  -857,  -857,
    -857,   660,  -857,  -857,   982,  -857,   947,  -857,   962,  -857,
    -857,  -857,   998,  -857,  -857,  -857,  -857,  -857,  1335,  1001,
    1002,  1014,  -857,   475,  1335,   889,  1335,   988,  -857,  -857,
     961,   966,  -857,   499,   889,   475,  -857,  -857,  1335,    -8,
    -857,  -857,   475,  1017,  -857,  -857,  1026,  1003,  -857,  -857,
     475,  -857,  1027,  -857,  -857,   984,  -857,  -857,  -857,  -857
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     7,     3,     0,     6,    72,     5,    72,
     527,     0,     8,   163,   165,   170,   190,   203,    12,   479,
     483,   485,   487,   489,   491,   493,   495,   496,   497,   520,
     498,   499,     0,   500,   501,   503,   502,   504,   505,   521,
     522,   523,   524,   525,     0,   528,     0,   207,     0,   432,
     435,   438,   440,     0,     0,     0,     0,     0,   535,   536,
     537,     0,   539,   542,     0,     0,     0,   547,     0,   549,
       0,     0,     0,     0,     0,     0,     0,     0,   564,     0,
       0,   567,   142,     0,   149,   568,     0,     0,     0,     0,
       0,   578,   442,   444,     0,   579,     0,     0,     0,     0,
       0,     0,     0,   540,   541,   372,     0,     0,   583,     0,
       0,     0,     0,     0,     0,     0,     0,   596,     0,   100,
       0,   125,     0,   604,   605,   606,     0,     0,     0,     0,
     613,     0,     0,     0,   617,   618,   619,   620,   621,   622,
     623,   624,     0,     0,     0,     0,   631,     0,     0,     0,
     635,   636,   637,   638,   639,   640,   641,   642,     9,    13,
      14,    16,    15,    11,    26,    27,    28,    29,     0,    74,
      91,     0,    92,    75,   106,   107,    76,   116,     0,   117,
      77,     0,    78,    79,    17,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   289,     0,   305,   318,   319,
     320,   307,   308,   309,   310,   311,   312,   313,   314,   306,
     352,   353,     0,   397,   398,   399,   400,   401,   402,   403,
     526,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   584,   585,     0,   428,   429,
     430,   431,    18,    19,    10,     0,     0,     0,     0,     0,
       0,     0,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,   480,   481,   482,     0,     0,     0,     0,   207,
     176,   217,     0,     0,     0,   486,   488,   490,   492,   494,
       0,   179,   198,   220,   181,   200,   222,     0,     0,     0,
       0,   208,     0,   166,   209,   484,     0,     0,   506,   508,
     514,   507,   509,   515,     0,   511,   517,   510,   516,   512,
     518,   513,   519,   282,   186,     0,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   315,
     434,     0,   433,   437,   436,   439,   441,   449,     0,     0,
     453,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   538,     0,    72,   543,     0,   548,     0,   550,   349,
     350,   552,     0,     0,     0,   557,     0,   559,     0,     0,
       0,    72,   565,   351,     0,    72,   317,    72,     0,     0,
       0,     0,   577,   443,   445,     0,     0,     0,     0,     0,
       0,     0,   582,   373,     0,     0,     0,     0,   108,    72,
     331,   340,     0,   545,   546,   597,   598,   601,   602,   603,
     600,     0,    72,   112,    72,   137,   607,     0,   609,     0,
       0,   612,   614,   615,   616,   625,     0,   627,     0,     0,
     630,   632,   633,   634,   530,     0,     0,    73,    81,    82,
      94,   119,     0,    80,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   201,     0,     0,     0,
       0,     0,     0,     0,     0,   221,   223,     0,     0,    21,
      22,     0,   592,   594,   164,   169,     0,   189,     0,     0,
       0,     0,     0,     0,   202,   206,   224,   233,   290,   593,
     595,   153,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   529,   288,
     238,   250,   262,   239,   251,   240,   252,   241,   253,   242,
     254,   243,   255,   234,   276,   236,   270,   271,   273,   272,
     274,   275,   277,   278,   283,   284,     0,   446,     0,   447,
       0,   454,   455,   456,   457,     0,   459,   460,     0,     0,
       0,   473,   474,     0,   478,   477,     0,     0,   544,   551,
      24,    25,   553,     0,     0,   558,   560,     0,     0,     0,
     566,   143,   150,     0,   573,   574,   575,   576,   448,     0,
       0,     0,     0,     0,     0,     0,     0,   382,     0,     0,
     291,   391,     0,     0,    72,     0,   338,     0,   347,     0,
     475,   599,     0,    72,     0,    72,     0,     0,   611,     0,
       0,   629,   531,    83,    87,    72,    72,   132,   235,   167,
     237,   168,   287,   232,   244,   171,   245,   172,   246,   173,
     247,   174,   175,   248,   177,   249,   178,   279,   183,   264,
     225,   265,   226,   267,   228,   266,   227,   268,   229,   269,
     230,   280,   184,   281,   185,   285,   187,   286,   188,     0,
       0,     0,   256,   191,   257,   192,   258,   193,   259,   194,
     195,   260,   196,   261,   197,   263,   204,   212,   213,   214,
     215,   216,   218,   219,   210,   211,   586,   316,   450,   458,
     452,   451,   461,     0,   394,     0,     0,     0,     0,    51,
     555,   554,   556,   561,     0,    30,     0,   570,   569,   571,
     572,   325,     0,     0,   323,   581,     0,   580,   385,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,    36,
       0,     0,   332,     0,     0,   341,   101,   113,   126,     0,
     608,   610,   626,   628,    72,    72,    72,     0,     0,    72,
     231,   588,   356,   476,     0,   464,     0,     0,     0,     0,
       0,    46,     0,   563,     0,     0,     0,     0,   321,     0,
       0,   324,     0,     0,     0,   383,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,   334,     0,     0,
       0,   343,     0,     0,     0,   138,   532,    84,    88,    95,
     120,     0,   356,   587,     0,   463,   395,     0,     0,   465,
     467,   469,   471,    55,    63,   562,    31,   144,   328,   326,
       0,   322,   386,     0,     0,     0,     0,   388,     0,     0,
       0,     0,   110,    37,     0,   336,   333,   335,     0,   345,
     342,   344,   102,   114,   127,    72,     0,     0,     0,     0,
       0,   133,   589,   462,     0,     0,   356,   356,   356,   356,
      47,     0,    52,     0,    72,    72,     0,     0,     0,     0,
       0,   366,     0,     0,   357,   384,     0,     0,     0,   375,
       0,     0,   361,   393,    72,    72,   339,     0,   348,     0,
      72,    72,    72,     0,   533,    85,    89,    96,   121,    72,
     377,     0,     0,   363,   396,   466,   468,   470,   472,     0,
      60,    57,    56,     0,    69,    65,    64,    32,     0,   329,
     327,   330,   368,     0,     0,   359,   387,     0,   354,     0,
     389,   292,     0,     0,   590,     0,   111,    38,   337,   346,
     103,   115,   128,   139,    72,    72,    72,    72,    72,     0,
       0,   591,     0,    58,     0,    48,    66,     0,    53,     0,
     145,     0,   378,     0,     0,   356,     0,     0,     0,     0,
       0,     0,     0,     0,    72,   534,    86,    90,    97,   122,
     134,     0,     0,     0,    61,    49,     0,    70,     0,    33,
      72,     0,     0,     0,   365,   355,     0,   293,   390,   374,
       0,    39,   104,   129,   140,     0,     0,    72,   376,     0,
      72,    72,     0,    67,    72,    54,    42,     0,   369,     8,
     379,     0,     0,     0,     0,    42,     0,     0,     0,    98,
     123,   135,     0,    59,    62,    50,    72,    71,    43,    34,
     146,     0,   367,   370,     0,   356,     0,   358,     0,   304,
     294,   298,   299,   300,   362,    40,   105,   130,    72,     0,
       0,     0,   364,    68,    72,     0,    72,     0,   381,   380,
     369,     0,   295,     0,     0,   141,    99,   124,    72,     0,
      45,    35,   147,     0,   360,   302,     0,     0,   301,    41,
     136,    44,     0,   371,   296,     0,   148,   356,   303,   297
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -857,  -857,  -857,  -857,  1041,  -857,    -9,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,   -45,  -857,   -91,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,   124,  -857,  -857,
    -857,  -857,  -857,   123,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -270,   -48,    -4,
      55,     5,   403,   133,   580,  -857,  -857,    -3,    -2,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,   -86,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,   202,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,   199,  -857,  -857,  -857,  -857,  -857,  -857,  -856,
    -857,  -857,  -857,  -857,  -857,  -857,   -79,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     4,     5,   275,     7,   158,   159,   160,   161,
     162,   163,   164,   825,   924,  1019,  1076,  1125,   165,   843,
     945,  1031,  1085,  1134,  1099,  1124,  1141,   166,   873,   970,
    1045,  1072,   822,   974,  1048,   920,   921,   971,  1043,  1015,
    1071,   922,   923,   975,  1046,  1096,  1018,  1074,   167,   168,
     473,   467,   468,   805,   907,  1005,   469,   806,   908,  1006,
     169,   170,   171,   675,   909,  1007,  1065,  1119,   172,   442,
     852,   950,  1032,  1086,   173,   174,   654,   842,   944,   175,
     663,   853,   951,   176,   177,   178,   676,   910,  1008,  1066,
    1120,   179,   444,   854,   952,  1033,  1087,   180,   181,   809,
     959,  1067,  1121,   665,   905,  1034,  1088,   182,   405,   766,
     925,  1050,  1126,  1152,   183,   407,   184,   276,   185,   186,
     187,   188,   189,   190,   191,   192,   810,   193,   194,   195,
     784,  1027,  1083,  1132,  1146,  1157,  1110,  1111,  1112,  1113,
     196,   197,   198,   199,   200,   201,   827,   927,   879,   202,
     203,   657,   792,   846,   847,   947,   204,   205,   206,   659,
     795,   850,   851,   949,   207,   208,   209,   210,  1025,   863,
     933,   984,   941,   962,   934,   985,  1102,  1103,   424,   942,
     963,   211,  1052,  1105,  1080,   649,   780,   889,   653,   756,
     212,   213,   214,   215,   216,   217,   916,   917,   918,   919,
     218,   219,   220,   672,   804,   906,  1004,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   812,   246,   862,   247,   379,   248,   249,   250,
     251,   252,   253
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     254,   362,   364,   365,   366,   541,   912,   265,   271,   272,
     464,   900,   446,   448,   455,   457,   267,   896,   464,   392,
     465,     8,   464,   464,   282,   290,   295,   296,   297,   298,
     299,   301,   304,   855,   464,   759,   535,   315,   319,   322,
     325,   327,   329,   331,   413,   414,   334,   507,  -152,   464,
     337,   292,   435,   436,   647,     9,   651,    15,   367,   464,
     965,   966,   967,   968,   278,   395,   266,   393,   911,   359,
     293,   294,   255,   396,   335,   388,    13,    14,    15,    16,
      17,   466,    17,     9,   464,   256,   313,   281,   318,   321,
     754,   257,   258,   648,   259,   652,   260,   437,   438,   439,
     368,   859,   778,   292,   553,   554,   887,   397,   261,    15,
     525,    44,   567,    44,   262,   369,   278,    14,   719,   931,
     433,   434,   293,   294,  1151,    16,   398,   399,   939,   755,
     475,   860,   476,   400,   960,   370,   317,   720,   721,   281,
     798,   779,   255,   371,   269,   888,    13,    14,    15,    16,
      17,   796,   284,   849,   678,   256,   372,   845,   932,   765,
     722,   257,   258,  1003,   259,   567,   260,   940,   380,  1055,
      14,   815,   381,   961,   535,  1020,   982,   336,   261,   464,
     719,    44,   292,   464,   262,   563,   385,    16,    15,   317,
     440,   464,   441,   557,   558,   278,   373,   374,   384,   720,
     721,   293,   294,   375,   789,   107,   382,   680,   447,   449,
     456,   458,   567,   376,   263,   983,   264,    14,   281,   383,
     508,   509,   724,   823,   377,   719,   378,   719,   464,   517,
     386,   518,    16,   389,    16,   255,   317,   390,   391,    13,
      14,    15,    16,    17,   720,   721,   720,   721,   256,  1129,
     525,   265,   271,   272,   257,   258,   387,   259,   394,   260,
     267,   290,   301,   304,   782,  1040,   334,   726,   401,   728,
     565,   261,   566,   783,    44,   107,   402,   262,  1100,  1108,
     335,   464,   543,   290,   301,   304,   334,   292,    17,   292,
     543,   301,   304,    15,   464,    15,   403,   543,   301,   304,
     278,  1159,   278,   786,   404,   543,   293,   294,   293,   294,
     266,   363,   787,   719,   475,   313,   476,   818,   833,    44,
      16,   543,   735,   281,   406,   281,   819,   834,   273,   543,
     274,   749,   720,   721,   616,   408,   565,   633,   566,   750,
     643,   937,   644,   569,   570,   573,   575,   577,   579,   581,
     938,   584,   409,   416,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   988,   417,   410,   564,   107,   994,
    1011,   564,   313,   989,   617,   602,   411,   606,   995,  1012,
     517,   412,   518,   415,   312,   615,  1022,   418,   269,    14,
     618,   420,   629,   546,   547,  1023,   631,   308,   632,   419,
     583,   421,   585,   309,   310,   422,   259,   425,   260,   423,
     545,   427,   426,   634,   268,   553,   554,   428,   555,   556,
     655,   429,   283,   432,   719,   601,   289,   443,   445,   302,
     305,    16,   430,   662,   431,   664,   320,   323,   326,   328,
     330,   332,   450,   720,   721,   451,   661,   557,   558,   559,
     560,   502,   561,   562,   546,   547,   548,   549,   482,   550,
     551,   485,   486,   452,   552,   453,   731,   454,   545,   459,
     568,   719,   572,   460,   461,   462,   553,   554,    16,   555,
     556,   463,   683,   685,   687,   689,   691,   692,   694,   696,
     720,   721,   698,   700,   702,   704,   706,   708,   710,   712,
     714,   716,   718,   604,   255,   464,   470,   471,    13,    14,
      15,    16,    17,   733,   472,   553,   554,   256,   555,   556,
     474,   507,   519,   257,   258,   520,   259,   521,   260,   522,
     679,   681,   523,   524,   537,   538,   563,   596,   539,   540,
     261,   542,   635,    44,   637,   597,   262,   598,   747,   599,
     307,   685,   687,   689,   691,   694,   696,   698,   712,   714,
     716,   718,   831,   308,   607,   605,   608,   292,   609,   309,
     310,   610,   259,    15,   288,   613,   611,   255,   612,   620,
     278,    13,    14,    15,    16,    17,   293,   294,   619,   621,
     256,   270,   289,   622,   623,   625,   257,   258,   626,   259,
     291,   260,   627,   281,   624,   543,   303,   306,   628,   311,
     751,   314,   639,   261,   630,   638,    44,   640,   757,   262,
     679,   681,   564,   636,   641,   642,   645,   646,   760,   650,
     762,   656,   666,   658,   660,   682,   667,   107,   768,   668,
     736,  1147,   669,   670,   671,   788,   673,   674,   677,   776,
     699,   752,   746,   360,   797,   564,   799,   701,   268,   753,
     302,   305,   703,   705,   707,   255,   807,   808,   709,    13,
      14,    15,    16,    17,   758,   761,   763,   764,   256,   771,
     544,   772,   302,   305,   257,   258,   773,   259,   767,   260,
     774,   777,   781,   300,   791,   785,   736,   790,   361,    15,
      16,   261,   775,   544,    44,   793,   256,   262,   794,   566,
     107,   800,   257,   258,   518,   259,   814,   288,   821,   544,
     801,   811,   802,   803,   817,   828,   829,   544,   826,   281,
     830,   748,   836,   545,   832,   289,   838,   835,   837,   839,
     841,   840,   571,   574,   576,   578,   580,   582,   285,   844,
     845,   848,   866,   867,    15,   813,   849,   868,   816,   874,
     877,   256,   878,   876,   881,   882,   770,   286,   287,   824,
     259,   880,   288,   603,   292,   883,   885,   884,   886,   890,
      15,   891,   892,   893,   281,   895,   292,   278,   894,   898,
     289,   899,    15,   293,   294,   856,   857,   858,   107,   278,
     861,   902,   926,   903,   904,   293,   294,   292,   914,  1104,
     281,   324,   929,    15,   915,   930,   333,    15,    16,   864,
     278,   928,   281,   935,   278,   870,   293,   294,   614,   936,
     279,   280,   943,   955,   956,   270,   291,   303,   306,   311,
     314,   954,   957,   281,   958,   964,   946,   281,   969,   682,
     948,   546,   547,   548,   549,   482,   550,   551,   485,   486,
     979,   552,   973,   980,   981,   270,   303,   306,   314,   986,
     987,   990,   991,   553,   554,   869,   555,   556,   292,   992,
     270,   998,   993,   999,    15,  1010,  1014,   270,   291,   303,
     306,   278,   270,  1021,  1017,  1024,   953,   293,   294,  1028,
    1026,   723,   725,   727,   729,   730,   732,   734,  1029,  1030,
    1041,  1042,  1044,   292,   281,   977,   978,  1047,  1049,    15,
     684,  1013,  1051,  1053,  1057,  1016,   278,  1054,  1062,  1056,
    1063,  1058,   293,   294,  1060,   996,   997,  1061,  1059,  1068,
    1069,  1000,  1001,  1002,  1070,  1073,  1075,  1078,  1079,   281,
    1009,  1081,  1082,   872,  1084,   686,  1089,  1090,  1092,   865,
     723,   725,   727,   729,   732,   734,   546,   547,   548,   549,
     482,   550,   551,   485,   486,  1095,   552,  1101,  1098,  1106,
    1107,   292,  1116,  1114,  1117,  1118,  1122,    15,   553,   554,
    1128,   555,   556,  1131,   278,  1035,  1036,  1037,  1038,  1039,
     293,   294,  1130,   544,   546,   547,   548,   549,   482,   550,
     551,   485,   486,  1133,   552,  1136,  1137,   281,   292,  1143,
    1138,  1145,  1140,   688,    15,  1064,   553,   554,  1153,   555,
     556,   278,  1154,  1156,  1155,  1109,   769,   293,   294,  1158,
    1115,  1077,     6,  1149,   292,   972,   976,  1148,   897,   901,
      15,  1144,     0,  1127,   281,     0,     0,   278,  1091,     0,
     690,  1093,  1094,   293,   294,  1097,   508,   509,   510,   511,
     512,   513,   514,     0,   875,   517,     0,   518,     0,     0,
     281,     0,     0,     0,     0,  1109,   693,  1123,   737,   738,
     739,   740,   741,   742,   743,     0,     0,   744,   745,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,  1135,
     518,     0,   913,     0,     0,  1139,     0,  1142,     0,     0,
       0,     0,   544,   302,   305,     0,     0,     0,     0,  1150,
       2,     3,     0,     0,    -8,    -8,     0,    -8,     0,    -8,
      -8,    -8,    -8,    -8,    -8,     0,     0,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
       0,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,     0,    -8,
       0,    -8,    -8,    -8,     0,    -8,     0,    -8,    -8,    -8,
      -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,     0,
       0,     0,     0,     0,     0,    -8,    -8,    -8,    -8,    -8,
       0,     0,     0,   871,     0,    -8,    -8,    -8,    -8,    -8,
       0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,     0,
      -8,     0,     0,    -8,     0,     0,    -8,     0,    -8,     0,
      -8,     0,     0,     0,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,     0,     0,    -8,    -8,    -8,     0,    -8,     0,    -8,
       0,    -8,   534,    -8,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,    -8,   498,   499,   500,   501,   502,   503,   504,
     505,   506,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -4,    10,
      11,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       0,    55,    56,     0,    57,     0,    58,    59,    60,     0,
      61,     0,    62,    63,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,     0,     0,     0,     0,     0,
      78,    79,     0,    80,    81,     0,   -93,    82,  -131,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     0,    98,     0,     0,    99,     0,
       0,   100,     0,   101,     0,   102,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,   111,
    -118,     0,   112,     0,   113,     0,   114,   534,   115,   116,
     117,   118,     0,     0,   119,   120,   121,   122,   557,   558,
     559,   560,   502,   561,   562,   505,   506,     0,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   292,     0,   292,     0,   292,     0,    15,
       0,    15,     0,    15,     0,   292,   278,     0,   278,     0,
     278,    15,   293,   294,   293,   294,   293,   294,   278,     0,
       0,     0,     0,     0,   293,   294,     0,     0,     0,   281,
     292,   281,   292,   281,     0,   695,    15,   697,    15,   699,
     292,   281,   292,   278,     0,   278,    15,   701,    15,   293,
     294,   293,   294,   278,     0,   278,     0,     0,     0,   293,
     294,   293,   294,     0,     0,     0,   281,   292,   281,     0,
       0,     0,   703,    15,   705,   292,   281,   292,   281,   292,
     278,    15,   707,    15,   709,    15,   293,   294,   278,     0,
     278,     0,   278,     0,   293,   294,   293,   294,   293,   294,
       0,     0,     0,   281,     0,     0,     0,     0,     0,   711,
     526,   281,   527,   281,     0,   281,     0,   713,     0,   715,
       0,   717,     0,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,   487,     0,     0,     0,   338,     0,   528,
     529,   530,   531,   532,   533,   494,   495,     0,   496,   497,
     339,   340,   341,   342,     0,   343,   344,     0,     0,   345,
     346,   347,     0,     0,   348,   477,   349,   350,   351,   352,
     353,   354,   355,   356,     0,   357,   358,     0,   478,   479,
     480,   481,   482,   483,   484,   485,   486,     0,   487,     0,
       0,     0,   338,     0,   488,   489,   490,   491,   492,   493,
     494,   495,     0,   496,   497,   339,   340,   341,   342,     0,
     343,   344,     0,     0,   345,   346,   347,     0,     0,     0,
       0,   349,   350,   351,   352,   353,   354,   355,   356,   600,
     357,   358,     0,     0,    14,    15,    16,    17,   277,     0,
       0,     0,   278,     0,    15,    16,    17,     0,   279,   280,
       0,   278,     0,   317,     0,     0,     0,   279,   280,     0,
       0,     0,     0,     0,     0,   281,     0,   527,    44,     0,
       0,     0,     0,     0,   281,     0,     0,    44,   546,   547,
     548,   549,   482,   550,   551,   485,   486,     0,   552,   316,
       0,     0,     0,     0,    14,    15,    16,     0,     0,     0,
     553,   554,   278,   555,   556,     0,     0,     0,   279,   280,
       0,     0,     0,   317,   546,   547,   548,   549,   482,   550,
     551,   485,   486,     0,   552,   281,     0,     0,   820,     0,
       0,     0,     0,     0,     0,     0,   553,   554,     0,   555,
     556,   546,   547,   548,   549,   482,   550,   551,   485,   486,
       0,   552,   546,   547,   548,   549,   482,   550,   551,     0,
       0,     0,   552,   553,   554,     0,   555,   556,     0,     0,
       0,     0,     0,     0,   553,   554,   536,   555,   556,   546,
     547,   548,   549,   482,   550,   551,     0,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,     0,   518,     0,
       0,   553,   554,     0,   555,   556,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   557,   558,   559,   560,   502,
     561,   562,   505,   506
};

static const yytype_int16 yycheck[] =
{
       9,    49,    50,    51,    52,   275,   862,    11,    11,    11,
      30,     8,    13,    13,    13,    13,    11,     8,    30,    79,
      97,   208,    30,    30,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    14,    30,     6,     6,    32,    33,    34,
      35,    36,    37,    38,    92,    93,    41,    17,     8,    30,
     146,     5,    17,    18,     9,    15,     9,    11,    53,    30,
     916,   917,   918,   919,    18,    58,    11,   127,    14,    47,
      24,    25,     5,    66,     5,    70,     9,    10,    11,    12,
      13,   158,    13,    15,    30,    18,    31,    41,    33,    34,
       9,    24,    25,    48,    27,    48,    29,    62,    63,    64,
      13,    97,     9,     5,    39,    40,     9,   100,    41,    11,
       6,    44,     5,    44,    47,    55,    18,    10,     5,     9,
     115,   116,    24,    25,   132,    12,   119,   120,     9,    48,
      26,   143,    28,   126,     9,    58,    29,    24,    25,    41,
     160,    48,     5,    66,    11,    48,     9,    10,    11,    12,
      13,   158,    19,   150,    47,    18,    79,   148,    48,     6,
      47,    24,    25,    14,    27,     5,    29,    48,    60,  1025,
      10,   125,    66,    48,     6,    14,     9,    44,    41,    30,
       5,    44,     5,    30,    47,    17,    72,    12,    11,    29,
     155,    30,   157,    17,    18,    18,   119,   120,    65,    24,
      25,    24,    25,   126,     6,   138,     5,    47,   209,   209,
     209,   209,     5,   136,   147,    48,   149,    10,    41,     5,
      17,    18,    47,   125,   147,     5,   149,     5,    30,    26,
      66,    28,    12,    47,    12,     5,    29,    47,    79,     9,
      10,    11,    12,    13,    24,    25,    24,    25,    18,  1105,
       6,   255,   255,   255,    24,    25,    79,    27,    79,    29,
     255,   256,   257,   258,     6,    14,   261,    47,     5,    47,
      26,    41,    28,    15,    44,   138,    47,    47,    14,   142,
       5,    30,   277,   278,   279,   280,   281,     5,    13,     5,
     285,   286,   287,    11,    30,    11,    47,   292,   293,   294,
      18,  1157,    18,     6,    80,   300,    24,    25,    24,    25,
     255,    81,    15,     5,    26,   260,    28,     6,     6,    44,
      12,   316,    47,    41,    47,    41,    15,    15,   147,   324,
     149,    47,    24,    25,   382,    81,    26,    55,    28,    55,
     122,     6,   124,   338,   339,   340,   341,   342,   343,   344,
      15,   346,    82,    47,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     6,    13,    83,   312,   138,     6,
       6,   316,   317,    15,   383,   370,    83,   372,    15,    15,
      26,    83,    28,    55,     5,   380,     6,   121,   255,    10,
     385,    13,   401,    17,    18,    15,   405,    18,   407,   121,
     345,    13,   347,    24,    25,    66,    27,     5,    29,   141,
     277,     5,    31,   408,    11,    39,    40,     5,    42,    43,
     429,     5,    19,   152,     5,   370,    47,     5,     5,    26,
      27,    12,    47,   442,    47,   444,    33,    34,    35,    36,
      37,    38,    13,    24,    25,    13,   441,    17,    18,    19,
      20,    21,    22,    23,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    13,    27,    13,    47,    13,   335,    13,
     337,     5,   339,    13,    13,    13,    39,    40,    12,    42,
      43,    13,   477,   478,   479,   480,   481,   482,   483,   484,
      24,    25,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   370,     5,    30,   101,   145,     9,    10,
      11,    12,    13,    47,   103,    39,    40,    18,    42,    43,
      14,    17,    14,    24,    25,    14,    27,    47,    29,     6,
     475,   476,     6,     6,     6,     6,    17,    16,     8,     8,
      41,     8,   409,    44,   411,    13,    47,    13,   596,    47,
       5,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   125,    18,    13,    58,   121,     5,    13,    24,
      25,     5,    27,    11,    29,    58,    13,     5,    13,    31,
      18,     9,    10,    11,    12,    13,    24,    25,    47,    31,
      18,    11,    47,    47,    79,    58,    24,    25,    13,    27,
      20,    29,   121,    41,    47,   600,    26,    27,    13,    29,
     605,    31,    16,    41,    47,    47,    44,    13,   613,    47,
     565,   566,   567,    84,    13,    13,    13,     5,   623,    11,
     625,    47,    13,    47,    47,    47,    13,   138,   633,    13,
     507,   142,    13,    13,    13,   654,     5,     5,     5,   644,
      47,    13,    55,    81,   663,   600,   665,    47,   255,   124,
     257,   258,    47,    47,    47,     5,   675,   676,    47,     9,
      10,    11,    12,    13,     6,    47,    13,   124,    18,     7,
     277,    16,   279,   280,    24,    25,    16,    27,   633,    29,
      13,    13,    31,     5,     7,    31,   563,   122,   126,    11,
      12,    41,   129,   300,    44,   122,    18,    47,     7,    28,
     138,   210,    24,    25,    28,    27,   124,    29,     7,   316,
     210,    55,   210,   210,    31,    13,    13,   324,   103,    41,
      16,   598,    47,   600,    31,    47,     5,    55,    48,    55,
      48,    47,   339,   340,   341,   342,   343,   344,     5,    47,
     148,    47,    55,    47,    11,   750,   150,    48,   753,     7,
       5,    18,    13,   131,    13,    55,   633,    24,    25,   764,
      27,   122,    29,   370,     5,    47,     5,    48,    31,     5,
      11,    31,     6,   131,    41,    47,     5,    18,    16,    16,
      47,    47,    11,    24,    25,   804,   805,   806,   138,    18,
     809,     5,    15,     6,     5,    24,    25,     5,     5,  1079,
      41,     5,     5,    11,    31,    31,    47,    11,    12,   814,
      18,   122,    41,    55,    18,   820,    24,    25,    47,    31,
      24,    25,    55,     6,     6,   255,   256,   257,   258,   259,
     260,    31,     5,    41,     5,    55,   894,    41,    91,    47,
     898,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      13,    27,    92,     8,    13,   285,   286,   287,   288,    55,
      47,    55,    47,    39,    40,   820,    42,    43,     5,    48,
     300,    14,    47,    14,    11,    47,    93,   307,   308,   309,
     310,    18,   312,    47,    94,    31,   905,    24,    25,    31,
      48,   498,   499,   500,   501,   502,   503,   504,    31,    48,
      31,    48,    31,     5,    41,   924,   925,    31,   132,    11,
      47,   969,    31,    48,     5,   973,    18,    55,     6,    47,
       6,    55,    24,    25,    47,   944,   945,   132,    55,    55,
      47,   950,   951,   952,    31,    31,     8,    55,     7,    41,
     959,    47,    31,   820,    31,    47,     6,     6,    31,   125,
     557,   558,   559,   560,   561,   562,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     8,    27,    16,    90,    31,
      55,     5,    14,    55,    14,     6,    55,    11,    39,    40,
       8,    42,    43,    31,    18,  1004,  1005,  1006,  1007,  1008,
      24,    25,    55,   600,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    15,    27,    14,    14,    41,     5,    31,
       6,    55,   133,    47,    11,  1034,    39,    40,    11,    42,
      43,    18,     6,     6,    31,  1083,   633,    24,    25,    55,
    1085,  1050,     1,  1134,     5,   921,   923,  1133,   846,   850,
      11,  1130,    -1,  1101,    41,    -1,    -1,    18,  1067,    -1,
      47,  1070,  1071,    24,    25,  1074,    17,    18,    19,    20,
      21,    22,    23,    -1,   125,    26,    -1,    28,    -1,    -1,
      41,    -1,    -1,    -1,    -1,  1133,    47,  1096,   508,   509,
     510,   511,   512,   513,   514,    -1,    -1,   517,   518,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,  1118,
      28,    -1,   125,    -1,    -1,  1124,    -1,  1126,    -1,    -1,
      -1,    -1,   719,   720,   721,    -1,    -1,    -1,    -1,  1138,
       0,     1,    -1,    -1,     4,     5,    -1,     7,    -1,     9,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    -1,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    69,
      70,    71,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      -1,    -1,    -1,   820,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,    -1,    -1,   123,    -1,    -1,   126,    -1,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,   143,   144,   145,    -1,   147,    -1,   149,
      -1,   151,     6,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,     4,
       5,    -1,     7,    -1,     9,    10,    11,    12,    13,    14,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    -1,    59,    -1,    61,    62,    63,    -1,
      65,    -1,    67,    68,    69,    70,    71,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      95,    96,    -1,    98,    99,    -1,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,    -1,    -1,   123,    -1,
      -1,   126,    -1,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,   143,   144,
     145,    -1,   147,    -1,   149,    -1,   151,     6,   153,   154,
     155,   156,    -1,    -1,   159,   160,   161,   162,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,     5,    -1,     5,    -1,     5,    -1,    11,
      -1,    11,    -1,    11,    -1,     5,    18,    -1,    18,    -1,
      18,    11,    24,    25,    24,    25,    24,    25,    18,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    41,
       5,    41,     5,    41,    -1,    47,    11,    47,    11,    47,
       5,    41,     5,    18,    -1,    18,    11,    47,    11,    24,
      25,    24,    25,    18,    -1,    18,    -1,    -1,    -1,    24,
      25,    24,    25,    -1,    -1,    -1,    41,     5,    41,    -1,
      -1,    -1,    47,    11,    47,     5,    41,     5,    41,     5,
      18,    11,    47,    11,    47,    11,    24,    25,    18,    -1,
      18,    -1,    18,    -1,    24,    25,    24,    25,    24,    25,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    47,
       4,    41,     6,    41,    -1,    41,    -1,    47,    -1,    47,
      -1,    47,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    -1,    -1,    -1,     4,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      17,    18,    19,    20,    -1,    22,    23,    -1,    -1,    26,
      27,    28,    -1,    -1,    31,     4,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,     4,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    17,    18,    19,    20,    -1,
      22,    23,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,     5,
      42,    43,    -1,    -1,    10,    11,    12,    13,     5,    -1,
      -1,    -1,    18,    -1,    11,    12,    13,    -1,    24,    25,
      -1,    18,    -1,    29,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,     6,    44,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    44,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,
      39,    40,    18,    42,    43,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    29,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    41,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    42,
      43,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    39,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,     6,    42,    43,    17,
      18,    19,    20,    21,    22,    23,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    -1,
      -1,    39,    40,    -1,    42,    43,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    17,    18,    19,    20,    21,
      22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   212,     0,     1,   213,   214,   215,   216,   208,    15,
       4,     5,     7,     9,    10,    11,    12,    13,    14,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    56,    57,    59,    61,    62,
      63,    65,    67,    68,    69,    70,    71,    73,    74,    75,
      76,    77,    78,    85,    86,    87,    88,    89,    95,    96,
      98,    99,   102,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   120,   123,
     126,   128,   130,   134,   135,   136,   137,   138,   139,   140,
     143,   144,   147,   149,   151,   153,   154,   155,   156,   159,
     160,   161,   162,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   217,   218,
     219,   220,   221,   222,   223,   229,   238,   259,   260,   271,
     272,   273,   279,   285,   286,   290,   294,   295,   296,   302,
     308,   309,   318,   325,   327,   329,   330,   331,   332,   333,
     334,   335,   336,   338,   339,   340,   351,   352,   353,   354,
     355,   356,   360,   361,   367,   368,   369,   375,   376,   377,
     378,   392,   401,   402,   403,   404,   405,   406,   411,   412,
     413,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   444,   446,   448,   449,
     450,   451,   452,   453,   217,     5,    18,    24,    25,    27,
      29,    41,    47,   147,   149,   330,   331,   332,   333,   334,
     335,   338,   339,   147,   149,   215,   328,     5,    18,    24,
      25,    41,   332,   333,   334,     5,    24,    25,    29,    47,
     332,   335,     5,    24,    25,   332,   332,   332,   332,   332,
       5,   332,   333,   335,   332,   333,   335,     5,    18,    24,
      25,   335,     5,   331,   335,   332,     5,    29,   331,   332,
     333,   331,   332,   333,     5,   332,   333,   332,   333,   332,
     333,   332,   333,    47,   332,     5,   334,   146,     4,    17,
      18,    19,    20,    22,    23,    26,    27,    28,    31,    33,
      34,    35,    36,    37,    38,    39,    40,    42,    43,    47,
      81,   126,   329,    81,   329,   329,   329,   332,    13,    55,
      58,    66,    79,   119,   120,   126,   136,   147,   149,   447,
      60,    66,     5,     5,   334,    72,    66,    79,   332,    47,
      47,    79,    79,   127,    79,    58,    66,   100,   119,   120,
     126,     5,    47,    47,    80,   319,    47,   326,    81,    82,
      83,    83,    83,   329,   329,    55,    47,    13,   121,   121,
      13,    13,    66,   141,   389,     5,    31,     5,     5,     5,
      47,    47,   152,   332,   332,    17,    18,    62,    63,    64,
     155,   157,   280,     5,   303,     5,    13,   209,    13,   209,
      13,    13,    13,    13,    13,    13,   209,    13,   209,    13,
      13,    13,    13,    13,    30,    97,   158,   262,   263,   267,
     101,   145,   103,   261,    14,    26,    28,     4,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    27,    33,    34,
      35,    36,    37,    38,    39,    40,    42,    43,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    17,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    28,    14,
      14,    47,     6,     6,     6,     6,     4,     6,    33,    34,
      35,    36,    37,    38,     6,     6,     6,     6,     6,     8,
       8,   328,     8,   332,   333,   334,    17,    18,    19,    20,
      22,    23,    27,    39,    40,    42,    43,    17,    18,    19,
      20,    22,    23,    17,   331,    26,    28,     5,   334,   332,
     332,   333,   334,   332,   333,   332,   333,   332,   333,   332,
     333,   332,   333,   331,   332,   331,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,    16,    13,    13,    47,
       5,   331,   332,   333,   334,    58,   332,    13,   121,    13,
       5,    13,    13,    58,    47,   332,   329,   217,   332,    47,
      31,    31,    47,    79,    47,    58,    13,   121,    13,   217,
      47,   217,   217,    55,   332,   334,    84,   334,    47,    16,
      13,    13,    13,   122,   124,    13,     5,     9,    48,   396,
      11,     9,    48,   399,   287,   217,    47,   362,    47,   370,
      47,   332,   217,   291,   217,   314,    13,    13,    13,    13,
      13,    13,   414,     5,     5,   274,   297,     5,    47,   331,
      47,   331,    47,   332,    47,   332,    47,   332,    47,   332,
      47,   332,   332,    47,   332,    47,   332,    47,   332,    47,
     332,    47,   332,    47,   332,    47,   332,    47,   332,    47,
     332,    47,   332,    47,   332,    47,   332,    47,   332,     5,
      24,    25,    47,   333,    47,   333,    47,   333,    47,   333,
     333,    47,   333,    47,   333,    47,   334,   335,   335,   335,
     335,   335,   335,   335,   335,   335,    55,   329,   334,    47,
      55,   332,    13,   124,     9,    48,   400,   332,     6,     6,
     332,    47,   332,    13,   124,     6,   320,   331,   332,   333,
     334,     7,    16,    16,    13,   129,   332,    13,     9,    48,
     397,    31,     6,    15,   341,    31,     6,    15,   217,     6,
     122,     7,   363,   122,     7,   371,   158,   217,   160,   217,
     210,   210,   210,   210,   415,   264,   268,   217,   217,   310,
     337,    55,   443,   332,   124,   125,   332,    31,     6,    15,
      31,     7,   243,   125,   332,   224,   103,   357,    13,    13,
      16,   125,    31,     6,    15,    55,    47,    48,     5,    55,
      47,    48,   288,   230,    47,   148,   364,   365,    47,   150,
     372,   373,   281,   292,   304,    14,   217,   217,   217,    97,
     143,   217,   445,   380,   332,   125,    55,    47,    48,   331,
     332,   333,   334,   239,     7,   125,   131,     5,    13,   359,
     122,    13,    55,    47,    48,     5,    31,     9,    48,   398,
       5,    31,     6,   131,    16,    47,     8,   365,    16,    47,
       8,   373,     5,     6,     5,   315,   416,   265,   269,   275,
     298,    14,   380,   125,     5,    31,   407,   408,   409,   410,
     246,   247,   252,   253,   225,   321,    15,   358,   122,     5,
      31,     9,    48,   381,   385,    55,    31,     6,    15,     9,
      48,   383,   390,    55,   289,   231,   329,   366,   329,   374,
     282,   293,   305,   217,    31,     6,     6,     5,     5,   311,
       9,    48,   384,   391,    55,   380,   380,   380,   380,    91,
     240,   248,   248,    92,   244,   254,   254,   217,   217,    13,
       8,    13,     9,    48,   382,   386,    55,    47,     6,    15,
      55,    47,    48,    47,     6,    15,   217,   217,    14,    14,
     217,   217,   217,    14,   417,   266,   270,   276,   299,   217,
      47,     6,    15,   329,    93,   250,   329,    94,   257,   226,
      14,    47,     6,    15,    31,   379,    48,   342,    31,    31,
      48,   232,   283,   306,   316,   217,   217,   217,   217,   217,
      14,    31,    48,   249,    31,   241,   255,    31,   245,   132,
     322,    31,   393,    48,    55,   380,    47,     5,    55,    55,
      47,   132,     6,     6,   217,   277,   300,   312,    55,    47,
      31,   251,   242,    31,   258,     8,   227,   217,    55,     7,
     395,    47,    31,   343,    31,   233,   284,   307,   317,     6,
       6,   217,    31,   217,   217,     8,   256,   217,    90,   235,
      14,    16,   387,   388,   328,   394,    31,    55,   142,   329,
     347,   348,   349,   350,    55,   235,    14,    14,     6,   278,
     301,   313,    55,   217,   236,   228,   323,   329,     8,   380,
      55,    31,   344,    15,   234,   217,    14,    14,     6,   217,
     133,   237,   217,    31,   387,    55,   345,   142,   350,   237,
     217,   132,   324,    11,     6,    31,     6,   346,    55,   380
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   211,   212,   212,   214,   213,   213,   213,   216,   215,
     215,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     218,   219,   220,   221,   221,   221,   222,   222,   222,   222,
     224,   225,   226,   227,   228,   223,   230,   231,   232,   233,
     234,   229,   235,   236,   235,   237,   239,   240,   241,   242,
     238,   243,   244,   245,   238,   247,   246,   246,   249,   248,
     250,   251,   250,   253,   252,   252,   255,   256,   254,   257,
     258,   257,   260,   259,   259,   259,   259,   259,   259,   261,
     259,   262,   262,   264,   265,   266,   263,   268,   269,   270,
     267,   271,   271,   273,   274,   275,   276,   277,   278,   272,
     280,   281,   282,   283,   284,   279,   285,   285,   287,   288,
     289,   286,   291,   292,   293,   290,   294,   294,   296,   297,
     298,   299,   300,   301,   295,   303,   304,   305,   306,   307,
     302,   309,   310,   311,   312,   313,   308,   314,   315,   316,
     317,   308,   319,   320,   321,   322,   323,   324,   318,   326,
     325,   327,   328,   328,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   330,   330,   331,   331,   331,   331,   331,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   334,   334,   334,   334,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   336,   336,   336,   336,   336,
     337,   336,   336,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   339,
     339,   341,   342,   343,   344,   345,   346,   340,   347,   348,
     349,   349,   349,   349,   350,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   352,   352,   352,   352,   352,
     352,   353,   354,   354,   355,   357,   358,   356,   359,   359,
     360,   362,   361,   363,   364,   364,   366,   365,   367,   368,
     370,   369,   371,   372,   372,   374,   373,   375,   376,   377,
     377,   377,   377,   377,   379,   378,   380,   381,   381,   382,
     382,   383,   383,   384,   384,   385,   385,   386,   386,   387,
     387,   388,   389,   389,   390,   390,   391,   391,   393,   394,
     392,   395,   396,   396,   396,   397,   397,   397,   398,   398,
     398,   399,   399,   399,   400,   400,   400,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   403,   403,   404,
     405,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   407,   406,   408,   406,   409,
     406,   410,   406,   406,   406,   406,   406,   411,   411,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     414,   415,   416,   417,   413,   418,   419,   419,   420,   421,
     421,   421,   421,   422,   423,   423,   423,   424,   425,   426,
     426,   426,   427,   427,   427,   427,   428,   428,   428,   428,
     428,   428,   428,   428,   429,   429,   430,   431,   432,   433,
     433,   433,   433,   433,   434,   435,   435,   435,   435,   436,
     437,   438,   439,   440,   441,   441,   443,   442,   445,   444,
     446,   447,   448,   448,   449,   449,   450,   451,   451,   451,
     451,   451,   451,   451,   452,   452,   452,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     3,     1,     1,     1,     1,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,    14,     0,     0,     4,     1,     0,     0,     0,     0,
      12,     0,     0,     0,    11,     0,     2,     2,     0,     5,
       0,     0,     4,     0,     2,     2,     0,     0,     6,     0,
       0,     4,     0,     2,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     0,     0,     0,     8,     0,     0,     0,
       8,     1,     1,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,    12,     1,     1,     0,     0,
       0,     8,     0,     0,     0,     8,     1,     1,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,    16,     0,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     2,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     1,     3,     2,     3,     1,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       0,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     1,
       3,     0,     0,     0,     0,     0,     0,    17,     1,     1,
       1,     3,     3,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     2,     1,     1,
       1,     5,     6,     4,     5,     0,     0,     8,     1,     3,
       8,     0,     4,     3,     1,     2,     0,     4,     3,     7,
       0,     4,     3,     1,     2,     0,     4,     3,     7,     2,
       2,     2,     1,     1,     0,    10,     0,     1,     6,     1,
       7,     1,     6,     1,     6,     4,     1,     5,     1,     0,
       1,     4,     0,     1,     4,     1,     4,     1,     0,     0,
      13,     3,     1,     3,     5,     1,     3,     5,     1,     3,
       5,     1,     3,     5,     1,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     3,     3,     3,     2,
       4,     4,     4,     2,     3,     3,     3,     3,     4,     3,
       3,     4,     7,     6,     5,     0,     8,     0,     8,     0,
       8,     0,     8,     3,     3,     3,     5,     3,     3,     1,
       2,     2,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     0,     0,     0,     9,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     3,     2,     2,     1,     2,     1,
       2,     3,     2,     3,     4,     4,     4,     2,     3,     2,
       3,     4,     6,     5,     1,     2,     3,     1,     1,     4,
       4,     4,     4,     3,     3,     3,     3,     2,     1,     1,
       4,     4,     2,     1,     1,     1,     0,     5,     0,     6,
       8,     8,     3,     3,     3,     3,     1,     2,     2,     3,
       2,     2,     2,     2,     1,     1,     1,     2,     4,     2,
       4,     3,     2,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     2,     4,     3,
       2,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 3: /* input: input line  */
#line 1019 "pnfha.ypp"
                     { ASTNode start("START"); tree.add_node(start); }
#line 3865 "pnfha.tab.cpp"
    break;

  case 4: /* $@1: %empty  */
#line 1022 "pnfha.ypp"
        {
	 ASTNode line("line");
         tree.add_node(line);
	}
#line 3874 "pnfha.tab.cpp"
    break;

  case 7: /* line: error  */
#line 1028 "pnfha.ypp"
                        { yyerrok; }
#line 3880 "pnfha.tab.cpp"
    break;

  case 8: /* $@2: %empty  */
#line 1031 "pnfha.ypp"
                {
		 ASTNode statement("statement");
  		 tree.add_node(statement);
		}
#line 3889 "pnfha.tab.cpp"
    break;

  case 11: /* stmt: control_statement  */
#line 1039 "pnfha.ypp"
                                  { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1; 
		    	                    statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3896 "pnfha.tab.cpp"
    break;

  case 12: /* stmt: SEND  */
#line 1041 "pnfha.ypp"
                       { conprint("VOID TVOID 0V\n"); statementoutcount.insert(); 
                         statementoutcount[statementoutcount.length() - 1] = outcount - 1; statementlineno.insert(); statementlineno[statementlineno.length() - 1]                          = yylineno; }
#line 3903 "pnfha.tab.cpp"
    break;

  case 13: /* stmt: expression_statement  */
#line 1043 "pnfha.ypp"
                                        { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					  statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3910 "pnfha.tab.cpp"
    break;

  case 14: /* stmt: declaration_statement  */
#line 1045 "pnfha.ypp"
                                         { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
					   statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3917 "pnfha.tab.cpp"
    break;

  case 15: /* stmt: label_statement  */
#line 1047 "pnfha.ypp"
                                   { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3924 "pnfha.tab.cpp"
    break;

  case 16: /* stmt: command_statement  */
#line 1049 "pnfha.ypp"
                                     { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				       statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; }
#line 3931 "pnfha.tab.cpp"
    break;

  case 17: /* stmt: statement_block  */
#line 1051 "pnfha.ypp"
                                   { statementoutcount.insert(); statementoutcount[statementoutcount.length() - 1] = outcount - 1;
				     statementlineno.insert(); statementlineno[statementlineno.length() - 1] = yylineno; inblock = true;
				   }
#line 3939 "pnfha.tab.cpp"
    break;

  case 20: /* expression_statement: expression SEND  */
#line 1059 "pnfha.ypp"
                        {
			 ASTNode expression_statement("expression_statement");
			 tree.add_node(expression_statement);
			}
#line 3948 "pnfha.tab.cpp"
    break;

  case 21: /* declaration_statement: declaration SEND  */
#line 1066 "pnfha.ypp"
                        {
			 ASTNode declaration_statement("declaration_statement");
			 tree.add_node(declaration_statement);
			}
#line 3957 "pnfha.tab.cpp"
    break;

  case 22: /* command_statement: command SEND  */
#line 1073 "pnfha.ypp"
                        {
			 ASTNode command_statement("command_statement");
			 tree.add_node(command_statement);
			}
#line 3966 "pnfha.tab.cpp"
    break;

  case 23: /* label_statement: ID OPCOLON  */
#line 1080 "pnfha.ypp"
                        {
			 ASTNode label_statement("label_statement");

			 bool declared = false;
			 String str;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  str = labelTable[i].name();
			  if (yyvsp[-1].to_string().get().getString() == labelTable[i].name().getString())
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
#line 4003 "pnfha.tab.cpp"
    break;

  case 24: /* label_statement: SUB ID OPCOLON  */
#line 1113 "pnfha.ypp"
                        {
			 ASTNode label_statement("label_statement");

			 conprint("LBL TVOID 0V\n");

			 tree.add_node(label_statement);
			}
#line 4015 "pnfha.tab.cpp"
    break;

  case 25: /* label_statement: EVENT ID OPCOLON  */
#line 1121 "pnfha.ypp"
                        {
			 ASTNode label_statement("label_statement");

			 conprint("ELBL TVOID 0V\n");

			 tree.add_node(label_statement);
			}
#line 4027 "pnfha.tab.cpp"
    break;

  case 26: /* control_statement: if_statement  */
#line 1131 "pnfha.ypp"
                        {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			}
#line 4037 "pnfha.tab.cpp"
    break;

  case 27: /* control_statement: unless_statement  */
#line 1137 "pnfha.ypp"
                        {
			 ASTNode control_statement("control_statement");
			
			 tree.add_node(control_statement);
			}
#line 4047 "pnfha.tab.cpp"
    break;

  case 28: /* control_statement: switch_statement  */
#line 1143 "pnfha.ypp"
                        {
			 ASTNode control_statement("control_statement");
			 tree.add_node(control_statement);
			}
#line 4056 "pnfha.tab.cpp"
    break;

  case 29: /* control_statement: loop_statement  */
#line 1148 "pnfha.ypp"
                        {
			 ASTNode control_statement("control_statement");

			 breakinforever = false;

			 tree.add_node(control_statement);
			}
#line 4068 "pnfha.tab.cpp"
    break;

  case 30: /* $@3: %empty  */
#line 1158 "pnfha.ypp"
                        {
			 ASTNode if_statementp1("if_statementp1");

			 tree.add_node(if_statementp1);		
			}
#line 4078 "pnfha.tab.cpp"
    break;

  case 31: /* $@4: %empty  */
#line 1164 "pnfha.ypp"
                        {			 
			 ASTNode if_statementp2("if_statementp2");
			
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			}
#line 4091 "pnfha.tab.cpp"
    break;

  case 32: /* $@5: %empty  */
#line 1173 "pnfha.ypp"
                        {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			}
#line 4102 "pnfha.tab.cpp"
    break;

  case 33: /* $@6: %empty  */
#line 1180 "pnfha.ypp"
                        {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			}
#line 4111 "pnfha.tab.cpp"
    break;

  case 34: /* $@7: %empty  */
#line 1185 "pnfha.ypp"
                        {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			}
#line 4121 "pnfha.tab.cpp"
    break;

  case 35: /* if_statement: IF LEFTP stmt RIGHTP $@3 THEN $@4 stmt $@5 ENDIF $@6 opt_else $@7 eif  */
#line 1191 "pnfha.ypp"
                        {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			}
#line 4133 "pnfha.tab.cpp"
    break;

  case 36: /* $@8: %empty  */
#line 1201 "pnfha.ypp"
                        {
			 ASTNode if_statementp1("if_statementp1");

			 conprint("NOT TVOID 0V\n");	

			 tree.add_node(if_statementp1);		
			}
#line 4145 "pnfha.tab.cpp"
    break;

  case 37: /* $@9: %empty  */
#line 1209 "pnfha.ypp"
                        {			 
			 ASTNode if_statementp2("if_statementp2");
		
			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(if_statementp2);
			}
#line 4158 "pnfha.tab.cpp"
    break;

  case 38: /* $@10: %empty  */
#line 1218 "pnfha.ypp"
                        {
			 ASTNode if_statementp3("if_statementp3");
			 // Code for if will be inserted here...
			
			 tree.add_node(if_statementp3);
			}
#line 4169 "pnfha.tab.cpp"
    break;

  case 39: /* $@11: %empty  */
#line 1225 "pnfha.ypp"
                        {
			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIF TVOID 0V\n");
			}
#line 4178 "pnfha.tab.cpp"
    break;

  case 40: /* $@12: %empty  */
#line 1230 "pnfha.ypp"
                        {
			 ASTNode if_statementp6("if_statementp6");

			 tree.add_node(if_statementp6);
			}
#line 4188 "pnfha.tab.cpp"
    break;

  case 41: /* unless_statement: UNLESS LEFTP stmt RIGHTP $@8 THEN $@9 stmt $@10 ENDIF $@11 opt_else $@12 eif  */
#line 1236 "pnfha.ypp"
                        {
			 ASTNode if_statementp4("if_statementp4");

			 conprint("EIF TVOID 0V\n");

			 tree.add_node(if_statementp4);
			}
#line 4200 "pnfha.tab.cpp"
    break;

  case 43: /* $@13: %empty  */
#line 1246 "pnfha.ypp"
                        {
			 ASTNode if_statementp5("if_statementp5");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 // Code for else will be inserted here if exists...
			 tree.add_node(if_statementp5);
			}
#line 4214 "pnfha.tab.cpp"
    break;

  case 44: /* opt_else: ELSE $@13 stmt ENDIF  */
#line 1257 "pnfha.ypp"
                        {
			 ASTNode if_statementp7("if_statementp7");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");

			 tree.add_node(if_statementp7);
			}
#line 4227 "pnfha.tab.cpp"
    break;

  case 46: /* $@14: %empty  */
#line 1271 "pnfha.ypp"
                        {
			 ASTNode switch_statementp1("switch_statementp1");

			 switchfound = true;
			 ++switchcounter;
			 switchcasecounter = 0;
			 inswitch = true;

			 switch (exptype)
			 {
			  case TBOOLEAN:
			   conprint("ALOAD TBOOLEAN %s\n", yyvsp[-2].to_string().get().getString().c_str());
			   switchexptype = TBOOLEAN;
     			   break;

			  case TNUMBER:
			   conprint("ALOAD TNUMBER %s\n", yyvsp[-2].to_string().get().getString().c_str());
			   switchexptype = TNUMBER;
			   break;

			  case TCHARACTER:
			   conprint("ALOAD TCHARACTER %s\n", yyvsp[-2].to_string().get().getString().c_str());
			   switchexptype = TCHARACTER;
			   break;

			  case TSTRING:
			   conprint("ALOAD TSTRING %s\n", yyvsp[-2].to_string().get().getString().c_str());
			   switchexptype = TSTRING;
			   break;

			  default:
			   yyerror("Invalid switch statement.");
			 }
			 conprint("SWITCH2 TVOID 0V\n");
                         conprint("SWBEGIN TVOID 0V\n");

			 tree.add_node(switch_statementp1);
			}
#line 4270 "pnfha.tab.cpp"
    break;

  case 47: /* $@15: %empty  */
#line 1310 "pnfha.ypp"
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
#line 4303 "pnfha.tab.cpp"
    break;

  case 48: /* $@16: %empty  */
#line 1339 "pnfha.ypp"
                        {
			 ASTNode switch_statementp3("switch_statementp3");

			 tree.add_node(switch_statementp3);
			}
#line 4313 "pnfha.tab.cpp"
    break;

  case 49: /* $@17: %empty  */
#line 1344 "pnfha.ypp"
                        {

			}
#line 4321 "pnfha.tab.cpp"
    break;

  case 50: /* switch_statement: SWITCH LEFTP expression RIGHTP LEFTB $@14 case_statements $@15 opt_default_statement $@16 $@17 RIGHTB  */
#line 1348 "pnfha.ypp"
                        {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			}
#line 4333 "pnfha.tab.cpp"
    break;

  case 51: /* $@18: %empty  */
#line 1356 "pnfha.ypp"
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
#line 4351 "pnfha.tab.cpp"
    break;

  case 52: /* $@19: %empty  */
#line 1371 "pnfha.ypp"
                        {
			 ASTNode switch_statementp2("switch_statementp2");
			 
			 tree.add_node(switch_statementp2);
			}
#line 4361 "pnfha.tab.cpp"
    break;

  case 53: /* $@20: %empty  */
#line 1377 "pnfha.ypp"
                        {
			 ASTNode switch_statementp3("switch_statementp3");
			 tree.add_node(switch_statementp3);
			}
#line 4370 "pnfha.tab.cpp"
    break;

  case 54: /* switch_statement: CSWITCH LEFTP stmt RIGHTP $@18 LEFTB case_statements2 $@19 opt_default_statement2 $@20 RIGHTB  */
#line 1382 "pnfha.ypp"
                        {
			 ASTNode switch_statementp4("switch_statementp4");

			 conprint("SWEND TVOID 0V\n");

			 tree.add_node(switch_statementp4);
			}
#line 4382 "pnfha.tab.cpp"
    break;

  case 55: /* $@21: %empty  */
#line 1391 "pnfha.ypp"
                        {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			}
#line 4391 "pnfha.tab.cpp"
    break;

  case 58: /* $@22: %empty  */
#line 1400 "pnfha.ypp"
                        {
			 ASTNode case_statement("case_statement");

			 ++switchcasecounter;

			 if (switchexptype != exptype)
			  yyerror("Non-Matching Switch Expression");

			 
 			 switch (exptype)
			 {
			  case TBOOLEAN:
			   conprint("SWCASE TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

			  case TNUMBER:
			   conprint("SWCASE TNUMBER %g\n", yyvsp[0].to_number().get());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

			  case TCHARACTER:
			   conprint("SWCASE TCHARCTER %c\n", yyvsp[0].to_character().get());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

		 	  case TSTRING:
			   conprint("SWCASE TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			   conprint ("SWCBEGIN TVOID 0V\n");
			   break;

			  default:
			   yyerror("Invalid switch statement.");
			};

			 tree.add_node(case_statement);
			}
#line 4433 "pnfha.tab.cpp"
    break;

  case 59: /* case_statement: CASE expression $@22 OPCOLON stmt  */
#line 1438 "pnfha.ypp"
                        {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 4441 "pnfha.tab.cpp"
    break;

  case 61: /* $@23: %empty  */
#line 1444 "pnfha.ypp"
                        {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			}
#line 4450 "pnfha.tab.cpp"
    break;

  case 62: /* opt_default_statement: DEFAULT OPCOLON $@23 stmt  */
#line 1449 "pnfha.ypp"
                        {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 4458 "pnfha.tab.cpp"
    break;

  case 63: /* $@24: %empty  */
#line 1454 "pnfha.ypp"
                        {
			 ASTNode case_statements("case_statements");
			 tree.add_node(case_statements);
			}
#line 4467 "pnfha.tab.cpp"
    break;

  case 66: /* $@25: %empty  */
#line 1463 "pnfha.ypp"
                        {
			 ASTNode case_statementp1("case_statement");

			 ++switchcasecounter;

			 switch (exptype)
			 {
			  case TBOOLEAN:
			   conprint("SWCASE TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("SWCASE TNUMBER %g\n", yyvsp[0].to_number().get());
			   break;

			  case TCHARACTER:
			   conprint("SWCASE TCHARACTER %c\n", yyvsp[0].to_character().get());
			   break;

			  case TSTRING:
			   conprint("SWCASE TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid type.");
			 }
			 conprint("SWCBEGIN TVOID 0V\n");
			
			 tree.add_node(case_statementp1);
			}
#line 4502 "pnfha.tab.cpp"
    break;

  case 67: /* $@26: %empty  */
#line 1494 "pnfha.ypp"
                        {
			 ASTNode case_statementp2("case_statementp2");

			 tree.add_node(case_statementp2);
			}
#line 4512 "pnfha.tab.cpp"
    break;

  case 68: /* case_statement2: CCASE expression $@25 OPCOLON $@26 stmt  */
#line 1500 "pnfha.ypp"
                        {
			 ASTNode case_statementp3("case_statementp3");

			 conprint("SWCEND TVOID 0V\n");

			 tree.add_node(case_statementp3);
			}
#line 4524 "pnfha.tab.cpp"
    break;

  case 70: /* $@27: %empty  */
#line 1510 "pnfha.ypp"
                        {
			 conprint("SWDEFAULT TVOID 0V\n");
			 conprint("SWCBEGIN TVOID 0V\n");
			}
#line 4533 "pnfha.tab.cpp"
    break;

  case 71: /* opt_default_statement2: CDEFAULT OPCOLON $@27 stmt  */
#line 1515 "pnfha.ypp"
                        {
			 conprint("SWCEND TVOID 0V\n");
			}
#line 4541 "pnfha.tab.cpp"
    break;

  case 72: /* $@28: %empty  */
#line 1521 "pnfha.ypp"
            {
			 loopexpr = true;
			 inloop2 = true;
			}
#line 4550 "pnfha.tab.cpp"
    break;

  case 73: /* loop_statement: $@28 while_loop  */
#line 1526 "pnfha.ypp"
                        {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 4559 "pnfha.tab.cpp"
    break;

  case 74: /* loop_statement: whileb_loop  */
#line 1531 "pnfha.ypp"
                        {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 4568 "pnfha.tab.cpp"
    break;

  case 75: /* loop_statement: until_loop  */
#line 1536 "pnfha.ypp"
                        {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 4577 "pnfha.tab.cpp"
    break;

  case 76: /* loop_statement: untilb_loop  */
#line 1541 "pnfha.ypp"
                        {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 4586 "pnfha.tab.cpp"
    break;

  case 77: /* loop_statement: for_loop  */
#line 1546 "pnfha.ypp"
                        {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 4595 "pnfha.tab.cpp"
    break;

  case 78: /* loop_statement: forb_loop  */
#line 1551 "pnfha.ypp"
                        {
			 ASTNode loop_statement("loop_statement");
			 tree.add_node(loop_statement);
			}
#line 4604 "pnfha.tab.cpp"
    break;

  case 79: /* $@29: %empty  */
#line 1556 "pnfha.ypp"
                        {
			 ASTNode loop_statement("loop_statement");
			 
			 loopexpr = false;
			 inloop = true;		 

			 tree.add_node(loop_statement);
			}
#line 4617 "pnfha.tab.cpp"
    break;

  case 80: /* loop_statement: forever_loop $@29  */
#line 1564 "pnfha.ypp"
                        {
			 inloop2 = false;
			 inwhile = false;
			 indowhile = false;
			 infor2 = false;
			 indofor = false;
			 inforever = false;
			}
#line 4630 "pnfha.tab.cpp"
    break;

  case 83: /* $@30: %empty  */
#line 1579 "pnfha.ypp"
                        {
			 ASTNode while_loopp1("while_loopp1");

			 inwhile = true;
			 ++whilecounter;
			 conprint("LBL TSTRING \"while_test_%u\"\n", whilecounter);

			 tree.add_node(while_loopp1);
			}
#line 4644 "pnfha.tab.cpp"
    break;

  case 84: /* $@31: %empty  */
#line 1589 "pnfha.ypp"
                        {
			 ASTNode while_loopp2("while_loopp2");

			 tree.add_node(while_loopp2);
			}
#line 4654 "pnfha.tab.cpp"
    break;

  case 85: /* $@32: %empty  */
#line 1595 "pnfha.ypp"
                        {
			 ASTNode while_loopp3("while_loopp3");

			 conprint("CGOTOL TSTRING \"while_body_%u\"\n", whilecounter);
			 conprint("GOTOL TSTRING \"while_end_%u\"\n", whilecounter);

			 conprint("LBL TSTRING \"while_body_%u\"\n", whilecounter);

			 tree.add_node(while_loopp3);
			}
#line 4669 "pnfha.tab.cpp"
    break;

  case 86: /* whilec_loop1: WHILEC LEFTP $@30 stmt $@31 RIGHTP $@32 stmt  */
#line 1606 "pnfha.ypp"
                        {
			 ASTNode while_loopp4("while_loopp4");

			 conprint("GOTOL TSTRING \"while_test_%u\"\n", whilecounter);
			 conprint("LBL TSTRING \"while_end_%u\"\n", whilecounter);

			 tree.add_node(while_loopp4);
			}
#line 4682 "pnfha.tab.cpp"
    break;

  case 87: /* $@33: %empty  */
#line 1617 "pnfha.ypp"
                        {
			 ASTNode while_loopp1("while_loopp1");

			 inwhile = true;
			 ++whilecounter;
            
             conprint("LOOP TVOID 0V\n");

			 tree.add_node(while_loopp1);
			}
#line 4697 "pnfha.tab.cpp"
    break;

  case 88: /* $@34: %empty  */
#line 1628 "pnfha.ypp"
                        {
			 ASTNode while_loopp2("while_loopp2");

			 tree.add_node(while_loopp2);
			}
#line 4707 "pnfha.tab.cpp"
    break;

  case 89: /* $@35: %empty  */
#line 1634 "pnfha.ypp"
                        {
			 ASTNode while_loopp3("while_loopp3");

			 conprint("ELOOP TVOID 0V\n");
             conprint("WHILE TVOID 0V\n");
             
             conprint("WHILEB TVOID 0V\n");

			 tree.add_node(while_loopp3);
			}
#line 4722 "pnfha.tab.cpp"
    break;

  case 90: /* while_loop1: WHILE LEFTP $@33 stmt $@34 RIGHTP $@35 stmt  */
#line 1645 "pnfha.ypp"
                        {
			 ASTNode while_loopp4("while_loopp4");

			 conprint("WHILEE TVOID 0V\n");

			 tree.add_node(while_loopp4);
			}
#line 4734 "pnfha.tab.cpp"
    break;

  case 93: /* $@36: %empty  */
#line 1659 "pnfha.ypp"
            {
			 ASTNode do_while_loopp1("do_while_loopp1");

			 indowhile = true;
			 ++dowhilecounter;
			 conprint("LBL TSTRING \"do_while_body_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp1);
			}
#line 4748 "pnfha.tab.cpp"
    break;

  case 94: /* $@37: %empty  */
#line 1669 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp2("do_while_loopp2");

			 tree.add_node(do_while_loopp2);
			}
#line 4758 "pnfha.tab.cpp"
    break;

  case 95: /* $@38: %empty  */
#line 1676 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp3("do_while_loopp3");

			 conprint("LBL TSTRING \"do_while_test_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp3);
			}
#line 4770 "pnfha.tab.cpp"
    break;

  case 96: /* $@39: %empty  */
#line 1684 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp4("do_while_loopp4");

			 tree.add_node(do_while_loopp4);
			}
#line 4780 "pnfha.tab.cpp"
    break;

  case 97: /* $@40: %empty  */
#line 1690 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp5("do_while_loopp5");

			 conprint("CGOTOL TSTRING \"do_while_body_%u\"\n", dowhilecounter);
			 conprint("GOTOL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp5);
			}
#line 4793 "pnfha.tab.cpp"
    break;

  case 98: /* $@41: %empty  */
#line 1699 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp6("do_while_loopp6");

			 conprint("LBL TSTRING \"do_while_end_%u\"\n", dowhilecounter);

			 tree.add_node(do_while_loopp6);
			}
#line 4805 "pnfha.tab.cpp"
    break;

  case 99: /* whilebc_loop1: $@36 DOWHILEC $@37 stmt WHILEC $@38 LEFTP $@39 stmt $@40 RIGHTP $@41 SEND  */
#line 1707 "pnfha.ypp"
            {
             loopexpr = false;
            }
#line 4813 "pnfha.tab.cpp"
    break;

  case 100: /* $@42: %empty  */
#line 1713 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp2("do_while_loopp2");

             conprint("WHILEBBB TVOID 0V\n");

			 tree.add_node(do_while_loopp2);
			}
#line 4825 "pnfha.tab.cpp"
    break;

  case 101: /* $@43: %empty  */
#line 1722 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp3("do_while_loopp3");

			 conprint("WHILEBBE TVOID 0V\n");

			 tree.add_node(do_while_loopp3);
			}
#line 4837 "pnfha.tab.cpp"
    break;

  case 102: /* $@44: %empty  */
#line 1730 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp4("do_while_loopp4");

             conprint("LOOP TVOID 0V\n");

			 tree.add_node(do_while_loopp4);
			}
#line 4849 "pnfha.tab.cpp"
    break;

  case 103: /* $@45: %empty  */
#line 1738 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp5("do_while_loopp5");

			 tree.add_node(do_while_loopp5);
			}
#line 4859 "pnfha.tab.cpp"
    break;

  case 104: /* $@46: %empty  */
#line 1744 "pnfha.ypp"
                        {
			 ASTNode do_while_loopp6("do_while_loopp6");

			 conprint("ELOOP TVOID 0V\n");
             conprint("WHILEBB TVOID 0V\n");

			 tree.add_node(do_while_loopp6);
			}
#line 4872 "pnfha.tab.cpp"
    break;

  case 105: /* whileb_loop1: DOWHILE $@42 stmt WHILE $@43 LEFTP $@44 stmt $@45 RIGHTP $@46 SEND  */
#line 1753 "pnfha.ypp"
            {
             loopexpr = false;
            }
#line 4880 "pnfha.tab.cpp"
    break;

  case 108: /* $@47: %empty  */
#line 1764 "pnfha.ypp"
                        {
			 ASTNode until_loopp1("until_loopp1");

			 inuntil = true;
			 ++untilcounter;
			 conprint("LBL TSTRING \"until_test_%u\"\n", untilcounter);

			 tree.add_node(until_loopp1);
			}
#line 4894 "pnfha.tab.cpp"
    break;

  case 109: /* $@48: %empty  */
#line 1774 "pnfha.ypp"
                        {
			 ASTNode until_loopp2("until_loopp2");

			 tree.add_node(until_loopp2);
			}
#line 4904 "pnfha.tab.cpp"
    break;

  case 110: /* $@49: %empty  */
#line 1780 "pnfha.ypp"
                        {
			 ASTNode until_loopp3("until_loopp3");


			 conprint("NOT TVOID 0V\n");

			 conprint("CGOTOL TSTRING \"until_body_%u\"\n", untilcounter);
			 conprint("GOTOL TSTRING \"until_end_%u\"\n", untilcounter);

			 conprint("LBL TSTRING \"until_body_%u\"\n", untilcounter);

			 tree.add_node(until_loopp3);
			}
#line 4922 "pnfha.tab.cpp"
    break;

  case 111: /* untilc_loop1: UNTILC LEFTP $@47 stmt $@48 RIGHTP $@49 stmt  */
#line 1794 "pnfha.ypp"
                        {
			 ASTNode until_loopp4("until_loopp4");

			 conprint("GOTOL TSTRING \"until_test_%u\"\n", untilcounter);
			 conprint("LBL TSTRING \"until_end_%u\"\n", untilcounter);

			 tree.add_node(until_loopp4);
			}
#line 4935 "pnfha.tab.cpp"
    break;

  case 112: /* $@50: %empty  */
#line 1806 "pnfha.ypp"
                        {
			 ASTNode until_loopp1("until_loopp1");

			 inuntil = true;
			 ++untilcounter;
			 conprint("LOOP TVOID 0V\n");

			 tree.add_node(until_loopp1);
			}
#line 4949 "pnfha.tab.cpp"
    break;

  case 113: /* $@51: %empty  */
#line 1816 "pnfha.ypp"
                        {
			 ASTNode until_loopp2("until_loopp2");

			 tree.add_node(until_loopp2);
			}
#line 4959 "pnfha.tab.cpp"
    break;

  case 114: /* $@52: %empty  */
#line 1822 "pnfha.ypp"
                        {
			 ASTNode until_loopp3("until_loopp3");


			 conprint("ELOOP TVOID 0V\n");

			 conprint("UNTIL TVOID 0V\n");
			 conprint("UNTILB TVOID 0V\n");

			 tree.add_node(until_loopp3);
			}
#line 4975 "pnfha.tab.cpp"
    break;

  case 115: /* until_loop1: UNTIL LEFTP $@50 stmt $@51 RIGHTP $@52 stmt  */
#line 1834 "pnfha.ypp"
                        {
			 ASTNode until_loopp4("until_loopp4");

			 conprint("UNTILE TVOID 0V\n");

			 tree.add_node(until_loopp4);
			}
#line 4987 "pnfha.tab.cpp"
    break;

  case 118: /* $@53: %empty  */
#line 1848 "pnfha.ypp"
                {
			 ASTNode do_until_loopp1("do_until_loopp1");

			 indountil = true;
			 ++dountilcounter;
			 conprint("LBL TSTRING \"do_until_body_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp1);
			}
#line 5001 "pnfha.tab.cpp"
    break;

  case 119: /* $@54: %empty  */
#line 1858 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp2("do_until_loopp2");

			 tree.add_node(do_until_loopp2);
			}
#line 5011 "pnfha.tab.cpp"
    break;

  case 120: /* $@55: %empty  */
#line 1865 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp3("do_until_loopp3");

			 conprint("LBL TSTRING \"do_until_test_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp3);
			}
#line 5023 "pnfha.tab.cpp"
    break;

  case 121: /* $@56: %empty  */
#line 1873 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp4("do_until_loopp4");

			 tree.add_node(do_until_loopp4);
			}
#line 5033 "pnfha.tab.cpp"
    break;

  case 122: /* $@57: %empty  */
#line 1879 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp5("do_until_loopp5");

			 conprint("CGOTOL TSTRING \"do_until_body_%u\"\n", dountilcounter);
			 conprint("GOTOL TSTRING \"do_until_end_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp5);
			}
#line 5046 "pnfha.tab.cpp"
    break;

  case 123: /* $@58: %empty  */
#line 1888 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp6("do_until_loopp6");

			 conprint("NOT TVOID 0V\n");

			 conprint("LBL TSTRING \"do_until_end_%u\"\n", dountilcounter);

			 tree.add_node(do_until_loopp6);
			}
#line 5060 "pnfha.tab.cpp"
    break;

  case 124: /* untilbc_loop1: $@53 DOUNTILC $@54 stmt UNTILC $@55 LEFTP $@56 stmt $@57 RIGHTP $@58 SEND  */
#line 1898 "pnfha.ypp"
            {
             loopexpr = false;
            }
#line 5068 "pnfha.tab.cpp"
    break;

  case 125: /* $@59: %empty  */
#line 1905 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp2("do_until_loopp2");

             conprint("UNTILBBB TVOID 0V\n");

			 tree.add_node(do_until_loopp2);
			}
#line 5080 "pnfha.tab.cpp"
    break;

  case 126: /* $@60: %empty  */
#line 1914 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp3("do_until_loopp3");

			 conprint("UNTILBBE TVOID 0V\n");

			 tree.add_node(do_until_loopp3);
			}
#line 5092 "pnfha.tab.cpp"
    break;

  case 127: /* $@61: %empty  */
#line 1922 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp4("do_until_loopp4");

             conprint("LOOP TVOID 0V\n");

			 tree.add_node(do_until_loopp4);
			}
#line 5104 "pnfha.tab.cpp"
    break;

  case 128: /* $@62: %empty  */
#line 1930 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp5("do_until_loopp5");

			 tree.add_node(do_until_loopp5);
			}
#line 5114 "pnfha.tab.cpp"
    break;

  case 129: /* $@63: %empty  */
#line 1936 "pnfha.ypp"
                        {
			 ASTNode do_until_loopp6("do_until_loopp6");

			 conprint("ELOOP TVOID 0V\n");

			 conprint("UNTILBB TVOID 0V\n");

			 tree.add_node(do_until_loopp6);
			}
#line 5128 "pnfha.tab.cpp"
    break;

  case 130: /* untilb_loop1: DOUNTIL $@59 stmt UNTIL $@60 LEFTP $@61 stmt $@62 RIGHTP $@63 SEND  */
#line 1946 "pnfha.ypp"
            {
             loopexpr = false;
            }
#line 5136 "pnfha.tab.cpp"
    break;

  case 131: /* $@64: %empty  */
#line 1951 "pnfha.ypp"
                        {
			 infor = true;
			}
#line 5144 "pnfha.tab.cpp"
    break;

  case 132: /* $@65: %empty  */
#line 1955 "pnfha.ypp"
                        {
			 ASTNode for_loopp1("for_loopp1");

			 infor2 = true;
			 ++forcounter;
			 conprint("LBL TSTRING \"for_initialization_%u\"\n", forcounter);

			 tree.add_node(for_loopp1);
			}
#line 5158 "pnfha.tab.cpp"
    break;

  case 133: /* $@66: %empty  */
#line 1965 "pnfha.ypp"
                        {
			 ASTNode for_loopp2("for_loopp2");

			 conprint("LBL TSTRING \"for_condition_%u\"\n", forcounter);

			 tree.add_node(for_loopp2);
			}
#line 5170 "pnfha.tab.cpp"
    break;

  case 134: /* $@67: %empty  */
#line 1973 "pnfha.ypp"
                        {
			 ASTNode for_loopp3("for_loopp3");

			 conprint("CGOTOL TSTRING \"for_body_%u\"\n", forcounter);
			 conprint("GOTOL TSTRING \"for_end_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_increment_statement_%u\"\n", forcounter);

			 tree.add_node(for_loopp3);
			}
#line 5184 "pnfha.tab.cpp"
    break;

  case 135: /* $@68: %empty  */
#line 1983 "pnfha.ypp"
                        {
			 ASTNode for_loopp4("for_loopp4");

			 conprint("GOTOL TSTRING \"for_condition_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_body_%u\"\n", forcounter);

			 tree.add_node(for_loopp4);
			}
#line 5197 "pnfha.tab.cpp"
    break;

  case 136: /* for_loop: $@64 FORC LEFTP $@65 stmt SEND $@66 stmt SEND $@67 stmt $@68 RIGHTP stmt  */
#line 1992 "pnfha.ypp"
                        {
			 ASTNode for_loopp5("for_loopp5");

			 conprint("GOTOL TSTRING \"for_increment_statement_%u\"\n", forcounter);
			 conprint("LBL TSTRING \"for_end_%u\"\n", forcounter);

			 tree.add_node(for_loopp5);
			}
#line 5210 "pnfha.tab.cpp"
    break;

  case 137: /* $@69: %empty  */
#line 2001 "pnfha.ypp"
                        {
			 ASTNode for_loopp1("for_loopp1");

			 infor2 = true;
			 ++forcounter;
			 conprint("FOR TVOID 0V\n");

			 tree.add_node(for_loopp1);
			}
#line 5224 "pnfha.tab.cpp"
    break;

  case 138: /* $@70: %empty  */
#line 2011 "pnfha.ypp"
                        {
			 ASTNode for_loopp2("for_loopp2");

			 conprint("FORINIT TVOID 0V\n");

			 tree.add_node(for_loopp2);
			}
#line 5236 "pnfha.tab.cpp"
    break;

  case 139: /* $@71: %empty  */
#line 2019 "pnfha.ypp"
                        {
			 ASTNode for_loopp3("for_loopp3");

			 conprint("FORCOND TVOID 0V\n");

			 tree.add_node(for_loopp3);
			}
#line 5248 "pnfha.tab.cpp"
    break;

  case 140: /* $@72: %empty  */
#line 2027 "pnfha.ypp"
                        {
			 ASTNode for_loopp4("for_loopp4");

			 conprint("FORINC TVOID 0V\n");
			 conprint("FORB TVOID 0V\n");

			 tree.add_node(for_loopp4);
			}
#line 5261 "pnfha.tab.cpp"
    break;

  case 141: /* for_loop: FOR LEFTP $@69 stmt SEND $@70 stmt SEND $@71 stmt $@72 RIGHTP stmt  */
#line 2036 "pnfha.ypp"
                        {
			 ASTNode for_loopp5("for_loopp5");

			 conprint("FORE TVOID 0V\n");

			 tree.add_node(for_loopp5);
			}
#line 5273 "pnfha.tab.cpp"
    break;

  case 142: /* $@73: %empty  */
#line 2046 "pnfha.ypp"
                        {
			 ASTNode forb_loopp1("forb_loopp1");

			 indofor = true;
			 infor = true;
			 ++doforcounter;

			 conprint("GOTOL TSTRING \"dofor_initialization_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_body_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp1);
			}
#line 5290 "pnfha.tab.cpp"
    break;

  case 143: /* $@74: %empty  */
#line 2059 "pnfha.ypp"
                        {
			 ASTNode forb_loopp2("forb_loopp2");

			 conprint("GOTOL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_initialization_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp2);
			}
#line 5303 "pnfha.tab.cpp"
    break;

  case 144: /* $@75: %empty  */
#line 2068 "pnfha.ypp"
                        {
			 ASTNode forb_loopp3("forb_loopp3");

			 tree.add_node(forb_loopp3);
			}
#line 5313 "pnfha.tab.cpp"
    break;

  case 145: /* $@76: %empty  */
#line 2074 "pnfha.ypp"
                        {
			 ASTNode forb_loopp4("forb_loopp4");

			 conprint("GOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_condition_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp4);
			}
#line 5326 "pnfha.tab.cpp"
    break;

  case 146: /* $@77: %empty  */
#line 2083 "pnfha.ypp"
                        {
			 ASTNode forb_loopp5("forb_loopp5");

			 conprint("CGOTOL TSTRING \"dofor_body_%u\"\n", doforcounter);
			 conprint("GOTOL TSTRING \"dofor_end_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_increment_statement_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp5);
			}
#line 5340 "pnfha.tab.cpp"
    break;

  case 147: /* $@78: %empty  */
#line 2093 "pnfha.ypp"
                        {
			 ASTNode forb_loopp6("forb_loopp6");
			 tree.add_node(forb_loopp6);
			}
#line 5349 "pnfha.tab.cpp"
    break;

  case 148: /* forb_loop: DOFORC $@73 stmt $@74 FORC LEFTP $@75 stmt SEND $@76 stmt SEND $@77 stmt $@78 RIGHTP  */
#line 2098 "pnfha.ypp"
                        {
			 ASTNode forb_loopp7("forb_loopp7");

			 conprint("GOTOL TSTRING \"dofor_condition_%u\"\n", doforcounter);
			 conprint("LBL TSTRING \"dofor_end_%u\"\n", doforcounter);

			 tree.add_node(forb_loopp7);
			}
#line 5362 "pnfha.tab.cpp"
    break;

  case 149: /* $@79: %empty  */
#line 2109 "pnfha.ypp"
                        {
			 ASTNode forever_loopp1("forever_loopp1");

			 breakinforever = true;
			 ++forevercounter;
			 conprint("LBL TSTRING \"forever_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp1);			
			}
#line 5376 "pnfha.tab.cpp"
    break;

  case 150: /* forever_loop: FOREVERC $@79 stmt  */
#line 2119 "pnfha.ypp"
                        {
			 ASTNode forever_loopp2("forever_loopp2");

			 conprint("GOTOL TSTRING \"forever_%u\"\n", forevercounter);
			 conprint("LBL TSTRING \"forever_end_%u\"\n", forevercounter);

			 tree.add_node(forever_loopp2);			
			}
#line 5389 "pnfha.tab.cpp"
    break;

  case 151: /* statement_block: LEFTB statements RIGHTB  */
#line 2132 "pnfha.ypp"
                    { PNF_String str(yyvsp[-1].to_string().get()); yyval.put(str); ASTNode statement_block("statement_block"); 
                                                  tree.add_node(statement_block); }
#line 5396 "pnfha.tab.cpp"
    break;

  case 152: /* statements: statement  */
#line 2137 "pnfha.ypp"
                        {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			}
#line 5405 "pnfha.tab.cpp"
    break;

  case 153: /* statements: statement statements  */
#line 2142 "pnfha.ypp"
                        {
			 ASTNode statements("statements");
			 tree.add_node(statements);
			}
#line 5414 "pnfha.tab.cpp"
    break;

  case 154: /* expression: void_expression  */
#line 2148 "pnfha.ypp"
                                { yyval = yyvsp[0]; exptype = TVOID; ASTNode expression("expression"); tree.add_node(expression); }
#line 5420 "pnfha.tab.cpp"
    break;

  case 155: /* expression: boolean_expression  */
#line 2150 "pnfha.ypp"
                {
		 yyval = yyvsp[0];
		 savenumber = yyval;
		 exptype = TBOOLEAN;
		 ASTNode expression("expression");
		 tree.add_node(expression);
		}
#line 5432 "pnfha.tab.cpp"
    break;

  case 156: /* expression: number_expression  */
#line 2157 "pnfha.ypp"
                                    { yyval = yyvsp[0]; savenumber = yyval; exptype = TNUMBER; ASTNode expression("expression");
                                      tree.add_node(expression); }
#line 5439 "pnfha.tab.cpp"
    break;

  case 157: /* expression: character_expression  */
#line 2159 "pnfha.ypp"
                                       { yyval = yyvsp[0]; savenumber = yyval; exptype = TCHARACTER; ASTNode expression("expression"); 
                                         tree.add_node(expression); }
#line 5446 "pnfha.tab.cpp"
    break;

  case 158: /* expression: string_expression  */
#line 2161 "pnfha.ypp"
                                    { yyval = yyvsp[0]; savenumber = (PNF_String)strip_quotes(yyval.to_string().get()); exptype = TSTRING; ASTNode expression("expression"); 
                                      tree.add_node(expression); }
#line 5453 "pnfha.tab.cpp"
    break;

  case 159: /* expression: id_expression  */
#line 2163 "pnfha.ypp"
                                { yyval = yyvsp[0]; exptype = (PNF_Type_Enum)yyval.getType(); ASTNode expression("expression"); 
                                  tree.add_node(expression); }
#line 5460 "pnfha.tab.cpp"
    break;

  case 160: /* expression: relational_expression  */
#line 2165 "pnfha.ypp"
                                        { yyval = yyvsp[0]; exptype = TBOOLEAN; ASTNode expression("expression"); 
					  tree.add_node(expression); }
#line 5467 "pnfha.tab.cpp"
    break;

  case 161: /* expression: mixed_expression  */
#line 2167 "pnfha.ypp"
                                   { yyval = yyvsp[0]; exptype = (PNF_Type_Enum)yyval.getType(); ASTNode expression("expression"); 
				     tree.add_node(expression); }
#line 5474 "pnfha.tab.cpp"
    break;

  case 162: /* expression: function_expression  */
#line 2169 "pnfha.ypp"
                                      { yyval = yyvsp[0]; exptype = (PNF_Type_Enum)yyval.getType(); ASTNode expression("expression"); tree.add_node(expression); 		
		}
#line 5481 "pnfha.tab.cpp"
    break;

  case 163: /* void_expression: VOIDV  */
#line 2175 "pnfha.ypp"
                        {
			 PNF_String s("0V");
			 yyval.put(s);

			 exptruth = false;

			 ASTNode void_expression("void_expression");
			 tree.add_node(void_expression);
			}
#line 5495 "pnfha.tab.cpp"
    break;

  case 164: /* void_expression: LEFTP void_expression RIGHTP  */
#line 2184 "pnfha.ypp"
                                                       { yyval = yyvsp[-1]; }
#line 5501 "pnfha.tab.cpp"
    break;

  case 165: /* boolean_expression: BOOLEANV  */
#line 2188 "pnfha.ypp"
                        { 
			 yyval = yyvsp[0];

			 String str = yyval.to_boolean().get();
			 if (str == "true")
			  exptruth = true;
                         else if (str == "false")
                          exptruth = false;
			 else
			  exptruth = true;

			
			 ASTNode boolean_expression("boolean_expression"); 
			 tree.add_node(boolean_expression);
			}
#line 5521 "pnfha.tab.cpp"
    break;

  case 166: /* boolean_expression: OPNOT boolean_expression  */
#line 2204 "pnfha.ypp"
                        {
			 bool b;
			 String str = yyvsp[0].to_boolean().get();

			 if (str.getString() == "true")
			  b = true;
			 else
			  b = false;

			 PNF_Boolean b2(b);
			 b2.opnot();
			 yyval.put(b2);
			}
#line 5539 "pnfha.tab.cpp"
    break;

  case 167: /* boolean_expression: boolean_expression OPAND boolean_expression  */
#line 2218 "pnfha.ypp"
                        {
			 String bl = yyvsp[0].to_boolean().get();
			 bool b;
			
			 if (bl.getString() == "true")
			  b = true;
			 else if (bl.getString() == "false")
			  b = false;
			 else
			  b = false;

			 PNF_Boolean b2(yyvsp[-2].to_boolean());
			 b2.opand(b);
			 yyval.put(b2);
			}
#line 5559 "pnfha.tab.cpp"
    break;

  case 168: /* boolean_expression: boolean_expression OPOR boolean_expression  */
#line 2234 "pnfha.ypp"
                        {
			 String bl = yyvsp[0].to_boolean().get();
			 bool b;
			
			 if (bl.getString() == "true")
			  b = true;
			 else if (bl.getString() == "false")
			  b = false;
			 else
			  b = false;

			 PNF_Boolean b2(yyvsp[-2].to_boolean());
			 b2.opor(b);
			 yyval.put(b2);
			}
#line 5579 "pnfha.tab.cpp"
    break;

  case 169: /* boolean_expression: LEFTP boolean_expression RIGHTP  */
#line 2249 "pnfha.ypp"
                                                          { yyval = yyvsp[-1]; }
#line 5585 "pnfha.tab.cpp"
    break;

  case 170: /* number_expression: NUMBERV  */
#line 2253 "pnfha.ypp"
                        { 
			 yyval = yyvsp[0];

			 double d = yyval.to_number().get();

                         if (d == 0)
                          exptruth = false;
                         else
                          exptruth = true;

			 ASTNode number_expression("number_expression");
                         tree.add_node(number_expression);
			}
#line 5603 "pnfha.tab.cpp"
    break;

  case 171: /* number_expression: number_expression OPPLUS number_expression  */
#line 2267 "pnfha.ypp"
                        {
			 double d = yyvsp[-1].to_number().get();
			 yyvsp[-2].to_number().add(d);
			 yyval = yyvsp[-2];
			}
#line 5613 "pnfha.tab.cpp"
    break;

  case 172: /* number_expression: number_expression OPMINUS number_expression  */
#line 2273 "pnfha.ypp"
                        {
			 double d = yyvsp[-1].to_number().get();
			 yyvsp[-2].to_number().sub(d);
			 yyval = yyvsp[-2];
			}
#line 5623 "pnfha.tab.cpp"
    break;

  case 173: /* number_expression: number_expression OPTIMES number_expression  */
#line 2279 "pnfha.ypp"
                        {
			 double d = yyvsp[-1].to_number().get();
			 yyvsp[-2].to_number().mul(d);
			 yyval = yyvsp[-2];
			}
#line 5633 "pnfha.tab.cpp"
    break;

  case 174: /* number_expression: number_expression OPDIV number_expression  */
#line 2285 "pnfha.ypp"
                        {
			 double d = yyvsp[-1].to_number().get();
			 yyvsp[-2].to_number().div(d);
			 yyval = yyvsp[-2];
			}
#line 5643 "pnfha.tab.cpp"
    break;

  case 175: /* number_expression: number_expression OPMODULUS number_expression  */
#line 2291 "pnfha.ypp"
                        {
			 double d = yyvsp[-1].to_number().get();
			 yyvsp[-2].to_number().mod(d);
			 yyval = yyvsp[-2];
			}
#line 5653 "pnfha.tab.cpp"
    break;

  case 176: /* number_expression: OPMINUS number_expression  */
#line 2297 "pnfha.ypp"
                        {
			 char * str = "-";
			 strcat(str, yyvsp[0].to_string().get().getString().c_str());
			 PNF_String s(str);
			 PNF_Variable v(s);
			 yyval = v;
			}
#line 5665 "pnfha.tab.cpp"
    break;

  case 177: /* number_expression: number_expression OPPOWER number_expression  */
#line 2305 "pnfha.ypp"
                        {
			 double d = yyvsp[0].to_number().get();
			 PNF_Number n(yyvsp[-2].to_number());
			 n.pow(d);
			 yyval.put(n);
			}
#line 5676 "pnfha.tab.cpp"
    break;

  case 178: /* number_expression: number_expression OPROOT number_expression  */
#line 2312 "pnfha.ypp"
                        {
			 double d = yyvsp[-2].to_number().get();
			 PNF_Number n(yyvsp[0].to_number());
			 n.root(d);			 
			 yyval.put(n);
			}
#line 5687 "pnfha.tab.cpp"
    break;

  case 179: /* number_expression: OPINC number_expression  */
#line 2319 "pnfha.ypp"
                        {
			 PNF_Number n(yyvsp[0].to_number().get());
			 n.inc(1);
			 yyval.put(n);
			}
#line 5697 "pnfha.tab.cpp"
    break;

  case 180: /* number_expression: number_expression OPINC  */
#line 2325 "pnfha.ypp"
                        {
			 PNF_Number n(yyvsp[-1].to_number().get());
			 yyval.put(n);
			 n.inc(1);
			}
#line 5707 "pnfha.tab.cpp"
    break;

  case 181: /* number_expression: OPDEC number_expression  */
#line 2331 "pnfha.ypp"
                        {
			 PNF_Number n(yyvsp[0].to_number().get());
			 n.dec(1);
			 yyval.put(n);
			}
#line 5717 "pnfha.tab.cpp"
    break;

  case 182: /* number_expression: number_expression OPDEC  */
#line 2337 "pnfha.ypp"
                        {
			 PNF_Number n(yyvsp[-1].to_number().get());
			 yyval.put(n);
			 n.dec(1);
			}
#line 5727 "pnfha.tab.cpp"
    break;

  case 183: /* number_expression: number_expression OPAMP number_expression  */
#line 2343 "pnfha.ypp"
                        {
			 int d1 = (int)yyvsp[-2].to_number().get();
			 int d2 = (int)yyvsp[0].to_number().get();
			 int d3 = d1 & d2;
			 PNF_Number n(d3);
			 yyval.put(n);
			}
#line 5739 "pnfha.tab.cpp"
    break;

  case 184: /* number_expression: number_expression OPBTOR number_expression  */
#line 2351 "pnfha.ypp"
                        {
			 int d1 = (int)yyvsp[-2].to_number().get();
			 int d2 = (int)yyvsp[0].to_number().get();
			 int d3 = d1 | d2;
			 PNF_Number n(d3);
			 yyval.put(n);
			}
#line 5751 "pnfha.tab.cpp"
    break;

  case 185: /* number_expression: number_expression OPBTXOR number_expression  */
#line 2360 "pnfha.ypp"
                        {
			 int d1 = (int)yyvsp[-2].to_number().get();
			 int d2 = (int)yyvsp[0].to_number().get();
			 int d3 = d1 ^ d2;
			 PNF_Number n(d3);
			 yyval.put(n);
			}
#line 5763 "pnfha.tab.cpp"
    break;

  case 186: /* number_expression: OPBTNOT number_expression  */
#line 2368 "pnfha.ypp"
                        {
			 int d = (int)yyvsp[0].to_number().get();
			 d = ~d;
			 PNF_Number n(d);
			 yyval.put(n);
			}
#line 5774 "pnfha.tab.cpp"
    break;

  case 187: /* number_expression: number_expression OPBTSL number_expression  */
#line 2375 "pnfha.ypp"
                        {
			 int d1 = (int)yyvsp[-2].to_number().get();
			 int d2 = (int)yyvsp[0].to_number().get();
			 int d3 = d1 << d2;
			 PNF_Number n(d3);
			 yyval.put(n);
			}
#line 5786 "pnfha.tab.cpp"
    break;

  case 188: /* number_expression: number_expression OPBTSR number_expression  */
#line 2383 "pnfha.ypp"
                        {
			 int d1 = (int)yyvsp[-2].to_number().get();
			 int d2 = (int)yyvsp[0].to_number().get();
			 int d3 = d1 >> d2;
			 PNF_Number n(d3);
			 yyval.put(n);
			}
#line 5798 "pnfha.tab.cpp"
    break;

  case 189: /* number_expression: LEFTP number_expression RIGHTP  */
#line 2390 "pnfha.ypp"
                                                                        { yyval = yyvsp[-1]; }
#line 5804 "pnfha.tab.cpp"
    break;

  case 190: /* character_expression: CHARACTERV  */
#line 2395 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];
			 char ch = yyval.to_character().get();

			 if (ch == '\0')
                          exptruth = false;
			 else
			  exptruth = true;

			 ASTNode character_expression("character_expression"); 
			 tree.add_node(character_expression);
			}
#line 5821 "pnfha.tab.cpp"
    break;

  case 191: /* character_expression: character_expression OPPLUS character_expression  */
#line 2408 "pnfha.ypp"
                        {
			 char d = yyvsp[-2].to_character().get();
			 PNF_Character c(d);
			 c.add(yyvsp[0].to_character().get());
			 yyval.put(c);
			}
#line 5832 "pnfha.tab.cpp"
    break;

  case 192: /* character_expression: character_expression OPMINUS character_expression  */
#line 2415 "pnfha.ypp"
                        {
			 char d = yyvsp[-2].to_character().get();
			 PNF_Character c(d);
			 c.sub(yyvsp[0].to_character().get());
			 yyval.put(c);
			}
#line 5843 "pnfha.tab.cpp"
    break;

  case 193: /* character_expression: character_expression OPTIMES character_expression  */
#line 2422 "pnfha.ypp"
                        {
			 char d = yyvsp[-2].to_character().get();
			 PNF_Character c(d);
			 c.mul(yyvsp[0].to_character().get());
			 yyval.put(c);
			}
#line 5854 "pnfha.tab.cpp"
    break;

  case 194: /* character_expression: character_expression OPDIV character_expression  */
#line 2429 "pnfha.ypp"
                        {
			 char d = yyvsp[-2].to_character().get();
			 PNF_Character c(d);
			 c.div(yyvsp[0].to_character().get());
			 yyval.put(c);			}
#line 5864 "pnfha.tab.cpp"
    break;

  case 195: /* character_expression: character_expression OPMODULUS character_expression  */
#line 2435 "pnfha.ypp"
                        {
			 char d = yyvsp[-2].to_character().get();
			 PNF_Character c(d);
			 c.mod(yyvsp[0].to_character().get());
			 yyval.put(c);
			}
#line 5875 "pnfha.tab.cpp"
    break;

  case 196: /* character_expression: character_expression OPPOWER character_expression  */
#line 2442 "pnfha.ypp"
                        {
			 char d = yyvsp[0].to_character().get();
			 PNF_Character c(yyvsp[-2].to_character());
			 c.pow(d);
			 yyval.put(c);
			}
#line 5886 "pnfha.tab.cpp"
    break;

  case 197: /* character_expression: character_expression OPROOT character_expression  */
#line 2449 "pnfha.ypp"
                        {
			 char d = yyvsp[-2].to_character().get();
			 PNF_Character c(yyvsp[0].to_character());
			 c.root(d);
			 yyval.put(c);
			}
#line 5897 "pnfha.tab.cpp"
    break;

  case 198: /* character_expression: OPINC character_expression  */
#line 2456 "pnfha.ypp"
                        {
			 PNF_Character n(yyvsp[0].to_character().get());
			 n.inc(1);
			 yyval.put(n);
			}
#line 5907 "pnfha.tab.cpp"
    break;

  case 199: /* character_expression: character_expression OPINC  */
#line 2462 "pnfha.ypp"
                        {
			 PNF_Character n(yyvsp[-1].to_character().get());
			 yyval.put(n);
			 n.inc(1);
			}
#line 5917 "pnfha.tab.cpp"
    break;

  case 200: /* character_expression: OPDEC character_expression  */
#line 2468 "pnfha.ypp"
                        {
			 PNF_Character n(yyvsp[0].to_character().get());
			 n.dec(1);
			 yyval.put(n);
			}
#line 5927 "pnfha.tab.cpp"
    break;

  case 201: /* character_expression: character_expression OPDEC  */
#line 2474 "pnfha.ypp"
                        {
			 PNF_Character n(yyvsp[-1].to_character().get());
			 yyval.put(n);
			 n.dec(1);
			}
#line 5937 "pnfha.tab.cpp"
    break;

  case 202: /* character_expression: LEFTP character_expression RIGHTP  */
#line 2479 "pnfha.ypp"
                                                                { yyval = yyvsp[-1]; }
#line 5943 "pnfha.tab.cpp"
    break;

  case 203: /* string_expression: STRINGV  */
#line 2484 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];
		
			 String str = yyval.to_string().get();
			 if (str == "")
			  exptruth = false;
			 else
			  exptruth = true;

			 ASTNode string_expression("string_expression"); 
			 tree.add_node(string_expression);
			}
#line 5960 "pnfha.tab.cpp"
    break;

  case 204: /* string_expression: string_expression OPPLUS string_expression  */
#line 2497 "pnfha.ypp"
                        {
			 String d = yyvsp[-2].to_string().get();
			 PNF_String s(d);
			 s.add(yyvsp[0].to_string().get());

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
			 yyval.put(s);
			}
#line 5989 "pnfha.tab.cpp"
    break;

  case 205: /* string_expression: OPSTR string_expression  */
#line 2522 "pnfha.ypp"
                        {
			 String str = yyvsp[0].to_string().get();
			 String str2 = "\"" + str + "\"";
			 PNF_String s(str2);
			 yyval.put(s);
			}
#line 6000 "pnfha.tab.cpp"
    break;

  case 206: /* string_expression: LEFTP string_expression RIGHTP  */
#line 2528 "pnfha.ypp"
                                                                { yyval = yyvsp[-1]; }
#line 6006 "pnfha.tab.cpp"
    break;

  case 207: /* id_expression: ID  */
#line 2533 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   yyval = varTable[scope][i].value();

			   switch (yyval.getType())
			   {
			    case TVOID:
			     exptruth = false;
			     break;

			    case TBOOLEAN:
			    {
			     String str = yyval.to_boolean().get();
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
			     double d = yyval.to_number().get();
			     if (d == 0)
			      exptruth = false;
			     else
			      exptruth = true;
			     }
			     break;

			    case TCHARACTER:
			    {
			     char ch = yyval.to_character().get();
			     if (ch == '\0')
			      exptruth = false;
			     else
			      exptruth = true;
			     }
			     break;

			    case TSTRING:
			    {
			     String str = yyval.to_string().get();
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
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 ASTNode id_expression("id_expression");
			 tree.add_node(id_expression);
			}
#line 6081 "pnfha.tab.cpp"
    break;

  case 208: /* id_expression: OPAMP id_expression  */
#line 2604 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Number n(varTable[scope][i].address());
			   yyval.put(n);
			  }
			 }

			 if (!declared)
			 {
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (strcmp(labelTable[i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			   {
			    declared = true;
			    PNF_Number n(labelTable[i].address());
			    yyval.put(n);
			   }
 			  }


			  if (!declared)
			  {
			   for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			   {
			    if (strcmp(eventLabelTable[i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			    {
			     declared = true;
			     PNF_Number n(eventLabelTable[i].address());
			     yyval.put(n);
			    }
  			   }
			  }
			 }
			}
#line 6125 "pnfha.tab.cpp"
    break;

  case 209: /* id_expression: OPNOT id_expression  */
#line 2644 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
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
			   yyval.put(b);
			   varTable[scope][i].value(b);			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
			}
#line 6166 "pnfha.tab.cpp"
    break;

  case 210: /* id_expression: id_expression OPAND id_expression  */
#line 2681 "pnfha.ypp"
                        {
			 bool declared1 = false;
			 bool declared2 = false;
  		   	 PNF_Boolean b1;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
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
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 PNF_Boolean b3;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
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
			  String str = yyvsp[0].to_string().get();
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
			 yyval.put(b1);
			}
#line 6247 "pnfha.tab.cpp"
    break;

  case 211: /* id_expression: id_expression OPOR id_expression  */
#line 2758 "pnfha.ypp"
                        {
			 bool declared1 = false;
			 bool declared2 = false;
			 PNF_Boolean b1;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
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
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }


   		         PNF_Boolean b3;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
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
			  String str = yyvsp[0].to_string().get();
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
			 yyval.put(b1);
			}
#line 6330 "pnfha.tab.cpp"
    break;

  case 212: /* id_expression: id_expression OPPLUS id_expression  */
#line 2837 "pnfha.ypp"
                        {
			 switch (yyvsp[-2].getType())
			 {
			  case TNUMBER:
			  {
			   if (yyvsp[0].getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   double d = yyvsp[0].to_number().get();
			   PNF_Number n(yyvsp[-2].to_number());
			   n.add(d);
			   yyval.put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if (yyvsp[0].getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   char d = yyvsp[0].to_character().get();
			   PNF_Character n(yyvsp[-2].to_character());
			   n.add(d);
			   yyval.put(n);
			  }
			  break;

			  case TSTRING:
			  {
			   if (yyvsp[0].getType() != TSTRING)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }

			   String str = yyvsp[0].to_string().get();
			   String str2 = "";
			   for (unsigned long i = 0; i < str.length(); ++i)
 			   {
			    if (str[i] == '\"')
			     continue;
			    str2 += str[i];
			   }

			   str = yyvsp[-2].to_string().get();
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

			   yyval.put(s);
			  }
			  break;

			  default:
			   PNF_Number n(0);
			   yyval.put(n);
			   break;
			 }
			}
#line 6414 "pnfha.tab.cpp"
    break;

  case 213: /* id_expression: id_expression OPMINUS id_expression  */
#line 2917 "pnfha.ypp"
                        {
			 switch (yyvsp[-2].getType())
			 {
			  case TNUMBER:
			  {
			   if (yyvsp[0].getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   double d = yyvsp[0].to_number().get();
			   PNF_Number n(yyvsp[-2].to_number());
			   n.sub(d);
			   yyval.put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if (yyvsp[0].getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   char d = yyvsp[0].to_character().get();
			   PNF_Character n(yyvsp[-2].to_character());
			   n.sub(d);
			   yyval.put(n);
			  }
			  break;			

			  default:
			   PNF_Number n(0);
			   yyval.put(n);
			   break;
			 }
			}
#line 6456 "pnfha.tab.cpp"
    break;

  case 214: /* id_expression: id_expression OPTIMES id_expression  */
#line 2955 "pnfha.ypp"
                        {
			 switch (yyvsp[-2].getType())
			 {
			  case TNUMBER:
			  {
			   if (yyvsp[0].getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   double d = yyvsp[0].to_number().get();
			   PNF_Number n(yyvsp[-2].to_number());
			   n.mul(d);
			   yyval.put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if (yyvsp[0].getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   char d = yyvsp[0].to_character().get();
			   PNF_Character n(yyvsp[-2].to_character());
			   n.mul(d);
			   yyval.put(n);
			  }
			  break;				

			  default:
			   PNF_Number n(0);
			   yyval.put(n);
			   break;
			 }
			}
#line 6498 "pnfha.tab.cpp"
    break;

  case 215: /* id_expression: id_expression OPDIV id_expression  */
#line 2993 "pnfha.ypp"
                        {
			 switch (yyvsp[-2].getType())
			 {
			  case TNUMBER:
			  {
			   if (yyvsp[0].getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   double d = yyvsp[0].to_number().get();
			   PNF_Number n(yyvsp[-2].to_number());
			   n.div(d);
			   yyval.put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if (yyvsp[0].getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   char d = yyvsp[0].to_character().get();
			   PNF_Character n(yyvsp[-2].to_character());
			   n.div(d);
			   yyval.put(n);
			  }
			  break;			

			  default:
			   PNF_Number n(0);
			   yyval.put(n);
			   break;
			 }
			}
#line 6540 "pnfha.tab.cpp"
    break;

  case 216: /* id_expression: id_expression OPMODULUS id_expression  */
#line 3031 "pnfha.ypp"
                        {
			 switch (yyvsp[-2].getType())
			 {
			  case TNUMBER:
			  {
			   if (yyvsp[0].getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   double d = yyvsp[0].to_number().get();
			   PNF_Number n(yyvsp[-2].to_number());
			   n.mod(d);
			   yyval.put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if (yyvsp[0].getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   char d = yyvsp[0].to_character().get();
			   PNF_Character n(yyvsp[-2].to_character());
			   n.mod(d);
			   yyval.put(n);
			  }
			  break;	

			  default:
			   PNF_Number n(0);
			   yyval.put(n);
			   break;
			 }
			}
#line 6582 "pnfha.tab.cpp"
    break;

  case 217: /* id_expression: OPMINUS id_expression  */
#line 3069 "pnfha.ypp"
                        {
			 if (yyvsp[0].getType() != TNUMBER)
			 {
			  PNF_Number n(0);
                          yyval.put(n);
			 }
			 double d = yyvsp[0].to_number().get();
			 d = -d;
			 PNF_Number n(d);
			 PNF_Variable v(n);
			 yyval = v;
			}
#line 6599 "pnfha.tab.cpp"
    break;

  case 218: /* id_expression: id_expression OPPOWER id_expression  */
#line 3082 "pnfha.ypp"
                        {
			 switch (yyvsp[-2].getType())
			 {
			  case TNUMBER:
			  {
			   if (yyvsp[0].getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   double d = yyvsp[0].to_number().get();
			   PNF_Number n(yyvsp[-2].to_number());
			   n.pow(d);
			   yyval.put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if (yyvsp[0].getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   char d = yyvsp[0].to_character().get();
			   PNF_Character n(yyvsp[-2].to_character());
			   n.pow(d);
			   yyval.put(n);
			  }
			  break;	

			  default:
			   PNF_Number n(0);
			   yyval.put(n);
			   break;
			 }
			}
#line 6641 "pnfha.tab.cpp"
    break;

  case 219: /* id_expression: id_expression OPROOT id_expression  */
#line 3120 "pnfha.ypp"
                        {
			 switch (yyvsp[-2].getType())
			 {
			  case TNUMBER:
			  {
			   if (yyvsp[0].getType() != TNUMBER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   double d = yyvsp[-2].to_number().get();
			   PNF_Number n(yyvsp[0].to_number());
			   n.root(d);
			   yyval.put(n);
			  }
			  break;

		          case TCHARACTER:
			  {
			   if (yyvsp[0].getType() != TCHARACTER)
			   {
			    PNF_Number n(0);
			    yyval.put(n);
			   }
			   char d = yyvsp[-2].to_character().get();
			   PNF_Character n(yyvsp[0].to_character());
			   n.root(d);
			   yyval.put(n);
			  }
			  break;	

			  default:
			   PNF_Number n(0);
			   yyval.put(n);
			   break;
			 }
			}
#line 6683 "pnfha.tab.cpp"
    break;

  case 220: /* id_expression: OPINC id_expression  */
#line 3158 "pnfha.ypp"
                        {
			 switch (yyvsp[0].getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n(yyvsp[0].to_number().get());
			   n.inc(1);
			   yyval.put(n);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c(yyvsp[0].to_character().get());
			   c.inc(1);
			   yyval.put(c);
			  }
	                  break;
			  
			  default:
			  {
			   PNF_Number n(0);
                           yyval.put(n);
			  }
			  break;
			 }
			}
#line 6715 "pnfha.tab.cpp"
    break;

  case 221: /* id_expression: id_expression OPINC  */
#line 3186 "pnfha.ypp"
                        {
			 switch (yyvsp[0].getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n(yyvsp[0].to_number().get());
			   yyval.put(n);
			   n.inc(1);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c(yyvsp[0].to_character().get());
			   yyval.put(c);
			   c.inc(1);
			  }
	                  break;
			  
			  default:
			  {
			   PNF_Number n(0);
                           yyval.put(n);
			  }
			  break;
			 }
			}
#line 6747 "pnfha.tab.cpp"
    break;

  case 222: /* id_expression: OPDEC id_expression  */
#line 3214 "pnfha.ypp"
                        {
			 switch (yyvsp[0].getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n(yyvsp[0].to_number().get());
			   n.dec(1);
			   yyval.put(n);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c(yyvsp[0].to_character().get());
			   c.dec(1);
			   yyval.put(c);
			  }
	                  break;
			  
			  default:
			  {
			   PNF_Number n(0);
                           yyval.put(n);
			  }
			  break;
			 }
			}
#line 6779 "pnfha.tab.cpp"
    break;

  case 223: /* id_expression: id_expression OPDEC  */
#line 3242 "pnfha.ypp"
                        {
			 switch (yyvsp[0].getType())
			 {
			  case TNUMBER:
			  {
			   PNF_Number n(yyvsp[0].to_number().get());
			   yyval.put(n);
			   n.dec(1);
			  }
			  break;

			  case TCHARACTER:
			  {
			   PNF_Character c(yyvsp[0].to_character().get());
			   yyval.put(c);
			   c.dec(1);
			  }
	                  break;
			  
			  default:
			  {
			   PNF_Number n(0);
                           yyval.put(n);
			  }
			  break;
			 }
			}
#line 6811 "pnfha.tab.cpp"
    break;

  case 224: /* id_expression: LEFTP id_expression RIGHTP  */
#line 3269 "pnfha.ypp"
                                                     { yyval = yyvsp[-2]; }
#line 6817 "pnfha.tab.cpp"
    break;

  case 225: /* relational_expression: number_expression OPEQU number_expression  */
#line 3273 "pnfha.ypp"
                        {
			 double d1 = yyvsp[-2].to_number().get();
			 double d2 = yyvsp[0].to_number().get();
			 bool b = d1 == d2;
			 PNF_Boolean b2(b);
			 yyval.put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 6832 "pnfha.tab.cpp"
    break;

  case 226: /* relational_expression: number_expression OPNEQU number_expression  */
#line 3284 "pnfha.ypp"
                        {
			 double d1 = yyvsp[-2].to_number().get();
			 double d2 = yyvsp[0].to_number().get();
			 bool b = d1 != d2;
			 PNF_Boolean b2(b);
			 yyval.put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 6847 "pnfha.tab.cpp"
    break;

  case 227: /* relational_expression: number_expression OPLSS number_expression  */
#line 3295 "pnfha.ypp"
                        {
			 double d1 = yyvsp[-2].to_number().get();
			 double d2 = yyvsp[0].to_number().get();
			 bool b = d1 < d2;
			 PNF_Boolean b2(b);
			 yyval.put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 6862 "pnfha.tab.cpp"
    break;

  case 228: /* relational_expression: number_expression OPGTR number_expression  */
#line 3306 "pnfha.ypp"
                        {
			 double d1 = yyvsp[-2].to_number().get();
			 double d2 = yyvsp[0].to_number().get();
			 bool b = d1 > d2;
			 PNF_Boolean b2(b);
			 yyval.put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 6877 "pnfha.tab.cpp"
    break;

  case 229: /* relational_expression: number_expression OPLEQU number_expression  */
#line 3317 "pnfha.ypp"
                        {
			 double d1 = yyvsp[-2].to_number().get();
			 double d2 = yyvsp[0].to_number().get();
			 bool b = d1 <= d2;
			 PNF_Boolean b2(b);
			 yyval.put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 6892 "pnfha.tab.cpp"
    break;

  case 230: /* @80: %empty  */
#line 3328 "pnfha.ypp"
                        {
			 double d1 = yyvsp[-2].to_number().get();
			 double d2 = yyvsp[0].to_number().get();
			 bool b = d1 >= d2;
			 PNF_Boolean b2(b);
			 yyval.put(b2);

			 ASTNode relational_expression("relational_expression");
			 tree.add_node(relational_expression);
			}
#line 6907 "pnfha.tab.cpp"
    break;

  case 231: /* relational_expression: number_expression OPGEQU number_expression @80  */
#line 3338 "pnfha.ypp"
                        {
			 String str = yyval.to_boolean().get();
			 if (str == "false")
			  exptruth = false;
			 else if (str == "true")
			  exptruth = true;
			 else
			  exptruth = true;
			}
#line 6921 "pnfha.tab.cpp"
    break;

  case 232: /* relational_expression: number_expression OPCMP number_expression  */
#line 3348 "pnfha.ypp"
                        {
			 double d1 = yyvsp[-2].to_number().get();
			 double d2 = yyvsp[0].to_number().get();
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
			 yyval.put(n);
			}
#line 6948 "pnfha.tab.cpp"
    break;

  case 233: /* mixed_expression: LEFTP mixed_expression RIGHTP  */
#line 3373 "pnfha.ypp"
                                                      { yyval = yyvsp[-1]; }
#line 6954 "pnfha.tab.cpp"
    break;

  case 234: /* mixed_expression: ID OPAND boolean_expression  */
#line 3375 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
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
			   String str = yyvsp[0].to_boolean().get();
			   if (str.getString() == "true")
			    b2 = true;
			   else if (str.getString() == "false")
			    b2 = false;
			   else
			    b2 = true;

			   b1.opand(b2);

			   yyval.put(b1);
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7007 "pnfha.tab.cpp"
    break;

  case 235: /* mixed_expression: boolean_expression OPAND ID  */
#line 3424 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
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
			   String str = yyvsp[-2].to_boolean().get();
			   if (str.getString() == "true")
			    b2 = true;
			   else if (str.getString() == "false")
			    b2 = false;
			   else
			    b2 = true;

			   b1.opand(b2);

			   yyval.put(b1);
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7060 "pnfha.tab.cpp"
    break;

  case 236: /* mixed_expression: ID OPOR boolean_expression  */
#line 3473 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
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
			   String str = yyvsp[0].to_boolean().get();
			   if (str.getString() == "true")
			    b2 = true;
			   else if (str.getString() == "false")
			    b2 = false;
			   else
			    b2 = true;

			   b1.opor(b2);

			   yyval.put(b1);
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7113 "pnfha.tab.cpp"
    break;

  case 237: /* mixed_expression: boolean_expression OPOR ID  */
#line 3522 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
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
			   String str = yyvsp[-2].to_boolean().get();
			   if (str.getString() == "true")
			    b2 = true;
			   else if (str.getString() == "false")
			    b2 = false;
			   else
			    b2 = true;

			   b1.opor(b2);

			   yyval.put(b1);
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7166 "pnfha.tab.cpp"
    break;

  case 238: /* mixed_expression: ID OPPLUS number_expression  */
#line 3571 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[0].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.add(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7212 "pnfha.tab.cpp"
    break;

  case 239: /* mixed_expression: ID OPMINUS number_expression  */
#line 3613 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[0].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.sub(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7258 "pnfha.tab.cpp"
    break;

  case 240: /* mixed_expression: ID OPTIMES number_expression  */
#line 3655 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[0].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.mul(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7304 "pnfha.tab.cpp"
    break;

  case 241: /* mixed_expression: ID OPDIV number_expression  */
#line 3697 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[0].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.div(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7350 "pnfha.tab.cpp"
    break;

  case 242: /* mixed_expression: ID OPPOWER number_expression  */
#line 3739 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[0].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.pow(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7396 "pnfha.tab.cpp"
    break;

  case 243: /* mixed_expression: ID OPROOT number_expression  */
#line 3781 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = varTable[scope][i].value().to_number().get();
			     PNF_Number n(yyvsp[0].to_number());
			     n.root(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7442 "pnfha.tab.cpp"
    break;

  case 244: /* mixed_expression: number_expression OPPLUS ID  */
#line 3823 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[-2].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.add(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7488 "pnfha.tab.cpp"
    break;

  case 245: /* mixed_expression: number_expression OPMINUS ID  */
#line 3865 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[-2].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.sub(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7534 "pnfha.tab.cpp"
    break;

  case 246: /* mixed_expression: number_expression OPTIMES ID  */
#line 3907 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[-2].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.mul(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7580 "pnfha.tab.cpp"
    break;

  case 247: /* mixed_expression: number_expression OPDIV ID  */
#line 3949 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[-2].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.div(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7626 "pnfha.tab.cpp"
    break;

  case 248: /* mixed_expression: number_expression OPPOWER ID  */
#line 3991 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = yyvsp[-2].to_number().get();
			     PNF_Number n(varTable[scope][i].value().to_number());
			     n.pow(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7672 "pnfha.tab.cpp"
    break;

  case 249: /* mixed_expression: number_expression OPROOT ID  */
#line 4033 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     double d = varTable[scope][i].value().to_number().get();
			     PNF_Number n(yyvsp[-2].to_number());
			     n.root(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7718 "pnfha.tab.cpp"
    break;

  case 250: /* mixed_expression: ID OPPLUS character_expression  */
#line 4075 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[0].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[0].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.add(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7764 "pnfha.tab.cpp"
    break;

  case 251: /* mixed_expression: ID OPMINUS character_expression  */
#line 4117 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[0].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[0].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.sub(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7810 "pnfha.tab.cpp"
    break;

  case 252: /* mixed_expression: ID OPTIMES character_expression  */
#line 4159 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[0].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[0].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.mul(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7856 "pnfha.tab.cpp"
    break;

  case 253: /* mixed_expression: ID OPDIV character_expression  */
#line 4201 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[0].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[0].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.div(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7902 "pnfha.tab.cpp"
    break;

  case 254: /* mixed_expression: ID OPPOWER character_expression  */
#line 4243 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[0].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[0].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.pow(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7948 "pnfha.tab.cpp"
    break;

  case 255: /* mixed_expression: ID OPROOT character_expression  */
#line 4285 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[0].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = varTable[scope][i].value().to_character().get();
			     PNF_Character n(yyvsp[0].to_character());
			     n.root(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 7994 "pnfha.tab.cpp"
    break;

  case 256: /* mixed_expression: character_expression OPPLUS ID  */
#line 4327 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[-2].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[-2].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.add(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8040 "pnfha.tab.cpp"
    break;

  case 257: /* mixed_expression: character_expression OPMINUS ID  */
#line 4369 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[-2].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[-2].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.sub(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8086 "pnfha.tab.cpp"
    break;

  case 258: /* mixed_expression: character_expression OPTIMES ID  */
#line 4411 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[-2].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[-2].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.mul(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8132 "pnfha.tab.cpp"
    break;

  case 259: /* mixed_expression: character_expression OPDIV ID  */
#line 4453 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[-2].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[-2].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.div(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8178 "pnfha.tab.cpp"
    break;

  case 260: /* mixed_expression: character_expression OPPOWER ID  */
#line 4495 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[-2].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = yyvsp[-2].to_character().get();
			     PNF_Character n(varTable[scope][i].value().to_character());
			     n.pow(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8224 "pnfha.tab.cpp"
    break;

  case 261: /* mixed_expression: character_expression OPROOT ID  */
#line 4537 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TCHARACTER:
			    {
			     if (yyvsp[-2].getType() != TCHARACTER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }
			     char d = varTable[scope][i].value().to_character().get();
			     PNF_Character n(yyvsp[-2].to_character());
			     n.root(d);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8270 "pnfha.tab.cpp"
    break;

  case 262: /* mixed_expression: ID OPPLUS string_expression  */
#line 4579 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TSTRING:
			    {
			     if (yyvsp[0].getType() != TSTRING)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     String d = yyvsp[0].to_string().get();
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
			     yyval.put(n2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8338 "pnfha.tab.cpp"
    break;

  case 263: /* mixed_expression: string_expression OPPLUS ID  */
#line 4643 "pnfha.ypp"
                        {
                         bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TSTRING:
			    {
			     if (yyvsp[-2].getType() != TSTRING)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     String d = yyvsp[-2].to_string().get();
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
			     yyval.put(n2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8406 "pnfha.tab.cpp"
    break;

  case 264: /* mixed_expression: number_expression OPEQU ID  */
#line 4707 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[-2].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 == d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8455 "pnfha.tab.cpp"
    break;

  case 265: /* mixed_expression: number_expression OPNEQU ID  */
#line 4752 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[-2].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 != d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8504 "pnfha.tab.cpp"
    break;

  case 266: /* mixed_expression: number_expression OPLSS ID  */
#line 4797 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[-2].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 < d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8553 "pnfha.tab.cpp"
    break;

  case 267: /* mixed_expression: number_expression OPGTR ID  */
#line 4842 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[-2].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 > d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8602 "pnfha.tab.cpp"
    break;

  case 268: /* mixed_expression: number_expression OPLEQU ID  */
#line 4887 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[-2].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 <= d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8651 "pnfha.tab.cpp"
    break;

  case 269: /* mixed_expression: number_expression OPGEQU ID  */
#line 4932 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[-2].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 >= d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8700 "pnfha.tab.cpp"
    break;

  case 270: /* mixed_expression: ID OPEQU number_expression  */
#line 4977 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[0].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 == d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8749 "pnfha.tab.cpp"
    break;

  case 271: /* mixed_expression: ID OPNEQU number_expression  */
#line 5022 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[0].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 != d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8798 "pnfha.tab.cpp"
    break;

  case 272: /* mixed_expression: ID OPLSS number_expression  */
#line 5067 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[0].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 < d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8847 "pnfha.tab.cpp"
    break;

  case 273: /* mixed_expression: ID OPGTR number_expression  */
#line 5112 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[0].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 > d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8896 "pnfha.tab.cpp"
    break;

  case 274: /* mixed_expression: ID OPLEQU number_expression  */
#line 5157 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[0].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 <= d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8945 "pnfha.tab.cpp"
    break;

  case 275: /* mixed_expression: ID OPGEQU number_expression  */
#line 5202 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     double d1 = yyvsp[0].to_number().get();
			     double d2 = varTable[scope][i].value().to_number().get();
			     bool b = d1 >= d2;
			     PNF_Boolean b2(b);
			     yyval.put(b2);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 8994 "pnfha.tab.cpp"
    break;

  case 276: /* mixed_expression: ID OPAMP number_expression  */
#line 5247 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[0].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 & d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9043 "pnfha.tab.cpp"
    break;

  case 277: /* mixed_expression: ID OPBTOR number_expression  */
#line 5292 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[0].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 | d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9092 "pnfha.tab.cpp"
    break;

  case 278: /* mixed_expression: ID OPBTXOR number_expression  */
#line 5337 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[0].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 ^ d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9141 "pnfha.tab.cpp"
    break;

  case 279: /* mixed_expression: number_expression OPAMP ID  */
#line 5382 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[-2].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 & d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9190 "pnfha.tab.cpp"
    break;

  case 280: /* mixed_expression: number_expression OPBTOR ID  */
#line 5427 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[-2].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 | d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9239 "pnfha.tab.cpp"
    break;

  case 281: /* mixed_expression: number_expression OPBTXOR ID  */
#line 5472 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[-2].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 ^ d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9288 "pnfha.tab.cpp"
    break;

  case 282: /* mixed_expression: OPBTNOT ID  */
#line 5517 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     int d1 = (int)varTable[scope][i].value().to_number().get();
			     int d2 = ~d1;
			     PNF_Number n(d1);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9329 "pnfha.tab.cpp"
    break;

  case 283: /* mixed_expression: ID OPBTSL number_expression  */
#line 5554 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[0].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 << d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9378 "pnfha.tab.cpp"
    break;

  case 284: /* mixed_expression: ID OPBTSR number_expression  */
#line 5599 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[0].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[0].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 >> d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9427 "pnfha.tab.cpp"
    break;

  case 285: /* mixed_expression: number_expression OPBTSL ID  */
#line 5644 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[-2].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 << d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9476 "pnfha.tab.cpp"
    break;

  case 286: /* mixed_expression: number_expression OPBTSR ID  */
#line 5689 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			     int d1 = (int)yyvsp[-2].to_number().get();
			     int d2 = (int)varTable[scope][i].value().to_number().get();
			     int d3 = d1 >> d2;
			     PNF_Number n(d3);
			     yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
	 		 ASTNode mixed_expression("mixed_expression"); 
		         tree.add_node(mixed_expression);
			}
#line 9525 "pnfha.tab.cpp"
    break;

  case 287: /* mixed_expression: number_expression OPCMP ID  */
#line 5734 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			 double d1 = yyvsp[-2].to_number().get();
			 double d2 = yyvsp[0].to_number().get();
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
			 yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }			
			}
#line 9587 "pnfha.tab.cpp"
    break;

  case 288: /* mixed_expression: ID OPCMP number_expression  */
#line 5792 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
  			  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   	
			   switch (varTable[scope][i].value().getType())
			   {
  			    case TNUMBER:
			    {
			     if (yyvsp[-2].getType() != TNUMBER)
			     {
			      PNF_Number n(0);
			      yyval.put(n);
			     }


			 double d1 = yyvsp[-2].to_number().get();
			 double d2 = yyvsp[0].to_number().get();
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
			 yyval.put(n);
			    }
			    break;

    		            default:
			     PNF_Number n(0);
			     yyval.put(n);
			     break;
			   }
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[-2].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }			
			}
#line 9649 "pnfha.tab.cpp"
    break;

  case 289: /* function_expression: function_command  */
#line 5852 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];
			}
#line 9657 "pnfha.tab.cpp"
    break;

  case 290: /* function_expression: LEFTP function_expression RIGHTP  */
#line 5856 "pnfha.ypp"
                        {
			 yyval = yyvsp[-1];
			}
#line 9665 "pnfha.tab.cpp"
    break;

  case 291: /* $@81: %empty  */
#line 5862 "pnfha.ypp"
                        {
			 funcnum = (unsigned long)yyvsp[0].to_number().get();
			}
#line 9673 "pnfha.tab.cpp"
    break;

  case 292: /* $@82: %empty  */
#line 5866 "pnfha.ypp"
                        {
			 fsaveid2 = yyvsp[0];

			 conprint("FCALL TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
			 conprint("FCPARAMS TVOID 0V\n");
			}
#line 9684 "pnfha.tab.cpp"
    break;

  case 293: /* $@83: %empty  */
#line 5873 "pnfha.ypp"
                        {
			 pnum3 = 0;
			 pnum4 = 0;
			}
#line 9693 "pnfha.tab.cpp"
    break;

  case 294: /* $@84: %empty  */
#line 5878 "pnfha.ypp"
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
#line 9717 "pnfha.tab.cpp"
    break;

  case 295: /* $@85: %empty  */
#line 5897 "pnfha.ypp"
                        {
			 if(fncdefault)
			 {
			  fncdefault = false;
			  conprint("FNCDEFAULT2 TVOID 0V\n");
			 }

			 conprint("FECPARAMS TVOID 0V\n");
			}
#line 9731 "pnfha.tab.cpp"
    break;

  case 296: /* $@86: %empty  */
#line 5907 "pnfha.ypp"
                        {
			 conprint("FECALL TVOID 0V\n");
			}
#line 9739 "pnfha.tab.cpp"
    break;

  case 297: /* function_command: FUNCCALL OPCOLON NUMBERV $@81 LEFTP vars3 RIGHTP ID $@82 LEFTP $@83 actual_function_parameters $@84 $@85 RIGHTP $@86 nothing  */
#line 5911 "pnfha.ypp"
                        {
			 for (unsigned long i = frets3.length() - 1; i > 0; --i)
			  frets3.remove();
			 frets3[0] = "";

			 for (unsigned long i = fparams3.length() - 1; i > 0; --i)
			  fparams3.remove();
			 fparams3[0] = "";
			}
#line 9753 "pnfha.tab.cpp"
    break;

  case 298: /* actual_function_parameters: dv  */
#line 5923 "pnfha.ypp"
                                {

				}
#line 9761 "pnfha.tab.cpp"
    break;

  case 299: /* dv: opt_expressions  */
#line 5930 "pnfha.ypp"
                                {
				 yyval = yyvsp[0];				 

				 for (unsigned long i = 0; i < funcps[funcps.length() - 1].length(); ++i)
			 	 {
			 	  funcps[funcps.length() - 1][i].value(yyvsp[0]);
			 	 }
				}
#line 9774 "pnfha.tab.cpp"
    break;

  case 300: /* opt_expressions: opt_expression  */
#line 5941 "pnfha.ypp"
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
#line 9821 "pnfha.tab.cpp"
    break;

  case 301: /* opt_expressions: opt_expressions COMMA opt_expression  */
#line 5984 "pnfha.ypp"
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
#line 9868 "pnfha.tab.cpp"
    break;

  case 302: /* opt_expressions: DEFAULTV2 OPCOLON TYPE  */
#line 6027 "pnfha.ypp"
                                {
				 PNF_Type_Enum t;
			  	 if (yyvsp[0].to_string().get() == "void")
				  t = TVOID;
				 else if (yyvsp[0].to_string().get() == "boolean")
				  t = TBOOLEAN;
				 else if (yyvsp[0].to_string().get() == "number")
				  t = TNUMBER;
				 else if (yyvsp[0].to_string().get() == "character")
				  t = TCHARACTER;
				 else if (yyvsp[0].to_string().get() == "string")
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
#line 9998 "pnfha.tab.cpp"
    break;

  case 303: /* opt_expressions: opt_expressions COMMA DEFAULTV2 OPCOLON TYPE  */
#line 6153 "pnfha.ypp"
                                {
				 PNF_Type_Enum t;
			  	 if (yyvsp[0].to_string().get() == "void")
				  t = TVOID;
				 else if (yyvsp[0].to_string().get() == "boolean")
				  t = TBOOLEAN;
				 else if (yyvsp[0].to_string().get() == "number")
				  t = TNUMBER;
				 else if (yyvsp[0].to_string().get() == "character")
				  t = TCHARACTER;
				 else if (yyvsp[0].to_string().get() == "string")
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
#line 10128 "pnfha.tab.cpp"
    break;

  case 304: /* opt_expression: expression  */
#line 6298 "pnfha.ypp"
                                {
				 yyval = yyvsp[0];
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
#line 10174 "pnfha.tab.cpp"
    break;

  case 305: /* declaration: variable_declaration  */
#line 6433 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			}
#line 10183 "pnfha.tab.cpp"
    break;

  case 306: /* declaration: label_declaration  */
#line 6438 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration"); 
		         tree.add_node(declaration);
			}
#line 10192 "pnfha.tab.cpp"
    break;

  case 307: /* declaration: enum_declaration  */
#line 6443 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 10201 "pnfha.tab.cpp"
    break;

  case 308: /* declaration: range_declaration  */
#line 6448 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 10210 "pnfha.tab.cpp"
    break;

  case 309: /* declaration: struct_declaration  */
#line 6453 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 10219 "pnfha.tab.cpp"
    break;

  case 310: /* declaration: struct_declaration2  */
#line 6458 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 10228 "pnfha.tab.cpp"
    break;

  case 311: /* declaration: struct_var_declaration3  */
#line 6463 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 10237 "pnfha.tab.cpp"
    break;

  case 312: /* declaration: union_declaration  */
#line 6468 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 10246 "pnfha.tab.cpp"
    break;

  case 313: /* declaration: union_declaration2  */
#line 6473 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 10255 "pnfha.tab.cpp"
    break;

  case 314: /* declaration: union_var_declaration3  */
#line 6478 "pnfha.ypp"
                        {
			 ASTNode declaration("declaration");
			 tree.add_node(declaration);
			}
#line 10264 "pnfha.tab.cpp"
    break;

  case 315: /* variable_declaration: VAR ID  */
#line 6485 "pnfha.ypp"
                        {
			 ASTNode variable_declaration("variable_declaration"); 

			 bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Number n(0);
			   PNF_Variable p(n);
			   varTable[scope][i].value(p);
			   yyval.put(varTable[scope][i].value().to_number());
			  }
			 }

			 if (!declared)
			 {
			  varTable[scope].insert();
			  varTable[scope][varTable[scope].length() - 1].name(yyvsp[0].to_string().get());
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
			  yyval.put(varTable[scope][varTable[scope].length() - 1].value().to_number());

			  if (varTable[scope].length() - 2 <= 0)
		  	   varTable[scope][varTable[scope].length() - 1].address(scope + 0);
			  else
			   varTable[scope][varTable[scope].length() - 1].address(scope + (varTable[scope][varTable[scope].length() - 2].address() + 1));
			 }
		         tree.add_node(variable_declaration);
			}
#line 10326 "pnfha.tab.cpp"
    break;

  case 316: /* variable_declaration: VAR ID OPEQUAL expression  */
#line 6543 "pnfha.ypp"
                        {
			 ASTNode variable_declaration("variable_declaration"); 

			 bool declared = false;
	     	 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[-2].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   varTable[scope][i].value(yyvsp[0]);
			
			   switch (yyvsp[0].getType())
			   {
			    case TVOID:
			     yyval.put("0V");
			     break;
			
			    case TBOOLEAN:
			     yyval.put(varTable[scope][i].value().to_boolean());
			     break;

			    case TNUMBER:
			     yyval.put(varTable[scope][i].value().to_number());
			     break;

			    case TCHARACTER:
			     yyval.put(varTable[scope][i].value().to_character());
			     break;

			    case TSTRING:
			     yyval.put(varTable[scope][i].value().to_string());
			     break;
			   }

               switch (yyval.getType())
		       {
			    case TVOID:
   			     conprint("ALOAD TVOID 0V\n");
			     break;

			    case TBOOLEAN:
   			     conprint("ALOAD TBOOLEAN %s\n", yyval.to_boolean().get().getString().c_str());
			     break;

			    case TNUMBER:
   			     conprint("ALOAD TNUMBER %g\n", yyval.to_number().get());
			     break;

			    case TCHARACTER:
   			     conprint("ALOAD TCHARACTER \'%c\'\n", yyval.to_character().get());
			     break;

			    case TSTRING:
   			     conprint("ALOAD TSTRING \"%s\"\n", yyval.to_string().get().getString().c_str());
			     break;
			   }

               conprint("VSTORE TNUMBER %g\n", varcount - 1);
			  }
			 }

			 if (!declared)
			 {
			  varTable[scope].insert();

			  varTable[scope][varTable[scope].length() - 1].name(yyvsp[-2].to_string().get());
			  varTable[scope][varTable[scope].length() - 1].value(yyvsp[0]);

			  yyval = yyvsp[0];

			  switch (yyval.getType())
		    	  {
			   case TVOID:
   			    conprint("ALOAD TVOID 0V\n");
			    break;

			   case TBOOLEAN:
   			    conprint("ALOAD TBOOLEAN %s\n", yyval.to_boolean().get().getString().c_str());
			    break;

			   case TNUMBER:
   			    conprint("ALOAD TNUMBER %g\n", yyval.to_number().get());
			    break;

			   case TCHARACTER:
   			    conprint("ALOAD TCHARACTER \'%c\'\n", yyval.to_character().get());
			    break;

			   case TSTRING:
   			    conprint("ALOAD TSTRING \"%s\"\n", yyval.to_string().get().getString().c_str());
			    break;
			  }
			  conprint("VSTORE TVOID 0V\n");
			  ++varcount;

			  unsigned long paddress = 0;
              paddress = varcount - 1;
			
			  varTable[scope][varTable[scope].length() - 1].address(paddress);
			 }
		     tree.add_node(variable_declaration);
			}
#line 10433 "pnfha.tab.cpp"
    break;

  case 317: /* variable_declaration: FVAR ID  */
#line 6646 "pnfha.ypp"
                        {
			 ASTNode variable_declaration("variable_declaration"); 

			 bool declared = false;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   PNF_Number n(0);
			   PNF_Variable p(n);
			   varTable[scope][i].value(p);
			   yyval.put(varTable[scope][i].value().to_number());
			  }
			 }

			 if (!declared)
			 {
			  varTable[scope].insert();
			  varTable[scope][varTable[scope].length() - 1].name(yyvsp[0].to_string().get());
			  PNF_Number n(0);
			  PNF_Variable p(n);
			  varTable[scope][varTable[scope].length() - 1].value(p);

			  ++varcount;
			  yyval.put(varTable[scope][varTable[scope].length() - 1].value().to_number());

			  if (varTable[scope].length() - 2 <= 0)
		  	   varTable[scope][varTable[scope].length() - 1].address(scope + 0);
			  else
			   varTable[scope][varTable[scope].length() - 1].address(scope + (varTable[scope][varTable[scope].length() - 2].address() + 1));
			 }
		         tree.add_node(variable_declaration);
			}
#line 10472 "pnfha.tab.cpp"
    break;

  case 318: /* variable_declaration: enumv_declaration  */
#line 6681 "pnfha.ypp"
                        {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 10481 "pnfha.tab.cpp"
    break;

  case 319: /* variable_declaration: rangev_declaration  */
#line 6686 "pnfha.ypp"
                        {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 10490 "pnfha.tab.cpp"
    break;

  case 320: /* variable_declaration: array_declaration  */
#line 6691 "pnfha.ypp"
                        {
			 ASTNode variable_declaration("variable_declaration");
			 tree.add_node(variable_declaration);
			}
#line 10499 "pnfha.tab.cpp"
    break;

  case 321: /* enumv_declaration: ENUMV STRINGV STRINGV OPEQUAL STRINGV  */
#line 6698 "pnfha.ypp"
                        {
			 ASTNode enumv_declaration("enumv_declaration");

			 conprint("ENUMS TSTRING %s\n", yyvsp[-3].to_string().get().getString().c_str());
			 conprint("ENUM TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 conprint("SENUM TSTRING %s\n", yyvsp[-2].to_string().get().getString().c_str());

			 tree.add_node(enumv_declaration);
			}
#line 10513 "pnfha.tab.cpp"
    break;

  case 322: /* rangev_declaration: RANGEV RTYPE2 STRINGV STRINGV OPEQUAL STRINGV  */
#line 6710 "pnfha.ypp"
                        {
			 ASTNode rangev_declaration("rangev_declaration");

			 if (yyvsp[-4].to_string().get() == "rtype1")
			 {
			  conprint("RSTART1 TSTRING %s\n", yyvsp[-3].to_string().get().getString().c_str());
			  conprint("RANGE1 TNUMBER %s\n", strip_quotes(yyvsp[0].to_string().get()).getString().c_str());
			  conprint("REND1 TSTRING %s\n", yyvsp[-2].to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(rangev_declaration);
			}
#line 10532 "pnfha.tab.cpp"
    break;

  case 323: /* rangev_declaration: RANGEV RTYPE2 STRINGV STRINGV  */
#line 6725 "pnfha.ypp"
                        {
			 ASTNode rangev_declaration("rangev_declaration");

			 if (yyvsp[-2].to_string().get() == "rtype2")
			 {
			  conprint("RSTART2 TSTRING %s\n", yyvsp[-1].to_string().get().getString().c_str());
			  conprint("RANGE2 TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(rangev_declaration);
			}
#line 10550 "pnfha.tab.cpp"
    break;

  case 324: /* array_declaration: ARRAY STRINGV OPLSQ number_expression OPRSQ  */
#line 6741 "pnfha.ypp"
                        {
			 ASTNode array_declaration("array_declaration");

			 conprint("ASTART TSTRING %s\n", yyvsp[-3].to_string().get().getString().c_str());
			 conprint("AEND TNUMBER %g\n", yyvsp[-1].to_number().get());

			 tree.add_node(array_declaration);
			}
#line 10563 "pnfha.tab.cpp"
    break;

  case 325: /* $@88: %empty  */
#line 6752 "pnfha.ypp"
                        {
			 ASTNode enum_declarationp1("enum_declarationp1");

			 conprint("ESTART TSTRING \"%s\"\n", yyvsp[-2].to_string().get().getString().c_str());

			 tree.add_node(enum_declarationp1);
			}
#line 10575 "pnfha.tab.cpp"
    break;

  case 326: /* $@89: %empty  */
#line 6760 "pnfha.ypp"
                        {
			 ASTNode enum_declarationp2("enum_declarationp2");
			 tree.add_node(enum_declarationp2);
			}
#line 10584 "pnfha.tab.cpp"
    break;

  case 327: /* enum_declaration: ENUM ID OPEQUAL LEFTB $@88 enum_strings $@89 RIGHTB  */
#line 6765 "pnfha.ypp"
                        {
			 ASTNode enum_declarationp3("enum_declarationp3");

			 conprint("EEND TVOID 0V\n");

			 tree.add_node(enum_declarationp3);
			}
#line 10596 "pnfha.tab.cpp"
    break;

  case 328: /* enum_strings: STRINGV  */
#line 6775 "pnfha.ypp"
                        {
			 ASTNode enum_strings("enum_strings");

			 conprint("ENAME TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());

			 tree.add_node(enum_strings);
			}
#line 10608 "pnfha.tab.cpp"
    break;

  case 329: /* enum_strings: enum_strings COMMA STRINGV  */
#line 6783 "pnfha.ypp"
                        {
			 conprint("ENAME TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			}
#line 10616 "pnfha.tab.cpp"
    break;

  case 330: /* range_declaration: RANGE RTYPE2 STRINGV OPEQUAL STRINGV OPDOT OPDOT STRINGV  */
#line 6789 "pnfha.ypp"
                        {
			 ASTNode range_declaration("range_declaration");

			 if (yyvsp[-6].to_string().get() == "rtype1")
			 {
			  conprint("RDSTART1 TSTRING %s\n", yyvsp[-5].to_string().get().getString().c_str());
			  conprint("RFROM1 TNUMBER %s\n", strip_quotes(yyvsp[-3].to_string().get()).getString().c_str());
			  conprint("RTO1 TNUMBER %s\n", strip_quotes(yyvsp[0].to_string().get()).getString().c_str());
			  conprint("RDEND1 TVOID 0V\n");
			 }
			 else if (yyvsp[-6].to_string().get() == "rtype2")
			 {
			  conprint("RDSTART2 TSTRING %s\n", yyvsp[-5].to_string().get().getString().c_str());
			  conprint("RFROM2 TNUMBER %s\n", strip_quotes(yyvsp[-3].to_string().get()).getString().c_str());
			  conprint("RTO2 TNUMBER %s\n", strip_quotes(yyvsp[0].to_string().get()).getString().c_str());
			  conprint("RDEND2 TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(range_declaration);
			}
#line 10643 "pnfha.tab.cpp"
    break;

  case 331: /* $@90: %empty  */
#line 6814 "pnfha.ypp"
                        {
			 conprint("STRUCT TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
			}
#line 10651 "pnfha.tab.cpp"
    break;

  case 333: /* struct_body: LEFTB struct_var_declarations RIGHTB  */
#line 6823 "pnfha.ypp"
                        {
			 conprint("ENDSTRUCT TVOID 0V\n");
			}
#line 10659 "pnfha.tab.cpp"
    break;

  case 336: /* $@91: %empty  */
#line 6833 "pnfha.ypp"
                                {
				 conprint("STRUCTVAR TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
				}
#line 10667 "pnfha.tab.cpp"
    break;

  case 338: /* struct_declaration2: STRUCT ID ID  */
#line 6840 "pnfha.ypp"
                                {
				 conprint("STRUCTNAME TSTRING \"%s\"\n", yyvsp[-1].to_string().get().getString().c_str());
				 conprint("STRUCTD TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
				}
#line 10676 "pnfha.tab.cpp"
    break;

  case 339: /* struct_var_declaration3: STRUCT ID ID OPDOT ID OPEQUAL expression  */
#line 6847 "pnfha.ypp"
                                {
				 conprint("STRUCTNAME TSTRING \"%s\"\n", yyvsp[-5].to_string().get().getString().c_str());
				 conprint("STRUCTONAME TSTRING \"%s\"\n", yyvsp[-4].to_string().get().getString().c_str());
				 conprint("STRUCTUSE TSTRING \"%s\"\n", yyvsp[-2].to_string().get().getString().c_str());
				 
				 switch (yyvsp[0].getType())
				 {
				  case TVOID:
				  {
				   conprint("ALOAD TVOID 0V\n");
				  }
				  break;

				  case TBOOLEAN:
				  {
				   conprint("ALOAD TBOOLEAN %s\n", yyvsp[0].to_boolean().get());
				  }
				  break;

				  case TNUMBER:
				  {
				   conprint("ALOAD TNUMBER %f\n", yyvsp[0].to_number().get());
				  }
				  break;

				  case TCHARACTER:
				  {
				   conprint("ALOAD TCHARACTER '%c'\n", yyvsp[-1].to_character().get());
				  }
				  break;

				  case TSTRING:
				  {
				   conprint("ALOAD TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
				  }
				  break;

				  default:
				   yyerror((char *)"Invalid type.");
				 }

				 conprint("STRUCTPUT TVOID 0V\n");
				}
#line 10724 "pnfha.tab.cpp"
    break;

  case 340: /* $@92: %empty  */
#line 6893 "pnfha.ypp"
                        {
			 conprint("UNION TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
			}
#line 10732 "pnfha.tab.cpp"
    break;

  case 342: /* union_body: LEFTB union_var_declarations RIGHTB  */
#line 6902 "pnfha.ypp"
                        {
			 conprint("ENDUNION TVOID 0V\n");
			}
#line 10740 "pnfha.tab.cpp"
    break;

  case 345: /* $@93: %empty  */
#line 6912 "pnfha.ypp"
                                {
				 conprint("UNIONVAR TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
				}
#line 10748 "pnfha.tab.cpp"
    break;

  case 347: /* union_declaration2: UNION ID ID  */
#line 6919 "pnfha.ypp"
                                {
				 conprint("UNIONNAME TSTRING \"%s\"\n", yyvsp[-1].to_string().get().getString().c_str());
				 conprint("UNIOND TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
				}
#line 10757 "pnfha.tab.cpp"
    break;

  case 348: /* union_var_declaration3: UNION ID ID OPDOT ID OPEQUAL expression  */
#line 6926 "pnfha.ypp"
                                {
				 conprint("UNIONNAME TSTRING \"%s\"\n", yyvsp[-5].to_string().get().getString().c_str());
				 conprint("UNIONONAME TSTRING \"%s\"\n", yyvsp[-4].to_string().get().getString().c_str());
				 conprint("UNIONUSE TSTRING \"%s\"\n", yyvsp[-2].to_string().get().getString().c_str());
				 
				 switch (yyvsp[0].getType())
				 {
				  case TVOID:
				  {
				   conprint("ALOAD TVOID 0V\n");
				  }
				  break;

				  case TBOOLEAN:
				  {
				   conprint("ALOAD TBOOLEAN %s\n", yyvsp[0].to_boolean().get());
				  }
				  break;

				  case TNUMBER:
				  {
				   conprint("ALOAD TNUMBER %f\n", yyvsp[0].to_number().get());
				  }
				  break;

				  case TCHARACTER:
				  {
				   conprint("ALOAD TCHARACTER '%c'\n", yyvsp[-1].to_character().get());
				  }
				  break;

				  case TSTRING:
				  {
				   conprint("ALOAD TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
				  }
				  break;

				  default:
				   yyerror((char *)"Invalid type.");
				 }

				 conprint("UNIONPUT TVOID 0V\n");
				}
#line 10805 "pnfha.tab.cpp"
    break;

  case 349: /* label_declaration: SUB ID  */
#line 6972 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  if (yyvsp[0].to_string().get().getString() == labelTable[i].name().getString())
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
			  labelTable[labelTable.length() - 1].name(yyvsp[0].to_string().get());
			  labelTable[labelTable.length() - 1].address(labelTable.length() - 2);
			 }

			 ASTNode label_declaration("label_declaration");
		         tree.add_node(label_declaration);
			}
#line 10833 "pnfha.tab.cpp"
    break;

  case 350: /* label_declaration: EVENT ID  */
#line 6996 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
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
			  eventLabelTable[eventLabelTable.length() - 1].name(yyvsp[0].to_string().get());
			  eventLabelTable[eventLabelTable.length() - 1].address(eventLabelTable.length() - 2);
			 }
			 ASTNode label_declaration("label_declaration");
		         tree.add_node(label_declaration);
			}
#line 10860 "pnfha.tab.cpp"
    break;

  case 351: /* label_declaration: LABEL ID  */
#line 7019 "pnfha.ypp"
                        {
			 bool declared = false;
			 for (unsigned long i = 0; i < labelTable.length(); ++i)
			 {
			  if (yyvsp[0].to_string().get().getString() == labelTable[i].name().getString())
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
			  labelTable[labelTable.length() - 1].name(yyvsp[0].to_string().get());
			  labelTable[labelTable.length() - 1].address(labelTable.length() - 2);
			 }

			 ASTNode label_declaration("label_declaration");
		         tree.add_node(label_declaration);
			}
#line 10888 "pnfha.tab.cpp"
    break;

  case 354: /* $@94: %empty  */
#line 7047 "pnfha.ypp"
                        {
			 funcps.insert();

			 funcptr->name(yyvsp[-3].to_string().get());			 
			 funcstk.add_function(*funcptr);
			 delete funcptr;
			 funcptr = NULL;			 
	
			 saveid3 = yyvsp[-3];
			 unsigned long index = funcstk.find(yyvsp[-3].to_string().get(), frets, fparams);
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
			 
			 
			 conprint("ALOAD TSTRING \"%s\"\n", yyvsp[-3].to_string().get().getString().c_str());
			 conprint("FNCSNAME TVOID 0V\n");
			 conprint("FNCSDEF TSTRING \"%s\"\n", funcstk.get_function(index).rname().getString().c_str());
			 conprint("FNCSTORE TVOID 0V\n");
			 conprint("FNCDELETE TVOID 0V\n");
			}
#line 10928 "pnfha.tab.cpp"
    break;

  case 355: /* function_declaration: FUNCDEF LEFTP vars RIGHTP ID LEFTP parameter_declaration RIGHTP $@94 nothing  */
#line 7083 "pnfha.ypp"
                        {
			 for (unsigned long i = frets.length() - 1; i > 0; --i)
			  frets.remove();

			 for (unsigned long i = fparams.length() - 1; i > 0; --i)
			  fparams.remove();
			}
#line 10940 "pnfha.tab.cpp"
    break;

  case 357: /* parameter_declaration: opt_var  */
#line 7095 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];

			 pnum = 0;
			 switch (exptype)
			 {
			  case TVOID:
			  {
			   PNF_Void v;
			   PNF_Variable v2(v);
			   funcptr->param(pnum, v2);
			   funcptr->pname(pnum, yyval.to_string().get());

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
			   funcptr->pname(pnum, yyval.to_string().get());

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
			   funcptr->pname(pnum, yyval.to_string().get());

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
			   funcptr->pname(pnum, yyval.to_string().get());

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
			   funcptr->pname(pnum, yyval.to_string().get());

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
#line 11037 "pnfha.tab.cpp"
    break;

  case 358: /* parameter_declaration: parameter_declaration COMMA VAR ID OPCOLON TYPE  */
#line 7188 "pnfha.ypp"
                        {
			 yyval = yyvsp[-2];


			 String type = yyvsp[0].to_string().get();
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
			   funcptr->pname(pnum, yyval.to_string().get());

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
			   funcptr->pname(pnum, yyval.to_string().get());

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
			   funcptr->pname(pnum, yyval.to_string().get());

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
			   funcptr->pname(pnum, yyval.to_string().get());

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
			   funcptr->pname(pnum, yyval.to_string().get());

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
#line 11151 "pnfha.tab.cpp"
    break;

  case 359: /* parameter_declaration2: opt_var2  */
#line 7300 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];

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
#line 11257 "pnfha.tab.cpp"
    break;

  case 360: /* parameter_declaration2: parameter_declaration2 COMMA VAR ID OPCOLON TYPE opt_default_value  */
#line 7402 "pnfha.ypp"
                        {
			 String type = yyvsp[-1].to_string().get();
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
#line 11375 "pnfha.tab.cpp"
    break;

  case 361: /* parameter_declaration5: opt_var5  */
#line 7518 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];

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
#line 11424 "pnfha.tab.cpp"
    break;

  case 362: /* parameter_declaration5: parameter_declaration5 COMMA VAR ID OPCOLON TYPE  */
#line 7563 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 11485 "pnfha.tab.cpp"
    break;

  case 363: /* parameter_declaration6: opt_var6  */
#line 7622 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];

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
#line 11534 "pnfha.tab.cpp"
    break;

  case 364: /* parameter_declaration6: parameter_declaration6 COMMA VAR ID OPCOLON TYPE  */
#line 7667 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 11595 "pnfha.tab.cpp"
    break;

  case 365: /* opt_var: VAR ID OPCOLON TYPE  */
#line 7726 "pnfha.ypp"
                        {
			 yyval = yyvsp[-2];

			 String type = yyvsp[0].to_string().get();
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
#line 11617 "pnfha.tab.cpp"
    break;

  case 366: /* opt_var: VOIDV  */
#line 7744 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];

			 exptype = TVOID;
			}
#line 11627 "pnfha.tab.cpp"
    break;

  case 367: /* opt_var2: VAR ID OPCOLON TYPE opt_default_value  */
#line 7752 "pnfha.ypp"
                        {
			 yyval = yyvsp[-3];

			 String type = yyvsp[-1].to_string().get();
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
#line 11649 "pnfha.tab.cpp"
    break;

  case 368: /* opt_var2: VOIDV  */
#line 7770 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];

			 exptype = TVOID;
			}
#line 11659 "pnfha.tab.cpp"
    break;

  case 370: /* opt_default_value: dvalue  */
#line 7778 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];


			 funcps[fsaveindex + 1].insert();
			 funcps[fsaveindex + 1][pnum5].value(yyval);


			 funcstk.get_function(fsaveindex + 1).defaultv(pnum5, yyval);
			 funcstk.get_function(fsaveindex + 1).syncdefaultp(pnum5);
			}
#line 11675 "pnfha.tab.cpp"
    break;

  case 371: /* dvalue: OPEQUAL expression OPCOLON NUMBERV  */
#line 7792 "pnfha.ypp"
                        {
			 yyval = yyvsp[-2];
			 pnum5 = (unsigned long)yyvsp[0].to_number().get();
			}
#line 11684 "pnfha.tab.cpp"
    break;

  case 373: /* optdefaultv: DEFAULTV  */
#line 7799 "pnfha.ypp"
                        {
			 fncdefault = true;
			 conprint("FNCDEFAULT TVOID 0V\n");
			}
#line 11693 "pnfha.tab.cpp"
    break;

  case 374: /* opt_var5: VAR ID OPCOLON TYPE  */
#line 7806 "pnfha.ypp"
                        {
			 yyval = yyvsp[-2];

			 String type = yyvsp[0].to_string().get();
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
#line 11715 "pnfha.tab.cpp"
    break;

  case 375: /* opt_var5: VOIDV  */
#line 7824 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];

			 exptype = TVOID;
			}
#line 11725 "pnfha.tab.cpp"
    break;

  case 376: /* opt_var6: VAR ID OPCOLON TYPE  */
#line 7832 "pnfha.ypp"
                        {
			 yyval = yyvsp[-2];

			 String type = yyvsp[0].to_string().get();
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
#line 11747 "pnfha.tab.cpp"
    break;

  case 377: /* opt_var6: VOIDV  */
#line 7850 "pnfha.ypp"
                        {
			 yyval = yyvsp[0];

			 exptype = TVOID;
			}
#line 11757 "pnfha.tab.cpp"
    break;

  case 378: /* $@95: %empty  */
#line 7858 "pnfha.ypp"
                        {
			 pnum5 = 0;


			 fsaveid = yyvsp[-3];
			 unsigned long index = funcstk.find(yyvsp[-3].to_string().get(), frets2, fparams2);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 fsaveindex = index;

			 conprint("GOTOL TSTRING \"%s_END\"\n", funcstk.get_function(index).rname().getString().c_str());
			 conprint("LBL TSTRING \"%s\"\n", funcstk.get_function(index).rname().getString().c_str());
			}
#line 11779 "pnfha.tab.cpp"
    break;

  case 379: /* $@96: %empty  */
#line 7876 "pnfha.ypp"
                        {
			 unsigned long index = funcstk.find(fsaveid.to_string().get(), frets2, fparams2);
			 if (index == -1)
			 {
			  yyerror("Function not found.");
			  exit(-1);
			 }

			 conprint("LBL TSTRING \"%s_END\"\n", funcstk.get_function(index).rname().getString().c_str());
			}
#line 11794 "pnfha.tab.cpp"
    break;

  case 380: /* function_declaration2: FUNCTION optdefaultv LEFTP vars2 RIGHTP ID LEFTP parameter_declaration2 RIGHTP $@95 function_body $@96 nothing  */
#line 7887 "pnfha.ypp"
                        {
			 for (unsigned long i = frets2.length() - 1; i > 0; --i)
			  frets2.remove();

			 for (unsigned long i = fparams2.length() - 1; i > 0; --i)
			  fparams2.remove();
			}
#line 11806 "pnfha.tab.cpp"
    break;

  case 382: /* vars: VOIDV  */
#line 7902 "pnfha.ypp"
                        {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");

			 exptype = TVOID;
			}
#line 11818 "pnfha.tab.cpp"
    break;

  case 383: /* vars: VAR OPCOLON TYPE  */
#line 7910 "pnfha.ypp"
                        {
			 funcptr = new Function();

		  	 conprint("FNCNEW TVOID 0V\n");


			 String type = yyvsp[0].to_string().get();
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
#line 11908 "pnfha.tab.cpp"
    break;

  case 384: /* vars: vars COMMA VAR OPCOLON TYPE  */
#line 7996 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 11992 "pnfha.tab.cpp"
    break;

  case 385: /* vars2: VOIDV  */
#line 8078 "pnfha.ypp"
                        {
			 exptype = TVOID;
			}
#line 12000 "pnfha.tab.cpp"
    break;

  case 386: /* vars2: VAR OPCOLON TYPE  */
#line 8082 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 12052 "pnfha.tab.cpp"
    break;

  case 387: /* vars2: vars2 COMMA VAR OPCOLON TYPE  */
#line 8130 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 12104 "pnfha.tab.cpp"
    break;

  case 388: /* vars3: VOIDV  */
#line 8180 "pnfha.ypp"
                        {
			 exptype = TVOID;			}
#line 12111 "pnfha.tab.cpp"
    break;

  case 389: /* vars3: VAR OPCOLON TYPE  */
#line 8183 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 12177 "pnfha.tab.cpp"
    break;

  case 390: /* vars3: vars3 COMMA VAR OPCOLON TYPE  */
#line 8245 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 12250 "pnfha.tab.cpp"
    break;

  case 391: /* vars5: VOIDV  */
#line 8452 "pnfha.ypp"
                        {
			 exptype = TVOID;
			}
#line 12258 "pnfha.tab.cpp"
    break;

  case 392: /* vars5: VAR OPCOLON TYPE  */
#line 8456 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 12310 "pnfha.tab.cpp"
    break;

  case 393: /* vars5: vars5 COMMA VAR OPCOLON TYPE  */
#line 8504 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 12362 "pnfha.tab.cpp"
    break;

  case 394: /* vars6: VOIDV  */
#line 8554 "pnfha.ypp"
                        {
			 exptype = TVOID;
			}
#line 12370 "pnfha.tab.cpp"
    break;

  case 395: /* vars6: VAR OPCOLON TYPE  */
#line 8558 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 12422 "pnfha.tab.cpp"
    break;

  case 396: /* vars6: vars6 COMMA VAR OPCOLON TYPE  */
#line 8606 "pnfha.ypp"
                        {
			 String type = yyvsp[0].to_string().get();
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
#line 12474 "pnfha.tab.cpp"
    break;

  case 397: /* command: print_command  */
#line 8658 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12483 "pnfha.tab.cpp"
    break;

  case 398: /* command: read_command  */
#line 8663 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12492 "pnfha.tab.cpp"
    break;

  case 399: /* command: end_command  */
#line 8668 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12501 "pnfha.tab.cpp"
    break;

  case 400: /* command: asm_command  */
#line 8673 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12510 "pnfha.tab.cpp"
    break;

  case 401: /* command: load_command  */
#line 8678 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12519 "pnfha.tab.cpp"
    break;

  case 402: /* command: goto_command  */
#line 8683 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12528 "pnfha.tab.cpp"
    break;

  case 403: /* command: operator_command  */
#line 8688 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12537 "pnfha.tab.cpp"
    break;

  case 404: /* command: st_command  */
#line 8693 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12546 "pnfha.tab.cpp"
    break;

  case 405: /* command: stack_command  */
#line 8698 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12555 "pnfha.tab.cpp"
    break;

  case 406: /* command: typeof_command  */
#line 8703 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12564 "pnfha.tab.cpp"
    break;

  case 407: /* command: rm_command  */
#line 8708 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12573 "pnfha.tab.cpp"
    break;

  case 408: /* command: crash_command  */
#line 8713 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12582 "pnfha.tab.cpp"
    break;

  case 409: /* command: version_command  */
#line 8718 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12591 "pnfha.tab.cpp"
    break;

  case 410: /* command: halt_command  */
#line 8723 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12600 "pnfha.tab.cpp"
    break;

  case 411: /* command: modt_command  */
#line 8728 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12609 "pnfha.tab.cpp"
    break;

  case 412: /* command: subroutine_command  */
#line 8733 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12618 "pnfha.tab.cpp"
    break;

  case 413: /* command: register_command  */
#line 8738 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12627 "pnfha.tab.cpp"
    break;

  case 414: /* command: store_command  */
#line 8743 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12636 "pnfha.tab.cpp"
    break;

  case 415: /* command: break_command  */
#line 8748 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12645 "pnfha.tab.cpp"
    break;

  case 416: /* command: address_command  */
#line 8753 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12654 "pnfha.tab.cpp"
    break;

  case 417: /* command: add2v_command  */
#line 8758 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12663 "pnfha.tab.cpp"
    break;

  case 418: /* command: continue_command  */
#line 8763 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12672 "pnfha.tab.cpp"
    break;

  case 419: /* command: check_command  */
#line 8768 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12681 "pnfha.tab.cpp"
    break;

  case 420: /* command: comment_command  */
#line 8773 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12690 "pnfha.tab.cpp"
    break;

  case 421: /* command: file_command  */
#line 8778 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12699 "pnfha.tab.cpp"
    break;

  case 422: /* command: meml_command  */
#line 8783 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12708 "pnfha.tab.cpp"
    break;

  case 423: /* command: pnfasm_command  */
#line 8788 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12717 "pnfha.tab.cpp"
    break;

  case 424: /* command: array_length_command  */
#line 8793 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12726 "pnfha.tab.cpp"
    break;

  case 425: /* command: dup_command  */
#line 8798 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12735 "pnfha.tab.cpp"
    break;

  case 426: /* command: fret_command  */
#line 8803 "pnfha.ypp"
                        {
			 ASTNode command("command");
		         tree.add_node(command);
			}
#line 12744 "pnfha.tab.cpp"
    break;

  case 432: /* print_command: PRINT  */
#line 8816 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 conprint("PRINT TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 12754 "pnfha.tab.cpp"
    break;

  case 433: /* print_command: PRINT expression  */
#line 8822 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("PRINT TBOOLEAN %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("PRINT TNUMBER %g\n", yyvsp[0].to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = yyvsp[0].to_string().get();
			   
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
			   conprint("PRINT TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 12804 "pnfha.tab.cpp"
    break;

  case 434: /* print_command: PRINT CTYPE  */
#line 8868 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");

			 if (yyvsp[0].to_string().get() == "ver")
			  conprint("VPRINT TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			}
#line 12819 "pnfha.tab.cpp"
    break;

  case 435: /* print_command: PRINTLN  */
#line 8879 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 conprint("PRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 12829 "pnfha.tab.cpp"
    break;

  case 436: /* print_command: PRINTLN expression  */
#line 8885 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("PRINTLN TBOOLEAN %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("PRINTLN TNUMBER %g\n", yyvsp[0].to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = yyvsp[0].to_string().get();
			   
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
                           conprint("PRINTLN TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 12879 "pnfha.tab.cpp"
    break;

  case 437: /* print_command: PRINTLN CTYPE  */
#line 8931 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");

			 if (yyvsp[0].to_string().get() == "ver")
			  conprint("VPRINTLN TVOID 0V\n");
			 else
 			  yyerror("Invalid check type.");

			 tree.add_node(print_command);
			}
#line 12894 "pnfha.tab.cpp"
    break;

  case 438: /* print_command: EPRINT  */
#line 8942 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 conprint("EPRINT TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 12904 "pnfha.tab.cpp"
    break;

  case 439: /* print_command: EPRINT expression  */
#line 8948 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("EPRINT TBOOLEAN %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("EPRINT TNUMBER %g\n", yyvsp[0].to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = yyvsp[0].to_string().get();
			   
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
			   conprint("EPRINT TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 12954 "pnfha.tab.cpp"
    break;

  case 440: /* print_command: EPRINTLN  */
#line 8994 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 conprint("EPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 12964 "pnfha.tab.cpp"
    break;

  case 441: /* print_command: EPRINTLN expression  */
#line 9000 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("EPRINTLN TBOOLEAN %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("EPRINTLN TNUMBER %g\n", yyvsp[0].to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = yyvsp[0].to_string().get();
			   
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
			   conprint("EPRINTLN TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 13014 "pnfha.tab.cpp"
    break;

  case 442: /* print_command: FPRINT  */
#line 9046 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 conprint("FPRINT TVOID 0V\n");
			}
#line 13023 "pnfha.tab.cpp"
    break;

  case 443: /* print_command: FPRINT expression  */
#line 9051 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot print void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("FPRINT TBOOLEAN %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("FPRINT TNUMBER %g\n", yyvsp[0].to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = yyvsp[0].to_string().get();
			   
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
			   conprint("FPRINT TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 13073 "pnfha.tab.cpp"
    break;

  case 444: /* print_command: FPRINTLN  */
#line 9097 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 conprint("FPRINTLN TVOID 0V\n");
			 tree.add_node(print_command);
			}
#line 13083 "pnfha.tab.cpp"
    break;

  case 445: /* print_command: FPRINTLN expression  */
#line 9103 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			 switch (exptype)
			 {
			  case TVOID:
			   yyerror("Cannot println void expression.");
			   break;

			  case TBOOLEAN:
			   conprint("FPRINTLN TBOOLEAN %s\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("FPRINTLN TNUMBER %g\n", yyvsp[0].to_number().get());
			   break;

			  case TCHARACTER:
			  {
			   String str = yyvsp[0].to_string().get();
			   
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
                           conprint("FPRINTLN TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Invalid exptype.");
			 }
			 tree.add_node(print_command);
			}
#line 13133 "pnfha.tab.cpp"
    break;

  case 446: /* print_command: PRINT ARRAY STRINGV  */
#line 9149 "pnfha.ypp"
                        {
			 ASTNode print_command("print_command");
			
			 conprint("APREP TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 conprint("APRINT TVOID 0V\n");

			 tree.add_node(print_command);
			}
#line 13146 "pnfha.tab.cpp"
    break;

  case 447: /* read_command: READ TYPE ID  */
#line 9161 "pnfha.ypp"
                        {
			 ASTNode read_command("read_command");

			 bool declared = false;
			 unsigned long address = 0;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
    		           address = varTable[scope][i].address();
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " is not declared.";
			  yyerror(str.getString().c_str());
			 }


			 PNF_Variable v;
			 if (yyvsp[-1].to_string().get().getString() == "void")
			 {
			  yyerror("Cannot read a void.");
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "boolean")
			 {
			  conprint("READ TBOOLEAN 0V\n");
			  ++varcount;
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "number")
			 {
			  conprint("READ TNUMBER 0V\n");
			  ++varcount;
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "character")
			 {
			  conprint("READ TCHARACTER 0V\n");
			  ++varcount;
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "string")
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
#line 13209 "pnfha.tab.cpp"
    break;

  case 448: /* read_command: FREAD TYPE ID  */
#line 9220 "pnfha.ypp"
                        {
			 ASTNode read_command("read_command");

			 bool declared = false;
			 unsigned long address = 0;
	     		 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
    		           address = varTable[scope][i].address();
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " is not declared.";
			  yyerror(str.getString().c_str());
			 }


			 PNF_Variable v;
			 if (yyvsp[-1].to_string().get().getString() == "void")
			 {
			  yyerror("Cannot read a void.");
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "boolean")
			 {
			  conprint("FREAD TBOOLEAN 0V\n");
			  ++varcount;
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "number")
			 {
			  conprint("FREAD TNUMBER 0V\n");
			  ++varcount;
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "character")
			 {
			  conprint("FREAD TCHARACTER 0V\n");
			  ++varcount;
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "string")
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
	 		  if (strcmp(varTable[scope][i].name().getString().c_str(), yyvsp[0].to_string().get().getString().c_str()) == 0)
			  {
			   PNF_Number n(0);
			   v.put(n);
			   varTable[scope][i].value(v);
			   varTable[scope][i].address(varcount - 1);
			  }
			 }
			 tree.add_node(read_command);
			}
#line 13283 "pnfha.tab.cpp"
    break;

  case 449: /* end_command: END number_expression  */
#line 9293 "pnfha.ypp"
                        {
			 ASTNode end_command("end_command");
			 conprint("QUIT TVOID %g\n", yyvsp[0].to_number().get());
			 tree.add_node(end_command);
			}
#line 13293 "pnfha.tab.cpp"
    break;

  case 450: /* asm_command: ASM STRINGV STRINGV string_expression  */
#line 9301 "pnfha.ypp"
                        {
			 ASTNode asm_command("asm_command");
			 conprint("%s %s %s\n", strip_quotes(yyvsp[-2].to_string().get()).getString().c_str(), 
					      strip_quotes(yyvsp[-1].to_string().get()).getString().c_str(), strip_quotes(yyvsp[0].to_string().get()).getString().c_str());
			 tree.add_node(asm_command);
			}
#line 13304 "pnfha.tab.cpp"
    break;

  case 451: /* load_command: LOAD RTYPE LTYPE number_expression  */
#line 9310 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 if (yyvsp[-1].to_string().get().getString() == "memory")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
			  {
			   switch (yyvsp[0].getType())
			   {
			    case TBOOLEAN:
    			     conprint("LOAD TBOOLEAN %g\n", yyvsp[0].to_number().get());
			     break;

			    case TNUMBER:
    	 		     conprint("LOAD TNUMBER %g\n", yyvsp[0].to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("LOAD TCHARACTER %g\n", yyvsp[0].to_number().get());
			     break;

			    case TSTRING:
    			     conprint("LOAD TSTRING %g\n", yyvsp[0].to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else if (yyvsp[-2].to_string().get().getString() == "%calc")
			  {
			   switch (yyvsp[0].getType())
			   {
			    case TBOOLEAN:
    			     conprint("LOADC TBOOLEAN %g\n", yyvsp[0].to_number().get());
			     break;

			    case TNUMBER:
    	 		     conprint("LOADC TNUMBER %g\n", yyvsp[0].to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("LOADC TCHARACTER %g\n", yyvsp[0].to_number().get());
			     break;

			    case TSTRING:
    			     conprint("LOADC TSTRING %g\n", yyvsp[0].to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else
			   yyerror("Invalid register type.");
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "variable")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
			  {
			   switch (yyvsp[0].getType())
			   {
			    case TBOOLEAN:
    			     conprint("VLOAD TBOOLEAN %g\n", yyvsp[0].to_number().get());
			     break;

			    case TNUMBER:
    			     conprint("VLOAD TNUMBER %g\n", yyvsp[0].to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("VLOAD TCHARACTER %g\n", yyvsp[0].to_number().get());
			     break;

			    case TSTRING:
    			     conprint("VLOAD TSTRING %g\n", yyvsp[0].to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			  else if (yyvsp[-2].to_string().get().getString() == "%calc")
			  {
			   switch (yyvsp[0].getType())
			   {
			    case TBOOLEAN:
    			     conprint("VLOADC TBOOLEAN %g\n", yyvsp[0].to_number().get());
			     break;

			    case TNUMBER:
    			     conprint("VLOADC TNUMBER %g\n", yyvsp[0].to_number().get());
			     break;

			    case TCHARACTER:
    			     conprint("VLOADC TCHARACTER %g\n", yyvsp[0].to_number().get());
			     break;

			    case TSTRING:
    			     conprint("VLOADC TSTRING %g\n", yyvsp[0].to_number().get());
			     break;

			    default:
			     yyerror("Invalid load expression.");
			     break;
			   }
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "args")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
			   conprint("ARLOAD TVOID %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "aload")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
 			   conprint("ALOAD TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
                           yyerror("Invalid register type.");
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "stk")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
                           conprint("LOADSP TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "seg1")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
			   conprint("SEGLOAD TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror((char *)"Invalid register type.");
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 13452 "pnfha.tab.cpp"
    break;

  case 452: /* load_command: LOAD RTYPE LTYPE TYPE  */
#line 9454 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 if (yyvsp[-1].to_string().get().getString() == "tend")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
			  {
 			   PNF_Type_Enum t;
			   String str = yyvsp[0].to_string().get();
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
			  else if (yyvsp[-2].to_string().get().getString() == "%calc")
			  {
 			   PNF_Type_Enum t;
			   String str = yyvsp[0].to_string().get();
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
#line 13549 "pnfha.tab.cpp"
    break;

  case 453: /* load_command: LOAD LTYPE  */
#line 9547 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 if (yyvsp[0].to_string().get().getString() == "typeof")
			 {
			   conprint("TLOAD TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "iname")
			 {
			  conprint("INLOAD TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "icount")
			 {
			  conprint("ICLOAD TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "argn")
			 {
			  conprint("ARNLOAD TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "stk")
			  conprint("LOADSTACK TVOID 0V\n");	 
			 else
			  yyerror("Invalid load type.");
			}
#line 13581 "pnfha.tab.cpp"
    break;

  case 454: /* load_command: LOAD LTYPE boolean_expression  */
#line 9575 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 if (yyvsp[-1].to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TBOOLEAN %s\n", yyvsp[0].to_string().get().getString().c_str());
			 }			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 13596 "pnfha.tab.cpp"
    break;

  case 455: /* load_command: LOAD LTYPE number_expression  */
#line 9586 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 if (yyvsp[-1].to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TNUMBER %g\n", yyvsp[0].to_number().get());
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "rvalue")
			 {
			  conprint("RNUM TNUMBER %d\n", (unsigned long)yyvsp[0].to_number().get());
			  conprint("RETURNV TVOID 0V\n");
			 }			 
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 13617 "pnfha.tab.cpp"
    break;

  case 456: /* load_command: LOAD LTYPE character_expression  */
#line 9603 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 if (yyvsp[-1].to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TCHARACTER %c\n", yyvsp[0].to_character().get());
			 }			 
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 13633 "pnfha.tab.cpp"
    break;

  case 457: /* load_command: LOAD LTYPE string_expression  */
#line 9615 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 if (yyvsp[-1].to_string().get().getString() == "aload")
			 {
			  conprint("ALOAD TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 }			 
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 13649 "pnfha.tab.cpp"
    break;

  case 458: /* load_command: LOAD RTYPE LTYPE ID  */
#line 9627 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");

			 PNF_Variable p;
			 unsigned long paddress = 0;
             bool declared = false;
	     	 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
		  	 {
	 		  if (varTable[scope][i].name() == yyvsp[0].to_string().get())
			  {
			   declared = true;
			   p.put(varTable[scope][i].value());
			   paddress = varTable[scope][i].address();			   
			   break;
			  }
			 }

			 if (!declared)
			 {
			  String str = yyvsp[0].to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }

			 if (yyvsp[-1].to_string().get().getString() == "memory")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
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
			  else if (yyvsp[-2].to_string().get().getString() == "%calc")
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
			 else if (yyvsp[-1].to_string().get().getString() == "variable")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
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
			  else if (yyvsp[-2].to_string().get().getString() == "%calc")
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
			 else if (yyvsp[-1].to_string().get().getString() == "args")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
			   conprint("ARLOAD TVOID %g\n", p.to_number().get());
			  else
			   yyerror("Invalid register type.");
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "aload")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accumulator")
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
			 else if (yyvsp[-1].to_string().get().getString() == "seg2")
			 {
			  if (yyvsp[-2].to_string().get().getString() == "%accmumulator")
			  {
			   conprint("SEGVLOAD TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid load type.");

			 tree.add_node(load_command);
			}
#line 13835 "pnfha.tab.cpp"
    break;

  case 459: /* load_command: LOAD STYPE number_expression  */
#line 9809 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");

			 if (yyvsp[-1].to_string().get().getString() == "heve")
			  conprint("HEGET TVOID %g", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get().getString() == "sheve")
			  conprint("SHEGET TVOID %g", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get().getString() == "eve")
			  conprint("EGET TVOID %g", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get().getString() == "exe")
			  conprint("EXGET TVOID %g", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get().getString() == "int")
			  conprint("IGET TVOID %g", yyvsp[0].to_number().get());
		  	 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(load_command);
			}
#line 13858 "pnfha.tab.cpp"
    break;

  case 460: /* load_command: LOAD VTYPE2 STRINGV  */
#line 9828 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");

			 if (yyvsp[-1].to_string().get() == "venum")
			 {
			  conprint("EPREP TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			  conprint("LOADE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid VTYPE2.");

			 tree.add_node(load_command);
			}
#line 13876 "pnfha.tab.cpp"
    break;

  case 461: /* load_command: LOAD RANGE RTYPE2 STRINGV  */
#line 9842 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");

			 if (yyvsp[-1].to_string().get() == "rtype1")
			 {
			  conprint("RLOAD1 TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(load_command);
			}
#line 13893 "pnfha.tab.cpp"
    break;

  case 462: /* load_command: LOAD RANGE RTYPE2 STRINGV OPLSQ number_expression OPRSQ  */
#line 9855 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");

			 if (yyvsp[-4].to_string().get() == "rtype2")
			 {
			  conprint("RPREP2 TSTRING %s\n", yyvsp[-3].to_string().get().getString().c_str());
			  conprint("RLOAD2 TNUMBER %g\n", yyvsp[-1].to_number().get());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(load_command);
			}
#line 13911 "pnfha.tab.cpp"
    break;

  case 463: /* load_command: LOAD ARRAY STRINGV OPLSQ number_expression OPRSQ  */
#line 9869 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", yyvsp[-3].to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", yyvsp[-1].to_number().get());
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			}
#line 13925 "pnfha.tab.cpp"
    break;

  case 464: /* load_command: LOAD ARRAY STRINGV OPLSQ OPRSQ  */
#line 9879 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");

			 conprint("APREP TSTRING %s\n", yyvsp[-2].to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("LOADIA TVOID 0V\n");

			 tree.add_node(load_command);
			}
#line 13939 "pnfha.tab.cpp"
    break;

  case 465: /* $@97: %empty  */
#line 9889 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 
			 if (yyvsp[-3].to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)yyvsp[-2].to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			  conprint("FNCSRET TBOOLEAN 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			}
#line 13968 "pnfha.tab.cpp"
    break;

  case 466: /* load_command: LOAD signature2 LTYPE number_expression OPCOLON boolean_expression $@97 nothing  */
#line 9914 "pnfha.ypp"
                        {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 13980 "pnfha.tab.cpp"
    break;

  case 467: /* $@98: %empty  */
#line 9922 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 
			 if (yyvsp[-3].to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)yyvsp[-2].to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TNUMBER %g\n", yyvsp[0].to_number().get());
			  conprint("FNCSRET TNUMBER 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			}
#line 14009 "pnfha.tab.cpp"
    break;

  case 468: /* load_command: LOAD signature2 LTYPE number_expression OPCOLON number_expression $@98 nothing  */
#line 9947 "pnfha.ypp"
                        {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 14021 "pnfha.tab.cpp"
    break;

  case 469: /* $@99: %empty  */
#line 9955 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 
			 if (yyvsp[-3].to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)yyvsp[-2].to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TCHARACTER %c\n", yyvsp[0].to_character().get());
			  conprint("FNCSRET TCHARACTER 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			}
#line 14050 "pnfha.tab.cpp"
    break;

  case 470: /* load_command: LOAD signature2 LTYPE number_expression OPCOLON character_expression $@99 nothing  */
#line 9980 "pnfha.ypp"
                        {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 14062 "pnfha.tab.cpp"
    break;

  case 471: /* $@100: %empty  */
#line 9988 "pnfha.ypp"
                        {
			 ASTNode load_command("load_command");
			 
			 if (yyvsp[-3].to_string().get() == "rvalue")
			 {
			  unsigned long index = funcstk.find(fsaveid.to_string().get(), frets6, fparams6);
			  if (index == -1)
			  {
			   yyerror("Function not found.");
			   exit(-1);
			  }

			  unsigned long rindex = (unsigned long)yyvsp[-2].to_number().get();

			  conprint("FNCLOAD TNUMBER %d\n", index);
			  conprint("RNUM TNUMBER %d\n", rindex);
			  conprint("ALOAD TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			  conprint("FNCSRET TSTRING 0V\n");
			 }
			 else
			  yyerror("Bad LTYPE.");

			 tree.add_node(load_command);
			}
#line 14091 "pnfha.tab.cpp"
    break;

  case 472: /* load_command: LOAD signature2 LTYPE number_expression OPCOLON string_expression $@100 nothing  */
#line 10013 "pnfha.ypp"
                        {
			 for (unsigned long i = frets6.length() - 1; i > 0; --i)
			  frets6.remove();

			 for (unsigned long i = fparams6.length() - 1; i > 0; --i)
			  fparams6.remove();
			}
#line 14103 "pnfha.tab.cpp"
    break;

  case 473: /* load_command: LOAD STRUCT STRINGV  */
#line 10021 "pnfha.ypp"
                        {
			 if (yyvsp[0].to_string().get().getString() == "\"get\"")
			 {
			  conprint("STRUCTGET TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "\"type1\"")
			 {
			  conprint("STRUCTTYPE TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "\"type2\"")
			 {
			  conprint("STRUCTTYPE2 TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "\"name1\"")
			 {
			  conprint("STRUCTNAME2 TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "\"name2\"")
			 {
			  conprint("STRUCTNAME3 TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid load type.");
			}
#line 14132 "pnfha.tab.cpp"
    break;

  case 474: /* load_command: LOAD UNION STRINGV  */
#line 10046 "pnfha.ypp"
                        {
			 if (yyvsp[0].to_string().get().getString() == "\"get\"")
			 {
			  conprint("UNIONGET TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "\"type1\"")
			 {
			  conprint("UNIONTYPE TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "\"type2\"")
			 {
			  conprint("UNIONTYPE2 TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "\"name1\"")
			 {
			  conprint("UNIONNAME2 TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get().getString() == "\"name2\"")
			 {
			  conprint("UNIONNAME3 TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid load type.");
			}
#line 14161 "pnfha.tab.cpp"
    break;

  case 475: /* load_command: USE OTYPE ID  */
#line 10071 "pnfha.ypp"
                        {
			 if (yyvsp[-1].to_string().get().getString() == "tstruct")
			 {
			  conprint("STRUCTUSE TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "tunion")
			 {
			  conprint("UNIONUSE TSTRING \"%s\"\n", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else
			  yyerror((char *)"Invalid object type.");
			}
#line 14178 "pnfha.tab.cpp"
    break;

  case 476: /* load_command: LOAD RTYPE LTYPE TYPE number_expression  */
#line 10084 "pnfha.ypp"
                        {
			 if (yyvsp[-2].to_string().get().getString() == "seg2")
			 {
			  if (yyvsp[-3].to_string().get().getString() == "%accumulator")
			  {
			   switch (yyvsp[-1].getType())
			   {
		 	    case TVOID:
			    {
			     conprint("SEGVLOAD TVOID %g\n", yyvsp[0].to_number().get());
			    }
			    break;

			    case TBOOLEAN:
			    {
			     conprint("SEGVLOAD TBOOLEAN %g\n", yyvsp[0].to_number().get());
			    }
			    break;

			   case TNUMBER:
			    {
			     conprint("SEGVLOAD TNUMBER %g\n", yyvsp[0].to_number().get());
			    }
			    break;

			    case TCHARACTER:
			    {
			     conprint("SEGVLOAD TCHARACTER %g\n", yyvsp[0].to_number().get());
			    }
			    break;

			    case TSTRING:
			    {
			     conprint("SEGVLOAD TSTRING %g\n", yyvsp[0].to_number().get());
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
#line 14230 "pnfha.tab.cpp"
    break;

  case 477: /* goto_command: GOTO GTYPE number_expression  */
#line 10134 "pnfha.ypp"
                        {
			 ASTNode goto_command("goto_command");
			 if (yyvsp[-1].to_string().get().getString() == "normal")
			 {
			  conprint("GOTO TVOID %g\n", yyvsp[0].to_number().get());
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "condition")
			  conprint("CGOTO TVOID %g\n", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get().getString() == "zero")
			  conprint("ZGOTO TVOID %g\n", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get().getString() == "positive")
			  conprint("PGOTO TVOID %g\n", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get().getString() == "negative")
			  conprint("NGOTO TVOID %g\n", yyvsp[0].to_number().get());
			 else
			  yyerror("Invalid goto type.");

			 tree.add_node(goto_command);
			}
#line 14254 "pnfha.tab.cpp"
    break;

  case 478: /* goto_command: GOTO GTYPE ID  */
#line 10154 "pnfha.ypp"
                        {
			 ASTNode goto_command("goto_command");
			 if (yyvsp[-1].to_string().get().getString() == "normal")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == yyvsp[0].to_string().get().getString())
			   {
			    declared = true;
			    conprint("GOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "condition")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == yyvsp[0].to_string().get().getString())
			   {
			    declared = true;
			    conprint("CGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "zero")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == yyvsp[0].to_string().get().getString())
			   {
			    declared = true;
			    conprint("ZGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "positive")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == yyvsp[0].to_string().get().getString())
			   {
			    declared = true;
			    conprint("PGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "negative")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == yyvsp[0].to_string().get().getString())
			   {
			    declared = true;
			    conprint("NGOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid goto type.");

			 tree.add_node(goto_command);
			}
#line 14361 "pnfha.tab.cpp"
    break;

  case 479: /* operator_command: OPPLUS  */
#line 10259 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14371 "pnfha.tab.cpp"
    break;

  case 480: /* operator_command: OPPLUS number_expression  */
#line 10265 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TNUMBER %g\n", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14381 "pnfha.tab.cpp"
    break;

  case 481: /* operator_command: OPPLUS character_expression  */
#line 10271 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TCHARACTER %c\n", yyvsp[0].to_character().get());
			 tree.add_node(operator_command);
			}
#line 14391 "pnfha.tab.cpp"
    break;

  case 482: /* operator_command: OPPLUS string_expression  */
#line 10277 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("ADD TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 tree.add_node(operator_command);
			}
#line 14401 "pnfha.tab.cpp"
    break;

  case 483: /* operator_command: OPMINUS  */
#line 10283 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14411 "pnfha.tab.cpp"
    break;

  case 484: /* operator_command: OPSUB number_expression  */
#line 10289 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("SUB TNUMBER %g\n", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14421 "pnfha.tab.cpp"
    break;

  case 485: /* operator_command: OPTIMES  */
#line 10295 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14431 "pnfha.tab.cpp"
    break;

  case 486: /* operator_command: OPTIMES number_expression  */
#line 10301 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("MUL TNUMBER %g\n", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14441 "pnfha.tab.cpp"
    break;

  case 487: /* operator_command: OPDIV  */
#line 10307 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14451 "pnfha.tab.cpp"
    break;

  case 488: /* operator_command: OPDIV number_expression  */
#line 10313 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("DIV TNUMBER %g\n", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14461 "pnfha.tab.cpp"
    break;

  case 489: /* operator_command: OPMODULUS  */
#line 10319 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14471 "pnfha.tab.cpp"
    break;

  case 490: /* operator_command: OPMODULUS number_expression  */
#line 10325 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("MOD TNUMBER %g\n", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14481 "pnfha.tab.cpp"
    break;

  case 491: /* operator_command: OPPOWER  */
#line 10331 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("POW TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14491 "pnfha.tab.cpp"
    break;

  case 492: /* operator_command: OPPOWER number_expression  */
#line 10337 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("POW TNUMBER %g\n", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14501 "pnfha.tab.cpp"
    break;

  case 493: /* operator_command: OPROOT  */
#line 10343 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14511 "pnfha.tab.cpp"
    break;

  case 494: /* operator_command: OPROOT number_expression  */
#line 10349 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("ROOT TNUMBER %g\n", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14521 "pnfha.tab.cpp"
    break;

  case 495: /* operator_command: OPINC  */
#line 10355 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("INC TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14531 "pnfha.tab.cpp"
    break;

  case 496: /* operator_command: OPDEC  */
#line 10361 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("DEC TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14541 "pnfha.tab.cpp"
    break;

  case 497: /* operator_command: OPAND  */
#line 10367 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("AND TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14551 "pnfha.tab.cpp"
    break;

  case 498: /* operator_command: OPOR  */
#line 10373 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("OR TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14561 "pnfha.tab.cpp"
    break;

  case 499: /* operator_command: OPNOT  */
#line 10379 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("NOT TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14571 "pnfha.tab.cpp"
    break;

  case 500: /* operator_command: OPEQU  */
#line 10385 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14581 "pnfha.tab.cpp"
    break;

  case 501: /* operator_command: OPNEQU  */
#line 10391 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14591 "pnfha.tab.cpp"
    break;

  case 502: /* operator_command: OPLSS  */
#line 10397 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14601 "pnfha.tab.cpp"
    break;

  case 503: /* operator_command: OPGTR  */
#line 10403 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14611 "pnfha.tab.cpp"
    break;

  case 504: /* operator_command: OPLEQU  */
#line 10409 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14621 "pnfha.tab.cpp"
    break;

  case 505: /* operator_command: OPGEQU  */
#line 10415 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14631 "pnfha.tab.cpp"
    break;

  case 506: /* operator_command: OPEQU boolean_expression  */
#line 10421 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");

			 String str = yyvsp[0].to_boolean().get();

			 conprint("EQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			}
#line 14645 "pnfha.tab.cpp"
    break;

  case 507: /* operator_command: OPNEQU boolean_expression  */
#line 10431 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");

			 String str = yyvsp[0].to_boolean().get();

			 conprint("NEQU TBOOLEAN %s", str.getString().c_str());

			 tree.add_node(operator_command);
			}
#line 14659 "pnfha.tab.cpp"
    break;

  case 508: /* operator_command: OPEQU number_expression  */
#line 10441 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TNUMBER %g", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14669 "pnfha.tab.cpp"
    break;

  case 509: /* operator_command: OPNEQU number_expression  */
#line 10447 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TNUMBER %g", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14679 "pnfha.tab.cpp"
    break;

  case 510: /* operator_command: OPLSS number_expression  */
#line 10453 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TNUMBER %g", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14689 "pnfha.tab.cpp"
    break;

  case 511: /* operator_command: OPGTR number_expression  */
#line 10459 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TNUMBER %g", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14699 "pnfha.tab.cpp"
    break;

  case 512: /* operator_command: OPLEQU number_expression  */
#line 10465 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TNUMBER %g", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14709 "pnfha.tab.cpp"
    break;

  case 513: /* operator_command: OPGEQU number_expression  */
#line 10471 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TNUMBER %g", yyvsp[0].to_number().get());
			 tree.add_node(operator_command);
			}
#line 14719 "pnfha.tab.cpp"
    break;

  case 514: /* operator_command: OPEQU character_expression  */
#line 10477 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("EQU TCHARACTER %c", yyvsp[0].to_character().get());
			 tree.add_node(operator_command);
			}
#line 14729 "pnfha.tab.cpp"
    break;

  case 515: /* operator_command: OPNEQU character_expression  */
#line 10483 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("NEQU TCHARACTER %c", yyvsp[0].to_character().get());
			 tree.add_node(operator_command);
			}
#line 14739 "pnfha.tab.cpp"
    break;

  case 516: /* operator_command: OPLSS character_expression  */
#line 10489 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("LSS TCHARACTER %c", yyvsp[0].to_character().get());
			 tree.add_node(operator_command);
			}
#line 14749 "pnfha.tab.cpp"
    break;

  case 517: /* operator_command: OPGTR character_expression  */
#line 10495 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("GTR TCHARACTER %c", yyvsp[0].to_character().get());
			 tree.add_node(operator_command);
			}
#line 14759 "pnfha.tab.cpp"
    break;

  case 518: /* operator_command: OPLEQU character_expression  */
#line 10501 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("LEQU TCHARACTER %c", yyvsp[0].to_character().get());
			 tree.add_node(operator_command);
			}
#line 14769 "pnfha.tab.cpp"
    break;

  case 519: /* operator_command: OPGEQU character_expression  */
#line 10507 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("GEQU TCHARACTER %c", yyvsp[0].to_character().get());
			 tree.add_node(operator_command);
			}
#line 14779 "pnfha.tab.cpp"
    break;

  case 520: /* operator_command: OPAMP  */
#line 10513 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("BTAND TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 14789 "pnfha.tab.cpp"
    break;

  case 521: /* operator_command: OPBTOR  */
#line 10519 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("BTOR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 14799 "pnfha.tab.cpp"
    break;

  case 522: /* operator_command: OPBTXOR  */
#line 10525 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("BTXOR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 14809 "pnfha.tab.cpp"
    break;

  case 523: /* operator_command: OPBTNOT  */
#line 10531 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("BTNOT TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 14819 "pnfha.tab.cpp"
    break;

  case 524: /* operator_command: OPBTSL  */
#line 10537 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("BTSL TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 14829 "pnfha.tab.cpp"
    break;

  case 525: /* operator_command: OPBTSR  */
#line 10543 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("BTSR TVOID 0V");
			 tree.add_node(operator_command);
			}
#line 14839 "pnfha.tab.cpp"
    break;

  case 527: /* operator_command: OPCMP  */
#line 10550 "pnfha.ypp"
                        {
			 conprint("CMP TVOID 0V");
			}
#line 14847 "pnfha.tab.cpp"
    break;

  case 528: /* operator_command: OPSTRTIMES  */
#line 10554 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 conprint("NTIMES TVOID 0V\n");
			 tree.add_node(operator_command);
			}
#line 14857 "pnfha.tab.cpp"
    break;

  case 529: /* operator_command: OPRUN RUNOPOP string_expression  */
#line 10560 "pnfha.ypp"
                        {
			 ASTNode operator_command("operator_command");
			 if (yyvsp[-1].to_string().get().getString() == "run")
			 {
			  conprint("RUN TSTRING %s", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "jrun")
			 {
			  conprint("JRUN TSTRING %s", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "pnfrun")
			 {
			  conprint("PNFRUN TSTRING %s", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else
			  yyerror((char *)"Bad run operator.");
			 tree.add_node(operator_command);
			}
#line 14880 "pnfha.tab.cpp"
    break;

  case 530: /* $@101: %empty  */
#line 10582 "pnfha.ypp"
                        {
			 ASTNode top_commandp1("top_commandp1");

			 intop = true;
			 ++topcounter;

			 conprint("IF TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp1);
			}
#line 14896 "pnfha.tab.cpp"
    break;

  case 531: /* $@102: %empty  */
#line 10593 "pnfha.ypp"
                        {
			 ASTNode top_commandp2("top_commandp2");			 

			 tree.add_node(top_commandp2);
			}
#line 14906 "pnfha.tab.cpp"
    break;

  case 532: /* $@103: %empty  */
#line 10599 "pnfha.ypp"
                        {
			 ASTNode top_commandp3("top_commandp3");

			conprint("IFEND TVOID 0V\n"); 
			conprint("ENDIF TVOID 0V\n");

			 tree.add_node(top_commandp3);
			}
#line 14919 "pnfha.tab.cpp"
    break;

  case 533: /* $@104: %empty  */
#line 10608 "pnfha.ypp"
                        {
			 ASTNode top_commandp4("top_commandp4");

			 conprint("IFELSE TVOID 0V\n");
			 conprint("IFBEGIN TVOID 0V\n");

			 tree.add_node(top_commandp4);
			}
#line 14932 "pnfha.tab.cpp"
    break;

  case 534: /* top_command: stmt OPQUES $@101 $@102 stmt $@103 OPCOLON $@104 stmt  */
#line 10617 "pnfha.ypp"
                        {
			 ASTNode top_commandp5("top_commandp5");

			 conprint("IFEND TVOID 0V\n");
			 conprint("ENDIFELSE TVOID 0V\n");
			 conprint("EIF TVOID 0V\n");

			 tree.add_node(top_commandp5);
			}
#line 14946 "pnfha.tab.cpp"
    break;

  case 535: /* st_command: ST  */
#line 10629 "pnfha.ypp"
                        {
			 ASTNode st_command("st_command");
			 conprint("ST TVOID 0V\n");
			 tree.add_node(st_command);
			}
#line 14956 "pnfha.tab.cpp"
    break;

  case 536: /* stack_command: PUSH  */
#line 10637 "pnfha.ypp"
                        {
			 ASTNode stack_command("stack_command");
			 conprint("PUSH TVOID 0V\n");
			 tree.add_node(stack_command);
			}
#line 14966 "pnfha.tab.cpp"
    break;

  case 537: /* stack_command: POP  */
#line 10643 "pnfha.ypp"
                        {
			 ASTNode stack_command("stack_command");
			 conprint("POP TVOID 0V\n");
			 tree.add_node(stack_command);
			}
#line 14976 "pnfha.tab.cpp"
    break;

  case 538: /* typeof_command: TYPEOF RTYPE  */
#line 10651 "pnfha.ypp"
                        {
			 ASTNode typeof_command("typeof_command");
			 if (yyvsp[0].to_string().get().getString() == "%accumulator")
  			  conprint("TYPEOF TVOID 0V\n");
			 else if (yyvsp[0].to_string().get().getString() == "%calc")
  			  conprint("CTYPEOF TVOID 0V\n");
                         else
			  yyerror("Invalid register type.");
			 tree.add_node(typeof_command);
			}
#line 14991 "pnfha.tab.cpp"
    break;

  case 539: /* rm_command: ATOC  */
#line 10664 "pnfha.ypp"
                        {
			 ASTNode rm_command("rm_command");
			 conprint("ATOC TVOID 0V\n");
			 tree.add_node(rm_command);
			}
#line 15001 "pnfha.tab.cpp"
    break;

  case 540: /* rm_command: ATOSP  */
#line 10670 "pnfha.ypp"
                        {
			 conprint("ATOSP TVOID 0V\n");
			}
#line 15009 "pnfha.tab.cpp"
    break;

  case 541: /* rm_command: SPTOA  */
#line 10674 "pnfha.ypp"
                        {
			 conprint("SPTOA TVOID 0V\n");
			}
#line 15017 "pnfha.tab.cpp"
    break;

  case 542: /* rm_command: SWITCH  */
#line 10678 "pnfha.ypp"
                        {
			 ASTNode rm_command("rm_command");
			 conprint("SWITCH TVOID 0V\n");
			 tree.add_node(rm_command);
			}
#line 15027 "pnfha.tab.cpp"
    break;

  case 543: /* crash_command: CRASH string_expression  */
#line 10686 "pnfha.ypp"
                        {
			 ASTNode crash_command("crash_command");
			 conprint("CRASH TSTRING %s", yyvsp[0].to_string().get().getString().c_str());
			 tree.add_node(crash_command);
			}
#line 15037 "pnfha.tab.cpp"
    break;

  case 544: /* version_command: VERSION VTYPE number_expression  */
#line 10694 "pnfha.ypp"
                        {
			 ASTNode version_command("version_command");

			 if (yyvsp[-1].to_string().get().getString() == "pnf")
  			  conprint("VERSION TVOID %f\n", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get() == "pnfasm")
			  conprint("version TVOID 0V\n");
			 else if (yyvsp[-1].to_string().get().getString() == "normal")
  			  ; // Not used yet. This is the first version.
                         else
			  yyerror("Invalid version type.");

			 tree.add_node(version_command);
			}
#line 15056 "pnfha.tab.cpp"
    break;

  case 545: /* version_command: MODE number_expression  */
#line 10709 "pnfha.ypp"
                        {
			 ASTNode version_command("version_command");

			 conprint("MODE TVOID %f\n", yyvsp[0].to_number().get());


			 tree.add_node(version_command);
			}
#line 15069 "pnfha.tab.cpp"
    break;

  case 546: /* version_command: EXTMODE number_expression  */
#line 10718 "pnfha.ypp"
                        {
			 ASTNode version_command("version_command");

			 conprint("EXTMODE TVOID %f\n", yyvsp[0].to_number().get());

			 tree.add_node(version_command);
			}
#line 15081 "pnfha.tab.cpp"
    break;

  case 547: /* halt_command: HALT  */
#line 10728 "pnfha.ypp"
                        {
			 ASTNode halt_command("halt_command");
			 conprint("HALT TVOID 0V\n");
			 tree.add_node(halt_command);
			}
#line 15091 "pnfha.tab.cpp"
    break;

  case 548: /* modt_command: MODT RTYPE  */
#line 10736 "pnfha.ypp"
                        {
			 ASTNode modt_command("modt_command");

			 if (yyvsp[0].to_string().get().getString() == "%accumulator")
  			  conprint("MODT TVOID 0V\n");
			 else if (yyvsp[0].to_string().get().getString() == "%calc")
  			  conprint("MODCT TVOID 0V\n");
                         else
			  yyerror("Invalid register type.");

			 tree.add_node(modt_command);
			}
#line 15108 "pnfha.tab.cpp"
    break;

  case 549: /* subroutine_command: RETURN  */
#line 10751 "pnfha.ypp"
                        {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("RET TVOID 0V\n");
			 tree.add_node(subroutine_command);
			}
#line 15118 "pnfha.tab.cpp"
    break;

  case 550: /* subroutine_command: GOSUB number_expression  */
#line 10757 "pnfha.ypp"
                        {
 			 ASTNode subroutine_command("subroutine_command");
			 conprint("CALL TVOID %g\n", yyvsp[0].to_number().get());
			 tree.add_node(subroutine_command);
			}
#line 15128 "pnfha.tab.cpp"
    break;

  case 551: /* subroutine_command: GOSUB STYPE ID  */
#line 10763 "pnfha.ypp"
                        {
 			 ASTNode subroutine_command("subroutine_command");

			 if (yyvsp[-1].to_string().get().getString() == "sub")
			 {
 			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == labelTable[i].name().getString())
			   {
			    declared = true;
			    double d = labelTable[i].address();
			    conprint("CALLL TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "heve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::hevents();
			    conprint("HEVENT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "sheve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::shevents();
			    conprint("SHEVENT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "eve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::events();
			    conprint("EVENT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "exe")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::exceptions();
			    conprint("EXCEPTION TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "int")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared = true;
			    double d = CELabel::ints();
			    conprint("INT TVOID %g\n", d);
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(subroutine_command);
			}
#line 15261 "pnfha.tab.cpp"
    break;

  case 552: /* register_command: UNREGISTER STYPE  */
#line 10894 "pnfha.ypp"
                        {
 			 ASTNode register_command("register_command");

			 if (yyvsp[0].to_string().get().getString() == "heve")
			 {
			  conprint("HEREM TVOID 0V\n");
 			  CELabel::dechevents();
			 }
			 else if (yyvsp[0].to_string().get().getString() == "sheve")
			 {
			  conprint("SHEREM TVOID 0V\n");
 			  CELabel::decshevents();
			 }
			 else if (yyvsp[0].to_string().get().getString() == "eve")
			 {
			  conprint("EREM TVOID 0V\n");
 			  CELabel::decevents();
                         }
			 else if (yyvsp[0].to_string().get().getString() == "exe")
			 {
			  conprint("EXREM TVOID 0V\n");
 			  CELabel::decexceptions();
			 }
			 else if (yyvsp[0].to_string().get().getString() == "int")
			 {
			  conprint("IREM TVOID 0V\n");
 			  CELabel::decints();
                         }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			}
#line 15299 "pnfha.tab.cpp"
    break;

  case 553: /* register_command: REGISTER STYPE ID  */
#line 10928 "pnfha.ypp"
                        {
 			 ASTNode register_command("register_command");

			 if (yyvsp[-1].to_string().get().getString() == "heve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "sheve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "eve")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "exe")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "int")
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
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
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }
			 else
			  yyerror("Invalid subroutine type.");

			 tree.add_node(register_command);
			}
#line 15422 "pnfha.tab.cpp"
    break;

  case 554: /* register_command: REREGISTER STYPE ID ID  */
#line 11047 "pnfha.ypp"
                        {
 			 ASTNode register_command("register_command");

			 if (yyvsp[-2].to_string().get().getString() == "heve")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[-1].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = yyvsp[-1].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("HEED TVOID %g\n", d2);
			 }
			 else if (yyvsp[-2].to_string().get().getString() == "sheve")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[-1].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = yyvsp[-1].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("SHEED TVOID %g\n", d2);
			 }
			 else if (yyvsp[-2].to_string().get().getString() == "eve")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[-1].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = yyvsp[-1].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("EED TVOID %g\n", d2);
			 }
			 else if (yyvsp[-2].to_string().get().getString() == "exe")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[-1].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = yyvsp[-1].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  conprint("EVLOAD TVOID %g\n", d1);
			  conprint("EXED TVOID %g\n", d2);
			 }
			 else if (yyvsp[-2].to_string().get().getString() == "int")
			 {
			  bool declared1 = false;
			  bool declared2 = false;
			  double d1;
			  double d2;
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[-1].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared1 = true;
			    d1 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared1)
			  {
			   String str = yyvsp[-1].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }


			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get().getString() == eventLabelTable[i].name().getString())
			   {
			    declared2 = true;
			    d2 = eventLabelTable[i].address();
			   }
			  }

			  if (!declared2)
			  {
			   String str = yyvsp[0].to_string().get();
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
#line 15650 "pnfha.tab.cpp"
    break;

  case 555: /* register_command: REGISTER BLANK STYPE number_expression  */
#line 11271 "pnfha.ypp"
                        {
			 ASTNode register_command("register_command");

			 if (yyvsp[-1].to_string().get() == "heve")
			  conprint("HEADDB TVOID %g\n", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get() == "sheve")
			  conprint("SHEADDB TVOID %g\n", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get() == "eve")
			  conprint("EADDB TVOID %g\n", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get() == "exe")
			  conprint("EXADDB TVOID %g\n", yyvsp[0].to_number().get());
			 else if (yyvsp[-1].to_string().get() == "int")
			  conprint("IADDB TVOID %g\n", yyvsp[0].to_number().get());
			 else
			  yyerror("Invalid STYPE.");

			 tree.add_node(register_command);
			}
#line 15673 "pnfha.tab.cpp"
    break;

  case 556: /* store_command: STORE RTYPE LTYPE number_expression  */
#line 11292 "pnfha.ypp"
                        {
 			 ASTNode store_command("store_command");

			 if (yyvsp[-2].to_string().get().getString() == "%accumulator")
			 {
			  if (yyvsp[-1].to_string().get().getString() == "memory")
			   conprint("STORE TVOID %g", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get().getString() == "variable")
			  {
			   conprint("VSTORE TVOID %g", yyvsp[0].to_number().get());
			  }
			  else if (yyvsp[-1].to_string().get().getString() == "stk")
			   conprint("STORESP TNUMBER %g\n", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get().getString() == "seg1")
			   conprint("SEGSTORE TNUMBER %g\n", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get().getString() == "seg2")
			   conprint("SEGVSTORE TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror("Invalid store type.");
			 }
			 else if (yyvsp[-2].to_string().get().getString() == "%calc")
			 {
			  if (yyvsp[-1].to_string().get().getString() == "memory")
			   conprint("STOREC TVOID %g", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get().getString() == "variable")
			  {
			   conprint("VSTOREC TVOID %g", yyvsp[0].to_number().get());
			  }
			  else
			   yyerror("Invalid store type.");
			 }
			 else
			  yyerror("Invalid register type.");

			 tree.add_node(store_command);
			}
#line 15714 "pnfha.tab.cpp"
    break;

  case 557: /* store_command: STORE LTYPE  */
#line 11329 "pnfha.ypp"
                        {
			 if (yyvsp[0].to_string().get().getString() == "stk")
			 {
			  conprint("STORESTACK TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid store type.");
			}
#line 15727 "pnfha.tab.cpp"
    break;

  case 558: /* store_command: STORE RTYPE LTYPE  */
#line 11338 "pnfha.ypp"
                        {
 			 ASTNode store_command("store_command");

			 if (yyvsp[-1].to_string().get().getString() == "%accumulator")
			 {
			  if (yyvsp[0].to_string().get().getString() == "variable")
			  {
			   conprint("VSTORE TVOID 0V");
			   ++varcount;
			  }
			  else if (yyvsp[0].to_string().get().getString() == "tend")
			   conprint("ESTORE TVOID 0V");
			 else if (yyvsp[0].to_string().get().getString() == "seg2")
			 {
			  conprint("SEGVSTORE TVOID 0V\n");
			 }
			  else
			   yyerror("Invalid store type.");
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "%calc")
			 {
			  if (yyvsp[0].to_string().get().getString() == "variable")
			  {
			   conprint("VSTOREC TVOID 0V");
		 	   ++varcount;
			  }
			  else if (yyvsp[0].to_string().get().getString() == "tend")
			   conprint("ESTOREC TVOID 0V");
			  else
			   yyerror("Invalid store type.");
			 }
			 else
			  yyerror("Invalid register type.");

			 tree.add_node(store_command);
			}
#line 15768 "pnfha.tab.cpp"
    break;

  case 559: /* store_command: STORE STOREA  */
#line 11375 "pnfha.ypp"
                        {
 			 ASTNode store_command("store_command");

			 conprint("STOREA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 15780 "pnfha.tab.cpp"
    break;

  case 560: /* store_command: STORE VTYPE2 STRINGV  */
#line 11383 "pnfha.ypp"
                        {
 			 ASTNode store_command("store_command");

			 if (yyvsp[-1].to_string().get() == "venum")
			 {
			  conprint("EPREP TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			  conprint("STOREE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid VTYPE2.");

			 tree.add_node(store_command);
			}
#line 15798 "pnfha.tab.cpp"
    break;

  case 561: /* store_command: STORE RANGE RTYPE2 STRINGV  */
#line 11397 "pnfha.ypp"
                        {
 			 ASTNode store_command("store_command");

			 if (yyvsp[-1].to_string().get() == "rtype1")
			 {
			  conprint("RSTORE1 TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid Range Type.");

			 tree.add_node(store_command);
			}
#line 15815 "pnfha.tab.cpp"
    break;

  case 562: /* store_command: STORE ARRAY STRINGV OPLSQ number_expression OPRSQ  */
#line 11410 "pnfha.ypp"
                        {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", yyvsp[-3].to_string().get().getString().c_str());
			 conprint("AIPREP TNUMBER %g\n", yyvsp[-1].to_number().get());
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 15829 "pnfha.tab.cpp"
    break;

  case 563: /* store_command: STORE ARRAY STRINGV OPLSQ OPRSQ  */
#line 11420 "pnfha.ypp"
                        {
			 ASTNode store_command("store_command");

			 conprint("APREP TSTRING %s\n", yyvsp[-2].to_string().get().getString().c_str());
			 conprint("AIPREP TVOID 0V\n");
			 conprint("STOREIA TVOID 0V\n");

			 tree.add_node(store_command);
			}
#line 15843 "pnfha.tab.cpp"
    break;

  case 564: /* break_command: BREAK  */
#line 11432 "pnfha.ypp"
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
#line 15865 "pnfha.tab.cpp"
    break;

  case 565: /* break_command: BREAK ID  */
#line 11450 "pnfha.ypp"
                        {
			 ASTNode break_command("break_command");

			 if (inswitch || inloop2)
			 {
			  bool declared = false;
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (labelTable[i].name().getString() == yyvsp[0].to_string().get().getString())
			   {
			    declared = true;
			    conprint("GOTOL TVOID %u\n", labelTable[i].address());
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get();
			   str += " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			 }

  			 tree.add_node(break_command);
			}
#line 15895 "pnfha.tab.cpp"
    break;

  case 566: /* address_command: ADDRESSOF ATYPE ID  */
#line 11478 "pnfha.ypp"
                        {
			 ASTNode address_command("address_command");

			 unsigned long address = 0;
			 bool declared = false;
			 if (yyvsp[-1].to_string().get() == "avariable")
			 {
			  for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			  {
			   if (yyvsp[0].to_string().get() == varTable[scope][i].name())
			   {
			    declared = true;
			    address = varTable[scope][i].address();
			    break;
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get() + " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			  else
			  {
			   if (varTable.length() == 1)
                            --address;

			   conprint("VADD TVOID %u\n", address);
			  }
			 }
			 else if (yyvsp[-1].to_string().get() == "alabel")
			 {
			  for (unsigned long i = 0; i < labelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get() == labelTable[i].name())
			   {
		            declared = true;
			    address = i - 1;
			    break;
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get() + " was not declared.";
			   yyerror(str.getString().c_str());
			  }
			  conprint("LADD TVOID %u\n", address);
			 }
			 else if (yyvsp[-1].to_string().get() == "aevent")
			 {
			  for (unsigned long i = 0; i < eventLabelTable.length(); ++i)
			  {
			   if (yyvsp[0].to_string().get() == eventLabelTable[i].name())
			   {
		            declared = true;
			    address = i - 1;
			    break;
			   }
			  }

			  if (!declared)
			  {
			   String str = yyvsp[0].to_string().get() + " was not declared.";
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
#line 15975 "pnfha.tab.cpp"
    break;

  case 567: /* add2v_command: ADD2V  */
#line 11556 "pnfha.ypp"
                        {
			 ASTNode add2v_command("add2v_command");

			 conprint("ADD2V TVOID 0V\n");

		         tree.add_node(add2v_command);
			}
#line 15987 "pnfha.tab.cpp"
    break;

  case 568: /* continue_command: CONTINUE  */
#line 11566 "pnfha.ypp"
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
#line 16008 "pnfha.tab.cpp"
    break;

  case 569: /* check_command: CHECK CTYPE TYPE number_expression  */
#line 11585 "pnfha.ypp"
                        {
			 ASTNode check_command("check_command");

			 if (yyvsp[-2].to_string().get() == "current_ver")
			 {
			  if (yyvsp[-1].to_string().get() == "void")
			   conprint("VCHECK TVOID %g\n", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get() == "number")
			   conprint("VCHECK TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "ver")
			 {
			  if (yyvsp[-1].to_string().get() == "void")
			   conprint("VSUPP TVOID %g\n", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get() == "number")
			   conprint("VSUPP TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "current_vmode")
			 {
			  if (yyvsp[-1].to_string().get() == "void")
			   conprint("MCHECK TVOID %g\n", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get() == "number")
			   conprint("MCHECK TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "vmode")
			 {
			  if (yyvsp[-1].to_string().get() == "void")
			   conprint("MSUPP TVOID %g\n", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get() == "number")
			   conprint("MSUPP TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "current_extvmode")
			 {
			  if (yyvsp[-1].to_string().get() == "void")
			   conprint("MEXTCHECK TVOID %g\n", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get() == "number")
			   conprint("MEXTCHECK TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "extvmode")
			 {
			  if (yyvsp[-1].to_string().get() == "void")
			   conprint("MEXTSUPP TVOID %g\n", yyvsp[0].to_number().get());
			  else if (yyvsp[-1].to_string().get() == "number")
			   conprint("MEXTSUPP TNUMBER %g\n", yyvsp[0].to_number().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 16075 "pnfha.tab.cpp"
    break;

  case 570: /* check_command: CHECK CTYPE TYPE boolean_expression  */
#line 11648 "pnfha.ypp"
                        {
			 ASTNode check_command("check_command");

			 if (yyvsp[-2].to_string().get() == "current_ver")
			 {
			  if (yyvsp[-1].to_string().get() == "boolean")
			   conprint("VCHECK TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if (yyvsp[-2].to_string().get() == "ver")
			 {
			  if (yyvsp[-1].to_string().get() == "boolean")
			   conprint("VSUPP TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "current_vmode")
			 {
			  if (yyvsp[-1].to_string().get() == "boolean")
			   conprint("MCHECK TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if (yyvsp[-2].to_string().get() == "vmode")
			 {
			  if (yyvsp[-1].to_string().get() == "boolean")
			   conprint("MSUPP TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "current_extvmode")
			 {
			  if (yyvsp[-1].to_string().get() == "boolean")
			   conprint("MEXTCHECK TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if (yyvsp[-2].to_string().get() == "extvmode")
			 {
			  if (yyvsp[-1].to_string().get() == "boolean")
			   conprint("MEXTSUPP TBOOLEAN %s\n", yyvsp[0].to_boolean().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 16130 "pnfha.tab.cpp"
    break;

  case 571: /* check_command: CHECK CTYPE TYPE character_expression  */
#line 11699 "pnfha.ypp"
                        {
			 ASTNode check_command("check_command");

			 if (yyvsp[-2].to_string().get() == "current_ver")
			 {
			  if (yyvsp[-1].to_string().get() == "character")
			   conprint("VCHECK TCHARACTER %c\n", yyvsp[0].to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if (yyvsp[-2].to_string().get() == "ver")
			 {
			  if (yyvsp[-1].to_string().get() == "character")
			   conprint("VSUPP TCHARACTER %c\n", yyvsp[0].to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "current_vmode")
			 {
			  if (yyvsp[-1].to_string().get() == "character")
			   conprint("MCHECK TCHARACTER %c\n", yyvsp[0].to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if (yyvsp[-2].to_string().get() == "vmode")
			 {
			  if (yyvsp[-1].to_string().get() == "character")
			   conprint("MSUPP TCHARACTER %c\n", yyvsp[0].to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "current_extvmode")
			 {
			  if (yyvsp[-1].to_string().get() == "character")
			   conprint("MEXTCHECK TCHARACTER %c\n", yyvsp[0].to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 if (yyvsp[-2].to_string().get() == "extvmode")
			 {
			  if (yyvsp[-1].to_string().get() == "character")
			   conprint("MEXTSUPP TCHARACTER %c\n", yyvsp[0].to_character().get());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 16185 "pnfha.tab.cpp"
    break;

  case 572: /* check_command: CHECK CTYPE TYPE string_expression  */
#line 11750 "pnfha.ypp"
                        {
			 ASTNode check_command("check_command");

			 if (yyvsp[-2].to_string().get() == "current_ver")
			 {
			  if (yyvsp[-1].to_string().get() == "string")
			   conprint("VCHECK TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if (yyvsp[-2].to_string().get() == "ver")
			 {
			  if (yyvsp[-1].to_string().get() == "string")
			   conprint("VSUPP TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "current_vmode")
			 {
			  if (yyvsp[-1].to_string().get() == "string")
			   conprint("MCHECK TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if (yyvsp[-2].to_string().get() == "vmode")
			 {
			  if (yyvsp[-1].to_string().get() == "string")
			   conprint("MSUPP TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else if (yyvsp[-2].to_string().get() == "current_extvmode")
			 {
			  if (yyvsp[-1].to_string().get() == "string")
			   conprint("MEXTCHECK TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 if (yyvsp[-2].to_string().get() == "extvmode")
			 {
			  if (yyvsp[-1].to_string().get() == "string")
			   conprint("MEXTSUPP TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			  else
			   yyerror("Invalid type.");
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 16240 "pnfha.tab.cpp"
    break;

  case 573: /* check_command: CHECK CTYPE number_expression  */
#line 11801 "pnfha.ypp"
                        {
			 ASTNode check_command("check_command");

			 if (yyvsp[-1].to_string().get() == "instruction")
			 {
   		          conprint("ISUPP TNUMBER %g\n", yyvsp[0].to_number().get());
			 }
			 if (yyvsp[-1].to_string().get() == "type")
			 {
			  conprint("TSUPP TNUMBER %g\n", yyvsp[0].to_number().get());
			 }
			 else
			  yyerror("Invalid check type.");

		         tree.add_node(check_command);
			}
#line 16261 "pnfha.tab.cpp"
    break;

  case 574: /* comment_command: HCMNT CMTYPE string_expression  */
#line 11820 "pnfha.ypp"
                        {
			 ASTNode comment_command("comment_command");

			 if (yyvsp[-1].to_string().get() == "l2")
			 {
			  String str = strip_quotes(yyvsp[0].to_string().get());
			  conprint(";\\ %s\n", str.getString().c_str());
			 }
			 else if (yyvsp[-1].to_string().get() == "l1")
			 {
			  conprint("COMMENT TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else
			 {
			  yyerror("Invalid comment type.");
                         }

		         tree.add_node(comment_command);
			}
#line 16285 "pnfha.tab.cpp"
    break;

  case 575: /* file_command: FMODE BFMODEC FMODEC  */
#line 11842 "pnfha.ypp"
                        {
			 ASTNode file_command("file_command");

			 if (yyvsp[-1].to_string().get() == "input")
			 {
			  if (yyvsp[0].to_string().get() == "in")
			   conprint("FIMODE TSTRING \"in\"\n");
			  else if (yyvsp[0].to_string().get() == "binary")
			   conprint("FIMODE TSTRING \"binary\"\n");
			  else
			   yyerror("Invalid file mode command.");
			 }
			 else if (yyvsp[-1].to_string().get() == "output")
			 {
			  if (yyvsp[0].to_string().get() == "out")
			   conprint("FOMODE TSTRING \"out\"\n");
			  else if (yyvsp[0].to_string().get() == "binary")
			   conprint("FOMODE TSTRING \"binary\"\n");
			  else if (yyvsp[0].to_string().get() == "ate")
			   conprint("FOMODE TSTRING \"ate\"\n");
			  else if (yyvsp[0].to_string().get() == "app")
			   conprint("FOMODE TSTRING \"app\"\n");
			  else if (yyvsp[0].to_string().get() == "trunc")
			   conprint("FOMODE TSTRING \"trunc\"\n");
			  else
			   yyerror("Invalid file mode command.");
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			}
#line 16322 "pnfha.tab.cpp"
    break;

  case 576: /* file_command: FOPEN BFMODEC string_expression  */
#line 11875 "pnfha.ypp"
                        {
			 ASTNode file_command("file_command");

			 if (yyvsp[-1].to_string().get() == "input")
			 {
			  conprint("FIOPEN TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else if (yyvsp[-1].to_string().get() == "output")
			 {
  			  conprint("FOOPEN TSTRING %s\n", yyvsp[0].to_string().get().getString().c_str());
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			}
#line 16343 "pnfha.tab.cpp"
    break;

  case 577: /* file_command: FCLOSE BFMODEC  */
#line 11892 "pnfha.ypp"
                        {
			 ASTNode file_command("file_command");

			 if (yyvsp[0].to_string().get() == "input")
			 {
			  conprint("FICLOSE TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get() == "output")
			 {
  			  conprint("FOCLOSE TVOID 0V\n");
			 }
			 else
			  yyerror("Invalid basic file mode command.");

			 tree.add_node(file_command);
			}
#line 16364 "pnfha.tab.cpp"
    break;

  case 578: /* file_command: FEOF  */
#line 11909 "pnfha.ypp"
                        {
			 ASTNode file_command("file_command");

			 conprint("FIEOF TVOID 0V\n");

			 tree.add_node(file_command);
			}
#line 16376 "pnfha.tab.cpp"
    break;

  case 579: /* meml_command: MEML  */
#line 11919 "pnfha.ypp"
                        {
			 ASTNode meml_command("meml_command");

			 conprint("MEML TVOID 0V\n");

			 tree.add_node(meml_command);
			}
#line 16388 "pnfha.tab.cpp"
    break;

  case 580: /* pnfasm_command: PNFASM STRINGV STRINGV STRINGV  */
#line 11929 "pnfha.ypp"
                        {
			 ASTNode pnfasm_command("pnfasm_command");

			 conprint("pnf %s %s %s\n", strip_quotes(yyvsp[-2].to_string().get()).getString().c_str(), 
						 strip_quotes(yyvsp[-1].to_string().get()).getString().c_str(), strip_quotes(yyvsp[0].to_string().get()).getString().c_str());

			 tree.add_node(pnfasm_command);
			}
#line 16401 "pnfha.tab.cpp"
    break;

  case 581: /* array_length_command: ARRAY STRINGV OPDOT LENGTH  */
#line 11940 "pnfha.ypp"
                        {
			 ASTNode array_length_command("array_length_command");
			
			 conprint("APREP TSTRING %s\n", yyvsp[-2].to_string().get().getString().c_str());
			 conprint("ALENGTH TVOID 0V\n");

			 tree.add_node(array_length_command);
			}
#line 16414 "pnfha.tab.cpp"
    break;

  case 582: /* dup_command: DUP RTYPE  */
#line 11950 "pnfha.ypp"
                        {
			 ASTNode dup_command("dup_command");

			 if (yyvsp[0].to_string().get() == "%accumulator")
			 {
			  conprint("DUP TVOID 0V\n");
			 }
			 else if (yyvsp[0].to_string().get() == "%calc")
			 {
			  conprint("CDUP TVOID 0V\n");
			 }
			 else
			  yyerror((char *)"Invalid register.");

			 tree.add_node(dup_command);
			}
#line 16435 "pnfha.tab.cpp"
    break;

  case 583: /* fret_command: FRET  */
#line 11969 "pnfha.ypp"
                        {
			 conprint("FRET TVOID 0V\n");
			}
#line 16443 "pnfha.tab.cpp"
    break;

  case 586: /* $@105: %empty  */
#line 11979 "pnfha.ypp"
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
			  if (funcps[index][i].name() == yyvsp[-1].to_string().get())
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
			
			 String str = yyvsp[0].to_string().get();
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
#line 16491 "pnfha.tab.cpp"
    break;

  case 587: /* psig: signature ID TYPE $@105 nothing  */
#line 12023 "pnfha.ypp"
                        {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			}
#line 16503 "pnfha.tab.cpp"
    break;

  case 588: /* $@106: %empty  */
#line 12033 "pnfha.ypp"
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
			  if (funcps[index][i].name() == yyvsp[-2].to_string().get())
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

			 String type = yyvsp[0].to_string().get();
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
#line 16554 "pnfha.tab.cpp"
    break;

  case 589: /* psig2: signature ID TYPE TYPE $@106 nothing  */
#line 12080 "pnfha.ypp"
                        {
			 for (unsigned long i = frets5.length() - 1; i > 0; --i)
			  frets5.remove();

			 for (unsigned long i = fparams5.length() - 1; i > 0; --i)
			  fparams5.remove();
			}
#line 16566 "pnfha.tab.cpp"
    break;

  case 590: /* signature: FPARAMETER LEFTP vars5 RIGHTP ID LEFTP parameter_declaration5 RIGHTP  */
#line 12090 "pnfha.ypp"
                        {
			 yyval = yyvsp[-3];
			}
#line 16574 "pnfha.tab.cpp"
    break;

  case 591: /* signature2: FUNCTION LEFTP vars6 RIGHTP ID LEFTP parameter_declaration6 RIGHTP  */
#line 12096 "pnfha.ypp"
                        {
			 yyval = yyvsp[-3];
			}
#line 16582 "pnfha.tab.cpp"
    break;

  case 592: /* struct_command: LEFTP STRUCT RIGHTP  */
#line 12102 "pnfha.ypp"
                        {
			 conprint("STRUCTUSING TVOID 0V\n");
			}
#line 16590 "pnfha.tab.cpp"
    break;

  case 593: /* struct_command: LEFTB STRUCT RIGHTB  */
#line 12106 "pnfha.ypp"
                        {
			 conprint("STRUCTUSINGNAME TVOID 0V\n");
			}
#line 16598 "pnfha.tab.cpp"
    break;

  case 594: /* union_command: LEFTP UNION RIGHTP  */
#line 12112 "pnfha.ypp"
                        {
			 conprint("UNIONUSING TVOID 0V\n");
			}
#line 16606 "pnfha.tab.cpp"
    break;

  case 595: /* union_command: LEFTB UNION RIGHTB  */
#line 12116 "pnfha.ypp"
                        {
			 conprint("UNIONUSINGNAME TVOID 0V\n");
			}
#line 16614 "pnfha.tab.cpp"
    break;

  case 596: /* copy_command: COPY  */
#line 12122 "pnfha.ypp"
                        {
			 conprint("CPY TVOID 0V\n");
			}
#line 16622 "pnfha.tab.cpp"
    break;

  case 597: /* segment_command: SEGMENT OPPLUS  */
#line 12128 "pnfha.ypp"
                        {
			 conprint("ADDSEG TVOID 0V\n");
			}
#line 16630 "pnfha.tab.cpp"
    break;

  case 598: /* segment_command: SEGMENT OPMINUS  */
#line 12132 "pnfha.ypp"
                        {
			 conprint("REMSEG TVOID 0V\n");
			}
#line 16638 "pnfha.tab.cpp"
    break;

  case 599: /* segment_command: SEGMENT CETYPE number_expression  */
#line 12136 "pnfha.ypp"
                        {
			 if (yyvsp[-1].to_string().get().getString() == "collapse")
			 {
			  conprint("COLLSEG TNUMBER %g\n", yyvsp[0].to_number().get());
			 }
			 else if (yyvsp[-1].to_string().get().getString() == "expand")
			 {
			  conprint("EXPSEG TNUMBER %g\n", yyvsp[0].to_number().get());
			 }
			 else
			  yyerror((char *)"Invalid CETYPE.");
			}
#line 16655 "pnfha.tab.cpp"
    break;

  case 600: /* segment_command: SEGMENT COPY  */
#line 12149 "pnfha.ypp"
                        {
			 conprint("CPYSEG TVOID 0V\n");
			}
#line 16663 "pnfha.tab.cpp"
    break;

  case 601: /* segment_command: SEGMENT PUSH  */
#line 12153 "pnfha.ypp"
                        {
			 conprint("PUSHSEG TVOID 0V\n");
			}
#line 16671 "pnfha.tab.cpp"
    break;

  case 602: /* segment_command: SEGMENT POP  */
#line 12157 "pnfha.ypp"
                        {
			 conprint("POPSEG TVOID 0V\n");
			}
#line 16679 "pnfha.tab.cpp"
    break;

  case 603: /* segment_command: SEGMENT TOP  */
#line 12161 "pnfha.ypp"
                        {
			 conprint("TOPSEG TVOID 0V\n");
			}
#line 16687 "pnfha.tab.cpp"
    break;

  case 604: /* pp_directive: PBIN  */
#line 12167 "pnfha.ypp"
                        {
			 ASTNode pp_directive("pp_directive");
			 conprint("#BIN#\n");
			 tree.add_node(pp_directive);
			}
#line 16697 "pnfha.tab.cpp"
    break;

  case 605: /* pp_directive: PPBIN  */
#line 12173 "pnfha.ypp"
                        {
			 ASTNode pp_directive("pp_directive");
			 conprint("#PBIN#\n");
			 tree.add_node(pp_directive);
			}
#line 16707 "pnfha.tab.cpp"
    break;

  case 606: /* pp_directive: PLIB  */
#line 12179 "pnfha.ypp"
                        {
			 ASTNode pp_directive("pp_directive");
			 conprint("#LIB#\n");
			 tree.add_node(pp_directive);
			}
#line 16717 "pnfha.tab.cpp"
    break;

  case 607: /* pp_statement: PINCLUDE STRINGV  */
#line 12187 "pnfha.ypp"
                        { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include %s", yyvsp[0].to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 16727 "pnfha.tab.cpp"
    break;

  case 608: /* pp_statement: PINCLUDE "<" STRINGV ">"  */
#line 12193 "pnfha.ypp"
                        { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#include <%s>", yyvsp[-2].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16737 "pnfha.tab.cpp"
    break;

  case 609: /* pp_statement: PIMPORT STRINGV  */
#line 12199 "pnfha.ypp"
                        { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import %s\n", yyvsp[0].to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 16747 "pnfha.tab.cpp"
    break;

  case 610: /* pp_statement: PIMPORT "<" STRINGV ">"  */
#line 12205 "pnfha.ypp"
                        { 
			 ASTNode pp_statement("pp_statement");
			 conprint("#import <%s>\n", yyvsp[-2].to_string().get().getString().c_str());
			 tree.add_node(pp_statement);
			}
#line 16757 "pnfha.tab.cpp"
    break;

  case 611: /* pp_statement: PDEFINE STRINGV STRINGV  */
#line 12211 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("#define %s %s\n", yyvsp[-1].to_string().get().getString().c_str(), 
						    yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16768 "pnfha.tab.cpp"
    break;

  case 612: /* pp_statement: PMACRO STRINGV  */
#line 12218 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("#macro %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16778 "pnfha.tab.cpp"
    break;

  case 613: /* pp_statement: PENDM  */
#line 12224 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endm\n");
			 tree.add_node(pp_statement);
		 	}
#line 16788 "pnfha.tab.cpp"
    break;

  case 614: /* pp_statement: PUNDEF STRINGV  */
#line 12230 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("#undef %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16798 "pnfha.tab.cpp"
    break;

  case 615: /* pp_statement: PIFDEF STRINGV  */
#line 12236 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("#ifdef %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16808 "pnfha.tab.cpp"
    break;

  case 616: /* pp_statement: PIFNDEF STRINGV  */
#line 12242 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("#infdef %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16818 "pnfha.tab.cpp"
    break;

  case 617: /* pp_statement: PELSE  */
#line 12248 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("#else\n"); 
			 tree.add_node(pp_statement);
			}
#line 16828 "pnfha.tab.cpp"
    break;

  case 618: /* pp_statement: PENDIF  */
#line 12254 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("#endif\n"); 
			 tree.add_node(pp_statement);
			}
#line 16838 "pnfha.tab.cpp"
    break;

  case 619: /* pp_statement: PPDATE  */
#line 12260 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("_DATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16848 "pnfha.tab.cpp"
    break;

  case 620: /* pp_statement: PPTIME  */
#line 12266 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("_TIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16858 "pnfha.tab.cpp"
    break;

  case 621: /* pp_statement: PPLINE  */
#line 12272 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("_LINE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16868 "pnfha.tab.cpp"
    break;

  case 622: /* pp_statement: PPFILE  */
#line 12278 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("_FILE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16878 "pnfha.tab.cpp"
    break;

  case 623: /* pp_statement: PPCDATE  */
#line 12284 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CDATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16888 "pnfha.tab.cpp"
    break;

  case 624: /* pp_statement: PPCTIME  */
#line 12290 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("_CTIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 16898 "pnfha.tab.cpp"
    break;

  case 625: /* pp_statement: PPINCLUDE STRINGV  */
#line 12296 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
		 	 conprint("%%include %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16908 "pnfha.tab.cpp"
    break;

  case 626: /* pp_statement: PPINCLUDE "<" STRINGV ">"  */
#line 12302 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%include <%s>\n", yyvsp[-2].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16918 "pnfha.tab.cpp"
    break;

  case 627: /* pp_statement: PPIMPORT STRINGV  */
#line 12308 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16928 "pnfha.tab.cpp"
    break;

  case 628: /* pp_statement: PPIMPORT "<" STRINGV ">"  */
#line 12314 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%import <%s>\n", yyvsp[-2].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16938 "pnfha.tab.cpp"
    break;

  case 629: /* pp_statement: PPDEFINE STRINGV STRINGV  */
#line 12320 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%define %s %s\n", yyvsp[-1].to_string().get().getString().c_str(), 
						     yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16949 "pnfha.tab.cpp"
    break;

  case 630: /* pp_statement: PPMACRO STRINGV  */
#line 12327 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%macro %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16959 "pnfha.tab.cpp"
    break;

  case 631: /* pp_statement: PPENDM  */
#line 12333 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endm\n"); 
			 tree.add_node(pp_statement);
			}
#line 16969 "pnfha.tab.cpp"
    break;

  case 632: /* pp_statement: PPUNDEF STRINGV  */
#line 12339 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%undef %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16979 "pnfha.tab.cpp"
    break;

  case 633: /* pp_statement: PPIFDEF STRINGV  */
#line 12345 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%ifdef %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16989 "pnfha.tab.cpp"
    break;

  case 634: /* pp_statement: PPIFNDEF STRINGV  */
#line 12351 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%infdef %s\n", yyvsp[0].to_string().get().getString().c_str()); 
			 tree.add_node(pp_statement);
			}
#line 16999 "pnfha.tab.cpp"
    break;

  case 635: /* pp_statement: PPELSE  */
#line 12357 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%else\n"); 
			 tree.add_node(pp_statement);
			}
#line 17009 "pnfha.tab.cpp"
    break;

  case 636: /* pp_statement: PPENDIF  */
#line 12363 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%endif\n"); 
			 tree.add_node(pp_statement);
			}
#line 17019 "pnfha.tab.cpp"
    break;

  case 637: /* pp_statement: PPPDATE  */
#line 12369 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_DATE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 17029 "pnfha.tab.cpp"
    break;

  case 638: /* pp_statement: PPPTIME  */
#line 12375 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_TIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 17039 "pnfha.tab.cpp"
    break;

  case 639: /* pp_statement: PPPLINE  */
#line 12381 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_LINE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 17049 "pnfha.tab.cpp"
    break;

  case 640: /* pp_statement: PPPFILE  */
#line 12387 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_FILE()\n"); 
			 tree.add_node(pp_statement);
			}
#line 17059 "pnfha.tab.cpp"
    break;

  case 641: /* pp_statement: PPPCDATE  */
#line 12393 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CDATE()\n");
			 tree.add_node(pp_statement);
			}
#line 17069 "pnfha.tab.cpp"
    break;

  case 642: /* pp_statement: PPPCTIME  */
#line 12399 "pnfha.ypp"
                        {
			 ASTNode pp_statement("pp_statement");
			 conprint("%%_CTIME()\n"); 
			 tree.add_node(pp_statement);
			}
#line 17079 "pnfha.tab.cpp"
    break;


#line 17083 "pnfha.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 12405 "pnfha.ypp"

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
