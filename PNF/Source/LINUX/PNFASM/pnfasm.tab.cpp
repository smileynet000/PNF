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
#line 1 "pnfasm.ypp" /* yacc.c:339  */

/* Prologue */
/*
Copyright (C) 2019 Dennis Earl Smiley

This file is part of pnfasm.

    pnfasm is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    pnfasm is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with pnfasm.  If not, see <https://www.gnu.org/licenses/>. 
*/
 
/* 
 CHANGELOG
 =========
 
 5/25/15 Origional a	- The first version.

 5/25/15 Origional a-a	- Removed ADDSTORE instruction. 2 instructions did the same thing.

 7/27/15 Original a-a-a - Added support for a type1 range.

 7/29/15 Original a-a-b - Fixed bugs...

 7/30/15 Original a-a-c - 1. Added support for a type1 range implementation.
			  2. Fixed bugs...
			  3. Added support for RLOAD1 and RSTORE1.
			  4. Added features to fix bugs...
			  5. Added support for a type2 range.
			  6. Added support for a type2 range implementation.
			  7. Added support for RPREP2 and RLOAD2
			  8. Added support for enums
			  9. Added support for enum implementations
			 10. Added support for other enum instructions
			 11. Added support for arrays
			 12. Added support for other array functions
			 13. Fixed bugs...
			 14. Changed array design.
			 15. Added version mechinism

3/25/17 Original a-a-d - 1. Added support for preprocessor.
			 2. Debugged the code...
			 3. Added support for automatic preprocessing.
			 4. Fixed bugs...
			 5. Added LIB directive...
			 6. Added IFs.
			 7. Added switches.
			 8. Added more stack documentation.
			 9. Added PATCH and NATIVE.

12/9/19 Origional a-a-e  1. Added FDECL and FRETS instructions.
			 2. Added FDEF, FDEF2, FEDEF2 and FEDEF instructions.
    			 3. Added PARAMF2 instruction.
 			 4. Added more function instructions.
			 5. Added documentation.
			 6. Added FNCPOINT and FNCLENGTH.
			 7. Fixed bugs...
			 8. Took out "extra" instructions.
*/
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

 ISTOREA     - Stores %accumulator to the address pointed at by %calc.
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

 IGOTO       - Go to the memory address specified and continue running the
               program from there.
               GOTO TVOID [memory address]

 ICGOTO       - Go to the memory address specified and continue running the
                program from there if %accumulator equals true.
                CGOTO TVOID [memory address]

 IZGOTO       - Go to the memory address specified if %accumulator is 0.
                ZGOTO TVOID [memory address]

 IPGOTO       - Go to the memory address specified if %accumulator is > 0.
                PGOTO TVOID [memory address]

 INGOTO       - Go to the memory address specified if %accumulator is < 0.
                NGOTO TVOID [memory address]

 IGOTOL        - Go to the label specified and continue running the
                 program from there.
                 GOTOL TVOID [label number]
                 GOTOL TSTRING [label string]               

 ICGOTOL       - Go to the label specified and continue running the
                 program from there if %accumulator equals true.
                 CGOTOL TVOID [label number]
                 CGOTOL TSTRING [label string

 IZGOTOL       - Go to the label specified if %accumulator is 0.
                 ZGOTOL TVOID [label number]
                 ZGOTOL TSTRING [label string]

 IPGOTOL       - Go to the memory address specified if %accumulator is > 0.
                 PGOTOL TVOID [label number]
                 PGOTOL TSTRING [label string]

 INGOTOL       - Go to the label specified if %accumulator is < 0.
                 NGOTOL TVOID [label number]
                 NGOTOL TSTRING [label string]

 IST           - Sets %accumulator to 0 if %calc is 0. (Used for loops.)
                 ST TVOID 0V

 IPUSH         - Put the accumulator on the stack.
                 PUSH TVOID 0V

 IPOP          - Loads a value into the accumulator from the stack.
                 POP TVOID 0V

 ICALL         - Calls a subroutine that begins at [memory address].
                 CALL TVOID [memory address]

 ICALLL        - Calls a subroutine that begins at [label].
                 CALLL TVOID [label]

 IRET          - Returns from a subroutine.
                 RET TVOID 0

 ILBL	       - Declares a label.
	         LBL TVOID 0V
                 LBL TSTRING [string]

 IVAR          - Declares a variable.
                 VAR TVOID [variable]

 IELBL         - Declares an event label.
                 ELBL TVOID 0V

 IEVLOAD       - Loads a value into %evalue.
                 EVLOAD TVOID [value]

 IHEADD        - Adds a Hardware Event to the table.
                 HEADD TVOID [event label number]

 IHEREM        - Removes a Hardware Event from the table.
                 HEREM TVOID 0V

 IHEED         - Edits a Hardware Event in the table. %evalue must be the hevent
                 number.
                 HEED TVOID [new event label number number]

 IHEGET        - Gets a Hardware Event event label number from the table. Puts it
                 in %evalue.
                 HEGET TVOID [hardware event number]

 ISHEADD       - Adds a System Hardware Event to the table.
                 SHEADD TVOID [event label number]

 ISHEREM       - Removes a System Hardware Event from the table.
                 SHEREM TVOID 0V

 ISHEED        - Edits a System Hardware Event in the table. %evalue must be the 
                 shevent number.
                 SHEED TVOID [new event label number number]

 ISHEGET       - Gets a System Hardware Event event label number from the table.
                 Puts it in %evalue.
                 SHEGET TVOID [hardware event number]

 IEADD        -  Adds an Event to the table.
                 EADD TVOID [event label number]

 IEREM         - Removes an Event from the table.
                 EREM TVOID 0V

 IEED          - Edits an Event in the table. %evalue must be the event number.
                 EED TVOID [new event label number number]

 IEGET         - Gets an Event event label number from the table. Puts it in \
                 %evalue.
                 EGET TVOID [hardware event number]

 IEXADD        - Adds an Exception to the table.
                 EXADD TVOID [event label number]

 IEXREM        - Removes an Exception from the table.
                 EXREM TVOID 0V

 IEXED         - Edits an Exception in the table. %evalue must be the exception
                 number.
                 EXED TVOID [new event label number number]

 IEXGET        - Gets an Exception event label number from the table. Puts it
                 in %evalue.
                 EXGET TVOID [hardware event number]

 IIADD         - Adds an Interrupt to the table.
                 IADD TVOID [event label number]

 IIREM         - Removes an Interrupt from the table.
                 IREM TVOID 0V

 IIED          - Edits an Interrupt in the table. %evalue must be the interrupt
                 number.
                 IED TVOID [new event label number number]

 IIGET         - Gets an Interrupt event label number from the table. Puts it
                 in %evalue.
                 IGET TVOID [hardware event number]
              
 IHEVENT       - Executes a Hardware Event subroutine.
                 HEVENT TVOID [hardware event number]

 ISHEVENT      - Executes a System Hardware Event Subroutine.
                 SHEVENT TVOID [system hardware event number]

 IEVENT        - Executes an Event subroutine.
          	 EVENT TVOID [event number]

 IEXCEPTION 	- Executes an Exception subroutine.
              	  EXCEPTION TVOID [exception number]

 IINT   	- Executes an Interrupt (User Defined Event) subroutine.
              	  INT TVOID [interrupt number]
                            
 ITYPEOF	- Puts the type of %accumulator in %typeof.
 		  TYPEOF TVOID 0V
 			  
 ICTYPEOF	- Puts the type of %calc in %typeof.
 		  CTYPEOF TVOID 0V
 			  
 ITLOAD         - Loads %typeof to %accumulator.
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
 			  
 ISWITCH    	- Switches %accumulator and %calc.
 		  SWITCH TVOID 0V
 		
 IVADD		- Gets the address of the specified variable.
 		  VADD TVOID [variable number]
 			  
 ILADD		- Gets the address of the specified label.
 		  LADD TVOID [label number]
 			  
 IELADD		- Gets the address of the specified event label.
 		  ELADD TVOID [event label number]

 IADD2V	   	 - Retrieves the value at the address stored in %accumulator.
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

 IVCHECK        - Sets %accumulator to true if version parameters match.
 	          VCHECK [type] [operand]

 IVSUPP         - Checks to see if a version is supported.
 	          VSUPP [type] [operand]

 IVPRINT	- Prints the version.
		  VPRINT TVOID 0V

 IVPRINTLN	- Prints the version, then a newline.
		  VPRINTLN TVOID 0V

 IISUPP	    	- Checks to see if an instruction is supported or not.
 		  ISUPP TNUMBER [data]
 			  
 ITSUPP		- Checks to see if a type is supported or not.
 		  TSUPP TNUMBER [data]

 ICOMMENT   	- A comment in the code.
 		  COMMENT TSTRING [string]

 IFIMODE        - Sets the mode for file input.
 	          FIMODE TSTRING [mode]
 		
 IFOMODE        - Sets the mode for file output.
 	          FOMODE TSTRING [mode]
 			  
 IFIOPEN        - Opens the specified file for input. If VOID, gets it from %accumulator.
		  FIOPEN TVOID 0V
 	          FIOPEN TSTRING [filename]
 			  
 IFOOPEN        - Opens the specified file for output. If VOID, gets it from, %accumulator.
		  FOOPEN TVOID 0V
 	          FOOPEN TSTRING [filename]
 			  
 IFREAD	        - Reads a value from the file, and stores it in %accumulator.
 	          FREAD [type] 0V
 			  
 IFPRINT        - Prints a value to the file.
 	          FRPINT [type] [data]
 			  
 IFPRINTLN      - Prints a value to the file, then a newline.
 	          FPRINTLN [type] [data]

 IFICLOSE   	- Closes the input file that's open.
 		  FICLOSE TVOID 0V
 			  
 IFOCLOSE   	- Closes the output file that's open.
 		  FOCLOSE TVOID 0V

 IMEML		- Stores the length of memory in %accumulator.
 		  MEML TVOID 0V

 IFIEOF		- Tests if we are at EOF or not.
 		  FIEOF TVOID 0V

 IARNLOAD	- Loads the number of arguments into %accumulator.
 		  ARNLOAD TVOID 0V

 IRDSTART1      - Marks the start of a type1 range.
 		  RDSTART1 TSTRING [name]
 			  
 IRFROM1        - Specifies the type1 range from value.
 		  RFROM1 TNUMBER [num]
 			  
 IRTO1		- Specifies the type1 range to value.
 		  RTO1 TNUMBER [num]
 			  
 IRDEND1	- Marks the end of a type1 range.
                  RDEND1 TVOID 0V

 IRSTART1       - Marks the start of a type1 range implementation. Needs a definition name.
                  RSTART1 TSTRING [defname]
              
 IRANGE1        - Specifies the range implementation value for a type1 range. To be valid, number MUST be within the range values...
 		  RANGE1 TNUMBER [num]
 			  
 IREND1         - Marks the end of the type1 range implementation, and names it.
 		  REND1 TSTRING [name]

 IRLOAD1    	- Loads a value from a type1 range to %accumulator.
 		  RLOAD1 TSTRING [name]
 			  
 IRSTORE1   	- Stores a value from %accumulator to a type1 range.
 		  RSTORE TSTRING [name]

 IHEADDB	- Add num blank hardware events
 		  HEADDB TVOID [num]
 			  
 ISHEADDB	- Add num blank system hardware events
 		  SHEADDB TVOID [num]
 			  
 IEADDB		- Add num blank events
 	          EADDB TVOID [num]
 			  
 IEXADDB	- Add num blank exceptions
 		  EXADDB TVOID [num]
 			  
 IIADDB		- Add num blank system interrupts
 		  IADDB TVOID [num]

 IRDSTART2  	- Marks the start of a type2 range.
 		  RDSTART2 TSTRING [name]
 			  
 IRFROM2    	- Specifies the type2 range from value.
 		  RFROM2 TNUMBER [num]
 			  
 IRTO2		- Specifies the type2 range to value.
 		  RTO2 TNUMBER [num]
 			  
 IRDEND2	- Marks the end of a type2 range.
              	  RDEND2 TVOID 0V

 IRSTART2   	- Marks the start of a type2 range implementation. Needs a definition name.
              	  RSTART2 TSTRING [defname]
              
 IRANGE2    	- Specifies the range implementation value for a type2 range.
 		  RANGE2 TSTRING [name]

 IRPREP2	- Prepares the rt2prep register...
 		  RPREP2 TSTRING [name]
 			  
 IRLOAD2	- Loads a value from index to %accumulator
 		  RLOAD2 TNUMBER [index]

 IESTART	- Marks the start of an enum definition
 		  ESTART TSTRING [name]
 			  
 IENAME		- Specifies an enum definition name
 		  ENAME TSTRING [name]
 			  
 IEEND		- Marks the end of an enum definition
 		  EEND TVOID 0V

 IENUMS		- Marks the beginning of an enum implementation
 		  ENUMS TSTRING [defname]
 			  
 IENUM		- Sets the value for the enum implementation
 		  ENUM TSTRING [valuename]
 			  
 ISENUM		- Ends the enum implementation. Names it.
 		  SENUM TSTRING [name]

 IEPREP		- Prepares the etprep register...
 		  EPREP TSTRING [name]
 			  
 ILOADE		- Loads a value from an enum to %accumulator
 		  LOADE TVOID 0V
 			  
 ISTOREE	- Stores a value from %accumulator to an enum
 		  STOREE TVOID 0V

 IASTART	- Names the array to be defined.
 		  ASTART TSTRING [name]
 			  
 IAEND		- Marks the end of an array definition
 		  AEND TNUMBER [length]

 IAPREP		- Prepares %aprep register
 		  APREP TSTRING [name]
 			  
 IAIPREP	- Prepares %aiprep register. If TVOID, gets number from %accumulator.
 		  AIPREP TNUMBER [num]
		  AIPREP TVOID 0V
 			  
 ILOADIA	- Loads a value from an array to %accumulator
 		  LOADIA TVOID 0V
 			  
 ISTOREIA	- Stores a value from %accumulator to an array
 		  STOREIA TVOID 0V

 IALENGTH   	- Gets the length of an array and puts it in %accumulator
	      	  ALENGTH TVOID 0V

 IAPRINT        - Prints the contents of an array
	    	  APRINT TVOID 0V

 IDUP		- Sets %accumulator to %calc
		  DUP TVOID 0V

 ICDUP		- Sets %calc to %accumulator
		  CDUP TVOID 0V

 IIF	    - Branches to if block if %accumulator is true, otherwise either optional else block or the end of the if.
	      IF TVOID 0V

 IIFBEGIN    - Marks the begining of the if or else block.
	      IFBEGIN TVOID 0V

 IIFEND	     - Marks the end of the if or else block.
	       IFEND TVOID 0V

 IENDIF	     - Marks the end of the if.
	       ENDIF TVOID 0V

 IIFELSE     - Marks the beginning of the optional else block.
	       IFELSE TVOID 0V

 IENDIFELSE  - Marks the end of the optional else blcok.
	       ENDIFELSE TVOID 0V

 IEIF	     - Marks the end of the if/else.
	       EIF TVOID 0V

ISWITCH2    - Specifies that what follows is a switch statement.
               SWITCH2 TVOID 0V

 ISWBEGIN    - The switch statement block start.
               SWBEGIN TVOID 0V

 ISWEND      - The switch statement block end.
               SWEND TVOID 0V

 ISWCBEGIN   - The switch statement case block start.
               SWCBEGIN TVOID 0V

 ISWCEND     - The switch statement case block end.
               SWCEND TVOID 0V

 ISWCASE     - A switch statement case.
               SWCASE [type] [value]

 ISWDEFAULT  - A switch statement default case.
               SWDEFAULT TVOID 0V

 ISWBREAK    - Goes to the next SWEND or reg.ecount.
	       SWBREAK TVOID 0V

 ILOADSP     - Loads the specified stack position into %accumulator.
	       LOADSP TNUMBER [stackpos]

 ISTORESP    - Stores the specified stack position from %accumulator. Also mirrors the stack in %savestack.
	       STORESP TNUMBER [stackpos]

 ILOADSTACK  - Loads %savestack into the stack.
	       LOADSTACK TVOID 0V

 ISTORESTACK - Stores the stack in %savestack.
	       STORESTACK TVOID 0V

 IATOSP	     - Sends %accumulator to %stackp.
	       ATOSP TVOID 0V

 ISPTOA	     - Sends %stackp to %accumulator.
	       SPTOA TVOID 0V

 IPATCH	     - Applies a patch.
	       PATCH [type] [value]

 INATIVE     - Runs a native subroutine.
	       NATIVE TSTRING [subroutine name]

 IFRET	      - Returns from a function.
		FRET TVOID 0V

 IFCALL	      - Prepares to call function [name]
		FCALL TSTRING [name]

 IFCPARAMS    - The actual parameter block start.
		FCPARAMS TVOID 0V

 IFECPARAMS   - The actual parameter block end.
		FECPARAMS TVOID 0V

 IFECALL      - Makes the call to the function.
		FECALL TVOID 0V

 IPUNUM       - Allows us to specify an actual parameter number.
		PNUM TNUMBER [num]

 IPARAMF      - Specify an actual parameter.
		PARAMF [type] [value]

 IPARAMF2     - Load parameter specified by %pnum to %accumulator
		PARAMF2 TVOID 0V

 IRNUM	      - Specify a return value number
		RNUM TNUMBER [num]

 IRETURNF     - Modifies a value for return
		RETURNF [type] [value]

 IFNAME	      - Sets %fname
		FNAME TSTRING [name]

 IRETURNV     - Loads %accumulator with return value %rnum
		RETURNV TVOID 0V

 IFNCLOAD     - Loads a function from %fpointer1 to %fpointer2.
		FNCLOAD TNUMBER [num]

 IFNCSTORE    - Stores a function from %fpointer2 to %fpointer1
		FNCSTORE TNUMBER [num]
		FNCSTORE TVOID 0V

 IFNCNEW      - Adds a new Function on the C++ heap.
		FNCNEW TVOID 0V

 IFNCDELETE   - Deletes a new Function on the C++ heap.
		FNCDELETE TVOID 0V

 IFNCSNAME    - Sets the name of the function %fpointer2
		FNCSNAME TVOID 0V

 IFNCSRET     - Sets the return type of a return value in %fpointer.
		FNCSRET [type] 0V

 IFNCSPARAM   - Adds a parameter of type [type] to %fpointer2 with value %accumulator
		FNCSPARAM [type] 0V

 IFNCSDEF      - Adds a definition beginning at [where] or [label] to %fpointer2.
		 FNCSDEF TNUMBER [where]
		 FNCSDEF TSTRING [label]

 IFNCGNAME     - Gets the name of %fpointer2
		 FNCGNAME TVOID 0V

 IFNCGRET      - Gets a return value from %fpointer2
		 FNCGRET TNUMBER [num]

 IFNCGPARAM    - Gets a parameter value from %fpointer2
		 FNCGPARAM TNUMBER [num]

 IFNCGDEF      - Gets a definition address for %fpointer2
		 FNCGDEF TVOID 0V
*/
#include <desLib/deslib.hpp>

#include <cstring>


#define OS_LINUX


#define YYSTYPE String

#define YYDEBUG 1


void yyerror(char const * c);
int yylex();

String get_extension(String fileName);
String strip_extension(String fileName);
void preprocess(String arg);
void mklib(String arg);


FILE * output;

unsigned long mode = 0;


unsigned long lineno = 0;
unsigned long iflineno = 0;
unsigned long elselineno = 0;
unsigned long varcounter = 0;
unsigned long ifcounter = 0;
unsigned long ifcounter2 = 0;

bool saw_elseend = false;
unsigned long saw_pifend = 0;
unsigned long ifcounter3 = 0;
unsigned long pifend = 0;

#line 877 "pnfasm.tab.cpp" /* yacc.c:339  */

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
    ASMVERSION = 258,
    PNF = 259,
    BIN = 260,
    PBIN = 261,
    LIB = 262,
    PINCLUDE = 263,
    PIMPORT = 264,
    PDEFINE = 265,
    PMACRO = 266,
    PENDM = 267,
    PUNDEF = 268,
    PIFDEF = 269,
    PIFNDEF = 270,
    PELSE = 271,
    PENDIF = 272,
    PPDATE = 273,
    PPTIME = 274,
    PPLINE = 275,
    PPFILE = 276,
    PPCDATE = 277,
    PPCTIME = 278,
    PPCOMMENT = 279,
    IVERSION = 280,
    IVOID = 281,
    ICRASH = 282,
    IQUIT = 283,
    IHALT = 284,
    IPRINT = 285,
    IPRINTLN = 286,
    IREAD = 287,
    ILOAD = 288,
    ISTORE = 289,
    ILOADC = 290,
    ISTOREC = 291,
    IELOAD = 292,
    IESTORE = 293,
    IELOADC = 294,
    IESTOREC = 295,
    IVLOAD = 296,
    IVSTORE = 297,
    IVLOADC = 298,
    IVSTOREC = 299,
    ISTOREA = 300,
    IMODT = 301,
    IMODCT = 302,
    IADD = 303,
    ISUB = 304,
    IMUL = 305,
    IDIV = 306,
    IMOD = 307,
    IPOW = 308,
    IROOT = 309,
    IINC = 310,
    IDEC = 311,
    IEQU = 312,
    INEQU = 313,
    IGTR = 314,
    ILSS = 315,
    IGEQU = 316,
    ILEQU = 317,
    IAND = 318,
    IOR = 319,
    INOT = 320,
    IGOTO = 321,
    ICGOTO = 322,
    IZGOTO = 323,
    IPGOTO = 324,
    INGOTO = 325,
    IGOTOL = 326,
    ICGOTOL = 327,
    IZGOTOL = 328,
    IPGOTOL = 329,
    INGOTOL = 330,
    IST = 331,
    IPUSH = 332,
    IPOP = 333,
    ICALL = 334,
    ICALLL = 335,
    IRET = 336,
    IVAR = 337,
    ILBL = 338,
    IEPRINT = 339,
    IEPRINTLN = 340,
    IEND = 341,
    IELBL = 342,
    IEVLOAD = 343,
    IHEADD = 344,
    IHEREM = 345,
    IHEED = 346,
    IHEGET = 347,
    ISHEADD = 348,
    ISHEREM = 349,
    ISHEED = 350,
    ISHEGET = 351,
    IEADD = 352,
    IEREM = 353,
    IEED = 354,
    IEGET = 355,
    IEXADD = 356,
    IEXREM = 357,
    IEXED = 358,
    IEXGET = 359,
    IIADD = 360,
    IIREM = 361,
    IIED = 362,
    IIGET = 363,
    IHEVENT = 364,
    ISHEVENT = 365,
    IEVENT = 366,
    IEXCEPTION = 367,
    IINT = 368,
    ITYPEOF = 369,
    ICTYPEOF = 370,
    ITLOAD = 371,
    IALOAD = 372,
    IINLOAD = 373,
    IICLOAD = 374,
    IARLOAD = 375,
    IATOC = 376,
    ISWITCH = 377,
    IVADD = 378,
    ILADD = 379,
    IELADD = 380,
    IADD2V = 381,
    IBTAND = 382,
    IBTOR = 383,
    IBTEXOR = 384,
    IBTNOT = 385,
    IBTSL = 386,
    IBTSR = 387,
    IVCHECK = 388,
    IVSUPP = 389,
    IVPRINT = 390,
    IVPRINTLN = 391,
    IISUPP = 392,
    ITSUPP = 393,
    ICOMMENT = 394,
    IFIMODE = 395,
    IFOMODE = 396,
    IFIOPEN = 397,
    IFOOPEN = 398,
    IFREAD = 399,
    IFPRINT = 400,
    IFPRINTLN = 401,
    IFICLOSE = 402,
    IFOCLOSE = 403,
    IMEML = 404,
    IFIEOF = 405,
    IARNLOAD = 406,
    IRDSTART1 = 407,
    IRFROM1 = 408,
    IRTO1 = 409,
    IRDEND1 = 410,
    IRSTART1 = 411,
    IRANGE1 = 412,
    IREND1 = 413,
    IRLOAD1 = 414,
    IRSTORE1 = 415,
    IHEADDB = 416,
    ISHEADDB = 417,
    IEADDB = 418,
    IEXADDB = 419,
    IIADDB = 420,
    IRDSTART2 = 421,
    IRFROM2 = 422,
    IRTO2 = 423,
    IRDEND2 = 424,
    IRSTART2 = 425,
    IRANGE2 = 426,
    IRPREP2 = 427,
    IRLOAD2 = 428,
    IESTART = 429,
    IENAME = 430,
    IEEND = 431,
    IENUMS = 432,
    IENUM = 433,
    ISENUM = 434,
    IEPREP = 435,
    ILOADE = 436,
    ISTOREE = 437,
    IASTART = 438,
    IAEND = 439,
    IAPREP = 440,
    IAIPREP = 441,
    ILOADIA = 442,
    ISTOREIA = 443,
    IALENGTH = 444,
    IAPRINT = 445,
    IDUP = 446,
    ICDUP = 447,
    IIF = 448,
    IENDIF = 449,
    IIFELSE = 450,
    IENDIFELSE = 451,
    IEIF = 452,
    IIFBEGIN = 453,
    IIFEND = 454,
    ISWITCH2 = 455,
    ISWBEGIN = 456,
    ISWEND = 457,
    ISWCASE = 458,
    ISWCBEGIN = 459,
    ISWCEND = 460,
    ISWDEFAULT = 461,
    ISWBREAK = 462,
    ILOADSP = 463,
    ISTORESP = 464,
    ILOADSTACK = 465,
    ISTORESTACK = 466,
    IATOSP = 467,
    ISPTOA = 468,
    IPATCH = 469,
    INATIVE = 470,
    IFRET = 471,
    IFCALL = 472,
    IFCPARAMS = 473,
    IFECPARAMS = 474,
    IFECALL = 475,
    IPNUM = 476,
    IPARAMF = 477,
    IPARAMF2 = 478,
    IPARAMF3 = 479,
    IRNUM = 480,
    IRETURNF = 481,
    IRETURNF2 = 482,
    IRETURNF3 = 483,
    IFNAME = 484,
    IRETURNV = 485,
    IFNCLOAD = 486,
    IFNCSTORE = 487,
    IFNCNEW = 488,
    IFNCDELETE = 489,
    IFNCSNAME = 490,
    IFNCSRET = 491,
    IFNCSPARAM = 492,
    IFNCSDEF = 493,
    IFNCGNAME = 494,
    IFNCGRET = 495,
    IFNCGPARAM = 496,
    IFNCGDEF = 497,
    IFNCPOINT = 498,
    IFNCLENGTH = 499,
    IFCALL2 = 500,
    IFCPARAMS2 = 501,
    IFECPARAMS2 = 502,
    IFECALL2 = 503,
    IFNCSYNCR = 504,
    TVOID = 505,
    TBOOLEAN = 506,
    TNUMBER = 507,
    TCHARACTER = 508,
    TSTRING = 509,
    VOID = 510,
    BOOLEAN = 511,
    NUMBER = 512,
    CHARACTER = 513,
    STRING = 514
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

#line 1185 "pnfasm.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   1036

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  263
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  400
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  998

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   516

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     260,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   261,   262
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1084,  1084,  1085,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1097,  1098,  1099,  1100,  1108,  1109,  1110,  1111,  1117,
    1118,  1123,  1132,  1133,  1139,  1140,  1145,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,
    1197,  1198,  1199,  1200,  1201,  1202,  1203,  1208,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
    1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1249,  1250,
    1257,  1258,  1265,  1266,  1273,  1274,  1281,  1282,  1283,  1284,
    1285,  1286,  1293,  1295,  1296,  1302,  1303,  1309,  1310,  1315,
    1325,  1326,  1332,  1333,  1338,  1348,  1349,  1350,  1351,  1352,
    1353,  1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,
    1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,
    1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,  1387,  1388,
    1394,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,  1412,
    1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1427,  1428,
    1434,  1444,  1445,  1452,  1453,  1459,  1469,  1470,  1471,  1472,
    1473,  1483,  1493,  1503,  1504,  1514,  1515,  1525,  1526,  1527,
    1528,  1529,  1530,  1536,  1537,  1542,  1551,  1552,  1558,  1559,
    1564,  1573,  1574,  1575,  1576,  1577,  1578,  1587,  1588,  1589,
    1590,  1599,  1600,  1609,  1618,  1627,  1628,  1629,  1630,  1631,
    1632,  1641,  1642,  1643,  1644,  1653,  1662,  1671,  1672,  1681,
    1690,  1691,  1700,  1709,  1718,  1727,  1728,  1729,  1738,  1739,
    1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,  1757,
    1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,
    1768,  1769,  1770,  1771,  1772,  1773,  1778,  1787,  1788,  1789,
    1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1807,
    1808,  1817,  1818,  1819,  1820,  1821,  1822,  1829,  1830,  1836,
    1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,
    1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,  1862,
    1863,  1864,  1866,  1873,  1874,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,  1885,  1886,  1887,  1888,  1889,
    1890,  1891,  1897,  1898,  1899,  1900,  1901,  1902,  1903,  1912,
    1913,  1914,  1915,  1916,  1917,  1924,  1927,  1928,  1935,  1936,
    1942,  1949,  1950,  1951,  1952,  1953,  1960,  1967,  1974,  1984,
    1985,  1986,  1987,  1988,  1989,  1990,  1991,  1992,  1993,  1994,
    1995,  1996,  1997,  1998,  1999,  2000,  2001,  2002,  2005,  2006,
    2007
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASMVERSION", "PNF", "BIN", "PBIN",
  "LIB", "PINCLUDE", "PIMPORT", "PDEFINE", "PMACRO", "PENDM", "PUNDEF",
  "PIFDEF", "PIFNDEF", "PELSE", "PENDIF", "PPDATE", "PPTIME", "PPLINE",
  "PPFILE", "PPCDATE", "PPCTIME", "PPCOMMENT", "IVERSION", "IVOID",
  "ICRASH", "IQUIT", "IHALT", "IPRINT", "IPRINTLN", "IREAD", "ILOAD",
  "ISTORE", "ILOADC", "ISTOREC", "IELOAD", "IESTORE", "IELOADC",
  "IESTOREC", "IVLOAD", "IVSTORE", "IVLOADC", "IVSTOREC", "ISTOREA",
  "IMODT", "IMODCT", "IADD", "ISUB", "IMUL", "IDIV", "IMOD", "IPOW",
  "IROOT", "IINC", "IDEC", "IEQU", "INEQU", "IGTR", "ILSS", "IGEQU",
  "ILEQU", "IAND", "IOR", "INOT", "IGOTO", "ICGOTO", "IZGOTO", "IPGOTO",
  "INGOTO", "IGOTOL", "ICGOTOL", "IZGOTOL", "IPGOTOL", "INGOTOL", "IST",
  "IPUSH", "IPOP", "ICALL", "ICALLL", "IRET", "IVAR", "ILBL", "IEPRINT",
  "IEPRINTLN", "IEND", "IELBL", "IEVLOAD", "IHEADD", "IHEREM", "IHEED",
  "IHEGET", "ISHEADD", "ISHEREM", "ISHEED", "ISHEGET", "IEADD", "IEREM",
  "IEED", "IEGET", "IEXADD", "IEXREM", "IEXED", "IEXGET", "IIADD", "IIREM",
  "IIED", "IIGET", "IHEVENT", "ISHEVENT", "IEVENT", "IEXCEPTION", "IINT",
  "ITYPEOF", "ICTYPEOF", "ITLOAD", "IALOAD", "IINLOAD", "IICLOAD",
  "IARLOAD", "IATOC", "ISWITCH", "IVADD", "ILADD", "IELADD", "IADD2V",
  "IBTAND", "IBTOR", "IBTEXOR", "IBTNOT", "IBTSL", "IBTSR", "IVCHECK",
  "IVSUPP", "IVPRINT", "IVPRINTLN", "IISUPP", "ITSUPP", "ICOMMENT",
  "IFIMODE", "IFOMODE", "IFIOPEN", "IFOOPEN", "IFREAD", "IFPRINT",
  "IFPRINTLN", "IFICLOSE", "IFOCLOSE", "IMEML", "IFIEOF", "IARNLOAD",
  "IRDSTART1", "IRFROM1", "IRTO1", "IRDEND1", "IRSTART1", "IRANGE1",
  "IREND1", "IRLOAD1", "IRSTORE1", "IHEADDB", "ISHEADDB", "IEADDB",
  "IEXADDB", "IIADDB", "IRDSTART2", "IRFROM2", "IRTO2", "IRDEND2",
  "IRSTART2", "IRANGE2", "IRPREP2", "IRLOAD2", "IESTART", "IENAME",
  "IEEND", "IENUMS", "IENUM", "ISENUM", "IEPREP", "ILOADE", "ISTOREE",
  "IASTART", "IAEND", "IAPREP", "IAIPREP", "ILOADIA", "ISTOREIA",
  "IALENGTH", "IAPRINT", "IDUP", "ICDUP", "IIF", "IENDIF", "IIFELSE",
  "IENDIFELSE", "IEIF", "IIFBEGIN", "IIFEND", "ISWITCH2", "ISWBEGIN",
  "ISWEND", "ISWCASE", "ISWCBEGIN", "ISWCEND", "ISWDEFAULT", "ISWBREAK",
  "ILOADSP", "ISTORESP", "ILOADSTACK", "ISTORESTACK", "IATOSP", "ISPTOA",
  "IPATCH", "INATIVE", "IFRET", "IFCALL", "IFCPARAMS", "IFECPARAMS",
  "IFECALL", "IPNUM", "IPARAMF", "IPARAMF2", "IPARAMF3", "IRNUM",
  "IRETURNF", "IRETURNF2", "IRETURNF3", "IFNAME", "IRETURNV", "IFNCLOAD",
  "IFNCSTORE", "IFNCNEW", "IFNCDELETE", "IFNCSNAME", "IFNCSRET",
  "IFNCSPARAM", "IFNCSDEF", "IFNCGNAME", "IFNCGRET", "IFNCGPARAM",
  "IFNCGDEF", "IFNCPOINT", "IFNCLENGTH", "IFCALL2", "IFCPARAMS2",
  "IFECPARAMS2", "IFECALL2", "IFNCSYNCR", "TVOID", "TBOOLEAN", "TNUMBER",
  "TCHARACTER", "TSTRING", "VOID", "BOOLEAN", "NUMBER", "CHARACTER",
  "STRING", "'\\n'", "\"<\"", "\">\"", "$accept", "input", "line",
  "instruction", "pinstruction", "variable", "pp", "directive", YY_NULLPTR
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
      10,   515,   516
};
# endif

#define YYPACT_NINF -249

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-249)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -249,     0,  -249,  -249,  -248,    -7,  -249,  -249,  -249,   135,
     172,   110,   140,  -249,   194,   200,   201,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,   205,   207,   204,   211,
     212,     1,    11,     5,   151,   213,   155,   214,   159,   215,
     163,   216,   167,   148,   171,   180,   217,    16,    21,   111,
     184,   185,   188,   189,   192,   193,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   125,   128,   130,   131,   133,   234,   235,   236,
     237,   136,   238,    26,   138,    31,    36,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,    41,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,    46,    51,   285,   286,   287,   288,
     289,   290,   291,   139,   141,   175,    56,    61,   292,   296,
     297,   298,   299,   300,   301,   303,   302,   304,   305,   306,
     307,   308,   309,   313,   314,   315,   316,   317,   318,   320,
     319,   321,   322,   323,   326,   325,   327,   324,   328,   329,
     330,   331,   336,   337,   334,   338,   335,   196,   341,    66,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,    71,   356,   357,   358,   359,   360,
     361,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     374,   376,   375,    76,   378,    81,   377,    86,    91,    96,
     379,   380,   382,   197,   381,   385,   386,   101,   106,   198,
     387,   388,   389,   392,   393,   394,   384,   395,   396,   397,
     398,  -249,  -249,  -249,  -249,  -249,  -249,  -249,   295,   294,
    -249,   362,  -249,   373,   390,  -249,  -249,  -249,  -249,   199,
     312,   391,   311,   399,   400,   195,   401,   402,   403,   404,
     363,   406,   407,   405,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   443,   442,   444,   445,   446,   447,   450,   449,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   441,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   508,   510,   511,   512,   513,   509,   516,
     107,   112,   115,   118,   142,   517,   514,   519,   383,   518,
     520,   521,   522,   523,   524,   525,   526,   527,   529,   530,
     531,   534,   533,   536,   535,   538,   537,   540,   539,   542,
     541,   544,   543,   546,   545,   548,   547,   550,   549,   552,
     551,   553,   554,   555,   556,   559,   560,   561,   562,   563,
     564,   528,   565,   567,   568,   569,   570,   572,   571,   573,
     574,   577,   578,   579,   580,   581,   582,   583,   584,   586,
     587,   585,   588,   589,   592,   593,   591,   594,   590,   596,
     595,   597,   598,   599,   600,   601,   602,   605,   603,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   624,   626,   627,   628,   625,   629,
     630,   633,   631,   632,   634,   635,   636,   639,   640,   641,
     642,   643,   644,   645,   647,   637,   646,   648,   649,   652,
     651,   653,   656,   654,   655,   657,   658,   660,   663,   661,
     662,   664,   666,   665,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   650,   690,   691,   692,   693,
     695,   697,   698,   699,   700,   703,   704,   705,   706,   707,
     696,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   721,   723,   724,   725,   726,   727,   728,
     730,   731,   732,   733,   734,   735,   736,   737,   738,   739,
     740,   741,   742,   743,   744,   745,   747,   746,   748,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     762,   763,   764,   765,   767,   766,   768,   771,   772,   773,
     770,   775,   776,   777,   778,  -249,   779,   408,   409,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    10,     0,     0,   398,   399,   400,     0,
       0,     0,     0,   385,     0,     0,     0,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     3,     5,     6,     7,     8,     9,     0,     0,
     379,     0,   381,     0,     0,   384,   386,   387,   388,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   363,     0,     0,     0,   383,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   366,   375,   371,   367,   376,   372,   368,   377,
     373,   369,   378,   374,   370,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   261,   260,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   364,   380,   382
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   252,   253,   254,   255,   256,   257
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       2,     3,   258,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     259,   274,   275,   276,   277,   278,   284,   285,   286,   287,
     251,   279,   280,   281,   282,   283,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   380,   381,   382,   383,
     384,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   428,   429,   430,   431,   432,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   525,   526,   527,   528,
     529,   544,   545,   546,   547,   548,   567,   568,   569,   570,
     571,   573,   574,   575,   576,   577,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   331,   742,   332,   333,   334,   743,   744,   745,   264,
     747,   746,   748,   750,   749,   363,   751,   752,   365,   364,
     367,   369,   366,   371,   368,   370,   377,   372,   385,   465,
     378,   467,   386,   466,   260,   468,   261,   753,   312,   265,
     313,   754,   288,   289,   290,   291,   293,   294,   295,   296,
     298,   299,   300,   301,   303,   304,   305,   306,   308,   309,
     310,   311,   314,   315,   316,   317,   469,   470,   471,   472,
     318,   262,   319,   263,   335,   337,   336,   338,   339,   341,
     340,   342,   343,   345,   344,   346,   522,   597,   523,   598,
     612,   637,   613,   266,   630,   269,   631,   270,   271,   267,
     268,   272,   273,   292,   297,   302,   307,   320,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   373,   374,   375,   376,   379,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   458,   459,     0,     0,   460,
     461,     0,   483,   462,   463,   464,   484,   485,   486,   487,
     625,   626,   491,   489,   488,   490,     0,   493,   492,   497,
     494,   495,   496,   498,   499,   500,   501,   632,   634,   505,
     503,   502,   504,     0,   512,   506,   507,   508,   509,   510,
       0,   511,   513,   514,   515,   516,   517,   518,   519,   521,
     520,   524,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   549,   550,   551,   552,
       0,     0,   553,   554,   555,   556,   557,   558,   559,   642,
     561,   627,   563,   560,   564,   562,   565,   566,   572,   578,
     595,   599,   628,   594,   596,   600,   601,   614,   620,   758,
     615,   616,   617,   618,   619,   621,   622,   623,   624,   629,
     633,     0,     0,     0,   635,   636,     0,     0,   638,   641,
     639,     0,   640,   643,   645,   644,   646,   647,   648,   649,
     996,   997,   650,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,     0,     0,   670,   671,   672,   673,   674,   675,
     696,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,     0,
       0,   694,   697,   695,   699,   698,   701,   700,   703,   702,
     705,   704,   707,   706,   709,   708,   710,   711,   712,   713,
     714,   715,   716,   717,   718,   719,     0,     0,   720,   721,
     722,   723,   724,   725,     0,   727,   726,   729,   728,   731,
     730,   733,   732,   735,   734,   736,   737,     0,   740,   738,
     739,   741,   755,   756,   757,   759,     0,   762,   760,   763,
     761,   764,   767,   765,   768,   766,   801,   769,   770,   771,
     772,   773,   774,   775,   776,   777,   778,   779,   780,   781,
     782,   783,   784,   785,   786,   787,   788,   789,   790,     0,
     791,   792,   793,   794,   795,   796,   797,   798,     0,   799,
       0,   800,   803,   804,   802,   806,   805,   807,   808,     0,
     809,   810,   811,   812,   813,   814,   815,   816,   817,     0,
       0,   818,   819,   821,   820,   828,   823,   822,   824,   826,
     825,   829,   830,   827,   831,     0,   835,   832,   833,   834,
     837,   836,   838,   839,   840,   841,   842,   843,     0,   844,
       0,   845,   848,   846,   849,   847,   850,   853,   851,   854,
     852,   855,   856,   857,   858,     0,   859,   860,   861,   863,
     862,     0,   875,   864,   865,   866,   867,   868,   869,   870,
     871,     0,   873,   872,   874,   876,   915,   877,   878,   879,
     880,   882,   881,   883,   884,   887,   885,   886,   888,   890,
     889,   892,   893,   891,   894,   895,   896,   897,   898,   899,
     900,   901,   902,   903,   904,   905,   906,   907,   908,   909,
     910,   911,   912,   913,   914,     0,     0,   916,   919,   917,
     920,   918,   921,   922,     0,   930,   923,   924,   925,   926,
     927,   928,   929,   931,     0,   933,   934,   935,   932,   937,
     936,   938,     0,   939,   942,   940,   943,   941,   944,   945,
     946,   947,     0,   949,   948,   950,   951,   952,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,     0,
     965,   967,     0,   964,   966,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   978,   979,   980,   981,     0,
       0,   982,   984,   985,   983,   986,   987,   988,   989,   990,
     991,   992,   993,   994,     0,     0,   995
};

static const yytype_int16 yycheck[] =
{
       0,     1,   250,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     257,   250,   251,   252,   253,   254,   251,   252,   253,   254,
     260,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   255,   252,   253,   254,   259,   255,   256,   259,
     255,   259,   257,   255,   259,   250,   258,   259,   250,   254,
     250,   250,   254,   250,   254,   254,   250,   254,   250,   250,
     254,   250,   254,   254,   259,   254,   261,   255,   250,   259,
     252,   259,   251,   252,   253,   254,   251,   252,   253,   254,
     251,   252,   253,   254,   251,   252,   253,   254,   251,   252,
     253,   254,   251,   252,   253,   254,   251,   252,   253,   254,
     250,   259,   252,   261,   250,   250,   252,   252,   250,   250,
     252,   252,   250,   250,   252,   252,   250,   250,   252,   252,
     252,   256,   254,   259,   255,   250,   257,   250,   254,   259,
     259,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,    -1,    -1,   252,
     252,    -1,   250,   254,   254,   254,   250,   250,   250,   250,
     255,   257,   250,   252,   254,   252,    -1,   252,   254,   250,
     254,   254,   254,   250,   250,   250,   250,   255,   257,   250,
     252,   254,   252,    -1,   250,   254,   254,   254,   252,   254,
      -1,   254,   254,   254,   254,   254,   250,   250,   254,   254,
     252,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
      -1,    -1,   252,   252,   250,   250,   250,   250,   250,   256,
     250,   259,   250,   254,   250,   254,   250,   252,   250,   252,
     250,   250,   259,   254,   252,   250,   250,   250,   254,   256,
     252,   252,   250,   250,   250,   250,   250,   250,   250,   259,
     259,    -1,    -1,    -1,   255,   255,    -1,    -1,   257,   255,
     258,    -1,   259,   257,   259,   258,   255,   255,   255,   255,
     262,   262,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,    -1,    -1,   257,   257,   257,   257,   255,   257,
     259,   257,   257,   257,   257,   255,   257,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,    -1,
      -1,   257,   255,   258,   255,   257,   255,   257,   255,   257,
     255,   257,   255,   257,   255,   257,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,    -1,    -1,   257,   257,
     257,   257,   257,   257,    -1,   257,   259,   257,   259,   257,
     259,   257,   259,   255,   259,   255,   255,    -1,   259,   257,
     257,   255,   255,   259,   255,   257,    -1,   255,   258,   256,
     259,   257,   255,   258,   255,   259,   258,   257,   257,   255,
     257,   255,   257,   255,   257,   255,   257,   255,   257,   255,
     257,   255,   257,   255,   257,   255,   257,   255,   257,    -1,
     257,   257,   257,   257,   255,   255,   255,   255,    -1,   256,
      -1,   257,   255,   255,   259,   255,   257,   255,   257,    -1,
     257,   257,   255,   255,   255,   255,   255,   255,   255,    -1,
      -1,   257,   256,   258,   257,   255,   257,   259,   256,   258,
     257,   255,   257,   259,   257,    -1,   255,   259,   259,   259,
     255,   259,   259,   255,   255,   255,   255,   255,    -1,   256,
      -1,   257,   255,   258,   256,   259,   257,   255,   258,   255,
     259,   255,   255,   255,   259,    -1,   257,   257,   255,   257,
     259,    -1,   255,   259,   259,   259,   257,   257,   257,   257,
     257,    -1,   257,   259,   257,   259,   256,   259,   259,   257,
     259,   255,   259,   259,   259,   255,   259,   259,   255,   257,
     259,   255,   257,   259,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,    -1,    -1,   257,   255,   258,
     255,   259,   255,   255,    -1,   259,   257,   257,   255,   255,
     255,   255,   255,   255,    -1,   255,   255,   255,   259,   255,
     257,   256,    -1,   257,   255,   258,   255,   259,   255,   255,
     255,   255,    -1,   255,   257,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,    -1,
     255,   255,    -1,   259,   257,   257,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,    -1,
      -1,   257,   255,   257,   259,   257,   255,   255,   255,   259,
     255,   255,   255,   255,    -1,    -1,   257
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   264,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   260,   265,   266,   267,   268,   269,   270,   250,   257,
     259,   261,   259,   261,   259,   259,   259,   259,   259,   250,
     250,   254,   250,   250,   250,   251,   252,   253,   254,   250,
     251,   252,   253,   254,   251,   252,   253,   254,   251,   252,
     253,   254,   250,   251,   252,   253,   254,   250,   251,   252,
     253,   254,   250,   251,   252,   253,   254,   250,   251,   252,
     253,   254,   250,   252,   251,   252,   253,   254,   250,   252,
     250,   250,   251,   252,   253,   254,   250,   251,   252,   253,
     254,   250,   252,   253,   254,   250,   252,   250,   252,   250,
     252,   250,   252,   250,   252,   250,   252,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   254,   250,   254,   250,   254,   250,
     254,   250,   254,   250,   250,   250,   250,   250,   254,   250,
     250,   251,   252,   253,   254,   250,   254,   250,   251,   252,
     253,   254,   250,   251,   252,   253,   254,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   251,
     252,   253,   254,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   251,
     252,   253,   254,   250,   251,   252,   253,   254,   250,   250,
     252,   252,   254,   254,   254,   250,   254,   250,   254,   251,
     252,   253,   254,   250,   251,   252,   253,   254,   250,   251,
     252,   253,   254,   250,   250,   250,   250,   250,   254,   252,
     252,   250,   254,   252,   254,   254,   254,   250,   250,   250,
     250,   250,   254,   252,   252,   250,   254,   254,   254,   252,
     254,   254,   250,   254,   254,   254,   254,   250,   250,   254,
     252,   254,   250,   252,   250,   250,   251,   252,   253,   254,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   251,   252,   253,   254,   250,
     250,   250,   250,   252,   252,   250,   250,   250,   250,   250,
     254,   250,   254,   250,   250,   250,   252,   250,   251,   252,
     253,   254,   250,   250,   251,   252,   253,   254,   252,   250,
     251,   252,   253,   254,   250,   251,   252,   253,   254,   250,
     251,   252,   253,   254,   254,   250,   252,   250,   252,   250,
     250,   250,   250,   251,   252,   253,   254,   250,   251,   252,
     253,   254,   252,   254,   250,   252,   252,   250,   250,   250,
     254,   250,   250,   250,   250,   255,   257,   259,   259,   259,
     255,   257,   255,   259,   257,   255,   255,   256,   257,   258,
     259,   255,   256,   257,   258,   259,   255,   255,   255,   255,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     257,   257,   257,   257,   255,   257,   257,   257,   257,   257,
     255,   257,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   257,   258,   259,   255,   257,   255,
     257,   255,   257,   255,   257,   255,   257,   255,   257,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     257,   257,   257,   257,   257,   257,   259,   257,   259,   257,
     259,   257,   259,   257,   259,   255,   255,   255,   257,   257,
     259,   255,   255,   259,   255,   256,   259,   255,   257,   259,
     255,   258,   259,   255,   259,   255,   259,   255,   256,   257,
     258,   259,   255,   256,   257,   258,   259,   255,   255,   257,
     257,   255,   257,   255,   257,   255,   257,   255,   257,   255,
     257,   255,   257,   255,   257,   255,   257,   255,   257,   255,
     257,   257,   257,   257,   257,   255,   255,   255,   255,   256,
     257,   258,   259,   255,   255,   257,   255,   255,   257,   257,
     257,   255,   255,   255,   255,   255,   255,   255,   257,   256,
     257,   258,   259,   257,   256,   257,   258,   259,   255,   255,
     257,   257,   259,   259,   259,   255,   259,   255,   259,   255,
     255,   255,   255,   255,   256,   257,   258,   259,   255,   256,
     257,   258,   259,   255,   255,   255,   255,   255,   259,   257,
     257,   255,   259,   257,   259,   259,   259,   257,   257,   257,
     257,   257,   259,   257,   257,   255,   259,   259,   259,   257,
     259,   259,   255,   259,   259,   259,   259,   255,   255,   259,
     257,   259,   255,   257,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   256,   257,   258,   259,   255,
     255,   255,   255,   257,   257,   255,   255,   255,   255,   255,
     259,   255,   259,   255,   255,   255,   257,   255,   256,   257,
     258,   259,   255,   255,   255,   255,   255,   255,   257,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   259,   255,   257,   255,   257,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   257,   259,   255,   257,   257,   255,   255,   255,
     259,   255,   255,   255,   255,   257,   262,   262
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   263,   264,   264,   265,   265,   265,   265,   265,   265,
     265,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   267,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   270,   270,
     270
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       4,     2,     4,     3,     2,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
        case 10:
#line 1094 "pnfasm.ypp" /* yacc.c:1646  */
    { yyerrok; }
#line 2965 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 1097 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "0 0 0\n"); }
#line 2971 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 1098 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "0 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 2977 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 1099 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "1 0 0\n"); }
#line 2983 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 1101 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "2 4 ");

		 for (int i = 1; (yyvsp[0])[i] != '\"'; ++i)
                  fprintf(output, "%i ", (yyvsp[0])[i]);
		 fprintf(output, "0\n");
		}
#line 2995 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 1108 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "3 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3001 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 1109 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "4 0 0\n"); }
#line 3007 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 1110 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "5 0 0\n"); }
#line 3013 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 1111 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "5 1 1\n");
						 else
						  fprintf(output, "5 1 0\n");
					        }
#line 3024 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 1117 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "5 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3030 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 1118 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "5 3 %i\n", ch);
						}
#line 3040 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 1123 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "5 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 3054 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 1132 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "6 0 0\n"); }
#line 3060 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 1133 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "6 1 1\n");
						 else
						  fprintf(output, "6 1 0\n");
					        }
#line 3071 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 1139 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "6 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3077 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 1140 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "6 3 %i\n", ch);
						}
#line 3087 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 1145 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "6 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 3101 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 1154 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "7 1 0\n"); }
#line 3107 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 1155 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "7 2 0\n"); }
#line 3113 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 1156 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "7 3 0\n"); }
#line 3119 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 1157 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "7 4 0\n"); }
#line 3125 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 1158 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "8 1 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3131 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 1159 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "8 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3137 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 1160 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "8 3 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3143 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 1161 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "8 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3149 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 1162 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "9 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3155 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 1163 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "10 1 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3161 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 1164 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "10 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3167 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 1165 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "10 3 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3173 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 1166 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "10 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3179 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 1167 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "11 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3185 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 1168 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "12 1 0\n"); }
#line 3191 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 1169 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "12 2 0\n"); }
#line 3197 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 1170 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "12 3 0\n"); }
#line 3203 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 1171 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "12 4 0\n"); }
#line 3209 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 1172 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "13 0 0\n"); }
#line 3215 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 1173 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "14 1 0\n"); }
#line 3221 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 1174 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "14 2 0\n"); }
#line 3227 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 1175 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "14 3 0\n"); }
#line 3233 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 1176 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "14 4 0\n"); }
#line 3239 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 1177 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "15 0 0\n"); }
#line 3245 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 1178 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "16 1 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3251 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 1179 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "16 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3257 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 1180 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "16 3 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3263 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 1181 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "16 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3269 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 1182 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "17 0 0\n"); }
#line 3275 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 1183 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "17 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3281 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 1184 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "18 1 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3287 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 1185 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "18 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3293 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1186 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "18 3 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3299 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 1187 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "18 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3305 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1188 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "19 0 0\n"); }
#line 3311 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1189 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "19 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3317 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1190 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "20 0 0\n"); }
#line 3323 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1191 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 0 0\n"); }
#line 3329 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1192 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 1 0\n"); }
#line 3335 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1193 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 2 0\n"); }
#line 3341 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1194 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 3 0\n"); }
#line 3347 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1195 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 4 0\n"); }
#line 3353 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1196 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 0 0\n"); }
#line 3359 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1197 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 1 0\n"); }
#line 3365 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1198 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 2 0\n"); }
#line 3371 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1199 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 3 0\n"); }
#line 3377 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1200 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 4 0\n"); }
#line 3383 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1201 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "23 0 0\n"); }
#line 3389 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1202 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "23 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3395 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1203 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "23 3 %i\n", ch);
						}
#line 3405 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1208 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "23 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3416 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1214 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "24 0 0\n"); }
#line 3422 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1215 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "24 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3428 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1216 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "25 0 0\n"); }
#line 3434 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1217 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "25 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3440 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1218 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "26 0 0\n"); }
#line 3446 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1219 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "26 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3452 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1220 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "27 0 0\n"); }
#line 3458 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1221 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "27 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3464 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1222 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "28 0 0\n"); }
#line 3470 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1223 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "28 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3476 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1224 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "29 0 0\n"); }
#line 3482 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1225 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "29 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3488 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1226 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "30 0 0\n"); }
#line 3494 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1227 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "31 0 0\n"); }
#line 3500 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1228 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "32 0 0\n"); }
#line 3506 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1229 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "33 0 0\n"); }
#line 3512 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1230 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "34 0 0\n"); }
#line 3518 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1231 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "35 0 0\n"); }
#line 3524 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1232 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "36 0 0\n"); }
#line 3530 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1233 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "37 0 0\n"); }
#line 3536 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1234 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "38 0 0\n"); }
#line 3542 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1235 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "39 0 0\n"); }
#line 3548 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1236 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "40 0 0\n"); }
#line 3554 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1237 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "41 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3560 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1238 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "42 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3566 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1239 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "43 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3572 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1240 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "44 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3578 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1241 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "45 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3584 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1242 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "46 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3590 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1243 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "46 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3601 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1249 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "47 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3607 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1251 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "47 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3618 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1257 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "48 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3624 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1259 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "48 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3635 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1265 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "49 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3641 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1267 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "49 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3652 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1273 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "50 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3658 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1275 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "50 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3669 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1281 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "51 0 0\n"); }
#line 3675 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1282 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "52 0 0\n"); }
#line 3681 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1283 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "53 0 0\n"); }
#line 3687 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1284 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "54 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3693 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1285 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "55 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3699 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1287 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "55 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3710 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1293 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "56 0 0\n"); }
#line 3716 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1295 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "58 0 0\n"); }
#line 3722 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1296 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "58 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");		
						}
#line 3733 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1302 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "59 0 0\n"); }
#line 3739 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1303 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "59 1 1\n");
						 else
						  fprintf(output, "59 1 0\n");
					        }
#line 3750 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1309 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "59 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3756 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1310 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "59 3 %i\n", ch);
						}
#line 3766 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1315 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "59 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 3780 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1325 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "60 0 0\n"); }
#line 3786 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1326 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "60 1 1\n");
						 else
						  fprintf(output, "60 1 0\n");
					        }
#line 3797 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1332 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "60 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3803 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1333 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "60 3 %i\n", ch);
						}
#line 3813 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1338 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "60 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 3827 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1348 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "61 0 0"); }
#line 3833 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1349 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "62 0 0\n"); }
#line 3839 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1350 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "63 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3845 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1351 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "64 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3851 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1352 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "65 0 0\n"); }
#line 3857 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1353 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "66 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3863 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1354 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "67 0 0\n"); }
#line 3869 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1355 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "68 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3875 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1356 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "69 0 0\n"); }
#line 3881 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1357 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "70 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3887 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1358 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "71 0 0\n"); }
#line 3893 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1359 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "72 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3899 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1360 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "73 0 0\n"); }
#line 3905 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1361 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "74 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3911 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1362 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "75 0 0\n"); }
#line 3917 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1363 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "76 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3923 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1364 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "77 0 0\n"); }
#line 3929 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1365 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "78 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3935 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1366 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "79 0 0\n"); }
#line 3941 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1367 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "80 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3947 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1368 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "81 0 0\n"); }
#line 3953 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1369 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "82 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3959 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1370 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "83 0 0\n"); }
#line 3965 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1371 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "84 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3971 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1372 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "85 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3977 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1373 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "86 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3983 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1374 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "87 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3989 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1375 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "88 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3995 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1376 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "89 0 0\n"); }
#line 4001 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1377 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "90 0 0\n"); }
#line 4007 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1378 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "91 0 0\n"); }
#line 4013 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1379 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "92 0 0\n"); }
#line 4019 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1381 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "92 1 1\n");
		 else
		  fprintf(output, "92 1 0\n");
		}
#line 4030 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1387 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "92 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4036 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1389 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "92 3 %i\n", ch);
		}
#line 4046 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1395 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "92 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4060 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1404 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "93 0 0\n"); }
#line 4066 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1405 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "94 0 0\n"); }
#line 4072 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1406 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "95 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4078 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1407 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "96 0 0\n"); }
#line 4084 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1408 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "97 0 0\n"); }
#line 4090 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1409 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "98 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4096 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1410 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "99 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4102 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1411 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "100 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4108 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1412 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "101 0 0\n"); }
#line 4114 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1413 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "102 0 0\n"); }
#line 4120 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1414 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "103 0 0\n"); }
#line 4126 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1415 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "104 0 0\n"); }
#line 4132 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1416 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "105 0 0\n"); }
#line 4138 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1417 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "106 0 0\n"); }
#line 4144 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1418 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "107 0 0\n"); }
#line 4150 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1419 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "108 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4156 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1421 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "108 1 1\n");
		 else
		  fprintf(output, "108 1 0\n");
		}
#line 4167 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1427 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "108 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4173 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1429 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "108 3 %i\n", ch);
		}
#line 4183 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1435 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "108 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4197 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1444 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "109 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4203 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1446 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "109 1 1\n");
		 else
		  fprintf(output, "109 1 0\n");
		}
#line 4214 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1452 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "109 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4220 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1454 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "109 3 %i\n", ch);
		}
#line 4230 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1460 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "109 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4244 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1469 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "110 0 0\n"); }
#line 4250 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1470 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "111 0 0\n"); }
#line 4256 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1471 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "112 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4262 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1472 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "113 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4268 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1474 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "114 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4282 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1484 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "115 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4296 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1494 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "116 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4310 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1503 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "117 0 0\n"); }
#line 4316 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1505 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "117 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4330 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1514 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "118 0 0\n"); }
#line 4336 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1516 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "118 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4350 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1525 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "119 1 0\n"); }
#line 4356 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1526 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "119 2 0\n"); }
#line 4362 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1527 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "119 3 0\n"); }
#line 4368 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1528 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "119 4 0\n"); }
#line 4374 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1529 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "120 0 0\n"); }
#line 4380 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1530 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "120 1 1\n");
						 else
						  fprintf(output, "120 1 0\n");
					        }
#line 4391 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1536 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "120 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4397 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1537 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "120 3 %i\n", ch);
						}
#line 4407 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1542 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "120 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4421 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1551 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "121 0 0\n"); }
#line 4427 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1552 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "121 1 1\n");
						 else
						  fprintf(output, "121 1 0\n");
					        }
#line 4438 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1558 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "121 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4444 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1559 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "121 3 %i\n", ch);
						}
#line 4454 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1564 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "121 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4468 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1573 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "122 0 0\n"); }
#line 4474 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1574 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "123 0 0\n"); }
#line 4480 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1575 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "124 0 0\n"); }
#line 4486 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1576 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "125 0 0\n"); }
#line 4492 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1577 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "126 0 0\n"); }
#line 4498 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1578 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "127 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4512 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1587 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "128 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4518 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1588 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "129 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4524 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1589 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "130 0 0\n"); }
#line 4530 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1590 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "131 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4544 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1599 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "132 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4550 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1600 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "133 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4564 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1609 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "134 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4578 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1618 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "135 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4592 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1627 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "136 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4598 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1628 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "137 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4604 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1629 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "138 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4610 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1630 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "139 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4616 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1631 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "140 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4622 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1632 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "141 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4636 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1641 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "142 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4642 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1642 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "143 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4648 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1643 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "144 0 0\n"); }
#line 4654 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1644 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "145 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4668 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1653 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "146 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4682 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1662 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "147 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4696 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1671 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "148 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4702 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1672 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "149 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4716 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1681 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "150 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4730 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1690 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "151 0 0\n"); }
#line 4736 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1691 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "152 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4750 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1700 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "153 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4764 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1709 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "154 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4778 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1718 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "155 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4792 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1727 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "156 0 0\n"); }
#line 4798 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1728 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "157 0 0\n"); }
#line 4804 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1729 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "158 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4818 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1738 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "159 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4824 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1739 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "160 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4838 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1748 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "161 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4844 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1749 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "161 0 0\n"); }
#line 4850 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1750 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "162 0 0\n"); }
#line 4856 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1751 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 0 0\n"); }
#line 4862 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1752 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 1 0\n"); }
#line 4868 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1753 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 2 0\n"); }
#line 4874 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1754 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 3 0\n"); }
#line 4880 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1755 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 4 0\n"); }
#line 4886 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1756 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "164 0 0\n"); }
#line 4892 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1757 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "165 0 0\n"); }
#line 4898 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1758 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "166 0 0\n"); }
#line 4904 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1759 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "167 0 0\n"); }
#line 4910 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1760 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "168 0 0\n"); }
#line 4916 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1761 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "169 0 0\n"); }
#line 4922 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 1762 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "170 0 0\n"); }
#line 4928 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 1763 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "171 0 0\n"); }
#line 4934 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 1764 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "172 0 0\n"); }
#line 4940 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1765 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "173 0 0\n"); }
#line 4946 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1766 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "174 0 0\n"); }
#line 4952 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1767 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "175 0 0\n");	}
#line 4958 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 1768 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "176 0 0\n");	}
#line 4964 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 1769 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "177 0 0\n");	}
#line 4970 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 1770 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "178 0 0\n"); }
#line 4976 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1771 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "178 1 %s\n", (yyvsp[0]).getString().c_str());	}
#line 4982 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 1772 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "178 2 %s\n", (yyvsp[0]).getString().c_str());	}
#line 4988 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1773 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "178 3 %i\n", ch);
						}
#line 4998 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1778 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "178 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5012 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1787 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "179 0 0\n");	}
#line 5018 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1788 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "180 0 0\n");	}
#line 5024 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1789 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "181 0 0\n");	}
#line 5030 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1790 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "182 0 0\n");	}
#line 5036 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1791 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "183 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5042 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1792 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "184 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5048 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1793 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "185 0 0\n"); }
#line 5054 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1794 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "186 0 0\n"); }
#line 5060 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1795 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "187 0 0\n"); }
#line 5066 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1796 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "188 0 0\n"); }
#line 5072 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1797 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "189 0 0\n"); }
#line 5078 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1798 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "190 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5092 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 1807 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "191 0 0\n"); }
#line 5098 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 1808 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "192 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5112 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 1817 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "193 0 0\n"); }
#line 5118 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 1818 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "194 0 0\n"); }
#line 5124 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 1819 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "195 0 0\n"); }
#line 5130 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 1820 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "196 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5136 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 1821 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "197 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5142 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 1823 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 if ((yyvsp[0]) == "true")
		 	  			  fprintf(output, "197 1 1\n");
			 			 else
			  			  fprintf(output, "197 1 0\n");
						}
#line 5153 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 1829 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "197 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5159 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 1831 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "197 3 %i\n", ch);
						}
#line 5169 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 1837 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "197 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5180 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 1843 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "198 0 0\n"); }
#line 5186 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 1844 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 0 0\n"); }
#line 5192 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 1845 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 1 0\n"); }
#line 5198 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 1846 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 2 0\n"); }
#line 5204 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 1847 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 3 0\n"); }
#line 5210 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 1848 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 4 0\n"); }
#line 5216 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 1849 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "200 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5222 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 1850 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 0 0\n"); }
#line 5228 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 1851 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 1 0\n"); }
#line 5234 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 1852 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 2 0\n"); }
#line 5240 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 1853 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 3 0\n"); }
#line 5246 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 1854 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 4 0\n"); }
#line 5252 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 1855 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 0 0\n"); }
#line 5258 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 1856 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 1 0\n"); }
#line 5264 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 1857 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 2 0\n"); }
#line 5270 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 1858 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 3 0\n"); }
#line 5276 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 1859 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 4 0\n"); }
#line 5282 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 1860 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 0 0\n"); }
#line 5288 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 1861 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 1 0\n"); }
#line 5294 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 1862 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 2 0\n"); }
#line 5300 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 1863 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 3 0\n"); }
#line 5306 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 1864 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 4 0\n"); }
#line 5312 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 1867 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "204 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5323 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 1873 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "205 0 0\n"); }
#line 5329 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 1874 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "206 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5335 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 1875 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "207 0 0\n"); }
#line 5341 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 1876 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "207 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5347 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 1877 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "208 0 0\n"); }
#line 5353 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 1878 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "209 0 0\n"); }
#line 5359 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 1879 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "210 0 0\n"); }
#line 5365 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 1880 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 0 0\n"); }
#line 5371 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 1881 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 1 0\n"); }
#line 5377 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 1882 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 2 0\n"); }
#line 5383 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 1883 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 3 0\n"); }
#line 5389 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 1884 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 4 0\n"); }
#line 5395 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 1885 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 0 0\n"); }
#line 5401 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 1886 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 1 0\n"); }
#line 5407 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 1887 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 2 0\n"); }
#line 5413 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 1888 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 3 0\n"); }
#line 5419 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 1889 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 4 0\n"); }
#line 5425 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 1890 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "213 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5431 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 1891 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "213 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5442 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 1897 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "214 0 0\n"); }
#line 5448 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 1898 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "215 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5454 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 1899 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "216 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5460 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 1900 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "217 0 0\n"); }
#line 5466 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 1901 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "218 0 0\n"); }
#line 5472 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 1902 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "219 0 0\n"); }
#line 5478 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 1903 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "220 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5492 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 1912 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "221 0 0\n"); }
#line 5498 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 1913 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "222 0 0\n"); }
#line 5504 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 1914 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "223 0 0\n"); }
#line 5510 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 1915 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "224 0 0\n"); }
#line 5516 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 1916 "pnfasm.ypp" /* yacc.c:1646  */
    { /* Do nothing... */ }
#line 5522 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 1917 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "%s %s %s\n", (yyvsp[-2]).getString().c_str(), (yyvsp[-1]).getString().c_str(), (yyvsp[0]).getString().c_str()); }
#line 5528 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 1927 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5534 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 1929 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 if ((yyvsp[0]) == "true")
		 	  			  fprintf(output, "57 1 1\n");
			 			 else
			  			  fprintf(output, "57 1 0\n");
						}
#line 5545 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 1935 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5551 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 1937 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "57 3 %i\n", ch);
						}
#line 5561 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 1943 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5572 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 1949 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 1 0\n"); }
#line 5578 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 1950 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 2 0\n"); }
#line 5584 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 1951 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 3 0\n"); }
#line 5590 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 1952 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 4 0\n"); }
#line 5596 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 1954 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 0 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5607 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 1961 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 1 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5618 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 1968 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 2 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5629 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 1975 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 3 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5640 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 1984 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#include %s\n", (yyvsp[0]).getString().c_str()); }
#line 5646 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 1985 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#include <%s>\n", (yyvsp[-2]).getString().c_str()); }
#line 5652 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 1986 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#import %s \n", (yyvsp[0]).getString().c_str()); }
#line 5658 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 1987 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#import <%s> \n", (yyvsp[-2]).getString().c_str()); }
#line 5664 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 1988 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#define %s %s\n", (yyvsp[-1]).getString().c_str(), (yyvsp[0]).getString().c_str()); }
#line 5670 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 1989 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#macro %s\n", (yyvsp[0]).getString().c_str()); }
#line 5676 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 1990 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#endm\n"); }
#line 5682 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 1991 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#undef %s\n", (yyvsp[0]).getString().c_str()); }
#line 5688 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 1992 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#ifdef %s\n", (yyvsp[0]).getString().c_str()); }
#line 5694 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 1993 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#ifndef %s\n", (yyvsp[0]).getString().c_str()); }
#line 5700 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 1994 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#else\n"); }
#line 5706 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 1995 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#endif\n"); }
#line 5712 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 1996 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_DATE()\n"); }
#line 5718 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 1997 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_TIME()\n"); }
#line 5724 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 1998 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_LINE()\n"); }
#line 5730 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 1999 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_FILE()\n"); }
#line 5736 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2000 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_CDATE()\n"); }
#line 5742 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2001 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_CTIME()\n"); }
#line 5748 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2002 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "\' %s\n", (yyvsp[0]).getString().c_str()); }
#line 5754 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2005 "pnfasm.ypp" /* yacc.c:1646  */
    { mode = 0; }
#line 5760 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2006 "pnfasm.ypp" /* yacc.c:1646  */
    { mode = 1; }
#line 5766 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2007 "pnfasm.ypp" /* yacc.c:1646  */
    { mode = 2; }
#line 5772 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;


#line 5776 "pnfasm.tab.cpp" /* yacc.c:1646  */
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
#line 2010 "pnfasm.ypp" /* yacc.c:1906  */

/* Additional C/C++ Code */
void yyerror(char const * c)
{
 cout << "* ERROR: " << yylineno << ": " << c << endl;
}
