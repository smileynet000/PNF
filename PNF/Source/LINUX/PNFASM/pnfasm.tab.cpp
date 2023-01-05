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
			10. Added NTIMES instruction.
			11. Added CMP instruction.
			12. Added RUN, JRUN, & PNFRUN instructions.
			13. Added struct instructions.
			14. Added more struct instructions.
			15. Implemented segment instructions.
            16. Implemented message instruction.
            17. Implemented basic class instructions.

2/19/22 Origional a-a-f 1. Implemented CLASSMETHOD instruction.
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

#line 893 "pnfasm.tab.cpp"

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
    ASMVERSION = 258,              /* ASMVERSION  */
    PNF = 259,                     /* PNF  */
    BIN = 260,                     /* BIN  */
    PBIN = 261,                    /* PBIN  */
    LIB = 262,                     /* LIB  */
    PINCLUDE = 263,                /* PINCLUDE  */
    PIMPORT = 264,                 /* PIMPORT  */
    PDEFINE = 265,                 /* PDEFINE  */
    PMACRO = 266,                  /* PMACRO  */
    PENDM = 267,                   /* PENDM  */
    PUNDEF = 268,                  /* PUNDEF  */
    PIFDEF = 269,                  /* PIFDEF  */
    PIFNDEF = 270,                 /* PIFNDEF  */
    PELSE = 271,                   /* PELSE  */
    PENDIF = 272,                  /* PENDIF  */
    PPDATE = 273,                  /* PPDATE  */
    PPTIME = 274,                  /* PPTIME  */
    PPLINE = 275,                  /* PPLINE  */
    PPFILE = 276,                  /* PPFILE  */
    PPCDATE = 277,                 /* PPCDATE  */
    PPCTIME = 278,                 /* PPCTIME  */
    PPCOMMENT = 279,               /* PPCOMMENT  */
    IVERSION = 280,                /* IVERSION  */
    IVOID = 281,                   /* IVOID  */
    ICRASH = 282,                  /* ICRASH  */
    IQUIT = 283,                   /* IQUIT  */
    IHALT = 284,                   /* IHALT  */
    IPRINT = 285,                  /* IPRINT  */
    IPRINTLN = 286,                /* IPRINTLN  */
    IREAD = 287,                   /* IREAD  */
    ILOAD = 288,                   /* ILOAD  */
    ISTORE = 289,                  /* ISTORE  */
    ILOADC = 290,                  /* ILOADC  */
    ISTOREC = 291,                 /* ISTOREC  */
    IELOAD = 292,                  /* IELOAD  */
    IESTORE = 293,                 /* IESTORE  */
    IELOADC = 294,                 /* IELOADC  */
    IESTOREC = 295,                /* IESTOREC  */
    IVLOAD = 296,                  /* IVLOAD  */
    IVSTORE = 297,                 /* IVSTORE  */
    IVLOADC = 298,                 /* IVLOADC  */
    IVSTOREC = 299,                /* IVSTOREC  */
    ISTOREA = 300,                 /* ISTOREA  */
    IMODT = 301,                   /* IMODT  */
    IMODCT = 302,                  /* IMODCT  */
    IADD = 303,                    /* IADD  */
    ISUB = 304,                    /* ISUB  */
    IMUL = 305,                    /* IMUL  */
    IDIV = 306,                    /* IDIV  */
    IMOD = 307,                    /* IMOD  */
    IPOW = 308,                    /* IPOW  */
    IROOT = 309,                   /* IROOT  */
    IINC = 310,                    /* IINC  */
    IDEC = 311,                    /* IDEC  */
    IEQU = 312,                    /* IEQU  */
    INEQU = 313,                   /* INEQU  */
    IGTR = 314,                    /* IGTR  */
    ILSS = 315,                    /* ILSS  */
    IGEQU = 316,                   /* IGEQU  */
    ILEQU = 317,                   /* ILEQU  */
    IAND = 318,                    /* IAND  */
    IOR = 319,                     /* IOR  */
    INOT = 320,                    /* INOT  */
    IGOTO = 321,                   /* IGOTO  */
    ICGOTO = 322,                  /* ICGOTO  */
    IZGOTO = 323,                  /* IZGOTO  */
    IPGOTO = 324,                  /* IPGOTO  */
    INGOTO = 325,                  /* INGOTO  */
    IGOTOL = 326,                  /* IGOTOL  */
    ICGOTOL = 327,                 /* ICGOTOL  */
    IZGOTOL = 328,                 /* IZGOTOL  */
    IPGOTOL = 329,                 /* IPGOTOL  */
    INGOTOL = 330,                 /* INGOTOL  */
    IST = 331,                     /* IST  */
    IPUSH = 332,                   /* IPUSH  */
    IPOP = 333,                    /* IPOP  */
    ICALL = 334,                   /* ICALL  */
    ICALLL = 335,                  /* ICALLL  */
    IRET = 336,                    /* IRET  */
    IVAR = 337,                    /* IVAR  */
    ILBL = 338,                    /* ILBL  */
    IEPRINT = 339,                 /* IEPRINT  */
    IEPRINTLN = 340,               /* IEPRINTLN  */
    IEND = 341,                    /* IEND  */
    IELBL = 342,                   /* IELBL  */
    IEVLOAD = 343,                 /* IEVLOAD  */
    IHEADD = 344,                  /* IHEADD  */
    IHEREM = 345,                  /* IHEREM  */
    IHEED = 346,                   /* IHEED  */
    IHEGET = 347,                  /* IHEGET  */
    ISHEADD = 348,                 /* ISHEADD  */
    ISHEREM = 349,                 /* ISHEREM  */
    ISHEED = 350,                  /* ISHEED  */
    ISHEGET = 351,                 /* ISHEGET  */
    IEADD = 352,                   /* IEADD  */
    IEREM = 353,                   /* IEREM  */
    IEED = 354,                    /* IEED  */
    IEGET = 355,                   /* IEGET  */
    IEXADD = 356,                  /* IEXADD  */
    IEXREM = 357,                  /* IEXREM  */
    IEXED = 358,                   /* IEXED  */
    IEXGET = 359,                  /* IEXGET  */
    IIADD = 360,                   /* IIADD  */
    IIREM = 361,                   /* IIREM  */
    IIED = 362,                    /* IIED  */
    IIGET = 363,                   /* IIGET  */
    IHEVENT = 364,                 /* IHEVENT  */
    ISHEVENT = 365,                /* ISHEVENT  */
    IEVENT = 366,                  /* IEVENT  */
    IEXCEPTION = 367,              /* IEXCEPTION  */
    IINT = 368,                    /* IINT  */
    ITYPEOF = 369,                 /* ITYPEOF  */
    ICTYPEOF = 370,                /* ICTYPEOF  */
    ITLOAD = 371,                  /* ITLOAD  */
    IALOAD = 372,                  /* IALOAD  */
    IINLOAD = 373,                 /* IINLOAD  */
    IICLOAD = 374,                 /* IICLOAD  */
    IARLOAD = 375,                 /* IARLOAD  */
    IATOC = 376,                   /* IATOC  */
    ISWITCH = 377,                 /* ISWITCH  */
    IVADD = 378,                   /* IVADD  */
    ILADD = 379,                   /* ILADD  */
    IELADD = 380,                  /* IELADD  */
    IADD2V = 381,                  /* IADD2V  */
    IBTAND = 382,                  /* IBTAND  */
    IBTOR = 383,                   /* IBTOR  */
    IBTEXOR = 384,                 /* IBTEXOR  */
    IBTNOT = 385,                  /* IBTNOT  */
    IBTSL = 386,                   /* IBTSL  */
    IBTSR = 387,                   /* IBTSR  */
    IVCHECK = 388,                 /* IVCHECK  */
    IVSUPP = 389,                  /* IVSUPP  */
    IVPRINT = 390,                 /* IVPRINT  */
    IVPRINTLN = 391,               /* IVPRINTLN  */
    IISUPP = 392,                  /* IISUPP  */
    ITSUPP = 393,                  /* ITSUPP  */
    ICOMMENT = 394,                /* ICOMMENT  */
    IFIMODE = 395,                 /* IFIMODE  */
    IFOMODE = 396,                 /* IFOMODE  */
    IFIOPEN = 397,                 /* IFIOPEN  */
    IFOOPEN = 398,                 /* IFOOPEN  */
    IFREAD = 399,                  /* IFREAD  */
    IFPRINT = 400,                 /* IFPRINT  */
    IFPRINTLN = 401,               /* IFPRINTLN  */
    IFICLOSE = 402,                /* IFICLOSE  */
    IFOCLOSE = 403,                /* IFOCLOSE  */
    IMEML = 404,                   /* IMEML  */
    IFIEOF = 405,                  /* IFIEOF  */
    IARNLOAD = 406,                /* IARNLOAD  */
    IRDSTART1 = 407,               /* IRDSTART1  */
    IRFROM1 = 408,                 /* IRFROM1  */
    IRTO1 = 409,                   /* IRTO1  */
    IRDEND1 = 410,                 /* IRDEND1  */
    IRSTART1 = 411,                /* IRSTART1  */
    IRANGE1 = 412,                 /* IRANGE1  */
    IREND1 = 413,                  /* IREND1  */
    IRLOAD1 = 414,                 /* IRLOAD1  */
    IRSTORE1 = 415,                /* IRSTORE1  */
    IHEADDB = 416,                 /* IHEADDB  */
    ISHEADDB = 417,                /* ISHEADDB  */
    IEADDB = 418,                  /* IEADDB  */
    IEXADDB = 419,                 /* IEXADDB  */
    IIADDB = 420,                  /* IIADDB  */
    IRDSTART2 = 421,               /* IRDSTART2  */
    IRFROM2 = 422,                 /* IRFROM2  */
    IRTO2 = 423,                   /* IRTO2  */
    IRDEND2 = 424,                 /* IRDEND2  */
    IRSTART2 = 425,                /* IRSTART2  */
    IRANGE2 = 426,                 /* IRANGE2  */
    IRPREP2 = 427,                 /* IRPREP2  */
    IRLOAD2 = 428,                 /* IRLOAD2  */
    IESTART = 429,                 /* IESTART  */
    IENAME = 430,                  /* IENAME  */
    IEEND = 431,                   /* IEEND  */
    IENUMS = 432,                  /* IENUMS  */
    IENUM = 433,                   /* IENUM  */
    ISENUM = 434,                  /* ISENUM  */
    IEPREP = 435,                  /* IEPREP  */
    ILOADE = 436,                  /* ILOADE  */
    ISTOREE = 437,                 /* ISTOREE  */
    IASTART = 438,                 /* IASTART  */
    IAEND = 439,                   /* IAEND  */
    IAPREP = 440,                  /* IAPREP  */
    IAIPREP = 441,                 /* IAIPREP  */
    ILOADIA = 442,                 /* ILOADIA  */
    ISTOREIA = 443,                /* ISTOREIA  */
    IALENGTH = 444,                /* IALENGTH  */
    IAPRINT = 445,                 /* IAPRINT  */
    IDUP = 446,                    /* IDUP  */
    ICDUP = 447,                   /* ICDUP  */
    IIF = 448,                     /* IIF  */
    IENDIF = 449,                  /* IENDIF  */
    IIFELSE = 450,                 /* IIFELSE  */
    IENDIFELSE = 451,              /* IENDIFELSE  */
    IEIF = 452,                    /* IEIF  */
    IIFBEGIN = 453,                /* IIFBEGIN  */
    IIFEND = 454,                  /* IIFEND  */
    ISWITCH2 = 455,                /* ISWITCH2  */
    ISWBEGIN = 456,                /* ISWBEGIN  */
    ISWEND = 457,                  /* ISWEND  */
    ISWCASE = 458,                 /* ISWCASE  */
    ISWCBEGIN = 459,               /* ISWCBEGIN  */
    ISWCEND = 460,                 /* ISWCEND  */
    ISWDEFAULT = 461,              /* ISWDEFAULT  */
    ISWBREAK = 462,                /* ISWBREAK  */
    ILOADSP = 463,                 /* ILOADSP  */
    ISTORESP = 464,                /* ISTORESP  */
    ILOADSTACK = 465,              /* ILOADSTACK  */
    ISTORESTACK = 466,             /* ISTORESTACK  */
    IATOSP = 467,                  /* IATOSP  */
    ISPTOA = 468,                  /* ISPTOA  */
    IPATCH = 469,                  /* IPATCH  */
    INATIVE = 470,                 /* INATIVE  */
    IFRET = 471,                   /* IFRET  */
    IFCALL = 472,                  /* IFCALL  */
    IFCPARAMS = 473,               /* IFCPARAMS  */
    IFECPARAMS = 474,              /* IFECPARAMS  */
    IFECALL = 475,                 /* IFECALL  */
    IPNUM = 476,                   /* IPNUM  */
    IPARAMF = 477,                 /* IPARAMF  */
    IPARAMF2 = 478,                /* IPARAMF2  */
    IPARAMF3 = 479,                /* IPARAMF3  */
    IRNUM = 480,                   /* IRNUM  */
    IRETURNF = 481,                /* IRETURNF  */
    IRETURNF2 = 482,               /* IRETURNF2  */
    IRETURNF3 = 483,               /* IRETURNF3  */
    IFNAME = 484,                  /* IFNAME  */
    IRETURNV = 485,                /* IRETURNV  */
    IFNCLOAD = 486,                /* IFNCLOAD  */
    IFNCSTORE = 487,               /* IFNCSTORE  */
    IFNCNEW = 488,                 /* IFNCNEW  */
    IFNCDELETE = 489,              /* IFNCDELETE  */
    IFNCSNAME = 490,               /* IFNCSNAME  */
    IFNCSRET = 491,                /* IFNCSRET  */
    IFNCSPARAM = 492,              /* IFNCSPARAM  */
    IFNCSDEF = 493,                /* IFNCSDEF  */
    IFNCGNAME = 494,               /* IFNCGNAME  */
    IFNCGRET = 495,                /* IFNCGRET  */
    IFNCGPARAM = 496,              /* IFNCGPARAM  */
    IFNCGDEF = 497,                /* IFNCGDEF  */
    IFNCPOINT = 498,               /* IFNCPOINT  */
    IFNCLENGTH = 499,              /* IFNCLENGTH  */
    IFNCSYNCR = 500,               /* IFNCSYNCR  */
    IFNCFIND = 501,                /* IFNCFIND  */
    IFNCFRET = 502,                /* IFNCFRET  */
    IFNCFPARAM = 503,              /* IFNCFPARAM  */
    IFNCFBRET = 504,               /* IFNCFBRET  */
    IFNCFBPARAM = 505,             /* IFNCFBPARAM  */
    IFNCDEFAULT = 506,             /* IFNCDEFAULT  */
    IFNCDEFAULT2 = 507,            /* IFNCDEFAULT2  */
    IFNCSDEFAULTV = 508,           /* IFNCSDEFAULTV  */
    IFNCSDEFAULTV2 = 509,          /* IFNCSDEFAULTV2  */
    IFNCGDEFAULTV2 = 510,          /* IFNCGDEFAULTV2  */
    IFNCDEFAULTSYNC = 511,         /* IFNCDEFAULTSYNC  */
    INTIMES = 512,                 /* INTIMES  */
    ICMP = 513,                    /* ICMP  */
    IRUN = 514,                    /* IRUN  */
    IJRUN = 515,                   /* IJRUN  */
    IPNFRUN = 516,                 /* IPNFRUN  */
    ISTRUCT = 517,                 /* ISTRUCT  */
    ISTRUCTVAR = 518,              /* ISTRUCTVAR  */
    IENDSTRUCT = 519,              /* IENDSTRUCT  */
    ISTRUCTNAME = 520,             /* ISTRUCTNAME  */
    ISTRUCTONAME = 521,            /* ISTRUCTONAME  */
    ISTRUCTD = 522,                /* ISTRUCTD  */
    ISTRUCTUSE = 523,              /* ISTRUCTUSE  */
    ISTRUCTUSING = 524,            /* ISTRUCTUSING  */
    ISTRUCTUSINGNAME = 525,        /* ISTRUCTUSINGNAME  */
    ISTRUCTGET = 526,              /* ISTRUCTGET  */
    ISTRUCTPUT = 527,              /* ISTRUCTPUT  */
    ISTRUCTTYPE = 528,             /* ISTRUCTTYPE  */
    ISTRUCTTYPE2 = 529,            /* ISTRUCTTYPE2  */
    ISTRUCTNAME2 = 530,            /* ISTRUCTNAME2  */
    ISTRUCTNAME3 = 531,            /* ISTRUCTNAME3  */
    IUNION = 532,                  /* IUNION  */
    IUNIONVAR = 533,               /* IUNIONVAR  */
    IENDUNION = 534,               /* IENDUNION  */
    IUNIONNAME = 535,              /* IUNIONNAME  */
    IUNIONONAME = 536,             /* IUNIONONAME  */
    IUNIOND = 537,                 /* IUNIOND  */
    IUNIONUSE = 538,               /* IUNIONUSE  */
    IUNIONUSING = 539,             /* IUNIONUSING  */
    IUNIONUSINGNAME = 540,         /* IUNIONUSINGNAME  */
    IUNIONGET = 541,               /* IUNIONGET  */
    IUNIONPUT = 542,               /* IUNIONPUT  */
    IUNIONTYPE = 543,              /* IUNIONTYPE  */
    IUNIONTYPE2 = 544,             /* IUNIONTYPE2  */
    IUNIONNAME2 = 545,             /* IUNIONNAME2  */
    IUNIONNAME3 = 546,             /* IUNIONNAME3  */
    IMODE = 547,                   /* IMODE  */
    IEXTMODE = 548,                /* IEXTMODE  */
    IMCHECK = 549,                 /* IMCHECK  */
    IMSUPP = 550,                  /* IMSUPP  */
    IMEXTCHECK = 551,              /* IMEXTCHECK  */
    IMEXTSUPP = 552,               /* IMEXTSUPP  */
    ICPY = 553,                    /* ICPY  */
    IADDSEG = 554,                 /* IADDSEG  */
    IREMSEG = 555,                 /* IREMSEG  */
    ICOLLSEG = 556,                /* ICOLLSEG  */
    IEXPSEG = 557,                 /* IEXPSEG  */
    ICPYSEG = 558,                 /* ICPYSEG  */
    ISEGLOAD = 559,                /* ISEGLOAD  */
    ISEGSTORE = 560,               /* ISEGSTORE  */
    ISEGPUSH = 561,                /* ISEGPUSH  */
    ISEGPOP = 562,                 /* ISEGPOP  */
    ISEGTOP = 563,                 /* ISEGTOP  */
    ISEGVLOAD = 564,               /* ISEGVLOAD  */
    ISEGVSTORE = 565,              /* ISEGVSTORE  */
    IMSG = 566,                    /* IMSG  */
    IWHILE = 567,                  /* IWHILE  */
    IWHILEB = 568,                 /* IWHILEB  */
    IWHILEE = 569,                 /* IWHILEE  */
    IWHILEBB = 570,                /* IWHILEBB  */
    IWHILEBBB = 571,               /* IWHILEBBB  */
    IWHILEBBE = 572,               /* IWHILEBBE  */
    IUNTIL = 573,                  /* IUNTIL  */
    IUNTILB = 574,                 /* IUNTILB  */
    IUNTILE = 575,                 /* IUNTILE  */
    IUNTILBB = 576,                /* IUNTILBB  */
    IUNTILBBB = 577,               /* IUNTILBBB  */
    IUNTILBBE = 578,               /* IUNTILBBE  */
    IFOR = 579,                    /* IFOR  */
    IFORINIT = 580,                /* IFORINIT  */
    IFORCOND = 581,                /* IFORCOND  */
    IFORINC = 582,                 /* IFORINC  */
    IFORB = 583,                   /* IFORB  */
    IFORE = 584,                   /* IFORE  */
    ICLASS = 585,                  /* ICLASS  */
    ICLASSVAR = 586,               /* ICLASSVAR  */
    IENDCLASS = 587,               /* IENDCLASS  */
    ICLASSNAME = 588,              /* ICLASSNAME  */
    ICLASSONAME = 589,             /* ICLASSONAME  */
    ICLASSD = 590,                 /* ICLASSD  */
    ICLASSUSE = 591,               /* ICLASSUSE  */
    ICLASSUSING = 592,             /* ICLASSUSING  */
    ICLASSUSINGNAME = 593,         /* ICLASSUSINGNAME  */
    ICLASSGET = 594,               /* ICLASSGET  */
    ICLASSPUT = 595,               /* ICLASSPUT  */
    ICLASSTYPE = 596,              /* ICLASSTYPE  */
    ICLASSTYPE2 = 597,             /* ICLASSTYPE2  */
    ICLASSNAME2 = 598,             /* ICLASSNAME2  */
    ICLASSNAME3 = 599,             /* ICLASSNAME3  */
    ICLASSMETHOD = 600,            /* ICLASSMETHOD  */
    ICLASSMETHOD2 = 601,           /* ICLASSMETHOD2  */
    ICLASSMETHODCALL = 602,        /* ICLASSMETHODCALL  */
    ICLASSMETHODCPARAMS = 603,     /* ICLASSMETHODCPARAMS  */
    ICLASSMETHODECPARAMS = 604,    /* ICLASSMETHODECPARAMS  */
    ICLASSMETHODECALL = 605,       /* ICLASSMETHODECALL  */
    ICLASSEXTENDACCESS = 606,      /* ICLASSEXTENDACCESS  */
    ICLASSEXTEND = 607,            /* ICLASSEXTEND  */
    ICLASSIMPLEMENTACCESS = 608,   /* ICLASSIMPLEMENTACCESS  */
    ICLASSIMPLEMENT = 609,         /* ICLASSIMPLEMENT  */
    TVOID = 610,                   /* TVOID  */
    TBOOLEAN = 611,                /* TBOOLEAN  */
    TNUMBER = 612,                 /* TNUMBER  */
    TCHARACTER = 613,              /* TCHARACTER  */
    TSTRING = 614,                 /* TSTRING  */
    VOID = 615,                    /* VOID  */
    BOOLEAN = 616,                 /* BOOLEAN  */
    NUMBER = 617,                  /* NUMBER  */
    CHARACTER = 618,               /* CHARACTER  */
    STRING = 619                   /* STRING  */
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
  YYSYMBOL_ASMVERSION = 3,                 /* ASMVERSION  */
  YYSYMBOL_PNF = 4,                        /* PNF  */
  YYSYMBOL_BIN = 5,                        /* BIN  */
  YYSYMBOL_PBIN = 6,                       /* PBIN  */
  YYSYMBOL_LIB = 7,                        /* LIB  */
  YYSYMBOL_PINCLUDE = 8,                   /* PINCLUDE  */
  YYSYMBOL_PIMPORT = 9,                    /* PIMPORT  */
  YYSYMBOL_PDEFINE = 10,                   /* PDEFINE  */
  YYSYMBOL_PMACRO = 11,                    /* PMACRO  */
  YYSYMBOL_PENDM = 12,                     /* PENDM  */
  YYSYMBOL_PUNDEF = 13,                    /* PUNDEF  */
  YYSYMBOL_PIFDEF = 14,                    /* PIFDEF  */
  YYSYMBOL_PIFNDEF = 15,                   /* PIFNDEF  */
  YYSYMBOL_PELSE = 16,                     /* PELSE  */
  YYSYMBOL_PENDIF = 17,                    /* PENDIF  */
  YYSYMBOL_PPDATE = 18,                    /* PPDATE  */
  YYSYMBOL_PPTIME = 19,                    /* PPTIME  */
  YYSYMBOL_PPLINE = 20,                    /* PPLINE  */
  YYSYMBOL_PPFILE = 21,                    /* PPFILE  */
  YYSYMBOL_PPCDATE = 22,                   /* PPCDATE  */
  YYSYMBOL_PPCTIME = 23,                   /* PPCTIME  */
  YYSYMBOL_PPCOMMENT = 24,                 /* PPCOMMENT  */
  YYSYMBOL_IVERSION = 25,                  /* IVERSION  */
  YYSYMBOL_IVOID = 26,                     /* IVOID  */
  YYSYMBOL_ICRASH = 27,                    /* ICRASH  */
  YYSYMBOL_IQUIT = 28,                     /* IQUIT  */
  YYSYMBOL_IHALT = 29,                     /* IHALT  */
  YYSYMBOL_IPRINT = 30,                    /* IPRINT  */
  YYSYMBOL_IPRINTLN = 31,                  /* IPRINTLN  */
  YYSYMBOL_IREAD = 32,                     /* IREAD  */
  YYSYMBOL_ILOAD = 33,                     /* ILOAD  */
  YYSYMBOL_ISTORE = 34,                    /* ISTORE  */
  YYSYMBOL_ILOADC = 35,                    /* ILOADC  */
  YYSYMBOL_ISTOREC = 36,                   /* ISTOREC  */
  YYSYMBOL_IELOAD = 37,                    /* IELOAD  */
  YYSYMBOL_IESTORE = 38,                   /* IESTORE  */
  YYSYMBOL_IELOADC = 39,                   /* IELOADC  */
  YYSYMBOL_IESTOREC = 40,                  /* IESTOREC  */
  YYSYMBOL_IVLOAD = 41,                    /* IVLOAD  */
  YYSYMBOL_IVSTORE = 42,                   /* IVSTORE  */
  YYSYMBOL_IVLOADC = 43,                   /* IVLOADC  */
  YYSYMBOL_IVSTOREC = 44,                  /* IVSTOREC  */
  YYSYMBOL_ISTOREA = 45,                   /* ISTOREA  */
  YYSYMBOL_IMODT = 46,                     /* IMODT  */
  YYSYMBOL_IMODCT = 47,                    /* IMODCT  */
  YYSYMBOL_IADD = 48,                      /* IADD  */
  YYSYMBOL_ISUB = 49,                      /* ISUB  */
  YYSYMBOL_IMUL = 50,                      /* IMUL  */
  YYSYMBOL_IDIV = 51,                      /* IDIV  */
  YYSYMBOL_IMOD = 52,                      /* IMOD  */
  YYSYMBOL_IPOW = 53,                      /* IPOW  */
  YYSYMBOL_IROOT = 54,                     /* IROOT  */
  YYSYMBOL_IINC = 55,                      /* IINC  */
  YYSYMBOL_IDEC = 56,                      /* IDEC  */
  YYSYMBOL_IEQU = 57,                      /* IEQU  */
  YYSYMBOL_INEQU = 58,                     /* INEQU  */
  YYSYMBOL_IGTR = 59,                      /* IGTR  */
  YYSYMBOL_ILSS = 60,                      /* ILSS  */
  YYSYMBOL_IGEQU = 61,                     /* IGEQU  */
  YYSYMBOL_ILEQU = 62,                     /* ILEQU  */
  YYSYMBOL_IAND = 63,                      /* IAND  */
  YYSYMBOL_IOR = 64,                       /* IOR  */
  YYSYMBOL_INOT = 65,                      /* INOT  */
  YYSYMBOL_IGOTO = 66,                     /* IGOTO  */
  YYSYMBOL_ICGOTO = 67,                    /* ICGOTO  */
  YYSYMBOL_IZGOTO = 68,                    /* IZGOTO  */
  YYSYMBOL_IPGOTO = 69,                    /* IPGOTO  */
  YYSYMBOL_INGOTO = 70,                    /* INGOTO  */
  YYSYMBOL_IGOTOL = 71,                    /* IGOTOL  */
  YYSYMBOL_ICGOTOL = 72,                   /* ICGOTOL  */
  YYSYMBOL_IZGOTOL = 73,                   /* IZGOTOL  */
  YYSYMBOL_IPGOTOL = 74,                   /* IPGOTOL  */
  YYSYMBOL_INGOTOL = 75,                   /* INGOTOL  */
  YYSYMBOL_IST = 76,                       /* IST  */
  YYSYMBOL_IPUSH = 77,                     /* IPUSH  */
  YYSYMBOL_IPOP = 78,                      /* IPOP  */
  YYSYMBOL_ICALL = 79,                     /* ICALL  */
  YYSYMBOL_ICALLL = 80,                    /* ICALLL  */
  YYSYMBOL_IRET = 81,                      /* IRET  */
  YYSYMBOL_IVAR = 82,                      /* IVAR  */
  YYSYMBOL_ILBL = 83,                      /* ILBL  */
  YYSYMBOL_IEPRINT = 84,                   /* IEPRINT  */
  YYSYMBOL_IEPRINTLN = 85,                 /* IEPRINTLN  */
  YYSYMBOL_IEND = 86,                      /* IEND  */
  YYSYMBOL_IELBL = 87,                     /* IELBL  */
  YYSYMBOL_IEVLOAD = 88,                   /* IEVLOAD  */
  YYSYMBOL_IHEADD = 89,                    /* IHEADD  */
  YYSYMBOL_IHEREM = 90,                    /* IHEREM  */
  YYSYMBOL_IHEED = 91,                     /* IHEED  */
  YYSYMBOL_IHEGET = 92,                    /* IHEGET  */
  YYSYMBOL_ISHEADD = 93,                   /* ISHEADD  */
  YYSYMBOL_ISHEREM = 94,                   /* ISHEREM  */
  YYSYMBOL_ISHEED = 95,                    /* ISHEED  */
  YYSYMBOL_ISHEGET = 96,                   /* ISHEGET  */
  YYSYMBOL_IEADD = 97,                     /* IEADD  */
  YYSYMBOL_IEREM = 98,                     /* IEREM  */
  YYSYMBOL_IEED = 99,                      /* IEED  */
  YYSYMBOL_IEGET = 100,                    /* IEGET  */
  YYSYMBOL_IEXADD = 101,                   /* IEXADD  */
  YYSYMBOL_IEXREM = 102,                   /* IEXREM  */
  YYSYMBOL_IEXED = 103,                    /* IEXED  */
  YYSYMBOL_IEXGET = 104,                   /* IEXGET  */
  YYSYMBOL_IIADD = 105,                    /* IIADD  */
  YYSYMBOL_IIREM = 106,                    /* IIREM  */
  YYSYMBOL_IIED = 107,                     /* IIED  */
  YYSYMBOL_IIGET = 108,                    /* IIGET  */
  YYSYMBOL_IHEVENT = 109,                  /* IHEVENT  */
  YYSYMBOL_ISHEVENT = 110,                 /* ISHEVENT  */
  YYSYMBOL_IEVENT = 111,                   /* IEVENT  */
  YYSYMBOL_IEXCEPTION = 112,               /* IEXCEPTION  */
  YYSYMBOL_IINT = 113,                     /* IINT  */
  YYSYMBOL_ITYPEOF = 114,                  /* ITYPEOF  */
  YYSYMBOL_ICTYPEOF = 115,                 /* ICTYPEOF  */
  YYSYMBOL_ITLOAD = 116,                   /* ITLOAD  */
  YYSYMBOL_IALOAD = 117,                   /* IALOAD  */
  YYSYMBOL_IINLOAD = 118,                  /* IINLOAD  */
  YYSYMBOL_IICLOAD = 119,                  /* IICLOAD  */
  YYSYMBOL_IARLOAD = 120,                  /* IARLOAD  */
  YYSYMBOL_IATOC = 121,                    /* IATOC  */
  YYSYMBOL_ISWITCH = 122,                  /* ISWITCH  */
  YYSYMBOL_IVADD = 123,                    /* IVADD  */
  YYSYMBOL_ILADD = 124,                    /* ILADD  */
  YYSYMBOL_IELADD = 125,                   /* IELADD  */
  YYSYMBOL_IADD2V = 126,                   /* IADD2V  */
  YYSYMBOL_IBTAND = 127,                   /* IBTAND  */
  YYSYMBOL_IBTOR = 128,                    /* IBTOR  */
  YYSYMBOL_IBTEXOR = 129,                  /* IBTEXOR  */
  YYSYMBOL_IBTNOT = 130,                   /* IBTNOT  */
  YYSYMBOL_IBTSL = 131,                    /* IBTSL  */
  YYSYMBOL_IBTSR = 132,                    /* IBTSR  */
  YYSYMBOL_IVCHECK = 133,                  /* IVCHECK  */
  YYSYMBOL_IVSUPP = 134,                   /* IVSUPP  */
  YYSYMBOL_IVPRINT = 135,                  /* IVPRINT  */
  YYSYMBOL_IVPRINTLN = 136,                /* IVPRINTLN  */
  YYSYMBOL_IISUPP = 137,                   /* IISUPP  */
  YYSYMBOL_ITSUPP = 138,                   /* ITSUPP  */
  YYSYMBOL_ICOMMENT = 139,                 /* ICOMMENT  */
  YYSYMBOL_IFIMODE = 140,                  /* IFIMODE  */
  YYSYMBOL_IFOMODE = 141,                  /* IFOMODE  */
  YYSYMBOL_IFIOPEN = 142,                  /* IFIOPEN  */
  YYSYMBOL_IFOOPEN = 143,                  /* IFOOPEN  */
  YYSYMBOL_IFREAD = 144,                   /* IFREAD  */
  YYSYMBOL_IFPRINT = 145,                  /* IFPRINT  */
  YYSYMBOL_IFPRINTLN = 146,                /* IFPRINTLN  */
  YYSYMBOL_IFICLOSE = 147,                 /* IFICLOSE  */
  YYSYMBOL_IFOCLOSE = 148,                 /* IFOCLOSE  */
  YYSYMBOL_IMEML = 149,                    /* IMEML  */
  YYSYMBOL_IFIEOF = 150,                   /* IFIEOF  */
  YYSYMBOL_IARNLOAD = 151,                 /* IARNLOAD  */
  YYSYMBOL_IRDSTART1 = 152,                /* IRDSTART1  */
  YYSYMBOL_IRFROM1 = 153,                  /* IRFROM1  */
  YYSYMBOL_IRTO1 = 154,                    /* IRTO1  */
  YYSYMBOL_IRDEND1 = 155,                  /* IRDEND1  */
  YYSYMBOL_IRSTART1 = 156,                 /* IRSTART1  */
  YYSYMBOL_IRANGE1 = 157,                  /* IRANGE1  */
  YYSYMBOL_IREND1 = 158,                   /* IREND1  */
  YYSYMBOL_IRLOAD1 = 159,                  /* IRLOAD1  */
  YYSYMBOL_IRSTORE1 = 160,                 /* IRSTORE1  */
  YYSYMBOL_IHEADDB = 161,                  /* IHEADDB  */
  YYSYMBOL_ISHEADDB = 162,                 /* ISHEADDB  */
  YYSYMBOL_IEADDB = 163,                   /* IEADDB  */
  YYSYMBOL_IEXADDB = 164,                  /* IEXADDB  */
  YYSYMBOL_IIADDB = 165,                   /* IIADDB  */
  YYSYMBOL_IRDSTART2 = 166,                /* IRDSTART2  */
  YYSYMBOL_IRFROM2 = 167,                  /* IRFROM2  */
  YYSYMBOL_IRTO2 = 168,                    /* IRTO2  */
  YYSYMBOL_IRDEND2 = 169,                  /* IRDEND2  */
  YYSYMBOL_IRSTART2 = 170,                 /* IRSTART2  */
  YYSYMBOL_IRANGE2 = 171,                  /* IRANGE2  */
  YYSYMBOL_IRPREP2 = 172,                  /* IRPREP2  */
  YYSYMBOL_IRLOAD2 = 173,                  /* IRLOAD2  */
  YYSYMBOL_IESTART = 174,                  /* IESTART  */
  YYSYMBOL_IENAME = 175,                   /* IENAME  */
  YYSYMBOL_IEEND = 176,                    /* IEEND  */
  YYSYMBOL_IENUMS = 177,                   /* IENUMS  */
  YYSYMBOL_IENUM = 178,                    /* IENUM  */
  YYSYMBOL_ISENUM = 179,                   /* ISENUM  */
  YYSYMBOL_IEPREP = 180,                   /* IEPREP  */
  YYSYMBOL_ILOADE = 181,                   /* ILOADE  */
  YYSYMBOL_ISTOREE = 182,                  /* ISTOREE  */
  YYSYMBOL_IASTART = 183,                  /* IASTART  */
  YYSYMBOL_IAEND = 184,                    /* IAEND  */
  YYSYMBOL_IAPREP = 185,                   /* IAPREP  */
  YYSYMBOL_IAIPREP = 186,                  /* IAIPREP  */
  YYSYMBOL_ILOADIA = 187,                  /* ILOADIA  */
  YYSYMBOL_ISTOREIA = 188,                 /* ISTOREIA  */
  YYSYMBOL_IALENGTH = 189,                 /* IALENGTH  */
  YYSYMBOL_IAPRINT = 190,                  /* IAPRINT  */
  YYSYMBOL_IDUP = 191,                     /* IDUP  */
  YYSYMBOL_ICDUP = 192,                    /* ICDUP  */
  YYSYMBOL_IIF = 193,                      /* IIF  */
  YYSYMBOL_IENDIF = 194,                   /* IENDIF  */
  YYSYMBOL_IIFELSE = 195,                  /* IIFELSE  */
  YYSYMBOL_IENDIFELSE = 196,               /* IENDIFELSE  */
  YYSYMBOL_IEIF = 197,                     /* IEIF  */
  YYSYMBOL_IIFBEGIN = 198,                 /* IIFBEGIN  */
  YYSYMBOL_IIFEND = 199,                   /* IIFEND  */
  YYSYMBOL_ISWITCH2 = 200,                 /* ISWITCH2  */
  YYSYMBOL_ISWBEGIN = 201,                 /* ISWBEGIN  */
  YYSYMBOL_ISWEND = 202,                   /* ISWEND  */
  YYSYMBOL_ISWCASE = 203,                  /* ISWCASE  */
  YYSYMBOL_ISWCBEGIN = 204,                /* ISWCBEGIN  */
  YYSYMBOL_ISWCEND = 205,                  /* ISWCEND  */
  YYSYMBOL_ISWDEFAULT = 206,               /* ISWDEFAULT  */
  YYSYMBOL_ISWBREAK = 207,                 /* ISWBREAK  */
  YYSYMBOL_ILOADSP = 208,                  /* ILOADSP  */
  YYSYMBOL_ISTORESP = 209,                 /* ISTORESP  */
  YYSYMBOL_ILOADSTACK = 210,               /* ILOADSTACK  */
  YYSYMBOL_ISTORESTACK = 211,              /* ISTORESTACK  */
  YYSYMBOL_IATOSP = 212,                   /* IATOSP  */
  YYSYMBOL_ISPTOA = 213,                   /* ISPTOA  */
  YYSYMBOL_IPATCH = 214,                   /* IPATCH  */
  YYSYMBOL_INATIVE = 215,                  /* INATIVE  */
  YYSYMBOL_IFRET = 216,                    /* IFRET  */
  YYSYMBOL_IFCALL = 217,                   /* IFCALL  */
  YYSYMBOL_IFCPARAMS = 218,                /* IFCPARAMS  */
  YYSYMBOL_IFECPARAMS = 219,               /* IFECPARAMS  */
  YYSYMBOL_IFECALL = 220,                  /* IFECALL  */
  YYSYMBOL_IPNUM = 221,                    /* IPNUM  */
  YYSYMBOL_IPARAMF = 222,                  /* IPARAMF  */
  YYSYMBOL_IPARAMF2 = 223,                 /* IPARAMF2  */
  YYSYMBOL_IPARAMF3 = 224,                 /* IPARAMF3  */
  YYSYMBOL_IRNUM = 225,                    /* IRNUM  */
  YYSYMBOL_IRETURNF = 226,                 /* IRETURNF  */
  YYSYMBOL_IRETURNF2 = 227,                /* IRETURNF2  */
  YYSYMBOL_IRETURNF3 = 228,                /* IRETURNF3  */
  YYSYMBOL_IFNAME = 229,                   /* IFNAME  */
  YYSYMBOL_IRETURNV = 230,                 /* IRETURNV  */
  YYSYMBOL_IFNCLOAD = 231,                 /* IFNCLOAD  */
  YYSYMBOL_IFNCSTORE = 232,                /* IFNCSTORE  */
  YYSYMBOL_IFNCNEW = 233,                  /* IFNCNEW  */
  YYSYMBOL_IFNCDELETE = 234,               /* IFNCDELETE  */
  YYSYMBOL_IFNCSNAME = 235,                /* IFNCSNAME  */
  YYSYMBOL_IFNCSRET = 236,                 /* IFNCSRET  */
  YYSYMBOL_IFNCSPARAM = 237,               /* IFNCSPARAM  */
  YYSYMBOL_IFNCSDEF = 238,                 /* IFNCSDEF  */
  YYSYMBOL_IFNCGNAME = 239,                /* IFNCGNAME  */
  YYSYMBOL_IFNCGRET = 240,                 /* IFNCGRET  */
  YYSYMBOL_IFNCGPARAM = 241,               /* IFNCGPARAM  */
  YYSYMBOL_IFNCGDEF = 242,                 /* IFNCGDEF  */
  YYSYMBOL_IFNCPOINT = 243,                /* IFNCPOINT  */
  YYSYMBOL_IFNCLENGTH = 244,               /* IFNCLENGTH  */
  YYSYMBOL_IFNCSYNCR = 245,                /* IFNCSYNCR  */
  YYSYMBOL_IFNCFIND = 246,                 /* IFNCFIND  */
  YYSYMBOL_IFNCFRET = 247,                 /* IFNCFRET  */
  YYSYMBOL_IFNCFPARAM = 248,               /* IFNCFPARAM  */
  YYSYMBOL_IFNCFBRET = 249,                /* IFNCFBRET  */
  YYSYMBOL_IFNCFBPARAM = 250,              /* IFNCFBPARAM  */
  YYSYMBOL_IFNCDEFAULT = 251,              /* IFNCDEFAULT  */
  YYSYMBOL_IFNCDEFAULT2 = 252,             /* IFNCDEFAULT2  */
  YYSYMBOL_IFNCSDEFAULTV = 253,            /* IFNCSDEFAULTV  */
  YYSYMBOL_IFNCSDEFAULTV2 = 254,           /* IFNCSDEFAULTV2  */
  YYSYMBOL_IFNCGDEFAULTV2 = 255,           /* IFNCGDEFAULTV2  */
  YYSYMBOL_IFNCDEFAULTSYNC = 256,          /* IFNCDEFAULTSYNC  */
  YYSYMBOL_INTIMES = 257,                  /* INTIMES  */
  YYSYMBOL_ICMP = 258,                     /* ICMP  */
  YYSYMBOL_IRUN = 259,                     /* IRUN  */
  YYSYMBOL_IJRUN = 260,                    /* IJRUN  */
  YYSYMBOL_IPNFRUN = 261,                  /* IPNFRUN  */
  YYSYMBOL_ISTRUCT = 262,                  /* ISTRUCT  */
  YYSYMBOL_ISTRUCTVAR = 263,               /* ISTRUCTVAR  */
  YYSYMBOL_IENDSTRUCT = 264,               /* IENDSTRUCT  */
  YYSYMBOL_ISTRUCTNAME = 265,              /* ISTRUCTNAME  */
  YYSYMBOL_ISTRUCTONAME = 266,             /* ISTRUCTONAME  */
  YYSYMBOL_ISTRUCTD = 267,                 /* ISTRUCTD  */
  YYSYMBOL_ISTRUCTUSE = 268,               /* ISTRUCTUSE  */
  YYSYMBOL_ISTRUCTUSING = 269,             /* ISTRUCTUSING  */
  YYSYMBOL_ISTRUCTUSINGNAME = 270,         /* ISTRUCTUSINGNAME  */
  YYSYMBOL_ISTRUCTGET = 271,               /* ISTRUCTGET  */
  YYSYMBOL_ISTRUCTPUT = 272,               /* ISTRUCTPUT  */
  YYSYMBOL_ISTRUCTTYPE = 273,              /* ISTRUCTTYPE  */
  YYSYMBOL_ISTRUCTTYPE2 = 274,             /* ISTRUCTTYPE2  */
  YYSYMBOL_ISTRUCTNAME2 = 275,             /* ISTRUCTNAME2  */
  YYSYMBOL_ISTRUCTNAME3 = 276,             /* ISTRUCTNAME3  */
  YYSYMBOL_IUNION = 277,                   /* IUNION  */
  YYSYMBOL_IUNIONVAR = 278,                /* IUNIONVAR  */
  YYSYMBOL_IENDUNION = 279,                /* IENDUNION  */
  YYSYMBOL_IUNIONNAME = 280,               /* IUNIONNAME  */
  YYSYMBOL_IUNIONONAME = 281,              /* IUNIONONAME  */
  YYSYMBOL_IUNIOND = 282,                  /* IUNIOND  */
  YYSYMBOL_IUNIONUSE = 283,                /* IUNIONUSE  */
  YYSYMBOL_IUNIONUSING = 284,              /* IUNIONUSING  */
  YYSYMBOL_IUNIONUSINGNAME = 285,          /* IUNIONUSINGNAME  */
  YYSYMBOL_IUNIONGET = 286,                /* IUNIONGET  */
  YYSYMBOL_IUNIONPUT = 287,                /* IUNIONPUT  */
  YYSYMBOL_IUNIONTYPE = 288,               /* IUNIONTYPE  */
  YYSYMBOL_IUNIONTYPE2 = 289,              /* IUNIONTYPE2  */
  YYSYMBOL_IUNIONNAME2 = 290,              /* IUNIONNAME2  */
  YYSYMBOL_IUNIONNAME3 = 291,              /* IUNIONNAME3  */
  YYSYMBOL_IMODE = 292,                    /* IMODE  */
  YYSYMBOL_IEXTMODE = 293,                 /* IEXTMODE  */
  YYSYMBOL_IMCHECK = 294,                  /* IMCHECK  */
  YYSYMBOL_IMSUPP = 295,                   /* IMSUPP  */
  YYSYMBOL_IMEXTCHECK = 296,               /* IMEXTCHECK  */
  YYSYMBOL_IMEXTSUPP = 297,                /* IMEXTSUPP  */
  YYSYMBOL_ICPY = 298,                     /* ICPY  */
  YYSYMBOL_IADDSEG = 299,                  /* IADDSEG  */
  YYSYMBOL_IREMSEG = 300,                  /* IREMSEG  */
  YYSYMBOL_ICOLLSEG = 301,                 /* ICOLLSEG  */
  YYSYMBOL_IEXPSEG = 302,                  /* IEXPSEG  */
  YYSYMBOL_ICPYSEG = 303,                  /* ICPYSEG  */
  YYSYMBOL_ISEGLOAD = 304,                 /* ISEGLOAD  */
  YYSYMBOL_ISEGSTORE = 305,                /* ISEGSTORE  */
  YYSYMBOL_ISEGPUSH = 306,                 /* ISEGPUSH  */
  YYSYMBOL_ISEGPOP = 307,                  /* ISEGPOP  */
  YYSYMBOL_ISEGTOP = 308,                  /* ISEGTOP  */
  YYSYMBOL_ISEGVLOAD = 309,                /* ISEGVLOAD  */
  YYSYMBOL_ISEGVSTORE = 310,               /* ISEGVSTORE  */
  YYSYMBOL_IMSG = 311,                     /* IMSG  */
  YYSYMBOL_IWHILE = 312,                   /* IWHILE  */
  YYSYMBOL_IWHILEB = 313,                  /* IWHILEB  */
  YYSYMBOL_IWHILEE = 314,                  /* IWHILEE  */
  YYSYMBOL_IWHILEBB = 315,                 /* IWHILEBB  */
  YYSYMBOL_IWHILEBBB = 316,                /* IWHILEBBB  */
  YYSYMBOL_IWHILEBBE = 317,                /* IWHILEBBE  */
  YYSYMBOL_IUNTIL = 318,                   /* IUNTIL  */
  YYSYMBOL_IUNTILB = 319,                  /* IUNTILB  */
  YYSYMBOL_IUNTILE = 320,                  /* IUNTILE  */
  YYSYMBOL_IUNTILBB = 321,                 /* IUNTILBB  */
  YYSYMBOL_IUNTILBBB = 322,                /* IUNTILBBB  */
  YYSYMBOL_IUNTILBBE = 323,                /* IUNTILBBE  */
  YYSYMBOL_IFOR = 324,                     /* IFOR  */
  YYSYMBOL_IFORINIT = 325,                 /* IFORINIT  */
  YYSYMBOL_IFORCOND = 326,                 /* IFORCOND  */
  YYSYMBOL_IFORINC = 327,                  /* IFORINC  */
  YYSYMBOL_IFORB = 328,                    /* IFORB  */
  YYSYMBOL_IFORE = 329,                    /* IFORE  */
  YYSYMBOL_ICLASS = 330,                   /* ICLASS  */
  YYSYMBOL_ICLASSVAR = 331,                /* ICLASSVAR  */
  YYSYMBOL_IENDCLASS = 332,                /* IENDCLASS  */
  YYSYMBOL_ICLASSNAME = 333,               /* ICLASSNAME  */
  YYSYMBOL_ICLASSONAME = 334,              /* ICLASSONAME  */
  YYSYMBOL_ICLASSD = 335,                  /* ICLASSD  */
  YYSYMBOL_ICLASSUSE = 336,                /* ICLASSUSE  */
  YYSYMBOL_ICLASSUSING = 337,              /* ICLASSUSING  */
  YYSYMBOL_ICLASSUSINGNAME = 338,          /* ICLASSUSINGNAME  */
  YYSYMBOL_ICLASSGET = 339,                /* ICLASSGET  */
  YYSYMBOL_ICLASSPUT = 340,                /* ICLASSPUT  */
  YYSYMBOL_ICLASSTYPE = 341,               /* ICLASSTYPE  */
  YYSYMBOL_ICLASSTYPE2 = 342,              /* ICLASSTYPE2  */
  YYSYMBOL_ICLASSNAME2 = 343,              /* ICLASSNAME2  */
  YYSYMBOL_ICLASSNAME3 = 344,              /* ICLASSNAME3  */
  YYSYMBOL_ICLASSMETHOD = 345,             /* ICLASSMETHOD  */
  YYSYMBOL_ICLASSMETHOD2 = 346,            /* ICLASSMETHOD2  */
  YYSYMBOL_ICLASSMETHODCALL = 347,         /* ICLASSMETHODCALL  */
  YYSYMBOL_ICLASSMETHODCPARAMS = 348,      /* ICLASSMETHODCPARAMS  */
  YYSYMBOL_ICLASSMETHODECPARAMS = 349,     /* ICLASSMETHODECPARAMS  */
  YYSYMBOL_ICLASSMETHODECALL = 350,        /* ICLASSMETHODECALL  */
  YYSYMBOL_ICLASSEXTENDACCESS = 351,       /* ICLASSEXTENDACCESS  */
  YYSYMBOL_ICLASSEXTEND = 352,             /* ICLASSEXTEND  */
  YYSYMBOL_ICLASSIMPLEMENTACCESS = 353,    /* ICLASSIMPLEMENTACCESS  */
  YYSYMBOL_ICLASSIMPLEMENT = 354,          /* ICLASSIMPLEMENT  */
  YYSYMBOL_TVOID = 355,                    /* TVOID  */
  YYSYMBOL_TBOOLEAN = 356,                 /* TBOOLEAN  */
  YYSYMBOL_TNUMBER = 357,                  /* TNUMBER  */
  YYSYMBOL_TCHARACTER = 358,               /* TCHARACTER  */
  YYSYMBOL_TSTRING = 359,                  /* TSTRING  */
  YYSYMBOL_VOID = 360,                     /* VOID  */
  YYSYMBOL_BOOLEAN = 361,                  /* BOOLEAN  */
  YYSYMBOL_NUMBER = 362,                   /* NUMBER  */
  YYSYMBOL_CHARACTER = 363,                /* CHARACTER  */
  YYSYMBOL_STRING = 364,                   /* STRING  */
  YYSYMBOL_365_n_ = 365,                   /* '\n'  */
  YYSYMBOL_366_ = 366,                     /* "<"  */
  YYSYMBOL_367_ = 367,                     /* ">"  */
  YYSYMBOL_YYACCEPT = 368,                 /* $accept  */
  YYSYMBOL_input = 369,                    /* input  */
  YYSYMBOL_line = 370,                     /* line  */
  YYSYMBOL_instruction = 371,              /* instruction  */
  YYSYMBOL_pinstruction = 372,             /* pinstruction  */
  YYSYMBOL_variable = 373,                 /* variable  */
  YYSYMBOL_pp = 374,                       /* pp  */
  YYSYMBOL_directive = 375                 /* directive  */
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
#define YYLAST   1462

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  368
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  549
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1401

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   621


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     365,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     366,   367
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1200,  1200,  1201,  1204,  1205,  1206,  1207,  1208,  1209,
    1210,  1213,  1214,  1215,  1216,  1224,  1225,  1226,  1227,  1228,
    1234,  1235,  1240,  1249,  1250,  1256,  1257,  1262,  1271,  1272,
    1273,  1274,  1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,
    1283,  1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,
    1293,  1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,
    1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,  1320,  1325,  1331,
    1332,  1333,  1334,  1335,  1336,  1337,  1338,  1339,  1340,  1341,
    1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,
    1352,  1353,  1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,
    1367,  1368,  1375,  1376,  1383,  1384,  1391,  1392,  1399,  1400,
    1401,  1402,  1403,  1404,  1411,  1413,  1414,  1420,  1421,  1427,
    1428,  1433,  1443,  1444,  1450,  1451,  1456,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,
    1479,  1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,
    1489,  1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,
    1505,  1506,  1512,  1522,  1523,  1524,  1525,  1526,  1527,  1528,
    1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,
    1545,  1546,  1552,  1562,  1563,  1570,  1571,  1577,  1587,  1588,
    1589,  1590,  1591,  1601,  1611,  1621,  1622,  1632,  1633,  1643,
    1644,  1645,  1646,  1647,  1648,  1654,  1655,  1660,  1669,  1670,
    1676,  1677,  1682,  1691,  1692,  1693,  1694,  1695,  1696,  1705,
    1706,  1707,  1708,  1717,  1718,  1727,  1736,  1745,  1746,  1747,
    1748,  1749,  1750,  1759,  1760,  1761,  1762,  1771,  1780,  1789,
    1790,  1799,  1808,  1809,  1818,  1827,  1836,  1845,  1846,  1847,
    1856,  1857,  1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,
    1874,  1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,
    1884,  1885,  1886,  1887,  1888,  1889,  1890,  1891,  1896,  1905,
    1906,  1907,  1908,  1909,  1910,  1911,  1912,  1913,  1914,  1915,
    1916,  1925,  1926,  1935,  1936,  1937,  1938,  1939,  1940,  1947,
    1948,  1954,  1961,  1962,  1963,  1964,  1965,  1966,  1967,  1968,
    1969,  1970,  1971,  1972,  1973,  1974,  1975,  1976,  1977,  1978,
    1979,  1980,  1981,  1982,  1983,  1984,  1985,  1986,  1988,  1995,
    1996,  1997,  1998,  1999,  2000,  2001,  2002,  2003,  2004,  2005,
    2006,  2007,  2008,  2009,  2010,  2011,  2012,  2013,  2019,  2020,
    2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,
    2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,
    2041,  2042,  2043,  2044,  2045,  2046,  2047,  2048,  2049,  2050,
    2051,  2060,  2069,  2078,  2087,  2096,  2097,  2106,  2115,  2124,
    2127,  2130,  2139,  2142,  2145,  2148,  2152,  2155,  2158,  2161,
    2165,  2174,  2183,  2184,  2193,  2202,  2211,  2214,  2217,  2226,
    2229,  2232,  2235,  2239,  2242,  2245,  2248,  2252,  2256,  2260,
    2261,  2268,  2269,  2275,  2285,  2286,  2293,  2294,  2300,  2310,
    2311,  2318,  2319,  2325,  2335,  2336,  2343,  2344,  2350,  2361,
    2365,  2369,  2373,  2375,  2377,  2381,  2383,  2385,  2389,  2393,
    2396,  2397,  2398,  2399,  2400,  2401,  2402,  2403,  2404,  2405,
    2406,  2407,  2408,  2409,  2410,  2411,  2412,  2413,  2414,  2415,
    2416,  2417,  2418,  2419,  2420,  2421,  2430,  2439,  2440,  2449,
    2458,  2467,  2470,  2473,  2482,  2485,  2488,  2491,  2495,  2498,
    2501,  2504,  2507,  2508,  2517,  2526,  2527,  2528,  2529,  2538,
    2547,  2556,  2566,  2567,  2574,  2577,  2578,  2585,  2586,  2592,
    2599,  2600,  2601,  2602,  2603,  2610,  2617,  2624,  2634,  2635,
    2636,  2637,  2638,  2639,  2640,  2641,  2642,  2643,  2644,  2645,
    2646,  2647,  2648,  2649,  2650,  2651,  2652,  2655,  2656,  2657
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
  "\"end of file\"", "error", "\"invalid token\"", "ASMVERSION", "PNF",
  "BIN", "PBIN", "LIB", "PINCLUDE", "PIMPORT", "PDEFINE", "PMACRO",
  "PENDM", "PUNDEF", "PIFDEF", "PIFNDEF", "PELSE", "PENDIF", "PPDATE",
  "PPTIME", "PPLINE", "PPFILE", "PPCDATE", "PPCTIME", "PPCOMMENT",
  "IVERSION", "IVOID", "ICRASH", "IQUIT", "IHALT", "IPRINT", "IPRINTLN",
  "IREAD", "ILOAD", "ISTORE", "ILOADC", "ISTOREC", "IELOAD", "IESTORE",
  "IELOADC", "IESTOREC", "IVLOAD", "IVSTORE", "IVLOADC", "IVSTOREC",
  "ISTOREA", "IMODT", "IMODCT", "IADD", "ISUB", "IMUL", "IDIV", "IMOD",
  "IPOW", "IROOT", "IINC", "IDEC", "IEQU", "INEQU", "IGTR", "ILSS",
  "IGEQU", "ILEQU", "IAND", "IOR", "INOT", "IGOTO", "ICGOTO", "IZGOTO",
  "IPGOTO", "INGOTO", "IGOTOL", "ICGOTOL", "IZGOTOL", "IPGOTOL", "INGOTOL",
  "IST", "IPUSH", "IPOP", "ICALL", "ICALLL", "IRET", "IVAR", "ILBL",
  "IEPRINT", "IEPRINTLN", "IEND", "IELBL", "IEVLOAD", "IHEADD", "IHEREM",
  "IHEED", "IHEGET", "ISHEADD", "ISHEREM", "ISHEED", "ISHEGET", "IEADD",
  "IEREM", "IEED", "IEGET", "IEXADD", "IEXREM", "IEXED", "IEXGET", "IIADD",
  "IIREM", "IIED", "IIGET", "IHEVENT", "ISHEVENT", "IEVENT", "IEXCEPTION",
  "IINT", "ITYPEOF", "ICTYPEOF", "ITLOAD", "IALOAD", "IINLOAD", "IICLOAD",
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
  "ISEGTOP", "ISEGVLOAD", "ISEGVSTORE", "IMSG", "IWHILE", "IWHILEB",
  "IWHILEE", "IWHILEBB", "IWHILEBBB", "IWHILEBBE", "IUNTIL", "IUNTILB",
  "IUNTILE", "IUNTILBB", "IUNTILBBB", "IUNTILBBE", "IFOR", "IFORINIT",
  "IFORCOND", "IFORINC", "IFORB", "IFORE", "ICLASS", "ICLASSVAR",
  "IENDCLASS", "ICLASSNAME", "ICLASSONAME", "ICLASSD", "ICLASSUSE",
  "ICLASSUSING", "ICLASSUSINGNAME", "ICLASSGET", "ICLASSPUT", "ICLASSTYPE",
  "ICLASSTYPE2", "ICLASSNAME2", "ICLASSNAME3", "ICLASSMETHOD",
  "ICLASSMETHOD2", "ICLASSMETHODCALL", "ICLASSMETHODCPARAMS",
  "ICLASSMETHODECPARAMS", "ICLASSMETHODECALL", "ICLASSEXTENDACCESS",
  "ICLASSEXTEND", "ICLASSIMPLEMENTACCESS", "ICLASSIMPLEMENT", "TVOID",
  "TBOOLEAN", "TNUMBER", "TCHARACTER", "TSTRING", "VOID", "BOOLEAN",
  "NUMBER", "CHARACTER", "STRING", "'\\n'", "\"<\"", "\">\"", "$accept",
  "input", "line", "instruction", "pinstruction", "variable", "pp",
  "directive", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-354)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -354,     0,  -354,  -354,  -353,    -7,  -354,  -354,  -354,   223,
     224,   143,   183,  -354,   260,   262,   263,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,   195,   196,   227,   236,
     265,     1,    11,     5,   198,   267,   202,   268,   206,   270,
     210,   273,   214,   237,   218,   240,   274,    16,    21,   151,
     241,   244,   245,   248,   249,   252,   253,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   171,   176,   177,   178,   179,   290,   291,   292,
     293,   184,   294,    26,   185,    31,    36,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,    41,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,    46,    51,   341,   342,   343,   344,
     345,   346,   347,   186,   187,   222,    56,    61,   348,   352,
     353,   354,   355,   356,   357,   359,   358,   360,   361,   362,
     363,   364,   365,   369,   370,   371,   372,   373,   374,   376,
     375,   377,   378,   379,   382,   381,   383,   380,   384,   385,
     386,   387,   392,   393,   390,   394,   391,   256,   397,    66,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,    71,   412,   413,   414,   415,   416,
     417,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     430,   432,   431,    76,    81,    86,   433,    91,    96,   101,
     434,   436,   435,   257,   439,   440,   441,   106,   111,   258,
     442,   443,   444,   447,   448,   449,   450,   451,   116,   121,
     452,   453,   454,   455,   126,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   470,   467,   468,   469,   156,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   157,   488,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   131,   136,   141,   146,   501,
     502,   503,   504,   505,   508,   507,   509,   510,   512,   513,
     226,   261,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   162,   539,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   557,   555,   556,   558,   559,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,   351,   350,  -354,   418,  -354,   473,   541,
    -354,  -354,  -354,  -354,   259,   368,   542,   367,   429,   438,
     560,   419,   437,   561,   562,   563,   564,   565,   566,   567,
     568,   570,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   602,   601,
     603,   604,   605,   606,   609,   608,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   571,
     600,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     666,   668,   669,   670,   671,   667,   674,   188,   163,   158,
     165,   189,   675,   672,   677,   678,   676,   679,   680,   681,
     682,   683,   684,   685,   686,   688,   689,   690,   693,   692,
     695,   694,   697,   696,   699,   698,   701,   700,   703,   702,
     705,   704,   707,   706,   709,   708,   711,   710,   712,   713,
     714,   715,   718,   719,   720,   721,   722,   723,   687,   724,
     726,   727,   728,   729,   731,   730,   732,   733,   736,   737,
     738,   739,   740,   741,   742,   743,   745,   746,   744,   747,
     748,   751,   752,   750,   753,   749,   755,   754,   756,   757,
     758,   759,   760,   761,   764,   762,   767,   768,   769,   770,
     771,   772,   773,   774,   775,   776,   777,   778,   779,   780,
     781,   783,   785,   786,   787,   784,   788,   789,   792,   790,
     791,   793,   794,   795,   798,   799,   800,   801,   802,   803,
     804,   806,   796,   805,   807,   808,   811,   810,   812,   815,
     813,   814,   816,   817,   819,   822,   820,   821,   823,   825,
     824,   828,   829,   830,   831,   832,   833,   834,   835,   836,
     837,   838,   839,   840,   841,   842,   843,   844,   845,   846,
     847,   848,   809,   849,   850,   851,   852,   854,   856,   857,
     858,   859,   862,   863,   864,   865,   866,   855,   867,   868,
     869,   870,   871,   872,   873,   874,   875,   876,   877,   878,
     880,   882,   883,   884,   885,   886,   887,   888,   889,   890,
     891,   893,   894,   895,   896,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   910,   909,   911,
     914,   915,   916,   917,   918,   919,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   930,   929,   931,   934,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   951,   952,   953,   954,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   964,   965,
     966,   967,   972,   969,   970,   971,   976,   977,   974,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,   991,   992,   993,   997,   994,   999,  1000,  1001,  1002,
    1003,  1004,  1005,  1006,  1007,  1008,  1009,  1011,  1012,  1010,
    1013,  1014,  1017,  1018,  1016,  1019,  1020,  1023,  1024,  1022,
    1025,  1026,  1029,  1030,  1028,  1031,  1015,  1021,  1027,  1032,
    1034,  1033,  1035,  1036,  1039,  1040,  1041,  1042,  1043,  1044,
    1045,  1048,  1047,  1049,  1050,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,
    1067,  1068,  1038,  1069,  1070,  1071,  1072,  1073,  1074,  1078,
    1075,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1095,  1093,  1094,  1096,  1097,  -354,
    1100,   471,   673,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,    10,     0,     0,   547,   548,   549,     0,
       0,     0,     0,   534,     0,     0,     0,   538,   539,   540,
     541,   542,   543,   544,   545,   546,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     4,     3,     5,     6,
       7,     8,     9,     0,     0,   528,     0,   530,     0,     0,
     533,   535,   536,   537,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   512,
       0,     0,     0,   532,    11,    12,    13,    14,    15,    16,
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
     117,   118,   119,   120,   121,   122,   123,   124,   515,   524,
     520,   516,   525,   521,   517,   526,   522,   518,   527,   523,
     519,   125,   126,   127,   128,   129,   130,   131,   132,   133,
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
     254,   255,   256,   257,   258,   259,   260,   261,   263,   262,
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
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   513,   529,
     531
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   357,   358,   359,   360,   361,   362
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,     3,   363,     4,     5,     6,     7,     8,     9,    10,
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
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   364,   380,   381,   382,   383,
     384,   390,   391,   392,   393,   356,   385,   386,   387,   388,
     389,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   487,   488,   489,   490,   491,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   535,   536,   537,   538,
     539,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   632,   633,   634,   635,   636,   651,   652,   653,   654,
     655,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,   713,   714,   715,   716,   717,   718,   719,   720,   721,
     722,   733,   734,   735,   736,   737,   738,   739,   740,   741,
     742,   747,   748,   749,   750,   751,   796,   797,   798,   799,
     800,   801,   802,   803,   804,   805,   806,   807,   808,   809,
     810,   811,   812,   813,   814,   815,   437,   369,   438,   439,
     440,   766,   783,   767,   784,   768,   785,   858,  1003,   859,
    1004,   860,  1005,  1000,  1001,  1006,   470,  1002,  1007,  1008,
     471,   472,   474,   476,   478,   473,   475,   477,   479,   484,
     492,   572,   574,   485,   493,   573,   575,   370,   998,  1009,
     374,   375,   999,  1010,   394,   395,   396,   397,   399,   400,
     401,   402,   404,   405,   406,   407,   409,   410,   411,   412,
     414,   415,   416,   417,   420,   421,   422,   423,   576,   577,
     578,   579,   827,   828,   829,   830,   376,   365,   367,   366,
     368,   377,   418,   378,   419,   424,   441,   425,   442,   443,
     445,   444,   446,   447,   449,   448,   450,   451,   453,   452,
     454,   629,   708,   630,   709,   723,   831,   724,   832,   884,
     379,   885,   398,   403,   371,   408,   372,   373,   413,   426,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   480,   481,   482,   483,   486,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   565,   566,     0,     0,
     567,   568,     0,   590,   569,   570,   571,   591,   592,   593,
     594,   879,   880,   598,   596,   595,   597,     0,   600,   599,
     604,   601,   602,   603,   605,   606,   607,   608,   886,   888,
     612,   610,   609,   611,     0,   619,   613,   614,   615,   616,
     617,     0,   618,   620,   621,   622,   623,   624,   625,   626,
     628,   627,   631,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   656,   657,   658,
     659,     0,     0,   660,   661,   662,   663,   664,   665,   666,
     892,   668,   881,   670,   667,   671,   669,   672,   673,   889,
     689,   706,   707,   705,   710,   711,   712,   725,   890,   893,
     726,   727,   728,   729,   730,   731,   732,   743,   744,   745,
     746,   752,   753,   754,   755,   756,     0,     0,     0,     0,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   769,
     770,   771,   772,   773,   774,   775,   776,   882,  1399,   779,
       0,   777,   778,   786,   780,   781,   782,   787,   788,   789,
     790,   791,   792,   793,   794,   795,   816,   817,   818,     0,
       0,   819,   820,   821,   822,   824,   823,   825,   826,   833,
     834,   835,   836,   837,   838,   839,   840,   841,   842,   843,
     844,   845,   846,   847,   848,   849,   850,   851,     0,     0,
     854,     0,   852,   853,   861,   855,   856,   857,   862,   863,
     864,   865,   866,   867,   868,   883,   887,   869,   872,   873,
     870,   871,   874,     0,   875,   876,     0,   877,   878,     0,
     891,     0,     0,   896,   894,   897,   895,   898,   901,   899,
     902,   900,   903,   904,   950,     0,   905,   906,   907,   908,
     909,   910,   911,   912,   913,   914,   915,   916,   917,   918,
     919,   920,   921,   922,   923,   924,     0,     0,   925,   926,
     927,   928,   929,   930,   951,   931,   932,   933,   934,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,     0,   952,   949,   954,   953,   956,   955,
     958,   957,   960,   959,   962,   961,   964,   963,   965,   966,
     967,   968,   969,   970,   971,   972,   973,   974,   975,     0,
       0,   976,   977,   978,   979,   980,   981,     0,   983,   982,
     985,   984,   987,   986,   989,   988,   991,   990,   992,   993,
       0,   996,   994,   995,   997,  1011,  1012,  1013,  1015,  1014,
    1400,  1018,  1016,  1019,  1017,  1020,  1023,  1021,  1024,  1022,
    1057,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,     0,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,  1054,     0,  1055,     0,  1056,  1059,  1060,  1058,  1062,
    1061,  1063,  1064,     0,  1065,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,  1073,     0,     0,  1074,  1075,  1077,  1076,  1084,
    1079,  1078,  1080,  1082,  1081,  1085,  1086,  1083,  1087,     0,
    1091,  1088,  1089,  1090,  1093,  1092,  1094,  1095,  1096,  1097,
    1098,  1099,     0,  1100,     0,  1101,  1104,  1102,  1105,  1103,
    1106,  1109,  1107,  1110,  1108,  1111,  1112,  1113,  1114,     0,
    1115,  1116,  1117,  1119,  1118,     0,  1131,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,     0,  1129,  1128,  1130,  1132,
    1171,  1133,  1134,  1135,  1136,  1138,  1137,  1139,  1140,  1143,
    1141,  1142,  1144,  1146,  1145,  1148,  1149,  1147,  1150,  1151,
    1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,
    1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,     0,
       0,  1172,  1175,  1173,  1176,  1174,  1177,  1178,     0,  1186,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1187,     0,  1189,
    1190,  1191,  1188,  1193,  1192,  1194,     0,  1195,  1198,  1196,
    1199,  1197,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,
       0,  1209,  1208,  1210,  1211,  1212,  1213,  1214,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,     0,  1225,  1227,
       0,  1224,  1226,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,     0,     0,  1242,
    1244,  1245,  1243,  1246,  1247,  1248,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,
    1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
    1273,  1274,  1275,     0,     0,     0,     0,  1276,  1277,  1278,
    1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,
    1289,  1290,  1291,  1292,  1293,  1294,  1295,     0,     0,  1298,
       0,  1296,  1297,  1302,  1299,  1300,  1301,  1303,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1312,     0,     0,  1313,
    1314,  1315,  1316,  1318,  1317,  1335,  1320,  1319,  1321,  1323,
    1322,  1336,  1325,  1324,  1326,  1328,  1327,  1337,  1330,  1329,
    1331,  1333,  1332,  1340,  1338,  1334,  1339,  1341,  1342,  1343,
    1344,  1345,  1371,     0,  1346,  1347,  1348,  1349,  1350,  1351,
    1353,  1352,  1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,
    1362,  1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,     0,
    1373,     0,     0,  1372,  1377,  1374,  1375,  1376,  1378,  1379,
    1380,  1381,  1382,  1383,  1384,  1385,  1386,  1387,     0,     0,
    1388,  1391,  1392,  1389,  1390,  1393,     0,  1394,  1395,     0,
    1396,  1397,  1398
};

static const yytype_int16 yycheck[] =
{
       0,     1,   355,     3,     4,     5,     6,     7,     8,     9,
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
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   362,   355,   356,   357,   358,
     359,   356,   357,   358,   359,   365,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   364,   357,   358,
     359,   355,   355,   357,   357,   359,   359,   355,   360,   357,
     362,   359,   364,   360,   361,   360,   355,   364,   363,   364,
     359,   355,   355,   355,   355,   359,   359,   359,   359,   355,
     355,   355,   355,   359,   359,   359,   359,   364,   360,   360,
     355,   355,   364,   364,   356,   357,   358,   359,   356,   357,
     358,   359,   356,   357,   358,   359,   356,   357,   358,   359,
     356,   357,   358,   359,   356,   357,   358,   359,   356,   357,
     358,   359,   356,   357,   358,   359,   359,   364,   364,   366,
     366,   355,   355,   357,   357,   355,   355,   357,   357,   355,
     355,   357,   357,   355,   355,   357,   357,   355,   355,   357,
     357,   355,   355,   357,   357,   357,   355,   359,   357,   360,
     355,   362,   355,   355,   364,   355,   364,   364,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,    -1,    -1,
     357,   357,    -1,   355,   359,   359,   359,   355,   355,   355,
     355,   360,   362,   355,   357,   359,   357,    -1,   357,   359,
     355,   359,   359,   359,   355,   355,   355,   355,   360,   362,
     355,   357,   359,   357,    -1,   355,   359,   359,   359,   357,
     359,    -1,   359,   359,   359,   359,   359,   355,   355,   359,
     359,   357,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,    -1,    -1,   357,   357,   355,   355,   355,   355,   355,
     361,   355,   364,   355,   359,   355,   359,   355,   357,   360,
     357,   355,   357,   359,   355,   355,   355,   355,   360,   362,
     357,   357,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,    -1,    -1,    -1,    -1,
     359,   359,   359,   359,   359,   355,   359,   359,   359,   355,
     355,   355,   355,   355,   355,   355,   355,   364,   367,   355,
      -1,   359,   359,   355,   359,   359,   359,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,    -1,
      -1,   357,   357,   355,   357,   355,   357,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,    -1,    -1,
     355,    -1,   359,   359,   355,   359,   359,   359,   355,   355,
     355,   355,   355,   355,   355,   364,   364,   357,   355,   355,
     359,   359,   355,    -1,   359,   359,    -1,   359,   359,    -1,
     360,    -1,    -1,   360,   363,   361,   364,   362,   360,   363,
     360,   364,   360,   360,   363,    -1,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,    -1,    -1,   362,   362,
     362,   362,   360,   362,   364,   362,   362,   362,   362,   360,
     362,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,    -1,   360,   362,   360,   362,   360,   362,
     360,   362,   360,   362,   360,   362,   360,   362,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,    -1,
      -1,   362,   362,   362,   362,   362,   362,    -1,   362,   364,
     362,   364,   362,   364,   362,   364,   360,   364,   360,   360,
      -1,   364,   362,   362,   360,   360,   364,   360,   362,   361,
     367,   360,   363,   361,   364,   362,   360,   363,   360,   364,
     363,   362,   362,   360,   362,   360,   362,   360,   362,   360,
     362,   360,   362,   360,   362,   360,   362,   360,   362,   360,
     362,   360,   362,    -1,   362,   362,   362,   362,   360,   360,
     360,   360,    -1,   361,    -1,   362,   360,   360,   364,   360,
     362,   360,   362,    -1,   362,   362,   360,   360,   360,   360,
     360,   360,   360,    -1,    -1,   362,   361,   363,   362,   360,
     362,   364,   361,   363,   362,   360,   362,   364,   362,    -1,
     360,   364,   364,   364,   360,   364,   364,   360,   360,   360,
     360,   360,    -1,   361,    -1,   362,   360,   363,   361,   364,
     362,   360,   363,   360,   364,   360,   360,   360,   364,    -1,
     362,   362,   360,   362,   364,    -1,   360,   364,   364,   364,
     362,   362,   362,   362,   362,    -1,   362,   364,   362,   364,
     361,   364,   364,   362,   364,   360,   364,   364,   364,   360,
     364,   364,   360,   362,   364,   360,   362,   364,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,    -1,
      -1,   362,   360,   363,   360,   364,   360,   360,    -1,   364,
     362,   362,   360,   360,   360,   360,   360,   360,    -1,   360,
     360,   360,   364,   360,   362,   361,    -1,   362,   360,   363,
     360,   364,   360,   360,   360,   360,   360,   360,   360,   360,
      -1,   360,   362,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,    -1,   360,   360,
      -1,   364,   362,   362,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,    -1,    -1,   362,
     360,   362,   364,   362,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,    -1,    -1,    -1,    -1,   364,   364,   364,
     364,   364,   360,   364,   364,   364,   360,   360,   364,   360,
     360,   360,   360,   360,   360,   360,   360,    -1,    -1,   360,
      -1,   364,   364,   360,   364,   364,   364,   360,   364,   360,
     360,   360,   360,   360,   360,   360,   360,    -1,    -1,   362,
     362,   362,   361,   363,   362,   360,   362,   364,   361,   363,
     362,   360,   362,   364,   361,   363,   362,   360,   362,   364,
     361,   363,   362,   360,   362,   364,   362,   362,   362,   360,
     360,   360,   364,    -1,   362,   362,   362,   362,   360,   362,
     360,   362,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,    -1,
     360,    -1,    -1,   364,   360,   364,   364,   364,   360,   364,
     360,   360,   360,   360,   360,   360,   360,   360,    -1,    -1,
     362,   360,   360,   364,   364,   360,    -1,   364,   364,    -1,
     364,   364,   362
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   369,     0,     1,     3,     4,     5,     6,     7,     8,
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
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   365,   370,   371,   372,
     373,   374,   375,   355,   362,   364,   366,   364,   366,   364,
     364,   364,   364,   364,   355,   355,   359,   355,   357,   355,
     355,   356,   357,   358,   359,   355,   356,   357,   358,   359,
     356,   357,   358,   359,   356,   357,   358,   359,   355,   356,
     357,   358,   359,   355,   356,   357,   358,   359,   355,   356,
     357,   358,   359,   355,   356,   357,   358,   359,   355,   357,
     356,   357,   358,   359,   355,   357,   355,   355,   356,   357,
     358,   359,   355,   356,   357,   358,   359,   355,   357,   358,
     359,   355,   357,   355,   357,   355,   357,   355,   357,   355,
     357,   355,   357,   355,   357,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   359,   355,   359,   355,   359,   355,   359,   355,   359,
     355,   355,   355,   355,   355,   359,   355,   355,   356,   357,
     358,   359,   355,   359,   355,   356,   357,   358,   359,   355,
     356,   357,   358,   359,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   356,   357,   358,   359,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   356,   357,   358,   359,
     355,   356,   357,   358,   359,   355,   355,   357,   357,   359,
     359,   359,   355,   359,   355,   359,   356,   357,   358,   359,
     355,   356,   357,   358,   359,   355,   356,   357,   358,   359,
     355,   355,   355,   355,   355,   359,   357,   357,   355,   359,
     357,   359,   359,   359,   355,   355,   355,   355,   355,   359,
     357,   357,   355,   359,   359,   359,   357,   359,   359,   355,
     359,   359,   359,   359,   355,   355,   359,   357,   359,   355,
     357,   355,   355,   356,   357,   358,   359,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   356,   357,   358,   359,   355,   355,   355,   355,
     357,   357,   355,   355,   355,   355,   355,   359,   355,   359,
     355,   355,   355,   357,   355,   356,   357,   358,   359,   355,
     356,   357,   358,   359,   355,   356,   357,   358,   359,   357,
     355,   356,   357,   358,   359,   355,   356,   357,   358,   359,
     355,   356,   357,   358,   359,   359,   355,   357,   355,   357,
     355,   355,   355,   355,   356,   357,   358,   359,   355,   356,
     357,   358,   359,   357,   359,   355,   357,   357,   355,   355,
     355,   355,   355,   355,   356,   357,   358,   359,   355,   356,
     357,   358,   359,   355,   355,   355,   355,   355,   356,   357,
     358,   359,   355,   355,   355,   355,   355,   359,   359,   359,
     359,   359,   355,   359,   359,   359,   355,   357,   359,   355,
     355,   355,   355,   355,   355,   355,   355,   359,   359,   355,
     359,   359,   359,   355,   357,   359,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   356,   357,   358,
     359,   355,   356,   357,   358,   359,   355,   355,   355,   357,
     357,   355,   357,   357,   355,   355,   355,   356,   357,   358,
     359,   355,   357,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   359,   359,   355,   359,   359,   359,   355,   357,
     359,   355,   355,   355,   355,   355,   355,   355,   355,   357,
     359,   359,   355,   355,   355,   359,   359,   359,   359,   360,
     362,   364,   364,   364,   360,   362,   360,   364,   362,   360,
     360,   360,   361,   362,   363,   364,   360,   361,   362,   363,
     364,   360,   360,   360,   360,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   362,   362,   362,   362,   360,
     362,   362,   362,   362,   362,   360,   362,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   362,
     363,   364,   360,   362,   360,   362,   360,   362,   360,   362,
     360,   362,   360,   362,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   362,   362,   362,   362,
     362,   362,   364,   362,   364,   362,   364,   362,   364,   362,
     364,   360,   360,   360,   362,   362,   364,   360,   360,   364,
     360,   361,   364,   360,   362,   364,   360,   363,   364,   360,
     364,   360,   364,   360,   361,   362,   363,   364,   360,   361,
     362,   363,   364,   360,   360,   362,   362,   360,   362,   360,
     362,   360,   362,   360,   362,   360,   362,   360,   362,   360,
     362,   360,   362,   360,   362,   360,   362,   362,   362,   362,
     362,   360,   360,   360,   360,   361,   362,   363,   364,   360,
     360,   362,   360,   360,   362,   362,   362,   360,   360,   360,
     360,   360,   360,   360,   362,   361,   362,   363,   364,   362,
     361,   362,   363,   364,   360,   360,   362,   362,   364,   364,
     364,   360,   364,   360,   364,   360,   360,   360,   360,   360,
     361,   362,   363,   364,   360,   361,   362,   363,   364,   360,
     360,   360,   360,   360,   364,   362,   362,   360,   364,   362,
     364,   364,   364,   362,   362,   362,   362,   362,   364,   362,
     362,   360,   364,   364,   364,   362,   364,   364,   360,   364,
     364,   364,   364,   360,   360,   364,   362,   364,   360,   362,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   361,   362,   363,   364,   360,   360,   360,   360,   362,
     362,   360,   360,   360,   360,   360,   364,   360,   364,   360,
     360,   360,   362,   360,   361,   362,   363,   364,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   362,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   364,   360,   362,   360,   362,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   362,   364,   360,   362,   362,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   364,   364,   364,   364,
     364,   360,   364,   364,   364,   360,   360,   364,   360,   360,
     360,   360,   360,   360,   360,   360,   364,   364,   360,   364,
     364,   364,   360,   360,   364,   360,   360,   360,   360,   360,
     360,   360,   360,   362,   362,   362,   361,   362,   363,   364,
     362,   361,   362,   363,   364,   362,   361,   362,   363,   364,
     362,   361,   362,   363,   364,   360,   360,   360,   362,   362,
     360,   362,   362,   360,   360,   360,   362,   362,   362,   362,
     360,   362,   362,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   364,   364,   360,   364,   364,   364,   360,   360,   364,
     360,   360,   360,   360,   360,   360,   360,   360,   362,   364,
     364,   360,   360,   360,   364,   364,   364,   364,   362,   367,
     367
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   368,   369,   369,   370,   370,   370,   370,   370,   370,
     370,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   372,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   375,   375,   375
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     4,
       2,     4,     3,     2,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 10: /* line: error  */
#line 1210 "pnfasm.ypp"
                                { yyerrok; }
#line 3882 "pnfasm.tab.cpp"
    break;

  case 11: /* instruction: IVERSION TVOID VOID  */
#line 1213 "pnfasm.ypp"
                                        { fprintf(output, "0 0 0\n"); }
#line 3888 "pnfasm.tab.cpp"
    break;

  case 12: /* instruction: IVERSION TVOID NUMBER  */
#line 1214 "pnfasm.ypp"
                                        { fprintf(output, "0 0 %s\n", yyvsp[0].getString().c_str()); }
#line 3894 "pnfasm.tab.cpp"
    break;

  case 13: /* instruction: IVOID TVOID VOID  */
#line 1215 "pnfasm.ypp"
                                        { fprintf(output, "1 0 0\n"); }
#line 3900 "pnfasm.tab.cpp"
    break;

  case 14: /* instruction: ICRASH TSTRING STRING  */
#line 1217 "pnfasm.ypp"
                {
		 fprintf(output, "2 4 ");

		 for (int i = 1; yyvsp[0][i] != '\"'; ++i)
                  fprintf(output, "%i ", yyvsp[0][i]);
		 fprintf(output, "0\n");
		}
#line 3912 "pnfasm.tab.cpp"
    break;

  case 15: /* instruction: IQUIT TVOID NUMBER  */
#line 1224 "pnfasm.ypp"
                                                { fprintf(output, "3 0 %s\n", yyvsp[0].getString().c_str()); }
#line 3918 "pnfasm.tab.cpp"
    break;

  case 16: /* instruction: IQUIT TNUMBER VOID  */
#line 1225 "pnfasm.ypp"
                                                { fprintf(output, "3 2 0\n"); }
#line 3924 "pnfasm.tab.cpp"
    break;

  case 17: /* instruction: IHALT TVOID VOID  */
#line 1226 "pnfasm.ypp"
                                                { fprintf(output, "4 0 0\n"); }
#line 3930 "pnfasm.tab.cpp"
    break;

  case 18: /* instruction: IPRINT TVOID VOID  */
#line 1227 "pnfasm.ypp"
                                                { fprintf(output, "5 0 0\n"); }
#line 3936 "pnfasm.tab.cpp"
    break;

  case 19: /* instruction: IPRINT TBOOLEAN BOOLEAN  */
#line 1228 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "5 1 1\n");
						 else
						  fprintf(output, "5 1 0\n");
					        }
#line 3947 "pnfasm.tab.cpp"
    break;

  case 20: /* instruction: IPRINT TNUMBER NUMBER  */
#line 1234 "pnfasm.ypp"
                                                { fprintf(output, "5 2 %s\n", yyvsp[0].getString().c_str()); }
#line 3953 "pnfasm.tab.cpp"
    break;

  case 21: /* instruction: IPRINT TCHARACTER CHARACTER  */
#line 1235 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "5 3 %i\n", ch);
						}
#line 3963 "pnfasm.tab.cpp"
    break;

  case 22: /* instruction: IPRINT TSTRING STRING  */
#line 1240 "pnfasm.ypp"
                                                {
						 fprintf(output, "5 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 3977 "pnfasm.tab.cpp"
    break;

  case 23: /* instruction: IPRINTLN TVOID VOID  */
#line 1249 "pnfasm.ypp"
                                                { fprintf(output, "6 0 0\n"); }
#line 3983 "pnfasm.tab.cpp"
    break;

  case 24: /* instruction: IPRINTLN TBOOLEAN BOOLEAN  */
#line 1250 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "6 1 1\n");
						 else
						  fprintf(output, "6 1 0\n");
					        }
#line 3994 "pnfasm.tab.cpp"
    break;

  case 25: /* instruction: IPRINTLN TNUMBER NUMBER  */
#line 1256 "pnfasm.ypp"
                                                { fprintf(output, "6 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4000 "pnfasm.tab.cpp"
    break;

  case 26: /* instruction: IPRINTLN TCHARACTER CHARACTER  */
#line 1257 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "6 3 %i\n", ch);
						}
#line 4010 "pnfasm.tab.cpp"
    break;

  case 27: /* instruction: IPRINTLN TSTRING STRING  */
#line 1262 "pnfasm.ypp"
                                                { 
						 fprintf(output, "6 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4024 "pnfasm.tab.cpp"
    break;

  case 28: /* instruction: IREAD TBOOLEAN VOID  */
#line 1271 "pnfasm.ypp"
                                                { fprintf(output, "7 1 0\n"); }
#line 4030 "pnfasm.tab.cpp"
    break;

  case 29: /* instruction: IREAD TNUMBER VOID  */
#line 1272 "pnfasm.ypp"
                                                { fprintf(output, "7 2 0\n"); }
#line 4036 "pnfasm.tab.cpp"
    break;

  case 30: /* instruction: IREAD TCHARACTER VOID  */
#line 1273 "pnfasm.ypp"
                                                { fprintf(output, "7 3 0\n"); }
#line 4042 "pnfasm.tab.cpp"
    break;

  case 31: /* instruction: IREAD TSTRING VOID  */
#line 1274 "pnfasm.ypp"
                                                { fprintf(output, "7 4 0\n"); }
#line 4048 "pnfasm.tab.cpp"
    break;

  case 32: /* instruction: ILOAD TBOOLEAN NUMBER  */
#line 1275 "pnfasm.ypp"
                                                { fprintf(output, "8 1 %s\n", yyvsp[0].getString().c_str()); }
#line 4054 "pnfasm.tab.cpp"
    break;

  case 33: /* instruction: ILOAD TNUMBER NUMBER  */
#line 1276 "pnfasm.ypp"
                                                { fprintf(output, "8 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4060 "pnfasm.tab.cpp"
    break;

  case 34: /* instruction: ILOAD TCHARACTER NUMBER  */
#line 1277 "pnfasm.ypp"
                                                { fprintf(output, "8 3 %s\n", yyvsp[0].getString().c_str()); }
#line 4066 "pnfasm.tab.cpp"
    break;

  case 35: /* instruction: ILOAD TSTRING NUMBER  */
#line 1278 "pnfasm.ypp"
                                                { fprintf(output, "8 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4072 "pnfasm.tab.cpp"
    break;

  case 36: /* instruction: ISTORE TVOID NUMBER  */
#line 1279 "pnfasm.ypp"
                                                { fprintf(output, "9 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4078 "pnfasm.tab.cpp"
    break;

  case 37: /* instruction: ILOADC TBOOLEAN NUMBER  */
#line 1280 "pnfasm.ypp"
                                                { fprintf(output, "10 1 %s\n", yyvsp[0].getString().c_str()); }
#line 4084 "pnfasm.tab.cpp"
    break;

  case 38: /* instruction: ILOADC TNUMBER NUMBER  */
#line 1281 "pnfasm.ypp"
                                                { fprintf(output, "10 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4090 "pnfasm.tab.cpp"
    break;

  case 39: /* instruction: ILOADC TCHARACTER NUMBER  */
#line 1282 "pnfasm.ypp"
                                                { fprintf(output, "10 3 %s\n", yyvsp[0].getString().c_str()); }
#line 4096 "pnfasm.tab.cpp"
    break;

  case 40: /* instruction: ILOADC TSTRING NUMBER  */
#line 1283 "pnfasm.ypp"
                                                { fprintf(output, "10 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4102 "pnfasm.tab.cpp"
    break;

  case 41: /* instruction: ISTOREC TVOID NUMBER  */
#line 1284 "pnfasm.ypp"
                                                { fprintf(output, "11 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4108 "pnfasm.tab.cpp"
    break;

  case 42: /* instruction: IELOAD TBOOLEAN VOID  */
#line 1285 "pnfasm.ypp"
                                                { fprintf(output, "12 1 0\n"); }
#line 4114 "pnfasm.tab.cpp"
    break;

  case 43: /* instruction: IELOAD TNUMBER VOID  */
#line 1286 "pnfasm.ypp"
                                                { fprintf(output, "12 2 0\n"); }
#line 4120 "pnfasm.tab.cpp"
    break;

  case 44: /* instruction: IELOAD TCHARACTER VOID  */
#line 1287 "pnfasm.ypp"
                                                { fprintf(output, "12 3 0\n"); }
#line 4126 "pnfasm.tab.cpp"
    break;

  case 45: /* instruction: IELOAD TSTRING VOID  */
#line 1288 "pnfasm.ypp"
                                                { fprintf(output, "12 4 0\n"); }
#line 4132 "pnfasm.tab.cpp"
    break;

  case 46: /* instruction: IESTORE TVOID VOID  */
#line 1289 "pnfasm.ypp"
                                                { fprintf(output, "13 0 0\n"); }
#line 4138 "pnfasm.tab.cpp"
    break;

  case 47: /* instruction: IELOADC TBOOLEAN VOID  */
#line 1290 "pnfasm.ypp"
                                                { fprintf(output, "14 1 0\n"); }
#line 4144 "pnfasm.tab.cpp"
    break;

  case 48: /* instruction: IELOADC TNUMBER VOID  */
#line 1291 "pnfasm.ypp"
                                                { fprintf(output, "14 2 0\n"); }
#line 4150 "pnfasm.tab.cpp"
    break;

  case 49: /* instruction: IELOADC TCHARACTER VOID  */
#line 1292 "pnfasm.ypp"
                                                { fprintf(output, "14 3 0\n"); }
#line 4156 "pnfasm.tab.cpp"
    break;

  case 50: /* instruction: IELOADC TSTRING VOID  */
#line 1293 "pnfasm.ypp"
                                                { fprintf(output, "14 4 0\n"); }
#line 4162 "pnfasm.tab.cpp"
    break;

  case 51: /* instruction: IESTOREC TVOID VOID  */
#line 1294 "pnfasm.ypp"
                                                { fprintf(output, "15 0 0\n"); }
#line 4168 "pnfasm.tab.cpp"
    break;

  case 52: /* instruction: IVLOAD TBOOLEAN NUMBER  */
#line 1295 "pnfasm.ypp"
                                                { fprintf(output, "16 1 %s\n", yyvsp[0].getString().c_str()); }
#line 4174 "pnfasm.tab.cpp"
    break;

  case 53: /* instruction: IVLOAD TNUMBER NUMBER  */
#line 1296 "pnfasm.ypp"
                                                { fprintf(output, "16 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4180 "pnfasm.tab.cpp"
    break;

  case 54: /* instruction: IVLOAD TCHARACTER NUMBER  */
#line 1297 "pnfasm.ypp"
                                                { fprintf(output, "16 3 %s\n", yyvsp[0].getString().c_str()); }
#line 4186 "pnfasm.tab.cpp"
    break;

  case 55: /* instruction: IVLOAD TSTRING NUMBER  */
#line 1298 "pnfasm.ypp"
                                                { fprintf(output, "16 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4192 "pnfasm.tab.cpp"
    break;

  case 56: /* instruction: IVSTORE TVOID VOID  */
#line 1299 "pnfasm.ypp"
                                                { fprintf(output, "17 0 0\n"); }
#line 4198 "pnfasm.tab.cpp"
    break;

  case 57: /* instruction: IVSTORE TNUMBER NUMBER  */
#line 1300 "pnfasm.ypp"
                                                { fprintf(output, "17 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4204 "pnfasm.tab.cpp"
    break;

  case 58: /* instruction: IVLOADC TBOOLEAN NUMBER  */
#line 1301 "pnfasm.ypp"
                                                { fprintf(output, "18 1 %s\n", yyvsp[0].getString().c_str()); }
#line 4210 "pnfasm.tab.cpp"
    break;

  case 59: /* instruction: IVLOADC TNUMBER NUMBER  */
#line 1302 "pnfasm.ypp"
                                                { fprintf(output, "18 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4216 "pnfasm.tab.cpp"
    break;

  case 60: /* instruction: IVLOADC TCHARACTER NUMBER  */
#line 1303 "pnfasm.ypp"
                                                { fprintf(output, "18 3 %s\n", yyvsp[0].getString().c_str()); }
#line 4222 "pnfasm.tab.cpp"
    break;

  case 61: /* instruction: IVLOADC TSTRING NUMBER  */
#line 1304 "pnfasm.ypp"
                                                { fprintf(output, "18 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4228 "pnfasm.tab.cpp"
    break;

  case 62: /* instruction: IVSTOREC TVOID VOID  */
#line 1305 "pnfasm.ypp"
                                                { fprintf(output, "19 0 0\n"); }
#line 4234 "pnfasm.tab.cpp"
    break;

  case 63: /* instruction: IVSTOREC TNUMBER NUMBER  */
#line 1306 "pnfasm.ypp"
                                                { fprintf(output, "19 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4240 "pnfasm.tab.cpp"
    break;

  case 64: /* instruction: ISTOREA TVOID VOID  */
#line 1307 "pnfasm.ypp"
                                                { fprintf(output, "20 0 0\n"); }
#line 4246 "pnfasm.tab.cpp"
    break;

  case 65: /* instruction: IMODT TVOID VOID  */
#line 1308 "pnfasm.ypp"
                                                { fprintf(output, "21 0 0\n"); }
#line 4252 "pnfasm.tab.cpp"
    break;

  case 66: /* instruction: IMODT TBOOLEAN VOID  */
#line 1309 "pnfasm.ypp"
                                                { fprintf(output, "21 1 0\n"); }
#line 4258 "pnfasm.tab.cpp"
    break;

  case 67: /* instruction: IMODT TNUMBER VOID  */
#line 1310 "pnfasm.ypp"
                                                { fprintf(output, "21 2 0\n"); }
#line 4264 "pnfasm.tab.cpp"
    break;

  case 68: /* instruction: IMODT TCHARACTER VOID  */
#line 1311 "pnfasm.ypp"
                                                { fprintf(output, "21 3 0\n"); }
#line 4270 "pnfasm.tab.cpp"
    break;

  case 69: /* instruction: IMODT TSTRING VOID  */
#line 1312 "pnfasm.ypp"
                                                { fprintf(output, "21 4 0\n"); }
#line 4276 "pnfasm.tab.cpp"
    break;

  case 70: /* instruction: IMODCT TVOID VOID  */
#line 1313 "pnfasm.ypp"
                                                { fprintf(output, "22 0 0\n"); }
#line 4282 "pnfasm.tab.cpp"
    break;

  case 71: /* instruction: IMODCT TBOOLEAN VOID  */
#line 1314 "pnfasm.ypp"
                                                { fprintf(output, "22 1 0\n"); }
#line 4288 "pnfasm.tab.cpp"
    break;

  case 72: /* instruction: IMODCT TNUMBER VOID  */
#line 1315 "pnfasm.ypp"
                                                { fprintf(output, "22 2 0\n"); }
#line 4294 "pnfasm.tab.cpp"
    break;

  case 73: /* instruction: IMODCT TCHARACTER VOID  */
#line 1316 "pnfasm.ypp"
                                                { fprintf(output, "22 3 0\n"); }
#line 4300 "pnfasm.tab.cpp"
    break;

  case 74: /* instruction: IMODCT TSTRING VOID  */
#line 1317 "pnfasm.ypp"
                                                { fprintf(output, "22 4 0\n"); }
#line 4306 "pnfasm.tab.cpp"
    break;

  case 75: /* instruction: IADD TVOID VOID  */
#line 1318 "pnfasm.ypp"
                                                { fprintf(output, "23 0 0\n"); }
#line 4312 "pnfasm.tab.cpp"
    break;

  case 76: /* instruction: IADD TNUMBER NUMBER  */
#line 1319 "pnfasm.ypp"
                                                { fprintf(output, "23 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4318 "pnfasm.tab.cpp"
    break;

  case 77: /* instruction: IADD TCHARACTER CHARACTER  */
#line 1320 "pnfasm.ypp"
                                                        {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "23 3 %i\n", ch);
						}
#line 4328 "pnfasm.tab.cpp"
    break;

  case 78: /* instruction: IADD TSTRING STRING  */
#line 1325 "pnfasm.ypp"
                                                {		
						 fprintf(output, "23 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4339 "pnfasm.tab.cpp"
    break;

  case 79: /* instruction: ISUB TVOID VOID  */
#line 1331 "pnfasm.ypp"
                                                { fprintf(output, "24 0 0\n"); }
#line 4345 "pnfasm.tab.cpp"
    break;

  case 80: /* instruction: ISUB TNUMBER NUMBER  */
#line 1332 "pnfasm.ypp"
                                                { fprintf(output, "24 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4351 "pnfasm.tab.cpp"
    break;

  case 81: /* instruction: IMUL TVOID VOID  */
#line 1333 "pnfasm.ypp"
                                                { fprintf(output, "25 0 0\n"); }
#line 4357 "pnfasm.tab.cpp"
    break;

  case 82: /* instruction: IMUL TNUMBER NUMBER  */
#line 1334 "pnfasm.ypp"
                                                { fprintf(output, "25 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4363 "pnfasm.tab.cpp"
    break;

  case 83: /* instruction: IDIV TVOID VOID  */
#line 1335 "pnfasm.ypp"
                                                { fprintf(output, "26 0 0\n"); }
#line 4369 "pnfasm.tab.cpp"
    break;

  case 84: /* instruction: IDIV TNUMBER NUMBER  */
#line 1336 "pnfasm.ypp"
                                                { fprintf(output, "26 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4375 "pnfasm.tab.cpp"
    break;

  case 85: /* instruction: IMOD TVOID VOID  */
#line 1337 "pnfasm.ypp"
                                                { fprintf(output, "27 0 0\n"); }
#line 4381 "pnfasm.tab.cpp"
    break;

  case 86: /* instruction: IMOD TNUMBER NUMBER  */
#line 1338 "pnfasm.ypp"
                                                { fprintf(output, "27 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4387 "pnfasm.tab.cpp"
    break;

  case 87: /* instruction: IPOW TVOID VOID  */
#line 1339 "pnfasm.ypp"
                                                { fprintf(output, "28 0 0\n"); }
#line 4393 "pnfasm.tab.cpp"
    break;

  case 88: /* instruction: IPOW TNUMBER NUMBER  */
#line 1340 "pnfasm.ypp"
                                                { fprintf(output, "28 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4399 "pnfasm.tab.cpp"
    break;

  case 89: /* instruction: IROOT TVOID VOID  */
#line 1341 "pnfasm.ypp"
                                                { fprintf(output, "29 0 0\n"); }
#line 4405 "pnfasm.tab.cpp"
    break;

  case 90: /* instruction: IROOT TNUMBER NUMBER  */
#line 1342 "pnfasm.ypp"
                                                { fprintf(output, "29 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4411 "pnfasm.tab.cpp"
    break;

  case 91: /* instruction: IINC TVOID VOID  */
#line 1343 "pnfasm.ypp"
                                                { fprintf(output, "30 0 0\n"); }
#line 4417 "pnfasm.tab.cpp"
    break;

  case 92: /* instruction: IINC TNUMBER VOID  */
#line 1344 "pnfasm.ypp"
                                                { fprintf(output, "30 2 0\n"); }
#line 4423 "pnfasm.tab.cpp"
    break;

  case 93: /* instruction: IDEC TVOID VOID  */
#line 1345 "pnfasm.ypp"
                                                { fprintf(output, "31 0 0\n"); }
#line 4429 "pnfasm.tab.cpp"
    break;

  case 94: /* instruction: IEQU TVOID VOID  */
#line 1346 "pnfasm.ypp"
                                                { fprintf(output, "32 0 0\n"); }
#line 4435 "pnfasm.tab.cpp"
    break;

  case 95: /* instruction: INEQU TVOID VOID  */
#line 1347 "pnfasm.ypp"
                                                { fprintf(output, "33 0 0\n"); }
#line 4441 "pnfasm.tab.cpp"
    break;

  case 96: /* instruction: IGTR TVOID VOID  */
#line 1348 "pnfasm.ypp"
                                                { fprintf(output, "34 0 0\n"); }
#line 4447 "pnfasm.tab.cpp"
    break;

  case 97: /* instruction: ILSS TVOID VOID  */
#line 1349 "pnfasm.ypp"
                                                { fprintf(output, "35 0 0\n"); }
#line 4453 "pnfasm.tab.cpp"
    break;

  case 98: /* instruction: IGEQU TVOID VOID  */
#line 1350 "pnfasm.ypp"
                                                { fprintf(output, "36 0 0\n"); }
#line 4459 "pnfasm.tab.cpp"
    break;

  case 99: /* instruction: ILEQU TVOID VOID  */
#line 1351 "pnfasm.ypp"
                                                { fprintf(output, "37 0 0\n"); }
#line 4465 "pnfasm.tab.cpp"
    break;

  case 100: /* instruction: IAND TVOID VOID  */
#line 1352 "pnfasm.ypp"
                                                { fprintf(output, "38 0 0\n"); }
#line 4471 "pnfasm.tab.cpp"
    break;

  case 101: /* instruction: IOR TVOID VOID  */
#line 1353 "pnfasm.ypp"
                                                { fprintf(output, "39 0 0\n"); }
#line 4477 "pnfasm.tab.cpp"
    break;

  case 102: /* instruction: INOT TVOID VOID  */
#line 1354 "pnfasm.ypp"
                                                { fprintf(output, "40 0 0\n"); }
#line 4483 "pnfasm.tab.cpp"
    break;

  case 103: /* instruction: IGOTO TVOID NUMBER  */
#line 1355 "pnfasm.ypp"
                                                { fprintf(output, "41 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4489 "pnfasm.tab.cpp"
    break;

  case 104: /* instruction: ICGOTO TVOID NUMBER  */
#line 1356 "pnfasm.ypp"
                                                { fprintf(output, "42 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4495 "pnfasm.tab.cpp"
    break;

  case 105: /* instruction: IZGOTO TVOID NUMBER  */
#line 1357 "pnfasm.ypp"
                                                { fprintf(output, "43 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4501 "pnfasm.tab.cpp"
    break;

  case 106: /* instruction: IPGOTO TVOID NUMBER  */
#line 1358 "pnfasm.ypp"
                                                { fprintf(output, "44 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4507 "pnfasm.tab.cpp"
    break;

  case 107: /* instruction: INGOTO TVOID NUMBER  */
#line 1359 "pnfasm.ypp"
                                                { fprintf(output, "45 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4513 "pnfasm.tab.cpp"
    break;

  case 108: /* instruction: IGOTOL TVOID NUMBER  */
#line 1360 "pnfasm.ypp"
                                                { fprintf(output, "46 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4519 "pnfasm.tab.cpp"
    break;

  case 109: /* instruction: IGOTOL TSTRING STRING  */
#line 1361 "pnfasm.ypp"
                                                {
						 fprintf(output, "46 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4530 "pnfasm.tab.cpp"
    break;

  case 110: /* instruction: ICGOTOL TVOID NUMBER  */
#line 1367 "pnfasm.ypp"
                                                { fprintf(output, "47 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4536 "pnfasm.tab.cpp"
    break;

  case 111: /* instruction: ICGOTOL TSTRING STRING  */
#line 1369 "pnfasm.ypp"
                                                {
						 fprintf(output, "47 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4547 "pnfasm.tab.cpp"
    break;

  case 112: /* instruction: IZGOTOL TVOID NUMBER  */
#line 1375 "pnfasm.ypp"
                                                { fprintf(output, "48 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4553 "pnfasm.tab.cpp"
    break;

  case 113: /* instruction: IZGOTOL TSTRING STRING  */
#line 1377 "pnfasm.ypp"
                                                {
						 fprintf(output, "48 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4564 "pnfasm.tab.cpp"
    break;

  case 114: /* instruction: IPGOTOL TVOID NUMBER  */
#line 1383 "pnfasm.ypp"
                                                { fprintf(output, "49 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4570 "pnfasm.tab.cpp"
    break;

  case 115: /* instruction: IPGOTOL TSTRING STRING  */
#line 1385 "pnfasm.ypp"
                                                {
						 fprintf(output, "49 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4581 "pnfasm.tab.cpp"
    break;

  case 116: /* instruction: INGOTOL TVOID NUMBER  */
#line 1391 "pnfasm.ypp"
                                                { fprintf(output, "50 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4587 "pnfasm.tab.cpp"
    break;

  case 117: /* instruction: INGOTOL TSTRING STRING  */
#line 1393 "pnfasm.ypp"
                                                {
						 fprintf(output, "50 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4598 "pnfasm.tab.cpp"
    break;

  case 118: /* instruction: IST TVOID VOID  */
#line 1399 "pnfasm.ypp"
                                                { fprintf(output, "51 0 0\n"); }
#line 4604 "pnfasm.tab.cpp"
    break;

  case 119: /* instruction: IPUSH TVOID VOID  */
#line 1400 "pnfasm.ypp"
                                                { fprintf(output, "52 0 0\n"); }
#line 4610 "pnfasm.tab.cpp"
    break;

  case 120: /* instruction: IPOP TVOID VOID  */
#line 1401 "pnfasm.ypp"
                                                { fprintf(output, "53 0 0\n"); }
#line 4616 "pnfasm.tab.cpp"
    break;

  case 121: /* instruction: ICALL TVOID NUMBER  */
#line 1402 "pnfasm.ypp"
                                                { fprintf(output, "54 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4622 "pnfasm.tab.cpp"
    break;

  case 122: /* instruction: ICALLL TVOID NUMBER  */
#line 1403 "pnfasm.ypp"
                                                { fprintf(output, "55 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4628 "pnfasm.tab.cpp"
    break;

  case 123: /* instruction: ICALLL TSTRING STRING  */
#line 1405 "pnfasm.ypp"
                                                {
						 fprintf(output, "55 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4639 "pnfasm.tab.cpp"
    break;

  case 124: /* instruction: IRET TVOID VOID  */
#line 1411 "pnfasm.ypp"
                                                { fprintf(output, "56 0 0\n"); }
#line 4645 "pnfasm.tab.cpp"
    break;

  case 125: /* instruction: ILBL TVOID VOID  */
#line 1413 "pnfasm.ypp"
                                                { fprintf(output, "58 0 0\n"); }
#line 4651 "pnfasm.tab.cpp"
    break;

  case 126: /* instruction: ILBL TSTRING STRING  */
#line 1414 "pnfasm.ypp"
                                                {
						 fprintf(output, "58 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");		
						}
#line 4662 "pnfasm.tab.cpp"
    break;

  case 127: /* instruction: IEPRINT TVOID VOID  */
#line 1420 "pnfasm.ypp"
                                                { fprintf(output, "59 0 0\n"); }
#line 4668 "pnfasm.tab.cpp"
    break;

  case 128: /* instruction: IEPRINT TBOOLEAN BOOLEAN  */
#line 1421 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "59 1 1\n");
						 else
						  fprintf(output, "59 1 0\n");
					        }
#line 4679 "pnfasm.tab.cpp"
    break;

  case 129: /* instruction: IEPRINT TNUMBER NUMBER  */
#line 1427 "pnfasm.ypp"
                                                        { fprintf(output, "59 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4685 "pnfasm.tab.cpp"
    break;

  case 130: /* instruction: IEPRINT TCHARACTER CHARACTER  */
#line 1428 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "59 3 %i\n", ch);
						}
#line 4695 "pnfasm.tab.cpp"
    break;

  case 131: /* instruction: IEPRINT TSTRING STRING  */
#line 1433 "pnfasm.ypp"
                                                { 
						 fprintf(output, "59 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4709 "pnfasm.tab.cpp"
    break;

  case 132: /* instruction: IEPRINTLN TVOID VOID  */
#line 1443 "pnfasm.ypp"
                                                { fprintf(output, "60 0 0\n"); }
#line 4715 "pnfasm.tab.cpp"
    break;

  case 133: /* instruction: IEPRINTLN TBOOLEAN BOOLEAN  */
#line 1444 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "60 1 1\n");
						 else
						  fprintf(output, "60 1 0\n");
					        }
#line 4726 "pnfasm.tab.cpp"
    break;

  case 134: /* instruction: IEPRINTLN TNUMBER NUMBER  */
#line 1450 "pnfasm.ypp"
                                                { fprintf(output, "60 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4732 "pnfasm.tab.cpp"
    break;

  case 135: /* instruction: IEPRINTLN TCHARACTER CHARACTER  */
#line 1451 "pnfasm.ypp"
                                                        {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "60 3 %i\n", ch);
						}
#line 4742 "pnfasm.tab.cpp"
    break;

  case 136: /* instruction: IEPRINTLN TSTRING STRING  */
#line 1456 "pnfasm.ypp"
                                                { 
						 fprintf(output, "60 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4756 "pnfasm.tab.cpp"
    break;

  case 137: /* instruction: IEND TVOID VOID  */
#line 1466 "pnfasm.ypp"
                                                { fprintf(output, "61 0 0"); }
#line 4762 "pnfasm.tab.cpp"
    break;

  case 138: /* instruction: IELBL TVOID VOID  */
#line 1467 "pnfasm.ypp"
                                                { fprintf(output, "62 0 0\n"); }
#line 4768 "pnfasm.tab.cpp"
    break;

  case 139: /* instruction: IEVLOAD TVOID NUMBER  */
#line 1468 "pnfasm.ypp"
                                                { fprintf(output, "63 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4774 "pnfasm.tab.cpp"
    break;

  case 140: /* instruction: IHEADD TVOID NUMBER  */
#line 1469 "pnfasm.ypp"
                                                { fprintf(output, "64 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4780 "pnfasm.tab.cpp"
    break;

  case 141: /* instruction: IHEREM TVOID VOID  */
#line 1470 "pnfasm.ypp"
                                                { fprintf(output, "65 0 0\n"); }
#line 4786 "pnfasm.tab.cpp"
    break;

  case 142: /* instruction: IHEED TVOID NUMBER  */
#line 1471 "pnfasm.ypp"
                                                { fprintf(output, "66 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4792 "pnfasm.tab.cpp"
    break;

  case 143: /* instruction: IHEGET TVOID VOID  */
#line 1472 "pnfasm.ypp"
                                                { fprintf(output, "67 0 0\n"); }
#line 4798 "pnfasm.tab.cpp"
    break;

  case 144: /* instruction: ISHEADD TVOID NUMBER  */
#line 1473 "pnfasm.ypp"
                                                { fprintf(output, "68 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4804 "pnfasm.tab.cpp"
    break;

  case 145: /* instruction: ISHEREM TVOID VOID  */
#line 1474 "pnfasm.ypp"
                                                { fprintf(output, "69 0 0\n"); }
#line 4810 "pnfasm.tab.cpp"
    break;

  case 146: /* instruction: ISHEED TVOID NUMBER  */
#line 1475 "pnfasm.ypp"
                                                { fprintf(output, "70 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4816 "pnfasm.tab.cpp"
    break;

  case 147: /* instruction: ISHEGET TVOID VOID  */
#line 1476 "pnfasm.ypp"
                                                { fprintf(output, "71 0 0\n"); }
#line 4822 "pnfasm.tab.cpp"
    break;

  case 148: /* instruction: IEADD TVOID NUMBER  */
#line 1477 "pnfasm.ypp"
                                                { fprintf(output, "72 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4828 "pnfasm.tab.cpp"
    break;

  case 149: /* instruction: IEREM TVOID VOID  */
#line 1478 "pnfasm.ypp"
                                                { fprintf(output, "73 0 0\n"); }
#line 4834 "pnfasm.tab.cpp"
    break;

  case 150: /* instruction: IEED TVOID NUMBER  */
#line 1479 "pnfasm.ypp"
                                                { fprintf(output, "74 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4840 "pnfasm.tab.cpp"
    break;

  case 151: /* instruction: IEGET TVOID VOID  */
#line 1480 "pnfasm.ypp"
                                                { fprintf(output, "75 0 0\n"); }
#line 4846 "pnfasm.tab.cpp"
    break;

  case 152: /* instruction: IEXADD TVOID NUMBER  */
#line 1481 "pnfasm.ypp"
                                                { fprintf(output, "76 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4852 "pnfasm.tab.cpp"
    break;

  case 153: /* instruction: IEXREM TVOID VOID  */
#line 1482 "pnfasm.ypp"
                                                { fprintf(output, "77 0 0\n"); }
#line 4858 "pnfasm.tab.cpp"
    break;

  case 154: /* instruction: IEXED TVOID NUMBER  */
#line 1483 "pnfasm.ypp"
                                                { fprintf(output, "78 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4864 "pnfasm.tab.cpp"
    break;

  case 155: /* instruction: IEXGET TVOID VOID  */
#line 1484 "pnfasm.ypp"
                                                { fprintf(output, "79 0 0\n"); }
#line 4870 "pnfasm.tab.cpp"
    break;

  case 156: /* instruction: IIADD TVOID NUMBER  */
#line 1485 "pnfasm.ypp"
                                                { fprintf(output, "80 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4876 "pnfasm.tab.cpp"
    break;

  case 157: /* instruction: IIREM TVOID VOID  */
#line 1486 "pnfasm.ypp"
                                                { fprintf(output, "81 0 0\n"); }
#line 4882 "pnfasm.tab.cpp"
    break;

  case 158: /* instruction: IIED TVOID NUMBER  */
#line 1487 "pnfasm.ypp"
                                                { fprintf(output, "82 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4888 "pnfasm.tab.cpp"
    break;

  case 159: /* instruction: IIGET TVOID VOID  */
#line 1488 "pnfasm.ypp"
                                                { fprintf(output, "83 0 0\n"); }
#line 4894 "pnfasm.tab.cpp"
    break;

  case 160: /* instruction: IHEVENT TVOID NUMBER  */
#line 1489 "pnfasm.ypp"
                                                { fprintf(output, "84 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4900 "pnfasm.tab.cpp"
    break;

  case 161: /* instruction: ISHEVENT TVOID NUMBER  */
#line 1490 "pnfasm.ypp"
                                                { fprintf(output, "85 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4906 "pnfasm.tab.cpp"
    break;

  case 162: /* instruction: IEVENT TVOID NUMBER  */
#line 1491 "pnfasm.ypp"
                                                { fprintf(output, "86 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4912 "pnfasm.tab.cpp"
    break;

  case 163: /* instruction: IEXCEPTION TVOID NUMBER  */
#line 1492 "pnfasm.ypp"
                                                { fprintf(output, "87 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4918 "pnfasm.tab.cpp"
    break;

  case 164: /* instruction: IINT TVOID NUMBER  */
#line 1493 "pnfasm.ypp"
                                                { fprintf(output, "88 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4924 "pnfasm.tab.cpp"
    break;

  case 165: /* instruction: ITYPEOF TVOID VOID  */
#line 1494 "pnfasm.ypp"
                                                { fprintf(output, "89 0 0\n"); }
#line 4930 "pnfasm.tab.cpp"
    break;

  case 166: /* instruction: ICTYPEOF TVOID VOID  */
#line 1495 "pnfasm.ypp"
                                                { fprintf(output, "90 0 0\n"); }
#line 4936 "pnfasm.tab.cpp"
    break;

  case 167: /* instruction: ITLOAD TVOID VOID  */
#line 1496 "pnfasm.ypp"
                                                { fprintf(output, "91 0 0\n"); }
#line 4942 "pnfasm.tab.cpp"
    break;

  case 168: /* instruction: IALOAD TVOID VOID  */
#line 1497 "pnfasm.ypp"
                                                { fprintf(output, "92 0 0\n"); }
#line 4948 "pnfasm.tab.cpp"
    break;

  case 169: /* instruction: IALOAD TBOOLEAN BOOLEAN  */
#line 1499 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "92 1 1\n");
		 else
		  fprintf(output, "92 1 0\n");
		}
#line 4959 "pnfasm.tab.cpp"
    break;

  case 170: /* instruction: IALOAD TNUMBER NUMBER  */
#line 1505 "pnfasm.ypp"
                                                { fprintf(output, "92 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4965 "pnfasm.tab.cpp"
    break;

  case 171: /* instruction: IALOAD TCHARACTER CHARACTER  */
#line 1507 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "92 3 %i\n", ch);
		}
#line 4975 "pnfasm.tab.cpp"
    break;

  case 172: /* instruction: IALOAD TSTRING STRING  */
#line 1513 "pnfasm.ypp"
                {
		 fprintf(output, "92 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 4989 "pnfasm.tab.cpp"
    break;

  case 173: /* instruction: IINLOAD TVOID VOID  */
#line 1522 "pnfasm.ypp"
                                                { fprintf(output, "93 0 0\n"); }
#line 4995 "pnfasm.tab.cpp"
    break;

  case 174: /* instruction: IICLOAD TVOID VOID  */
#line 1523 "pnfasm.ypp"
                                                { fprintf(output, "94 0 0\n"); }
#line 5001 "pnfasm.tab.cpp"
    break;

  case 175: /* instruction: IARLOAD TVOID NUMBER  */
#line 1524 "pnfasm.ypp"
                                                { fprintf(output, "95 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5007 "pnfasm.tab.cpp"
    break;

  case 176: /* instruction: IATOC TVOID VOID  */
#line 1525 "pnfasm.ypp"
                                                { fprintf(output, "96 0 0\n"); }
#line 5013 "pnfasm.tab.cpp"
    break;

  case 177: /* instruction: ISWITCH TVOID VOID  */
#line 1526 "pnfasm.ypp"
                                                { fprintf(output, "97 0 0\n"); }
#line 5019 "pnfasm.tab.cpp"
    break;

  case 178: /* instruction: IVADD TVOID NUMBER  */
#line 1527 "pnfasm.ypp"
                                                { fprintf(output, "98 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5025 "pnfasm.tab.cpp"
    break;

  case 179: /* instruction: ILADD TVOID NUMBER  */
#line 1528 "pnfasm.ypp"
                                                { fprintf(output, "99 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5031 "pnfasm.tab.cpp"
    break;

  case 180: /* instruction: IELADD TVOID NUMBER  */
#line 1529 "pnfasm.ypp"
                                                { fprintf(output, "100 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5037 "pnfasm.tab.cpp"
    break;

  case 181: /* instruction: IADD2V TVOID VOID  */
#line 1530 "pnfasm.ypp"
                                                { fprintf(output, "101 0 0\n"); }
#line 5043 "pnfasm.tab.cpp"
    break;

  case 182: /* instruction: IBTAND TVOID VOID  */
#line 1531 "pnfasm.ypp"
                                                { fprintf(output, "102 0 0\n"); }
#line 5049 "pnfasm.tab.cpp"
    break;

  case 183: /* instruction: IBTOR TVOID VOID  */
#line 1532 "pnfasm.ypp"
                                                { fprintf(output, "103 0 0\n"); }
#line 5055 "pnfasm.tab.cpp"
    break;

  case 184: /* instruction: IBTEXOR TVOID VOID  */
#line 1533 "pnfasm.ypp"
                                                { fprintf(output, "104 0 0\n"); }
#line 5061 "pnfasm.tab.cpp"
    break;

  case 185: /* instruction: IBTNOT TVOID VOID  */
#line 1534 "pnfasm.ypp"
                                                { fprintf(output, "105 0 0\n"); }
#line 5067 "pnfasm.tab.cpp"
    break;

  case 186: /* instruction: IBTSL TVOID VOID  */
#line 1535 "pnfasm.ypp"
                                                { fprintf(output, "106 0 0\n"); }
#line 5073 "pnfasm.tab.cpp"
    break;

  case 187: /* instruction: IBTSR TVOID VOID  */
#line 1536 "pnfasm.ypp"
                                                { fprintf(output, "107 0 0\n"); }
#line 5079 "pnfasm.tab.cpp"
    break;

  case 188: /* instruction: IVCHECK TVOID NUMBER  */
#line 1537 "pnfasm.ypp"
                                                { fprintf(output, "108 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5085 "pnfasm.tab.cpp"
    break;

  case 189: /* instruction: IVCHECK TBOOLEAN BOOLEAN  */
#line 1539 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "108 1 1\n");
		 else
		  fprintf(output, "108 1 0\n");
		}
#line 5096 "pnfasm.tab.cpp"
    break;

  case 190: /* instruction: IVCHECK TNUMBER NUMBER  */
#line 1545 "pnfasm.ypp"
                                                { fprintf(output, "108 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5102 "pnfasm.tab.cpp"
    break;

  case 191: /* instruction: IVCHECK TCHARACTER CHARACTER  */
#line 1547 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "108 3 %i\n", ch);
		}
#line 5112 "pnfasm.tab.cpp"
    break;

  case 192: /* instruction: IVCHECK TSTRING STRING  */
#line 1553 "pnfasm.ypp"
                {
		 fprintf(output, "108 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5126 "pnfasm.tab.cpp"
    break;

  case 193: /* instruction: IVSUPP TVOID NUMBER  */
#line 1562 "pnfasm.ypp"
                                                { fprintf(output, "109 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5132 "pnfasm.tab.cpp"
    break;

  case 194: /* instruction: IVSUPP TBOOLEAN BOOLEAN  */
#line 1564 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "109 1 1\n");
		 else
		  fprintf(output, "109 1 0\n");
		}
#line 5143 "pnfasm.tab.cpp"
    break;

  case 195: /* instruction: IVSUPP TNUMBER NUMBER  */
#line 1570 "pnfasm.ypp"
                                        { fprintf(output, "109 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5149 "pnfasm.tab.cpp"
    break;

  case 196: /* instruction: IVSUPP TCHARACTER CHARACTER  */
#line 1572 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "109 3 %i\n", ch);
		}
#line 5159 "pnfasm.tab.cpp"
    break;

  case 197: /* instruction: IVSUPP TSTRING STRING  */
#line 1578 "pnfasm.ypp"
                {
		 fprintf(output, "109 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5173 "pnfasm.tab.cpp"
    break;

  case 198: /* instruction: IVPRINT TVOID VOID  */
#line 1587 "pnfasm.ypp"
                                                { fprintf(output, "110 0 0\n"); }
#line 5179 "pnfasm.tab.cpp"
    break;

  case 199: /* instruction: IVPRINTLN TVOID VOID  */
#line 1588 "pnfasm.ypp"
                                                { fprintf(output, "111 0 0\n"); }
#line 5185 "pnfasm.tab.cpp"
    break;

  case 200: /* instruction: IISUPP TNUMBER NUMBER  */
#line 1589 "pnfasm.ypp"
                                                { fprintf(output, "112 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5191 "pnfasm.tab.cpp"
    break;

  case 201: /* instruction: ITSUPP TNUMBER NUMBER  */
#line 1590 "pnfasm.ypp"
                                                { fprintf(output, "113 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5197 "pnfasm.tab.cpp"
    break;

  case 202: /* instruction: ICOMMENT TSTRING STRING  */
#line 1592 "pnfasm.ypp"
                {
		 fprintf(output, "114 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5211 "pnfasm.tab.cpp"
    break;

  case 203: /* instruction: IFIMODE TSTRING STRING  */
#line 1602 "pnfasm.ypp"
                {
		 fprintf(output, "115 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5225 "pnfasm.tab.cpp"
    break;

  case 204: /* instruction: IFOMODE TSTRING STRING  */
#line 1612 "pnfasm.ypp"
                {
		 fprintf(output, "116 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5239 "pnfasm.tab.cpp"
    break;

  case 205: /* instruction: IFIOPEN TVOID VOID  */
#line 1621 "pnfasm.ypp"
                                                { fprintf(output, "117 0 0\n"); }
#line 5245 "pnfasm.tab.cpp"
    break;

  case 206: /* instruction: IFIOPEN TSTRING STRING  */
#line 1623 "pnfasm.ypp"
                {
		 fprintf(output, "117 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5259 "pnfasm.tab.cpp"
    break;

  case 207: /* instruction: IFOOPEN TVOID VOID  */
#line 1632 "pnfasm.ypp"
                                                { fprintf(output, "118 0 0\n"); }
#line 5265 "pnfasm.tab.cpp"
    break;

  case 208: /* instruction: IFOOPEN TSTRING STRING  */
#line 1634 "pnfasm.ypp"
                {
		 fprintf(output, "118 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5279 "pnfasm.tab.cpp"
    break;

  case 209: /* instruction: IFREAD TBOOLEAN VOID  */
#line 1643 "pnfasm.ypp"
                                                { fprintf(output, "119 1 0\n"); }
#line 5285 "pnfasm.tab.cpp"
    break;

  case 210: /* instruction: IFREAD TNUMBER VOID  */
#line 1644 "pnfasm.ypp"
                                                { fprintf(output, "119 2 0\n"); }
#line 5291 "pnfasm.tab.cpp"
    break;

  case 211: /* instruction: IFREAD TCHARACTER VOID  */
#line 1645 "pnfasm.ypp"
                                                { fprintf(output, "119 3 0\n"); }
#line 5297 "pnfasm.tab.cpp"
    break;

  case 212: /* instruction: IFREAD TSTRING VOID  */
#line 1646 "pnfasm.ypp"
                                                { fprintf(output, "119 4 0\n"); }
#line 5303 "pnfasm.tab.cpp"
    break;

  case 213: /* instruction: IFPRINT TVOID VOID  */
#line 1647 "pnfasm.ypp"
                                                { fprintf(output, "120 0 0\n"); }
#line 5309 "pnfasm.tab.cpp"
    break;

  case 214: /* instruction: IFPRINT TBOOLEAN BOOLEAN  */
#line 1648 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "120 1 1\n");
						 else
						  fprintf(output, "120 1 0\n");
					        }
#line 5320 "pnfasm.tab.cpp"
    break;

  case 215: /* instruction: IFPRINT TNUMBER NUMBER  */
#line 1654 "pnfasm.ypp"
                                                { fprintf(output, "120 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5326 "pnfasm.tab.cpp"
    break;

  case 216: /* instruction: IFPRINT TCHARACTER CHARACTER  */
#line 1655 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "120 3 %i\n", ch);
						}
#line 5336 "pnfasm.tab.cpp"
    break;

  case 217: /* instruction: IFPRINT TSTRING STRING  */
#line 1660 "pnfasm.ypp"
                                                { 
						 fprintf(output, "120 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5350 "pnfasm.tab.cpp"
    break;

  case 218: /* instruction: IFPRINTLN TVOID VOID  */
#line 1669 "pnfasm.ypp"
                                                { fprintf(output, "121 0 0\n"); }
#line 5356 "pnfasm.tab.cpp"
    break;

  case 219: /* instruction: IFPRINTLN TBOOLEAN BOOLEAN  */
#line 1670 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "121 1 1\n");
						 else
						  fprintf(output, "121 1 0\n");
					        }
#line 5367 "pnfasm.tab.cpp"
    break;

  case 220: /* instruction: IFPRINTLN TNUMBER NUMBER  */
#line 1676 "pnfasm.ypp"
                                                { fprintf(output, "121 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5373 "pnfasm.tab.cpp"
    break;

  case 221: /* instruction: IFPRINTLN TCHARACTER CHARACTER  */
#line 1677 "pnfasm.ypp"
                                                        {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "121 3 %i\n", ch);
						}
#line 5383 "pnfasm.tab.cpp"
    break;

  case 222: /* instruction: IFPRINTLN TSTRING STRING  */
#line 1682 "pnfasm.ypp"
                                                { 
						 fprintf(output, "121 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5397 "pnfasm.tab.cpp"
    break;

  case 223: /* instruction: IFICLOSE TVOID VOID  */
#line 1691 "pnfasm.ypp"
                                                { fprintf(output, "122 0 0\n"); }
#line 5403 "pnfasm.tab.cpp"
    break;

  case 224: /* instruction: IFOCLOSE TVOID VOID  */
#line 1692 "pnfasm.ypp"
                                                { fprintf(output, "123 0 0\n"); }
#line 5409 "pnfasm.tab.cpp"
    break;

  case 225: /* instruction: IMEML TVOID VOID  */
#line 1693 "pnfasm.ypp"
                                                { fprintf(output, "124 0 0\n"); }
#line 5415 "pnfasm.tab.cpp"
    break;

  case 226: /* instruction: IFIEOF TVOID VOID  */
#line 1694 "pnfasm.ypp"
                                                { fprintf(output, "125 0 0\n"); }
#line 5421 "pnfasm.tab.cpp"
    break;

  case 227: /* instruction: IARNLOAD TVOID VOID  */
#line 1695 "pnfasm.ypp"
                                                { fprintf(output, "126 0 0\n"); }
#line 5427 "pnfasm.tab.cpp"
    break;

  case 228: /* instruction: IRDSTART1 TSTRING STRING  */
#line 1696 "pnfasm.ypp"
                                                { 
						 fprintf(output, "127 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5441 "pnfasm.tab.cpp"
    break;

  case 229: /* instruction: IRFROM1 TNUMBER NUMBER  */
#line 1705 "pnfasm.ypp"
                                                { fprintf(output, "128 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5447 "pnfasm.tab.cpp"
    break;

  case 230: /* instruction: IRTO1 TNUMBER NUMBER  */
#line 1706 "pnfasm.ypp"
                                                { fprintf(output, "129 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5453 "pnfasm.tab.cpp"
    break;

  case 231: /* instruction: IRDEND1 TVOID VOID  */
#line 1707 "pnfasm.ypp"
                                                { fprintf(output, "130 0 0\n"); }
#line 5459 "pnfasm.tab.cpp"
    break;

  case 232: /* instruction: IRSTART1 TSTRING STRING  */
#line 1708 "pnfasm.ypp"
                                                { 
						 fprintf(output, "131 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5473 "pnfasm.tab.cpp"
    break;

  case 233: /* instruction: IRANGE1 TNUMBER NUMBER  */
#line 1717 "pnfasm.ypp"
                                                { fprintf(output, "132 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5479 "pnfasm.tab.cpp"
    break;

  case 234: /* instruction: IREND1 TSTRING STRING  */
#line 1718 "pnfasm.ypp"
                                        { 
						 fprintf(output, "133 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5493 "pnfasm.tab.cpp"
    break;

  case 235: /* instruction: IRLOAD1 TSTRING STRING  */
#line 1727 "pnfasm.ypp"
                                                { 
						 fprintf(output, "134 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5507 "pnfasm.tab.cpp"
    break;

  case 236: /* instruction: IRSTORE1 TSTRING STRING  */
#line 1736 "pnfasm.ypp"
                                                { 
						 fprintf(output, "135 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5521 "pnfasm.tab.cpp"
    break;

  case 237: /* instruction: IHEADDB TVOID NUMBER  */
#line 1745 "pnfasm.ypp"
                                        { fprintf(output, "136 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5527 "pnfasm.tab.cpp"
    break;

  case 238: /* instruction: ISHEADDB TVOID NUMBER  */
#line 1746 "pnfasm.ypp"
                                        { fprintf(output, "137 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5533 "pnfasm.tab.cpp"
    break;

  case 239: /* instruction: IEADDB TVOID NUMBER  */
#line 1747 "pnfasm.ypp"
                                        { fprintf(output, "138 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5539 "pnfasm.tab.cpp"
    break;

  case 240: /* instruction: IEXADDB TVOID NUMBER  */
#line 1748 "pnfasm.ypp"
                                        { fprintf(output, "139 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5545 "pnfasm.tab.cpp"
    break;

  case 241: /* instruction: IIADDB TVOID NUMBER  */
#line 1749 "pnfasm.ypp"
                                        { fprintf(output, "140 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5551 "pnfasm.tab.cpp"
    break;

  case 242: /* instruction: IRDSTART2 TSTRING STRING  */
#line 1750 "pnfasm.ypp"
                                                { 
						 fprintf(output, "141 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5565 "pnfasm.tab.cpp"
    break;

  case 243: /* instruction: IRFROM2 TNUMBER NUMBER  */
#line 1759 "pnfasm.ypp"
                                                { fprintf(output, "142 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5571 "pnfasm.tab.cpp"
    break;

  case 244: /* instruction: IRTO2 TNUMBER NUMBER  */
#line 1760 "pnfasm.ypp"
                                                { fprintf(output, "143 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5577 "pnfasm.tab.cpp"
    break;

  case 245: /* instruction: IRDEND2 TVOID VOID  */
#line 1761 "pnfasm.ypp"
                                                { fprintf(output, "144 0 0\n"); }
#line 5583 "pnfasm.tab.cpp"
    break;

  case 246: /* instruction: IRSTART2 TSTRING STRING  */
#line 1762 "pnfasm.ypp"
                                                { 
						 fprintf(output, "145 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5597 "pnfasm.tab.cpp"
    break;

  case 247: /* instruction: IRANGE2 TSTRING STRING  */
#line 1771 "pnfasm.ypp"
                                                { 
						 fprintf(output, "146 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5611 "pnfasm.tab.cpp"
    break;

  case 248: /* instruction: IRPREP2 TSTRING STRING  */
#line 1780 "pnfasm.ypp"
                                                { 
						 fprintf(output, "147 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5625 "pnfasm.tab.cpp"
    break;

  case 249: /* instruction: IRLOAD2 TNUMBER NUMBER  */
#line 1789 "pnfasm.ypp"
                                                { fprintf(output, "148 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5631 "pnfasm.tab.cpp"
    break;

  case 250: /* instruction: IESTART TSTRING STRING  */
#line 1790 "pnfasm.ypp"
                                                { 
						 fprintf(output, "149 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5645 "pnfasm.tab.cpp"
    break;

  case 251: /* instruction: IENAME TSTRING STRING  */
#line 1799 "pnfasm.ypp"
                                        { 
						 fprintf(output, "150 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5659 "pnfasm.tab.cpp"
    break;

  case 252: /* instruction: IEEND TVOID VOID  */
#line 1808 "pnfasm.ypp"
                                                { fprintf(output, "151 0 0\n"); }
#line 5665 "pnfasm.tab.cpp"
    break;

  case 253: /* instruction: IENUMS TSTRING STRING  */
#line 1809 "pnfasm.ypp"
                                                { 
						 fprintf(output, "152 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5679 "pnfasm.tab.cpp"
    break;

  case 254: /* instruction: IENUM TSTRING STRING  */
#line 1818 "pnfasm.ypp"
                                                { 
						 fprintf(output, "153 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5693 "pnfasm.tab.cpp"
    break;

  case 255: /* instruction: ISENUM TSTRING STRING  */
#line 1827 "pnfasm.ypp"
                                                { 
						 fprintf(output, "154 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5707 "pnfasm.tab.cpp"
    break;

  case 256: /* instruction: IEPREP TSTRING STRING  */
#line 1836 "pnfasm.ypp"
                                                { 
						 fprintf(output, "155 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5721 "pnfasm.tab.cpp"
    break;

  case 257: /* instruction: ILOADE TVOID VOID  */
#line 1845 "pnfasm.ypp"
                                                { fprintf(output, "156 0 0\n"); }
#line 5727 "pnfasm.tab.cpp"
    break;

  case 258: /* instruction: ISTOREE TVOID VOID  */
#line 1846 "pnfasm.ypp"
                                                { fprintf(output, "157 0 0\n"); }
#line 5733 "pnfasm.tab.cpp"
    break;

  case 259: /* instruction: IASTART TSTRING STRING  */
#line 1847 "pnfasm.ypp"
                                                { 
						 fprintf(output, "158 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5747 "pnfasm.tab.cpp"
    break;

  case 260: /* instruction: IAEND TNUMBER NUMBER  */
#line 1856 "pnfasm.ypp"
                                                { fprintf(output, "159 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5753 "pnfasm.tab.cpp"
    break;

  case 261: /* instruction: IAPREP TSTRING STRING  */
#line 1857 "pnfasm.ypp"
                                        { 
						 fprintf(output, "160 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5767 "pnfasm.tab.cpp"
    break;

  case 262: /* instruction: IAIPREP TNUMBER NUMBER  */
#line 1866 "pnfasm.ypp"
                                                { fprintf(output, "161 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5773 "pnfasm.tab.cpp"
    break;

  case 263: /* instruction: IAIPREP TVOID VOID  */
#line 1867 "pnfasm.ypp"
                                                { fprintf(output, "161 0 0\n"); }
#line 5779 "pnfasm.tab.cpp"
    break;

  case 264: /* instruction: ILOADIA TVOID VOID  */
#line 1868 "pnfasm.ypp"
                                                { fprintf(output, "162 0 0\n"); }
#line 5785 "pnfasm.tab.cpp"
    break;

  case 265: /* instruction: ISTOREIA TVOID VOID  */
#line 1869 "pnfasm.ypp"
                                                { fprintf(output, "163 0 0\n"); }
#line 5791 "pnfasm.tab.cpp"
    break;

  case 266: /* instruction: ISTOREIA TBOOLEAN VOID  */
#line 1870 "pnfasm.ypp"
                                                { fprintf(output, "163 1 0\n"); }
#line 5797 "pnfasm.tab.cpp"
    break;

  case 267: /* instruction: ISTOREIA TNUMBER VOID  */
#line 1871 "pnfasm.ypp"
                                                { fprintf(output, "163 2 0\n"); }
#line 5803 "pnfasm.tab.cpp"
    break;

  case 268: /* instruction: ISTOREIA TCHARACTER VOID  */
#line 1872 "pnfasm.ypp"
                                                { fprintf(output, "163 3 0\n"); }
#line 5809 "pnfasm.tab.cpp"
    break;

  case 269: /* instruction: ISTOREIA TSTRING VOID  */
#line 1873 "pnfasm.ypp"
                                                { fprintf(output, "163 4 0\n"); }
#line 5815 "pnfasm.tab.cpp"
    break;

  case 270: /* instruction: IALENGTH TVOID VOID  */
#line 1874 "pnfasm.ypp"
                                                { fprintf(output, "164 0 0\n"); }
#line 5821 "pnfasm.tab.cpp"
    break;

  case 271: /* instruction: IAPRINT TVOID VOID  */
#line 1875 "pnfasm.ypp"
                                                { fprintf(output, "165 0 0\n"); }
#line 5827 "pnfasm.tab.cpp"
    break;

  case 272: /* instruction: IDUP TVOID VOID  */
#line 1876 "pnfasm.ypp"
                                                { fprintf(output, "166 0 0\n"); }
#line 5833 "pnfasm.tab.cpp"
    break;

  case 273: /* instruction: ICDUP TVOID VOID  */
#line 1877 "pnfasm.ypp"
                                                { fprintf(output, "167 0 0\n"); }
#line 5839 "pnfasm.tab.cpp"
    break;

  case 274: /* instruction: IIF TVOID VOID  */
#line 1878 "pnfasm.ypp"
                                                { fprintf(output, "168 0 0\n"); }
#line 5845 "pnfasm.tab.cpp"
    break;

  case 275: /* instruction: IENDIF TVOID VOID  */
#line 1879 "pnfasm.ypp"
                                                { fprintf(output, "169 0 0\n"); }
#line 5851 "pnfasm.tab.cpp"
    break;

  case 276: /* instruction: IIFELSE TVOID VOID  */
#line 1880 "pnfasm.ypp"
                                                { fprintf(output, "170 0 0\n"); }
#line 5857 "pnfasm.tab.cpp"
    break;

  case 277: /* instruction: IENDIFELSE TVOID VOID  */
#line 1881 "pnfasm.ypp"
                                                { fprintf(output, "171 0 0\n"); }
#line 5863 "pnfasm.tab.cpp"
    break;

  case 278: /* instruction: IEIF TVOID VOID  */
#line 1882 "pnfasm.ypp"
                                                { fprintf(output, "172 0 0\n"); }
#line 5869 "pnfasm.tab.cpp"
    break;

  case 279: /* instruction: IIFBEGIN TVOID VOID  */
#line 1883 "pnfasm.ypp"
                                                { fprintf(output, "173 0 0\n"); }
#line 5875 "pnfasm.tab.cpp"
    break;

  case 280: /* instruction: IIFEND TVOID VOID  */
#line 1884 "pnfasm.ypp"
                                                { fprintf(output, "174 0 0\n"); }
#line 5881 "pnfasm.tab.cpp"
    break;

  case 281: /* instruction: ISWITCH2 TVOID VOID  */
#line 1885 "pnfasm.ypp"
                                                { fprintf(output, "175 0 0\n");	}
#line 5887 "pnfasm.tab.cpp"
    break;

  case 282: /* instruction: ISWBEGIN TVOID VOID  */
#line 1886 "pnfasm.ypp"
                                                { fprintf(output, "176 0 0\n");	}
#line 5893 "pnfasm.tab.cpp"
    break;

  case 283: /* instruction: ISWEND TVOID VOID  */
#line 1887 "pnfasm.ypp"
                                                { fprintf(output, "177 0 0\n");	}
#line 5899 "pnfasm.tab.cpp"
    break;

  case 284: /* instruction: ISWCASE TVOID VOID  */
#line 1888 "pnfasm.ypp"
                                                { fprintf(output, "178 0 0\n"); }
#line 5905 "pnfasm.tab.cpp"
    break;

  case 285: /* instruction: ISWCASE TBOOLEAN BOOLEAN  */
#line 1889 "pnfasm.ypp"
                                                { fprintf(output, "178 1 %s\n", yyvsp[0].getString().c_str());	}
#line 5911 "pnfasm.tab.cpp"
    break;

  case 286: /* instruction: ISWCASE TNUMBER NUMBER  */
#line 1890 "pnfasm.ypp"
                                                { fprintf(output, "178 2 %s\n", yyvsp[0].getString().c_str());	}
#line 5917 "pnfasm.tab.cpp"
    break;

  case 287: /* instruction: ISWCASE TCHARACTER CHARACTER  */
#line 1891 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "178 3 %i\n", ch);
						}
#line 5927 "pnfasm.tab.cpp"
    break;

  case 288: /* instruction: ISWCASE TSTRING STRING  */
#line 1896 "pnfasm.ypp"
                                                { 
						 fprintf(output, "178 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5941 "pnfasm.tab.cpp"
    break;

  case 289: /* instruction: ISWCBEGIN TVOID VOID  */
#line 1905 "pnfasm.ypp"
                                                { fprintf(output, "179 0 0\n");	}
#line 5947 "pnfasm.tab.cpp"
    break;

  case 290: /* instruction: ISWCEND TVOID VOID  */
#line 1906 "pnfasm.ypp"
                                                { fprintf(output, "180 0 0\n");	}
#line 5953 "pnfasm.tab.cpp"
    break;

  case 291: /* instruction: ISWDEFAULT TVOID VOID  */
#line 1907 "pnfasm.ypp"
                                                { fprintf(output, "181 0 0\n");	}
#line 5959 "pnfasm.tab.cpp"
    break;

  case 292: /* instruction: ISWBREAK TVOID VOID  */
#line 1908 "pnfasm.ypp"
                                                { fprintf(output, "182 0 0\n");	}
#line 5965 "pnfasm.tab.cpp"
    break;

  case 293: /* instruction: ILOADSP TNUMBER NUMBER  */
#line 1909 "pnfasm.ypp"
                                                { fprintf(output, "183 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5971 "pnfasm.tab.cpp"
    break;

  case 294: /* instruction: ISTORESP TNUMBER NUMBER  */
#line 1910 "pnfasm.ypp"
                                                { fprintf(output, "184 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5977 "pnfasm.tab.cpp"
    break;

  case 295: /* instruction: ILOADSTACK TVOID VOID  */
#line 1911 "pnfasm.ypp"
                                                { fprintf(output, "185 0 0\n"); }
#line 5983 "pnfasm.tab.cpp"
    break;

  case 296: /* instruction: ISTORESTACK TVOID VOID  */
#line 1912 "pnfasm.ypp"
                                                { fprintf(output, "186 0 0\n"); }
#line 5989 "pnfasm.tab.cpp"
    break;

  case 297: /* instruction: IATOSP TVOID VOID  */
#line 1913 "pnfasm.ypp"
                                                { fprintf(output, "187 0 0\n"); }
#line 5995 "pnfasm.tab.cpp"
    break;

  case 298: /* instruction: ISPTOA TVOID VOID  */
#line 1914 "pnfasm.ypp"
                                                { fprintf(output, "188 0 0\n"); }
#line 6001 "pnfasm.tab.cpp"
    break;

  case 299: /* instruction: IPATCH TVOID VOID  */
#line 1915 "pnfasm.ypp"
                                                { fprintf(output, "189 0 0\n"); }
#line 6007 "pnfasm.tab.cpp"
    break;

  case 300: /* instruction: INATIVE TSTRING STRING  */
#line 1916 "pnfasm.ypp"
                                                { 
						 fprintf(output, "190 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6021 "pnfasm.tab.cpp"
    break;

  case 301: /* instruction: IFRET TVOID VOID  */
#line 1925 "pnfasm.ypp"
                                                { fprintf(output, "191 0 0\n"); }
#line 6027 "pnfasm.tab.cpp"
    break;

  case 302: /* instruction: IFCALL TSTRING STRING  */
#line 1926 "pnfasm.ypp"
                                                { 
						 fprintf(output, "192 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6041 "pnfasm.tab.cpp"
    break;

  case 303: /* instruction: IFCPARAMS TVOID VOID  */
#line 1935 "pnfasm.ypp"
                                                { fprintf(output, "193 0 0\n"); }
#line 6047 "pnfasm.tab.cpp"
    break;

  case 304: /* instruction: IFECPARAMS TVOID VOID  */
#line 1936 "pnfasm.ypp"
                                                { fprintf(output, "194 0 0\n"); }
#line 6053 "pnfasm.tab.cpp"
    break;

  case 305: /* instruction: IFECALL TVOID VOID  */
#line 1937 "pnfasm.ypp"
                                                { fprintf(output, "195 0 0\n"); }
#line 6059 "pnfasm.tab.cpp"
    break;

  case 306: /* instruction: IPNUM TNUMBER NUMBER  */
#line 1938 "pnfasm.ypp"
                                                { fprintf(output, "196 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6065 "pnfasm.tab.cpp"
    break;

  case 307: /* instruction: IPARAMF TVOID VOID  */
#line 1939 "pnfasm.ypp"
                                                { fprintf(output, "197 0 0\n"); }
#line 6071 "pnfasm.tab.cpp"
    break;

  case 308: /* instruction: IPARAMF TBOOLEAN BOOLEAN  */
#line 1941 "pnfasm.ypp"
                                                {
			 			 if (yyvsp[0] == "true")
		 	  			  fprintf(output, "197 1 1\n");
			 			 else
			  			  fprintf(output, "197 1 0\n");
						}
#line 6082 "pnfasm.tab.cpp"
    break;

  case 309: /* instruction: IPARAMF TNUMBER NUMBER  */
#line 1947 "pnfasm.ypp"
                                                { fprintf(output, "197 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6088 "pnfasm.tab.cpp"
    break;

  case 310: /* instruction: IPARAMF TCHARACTER CHARACTER  */
#line 1949 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "197 3 %i\n", ch);
						}
#line 6098 "pnfasm.tab.cpp"
    break;

  case 311: /* instruction: IPARAMF TSTRING STRING  */
#line 1955 "pnfasm.ypp"
                                                {		
						 fprintf(output, "197 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6109 "pnfasm.tab.cpp"
    break;

  case 312: /* instruction: IPARAMF2 TVOID VOID  */
#line 1961 "pnfasm.ypp"
                                                { fprintf(output, "198 0 0\n"); }
#line 6115 "pnfasm.tab.cpp"
    break;

  case 313: /* instruction: IPARAMF2 TBOOLEAN VOID  */
#line 1962 "pnfasm.ypp"
                                                { fprintf(output, "198 1 0\n"); }
#line 6121 "pnfasm.tab.cpp"
    break;

  case 314: /* instruction: IPARAMF2 TNUMBER VOID  */
#line 1963 "pnfasm.ypp"
                                                { fprintf(output, "198 2 0\n"); }
#line 6127 "pnfasm.tab.cpp"
    break;

  case 315: /* instruction: IPARAMF2 TCHARACTER VOID  */
#line 1964 "pnfasm.ypp"
                                                { fprintf(output, "198 3 0\n"); }
#line 6133 "pnfasm.tab.cpp"
    break;

  case 316: /* instruction: IPARAMF2 TSTRING VOID  */
#line 1965 "pnfasm.ypp"
                                                { fprintf(output, "198 4 0\n"); }
#line 6139 "pnfasm.tab.cpp"
    break;

  case 317: /* instruction: IPARAMF3 TVOID VOID  */
#line 1966 "pnfasm.ypp"
                                                { fprintf(output, "199 0 0\n"); }
#line 6145 "pnfasm.tab.cpp"
    break;

  case 318: /* instruction: IPARAMF3 TBOOLEAN VOID  */
#line 1967 "pnfasm.ypp"
                                                { fprintf(output, "199 1 0\n"); }
#line 6151 "pnfasm.tab.cpp"
    break;

  case 319: /* instruction: IPARAMF3 TNUMBER VOID  */
#line 1968 "pnfasm.ypp"
                                                { fprintf(output, "199 2 0\n"); }
#line 6157 "pnfasm.tab.cpp"
    break;

  case 320: /* instruction: IPARAMF3 TCHARACTER VOID  */
#line 1969 "pnfasm.ypp"
                                                { fprintf(output, "199 3 0\n"); }
#line 6163 "pnfasm.tab.cpp"
    break;

  case 321: /* instruction: IPARAMF3 TSTRING VOID  */
#line 1970 "pnfasm.ypp"
                                                { fprintf(output, "199 4 0\n"); }
#line 6169 "pnfasm.tab.cpp"
    break;

  case 322: /* instruction: IRNUM TNUMBER NUMBER  */
#line 1971 "pnfasm.ypp"
                                                { fprintf(output, "200 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6175 "pnfasm.tab.cpp"
    break;

  case 323: /* instruction: IRETURNF TVOID VOID  */
#line 1972 "pnfasm.ypp"
                                                { fprintf(output, "201 0 0\n"); }
#line 6181 "pnfasm.tab.cpp"
    break;

  case 324: /* instruction: IRETURNF TBOOLEAN VOID  */
#line 1973 "pnfasm.ypp"
                                                { fprintf(output, "201 1 0\n"); }
#line 6187 "pnfasm.tab.cpp"
    break;

  case 325: /* instruction: IRETURNF TNUMBER VOID  */
#line 1974 "pnfasm.ypp"
                                                { fprintf(output, "201 2 0\n"); }
#line 6193 "pnfasm.tab.cpp"
    break;

  case 326: /* instruction: IRETURNF TCHARACTER VOID  */
#line 1975 "pnfasm.ypp"
                                                { fprintf(output, "201 3 0\n"); }
#line 6199 "pnfasm.tab.cpp"
    break;

  case 327: /* instruction: IRETURNF TSTRING VOID  */
#line 1976 "pnfasm.ypp"
                                                { fprintf(output, "201 4 0\n"); }
#line 6205 "pnfasm.tab.cpp"
    break;

  case 328: /* instruction: IRETURNF2 TVOID VOID  */
#line 1977 "pnfasm.ypp"
                                                { fprintf(output, "202 0 0\n"); }
#line 6211 "pnfasm.tab.cpp"
    break;

  case 329: /* instruction: IRETURNF2 TBOOLEAN VOID  */
#line 1978 "pnfasm.ypp"
                                                { fprintf(output, "202 1 0\n"); }
#line 6217 "pnfasm.tab.cpp"
    break;

  case 330: /* instruction: IRETURNF2 TNUMBER VOID  */
#line 1979 "pnfasm.ypp"
                                                { fprintf(output, "202 2 0\n"); }
#line 6223 "pnfasm.tab.cpp"
    break;

  case 331: /* instruction: IRETURNF2 TCHARACTER VOID  */
#line 1980 "pnfasm.ypp"
                                                { fprintf(output, "202 3 0\n"); }
#line 6229 "pnfasm.tab.cpp"
    break;

  case 332: /* instruction: IRETURNF2 TSTRING VOID  */
#line 1981 "pnfasm.ypp"
                                                { fprintf(output, "202 4 0\n"); }
#line 6235 "pnfasm.tab.cpp"
    break;

  case 333: /* instruction: IRETURNF3 TVOID VOID  */
#line 1982 "pnfasm.ypp"
                                                { fprintf(output, "203 0 0\n"); }
#line 6241 "pnfasm.tab.cpp"
    break;

  case 334: /* instruction: IRETURNF3 TBOOLEAN VOID  */
#line 1983 "pnfasm.ypp"
                                                { fprintf(output, "203 1 0\n"); }
#line 6247 "pnfasm.tab.cpp"
    break;

  case 335: /* instruction: IRETURNF3 TNUMBER VOID  */
#line 1984 "pnfasm.ypp"
                                                { fprintf(output, "203 2 0\n"); }
#line 6253 "pnfasm.tab.cpp"
    break;

  case 336: /* instruction: IRETURNF3 TCHARACTER VOID  */
#line 1985 "pnfasm.ypp"
                                                { fprintf(output, "203 3 0\n"); }
#line 6259 "pnfasm.tab.cpp"
    break;

  case 337: /* instruction: IRETURNF3 TSTRING VOID  */
#line 1986 "pnfasm.ypp"
                                                { fprintf(output, "203 4 0\n"); }
#line 6265 "pnfasm.tab.cpp"
    break;

  case 338: /* instruction: IFNAME TSTRING STRING  */
#line 1989 "pnfasm.ypp"
                                                {		
						 fprintf(output, "204 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6276 "pnfasm.tab.cpp"
    break;

  case 339: /* instruction: IRETURNV TVOID VOID  */
#line 1995 "pnfasm.ypp"
                                                { fprintf(output, "205 0 0\n"); }
#line 6282 "pnfasm.tab.cpp"
    break;

  case 340: /* instruction: IFNCLOAD TNUMBER NUMBER  */
#line 1996 "pnfasm.ypp"
                                                { fprintf(output, "206 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6288 "pnfasm.tab.cpp"
    break;

  case 341: /* instruction: IFNCSTORE TVOID VOID  */
#line 1997 "pnfasm.ypp"
                                                { fprintf(output, "207 0 0\n"); }
#line 6294 "pnfasm.tab.cpp"
    break;

  case 342: /* instruction: IFNCSTORE TNUMBER NUMBER  */
#line 1998 "pnfasm.ypp"
                                                { fprintf(output, "207 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6300 "pnfasm.tab.cpp"
    break;

  case 343: /* instruction: IFNCNEW TVOID VOID  */
#line 1999 "pnfasm.ypp"
                                                { fprintf(output, "208 0 0\n"); }
#line 6306 "pnfasm.tab.cpp"
    break;

  case 344: /* instruction: IFNCDELETE TVOID VOID  */
#line 2000 "pnfasm.ypp"
                                                { fprintf(output, "209 0 0\n"); }
#line 6312 "pnfasm.tab.cpp"
    break;

  case 345: /* instruction: IFNCSNAME TVOID VOID  */
#line 2001 "pnfasm.ypp"
                                                { fprintf(output, "210 0 0\n"); }
#line 6318 "pnfasm.tab.cpp"
    break;

  case 346: /* instruction: IFNCSRET TVOID VOID  */
#line 2002 "pnfasm.ypp"
                                                { fprintf(output, "211 0 0\n"); }
#line 6324 "pnfasm.tab.cpp"
    break;

  case 347: /* instruction: IFNCSRET TBOOLEAN VOID  */
#line 2003 "pnfasm.ypp"
                                                { fprintf(output, "211 1 0\n"); }
#line 6330 "pnfasm.tab.cpp"
    break;

  case 348: /* instruction: IFNCSRET TNUMBER VOID  */
#line 2004 "pnfasm.ypp"
                                                { fprintf(output, "211 2 0\n"); }
#line 6336 "pnfasm.tab.cpp"
    break;

  case 349: /* instruction: IFNCSRET TCHARACTER VOID  */
#line 2005 "pnfasm.ypp"
                                                { fprintf(output, "211 3 0\n"); }
#line 6342 "pnfasm.tab.cpp"
    break;

  case 350: /* instruction: IFNCSRET TSTRING VOID  */
#line 2006 "pnfasm.ypp"
                                                { fprintf(output, "211 4 0\n"); }
#line 6348 "pnfasm.tab.cpp"
    break;

  case 351: /* instruction: IFNCSPARAM TVOID VOID  */
#line 2007 "pnfasm.ypp"
                                                { fprintf(output, "212 0 0\n"); }
#line 6354 "pnfasm.tab.cpp"
    break;

  case 352: /* instruction: IFNCSPARAM TBOOLEAN VOID  */
#line 2008 "pnfasm.ypp"
                                                { fprintf(output, "212 1 0\n"); }
#line 6360 "pnfasm.tab.cpp"
    break;

  case 353: /* instruction: IFNCSPARAM TNUMBER VOID  */
#line 2009 "pnfasm.ypp"
                                                { fprintf(output, "212 2 0\n"); }
#line 6366 "pnfasm.tab.cpp"
    break;

  case 354: /* instruction: IFNCSPARAM TCHARACTER VOID  */
#line 2010 "pnfasm.ypp"
                                                { fprintf(output, "212 3 0\n"); }
#line 6372 "pnfasm.tab.cpp"
    break;

  case 355: /* instruction: IFNCSPARAM TSTRING VOID  */
#line 2011 "pnfasm.ypp"
                                                { fprintf(output, "212 4 0\n"); }
#line 6378 "pnfasm.tab.cpp"
    break;

  case 356: /* instruction: IFNCSDEF TNUMBER NUMBER  */
#line 2012 "pnfasm.ypp"
                                                { fprintf(output, "213 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6384 "pnfasm.tab.cpp"
    break;

  case 357: /* instruction: IFNCSDEF TSTRING STRING  */
#line 2013 "pnfasm.ypp"
                                                {		
						 fprintf(output, "213 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6395 "pnfasm.tab.cpp"
    break;

  case 358: /* instruction: IFNCGNAME TVOID VOID  */
#line 2019 "pnfasm.ypp"
                                                { fprintf(output, "214 0 0\n"); }
#line 6401 "pnfasm.tab.cpp"
    break;

  case 359: /* instruction: IFNCGRET TNUMBER NUMBER  */
#line 2020 "pnfasm.ypp"
                                                { fprintf(output, "215 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6407 "pnfasm.tab.cpp"
    break;

  case 360: /* instruction: IFNCGPARAM TNUMBER NUMBER  */
#line 2021 "pnfasm.ypp"
                                                { fprintf(output, "216 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6413 "pnfasm.tab.cpp"
    break;

  case 361: /* instruction: IFNCGDEF TVOID VOID  */
#line 2022 "pnfasm.ypp"
                                                { fprintf(output, "217 0 0\n"); }
#line 6419 "pnfasm.tab.cpp"
    break;

  case 362: /* instruction: IFNCPOINT TVOID VOID  */
#line 2023 "pnfasm.ypp"
                                                { fprintf(output, "218 0 0\n"); }
#line 6425 "pnfasm.tab.cpp"
    break;

  case 363: /* instruction: IFNCLENGTH TVOID VOID  */
#line 2024 "pnfasm.ypp"
                                                { fprintf(output, "219 0 0\n"); }
#line 6431 "pnfasm.tab.cpp"
    break;

  case 364: /* instruction: IFNCSYNCR TVOID VOID  */
#line 2025 "pnfasm.ypp"
                                                { fprintf(output, "220 0 0\n"); }
#line 6437 "pnfasm.tab.cpp"
    break;

  case 365: /* instruction: IFNCFIND TVOID VOID  */
#line 2026 "pnfasm.ypp"
                                                { fprintf(output, "221 0 0\n"); }
#line 6443 "pnfasm.tab.cpp"
    break;

  case 366: /* instruction: IFNCFRET TVOID VOID  */
#line 2027 "pnfasm.ypp"
                                                { fprintf(output, "222 0 0\n"); }
#line 6449 "pnfasm.tab.cpp"
    break;

  case 367: /* instruction: IFNCFRET TBOOLEAN VOID  */
#line 2028 "pnfasm.ypp"
                                                { fprintf(output, "222 1 0\n"); }
#line 6455 "pnfasm.tab.cpp"
    break;

  case 368: /* instruction: IFNCFRET TNUMBER VOID  */
#line 2029 "pnfasm.ypp"
                                                { fprintf(output, "222 2 0\n"); }
#line 6461 "pnfasm.tab.cpp"
    break;

  case 369: /* instruction: IFNCFRET TCHARACTER VOID  */
#line 2030 "pnfasm.ypp"
                                                { fprintf(output, "222 3 0\n"); }
#line 6467 "pnfasm.tab.cpp"
    break;

  case 370: /* instruction: IFNCFRET TSTRING VOID  */
#line 2031 "pnfasm.ypp"
                                                { fprintf(output, "222 4 0\n"); }
#line 6473 "pnfasm.tab.cpp"
    break;

  case 371: /* instruction: IFNCFPARAM TVOID VOID  */
#line 2032 "pnfasm.ypp"
                                                { fprintf(output, "223 0 0\n"); }
#line 6479 "pnfasm.tab.cpp"
    break;

  case 372: /* instruction: IFNCFPARAM TBOOLEAN VOID  */
#line 2033 "pnfasm.ypp"
                                                { fprintf(output, "223 1 0\n"); }
#line 6485 "pnfasm.tab.cpp"
    break;

  case 373: /* instruction: IFNCFPARAM TNUMBER VOID  */
#line 2034 "pnfasm.ypp"
                                                { fprintf(output, "223 2 0\n"); }
#line 6491 "pnfasm.tab.cpp"
    break;

  case 374: /* instruction: IFNCFPARAM TCHARACTER VOID  */
#line 2035 "pnfasm.ypp"
                                                { fprintf(output, "223 3 0\n"); }
#line 6497 "pnfasm.tab.cpp"
    break;

  case 375: /* instruction: IFNCFPARAM TSTRING VOID  */
#line 2036 "pnfasm.ypp"
                                                { fprintf(output, "223 4 0\n"); }
#line 6503 "pnfasm.tab.cpp"
    break;

  case 376: /* instruction: IFNCFBRET TVOID VOID  */
#line 2037 "pnfasm.ypp"
                                                { fprintf(output, "224 0 0\n"); }
#line 6509 "pnfasm.tab.cpp"
    break;

  case 377: /* instruction: IFNCFBPARAM TVOID VOID  */
#line 2038 "pnfasm.ypp"
                                                { fprintf(output, "225 0 0\n"); }
#line 6515 "pnfasm.tab.cpp"
    break;

  case 378: /* instruction: IFNCDEFAULT TVOID VOID  */
#line 2039 "pnfasm.ypp"
                                                { fprintf(output, "226 0 0\n"); }
#line 6521 "pnfasm.tab.cpp"
    break;

  case 379: /* instruction: IFNCDEFAULT2 TVOID VOID  */
#line 2040 "pnfasm.ypp"
                                                { fprintf(output, "227 0 0\n"); }
#line 6527 "pnfasm.tab.cpp"
    break;

  case 380: /* instruction: IFNCSDEFAULTV TVOID VOID  */
#line 2041 "pnfasm.ypp"
                                                { fprintf(output, "228 0 0\n"); }
#line 6533 "pnfasm.tab.cpp"
    break;

  case 381: /* instruction: IFNCSDEFAULTV TBOOLEAN VOID  */
#line 2042 "pnfasm.ypp"
                                                { fprintf(output, "228 1 0\n"); }
#line 6539 "pnfasm.tab.cpp"
    break;

  case 382: /* instruction: IFNCSDEFAULTV TNUMBER VOID  */
#line 2043 "pnfasm.ypp"
                                                { fprintf(output, "228 2 0\n"); }
#line 6545 "pnfasm.tab.cpp"
    break;

  case 383: /* instruction: IFNCSDEFAULTV TCHARACTER VOID  */
#line 2044 "pnfasm.ypp"
                                                { fprintf(output, "228 3 0\n"); }
#line 6551 "pnfasm.tab.cpp"
    break;

  case 384: /* instruction: IFNCSDEFAULTV TSTRING VOID  */
#line 2045 "pnfasm.ypp"
                                                { fprintf(output, "228 4 0\n"); }
#line 6557 "pnfasm.tab.cpp"
    break;

  case 385: /* instruction: IFNCSDEFAULTV2 TVOID VOID  */
#line 2046 "pnfasm.ypp"
                                                { fprintf(output, "229 0 0\n"); }
#line 6563 "pnfasm.tab.cpp"
    break;

  case 386: /* instruction: IFNCGDEFAULTV2 TVOID VOID  */
#line 2047 "pnfasm.ypp"
                                                { fprintf(output, "230 0 0\n"); }
#line 6569 "pnfasm.tab.cpp"
    break;

  case 387: /* instruction: IFNCDEFAULTSYNC TVOID VOID  */
#line 2048 "pnfasm.ypp"
                                                { fprintf(output, "231 0 0\n"); }
#line 6575 "pnfasm.tab.cpp"
    break;

  case 388: /* instruction: INTIMES TVOID VOID  */
#line 2049 "pnfasm.ypp"
                                                { fprintf(output, "232 0 0\n"); }
#line 6581 "pnfasm.tab.cpp"
    break;

  case 389: /* instruction: ICMP TVOID VOID  */
#line 2050 "pnfasm.ypp"
                                                { fprintf(output, "233 0 0\n"); }
#line 6587 "pnfasm.tab.cpp"
    break;

  case 390: /* instruction: IRUN TSTRING STRING  */
#line 2051 "pnfasm.ypp"
                                                { 
						 fprintf(output, "234 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6601 "pnfasm.tab.cpp"
    break;

  case 391: /* instruction: IJRUN TSTRING STRING  */
#line 2060 "pnfasm.ypp"
                                                { 
						 fprintf(output, "235 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6615 "pnfasm.tab.cpp"
    break;

  case 392: /* instruction: IPNFRUN TSTRING STRING  */
#line 2069 "pnfasm.ypp"
                                                { 
						 fprintf(output, "236 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6629 "pnfasm.tab.cpp"
    break;

  case 393: /* instruction: ISTRUCT TSTRING STRING  */
#line 2078 "pnfasm.ypp"
                                                { 
						 fprintf(output, "237 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6643 "pnfasm.tab.cpp"
    break;

  case 394: /* instruction: ISTRUCTVAR TSTRING STRING  */
#line 2087 "pnfasm.ypp"
                                                { 
						 fprintf(output, "238 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6657 "pnfasm.tab.cpp"
    break;

  case 395: /* instruction: IENDSTRUCT TVOID VOID  */
#line 2096 "pnfasm.ypp"
                                        { fprintf(output, "239 0 0\n"); }
#line 6663 "pnfasm.tab.cpp"
    break;

  case 396: /* instruction: ISTRUCTNAME TSTRING STRING  */
#line 2097 "pnfasm.ypp"
                                                { 
						 fprintf(output, "240 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6677 "pnfasm.tab.cpp"
    break;

  case 397: /* instruction: ISTRUCTONAME TSTRING STRING  */
#line 2106 "pnfasm.ypp"
                                                { 
						 fprintf(output, "241 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6691 "pnfasm.tab.cpp"
    break;

  case 398: /* instruction: ISTRUCTD TSTRING STRING  */
#line 2115 "pnfasm.ypp"
                                                { 
						 fprintf(output, "242 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6705 "pnfasm.tab.cpp"
    break;

  case 399: /* instruction: ISTRUCTUSE TVOID VOID  */
#line 2124 "pnfasm.ypp"
                                                { 
						 fprintf(output, "243 0 0\n");
						}
#line 6713 "pnfasm.tab.cpp"
    break;

  case 400: /* instruction: ISTRUCTUSE TNUMBER VOID  */
#line 2127 "pnfasm.ypp"
                                                {	
						fprintf(output, "243 2 0\n");
						}
#line 6721 "pnfasm.tab.cpp"
    break;

  case 401: /* instruction: ISTRUCTUSE TSTRING STRING  */
#line 2130 "pnfasm.ypp"
                                                { 
						 fprintf(output, "243 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6735 "pnfasm.tab.cpp"
    break;

  case 402: /* instruction: ISTRUCTUSING TVOID VOID  */
#line 2139 "pnfasm.ypp"
                                                { 
						 fprintf(output, "244 0 0\n");
						}
#line 6743 "pnfasm.tab.cpp"
    break;

  case 403: /* instruction: ISTRUCTUSINGNAME TVOID VOID  */
#line 2142 "pnfasm.ypp"
                                                { 
						 fprintf(output, "245 0 0\n");
						}
#line 6751 "pnfasm.tab.cpp"
    break;

  case 404: /* instruction: ISTRUCTGET TVOID VOID  */
#line 2145 "pnfasm.ypp"
                                                { 
						 fprintf(output, "246 0 0\n");
						}
#line 6759 "pnfasm.tab.cpp"
    break;

  case 405: /* instruction: ISTRUCTPUT TVOID VOID  */
#line 2148 "pnfasm.ypp"
                                                { 
						 fprintf(output, "247 0 0\n");
						}
#line 6767 "pnfasm.tab.cpp"
    break;

  case 406: /* instruction: ISTRUCTTYPE TVOID VOID  */
#line 2152 "pnfasm.ypp"
                                                { 
						 fprintf(output, "248 0 0\n");
						}
#line 6775 "pnfasm.tab.cpp"
    break;

  case 407: /* instruction: ISTRUCTTYPE2 TVOID VOID  */
#line 2155 "pnfasm.ypp"
                                                { 
						 fprintf(output, "249 0 0\n");
						}
#line 6783 "pnfasm.tab.cpp"
    break;

  case 408: /* instruction: ISTRUCTNAME2 TVOID VOID  */
#line 2158 "pnfasm.ypp"
                                                { 
						 fprintf(output, "250 0 0\n");
						}
#line 6791 "pnfasm.tab.cpp"
    break;

  case 409: /* instruction: ISTRUCTNAME3 TVOID VOID  */
#line 2161 "pnfasm.ypp"
                                                { 
						 fprintf(output, "251 0 0\n");
						}
#line 6799 "pnfasm.tab.cpp"
    break;

  case 410: /* instruction: IUNION TSTRING STRING  */
#line 2165 "pnfasm.ypp"
                                        { 
						 fprintf(output, "252 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6813 "pnfasm.tab.cpp"
    break;

  case 411: /* instruction: IUNIONVAR TSTRING STRING  */
#line 2174 "pnfasm.ypp"
                                                { 
						 fprintf(output, "253 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6827 "pnfasm.tab.cpp"
    break;

  case 412: /* instruction: IENDUNION TVOID VOID  */
#line 2183 "pnfasm.ypp"
                                        { fprintf(output, "254 0 0\n"); }
#line 6833 "pnfasm.tab.cpp"
    break;

  case 413: /* instruction: IUNIONNAME TSTRING STRING  */
#line 2184 "pnfasm.ypp"
                                                { 
						 fprintf(output, "255 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6847 "pnfasm.tab.cpp"
    break;

  case 414: /* instruction: IUNIONONAME TSTRING STRING  */
#line 2193 "pnfasm.ypp"
                                                { 
						 fprintf(output, "256 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6861 "pnfasm.tab.cpp"
    break;

  case 415: /* instruction: IUNIOND TSTRING STRING  */
#line 2202 "pnfasm.ypp"
                                                { 
						 fprintf(output, "257 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6875 "pnfasm.tab.cpp"
    break;

  case 416: /* instruction: IUNIONUSE TVOID VOID  */
#line 2211 "pnfasm.ypp"
                                                { 
						 fprintf(output, "258 0 0\n");
						}
#line 6883 "pnfasm.tab.cpp"
    break;

  case 417: /* instruction: IUNIONUSE TNUMBER VOID  */
#line 2214 "pnfasm.ypp"
                                                {	
						fprintf(output, "258 2 0\n");
						}
#line 6891 "pnfasm.tab.cpp"
    break;

  case 418: /* instruction: IUNIONUSE TSTRING STRING  */
#line 2217 "pnfasm.ypp"
                                                { 
						 fprintf(output, "258 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6905 "pnfasm.tab.cpp"
    break;

  case 419: /* instruction: IUNIONUSING TVOID VOID  */
#line 2226 "pnfasm.ypp"
                                                { 
						 fprintf(output, "259 0 0\n");
						}
#line 6913 "pnfasm.tab.cpp"
    break;

  case 420: /* instruction: IUNIONUSINGNAME TVOID VOID  */
#line 2229 "pnfasm.ypp"
                                                { 
						 fprintf(output, "260 0 0\n");
						}
#line 6921 "pnfasm.tab.cpp"
    break;

  case 421: /* instruction: IUNIONGET TVOID VOID  */
#line 2232 "pnfasm.ypp"
                                                { 
						 fprintf(output, "261 0 0\n");
						}
#line 6929 "pnfasm.tab.cpp"
    break;

  case 422: /* instruction: IUNIONPUT TVOID VOID  */
#line 2235 "pnfasm.ypp"
                                                { 
						 fprintf(output, "262 0 0\n");
						}
#line 6937 "pnfasm.tab.cpp"
    break;

  case 423: /* instruction: IUNIONTYPE TVOID VOID  */
#line 2239 "pnfasm.ypp"
                                        { 
						 fprintf(output, "263 0 0\n");
						}
#line 6945 "pnfasm.tab.cpp"
    break;

  case 424: /* instruction: IUNIONTYPE2 TVOID VOID  */
#line 2242 "pnfasm.ypp"
                                                { 
						 fprintf(output, "264 0 0\n");
						}
#line 6953 "pnfasm.tab.cpp"
    break;

  case 425: /* instruction: IUNIONNAME2 TVOID VOID  */
#line 2245 "pnfasm.ypp"
                                                { 
						 fprintf(output, "265 0 0\n");
						}
#line 6961 "pnfasm.tab.cpp"
    break;

  case 426: /* instruction: IUNIONNAME3 TVOID VOID  */
#line 2248 "pnfasm.ypp"
                                                { 
						 fprintf(output, "266 0 0\n");
						}
#line 6969 "pnfasm.tab.cpp"
    break;

  case 427: /* instruction: IMODE TVOID NUMBER  */
#line 2252 "pnfasm.ypp"
                                                { 
						 fprintf(output, "267 0 0\n");
						}
#line 6977 "pnfasm.tab.cpp"
    break;

  case 428: /* instruction: IEXTMODE TVOID NUMBER  */
#line 2256 "pnfasm.ypp"
                                                { 
						 fprintf(output, "268 0 %s\n", yyvsp[0].getString().c_str());
						}
#line 6985 "pnfasm.tab.cpp"
    break;

  case 429: /* instruction: IMCHECK TVOID NUMBER  */
#line 2260 "pnfasm.ypp"
                                                { fprintf(output, "269 0 %s\n", yyvsp[0].getString().c_str()); }
#line 6991 "pnfasm.tab.cpp"
    break;

  case 430: /* instruction: IMCHECK TBOOLEAN BOOLEAN  */
#line 2262 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "269 1 1\n");
		 else
		  fprintf(output, "269 1 0\n");
		}
#line 7002 "pnfasm.tab.cpp"
    break;

  case 431: /* instruction: IMCHECK TNUMBER NUMBER  */
#line 2268 "pnfasm.ypp"
                                                { fprintf(output, "269 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7008 "pnfasm.tab.cpp"
    break;

  case 432: /* instruction: IMCHECK TCHARACTER CHARACTER  */
#line 2270 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "269 3 %i\n", ch);
		}
#line 7018 "pnfasm.tab.cpp"
    break;

  case 433: /* instruction: IMCHECK TSTRING STRING  */
#line 2276 "pnfasm.ypp"
                {
		 fprintf(output, "269 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 7032 "pnfasm.tab.cpp"
    break;

  case 434: /* instruction: IMSUPP TVOID NUMBER  */
#line 2285 "pnfasm.ypp"
                                                { fprintf(output, "270 0 %s\n", yyvsp[0].getString().c_str()); }
#line 7038 "pnfasm.tab.cpp"
    break;

  case 435: /* instruction: IMSUPP TBOOLEAN BOOLEAN  */
#line 2287 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "270 1 1\n");
		 else
		  fprintf(output, "270 1 0\n");
		}
#line 7049 "pnfasm.tab.cpp"
    break;

  case 436: /* instruction: IMSUPP TNUMBER NUMBER  */
#line 2293 "pnfasm.ypp"
                                        { fprintf(output, "270 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7055 "pnfasm.tab.cpp"
    break;

  case 437: /* instruction: IMSUPP TCHARACTER CHARACTER  */
#line 2295 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "270 3 %i\n", ch);
		}
#line 7065 "pnfasm.tab.cpp"
    break;

  case 438: /* instruction: IMSUPP TSTRING STRING  */
#line 2301 "pnfasm.ypp"
                {
		 fprintf(output, "270 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 7079 "pnfasm.tab.cpp"
    break;

  case 439: /* instruction: IMEXTCHECK TVOID NUMBER  */
#line 2310 "pnfasm.ypp"
                                                        { fprintf(output, "271 0 %s\n", yyvsp[0].getString().c_str()); }
#line 7085 "pnfasm.tab.cpp"
    break;

  case 440: /* instruction: IMEXTCHECK TBOOLEAN BOOLEAN  */
#line 2312 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "271 1 1\n");
		 else
		  fprintf(output, "271 1 0\n");
		}
#line 7096 "pnfasm.tab.cpp"
    break;

  case 441: /* instruction: IMEXTCHECK TNUMBER NUMBER  */
#line 2318 "pnfasm.ypp"
                                                { fprintf(output, "271 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7102 "pnfasm.tab.cpp"
    break;

  case 442: /* instruction: IMEXTCHECK TCHARACTER CHARACTER  */
#line 2320 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "271 3 %i\n", ch);
		}
#line 7112 "pnfasm.tab.cpp"
    break;

  case 443: /* instruction: IMEXTCHECK TSTRING STRING  */
#line 2326 "pnfasm.ypp"
                {
		 fprintf(output, "271 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 7126 "pnfasm.tab.cpp"
    break;

  case 444: /* instruction: IMEXTSUPP TVOID NUMBER  */
#line 2335 "pnfasm.ypp"
                                                        { fprintf(output, "272 0 %s\n", yyvsp[0].getString().c_str()); }
#line 7132 "pnfasm.tab.cpp"
    break;

  case 445: /* instruction: IMEXTSUPP TBOOLEAN BOOLEAN  */
#line 2337 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "272 1 1\n");
		 else
		  fprintf(output, "272 1 0\n");
		}
#line 7143 "pnfasm.tab.cpp"
    break;

  case 446: /* instruction: IMEXTSUPP TNUMBER NUMBER  */
#line 2343 "pnfasm.ypp"
                                                { fprintf(output, "272 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7149 "pnfasm.tab.cpp"
    break;

  case 447: /* instruction: IMEXTSUPP TCHARACTER CHARACTER  */
#line 2345 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "272 3 %i\n", ch);
		}
#line 7159 "pnfasm.tab.cpp"
    break;

  case 448: /* instruction: IMEXTSUPP TSTRING STRING  */
#line 2351 "pnfasm.ypp"
                {
		 fprintf(output, "272 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 7173 "pnfasm.tab.cpp"
    break;

  case 449: /* instruction: ICPY TVOID VOID  */
#line 2361 "pnfasm.ypp"
                                                { 
						 fprintf(output, "273 0 0\n");
						}
#line 7181 "pnfasm.tab.cpp"
    break;

  case 450: /* instruction: IADDSEG TVOID VOID  */
#line 2365 "pnfasm.ypp"
                                                { 
						 fprintf(output, "274 0 0\n");
						}
#line 7189 "pnfasm.tab.cpp"
    break;

  case 451: /* instruction: IREMSEG TVOID VOID  */
#line 2369 "pnfasm.ypp"
                                                { 
						 fprintf(output, "275 0 0\n");
						}
#line 7197 "pnfasm.tab.cpp"
    break;

  case 452: /* instruction: ICOLLSEG TNUMBER NUMBER  */
#line 2373 "pnfasm.ypp"
                                                { fprintf(output, "276 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7203 "pnfasm.tab.cpp"
    break;

  case 453: /* instruction: IEXPSEG TNUMBER NUMBER  */
#line 2375 "pnfasm.ypp"
                                                { fprintf(output, "277 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7209 "pnfasm.tab.cpp"
    break;

  case 454: /* instruction: ICPYSEG TVOID VOID  */
#line 2377 "pnfasm.ypp"
                                                { 
						 fprintf(output, "278 0 0\n");
						}
#line 7217 "pnfasm.tab.cpp"
    break;

  case 455: /* instruction: ISEGLOAD TNUMBER NUMBER  */
#line 2381 "pnfasm.ypp"
                                                { fprintf(output, "279 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7223 "pnfasm.tab.cpp"
    break;

  case 456: /* instruction: ISEGSTORE TNUMBER NUMBER  */
#line 2383 "pnfasm.ypp"
                                                { fprintf(output, "280 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7229 "pnfasm.tab.cpp"
    break;

  case 457: /* instruction: ISEGPUSH TVOID VOID  */
#line 2385 "pnfasm.ypp"
                                                { 
						 fprintf(output, "281 0 0\n");
						}
#line 7237 "pnfasm.tab.cpp"
    break;

  case 458: /* instruction: ISEGPOP TVOID VOID  */
#line 2389 "pnfasm.ypp"
                                                { 
						 fprintf(output, "282 0 0\n");
						}
#line 7245 "pnfasm.tab.cpp"
    break;

  case 459: /* instruction: ISEGTOP TVOID VOID  */
#line 2393 "pnfasm.ypp"
                                                { 
						 fprintf(output, "283 0 0\n");
						}
#line 7253 "pnfasm.tab.cpp"
    break;

  case 460: /* instruction: ISEGVLOAD TBOOLEAN NUMBER  */
#line 2396 "pnfasm.ypp"
                                                { fprintf(output, "284 1 %s\n", yyvsp[0].getString().c_str()); }
#line 7259 "pnfasm.tab.cpp"
    break;

  case 461: /* instruction: ISEGVLOAD TNUMBER NUMBER  */
#line 2397 "pnfasm.ypp"
                                                        { fprintf(output, "284 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7265 "pnfasm.tab.cpp"
    break;

  case 462: /* instruction: ISEGVLOAD TCHARACTER NUMBER  */
#line 2398 "pnfasm.ypp"
                                                { fprintf(output, "284 3 %s\n", yyvsp[0].getString().c_str()); }
#line 7271 "pnfasm.tab.cpp"
    break;

  case 463: /* instruction: ISEGVLOAD TSTRING NUMBER  */
#line 2399 "pnfasm.ypp"
                                                        { fprintf(output, "284 4 %s\n", yyvsp[0].getString().c_str()); }
#line 7277 "pnfasm.tab.cpp"
    break;

  case 464: /* instruction: ISEGVSTORE TVOID VOID  */
#line 2400 "pnfasm.ypp"
                                                { fprintf(output, "285 0 0\n"); }
#line 7283 "pnfasm.tab.cpp"
    break;

  case 465: /* instruction: ISEGVSTORE TNUMBER NUMBER  */
#line 2401 "pnfasm.ypp"
                                                { fprintf(output, "285 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7289 "pnfasm.tab.cpp"
    break;

  case 466: /* instruction: IMSG TVOID NUMBER  */
#line 2402 "pnfasm.ypp"
                                    { fprintf(output, "286 0 %s\n", yyvsp[0].getString().c_str()); }
#line 7295 "pnfasm.tab.cpp"
    break;

  case 467: /* instruction: IWHILE TVOID VOID  */
#line 2403 "pnfasm.ypp"
                                        { fprintf(output, "287 0 0\n"); }
#line 7301 "pnfasm.tab.cpp"
    break;

  case 468: /* instruction: IWHILEB TVOID VOID  */
#line 2404 "pnfasm.ypp"
                                        { fprintf(output, "288 0 0\n"); }
#line 7307 "pnfasm.tab.cpp"
    break;

  case 469: /* instruction: IWHILEE TVOID VOID  */
#line 2405 "pnfasm.ypp"
                                        { fprintf(output, "289 0 0\n"); }
#line 7313 "pnfasm.tab.cpp"
    break;

  case 470: /* instruction: IWHILEBB TVOID VOID  */
#line 2406 "pnfasm.ypp"
                                        { fprintf(output, "290 0 0\n"); }
#line 7319 "pnfasm.tab.cpp"
    break;

  case 471: /* instruction: IWHILEBBB TVOID VOID  */
#line 2407 "pnfasm.ypp"
                                        { fprintf(output, "291 0 0\n"); }
#line 7325 "pnfasm.tab.cpp"
    break;

  case 472: /* instruction: IWHILEBBE TVOID VOID  */
#line 2408 "pnfasm.ypp"
                                        { fprintf(output, "292 0 0\n"); }
#line 7331 "pnfasm.tab.cpp"
    break;

  case 473: /* instruction: IUNTIL TVOID VOID  */
#line 2409 "pnfasm.ypp"
                                            { fprintf(output, "293 0 0\n"); }
#line 7337 "pnfasm.tab.cpp"
    break;

  case 474: /* instruction: IUNTILB TVOID VOID  */
#line 2410 "pnfasm.ypp"
                                        { fprintf(output, "294 0 0\n"); }
#line 7343 "pnfasm.tab.cpp"
    break;

  case 475: /* instruction: IUNTILE TVOID VOID  */
#line 2411 "pnfasm.ypp"
                                        { fprintf(output, "295 0 0\n"); }
#line 7349 "pnfasm.tab.cpp"
    break;

  case 476: /* instruction: IUNTILBB TVOID VOID  */
#line 2412 "pnfasm.ypp"
                                        { fprintf(output, "296 0 0\n"); }
#line 7355 "pnfasm.tab.cpp"
    break;

  case 477: /* instruction: IUNTILBBB TVOID VOID  */
#line 2413 "pnfasm.ypp"
                                        { fprintf(output, "297 0 0\n"); }
#line 7361 "pnfasm.tab.cpp"
    break;

  case 478: /* instruction: IUNTILBBE TVOID VOID  */
#line 2414 "pnfasm.ypp"
                                        { fprintf(output, "298 0 0\n"); }
#line 7367 "pnfasm.tab.cpp"
    break;

  case 479: /* instruction: IFOR TVOID VOID  */
#line 2415 "pnfasm.ypp"
                                        { fprintf(output, "299 0 0\n"); }
#line 7373 "pnfasm.tab.cpp"
    break;

  case 480: /* instruction: IFORINIT TVOID VOID  */
#line 2416 "pnfasm.ypp"
                                        { fprintf(output, "300 0 0\n"); }
#line 7379 "pnfasm.tab.cpp"
    break;

  case 481: /* instruction: IFORCOND TVOID VOID  */
#line 2417 "pnfasm.ypp"
                                        { fprintf(output, "301 0 0\n"); }
#line 7385 "pnfasm.tab.cpp"
    break;

  case 482: /* instruction: IFORINC TVOID VOID  */
#line 2418 "pnfasm.ypp"
                                        { fprintf(output, "302 0 0\n"); }
#line 7391 "pnfasm.tab.cpp"
    break;

  case 483: /* instruction: IFORB TVOID VOID  */
#line 2419 "pnfasm.ypp"
                                        { fprintf(output, "303 0 0\n"); }
#line 7397 "pnfasm.tab.cpp"
    break;

  case 484: /* instruction: IFORE TVOID VOID  */
#line 2420 "pnfasm.ypp"
                                        { fprintf(output, "304 0 0\n"); }
#line 7403 "pnfasm.tab.cpp"
    break;

  case 485: /* instruction: ICLASS TSTRING STRING  */
#line 2421 "pnfasm.ypp"
                                        { 
						 fprintf(output, "305 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7417 "pnfasm.tab.cpp"
    break;

  case 486: /* instruction: ICLASSVAR TSTRING STRING  */
#line 2430 "pnfasm.ypp"
                                                { 
						 fprintf(output, "306 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7431 "pnfasm.tab.cpp"
    break;

  case 487: /* instruction: IENDCLASS TVOID VOID  */
#line 2439 "pnfasm.ypp"
                                        { fprintf(output, "307 0 0\n"); }
#line 7437 "pnfasm.tab.cpp"
    break;

  case 488: /* instruction: ICLASSNAME TSTRING STRING  */
#line 2440 "pnfasm.ypp"
                                                { 
						 fprintf(output, "308 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7451 "pnfasm.tab.cpp"
    break;

  case 489: /* instruction: ICLASSONAME TSTRING STRING  */
#line 2449 "pnfasm.ypp"
                                                { 
						 fprintf(output, "309 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7465 "pnfasm.tab.cpp"
    break;

  case 490: /* instruction: ICLASSD TSTRING STRING  */
#line 2458 "pnfasm.ypp"
                                                { 
						 fprintf(output, "310 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7479 "pnfasm.tab.cpp"
    break;

  case 491: /* instruction: ICLASSUSE TVOID VOID  */
#line 2467 "pnfasm.ypp"
                                                { 
						 fprintf(output, "311 0 0\n");
						}
#line 7487 "pnfasm.tab.cpp"
    break;

  case 492: /* instruction: ICLASSUSE TNUMBER VOID  */
#line 2470 "pnfasm.ypp"
                                                {	
						fprintf(output, "311 2 0\n");
						}
#line 7495 "pnfasm.tab.cpp"
    break;

  case 493: /* instruction: ICLASSUSE TSTRING STRING  */
#line 2473 "pnfasm.ypp"
                                                { 
						 fprintf(output, "311 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7509 "pnfasm.tab.cpp"
    break;

  case 494: /* instruction: ICLASSUSING TVOID VOID  */
#line 2482 "pnfasm.ypp"
                                                { 
						 fprintf(output, "312 0 0\n");
						}
#line 7517 "pnfasm.tab.cpp"
    break;

  case 495: /* instruction: ICLASSUSINGNAME TVOID VOID  */
#line 2485 "pnfasm.ypp"
                                                { 
						 fprintf(output, "313 0 0\n");
						}
#line 7525 "pnfasm.tab.cpp"
    break;

  case 496: /* instruction: ICLASSGET TVOID VOID  */
#line 2488 "pnfasm.ypp"
                                                { 
						 fprintf(output, "314 0 0\n");
						}
#line 7533 "pnfasm.tab.cpp"
    break;

  case 497: /* instruction: ICLASSPUT TVOID VOID  */
#line 2491 "pnfasm.ypp"
                                                { 
						 fprintf(output, "315 0 0\n");
						}
#line 7541 "pnfasm.tab.cpp"
    break;

  case 498: /* instruction: ICLASSTYPE TVOID VOID  */
#line 2495 "pnfasm.ypp"
                                        { 
						 fprintf(output, "316 0 0\n");
						}
#line 7549 "pnfasm.tab.cpp"
    break;

  case 499: /* instruction: ICLASSTYPE2 TVOID VOID  */
#line 2498 "pnfasm.ypp"
                                                { 
						 fprintf(output, "317 0 0\n");
						}
#line 7557 "pnfasm.tab.cpp"
    break;

  case 500: /* instruction: ICLASSNAME2 TVOID VOID  */
#line 2501 "pnfasm.ypp"
                                                { 
						 fprintf(output, "318 0 0\n");
						}
#line 7565 "pnfasm.tab.cpp"
    break;

  case 501: /* instruction: ICLASSNAME3 TVOID VOID  */
#line 2504 "pnfasm.ypp"
                                                { 
						 fprintf(output, "319 0 0\n");
						}
#line 7573 "pnfasm.tab.cpp"
    break;

  case 502: /* instruction: ICLASSMETHOD TNUMBER NUMBER  */
#line 2507 "pnfasm.ypp"
                                              { fprintf(output, "320 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7579 "pnfasm.tab.cpp"
    break;

  case 503: /* instruction: ICLASSMETHOD2 TSTRING STRING  */
#line 2508 "pnfasm.ypp"
                                                { 
						 fprintf(output, "321 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7593 "pnfasm.tab.cpp"
    break;

  case 504: /* instruction: ICLASSMETHODCALL TSTRING STRING  */
#line 2517 "pnfasm.ypp"
                                                { 
						 fprintf(output, "322 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7607 "pnfasm.tab.cpp"
    break;

  case 505: /* instruction: ICLASSMETHODCPARAMS TVOID VOID  */
#line 2526 "pnfasm.ypp"
                                                                { fprintf(output, "323 0 0\n"); }
#line 7613 "pnfasm.tab.cpp"
    break;

  case 506: /* instruction: ICLASSMETHODECPARAMS TVOID VOID  */
#line 2527 "pnfasm.ypp"
                                                                { fprintf(output, "324 0 0\n"); }
#line 7619 "pnfasm.tab.cpp"
    break;

  case 507: /* instruction: ICLASSMETHODECALL TVOID VOID  */
#line 2528 "pnfasm.ypp"
                                                        { fprintf(output, "325 0 0\n"); }
#line 7625 "pnfasm.tab.cpp"
    break;

  case 508: /* instruction: ICLASSEXTENDACCESS TSTRING STRING  */
#line 2529 "pnfasm.ypp"
                                                { 
						 fprintf(output, "326 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7639 "pnfasm.tab.cpp"
    break;

  case 509: /* instruction: ICLASSEXTEND TSTRING STRING  */
#line 2538 "pnfasm.ypp"
                                        { 
						 fprintf(output, "327 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7653 "pnfasm.tab.cpp"
    break;

  case 510: /* instruction: ICLASSIMPLEMENTACCESS TSTRING STRING  */
#line 2547 "pnfasm.ypp"
                                                { 
						 fprintf(output, "328 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7667 "pnfasm.tab.cpp"
    break;

  case 511: /* instruction: ICLASSIMPLEMENT TSTRING STRING  */
#line 2556 "pnfasm.ypp"
                                                { 
						 fprintf(output, "329 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7681 "pnfasm.tab.cpp"
    break;

  case 512: /* instruction: ASMVERSION TVOID VOID  */
#line 2566 "pnfasm.ypp"
                                                { /* Do nothing... */ }
#line 7687 "pnfasm.tab.cpp"
    break;

  case 513: /* instruction: PNF NUMBER NUMBER NUMBER  */
#line 2567 "pnfasm.ypp"
                                                { fprintf(output, "%s %s %s\n", yyvsp[-2].getString().c_str(), yyvsp[-1].getString().c_str(), yyvsp[0].getString().c_str()); }
#line 7693 "pnfasm.tab.cpp"
    break;

  case 515: /* variable: IVAR TVOID VOID  */
#line 2577 "pnfasm.ypp"
                                                { fprintf(output, "57 0 0\n"); }
#line 7699 "pnfasm.tab.cpp"
    break;

  case 516: /* variable: IVAR TBOOLEAN BOOLEAN  */
#line 2579 "pnfasm.ypp"
                                                {
			 			 if (yyvsp[0] == "true")
		 	  			  fprintf(output, "57 1 1\n");
			 			 else
			  			  fprintf(output, "57 1 0\n");
						}
#line 7710 "pnfasm.tab.cpp"
    break;

  case 517: /* variable: IVAR TNUMBER NUMBER  */
#line 2585 "pnfasm.ypp"
                                                { fprintf(output, "57 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7716 "pnfasm.tab.cpp"
    break;

  case 518: /* variable: IVAR TCHARACTER CHARACTER  */
#line 2587 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "57 3 %i\n", ch);
						}
#line 7726 "pnfasm.tab.cpp"
    break;

  case 519: /* variable: IVAR TSTRING STRING  */
#line 2593 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7737 "pnfasm.tab.cpp"
    break;

  case 520: /* variable: IVAR TBOOLEAN VOID  */
#line 2599 "pnfasm.ypp"
                                                { fprintf(output, "57 1 0\n"); }
#line 7743 "pnfasm.tab.cpp"
    break;

  case 521: /* variable: IVAR TNUMBER VOID  */
#line 2600 "pnfasm.ypp"
                                                { fprintf(output, "57 2 0\n"); }
#line 7749 "pnfasm.tab.cpp"
    break;

  case 522: /* variable: IVAR TCHARACTER VOID  */
#line 2601 "pnfasm.ypp"
                                                { fprintf(output, "57 3 0\n"); }
#line 7755 "pnfasm.tab.cpp"
    break;

  case 523: /* variable: IVAR TSTRING VOID  */
#line 2602 "pnfasm.ypp"
                                                { fprintf(output, "57 4 0\n"); }
#line 7761 "pnfasm.tab.cpp"
    break;

  case 524: /* variable: IVAR TVOID STRING  */
#line 2604 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 0 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7772 "pnfasm.tab.cpp"
    break;

  case 525: /* variable: IVAR TBOOLEAN STRING  */
#line 2611 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 1 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7783 "pnfasm.tab.cpp"
    break;

  case 526: /* variable: IVAR TNUMBER STRING  */
#line 2618 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 2 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7794 "pnfasm.tab.cpp"
    break;

  case 527: /* variable: IVAR TCHARACTER STRING  */
#line 2625 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 3 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7805 "pnfasm.tab.cpp"
    break;

  case 528: /* pp: PINCLUDE STRING  */
#line 2634 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#include %s\n", yyvsp[0].getString().c_str()); }
#line 7811 "pnfasm.tab.cpp"
    break;

  case 529: /* pp: PINCLUDE "<" STRING ">"  */
#line 2635 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#include <%s>\n", yyvsp[-2].getString().c_str()); }
#line 7817 "pnfasm.tab.cpp"
    break;

  case 530: /* pp: PIMPORT STRING  */
#line 2636 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#import %s \n", yyvsp[0].getString().c_str()); }
#line 7823 "pnfasm.tab.cpp"
    break;

  case 531: /* pp: PIMPORT "<" STRING ">"  */
#line 2637 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#import <%s> \n", yyvsp[-2].getString().c_str()); }
#line 7829 "pnfasm.tab.cpp"
    break;

  case 532: /* pp: PDEFINE STRING STRING  */
#line 2638 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#define %s %s\n", yyvsp[-1].getString().c_str(), yyvsp[0].getString().c_str()); }
#line 7835 "pnfasm.tab.cpp"
    break;

  case 533: /* pp: PMACRO STRING  */
#line 2639 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#macro %s\n", yyvsp[0].getString().c_str()); }
#line 7841 "pnfasm.tab.cpp"
    break;

  case 534: /* pp: PENDM  */
#line 2640 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#endm\n"); }
#line 7847 "pnfasm.tab.cpp"
    break;

  case 535: /* pp: PUNDEF STRING  */
#line 2641 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#undef %s\n", yyvsp[0].getString().c_str()); }
#line 7853 "pnfasm.tab.cpp"
    break;

  case 536: /* pp: PIFDEF STRING  */
#line 2642 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#ifdef %s\n", yyvsp[0].getString().c_str()); }
#line 7859 "pnfasm.tab.cpp"
    break;

  case 537: /* pp: PIFNDEF STRING  */
#line 2643 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#ifndef %s\n", yyvsp[0].getString().c_str()); }
#line 7865 "pnfasm.tab.cpp"
    break;

  case 538: /* pp: PELSE  */
#line 2644 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#else\n"); }
#line 7871 "pnfasm.tab.cpp"
    break;

  case 539: /* pp: PENDIF  */
#line 2645 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#endif\n"); }
#line 7877 "pnfasm.tab.cpp"
    break;

  case 540: /* pp: PPDATE  */
#line 2646 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_DATE()\n"); }
#line 7883 "pnfasm.tab.cpp"
    break;

  case 541: /* pp: PPTIME  */
#line 2647 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_TIME()\n"); }
#line 7889 "pnfasm.tab.cpp"
    break;

  case 542: /* pp: PPLINE  */
#line 2648 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_LINE()\n"); }
#line 7895 "pnfasm.tab.cpp"
    break;

  case 543: /* pp: PPFILE  */
#line 2649 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_FILE()\n"); }
#line 7901 "pnfasm.tab.cpp"
    break;

  case 544: /* pp: PPCDATE  */
#line 2650 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_CDATE()\n"); }
#line 7907 "pnfasm.tab.cpp"
    break;

  case 545: /* pp: PPCTIME  */
#line 2651 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_CTIME()\n"); }
#line 7913 "pnfasm.tab.cpp"
    break;

  case 546: /* pp: PPCOMMENT  */
#line 2652 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "\' %s\n", yyvsp[0].getString().c_str()); }
#line 7919 "pnfasm.tab.cpp"
    break;

  case 547: /* directive: BIN  */
#line 2655 "pnfasm.ypp"
                        { mode = 0; }
#line 7925 "pnfasm.tab.cpp"
    break;

  case 548: /* directive: PBIN  */
#line 2656 "pnfasm.ypp"
                        { mode = 1; }
#line 7931 "pnfasm.tab.cpp"
    break;

  case 549: /* directive: LIB  */
#line 2657 "pnfasm.ypp"
                        { mode = 2; }
#line 7937 "pnfasm.tab.cpp"
    break;


#line 7941 "pnfasm.tab.cpp"

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

#line 2660 "pnfasm.ypp"

/* Additional C/C++ Code */
void yyerror(char const * c)
{
 cout << "* ERROR: " << yylineno << ": " << c << endl;
}
