/*
 COPYRIGHT INFO
 ==============
 
 pnf.hpp Copyright (C) 2015 Dennis Earl Smiley
 This software is distributed under the terms of des Software Liscense a - a-a-e or at your option, any later version. This software is alpha as of 5/25/15.
 Contact info despersonal000@gmail.com
 
 
 CHANGELOG
 =========
 
 5/25/15 Origional a 	- The first version.
 5/25/15 Origional a-a	- 1. Removed IADDSTORE instruction. 2 instructions did the same thing.
 						  2. Fixed a bug in FOMODE.
 						  3. Fixed a bug in memory.
 						  4. Fixed bugs...
*/
#include <deslib/deslib.hpp>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <cctype>


/*
 IVERSION   - Switches versions. It's not possible to switch versions yet, because it's the first version.
              VERSION TVOID 0V

 IVOID      - Does nothing.
              VOID TVOID 0V

 ICRASH     - Intentional crash of program.
              CRASH TSTRING [string]

 IQUIT      - Quits the program. Returns return value.
              QUIT TVOID [return value]

 IHALT      - Halts the system by entering a forever loop.
              HALT TVOID 0V

 IPRINT     - Prints the specified value or the contents of the accumulator.
              PRINT TVOID 0V
              PRINT TBOOLEAN [data]
              PRINT TNUMBER [data]
              PRINT TCHARACTER [data]
              PRINT TSTRING [data]

 IPRINTLN   - Prints the specified value or the contents of the accumulator,
              then a newline.
              PRINTLN TVOID 0V
              PRINTLN TBOOLEAN [data]
              PRINTLN TNUMBER [data]
              PRINTLN TCHARACTER [data]
              PRINTLN TSTRING [data]

 IREAD      - Reads in a value to the accumulator.
              READ [type] 0V

 ILOAD      - Loads a value from memory into the accumulator.
              LOAD [type] [address]

 ISTORE     - Stores the contents of the accumulator at the specified memory
              location.
              STORE TVOID [address]

 ILOADC     - Loads a value from memory into the %calc register.
              LOADC [type] [address]

 ISTOREC    - Stores the contents of the %calc register into the specified
              memory location.
              STOREC TVOID [address]

 IESTORE    - Stores the contents of %accumulator into [%ecount + 3].
              ESTORE TVOID 0V

 IESTOREC    - Stores the contents of %calc into [%ecount + 3].
               ESTOREC TVOID 0V

 IVLOAD      - Gets a variable from variable location %operand, and stores it in
               %accumulator.
               VLOAD [type] [Variable Address]

 IVSTORE     - Stores a new variable from %accumulator to the next location.
               VSTORE TVOID 0V
               VSTORE TNUMBER [variable number]

 IVLOADC     - Gets a variable from variable location %operand, and stores it in
               %calc.
               VLOADC [type] [Variable Address]

 IVSTOREC    - Stores a new variable from %calc to the next location.
               VSTOREC TVOID 0V
               VSTOREC TNUMBER [variable number]
               
 ISTOREA	 - Stores %accumulator to the address pointed at by %calc.
 			   STOREA TVOID 0V

 IMODT       - Modifies the type of %accumulator.
               MODT [type] 0V

 IMODCT      - Modifies the type of %calc.
               MODCT [type] 0V

 IADD       - Adds %calc or other value to %accumulator.
              ADD TVOID 0V
              ADD TNUMBER [data]
              ADD TCHARACTER [data]
              ADD TSTRING [data]

 ISUB       - Subtracts %calc from %accumulator.
              SUB VOID 0
              SUB TNUMBER [data]

 IMUL       - Multiplies %accumulator and %calc.
              MUL VOID 0
              MUL TNUMBER [data]

 IDIV       - Divides %calc by %accumulator.
              DIV VOID 0
              DIV TNUMBER [data]

 IMOD       - Takes a modulus of %accumulator and %calc.
              MOD VOID 0
              MOD TNUMBER [data]

 IPOW       - Raises %accumulator to the power of %calc.
              POW VOID 0
              POW TNUMBER [data]

 IROOT      - Root %accumulator by itself or the given number.
              SQRT VOID 0
              SQRT TNUMBER [data]

 IINC       - Increments %accumulator.
              INC TVOID 0V

 IDEC       - Decrements %accumulator.
              DEC TVOID 0V

 IEQU       - Tests if %accumulator == %calc.
              EQU TVOID 0V
              EQU TBOOLEAN [data]
              EQU TNUMBER [data]
              EQU TCHARACTER [data]

 INEQU      - Tests if %accumulator != %calc.
              NEQU TVOID 0V
              NEQU TBOOLEAN [data]
              NEQU TNUMBER [data]
              NEQU TCHARACTER [data]

 IGTR       - Tests if %accumulator > %calc.
              GTR TVOID 0V
              GTR TNUMBER [data]
              GTR TCHARACTER [data]

 ILSS       - Tests if %accumulator < %calc.
              LSS TVOID 0V
              LSS TNUMBER [data]
              LSS TCHARACTER [data]

 IGEQU       - Tests if %accumulator >= %calc.
               GEQU TVOID 0V
               GEQU TNUMBER [data]
               GEQU TCHARACTER [data]

 ILEQU       - Tests if %accumulator <= %calc.
               LEQU TVOID 0V
               LEQU TNUMBER [data]
               LEQU TCHARACTER [data]

 IAND        - %accumulator && %calc
               AND TVOID 0V

 IOR         - %accumulator || %calc
               OR TVOID 0V

 INOT        - !(%accumulator)
               NOT TVOID 0V

 IGOTO      - Go to the memory address specified and continue running the
              program from there.
              GOTO TVOID [memory address]

 ICGOTO      - Go to the memory address specified and continue running the
              program from there if %accumulator equals true.
              CGOTO TVOID [memory address]

 IZGOTO     - Go to the memory address specified if %accumulator is 0.
              ZGOTO TVOID [memory address]

 IPGOTO     - Go to the memory address specified if %accumulator is > 0.
              PGOTO TVOID [memory address]

 INGOTO     - Go to the memory address specified if %accumulator is < 0.
              NGOTO TVOID [memory address]

 IGOTOL      - Go to the label specified and continue running the
               program from there.
               GOTOL TVOID [label number]
               GOTOL TSTRING [label string]
               

 ICGOTOL      - Go to the label specified and continue running the
                program from there if %accumulator equals true.
                CGOTOL TVOID [label number]
                CGOTOL TSTRING [label string

 IZGOTOL     - Go to the label specified if %accumulator is 0.
               ZGOTOL TVOID [label number]
               ZGOTOL TSTRING [label string]

 IPGOTOL     - Go to the memory address specified if %accumulator is > 0.
               PGOTOL TVOID [label number]
               PGOTOL TSTRING [label string]

 INGOTOL     - Go to the label specified if %accumulator is < 0.
               NGOTOL TVOID [label number]
               NGOTOL TSTRING [label string]

 IST        - Sets %accumulator to 0 if %calc is 0. (Used for loops.)
              ST TVOID 0V

 IPUSH      - Put the accumulator on the stack.
              PUSH TVOID 0V

 IPOP       - Loads a value into the accumulator from the stack.
              POP TVOID 0V

 ICALL      - Calls a subroutine that begins at [memory address].
              CALL TVOID [memory address]

 ICALLL      - Calls a subroutine that begins at [label].
               CALLL TVOID [label]

 IRET       - Returns from a subroutine.
              RET TVOID 0

 ILBL	    - Declares a label.
	          LBL TVOID 0V
	          LBL TSTRING [string]

 IVAR       - Declares a variable.
              VAR TVOID [variable]

 IELBL      - Declares an event label.
              ELBL TVOID 0V

 IEVLOAD    - Loads a value into %evalue.
              EVLOAD TVOID [value]

 IHEADD     - Adds a Hardware Event to the table.
              HEADD TVOID [event label number]

 IHEREM     - Removes a Hardware Event from the table.
              HEREM TVOID 0V

 IHEED      - Edits a Hardware Event in the table. %evalue must be the hevent
              number.
              HEED TVOID [new event label number number]

 IHEGET     - Gets a Hardware Event event label number from the table. Puts it
              in %evalue.
              HEGET TVOID [hardware event number]

 ISHEADD     - Adds a System Hardware Event to the table.
              SHEADD TVOID [event label number]

 ISHEREM     - Removes a System Hardware Event from the table.
              SHEREM TVOID 0V

 ISHEED      - Edits a System Hardware Event in the table. %evalue must be the 
               shevent number.
              SHEED TVOID [new event label number number]

 ISHEGET     - Gets a System Hardware Event event label number from the table.
               Puts it in %evalue.
              SHEGET TVOID [hardware event number]

 IEADD     -  Adds an Event to the table.
              EADD TVOID [event label number]

 IEREM      - Removes an Event from the table.
              EREM TVOID 0V

 IEED       - Edits an Event in the table. %evalue must be the event number.
              EED TVOID [new event label number number]

 IEGET      - Gets an Event event label number from the table. Puts it in \
              %evalue.
              EGET TVOID [hardware event number]

 IEXADD     - Adds an Exception to the table.
              EXADD TVOID [event label number]

 IEXREM     - Removes an Exception from the table.
              EXREM TVOID 0V

 IEXED      - Edits an Exception in the table. %evalue must be the exception
              number.
              EXED TVOID [new event label number number]

 IEXGET     - Gets an Exception event label number from the table. Puts it
              in %evalue.
              EXGET TVOID [hardware event number]

 IIADD      - Adds an Interrupt to the table.
              IADD TVOID [event label number]

 IIREM      - Removes an Interrupt from the table.
              IREM TVOID 0V

 IIED       - Edits an Interrupt in the table. %evalue must be the interrupt
              number.
              IED TVOID [new event label number number]

 IIGET      - Gets an Interrupt event label number from the table. Puts it
              in %evalue.
              IGET TVOID [hardware event number]
              
 IHEVENT    - Executes a Hardware Event subroutine.
              HEVENT TVOID [hardware event number]

 ISHEVENT   - Executes a System Hardware Event Subroutine.
              SHEVENT TVOID [system hardware event number]

 IEVENT     - Executes an Event subroutine.
              EVENT TVOID [event number]

 IEXCEPTION - Executes an Exception subroutine.
              EXCEPTION TVOID [exception number]

 IINT       - Executes an Interrupt (User Defined Event) subroutine.
              INT TVOID [interrupt number]
                            
 ITYPEOF	- Puts the type of %accumulator in %typeof.
 			  TYPEOF TVOID 0V
 			  
 ICTYPEOF	- Puts the type of %calc in %typeof.
 			  CTYPEOF TVOID 0V
 			  
 ITLOAD     - Loads %typeof to %accumulator.
	   	      TLOAD TVOID 0V

 IALOAD		- Loads a value into the accumulator.
 			  ALOAD TVOID 0V
 			  ALOAD TBOOLEAN [data]
 			  ALOAD TNUMBER [data]
 			  ALOAD TCHARACTER [data]
 			  ALOAD TSTRING [data]
 			  
 IINLOAD	- Loads %iname into %accumulator.
 			  INLOAD TVOID 0V
 			  
 IICLOAD	- Loads %icount into %accumulator.
 			  ICLOAD TVOID 0V
 			  
 IARLOAD	- Loads %arg[number] into %accumulator.
 			  ARLOAD TVOID [number]
 			  
 IELOAD		- Loads [%ecount + 3] to %accumulator.
 			  ELOAD TVOID 0V
 			  
 IELOADC	- Loads [%ecount + 3] to %calc.
 			  ELOADC TVOID 0V
 			  
 IATOC		- Puts %accumulator in %calc.
 			  ATOC TVOID 0V
 			  
 ISWITCH    - Switches %accumulator and %calc.
 			  SWITCH TVOID 0V
 		
 IVADD		- Gets the address of the specified variable.
 			  VADD TVOID [variable number]
 			  
 ILADD		- Gets the address of the specified label.
 			  LADD TVOID [label number]
 			  
 IELADD		- Gets the address of the specified event label.
 			  ELADD TVOID [event label number]
 			  
 IADD2V	    - Retrieves the value at the address stored in %accumulator.
 			  ADD2V TVOID 0V
 			  
 IBTAND		- Performs bit AND on %accumulator and %calc.
 			  BTAND TVOID 0V
 			  
 IBTOR		- Performs bit OR on %accumulator and %calc.
 			  BTOR TVOID 0V
 			  
 IBTEXOR	- Performs bit exclusive OR on %accumulator and %calc.
 			  BTEXOR TVOID 0V
 			  
 IBTNOT		- Performs bit NOT on %accumulator.
 			  BTNOT TVOID 0V
 			  
 IBTSL		- Performs << on %accumulator and %calc.
 			  BTSL TVOID 0V
 			  
 IBTSR		- Performs >> on %accumulator and %calc.
 			  BTSR TVOID 0V
 			  
 IVCHECK    - Sets %accumulator to true if version parameters match.
 			  VCHECK [type] [operand]
 			  
 IVSUPP		- Checks to see if a version is supported.
 			  VSUPP [type] [operand]
 			  
 IVPRINT    - Prints the version.
 			  VPRINT TVOID 0V
 			  
 IVPRINTLN  - Prints the version, then a newline.
 			  VPRINTLN TVOID 0V
 			  
 IISUPP	    - Checks to see if an instruction is supported or not.
 			  ISUPP TNUMBER [data]
 			  
 ITSUPP		- Checks to see if a type is supported or not.
 			  TSUPP TNUMBER [data]
 			  
 ICOMMENT   - A comment in the code.
 			  COMMENT TSTRING [string]
 			  
 IFIMODE	- Sets the mode for file input.
 			  FIMODE TSTRING [mode]
 		
 IFOMODE    - Sets the mode for file output.
 			  FOMODE TSTRING [mode]
 			  
 IFIOPEN	- Opens the specified file for input. If VOID, gets it from %accumulator.
 			  FIOPEN TVOID 0V
 			  FIOPEN TSTRING [filename]
 			  
 IFOOPEN	- Opens the specified file for output. If VOID, gets it from %accumulator.
 			  FOOPEN TVOID 0V
 			  FOOPEN TSTRING [filename]
 			  
 IFREAD		- Reads a value from the file, and stores it in %accumulator.
 			  FREAD [type] 0V
 			  
 IFPRINT	- Prints a value to the file.
 			  FRPINT [type] [data]
 			  
 IFPRINTLN	- Prints a value to the file, then a newline.
 			  FPRINTLN [type] [data]
 			  
 IFICLOSE   - Closes the input file that's open.
 			  FICLOSE TVOID 0V
 			  
 IFOCLOSE   - Closes the output file that's open.
 			  FOCLOSE TVOID 0V
 			  
 IMEML		- Stores the length of memory in %accumulator.
 			  MEML TVOID 0V
 			  
 IFIEOF		- Tests if we are at EOF or not.
 			  FIEOF TVOID 0V
 			  
 IARNLOAD	- Loads the number of arguments into %accumulator.
 			  ARNLOAD TVOID 0V
*/
enum PNF_Instruction_Enum
{ 
 IVERSION = 0,
 IVOID,
 ICRASH,
 IQUIT,
 IHALT,
 IPRINT,
 IPRINTLN,
 IREAD,
 ILOAD,
 ISTORE,
 ILOADC,
 ISTOREC,
 IELOAD,
 IESTORE,
 IELOADC,
 IESTOREC,
 IVLOAD,
 IVSTORE,
 IVLOADC,
 IVSTOREC,
 ISTOREA,
 IMODT,
 IMODCT,
 IADD,
 ISUB,
 IMUL,
 IDIV,
 IMOD,
 IPOW,
 IROOT,
 IINC,
 IDEC,
 IEQU,
 INEQU,
 IGTR,
 ILSS,
 IGEQU,
 ILEQU,
 IAND,
 IOR,
 INOT,
 IGOTO,
 ICGOTO,
 IZGOTO,
 IPGOTO,
 INGOTO,
 IGOTOL,
 ICGOTOL,
 IZGOTOL,
 IPGOTOL,
 INGOTOL,
 IST,
 IPUSH,
 IPOP,
 ICALL,
 ICALLL,
 IRET,
 IVAR,
 ILBL,
 IEPRINT,
 IEPRINTLN,
 IEND,
 IELBL,
 IEVLOAD,
 IHEADD,
 IHEREM,
 IHEED,
 IHEGET,
 ISHEADD,
 ISHEREM,
 ISHEED,
 ISHEGET,
 IEADD,
 IEREM,
 IEED,
 IEGET,
 IEXADD,
 IEXREM,
 IEXED,
 IEXGET,
 IIADD,
 IIREM,
 IIED,
 IIGET,
 IHEVENT,
 ISHEVENT,
 IEVENT,
 IEXCEPTION,
 IINT,
 ITYPEOF,
 ICTYPEOF,
 ITLOAD,
 IALOAD,
 IINLOAD,
 IICLOAD,
 IARLOAD,
 IATOC,
 ISWITCH,
 IVADD,
 ILADD,
 IELADD,
 IADD2V,
 IBTAND,
 IBTOR,
 IBTEXOR,
 IBTNOT,
 IBTSL,
 IBTSR,
 IVCHECK,
 IVSUPP,
 IVPRINT,
 IVPRINTLN,
 IISUPP,
 ITSUPP,
 ICOMMENT,
 IFIMODE,
 IFOMODE,
 IFIOPEN,
 IFOOPEN,
 IFREAD,
 IFPRINT,
 IFPRINTLN,
 IFICLOSE,
 IFOCLOSE,
 IMEML,
 IFIEOF,
 IARNLOAD
};
     
enum PNF_Type_Enum 
{
 TVOID = 0,
 TBOOLEAN,
 TNUMBER,
 TCHARACTER,
 TSTRING
};

enum PNF_FMODE
{
 FMIN = 0,
 FMOUT,
 FMBINARY,
 FMATE,
 FMAPP,
 FMTRUNC	
};

enum BREAKPOINT_CONTROL
{
 BCONE = 0,
 BCTWO,
 BCTHREE
};


class PNF_Void
{
 public:
        void put();
        void get() const;
        
        double to_mem();
        void from_mem(double i);

        void print();
        void eprint();
        void read();
        
        void fprint(ofstream & fout);
        void fread(ifstream & fin);
        
        
        PNF_Void operator=(const PNF_Void & v) const;
};

void PNF_Void::put()
{
 // Does nothing
}

void PNF_Void::get() const
{
 // Does nothing
}

double PNF_Void::to_mem()
{
 return 0;
}

void PNF_Void::from_mem(double i)
{
 if (i != 0)
  error(ERRORMSG, (char *)"Not Void.");
}

void PNF_Void::print()
{
 cout << 0;
}

void PNF_Void::fprint(ofstream & fout)
{
 fout << 0;
}

void PNF_Void::eprint()
{
 cerr << 0;
}

void PNF_Void::read()
{
 // Does nothing
}

void PNF_Void::fread(ifstream & fin)
{
 // Does nothing
}

PNF_Void PNF_Void::operator=(const PNF_Void & v) const
{
 if (this == &v)
  return *this;
  
 return (*this);
}


class PNF_Boolean
{
 protected:
           bool data;
 
 public:
        PNF_Boolean();
        PNF_Boolean(bool d);
        ~PNF_Boolean();
        
        
        void put(bool d);
        String get() const;
        
        double to_mem();
        void from_mem(double i);

        void print();
        void eprint();
        void read();
        
        void fprint(ofstream & fout);
        void fread(ifstream & fin);
        
        
        void opnot();
        void opand(bool b);
        void opor(bool b);
        
        
        PNF_Boolean operator=(const PNF_Boolean & b);
};

PNF_Boolean::PNF_Boolean()
{
 data = false;
}

PNF_Boolean::PNF_Boolean(bool d)
{
 data = d;
}

PNF_Boolean::~PNF_Boolean()
{
 
}
        
void PNF_Boolean::put(bool d)
{
 data = d;
}

String PNF_Boolean::get() const
{
 if (data == true)
  return (char *)"true";
 else
  return (char *)"false";
}

double PNF_Boolean::to_mem()
{
 return data;
}

void PNF_Boolean::from_mem(double i)
{
 data = (bool)i;
}

void PNF_Boolean::print()
{
 cout << get();
}

void PNF_Boolean::fprint(ofstream & fout)
{
 fout << get();
}

void PNF_Boolean::eprint()
{
 cerr << get();
}

void PNF_Boolean::read()
{
 string data2;
 
 cin >> data2;

 if (data2 == "false")
  data = false;
 else if (data2 == "true")
  data = true;
 else
  data = false;
}

void PNF_Boolean::fread(ifstream & fin)
{
 string data2;
 
 fin >> data2;

 if (data2 == "false")
  data = false;
 else if (data2 == "true")
  data = true;
 else
  data = false;
}

void PNF_Boolean::opnot()
{
 if (data == false)
  data = true;
 else if (data == true)
  data = false;
 else
  data = false;
}

void PNF_Boolean::opand(bool b)
{
 data = data && b;
}

void PNF_Boolean::opor(bool b)
{
 data = data || b;
}

PNF_Boolean PNF_Boolean::operator=(const PNF_Boolean & b)
{
 if (this == &b)
  return *this;
 
 data = b.data;
 
 
 return (*this);
}


class PNF_Number
{
 protected:
           double data;
           
           
 public:
        PNF_Number();
        PNF_Number(double d);
        ~PNF_Number();
        
        void put(double d);
        double get() const;
        
        
        double to_mem();
        void from_mem(double d);

        void print();
        void eprint();
        void read();
        
        void fprint(ofstream & fout);
        void fread(ifstream & fin);


        void add(double d);
        void sub(double d);
        void mul(double d);
        void div(double d);
        void mod(double d);

        void pow(double d);
        void root(double d);
        void inc(double d);
        void dec(double d);
        
        
        PNF_Number operator=(const PNF_Number & n);
};

PNF_Number::PNF_Number()
{
 data = 0;
}

PNF_Number::PNF_Number(double d)
{
 data = d;
}

PNF_Number::~PNF_Number()
{
 
}
        
void PNF_Number::put(double d)
{
 data = d;
}

double PNF_Number::get() const
{
 return data;
}

double PNF_Number::to_mem()
{
 return get();
}

void PNF_Number::from_mem(double d)
{
 put(d);
}

void PNF_Number::print()
{
 cout << data;
}

void PNF_Number::fprint(ofstream & fout)
{
 fout << data;
}

void PNF_Number::eprint()
{
 cerr << data;
}

void PNF_Number::read()
{
 cin >> data;
}

void PNF_Number::fread(ifstream & fin)
{
 fin >> data;
}

void PNF_Number::add(double d)
{
 data += d;
}

void PNF_Number::sub(double d)
{
 data -= d;
}

void PNF_Number::mul(double d)
{
 data *= d;
}

void PNF_Number::div(double d)
{
 data /= d;
}

void PNF_Number::mod(double d)
{
 long l = (long)data % (long)d;
 data = l;
}

void PNF_Number::pow(double d)
{
 data = ::pow(data, (int)d);
}

void PNF_Number::root(double d)
{
 if (d == 2)
  data = ::sqrt(data);
 else
 {
  int data2 = (int)data;
  for (int i = (int)d - 1; i != 0; --i)
   data2 = data2 / d;
  data = data2;
 }
}

void PNF_Number::inc(double d)
{
 data += d;
}

void PNF_Number::dec(double d)
{
 data -= d;
}

PNF_Number PNF_Number::operator=(const PNF_Number & n)
{
 if (this == &n)
  return *this;
  
 this->data = n.data;
 
 
 return (*this);
}


class PNF_Character
{
 protected:
           char data;
           
           
 public:
        PNF_Character();
        PNF_Character(char d);
        ~PNF_Character();
        
        void put(char d);
        char get() const;
        
        double to_mem();
        void from_mem(double c);

        void print();
        void eprint();
        void read();
        
        void fprint(ofstream & fout);
        void fread(ifstream & fin);
        

        void add(char d);
        void sub(char d);
        void mul(char d);
        void div(char d);
        void mod(char d);
        
        void pow(char d);
        void root(char d);
        void inc(char d);
        void dec(char d);
        
        
        PNF_Character operator=(const PNF_Character & c);
};

PNF_Character::PNF_Character()
{
 data = '\0';
}

PNF_Character::PNF_Character(char d)
{
 data = d;
}

PNF_Character::~PNF_Character()
{
 
}
        
void PNF_Character::put(char d)
{
 data = d;
}

char PNF_Character::get() const
{
 return data;
}

double PNF_Character::to_mem()
{
 return (double)data;
}

void PNF_Character::from_mem(double c)
{
 data = (char)c;
}

void PNF_Character::print()
{
 cout << data;
}

void PNF_Character::fprint(ofstream & fout)
{
 fout << data;
}

void PNF_Character::eprint()
{
 cerr << data;
}

void PNF_Character::read()
{
 cin >> data;
}

void PNF_Character::fread(ifstream & fin)
{
 fin >> data;
}

void PNF_Character::add(char d)
{
 data += d;
}

void PNF_Character::sub(char d)
{
 data -= d;
}

void PNF_Character::mul(char d)
{
 data *= d;
}

void PNF_Character::div(char d)
{
 data = data / d;
}

void PNF_Character::mod(char d)
{
 data = data % d;
}

void PNF_Character::pow(char d)
{
 double n1 = (int)data;
 double n2 = (int)d;
 double r;
 r = ::pow(n1, n2);
 int r2 = (int)r;
 data = (char)r2;
}

void PNF_Character::root(char d)
{
 double d2 = (double)d;
 if (d2 == 2)
  data = ::sqrt(data);
 else
 {
  int data2 = (int)data;
  for (int i = (int)d2 - 1; i != 0; --i)
   data2 = data2 / d2;
  data = data2;
 }
}

void PNF_Character::inc(char d)
{
 data += d;
}

void PNF_Character::dec(char d)
{
 data -= d;
}

PNF_Character PNF_Character::operator=(const PNF_Character & c)
{
 if (this == &c)
  return *this;
  
 this->data = c.data;
 
 
 return (*this);
}


class PNF_String
{
 protected:
           String data;
           
 public:
        PNF_String();
        PNF_String(String d);
        ~PNF_String();
        
        void put(String d);
        String get() const;
        
        double * to_mem();
        void from_mem(double * w);

        void print();
        void eprint();
        void read();
        
        void fprint(ofstream & fout);
        void fread(ifstream & fin);
        

        void add(String d);
        
        
        PNF_String operator=(const PNF_String & s);
};

PNF_String::PNF_String()
{
 data = (char *)"";
}

PNF_String::PNF_String(String d)
{
 data = d;
}

PNF_String::~PNF_String()
{
 
}
        
void PNF_String::put(String d)
{
 data = d;
}

String PNF_String::get() const
{
 return data;
}

double * PNF_String::to_mem()
{
 double * ret = new double[data.size()];
 
 for (unsigned long i = 0; i < data.size(); ++i)
 {
  if ((data.getString().data()[i]) == '\0')
   break;
  ret[i] = (long)data.getString().data()[i];
 }
 ret[data.size()] = 0;


 return ret;
}

void PNF_String::from_mem(double * w)
{
 unsigned long i;
 for (i = 0; w[i] != 0; ++i)
  data[i] = (char)w[i];
}

void PNF_String::print()
{
 cout << data;
}

void PNF_String::fprint(ofstream & fout)
{
 fout << data;
}

void PNF_String::eprint()
{
 cerr << data;
}

void PNF_String::read()
{
 cin >> data;
}

void PNF_String::fread(ifstream & fin)
{
 fin >> data;
}

void PNF_String::add(String d)
{
 data += d;
}

PNF_String PNF_String::operator=(const PNF_String & s)
{
 if (this == &s)
  return *this;
  
 this->data = s.data;
 
 
 return (*this);
}


class PNF_Variable
{
 private:
         PNF_Void v;
         PNF_Boolean b;
         PNF_Number n;
         PNF_Character c;
         PNF_String s;
 
 
         long type;         
 
 
 public:
 		PNF_Variable();
 		PNF_Variable(PNF_Void v);
 		PNF_Variable(PNF_Boolean b);
 		PNF_Variable(PNF_Number n);
 		PNF_Variable(PNF_Character c);
 		PNF_Variable(PNF_String s);
 		
 		
        long getType() const;
        void setType(long t);
        

        void put(PNF_Void v);
        void put(PNF_Boolean b);
        void put(PNF_Number n);
        void put(PNF_Character c);
        void put(PNF_String s);

        double * getm();
        void putm(double * d);

        void print();
        void println();
        void eprint();
        void eprintln();
        void read();
        
        void fprint(ofstream & fout);
        void fread(ifstream & fin);
        

        PNF_Void to_void() const;
        PNF_Boolean to_boolean() const;
        PNF_Number to_number() const;
        PNF_Character to_character() const;
        PNF_String to_string() const;
        
        
        PNF_Variable operator=(const PNF_Variable & v);
};

PNF_Variable::PNF_Variable()
{
	
}

PNF_Variable::PNF_Variable(PNF_Void v)
{
 put(v);
}

PNF_Variable::PNF_Variable(PNF_Boolean b)
{
 put(b);
}

PNF_Variable::PNF_Variable(PNF_Number n)
{
 put(n);
}

PNF_Variable::PNF_Variable(PNF_Character c)
{
 put(c);
}

PNF_Variable::PNF_Variable(PNF_String s)
{
 put(s);
}
 		
long PNF_Variable::getType() const
{
 return type;
}

void PNF_Variable::setType(long t)
{
 long t2 = type;
 
 switch (t2)
 {
  case TVOID:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 // Do nothing...
   	}
   	break;
   	
   	case TBOOLEAN:
   	{
     b = to_boolean();
   	}
   	break;
   	
   	case TNUMBER:
   	{
   	 n = to_number();
   	}
   	break;
   	
   	case TCHARACTER:
   	{
   	 c = to_character();
   	}
   	break;
   	
   	case TSTRING:
   	{
   	 s = to_string();
   	}
   	break;
   }	
  }
  break;
  
  case TBOOLEAN:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 v = to_void();	
   	}
   	break;
   	
   	case TBOOLEAN:
   	{
   	 // Do nothing...
   	}
   	break;
   	
   	case TNUMBER:
   	{
   	 n = to_number();
   	}
   	break;
   	
   	case TCHARACTER:
   	{
   	 c = to_character();	
   	}
   	break;
   	
   	case TSTRING:
   	{
   	 s = to_string();
   	}
   	break;
   }	
  }
  break;
  
  case TNUMBER:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 v = to_void();
   	}
   	break;
   	
   	case TBOOLEAN:
   	{
   	 b = to_boolean();
   	}
   	break;
   	
   	case TNUMBER:
   	{
   	 // Do nothing...
   	}
   	break;
   	
   	case TCHARACTER:
   	{
   	 c = to_character();
   	}
   	break;
   	
   	case TSTRING:
   	{
   	 s = to_string();
   	}
   	break;
   }	
  }
  break;
  
  case TCHARACTER:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 v = to_void();
   	}
   	break;
   	
   	case TBOOLEAN:
   	{
   	 b = to_boolean();
   	}
   	break;
   	
   	case TNUMBER:
   	{
   	 n = to_number();
   	}
   	break;
   	
   	case TCHARACTER:
   	{
   	 // Do nothing...
   	}
   	break;
   	
   	case TSTRING:
   	{
   	 s = to_string();
   	}
   	break;
   }	
  }
  break;
  
  case TSTRING:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 v = to_void();
   	}
   	break;
   	
   	case TBOOLEAN:
   	{
   	 b = to_boolean();
   	}
   	break;
   	
   	case TNUMBER:
   	{
   	 n = to_number();
   	}
   	break;
   	
   	case TCHARACTER:
   	{
   	 c = to_character();
   	}
   	break;
   	
   	case TSTRING:
   	{
   	 // Do nothing...
   	}
   	break;
   }	
  }
  break;
 }
 
 type = t;
}

void PNF_Variable::put(PNF_Void v)
{
 setType(TVOID);
 this->v = v;
}

void PNF_Variable::put(PNF_Boolean b)
{
 setType(TBOOLEAN);
 this->b = b;
}

void PNF_Variable::put(PNF_Number n)
{
 setType(TNUMBER);
 this->n = n;
}

void PNF_Variable::put(PNF_Character c)
{
 setType(TCHARACTER);
 this->c = c;
}

void PNF_Variable::put(PNF_String s)
{
 setType(TSTRING);
 this->s = s;
}
        
double * PNF_Variable::getm()
{
 double * ret = new double;

 switch (type)
 {
  case TVOID:
       *ret = v.to_mem();
       break;
       
  case TBOOLEAN:
       *ret = b.to_mem();
       break;
       
  case TNUMBER:
       *ret = n.to_mem();
       break;
       
  case TCHARACTER:
       *ret = c.to_mem();
       break;
       
  case TSTRING:
       ret = s.to_mem();
       break;
 };
 
 return ret;
}

void PNF_Variable::putm(double * d)
{
 switch (type)
 {
  case TVOID:
       v.from_mem(*d);
       break;
       
  case TBOOLEAN:
       b.from_mem(*d);
       break;
       
  case TNUMBER:
       n.from_mem(*d);
       break;
       
  case TCHARACTER:
       c.from_mem(*d);
       break;
       
  case TSTRING:
       s.from_mem(d);
       break;
 };
}

void PNF_Variable::print()
{
 switch (type)
 {
  case TVOID:
   v.print();
   break;

  case TBOOLEAN:
   b.print();
   break;

  case TNUMBER:
   n.print();
   break;

  case TCHARACTER:
   c.print();
   break;

  case TSTRING:
   s.print();
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Variable::println()
{
 switch (type)
 {
  case TVOID:
   v.print();
   cout << endl;
   break;

  case TBOOLEAN:
   b.print();
   cout << endl;
   break;

  case TNUMBER:
   n.print();
   cout << endl;
   break;

  case TCHARACTER:
   c.print();
   cout << endl;
   break;

  case TSTRING:
   s.print();
   cout << endl;
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Variable::fprint(ofstream & fout)
{
 switch (type)
 {
  case TVOID:
   v.fprint(fout);
   break;

  case TBOOLEAN:
   b.fprint(fout);
   break;

  case TNUMBER:
   n.fprint(fout);
   break;

  case TCHARACTER:
   c.fprint(fout);
   break;

  case TSTRING:
   s.fprint(fout);
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Variable::eprint()
{
 switch (type)
 {
  case TVOID:
   v.eprint();
   break;

  case TBOOLEAN:
   b.eprint();
   break;

  case TNUMBER:
   n.eprint();
   break;

  case TCHARACTER:
   c.eprint();
   break;

  case TSTRING:
   s.eprint();
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Variable::eprintln()
{
 switch (type)
 {
  case TVOID:
   v.eprint();
   cerr << endl;
   break;

  case TBOOLEAN:
   b.eprint();
   cerr << endl;
   break;

  case TNUMBER:
   n.eprint();
   cerr << endl;
   break;

  case TCHARACTER:
   c.eprint();
   cerr << endl;
   break;

  case TSTRING:
   s.eprint();
   cerr << endl;
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Variable::read()
{
 switch (getType())
 {
  case TVOID:
   v.read();
   break;

  case TBOOLEAN:
   b.read();
   break;

  case TNUMBER:
   n.read();
   break;

  case TCHARACTER:
   c.read();
   break;

  case TSTRING:
  {
   s.read();
   }
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Variable::fread(ifstream & fin)
{
 switch (getType())
 {
  case TVOID:
   v.fread(fin);
   break;

  case TBOOLEAN:
   b.fread(fin);
   break;

  case TNUMBER:
   n.fread(fin);
   break;

  case TCHARACTER:
   c.fread(fin);
   break;

  case TSTRING:
  {
   s.fread(fin);
   }
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

PNF_Void PNF_Variable::to_void() const
{
 PNF_Void v;
 return v;
}

PNF_Boolean PNF_Variable::to_boolean() const
{
 PNF_Boolean b;

 switch (getType())
 {
  case TVOID:
       b.put(false);
       break;

  case TBOOLEAN:
       b = this->b;
       break;

  case TNUMBER:
       b.put(n.get());
       break;

  case TCHARACTER:
  	   if (c.get() == 't')
  	    b.put(true);
  	   else if (c.get() == 'f')
  	    b.put(false);
  	   else
  	    b.put(false);
       break;

  case TSTRING:
  	   if (s.get().getString() == "true")
  	    b.put(true);
  	   else if (s.get().getString() == "false")
  	    b.put(false);
  	   else
  	    b.put(false);
       break;
 }

 return b;
}

PNF_Number PNF_Variable::to_number() const
{
 PNF_Number n;

 switch (getType())
 {
  case TVOID:
       n.put(0);
       break;

  case TBOOLEAN:
       if (b.get().getString() == "true")
          n.put(1);
       else
          n.put(0);
       break;

  case TNUMBER:
       n = this->n;
       break;

  case TCHARACTER:
       n.put(c.get());
       break;

  case TSTRING:
  {
   unsigned long value = 0;
   for (unsigned long i = 0; i < s.get().length(); ++i)
    value += (unsigned long)s.get()[i];
   n.put(value);
  }
  break;
 }

 return n;
}

PNF_Character PNF_Variable::to_character() const
{
 PNF_Character c;

 switch (getType())
 {
  case TVOID:
       c = '\0';
       break;

  case TBOOLEAN:
       if (b.get().getString() == "true")
        c = 't';
       else
        c = 'f';
       break;

  case TNUMBER:
       c = (char)n.get();
       break;

  case TCHARACTER:
       c = this->c;
       break;

  case TSTRING:
       c = s.get()[0];
       break;
 }


 return c;
}

PNF_String PNF_Variable::to_string() const
{
 PNF_String s;

 switch (getType())
 {
  case TVOID:
       s.put((char *)"");
       break;

  case TBOOLEAN:
       s = b.get();
       break;

  case TNUMBER:
       s.put((char)n.get());
       break;

  case TCHARACTER:
       s.put(c.get());
       break;

  case TSTRING:
       s = this->s;
       break;
 }


 return s;
}

PNF_Variable PNF_Variable::operator=(const PNF_Variable & v)
{
 if (this == &v)
  return *this;
  
  this->v = v.v;
  this->b = v.b;
  this->n = v.n;
  this->c = v.c;
  this->s = v.s;
  this->type = v.type;
  
  return (*this);
}


class Memory
{
 private:
         Array<double> mem;
         
         
 public:
        Memory();
        ~Memory();
        
        
        double get(unsigned long i);
        void put(unsigned long i, double d);
        long length();

        Array<double> getmem();
        void setmem(Array<double> a);

        void insert();
        void remove();
};

Memory::Memory()
{
 
}

Memory::~Memory()
{
 
}        
        
double Memory::get(unsigned long i)
{
 if (i >= length())
 {
  for (unsigned j = mem.length(); i >= mem.length(); ++j)
  {
   insert();
   mem.put(0, j);
  }
 }
 return mem.get(i);
}

void Memory::put(unsigned long i, double d)
{
 if (i >= length())
 {
  insert();
  mem.put(d, i);
 }
 else
  mem.put(d, i);
}

long Memory::length()
{
 return mem.length();
}

Array<double> Memory::getmem()
{
 return this->mem;
}

void Memory::setmem(Array<double> a)
{
 this->mem = a;
}

void Memory::insert()
{
 mem.insert();
}

void Memory::remove()
{
 mem.remove();
}

class Stack
{
 private:
         stack<PNF_Variable> stk;
         
         
 public:
        Stack();
        ~Stack();
        
        
        PNF_Variable pop();
        void push(PNF_Variable & v);
        PNF_Variable top();

        long length();
};

Stack::Stack()
{
 
}

Stack::~Stack()
{

}
                
PNF_Variable Stack::pop()
{
 if (length() == 0)
 {
  PNF_Number n(-1);
  PNF_Variable v(n);
  return v;
 }
  
 PNF_Variable ret = stk.top();
 stk.pop();


 return ret;
}

PNF_Variable Stack::top()
{
 if (length() == 0)
 {
  PNF_Number n(-1);
  PNF_Variable v(n);
  return v;
 }
 return stk.top();
}

void Stack::push(PNF_Variable & v)
{
 stk.push(v);
}

long Stack::length()
{
 return stk.size();
}

class Label
{
 private:
  unsigned long num;
  String string;
  
  
 public:
  Label(unsigned long n, String s);
  
  void setLabel(unsigned long n, String s);
  void setNum(unsigned long n);
  void setString(String s);
  
  unsigned long getNum();
  String getString();
};

Label::Label(unsigned long n = 0, String s = "")
{
 num = n;
 string = s;
}
  
void Label::setLabel(unsigned long n = 0, String s = "")
{
 num = n;
 string = s;
}

void Label::setNum(unsigned long n = 0)
{
 num = n;
}

void Label::setString(String s = "")
{
 string = s;
}
  
unsigned long Label::getNum()
{
 return num;
}

String Label::getString()
{
 return string;
}

class ETable
{
 private:
  Array<unsigned long> table;


 public:
  ETable();
  
  
  void add(unsigned long value);
  void remove();
  void edit(unsigned long index, unsigned long value);
  unsigned long get(unsigned long index);
  unsigned long length();
};


ETable::ETable()
{
 table[0] = -1;
}

void ETable::add(unsigned long value)
{
 if (length() == 1)
  table.put(value, 0);
 else
 {
  table.insert();
  table.put(value, (length() - 1));
 }
}

void ETable::remove()
{
 table.remove();
}

void ETable::edit(unsigned long index, unsigned long value)
{
 if (index < length())
  table.put(value, index);
 else
 {
  add(value);
 }
}

unsigned long ETable::get(unsigned long index)
{
 if (index >= length())
  return -1;
 return table.get(index);
}

unsigned long ETable::length()
{
 return table.length();
}

class PNF_Version
{
 public:
  PNF_Variable base;
  double top;
  
  
  PNF_Version(unsigned long d);
};

PNF_Version::PNF_Version(unsigned long d = 0)
{
 PNF_Void v;
 base.put(v);
 top = d;
}

struct Registers
{
 unsigned long icount;

 unsigned long instruction;
 unsigned long type;
 unsigned long operand;
 unsigned long ninstruction;
 
 unsigned long mins;
 unsigned long pmins;

 
 String iname;
 Array<String> args;


 unsigned long ecount;
 Array<unsigned long> varcount;
 Array<Label> labels;
 Array<unsigned long> elabels;


 unsigned long evalue;
 ETable hevents;
 ETable shevents;
 ETable events;
 ETable exceptions;
 ETable interrupts;


 String type_of;
 
 
 PNF_Variable accumulator;
 PNF_Variable calc;
 
 PNF_Version version;
 Array<PNF_Version> sversion;
 
 Array<unsigned long> sinstruction;
 Array<unsigned long> stype;
 
 
 PNF_FMODE fimode;
 PNF_FMODE fomode;
};


struct ProgramState
{
 Registers reg;
 Memory mem;
 Stack stk;
};
 
        
class PNF
{
 private:       
         Memory mem;
         Registers reg;
         Stack stk;
         Stack substk;
         
         ifstream pnffin;
         ofstream pnffout;
         
         
         String get_extension(String fileName);
         
         
 public:
        PNF(int argc, char ** argv);
        ~PNF();
        
        
        String getProgram();
        void setProgram(char * program);

        Memory & getmem();
        void setmem(Memory & mem);
        
        
        void crash(String str);


        void load();
        void loads2();
        void loads3();
        void check();
        int execute();
        
        
        ProgramState builtin_breakpoint_exception(ProgramState state);
};


String PNF::get_extension(String fileName)
{
 unsigned long index = fileName.getString().find(".");
 if (index == string::npos)
  crash("File has No Extension.");
  
 String extension = fileName.getString().substr(index);
 
 
 return extension;
}

PNF::PNF(int argc, char ** argv)
{
 double l = 0;
 double * pl = &l;
 
 reg.icount = 0;
 reg.instruction = 0;
 reg.type = 0;
 reg.operand = 0;
 reg.type_of = "UNKNOWN"; // Initialized to UNKNOWN Value.

 reg.iname = argv[0];
 for (long i = 0; i < argc; ++i)
 {
  if (i + 1 == argc)
   break;

  if (reg.args.length() < (argc - 1))
   reg.args.insert();
  reg.args.put(argv[i + 1], i);
 }
 
 reg.accumulator.setType(TVOID);
 reg.accumulator.putm(pl);

 reg.calc.setType(TVOID);
 reg.calc.putm(pl);
}

PNF::~PNF()
{
 
}
                
String PNF::getProgram()
{
 return reg.iname;
}

void PNF::setProgram(char * program)
{
 reg.iname = program;
}        

Memory & PNF::getmem()
{
 return mem;
}

void PNF::setmem(Memory & mem)
{
 for (unsigned long i = 0; i < this->mem.length(); ++i)
  mem.getmem().put(this->mem.get(i), i);
}

void PNF::crash(String str)
{
 error(ERRORMSG, str);
 cout << endl;

 cout << "Registers:\n";
 cout << "==========\n";
 cout << "%icount              = " << reg.icount << endl;
 cout << endl;
 cout << "%instruction         = " << reg.instruction << endl;
 cout << "%type                = " << reg.type << endl;
 cout << "%operand             = " << reg.operand << endl;
 cout << "%ninstruction        = " << reg.ninstruction << endl;
 cout << "%mins                = " << reg.mins << endl;
 cout << "%pmins               = " << reg.pmins << endl;
 cout << "%typeof              = " << reg.type_of << endl;
 cout << "%version             = ";
 reg.version.base.print();
 cout << " " << reg.version.top << endl;
 cout << "%accumulator         = ";
 reg.accumulator.print();
 cout << endl;
 cout << "%calc                = ";
 reg.calc.print();
 cout << endl;
 cout << "%iname               = " << reg.iname;
 cout << "\n\n";


 for (unsigned long i = 0; i < mem.length(); ++i)
  cout << "memory[" << i << "]: " << mem.get(i) << endl;
 cout << "\n\n";

 for (unsigned long i = 0; i < stk.length(); ++i)
 {
  cout << "Stack[" << i << "]: ";
  stk.top().println();
 }

 for (unsigned long i = 0; i < reg.args.length(); ++i)
  cout << "args[" << i << "]: " << reg.args.get(i) << endl;
 cout << "\n\n";
 
 
 exit(-1);
}

void PNF::load()
{
 String extension = get_extension(reg.args.get(0));
 if (extension != ".pnf")
  crash("Program has Invalid Extension.");
 
 fin.open(reg.args.get(0).getString().c_str());
 if (!fin)
  crash("Program Not Found or File Not Readable.");
 
 String signature = (char *)"!@.PNF";
 String str;
 fin >> str;

 
 if (str.getString() == signature.getString())
 {
  double num = 0;
  double num2 = 0;
  
  unsigned long i;
  for (i = 0; !fin.eof(); ++i)
  {
   fin >> num;
   mem.put(i, num);
  }
  reg.ecount = i;
 }
 else
  crash("Wrong Signature.");
 fin.close();
}

void PNF::loads2()
{
 if (mem.get(0) != IVERSION)
  crash("Version Unknown.");
 if (mem.get(reg.ecount - 3) != IEND)
  crash("No END Instruction.");

 // Put the address of the variables in varcount.
 for (unsigned long j = 0, k = 0; j != reg.ecount; ++j)
 {
  if (mem.get(j) == IVAR && mem.get(j + 1) == TVOID)
  {
   reg.varcount.put(j + 2, k);
   reg.varcount.insert();
   ++k;
  }
 }

 for (unsigned long j = 0, k = 0; j != reg.ecount; ++j)
 {
  if (mem.get(j) == ILBL && mem.get(j + 1) == TVOID && mem.get(j + 2) == 0)
  {
   Label l(j + 3, "");
   reg.labels.put(l, k);
   reg.labels.insert();
   ++k;
  }
  else if (mem.get(j) == ILBL && mem.get(j + 1) == TSTRING)
  {
   Label l2;
   String temp = "";
   unsigned long l, cl;
   for (l = j + 2, cl = 0; mem.get(l) != 0; ++l, ++cl)
   {
   	temp += (char)mem.get(l);
   }
   l2.setString(temp);
   
   l2.setNum(j + cl + 3);
   reg.labels.put(l2, k);
   reg.labels.insert();
   ++k; // String labels count too...
  }
 }

 for (unsigned long j = 0, k = 0; j != reg.ecount; ++j)
 {
  if (mem.get(j) == IELBL && mem.get(j + 1) == TVOID && mem.get(j + 2) == 0)
  {
   reg.elabels.put(j + 3, k);
   reg.elabels.insert();
   ++k;
  }
 }

 reg.icount = 0;
}

void PNF::loads3()
{
 // Set ecount...
 reg.ecount = mem.length();
}

void PNF::check()
{
 // Not implemented yet.
}

int PNF::execute()
{
 // Variables needed
 bool inBreakpoint = false;
 unsigned long numBreakpoints = 0;
 unsigned long inSubBreakpoint = 0;
 bool inRet = false;
  
 bool quitFound = false;
 unsigned long quitValue = 0;
 
 bool eofstate = false;
 bool eofstate2 = false;
  
  
 // Load the registers with the proper memory
 // Version
 PNF_Void v;
 reg.version.base.put(v);
 reg.version.top = 0;
 
  // Load the supported versions...
 reg.sversion[0].base.put(v);
 reg.sversion[0].top = 0;
  
  // Load the supported instructions...
  for (unsigned long is = 0; is <= 113; ++is)
  {
   if (is != 0)
    reg.sinstruction.insert();
    
   reg.sinstruction[is] = is;
  }
  
  // Load the supported types...
  for (unsigned long is = 0; is <= 4; ++is)
  {
   if (is != 0)
    reg.stype.insert();
    
   reg.stype[is] = is;
  }
  
  // Load fimode and fomode
  reg.fimode = FMIN;
  reg.fomode = FMOUT;
  
  
 // Execute program
 for (unsigned long i = 0, j = 1, k = 2; ; i += 3, j += 3, k += 3)
 {  
  // Load the registers with the proper memory   
  ++reg.icount;

  reg.instruction = (long)mem.get(i);
  reg.type = (long)mem.get(j);
  reg.operand = (long)mem.get(k);
  reg.ninstruction = (long)mem.get(k + 1);
   
  reg.mins = i;
  if (reg.icount == 1)
   reg.pmins = 0;
  else
   reg.pmins = i - 3;
  
  
  // Run the instruction
  switch (reg.instruction)
  {
   case IVERSION:
        switch (reg.type)
        {
         case TVOID:
               if (reg.operand != 0)
                crash("Invalid VOID Value.");
               else
               {
               	PNF_Void v;
               	reg.version.base.put(v);
               	reg.version.top = 0;
               }
               break;
               
         default:
               crash("Invalid Type.");
        };
        break;
        
   case IVOID:  
        switch (reg.type)
        {
         case TVOID:
               if (reg.operand != 0)
                crash("Invalid VOID Value.");
               else
                ; // Does Nothing...      
               break;
               
         default:
               crash("Invalid Type.");
               break;  
        };
        break;
        
   case ICRASH:
        switch (reg.type)
        {
         case TSTRING:   
              {           
               unsigned long l;
               String str;
               for (l = k; mem.get(l) != 0; ++l)
               {
                char c = (char)mem.get(l);
                str = str + c;
               }
               i = l;               
               crash(str);
              }
              break;
              
         default:
                 crash("Invalid Type.");
                 break;
        }
        break;
        
   case IQUIT:
        switch (reg.type)
        {
         case TVOID:
          quitValue = reg.operand;
          quitFound = true;
          break;
              
         default:
          crash("Invalid Type.");
        }
        break;
        
        
   case IHALT:
        switch (reg.type)
        {
         case TVOID:
              if (reg.operand != 0)
               crash("Invalid VOID Value.");
              else
               for (;;)
                ;
              
         default:
          crash("Invalid Type.");
          break;
        };
        
   case IPRINT:
   {
        switch (reg.type)
        {
         case TVOID:
         {
          if (reg.operand != 0)
           crash("Invalid VOID Value.");
          else
          {
           reg.accumulator.print();
          }
         }
         break;

         case TBOOLEAN:
          switch (reg.operand)
          {
           case 0:
            cout << "false";
            break;

           case 1:
            cout << "true";
            break;

           default:
            cout << "true";
            break;
          }
          break;

         case TNUMBER:
          cout << reg.operand;
          break;

         case TCHARACTER:
          cout << (char)reg.operand;
          break;

         case TSTRING:
         {
          unsigned long is = 0;
          for (is = k; mem.get(is) != 0; ++is)          
           cout << (char)mem.get(is);

          i = is + 1;
          j = i + 1;
          k = i + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         break;
              
         default:
          crash("Invalid Type.");
          break;
        };
   }
        break;

   case IPRINTLN:
   {
        switch (reg.type)
        {
         case TVOID:
              if (reg.operand != 0)
               crash("Invalid VOID Value.");
              else
              {
               reg.accumulator.println();
              }
              break;

         case TBOOLEAN:
          switch (reg.operand)
          {
           case 0:
            cout << "false\n";
            break;

           case 1:
            cout << "true\n";
            break;

           default:
            cout << "true\n";
            break;
          }
          break;

         case TNUMBER:
          cout << reg.operand << endl;
          break;

         case TCHARACTER:
          cout << (char)reg.operand << endl;
          break;

         case TSTRING:
         {
          unsigned long is = 0;
          for (is = k; mem.get(is) != 0; ++is)          
           cout << (char)mem.get(is);
          cout << endl;

          i = is + 1;
          j = i + 1;
          k = i + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         break;
              
         default:
          crash("Invalid Type.");
          break;
        };
   }
   break;

   case IREAD:
        reg.accumulator.setType(reg.type);

        if (reg.operand != 0)
         crash("Invalid Parameter.");
        else
        {
         reg.accumulator.read();
        }

        break;

   case ILOAD:
        {
         double m;
         double * pm;
        

         reg.accumulator.setType(reg.type);

         switch (reg.accumulator.getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.operand);
               pm = &m;

               reg.accumulator.putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.operand);
               pm = &m;

               reg.accumulator.putm(pm);
               break;

          case TCHARACTER:
               pm = &m;       
               *pm = mem.get(reg.operand);
               reg.accumulator.putm(pm);
               break;

          case TSTRING:
          {           
               String str = (char *)"";
               long n;
               long o;
               for (n = reg.operand; mem.get(n) != 0; ++n)
               {
                char ch = (char)mem.get(n);
                str += ch;
               }
               PNF_String str2(str.getString());
               reg.accumulator.put(str2);
          }
          break;
              
          default:
           crash("Invalid Type.");
           break;
         }
         break;
        }

   case ISTORE:
        {
         if (reg.type != 0)
          crash("Invalid Type Identifier.");

         double * pm;
         pm = reg.accumulator.getm();
         
         switch (reg.accumulator.getType())
         {
          case TVOID:
           mem.put(reg.operand, *pm);
           break;

          case TBOOLEAN:
           mem.put(reg.operand, *pm);
           break;

          case TNUMBER:
           mem.put(reg.operand, *pm);
           break;

          case TCHARACTER:
           mem.put(reg.operand, *pm);
           break;

          case TSTRING:
           for (long i = 0; pm[i] != 0; ++i)
            mem.put(reg.operand + i, pm[i]);
           break;


          default:
           crash("Invalid Type.");
         }
        }
        break;

   case ILOADC:
        {
         double m;
         double * pm;
        

         reg.calc.setType(reg.type);

         switch (reg.calc.getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.operand);
               pm = &m;

               reg.calc.putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.operand);
               pm = &m;

               reg.calc.putm(pm);
               break;

          case TCHARACTER:
               pm = &m;       
               *pm = mem.get(reg.operand);
               reg.calc.putm(pm);
               break;

          case TSTRING:
          {           
               String str = (char *)"";
               long n;
               long o;
               for (n = reg.operand; mem.get(n) != 0; ++n)
               {
                char ch = (char)mem.get(n);
                str += ch;
               }
               PNF_String str2(str.getString());
               reg.calc.put(str2);
          }
          break;
              
          default:
           crash("Invalid Type.");
           break;
         }
         break;
        }

   case ISTOREC:
        {
         if (reg.type != 0)
          crash("Invalid Type Identifier.");

         double * pm;
         pm = reg.calc.getm();
         
         switch (reg.calc.getType())
         {
          case TVOID:
           mem.put(reg.operand, *pm);
           break;

          case TBOOLEAN:
           mem.put(reg.operand, *pm);
           break;

          case TNUMBER:
           mem.put(reg.operand, *pm);
           break;

          case TCHARACTER:
           mem.put(reg.operand, *pm);
           break;

          case TSTRING:
           for (long i = 0; pm[i] != 0; ++i)
            mem.put(reg.operand + i, pm[i]);
           break;


          default:
           crash("Invalid Type.");
         }
        }
        break;

   case IELOAD:
        {
         double m;
         double * pm;
        

         reg.accumulator.setType(reg.type);

         switch (reg.accumulator.getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.ecount);
               pm = &m;

               reg.accumulator.putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.ecount);
               pm = &m;

               reg.accumulator.putm(pm);
               break;

          case TCHARACTER:
               pm = &m;       
               *pm = mem.get(reg.ecount);
               reg.accumulator.putm(pm);
               break;

          case TSTRING:
          {           
               String str = (char *)"";
               long n;
               long o;
               for (n = reg.ecount; mem.get(n) != 0; ++n)
               {
                char ch = (char)mem.get(n);
                str += ch;
               }
               PNF_String str2(str.getString());
               reg.accumulator.put(str2);
          }
          break;
              
          default:
           crash("Invalid Type.");
           break;
         }
         break;
        }

   case IESTORE:
        {
         if (reg.operand != 0)
          crash("Invalid Operand.");
         if (reg.type != 0)
          crash("Invalid Type Identifier.");

         double * pm;
         pm = reg.accumulator.getm();
         
         switch (reg.accumulator.getType())
         {
          case TVOID:
           mem.insert();
           mem.insert();
           mem.insert();
           mem.put(reg.ecount + 3, *pm);
           reg.ecount += 3;
           break;

          case TBOOLEAN:
           mem.insert();
           mem.insert();
           mem.insert();
           mem.put(reg.ecount + 3, *pm);
           reg.ecount += 3;
           break;

          case TNUMBER:
           mem.insert();
           mem.insert();
           mem.insert();
           mem.put(reg.ecount + 3, *pm);
           reg.ecount += 3;
           break;

          case TCHARACTER:
           mem.insert();
           mem.insert();
           mem.insert();
           mem.put(reg.ecount + 3, *pm);
           reg.ecount += 3;
           break;

          case TSTRING:
           mem.insert();
           mem.insert();
           unsigned long is;
           for (is = 0; pm[is] != 0; ++is)
           {
           	mem.insert();
            mem.put((reg.ecount  + 3)+ is, pm[is]);
           }
           reg.ecount += is;
           reg.ecount += 2;
           break;


          default:
           crash("Invalid Type.");
         }
        }
        break;

   case IELOADC:
        {
         double m;
         double * pm;
        

         reg.calc.setType(reg.type);

         switch (reg.calc.getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.ecount);
               pm = &m;

               reg.calc.putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.ecount);
               pm = &m;

               reg.calc.putm(pm);
               break;

          case TCHARACTER:
               pm = &m;       
               *pm = mem.get(reg.ecount);
               reg.calc.putm(pm);
               break;

          case TSTRING:
          {           
               String str = (char *)"";
               long n;
               long o;
               for (n = reg.ecount; mem.get(n) != 0; ++n)
               {
                char ch = (char)mem.get(n);
                str += ch;
               }
               PNF_String str2(str.getString());
               reg.calc.put(str2);
          }
          break;
              
          default:
           crash("Invalid Type.");
           break;
         }
         break;
        }

case IESTOREC:
        {
         if (reg.operand != 0)
          crash("Invalid Operand.");
         if (reg.type != 0)
          crash("Invalid Type Identifier.");

         double * pm;
         pm = reg.calc.getm();
         
         switch (reg.calc.getType())
         {
          case TVOID:
           mem.insert();
           mem.insert();
           mem.insert();
           mem.put(reg.ecount + 3, *pm);
           reg.ecount += 3;
           break;

          case TBOOLEAN:
           mem.insert();
           mem.insert();
           mem.insert();
           mem.put(reg.ecount + 3, *pm);
           reg.ecount += 3;
           break;

          case TNUMBER:
           mem.insert();
           mem.insert();
           mem.insert();
           mem.put(reg.ecount + 3, *pm);
           reg.ecount += 3;
           break;

          case TCHARACTER:
           mem.insert();
           mem.insert();
           mem.insert();
           mem.put(reg.ecount + 3, *pm);
           reg.ecount += 3;
           break;

          case TSTRING:
           mem.insert();
           mem.insert();
           unsigned long is;
           for (is = 0; pm[is] != 0; ++is)
           {
           	mem.insert();
            mem.put((reg.ecount + 3) + is, pm[is]);
           }
           reg.ecount += is;
           reg.ecount += 2;
           break;


          default:
           crash("Invalid Type.");
         }
        }
        break;

  case IVLOAD:
        {
         double m;
         double * pm;
        

         reg.accumulator.setType(reg.type);
         reg.operand = reg.varcount.get(reg.operand);

         switch (reg.accumulator.getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.operand);
               pm = &m;

               reg.accumulator.putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.operand);
               pm = &m;

               reg.accumulator.putm(pm);
               break;

          case TCHARACTER:
               pm = &m;       
               *pm = mem.get(reg.operand);
               reg.accumulator.putm(pm);
               break;

          case TSTRING:
          {           
               String str = (char *)"";
               for (unsigned long n = reg.operand; mem.get(n) != 0; ++n)
               {
                char ch = (char)mem.get(n);
                str += ch;
               }
               PNF_String str2(str.getString());
               reg.accumulator.put(str2);
          }
          break;
              
          default:
           crash("Invalid Type.");
           break;
         }
         break;
        }

   case IVSTORE:
        {
         switch (reg.type)
         {
          case TVOID:
          {
           if (reg.operand != 0)
            crash("Invalid Operand.");

           long j = reg.ecount;
           mem.put(j, IVAR);
           mem.put(j + 1, TVOID);
           double * pm;
           pm = reg.accumulator.getm();


           reg.varcount.insert();         
           reg.varcount.put(j + 2, reg.varcount.length() - 1);
         
           switch (reg.accumulator.getType())
           {
            case TVOID:
             mem.put(j + 2, *pm);
             reg.ecount += 3;
             break;

            case TBOOLEAN:
             mem.put(j + 2, *pm);
             reg.ecount += 3;
             break;

            case TNUMBER:
             mem.put(j + 2, *pm);
             reg.ecount += 3;
             break;

            case TCHARACTER:
             mem.put(j + 2, *pm);
             reg.ecount += 3;
             break;

            case TSTRING:
             unsigned long i;
             for (i = 0; pm[i] != 0; ++i)
              mem.put((j + 2) + i, pm[i]);
             reg.ecount += 3;
             break;


            default:
             crash("Invalid Type.");
           }

           for (unsigned long j = 0, k = 0; j != reg.ecount; ++j)
           {
            if (mem.get(j) == IVAR && mem.get(j + 1) == TVOID)
            {
             reg.varcount.put(j + 2, k);
             reg.varcount.insert();
             ++k;
            }
           }
          }
          break;
           
          case TNUMBER:
          {
           long j = reg.varcount.get(reg.operand);
           double * pm;
           pm = reg.accumulator.getm();
         
           switch (reg.accumulator.getType())
           {
            case TVOID:
             mem.put(j, *pm);
             break;

            case TBOOLEAN:
             mem.put(j, *pm);             
             break;

            case TNUMBER:
             mem.put(j, *pm);
             break;

            case TCHARACTER:
             mem.put(j, *pm);             
             break;

            case TSTRING:
             unsigned long i;
             for (i = 0; pm[i] != 0; ++i)
              mem.put((j) + i, pm[i]);
             break;


            default:
             crash("Invalid Type.");
            }
           }
           break;
           
           default:
            crash("Invalid Type Identifier.");
            break;
          }
         }
         break;

  case IVLOADC:
        {
         double m;
         double * pm;
        

         reg.calc.setType(reg.type);
         reg.operand = reg.varcount.get(reg.operand);

         switch (reg.calc.getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.operand);
               pm = &m;

               reg.calc.putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.operand);
               pm = &m;

               reg.calc.putm(pm);
               break;

          case TCHARACTER:
               pm = &m;       
               *pm = mem.get(reg.operand);
               reg.calc.putm(pm);
               break;

          case TSTRING:
          {           
               String str = (char *)"";
               long n;
               long o;
               for (n = reg.operand; mem.get(n) != 0; ++n)
               {
                char ch = (char)mem.get(n);
                str += ch;
               }
               PNF_String str2(str.getString());
               reg.calc.put(str2);
          }
          break;
              
          default:
           crash("Invalid Type.");
           break;
         }
         break;
        }

   case IVSTOREC:
        {
         switch (reg.type)
         {
          case TVOID:
          {
           if (reg.operand != 0)
            crash("Invalid Operand.");

           long j = reg.ecount;
           mem.put(j, IVAR);
           mem.put(j + 1, TVOID);
           double * pm;
           pm = reg.calc.getm();


           reg.varcount.insert();         
           reg.varcount.put(j + 2, reg.varcount.length() - 1);
         
           switch (reg.calc.getType())
           {
            case TVOID:
             mem.put(j + 2, *pm);
             reg.ecount += 3;
             break;

            case TBOOLEAN:
             mem.put(j + 2, *pm);
             reg.ecount += 3;
             break;

            case TNUMBER:
             mem.put(j + 2, *pm);
             reg.ecount += 3;
             break;

            case TCHARACTER:
             mem.put(j + 2, *pm);
             reg.ecount += 3;
             break;

            case TSTRING:
             unsigned long i;
             for (i = 0; pm[i] != 0; ++i)
              mem.put((j + 2) + i, pm[i]);
             reg.ecount += 3;
             break;


            default:
             crash("Invalid Type.");
           }

           for (unsigned long j = 0, k = 0; j != reg.ecount; ++j)
           {
            if (mem.get(j) == IVAR && mem.get(j + 1) == TVOID)
            {
             reg.varcount.put(j + 2, k);
             reg.varcount.insert();
             ++k;
            }
           }
          }
          break;
           
          case TNUMBER:
          {
           long j = reg.varcount.get(reg.operand);
           double * pm;
           pm = reg.calc.getm();
         
           switch (reg.calc.getType())
           {
            case TVOID:
             mem.put(j, *pm);
             break;

            case TBOOLEAN:
             mem.put(j, *pm);             
             break;

            case TNUMBER:
             mem.put(j, *pm);
             break;

            case TCHARACTER:
             mem.put(j, *pm);             
             break;

            case TSTRING:
             unsigned long i;
             for (i = 0; pm[i] != 0; ++i)
              mem.put((j) + i, pm[i]);
             break;


            default:
             crash("Invalid Type.");
            }
           }
           break;
           
           default:
            crash("Invalid Type Identifier.");
            break;
          }
         }
         break;
        
   case ISTOREA:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid STOREA instruction.");
   	 
   	unsigned long address = (unsigned long)reg.calc.to_number().get();
   	mem.put(address, reg.accumulator.to_number().get());
   }
   break;

   case IMODT:
        {
         if (reg.operand == 0)
          reg.accumulator.setType(reg.type);
         else
          crash("Invalid Operand.");
        }
        break;

   case IMODCT:
        {
         if (reg.operand == 0)
          reg.calc.setType(reg.type);
         else
          crash("Invalid Operand.");
        }
        break;

   case IADD:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           switch (reg.accumulator.getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.to_number();
             tn.add(reg.calc.to_number().get());
             reg.accumulator.put(tn);
             break;
            }

            case TSTRING:
            {
             PNF_String ts = reg.accumulator.to_string();
             ts.add(reg.calc.to_string().get());
             reg.accumulator.put(ts);
             break;
            }

            default:
             crash("Invalid ADD Instruction.");
             break;
           }
          }
          else
           crash("Invalid ADD Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            reg.accumulator.to_number().add(reg.operand);
           }
           break;

           case TCHARACTER:
            reg.accumulator.to_character().add(reg.operand);
            break;

           case TSTRING:
           {
            unsigned long i2 = 0;
            for (i2 = k; mem.get(i2) != 0; ++i2)
             reg.accumulator.to_character().add((char)mem.get(i2));
            i = i2;
            j = i + 1;
            k = i + 2;             
           }
           break;

           default:
            crash("Invalid ADD Instruction.");
          }
         }
        }
        break;

   case ISUB:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           switch (reg.accumulator.getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.to_number();
             tn.sub(reg.calc.to_number().get());
             reg.accumulator.put(tn);
             break;
            }

            default:
             crash("Invalid SUB Instruction.");
             break;
           }
          }
          else
           crash("Invalid SUB Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.to_number().sub(reg.operand);
            break;

           default:
            crash("Invalid SUB Instruction.");
          }
         }
         break;
        }

   case IMUL:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           switch (reg.accumulator.getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.to_number();
             tn.mul(reg.calc.to_number().get());
             reg.accumulator.put(tn);
             break;
            }

            default:
             crash("Invalid MUL Instruction.");
             break;
           }
          }
          else
           crash("Invalid MUL Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.to_number().mul(reg.operand);
            break;

           default:
            crash("Invalid MUL Instruction.");
          }
         }
         break;
        }

   case IDIV:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           switch (reg.accumulator.getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.to_number();
             tn.div(reg.calc.to_number().get());
             reg.accumulator.put(tn);
             break;
            }

            default:
             crash("Invalid DIV Instruction.");
             break;
           }
          }
          else
           crash("Invalid DIV Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.to_number().div(reg.operand);
            break;

           default:
            crash("Invalid DIV Instruction.");
          }
         }
         break;
        }

        case IMOD:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           switch (reg.accumulator.getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.to_number();
             tn.mod(reg.calc.to_number().get());
             reg.accumulator.put(tn);
             break;
            }

            default:
             crash("Invalid MOD Instruction.");
             break;
           }
          }
          else
           crash("Invalid MOD Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.to_number().sub(reg.operand);
            break;

           default:
            crash("Invalid MOD Instruction.");
          }
         }
         break;
        }

   case IPOW:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           switch (reg.accumulator.getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.to_number();
             tn.pow(reg.calc.to_number().get());
             reg.accumulator.put(tn);
             break;
            }

            default:
             crash("Invalid POW Instruction.");
             break;
           }
          }
          else
           crash("Invalid POW Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.to_number().pow(reg.operand);
            break;

           default:
            crash("Invalid POW Instruction.");
          }
         }
         break;
        }

   case IROOT:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          switch (reg.accumulator.getType())
          {
           case TNUMBER:
           {
            PNF_Number tn = reg.accumulator.to_number();
            tn.root(reg.accumulator.to_number().get());
            reg.accumulator.put(tn);
            break;
           }

           default:
            crash("Invalid ROOT Instruction.");
            break;
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.to_number().root(reg.operand);
            break;

           default:
            crash("Invalid ROOT Instruction.");
          }
         }
        }
        break;

   case IINC:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          switch (reg.accumulator.getType())
          {
           case TNUMBER:
           {
            PNF_Number tn = reg.accumulator.to_number();
            tn.inc(1);
            reg.accumulator.put(tn);
            break;
           }

           default:
            crash("Invalid INC Instruction.");
            break;
          }
         }
         else
          crash("Invalid INC Instruction.");
        }
        break;

   case IDEC:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          switch (reg.accumulator.getType())
          {
           case TNUMBER:
           {
            PNF_Number tn = reg.accumulator.to_number();
            tn.dec(1);
            reg.accumulator.put(tn);
            break;
           }

           default:
            crash("Invalid DEC Instruction.");
            break;
          }
         }
         else
          crash("Invalid DEC Instruction.");
        }
        break;

   case IEQU:
        {
         if (reg.type == TVOID && reg.operand == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           bool b = (reg.accumulator.to_number().get() == reg.calc.to_number().get());
           PNF_Boolean b2;
           b2.put(b);
           reg.accumulator.put(b2);
          }
         }
         else
         {
          switch (reg.type)
          {
           case TBOOLEAN:
           {
             bool b = (reg.accumulator.to_boolean().get().getString() == "true" ? true : false);
             bool b2 = (reg.operand == 0 ? false : true);
             bool b3 = b && b2;
             PNF_Boolean b4;
             b4.put(b3);
             reg.accumulator.put(b4);
            }
            break;

           case TNUMBER:
           {
            bool b = (reg.accumulator.to_number().get() == reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.to_character().get() == (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           default:
            crash("Invalid Type.");
          }
         }
        }
        break;

   case INEQU:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           bool b = (reg.accumulator.to_number().get() != reg.calc.to_number().get());
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
          }
         }
         else
         {
          switch (reg.type)
          {
           case TBOOLEAN:
           {
             bool b = (reg.accumulator.to_boolean().get().getString() != "true" ? true : false);
             bool b2 = (reg.operand == 0 ? false : true);
             bool b3 = b && b2;
             PNF_Boolean b4;
             b4.put(b3);
             reg.accumulator.put(b4);
            }
            break;

           case TNUMBER:
           {
            bool b = (reg.accumulator.to_number().get() != reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.to_character().get() != (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           default:
            crash("Invalid Type.");
          }
         }
        }
        break;

   case IGTR:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           bool b = (reg.accumulator.to_number().get() > reg.calc.to_number().get());
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            bool b = (reg.accumulator.to_number().get() > reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.to_character().get() > (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           default:
            crash("Invalid Type.");
          }
         }
        }
        break;

   case ILSS:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           bool b = (reg.accumulator.to_number().get() < reg.calc.to_number().get());
           PNF_Boolean b2;
           b2.put(b);
           reg.accumulator.put(b2);           
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            bool b = (reg.accumulator.to_number().get() < reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.to_character().get() < (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           default:
            crash("Invalid Type.");
          }
         }
        }
        break;

   case IGEQU:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           bool b = (reg.accumulator.to_number().get() >= reg.calc.to_number().get());
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            bool b = (reg.accumulator.to_number().get() >= reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.to_character().get() >= (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           default:
            crash("Invalid Type.");
          }
         }
        }
        break;

   case ILEQU:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           bool b = (reg.accumulator.to_number().get() <= reg.calc.to_number().get());
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            bool b = (reg.accumulator.to_number().get() <= reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.to_character().get() <= (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
           break;

           default:
            crash("Invalid Type.");
          }
         }
        }
        break;

   case IAND:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           bool b = (reg.accumulator.to_boolean().get().getString() == "true" && reg.calc.to_boolean().get().getString() == "true");
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
          }
         }
        }
        break;

        case IOR:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.getType() == reg.calc.getType())
          {
           bool b = (reg.accumulator.to_boolean().get().getString() == "true" || reg.calc.to_boolean().get().getString() == "true");
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.put(b2);
           }
          }
         }
        }
        break;

        case INOT:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.to_boolean().get().getString() == "true")
           reg.accumulator.to_boolean().put(false);
          else
           reg.accumulator.to_boolean().put(true);
         }
        }
        break;

   case IGOTO:
        if (reg.type == 0)
        {
         i = reg.operand;
         j = reg.operand + 1;
         k = reg.operand + 2;

         i = i - 3;
         j = i + 1;
         k = i + 2;
        }
        else
         crash("Invalid GOTO.");
        break;

  case ICGOTO:
        if (reg.type == 0)
        {
         if (reg.accumulator.to_boolean().get().getString() == "true")
         {
          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
        }
        else
         crash("Invalid CGOTO.");
        break;

   case IZGOTO:
        if (reg.accumulator.to_number().get() == 0)
        {
         if (reg.type == 0)
         {
          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else
          crash("Invalid ZGOTO.");
        }
        break;

   case IPGOTO:
        if (reg.accumulator.to_number().get() > 0)
        {
         if (reg.type == 0)
         {
          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else
          crash("Invalid PGOTO.");
        }
        break;

   case INGOTO:
        if (reg.accumulator.to_number().get() < 0)
        {
         if (reg.type == 0)
         {
          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else
          crash("Invalid NGOTO.");
        }
        break;

   case IGOTOL:
        if (reg.type == TVOID)
        {
         reg.operand = reg.labels.get(reg.operand).getNum();        

         i = reg.operand;
         j = reg.operand + 1;
         k = reg.operand + 2;

         i = i - 3;
         j = i + 1;
         k = i + 2;
        }
        else if (reg.type == TSTRING)
        {
         String lblname = "";
         unsigned long is;
         for (is = k; mem.get(is) != 0; ++is)
          lblname += (char)mem.get(is);
          
         for (unsigned long is2 = 0; is2 < reg.labels.length(); ++is2)
         {
          if (reg.labels.get(is2).getString().getString() == lblname.getString())
          {
           reg.operand = reg.labels.get(is2).getNum();           
           break;
          }
          else
           reg.operand = is + 1;
         }

         i = reg.operand;
         j = reg.operand + 1;
         k = reg.operand + 2;

         i = i - 3;
         j = i + 1;
         k = i + 2;
        }
        else
         crash("Invalid GOTOL.");
        break;

  case ICGOTOL:
        if (reg.type == 0)
        {
         if (reg.accumulator.to_boolean().get().getString() == "true")
         {
          reg.operand = reg.labels.get(reg.operand).getNum();        

          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
        }
        else if (reg.type == TSTRING)
        {
         if (reg.accumulator.to_boolean().get().getString() == "true")
         {
          String lblname = "";
          unsigned long is;
          for (is = k; mem.get(is) != 0; ++is)
           lblname += (char)mem.get(is);
          
          for (unsigned long is2 = 0; is2 < reg.labels.length(); ++is2)
          {
           if (reg.labels.get(is2).getString().getString() == lblname.getString())
           {
            reg.operand = reg.labels.get(is2).getNum();           
            break;
           }
           else
           {
            reg.operand = is + 1;
           }
          }

          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else
         {
          unsigned long is;
          for (is = k; mem.get(is) != 0; ++is)
           ;
           
          reg.operand = is + 1;
          
          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
        }
        else
         crash("Invalid CGOTOL.");
        break;

   case IZGOTOL:
        if (reg.accumulator.to_number().get() == 0)
        {
         if (reg.type == 0)
         {
          reg.operand = reg.labels.get(reg.operand).getNum();        

          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else if (reg.type == TSTRING)
         {
          String lblname = "";
          unsigned long is;
          for (is = k; mem.get(is) != 0; ++is)
           lblname += (char)mem.get(is);
          
          for (unsigned long is2 = 0; is2 < reg.labels.length(); ++is2)
          {
           if (reg.labels.get(is2).getString().getString() == lblname.getString())
           {
            reg.operand = reg.labels.get(is2).getNum();           
            break;
           }
           else
            reg.operand = is + 1;
          }

          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else
          crash("Invalid ZGOTOL.");
        }
        break;

   case IPGOTOL:
        if (reg.accumulator.to_number().get() > 0)
        {
         if (reg.type == 0)
         {
          reg.operand = reg.labels.get(reg.operand).getNum();        

          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else if (reg.type == TSTRING)
         {
          String lblname = "";
          unsigned long is;
          for (is = k; mem.get(is) != 0; ++is)
           lblname += (char)mem.get(is);
          
          for (unsigned long is2 = 0; is2 < reg.labels.length(); ++is2)
          {
           if (reg.labels.get(is2).getString().getString() == lblname.getString())
           {
            reg.operand = reg.labels.get(is2).getNum();           
            break;
           }
           else
            reg.operand = is + 1;
          }

          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else
          crash("Invalid PGOTOL.");
        }
        break;

   case INGOTOL:
        if (reg.accumulator.to_number().get() < 0)
        {
         if (reg.type == 0)
         {
          reg.operand = reg.labels.get(reg.operand).getNum();        

          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else if (reg.type == TSTRING)
         {
          String lblname = "";
          unsigned long is;
          for (is = k; mem.get(is) != 0; ++is)
           lblname += (char)mem.get(is);
          
          for (unsigned long is2 = 0; is2 < reg.labels.length(); ++is2)
          {
           if (reg.labels.get(is2).getString().getString() == lblname.getString())
           {
            reg.operand = reg.labels.get(is2).getNum();           
            break;
           }
           else
            reg.operand = is + 1;
          }

          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         else
          crash("Invalid NGOTOL.");
        }
        break;

   case IST:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          reg.calc.to_number().dec(1);
          if (reg.calc.to_number().get() == 0)
           reg.accumulator.put(reg.calc.to_number());
         }
        }
        break;

   case IPUSH:
        if (reg.operand == 0)
        {
         switch (reg.type)
         {
          case TVOID:
                  {                               
                   stk.push(reg.accumulator);                   
                  } 
                  break;

          default:
                  crash("Invalid PUSH.");
                  break;                 
         }
        }
        else
            crash("Invalid PUSH.");
        break;

       case IPOP:
        {
         if (reg.operand == 0)
         {         
          switch (reg.type)
          {
           case TVOID:  
           {                                    
                   reg.accumulator = stk.top();
                   stk.pop();
                   break;
           }

           default:
                   crash("Invalid POP.");
                   break;
          }
         }
         else
             crash("Invalid POP.");
        }
        break;

       case ICALL:
        if (reg.type == 0)
        {
         // Push current instruction address.
         PNF_Number n(i);
         PNF_Variable v(n);
         substk.push(v);

         // GOTO Address
          i = reg.operand;
          j = reg.operand + 1;
          k = reg.operand + 2;

         i = i - 3;
         j = i + 1;
         k = i + 2;
         
         
         if (inBreakpoint)
          ++inSubBreakpoint;
        }
        else
         crash("Invalid CALL.");
        break;

       case ICALLL:
        if (reg.type == 0)
        {
         // Push current instruction address.
         PNF_Number n(i);
         PNF_Variable v(n);
         substk.push(v);

         // GOTO Address
         reg.operand = reg.labels.get(reg.operand).getNum();

         i = reg.operand;
         j = reg.operand + 1;
         k = reg.operand + 2;

         i = i - 3;
         j = i + 1;
         k = i + 2;
        }
        else if (reg.type == TSTRING)
        {
         // Push current instruction address.
         unsigned long is;
         for (is = k; mem.get(is) != 0; ++is)
          ;
         PNF_Number n(is - 2);
         PNF_Variable v(n);
         substk.push(v);

         // GOTO Address		    
         String lblname = "";
         for (is = k; mem.get(is) != 0; ++is)
          lblname += (char)mem.get(is);
          
         for (unsigned long is2 = 0; is2 < reg.labels.length(); ++is2)
         {
          if (reg.labels.get(is2).getString() == lblname)
          {
           reg.operand = reg.labels.get(is2).getNum();           
           break;
          }
          else
           reg.operand = is + 1;
         }

         i = reg.operand;
         j = reg.operand + 1;
         k = reg.operand + 2;

         i = i - 3;
         j = i + 1;
         k = i + 2;
         
         
         if (inBreakpoint)
          ++inSubBreakpoint;
        }        
        else
         crash("Invalid CALLL.");
        break;

       case IRET:
        if (reg.type == 0 && reg.operand == 0)
        {
         PNF_Variable v = (substk.top());
         i = (unsigned long)v.to_number().get();
		 if (i == -1)
          crash("Could Not Return.");
          
         i += 3;
         substk.pop();

         // GOTO Address          
         j = i + 1;
         k = i + 2;

         i = i - 3;
         j = i + 1;
         k = i + 2;
         
         if (inSubBreakpoint != 0)
          --inSubBreakpoint;
          
         inRet = true;
         inBreakpoint = false;
        }
        else
         crash("Invalid RET.");
         
        break;


   case IVAR:
        {
         // Work done on loads2().
        }
        break;

   case ILBL:
        {
         if (reg.type == TSTRING)
         {
          unsigned long is;
          for (is = k; mem.get(is) != 0; ++is)
           ;                
          
          i = is + 1;
          j = i + 1;
          k = i + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         // If not TSTRING, we don't need to process here...
        }
        break;

   case IEPRINT:
   {
        switch (reg.type)
        {
         case TVOID:
         {
          if (reg.operand != 0)
           crash("Invalid VOID Value.");
          else
          {
           reg.accumulator.eprint();
          }
         }
         break;

         case TBOOLEAN:
          switch (reg.operand)
          {
           case 0:
            cerr << "false";
            break;

           case 1:
            cerr << "true";
            break;

           default:
            cerr << "true";
            break;
          }
          break;

         case TNUMBER:
          cerr << reg.operand;
          break;

         case TCHARACTER:
          cerr << (char)reg.operand;
          break;

         case TSTRING:
         {
          unsigned long is = 0;
          for (is = k; mem.get(is) != 0; ++is)
           cerr << (char)mem.get(is);

          i = is + 1;
          j = i + 1;
          k = i + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         break;
              
         default:
          crash("Invalid Type.");
          break;
        };
   }
        break;

   case IEPRINTLN:
   {
        switch (reg.type)
        {
         case TVOID:
              if (reg.operand != 0)
               crash("Invalid VOID Value.");
              else
              {
               reg.accumulator.eprintln();
              }
              break;

         case TBOOLEAN:
          switch (reg.operand)
          {
           case 0:
            cerr << "false\n";
            break;

           case 1:
            cerr << "true\n";
            break;

           default:
            cerr << "true\n";
            break;
          }
          break;

         case TNUMBER:
          cerr << reg.operand << endl;
          break;

         case TCHARACTER:
          cerr << (char)reg.operand << endl;
          break;

         case TSTRING:
         {
          unsigned long is = 0;
          for (is = k; mem.get(is) != 0; ++is)
           cerr << (char)mem.get(is);
          cerr << endl;

          i = is + 1;
          j = i + 1;
          k = i + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
         }
         break;
              
         default:
          crash("Invalid Type.");
          break;
        };
   }
        break;
 
   case IEND:
   {
    // Do nothing, just a marker for the end.
   }
   break;

   case IELBL:
   {
    // Work done on loads2().
   }
   break;

   case IEVLOAD:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.evalue = (unsigned long)reg.operand;
   }
   break;

   case IHEADD:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.hevents.add(reg.operand);
   }
   break;

   case IHEREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash("Invalid Type or Void Value.");
    else
     reg.hevents.remove();
   }
   break;

   case IHEED:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.hevents.edit(reg.evalue, reg.operand);
   }
   break;

   case IHEGET:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.evalue = reg.hevents.get(reg.operand);
   }
   break;

   case ISHEADD:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.shevents.add(reg.operand);
   }
   break;

   case ISHEREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash("Invalid Type or Void Value.");
    else
     reg.shevents.remove();
   }
   break;

   case ISHEED:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.shevents.edit(reg.evalue, reg.operand);
   }
   break;

   case ISHEGET:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.evalue = reg.shevents.get(reg.operand);
   }
   break;

   case IEADD:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.events.add(reg.operand);
   }
   break;

   case IEREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash("Invalid Type or Void Value.");
    else
     reg.events.remove();
   }
   break;

   case IEED:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.events.edit(reg.evalue, reg.operand);
   }
   break;

   case IEGET:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.evalue = reg.events.get(reg.operand);
   }
   break;

   case IEXADD:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.exceptions.add(reg.operand);
   }
   break;

   case IEXREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash("Invalid Type or Void Value.");
    else
     reg.exceptions.remove();
   }
   break;

   case IEXED:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
    {
     reg.exceptions.edit(reg.evalue, reg.operand);
    }
   }
   break;

   case IEXGET:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.evalue = reg.exceptions.get(reg.operand);
   }
   break;

   case IIADD:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.interrupts.add(reg.operand);
   }
   break;

   case IIREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash("Invalid Type or Void Value.");
    else
     reg.interrupts.remove();
   }
   break;

   case IIED:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.interrupts.edit(reg.evalue, reg.operand);
   }
   break;

   case IIGET:
   {
    if (reg.type != TVOID)
     crash("Invalid Type.");
    else
     reg.evalue = reg.interrupts.get(reg.operand);
   }
   break;

   case IHEVENT:
   {
    if (reg.type == 0)
    {
     // Push current instruction address.
     PNF_Number n(i);
     PNF_Variable v(n);
     substk.push(v);

     // GOTO Address
     reg.operand = reg.hevents.get(reg.operand);
     reg.operand = reg.elabels.get(reg.operand);

     i = reg.operand;
     j = reg.operand + 1;
     k = reg.operand + 2;

     i = i - 3;
     j = i + 1;
     k = i + 2;
     
     
     if (inBreakpoint)
      ++inSubBreakpoint;
    }
    else
     crash("Invalid HEVENT.");
   }
   break;

   case ISHEVENT:
   {
    if (reg.type == 0)
    {
     // Push current instruction address.
     PNF_Number n(i);
     PNF_Variable v(n);
     substk.push(v);

     // GOTO Address
     reg.operand = reg.shevents.get(reg.operand);
     reg.operand = reg.elabels.get(reg.operand);

     i = reg.operand;
     j = reg.operand + 1;
     k = reg.operand + 2;

     i = i - 3;
     j = i + 1;
     k = i + 2;
     
     
     if (inBreakpoint)
      ++inSubBreakpoint;
    }
    else
     crash("Invalid SHEVENT.");
   }
   break;

   case IEVENT:
   {
    if (reg.type == 0)
    {
     // Push current instruction address.
     PNF_Number n(i);
     PNF_Variable v(n);
     substk.push(v);

     // GOTO Address
     reg.operand = reg.events.get(reg.operand);
     reg.operand = reg.elabels.get(reg.operand);

     i = reg.operand;
     j = reg.operand + 1;
     k = reg.operand + 2;

     i = i - 3;
     j = i + 1;
     k = i + 2;
     
     
     if (inBreakpoint)
      ++inSubBreakpoint;
    }
    else
     crash("Invalid EVENT.");
   }
   break;

   case IEXCEPTION:
   {
    if (reg.type == 0)
    {
     // Push current instruction address.
     PNF_Number n(i);
     PNF_Variable v(n);
     substk.push(v);

     // GOTO Address
     reg.operand = reg.exceptions.get(reg.operand);
     reg.operand = reg.elabels.get(reg.operand);

     i = reg.operand;
     j = reg.operand + 1;
     k = reg.operand + 2;

     i = i - 3;
     j = i + 1;
     k = i + 2;
     
     
     if (inBreakpoint)
      ++inSubBreakpoint;
    }
    else
     crash("Invalid EXCEPTION.");
   }
   break;

   case IINT:
   {
    if (reg.type == 0)
    {
     // Push current instruction address.
     PNF_Number n(i);
     PNF_Variable v(n);
     substk.push(v);

     // GOTO Address
     reg.operand = reg.interrupts.get(reg.operand);
     reg.operand = reg.elabels.get(reg.operand);

     i = reg.operand;
     j = reg.operand + 1;
     k = reg.operand + 2;

     i = i - 3;
     j = i + 1;
     k = i + 2;
     
     
     if (inBreakpoint)
      ++inSubBreakpoint;
    }
    else
     crash("Invalid INT.");
   }
   break;
   
   case ITYPEOF:
   {
   	if (reg.type != TVOID && reg.operand != 0)
   	 crash("Invalid TYPEOF.");
   	 
   	long ttype = reg.accumulator.getType();
   	String type;
   	switch (ttype)
   	{
   	 case TVOID:
   	  type = "VOID";
   	  break;
   	  
   	 case TBOOLEAN:
   	  type = "BOOLEAN";
   	  break;
   	  
   	 case TNUMBER:
   	  type = "NUMBER";
   	  break;
   	  
   	 case TCHARACTER:
   	  type = "CHARACTER";
   	  break;
   	 	
   	 case TSTRING:
   	  type = "STRING";
   	  break;
   	 	
   	 default:
   	  type = "UNKNOWN";
   	  break;
   	}
   	reg.type_of = type;
   }
   break;
   
   case ICTYPEOF:
   {
   	if (reg.type != TVOID && reg.operand != 0)
   	 crash("Invalid CTYPEOF.");
   	 
   	long ttype = reg.calc.getType();
   	String type;
   	switch (ttype)
   	{
   	 case TVOID:
   	  type = "VOID";
   	  break;
   	  
   	 case TBOOLEAN:
   	  type = "BOOLEAN";
   	  break;
   	  
   	 case TNUMBER:
   	  type = "NUMBER";
   	  break;
   	  
   	 case TCHARACTER:
   	  type = "CHARACTER";
   	  break;
   	 	
   	 case TSTRING:
   	  type = "STRING";
   	  break;
   	 	
   	 default:
   	  type = "UNKNOWN";
   	  break;
   	}
   	reg.type_of = type;
   }
   break;
   
   case ITLOAD:
   {
   	if (reg.type != TVOID && reg.operand != 0)
   	 crash("Invalid TLOAD.");
   	 
   	reg.accumulator.put(reg.type_of);
   }
   break;
   
   
   case IALOAD:
   {
   	switch (reg.type)
   	{
   	 case TVOID:
   	 {
   	  if (reg.operand != 0)
   	   crash("Invalid VOID Value.");
   	   
   	  PNF_Void v;
   	  reg.accumulator.put(v);
     }
   	 break;
   	  
   	 case TBOOLEAN:
   	 {
   	  PNF_Boolean b;
   	  switch (reg.operand)
   	  {
   	   case 0:
   	   	b.put(false);
   	   	break;
   	   	
   	   case 1:
   	   	b.put(true);
   	   	break;
   	   	
   	   default:
   	   	b.put(true);
   	   	break;
   	  }
   	  reg.accumulator.put(b);
   	 }
   	 break;
   	  
   	 case TNUMBER:
   	 {
   	  PNF_Number n(mem.get(k));
   	  reg.accumulator.put(n);
   	 }
   	 break;
   	  
   	 case TCHARACTER:
   	 {
   	  PNF_Character c(reg.operand);
   	  reg.accumulator.put(c);
   	 }
   	 break;
   	  
   	 case TSTRING:
   	 {
   	  String str = "";
   	  unsigned long is;
   	  for (is = k; mem.get(is) != 0; ++is)
   	  {
   	   str += (char)mem.get(is);
   	  }
   	  PNF_String s(str);
   	  reg.accumulator.put(s);
   	  
   	  
      i = is + 1;
      j = i + 1;
      k = i + 2;

      i = i - 3;
      j = i + 1;
      k = i + 2;
   	 }
   	 break;
   	  
   	 default:
   	  crash("Invalid Type.");
   	  break;
   	}
   }
   break;
   
   
   case IINLOAD:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid INLOAD instruction.");
   	 
   	PNF_String s(reg.iname);
   	reg.accumulator.put(s);
   }
   break;
   
   
   case IICLOAD:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid ICLOAD instruction.");
   	 
   	PNF_Number n(reg.icount);
   	reg.accumulator.put(n);
   }
   break;
   
   
   case IARLOAD:
   {
   	if (reg.type != 0)
   	 crash("Invalid ARLOAD instruction.");
   	 
   	PNF_String s(reg.args.get(reg.operand));
   	reg.accumulator.put(s);
   }
   break;
   
   
   case IATOC:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid ATOC instruction.");
   	 
   	reg.calc = reg.accumulator;
   }
   break;
   
   
   case ISWITCH:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid SWITCH instruction.");
   	
   	PNF_Variable v = reg.accumulator;
   	reg.accumulator = reg.calc;
   	reg.calc = v;
   }
   break;
   
   
   case IVADD:
   {
   	if (reg.type == TVOID)
   	{ 
   	PNF_Number n(reg.varcount.get(reg.operand));
   	reg.accumulator.put(n);
    }
    else
     crash("Invalid VADD instruction.");
   }
   break;
   
   
   case ILADD:
   {
   	if (reg.type != 0)
   	 crash("Invalid LADD instruction.");
   	 
   	PNF_Number n(reg.labels.get(reg.operand).getNum());
   	reg.accumulator.put(n);
   }
   break;
   
   
   case IELADD:
   {
   	if (reg.type != 0)
   	 crash("Invalid ELADD instruction.");
   	 
   	PNF_Number n(reg.elabels.get(reg.operand));
   	reg.accumulator.put(n);
   }
   break;
   
   case IADD2V:
   {
   	if (reg.type == TVOID && reg.operand == 0)
   	{
   	 unsigned long address = (unsigned long)reg.accumulator.to_number().get();
   	 double value = mem.get(address);
   	  	 
   	 PNF_Number n(value);
   	 reg.accumulator.put(n);
   	}
   	else
   	 crash("Invalid ADD2V instruction.");
   }
   break;
   
   case IBTAND:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid BTAND instruction.");
   	 
   	unsigned long n1 = (unsigned long)reg.accumulator.to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.to_number().get();
   	unsigned long n3 = n1 & n2;
   	PNF_Number n(n3);
   	reg.accumulator.put(n);
   }
   break;
   
   
   case IBTOR:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid BTOR instruction.");
   	 
   	unsigned long n1 = (unsigned long)reg.accumulator.to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.to_number().get();
   	unsigned long n3 = n1 | n2;
   	PNF_Number n(n3);
   	reg.accumulator.put(n);
   }   	
   break;
   
   
   case IBTEXOR:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid BTEXOR instruction.");
   	 
   	unsigned long n1 = (unsigned long)reg.accumulator.to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.to_number().get();
   	unsigned long n3 = n1 ^ n2;
   	PNF_Number n(n3);
   	reg.accumulator.put(n);
   }
   break;
   
   
   case IBTNOT:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid BTNOT instruction.");
   	 
   	unsigned long n1 = (unsigned long)reg.accumulator.to_number().get();
   	unsigned long n3 = ~n1;
   	PNF_Number n(n3);
   	reg.accumulator.put(n);
   }
   break;
   
   
   case IBTSL:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid BTSL instruction.");
   	 
   	unsigned long n1 = (unsigned long)reg.accumulator.to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.to_number().get();
   	unsigned long n3 = n1 << n2;
   	PNF_Number n(n3);
   	reg.accumulator.put(n);
   }
   break;
   
   
   case IBTSR:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid BTSR instruction.");
   	 
   	unsigned long n1 = (unsigned long)reg.accumulator.to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.to_number().get();
   	unsigned long n3 = n1 >> n2;
   	PNF_Number n(n3);
   	reg.accumulator.put(n);
   }
   break;
   
   case IVCHECK:
   {
    bool vcheck = false;
    PNF_Boolean b;
    switch (reg.version.base.getType())
    {
   	 case TVOID:
   	 {
   	  if ((unsigned long)reg.version.top == reg.operand)
   	  {
   	   vcheck = true;
   	   b.put(vcheck);
   	   reg.accumulator.put(b);
   	  }
   	  else
   	  {
   	   vcheck = false;
   	   b.put(vcheck);
   	   reg.accumulator.put(b);   	
   	  }
   	 }
   	 break;
   	
   	 default:
   	 {
   	  vcheck = false;
   	  b.put(vcheck);
   	  reg.accumulator.put(b);
   	 }
    }
   }
   break;
  
   case IVSUPP:
   {
    bool vcheck = false;
    PNF_Boolean b;
   
    for (unsigned long l = 0; l < reg.sversion.length(); ++l)
    {
     switch (reg.sversion[l].base.getType())
     {
      case TVOID:
      {       
   	   if ((unsigned long)reg.sversion[l].top == reg.operand)
   	   {
   	   	vcheck = true;
        b.put(vcheck);
        reg.accumulator.put(b);
        goto endloop;
       }
   	   else
   	   {
        vcheck = false;
        b.put(vcheck);
        reg.accumulator.put(b);   	
       }
   	  }
      break;
   	
      default:
      {
       vcheck = false;
   	   b.put(vcheck);
   	   reg.accumulator.put(b);
   	  }
     }
    }
    endloop:
     ;
   }
   break;
   
   case IVPRINT:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash("Invalid VPRINT instruction.");
   	 
   	reg.version.base.print();
   	cout << " " << reg.version.top;
   }
   break;
   
   case IVPRINTLN:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash("Invalid VPRINTLN instruction.");
   	 
   	reg.version.base.print();
   	cout << " " << reg.version.top << endl;
   }
   break;
   
   case IISUPP:
   {
   	if (reg.type != TNUMBER)
   	 crash("Invalid ISUPP instruction.");
   	 
   	for (unsigned long is = 0; is < reg.sinstruction.length(); ++is)
   	{
   	 bool icheck = false;
   	 PNF_Boolean b;
   	 
   	 if (reg.sinstruction[is] == reg.operand)
   	 {
   	  icheck = true;
   	  b.put(icheck);
   	  reg.accumulator.put(b);
   	  break;
   	 }
   	 else
   	 { 
   	  icheck = false;
   	  b.put(icheck);
   	  reg.accumulator.put(b);
   	 }
   	}
   }
   break;
   
   case ITSUPP:
   {
   	if (reg.type != TNUMBER)
   	 crash("Invalid TSUPP instruction.");
   	 
   	for (unsigned long is = 0; is < reg.stype.length(); ++is)
   	{
   	 bool tcheck = false;
   	 PNF_Boolean b;
   	 
   	 if (reg.stype[is] == reg.operand)
   	 {
   	  tcheck = true;
   	  b.put(tcheck);
   	  reg.accumulator.put(b);
   	  break;
   	 }
   	 else
   	 {
   	  tcheck = false;
   	  b.put(tcheck);
   	  reg.accumulator.put(b);
   	 }
   	}
   }
   break;
   
   case ICOMMENT:
   {
   	if (reg.type != TSTRING)
   	 crash("Invalid COMMENT instruction.");
   	else
   	{
  	 unsigned long is = 0;
     for (is = k; mem.get(is) != 0; ++is)          
      ; // Ignore comment...
          
     i = is + 1;
     j = i + 1;
     k = i + 2;

     i = i - 3;
     j = i + 1;
     k = i + 2;
   	}
   }
   break;
   
   case IFIMODE:
   {
   	String str = "";
   	
   	if (reg.type != TSTRING)
   	 crash("Invalid FIMODE instruction.");
   	else
   	{
  	 unsigned long is = 0;
     for (is = k; mem.get(is) != 0; ++is)          
      str += (char)mem.get(is);
      
     if (str == "in")
      reg.fimode = FMIN;
     else if (str == "binary")
      reg.fimode = FMBINARY;
     else
      crash("Invalid file input mode.");
          
     i = is + 1;
     j = i + 1;
     k = i + 2;

     i = i - 3;
     j = i + 1;
     k = i + 2;
   	}
   }
   break;
   
   case IFOMODE:
   {
   	String str = "";
   	
   	if (reg.type != TSTRING)
   	 crash("Invalid FOMODE instruction.");
   	else
   	{
  	 unsigned long is = 0;
     for (is = k; mem.get(is) != 0; ++is)          
      str += (char)mem.get(is);
      
     if (str == "out")
      reg.fomode = FMOUT;
     else if (str == "binary")
      reg.fomode = FMBINARY;
     else if (str == "ate")
      reg.fomode = FMATE;
     else if (str == "app")
      reg.fomode = FMAPP;
     else if (str == "trunc")
      reg.fomode = FMTRUNC;	  	  	        
     else
      crash("Invalid file output mode.");
          
     i = is + 1;
     j = i + 1;
     k = i + 2;

     i = i - 3;
     j = i + 1;
     k = i + 2;
   	}
   }
   break;
   
   case IFIOPEN:
   {
   	String str = "";
   	bool worked;
   	
   	switch (reg.type)
   	{
   	 case TVOID:
   	 {
   	  if (reg.operand != 0)
   	   crash("Invalid FIOPEN instruction.");
   	  else
   	  {
   	   str = reg.accumulator.to_string().get();
   	   switch (reg.fimode)
       {
        case FMIN:
         pnffin.open(str.getString().c_str(), ifstream::in);
         break;
    
        case FMBINARY:
         pnffin.open(str.getString().c_str(), ifstream::binary);
         break;
       
        default:
         crash("Invalid file input mode.");
       }
       worked = (pnffin);
       PNF_Boolean b(worked);
       reg.accumulator.put(b);
   	  }
   	 }
   	 break;
   	 
   	 case TSTRING:
   	 {
   	  unsigned long is = 0;
      for (is = k; mem.get(is) != 0; ++is)          
       str += (char)mem.get(is);
      
      switch (reg.fimode)
      {
       case FMIN:
        pnffin.open(str.getString().c_str(), ifstream::in);
        break;
    
       case FMBINARY:
        pnffin.open(str.getString().c_str(), ifstream::binary);
        break;
       
       default:
        crash("Invalid file input mode.");
      }
      worked = (pnffin);
      PNF_Boolean b(worked);
      reg.accumulator.put(b);
          
      i = is + 1;
      j = i + 1;
      k = i + 2;

      i = i - 3;
      j = i + 1;
      k = i + 2;	
   	 }
   	 break;
   	 
   	 default:
   	  crash("Invalid FIOPEN instruction.");
   	}
   }
   break;
   
   case IFOOPEN:
   {
   	String str = "";
   	bool worked;
   	
   	switch (reg.type)
   	{
   	 case TVOID:
   	 {
   	  if (reg.operand != 0)
   	   crash("Invalid file output mode.");
   	  else
   	  {
   	   str = reg.accumulator.to_string().get();
   	   switch (reg.fomode)
       {
        case FMOUT:
         pnffout.open(str.getString().c_str(), ofstream::out);
         break;
    
        case FMBINARY:
         pnffout.open(str.getString().c_str(), ofstream::binary);
         break;
       
        case FMATE:
         pnffout.open(str.getString().c_str(), ofstream::ate);
         break;
       
        case FMAPP:
         pnffout.open(str.getString().c_str(), ofstream::app);
         break;
       
        case FMTRUNC:
         pnffout.open(str.getString().c_str(), ofstream::trunc);
         break;
       
        default:
         crash("Invalid file output mode.");
       }
       worked = (pnffout);
       PNF_Boolean b(worked);
       reg.accumulator.put(b);
   	  }
   	 }
   	 break;
   	 
   	 case TSTRING:
   	 {
   	  unsigned long is = 0;
      for (is = k; mem.get(is) != 0; ++is)          
       str += (char)mem.get(is);
      
      switch (reg.fomode)
      {
       case FMOUT:
        pnffout.open(str.getString().c_str(), ofstream::out);
        break;
    
       case FMBINARY:
        pnffout.open(str.getString().c_str(), ofstream::binary);
        break;
       
       case FMATE:
        pnffout.open(str.getString().c_str(), ofstream::ate);
        break;
       
       case FMAPP:
        pnffout.open(str.getString().c_str(), ofstream::app);
        break;
       
       case FMTRUNC:
        pnffout.open(str.getString().c_str(), ofstream::trunc);
        break;
       
       default:
        crash("Invalid file output mode.");
      }
      worked = (pnffout);
      PNF_Boolean b(worked);
      reg.accumulator.put(b);
          
      i = is + 1;
      j = i + 1;
      k = i + 2;

      i = i - 3;
      j = i + 1;
      k = i + 2;
   	 }
   	 break;
   	 
   	 default:
   	  crash("Invalid FOOPEN instruction.");
    }   	
   }
   break;
   
   case IFREAD:
   {
    reg.accumulator.setType(reg.type);

    if (reg.operand != 0)
     crash("Invalid Parameter.");
    else
    {
     reg.accumulator.fread(pnffin);
    }   	
   }
   break;
   
   case IFPRINT:
   {
    switch (reg.type)
    {
     case TVOID:
     {
      if (reg.operand != 0)
       crash("Invalid VOID Value.");
      else
      {
       reg.accumulator.fprint(pnffout);
      }
     }
     break;

     case TBOOLEAN:
      switch (reg.operand)
      {
       case 0:
        pnffout << "false";
        break;

       case 1:
        pnffout << "true";
        break;

       default:
        pnffout << "true";
        break;
      }
      break;

     case TNUMBER:
      pnffout << reg.operand;
      break;

     case TCHARACTER:
      pnffout << (char)reg.operand;
      break;

     case TSTRING:
     {
      unsigned long is = 0;
      for (is = k; mem.get(is) != 0; ++is)          
       pnffout << (char)mem.get(is);

      i = is + 1;
      j = i + 1;
      k = i + 2;

      i = i - 3;
      j = i + 1;
      k = i + 2;
     }
     break;
              
     default:
      crash("Invalid Type.");
      break;
    };
   }
   break;
   
   case IFPRINTLN:
   {
    switch (reg.type)
    {
     case TVOID:
     {
      if (reg.operand != 0)
       crash("Invalid VOID Value.");
      else
      {
       reg.accumulator.fprint(pnffout);
      }
     }
     break;

     case TBOOLEAN:
      switch (reg.operand)
      {
       case 0:
        pnffout << "false";
        break;

       case 1:
        pnffout << "true";
        break;

       default:
        pnffout << "true";
        break;
      }
      break;

     case TNUMBER:
      pnffout << reg.operand;
      break;

     case TCHARACTER:
      pnffout << (char)reg.operand;
      break;

     case TSTRING:
     {
      unsigned long is = 0;
      for (is = k; mem.get(is) != 0; ++is)          
       pnffout << (char)mem.get(is);

      i = is + 1;
      j = i + 1;
      k = i + 2;

      i = i - 3;
      j = i + 1;
      k = i + 2;
     }
     break;
              
     default:
      crash("Invalid Type.");
      break;
    };
	pnffout << endl;   	
   }
   break;
   
   case IFICLOSE:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash("Invalid FICLOSE instruction.");
   	 
   	pnffin.close();
   }
   break;
   
   case IFOCLOSE:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash("Invalid FOCLOSE instruction.");
   	 
   	pnffout.close();
   }
   break;
   
   case IMEML:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash("Invalid MEML instruction.");
   	 
   	PNF_Number n(mem.length());
   	reg.accumulator.put(n);
   }
   break;
   
   case IFIEOF:
   {
   	bool eof = false;
   	
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash("Invalid FIEOF instruction.");
   	 
   	eofstate = pnffin.eof();
   	if (eofstate && eofstate2)
   	 eof = true;
   	else if (eofstate && !eofstate2)
   	{
   	 eof = false;
   	 eofstate2 = true;
   	}
   	PNF_Boolean b(eof);
   	reg.accumulator.put(b);
   }
   break;
   
   case IARNLOAD:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash("Invalid ARNLOAD instruction.");
   	 
   	 
   	PNF_Number n(reg.args.length());
   	reg.accumulator.put(n);
   }
   break;
        
        
   default:
    crash("Invalid Instruction.");
    break;
  }
  
   
  // Execute breakpoint Exception
  if (!inBreakpoint && !inRet)
  {
   unsigned long address = 0;
    
   address = reg.exceptions.get(address);
   if (address != -1)
   {
   	++numBreakpoints;
	inBreakpoint = true;
	
		
   	// Push current instruction address.
    PNF_Number n(i);
    PNF_Variable v(n);
    substk.push(v);
    
    
    // GOTO address    
    address = reg.elabels.get(address);
    
    i = address;
    j = address + 1;
    k = address + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   else
   {
    ProgramState state;
    state.reg = reg;
    state.mem = mem;
    state.stk = stk;
  
    inBreakpoint = true;
    state = builtin_breakpoint_exception(state);
    ++numBreakpoints;
    inBreakpoint = false;
  
    reg = state.reg;
    mem = state.mem;
    stk = state.stk;
   }
  }
  
  
  // Quit if needed
  if (quitFound)
   exit(quitValue);
   
   
  // Variables
  if (inRet)
   inRet = false;
 }
}

ProgramState PNF::builtin_breakpoint_exception(ProgramState state)
{
 // Nothing needed at this time...
 
 
 return state;
}
