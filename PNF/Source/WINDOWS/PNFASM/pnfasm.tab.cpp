
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
#line 1 "pnfasm.ypp"

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
			 9. Debugged...
			10. Added FNCFRET and FNCFPARAM.
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
#include <deslib/deslib.hpp>

#include <cstring>


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


/* Line 189 of yacc.c  */
#line 884 "pnfasm.tab.cpp"

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
     TVOID = 506,
     TBOOLEAN = 507,
     TNUMBER = 508,
     TCHARACTER = 509,
     TSTRING = 510,
     VOID = 511,
     BOOLEAN = 512,
     NUMBER = 513,
     CHARACTER = 514,
     STRING = 515
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
#line 1186 "pnfasm.tab.cpp"

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
#define YYLAST   1062

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  264
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  413
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1025

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   517

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     261,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     255,   256,   257,   258,   259,   260,   262,   263
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    25,    29,    33,    37,    41,    45,    49,    53,
      57,    61,    65,    69,    73,    77,    81,    85,    89,    93,
      97,   101,   105,   109,   113,   117,   121,   125,   129,   133,
     137,   141,   145,   149,   153,   157,   161,   165,   169,   173,
     177,   181,   185,   189,   193,   197,   201,   205,   209,   213,
     217,   221,   225,   229,   233,   237,   241,   245,   249,   253,
     257,   261,   265,   269,   273,   277,   281,   285,   289,   293,
     297,   301,   305,   309,   313,   317,   321,   325,   329,   333,
     337,   341,   345,   349,   353,   357,   361,   365,   369,   373,
     377,   381,   385,   389,   393,   397,   401,   405,   409,   413,
     417,   421,   425,   429,   433,   437,   441,   445,   449,   453,
     457,   461,   465,   469,   473,   477,   481,   485,   489,   493,
     497,   501,   505,   509,   513,   517,   521,   525,   529,   533,
     537,   541,   545,   549,   553,   557,   561,   565,   569,   573,
     577,   581,   585,   589,   593,   597,   601,   605,   609,   613,
     617,   621,   625,   629,   633,   637,   641,   645,   649,   653,
     657,   661,   665,   669,   673,   677,   681,   685,   689,   693,
     697,   701,   705,   709,   713,   717,   721,   725,   729,   733,
     737,   741,   745,   749,   753,   757,   761,   765,   769,   773,
     777,   781,   785,   789,   793,   797,   801,   805,   809,   813,
     817,   821,   825,   829,   833,   837,   841,   845,   849,   853,
     857,   861,   865,   869,   873,   877,   881,   885,   889,   893,
     897,   901,   905,   909,   913,   917,   921,   925,   929,   933,
     937,   941,   945,   949,   953,   957,   961,   965,   969,   973,
     977,   981,   985,   989,   993,   997,  1001,  1005,  1009,  1013,
    1017,  1021,  1025,  1029,  1033,  1037,  1041,  1045,  1049,  1053,
    1057,  1061,  1065,  1069,  1073,  1077,  1081,  1085,  1089,  1093,
    1097,  1101,  1105,  1109,  1113,  1117,  1121,  1125,  1129,  1133,
    1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1169,  1173,
    1177,  1181,  1185,  1189,  1193,  1197,  1201,  1205,  1209,  1213,
    1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,  1249,  1253,
    1257,  1261,  1265,  1269,  1273,  1277,  1281,  1285,  1289,  1293,
    1297,  1301,  1305,  1309,  1313,  1317,  1321,  1325,  1329,  1333,
    1337,  1341,  1345,  1349,  1353,  1357,  1361,  1365,  1369,  1373,
    1377,  1381,  1385,  1389,  1393,  1397,  1401,  1405,  1409,  1413,
    1417,  1421,  1425,  1429,  1433,  1437,  1441,  1445,  1449,  1453,
    1457,  1461,  1465,  1469,  1473,  1477,  1481,  1485,  1490,  1491,
    1495,  1499,  1503,  1507,  1511,  1515,  1519,  1523,  1527,  1531,
    1535,  1539,  1543,  1546,  1551,  1554,  1559,  1563,  1566,  1568,
    1571,  1574,  1577,  1579,  1581,  1583,  1585,  1587,  1589,  1591,
    1593,  1595,  1597,  1599
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     265,     0,    -1,    -1,   265,   266,    -1,   261,    -1,   267,
      -1,   268,    -1,   269,    -1,   270,    -1,   271,    -1,     1,
      -1,    25,   251,   256,    -1,    25,   251,   258,    -1,    26,
     251,   256,    -1,    27,   255,   260,    -1,    28,   251,   258,
      -1,    29,   251,   256,    -1,    30,   251,   256,    -1,    30,
     252,   257,    -1,    30,   253,   258,    -1,    30,   254,   259,
      -1,    30,   255,   260,    -1,    31,   251,   256,    -1,    31,
     252,   257,    -1,    31,   253,   258,    -1,    31,   254,   259,
      -1,    31,   255,   260,    -1,    32,   252,   256,    -1,    32,
     253,   256,    -1,    32,   254,   256,    -1,    32,   255,   256,
      -1,    33,   252,   258,    -1,    33,   253,   258,    -1,    33,
     254,   258,    -1,    33,   255,   258,    -1,    34,   251,   258,
      -1,    35,   252,   258,    -1,    35,   253,   258,    -1,    35,
     254,   258,    -1,    35,   255,   258,    -1,    36,   251,   258,
      -1,    37,   252,   256,    -1,    37,   253,   256,    -1,    37,
     254,   256,    -1,    37,   255,   256,    -1,    38,   251,   256,
      -1,    39,   252,   256,    -1,    39,   253,   256,    -1,    39,
     254,   256,    -1,    39,   255,   256,    -1,    40,   251,   256,
      -1,    41,   252,   258,    -1,    41,   253,   258,    -1,    41,
     254,   258,    -1,    41,   255,   258,    -1,    42,   251,   256,
      -1,    42,   253,   258,    -1,    43,   252,   258,    -1,    43,
     253,   258,    -1,    43,   254,   258,    -1,    43,   255,   258,
      -1,    44,   251,   256,    -1,    44,   253,   258,    -1,    45,
     251,   256,    -1,    46,   251,   256,    -1,    46,   252,   256,
      -1,    46,   253,   256,    -1,    46,   254,   256,    -1,    46,
     255,   256,    -1,    47,   251,   256,    -1,    47,   252,   256,
      -1,    47,   253,   256,    -1,    47,   254,   256,    -1,    47,
     255,   256,    -1,    48,   251,   256,    -1,    48,   253,   258,
      -1,    48,   254,   259,    -1,    48,   255,   260,    -1,    49,
     251,   256,    -1,    49,   253,   258,    -1,    50,   251,   256,
      -1,    50,   253,   258,    -1,    51,   251,   256,    -1,    51,
     253,   258,    -1,    52,   251,   256,    -1,    52,   253,   258,
      -1,    53,   251,   256,    -1,    53,   253,   258,    -1,    54,
     251,   256,    -1,    54,   253,   258,    -1,    55,   251,   256,
      -1,    56,   251,   256,    -1,    57,   251,   256,    -1,    58,
     251,   256,    -1,    59,   251,   256,    -1,    60,   251,   256,
      -1,    61,   251,   256,    -1,    62,   251,   256,    -1,    63,
     251,   256,    -1,    64,   251,   256,    -1,    65,   251,   256,
      -1,    66,   251,   258,    -1,    67,   251,   258,    -1,    68,
     251,   258,    -1,    69,   251,   258,    -1,    70,   251,   258,
      -1,    71,   251,   258,    -1,    71,   255,   260,    -1,    72,
     251,   258,    -1,    72,   255,   260,    -1,    73,   251,   258,
      -1,    73,   255,   260,    -1,    74,   251,   258,    -1,    74,
     255,   260,    -1,    75,   251,   258,    -1,    75,   255,   260,
      -1,    76,   251,   256,    -1,    77,   251,   256,    -1,    78,
     251,   256,    -1,    79,   251,   258,    -1,    80,   251,   258,
      -1,    80,   255,   260,    -1,    81,   251,   256,    -1,    83,
     251,   256,    -1,    83,   255,   260,    -1,    84,   251,   256,
      -1,    84,   252,   257,    -1,    84,   253,   258,    -1,    84,
     254,   259,    -1,    84,   255,   260,    -1,    85,   251,   256,
      -1,    85,   252,   257,    -1,    85,   253,   258,    -1,    85,
     254,   259,    -1,    85,   255,   260,    -1,    86,   251,   256,
      -1,    87,   251,   256,    -1,    88,   251,   258,    -1,    89,
     251,   258,    -1,    90,   251,   256,    -1,    91,   251,   258,
      -1,    92,   251,   256,    -1,    93,   251,   258,    -1,    94,
     251,   256,    -1,    95,   251,   258,    -1,    96,   251,   256,
      -1,    97,   251,   258,    -1,    98,   251,   256,    -1,    99,
     251,   258,    -1,   100,   251,   256,    -1,   101,   251,   258,
      -1,   102,   251,   256,    -1,   103,   251,   258,    -1,   104,
     251,   256,    -1,   105,   251,   258,    -1,   106,   251,   256,
      -1,   107,   251,   258,    -1,   108,   251,   256,    -1,   109,
     251,   258,    -1,   110,   251,   258,    -1,   111,   251,   258,
      -1,   112,   251,   258,    -1,   113,   251,   258,    -1,   114,
     251,   256,    -1,   115,   251,   256,    -1,   116,   251,   256,
      -1,   117,   251,   256,    -1,   117,   252,   257,    -1,   117,
     253,   258,    -1,   117,   254,   259,    -1,   117,   255,   260,
      -1,   118,   251,   256,    -1,   119,   251,   256,    -1,   120,
     251,   258,    -1,   121,   251,   256,    -1,   122,   251,   256,
      -1,   123,   251,   258,    -1,   124,   251,   258,    -1,   125,
     251,   258,    -1,   126,   251,   256,    -1,   127,   251,   256,
      -1,   128,   251,   256,    -1,   129,   251,   256,    -1,   130,
     251,   256,    -1,   131,   251,   256,    -1,   132,   251,   256,
      -1,   133,   251,   258,    -1,   133,   252,   257,    -1,   133,
     253,   258,    -1,   133,   254,   259,    -1,   133,   255,   260,
      -1,   134,   251,   258,    -1,   134,   252,   257,    -1,   134,
     253,   258,    -1,   134,   254,   259,    -1,   134,   255,   260,
      -1,   135,   251,   256,    -1,   136,   251,   256,    -1,   137,
     253,   258,    -1,   138,   253,   258,    -1,   139,   255,   260,
      -1,   140,   255,   260,    -1,   141,   255,   260,    -1,   142,
     251,   256,    -1,   142,   255,   260,    -1,   143,   251,   256,
      -1,   143,   255,   260,    -1,   144,   252,   256,    -1,   144,
     253,   256,    -1,   144,   254,   256,    -1,   144,   255,   256,
      -1,   145,   251,   256,    -1,   145,   252,   257,    -1,   145,
     253,   258,    -1,   145,   254,   259,    -1,   145,   255,   260,
      -1,   146,   251,   256,    -1,   146,   252,   257,    -1,   146,
     253,   258,    -1,   146,   254,   259,    -1,   146,   255,   260,
      -1,   147,   251,   256,    -1,   148,   251,   256,    -1,   149,
     251,   256,    -1,   150,   251,   256,    -1,   151,   251,   256,
      -1,   152,   255,   260,    -1,   153,   253,   258,    -1,   154,
     253,   258,    -1,   155,   251,   256,    -1,   156,   255,   260,
      -1,   157,   253,   258,    -1,   158,   255,   260,    -1,   159,
     255,   260,    -1,   160,   255,   260,    -1,   161,   251,   258,
      -1,   162,   251,   258,    -1,   163,   251,   258,    -1,   164,
     251,   258,    -1,   165,   251,   258,    -1,   166,   255,   260,
      -1,   167,   253,   258,    -1,   168,   253,   258,    -1,   169,
     251,   256,    -1,   170,   255,   260,    -1,   171,   255,   260,
      -1,   172,   255,   260,    -1,   173,   253,   258,    -1,   174,
     255,   260,    -1,   175,   255,   260,    -1,   176,   251,   256,
      -1,   177,   255,   260,    -1,   178,   255,   260,    -1,   179,
     255,   260,    -1,   180,   255,   260,    -1,   181,   251,   256,
      -1,   182,   251,   256,    -1,   183,   255,   260,    -1,   184,
     253,   258,    -1,   185,   255,   260,    -1,   186,   253,   258,
      -1,   186,   251,   256,    -1,   187,   251,   256,    -1,   188,
     251,   256,    -1,   188,   252,   256,    -1,   188,   253,   256,
      -1,   188,   254,   256,    -1,   188,   255,   256,    -1,   189,
     251,   256,    -1,   190,   251,   256,    -1,   191,   251,   256,
      -1,   192,   251,   256,    -1,   193,   251,   256,    -1,   194,
     251,   256,    -1,   195,   251,   256,    -1,   196,   251,   256,
      -1,   197,   251,   256,    -1,   198,   251,   256,    -1,   199,
     251,   256,    -1,   200,   251,   256,    -1,   201,   251,   256,
      -1,   202,   251,   256,    -1,   203,   251,   256,    -1,   203,
     252,   257,    -1,   203,   253,   258,    -1,   203,   254,   259,
      -1,   203,   255,   260,    -1,   204,   251,   256,    -1,   205,
     251,   256,    -1,   206,   251,   256,    -1,   207,   251,   256,
      -1,   208,   253,   258,    -1,   209,   253,   258,    -1,   210,
     251,   256,    -1,   211,   251,   256,    -1,   212,   251,   256,
      -1,   213,   251,   256,    -1,   214,   251,   256,    -1,   215,
     255,   260,    -1,   216,   251,   256,    -1,   217,   255,   260,
      -1,   218,   251,   256,    -1,   219,   251,   256,    -1,   220,
     251,   256,    -1,   221,   253,   258,    -1,   222,   251,   256,
      -1,   222,   252,   257,    -1,   222,   253,   258,    -1,   222,
     254,   259,    -1,   222,   255,   260,    -1,   223,   251,   256,
      -1,   223,   252,   256,    -1,   223,   253,   256,    -1,   223,
     254,   256,    -1,   223,   255,   256,    -1,   224,   251,   256,
      -1,   224,   252,   256,    -1,   224,   253,   256,    -1,   224,
     254,   256,    -1,   224,   255,   256,    -1,   225,   253,   258,
      -1,   226,   251,   256,    -1,   226,   252,   256,    -1,   226,
     253,   256,    -1,   226,   254,   256,    -1,   226,   255,   256,
      -1,   227,   251,   256,    -1,   227,   252,   256,    -1,   227,
     253,   256,    -1,   227,   254,   256,    -1,   227,   255,   256,
      -1,   228,   251,   256,    -1,   228,   252,   256,    -1,   228,
     253,   256,    -1,   228,   254,   256,    -1,   228,   255,   256,
      -1,   229,   255,   260,    -1,   230,   251,   256,    -1,   231,
     253,   258,    -1,   232,   251,   256,    -1,   232,   253,   258,
      -1,   233,   251,   256,    -1,   234,   251,   256,    -1,   235,
     251,   256,    -1,   236,   251,   256,    -1,   236,   252,   256,
      -1,   236,   253,   256,    -1,   236,   254,   256,    -1,   236,
     255,   256,    -1,   237,   251,   256,    -1,   237,   252,   256,
      -1,   237,   253,   256,    -1,   237,   254,   256,    -1,   237,
     255,   256,    -1,   238,   253,   258,    -1,   238,   255,   260,
      -1,   239,   251,   256,    -1,   240,   253,   258,    -1,   241,
     253,   258,    -1,   242,   251,   256,    -1,   243,   251,   256,
      -1,   244,   251,   256,    -1,   245,   251,   256,    -1,   246,
     251,   256,    -1,   247,   251,   256,    -1,   247,   252,   256,
      -1,   247,   253,   256,    -1,   247,   254,   256,    -1,   247,
     255,   256,    -1,   248,   251,   256,    -1,   248,   252,   256,
      -1,   248,   253,   256,    -1,   248,   254,   256,    -1,   248,
     255,   256,    -1,   249,   251,   256,    -1,   250,   251,   256,
      -1,     3,   251,   256,    -1,     4,   258,   258,   258,    -1,
      -1,    82,   251,   256,    -1,    82,   252,   257,    -1,    82,
     253,   258,    -1,    82,   254,   259,    -1,    82,   255,   260,
      -1,    82,   252,   256,    -1,    82,   253,   256,    -1,    82,
     254,   256,    -1,    82,   255,   256,    -1,    82,   251,   260,
      -1,    82,   252,   260,    -1,    82,   253,   260,    -1,    82,
     254,   260,    -1,     8,   260,    -1,     8,   262,   260,   263,
      -1,     9,   260,    -1,     9,   262,   260,   263,    -1,    10,
     260,   260,    -1,    11,   260,    -1,    12,    -1,    13,   260,
      -1,    14,   260,    -1,    15,   260,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    23,    -1,    24,    -1,     5,    -1,     6,    -1,     7,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
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
    1863,  1864,  1865,  1866,  1867,  1868,  1870,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,  1885,  1886,  1887,  1888,  1889,
    1890,  1891,  1892,  1893,  1894,  1895,  1901,  1902,  1903,  1904,
    1905,  1906,  1907,  1908,  1909,  1910,  1911,  1912,  1913,  1914,
    1915,  1916,  1917,  1918,  1919,  1920,  1922,  1923,  1930,  1933,
    1934,  1941,  1942,  1948,  1955,  1956,  1957,  1958,  1959,  1966,
    1973,  1980,  1990,  1991,  1992,  1993,  1994,  1995,  1996,  1997,
    1998,  1999,  2000,  2001,  2002,  2003,  2004,  2005,  2006,  2007,
    2008,  2011,  2012,  2013
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "IFNCFRET", "IFNCFPARAM", "IFNCFBRET", "IFNCFBPARAM", "TVOID",
  "TBOOLEAN", "TNUMBER", "TCHARACTER", "TSTRING", "VOID", "BOOLEAN",
  "NUMBER", "CHARACTER", "STRING", "'\\n'", "\"<\"", "\">\"", "$accept",
  "input", "line", "instruction", "pinstruction", "variable", "pp",
  "directive", 0
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,    10,   516,   517
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   264,   265,   265,   266,   266,   266,   266,   266,   266,
     266,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   268,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   271,   271,   271
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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
       3,     3,     3,     3,     3,     3,     3,     4,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     4,     2,     4,     3,     2,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    10,     0,     0,   411,   412,   413,     0,
       0,     0,     0,   398,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,   410,     0,     0,     0,     0,
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
       0,   392,     0,   394,     0,     0,   397,   399,   400,   401,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   376,
       0,     0,     0,   396,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   379,   388,   384,   380,
     389,   385,   381,   390,   386,   382,   391,   387,   383,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   261,   260,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   377,   393,   395
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   253,   254,   255,   256,   257,   258
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -250
static const yytype_int16 yypact[] =
{
    -250,     0,  -250,  -250,  -249,    -7,  -250,  -250,  -250,   150,
     187,   125,   155,  -250,   209,   215,   216,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,   220,   222,   219,   226,
     227,     1,    11,     5,   166,   228,   170,   229,   174,   230,
     178,   231,   182,   163,   186,   195,   232,    16,    21,   126,
     199,   200,   203,   204,   207,   208,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   140,   143,   145,   146,   148,   249,   250,   251,
     252,   151,   253,    26,   153,    31,    36,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,    41,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    46,    51,   300,   301,   302,   303,
     304,   305,   306,   154,   156,   190,    56,    61,   307,   311,
     312,   313,   314,   315,   316,   318,   317,   319,   320,   321,
     322,   323,   324,   328,   329,   330,   331,   332,   333,   335,
     334,   336,   337,   338,   341,   340,   342,   339,   343,   344,
     345,   346,   351,   352,   349,   353,   350,   211,   356,    66,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,    71,   371,   372,   373,   374,   375,
     376,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     389,   391,   390,    76,    81,    86,   392,    91,    96,   101,
     393,   395,   394,   212,   398,   399,   400,   106,   111,   213,
     401,   402,   403,   406,   407,   408,   409,   410,   116,   121,
     411,   412,  -250,  -250,  -250,  -250,  -250,  -250,  -250,   310,
     309,  -250,   377,  -250,   404,   405,  -250,  -250,  -250,  -250,
     214,   327,   413,   326,   388,   397,   210,   396,   415,   416,
     414,   378,   417,   418,   419,   422,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   455,   454,   456,   457,   458,   459,   462,
     461,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   423,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   453,   509,   510,   511,   512,
     513,   514,   515,   516,   519,   521,   522,   523,   524,   520,
     527,   122,   127,   130,   133,   157,   528,   525,   530,   531,
     529,   532,   533,   534,   535,   536,   537,   538,   539,   541,
     542,   543,   546,   545,   548,   547,   550,   549,   552,   551,
     554,   553,   556,   555,   558,   557,   560,   559,   562,   561,
     564,   563,   565,   566,   567,   568,   571,   572,   573,   574,
     575,   576,   540,   577,   579,   580,   581,   582,   584,   583,
     585,   586,   589,   590,   591,   592,   593,   594,   595,   596,
     598,   599,   597,   600,   601,   604,   605,   603,   606,   602,
     608,   607,   609,   610,   611,   612,   613,   614,   617,   615,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   636,   638,   639,   640,   637,
     641,   642,   645,   643,   644,   646,   647,   648,   651,   652,
     653,   654,   655,   656,   657,   659,   649,   658,   660,   661,
     664,   663,   665,   668,   666,   667,   669,   670,   672,   675,
     673,   674,   676,   678,   677,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   662,   702,   703,   704,
     705,   707,   709,   710,   711,   712,   715,   716,   717,   718,
     719,   708,   720,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   733,   735,   736,   737,   738,   739,
     740,   741,   742,   743,   744,   746,   747,   748,   749,   750,
     751,   752,   753,   754,   755,   756,   757,   758,   759,   760,
     761,   763,   762,   764,   767,   768,   769,   770,   771,   772,
     773,   774,   775,   776,   777,   778,   779,   780,   781,   783,
     782,   784,   787,   788,   789,   790,   791,   792,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   802,   803,  -250,
     804,   421,   526,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
       2,     3,   259,     4,     5,     6,     7,     8,     9,    10,
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
     251,   260,   275,   276,   277,   278,   279,   285,   286,   287,
     288,   252,   280,   281,   282,   283,   284,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   381,   382,   383,
     384,   385,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   429,   430,   431,   432,   433,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   526,   527,   528,
     529,   530,   545,   546,   547,   548,   549,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   332,   756,   333,
     334,   335,   757,   758,   759,   265,   761,   760,   762,   764,
     763,   364,   765,   766,   366,   365,   368,   370,   367,   372,
     369,   371,   378,   373,   386,   466,   379,   468,   387,   467,
     261,   469,   262,   767,   313,   266,   314,   768,   289,   290,
     291,   292,   294,   295,   296,   297,   299,   300,   301,   302,
     304,   305,   306,   307,   309,   310,   311,   312,   315,   316,
     317,   318,   470,   471,   472,   473,   319,   263,   320,   264,
     336,   338,   337,   339,   340,   342,   341,   343,   344,   346,
     345,   347,   523,   602,   524,   603,   617,   651,   618,   267,
     644,   270,   645,   271,   272,   268,   269,   273,   274,   293,
     298,   303,   308,   321,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     374,   375,   376,   377,   380,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   459,   460,     0,     0,   461,   462,     0,   484,   463,
     464,   465,   485,   486,   487,   488,   639,   640,   492,   490,
     489,   491,     0,   494,   493,   498,   495,   496,   497,   499,
     500,   501,   502,   646,   648,   506,   504,   503,   505,     0,
     513,   507,   508,   509,   510,   511,     0,   512,   514,   515,
     516,   517,   518,   519,   520,   522,   521,   525,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   550,   551,   552,   553,     0,     0,   554,   555,
     556,   557,   558,   559,   560,   656,   562,   641,   564,   561,
     565,   563,   566,   567,   649,   583,   600,   601,   599,   604,
     605,   606,   619,   650,   652,   620,   621,   622,   623,   624,
     625,   626,   637,   638,   642,   643,     0,     0,     0,     0,
     655,     0,     0,   647,   653,   657,   654,   658,   660,   659,
     661,   662,   663,   710,  1023,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,   682,   683,     0,     0,   684,   685,   686,
     687,   688,   689,   740,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,     0,     0,   708,   711,   709,   713,   712,   715,
     714,   717,   716,   719,   718,   721,   720,   723,   722,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,     0,
       0,   734,   735,   736,   737,   738,   739,   741,     0,   743,
     742,   745,   744,   747,   746,   749,   748,   750,   751,     0,
     754,   752,   753,   755,   769,   770,   771,   773,   772,  1024,
     776,   774,   777,   775,   778,   781,   779,   782,   780,   815,
     783,   784,   785,   786,   787,   788,   789,   790,   791,   792,
     793,   794,   795,   796,   797,   798,   799,   800,   801,   802,
     803,   804,     0,   805,   806,   807,   808,   809,   810,   811,
     812,     0,   813,     0,   814,   817,   818,   816,   820,   819,
     821,   822,     0,   823,   824,   825,   826,   827,   828,   829,
     830,   831,     0,     0,   832,   833,   835,   834,   842,   837,
     836,   838,   840,   839,   843,   844,   841,   845,     0,   849,
     846,   847,   848,   851,   850,   852,   853,   854,   855,   856,
     857,     0,   858,     0,   859,   862,   860,   863,   861,   864,
     867,   865,   868,   866,   869,   870,   871,   872,     0,   873,
     874,   875,   877,   876,     0,   889,   878,   879,   880,   881,
     882,   883,   884,   885,     0,   887,   886,   888,   890,   929,
     891,   892,   893,   894,   896,   895,   897,   898,   901,   899,
     900,   902,   904,   903,   906,   907,   905,   908,   909,   910,
     911,   912,   913,   914,   915,   916,   917,   918,   919,   920,
     921,   922,   923,   924,   925,   926,   927,   928,     0,     0,
     930,   933,   931,   934,   932,   935,   936,     0,   944,   937,
     938,   939,   940,   941,   942,   943,   945,     0,   947,   948,
     949,   946,   951,   950,   952,     0,   953,   956,   954,   957,
     955,   958,   959,   960,   961,   962,   963,   964,   965,     0,
     967,   966,   968,   969,   970,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   980,   981,     0,   983,   985,     0,
     982,   984,   986,   987,   988,   989,   990,   991,   992,   993,
     994,   995,   996,   997,   998,   999,     0,     0,  1000,  1002,
    1003,  1001,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
       0,     0,  1022
};

static const yytype_int16 yycheck[] =
{
       0,     1,   251,     3,     4,     5,     6,     7,     8,     9,
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
     250,   258,   251,   252,   253,   254,   255,   252,   253,   254,
     255,   261,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   256,   253,
     254,   255,   260,   256,   257,   260,   256,   260,   258,   256,
     260,   251,   259,   260,   251,   255,   251,   251,   255,   251,
     255,   255,   251,   255,   251,   251,   255,   251,   255,   255,
     260,   255,   262,   256,   251,   260,   253,   260,   252,   253,
     254,   255,   252,   253,   254,   255,   252,   253,   254,   255,
     252,   253,   254,   255,   252,   253,   254,   255,   252,   253,
     254,   255,   252,   253,   254,   255,   251,   260,   253,   262,
     251,   251,   253,   253,   251,   251,   253,   253,   251,   251,
     253,   253,   251,   251,   253,   253,   253,   257,   255,   260,
     256,   251,   258,   251,   255,   260,   260,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,    -1,    -1,   253,   253,    -1,   251,   255,
     255,   255,   251,   251,   251,   251,   256,   258,   251,   253,
     255,   253,    -1,   253,   255,   251,   255,   255,   255,   251,
     251,   251,   251,   256,   258,   251,   253,   255,   253,    -1,
     251,   255,   255,   255,   253,   255,    -1,   255,   255,   255,
     255,   255,   251,   251,   255,   255,   253,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,    -1,    -1,   253,   253,
     251,   251,   251,   251,   251,   257,   251,   260,   251,   255,
     251,   255,   251,   253,   256,   253,   251,   253,   255,   251,
     251,   251,   251,   256,   258,   253,   253,   251,   251,   251,
     251,   251,   251,   251,   260,   260,    -1,    -1,    -1,    -1,
     256,    -1,    -1,   260,   259,   258,   260,   259,   256,   260,
     256,   256,   256,   260,   263,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,    -1,    -1,   258,   258,   258,
     258,   256,   258,   260,   258,   258,   258,   258,   256,   258,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,    -1,    -1,   258,   256,   259,   256,   258,   256,
     258,   256,   258,   256,   258,   256,   258,   256,   258,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,    -1,
      -1,   258,   258,   258,   258,   258,   258,   258,    -1,   258,
     260,   258,   260,   258,   260,   256,   260,   256,   256,    -1,
     260,   258,   258,   256,   256,   260,   256,   258,   257,   263,
     256,   259,   257,   260,   258,   256,   259,   256,   260,   259,
     258,   258,   256,   258,   256,   258,   256,   258,   256,   258,
     256,   258,   256,   258,   256,   258,   256,   258,   256,   258,
     256,   258,    -1,   258,   258,   258,   258,   256,   256,   256,
     256,    -1,   257,    -1,   258,   256,   256,   260,   256,   258,
     256,   258,    -1,   258,   258,   256,   256,   256,   256,   256,
     256,   256,    -1,    -1,   258,   257,   259,   258,   256,   258,
     260,   257,   259,   258,   256,   258,   260,   258,    -1,   256,
     260,   260,   260,   256,   260,   260,   256,   256,   256,   256,
     256,    -1,   257,    -1,   258,   256,   259,   257,   260,   258,
     256,   259,   256,   260,   256,   256,   256,   260,    -1,   258,
     258,   256,   258,   260,    -1,   256,   260,   260,   260,   258,
     258,   258,   258,   258,    -1,   258,   260,   258,   260,   257,
     260,   260,   258,   260,   256,   260,   260,   260,   256,   260,
     260,   256,   258,   260,   256,   258,   260,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,    -1,    -1,
     258,   256,   259,   256,   260,   256,   256,    -1,   260,   258,
     258,   256,   256,   256,   256,   256,   256,    -1,   256,   256,
     256,   260,   256,   258,   257,    -1,   258,   256,   259,   256,
     260,   256,   256,   256,   256,   256,   256,   256,   256,    -1,
     256,   258,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,    -1,   256,   256,    -1,
     260,   258,   258,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,    -1,    -1,   258,   256,
     258,   260,   258,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
      -1,    -1,   258
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   265,     0,     1,     3,     4,     5,     6,     7,     8,
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
     249,   250,   261,   266,   267,   268,   269,   270,   271,   251,
     258,   260,   262,   260,   262,   260,   260,   260,   260,   260,
     251,   251,   255,   251,   251,   251,   252,   253,   254,   255,
     251,   252,   253,   254,   255,   252,   253,   254,   255,   252,
     253,   254,   255,   251,   252,   253,   254,   255,   251,   252,
     253,   254,   255,   251,   252,   253,   254,   255,   251,   252,
     253,   254,   255,   251,   253,   252,   253,   254,   255,   251,
     253,   251,   251,   252,   253,   254,   255,   251,   252,   253,
     254,   255,   251,   253,   254,   255,   251,   253,   251,   253,
     251,   253,   251,   253,   251,   253,   251,   253,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   255,   251,   255,   251,   255,
     251,   255,   251,   255,   251,   251,   251,   251,   251,   255,
     251,   251,   252,   253,   254,   255,   251,   255,   251,   252,
     253,   254,   255,   251,   252,   253,   254,   255,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     252,   253,   254,   255,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     252,   253,   254,   255,   251,   252,   253,   254,   255,   251,
     251,   253,   253,   255,   255,   255,   251,   255,   251,   255,
     252,   253,   254,   255,   251,   252,   253,   254,   255,   251,
     252,   253,   254,   255,   251,   251,   251,   251,   251,   255,
     253,   253,   251,   255,   253,   255,   255,   255,   251,   251,
     251,   251,   251,   255,   253,   253,   251,   255,   255,   255,
     253,   255,   255,   251,   255,   255,   255,   255,   251,   251,
     255,   253,   255,   251,   253,   251,   251,   252,   253,   254,
     255,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   252,   253,   254,   255,
     251,   251,   251,   251,   253,   253,   251,   251,   251,   251,
     251,   255,   251,   255,   251,   251,   251,   253,   251,   252,
     253,   254,   255,   251,   252,   253,   254,   255,   251,   252,
     253,   254,   255,   253,   251,   252,   253,   254,   255,   251,
     252,   253,   254,   255,   251,   252,   253,   254,   255,   255,
     251,   253,   251,   253,   251,   251,   251,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   253,   255,   251,
     253,   253,   251,   251,   251,   251,   251,   251,   252,   253,
     254,   255,   251,   252,   253,   254,   255,   251,   251,   256,
     258,   260,   260,   260,   256,   258,   256,   260,   258,   256,
     256,   257,   258,   259,   260,   256,   257,   258,   259,   260,
     256,   256,   256,   256,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   258,   258,   258,   258,   256,   258,
     258,   258,   258,   258,   256,   258,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   258,   259,
     260,   256,   258,   256,   258,   256,   258,   256,   258,   256,
     258,   256,   258,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   258,   258,   258,   258,   258,   258,
     260,   258,   260,   258,   260,   258,   260,   258,   260,   256,
     256,   256,   258,   258,   260,   256,   256,   260,   256,   257,
     260,   256,   258,   260,   256,   259,   260,   256,   260,   256,
     260,   256,   257,   258,   259,   260,   256,   257,   258,   259,
     260,   256,   256,   258,   258,   256,   258,   256,   258,   256,
     258,   256,   258,   256,   258,   256,   258,   256,   258,   256,
     258,   256,   258,   256,   258,   258,   258,   258,   258,   256,
     256,   256,   256,   257,   258,   259,   260,   256,   256,   258,
     256,   256,   258,   258,   258,   256,   256,   256,   256,   256,
     256,   256,   258,   257,   258,   259,   260,   258,   257,   258,
     259,   260,   256,   256,   258,   258,   260,   260,   260,   256,
     260,   256,   260,   256,   256,   256,   256,   256,   257,   258,
     259,   260,   256,   257,   258,   259,   260,   256,   256,   256,
     256,   256,   260,   258,   258,   256,   260,   258,   260,   260,
     260,   258,   258,   258,   258,   258,   260,   258,   258,   256,
     260,   260,   260,   258,   260,   260,   256,   260,   260,   260,
     260,   256,   256,   260,   258,   260,   256,   258,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   257,
     258,   259,   260,   256,   256,   256,   256,   258,   258,   256,
     256,   256,   256,   256,   260,   256,   260,   256,   256,   256,
     258,   256,   257,   258,   259,   260,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   258,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   260,   256,   258,   256,   258,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     258,   260,   256,   258,   258,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   258,   263,   263
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
        case 10:

/* Line 1455 of yacc.c  */
#line 1094 "pnfasm.ypp"
    { yyerrok; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 1097 "pnfasm.ypp"
    { fprintf(output, "0 0 0\n"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 1098 "pnfasm.ypp"
    { fprintf(output, "0 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 1099 "pnfasm.ypp"
    { fprintf(output, "1 0 0\n"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 1101 "pnfasm.ypp"
    {
		 fprintf(output, "2 4 ");

		 for (int i = 1; (yyvsp[(3) - (3)])[i] != '\"'; ++i)
                  fprintf(output, "%i ", (yyvsp[(3) - (3)])[i]);
		 fprintf(output, "0\n");
		;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 1108 "pnfasm.ypp"
    { fprintf(output, "3 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 1109 "pnfasm.ypp"
    { fprintf(output, "4 0 0\n"); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 1110 "pnfasm.ypp"
    { fprintf(output, "5 0 0\n"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 1111 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "5 1 1\n");
						 else
						  fprintf(output, "5 1 0\n");
					        ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 1117 "pnfasm.ypp"
    { fprintf(output, "5 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 1118 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "5 3 %i\n", ch);
						;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 1123 "pnfasm.ypp"
    {
						 fprintf(output, "5 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 1132 "pnfasm.ypp"
    { fprintf(output, "6 0 0\n"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 1133 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "6 1 1\n");
						 else
						  fprintf(output, "6 1 0\n");
					        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 1139 "pnfasm.ypp"
    { fprintf(output, "6 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1140 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "6 3 %i\n", ch);
						;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 1145 "pnfasm.ypp"
    { 
						 fprintf(output, "6 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 1154 "pnfasm.ypp"
    { fprintf(output, "7 1 0\n"); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1155 "pnfasm.ypp"
    { fprintf(output, "7 2 0\n"); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1156 "pnfasm.ypp"
    { fprintf(output, "7 3 0\n"); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1157 "pnfasm.ypp"
    { fprintf(output, "7 4 0\n"); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1158 "pnfasm.ypp"
    { fprintf(output, "8 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1159 "pnfasm.ypp"
    { fprintf(output, "8 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1160 "pnfasm.ypp"
    { fprintf(output, "8 3 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1161 "pnfasm.ypp"
    { fprintf(output, "8 4 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 1162 "pnfasm.ypp"
    { fprintf(output, "9 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1163 "pnfasm.ypp"
    { fprintf(output, "10 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1164 "pnfasm.ypp"
    { fprintf(output, "10 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 1165 "pnfasm.ypp"
    { fprintf(output, "10 3 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1166 "pnfasm.ypp"
    { fprintf(output, "10 4 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1167 "pnfasm.ypp"
    { fprintf(output, "11 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1168 "pnfasm.ypp"
    { fprintf(output, "12 1 0\n"); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1169 "pnfasm.ypp"
    { fprintf(output, "12 2 0\n"); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1170 "pnfasm.ypp"
    { fprintf(output, "12 3 0\n"); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1171 "pnfasm.ypp"
    { fprintf(output, "12 4 0\n"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1172 "pnfasm.ypp"
    { fprintf(output, "13 0 0\n"); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1173 "pnfasm.ypp"
    { fprintf(output, "14 1 0\n"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1174 "pnfasm.ypp"
    { fprintf(output, "14 2 0\n"); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1175 "pnfasm.ypp"
    { fprintf(output, "14 3 0\n"); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1176 "pnfasm.ypp"
    { fprintf(output, "14 4 0\n"); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1177 "pnfasm.ypp"
    { fprintf(output, "15 0 0\n"); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1178 "pnfasm.ypp"
    { fprintf(output, "16 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1179 "pnfasm.ypp"
    { fprintf(output, "16 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1180 "pnfasm.ypp"
    { fprintf(output, "16 3 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1181 "pnfasm.ypp"
    { fprintf(output, "16 4 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1182 "pnfasm.ypp"
    { fprintf(output, "17 0 0\n"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1183 "pnfasm.ypp"
    { fprintf(output, "17 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1184 "pnfasm.ypp"
    { fprintf(output, "18 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1185 "pnfasm.ypp"
    { fprintf(output, "18 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1186 "pnfasm.ypp"
    { fprintf(output, "18 3 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1187 "pnfasm.ypp"
    { fprintf(output, "18 4 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1188 "pnfasm.ypp"
    { fprintf(output, "19 0 0\n"); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1189 "pnfasm.ypp"
    { fprintf(output, "19 4 0\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1190 "pnfasm.ypp"
    { fprintf(output, "20 0 0\n"); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1191 "pnfasm.ypp"
    { fprintf(output, "21 0 0\n"); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1192 "pnfasm.ypp"
    { fprintf(output, "21 1 0\n"); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1193 "pnfasm.ypp"
    { fprintf(output, "21 2 0\n"); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1194 "pnfasm.ypp"
    { fprintf(output, "21 3 0\n"); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1195 "pnfasm.ypp"
    { fprintf(output, "21 4 0\n"); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1196 "pnfasm.ypp"
    { fprintf(output, "22 0 0\n"); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1197 "pnfasm.ypp"
    { fprintf(output, "22 1 0\n"); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1198 "pnfasm.ypp"
    { fprintf(output, "22 2 0\n"); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1199 "pnfasm.ypp"
    { fprintf(output, "22 3 0\n"); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1200 "pnfasm.ypp"
    { fprintf(output, "22 4 0\n"); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1201 "pnfasm.ypp"
    { fprintf(output, "23 0 0\n"); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1202 "pnfasm.ypp"
    { fprintf(output, "23 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1203 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "23 3 %i\n", ch);
						;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1208 "pnfasm.ypp"
    {		
						 fprintf(output, "23 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1214 "pnfasm.ypp"
    { fprintf(output, "24 0 0\n"); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1215 "pnfasm.ypp"
    { fprintf(output, "24 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1216 "pnfasm.ypp"
    { fprintf(output, "25 0 0\n"); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1217 "pnfasm.ypp"
    { fprintf(output, "25 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1218 "pnfasm.ypp"
    { fprintf(output, "26 0 0\n"); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1219 "pnfasm.ypp"
    { fprintf(output, "26 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1220 "pnfasm.ypp"
    { fprintf(output, "27 0 0\n"); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1221 "pnfasm.ypp"
    { fprintf(output, "27 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1222 "pnfasm.ypp"
    { fprintf(output, "28 0 0\n"); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1223 "pnfasm.ypp"
    { fprintf(output, "28 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1224 "pnfasm.ypp"
    { fprintf(output, "29 0 0\n"); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1225 "pnfasm.ypp"
    { fprintf(output, "29 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1226 "pnfasm.ypp"
    { fprintf(output, "30 0 0\n"); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1227 "pnfasm.ypp"
    { fprintf(output, "31 0 0\n"); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1228 "pnfasm.ypp"
    { fprintf(output, "32 0 0\n"); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1229 "pnfasm.ypp"
    { fprintf(output, "33 0 0\n"); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1230 "pnfasm.ypp"
    { fprintf(output, "34 0 0\n"); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1231 "pnfasm.ypp"
    { fprintf(output, "35 0 0\n"); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1232 "pnfasm.ypp"
    { fprintf(output, "36 0 0\n"); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1233 "pnfasm.ypp"
    { fprintf(output, "37 0 0\n"); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1234 "pnfasm.ypp"
    { fprintf(output, "38 0 0\n"); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1235 "pnfasm.ypp"
    { fprintf(output, "39 0 0\n"); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1236 "pnfasm.ypp"
    { fprintf(output, "40 0 0\n"); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1237 "pnfasm.ypp"
    { fprintf(output, "41 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1238 "pnfasm.ypp"
    { fprintf(output, "42 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1239 "pnfasm.ypp"
    { fprintf(output, "43 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1240 "pnfasm.ypp"
    { fprintf(output, "44 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1241 "pnfasm.ypp"
    { fprintf(output, "45 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1242 "pnfasm.ypp"
    { fprintf(output, "46 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1243 "pnfasm.ypp"
    {
						 fprintf(output, "46 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1249 "pnfasm.ypp"
    { fprintf(output, "47 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1251 "pnfasm.ypp"
    {
						 fprintf(output, "47 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1257 "pnfasm.ypp"
    { fprintf(output, "48 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1259 "pnfasm.ypp"
    {
						 fprintf(output, "48 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1265 "pnfasm.ypp"
    { fprintf(output, "49 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1267 "pnfasm.ypp"
    {
						 fprintf(output, "49 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1273 "pnfasm.ypp"
    { fprintf(output, "50 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1275 "pnfasm.ypp"
    {
						 fprintf(output, "50 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1281 "pnfasm.ypp"
    { fprintf(output, "51 0 0\n"); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1282 "pnfasm.ypp"
    { fprintf(output, "52 0 0\n"); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1283 "pnfasm.ypp"
    { fprintf(output, "53 0 0\n"); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1284 "pnfasm.ypp"
    { fprintf(output, "54 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1285 "pnfasm.ypp"
    { fprintf(output, "55 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1287 "pnfasm.ypp"
    {
						 fprintf(output, "55 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1293 "pnfasm.ypp"
    { fprintf(output, "56 0 0\n"); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1295 "pnfasm.ypp"
    { fprintf(output, "58 0 0\n"); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1296 "pnfasm.ypp"
    {
						 fprintf(output, "58 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");		
						;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1302 "pnfasm.ypp"
    { fprintf(output, "59 0 0\n"); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1303 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "59 1 1\n");
						 else
						  fprintf(output, "59 1 0\n");
					        ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1309 "pnfasm.ypp"
    { fprintf(output, "59 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1310 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "59 3 %i\n", ch);
						;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1315 "pnfasm.ypp"
    { 
						 fprintf(output, "59 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1325 "pnfasm.ypp"
    { fprintf(output, "60 0 0\n"); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1326 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "60 1 1\n");
						 else
						  fprintf(output, "60 1 0\n");
					        ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1332 "pnfasm.ypp"
    { fprintf(output, "60 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1333 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "60 3 %i\n", ch);
						;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1338 "pnfasm.ypp"
    { 
						 fprintf(output, "60 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1348 "pnfasm.ypp"
    { fprintf(output, "61 0 0"); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1349 "pnfasm.ypp"
    { fprintf(output, "62 0 0\n"); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1350 "pnfasm.ypp"
    { fprintf(output, "63 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1351 "pnfasm.ypp"
    { fprintf(output, "64 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1352 "pnfasm.ypp"
    { fprintf(output, "65 0 0\n"); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1353 "pnfasm.ypp"
    { fprintf(output, "66 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1354 "pnfasm.ypp"
    { fprintf(output, "67 0 0\n"); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1355 "pnfasm.ypp"
    { fprintf(output, "68 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1356 "pnfasm.ypp"
    { fprintf(output, "69 0 0\n"); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1357 "pnfasm.ypp"
    { fprintf(output, "70 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1358 "pnfasm.ypp"
    { fprintf(output, "71 0 0\n"); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1359 "pnfasm.ypp"
    { fprintf(output, "72 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1360 "pnfasm.ypp"
    { fprintf(output, "73 0 0\n"); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1361 "pnfasm.ypp"
    { fprintf(output, "74 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1362 "pnfasm.ypp"
    { fprintf(output, "75 0 0\n"); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1363 "pnfasm.ypp"
    { fprintf(output, "76 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1364 "pnfasm.ypp"
    { fprintf(output, "77 0 0\n"); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1365 "pnfasm.ypp"
    { fprintf(output, "78 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1366 "pnfasm.ypp"
    { fprintf(output, "79 0 0\n"); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1367 "pnfasm.ypp"
    { fprintf(output, "80 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1368 "pnfasm.ypp"
    { fprintf(output, "81 0 0\n"); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1369 "pnfasm.ypp"
    { fprintf(output, "82 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1370 "pnfasm.ypp"
    { fprintf(output, "83 0 0\n"); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1371 "pnfasm.ypp"
    { fprintf(output, "84 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1372 "pnfasm.ypp"
    { fprintf(output, "85 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1373 "pnfasm.ypp"
    { fprintf(output, "86 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1374 "pnfasm.ypp"
    { fprintf(output, "87 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1375 "pnfasm.ypp"
    { fprintf(output, "88 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1376 "pnfasm.ypp"
    { fprintf(output, "89 0 0\n"); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1377 "pnfasm.ypp"
    { fprintf(output, "90 0 0\n"); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1378 "pnfasm.ypp"
    { fprintf(output, "91 0 0\n"); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1379 "pnfasm.ypp"
    { fprintf(output, "92 0 0\n"); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1381 "pnfasm.ypp"
    {
		 if ((yyvsp[(3) - (3)]) == "true")
		  fprintf(output, "92 1 1\n");
		 else
		  fprintf(output, "92 1 0\n");
		;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1387 "pnfasm.ypp"
    { fprintf(output, "92 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1389 "pnfasm.ypp"
    {
		 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "92 3 %i\n", ch);
		;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1395 "pnfasm.ypp"
    {
		 fprintf(output, "92 4 ");
		 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
                 {
		  if ((yyvsp[(3) - (3)])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
		 }
		 fprintf(output, "0\n");
		;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1404 "pnfasm.ypp"
    { fprintf(output, "93 0 0\n"); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1405 "pnfasm.ypp"
    { fprintf(output, "94 0 0\n"); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1406 "pnfasm.ypp"
    { fprintf(output, "95 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1407 "pnfasm.ypp"
    { fprintf(output, "96 0 0\n"); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1408 "pnfasm.ypp"
    { fprintf(output, "97 0 0\n"); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1409 "pnfasm.ypp"
    { fprintf(output, "98 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1410 "pnfasm.ypp"
    { fprintf(output, "99 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1411 "pnfasm.ypp"
    { fprintf(output, "100 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1412 "pnfasm.ypp"
    { fprintf(output, "101 0 0\n"); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1413 "pnfasm.ypp"
    { fprintf(output, "102 0 0\n"); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1414 "pnfasm.ypp"
    { fprintf(output, "103 0 0\n"); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1415 "pnfasm.ypp"
    { fprintf(output, "104 0 0\n"); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1416 "pnfasm.ypp"
    { fprintf(output, "105 0 0\n"); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1417 "pnfasm.ypp"
    { fprintf(output, "106 0 0\n"); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1418 "pnfasm.ypp"
    { fprintf(output, "107 0 0\n"); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1419 "pnfasm.ypp"
    { fprintf(output, "108 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1421 "pnfasm.ypp"
    {
		 if ((yyvsp[(3) - (3)]) == "true")
		  fprintf(output, "108 1 1\n");
		 else
		  fprintf(output, "108 1 0\n");
		;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1427 "pnfasm.ypp"
    { fprintf(output, "108 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1429 "pnfasm.ypp"
    {
		 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "108 3 %i\n", ch);
		;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1435 "pnfasm.ypp"
    {
		 fprintf(output, "108 4 ");
		 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
                 {
		  if ((yyvsp[(3) - (3)])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
		 }
		 fprintf(output, "0\n");
		;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1444 "pnfasm.ypp"
    { fprintf(output, "109 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1446 "pnfasm.ypp"
    {
		 if ((yyvsp[(3) - (3)]) == "true")
		  fprintf(output, "109 1 1\n");
		 else
		  fprintf(output, "109 1 0\n");
		;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1452 "pnfasm.ypp"
    { fprintf(output, "109 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1454 "pnfasm.ypp"
    {
		 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "109 3 %i\n", ch);
		;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1460 "pnfasm.ypp"
    {
		 fprintf(output, "109 4 ");
		 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
                 {
		  if ((yyvsp[(3) - (3)])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
		 }
		 fprintf(output, "0\n");
		;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1469 "pnfasm.ypp"
    { fprintf(output, "110 0 0\n"); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1470 "pnfasm.ypp"
    { fprintf(output, "111 0 0\n"); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1471 "pnfasm.ypp"
    { fprintf(output, "112 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1472 "pnfasm.ypp"
    { fprintf(output, "113 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1474 "pnfasm.ypp"
    {
		 fprintf(output, "114 4 ");
		 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
                 {
		  if ((yyvsp[(3) - (3)])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
		 }
		 fprintf(output, "0\n");
		;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1484 "pnfasm.ypp"
    {
		 fprintf(output, "115 4 ");
		 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
                 {
		  if ((yyvsp[(3) - (3)])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
		 }
		 fprintf(output, "0\n");
		;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1494 "pnfasm.ypp"
    {
		 fprintf(output, "116 4 ");
		 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
                 {
		  if ((yyvsp[(3) - (3)])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
		 }
		 fprintf(output, "0\n");
		;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1503 "pnfasm.ypp"
    { fprintf(output, "117 0 0\n"); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1505 "pnfasm.ypp"
    {
		 fprintf(output, "117 4 ");
		 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
                 {
		  if ((yyvsp[(3) - (3)])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
		 }
		 fprintf(output, "0\n");
		;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1514 "pnfasm.ypp"
    { fprintf(output, "118 0 0\n"); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1516 "pnfasm.ypp"
    {
		 fprintf(output, "118 4 ");
		 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
                 {
		  if ((yyvsp[(3) - (3)])[i] != '\"')
                   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
		 }
		 fprintf(output, "0\n");
		;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1525 "pnfasm.ypp"
    { fprintf(output, "119 1 0\n"); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1526 "pnfasm.ypp"
    { fprintf(output, "119 2 0\n"); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1527 "pnfasm.ypp"
    { fprintf(output, "119 3 0\n"); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1528 "pnfasm.ypp"
    { fprintf(output, "119 4 0\n"); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1529 "pnfasm.ypp"
    { fprintf(output, "120 0 0\n"); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1530 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "120 1 1\n");
						 else
						  fprintf(output, "120 1 0\n");
					        ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1536 "pnfasm.ypp"
    { fprintf(output, "120 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1537 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "120 3 %i\n", ch);
						;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1542 "pnfasm.ypp"
    { 
						 fprintf(output, "120 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1551 "pnfasm.ypp"
    { fprintf(output, "121 0 0\n"); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1552 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "121 1 1\n");
						 else
						  fprintf(output, "121 1 0\n");
					        ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1558 "pnfasm.ypp"
    { fprintf(output, "121 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1559 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "121 3 %i\n", ch);
						;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1564 "pnfasm.ypp"
    { 
						 fprintf(output, "121 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1573 "pnfasm.ypp"
    { fprintf(output, "122 0 0\n"); ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1574 "pnfasm.ypp"
    { fprintf(output, "123 0 0\n"); ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1575 "pnfasm.ypp"
    { fprintf(output, "124 0 0\n"); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1576 "pnfasm.ypp"
    { fprintf(output, "125 0 0\n"); ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1577 "pnfasm.ypp"
    { fprintf(output, "126 0 0\n"); ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1578 "pnfasm.ypp"
    { 
						 fprintf(output, "127 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1587 "pnfasm.ypp"
    { fprintf(output, "128 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1588 "pnfasm.ypp"
    { fprintf(output, "129 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1589 "pnfasm.ypp"
    { fprintf(output, "130 0 0\n"); ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1590 "pnfasm.ypp"
    { 
						 fprintf(output, "131 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1599 "pnfasm.ypp"
    { fprintf(output, "132 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1600 "pnfasm.ypp"
    { 
						 fprintf(output, "133 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1609 "pnfasm.ypp"
    { 
						 fprintf(output, "134 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1618 "pnfasm.ypp"
    { 
						 fprintf(output, "135 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1627 "pnfasm.ypp"
    { fprintf(output, "136 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1628 "pnfasm.ypp"
    { fprintf(output, "137 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1629 "pnfasm.ypp"
    { fprintf(output, "138 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1630 "pnfasm.ypp"
    { fprintf(output, "139 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1631 "pnfasm.ypp"
    { fprintf(output, "140 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1632 "pnfasm.ypp"
    { 
						 fprintf(output, "141 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1641 "pnfasm.ypp"
    { fprintf(output, "142 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1642 "pnfasm.ypp"
    { fprintf(output, "143 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1643 "pnfasm.ypp"
    { fprintf(output, "144 0 0\n"); ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1644 "pnfasm.ypp"
    { 
						 fprintf(output, "145 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1653 "pnfasm.ypp"
    { 
						 fprintf(output, "146 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1662 "pnfasm.ypp"
    { 
						 fprintf(output, "147 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1671 "pnfasm.ypp"
    { fprintf(output, "148 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1672 "pnfasm.ypp"
    { 
						 fprintf(output, "149 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1681 "pnfasm.ypp"
    { 
						 fprintf(output, "150 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1690 "pnfasm.ypp"
    { fprintf(output, "151 0 0\n"); ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1691 "pnfasm.ypp"
    { 
						 fprintf(output, "152 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1700 "pnfasm.ypp"
    { 
						 fprintf(output, "153 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1709 "pnfasm.ypp"
    { 
						 fprintf(output, "154 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1718 "pnfasm.ypp"
    { 
						 fprintf(output, "155 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1727 "pnfasm.ypp"
    { fprintf(output, "156 0 0\n"); ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1728 "pnfasm.ypp"
    { fprintf(output, "157 0 0\n"); ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1729 "pnfasm.ypp"
    { 
						 fprintf(output, "158 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1738 "pnfasm.ypp"
    { fprintf(output, "159 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1739 "pnfasm.ypp"
    { 
						 fprintf(output, "160 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1748 "pnfasm.ypp"
    { fprintf(output, "161 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1749 "pnfasm.ypp"
    { fprintf(output, "161 0 0\n"); ;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1750 "pnfasm.ypp"
    { fprintf(output, "162 0 0\n"); ;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1751 "pnfasm.ypp"
    { fprintf(output, "163 0 0\n"); ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1752 "pnfasm.ypp"
    { fprintf(output, "163 1 0\n"); ;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1753 "pnfasm.ypp"
    { fprintf(output, "163 2 0\n"); ;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1754 "pnfasm.ypp"
    { fprintf(output, "163 3 0\n"); ;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1755 "pnfasm.ypp"
    { fprintf(output, "163 4 0\n"); ;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1756 "pnfasm.ypp"
    { fprintf(output, "164 0 0\n"); ;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1757 "pnfasm.ypp"
    { fprintf(output, "165 0 0\n"); ;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1758 "pnfasm.ypp"
    { fprintf(output, "166 0 0\n"); ;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1759 "pnfasm.ypp"
    { fprintf(output, "167 0 0\n"); ;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1760 "pnfasm.ypp"
    { fprintf(output, "168 0 0\n"); ;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1761 "pnfasm.ypp"
    { fprintf(output, "169 0 0\n"); ;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1762 "pnfasm.ypp"
    { fprintf(output, "170 0 0\n"); ;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1763 "pnfasm.ypp"
    { fprintf(output, "171 0 0\n"); ;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1764 "pnfasm.ypp"
    { fprintf(output, "172 0 0\n"); ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1765 "pnfasm.ypp"
    { fprintf(output, "173 0 0\n"); ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1766 "pnfasm.ypp"
    { fprintf(output, "174 0 0\n"); ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1767 "pnfasm.ypp"
    { fprintf(output, "175 0 0\n");	;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1768 "pnfasm.ypp"
    { fprintf(output, "176 0 0\n");	;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1769 "pnfasm.ypp"
    { fprintf(output, "177 0 0\n");	;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1770 "pnfasm.ypp"
    { fprintf(output, "178 0 0\n"); ;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1771 "pnfasm.ypp"
    { fprintf(output, "178 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str());	;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1772 "pnfasm.ypp"
    { fprintf(output, "178 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str());	;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1773 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "178 3 %i\n", ch);
						;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1778 "pnfasm.ypp"
    { 
						 fprintf(output, "178 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1787 "pnfasm.ypp"
    { fprintf(output, "179 0 0\n");	;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1788 "pnfasm.ypp"
    { fprintf(output, "180 0 0\n");	;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1789 "pnfasm.ypp"
    { fprintf(output, "181 0 0\n");	;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1790 "pnfasm.ypp"
    { fprintf(output, "182 0 0\n");	;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1791 "pnfasm.ypp"
    { fprintf(output, "183 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1792 "pnfasm.ypp"
    { fprintf(output, "184 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1793 "pnfasm.ypp"
    { fprintf(output, "185 0 0\n"); ;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1794 "pnfasm.ypp"
    { fprintf(output, "186 0 0\n"); ;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1795 "pnfasm.ypp"
    { fprintf(output, "187 0 0\n"); ;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1796 "pnfasm.ypp"
    { fprintf(output, "188 0 0\n"); ;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1797 "pnfasm.ypp"
    { fprintf(output, "189 0 0\n"); ;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1798 "pnfasm.ypp"
    { 
						 fprintf(output, "190 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1807 "pnfasm.ypp"
    { fprintf(output, "191 0 0\n"); ;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1808 "pnfasm.ypp"
    { 
						 fprintf(output, "192 4 ");
						 for (unsigned long i = 0; i < (yyvsp[(3) - (3)]).length(); ++i)
						 {
						  if ((yyvsp[(3) - (3)])[i] != '\"')
						   fprintf(output, "%d ", (int)((yyvsp[(3) - (3)])[i]));
						 }
						 fprintf(output, "0\n");
						;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1817 "pnfasm.ypp"
    { fprintf(output, "193 0 0\n"); ;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1818 "pnfasm.ypp"
    { fprintf(output, "194 0 0\n"); ;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1819 "pnfasm.ypp"
    { fprintf(output, "195 0 0\n"); ;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1820 "pnfasm.ypp"
    { fprintf(output, "196 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1821 "pnfasm.ypp"
    { fprintf(output, "197 0 0\n"); ;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1823 "pnfasm.ypp"
    {
			 			 if ((yyvsp[(3) - (3)]) == "true")
		 	  			  fprintf(output, "197 1 1\n");
			 			 else
			  			  fprintf(output, "197 1 0\n");
						;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1829 "pnfasm.ypp"
    { fprintf(output, "197 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1831 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "197 3 %i\n", ch);
						;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1837 "pnfasm.ypp"
    {		
						 fprintf(output, "197 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1843 "pnfasm.ypp"
    { fprintf(output, "198 0 0\n"); ;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1844 "pnfasm.ypp"
    { fprintf(output, "198 1 0\n"); ;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1845 "pnfasm.ypp"
    { fprintf(output, "198 2 0\n"); ;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1846 "pnfasm.ypp"
    { fprintf(output, "198 3 0\n"); ;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1847 "pnfasm.ypp"
    { fprintf(output, "198 4 0\n"); ;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1848 "pnfasm.ypp"
    { fprintf(output, "199 0 0\n"); ;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1849 "pnfasm.ypp"
    { fprintf(output, "199 1 0\n"); ;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1850 "pnfasm.ypp"
    { fprintf(output, "199 2 0\n"); ;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1851 "pnfasm.ypp"
    { fprintf(output, "199 3 0\n"); ;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1852 "pnfasm.ypp"
    { fprintf(output, "199 4 0\n"); ;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1853 "pnfasm.ypp"
    { fprintf(output, "200 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1854 "pnfasm.ypp"
    { fprintf(output, "201 0 0\n"); ;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1855 "pnfasm.ypp"
    { fprintf(output, "201 1 0\n"); ;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1856 "pnfasm.ypp"
    { fprintf(output, "201 2 0\n"); ;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1857 "pnfasm.ypp"
    { fprintf(output, "201 3 0\n"); ;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1858 "pnfasm.ypp"
    { fprintf(output, "201 4 0\n"); ;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1859 "pnfasm.ypp"
    { fprintf(output, "202 0 0\n"); ;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1860 "pnfasm.ypp"
    { fprintf(output, "202 1 0\n"); ;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1861 "pnfasm.ypp"
    { fprintf(output, "202 2 0\n"); ;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1862 "pnfasm.ypp"
    { fprintf(output, "202 3 0\n"); ;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1863 "pnfasm.ypp"
    { fprintf(output, "202 4 0\n"); ;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1864 "pnfasm.ypp"
    { fprintf(output, "203 0 0\n"); ;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1865 "pnfasm.ypp"
    { fprintf(output, "203 1 0\n"); ;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1866 "pnfasm.ypp"
    { fprintf(output, "203 2 0\n"); ;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1867 "pnfasm.ypp"
    { fprintf(output, "203 3 0\n"); ;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1868 "pnfasm.ypp"
    { fprintf(output, "203 4 0\n"); ;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1871 "pnfasm.ypp"
    {		
						 fprintf(output, "204 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1877 "pnfasm.ypp"
    { fprintf(output, "205 0 0\n"); ;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1878 "pnfasm.ypp"
    { fprintf(output, "206 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1879 "pnfasm.ypp"
    { fprintf(output, "207 0 0\n"); ;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1880 "pnfasm.ypp"
    { fprintf(output, "207 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1881 "pnfasm.ypp"
    { fprintf(output, "208 0 0\n"); ;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1882 "pnfasm.ypp"
    { fprintf(output, "209 0 0\n"); ;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1883 "pnfasm.ypp"
    { fprintf(output, "210 0 0\n"); ;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1884 "pnfasm.ypp"
    { fprintf(output, "211 0 0\n"); ;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1885 "pnfasm.ypp"
    { fprintf(output, "211 1 0\n"); ;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1886 "pnfasm.ypp"
    { fprintf(output, "211 2 0\n"); ;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1887 "pnfasm.ypp"
    { fprintf(output, "211 3 0\n"); ;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1888 "pnfasm.ypp"
    { fprintf(output, "211 4 0\n"); ;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1889 "pnfasm.ypp"
    { fprintf(output, "212 0 0\n"); ;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1890 "pnfasm.ypp"
    { fprintf(output, "212 1 0\n"); ;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1891 "pnfasm.ypp"
    { fprintf(output, "212 2 0\n"); ;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1892 "pnfasm.ypp"
    { fprintf(output, "212 3 0\n"); ;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1893 "pnfasm.ypp"
    { fprintf(output, "212 4 0\n"); ;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1894 "pnfasm.ypp"
    { fprintf(output, "213 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1895 "pnfasm.ypp"
    {		
						 fprintf(output, "213 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1901 "pnfasm.ypp"
    { fprintf(output, "214 0 0\n"); ;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1902 "pnfasm.ypp"
    { fprintf(output, "215 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1903 "pnfasm.ypp"
    { fprintf(output, "216 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1904 "pnfasm.ypp"
    { fprintf(output, "217 0 0\n"); ;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1905 "pnfasm.ypp"
    { fprintf(output, "218 0 0\n"); ;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1906 "pnfasm.ypp"
    { fprintf(output, "219 0 0\n"); ;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1907 "pnfasm.ypp"
    { fprintf(output, "220 0 0\n"); ;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1908 "pnfasm.ypp"
    { fprintf(output, "221 0 0\n"); ;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1909 "pnfasm.ypp"
    { fprintf(output, "222 0 0\n"); ;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1910 "pnfasm.ypp"
    { fprintf(output, "222 1 0\n"); ;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1911 "pnfasm.ypp"
    { fprintf(output, "222 2 0\n"); ;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1912 "pnfasm.ypp"
    { fprintf(output, "222 3 0\n"); ;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1913 "pnfasm.ypp"
    { fprintf(output, "222 4 0\n"); ;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1914 "pnfasm.ypp"
    { fprintf(output, "223 0 0\n"); ;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1915 "pnfasm.ypp"
    { fprintf(output, "223 1 0\n"); ;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1916 "pnfasm.ypp"
    { fprintf(output, "223 2 0\n"); ;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1917 "pnfasm.ypp"
    { fprintf(output, "223 3 0\n"); ;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1918 "pnfasm.ypp"
    { fprintf(output, "223 4 0\n"); ;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1919 "pnfasm.ypp"
    { fprintf(output, "224 0 0\n"); ;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1920 "pnfasm.ypp"
    { fprintf(output, "225 0 0\n"); ;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1922 "pnfasm.ypp"
    { /* Do nothing... */ ;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1923 "pnfasm.ypp"
    { fprintf(output, "%s %s %s\n", (yyvsp[(2) - (4)]).getString().c_str(), (yyvsp[(3) - (4)]).getString().c_str(), (yyvsp[(4) - (4)]).getString().c_str()); ;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1933 "pnfasm.ypp"
    { fprintf(output, "57 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1935 "pnfasm.ypp"
    {
			 			 if ((yyvsp[(3) - (3)]) == "true")
		 	  			  fprintf(output, "57 1 1\n");
			 			 else
			  			  fprintf(output, "57 1 0\n");
						;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1941 "pnfasm.ypp"
    { fprintf(output, "57 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1943 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "57 3 %i\n", ch);
						;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1949 "pnfasm.ypp"
    {		
						 fprintf(output, "57 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1955 "pnfasm.ypp"
    { fprintf(output, "57 1 0\n"); ;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1956 "pnfasm.ypp"
    { fprintf(output, "57 2 0\n"); ;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1957 "pnfasm.ypp"
    { fprintf(output, "57 3 0\n"); ;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1958 "pnfasm.ypp"
    { fprintf(output, "57 4 0\n"); ;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1960 "pnfasm.ypp"
    {		
						 fprintf(output, "57 0 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1967 "pnfasm.ypp"
    {		
						 fprintf(output, "57 1 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1974 "pnfasm.ypp"
    {		
						 fprintf(output, "57 2 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1981 "pnfasm.ypp"
    {		
						 fprintf(output, "57 3 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1990 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#include %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1991 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#include <%s>\n", (yyvsp[(2) - (4)]).getString().c_str()); ;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1992 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#import %s \n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1993 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#import <%s> \n", (yyvsp[(2) - (4)]).getString().c_str()); ;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1994 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#define %s %s\n", (yyvsp[(2) - (3)]).getString().c_str(), (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1995 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#macro %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1996 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#endm\n"); ;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1997 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#undef %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1998 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#ifdef %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1999 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#ifndef %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2000 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#else\n"); ;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2001 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#endif\n"); ;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2002 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_DATE()\n"); ;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 2003 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_TIME()\n"); ;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2004 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_LINE()\n"); ;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2005 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_FILE()\n"); ;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2006 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_CDATE()\n"); ;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2007 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_CTIME()\n"); ;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2008 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "\' %s\n", (yyvsp[(1) - (1)]).getString().c_str()); ;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2011 "pnfasm.ypp"
    { mode = 0; ;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2012 "pnfasm.ypp"
    { mode = 1; ;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2013 "pnfasm.ypp"
    { mode = 2; ;}
    break;



/* Line 1455 of yacc.c  */
#line 6584 "pnfasm.tab.cpp"
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
#line 2016 "pnfasm.ypp"

/* Additional C/C++ Code */
void yyerror(char const * c)
{
 cout << "* ERROR: " << yylineno << ": " << c << endl;
}
