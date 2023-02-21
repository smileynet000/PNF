
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
#line 1 "pnfhra.ypp"

/* Prologue */
/*
Copyright (C) 2019 Dennis Earl Smiley

This file is part of pnfhra.

    pnfhra is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    pnfhra is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with pnfhra.  If not, see <https://www.gnu.org/licenses/>. 
*/
/*
CHANGELOG
=========

5/3/19 Origional a-a-a - 1. The first version.
			 2. Added structs.
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

class Param
{
 protected:
  String itsname;
  PNF_Variable itsparam;


 public:
  Param(int i = 0);

  String name();
  void name(String n);

  PNF_Variable param();
  void param(PNF_Variable v);
};

Param::Param(int i)
{
 itsname = "";
 PNF_Void v;
 itsparam.put(v);
}

String Param::name()
{
 return itsname;
}

void Param::name(String n)
{
 itsname = n;
}

PNF_Variable Param::param()
{
 return itsparam;
}

void Param::param(PNF_Variable v)
{
 itsparam = v;
}

class Function
{
 protected:
  PNF_Variable itsret;
  String itsname;
  Array<Param> itsparam;

 public:
  Function();
  Function(int i);

  Function(const Function & f);


  ~Function();


 PNF_Variable ret();
 String name();
 Array<Param> params();
 PNF_Variable param(unsigned long i);
 String pname(unsigned long i);

 void ret(PNF_Variable r);
 void name(String n);
 void params(Array<Param> p);
 void param(unsigned long i, PNF_Variable v);
 void pname(unsigned long i, String n);
};

Function::Function()
{
 PNF_Void v;
 PNF_Variable v2(v);
 itsret = v2;

 itsname = "";
}

Function::Function(int i)
{
 Function();
}

Function::Function(const Function & f)
{
 itsret = f.itsret;
 itsname = f.itsname;
 itsparam = f.itsparam;
}

Function::~Function()
{

}

PNF_Variable Function::ret()
{
 return itsret;
}

String Function::name()
{
 return itsname;
}

Array<Param> Function::params()
{
 return itsparam;
}

PNF_Variable Function::param(unsigned long i)
{
 return itsparam[i].param();
}

String Function::pname(unsigned long i)
{
 return itsparam[i].name();
}

void Function::ret(PNF_Variable r)
{
 itsret = r;
}

void Function::name(String n)
{
 itsname = n;
}

void Function::params(Array<Param> p)
{
 itsparam = p;
}

void Function::param(unsigned long i, PNF_Variable v)
{
 itsparam[i].param(v);
}

void Function::pname(unsigned long i, String n)
{
 itsparam[i].name(n);
}

class Function_Stack
{
 protected:
  Array<Function> itsstk;

 
 public:
  Function_Stack(int i = 0);

  Array<Function> get();
  
  void set(Array<Function> f);

  void add_function(Function f);
  Function get_function(unsigned long i);
  Function get_function(String n, bool & f);
  void mod_function(unsigned long i, Function f);

 unsigned long find_duplicate(Function f, bool & b);
};

Function_Stack::Function_Stack(int i)
{

}

Array<Function> Function_Stack::get()
{
 return itsstk;
}
  
void Function_Stack::set(Array<Function> f)
{
 itsstk = f;
}

void Function_Stack::add_function(Function f)
{
 bool b = false;
 unsigned long index = find_duplicate(f, b);
 if (!b)
 {
  if (itsstk.length() != 1)
   itsstk.insert();

  itsstk[itsstk.length() - 1] = f;
 }
}

Function Function_Stack::get_function(unsigned long i)
{
 return itsstk[i];
}

Function Function_Stack::get_function(String n, bool & f)
{
 Function itsnull;
 bool found = false;
 unsigned long i;
 for (i = 0; i < itsstk.length(); ++i)
 {
  String name = itsstk[i].name();
  if (name == n)
  {
   found = true;
   break;
  }
 }

 if (found == false)
 {
  f = false;
  return itsnull;
 }
 else
 {
  f = true;
  return itsstk[i];
 }
}

void Function_Stack::mod_function(unsigned long i, Function f)
{
 itsstk[i] = f;
}

unsigned long Function_Stack::find_duplicate(Function f, bool & b)
{
 unsigned long ret;
 b = false;
 unsigned long i;
 for (i = 0; i < itsstk.length(); ++i)
 {
  if (itsstk[i].name() == f.name())
  {
   b = false;
   if (itsstk[i].ret().getm() == f.ret().getm())
   {
    for (unsigned j = 0; j < itsstk[i].params().length(); ++j)
    {
     if (itsstk[i].param(j).getm() != f.param(j).getm())
      b = true;
    }
   }
  }
 }

 ret = i;
 return ret;
}

class Struct
{
 protected:
  String itsname;
  Array<Var> itsvars;

 public:
  Struct(int i = 0);

  String name();
  void name(String n);

  Array<Var> vars();
  
  Var var(unsigned long i);
  void var(unsigned long i, Var v);

  unsigned long vnumber();
};

Struct::Struct(int i)
{

}

String Struct::name()
{
 return itsname;
}

void Struct::name(String n)
{
 itsname = n;
}

Array<Var> Struct::vars()
{
 return itsvars;
}
  
Var Struct::var(unsigned long i)
{
if (i >= itsvars.length())
 {
  for (unsigned long j = i; j >= itsvars.length(); --j)
   itsvars.insert();
 }
 return itsvars[i];
}

void Struct::var(unsigned long i, Var v)
{
 if (i >= itsvars.length())
 {
  for (unsigned long j = i; j >= itsvars.length(); --j)
   itsvars.insert();
 }
 itsvars[i] = v;
}

unsigned long Struct::vnumber()
{
 return itsvars.length();
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

Array<String> out;
char outbuffer[256];
unsigned long outcount;

Function_Stack funcs;
unsigned long paramcount;
unsigned long paramcount2;
Function * current_func;
unsigned long current_param = 0;

Array<Struct> structs;
unsigned long struct_counter = 0;
unsigned long svarcounter = 0;


ASTTree tree;


/* Line 189 of yacc.c  */
#line 1048 "pnfhra.tab.cpp"

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
     STRUCT = 388,
     STRUCTD = 389,
     PBIN = 390,
     PPBIN = 391,
     PLIB = 392,
     PINCLUDE = 393,
     PIMPORT = 394,
     PDEFINE = 395,
     PMACRO = 396,
     PENDM = 397,
     PUNDEF = 398,
     PIFDEF = 399,
     PIFNDEF = 400,
     PELSE = 401,
     PENDIF = 402,
     PPDATE = 403,
     PPTIME = 404,
     PPLINE = 405,
     PPFILE = 406,
     PPCDATE = 407,
     PPCTIME = 408,
     PPINCLUDE = 409,
     PPIMPORT = 410,
     PPDEFINE = 411,
     PPMACRO = 412,
     PPENDM = 413,
     PPUNDEF = 414,
     PPIFDEF = 415,
     PPIFNDEF = 416,
     PPELSE = 417,
     PPENDIF = 418,
     PPPDATE = 419,
     PPPTIME = 420,
     PPPLINE = 421,
     PPPFILE = 422,
     PPPCDATE = 423,
     PPPCTIME = 424
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
#line 1259 "pnfhra.tab.cpp"

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
#define YYLAST   1706

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  174
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  152
/* YYNRULES -- Number of rules.  */
#define YYNRULES  493
/* YYNRULES -- Number of states.  */
#define YYNSTATES  850

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   428

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
     165,   166,   167,   168,   169,   170,   171,   172,   173
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    13,    15,    16,
      19,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    44,    47,    50,    53,    57,    61,    63,    65,    67,
      68,    69,    70,    71,    72,    73,    89,    90,    91,    96,
      98,    99,   100,   101,   102,   115,   116,   117,   118,   119,
     131,   132,   135,   138,   139,   145,   146,   147,   152,   153,
     156,   159,   160,   161,   168,   169,   172,   174,   176,   178,
     179,   182,   183,   184,   185,   194,   195,   196,   197,   198,
     199,   211,   212,   213,   214,   215,   216,   217,   233,   234,
     235,   236,   237,   238,   239,   256,   257,   261,   262,   267,
     269,   272,   274,   276,   278,   280,   282,   284,   286,   288,
     290,   292,   296,   298,   301,   305,   309,   313,   315,   319,
     323,   327,   331,   335,   338,   342,   346,   349,   352,   355,
     358,   362,   366,   370,   373,   377,   381,   385,   387,   391,
     395,   399,   403,   407,   411,   415,   418,   421,   424,   427,
     431,   433,   437,   440,   444,   446,   449,   452,   456,   460,
     464,   468,   472,   476,   480,   483,   487,   491,   494,   497,
     500,   503,   507,   511,   515,   519,   523,   527,   531,   535,
     539,   543,   547,   551,   555,   559,   563,   567,   571,   575,
     579,   583,   587,   591,   595,   599,   603,   607,   611,   615,
     619,   623,   627,   631,   635,   639,   643,   647,   651,   655,
     659,   663,   667,   671,   675,   679,   683,   687,   691,   695,
     699,   703,   707,   711,   715,   719,   723,   727,   730,   734,
     738,   742,   746,   748,   752,   754,   756,   758,   760,   762,
     764,   766,   768,   771,   776,   779,   781,   783,   785,   791,
     798,   803,   809,   810,   811,   820,   822,   826,   835,   838,
     841,   844,   850,   856,   858,   863,   865,   870,   873,   875,
     878,   880,   881,   890,   891,   900,   904,   905,   906,   912,
     917,   919,   922,   926,   929,   934,   937,   939,   941,   943,
     947,   949,   951,   953,   955,   957,   959,   961,   963,   965,
     967,   969,   971,   973,   975,   977,   979,   981,   983,   985,
     987,   989,   991,   993,   995,   997,   999,  1001,  1003,  1005,
    1007,  1010,  1013,  1015,  1018,  1021,  1023,  1026,  1028,  1031,
    1033,  1036,  1038,  1041,  1045,  1049,  1053,  1056,  1061,  1066,
    1071,  1074,  1078,  1082,  1086,  1090,  1095,  1100,  1108,  1115,
    1121,  1125,  1129,  1131,  1134,  1137,  1140,  1142,  1145,  1147,
    1150,  1152,  1155,  1157,  1160,  1162,  1165,  1167,  1170,  1172,
    1174,  1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,
    1195,  1198,  1201,  1204,  1207,  1210,  1213,  1216,  1219,  1222,
    1225,  1228,  1231,  1234,  1236,  1238,  1240,  1242,  1244,  1246,
    1248,  1249,  1250,  1251,  1252,  1262,  1264,  1266,  1268,  1271,
    1273,  1275,  1277,  1279,  1282,  1285,  1287,  1290,  1292,  1295,
    1299,  1302,  1306,  1311,  1316,  1321,  1324,  1328,  1331,  1335,
    1340,  1347,  1353,  1355,  1358,  1362,  1364,  1366,  1371,  1376,
    1381,  1385,  1389,  1393,  1397,  1400,  1402,  1404,  1409,  1414,
    1417,  1422,  1423,  1425,  1429,  1431,  1433,  1435,  1437,  1440,
    1445,  1448,  1453,  1457,  1460,  1462,  1465,  1468,  1471,  1473,
    1475,  1477,  1479,  1481,  1483,  1485,  1487,  1490,  1495,  1498,
    1503,  1507,  1510,  1512,  1515,  1518,  1521,  1523,  1525,  1527,
    1529,  1531,  1533,  1535
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     175,     0,    -1,    -1,   175,   176,    -1,    -1,   177,   170,
      -1,   178,    -1,     1,    -1,    -1,   179,   180,    -1,   178,
      39,   180,    -1,   185,    -1,    38,    -1,   181,    -1,   182,
      -1,   184,    -1,   183,    -1,   245,    -1,   324,    -1,   325,
      -1,   248,    38,    -1,   258,    38,    -1,   286,    38,    -1,
      44,    41,    -1,    73,    44,    41,    -1,    74,    44,    41,
      -1,   186,    -1,   196,    -1,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    29,   187,   180,    30,   188,   127,
     189,   180,   190,   128,   191,   193,   192,   195,    -1,    -1,
      -1,    86,   194,   180,   128,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    64,    29,   248,    30,    31,   197,   205,   198,
     209,   199,   200,    32,    -1,    -1,    -1,    -1,    -1,    65,
      29,   201,   180,    30,   202,    31,   203,   211,   204,    32,
      -1,    -1,   206,   207,    -1,   205,   207,    -1,    -1,    87,
     248,   208,    41,   180,    -1,    -1,    -1,    89,    41,   210,
     180,    -1,    -1,   212,   213,    -1,   211,   213,    -1,    -1,
      -1,    88,   248,   214,    41,   215,   180,    -1,    -1,   217,
     219,    -1,   223,    -1,   229,    -1,   236,    -1,    -1,   243,
     218,    -1,    -1,    -1,    -1,    93,    29,   220,   180,   221,
      30,   222,   180,    -1,    -1,    -1,    -1,    -1,    -1,   224,
      97,   225,   180,    93,   226,    29,   227,   180,   228,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    99,    29,
     231,   180,    38,   232,   180,    38,   233,   180,   234,    30,
     235,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
     237,   180,   238,    99,    29,   239,   180,    38,   240,   180,
      38,   241,   180,   242,    30,    -1,    -1,   101,   244,   180,
      -1,    -1,    31,   246,   247,    32,    -1,   178,    -1,   178,
     247,    -1,   249,    -1,   250,    -1,   251,    -1,   252,    -1,
     253,    -1,   254,    -1,   255,    -1,   256,    -1,   257,    -1,
      33,    -1,    29,   249,    30,    -1,    34,    -1,     7,   250,
      -1,   250,    26,   250,    -1,   250,    27,   250,    -1,    29,
     250,    30,    -1,    35,    -1,   251,    14,   251,    -1,   251,
      15,   251,    -1,   251,    13,   251,    -1,   251,    12,   251,
      -1,   251,    11,   251,    -1,    15,   251,    -1,   251,    10,
     251,    -1,   251,     9,   251,    -1,     4,   251,    -1,   251,
       4,    -1,     3,   251,    -1,   251,     3,    -1,   251,     8,
     251,    -1,   251,    24,   251,    -1,   251,    25,   251,    -1,
       6,   251,    -1,   251,    17,   251,    -1,   251,    16,   251,
      -1,    29,   251,    30,    -1,    36,    -1,   252,    14,   252,
      -1,   252,    15,   252,    -1,   252,    13,   252,    -1,   252,
      12,   252,    -1,   252,    11,   252,    -1,   252,    10,   252,
      -1,   252,     9,   252,    -1,     4,   252,    -1,   252,     4,
      -1,     3,   252,    -1,   252,     3,    -1,    29,   252,    30,
      -1,    37,    -1,   253,    14,   253,    -1,    43,   253,    -1,
      29,   253,    30,    -1,    44,    -1,     8,   254,    -1,     7,
     254,    -1,   254,    26,   254,    -1,   254,    27,   254,    -1,
     254,    14,   254,    -1,   254,    15,   254,    -1,   254,    13,
     254,    -1,   254,    12,   254,    -1,   254,    11,   254,    -1,
      15,   254,    -1,   254,    10,   254,    -1,   254,     9,   254,
      -1,     4,   254,    -1,   254,     4,    -1,     3,   254,    -1,
     254,     3,    -1,    29,   254,    30,    -1,   251,    23,   251,
      -1,   251,    22,   251,    -1,   251,    21,   251,    -1,   251,
      19,   251,    -1,   251,    20,   251,    -1,   251,    18,   251,
      -1,    29,   256,    30,    -1,    44,    26,   250,    -1,   250,
      26,    44,    -1,    44,    27,   250,    -1,   250,    27,    44,
      -1,    44,    14,   251,    -1,    44,    15,   251,    -1,    44,
      13,   251,    -1,    44,    12,   251,    -1,    44,    10,   251,
      -1,    44,     9,   251,    -1,   251,    14,    44,    -1,   251,
      15,    44,    -1,   251,    13,    44,    -1,   251,    12,    44,
      -1,   251,    10,    44,    -1,   251,     9,    44,    -1,    44,
      14,   252,    -1,    44,    15,   252,    -1,    44,    13,   252,
      -1,    44,    12,   252,    -1,    44,    10,   252,    -1,    44,
       9,   252,    -1,   252,    14,    44,    -1,   252,    15,    44,
      -1,   252,    13,    44,    -1,   252,    12,    44,    -1,   252,
      10,    44,    -1,   252,     9,    44,    -1,    44,    14,   253,
      -1,   253,    14,    44,    -1,   251,    23,    44,    -1,   251,
      22,    44,    -1,   251,    21,    44,    -1,   251,    19,    44,
      -1,   251,    20,    44,    -1,   251,    18,    44,    -1,    44,
      23,   251,    -1,    44,    22,   251,    -1,    44,    21,   251,
      -1,    44,    19,   251,    -1,    44,    20,   251,    -1,    44,
      18,   251,    -1,    44,     8,   251,    -1,    44,    24,   251,
      -1,    44,    25,   251,    -1,   251,     8,    44,    -1,   251,
      24,    44,    -1,   251,    25,    44,    -1,     6,    44,    -1,
      44,    17,   251,    -1,    44,    16,   251,    -1,   251,    17,
      44,    -1,   251,    16,    44,    -1,   321,    -1,    29,   257,
      30,    -1,   259,    -1,   268,    -1,   263,    -1,   267,    -1,
     269,    -1,   274,    -1,   278,    -1,   285,    -1,    45,    44,
      -1,    45,    44,    28,   248,    -1,   100,    44,    -1,   260,
      -1,   261,    -1,   262,    -1,   114,    37,    37,    28,    37,
      -1,   119,   117,    37,    37,    28,    37,    -1,   119,   117,
      37,    37,    -1,   122,    37,   120,   251,   121,    -1,    -1,
      -1,   113,    44,    28,    31,   264,   266,   265,    32,    -1,
      37,    -1,   266,    39,    37,    -1,   116,   117,    37,    28,
      37,   118,   118,    37,    -1,    73,    44,    -1,    74,    44,
      -1,    92,    44,    -1,    33,    44,    29,   270,    30,    -1,
      45,    44,    29,   270,    30,    -1,   272,    -1,   270,   171,
      45,    44,    -1,   273,    -1,   270,   171,    45,    44,    -1,
      45,    44,    -1,    33,    -1,    45,    44,    -1,    33,    -1,
      -1,   132,    33,    44,    29,   271,    30,   275,   277,    -1,
      -1,   132,    45,    44,    29,   270,    30,   276,   277,    -1,
      31,   247,    32,    -1,    -1,    -1,   279,   133,    44,   280,
     281,    -1,    31,   282,    38,    32,    -1,   283,    -1,   283,
     282,    -1,   133,   284,    38,    -1,    45,    44,    -1,    45,
      44,    28,   248,    -1,   100,    44,    -1,   260,    -1,   261,
      -1,   262,    -1,   134,    44,    44,    -1,   287,    -1,   288,
      -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,   293,
      -1,   299,    -1,   300,    -1,   301,    -1,   302,    -1,   303,
      -1,   304,    -1,   305,    -1,   306,    -1,   307,    -1,   308,
      -1,   309,    -1,   310,    -1,   311,    -1,   312,    -1,   313,
      -1,   314,    -1,   315,    -1,   316,    -1,   317,    -1,   318,
      -1,   319,    -1,   320,    -1,    46,    -1,    46,   248,    -1,
      46,    77,    -1,    47,    -1,    47,   248,    -1,    47,    77,
      -1,    48,    -1,    48,   248,    -1,    49,    -1,    49,   248,
      -1,   109,    -1,   109,   248,    -1,   110,    -1,   110,   248,
      -1,    46,   122,    37,    -1,    53,    52,    44,    -1,   111,
      52,    44,    -1,    50,   251,    -1,    51,    37,    37,   253,
      -1,    54,    62,    55,   251,    -1,    54,    62,    55,    52,
      -1,    54,    55,    -1,    54,    55,   250,    -1,    54,    55,
     251,    -1,    54,    55,   252,    -1,    54,    55,   253,    -1,
      54,    62,    55,    44,    -1,    54,   116,   117,    37,    -1,
      54,   116,   117,    37,   120,   251,   121,    -1,    54,   122,
      37,   120,   251,   121,    -1,    54,   122,    37,   120,   121,
      -1,    56,    57,   251,    -1,    56,    57,    44,    -1,    14,
      -1,    14,   251,    -1,    14,   252,    -1,    14,   253,    -1,
      15,    -1,    42,   251,    -1,    13,    -1,    13,   251,    -1,
      12,    -1,    12,   251,    -1,    11,    -1,    11,   251,    -1,
      10,    -1,    10,   251,    -1,     9,    -1,     9,   251,    -1,
       4,    -1,     3,    -1,    26,    -1,    27,    -1,     7,    -1,
      23,    -1,    22,    -1,    21,    -1,    19,    -1,    20,    -1,
      18,    -1,    23,   250,    -1,    22,   250,    -1,    23,   251,
      -1,    22,   251,    -1,    21,   251,    -1,    19,   251,    -1,
      20,   251,    -1,    18,   251,    -1,    23,   252,    -1,    22,
     252,    -1,    21,   252,    -1,    19,   252,    -1,    20,   252,
      -1,    18,   252,    -1,     8,    -1,    24,    -1,    25,    -1,
       6,    -1,    17,    -1,    16,    -1,   294,    -1,    -1,    -1,
      -1,    -1,   180,    40,   295,   296,   180,   297,    41,   298,
     180,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    62,
      -1,    63,    -1,   130,    -1,   131,    -1,    64,    -1,    66,
     253,    -1,    67,    68,    -1,    69,    -1,    70,    62,    -1,
      71,    -1,    72,   251,    -1,    72,    75,    44,    -1,    81,
      75,    -1,    82,    75,    44,    -1,    83,    75,    44,    44,
      -1,    82,   123,    75,   251,    -1,    84,    62,    55,   251,
      -1,    84,    55,    -1,    84,    62,    55,    -1,    84,    96,
      -1,    84,   115,    37,    -1,    84,   116,   117,    37,    -1,
      84,   122,    37,   120,   251,   121,    -1,    84,   122,    37,
     120,   121,    -1,    91,    -1,    91,    44,    -1,    94,    76,
      44,    -1,    95,    -1,   102,    -1,   103,    77,    52,   251,
      -1,   103,    77,    52,   250,    -1,   103,    77,    52,   253,
      -1,   103,    77,   251,    -1,   104,    78,   253,    -1,   105,
      79,    80,    -1,   106,    79,   253,    -1,   107,    79,    -1,
     108,    -1,   112,    -1,   124,    37,    37,    37,    -1,   122,
      37,   118,   125,    -1,   126,    62,    -1,    44,    29,   322,
      30,    -1,    -1,   323,    -1,   322,   171,   248,    -1,   248,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,    37,    -1,
     138,   172,    37,   173,    -1,   139,    37,    -1,   139,   172,
      37,   173,    -1,   140,    37,    37,    -1,   141,    37,    -1,
     142,    -1,   143,    37,    -1,   144,    37,    -1,   145,    37,
      -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,
      -1,   151,    -1,   152,    -1,   153,    -1,   154,    37,    -1,
     154,   172,    37,   173,    -1,   155,    37,    -1,   155,   172,
      37,   173,    -1,   156,    37,    37,    -1,   157,    37,    -1,
     158,    -1,   159,    37,    -1,   160,    37,    -1,   161,    37,
      -1,   162,    -1,   163,    -1,   164,    -1,   165,    -1,   166,
      -1,   167,    -1,   168,    -1,   169,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1176,  1176,  1177,  1180,  1180,  1183,  1184,  1187,  1187,
    1190,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1201,  1202,
    1205,  1210,  1215,  1220,  1224,  1228,  1234,  1237,  1240,  1246,
    1251,  1255,  1259,  1262,  1266,  1245,  1274,  1275,  1274,  1285,
    1289,  1293,  1297,  1299,  1288,  1306,  1311,  1315,  1319,  1305,
    1327,  1327,  1330,  1334,  1333,  1342,  1343,  1342,  1352,  1352,
    1355,  1359,  1363,  1358,  1380,  1380,  1385,  1388,  1391,  1395,
    1394,  1402,  1406,  1409,  1401,  1417,  1420,  1425,  1429,  1433,
    1417,  1441,  1444,  1449,  1454,  1458,  1461,  1441,  1470,  1474,
    1477,  1482,  1487,  1491,  1469,  1500,  1499,  1508,  1507,  1518,
    1521,  1526,  1527,  1531,  1532,  1533,  1534,  1538,  1539,  1540,
    1544,  1549,  1555,  1559,  1573,  1589,  1605,  1611,  1616,  1624,
    1630,  1636,  1642,  1648,  1656,  1662,  1668,  1674,  1680,  1686,
    1692,  1700,  1708,  1716,  1723,  1731,  1739,  1745,  1749,  1756,
    1763,  1770,  1777,  1784,  1791,  1798,  1804,  1810,  1816,  1822,
    1828,  1832,  1857,  1864,  1870,  1888,  1928,  1965,  2042,  2121,
    2201,  2239,  2277,  2315,  2353,  2366,  2404,  2442,  2470,  2498,
    2526,  2554,  2560,  2568,  2576,  2584,  2592,  2600,  2611,  2615,
    2662,  2709,  2756,  2803,  2843,  2883,  2923,  2963,  3003,  3043,
    3083,  3123,  3163,  3203,  3243,  3283,  3323,  3363,  3403,  3443,
    3483,  3523,  3563,  3603,  3643,  3683,  3723,  3763,  3825,  3887,
    3930,  3973,  4016,  4059,  4102,  4145,  4188,  4231,  4274,  4317,
    4360,  4403,  4446,  4489,  4532,  4575,  4618,  4661,  4696,  4739,
    4782,  4825,  4870,  4871,  4874,  4877,  4880,  4883,  4886,  4889,
    4892,  4895,  4898,  4908,  4943,  4947,  4950,  4953,  4958,  4970,
    4980,  4992,  5005,  5009,  5004,  5017,  5021,  5027,  5034,  5038,
    5042,  5048,  5072,  5093,  5098,  5101,  5105,  5108,  5112,  5115,
    5119,  5123,  5122,  5147,  5146,  5171,  5176,  5179,  5176,  5193,
    5196,  5200,  5206,  5212,  5219,  5227,  5231,  5234,  5237,  5242,
    5270,  5273,  5276,  5279,  5282,  5285,  5288,  5291,  5294,  5297,
    5300,  5303,  5306,  5309,  5312,  5315,  5318,  5321,  5324,  5327,
    5330,  5333,  5336,  5339,  5342,  5345,  5348,  5351,  5354,  5360,
    5364,  5368,  5372,  5376,  5380,  5384,  5388,  5392,  5396,  5400,
    5404,  5408,  5412,  5416,  5423,  5427,  5434,  5440,  5447,  5451,
    5455,  5459,  5463,  5467,  5471,  5475,  5480,  5485,  5490,  5494,
    5500,  5504,  5510,  5514,  5518,  5522,  5526,  5530,  5534,  5538,
    5542,  5546,  5550,  5554,  5558,  5562,  5566,  5570,  5574,  5578,
    5582,  5586,  5590,  5594,  5598,  5602,  5606,  5610,  5614,  5618,
    5622,  5626,  5630,  5634,  5638,  5642,  5646,  5650,  5654,  5658,
    5662,  5666,  5670,  5674,  5678,  5682,  5686,  5690,  5694,  5698,
    5707,  5710,  5713,  5716,  5705,  5724,  5730,  5734,  5740,  5746,
    5750,  5754,  5758,  5764,  5770,  5776,  5782,  5788,  5792,  5796,
    5802,  5806,  5810,  5815,  5821,  5825,  5829,  5833,  5837,  5841,
    5845,  5849,  5855,  5859,  5865,  5871,  5877,  5883,  5887,  5892,
    5897,  5903,  5909,  5913,  5917,  5921,  5927,  5933,  5940,  5945,
    5951,  6004,  6007,  6011,  6014,  6020,  6024,  6028,  6034,  6038,
    6042,  6046,  6050,  6054,  6058,  6062,  6066,  6070,  6074,  6078,
    6082,  6086,  6090,  6094,  6098,  6102,  6106,  6110,  6114,  6118,
    6122,  6126,  6130,  6134,  6138,  6142,  6146,  6150,  6154,  6158,
    6162,  6166,  6170,  6174
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
  "FUNCTION", "STRUCT", "STRUCTD", "PBIN", "PPBIN", "PLIB", "PINCLUDE",
  "PIMPORT", "PDEFINE", "PMACRO", "PENDM", "PUNDEF", "PIFDEF", "PIFNDEF",
  "PELSE", "PENDIF", "PPDATE", "PPTIME", "PPLINE", "PPFILE", "PPCDATE",
  "PPCTIME", "PPINCLUDE", "PPIMPORT", "PPDEFINE", "PPMACRO", "PPENDM",
  "PPUNDEF", "PPIFDEF", "PPIFNDEF", "PPELSE", "PPENDIF", "PPPDATE",
  "PPPTIME", "PPPLINE", "PPPFILE", "PPPCDATE", "PPPCTIME", "\"\\n\"",
  "\",\"", "\"<\"", "\">\"", "$accept", "input", "line", "$@1",
  "statement", "$@2", "stmt", "expression_statement",
  "declaration_statement", "command_statement", "label_statement",
  "control_statement", "if_statement", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "opt_else", "$@9", "eif", "switch_statement", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "case_statements",
  "$@18", "case_statement", "$@19", "opt_default_statement", "$@20",
  "case_statements2", "$@21", "case_statement2", "$@22", "$@23",
  "loop_statement", "$@25", "$@26", "while_loop", "$@27", "$@28", "$@29",
  "whileb_loop", "$@30", "$@31", "$@32", "$@33", "$@34", "for_loop",
  "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "forb_loop", "$@41",
  "$@42", "$@43", "$@44", "$@45", "$@46", "forever_loop", "$@47",
  "statement_block", "$@48", "statements", "expression", "void_expression",
  "boolean_expression", "number_expression", "character_expression",
  "string_expression", "id_expression", "relational_expression",
  "mixed_expression", "function_expression", "declaration",
  "variable_declaration", "enumv_declaration", "rangev_declaration",
  "array_declaration", "enum_declaration", "$@49", "$@50", "enum_strings",
  "range_declaration", "label_declaration", "function_declaration",
  "parameter_declaration", "parameter_declaration2", "opt_var", "opt_var2",
  "function_declaration2", "$@51", "$@52", "function_body",
  "struct_declaration", "$@53", "$@54", "struct_body", "vars",
  "variable_declaration2", "variable_declaration3", "struct_declaration2",
  "command", "print_command", "read_command", "end_command", "asm_command",
  "load_command", "goto_command", "operator_command", "top_command",
  "$@55", "$@56", "$@57", "$@58", "st_command", "stack_command",
  "typeof_command", "rm_command", "crash_command", "version_command",
  "halt_command", "modt_command", "subroutine_command", "register_command",
  "store_command", "break_command", "address_command", "add2v_command",
  "continue_command", "check_command", "comment_command", "file_command",
  "meml_command", "pnfasm_command", "array_length_command", "dup_command",
  "function_command", "actual_function_parameters", "opt_expression",
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   174,   175,   175,   177,   176,   176,   176,   179,   178,
     178,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     181,   182,   183,   184,   184,   184,   185,   185,   185,   187,
     188,   189,   190,   191,   192,   186,   193,   194,   193,   195,
     197,   198,   199,   200,   196,   201,   202,   203,   204,   196,
     206,   205,   205,   208,   207,   209,   210,   209,   212,   211,
     211,   214,   215,   213,   217,   216,   216,   216,   216,   218,
     216,   220,   221,   222,   219,   224,   225,   226,   227,   228,
     223,   230,   231,   232,   233,   234,   235,   229,   237,   238,
     239,   240,   241,   242,   236,   244,   243,   246,   245,   247,
     247,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     249,   249,   250,   250,   250,   250,   250,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     253,   253,   253,   253,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   255,   255,   255,   255,   255,   255,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   257,   257,   258,   258,   258,   258,   258,   258,
     258,   258,   259,   259,   259,   259,   259,   259,   260,   261,
     261,   262,   264,   265,   263,   266,   266,   267,   268,   268,
     268,   269,   269,   270,   270,   271,   271,   272,   272,   273,
     273,   275,   274,   276,   274,   277,   279,   280,   278,   281,
     282,   282,   283,   284,   284,   284,   284,   284,   284,   285,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   288,   288,   289,   290,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     292,   292,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     295,   296,   297,   298,   294,   299,   300,   300,   301,   302,
     302,   302,   302,   303,   304,   305,   306,   307,   307,   307,
     308,   308,   308,   308,   309,   309,   309,   309,   309,   309,
     309,   309,   310,   310,   311,   312,   313,   314,   314,   314,
     314,   315,   316,   316,   316,   316,   317,   318,   319,   320,
     321,   322,   322,   322,   323,   324,   324,   324,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     3,     1,     1,     1,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     4,     1,
       0,     0,     0,     0,    12,     0,     0,     0,     0,    11,
       0,     2,     2,     0,     5,     0,     0,     4,     0,     2,
       2,     0,     0,     6,     0,     2,     1,     1,     1,     0,
       2,     0,     0,     0,     8,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,    16,     0,     3,     0,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     2,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       1,     3,     2,     3,     1,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     2,     1,     1,     1,     5,     6,
       4,     5,     0,     0,     8,     1,     3,     8,     2,     2,
       2,     5,     5,     1,     4,     1,     4,     2,     1,     2,
       1,     0,     8,     0,     8,     3,     0,     0,     5,     4,
       1,     2,     3,     2,     4,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     3,     3,     3,     2,     4,     4,     4,
       2,     3,     3,     3,     3,     4,     4,     7,     6,     5,
       3,     3,     1,     2,     2,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     0,     0,     9,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     2,     1,     2,     1,     2,     3,
       2,     3,     4,     4,     4,     2,     3,     2,     3,     4,
       6,     5,     1,     2,     3,     1,     1,     4,     4,     4,
       3,     3,     3,     3,     2,     1,     1,     4,     4,     2,
       4,     0,     1,     3,     1,     1,     1,     1,     2,     4,
       2,     4,     3,     2,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     2,     4,
       3,     2,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     7,     3,     0,     6,    64,     5,    64,
     369,   368,   396,   372,   393,   366,   364,   362,   360,   358,
     352,   356,   398,   397,   378,   376,   377,   375,   374,   373,
     394,   395,   370,   371,     0,    97,   110,   112,   117,   137,
     150,    12,     0,     0,   154,     0,   319,   322,   325,   327,
       0,     0,     0,     0,     0,   405,   406,   407,     0,   409,
     412,     0,     0,     0,   415,     0,   417,     0,     0,     0,
       0,     0,     0,     0,     0,   432,     0,     0,   435,    88,
       0,    95,   436,     0,     0,     0,     0,     0,   445,   329,
     331,     0,   446,     0,     0,     0,     0,     0,     0,     0,
     410,   411,     0,     0,   455,   456,   457,     0,     0,     0,
       0,   464,     0,     0,     0,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   482,     0,     0,
       0,   486,   487,   488,   489,   490,   491,   492,   493,     9,
      13,    14,    16,    15,    11,    26,    27,    28,     0,    66,
       0,    67,     0,    68,    69,    17,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,   234,   245,   246,
     247,   236,   237,   235,   238,   239,   240,     0,   241,     0,
     290,   291,   292,   293,   294,   295,   296,   399,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     232,    18,    19,    10,     0,     0,     0,     0,     0,     0,
       0,   154,   128,   147,   169,   126,   145,   167,     0,     0,
       0,     0,   227,   133,     0,     0,     0,     0,     0,   113,
     156,     0,   155,   367,   365,   363,   361,   359,     0,     0,
       0,   353,   354,   355,     0,     0,     0,   123,   164,     0,
     386,   392,   384,   390,   385,   391,   383,   389,     0,     0,
     380,   382,   388,   379,   381,   387,     0,   110,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,   357,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   451,    23,   242,   321,     0,   320,   324,   323,   326,
     328,   336,     0,     0,   340,     0,     0,     0,     0,   408,
       0,    45,   413,   414,   416,     0,   418,   258,   259,   420,
       0,     0,     0,   425,     0,   427,     0,     0,     0,    29,
     433,   260,     0,    64,   244,    64,     0,     0,     0,     0,
     444,   330,   332,     0,     0,     0,     0,     0,     0,     0,
     449,     0,     0,     0,   458,     0,   460,     0,     0,   463,
     465,   466,   467,   476,     0,   478,     0,     0,   481,   483,
     484,   485,   400,     0,    65,    76,     0,    70,    20,     0,
       0,   129,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   146,     0,     0,     0,     0,     0,     0,     0,
       0,   170,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,   116,     0,     0,     0,     0,     0,     0,   136,   149,
     153,   171,   178,   233,     8,     0,     0,   221,   188,   200,
     187,   199,   186,   198,   185,   197,   183,   195,   207,   184,
     196,   229,   228,   220,   218,   219,   217,   216,   215,   222,
     223,   179,   181,   454,     0,   452,     0,     0,   333,     0,
     334,     0,   341,   342,   343,   344,     0,     0,     0,   351,
     350,     0,    64,   419,    24,    25,   421,     0,     0,   426,
     428,     0,     0,    64,   434,    89,    96,     0,   440,   441,
     442,   443,   335,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   289,     0,     0,   462,     0,     0,   480,   401,
      71,    64,    82,   180,   114,   182,   115,   224,   130,   194,
     125,   193,   124,   122,   192,   121,   191,   120,   189,   118,
     190,   119,   231,   135,   230,   134,   214,   177,   212,   175,
     213,   176,   211,   174,   210,   173,   209,   172,   225,   131,
     226,   132,     0,     0,     0,   206,   144,   205,   143,   142,
     204,   141,   203,   140,   201,   138,   202,   139,   208,   151,
     166,   165,   163,   162,   161,   159,   160,   157,   158,   277,
     100,    98,   268,     0,     0,   263,   450,     0,   243,     0,
     337,   345,   339,   338,   346,     0,     0,     0,   423,   422,
     424,   429,     0,     0,     0,     0,   438,   437,   439,   252,
       0,     0,   250,   448,     0,   447,     0,     0,   459,   461,
     477,   479,    64,    64,     0,    64,     0,   267,   261,     0,
     453,   262,     0,   349,     0,    40,    46,   431,     0,    30,
       0,     0,   248,     0,     0,   251,   268,     0,     0,     0,
     265,     0,   402,    72,    77,     0,     0,   278,     0,     0,
     348,    50,     0,   430,     0,    90,   255,   253,     0,   249,
     267,     0,   271,   273,     0,     0,     0,    83,     0,     0,
     280,   264,   347,    41,     0,    47,    31,    64,     0,     0,
       0,     0,     0,     0,   403,    73,    78,    64,     0,     0,
       0,   286,   287,   288,     0,     0,   281,     0,    55,    52,
      51,    58,    64,     0,   256,   254,   257,   264,     8,   272,
     274,    64,    64,    64,     0,   283,   285,     0,   282,   279,
      53,     0,    42,    48,     0,    32,    91,     0,   404,    74,
      79,    84,     0,     0,    56,    43,     0,     0,    60,    59,
       0,    64,   275,     0,    64,   284,    64,    64,     0,    61,
      49,    33,     0,    80,    85,    54,    57,    44,     0,    36,
      92,     0,    62,    37,    34,    64,    86,    64,    64,     0,
      93,    64,    63,     0,    39,    35,     0,    87,    38,    94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,   484,     7,   139,   140,   141,   142,
     143,   144,   145,   543,   724,   772,   810,   829,   839,   834,
     838,   845,   146,   721,   768,   805,   818,   532,   722,   771,
     807,   743,   744,   769,   803,   792,   817,   793,   794,   808,
     828,   837,   147,   148,   397,   394,   683,   735,   782,   149,
     150,   571,   736,   783,   813,   151,   152,   685,   757,   814,
     831,   841,   153,   353,   664,   747,   811,   835,   846,   154,
     355,   155,   287,   485,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     701,   749,   727,   172,   173,   174,   644,   709,   645,   710,
     175,   752,   753,   779,   176,   177,   686,   717,   739,   740,
     764,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   569,   682,   734,   781,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   514,   515,
     211,   212
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -513
static const yytype_int16 yypact[] =
{
    -513,   932,  -513,  -513,  -513,  -141,    13,  1100,  -513,  1100,
     455,   455,   509,   188,   306,   473,   473,   473,   473,   473,
    1392,   522,  -513,  -513,  1464,  1464,  1464,  1464,  1451,  1451,
    -513,  -513,  -513,  -513,   322,  -513,    21,  -513,  -513,  -513,
    -513,  -513,   473,    19,  1424,    29,    71,   234,   322,   322,
     473,    59,    61,   -29,    35,  -513,  -513,  -513,    48,  -513,
     107,   112,    19,    63,  -513,    83,  -513,   123,   105,   109,
      82,   -41,    88,   -13,   145,   134,   142,   113,  -513,  -513,
     153,  -513,  -513,   125,   106,   126,   128,   130,  -513,   322,
     322,   166,  -513,   186,   211,   147,   158,   225,   236,   219,
    -513,  -513,    31,   240,  -513,  -513,  -513,    -6,    -5,   249,
     268,  -513,   282,   285,   296,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,    -2,    -1,   299,   302,  -513,   303,   308,
     312,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,   314,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,   267,  -513,
     271,  -513,   272,  -513,  -513,  -513,   334,  -513,   194,  1619,
     602,   363,  1599,  -513,  -513,  -513,   335,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,   245,  -513,   342,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,   314,   455,   455,   473,   306,   306,   522,
     455,  -513,  1547,  1374,   653,  1547,  1374,   653,   473,   473,
     473,   473,  -513,  1547,   306,   306,   188,   306,   188,   208,
     653,   306,   653,  1642,  1642,  1642,  1642,  1642,  1464,  1464,
    1392,  1642,   914,   367,   522,   522,   522,  1547,   653,  1464,
    1642,   914,  1642,   914,  1642,   914,  1642,   914,   127,  1451,
     208,  1642,   914,   208,  1642,   914,   509,  -513,  1660,   360,
     174,  1493,  1564,    23,  1539,   361,   362,  -513,   366,  1642,
      19,   367,   473,  1464,  1464,  1464,  1464,  1392,  1464,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   127,
     127,   322,  -513,   251,  -513,   352,  -513,  -513,  -513,  -513,
    -513,  1642,   380,   353,  1365,   343,   304,   383,   690,  -513,
     322,  -513,   367,  -513,  -513,   378,  1642,   392,   393,  -513,
     391,   381,   397,  -513,   387,  -513,   399,   340,   423,  -513,
    -513,  -513,   420,  1100,  -513,  1100,   184,    19,   385,    19,
    -513,  -513,  -513,   422,   444,   436,   437,   438,   -77,   441,
    -513,   445,   448,   452,  -513,   460,  -513,   461,   463,  -513,
    -513,  -513,  -513,  -513,   474,  -513,   477,   479,  -513,  -513,
    -513,  -513,  -513,   481,  -513,  -513,   489,  -513,  -513,   199,
     309,  -513,  -513,   708,   762,   795,   473,   808,   830,   838,
     843,   860,   887,  1267,  1271,  1275,  1288,  1310,  1318,  1323,
    1331,  -513,  -513,   279,   338,    65,   451,   465,   516,   536,
     210,  -513,  -513,   306,   306,   306,   306,   306,   306,   306,
     306,   306,  -513,   483,  -513,  1516,  1577,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,    65,    65,
      65,    65,    65,    65,   230,   127,   127,    25,    19,   127,
    -513,  -513,   487,   488,   497,   498,   502,   503,  -513,  -513,
    -513,  -513,  -513,  -513,    15,   449,    97,  1642,  1642,   914,
    1642,   914,  1642,   914,  1642,   914,  1642,   914,   367,  1642,
     914,  1642,  1642,  1642,  1642,  1642,  1642,  1642,  1642,  1642,
    1642,   208,   208,  -513,   -21,  -513,   322,    97,  -513,    19,
    -513,  1365,   208,  1642,   914,   367,   179,   484,   428,  -513,
    1642,   519,  1100,  -513,  -513,  -513,  -513,   473,   506,   473,
    -513,   518,   443,  1100,  -513,   314,   314,  1375,  1642,   367,
    -513,   367,  -513,   530,   543,   547,   527,   456,   473,   539,
     557,   568,  -513,   425,   426,  -513,   427,   446,  -513,  -513,
    -513,  1100,  -513,  -513,   574,  -513,  -513,  -513,  1681,  -513,
    1681,  -513,  1681,   553,  -513,   553,  -513,   553,  -513,   156,
    -513,   156,  -513,   293,  -513,   293,  -513,  1642,  -513,  1642,
    -513,  1642,  -513,  1642,  -513,  1642,  -513,  1642,  -513,  -513,
    -513,  -513,    65,    65,    65,  -513,  1374,  -513,  1374,   244,
    -513,   244,  -513,   244,  -513,  -513,  -513,  -513,  -513,  -513,
     653,   653,   349,   349,   349,   305,   305,   583,  -513,  -513,
    -513,  -513,  -513,   576,   -20,  -513,  -513,   322,  -513,   -11,
     367,  -513,  -513,  1642,   501,    55,   591,    20,  1642,  -513,
    1642,  -513,   140,    58,   524,  1375,   208,  1642,   367,  -513,
     589,   590,   611,  -513,   108,  -513,   102,    97,  -513,  -513,
    -513,  -513,  1100,  1100,   -12,  1100,   609,  -513,  -513,   596,
    -513,  -513,   473,  -513,   415,  -513,  -513,  -513,   579,  -513,
     613,   606,  -513,   526,   610,  -513,   618,   605,   499,   620,
    -513,    -3,   314,   314,  -513,    51,   538,  -513,   615,   621,
    -513,  -513,   629,  -513,   542,  -513,  -513,   633,   559,  -513,
     645,   636,  -513,  -513,   637,   652,   655,  -513,    40,   647,
     538,  -513,  -513,   608,   608,  -513,  -513,  1100,   660,   666,
     662,   657,   673,   673,  -513,  -513,  -513,  1100,   671,   672,
     680,  -513,  -513,  -513,   682,   686,  -513,   322,   632,  -513,
    -513,  -513,  1100,    57,  -513,  -513,  -513,   694,  -513,  -513,
    -513,  1100,  1100,  1100,    99,   701,  -513,   612,  -513,  -513,
    -513,   689,  -513,   643,   643,   314,  -513,   703,   314,   314,
     314,  -513,   322,   692,  -513,  -513,   322,   704,  -513,  -513,
     616,  1100,  -513,   709,  1100,  -513,  1100,  1100,   713,  -513,
    -513,  -513,   139,  -513,   314,   314,   314,  -513,   699,   661,
    -513,   711,  -513,  -513,  -513,  1100,  -513,  1100,  1100,   617,
     314,  1100,   314,     0,  -513,  -513,   719,   314,  -513,  -513
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -513,  -513,  -513,  -513,   749,  -513,    -9,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,     7,  -513,  -513,  -513,  -513,  -513,   -40,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -466,   -45,   721,    38,    -4,   359,    37,
     472,  -513,   722,   724,  -513,  -513,    22,    24,    26,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -512,  -513,  -513,  -513,
    -513,  -513,  -513,     6,  -513,  -513,  -513,  -513,    27,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -277
static const yytype_int16 yytable[] =
{
     213,   316,   318,   319,   320,   649,   222,   225,   233,   646,
     688,   243,   244,   245,   246,   247,   251,   257,   640,   691,
     260,   262,   264,   266,   271,   274,   324,   733,   392,     8,
     281,   374,   376,   325,   340,   383,   385,   430,   289,   468,
     392,   557,   343,   558,   361,   362,   321,   -99,   290,   344,
     696,   239,     9,   480,     9,   480,    40,   253,   228,   229,
     392,   216,    43,   336,   371,   288,   270,   273,   612,   613,
     230,   283,   280,   313,   214,   215,   372,   276,   236,   218,
     291,   714,   341,   345,   231,   758,   219,   326,   699,   737,
      38,   392,   328,   327,   614,   796,   322,   392,   392,   332,
      34,    39,   346,   347,   277,    37,    38,    39,    40,   348,
     329,   401,   402,   323,    43,   278,   447,   448,   449,   406,
     450,   451,   452,   453,   454,   455,   228,   229,   848,   216,
     642,   333,   456,   457,   268,   706,   330,   801,   230,   392,
     759,   331,   643,   228,   229,   334,   216,   707,   314,   337,
     647,   689,   231,   338,    94,   230,   469,   339,    38,    96,
     689,    37,   760,   342,   708,   711,   375,   377,   689,   231,
     384,   386,   454,   455,   349,    38,   693,   830,   350,   392,
     456,   457,   228,   229,   357,   216,   351,   228,   229,   352,
     216,   234,   235,   315,   230,   236,   218,   354,   335,   230,
     399,   400,   356,   237,   471,   358,   268,   359,   231,   360,
     222,   225,   233,   231,    38,   257,   445,   238,   363,    38,
     399,   400,    37,   651,   222,   225,   257,   445,   469,   705,
     364,   652,   221,    37,   465,   466,   547,   214,   215,   290,
     276,   236,   218,   573,   222,   225,   445,    40,   365,   219,
     222,   225,   445,    43,   628,   445,   465,   466,   462,   463,
     471,   697,   368,    34,   366,   445,   513,   277,    37,    38,
      39,    40,   233,   369,   239,   367,   464,    43,   278,   516,
     517,   370,   612,   613,   373,   531,   378,   467,   487,   488,
     490,   492,   494,   496,   499,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   379,   239,   464,   614,   234,
     235,   317,   797,   217,   218,    39,   268,   456,   457,   380,
     523,   237,   381,   615,   530,   214,   215,   467,   276,   236,
     218,   440,   441,   382,   498,   241,   387,   219,   469,   388,
     389,   612,   613,    37,   545,   390,   546,   511,   512,   391,
     221,    34,   548,   575,   392,   277,    37,    38,    39,    40,
     393,   525,   522,   438,   439,    43,   278,   614,   395,   223,
     226,   396,   398,   442,    39,   440,   441,   430,   443,   252,
     444,   468,   617,   261,   263,   265,   267,   272,   275,   518,
     470,   482,   483,   282,   549,   486,   551,   520,   526,   578,
     580,   582,   583,   585,   587,   589,   591,   593,   595,   597,
     599,   601,   603,   605,   607,   609,   611,   519,   401,   402,
     528,   527,   533,   447,   448,   449,   406,   450,   451,   452,
     453,   454,   455,   534,   535,   536,   540,   574,   576,   456,
     457,   538,   539,   578,   580,   582,   585,   587,   589,   591,
     593,   595,   609,   611,   612,   613,   537,   541,   214,   215,
     542,   216,   217,   218,   544,   550,   552,   629,   612,   613,
     219,   648,   553,   554,   555,   556,   228,   229,   559,   216,
     614,   641,   224,   227,   220,   240,   242,    39,   230,   560,
      38,    39,   561,   258,   614,   620,   562,   563,   564,   221,
     565,    39,   231,   574,   576,   629,   284,   464,    38,   622,
     570,   566,   228,   229,   567,   216,   568,   445,   572,   612,
     613,   654,   653,   657,   230,   254,   255,   639,   216,   217,
     218,   596,   598,   658,   663,   660,   720,   219,   231,   612,
     613,   600,   602,   667,    38,   614,   604,   606,   655,   656,
     659,   256,    39,   232,   674,   661,   650,    38,   467,   464,
     624,   669,   684,   662,   672,   614,   221,   452,   453,   454,
     455,   670,    39,   223,   226,   671,   675,   456,   457,   446,
     626,   673,   401,   402,   668,   666,   676,   447,   448,   449,
     406,   450,   451,   452,   453,   454,   455,   677,   678,   679,
     680,   466,   690,   456,   457,   421,   422,   223,   226,   446,
     441,   423,   424,   425,   426,   427,   428,   429,   446,   681,
     687,   692,   695,   700,   401,   402,   702,   703,   446,   447,
     448,   449,   406,   450,   451,   452,   453,   454,   455,   704,
     716,   718,   725,   726,   728,   456,   457,   729,  -270,   730,
     732,   694,   489,   491,   493,   495,   497,   500,   698,   741,
     745,   445,   433,   434,   435,   436,   437,   438,   439,   746,
     731,   738,   748,   712,   713,  -269,   715,   750,   754,   440,
     441,   751,   755,   524,   756,   765,   224,   227,   719,   240,
     242,   258,   284,   228,   229,   767,   216,   774,   775,   776,
     723,   777,   467,   464,   778,   230,   224,   227,   240,   258,
     284,   228,   229,   284,   216,   785,   786,   787,   789,   231,
     788,   791,   790,   230,  -266,    38,   224,   227,   284,   802,
     804,   806,   558,   816,   529,   812,   820,   231,   773,   823,
     832,   836,   742,    38,   821,   827,   844,   833,   784,   849,
       6,   770,   577,     0,   809,   279,   285,   815,   286,   780,
     761,   819,   762,   795,   763,   228,   229,   766,   216,     0,
       0,     0,   798,   799,   800,     0,     0,   230,     0,     0,
       0,     0,   616,   618,   619,   621,   623,   625,   627,     0,
       0,   231,     0,     0,     0,     0,     0,    38,   228,   229,
       0,   216,   822,     0,     0,   824,   579,   825,   826,     0,
     230,   228,   229,     0,   216,     0,     0,   616,   618,   621,
     623,   625,   627,   230,   231,     0,   840,     0,   842,   843,
      38,     0,   847,   228,   229,     0,   216,   231,     0,   581,
       0,   228,   229,    38,   216,   230,   228,   229,     0,   216,
       0,     0,   584,   230,     0,     0,     0,     0,   230,   231,
       0,     0,     0,   228,   229,    38,   216,   231,     0,     0,
       0,     0,   231,    38,   586,   230,     0,     0,    38,     0,
     446,     0,   588,     0,     0,     0,     0,   590,     0,   231,
     228,   229,     0,   216,     0,    38,     0,     0,     0,     0,
       0,     0,   230,     0,   592,   630,   631,   632,   633,   634,
     635,   636,   637,   638,     0,     0,   231,   421,   422,     0,
       0,     0,    38,   458,   459,   425,   460,   461,   462,   463,
       0,   594,     2,     3,     0,    -8,    -8,     0,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
       0,    -8,     0,    -8,     0,    -8,    -8,    -8,    -8,    -8,
      -8,   223,   226,   446,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,     0,    -8,    -8,     0,    -8,     0,
      -8,    -8,    -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,
       0,    -8,    -8,    -8,    -8,    -8,    -8,     0,     0,     0,
       0,     0,     0,    -8,    -8,    -8,    -8,    -8,     0,     0,
       0,     0,     0,    -8,    -8,    -8,    -8,    -8,     0,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,     0,    -8,     0,
       0,    -8,     0,     0,    -8,     0,    -8,     0,    -8,     0,
       0,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -4,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    34,
       0,    35,     0,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,     0,    52,    53,     0,    54,     0,    55,    56,
      57,    58,     0,    59,    60,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    69,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,     0,     0,     0,     0,
       0,    75,    76,     0,    77,    78,     0,   -75,    79,   -81,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,     0,     0,    96,
       0,     0,    97,     0,    98,     0,    99,     0,     0,     0,
     100,   101,   102,  -276,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     228,   229,     0,   216,   228,   229,     0,   216,   228,   229,
       0,   216,   230,     0,     0,     0,   230,     0,     0,     0,
     230,   228,   229,     0,   216,     0,   231,     0,     0,     0,
     231,     0,    38,   230,   231,     0,    38,     0,     0,     0,
      38,   596,     0,   228,   229,   598,   216,   231,     0,   600,
       0,   228,   229,    38,   216,   230,   228,   229,     0,   216,
       0,     0,   602,   230,   228,   229,     0,   216,   230,   231,
       0,     0,     0,     0,     0,    38,   230,   231,     0,     0,
       0,     0,   231,    38,   604,     0,     0,     0,    38,     0,
     231,     0,   606,     0,     0,     0,    38,   608,   248,   249,
       0,   216,   268,     0,     0,   610,     0,     0,   228,   229,
     230,   216,   268,   458,   459,   425,   460,   461,   462,   463,
     230,     0,     0,     0,   521,   248,   249,     0,   216,    37,
      38,    39,    40,     0,   665,     0,     0,   230,    43,    37,
      38,     0,    40,     0,     0,     0,     0,     0,    43,     0,
       0,   250,     0,     0,     0,     0,     0,    38,    39,    40,
       0,     0,   292,   293,   294,    43,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,     0,   311,   248,   249,     0,   216,   268,     0,
       0,     0,     0,     0,     0,   312,   230,   248,   249,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     269,     0,     0,     0,     0,    37,    38,    39,     0,     0,
       0,     0,     0,   259,     0,     0,   401,   402,     0,    38,
      39,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   472,   473,   474,   475,   476,   477,   419,   420,   401,
     402,     0,     0,   478,   447,   448,   449,   406,   450,   451,
     452,   453,   454,   455,     0,     0,     0,     0,     0,     0,
     456,   457,   431,   432,     0,     0,   478,     0,   433,   434,
     435,   436,   437,   438,   439,   447,   448,   449,   406,   450,
     451,   452,   453,   454,   455,   440,   441,   421,   422,   481,
       0,   456,   457,   423,   424,   425,   426,   427,   428,   429,
     421,   422,     0,     0,     0,     0,   458,   459,   425,   460,
     461,   462,   463,     0,   479,     0,     0,     0,     0,     0,
       0,     0,   431,   432,     0,     0,     0,   479,   433,   434,
     435,   436,   437,   438,   439,     0,     0,     0,     0,     0,
       0,     0,   401,   402,     0,   440,   441,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   401,   402,     0,     0,     0,
     447,   448,   449,   406,   450,   451,   452,   453,   454,   455,
       0,     0,     0,     0,     0,     0,   456,   457,   292,   293,
     294,     0,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,     0,   311,
     448,   449,   406,   450,   451,   452,   453,   454,   455,     0,
       0,     0,     0,     0,     0,   456,   457
};

static const yytype_int16 yycheck[] =
{
       9,    46,    47,    48,    49,   517,    10,    11,    12,    30,
      30,    15,    16,    17,    18,    19,    20,    21,   484,    30,
      24,    25,    26,    27,    28,    29,    55,    30,    40,   170,
      34,    37,    37,    62,    75,    37,    37,    14,    42,    14,
      40,   118,    55,   120,    89,    90,    50,    32,    29,    62,
      30,    13,    39,    30,    39,    30,    37,    20,     3,     4,
      40,     6,    43,    67,    33,    44,    28,    29,     3,     4,
      15,    34,    34,    44,     3,     4,    45,     6,     7,     8,
      43,    93,   123,    96,    29,    45,    15,   116,    30,    38,
      35,    40,    57,   122,    29,    38,    37,    40,    40,    62,
      29,    36,   115,   116,    33,    34,    35,    36,    37,   122,
      62,     3,     4,    52,    43,    44,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     3,     4,   128,     6,
      33,    68,    24,    25,     7,    33,    29,    38,    15,    40,
     100,    29,    45,     3,     4,    62,     6,    45,    77,    44,
     171,   171,    29,    44,   114,    15,    29,    75,    35,   119,
     171,    34,   122,    75,   676,   677,   172,   172,   171,    29,
     172,   172,    16,    17,    29,    35,   121,    38,    44,    40,
      24,    25,     3,     4,    78,     6,    44,     3,     4,    76,
       6,     3,     4,   122,    15,     7,     8,    44,    75,    15,
      26,    27,    77,    15,    30,    79,     7,    79,    29,    79,
     214,   215,   216,    29,    35,   219,   220,    29,    52,    35,
      26,    27,    34,    44,   228,   229,   230,   231,    29,   121,
      44,    52,    44,    34,    26,    27,    52,     3,     4,    29,
       6,     7,     8,    44,   248,   249,   250,    37,    37,    15,
     254,   255,   256,    43,    44,   259,    26,    27,    14,    15,
      30,   121,    37,    29,   117,   269,   311,    33,    34,    35,
      36,    37,   276,    37,   236,   117,   238,    43,    44,    28,
      29,    62,     3,     4,    44,   330,    37,   250,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    37,   268,   269,    29,     3,
       4,    77,   778,     7,     8,    36,     7,    24,    25,    37,
     324,    15,    37,    44,   328,     3,     4,   290,     6,     7,
       8,    26,    27,    37,   297,    29,    37,    15,    29,    37,
      37,     3,     4,    34,   353,    37,   355,   309,   310,    37,
      44,    29,   356,    44,    40,    33,    34,    35,    36,    37,
      93,   324,   324,    14,    15,    43,    44,    29,    97,    10,
      11,    99,    38,    38,    36,    26,    27,    14,   133,    20,
      38,    14,    44,    24,    25,    26,    27,    28,    29,    37,
      30,    30,    30,    34,   357,    29,   359,    44,    55,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,    37,     3,     4,
      37,   117,    44,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    41,    41,    44,    37,   399,   400,    24,
      25,    44,    55,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,     3,     4,    75,   117,     3,     4,
      37,     6,     7,     8,    44,    80,    44,   430,     3,     4,
      15,   516,    28,    37,    37,    37,     3,     4,    37,     6,
      29,    32,    10,    11,    29,    13,    14,    36,    15,    44,
      35,    36,    44,    21,    29,    44,    44,    37,    37,    44,
      37,    36,    29,   465,   466,   468,    34,   469,    35,    44,
      29,    37,     3,     4,    37,     6,    37,   521,    29,     3,
       4,    37,   526,   532,    15,     3,     4,    44,     6,     7,
       8,    44,    44,   537,   543,   539,   121,    15,    29,     3,
       4,    44,    44,   547,    35,    29,    44,    44,   120,    30,
      44,    29,    36,    44,   558,    37,   519,    35,   521,   521,
      44,    31,   571,   120,    37,    29,    44,    14,    15,    16,
      17,    28,    36,   214,   215,    28,    37,    24,    25,   220,
      44,   125,     3,     4,   547,   547,    29,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    29,   173,   173,
     173,    27,   647,    24,    25,     3,     4,   248,   249,   250,
      27,     9,    10,    11,    12,    13,    14,    15,   259,   173,
      44,   120,    31,    99,     3,     4,    37,    37,   269,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    28,
      31,    45,    29,    37,   118,    24,    25,    37,    30,    44,
      30,   655,   293,   294,   295,   296,   297,   298,   662,    44,
      31,   665,     9,    10,    11,    12,    13,    14,    15,   127,
     171,   133,    39,   682,   683,    30,   685,   118,    41,    26,
      27,    45,    30,   324,    29,    38,   214,   215,   692,   217,
     218,   219,   220,     3,     4,    87,     6,    37,    32,    37,
     121,    44,   665,   665,    31,    15,   234,   235,   236,   237,
     238,     3,     4,   241,     6,    44,    44,    37,    32,    29,
      38,    89,   767,    15,    30,    35,   254,   255,   256,    28,
      41,    88,   120,    41,    44,    32,    32,    29,   747,    30,
      41,    30,   121,    35,   128,    32,   129,    86,   757,    30,
       1,   744,    44,    -1,   794,    34,    34,   802,    34,   753,
     738,   806,   738,   772,   738,     3,     4,   740,     6,    -1,
      -1,    -1,   781,   782,   783,    -1,    -1,    15,    -1,    -1,
      -1,    -1,   423,   424,   425,   426,   427,   428,   429,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    35,     3,     4,
      -1,     6,   811,    -1,    -1,   814,    44,   816,   817,    -1,
      15,     3,     4,    -1,     6,    -1,    -1,   458,   459,   460,
     461,   462,   463,    15,    29,    -1,   835,    -1,   837,   838,
      35,    -1,   841,     3,     4,    -1,     6,    29,    -1,    44,
      -1,     3,     4,    35,     6,    15,     3,     4,    -1,     6,
      -1,    -1,    44,    15,    -1,    -1,    -1,    -1,    15,    29,
      -1,    -1,    -1,     3,     4,    35,     6,    29,    -1,    -1,
      -1,    -1,    29,    35,    44,    15,    -1,    -1,    35,    -1,
     521,    -1,    44,    -1,    -1,    -1,    -1,    44,    -1,    29,
       3,     4,    -1,     6,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    44,   433,   434,   435,   436,   437,
     438,   439,   440,   441,    -1,    -1,    29,     3,     4,    -1,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      -1,    44,     0,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    31,    -1,    33,    34,    35,    36,    37,
      38,   612,   613,   614,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    60,    61,    -1,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,   116,    -1,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    31,    -1,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    53,    54,    -1,    56,    -1,    58,    59,
      60,    61,    -1,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    91,    92,    -1,    94,    95,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,    -1,    -1,   119,
      -1,    -1,   122,    -1,   124,    -1,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       3,     4,    -1,     6,     3,     4,    -1,     6,     3,     4,
      -1,     6,    15,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      15,     3,     4,    -1,     6,    -1,    29,    -1,    -1,    -1,
      29,    -1,    35,    15,    29,    -1,    35,    -1,    -1,    -1,
      35,    44,    -1,     3,     4,    44,     6,    29,    -1,    44,
      -1,     3,     4,    35,     6,    15,     3,     4,    -1,     6,
      -1,    -1,    44,    15,     3,     4,    -1,     6,    15,    29,
      -1,    -1,    -1,    -1,    -1,    35,    15,    29,    -1,    -1,
      -1,    -1,    29,    35,    44,    -1,    -1,    -1,    35,    -1,
      29,    -1,    44,    -1,    -1,    -1,    35,    44,     3,     4,
      -1,     6,     7,    -1,    -1,    44,    -1,    -1,     3,     4,
      15,     6,     7,     9,    10,    11,    12,    13,    14,    15,
      15,    -1,    -1,    -1,    29,     3,     4,    -1,     6,    34,
      35,    36,    37,    -1,    29,    -1,    -1,    15,    43,    34,
      35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      -1,    -1,     8,     9,    10,    43,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,     3,     4,    -1,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    15,     3,     4,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,     3,     4,    -1,    35,
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
      -1,    -1,     3,     4,    -1,    -1,    -1,    30,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    26,    27,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     3,     4,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   175,     0,     1,   176,   177,   178,   179,   170,    39,
       3,     4,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    29,    31,    33,    34,    35,    36,
      37,    38,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    53,    54,    56,    58,    59,    60,    61,    63,
      64,    65,    66,    67,    69,    70,    71,    72,    73,    74,
      81,    82,    83,    84,    85,    91,    92,    94,    95,    98,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   119,   122,   124,   126,
     130,   131,   132,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   180,
     181,   182,   183,   184,   185,   186,   196,   216,   217,   223,
     224,   229,   230,   236,   243,   245,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   267,   268,   269,   274,   278,   279,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   324,   325,   180,     3,     4,     6,     7,     8,    15,
      29,    44,   251,   252,   254,   251,   252,   254,     3,     4,
      15,    29,    44,   251,     3,     4,     7,    15,    29,   250,
     254,    29,   254,   251,   251,   251,   251,   251,     3,     4,
      29,   251,   252,   253,     3,     4,    29,   251,   254,    29,
     251,   252,   251,   252,   251,   252,   251,   252,     7,    29,
     250,   251,   252,   250,   251,   252,     6,    33,    44,   249,
     250,   251,   252,   253,   254,   256,   257,   246,    44,   251,
      29,   253,     8,     9,    10,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    29,    41,    44,    77,   122,   248,    77,   248,   248,
     248,   251,    37,    52,    55,    62,   116,   122,    57,    62,
      29,    29,   253,    68,    62,    75,   251,    44,    44,    75,
      75,   123,    75,    55,    62,    96,   115,   116,   122,    29,
      44,    44,    76,   237,    44,   244,    77,    78,    79,    79,
      79,   248,   248,    52,    44,    37,   117,   117,    37,    37,
      62,    33,    45,    44,    37,   172,    37,   172,    37,    37,
      37,    37,    37,    37,   172,    37,   172,    37,    37,    37,
      37,    37,    40,    93,   219,    97,    99,   218,    38,    26,
      27,     3,     4,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     3,     4,     9,    10,    11,    12,    13,    14,    15,
      14,     3,     4,     9,    10,    11,    12,    13,    14,    15,
      26,    27,    38,   133,    38,   251,   252,     8,     9,    10,
      12,    13,    14,    15,    16,    17,    24,    25,     9,    10,
      12,    13,    14,    15,   250,    26,    27,   253,    14,    29,
      30,    30,    18,    19,    20,    21,    22,    23,    30,    30,
      30,    30,    30,    30,   178,   247,    29,   251,   251,   252,
     251,   252,   251,   252,   251,   252,   251,   252,   253,   251,
     252,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   250,   250,   248,   322,   323,    28,    29,    37,    37,
      44,    29,   250,   251,   252,   253,    55,   117,    37,    44,
     251,   248,   201,    44,    41,    41,    44,    75,    44,    55,
      37,   117,    37,   187,    44,   180,   180,    52,   251,   253,
      80,   253,    44,    28,    37,    37,    37,   118,   120,    37,
      44,    44,    44,    37,    37,    37,    37,    37,    37,   295,
      29,   225,    29,    44,   250,    44,   250,    44,   251,    44,
     251,    44,   251,   251,    44,   251,    44,   251,    44,   251,
      44,   251,    44,   251,    44,   251,    44,   251,    44,   251,
      44,   251,    44,   251,    44,   251,    44,   251,    44,   251,
      44,   251,     3,     4,    29,    44,   252,    44,   252,   252,
      44,   252,    44,   252,    44,   252,    44,   252,    44,   253,
     254,   254,   254,   254,   254,   254,   254,   254,   254,    44,
     247,    32,    33,    45,   270,   272,    30,   171,   248,   270,
     253,    44,    52,   251,    37,   120,    30,   180,   251,    44,
     251,    37,   120,   180,   238,    29,   250,   251,   253,    31,
      28,    28,    37,   125,   251,    37,    29,    29,   173,   173,
     173,   173,   296,   220,   180,   231,   280,    44,    30,   171,
     248,    30,   120,   121,   251,    31,    30,   121,   251,    30,
      99,   264,    37,    37,    28,   121,    33,    45,   270,   271,
     273,   270,   180,   180,    93,   180,    31,   281,    45,   251,
     121,   197,   202,   121,   188,    29,    37,   266,   118,    37,
      44,   171,    30,    30,   297,   221,   226,    38,   133,   282,
     283,    44,   121,   205,   206,    31,   127,   239,    39,   265,
     118,    45,   275,   276,    41,    30,    29,   232,    45,   100,
     122,   260,   261,   262,   284,    38,   282,    87,   198,   207,
     207,   203,   189,   180,    37,    32,    37,    44,    31,   277,
     277,   298,   222,   227,   180,    44,    44,    37,    38,    32,
     248,    89,   209,   211,   212,   180,    38,   247,   180,   180,
     180,    38,    28,   208,    41,   199,    88,   204,   213,   213,
     190,   240,    32,   228,   233,   248,    41,   210,   200,   248,
      32,   128,   180,    30,   180,   180,   180,    32,   214,   191,
      38,   234,    41,    86,   193,   241,    30,   215,   194,   192,
     180,   235,   180,   180,   129,   195,   242,   180,   128,    30
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
#line 1177 "pnfhra.ypp"
    {  ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 1180 "pnfhra.ypp"
    {
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 1184 "pnfhra.ypp"
    { yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 1187 "pnfhra.ypp"
    {
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 1193 "pnfhra.ypp"
    { ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 1194 "pnfhra.ypp"
    { conprint("VOID TVOID 0V\n"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 1195 "pnfhra.ypp"
    { ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 1196 "pnfhra.ypp"
    { ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 1197 "pnfhra.ypp"
    { ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 1198 "pnfhra.ypp"
    { ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 1199 "pnfhra.ypp"
    {
				   ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 1206 "pnfhra.ypp"
    {
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 1211 "pnfhra.ypp"
    {
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 1216 "pnfhra.ypp"
    {
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 1221 "pnfhra.ypp"
    {
			 conprint("%s:\n", (yyvsp[(1) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 1225 "pnfhra.ypp"
    {
			 conprint("sub %s:\n", (yyvsp[(1) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1229 "pnfhra.ypp"
    {
			 conprint("event %s:\n", (yyvsp[(1) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 1235 "pnfhra.ypp"
    {
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 1238 "pnfhra.ypp"
    {
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1241 "pnfhra.ypp"
    {
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1246 "pnfhra.ypp"
    {
			 conprint("if ({\n");
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1251 "pnfhra.ypp"
    {
			 conprint ("\n})");
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1255 "pnfhra.ypp"
    {
			 conprint(" then\n");			 
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1259 "pnfhra.ypp"
    {
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1262 "pnfhra.ypp"
    {
			 conprint("\nendif\n");
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1266 "pnfhra.ypp"
    {
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 1269 "pnfhra.ypp"
    {
			 conprint("\ndoneif\n");
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1275 "pnfhra.ypp"
    {
			 conprint("\nelse\n");
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 1280 "pnfhra.ypp"
    {
			 conprint("\nendif\n");
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1289 "pnfhra.ypp"
    {
			 conprint("switch (%s)\n{", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1293 "pnfhra.ypp"
    {

			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1297 "pnfhra.ypp"
    {
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1299 "pnfhra.ypp"
    {

			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1303 "pnfhra.ypp"
    {
			;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1306 "pnfhra.ypp"
    {
			 conprint("cswitch (");
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1311 "pnfhra.ypp"
    {
			 conprint(")\n");
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1315 "pnfhra.ypp"
    {
			 conprint("{\n");
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1319 "pnfhra.ypp"
    {
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1322 "pnfhra.ypp"
    {
			 conprint("}\n");
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1327 "pnfhra.ypp"
    {
			;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1334 "pnfhra.ypp"
    {
			 conprint("case %s:\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1338 "pnfhra.ypp"
    {
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1343 "pnfhra.ypp"
    {
			 conprint("default:\n");
			;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1347 "pnfhra.ypp"
    {

			;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1352 "pnfhra.ypp"
    {
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1359 "pnfhra.ypp"
    {
			 conprint("ccase %s:\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1363 "pnfhra.ypp"
    {
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1366 "pnfhra.ypp"
    {
			;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1380 "pnfhra.ypp"
    {
			;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1383 "pnfhra.ypp"
    {
			;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1386 "pnfhra.ypp"
    {
			;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1389 "pnfhra.ypp"
    {
			;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1392 "pnfhra.ypp"
    {
			;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1395 "pnfhra.ypp"
    {
			;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1397 "pnfhra.ypp"
    {
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1402 "pnfhra.ypp"
    {
			 conprint("while (");
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1406 "pnfhra.ypp"
    {
			;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1409 "pnfhra.ypp"
    {
			 conprint(")\n");
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1413 "pnfhra.ypp"
    {
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1417 "pnfhra.ypp"
    {
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1420 "pnfhra.ypp"
    {
			 conprint("dowhile\n");
			;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1425 "pnfhra.ypp"
    {
			 conprint("while");
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1429 "pnfhra.ypp"
    {
			 conprint("(");
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1433 "pnfhra.ypp"
    {
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1436 "pnfhra.ypp"
    {
			 conprint(")");
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1441 "pnfhra.ypp"
    {
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1444 "pnfhra.ypp"
    {
			 conprint("for (");
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1449 "pnfhra.ypp"
    {
			 conprint ("; ");
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1454 "pnfhra.ypp"
    {
			 conprint("; ");
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1458 "pnfhra.ypp"
    {
			;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1461 "pnfhra.ypp"
    {
			 conprint(")\n");
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1465 "pnfhra.ypp"
    {
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1470 "pnfhra.ypp"
    {
			 conprint("dofor\n");
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1474 "pnfhra.ypp"
    {
			;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1477 "pnfhra.ypp"
    {
			 conprint("for (");
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1482 "pnfhra.ypp"
    {
			 conprint("; ");
			;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1487 "pnfhra.ypp"
    {
			 conprint("; ");
			;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1491 "pnfhra.ypp"
    {
			;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1494 "pnfhra.ypp"
    {
			 conprint(")");
			;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1500 "pnfhra.ypp"
    {
			 conprint("forever\n");
			;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1504 "pnfhra.ypp"
    {
			;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1508 "pnfhra.ypp"
    {
			 conprint("{\n");
			;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1513 "pnfhra.ypp"
    {
			 conprint("}\n");
			;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1519 "pnfhra.ypp"
    {
			;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1522 "pnfhra.ypp"
    {
			;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1526 "pnfhra.ypp"
    { exptype = TVOID; ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1528 "pnfhra.ypp"
    {
		 exptype = TBOOLEAN;		 
		;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1531 "pnfhra.ypp"
    { exptype = TNUMBER; ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1532 "pnfhra.ypp"
    { exptype = TCHARACTER; ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1533 "pnfhra.ypp"
    { exptype = TSTRING; ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1535 "pnfhra.ypp"
    {		 
		 exptype = (PNF_Type_Enum)(yyval).getType();
		;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1538 "pnfhra.ypp"
    { exptype = TBOOLEAN; ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1539 "pnfhra.ypp"
    { exptype = (PNF_Type_Enum)(yyval).getType(); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1540 "pnfhra.ypp"
    { exptype = (PNF_Type_Enum)(yyval).getType(); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1545 "pnfhra.ypp"
    {
		 	 PNF_String s("0V");
			 (yyval).put(s);
			;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1550 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1556 "pnfhra.ypp"
    { 
			 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1560 "pnfhra.ypp"
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

  case 114:

/* Line 1455 of yacc.c  */
#line 1574 "pnfhra.ypp"
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

  case 115:

/* Line 1455 of yacc.c  */
#line 1590 "pnfhra.ypp"
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

  case 116:

/* Line 1455 of yacc.c  */
#line 1606 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1612 "pnfhra.ypp"
    {
			 PNF_Number n(yylval.to_number().get());
			 (yyval).put(n);
			;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1617 "pnfhra.ypp"
    {
			 double d2 = (yyvsp[(2) - (3)]).to_number().get();
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d3 = d1 + d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1625 "pnfhra.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().sub(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1631 "pnfhra.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mul(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1637 "pnfhra.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().div(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1643 "pnfhra.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().mod(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1649 "pnfhra.ypp"
    {
			 char * str = "-";
			 strcat(str, (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			 PNF_String s(str);
			 PNF_Variable v(s);
			 (yyval) = v;
			;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1657 "pnfhra.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().pow(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1663 "pnfhra.ypp"
    {
			 double d = (yyvsp[(2) - (3)]).to_number().get();
			 (yyvsp[(1) - (3)]).to_number().root(d);
			 (yyval) = (yyvsp[(1) - (3)]);
			;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1669 "pnfhra.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1675 "pnfhra.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1681 "pnfhra.ypp"
    {
			 PNF_Number n((yyvsp[(2) - (2)]).to_number().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1687 "pnfhra.ypp"
    {
			 PNF_Number n((yyvsp[(1) - (2)]).to_number().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1693 "pnfhra.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 & d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1701 "pnfhra.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 | d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1709 "pnfhra.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 ^ d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1717 "pnfhra.ypp"
    {
			 int d = (int)(yyvsp[(2) - (2)]).to_number().get();
			 d = ~d;
			 PNF_Number n(d);
			 (yyval).put(n);
			;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1724 "pnfhra.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 << d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1732 "pnfhra.ypp"
    {
			 int d1 = (int)(yyvsp[(1) - (3)]).to_number().get();
			 int d2 = (int)(yyvsp[(3) - (3)]).to_number().get();
			 int d3 = d1 >> d2;
			 PNF_Number n(d3);
			 (yyval).put(n);
			;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1740 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1746 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1750 "pnfhra.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.add((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1757 "pnfhra.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.sub((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1764 "pnfhra.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mul((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1771 "pnfhra.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.div((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1778 "pnfhra.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c(d);
			 c.mod((yyvsp[(3) - (3)]).to_character().get());
			 (yyval).put(c);
			;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1785 "pnfhra.ypp"
    {
			 char d = (yyvsp[(3) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(1) - (3)]).to_character());
			 c.pow(d);
			 (yyval).put(c);
			;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1792 "pnfhra.ypp"
    {
			 char d = (yyvsp[(1) - (3)]).to_character().get();
			 PNF_Character c((yyvsp[(3) - (3)]).to_character());
			 c.root(d);
			 (yyval).put(c);
			;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1799 "pnfhra.ypp"
    {
			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.inc(1);
			 (yyval).put(n);
			;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1805 "pnfhra.ypp"
    {
 			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.inc(1);
			;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1811 "pnfhra.ypp"
    {
 			 PNF_Character n((yyvsp[(2) - (2)]).to_character().get());
			 n.dec(1);
			 (yyval).put(n);
			;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1817 "pnfhra.ypp"
    {
			 PNF_Character n((yyvsp[(1) - (2)]).to_character().get());
			 (yyval).put(n);
			 n.dec(1);
			;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1823 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1829 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1833 "pnfhra.ypp"
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

  case 152:

/* Line 1455 of yacc.c  */
#line 1858 "pnfhra.ypp"
    {
			 String str = (yyvsp[(2) - (2)]).to_string().get();
			 String str2 = "\"" + str + "\"";
			 PNF_String s(str2);
			 (yyval).put(s);
			;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1865 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1871 "pnfhra.ypp"
    {
			 bool declared = false;
			 for (unsigned long i = 0; i < varTable[scope].length(); ++i)
			 {
			  if (strcmp(varTable[scope][i].name().getString().c_str(), (yyvsp[(1) - (1)]).to_string().get().getString().c_str()) == 0)
			  {
			   declared = true;
			   (yyval) = varTable[scope][i].value();			   			  }
			 }

			 if (!declared)
			 {
			  String str = (yyvsp[(1) - (1)]).to_string().get();
			  str += " was not declared.";
			  yyerror(str.getString().c_str());
			 }
			;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1889 "pnfhra.ypp"
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

  case 156:

/* Line 1455 of yacc.c  */
#line 1929 "pnfhra.ypp"
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

  case 157:

/* Line 1455 of yacc.c  */
#line 1966 "pnfhra.ypp"
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

  case 158:

/* Line 1455 of yacc.c  */
#line 2043 "pnfhra.ypp"
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

  case 159:

/* Line 1455 of yacc.c  */
#line 2122 "pnfhra.ypp"
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

  case 160:

/* Line 1455 of yacc.c  */
#line 2202 "pnfhra.ypp"
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

  case 161:

/* Line 1455 of yacc.c  */
#line 2240 "pnfhra.ypp"
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

  case 162:

/* Line 1455 of yacc.c  */
#line 2278 "pnfhra.ypp"
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

  case 163:

/* Line 1455 of yacc.c  */
#line 2316 "pnfhra.ypp"
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

  case 164:

/* Line 1455 of yacc.c  */
#line 2354 "pnfhra.ypp"
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

  case 165:

/* Line 1455 of yacc.c  */
#line 2367 "pnfhra.ypp"
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

  case 166:

/* Line 1455 of yacc.c  */
#line 2405 "pnfhra.ypp"
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

  case 167:

/* Line 1455 of yacc.c  */
#line 2443 "pnfhra.ypp"
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

  case 168:

/* Line 1455 of yacc.c  */
#line 2471 "pnfhra.ypp"
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

  case 169:

/* Line 1455 of yacc.c  */
#line 2499 "pnfhra.ypp"
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

  case 170:

/* Line 1455 of yacc.c  */
#line 2527 "pnfhra.ypp"
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

  case 171:

/* Line 1455 of yacc.c  */
#line 2555 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 2561 "pnfhra.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 == d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);
			;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 2569 "pnfhra.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 != d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);
			;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 2577 "pnfhra.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 < d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);
			;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 2585 "pnfhra.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 > d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);
			;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 2593 "pnfhra.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 <= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);
			;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 2601 "pnfhra.ypp"
    {
			 double d1 = (yyvsp[(1) - (3)]).to_number().get();
			 double d2 = (yyvsp[(3) - (3)]).to_number().get();
			 bool b = d1 >= d2;
			 PNF_Boolean b2(b);
			 (yyval).put(b2);
			;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 2612 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 2616 "pnfhra.ypp"
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
			;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 2663 "pnfhra.ypp"
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
			;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 2710 "pnfhra.ypp"
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
			;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 2757 "pnfhra.ypp"
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
			;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 2804 "pnfhra.ypp"
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
			;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 2844 "pnfhra.ypp"
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
			;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 2884 "pnfhra.ypp"
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
                	;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 2924 "pnfhra.ypp"
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
                	;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 2964 "pnfhra.ypp"
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
                	;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 3004 "pnfhra.ypp"
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
                	;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 3044 "pnfhra.ypp"
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
			;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 3084 "pnfhra.ypp"
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
                	;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 3124 "pnfhra.ypp"
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
                	;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 3164 "pnfhra.ypp"
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
                	;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 3204 "pnfhra.ypp"
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
                	;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 3244 "pnfhra.ypp"
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
                	;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 3284 "pnfhra.ypp"
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
                	;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 3324 "pnfhra.ypp"
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
                	;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 3364 "pnfhra.ypp"
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
                	;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 3404 "pnfhra.ypp"
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
                	;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 3444 "pnfhra.ypp"
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
                	;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 3484 "pnfhra.ypp"
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
                	;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 3524 "pnfhra.ypp"
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
                	;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 3564 "pnfhra.ypp"
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
                	;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 3604 "pnfhra.ypp"
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
                	;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 3644 "pnfhra.ypp"
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
                	;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 3684 "pnfhra.ypp"
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
                	;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 3724 "pnfhra.ypp"
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
                	;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 3764 "pnfhra.ypp"
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
                	;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 3826 "pnfhra.ypp"
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
                	;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 3888 "pnfhra.ypp"
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
			;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 3931 "pnfhra.ypp"
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
			;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 3974 "pnfhra.ypp"
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
			;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 4017 "pnfhra.ypp"
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
			;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 4060 "pnfhra.ypp"
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
			;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 4103 "pnfhra.ypp"
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
			;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 4146 "pnfhra.ypp"
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
			;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 4189 "pnfhra.ypp"
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
			;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 4232 "pnfhra.ypp"
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
			;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 4275 "pnfhra.ypp"
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
			;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 4318 "pnfhra.ypp"
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
			;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 4361 "pnfhra.ypp"
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
			;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 4404 "pnfhra.ypp"
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
			;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 4447 "pnfhra.ypp"
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
			;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 4490 "pnfhra.ypp"
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
			;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 4533 "pnfhra.ypp"
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
			;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 4576 "pnfhra.ypp"
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
			;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 4619 "pnfhra.ypp"
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
			;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 4662 "pnfhra.ypp"
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
			;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 4697 "pnfhra.ypp"
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
			;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 4740 "pnfhra.ypp"
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
			;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 4783 "pnfhra.ypp"
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
			;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 4826 "pnfhra.ypp"
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
			;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 4875 "pnfhra.ypp"
    {
			;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 4878 "pnfhra.ypp"
    {
			;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 4881 "pnfhra.ypp"
    {
			;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 4884 "pnfhra.ypp"
    {
			;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 4887 "pnfhra.ypp"
    {
			;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 4890 "pnfhra.ypp"
    {
			;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 4893 "pnfhra.ypp"
    {
			;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 4899 "pnfhra.ypp"
    {
			 Var v;
			 v.name((yyvsp[(2) - (2)]).to_string().get());
			 varTable[scope][varTable[scope].length() - 1] = v;

			 varTable[scope].insert();

			 conprint("var %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 4909 "pnfhra.ypp"
    {
			 Var v;
			 v.name((yyvsp[(2) - (4)]).to_string().get());
			 v.value((yyvsp[(4) - (4)]));
			 varTable[scope][varTable[scope].length() - 1] = v;

			 switch ((yyvsp[(4) - (4)]).getType())
			 {
			  case TVOID:
			   conprint("var %s = %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			   break;

			  case TBOOLEAN:
			   conprint("var %s = %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			   break;

			  case TNUMBER:
			   conprint("var %s = %g;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(4) - (4)]).to_number().get());
			   break;

			  case TCHARACTER:
			   conprint("var %s = %c;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(4) - (4)]).to_character().get());
			   break;

			  case TSTRING:
			   conprint("var %s = %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			   break;

			  default:
			   yyerror("Bad type.");
			 }

			 varTable[scope].insert();
			;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 4944 "pnfhra.ypp"
    {
			 conprint("fvar %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 4948 "pnfhra.ypp"
    {
			;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 4951 "pnfhra.ypp"
    {
			;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 4954 "pnfhra.ypp"
    {
			;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 4959 "pnfhra.ypp"
    {
			 Var v;
			 v.name((yyvsp[(2) - (5)]).to_string().get());
			 v.value((yyvsp[(5) - (5)]));
			 varTable[scope][varTable.length() - 1] = v;

			 conprint("enumv %s %s = %s\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str(), (yyvsp[(3) - (5)]).to_string().get().getString().c_str(), 
				  (yyvsp[(5) - (5)]).to_string().get().getString().c_str());
			;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 4971 "pnfhra.ypp"
    {
			 Var v;
			 v.name((yyvsp[(3) - (6)]).to_string().get());
			 v.value((yyvsp[(6) - (6)]));
			 varTable[scope][varTable.length() - 1] = v;

			 conprint("rangev %s %s %s = %s\n", (yyvsp[(2) - (6)]).to_string().get().getString().c_str(), (yyvsp[(3) - (6)]).to_string().get().getString().c_str(), 
				  (yyvsp[(4) - (6)]).to_string().get().getString().c_str(), (yyvsp[(6) - (6)]).to_string().get().getString().c_str());
			;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 4981 "pnfhra.ypp"
    {
			 Var v;
			 v.name((yyvsp[(2) - (4)]).to_string().get());
			 v.value((yyvsp[(4) - (4)]));
			 varTable[scope][varTable.length() - 1] = v;
			
			 conprint("rangev %s %s %s\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), 
				  (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 4993 "pnfhra.ypp"
    {
			 Var v;
			 v.name((yyvsp[(2) - (5)]).to_string().get());
			 PNF_String str((char *)"{array}");
			 v.value(str);
			 varTable[scope][varTable.length() - 1] = v;

			 conprint("array %s[%s]\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str(), (yyvsp[(4) - (5)]).to_string().get().getString().c_str());
			;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 5005 "pnfhra.ypp"
    {
			 conprint("enum %s = {\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 5009 "pnfhra.ypp"
    {
			;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 5012 "pnfhra.ypp"
    {
			 conprint("}\n");
			;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 5018 "pnfhra.ypp"
    {
			 conprint("%s\n", (yyvsp[(1) - (1)]).to_string().get().getString().c_str());
			;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 5022 "pnfhra.ypp"
    {
			 conprint("%s, %s\n", (yyvsp[(1) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 5028 "pnfhra.ypp"
    {
			 conprint("range %s %s = %s..%s\n", (yyvsp[(2) - (8)]).to_string().get().getString().c_str(), (yyvsp[(3) - (8)]).to_string().get().getString().c_str(), 
				  (yyvsp[(5) - (8)]).to_string().get().getString().c_str(), (yyvsp[(8) - (8)]).to_string().get().getString().c_str());
			;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 5035 "pnfhra.ypp"
    {
			 conprint("sub %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 5039 "pnfhra.ypp"
    {
			 conprint("event %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 5043 "pnfhra.ypp"
    {
			 conprint("label %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 5049 "pnfhra.ypp"
    {
			 Function f;
			 f.name((yyvsp[(2) - (5)]).to_string().get());
			 PNF_Void v;
			 PNF_Variable v2(v);
			 f.ret(v2);

			 for (unsigned long i = 0; i < paramcount; ++i)
                         {
			  String str = "";
			  str.from_long(i);
			  String str2 = "p";
			  str2 += str;

			  f.param(i, v2);
			  f.pname(i, str2);
			 }
			 paramcount = 0;
			 funcs.add_function(f);

			 conprint("subroutine %s;\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 conprint("var %s;\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 5073 "pnfhra.ypp"
    {
			 Function f;
			 f.name((yyvsp[(2) - (5)]).to_string().get());
			 PNF_Void v;
			 PNF_Variable v2(v);
			 f.ret(v2);

			 for (unsigned long i = 0; i < paramcount; ++i)
                         {
			  f.param(i, v2);
			  f.pname(i, (yyvsp[(4) - (5)]).to_string().get());
			 }
			 paramcount = 0;
			 funcs.add_function(f);
			 
			 conprint("subroutine %s;\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			 conprint("var %s;\n", (yyvsp[(2) - (5)]).to_string().get().getString().c_str());
			;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 5094 "pnfhra.ypp"
    {
			 ++paramcount;
			 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 5102 "pnfhra.ypp"
    {
			 ++paramcount2;
			;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 5109 "pnfhra.ypp"
    {
			 (yyval) = (yyvsp[(2) - (2)]);
			;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 5116 "pnfhra.ypp"
    {
			 conprint("var %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());			 
			;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 5123 "pnfhra.ypp"
    {
			 Function f;
			 f.name((yyvsp[(3) - (6)]).to_string().get());
			 PNF_Void v;
			 PNF_Variable v2(v);
			 f.ret(v2);

			 for (unsigned long i = 0; i < paramcount2; ++i)
                         {
			  f.param(i, v2);
			  			 }
			 paramcount2 = 0;

			 bool b = false;
			 funcs.find_duplicate(f, b);
			 if (b)
			  yyerror("Function mismatch.");

			 conprint("%s:\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 5144 "pnfhra.ypp"
    {
			;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 5147 "pnfhra.ypp"
    {
			 Function f;
			 f.name((yyvsp[(3) - (6)]).to_string().get());
			 PNF_Void v;
			 PNF_Variable v2(v);
			 f.ret(v2);

			 for (unsigned long i = 0; i < paramcount2; ++i)
                         {
			  f.param(i, v2);
			 }
			 paramcount2 = 0;

			 bool b = false;
			 funcs.find_duplicate(f, b);
			 if (b)
			  yyerror("Function mismatch.");
			 conprint("%s:\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str());
			;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 5167 "pnfhra.ypp"
    {
			;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 5176 "pnfhra.ypp"
    {	 
   			;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 5179 "pnfhra.ypp"
    {
			 structs.insert();

			 String str = yytext;
			 cout << str << endl;
			 structs[struct_counter].name(str);
			 struct_counter++;
			;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 5188 "pnfhra.ypp"
    {
			 svarcounter = 0;
			;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 5197 "pnfhra.ypp"
    {
			
			;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 5201 "pnfhra.ypp"
    {
			 
			;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 5207 "pnfhra.ypp"
    {
			 cout << "a...\n";
			;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 5213 "pnfhra.ypp"
    {
			 Var v;
			 v.name((yyvsp[(2) - (2)]).to_string().get());
			 structs[struct_counter].var(svarcounter, v);
			 ++svarcounter;
			;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 5220 "pnfhra.ypp"
    {
			 Var v;
			 v.name((yyvsp[(2) - (4)]).to_string().get());
			 v.value((yyvsp[(4) - (4)]));
			 structs[struct_counter].var(svarcounter, v);
			 ++svarcounter;		
			;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 5228 "pnfhra.ypp"
    {
			 conprint("fvar %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 5232 "pnfhra.ypp"
    {
			;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 5235 "pnfhra.ypp"
    {
			;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 5238 "pnfhra.ypp"
    {
			;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 5243 "pnfhra.ypp"
    {
			 bool found = false;
			 unsigned long i;
			 for (i = 0; i < struct_counter; ++i)
			 {
			  cout << structs[i].name() << " " << (yyvsp[(2) - (3)]).to_string().get() << endl;
			  if (structs[i].name() == (yyvsp[(2) - (3)]).to_string().get())
			  {
			   found = true;
			   break;
			  }
			 }

			 if (found)
			 {
			  for (unsigned long j = 0; j < structs[i].vnumber(); ++j)
			  {
			   conprint((char *)"var %s %s = %s;\n", (char *)((char *)((yyvsp[(2) - (3)]).to_string().get() + (char *)"_").getString().c_str() +
				    (yyvsp[(3) - (3)]).to_string().get()).getString().c_str(),
				    (char *)structs[i].var(j).name().getString().c_str(),
				    (structs[i].var(j).value().to_string().get() == "") ? "0V" : 
				    (char *)structs[i].var(j).value().to_string().get().getString().c_str());
			  }
			 }
			;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 5271 "pnfhra.ypp"
    {
			;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 5274 "pnfhra.ypp"
    {
			;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 5277 "pnfhra.ypp"
    {
			;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 5280 "pnfhra.ypp"
    {
			;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 5283 "pnfhra.ypp"
    {
			;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 5286 "pnfhra.ypp"
    {
			;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 5289 "pnfhra.ypp"
    {
			;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 5292 "pnfhra.ypp"
    {
			;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 5295 "pnfhra.ypp"
    {
			;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 5298 "pnfhra.ypp"
    {
			;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 5301 "pnfhra.ypp"
    {
			;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 5304 "pnfhra.ypp"
    {
			;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 5307 "pnfhra.ypp"
    {
			;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 5310 "pnfhra.ypp"
    {
			;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 5313 "pnfhra.ypp"
    {
			;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 5316 "pnfhra.ypp"
    {
			;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 5319 "pnfhra.ypp"
    {
			;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 5322 "pnfhra.ypp"
    {
			;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 5325 "pnfhra.ypp"
    {
			;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 5328 "pnfhra.ypp"
    {
			;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 5331 "pnfhra.ypp"
    {
			;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 5334 "pnfhra.ypp"
    {
			;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 5337 "pnfhra.ypp"
    {
			;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 5340 "pnfhra.ypp"
    {
			;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 5343 "pnfhra.ypp"
    {
			;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 5346 "pnfhra.ypp"
    {
			;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 5349 "pnfhra.ypp"
    {
			;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 5352 "pnfhra.ypp"
    {
			;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 5355 "pnfhra.ypp"
    {
			;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 5361 "pnfhra.ypp"
    {
			 conprint("print;\n");
			;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 5365 "pnfhra.ypp"
    {
			 conprint("print %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 5369 "pnfhra.ypp"
    {
			 conprint("print %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 5373 "pnfhra.ypp"
    {
			 conprint("println;");
			;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 5377 "pnfhra.ypp"
    {
			 conprint("println %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 5381 "pnfhra.ypp"
    {
			 conprint("println %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 5385 "pnfhra.ypp"
    {
			 conprint("eprint;");
			;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 5389 "pnfhra.ypp"
    {
			 conprint("eprint %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 5393 "pnfhra.ypp"
    {
			 conprint("eprintln;");
			;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 5397 "pnfhra.ypp"
    {
			 conprint("eprintln %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 5401 "pnfhra.ypp"
    {
			 conprint("fprint;");
			;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 5405 "pnfhra.ypp"
    {
			 conprint("fprint %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 5409 "pnfhra.ypp"
    {
			 conprint("fprintln;");
			;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 5413 "pnfhra.ypp"
    {
			 conprint("fprintln %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 5417 "pnfhra.ypp"
    {
			 conprint("print array %s\n", (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 5424 "pnfhra.ypp"
    {
			 conprint("read %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 5428 "pnfhra.ypp"
    {
			 conprint("fread %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 5435 "pnfhra.ypp"
    {
			 conprint("end %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 5441 "pnfhra.ypp"
    {
			 conprint("asm %s %s %s\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), 
				  (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 5448 "pnfhra.ypp"
    {
			 conprint("load %s %s %g;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), (yyvsp[(4) - (4)]).to_number().get());
			;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 5452 "pnfhra.ypp"
    {
			 conprint("load %s %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 5456 "pnfhra.ypp"
    {
			 conprint("load %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 5460 "pnfhra.ypp"
    {
			 conprint("load %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_boolean().get().getString().c_str());
			;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 5464 "pnfhra.ypp"
    {
			 conprint("load %s %g;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_number().get());
			;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 5468 "pnfhra.ypp"
    {
			 conprint("load %s %c;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_character().get());
			;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 5472 "pnfhra.ypp"
    {
			 conprint("load %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 5476 "pnfhra.ypp"
    {
			 conprint("load %s %s %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), 
				  (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 5481 "pnfhra.ypp"
    {
			 conprint("load %s %s %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), 
				  (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 5486 "pnfhra.ypp"
    {
			 conprint("load %s %s %s[%g];\n", (yyvsp[(2) - (7)]).to_string().get().getString().c_str(), (yyvsp[(3) - (7)]).to_string().get().getString().c_str(), 
				  (yyvsp[(5) - (7)]).to_number().get());
			;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 5491 "pnfhra.ypp"
    {
			 conprint("load array %s[%g];\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str(), (yyvsp[(5) - (6)]).to_number().get());
			;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 5495 "pnfhra.ypp"
    {
			 conprint("load array %s[];\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 5501 "pnfhra.ypp"
    {
			 conprint("goto %s %g;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_number().get());
			;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 5505 "pnfhra.ypp"
    {
			 conprint("goto %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 5511 "pnfhra.ypp"
    {
			 conprint("+;\n");
			;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 5515 "pnfhra.ypp"
    {
			 conprint("+ %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 5519 "pnfhra.ypp"
    {
			 conprint("+ %c;\n", (yyvsp[(2) - (2)]).to_character().get());
			;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 5523 "pnfhra.ypp"
    {
			 conprint("+ %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 5527 "pnfhra.ypp"
    {
			 conprint("-;\n");
			;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 5531 "pnfhra.ypp"
    {
			 conprint("- %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 5535 "pnfhra.ypp"
    {
			 conprint("*;\n");
			;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 5539 "pnfhra.ypp"
    {
			 conprint("* %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 5543 "pnfhra.ypp"
    {
			 conprint("/;\n");
			;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 5547 "pnfhra.ypp"
    {
			 conprint("/ %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 5551 "pnfhra.ypp"
    {
			 conprint("%%;\n");
			;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 5555 "pnfhra.ypp"
    {
			 conprint("%% %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 5559 "pnfhra.ypp"
    {
			 conprint("^;\n");
			;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 5563 "pnfhra.ypp"
    {
			 conprint("^ %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 5567 "pnfhra.ypp"
    {
			 conprint("!^;\n");
			;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 5571 "pnfhra.ypp"
    {
			 conprint("!^ %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 5575 "pnfhra.ypp"
    {
			 conprint("++;\n");
			;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 5579 "pnfhra.ypp"
    {
			 conprint("--;\n");
			;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 5583 "pnfhra.ypp"
    {
			 conprint("&&;\n");
			;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 5587 "pnfhra.ypp"
    {
			 conprint("||;\n");
			;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 5591 "pnfhra.ypp"
    {
			 conprint("!;\n");
			;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 5595 "pnfhra.ypp"
    {
			 conprint("==;\n");
			;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 5599 "pnfhra.ypp"
    {
			 conprint("!=;\n");
			;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 5603 "pnfhra.ypp"
    {
			 conprint("<;\n");
			;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 5607 "pnfhra.ypp"
    {
			 conprint(">;\n");
			;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 5611 "pnfhra.ypp"
    {
			 conprint("<=;\n");
			;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 5615 "pnfhra.ypp"
    {
			 conprint(">=;\n");
			;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 5619 "pnfhra.ypp"
    {
			 conprint("== %s;\n", (yyvsp[(2) - (2)]).to_boolean().get().getString().c_str());
			;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 5623 "pnfhra.ypp"
    {
			 conprint("!= %s;\n", (yyvsp[(2) - (2)]).to_boolean().get().getString().c_str());
			;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 5627 "pnfhra.ypp"
    {
			 conprint("== %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 5631 "pnfhra.ypp"
    {
			 conprint("!= %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 5635 "pnfhra.ypp"
    {
			 conprint("< %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 5639 "pnfhra.ypp"
    {
			 conprint("> %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 5643 "pnfhra.ypp"
    {
			 conprint("<= %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 5647 "pnfhra.ypp"
    {
			 conprint(">= %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 5651 "pnfhra.ypp"
    {
			 conprint("== %c;\n", (yyvsp[(2) - (2)]).to_character().get());
			;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 5655 "pnfhra.ypp"
    {
			 conprint("!= %c;\n", (yyvsp[(2) - (2)]).to_character().get());
			;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 5659 "pnfhra.ypp"
    {
			 conprint("< %c;\n", (yyvsp[(2) - (2)]).to_character().get());
			;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 5663 "pnfhra.ypp"
    {
			 conprint("> %c;\n", (yyvsp[(2) - (2)]).to_character().get());
			;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 5667 "pnfhra.ypp"
    {
			 conprint("<= %c;\n", (yyvsp[(2) - (2)]).to_character().get());
			;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 5671 "pnfhra.ypp"
    {
			 conprint(">= %c;\n", (yyvsp[(2) - (2)]).to_character().get());
			;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 5675 "pnfhra.ypp"
    {
			 conprint("&;\n");
			;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 5679 "pnfhra.ypp"
    {
			 conprint("|;\n");
			;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 5683 "pnfhra.ypp"
    {
			 conprint("^|;\n");
			;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 5687 "pnfhra.ypp"
    {
			 conprint("~;\n");
			;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 5691 "pnfhra.ypp"
    {
			 conprint("<<;\n");
			;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 5695 "pnfhra.ypp"
    {
			 conprint(">>;\n");
			;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 5699 "pnfhra.ypp"
    {
			 conprint("\n;\n");
			;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 5707 "pnfhra.ypp"
    {
			 conprint("? ");
			;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 5710 "pnfhra.ypp"
    {
			;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 5713 "pnfhra.ypp"
    {
			;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 5716 "pnfhra.ypp"
    {
			 conprint(": ");
			;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 5720 "pnfhra.ypp"
    {
			;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 5725 "pnfhra.ypp"
    {
			 conprint("st;\n");
			;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 5731 "pnfhra.ypp"
    {
			 conprint("push;\n");
			;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 5735 "pnfhra.ypp"
    {
			 conprint("pop;\n");
			;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 5741 "pnfhra.ypp"
    {
			 conprint("typeof %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 5747 "pnfhra.ypp"
    {
			 conprint("atoc;\n");
			;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 5751 "pnfhra.ypp"
    {
			 conprint("atosp;\n");
			;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 5755 "pnfhra.ypp"
    {
			 conprint("sptoa;\n");
			;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 5759 "pnfhra.ypp"
    {
			 conprint("switch;\n");
			;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 5765 "pnfhra.ypp"
    {
			 conprint("crash %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 5771 "pnfhra.ypp"
    {
			 conprint("version %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 5777 "pnfhra.ypp"
    {
			 conprint("halt;\n");
			;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 5783 "pnfhra.ypp"
    {
			 conprint("modt %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 5789 "pnfhra.ypp"
    {
			 conprint("return;\n");
			;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 5793 "pnfhra.ypp"
    {
			 conprint("gosub %g;\n", (yyvsp[(2) - (2)]).to_number().get());
			;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 5797 "pnfhra.ypp"
    {
			 conprint("gosub %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 5803 "pnfhra.ypp"
    {
			 conprint("unregister %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 5807 "pnfhra.ypp"
    {
			 conprint("register %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 5811 "pnfhra.ypp"
    {
			 conprint("reregister %s %s %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), 
				  (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 5816 "pnfhra.ypp"
    {
			 conprint("register blank %s %g;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_number().get());
			;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 5822 "pnfhra.ypp"
    {
			 conprint("store %s %s %g;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), (yyvsp[(4) - (4)]).to_number().get());
			;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 5826 "pnfhra.ypp"
    {
			 conprint("store %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 5830 "pnfhra.ypp"
    {
			 conprint("store %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 5834 "pnfhra.ypp"
    {
			 conprint("store storea;\n");
			;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 5838 "pnfhra.ypp"
    {
			 conprint("store %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 5842 "pnfhra.ypp"
    {
			 conprint("store range %s %s;\n", (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 5846 "pnfhra.ypp"
    {
			 conprint("store array %s[%g];\n", (yyvsp[(3) - (6)]).to_string().get().getString().c_str(), (yyvsp[(4) - (6)]).to_number().get());
			;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 5850 "pnfhra.ypp"
    {
			 conprint("store array %s[];\n", (yyvsp[(3) - (5)]).to_string().get().getString().c_str());
			;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 5856 "pnfhra.ypp"
    {
			 conprint("break;\n");
			;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 5860 "pnfhra.ypp"
    {
			 conprint("break %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 5866 "pnfhra.ypp"
    {
			 conprint("addressof %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 5872 "pnfhra.ypp"
    {
			 conprint("add2v;\n");
			;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 5878 "pnfhra.ypp"
    {
			 conprint("continue;\n");
			;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 5884 "pnfhra.ypp"
    {
			 conprint("check %s %s %g;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), (yyvsp[(4) - (4)]).to_number().get());
			;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 5888 "pnfhra.ypp"
    {
			 conprint("check %s %s %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(),
				  (yyvsp[(4) - (4)]).to_boolean().get().getString().c_str());
			;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 5893 "pnfhra.ypp"
    {
			 conprint("check %s %s %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), 
				  (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 5898 "pnfhra.ypp"
    {
			 conprint("check %s %g;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_number().get());
			;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 5904 "pnfhra.ypp"
    {
			 conprint("hcmnt %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 5910 "pnfhra.ypp"
    {
			 conprint("fmode %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 5914 "pnfhra.ypp"
    {
			 conprint("fopen %s %s;\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 5918 "pnfhra.ypp"
    {
			 conprint("fclose %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 5922 "pnfhra.ypp"
    {
			 conprint("feof;\n");
			;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 5928 "pnfhra.ypp"
    {
			 conprint("meml;\n");
			;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 5934 "pnfhra.ypp"
    {
			 conprint("pnfasm %s %s %s;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str(), (yyvsp[(3) - (4)]).to_string().get().getString().c_str(), 
				  (yyvsp[(4) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 5941 "pnfhra.ypp"
    {
			 conprint("array %s.length;\n", (yyvsp[(2) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 5946 "pnfhra.ypp"
    {
			 conprint("dup %s;\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 5952 "pnfhra.ypp"
    {
			 current_param = 0;
			
			 bool found = false;
			 Function f = funcs.get_function((yyvsp[(1) - (4)]).to_string().get(), found);
			 
			 if (!found)
			  yyerror("Function not found.");

			 Array<Param> p;
			 p = f.params();
			 Array<Param> p2;
			 p2 = current_func->params();

			 if (p.length() != p2.length())
			  yyerror("Function parameter mismatch.");

			 delete current_func;

			 for (unsigned long i = 0; i < p.length(); ++i)
			 {
			  switch (p[i].param().getType())
			  {
			   case TVOID:
  			    conprint("var %s = %s;\n", p[i].name().getString().c_str(), (char *)"0V");
			    break;

			   case TBOOLEAN:
  			    conprint("var %s = %s;\n", p[i].name().getString().c_str(), (p[i]).param().to_boolean().get().getString().c_str());
			    break;

			   case TNUMBER:
  			    conprint("var %s = %g;\n", p[i].name().getString().c_str(), (p[i]).param().to_number().get());
   			    break;

			   case TCHARACTER:
  			    conprint("var %s = %c;\n", p[i].name().getString().c_str(), (p[i]).param().to_character().get());
			    break;

			   case TSTRING:
  			    conprint("var %s = %s;\n", p[i].name().getString().c_str(), (p[i]).param().to_string().get().getString().c_str());
			    break;

			   default:
			    yyerror("Invalid function parameter type.");
			  };
			 }

			 conprint("gosub sub %s;\n", (yyvsp[(1) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 6004 "pnfhra.ypp"
    {
				 current_func = new Function();
				;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 6008 "pnfhra.ypp"
    {
				 current_func->param(current_param++, (yyvsp[(1) - (1)]));
				;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 6015 "pnfhra.ypp"
    {
				 (yyval) = (yyvsp[(1) - (1)]);
				;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 6021 "pnfhra.ypp"
    {
			 conprint("%BIN%\n");
			;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 6025 "pnfhra.ypp"
    {
			 conprint("%PBIN%\n");
			;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 6029 "pnfhra.ypp"
    {
			 conprint("%LIB%\n");
			;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 6035 "pnfhra.ypp"
    {
			 conprint("%include %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 6039 "pnfhra.ypp"
    { 
			 conprint("%include <%s>\n", (yyvsp[(3) - (4)]).to_string().get().getString().c_str());
			;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 6043 "pnfhra.ypp"
    {
			 conprint("%import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 6047 "pnfhra.ypp"
    {
			 conprint("%import <%s>\n", (yyvsp[(3) - (4)]).to_string().get().getString().c_str()); 
			;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 6051 "pnfhra.ypp"
    {
			 conprint("%define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 6055 "pnfhra.ypp"
    {
			 conprint("%macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 6059 "pnfhra.ypp"
    {
			 conprint("%endm\n");
		 	;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 6063 "pnfhra.ypp"
    {
			 conprint("%undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 6067 "pnfhra.ypp"
    {
 			 conprint("%ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 6071 "pnfhra.ypp"
    {
			 conprint("%ifndef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 6075 "pnfhra.ypp"
    {
			 conprint("else\n");
			;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 6079 "pnfhra.ypp"
    {
			 conprint("endif\n");
			;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 6083 "pnfhra.ypp"
    {
			 conprint("%_DATE()\n");
			;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 6087 "pnfhra.ypp"
    {
			 conprint("%_TIME()\n");
			;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 6091 "pnfhra.ypp"
    {
			 conprint("%_LINE()\n");
			;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 6095 "pnfhra.ypp"
    {
			 conprint("%_FILE()\n");
			;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 6099 "pnfhra.ypp"
    {
			 conprint("%_CDATE()\n");
			;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 6103 "pnfhra.ypp"
    {
			 conprint("%_CTIME()\n");
			;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 6107 "pnfhra.ypp"
    {
			 conprint("%%include %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 6111 "pnfhra.ypp"
    {
			 conprint("%%include <%s>\n", (yyvsp[(3) - (4)]).to_string().get().getString().c_str()); 
			;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 6115 "pnfhra.ypp"
    {
			 conprint("%%import %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str()); 
			;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 6119 "pnfhra.ypp"
    {
			 conprint("%%import <%s>\n", (yyvsp[(3) - (4)]).to_string().get().getString().c_str()); 
			;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 6123 "pnfhra.ypp"
    {
			 conprint("%%define %s %s\n", (yyvsp[(2) - (3)]).to_string().get().getString().c_str(), (yyvsp[(3) - (3)]).to_string().get().getString().c_str());
			;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 6127 "pnfhra.ypp"
    {
			 conprint("%%macro %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 6131 "pnfhra.ypp"
    {
			 conprint("%%endm\n");
			;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 6135 "pnfhra.ypp"
    {
			 conprint("%%undef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 6139 "pnfhra.ypp"
    {
			 conprint("%%ifdef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 6143 "pnfhra.ypp"
    {
			 conprint("%%ifndef %s\n", (yyvsp[(2) - (2)]).to_string().get().getString().c_str());
			;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 6147 "pnfhra.ypp"
    {
			 conprint("%%else\n");
			;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 6151 "pnfhra.ypp"
    {
			 conprint("%%endif\n");
			;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 6155 "pnfhra.ypp"
    {
			 conprint("%%_DATE()\n");
			;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 6159 "pnfhra.ypp"
    {
			 conprint("%%_TIME()\n");
			;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 6163 "pnfhra.ypp"
    {
			 conprint("%%_LINE()\n");
			;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 6167 "pnfhra.ypp"
    {
			 conprint("%%_FILE\n");
			;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 6171 "pnfhra.ypp"
    {
			 conprint("%%_CDATE()\n");
			;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 6175 "pnfhra.ypp"
    {
			 conprint("%%_CTIME()\n");
			;}
    break;



/* Line 1455 of yacc.c  */
#line 10632 "pnfhra.tab.cpp"
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
#line 6179 "pnfhra.ypp"

/* Additional C/C++ Code */
