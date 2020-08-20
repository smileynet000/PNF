
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
			 9. Fixed to add new instructions again...
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


/* Line 189 of yacc.c  */
#line 886 "pnfasm.tab.cpp"

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
     IFCALL2 = 500,
     IFCPARAMS2 = 501,
     IFECPARAMS2 = 502,
     IFECALL2 = 503,
     IFNCSYNCR = 504,
     IFNCFIND = 505,
     IFNCFRET = 506,
     IFNCFPARAM = 507,
     IFNCFBRET = 508,
     IFNCFBPARAM = 509,
     IFNCDEFAULT = 510,
     IFNCDEFAULT2 = 511,
     IFNCSDEFAULTV = 512,
     IFNCSDEFAULTV2 = 513,
     IFNCGDEFAULTV2 = 514,
     IFNCDEFAULTSYNC = 515,
     TVOID = 516,
     TBOOLEAN = 517,
     TNUMBER = 518,
     TCHARACTER = 519,
     TSTRING = 520,
     VOID = 521,
     BOOLEAN = 522,
     NUMBER = 523,
     CHARACTER = 524,
     STRING = 525
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
#line 1198 "pnfasm.tab.cpp"

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
#define YYLAST   1090

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  274
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  423
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1051

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   527

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     271,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     265,   266,   267,   268,   269,   270,   272,   273
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
    1457,  1461,  1465,  1469,  1473,  1477,  1481,  1485,  1489,  1493,
    1497,  1501,  1505,  1509,  1513,  1517,  1521,  1525,  1530,  1531,
    1535,  1539,  1543,  1547,  1551,  1555,  1559,  1563,  1567,  1571,
    1575,  1579,  1583,  1586,  1591,  1594,  1599,  1603,  1606,  1608,
    1611,  1614,  1617,  1619,  1621,  1623,  1625,  1627,  1629,  1631,
    1633,  1635,  1637,  1639
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     275,     0,    -1,    -1,   275,   276,    -1,   271,    -1,   277,
      -1,   278,    -1,   279,    -1,   280,    -1,   281,    -1,     1,
      -1,    25,   261,   266,    -1,    25,   261,   268,    -1,    26,
     261,   266,    -1,    27,   265,   270,    -1,    28,   261,   268,
      -1,    29,   261,   266,    -1,    30,   261,   266,    -1,    30,
     262,   267,    -1,    30,   263,   268,    -1,    30,   264,   269,
      -1,    30,   265,   270,    -1,    31,   261,   266,    -1,    31,
     262,   267,    -1,    31,   263,   268,    -1,    31,   264,   269,
      -1,    31,   265,   270,    -1,    32,   262,   266,    -1,    32,
     263,   266,    -1,    32,   264,   266,    -1,    32,   265,   266,
      -1,    33,   262,   268,    -1,    33,   263,   268,    -1,    33,
     264,   268,    -1,    33,   265,   268,    -1,    34,   261,   268,
      -1,    35,   262,   268,    -1,    35,   263,   268,    -1,    35,
     264,   268,    -1,    35,   265,   268,    -1,    36,   261,   268,
      -1,    37,   262,   266,    -1,    37,   263,   266,    -1,    37,
     264,   266,    -1,    37,   265,   266,    -1,    38,   261,   266,
      -1,    39,   262,   266,    -1,    39,   263,   266,    -1,    39,
     264,   266,    -1,    39,   265,   266,    -1,    40,   261,   266,
      -1,    41,   262,   268,    -1,    41,   263,   268,    -1,    41,
     264,   268,    -1,    41,   265,   268,    -1,    42,   261,   266,
      -1,    42,   263,   268,    -1,    43,   262,   268,    -1,    43,
     263,   268,    -1,    43,   264,   268,    -1,    43,   265,   268,
      -1,    44,   261,   266,    -1,    44,   263,   268,    -1,    45,
     261,   266,    -1,    46,   261,   266,    -1,    46,   262,   266,
      -1,    46,   263,   266,    -1,    46,   264,   266,    -1,    46,
     265,   266,    -1,    47,   261,   266,    -1,    47,   262,   266,
      -1,    47,   263,   266,    -1,    47,   264,   266,    -1,    47,
     265,   266,    -1,    48,   261,   266,    -1,    48,   263,   268,
      -1,    48,   264,   269,    -1,    48,   265,   270,    -1,    49,
     261,   266,    -1,    49,   263,   268,    -1,    50,   261,   266,
      -1,    50,   263,   268,    -1,    51,   261,   266,    -1,    51,
     263,   268,    -1,    52,   261,   266,    -1,    52,   263,   268,
      -1,    53,   261,   266,    -1,    53,   263,   268,    -1,    54,
     261,   266,    -1,    54,   263,   268,    -1,    55,   261,   266,
      -1,    56,   261,   266,    -1,    57,   261,   266,    -1,    58,
     261,   266,    -1,    59,   261,   266,    -1,    60,   261,   266,
      -1,    61,   261,   266,    -1,    62,   261,   266,    -1,    63,
     261,   266,    -1,    64,   261,   266,    -1,    65,   261,   266,
      -1,    66,   261,   268,    -1,    67,   261,   268,    -1,    68,
     261,   268,    -1,    69,   261,   268,    -1,    70,   261,   268,
      -1,    71,   261,   268,    -1,    71,   265,   270,    -1,    72,
     261,   268,    -1,    72,   265,   270,    -1,    73,   261,   268,
      -1,    73,   265,   270,    -1,    74,   261,   268,    -1,    74,
     265,   270,    -1,    75,   261,   268,    -1,    75,   265,   270,
      -1,    76,   261,   266,    -1,    77,   261,   266,    -1,    78,
     261,   266,    -1,    79,   261,   268,    -1,    80,   261,   268,
      -1,    80,   265,   270,    -1,    81,   261,   266,    -1,    83,
     261,   266,    -1,    83,   265,   270,    -1,    84,   261,   266,
      -1,    84,   262,   267,    -1,    84,   263,   268,    -1,    84,
     264,   269,    -1,    84,   265,   270,    -1,    85,   261,   266,
      -1,    85,   262,   267,    -1,    85,   263,   268,    -1,    85,
     264,   269,    -1,    85,   265,   270,    -1,    86,   261,   266,
      -1,    87,   261,   266,    -1,    88,   261,   268,    -1,    89,
     261,   268,    -1,    90,   261,   266,    -1,    91,   261,   268,
      -1,    92,   261,   266,    -1,    93,   261,   268,    -1,    94,
     261,   266,    -1,    95,   261,   268,    -1,    96,   261,   266,
      -1,    97,   261,   268,    -1,    98,   261,   266,    -1,    99,
     261,   268,    -1,   100,   261,   266,    -1,   101,   261,   268,
      -1,   102,   261,   266,    -1,   103,   261,   268,    -1,   104,
     261,   266,    -1,   105,   261,   268,    -1,   106,   261,   266,
      -1,   107,   261,   268,    -1,   108,   261,   266,    -1,   109,
     261,   268,    -1,   110,   261,   268,    -1,   111,   261,   268,
      -1,   112,   261,   268,    -1,   113,   261,   268,    -1,   114,
     261,   266,    -1,   115,   261,   266,    -1,   116,   261,   266,
      -1,   117,   261,   266,    -1,   117,   262,   267,    -1,   117,
     263,   268,    -1,   117,   264,   269,    -1,   117,   265,   270,
      -1,   118,   261,   266,    -1,   119,   261,   266,    -1,   120,
     261,   268,    -1,   121,   261,   266,    -1,   122,   261,   266,
      -1,   123,   261,   268,    -1,   124,   261,   268,    -1,   125,
     261,   268,    -1,   126,   261,   266,    -1,   127,   261,   266,
      -1,   128,   261,   266,    -1,   129,   261,   266,    -1,   130,
     261,   266,    -1,   131,   261,   266,    -1,   132,   261,   266,
      -1,   133,   261,   268,    -1,   133,   262,   267,    -1,   133,
     263,   268,    -1,   133,   264,   269,    -1,   133,   265,   270,
      -1,   134,   261,   268,    -1,   134,   262,   267,    -1,   134,
     263,   268,    -1,   134,   264,   269,    -1,   134,   265,   270,
      -1,   135,   261,   266,    -1,   136,   261,   266,    -1,   137,
     263,   268,    -1,   138,   263,   268,    -1,   139,   265,   270,
      -1,   140,   265,   270,    -1,   141,   265,   270,    -1,   142,
     261,   266,    -1,   142,   265,   270,    -1,   143,   261,   266,
      -1,   143,   265,   270,    -1,   144,   262,   266,    -1,   144,
     263,   266,    -1,   144,   264,   266,    -1,   144,   265,   266,
      -1,   145,   261,   266,    -1,   145,   262,   267,    -1,   145,
     263,   268,    -1,   145,   264,   269,    -1,   145,   265,   270,
      -1,   146,   261,   266,    -1,   146,   262,   267,    -1,   146,
     263,   268,    -1,   146,   264,   269,    -1,   146,   265,   270,
      -1,   147,   261,   266,    -1,   148,   261,   266,    -1,   149,
     261,   266,    -1,   150,   261,   266,    -1,   151,   261,   266,
      -1,   152,   265,   270,    -1,   153,   263,   268,    -1,   154,
     263,   268,    -1,   155,   261,   266,    -1,   156,   265,   270,
      -1,   157,   263,   268,    -1,   158,   265,   270,    -1,   159,
     265,   270,    -1,   160,   265,   270,    -1,   161,   261,   268,
      -1,   162,   261,   268,    -1,   163,   261,   268,    -1,   164,
     261,   268,    -1,   165,   261,   268,    -1,   166,   265,   270,
      -1,   167,   263,   268,    -1,   168,   263,   268,    -1,   169,
     261,   266,    -1,   170,   265,   270,    -1,   171,   265,   270,
      -1,   172,   265,   270,    -1,   173,   263,   268,    -1,   174,
     265,   270,    -1,   175,   265,   270,    -1,   176,   261,   266,
      -1,   177,   265,   270,    -1,   178,   265,   270,    -1,   179,
     265,   270,    -1,   180,   265,   270,    -1,   181,   261,   266,
      -1,   182,   261,   266,    -1,   183,   265,   270,    -1,   184,
     263,   268,    -1,   185,   265,   270,    -1,   186,   263,   268,
      -1,   186,   261,   266,    -1,   187,   261,   266,    -1,   188,
     261,   266,    -1,   188,   262,   266,    -1,   188,   263,   266,
      -1,   188,   264,   266,    -1,   188,   265,   266,    -1,   189,
     261,   266,    -1,   190,   261,   266,    -1,   191,   261,   266,
      -1,   192,   261,   266,    -1,   193,   261,   266,    -1,   194,
     261,   266,    -1,   195,   261,   266,    -1,   196,   261,   266,
      -1,   197,   261,   266,    -1,   198,   261,   266,    -1,   199,
     261,   266,    -1,   200,   261,   266,    -1,   201,   261,   266,
      -1,   202,   261,   266,    -1,   203,   261,   266,    -1,   203,
     262,   267,    -1,   203,   263,   268,    -1,   203,   264,   269,
      -1,   203,   265,   270,    -1,   204,   261,   266,    -1,   205,
     261,   266,    -1,   206,   261,   266,    -1,   207,   261,   266,
      -1,   208,   263,   268,    -1,   209,   263,   268,    -1,   210,
     261,   266,    -1,   211,   261,   266,    -1,   212,   261,   266,
      -1,   213,   261,   266,    -1,   214,   261,   266,    -1,   215,
     265,   270,    -1,   216,   261,   266,    -1,   217,   265,   270,
      -1,   218,   261,   266,    -1,   219,   261,   266,    -1,   220,
     261,   266,    -1,   221,   263,   268,    -1,   222,   261,   266,
      -1,   222,   262,   267,    -1,   222,   263,   268,    -1,   222,
     264,   269,    -1,   222,   265,   270,    -1,   223,   261,   266,
      -1,   223,   262,   266,    -1,   223,   263,   266,    -1,   223,
     264,   266,    -1,   223,   265,   266,    -1,   224,   261,   266,
      -1,   224,   262,   266,    -1,   224,   263,   266,    -1,   224,
     264,   266,    -1,   224,   265,   266,    -1,   225,   263,   268,
      -1,   226,   261,   266,    -1,   226,   262,   266,    -1,   226,
     263,   266,    -1,   226,   264,   266,    -1,   226,   265,   266,
      -1,   227,   261,   266,    -1,   227,   262,   266,    -1,   227,
     263,   266,    -1,   227,   264,   266,    -1,   227,   265,   266,
      -1,   228,   261,   266,    -1,   228,   262,   266,    -1,   228,
     263,   266,    -1,   228,   264,   266,    -1,   228,   265,   266,
      -1,   229,   265,   270,    -1,   230,   261,   266,    -1,   231,
     263,   268,    -1,   232,   261,   266,    -1,   232,   263,   268,
      -1,   233,   261,   266,    -1,   234,   261,   266,    -1,   235,
     261,   266,    -1,   236,   261,   266,    -1,   236,   262,   266,
      -1,   236,   263,   266,    -1,   236,   264,   266,    -1,   236,
     265,   266,    -1,   237,   261,   266,    -1,   237,   262,   266,
      -1,   237,   263,   266,    -1,   237,   264,   266,    -1,   237,
     265,   266,    -1,   238,   263,   268,    -1,   238,   265,   270,
      -1,   239,   261,   266,    -1,   240,   263,   268,    -1,   241,
     263,   268,    -1,   242,   261,   266,    -1,   243,   261,   266,
      -1,   244,   261,   266,    -1,   249,   261,   266,    -1,   250,
     261,   266,    -1,   251,   261,   266,    -1,   251,   262,   266,
      -1,   251,   263,   266,    -1,   251,   264,   266,    -1,   251,
     265,   266,    -1,   252,   261,   266,    -1,   252,   262,   266,
      -1,   252,   263,   266,    -1,   252,   264,   266,    -1,   252,
     265,   266,    -1,   253,   261,   266,    -1,   254,   261,   266,
      -1,   255,   261,   266,    -1,   256,   261,   266,    -1,   257,
     261,   266,    -1,   257,   262,   266,    -1,   257,   263,   266,
      -1,   257,   264,   266,    -1,   257,   265,   266,    -1,   258,
     261,   266,    -1,   259,   261,   266,    -1,   260,   261,   266,
      -1,     3,   261,   266,    -1,     4,   268,   268,   268,    -1,
      -1,    82,   261,   266,    -1,    82,   262,   267,    -1,    82,
     263,   268,    -1,    82,   264,   269,    -1,    82,   265,   270,
      -1,    82,   262,   266,    -1,    82,   263,   266,    -1,    82,
     264,   266,    -1,    82,   265,   266,    -1,    82,   261,   270,
      -1,    82,   262,   270,    -1,    82,   263,   270,    -1,    82,
     264,   270,    -1,     8,   270,    -1,     8,   272,   270,   273,
      -1,     9,   270,    -1,     9,   272,   270,   273,    -1,    10,
     270,   270,    -1,    11,   270,    -1,    12,    -1,    13,   270,
      -1,    14,   270,    -1,    15,   270,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    23,    -1,    24,    -1,     5,    -1,     6,    -1,     7,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1096,  1096,  1097,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1109,  1110,  1111,  1112,  1120,  1121,  1122,  1123,  1129,
    1130,  1135,  1144,  1145,  1151,  1152,  1157,  1166,  1167,  1168,
    1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,
    1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,
    1209,  1210,  1211,  1212,  1213,  1214,  1215,  1220,  1226,  1227,
    1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,
    1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,
    1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1261,  1262,
    1269,  1270,  1277,  1278,  1285,  1286,  1293,  1294,  1295,  1296,
    1297,  1298,  1305,  1307,  1308,  1314,  1315,  1321,  1322,  1327,
    1337,  1338,  1344,  1345,  1350,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1399,  1400,
    1406,  1416,  1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,
    1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,  1439,  1440,
    1446,  1456,  1457,  1464,  1465,  1471,  1481,  1482,  1483,  1484,
    1485,  1495,  1505,  1515,  1516,  1526,  1527,  1537,  1538,  1539,
    1540,  1541,  1542,  1548,  1549,  1554,  1563,  1564,  1570,  1571,
    1576,  1585,  1586,  1587,  1588,  1589,  1590,  1599,  1600,  1601,
    1602,  1611,  1612,  1621,  1630,  1639,  1640,  1641,  1642,  1643,
    1644,  1653,  1654,  1655,  1656,  1665,  1674,  1683,  1684,  1693,
    1702,  1703,  1712,  1721,  1730,  1739,  1740,  1741,  1750,  1751,
    1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,
    1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,
    1780,  1781,  1782,  1783,  1784,  1785,  1790,  1799,  1800,  1801,
    1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1819,
    1820,  1829,  1830,  1831,  1832,  1833,  1834,  1841,  1842,  1848,
    1855,  1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,
    1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,  1874,
    1875,  1876,  1877,  1878,  1879,  1880,  1882,  1889,  1890,  1891,
    1892,  1893,  1894,  1895,  1896,  1897,  1898,  1899,  1900,  1901,
    1902,  1903,  1904,  1905,  1906,  1907,  1913,  1914,  1915,  1916,
    1917,  1918,  1919,  1920,  1921,  1922,  1923,  1924,  1925,  1926,
    1927,  1928,  1929,  1930,  1931,  1932,  1933,  1934,  1935,  1936,
    1937,  1938,  1939,  1940,  1941,  1942,  1943,  1944,  1951,  1954,
    1955,  1962,  1963,  1969,  1976,  1977,  1978,  1979,  1980,  1987,
    1994,  2001,  2011,  2012,  2013,  2014,  2015,  2016,  2017,  2018,
    2019,  2020,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2032,  2033,  2034
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
  "IFNCGDEF", "IFNCPOINT", "IFNCLENGTH", "IFCALL2", "IFCPARAMS2",
  "IFECPARAMS2", "IFECALL2", "IFNCSYNCR", "IFNCFIND", "IFNCFRET",
  "IFNCFPARAM", "IFNCFBRET", "IFNCFBPARAM", "IFNCDEFAULT", "IFNCDEFAULT2",
  "IFNCSDEFAULTV", "IFNCSDEFAULTV2", "IFNCGDEFAULTV2", "IFNCDEFAULTSYNC",
  "TVOID", "TBOOLEAN", "TNUMBER", "TCHARACTER", "TSTRING", "VOID",
  "BOOLEAN", "NUMBER", "CHARACTER", "STRING", "'\\n'", "\"<\"", "\">\"",
  "$accept", "input", "line", "instruction", "pinstruction", "variable",
  "pp", "directive", 0
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
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,    10,   526,   527
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   274,   275,   275,   276,   276,   276,   276,   276,   276,
     276,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   278,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   281,   281,   281
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
       2,     0,     1,    10,     0,     0,   421,   422,   423,     0,
       0,     0,     0,   408,     0,     0,     0,   412,   413,   414,
     415,   416,   417,   418,   419,   420,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     4,     3,
       5,     6,     7,     8,     9,     0,     0,   402,     0,   404,
       0,     0,   407,   409,   410,   411,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   386,     0,     0,     0,   406,
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
     121,   122,   389,   398,   394,   390,   399,   395,   391,   400,
     396,   392,   401,   397,   393,   123,   124,   125,   126,   127,
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
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   387,   403,
     405
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   259,   260,   261,   262,   263,   264
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -260
static const yytype_int16 yypact[] =
{
    -260,     0,  -260,  -260,  -259,    -7,  -260,  -260,  -260,   155,
     188,   130,   160,  -260,   210,   216,   217,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,   221,   223,   220,   227,
     228,     1,    11,   -17,     5,   229,   171,   230,   175,   231,
     179,   232,   183,   168,   187,   196,   233,    16,    21,   131,
     200,   201,   204,   205,   208,   209,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   145,   148,   150,   151,   153,   250,   251,   252,
     253,   156,   254,    26,   158,    31,    36,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    41,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,    46,    51,   301,   302,   303,   304,
     305,   306,   307,   159,   161,   191,    56,    61,   308,   312,
     313,   314,   315,   316,   317,   319,   318,   320,   321,   322,
     323,   324,   325,   329,   330,   331,   332,   333,   334,   336,
     335,   337,   338,   339,   342,   341,   343,   340,   344,   345,
     346,   347,   352,   353,   350,   354,   351,   212,   357,    66,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,    71,   372,   373,   374,   375,   376,
     377,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     390,   392,   391,    76,    81,    86,   393,    91,    96,   101,
     394,   396,   395,   213,   399,   400,   401,   106,   111,   214,
     402,   403,   404,   407,   408,   409,   410,   411,   116,   121,
     412,   413,   414,   415,   126,   416,   417,   418,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,   311,   310,  -260,   378,  -260,
     419,   420,  -260,  -260,  -260,  -260,   215,   328,   421,   327,
     389,   398,   211,   397,   423,   424,   422,   379,   425,   426,
     427,   430,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   463,
     462,   464,   465,   466,   467,   470,   469,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   431,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   461,   517,   518,   519,   520,   521,   522,   523,   524,
     527,   529,   530,   531,   532,   528,   535,   127,   132,   135,
     138,   162,   536,   533,   538,   539,   537,   540,   541,   542,
     543,   544,   545,   546,   547,   549,   550,   551,   554,   553,
     556,   555,   558,   557,   560,   559,   562,   561,   564,   563,
     566,   565,   568,   567,   570,   569,   572,   571,   573,   574,
     575,   576,   579,   580,   581,   582,   583,   584,   548,   585,
     587,   588,   589,   590,   592,   591,   593,   594,   597,   598,
     599,   600,   601,   602,   603,   604,   606,   607,   605,   608,
     609,   612,   613,   611,   614,   610,   616,   615,   617,   618,
     619,   620,   621,   622,   625,   623,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   644,   646,   647,   648,   645,   649,   650,   653,   651,
     652,   654,   655,   656,   659,   660,   661,   662,   663,   664,
     665,   667,   657,   666,   668,   669,   672,   671,   673,   676,
     674,   675,   677,   678,   680,   683,   681,   682,   684,   686,
     685,   689,   690,   691,   692,   693,   694,   695,   696,   697,
     698,   699,   700,   701,   702,   703,   704,   705,   706,   707,
     708,   709,   670,   710,   711,   712,   713,   715,   717,   718,
     719,   720,   723,   724,   725,   726,   727,   716,   728,   729,
     730,   731,   732,   733,   734,   735,   736,   737,   738,   739,
     741,   743,   744,   745,   746,   747,   748,   749,   750,   751,
     752,   754,   755,   756,   757,   758,   759,   760,   761,   762,
     763,   764,   765,   766,   767,   768,   769,   771,   770,   772,
     775,   776,   777,   778,   779,   780,   781,   782,   783,   784,
     785,   786,   787,   788,   789,   791,   790,   792,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   805,   806,
     807,   808,   809,   810,   811,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   821,  -260,   822,   429,   534,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
       2,     3,   265,     4,     5,     6,     7,     8,     9,    10,
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
     241,   242,   243,   244,   245,   291,   292,   293,   294,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   266,   281,   282,   283,   284,   285,   295,   296,   297,
     298,   258,   286,   287,   288,   289,   290,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   387,   388,   389,
     390,   391,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   435,   436,   437,   438,   439,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   532,   533,   534,
     535,   536,   551,   552,   553,   554,   555,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   647,   648,   649,
     650,   651,   338,   772,   339,   340,   341,   773,   774,   775,
     271,   777,   776,   778,   780,   779,   370,   781,   782,   372,
     371,   374,   376,   373,   378,   375,   377,   384,   379,   392,
     472,   385,   474,   393,   473,   267,   475,   268,   783,   319,
     272,   320,   784,   300,   301,   302,   303,   305,   306,   307,
     308,   310,   311,   312,   313,   315,   316,   317,   318,   321,
     322,   323,   324,   476,   477,   478,   479,   325,   269,   326,
     270,   342,   344,   343,   345,   346,   348,   347,   349,   350,
     352,   351,   353,   529,   608,   530,   609,   623,   667,   624,
     273,   660,   276,   661,   277,   278,   274,   275,   279,   280,
     299,   304,   309,   314,   327,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   380,   381,   382,   383,   386,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   465,   466,     0,     0,   467,   468,     0,   490,
     469,   470,   471,   491,   492,   493,   494,   655,   656,   498,
     496,   495,   497,     0,   500,   499,   504,   501,   502,   503,
     505,   506,   507,   508,   662,   664,   512,   510,   509,   511,
       0,   519,   513,   514,   515,   516,   517,     0,   518,   520,
     521,   522,   523,   524,   525,   526,   528,   527,   531,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   556,   557,   558,   559,     0,     0,   560,
     561,   562,   563,   564,   565,   566,   672,   568,   657,   570,
     567,   571,   569,   572,   573,   665,   589,   606,   607,   605,
     610,   611,   612,   625,   666,   668,   626,   627,   628,   629,
     630,   631,   632,   643,   644,   645,   646,   652,   653,   654,
       0,     0,     0,     0,     0,     0,     0,     0,   671,   658,
     659,   663,   669,   673,   670,   674,   676,   675,   677,   678,
     679,   726,  1049,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,     0,     0,   700,   701,   702,   703,   704,
     705,   756,   706,   707,   708,   709,   710,   711,   712,   713,
     714,   715,   716,   717,   718,   719,   720,   721,   722,   723,
       0,     0,   724,   727,   725,   729,   728,   731,   730,   733,
     732,   735,   734,   737,   736,   739,   738,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,     0,     0,   750,
     751,   752,   753,   754,   755,   757,     0,   759,   758,   761,
     760,   763,   762,   765,   764,   766,   767,     0,   770,   768,
     769,   771,   785,   786,   787,   789,   788,  1050,   792,   790,
     793,   791,   794,   797,   795,   798,   796,   831,   799,   800,
     801,   802,   803,   804,   805,   806,   807,   808,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   818,   819,   820,
       0,   821,   822,   823,   824,   825,   826,   827,   828,     0,
     829,     0,   830,   833,   834,   832,   836,   835,   837,   838,
       0,   839,   840,   841,   842,   843,   844,   845,   846,   847,
       0,     0,   848,   849,   851,   850,   858,   853,   852,   854,
     856,   855,   859,   860,   857,   861,     0,   865,   862,   863,
     864,   867,   866,   868,   869,   870,   871,   872,   873,     0,
     874,     0,   875,   878,   876,   879,   877,   880,   883,   881,
     884,   882,   885,   886,   887,   888,     0,   889,   890,   891,
     893,   892,     0,   905,   894,   895,   896,   897,   898,   899,
     900,   901,     0,   903,   902,   904,   906,   945,   907,   908,
     909,   910,   912,   911,   913,   914,   917,   915,   916,   918,
     920,   919,   922,   923,   921,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,     0,     0,   946,   949,
     947,   950,   948,   951,   952,     0,   960,   953,   954,   955,
     956,   957,   958,   959,   961,     0,   963,   964,   965,   962,
     967,   966,   968,     0,   969,   972,   970,   973,   971,   974,
     975,   976,   977,   978,   979,   980,   981,     0,   983,   982,
     984,   985,   986,   987,   988,   989,   990,   991,   992,   993,
     994,   995,   996,   997,     0,   999,  1001,     0,   998,  1000,
    1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,
    1012,  1013,  1014,  1015,     0,     0,  1016,  1018,  1019,  1017,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,     0,     0,
    1048
};

static const yytype_int16 yycheck[] =
{
       0,     1,   261,     3,     4,     5,     6,     7,     8,     9,
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
     240,   241,   242,   243,   244,   262,   263,   264,   265,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   268,   261,   262,   263,   264,   265,   262,   263,   264,
     265,   271,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   262,   263,   264,   265,   261,   262,   263,
     264,   265,   261,   266,   263,   264,   265,   270,   266,   267,
     270,   266,   270,   268,   266,   270,   261,   269,   270,   261,
     265,   261,   261,   265,   261,   265,   265,   261,   265,   261,
     261,   265,   261,   265,   265,   270,   265,   272,   266,   261,
     270,   263,   270,   262,   263,   264,   265,   262,   263,   264,
     265,   262,   263,   264,   265,   262,   263,   264,   265,   262,
     263,   264,   265,   262,   263,   264,   265,   261,   270,   263,
     272,   261,   261,   263,   263,   261,   261,   263,   263,   261,
     261,   263,   263,   261,   261,   263,   263,   263,   267,   265,
     270,   266,   261,   268,   261,   265,   270,   270,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,    -1,    -1,   263,   263,    -1,   261,
     265,   265,   265,   261,   261,   261,   261,   266,   268,   261,
     263,   265,   263,    -1,   263,   265,   261,   265,   265,   265,
     261,   261,   261,   261,   266,   268,   261,   263,   265,   263,
      -1,   261,   265,   265,   265,   263,   265,    -1,   265,   265,
     265,   265,   265,   261,   261,   265,   265,   263,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,    -1,    -1,   263,
     263,   261,   261,   261,   261,   261,   267,   261,   270,   261,
     265,   261,   265,   261,   263,   266,   263,   261,   263,   265,
     261,   261,   261,   261,   266,   268,   263,   263,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,   270,
     270,   270,   269,   268,   270,   269,   266,   270,   266,   266,
     266,   270,   273,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,    -1,    -1,   268,   268,   268,   268,   266,
     268,   270,   268,   268,   268,   268,   266,   268,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
      -1,    -1,   268,   266,   269,   266,   268,   266,   268,   266,
     268,   266,   268,   266,   268,   266,   268,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,    -1,    -1,   268,
     268,   268,   268,   268,   268,   268,    -1,   268,   270,   268,
     270,   268,   270,   266,   270,   266,   266,    -1,   270,   268,
     268,   266,   266,   270,   266,   268,   267,   273,   266,   269,
     267,   270,   268,   266,   269,   266,   270,   269,   268,   268,
     266,   268,   266,   268,   266,   268,   266,   268,   266,   268,
     266,   268,   266,   268,   266,   268,   266,   268,   266,   268,
      -1,   268,   268,   268,   268,   266,   266,   266,   266,    -1,
     267,    -1,   268,   266,   266,   270,   266,   268,   266,   268,
      -1,   268,   268,   266,   266,   266,   266,   266,   266,   266,
      -1,    -1,   268,   267,   269,   268,   266,   268,   270,   267,
     269,   268,   266,   268,   270,   268,    -1,   266,   270,   270,
     270,   266,   270,   270,   266,   266,   266,   266,   266,    -1,
     267,    -1,   268,   266,   269,   267,   270,   268,   266,   269,
     266,   270,   266,   266,   266,   270,    -1,   268,   268,   266,
     268,   270,    -1,   266,   270,   270,   270,   268,   268,   268,
     268,   268,    -1,   268,   270,   268,   270,   267,   270,   270,
     268,   270,   266,   270,   270,   270,   266,   270,   270,   266,
     268,   270,   266,   268,   270,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,    -1,    -1,   268,   266,
     269,   266,   270,   266,   266,    -1,   270,   268,   268,   266,
     266,   266,   266,   266,   266,    -1,   266,   266,   266,   270,
     266,   268,   267,    -1,   268,   266,   269,   266,   270,   266,
     266,   266,   266,   266,   266,   266,   266,    -1,   266,   268,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,    -1,   266,   266,    -1,   270,   268,
     268,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,    -1,    -1,   268,   266,   268,   270,
     268,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,    -1,    -1,
     268
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   275,     0,     1,     3,     4,     5,     6,     7,     8,
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
     239,   240,   241,   242,   243,   244,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   271,   276,
     277,   278,   279,   280,   281,   261,   268,   270,   272,   270,
     272,   270,   270,   270,   270,   270,   261,   261,   265,   261,
     261,   261,   262,   263,   264,   265,   261,   262,   263,   264,
     265,   262,   263,   264,   265,   262,   263,   264,   265,   261,
     262,   263,   264,   265,   261,   262,   263,   264,   265,   261,
     262,   263,   264,   265,   261,   262,   263,   264,   265,   261,
     263,   262,   263,   264,   265,   261,   263,   261,   261,   262,
     263,   264,   265,   261,   262,   263,   264,   265,   261,   263,
     264,   265,   261,   263,   261,   263,   261,   263,   261,   263,
     261,   263,   261,   263,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   265,   261,   265,   261,   265,   261,   265,   261,   265,
     261,   261,   261,   261,   261,   265,   261,   261,   262,   263,
     264,   265,   261,   265,   261,   262,   263,   264,   265,   261,
     262,   263,   264,   265,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   262,   263,   264,   265,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   262,   263,   264,   265,
     261,   262,   263,   264,   265,   261,   261,   263,   263,   265,
     265,   265,   261,   265,   261,   265,   262,   263,   264,   265,
     261,   262,   263,   264,   265,   261,   262,   263,   264,   265,
     261,   261,   261,   261,   261,   265,   263,   263,   261,   265,
     263,   265,   265,   265,   261,   261,   261,   261,   261,   265,
     263,   263,   261,   265,   265,   265,   263,   265,   265,   261,
     265,   265,   265,   265,   261,   261,   265,   263,   265,   261,
     263,   261,   261,   262,   263,   264,   265,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   262,   263,   264,   265,   261,   261,   261,   261,
     263,   263,   261,   261,   261,   261,   261,   265,   261,   265,
     261,   261,   261,   263,   261,   262,   263,   264,   265,   261,
     262,   263,   264,   265,   261,   262,   263,   264,   265,   263,
     261,   262,   263,   264,   265,   261,   262,   263,   264,   265,
     261,   262,   263,   264,   265,   265,   261,   263,   261,   263,
     261,   261,   261,   261,   262,   263,   264,   265,   261,   262,
     263,   264,   265,   263,   265,   261,   263,   263,   261,   261,
     261,   261,   261,   261,   262,   263,   264,   265,   261,   262,
     263,   264,   265,   261,   261,   261,   261,   261,   262,   263,
     264,   265,   261,   261,   261,   266,   268,   270,   270,   270,
     266,   268,   266,   270,   268,   266,   266,   267,   268,   269,
     270,   266,   267,   268,   269,   270,   266,   266,   266,   266,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     268,   268,   268,   268,   266,   268,   268,   268,   268,   268,
     266,   268,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   268,   269,   270,   266,   268,   266,
     268,   266,   268,   266,   268,   266,   268,   266,   268,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     268,   268,   268,   268,   268,   268,   270,   268,   270,   268,
     270,   268,   270,   268,   270,   266,   266,   266,   268,   268,
     270,   266,   266,   270,   266,   267,   270,   266,   268,   270,
     266,   269,   270,   266,   270,   266,   270,   266,   267,   268,
     269,   270,   266,   267,   268,   269,   270,   266,   266,   268,
     268,   266,   268,   266,   268,   266,   268,   266,   268,   266,
     268,   266,   268,   266,   268,   266,   268,   266,   268,   266,
     268,   268,   268,   268,   268,   266,   266,   266,   266,   267,
     268,   269,   270,   266,   266,   268,   266,   266,   268,   268,
     268,   266,   266,   266,   266,   266,   266,   266,   268,   267,
     268,   269,   270,   268,   267,   268,   269,   270,   266,   266,
     268,   268,   270,   270,   270,   266,   270,   266,   270,   266,
     266,   266,   266,   266,   267,   268,   269,   270,   266,   267,
     268,   269,   270,   266,   266,   266,   266,   266,   270,   268,
     268,   266,   270,   268,   270,   270,   270,   268,   268,   268,
     268,   268,   270,   268,   268,   266,   270,   270,   270,   268,
     270,   270,   266,   270,   270,   270,   270,   266,   266,   270,
     268,   270,   266,   268,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   267,   268,   269,   270,   266,
     266,   266,   266,   268,   268,   266,   266,   266,   266,   266,
     270,   266,   270,   266,   266,   266,   268,   266,   267,   268,
     269,   270,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   268,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   270,   266,
     268,   266,   268,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   268,   270,   266,   268,
     268,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   268,   273,
     273
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
#line 1106 "pnfasm.ypp"
    { yyerrok; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 1109 "pnfasm.ypp"
    { fprintf(output, "0 0 0\n"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 1110 "pnfasm.ypp"
    { fprintf(output, "0 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 1111 "pnfasm.ypp"
    { fprintf(output, "1 0 0\n"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 1113 "pnfasm.ypp"
    {
		 fprintf(output, "2 4 ");

		 for (int i = 1; (yyvsp[(3) - (3)])[i] != '\"'; ++i)
                  fprintf(output, "%i ", (yyvsp[(3) - (3)])[i]);
		 fprintf(output, "0\n");
		;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 1120 "pnfasm.ypp"
    { fprintf(output, "3 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 1121 "pnfasm.ypp"
    { fprintf(output, "4 0 0\n"); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 1122 "pnfasm.ypp"
    { fprintf(output, "5 0 0\n"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 1123 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "5 1 1\n");
						 else
						  fprintf(output, "5 1 0\n");
					        ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 1129 "pnfasm.ypp"
    { fprintf(output, "5 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 1130 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "5 3 %i\n", ch);
						;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 1135 "pnfasm.ypp"
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
#line 1144 "pnfasm.ypp"
    { fprintf(output, "6 0 0\n"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 1145 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "6 1 1\n");
						 else
						  fprintf(output, "6 1 0\n");
					        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 1151 "pnfasm.ypp"
    { fprintf(output, "6 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1152 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "6 3 %i\n", ch);
						;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 1157 "pnfasm.ypp"
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
#line 1166 "pnfasm.ypp"
    { fprintf(output, "7 1 0\n"); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1167 "pnfasm.ypp"
    { fprintf(output, "7 2 0\n"); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1168 "pnfasm.ypp"
    { fprintf(output, "7 3 0\n"); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1169 "pnfasm.ypp"
    { fprintf(output, "7 4 0\n"); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1170 "pnfasm.ypp"
    { fprintf(output, "8 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1171 "pnfasm.ypp"
    { fprintf(output, "8 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1172 "pnfasm.ypp"
    { fprintf(output, "8 3 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1173 "pnfasm.ypp"
    { fprintf(output, "8 4 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 1174 "pnfasm.ypp"
    { fprintf(output, "9 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1175 "pnfasm.ypp"
    { fprintf(output, "10 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1176 "pnfasm.ypp"
    { fprintf(output, "10 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 1177 "pnfasm.ypp"
    { fprintf(output, "10 3 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1178 "pnfasm.ypp"
    { fprintf(output, "10 4 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1179 "pnfasm.ypp"
    { fprintf(output, "11 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1180 "pnfasm.ypp"
    { fprintf(output, "12 1 0\n"); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1181 "pnfasm.ypp"
    { fprintf(output, "12 2 0\n"); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1182 "pnfasm.ypp"
    { fprintf(output, "12 3 0\n"); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1183 "pnfasm.ypp"
    { fprintf(output, "12 4 0\n"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1184 "pnfasm.ypp"
    { fprintf(output, "13 0 0\n"); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1185 "pnfasm.ypp"
    { fprintf(output, "14 1 0\n"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1186 "pnfasm.ypp"
    { fprintf(output, "14 2 0\n"); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1187 "pnfasm.ypp"
    { fprintf(output, "14 3 0\n"); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1188 "pnfasm.ypp"
    { fprintf(output, "14 4 0\n"); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1189 "pnfasm.ypp"
    { fprintf(output, "15 0 0\n"); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1190 "pnfasm.ypp"
    { fprintf(output, "16 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1191 "pnfasm.ypp"
    { fprintf(output, "16 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1192 "pnfasm.ypp"
    { fprintf(output, "16 3 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1193 "pnfasm.ypp"
    { fprintf(output, "16 4 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1194 "pnfasm.ypp"
    { fprintf(output, "17 0 0\n"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1195 "pnfasm.ypp"
    { fprintf(output, "17 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1196 "pnfasm.ypp"
    { fprintf(output, "18 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1197 "pnfasm.ypp"
    { fprintf(output, "18 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1198 "pnfasm.ypp"
    { fprintf(output, "18 3 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1199 "pnfasm.ypp"
    { fprintf(output, "18 4 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1200 "pnfasm.ypp"
    { fprintf(output, "19 0 0\n"); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1201 "pnfasm.ypp"
    { fprintf(output, "19 4 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1202 "pnfasm.ypp"
    { fprintf(output, "20 0 0\n"); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1203 "pnfasm.ypp"
    { fprintf(output, "21 0 0\n"); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1204 "pnfasm.ypp"
    { fprintf(output, "21 1 0\n"); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1205 "pnfasm.ypp"
    { fprintf(output, "21 2 0\n"); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1206 "pnfasm.ypp"
    { fprintf(output, "21 3 0\n"); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1207 "pnfasm.ypp"
    { fprintf(output, "21 4 0\n"); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1208 "pnfasm.ypp"
    { fprintf(output, "22 0 0\n"); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1209 "pnfasm.ypp"
    { fprintf(output, "22 1 0\n"); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1210 "pnfasm.ypp"
    { fprintf(output, "22 2 0\n"); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1211 "pnfasm.ypp"
    { fprintf(output, "22 3 0\n"); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1212 "pnfasm.ypp"
    { fprintf(output, "22 4 0\n"); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1213 "pnfasm.ypp"
    { fprintf(output, "23 0 0\n"); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1214 "pnfasm.ypp"
    { fprintf(output, "23 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1215 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "23 3 %i\n", ch);
						;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1220 "pnfasm.ypp"
    {		
						 fprintf(output, "23 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1226 "pnfasm.ypp"
    { fprintf(output, "24 0 0\n"); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1227 "pnfasm.ypp"
    { fprintf(output, "24 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1228 "pnfasm.ypp"
    { fprintf(output, "25 0 0\n"); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1229 "pnfasm.ypp"
    { fprintf(output, "25 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1230 "pnfasm.ypp"
    { fprintf(output, "26 0 0\n"); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1231 "pnfasm.ypp"
    { fprintf(output, "26 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1232 "pnfasm.ypp"
    { fprintf(output, "27 0 0\n"); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1233 "pnfasm.ypp"
    { fprintf(output, "27 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1234 "pnfasm.ypp"
    { fprintf(output, "28 0 0\n"); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1235 "pnfasm.ypp"
    { fprintf(output, "28 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1236 "pnfasm.ypp"
    { fprintf(output, "29 0 0\n"); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1237 "pnfasm.ypp"
    { fprintf(output, "29 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1238 "pnfasm.ypp"
    { fprintf(output, "30 0 0\n"); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1239 "pnfasm.ypp"
    { fprintf(output, "31 0 0\n"); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1240 "pnfasm.ypp"
    { fprintf(output, "32 0 0\n"); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1241 "pnfasm.ypp"
    { fprintf(output, "33 0 0\n"); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1242 "pnfasm.ypp"
    { fprintf(output, "34 0 0\n"); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1243 "pnfasm.ypp"
    { fprintf(output, "35 0 0\n"); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1244 "pnfasm.ypp"
    { fprintf(output, "36 0 0\n"); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1245 "pnfasm.ypp"
    { fprintf(output, "37 0 0\n"); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1246 "pnfasm.ypp"
    { fprintf(output, "38 0 0\n"); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1247 "pnfasm.ypp"
    { fprintf(output, "39 0 0\n"); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1248 "pnfasm.ypp"
    { fprintf(output, "40 0 0\n"); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1249 "pnfasm.ypp"
    { fprintf(output, "41 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1250 "pnfasm.ypp"
    { fprintf(output, "42 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1251 "pnfasm.ypp"
    { fprintf(output, "43 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1252 "pnfasm.ypp"
    { fprintf(output, "44 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1253 "pnfasm.ypp"
    { fprintf(output, "45 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1254 "pnfasm.ypp"
    { fprintf(output, "46 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1255 "pnfasm.ypp"
    {
						 fprintf(output, "46 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1261 "pnfasm.ypp"
    { fprintf(output, "47 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1263 "pnfasm.ypp"
    {
						 fprintf(output, "47 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1269 "pnfasm.ypp"
    { fprintf(output, "48 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1271 "pnfasm.ypp"
    {
						 fprintf(output, "48 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1277 "pnfasm.ypp"
    { fprintf(output, "49 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1279 "pnfasm.ypp"
    {
						 fprintf(output, "49 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1285 "pnfasm.ypp"
    { fprintf(output, "50 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1287 "pnfasm.ypp"
    {
						 fprintf(output, "50 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1293 "pnfasm.ypp"
    { fprintf(output, "51 0 0\n"); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1294 "pnfasm.ypp"
    { fprintf(output, "52 0 0\n"); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1295 "pnfasm.ypp"
    { fprintf(output, "53 0 0\n"); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1296 "pnfasm.ypp"
    { fprintf(output, "54 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1297 "pnfasm.ypp"
    { fprintf(output, "55 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1299 "pnfasm.ypp"
    {
						 fprintf(output, "55 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1305 "pnfasm.ypp"
    { fprintf(output, "56 0 0\n"); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1307 "pnfasm.ypp"
    { fprintf(output, "58 0 0\n"); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1308 "pnfasm.ypp"
    {
						 fprintf(output, "58 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");		
						;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1314 "pnfasm.ypp"
    { fprintf(output, "59 0 0\n"); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1315 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "59 1 1\n");
						 else
						  fprintf(output, "59 1 0\n");
					        ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1321 "pnfasm.ypp"
    { fprintf(output, "59 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1322 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "59 3 %i\n", ch);
						;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1327 "pnfasm.ypp"
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
#line 1337 "pnfasm.ypp"
    { fprintf(output, "60 0 0\n"); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1338 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "60 1 1\n");
						 else
						  fprintf(output, "60 1 0\n");
					        ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1344 "pnfasm.ypp"
    { fprintf(output, "60 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1345 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "60 3 %i\n", ch);
						;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1350 "pnfasm.ypp"
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
#line 1360 "pnfasm.ypp"
    { fprintf(output, "61 0 0"); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1361 "pnfasm.ypp"
    { fprintf(output, "62 0 0\n"); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1362 "pnfasm.ypp"
    { fprintf(output, "63 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1363 "pnfasm.ypp"
    { fprintf(output, "64 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1364 "pnfasm.ypp"
    { fprintf(output, "65 0 0\n"); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1365 "pnfasm.ypp"
    { fprintf(output, "66 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1366 "pnfasm.ypp"
    { fprintf(output, "67 0 0\n"); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1367 "pnfasm.ypp"
    { fprintf(output, "68 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1368 "pnfasm.ypp"
    { fprintf(output, "69 0 0\n"); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1369 "pnfasm.ypp"
    { fprintf(output, "70 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1370 "pnfasm.ypp"
    { fprintf(output, "71 0 0\n"); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1371 "pnfasm.ypp"
    { fprintf(output, "72 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1372 "pnfasm.ypp"
    { fprintf(output, "73 0 0\n"); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1373 "pnfasm.ypp"
    { fprintf(output, "74 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1374 "pnfasm.ypp"
    { fprintf(output, "75 0 0\n"); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1375 "pnfasm.ypp"
    { fprintf(output, "76 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1376 "pnfasm.ypp"
    { fprintf(output, "77 0 0\n"); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1377 "pnfasm.ypp"
    { fprintf(output, "78 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1378 "pnfasm.ypp"
    { fprintf(output, "79 0 0\n"); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1379 "pnfasm.ypp"
    { fprintf(output, "80 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1380 "pnfasm.ypp"
    { fprintf(output, "81 0 0\n"); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1381 "pnfasm.ypp"
    { fprintf(output, "82 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1382 "pnfasm.ypp"
    { fprintf(output, "83 0 0\n"); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1383 "pnfasm.ypp"
    { fprintf(output, "84 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1384 "pnfasm.ypp"
    { fprintf(output, "85 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1385 "pnfasm.ypp"
    { fprintf(output, "86 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1386 "pnfasm.ypp"
    { fprintf(output, "87 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1387 "pnfasm.ypp"
    { fprintf(output, "88 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1388 "pnfasm.ypp"
    { fprintf(output, "89 0 0\n"); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1389 "pnfasm.ypp"
    { fprintf(output, "90 0 0\n"); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1390 "pnfasm.ypp"
    { fprintf(output, "91 0 0\n"); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1391 "pnfasm.ypp"
    { fprintf(output, "92 0 0\n"); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1393 "pnfasm.ypp"
    {
		 if ((yyvsp[(3) - (3)]) == "true")
		  fprintf(output, "92 1 1\n");
		 else
		  fprintf(output, "92 1 0\n");
		;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1399 "pnfasm.ypp"
    { fprintf(output, "92 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1401 "pnfasm.ypp"
    {
		 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "92 3 %i\n", ch);
		;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1407 "pnfasm.ypp"
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
#line 1416 "pnfasm.ypp"
    { fprintf(output, "93 0 0\n"); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1417 "pnfasm.ypp"
    { fprintf(output, "94 0 0\n"); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1418 "pnfasm.ypp"
    { fprintf(output, "95 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1419 "pnfasm.ypp"
    { fprintf(output, "96 0 0\n"); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1420 "pnfasm.ypp"
    { fprintf(output, "97 0 0\n"); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1421 "pnfasm.ypp"
    { fprintf(output, "98 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1422 "pnfasm.ypp"
    { fprintf(output, "99 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1423 "pnfasm.ypp"
    { fprintf(output, "100 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1424 "pnfasm.ypp"
    { fprintf(output, "101 0 0\n"); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1425 "pnfasm.ypp"
    { fprintf(output, "102 0 0\n"); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1426 "pnfasm.ypp"
    { fprintf(output, "103 0 0\n"); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1427 "pnfasm.ypp"
    { fprintf(output, "104 0 0\n"); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1428 "pnfasm.ypp"
    { fprintf(output, "105 0 0\n"); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1429 "pnfasm.ypp"
    { fprintf(output, "106 0 0\n"); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1430 "pnfasm.ypp"
    { fprintf(output, "107 0 0\n"); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1431 "pnfasm.ypp"
    { fprintf(output, "108 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1433 "pnfasm.ypp"
    {
		 if ((yyvsp[(3) - (3)]) == "true")
		  fprintf(output, "108 1 1\n");
		 else
		  fprintf(output, "108 1 0\n");
		;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1439 "pnfasm.ypp"
    { fprintf(output, "108 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1441 "pnfasm.ypp"
    {
		 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "108 3 %i\n", ch);
		;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1447 "pnfasm.ypp"
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
#line 1456 "pnfasm.ypp"
    { fprintf(output, "109 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1458 "pnfasm.ypp"
    {
		 if ((yyvsp[(3) - (3)]) == "true")
		  fprintf(output, "109 1 1\n");
		 else
		  fprintf(output, "109 1 0\n");
		;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1464 "pnfasm.ypp"
    { fprintf(output, "109 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1466 "pnfasm.ypp"
    {
		 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "109 3 %i\n", ch);
		;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1472 "pnfasm.ypp"
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
#line 1481 "pnfasm.ypp"
    { fprintf(output, "110 0 0\n"); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1482 "pnfasm.ypp"
    { fprintf(output, "111 0 0\n"); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1483 "pnfasm.ypp"
    { fprintf(output, "112 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1484 "pnfasm.ypp"
    { fprintf(output, "113 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1486 "pnfasm.ypp"
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
#line 1496 "pnfasm.ypp"
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
#line 1506 "pnfasm.ypp"
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
#line 1515 "pnfasm.ypp"
    { fprintf(output, "117 0 0\n"); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1517 "pnfasm.ypp"
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
#line 1526 "pnfasm.ypp"
    { fprintf(output, "118 0 0\n"); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1528 "pnfasm.ypp"
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
#line 1537 "pnfasm.ypp"
    { fprintf(output, "119 1 0\n"); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1538 "pnfasm.ypp"
    { fprintf(output, "119 2 0\n"); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1539 "pnfasm.ypp"
    { fprintf(output, "119 3 0\n"); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1540 "pnfasm.ypp"
    { fprintf(output, "119 4 0\n"); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1541 "pnfasm.ypp"
    { fprintf(output, "120 0 0\n"); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1542 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "120 1 1\n");
						 else
						  fprintf(output, "120 1 0\n");
					        ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1548 "pnfasm.ypp"
    { fprintf(output, "120 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1549 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "120 3 %i\n", ch);
						;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1554 "pnfasm.ypp"
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
#line 1563 "pnfasm.ypp"
    { fprintf(output, "121 0 0\n"); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1564 "pnfasm.ypp"
    {
						 if ((yyvsp[(3) - (3)]) == "true")
						  fprintf(output, "121 1 1\n");
						 else
						  fprintf(output, "121 1 0\n");
					        ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1570 "pnfasm.ypp"
    { fprintf(output, "121 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1571 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "121 3 %i\n", ch);
						;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1576 "pnfasm.ypp"
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
#line 1585 "pnfasm.ypp"
    { fprintf(output, "122 0 0\n"); ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1586 "pnfasm.ypp"
    { fprintf(output, "123 0 0\n"); ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1587 "pnfasm.ypp"
    { fprintf(output, "124 0 0\n"); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1588 "pnfasm.ypp"
    { fprintf(output, "125 0 0\n"); ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1589 "pnfasm.ypp"
    { fprintf(output, "126 0 0\n"); ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1590 "pnfasm.ypp"
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
#line 1599 "pnfasm.ypp"
    { fprintf(output, "128 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1600 "pnfasm.ypp"
    { fprintf(output, "129 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1601 "pnfasm.ypp"
    { fprintf(output, "130 0 0\n"); ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1602 "pnfasm.ypp"
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
#line 1611 "pnfasm.ypp"
    { fprintf(output, "132 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1612 "pnfasm.ypp"
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
#line 1621 "pnfasm.ypp"
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
#line 1630 "pnfasm.ypp"
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
#line 1639 "pnfasm.ypp"
    { fprintf(output, "136 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1640 "pnfasm.ypp"
    { fprintf(output, "137 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1641 "pnfasm.ypp"
    { fprintf(output, "138 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1642 "pnfasm.ypp"
    { fprintf(output, "139 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1643 "pnfasm.ypp"
    { fprintf(output, "140 0 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1644 "pnfasm.ypp"
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
#line 1653 "pnfasm.ypp"
    { fprintf(output, "142 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1654 "pnfasm.ypp"
    { fprintf(output, "143 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1655 "pnfasm.ypp"
    { fprintf(output, "144 0 0\n"); ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1656 "pnfasm.ypp"
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
#line 1665 "pnfasm.ypp"
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
#line 1674 "pnfasm.ypp"
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
#line 1683 "pnfasm.ypp"
    { fprintf(output, "148 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1684 "pnfasm.ypp"
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
#line 1693 "pnfasm.ypp"
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
#line 1702 "pnfasm.ypp"
    { fprintf(output, "151 0 0\n"); ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1703 "pnfasm.ypp"
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
#line 1712 "pnfasm.ypp"
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
#line 1721 "pnfasm.ypp"
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
#line 1730 "pnfasm.ypp"
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
#line 1739 "pnfasm.ypp"
    { fprintf(output, "156 0 0\n"); ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1740 "pnfasm.ypp"
    { fprintf(output, "157 0 0\n"); ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1741 "pnfasm.ypp"
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
#line 1750 "pnfasm.ypp"
    { fprintf(output, "159 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1751 "pnfasm.ypp"
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
#line 1760 "pnfasm.ypp"
    { fprintf(output, "161 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1761 "pnfasm.ypp"
    { fprintf(output, "161 0 0\n"); ;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1762 "pnfasm.ypp"
    { fprintf(output, "162 0 0\n"); ;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1763 "pnfasm.ypp"
    { fprintf(output, "163 0 0\n"); ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1764 "pnfasm.ypp"
    { fprintf(output, "163 1 0\n"); ;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1765 "pnfasm.ypp"
    { fprintf(output, "163 2 0\n"); ;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1766 "pnfasm.ypp"
    { fprintf(output, "163 3 0\n"); ;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1767 "pnfasm.ypp"
    { fprintf(output, "163 4 0\n"); ;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1768 "pnfasm.ypp"
    { fprintf(output, "164 0 0\n"); ;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1769 "pnfasm.ypp"
    { fprintf(output, "165 0 0\n"); ;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1770 "pnfasm.ypp"
    { fprintf(output, "166 0 0\n"); ;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1771 "pnfasm.ypp"
    { fprintf(output, "167 0 0\n"); ;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1772 "pnfasm.ypp"
    { fprintf(output, "168 0 0\n"); ;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1773 "pnfasm.ypp"
    { fprintf(output, "169 0 0\n"); ;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1774 "pnfasm.ypp"
    { fprintf(output, "170 0 0\n"); ;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1775 "pnfasm.ypp"
    { fprintf(output, "171 0 0\n"); ;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1776 "pnfasm.ypp"
    { fprintf(output, "172 0 0\n"); ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1777 "pnfasm.ypp"
    { fprintf(output, "173 0 0\n"); ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1778 "pnfasm.ypp"
    { fprintf(output, "174 0 0\n"); ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1779 "pnfasm.ypp"
    { fprintf(output, "175 0 0\n");	;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1780 "pnfasm.ypp"
    { fprintf(output, "176 0 0\n");	;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1781 "pnfasm.ypp"
    { fprintf(output, "177 0 0\n");	;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1782 "pnfasm.ypp"
    { fprintf(output, "178 0 0\n"); ;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1783 "pnfasm.ypp"
    { fprintf(output, "178 1 %s\n", (yyvsp[(3) - (3)]).getString().c_str());	;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1784 "pnfasm.ypp"
    { fprintf(output, "178 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str());	;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1785 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "178 3 %i\n", ch);
						;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1790 "pnfasm.ypp"
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
#line 1799 "pnfasm.ypp"
    { fprintf(output, "179 0 0\n");	;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1800 "pnfasm.ypp"
    { fprintf(output, "180 0 0\n");	;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1801 "pnfasm.ypp"
    { fprintf(output, "181 0 0\n");	;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1802 "pnfasm.ypp"
    { fprintf(output, "182 0 0\n");	;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1803 "pnfasm.ypp"
    { fprintf(output, "183 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1804 "pnfasm.ypp"
    { fprintf(output, "184 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1805 "pnfasm.ypp"
    { fprintf(output, "185 0 0\n"); ;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1806 "pnfasm.ypp"
    { fprintf(output, "186 0 0\n"); ;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1807 "pnfasm.ypp"
    { fprintf(output, "187 0 0\n"); ;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1808 "pnfasm.ypp"
    { fprintf(output, "188 0 0\n"); ;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1809 "pnfasm.ypp"
    { fprintf(output, "189 0 0\n"); ;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1810 "pnfasm.ypp"
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
#line 1819 "pnfasm.ypp"
    { fprintf(output, "191 0 0\n"); ;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1820 "pnfasm.ypp"
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
#line 1829 "pnfasm.ypp"
    { fprintf(output, "193 0 0\n"); ;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1830 "pnfasm.ypp"
    { fprintf(output, "194 0 0\n"); ;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1831 "pnfasm.ypp"
    { fprintf(output, "195 0 0\n"); ;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1832 "pnfasm.ypp"
    { fprintf(output, "196 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1833 "pnfasm.ypp"
    { fprintf(output, "197 0 0\n"); ;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1835 "pnfasm.ypp"
    {
			 			 if ((yyvsp[(3) - (3)]) == "true")
		 	  			  fprintf(output, "197 1 1\n");
			 			 else
			  			  fprintf(output, "197 1 0\n");
						;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1841 "pnfasm.ypp"
    { fprintf(output, "197 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1843 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "197 3 %i\n", ch);
						;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1849 "pnfasm.ypp"
    {		
						 fprintf(output, "197 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1855 "pnfasm.ypp"
    { fprintf(output, "198 0 0\n"); ;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1856 "pnfasm.ypp"
    { fprintf(output, "198 1 0\n"); ;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1857 "pnfasm.ypp"
    { fprintf(output, "198 2 0\n"); ;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1858 "pnfasm.ypp"
    { fprintf(output, "198 3 0\n"); ;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1859 "pnfasm.ypp"
    { fprintf(output, "198 4 0\n"); ;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1860 "pnfasm.ypp"
    { fprintf(output, "199 0 0\n"); ;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1861 "pnfasm.ypp"
    { fprintf(output, "199 1 0\n"); ;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1862 "pnfasm.ypp"
    { fprintf(output, "199 2 0\n"); ;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1863 "pnfasm.ypp"
    { fprintf(output, "199 3 0\n"); ;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1864 "pnfasm.ypp"
    { fprintf(output, "199 4 0\n"); ;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1865 "pnfasm.ypp"
    { fprintf(output, "200 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1866 "pnfasm.ypp"
    { fprintf(output, "201 0 0\n"); ;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1867 "pnfasm.ypp"
    { fprintf(output, "201 1 0\n"); ;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1868 "pnfasm.ypp"
    { fprintf(output, "201 2 0\n"); ;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1869 "pnfasm.ypp"
    { fprintf(output, "201 3 0\n"); ;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1870 "pnfasm.ypp"
    { fprintf(output, "201 4 0\n"); ;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1871 "pnfasm.ypp"
    { fprintf(output, "202 0 0\n"); ;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1872 "pnfasm.ypp"
    { fprintf(output, "202 1 0\n"); ;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1873 "pnfasm.ypp"
    { fprintf(output, "202 2 0\n"); ;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1874 "pnfasm.ypp"
    { fprintf(output, "202 3 0\n"); ;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1875 "pnfasm.ypp"
    { fprintf(output, "202 4 0\n"); ;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1876 "pnfasm.ypp"
    { fprintf(output, "203 0 0\n"); ;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1877 "pnfasm.ypp"
    { fprintf(output, "203 1 0\n"); ;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1878 "pnfasm.ypp"
    { fprintf(output, "203 2 0\n"); ;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1879 "pnfasm.ypp"
    { fprintf(output, "203 3 0\n"); ;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1880 "pnfasm.ypp"
    { fprintf(output, "203 4 0\n"); ;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1883 "pnfasm.ypp"
    {		
						 fprintf(output, "204 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1889 "pnfasm.ypp"
    { fprintf(output, "205 0 0\n"); ;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1890 "pnfasm.ypp"
    { fprintf(output, "206 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1891 "pnfasm.ypp"
    { fprintf(output, "207 0 0\n"); ;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1892 "pnfasm.ypp"
    { fprintf(output, "207 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1893 "pnfasm.ypp"
    { fprintf(output, "208 0 0\n"); ;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1894 "pnfasm.ypp"
    { fprintf(output, "209 0 0\n"); ;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1895 "pnfasm.ypp"
    { fprintf(output, "210 0 0\n"); ;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1896 "pnfasm.ypp"
    { fprintf(output, "211 0 0\n"); ;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1897 "pnfasm.ypp"
    { fprintf(output, "211 1 0\n"); ;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1898 "pnfasm.ypp"
    { fprintf(output, "211 2 0\n"); ;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1899 "pnfasm.ypp"
    { fprintf(output, "211 3 0\n"); ;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1900 "pnfasm.ypp"
    { fprintf(output, "211 4 0\n"); ;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1901 "pnfasm.ypp"
    { fprintf(output, "212 0 0\n"); ;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1902 "pnfasm.ypp"
    { fprintf(output, "212 1 0\n"); ;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1903 "pnfasm.ypp"
    { fprintf(output, "212 2 0\n"); ;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1904 "pnfasm.ypp"
    { fprintf(output, "212 3 0\n"); ;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1905 "pnfasm.ypp"
    { fprintf(output, "212 4 0\n"); ;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1906 "pnfasm.ypp"
    { fprintf(output, "213 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1907 "pnfasm.ypp"
    {		
						 fprintf(output, "213 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1913 "pnfasm.ypp"
    { fprintf(output, "214 0 0\n"); ;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1914 "pnfasm.ypp"
    { fprintf(output, "215 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1915 "pnfasm.ypp"
    { fprintf(output, "216 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1916 "pnfasm.ypp"
    { fprintf(output, "217 0 0\n"); ;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1917 "pnfasm.ypp"
    { fprintf(output, "218 0 0\n"); ;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1918 "pnfasm.ypp"
    { fprintf(output, "219 0 0\n"); ;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1919 "pnfasm.ypp"
    { fprintf(output, "220 0 0\n"); ;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1920 "pnfasm.ypp"
    { fprintf(output, "221 0 0\n"); ;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1921 "pnfasm.ypp"
    { fprintf(output, "222 0 0\n"); ;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1922 "pnfasm.ypp"
    { fprintf(output, "222 1 0\n"); ;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1923 "pnfasm.ypp"
    { fprintf(output, "222 2 0\n"); ;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1924 "pnfasm.ypp"
    { fprintf(output, "222 3 0\n"); ;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1925 "pnfasm.ypp"
    { fprintf(output, "222 4 0\n"); ;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1926 "pnfasm.ypp"
    { fprintf(output, "223 0 0\n"); ;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1927 "pnfasm.ypp"
    { fprintf(output, "223 1 0\n"); ;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1928 "pnfasm.ypp"
    { fprintf(output, "223 2 0\n"); ;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1929 "pnfasm.ypp"
    { fprintf(output, "223 3 0\n"); ;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1930 "pnfasm.ypp"
    { fprintf(output, "223 4 0\n"); ;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1931 "pnfasm.ypp"
    { fprintf(output, "224 0 0\n"); ;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1932 "pnfasm.ypp"
    { fprintf(output, "225 0 0\n"); ;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1933 "pnfasm.ypp"
    { fprintf(output, "226 0 0\n"); ;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1934 "pnfasm.ypp"
    { fprintf(output, "227 0 0\n"); ;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1935 "pnfasm.ypp"
    { fprintf(output, "228 0 0\n"); ;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1936 "pnfasm.ypp"
    { fprintf(output, "228 1 0\n"); ;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1937 "pnfasm.ypp"
    { fprintf(output, "228 2 0\n"); ;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1938 "pnfasm.ypp"
    { fprintf(output, "228 3 0\n"); ;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1939 "pnfasm.ypp"
    { fprintf(output, "228 4 0\n"); ;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1940 "pnfasm.ypp"
    { fprintf(output, "229 0 0\n"); ;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1941 "pnfasm.ypp"
    { fprintf(output, "230 0 0\n"); ;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1942 "pnfasm.ypp"
    { fprintf(output, "231 0 0\n"); ;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1943 "pnfasm.ypp"
    { /* Do nothing... */ ;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1944 "pnfasm.ypp"
    { fprintf(output, "%s %s %s\n", (yyvsp[(2) - (4)]).getString().c_str(), (yyvsp[(3) - (4)]).getString().c_str(), (yyvsp[(4) - (4)]).getString().c_str()); ;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1954 "pnfasm.ypp"
    { fprintf(output, "57 0 0\n"); ;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1956 "pnfasm.ypp"
    {
			 			 if ((yyvsp[(3) - (3)]) == "true")
		 	  			  fprintf(output, "57 1 1\n");
			 			 else
			  			  fprintf(output, "57 1 0\n");
						;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1962 "pnfasm.ypp"
    { fprintf(output, "57 2 %s\n", (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1964 "pnfasm.ypp"
    {
			 			 char * dup = strdup((yyvsp[(3) - (3)]).getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "57 3 %i\n", ch);
						;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1970 "pnfasm.ypp"
    {		
						 fprintf(output, "57 4 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1976 "pnfasm.ypp"
    { fprintf(output, "57 1 0\n"); ;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1977 "pnfasm.ypp"
    { fprintf(output, "57 2 0\n"); ;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1978 "pnfasm.ypp"
    { fprintf(output, "57 3 0\n"); ;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1979 "pnfasm.ypp"
    { fprintf(output, "57 4 0\n"); ;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1981 "pnfasm.ypp"
    {		
						 fprintf(output, "57 0 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1988 "pnfasm.ypp"
    {		
						 fprintf(output, "57 1 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1995 "pnfasm.ypp"
    {		
						 fprintf(output, "57 2 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 2002 "pnfasm.ypp"
    {		
						 fprintf(output, "57 3 ");				 
		 	 			 for (unsigned long i = 1; (yyvsp[(3) - (3)])[i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)(yyvsp[(3) - (3)])[i]);
		 	 			 fprintf(output, "0\n");
						;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2011 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#include %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2012 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#include <%s>\n", (yyvsp[(2) - (4)]).getString().c_str()); ;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2013 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#import %s \n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 2014 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#import <%s> \n", (yyvsp[(2) - (4)]).getString().c_str()); ;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2015 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#define %s %s\n", (yyvsp[(2) - (3)]).getString().c_str(), (yyvsp[(3) - (3)]).getString().c_str()); ;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2016 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#macro %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2017 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#endm\n"); ;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2018 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#undef %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2019 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#ifdef %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2020 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#ifndef %s\n", (yyvsp[(2) - (2)]).getString().c_str()); ;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2021 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#else\n"); ;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2022 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "#endif\n"); ;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2023 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_DATE()\n"); ;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2024 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_TIME()\n"); ;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2025 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_LINE()\n"); ;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2026 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_FILE()\n"); ;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2027 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_CDATE()\n"); ;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2028 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "_CTIME()\n"); ;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2029 "pnfasm.ypp"
    { if (mode == 1 || mode == 2) fprintf(output, "\' %s\n", (yyvsp[(1) - (1)]).getString().c_str()); ;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2032 "pnfasm.ypp"
    { mode = 0; ;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2033 "pnfasm.ypp"
    { mode = 1; ;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2034 "pnfasm.ypp"
    { mode = 2; ;}
    break;



/* Line 1455 of yacc.c  */
#line 6693 "pnfasm.tab.cpp"
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
#line 2037 "pnfasm.ypp"

/* Additional C/C++ Code */
void yyerror(char const * c)
{
 cout << "* ERROR: " << yylineno << ": " << c << endl;
}

