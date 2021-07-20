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
			 9. Fixed to add new instructions again...
			10. Added NTIMES instruction.
			11. Added CMP instruction.
			12. Added RUN, JRUN, & PNFRUN instructions.
			13. Added struct instructions.
			14. Added more struct instructions.
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

#line 883 "pnfasm.tab.cpp" /* yacc.c:339  */

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
    IFNCSYNCR = 500,
    IFNCFIND = 501,
    IFNCFRET = 502,
    IFNCFPARAM = 503,
    IFNCFBRET = 504,
    IFNCFBPARAM = 505,
    IFNCDEFAULT = 506,
    IFNCDEFAULT2 = 507,
    IFNCSDEFAULTV = 508,
    IFNCSDEFAULTV2 = 509,
    IFNCGDEFAULTV2 = 510,
    IFNCDEFAULTSYNC = 511,
    INTIMES = 512,
    ICMP = 513,
    IRUN = 514,
    IJRUN = 515,
    IPNFRUN = 516,
    ISTRUCT = 517,
    ISTRUCTVAR = 518,
    IENDSTRUCT = 519,
    ISTRUCTNAME = 520,
    ISTRUCTONAME = 521,
    ISTRUCTD = 522,
    ISTRUCTUSE = 523,
    ISTRUCTUSING = 524,
    ISTRUCTUSINGNAME = 525,
    ISTRUCTGET = 526,
    ISTRUCTPUT = 527,
    ISTRUCTTYPE = 528,
    ISTRUCTTYPE2 = 529,
    ISTRUCTNAME2 = 530,
    ISTRUCTNAME3 = 531,
    IUNION = 532,
    IUNIONVAR = 533,
    IENDUNION = 534,
    IUNIONNAME = 535,
    IUNIONONAME = 536,
    IUNIOND = 537,
    IUNIONUSE = 538,
    IUNIONUSING = 539,
    IUNIONUSINGNAME = 540,
    IUNIONGET = 541,
    IUNIONPUT = 542,
    IUNIONTYPE = 543,
    IUNIONTYPE2 = 544,
    IUNIONNAME2 = 545,
    IUNIONNAME3 = 546,
    IMODE = 547,
    IEXTMODE = 548,
    IMCHECK = 549,
    IMSUPP = 550,
    IMEXTCHECK = 551,
    IMEXTSUPP = 552,
    ICPY = 553,
    IADDSEG = 554,
    IREMSEG = 555,
    ICOLLSEG = 556,
    IEXPSEG = 557,
    ICPYSEG = 558,
    ISEGLOAD = 559,
    ISEGSTORE = 560,
    ISEGPUSH = 561,
    ISEGPOP = 562,
    ISEGTOP = 563,
    ISEGVLOAD = 564,
    ISEGVSTORE = 565,
    TVOID = 566,
    TBOOLEAN = 567,
    TNUMBER = 568,
    TCHARACTER = 569,
    TSTRING = 570,
    VOID = 571,
    BOOLEAN = 572,
    NUMBER = 573,
    CHARACTER = 574,
    STRING = 575
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

#line 1252 "pnfasm.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   1316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  324
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  502
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1263

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   577

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     321,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   322,   323
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1151,  1151,  1152,  1155,  1156,  1157,  1158,  1159,  1160,
    1161,  1164,  1165,  1166,  1167,  1175,  1176,  1177,  1178,  1179,
    1185,  1186,  1191,  1200,  1201,  1207,  1208,  1213,  1222,  1223,
    1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,
    1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1276,  1282,
    1283,  1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,
    1293,  1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,
    1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1317,
    1318,  1325,  1326,  1333,  1334,  1341,  1342,  1349,  1350,  1351,
    1352,  1353,  1354,  1361,  1363,  1364,  1370,  1371,  1377,  1378,
    1383,  1393,  1394,  1400,  1401,  1406,  1416,  1417,  1418,  1419,
    1420,  1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1455,
    1456,  1462,  1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,
    1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1495,
    1496,  1502,  1512,  1513,  1520,  1521,  1527,  1537,  1538,  1539,
    1540,  1541,  1551,  1561,  1571,  1572,  1582,  1583,  1593,  1594,
    1595,  1596,  1597,  1598,  1604,  1605,  1610,  1619,  1620,  1626,
    1627,  1632,  1641,  1642,  1643,  1644,  1645,  1646,  1655,  1656,
    1657,  1658,  1667,  1668,  1677,  1686,  1695,  1696,  1697,  1698,
    1699,  1700,  1709,  1710,  1711,  1712,  1721,  1730,  1739,  1740,
    1749,  1758,  1759,  1768,  1777,  1786,  1795,  1796,  1797,  1806,
    1807,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,
    1825,  1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,
    1835,  1836,  1837,  1838,  1839,  1840,  1841,  1846,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,  1866,
    1875,  1876,  1885,  1886,  1887,  1888,  1889,  1890,  1897,  1898,
    1904,  1911,  1912,  1913,  1914,  1915,  1916,  1917,  1918,  1919,
    1920,  1921,  1922,  1923,  1924,  1925,  1926,  1927,  1928,  1929,
    1930,  1931,  1932,  1933,  1934,  1935,  1936,  1938,  1945,  1946,
    1947,  1948,  1949,  1950,  1951,  1952,  1953,  1954,  1955,  1956,
    1957,  1958,  1959,  1960,  1961,  1962,  1963,  1969,  1970,  1971,
    1972,  1973,  1974,  1975,  1976,  1977,  1978,  1979,  1980,  1981,
    1982,  1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,
    1992,  1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,
    2010,  2019,  2028,  2037,  2046,  2047,  2056,  2065,  2074,  2077,
    2080,  2089,  2092,  2095,  2098,  2102,  2105,  2108,  2111,  2115,
    2124,  2133,  2134,  2143,  2152,  2161,  2164,  2167,  2176,  2179,
    2182,  2185,  2189,  2192,  2195,  2198,  2202,  2206,  2210,  2211,
    2218,  2219,  2225,  2235,  2236,  2243,  2244,  2250,  2260,  2261,
    2268,  2269,  2275,  2285,  2286,  2293,  2294,  2300,  2311,  2315,
    2319,  2323,  2325,  2327,  2331,  2333,  2335,  2339,  2343,  2346,
    2347,  2348,  2349,  2350,  2351,  2353,  2354,  2361,  2364,  2365,
    2372,  2373,  2379,  2386,  2387,  2388,  2389,  2390,  2397,  2404,
    2411,  2421,  2422,  2423,  2424,  2425,  2426,  2427,  2428,  2429,
    2430,  2431,  2432,  2433,  2434,  2435,  2436,  2437,  2438,  2439,
    2442,  2443,  2444
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
  "IFNCGDEF", "IFNCPOINT", "IFNCLENGTH", "IFNCSYNCR", "IFNCFIND",
  "IFNCFRET", "IFNCFPARAM", "IFNCFBRET", "IFNCFBPARAM", "IFNCDEFAULT",
  "IFNCDEFAULT2", "IFNCSDEFAULTV", "IFNCSDEFAULTV2", "IFNCGDEFAULTV2",
  "IFNCDEFAULTSYNC", "INTIMES", "ICMP", "IRUN", "IJRUN", "IPNFRUN",
  "ISTRUCT", "ISTRUCTVAR", "IENDSTRUCT", "ISTRUCTNAME", "ISTRUCTONAME",
  "ISTRUCTD", "ISTRUCTUSE", "ISTRUCTUSING", "ISTRUCTUSINGNAME",
  "ISTRUCTGET", "ISTRUCTPUT", "ISTRUCTTYPE", "ISTRUCTTYPE2",
  "ISTRUCTNAME2", "ISTRUCTNAME3", "IUNION", "IUNIONVAR", "IENDUNION",
  "IUNIONNAME", "IUNIONONAME", "IUNIOND", "IUNIONUSE", "IUNIONUSING",
  "IUNIONUSINGNAME", "IUNIONGET", "IUNIONPUT", "IUNIONTYPE", "IUNIONTYPE2",
  "IUNIONNAME2", "IUNIONNAME3", "IMODE", "IEXTMODE", "IMCHECK", "IMSUPP",
  "IMEXTCHECK", "IMEXTSUPP", "ICPY", "IADDSEG", "IREMSEG", "ICOLLSEG",
  "IEXPSEG", "ICPYSEG", "ISEGLOAD", "ISEGSTORE", "ISEGPUSH", "ISEGPOP",
  "ISEGTOP", "ISEGVLOAD", "ISEGVSTORE", "TVOID", "TBOOLEAN", "TNUMBER",
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
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,    10,   576,   577
};
# endif

#define YYPACT_NINF -310

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-310)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -310,     0,  -310,  -310,  -309,    -7,  -310,  -310,  -310,   181,
     223,   143,   153,  -310,   186,   255,   257,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,   165,   196,   258,   231,
     260,     1,    11,     5,   198,   263,   202,   265,   206,   267,
     210,   268,   214,   235,   218,   236,   269,    16,    21,   151,
     239,   240,   243,   244,   247,   248,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   171,   174,   176,   177,   179,   286,   287,   288,
     289,   182,   290,    26,   184,    31,    36,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    41,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,    46,    51,   337,   338,   339,   340,
     341,   342,   343,   185,   187,   222,    56,    61,   344,   348,
     349,   350,   351,   352,   353,   355,   354,   356,   357,   358,
     359,   360,   361,   365,   366,   367,   368,   369,   370,   372,
     371,   373,   374,   375,   378,   377,   379,   376,   380,   381,
     382,   383,   388,   389,   386,   390,   387,   251,   393,    66,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,    71,   408,   409,   410,   411,   412,
     413,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     426,   428,   427,    76,    81,    86,   429,    91,    96,   101,
     430,   432,   431,   252,   435,   436,   437,   106,   111,   253,
     438,   439,   440,   443,   444,   445,   446,   447,   116,   121,
     448,   449,   450,   451,   126,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   466,   463,   464,   465,   156,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   157,   484,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   131,   136,   141,   146,   497,
     498,   499,   500,   501,   504,   503,   505,   506,   508,   509,
     226,   256,  -310,  -310,  -310,  -310,  -310,  -310,  -310,   347,
     346,  -310,   414,  -310,   469,   502,  -310,  -310,  -310,  -310,
     254,   364,   507,   363,   425,   434,   510,   415,   433,   511,
     512,   513,   514,   515,   516,   517,   518,   520,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   552,   551,   553,   554,   555,   556,
     559,   558,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   521,   550,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   615,   617,   618,   619,   620,
     616,   623,   188,   158,   161,   164,   189,   624,   621,   626,
     627,   625,   628,   629,   630,   631,   632,   633,   634,   635,
     637,   638,   639,   642,   641,   644,   643,   646,   645,   648,
     647,   650,   649,   652,   651,   654,   653,   656,   655,   658,
     657,   660,   659,   661,   662,   663,   664,   667,   668,   669,
     670,   671,   672,   636,   673,   675,   676,   677,   678,   680,
     679,   681,   682,   685,   686,   687,   688,   689,   690,   691,
     692,   694,   695,   693,   696,   697,   700,   701,   699,   702,
     698,   704,   703,   705,   706,   707,   708,   709,   710,   713,
     711,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   732,   734,   735,   736,
     733,   737,   738,   741,   739,   740,   742,   743,   744,   747,
     748,   749,   750,   751,   752,   753,   755,   745,   754,   756,
     757,   760,   759,   761,   764,   762,   763,   765,   766,   768,
     771,   769,   770,   772,   774,   773,   777,   778,   779,   780,
     781,   782,   783,   784,   785,   786,   787,   788,   789,   790,
     791,   792,   793,   794,   795,   796,   797,   758,   798,   799,
     800,   801,   803,   805,   806,   807,   808,   811,   812,   813,
     814,   815,   804,   816,   817,   818,   819,   820,   821,   822,
     823,   824,   825,   826,   827,   829,   831,   832,   833,   834,
     835,   836,   837,   838,   839,   840,   842,   843,   844,   845,
     846,   847,   848,   849,   850,   851,   852,   853,   854,   855,
     856,   857,   859,   858,   860,   863,   864,   865,   866,   867,
     868,   869,   870,   871,   872,   873,   874,   875,   876,   877,
     879,   878,   880,   883,   884,   885,   886,   887,   888,   889,
     890,   891,   892,   893,   894,   895,   896,   897,   898,   899,
     900,   901,   902,   903,   904,   905,   906,   907,   908,   909,
     910,   911,   912,   913,   914,   915,   916,   921,   918,   919,
     920,   925,   926,   923,   928,   929,   930,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,   946,
     943,   948,   949,   950,   951,   952,   953,   954,   955,   956,
     957,   958,   960,   961,   959,   962,   963,   966,   967,   965,
     968,   969,   972,   973,   971,   974,   975,   978,   979,   977,
     980,   964,   970,   976,   981,   983,   982,   984,   985,   988,
     989,   990,   991,   992,   993,   994,   997,   996,  -310,   998,
     467,   622,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    10,     0,     0,   500,   501,   502,     0,
       0,     0,     0,   487,     0,     0,     0,   491,   492,   493,
     494,   495,   496,   497,   498,   499,     0,     0,     0,     0,
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
       0,     0,     4,     3,     5,     6,     7,     8,     9,     0,
       0,   481,     0,   483,     0,     0,   486,   488,   489,   490,
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
       0,     0,     0,     0,     0,     0,     0,     0,   465,     0,
       0,     0,   485,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   468,   477,   473,   469,
     478,   474,   470,   479,   475,   471,   480,   476,   472,   124,
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
     255,   256,   257,   258,   259,   260,   262,   261,   263,   264,
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
     466,   482,   484
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   313,   314,   315,   316,   317,   318
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       2,     3,   319,     4,     5,     6,     7,     8,     9,    10,
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
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   320,   336,   337,   338,   339,   340,   346,   347,   348,
     349,   312,   341,   342,   343,   344,   345,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   442,   443,   444,
     445,   446,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   490,   491,   492,   493,   494,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   587,   588,   589,
     590,   591,   606,   607,   608,   609,   610,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   645,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   702,   703,   704,
     705,   706,   751,   752,   753,   754,   755,   756,   757,   758,
     759,   760,   761,   762,   763,   764,   765,   766,   767,   768,
     769,   770,   393,   325,   394,   395,   396,   721,   738,   722,
     739,   723,   740,   326,   908,   909,   330,   911,   910,   912,
     914,   913,   425,   915,   916,   427,   426,   429,   431,   428,
     433,   430,   432,   439,   434,   447,   527,   440,   529,   448,
     528,   321,   530,   322,   906,   917,   327,   331,   907,   918,
     350,   351,   352,   353,   355,   356,   357,   358,   360,   361,
     362,   363,   365,   366,   367,   368,   370,   371,   372,   373,
     376,   377,   378,   379,   531,   532,   533,   534,   782,   783,
     784,   785,   333,   323,   334,   324,   374,   380,   375,   381,
     397,   399,   398,   400,   401,   403,   402,   404,   405,   407,
     406,   408,   584,   663,   585,   664,   678,   786,   679,   787,
     793,   335,   794,   332,   354,   328,   359,   329,   364,   369,
     382,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   435,   436,   437,
     438,   441,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   520,   521,
       0,     0,   522,   523,     0,   545,   524,   525,   526,   546,
     547,   548,   549,   788,   789,   553,   551,   550,   552,     0,
     555,   554,   559,   556,   557,   558,   560,   561,   562,   563,
     795,   797,   567,   565,   564,   566,     0,   574,   568,   569,
     570,   571,   572,     0,   573,   575,   576,   577,   578,   579,
     580,   581,   583,   582,   586,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   611,
     612,   613,   614,     0,     0,   615,   616,   617,   618,   619,
     620,   621,   801,   623,   790,   625,   622,   626,   624,   627,
     628,   798,   644,   661,   662,   660,   665,   666,   667,   680,
     799,   802,   681,   682,   683,   684,   685,   686,   687,   698,
     699,   700,   701,   707,   708,   709,   710,   711,     0,     0,
       0,     0,   712,   713,   714,   715,   716,   717,   718,   719,
     720,   724,   725,   726,   727,   728,   729,   730,   731,   791,
    1261,   734,     0,   732,   733,   741,   735,   736,   737,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   771,   772,
     773,     0,     0,   774,   775,   776,   777,   779,   778,   780,
     781,     0,   792,     0,     0,     0,   800,   796,     0,   805,
     803,   806,   804,   807,   810,   808,   811,   809,   812,   813,
     859,     0,   814,   815,   816,   817,   818,   819,   820,   821,
     822,   823,   824,   825,   826,   827,   828,   829,   830,   831,
     832,   833,     0,     0,   834,   835,   836,   837,   838,   839,
     860,   840,   841,   842,   843,   844,   845,   846,   847,   848,
     849,   850,   851,   852,   853,   854,   855,   856,   857,     0,
     861,   858,   863,   862,   865,   864,   867,   866,   869,   868,
     871,   870,   873,   872,   874,   875,   876,   877,   878,   879,
     880,   881,   882,   883,     0,     0,   884,   885,   886,   887,
     888,   889,     0,   891,   890,   893,   892,   895,   894,   897,
     896,   899,   898,   900,   901,     0,   904,   902,   903,   905,
     919,   920,   921,   923,   922,  1262,   926,   924,   927,   925,
     928,   931,   929,   932,   930,   965,   933,   934,   935,   936,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,   950,   951,   952,   953,   954,     0,   955,
     956,   957,   958,   959,   960,   961,   962,     0,   963,     0,
     964,   967,   968,   966,   970,   969,   971,   972,     0,   973,
     974,   975,   976,   977,   978,   979,   980,   981,     0,     0,
     982,   983,   985,   984,   992,   987,   986,   988,   990,   989,
     993,   994,   991,   995,     0,   999,   996,   997,   998,  1001,
    1000,  1002,  1003,  1004,  1005,  1006,  1007,     0,  1008,     0,
    1009,  1012,  1010,  1013,  1011,  1014,  1017,  1015,  1018,  1016,
    1019,  1020,  1021,  1022,     0,  1023,  1024,  1025,  1027,  1026,
       0,  1039,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
       0,  1037,  1036,  1038,  1040,  1079,  1041,  1042,  1043,  1044,
    1046,  1045,  1047,  1048,  1051,  1049,  1050,  1052,  1054,  1053,
    1056,  1057,  1055,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,     0,     0,  1080,  1083,  1081,  1084,
    1082,  1085,  1086,     0,  1094,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1095,     0,  1097,  1098,  1099,  1096,  1101,  1100,
    1102,     0,  1103,  1106,  1104,  1107,  1105,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,     0,  1117,  1116,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,     0,  1133,  1135,     0,  1132,  1134,  1136,  1137,
    1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,     0,     0,  1150,  1152,  1153,  1151,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,     0,     0,
       0,     0,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,     0,     0,  1206,     0,  1204,  1205,  1210,  1207,
    1208,  1209,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,
    1219,  1220,     0,     0,  1221,  1222,  1223,  1224,  1226,  1225,
    1243,  1228,  1227,  1229,  1231,  1230,  1244,  1233,  1232,  1234,
    1236,  1235,  1245,  1238,  1237,  1239,  1241,  1240,  1248,  1246,
    1242,  1247,  1249,  1250,  1251,  1252,  1253,     0,     0,  1254,
    1255,  1256,  1257,  1258,  1259,     0,  1260
};

static const yytype_int16 yycheck[] =
{
       0,     1,   311,     3,     4,     5,     6,     7,     8,     9,
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
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   318,   311,   312,   313,   314,   315,   312,   313,   314,
     315,   321,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   312,   313,   314,   315,   311,   312,   313,
     314,   315,   311,   320,   313,   314,   315,   311,   311,   313,
     313,   315,   315,   320,   316,   317,   311,   316,   320,   318,
     316,   320,   311,   319,   320,   311,   315,   311,   311,   315,
     311,   315,   315,   311,   315,   311,   311,   315,   311,   315,
     315,   320,   315,   322,   316,   316,   320,   311,   320,   320,
     312,   313,   314,   315,   312,   313,   314,   315,   312,   313,
     314,   315,   312,   313,   314,   315,   312,   313,   314,   315,
     312,   313,   314,   315,   312,   313,   314,   315,   312,   313,
     314,   315,   311,   320,   313,   322,   311,   311,   313,   313,
     311,   311,   313,   313,   311,   311,   313,   313,   311,   311,
     313,   313,   311,   311,   313,   313,   313,   311,   315,   313,
     316,   311,   318,   315,   311,   320,   311,   320,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
      -1,    -1,   313,   313,    -1,   311,   315,   315,   315,   311,
     311,   311,   311,   316,   318,   311,   313,   315,   313,    -1,
     313,   315,   311,   315,   315,   315,   311,   311,   311,   311,
     316,   318,   311,   313,   315,   313,    -1,   311,   315,   315,
     315,   313,   315,    -1,   315,   315,   315,   315,   315,   311,
     311,   315,   315,   313,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,    -1,    -1,   313,   313,   311,   311,   311,
     311,   311,   317,   311,   320,   311,   315,   311,   315,   311,
     313,   316,   313,   311,   313,   315,   311,   311,   311,   311,
     316,   318,   313,   313,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,    -1,    -1,
      -1,    -1,   315,   315,   315,   315,   315,   311,   315,   315,
     315,   311,   311,   311,   311,   311,   311,   311,   311,   320,
     323,   311,    -1,   315,   315,   311,   315,   315,   315,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,    -1,    -1,   313,   313,   311,   313,   311,   313,   311,
     311,    -1,   320,    -1,    -1,    -1,   316,   320,    -1,   316,
     319,   317,   320,   318,   316,   319,   316,   320,   316,   316,
     319,    -1,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,    -1,    -1,   318,   318,   318,   318,   316,   318,
     320,   318,   318,   318,   318,   316,   318,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,    -1,
     316,   318,   316,   318,   316,   318,   316,   318,   316,   318,
     316,   318,   316,   318,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,    -1,    -1,   318,   318,   318,   318,
     318,   318,    -1,   318,   320,   318,   320,   318,   320,   318,
     320,   316,   320,   316,   316,    -1,   320,   318,   318,   316,
     316,   320,   316,   318,   317,   323,   316,   319,   317,   320,
     318,   316,   319,   316,   320,   319,   318,   318,   316,   318,
     316,   318,   316,   318,   316,   318,   316,   318,   316,   318,
     316,   318,   316,   318,   316,   318,   316,   318,    -1,   318,
     318,   318,   318,   316,   316,   316,   316,    -1,   317,    -1,
     318,   316,   316,   320,   316,   318,   316,   318,    -1,   318,
     318,   316,   316,   316,   316,   316,   316,   316,    -1,    -1,
     318,   317,   319,   318,   316,   318,   320,   317,   319,   318,
     316,   318,   320,   318,    -1,   316,   320,   320,   320,   316,
     320,   320,   316,   316,   316,   316,   316,    -1,   317,    -1,
     318,   316,   319,   317,   320,   318,   316,   319,   316,   320,
     316,   316,   316,   320,    -1,   318,   318,   316,   318,   320,
      -1,   316,   320,   320,   320,   318,   318,   318,   318,   318,
      -1,   318,   320,   318,   320,   317,   320,   320,   318,   320,
     316,   320,   320,   320,   316,   320,   320,   316,   318,   320,
     316,   318,   320,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,    -1,    -1,   318,   316,   319,   316,
     320,   316,   316,    -1,   320,   318,   318,   316,   316,   316,
     316,   316,   316,    -1,   316,   316,   316,   320,   316,   318,
     317,    -1,   318,   316,   319,   316,   320,   316,   316,   316,
     316,   316,   316,   316,   316,    -1,   316,   318,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,    -1,   316,   316,    -1,   320,   318,   318,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,    -1,    -1,   318,   316,   318,   320,   318,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,    -1,    -1,
      -1,    -1,   320,   320,   320,   320,   320,   316,   320,   320,
     320,   316,   316,   320,   316,   316,   316,   316,   316,   316,
     316,   316,    -1,    -1,   316,    -1,   320,   320,   316,   320,
     320,   320,   316,   320,   316,   316,   316,   316,   316,   316,
     316,   316,    -1,    -1,   318,   318,   318,   317,   319,   318,
     316,   318,   320,   317,   319,   318,   316,   318,   320,   317,
     319,   318,   316,   318,   320,   317,   319,   318,   316,   318,
     320,   318,   318,   318,   316,   316,   316,    -1,    -1,   318,
     318,   318,   318,   316,   318,    -1,   318
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   325,     0,     1,     3,     4,     5,     6,     7,     8,
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
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   321,   326,   327,   328,   329,   330,   331,   311,
     318,   320,   322,   320,   322,   320,   320,   320,   320,   320,
     311,   311,   315,   311,   313,   311,   311,   312,   313,   314,
     315,   311,   312,   313,   314,   315,   312,   313,   314,   315,
     312,   313,   314,   315,   311,   312,   313,   314,   315,   311,
     312,   313,   314,   315,   311,   312,   313,   314,   315,   311,
     312,   313,   314,   315,   311,   313,   312,   313,   314,   315,
     311,   313,   311,   311,   312,   313,   314,   315,   311,   312,
     313,   314,   315,   311,   313,   314,   315,   311,   313,   311,
     313,   311,   313,   311,   313,   311,   313,   311,   313,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   315,   311,   315,   311,
     315,   311,   315,   311,   315,   311,   311,   311,   311,   311,
     315,   311,   311,   312,   313,   314,   315,   311,   315,   311,
     312,   313,   314,   315,   311,   312,   313,   314,   315,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   312,   313,   314,   315,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   312,   313,   314,   315,   311,   312,   313,   314,   315,
     311,   311,   313,   313,   315,   315,   315,   311,   315,   311,
     315,   312,   313,   314,   315,   311,   312,   313,   314,   315,
     311,   312,   313,   314,   315,   311,   311,   311,   311,   311,
     315,   313,   313,   311,   315,   313,   315,   315,   315,   311,
     311,   311,   311,   311,   315,   313,   313,   311,   315,   315,
     315,   313,   315,   315,   311,   315,   315,   315,   315,   311,
     311,   315,   313,   315,   311,   313,   311,   311,   312,   313,
     314,   315,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   312,   313,   314,
     315,   311,   311,   311,   311,   313,   313,   311,   311,   311,
     311,   311,   315,   311,   315,   311,   311,   311,   313,   311,
     312,   313,   314,   315,   311,   312,   313,   314,   315,   311,
     312,   313,   314,   315,   313,   311,   312,   313,   314,   315,
     311,   312,   313,   314,   315,   311,   312,   313,   314,   315,
     315,   311,   313,   311,   313,   311,   311,   311,   311,   312,
     313,   314,   315,   311,   312,   313,   314,   315,   313,   315,
     311,   313,   313,   311,   311,   311,   311,   311,   311,   312,
     313,   314,   315,   311,   312,   313,   314,   315,   311,   311,
     311,   311,   311,   312,   313,   314,   315,   311,   311,   311,
     311,   311,   315,   315,   315,   315,   315,   311,   315,   315,
     315,   311,   313,   315,   311,   311,   311,   311,   311,   311,
     311,   311,   315,   315,   311,   315,   315,   315,   311,   313,
     315,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   312,   313,   314,   315,   311,   312,   313,   314,
     315,   311,   312,   313,   314,   315,   311,   312,   313,   314,
     315,   311,   311,   311,   313,   313,   311,   313,   313,   311,
     311,   311,   312,   313,   314,   315,   311,   313,   316,   318,
     320,   320,   320,   316,   318,   316,   320,   318,   316,   316,
     316,   317,   318,   319,   320,   316,   317,   318,   319,   320,
     316,   316,   316,   316,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   318,   318,   318,   318,   316,   318,
     318,   318,   318,   318,   316,   318,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   318,   319,
     320,   316,   318,   316,   318,   316,   318,   316,   318,   316,
     318,   316,   318,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   318,   318,   318,   318,   318,   318,
     320,   318,   320,   318,   320,   318,   320,   318,   320,   316,
     316,   316,   318,   318,   320,   316,   316,   320,   316,   317,
     320,   316,   318,   320,   316,   319,   320,   316,   320,   316,
     320,   316,   317,   318,   319,   320,   316,   317,   318,   319,
     320,   316,   316,   318,   318,   316,   318,   316,   318,   316,
     318,   316,   318,   316,   318,   316,   318,   316,   318,   316,
     318,   316,   318,   316,   318,   318,   318,   318,   318,   316,
     316,   316,   316,   317,   318,   319,   320,   316,   316,   318,
     316,   316,   318,   318,   318,   316,   316,   316,   316,   316,
     316,   316,   318,   317,   318,   319,   320,   318,   317,   318,
     319,   320,   316,   316,   318,   318,   320,   320,   320,   316,
     320,   316,   320,   316,   316,   316,   316,   316,   317,   318,
     319,   320,   316,   317,   318,   319,   320,   316,   316,   316,
     316,   316,   320,   318,   318,   316,   320,   318,   320,   320,
     320,   318,   318,   318,   318,   318,   320,   318,   318,   316,
     320,   320,   320,   318,   320,   320,   316,   320,   320,   320,
     320,   316,   316,   320,   318,   320,   316,   318,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   317,
     318,   319,   320,   316,   316,   316,   316,   318,   318,   316,
     316,   316,   316,   316,   320,   316,   320,   316,   316,   316,
     318,   316,   317,   318,   319,   320,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   318,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   320,   316,   318,   316,   318,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     318,   320,   316,   318,   318,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   320,   320,   320,   320,   320,   316,
     320,   320,   320,   316,   316,   320,   316,   316,   316,   316,
     316,   316,   316,   316,   320,   320,   316,   320,   320,   320,
     316,   316,   320,   316,   316,   316,   316,   316,   316,   316,
     316,   318,   318,   318,   317,   318,   319,   320,   318,   317,
     318,   319,   320,   318,   317,   318,   319,   320,   318,   317,
     318,   319,   320,   316,   316,   316,   318,   318,   316,   318,
     318,   316,   316,   316,   318,   318,   318,   318,   316,   318,
     318,   323,   323
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   324,   325,   325,   326,   326,   326,   326,   326,   326,
     326,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   328,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     331,   331,   331
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
       3,     3,     3,     3,     3,     3,     4,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     4,     2,     4,     3,     2,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 1161 "pnfasm.ypp" /* yacc.c:1646  */
    { yyerrok; }
#line 3223 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 1164 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "0 0 0\n"); }
#line 3229 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 1165 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "0 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3235 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 1166 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "1 0 0\n"); }
#line 3241 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 1168 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "2 4 ");

		 for (int i = 1; (yyvsp[0])[i] != '\"'; ++i)
                  fprintf(output, "%i ", (yyvsp[0])[i]);
		 fprintf(output, "0\n");
		}
#line 3253 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 1175 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "3 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3259 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 1176 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "3 2 0\n"); }
#line 3265 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 1177 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "4 0 0\n"); }
#line 3271 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 1178 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "5 0 0\n"); }
#line 3277 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 1179 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "5 1 1\n");
						 else
						  fprintf(output, "5 1 0\n");
					        }
#line 3288 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 1185 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "5 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3294 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 1186 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "5 3 %i\n", ch);
						}
#line 3304 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 1191 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "5 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 3318 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 1200 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "6 0 0\n"); }
#line 3324 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 1201 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "6 1 1\n");
						 else
						  fprintf(output, "6 1 0\n");
					        }
#line 3335 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 1207 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "6 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3341 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 1208 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "6 3 %i\n", ch);
						}
#line 3351 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 1213 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "6 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 3365 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 1222 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "7 1 0\n"); }
#line 3371 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 1223 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "7 2 0\n"); }
#line 3377 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 1224 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "7 3 0\n"); }
#line 3383 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 1225 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "7 4 0\n"); }
#line 3389 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 1226 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "8 1 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3395 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 1227 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "8 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3401 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 1228 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "8 3 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3407 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 1229 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "8 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3413 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 1230 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "9 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3419 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 1231 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "10 1 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3425 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 1232 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "10 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3431 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 1233 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "10 3 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3437 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 1234 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "10 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3443 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 1235 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "11 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3449 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 1236 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "12 1 0\n"); }
#line 3455 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 1237 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "12 2 0\n"); }
#line 3461 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 1238 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "12 3 0\n"); }
#line 3467 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 1239 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "12 4 0\n"); }
#line 3473 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 1240 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "13 0 0\n"); }
#line 3479 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 1241 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "14 1 0\n"); }
#line 3485 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 1242 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "14 2 0\n"); }
#line 3491 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 1243 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "14 3 0\n"); }
#line 3497 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 1244 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "14 4 0\n"); }
#line 3503 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 1245 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "15 0 0\n"); }
#line 3509 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 1246 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "16 1 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3515 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 1247 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "16 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3521 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 1248 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "16 3 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3527 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 1249 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "16 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3533 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 1250 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "17 0 0\n"); }
#line 3539 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 1251 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "17 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3545 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 1252 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "18 1 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3551 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1253 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "18 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3557 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 1254 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "18 3 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3563 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1255 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "18 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3569 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1256 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "19 0 0\n"); }
#line 3575 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1257 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "19 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3581 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1258 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "20 0 0\n"); }
#line 3587 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1259 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 0 0\n"); }
#line 3593 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1260 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 1 0\n"); }
#line 3599 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1261 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 2 0\n"); }
#line 3605 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1262 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 3 0\n"); }
#line 3611 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1263 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "21 4 0\n"); }
#line 3617 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1264 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 0 0\n"); }
#line 3623 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1265 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 1 0\n"); }
#line 3629 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1266 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 2 0\n"); }
#line 3635 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1267 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 3 0\n"); }
#line 3641 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1268 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "22 4 0\n"); }
#line 3647 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1269 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "23 0 0\n"); }
#line 3653 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1270 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "23 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3659 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1271 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "23 3 %i\n", ch);
						}
#line 3669 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1276 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "23 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3680 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1282 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "24 0 0\n"); }
#line 3686 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1283 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "24 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3692 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1284 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "25 0 0\n"); }
#line 3698 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1285 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "25 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3704 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1286 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "26 0 0\n"); }
#line 3710 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1287 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "26 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3716 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1288 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "27 0 0\n"); }
#line 3722 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1289 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "27 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3728 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1290 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "28 0 0\n"); }
#line 3734 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1291 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "28 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3740 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1292 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "29 0 0\n"); }
#line 3746 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1293 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "29 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3752 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1294 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "30 0 0\n"); }
#line 3758 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1295 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "31 0 0\n"); }
#line 3764 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1296 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "32 0 0\n"); }
#line 3770 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1297 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "33 0 0\n"); }
#line 3776 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1298 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "34 0 0\n"); }
#line 3782 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1299 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "35 0 0\n"); }
#line 3788 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1300 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "36 0 0\n"); }
#line 3794 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1301 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "37 0 0\n"); }
#line 3800 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1302 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "38 0 0\n"); }
#line 3806 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1303 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "39 0 0\n"); }
#line 3812 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1304 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "40 0 0\n"); }
#line 3818 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1305 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "41 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3824 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1306 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "42 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3830 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1307 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "43 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3836 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1308 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "44 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3842 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1309 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "45 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3848 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1310 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "46 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3854 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1311 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "46 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3865 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1317 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "47 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3871 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1319 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "47 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3882 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1325 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "48 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3888 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1327 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "48 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3899 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1333 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "49 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3905 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1335 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "49 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3916 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1341 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "50 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3922 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1343 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "50 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3933 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1349 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "51 0 0\n"); }
#line 3939 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1350 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "52 0 0\n"); }
#line 3945 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1351 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "53 0 0\n"); }
#line 3951 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1352 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "54 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3957 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1353 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "55 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 3963 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1355 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "55 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 3974 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1361 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "56 0 0\n"); }
#line 3980 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1363 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "58 0 0\n"); }
#line 3986 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1364 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 fprintf(output, "58 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");		
						}
#line 3997 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1370 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "59 0 0\n"); }
#line 4003 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1371 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "59 1 1\n");
						 else
						  fprintf(output, "59 1 0\n");
					        }
#line 4014 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1377 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "59 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4020 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1378 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "59 3 %i\n", ch);
						}
#line 4030 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1383 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "59 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4044 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1393 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "60 0 0\n"); }
#line 4050 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1394 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "60 1 1\n");
						 else
						  fprintf(output, "60 1 0\n");
					        }
#line 4061 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1400 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "60 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4067 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1401 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "60 3 %i\n", ch);
						}
#line 4077 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1406 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "60 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4091 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1416 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "61 0 0"); }
#line 4097 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1417 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "62 0 0\n"); }
#line 4103 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1418 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "63 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4109 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1419 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "64 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4115 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1420 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "65 0 0\n"); }
#line 4121 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1421 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "66 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4127 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1422 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "67 0 0\n"); }
#line 4133 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1423 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "68 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4139 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1424 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "69 0 0\n"); }
#line 4145 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1425 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "70 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4151 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1426 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "71 0 0\n"); }
#line 4157 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1427 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "72 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4163 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1428 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "73 0 0\n"); }
#line 4169 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1429 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "74 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4175 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1430 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "75 0 0\n"); }
#line 4181 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1431 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "76 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4187 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1432 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "77 0 0\n"); }
#line 4193 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1433 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "78 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4199 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1434 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "79 0 0\n"); }
#line 4205 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1435 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "80 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4211 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1436 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "81 0 0\n"); }
#line 4217 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1437 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "82 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4223 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1438 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "83 0 0\n"); }
#line 4229 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1439 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "84 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4235 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1440 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "85 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4241 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1441 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "86 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4247 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1442 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "87 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4253 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1443 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "88 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4259 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1444 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "89 0 0\n"); }
#line 4265 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1445 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "90 0 0\n"); }
#line 4271 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1446 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "91 0 0\n"); }
#line 4277 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1447 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "92 0 0\n"); }
#line 4283 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1449 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "92 1 1\n");
		 else
		  fprintf(output, "92 1 0\n");
		}
#line 4294 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1455 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "92 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4300 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1457 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "92 3 %i\n", ch);
		}
#line 4310 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1463 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "92 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4324 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1472 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "93 0 0\n"); }
#line 4330 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1473 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "94 0 0\n"); }
#line 4336 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1474 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "95 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4342 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1475 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "96 0 0\n"); }
#line 4348 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1476 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "97 0 0\n"); }
#line 4354 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1477 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "98 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4360 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1478 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "99 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4366 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1479 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "100 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4372 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1480 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "101 0 0\n"); }
#line 4378 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1481 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "102 0 0\n"); }
#line 4384 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1482 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "103 0 0\n"); }
#line 4390 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1483 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "104 0 0\n"); }
#line 4396 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1484 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "105 0 0\n"); }
#line 4402 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1485 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "106 0 0\n"); }
#line 4408 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1486 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "107 0 0\n"); }
#line 4414 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1487 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "108 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4420 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1489 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "108 1 1\n");
		 else
		  fprintf(output, "108 1 0\n");
		}
#line 4431 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1495 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "108 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4437 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1497 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "108 3 %i\n", ch);
		}
#line 4447 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1503 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "108 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4461 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1512 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "109 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4467 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1514 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "109 1 1\n");
		 else
		  fprintf(output, "109 1 0\n");
		}
#line 4478 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1520 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "109 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4484 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1522 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "109 3 %i\n", ch);
		}
#line 4494 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1528 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "109 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4508 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1537 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "110 0 0\n"); }
#line 4514 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1538 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "111 0 0\n"); }
#line 4520 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1539 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "112 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4526 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1540 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "113 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4532 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1542 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "114 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4546 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1552 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "115 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4560 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1562 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "116 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4574 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1571 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "117 0 0\n"); }
#line 4580 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1573 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "117 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4594 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1582 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "118 0 0\n"); }
#line 4600 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1584 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "118 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4614 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1593 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "119 1 0\n"); }
#line 4620 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1594 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "119 2 0\n"); }
#line 4626 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1595 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "119 3 0\n"); }
#line 4632 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1596 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "119 4 0\n"); }
#line 4638 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1597 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "120 0 0\n"); }
#line 4644 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1598 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "120 1 1\n");
						 else
						  fprintf(output, "120 1 0\n");
					        }
#line 4655 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1604 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "120 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4661 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1605 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "120 3 %i\n", ch);
						}
#line 4671 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1610 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "120 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4685 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1619 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "121 0 0\n"); }
#line 4691 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1620 "pnfasm.ypp" /* yacc.c:1646  */
    {
						 if ((yyvsp[0]) == "true")
						  fprintf(output, "121 1 1\n");
						 else
						  fprintf(output, "121 1 0\n");
					        }
#line 4702 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1626 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "121 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4708 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1627 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "121 3 %i\n", ch);
						}
#line 4718 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1632 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "121 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4732 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1641 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "122 0 0\n"); }
#line 4738 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1642 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "123 0 0\n"); }
#line 4744 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1643 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "124 0 0\n"); }
#line 4750 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1644 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "125 0 0\n"); }
#line 4756 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1645 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "126 0 0\n"); }
#line 4762 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1646 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "127 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4776 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1655 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "128 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4782 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1656 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "129 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4788 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1657 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "130 0 0\n"); }
#line 4794 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1658 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "131 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4808 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1667 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "132 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4814 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1668 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "133 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4828 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1677 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "134 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4842 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1686 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "135 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4856 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1695 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "136 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4862 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1696 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "137 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4868 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1697 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "138 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4874 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1698 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "139 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4880 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1699 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "140 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4886 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1700 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "141 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4900 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1709 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "142 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4906 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1710 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "143 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4912 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1711 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "144 0 0\n"); }
#line 4918 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1712 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "145 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4932 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1721 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "146 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4946 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1730 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "147 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4960 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1739 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "148 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 4966 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1740 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "149 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4980 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1749 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "150 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4994 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1758 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "151 0 0\n"); }
#line 5000 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1759 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "152 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5014 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1768 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "153 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5028 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1777 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "154 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5042 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1786 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "155 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5056 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1795 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "156 0 0\n"); }
#line 5062 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1796 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "157 0 0\n"); }
#line 5068 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1797 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "158 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5082 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1806 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "159 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5088 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1807 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "160 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5102 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1816 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "161 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5108 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1817 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "161 0 0\n"); }
#line 5114 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1818 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "162 0 0\n"); }
#line 5120 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1819 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 0 0\n"); }
#line 5126 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1820 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 1 0\n"); }
#line 5132 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1821 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 2 0\n"); }
#line 5138 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1822 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 3 0\n"); }
#line 5144 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1823 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "163 4 0\n"); }
#line 5150 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1824 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "164 0 0\n"); }
#line 5156 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1825 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "165 0 0\n"); }
#line 5162 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1826 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "166 0 0\n"); }
#line 5168 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1827 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "167 0 0\n"); }
#line 5174 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1828 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "168 0 0\n"); }
#line 5180 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 1829 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "169 0 0\n"); }
#line 5186 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 1830 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "170 0 0\n"); }
#line 5192 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 1831 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "171 0 0\n"); }
#line 5198 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1832 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "172 0 0\n"); }
#line 5204 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1833 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "173 0 0\n"); }
#line 5210 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1834 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "174 0 0\n"); }
#line 5216 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 1835 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "175 0 0\n");	}
#line 5222 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 1836 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "176 0 0\n");	}
#line 5228 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 1837 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "177 0 0\n");	}
#line 5234 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1838 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "178 0 0\n"); }
#line 5240 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 1839 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "178 1 %s\n", (yyvsp[0]).getString().c_str());	}
#line 5246 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1840 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "178 2 %s\n", (yyvsp[0]).getString().c_str());	}
#line 5252 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1841 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "178 3 %i\n", ch);
						}
#line 5262 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1846 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "178 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5276 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1855 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "179 0 0\n");	}
#line 5282 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1856 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "180 0 0\n");	}
#line 5288 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1857 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "181 0 0\n");	}
#line 5294 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1858 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "182 0 0\n");	}
#line 5300 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1859 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "183 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5306 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1860 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "184 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5312 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1861 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "185 0 0\n"); }
#line 5318 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1862 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "186 0 0\n"); }
#line 5324 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1863 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "187 0 0\n"); }
#line 5330 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1864 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "188 0 0\n"); }
#line 5336 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1865 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "189 0 0\n"); }
#line 5342 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 1866 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "190 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5356 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 1875 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "191 0 0\n"); }
#line 5362 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 1876 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "192 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5376 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 1885 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "193 0 0\n"); }
#line 5382 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 1886 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "194 0 0\n"); }
#line 5388 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 1887 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "195 0 0\n"); }
#line 5394 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 1888 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "196 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5400 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 1889 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "197 0 0\n"); }
#line 5406 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 1891 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 if ((yyvsp[0]) == "true")
		 	  			  fprintf(output, "197 1 1\n");
			 			 else
			  			  fprintf(output, "197 1 0\n");
						}
#line 5417 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 1897 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "197 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5423 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 1899 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "197 3 %i\n", ch);
						}
#line 5433 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 1905 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "197 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5444 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 1911 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "198 0 0\n"); }
#line 5450 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 1912 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "198 1 0\n"); }
#line 5456 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 1913 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "198 2 0\n"); }
#line 5462 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 1914 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "198 3 0\n"); }
#line 5468 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 1915 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "198 4 0\n"); }
#line 5474 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 1916 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 0 0\n"); }
#line 5480 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 1917 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 1 0\n"); }
#line 5486 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 1918 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 2 0\n"); }
#line 5492 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 1919 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 3 0\n"); }
#line 5498 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 1920 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "199 4 0\n"); }
#line 5504 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 1921 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "200 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5510 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 1922 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 0 0\n"); }
#line 5516 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 1923 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 1 0\n"); }
#line 5522 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 1924 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 2 0\n"); }
#line 5528 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 1925 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 3 0\n"); }
#line 5534 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 1926 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "201 4 0\n"); }
#line 5540 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 1927 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 0 0\n"); }
#line 5546 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 1928 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 1 0\n"); }
#line 5552 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 1929 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 2 0\n"); }
#line 5558 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 1930 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 3 0\n"); }
#line 5564 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 1931 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "202 4 0\n"); }
#line 5570 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 1932 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 0 0\n"); }
#line 5576 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 1933 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 1 0\n"); }
#line 5582 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 1934 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 2 0\n"); }
#line 5588 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 1935 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 3 0\n"); }
#line 5594 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 1936 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "203 4 0\n"); }
#line 5600 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 1939 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "204 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5611 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 1945 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "205 0 0\n"); }
#line 5617 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 1946 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "206 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5623 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 1947 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "207 0 0\n"); }
#line 5629 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 1948 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "207 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5635 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 1949 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "208 0 0\n"); }
#line 5641 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 1950 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "209 0 0\n"); }
#line 5647 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 1951 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "210 0 0\n"); }
#line 5653 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 1952 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 0 0\n"); }
#line 5659 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 1953 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 1 0\n"); }
#line 5665 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 1954 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 2 0\n"); }
#line 5671 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 1955 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 3 0\n"); }
#line 5677 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 1956 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "211 4 0\n"); }
#line 5683 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 1957 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 0 0\n"); }
#line 5689 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 1958 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 1 0\n"); }
#line 5695 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 1959 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 2 0\n"); }
#line 5701 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 1960 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 3 0\n"); }
#line 5707 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 1961 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "212 4 0\n"); }
#line 5713 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 1962 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "213 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5719 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 1963 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "213 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 5730 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 1969 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "214 0 0\n"); }
#line 5736 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 1970 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "215 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5742 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 1971 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "216 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 5748 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 1972 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "217 0 0\n"); }
#line 5754 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 1973 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "218 0 0\n"); }
#line 5760 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 1974 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "219 0 0\n"); }
#line 5766 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 1975 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "220 0 0\n"); }
#line 5772 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 1976 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "221 0 0\n"); }
#line 5778 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 1977 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "222 0 0\n"); }
#line 5784 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 1978 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "222 1 0\n"); }
#line 5790 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 1979 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "222 2 0\n"); }
#line 5796 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 1980 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "222 3 0\n"); }
#line 5802 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 1981 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "222 4 0\n"); }
#line 5808 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 1982 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "223 0 0\n"); }
#line 5814 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 1983 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "223 1 0\n"); }
#line 5820 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 1984 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "223 2 0\n"); }
#line 5826 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 1985 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "223 3 0\n"); }
#line 5832 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 1986 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "223 4 0\n"); }
#line 5838 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 1987 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "224 0 0\n"); }
#line 5844 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 1988 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "225 0 0\n"); }
#line 5850 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 1989 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "226 0 0\n"); }
#line 5856 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 1990 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "227 0 0\n"); }
#line 5862 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 1991 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "228 0 0\n"); }
#line 5868 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 1992 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "228 1 0\n"); }
#line 5874 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 1993 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "228 2 0\n"); }
#line 5880 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 1994 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "228 3 0\n"); }
#line 5886 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 1995 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "228 4 0\n"); }
#line 5892 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 1996 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "229 0 0\n"); }
#line 5898 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 1997 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "230 0 0\n"); }
#line 5904 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 1998 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "231 0 0\n"); }
#line 5910 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 1999 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "232 0 0\n"); }
#line 5916 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2000 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "233 0 0\n"); }
#line 5922 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2001 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "234 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5936 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2010 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "235 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5950 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2019 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "236 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5964 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2028 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "237 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5978 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2037 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "238 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5992 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2046 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "239 0 0\n"); }
#line 5998 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2047 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "240 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6012 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2056 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "241 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6026 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2065 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "242 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6040 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2074 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "243 0 0\n");
						}
#line 6048 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2077 "pnfasm.ypp" /* yacc.c:1646  */
    {	
						fprintf(output, "243 2 0\n");
						}
#line 6056 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2080 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "243 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6070 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2089 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "244 0 0\n");
						}
#line 6078 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 2092 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "245 0 0\n");
						}
#line 6086 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2095 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "246 0 0\n");
						}
#line 6094 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2098 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "247 0 0\n");
						}
#line 6102 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2102 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "248 0 0\n");
						}
#line 6110 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2105 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "249 0 0\n");
						}
#line 6118 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2108 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "250 0 0\n");
						}
#line 6126 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2111 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "251 0 0\n");
						}
#line 6134 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2115 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "252 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6148 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2124 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "253 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6162 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2133 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "254 0 0\n"); }
#line 6168 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2134 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "255 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6182 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2143 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "256 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6196 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2152 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "257 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6210 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2161 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "258 0 0\n");
						}
#line 6218 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2164 "pnfasm.ypp" /* yacc.c:1646  */
    {	
						fprintf(output, "258 2 0\n");
						}
#line 6226 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2167 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "258 4 ");
						 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
						 {
						  if ((yyvsp[0])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6240 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2176 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "259 0 0\n");
						}
#line 6248 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2179 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "260 0 0\n");
						}
#line 6256 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2182 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "261 0 0\n");
						}
#line 6264 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2185 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "262 0 0\n");
						}
#line 6272 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2189 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "263 0 0\n");
						}
#line 6280 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2192 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "264 0 0\n");
						}
#line 6288 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2195 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "265 0 0\n");
						}
#line 6296 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2198 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "266 0 0\n");
						}
#line 6304 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2202 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "267 0 0\n");
						}
#line 6312 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2206 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "268 0 0\n");
						}
#line 6320 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2210 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "269 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6326 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2212 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "269 1 1\n");
		 else
		  fprintf(output, "269 1 0\n");
		}
#line 6337 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2218 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "269 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6343 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2220 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "269 3 %i\n", ch);
		}
#line 6353 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2226 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "269 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 6367 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2235 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "270 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6373 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2237 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "270 1 1\n");
		 else
		  fprintf(output, "270 1 0\n");
		}
#line 6384 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 2243 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "270 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6390 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2245 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "270 3 %i\n", ch);
		}
#line 6400 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2251 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "270 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 6414 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 2260 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "271 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6420 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 2262 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "271 1 1\n");
		 else
		  fprintf(output, "271 1 0\n");
		}
#line 6431 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2268 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "271 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6437 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 2270 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "271 3 %i\n", ch);
		}
#line 6447 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 2276 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "271 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 6461 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 2285 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "272 0 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6467 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 2287 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 if ((yyvsp[0]) == "true")
		  fprintf(output, "272 1 1\n");
		 else
		  fprintf(output, "272 1 0\n");
		}
#line 6478 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 2293 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "272 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6484 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 2295 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 char * dup = strdup((yyvsp[0]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "272 3 %i\n", ch);
		}
#line 6494 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 2301 "pnfasm.ypp" /* yacc.c:1646  */
    {
		 fprintf(output, "272 4 ");
		 for (unsigned long i = 0; i < (yyvsp[0]).length(); ++i)
                 {
		  if ((yyvsp[0])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[0])[i]));
		 }
		 fprintf(output, "0\n");
		}
#line 6508 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 2311 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "273 0 0\n");
						}
#line 6516 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 2315 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "274 0 0\n");
						}
#line 6524 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 2319 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "275 0 0\n");
						}
#line 6532 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 2323 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "276 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6538 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 2325 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "277 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6544 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 2327 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "278 0 0\n");
						}
#line 6552 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 2331 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "279 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6558 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 2333 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "280 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6564 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 2335 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "281 0 0\n");
						}
#line 6572 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 2339 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "282 0 0\n");
						}
#line 6580 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 2343 "pnfasm.ypp" /* yacc.c:1646  */
    { 
						 fprintf(output, "283 0 0\n");
						}
#line 6588 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 2346 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "284 1 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6594 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 2347 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "284 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6600 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 2348 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "284 3 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6606 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 2349 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "284 4 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6612 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 2350 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "285 0 0\n"); }
#line 6618 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 2351 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "285 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6624 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 2353 "pnfasm.ypp" /* yacc.c:1646  */
    { /* Do nothing... */ }
#line 6630 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 2354 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "%s %s %s\n", (yyvsp[-2]).getString().c_str(), (yyvsp[-1]).getString().c_str(), (yyvsp[0]).getString().c_str()); }
#line 6636 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 2364 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 0 0\n"); }
#line 6642 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 2366 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 if ((yyvsp[0]) == "true")
		 	  			  fprintf(output, "57 1 1\n");
			 			 else
			  			  fprintf(output, "57 1 0\n");
						}
#line 6653 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 2372 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 2 %s\n", (yyvsp[0]).getString().c_str()); }
#line 6659 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 2374 "pnfasm.ypp" /* yacc.c:1646  */
    {
			 			 char * dup = strdup((yyvsp[0]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "57 3 %i\n", ch);
						}
#line 6669 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 2380 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6680 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 2386 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 1 0\n"); }
#line 6686 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 2387 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 2 0\n"); }
#line 6692 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 2388 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 3 0\n"); }
#line 6698 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 2389 "pnfasm.ypp" /* yacc.c:1646  */
    { fprintf(output, "57 4 0\n"); }
#line 6704 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 2391 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 0 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6715 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 2398 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 1 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6726 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 2405 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 2 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6737 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 2412 "pnfasm.ypp" /* yacc.c:1646  */
    {		
						 fprintf(output, "57 3 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[0])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[0])[i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6748 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 2421 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#include %s\n", (yyvsp[0]).getString().c_str()); }
#line 6754 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 2422 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#include <%s>\n", (yyvsp[-2]).getString().c_str()); }
#line 6760 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 2423 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#import %s \n", (yyvsp[0]).getString().c_str()); }
#line 6766 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 2424 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#import <%s> \n", (yyvsp[-2]).getString().c_str()); }
#line 6772 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 2425 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#define %s %s\n", (yyvsp[-1]).getString().c_str(), (yyvsp[0]).getString().c_str()); }
#line 6778 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 2426 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#macro %s\n", (yyvsp[0]).getString().c_str()); }
#line 6784 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 2427 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#endm\n"); }
#line 6790 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 2428 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#undef %s\n", (yyvsp[0]).getString().c_str()); }
#line 6796 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 2429 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#ifdef %s\n", (yyvsp[0]).getString().c_str()); }
#line 6802 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 2430 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#ifndef %s\n", (yyvsp[0]).getString().c_str()); }
#line 6808 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 2431 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#else\n"); }
#line 6814 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 2432 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "#endif\n"); }
#line 6820 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 2433 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_DATE()\n"); }
#line 6826 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 2434 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_TIME()\n"); }
#line 6832 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 2435 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_LINE()\n"); }
#line 6838 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 2436 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_FILE()\n"); }
#line 6844 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 2437 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_CDATE()\n"); }
#line 6850 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 2438 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "_CTIME()\n"); }
#line 6856 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 2439 "pnfasm.ypp" /* yacc.c:1646  */
    { if (mode == 1 || mode == 2) fprintf(output, "\' %s\n", (yyvsp[0]).getString().c_str()); }
#line 6862 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 2442 "pnfasm.ypp" /* yacc.c:1646  */
    { mode = 0; }
#line 6868 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 2443 "pnfasm.ypp" /* yacc.c:1646  */
    { mode = 1; }
#line 6874 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 2444 "pnfasm.ypp" /* yacc.c:1646  */
    { mode = 2; }
#line 6880 "pnfasm.tab.cpp" /* yacc.c:1646  */
    break;


#line 6884 "pnfasm.tab.cpp" /* yacc.c:1646  */
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
#line 2447 "pnfasm.ypp" /* yacc.c:1906  */

/* Additional C/C++ Code */
void yyerror(char const * c)
{
 cout << "* ERROR: " << yylineno << ": " << c << endl;
}
