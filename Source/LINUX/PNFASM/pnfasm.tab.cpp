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
    ILOOP = 567,                   /* ILOOP  */
    IELOOP = 568,                  /* IELOOP  */
    IWHILE = 569,                  /* IWHILE  */
    IWHILEB = 570,                 /* IWHILEB  */
    IWHILEE = 571,                 /* IWHILEE  */
    IWHILEBB = 572,                /* IWHILEBB  */
    IWHILEBBB = 573,               /* IWHILEBBB  */
    IWHILEBBE = 574,               /* IWHILEBBE  */
    IUNTIL = 575,                  /* IUNTIL  */
    IUNTILB = 576,                 /* IUNTILB  */
    IUNTILE = 577,                 /* IUNTILE  */
    IUNTILBB = 578,                /* IUNTILBB  */
    IUNTILBBB = 579,               /* IUNTILBBB  */
    IUNTILBBE = 580,               /* IUNTILBBE  */
    IFOR = 581,                    /* IFOR  */
    IFORINIT = 582,                /* IFORINIT  */
    IFORCOND = 583,                /* IFORCOND  */
    IFORINC = 584,                 /* IFORINC  */
    IFORB = 585,                   /* IFORB  */
    IFORE = 586,                   /* IFORE  */
    IFORBB = 587,                  /* IFORBB  */
    IFORBBINIT = 588,              /* IFORBBINIT  */
    IFORBBCOND = 589,              /* IFORBBCOND  */
    IFORBBINC = 590,               /* IFORBBINC  */
    IFORBBB = 591,                 /* IFORBBB  */
    IFORBBE = 592,                 /* IFORBBE  */
    IFOREVER = 593,                /* IFOREVER  */
    IFOREVERE = 594,               /* IFOREVERE  */
    IBREAK = 595,                  /* IBREAK  */
    ICONTINUE = 596,               /* ICONTINUE  */
    ICLASS = 597,                  /* ICLASS  */
    ICLASSVAR = 598,               /* ICLASSVAR  */
    IENDCLASS = 599,               /* IENDCLASS  */
    ICLASSNAME = 600,              /* ICLASSNAME  */
    ICLASSONAME = 601,             /* ICLASSONAME  */
    ICLASSD = 602,                 /* ICLASSD  */
    ICLASSUSE = 603,               /* ICLASSUSE  */
    ICLASSUSING = 604,             /* ICLASSUSING  */
    ICLASSUSINGNAME = 605,         /* ICLASSUSINGNAME  */
    ICLASSGET = 606,               /* ICLASSGET  */
    ICLASSPUT = 607,               /* ICLASSPUT  */
    ICLASSTYPE = 608,              /* ICLASSTYPE  */
    ICLASSTYPE2 = 609,             /* ICLASSTYPE2  */
    ICLASSNAME2 = 610,             /* ICLASSNAME2  */
    ICLASSNAME3 = 611,             /* ICLASSNAME3  */
    ICLASSMETHOD = 612,            /* ICLASSMETHOD  */
    ICLASSMETHOD2 = 613,           /* ICLASSMETHOD2  */
    ICLASSMETHODCALL = 614,        /* ICLASSMETHODCALL  */
    ICLASSMETHODCPARAMS = 615,     /* ICLASSMETHODCPARAMS  */
    ICLASSMETHODECPARAMS = 616,    /* ICLASSMETHODECPARAMS  */
    ICLASSMETHODECALL = 617,       /* ICLASSMETHODECALL  */
    ICLASSEXTENDACCESS = 618,      /* ICLASSEXTENDACCESS  */
    ICLASSEXTEND = 619,            /* ICLASSEXTEND  */
    ICLASSIMPLEMENTACCESS = 620,   /* ICLASSIMPLEMENTACCESS  */
    ICLASSIMPLEMENT = 621,         /* ICLASSIMPLEMENT  */
    TVOID = 622,                   /* TVOID  */
    TBOOLEAN = 623,                /* TBOOLEAN  */
    TNUMBER = 624,                 /* TNUMBER  */
    TCHARACTER = 625,              /* TCHARACTER  */
    TSTRING = 626,                 /* TSTRING  */
    VOID = 627,                    /* VOID  */
    BOOLEAN = 628,                 /* BOOLEAN  */
    NUMBER = 629,                  /* NUMBER  */
    CHARACTER = 630,               /* CHARACTER  */
    STRING = 631                   /* STRING  */
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
  YYSYMBOL_ILOOP = 312,                    /* ILOOP  */
  YYSYMBOL_IELOOP = 313,                   /* IELOOP  */
  YYSYMBOL_IWHILE = 314,                   /* IWHILE  */
  YYSYMBOL_IWHILEB = 315,                  /* IWHILEB  */
  YYSYMBOL_IWHILEE = 316,                  /* IWHILEE  */
  YYSYMBOL_IWHILEBB = 317,                 /* IWHILEBB  */
  YYSYMBOL_IWHILEBBB = 318,                /* IWHILEBBB  */
  YYSYMBOL_IWHILEBBE = 319,                /* IWHILEBBE  */
  YYSYMBOL_IUNTIL = 320,                   /* IUNTIL  */
  YYSYMBOL_IUNTILB = 321,                  /* IUNTILB  */
  YYSYMBOL_IUNTILE = 322,                  /* IUNTILE  */
  YYSYMBOL_IUNTILBB = 323,                 /* IUNTILBB  */
  YYSYMBOL_IUNTILBBB = 324,                /* IUNTILBBB  */
  YYSYMBOL_IUNTILBBE = 325,                /* IUNTILBBE  */
  YYSYMBOL_IFOR = 326,                     /* IFOR  */
  YYSYMBOL_IFORINIT = 327,                 /* IFORINIT  */
  YYSYMBOL_IFORCOND = 328,                 /* IFORCOND  */
  YYSYMBOL_IFORINC = 329,                  /* IFORINC  */
  YYSYMBOL_IFORB = 330,                    /* IFORB  */
  YYSYMBOL_IFORE = 331,                    /* IFORE  */
  YYSYMBOL_IFORBB = 332,                   /* IFORBB  */
  YYSYMBOL_IFORBBINIT = 333,               /* IFORBBINIT  */
  YYSYMBOL_IFORBBCOND = 334,               /* IFORBBCOND  */
  YYSYMBOL_IFORBBINC = 335,                /* IFORBBINC  */
  YYSYMBOL_IFORBBB = 336,                  /* IFORBBB  */
  YYSYMBOL_IFORBBE = 337,                  /* IFORBBE  */
  YYSYMBOL_IFOREVER = 338,                 /* IFOREVER  */
  YYSYMBOL_IFOREVERE = 339,                /* IFOREVERE  */
  YYSYMBOL_IBREAK = 340,                   /* IBREAK  */
  YYSYMBOL_ICONTINUE = 341,                /* ICONTINUE  */
  YYSYMBOL_ICLASS = 342,                   /* ICLASS  */
  YYSYMBOL_ICLASSVAR = 343,                /* ICLASSVAR  */
  YYSYMBOL_IENDCLASS = 344,                /* IENDCLASS  */
  YYSYMBOL_ICLASSNAME = 345,               /* ICLASSNAME  */
  YYSYMBOL_ICLASSONAME = 346,              /* ICLASSONAME  */
  YYSYMBOL_ICLASSD = 347,                  /* ICLASSD  */
  YYSYMBOL_ICLASSUSE = 348,                /* ICLASSUSE  */
  YYSYMBOL_ICLASSUSING = 349,              /* ICLASSUSING  */
  YYSYMBOL_ICLASSUSINGNAME = 350,          /* ICLASSUSINGNAME  */
  YYSYMBOL_ICLASSGET = 351,                /* ICLASSGET  */
  YYSYMBOL_ICLASSPUT = 352,                /* ICLASSPUT  */
  YYSYMBOL_ICLASSTYPE = 353,               /* ICLASSTYPE  */
  YYSYMBOL_ICLASSTYPE2 = 354,              /* ICLASSTYPE2  */
  YYSYMBOL_ICLASSNAME2 = 355,              /* ICLASSNAME2  */
  YYSYMBOL_ICLASSNAME3 = 356,              /* ICLASSNAME3  */
  YYSYMBOL_ICLASSMETHOD = 357,             /* ICLASSMETHOD  */
  YYSYMBOL_ICLASSMETHOD2 = 358,            /* ICLASSMETHOD2  */
  YYSYMBOL_ICLASSMETHODCALL = 359,         /* ICLASSMETHODCALL  */
  YYSYMBOL_ICLASSMETHODCPARAMS = 360,      /* ICLASSMETHODCPARAMS  */
  YYSYMBOL_ICLASSMETHODECPARAMS = 361,     /* ICLASSMETHODECPARAMS  */
  YYSYMBOL_ICLASSMETHODECALL = 362,        /* ICLASSMETHODECALL  */
  YYSYMBOL_ICLASSEXTENDACCESS = 363,       /* ICLASSEXTENDACCESS  */
  YYSYMBOL_ICLASSEXTEND = 364,             /* ICLASSEXTEND  */
  YYSYMBOL_ICLASSIMPLEMENTACCESS = 365,    /* ICLASSIMPLEMENTACCESS  */
  YYSYMBOL_ICLASSIMPLEMENT = 366,          /* ICLASSIMPLEMENT  */
  YYSYMBOL_TVOID = 367,                    /* TVOID  */
  YYSYMBOL_TBOOLEAN = 368,                 /* TBOOLEAN  */
  YYSYMBOL_TNUMBER = 369,                  /* TNUMBER  */
  YYSYMBOL_TCHARACTER = 370,               /* TCHARACTER  */
  YYSYMBOL_TSTRING = 371,                  /* TSTRING  */
  YYSYMBOL_VOID = 372,                     /* VOID  */
  YYSYMBOL_BOOLEAN = 373,                  /* BOOLEAN  */
  YYSYMBOL_NUMBER = 374,                   /* NUMBER  */
  YYSYMBOL_CHARACTER = 375,                /* CHARACTER  */
  YYSYMBOL_STRING = 376,                   /* STRING  */
  YYSYMBOL_377_n_ = 377,                   /* '\n'  */
  YYSYMBOL_378_ = 378,                     /* "<"  */
  YYSYMBOL_379_ = 379,                     /* ">"  */
  YYSYMBOL_YYACCEPT = 380,                 /* $accept  */
  YYSYMBOL_input = 381,                    /* input  */
  YYSYMBOL_line = 382,                     /* line  */
  YYSYMBOL_instruction = 383,              /* instruction  */
  YYSYMBOL_pinstruction = 384,             /* pinstruction  */
  YYSYMBOL_variable = 385,                 /* variable  */
  YYSYMBOL_pp = 386,                       /* pp  */
  YYSYMBOL_directive = 387                 /* directive  */
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
#define YYLAST   1509

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  380
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  566
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1447

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   633


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
     377,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   378,   379
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1212,  1212,  1213,  1216,  1217,  1218,  1219,  1220,  1221,
    1222,  1225,  1226,  1227,  1228,  1236,  1237,  1238,  1239,  1240,
    1246,  1247,  1252,  1261,  1262,  1268,  1269,  1274,  1283,  1284,
    1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,
    1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1337,  1343,
    1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,
    1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,
    1364,  1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,
    1374,  1380,  1381,  1388,  1389,  1396,  1397,  1404,  1405,  1412,
    1413,  1414,  1415,  1416,  1417,  1424,  1426,  1427,  1433,  1434,
    1440,  1441,  1446,  1456,  1457,  1463,  1464,  1469,  1479,  1480,
    1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,  1490,
    1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,
    1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,
    1511,  1518,  1519,  1525,  1535,  1536,  1537,  1538,  1539,  1540,
    1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,  1549,  1550,
    1551,  1558,  1559,  1565,  1575,  1576,  1583,  1584,  1590,  1600,
    1601,  1602,  1603,  1604,  1614,  1624,  1634,  1635,  1645,  1646,
    1656,  1657,  1658,  1659,  1660,  1661,  1667,  1668,  1673,  1682,
    1683,  1689,  1690,  1695,  1704,  1705,  1706,  1707,  1708,  1709,
    1718,  1719,  1720,  1721,  1730,  1731,  1740,  1749,  1758,  1759,
    1760,  1761,  1762,  1763,  1772,  1773,  1774,  1775,  1784,  1793,
    1802,  1803,  1812,  1821,  1822,  1831,  1840,  1849,  1858,  1859,
    1860,  1869,  1870,  1879,  1880,  1881,  1882,  1883,  1884,  1885,
    1886,  1887,  1888,  1889,  1890,  1891,  1892,  1893,  1894,  1895,
    1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,  1904,  1909,
    1918,  1919,  1920,  1921,  1922,  1923,  1924,  1925,  1926,  1927,
    1928,  1929,  1938,  1939,  1948,  1949,  1950,  1951,  1952,  1953,
    1960,  1961,  1967,  1974,  1975,  1976,  1977,  1978,  1979,  1980,
    1981,  1982,  1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,
    1991,  1992,  1993,  1994,  1995,  1996,  1997,  1998,  1999,  2001,
    2008,  2009,  2010,  2011,  2012,  2013,  2014,  2015,  2016,  2017,
    2018,  2019,  2020,  2021,  2022,  2023,  2024,  2025,  2026,  2032,
    2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,  2041,  2042,
    2043,  2044,  2045,  2046,  2047,  2048,  2049,  2050,  2051,  2052,
    2053,  2054,  2055,  2056,  2057,  2058,  2059,  2060,  2061,  2062,
    2063,  2064,  2073,  2082,  2091,  2100,  2109,  2110,  2119,  2128,
    2137,  2140,  2143,  2152,  2155,  2158,  2161,  2165,  2168,  2171,
    2174,  2178,  2187,  2196,  2197,  2206,  2215,  2224,  2227,  2230,
    2239,  2242,  2245,  2248,  2252,  2255,  2258,  2261,  2265,  2269,
    2273,  2274,  2281,  2282,  2288,  2298,  2299,  2306,  2307,  2313,
    2323,  2324,  2331,  2332,  2338,  2348,  2349,  2356,  2357,  2363,
    2374,  2378,  2382,  2386,  2388,  2390,  2394,  2396,  2398,  2402,
    2406,  2409,  2410,  2411,  2412,  2413,  2414,  2415,  2416,  2417,
    2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,  2426,  2427,
    2428,  2429,  2430,  2431,  2432,  2433,  2434,  2435,  2436,  2437,
    2438,  2439,  2440,  2441,  2442,  2443,  2444,  2445,  2446,  2455,
    2456,  2457,  2466,  2475,  2484,  2485,  2494,  2503,  2512,  2515,
    2518,  2527,  2530,  2533,  2536,  2540,  2543,  2546,  2549,  2552,
    2553,  2562,  2571,  2572,  2573,  2574,  2583,  2592,  2601,  2611,
    2612,  2619,  2622,  2623,  2630,  2631,  2637,  2644,  2645,  2646,
    2647,  2648,  2655,  2662,  2669,  2679,  2680,  2681,  2682,  2683,
    2684,  2685,  2686,  2687,  2688,  2689,  2690,  2691,  2692,  2693,
    2694,  2695,  2696,  2697,  2700,  2701,  2702
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
  "ISEGTOP", "ISEGVLOAD", "ISEGVSTORE", "IMSG", "ILOOP", "IELOOP",
  "IWHILE", "IWHILEB", "IWHILEE", "IWHILEBB", "IWHILEBBB", "IWHILEBBE",
  "IUNTIL", "IUNTILB", "IUNTILE", "IUNTILBB", "IUNTILBBB", "IUNTILBBE",
  "IFOR", "IFORINIT", "IFORCOND", "IFORINC", "IFORB", "IFORE", "IFORBB",
  "IFORBBINIT", "IFORBBCOND", "IFORBBINC", "IFORBBB", "IFORBBE",
  "IFOREVER", "IFOREVERE", "IBREAK", "ICONTINUE", "ICLASS", "ICLASSVAR",
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

#define YYPACT_NINF (-366)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -366,     0,  -366,  -366,  -365,    -7,  -366,  -366,  -366,   229,
     230,   143,   189,  -366,   267,   269,   271,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,   201,   202,   233,   242,
     274,     1,    11,     5,   204,   277,   208,   279,   212,   281,
     216,   282,   220,   243,   224,   246,   283,    16,    21,   151,
     247,   250,   251,   254,   255,   258,   259,   284,   285,   262,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   177,   182,   183,   184,   185,   298,   299,   300,
     301,   190,   302,    26,   191,    31,    36,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,    41,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,    46,    51,   349,   350,   351,   352,
     353,   354,   355,   192,   193,   228,    56,    61,   356,   360,
     361,   362,   363,   364,   365,   367,   366,   368,   369,   370,
     371,   372,   373,   377,   378,   379,   380,   381,   382,   384,
     383,   385,   386,   387,   390,   389,   391,   388,   392,   393,
     394,   395,   400,   401,   398,   402,   399,   263,   405,    66,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,    71,   420,   421,   422,   423,   424,
     425,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     438,   440,   439,    76,    81,    86,   441,    91,    96,   101,
     442,   444,   443,   266,   447,   448,   449,   106,   111,   265,
     450,   451,   452,   455,   456,   457,   458,   459,   116,   121,
     460,   461,   462,   463,   126,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   478,   475,   476,   477,   156,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   157,   496,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   131,   136,   141,   146,   509,
     510,   511,   512,   513,   516,   515,   517,   518,   520,   521,
     232,   270,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   162,   163,   551,   552,   553,   554,   555,   556,   168,
     557,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   575,   573,   574,   576,   577,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,   359,   264,  -366,   426,  -366,
     481,   559,  -366,  -366,  -366,  -366,   268,   376,   560,   358,
     437,   446,   578,   427,   375,   579,   580,   581,   582,   445,
     583,   584,   585,   587,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     619,   618,   620,   621,   622,   623,   626,   625,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   588,   617,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   655,   656,   657,   658,
     659,   660,   662,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,   685,   687,   688,   689,   690,   686,   693,
     194,   169,   164,   171,   195,   694,   691,   696,   697,   695,
     698,   699,   700,   701,   702,   703,   704,   705,   707,   708,
     709,   712,   711,   714,   713,   716,   715,   718,   717,   720,
     719,   722,   721,   724,   723,   726,   725,   728,   727,   730,
     729,   731,   732,   733,   734,   737,   738,   739,   740,   741,
     742,   706,   743,   745,   746,   747,   748,   750,   749,   751,
     752,   755,   756,   757,   758,   759,   760,   761,   762,   764,
     765,   763,   766,   767,   770,   771,   769,   772,   768,   774,
     773,   775,   776,   777,   778,   779,   780,   783,   781,   786,
     787,   788,   789,   790,   791,   792,   793,   794,   795,   796,
     797,   798,   799,   800,   802,   804,   805,   806,   803,   807,
     808,   811,   809,   810,   812,   813,   814,   817,   818,   819,
     820,   821,   822,   823,   825,   815,   824,   826,   827,   830,
     829,   831,   834,   832,   833,   835,   836,   838,   841,   839,
     840,   842,   844,   843,   847,   848,   849,   850,   851,   852,
     853,   854,   855,   856,   857,   858,   859,   860,   861,   862,
     863,   864,   865,   866,   867,   828,   868,   869,   870,   871,
     873,   875,   876,   877,   878,   881,   882,   883,   884,   885,
     874,   886,   887,   888,   889,   890,   891,   892,   893,   894,
     895,   896,   897,   899,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   912,   913,   914,   915,   916,   917,
     918,   919,   920,   921,   922,   923,   924,   925,   926,   927,
     929,   928,   930,   933,   934,   935,   936,   937,   938,   939,
     940,   941,   942,   943,   944,   945,   946,   947,   949,   948,
     950,   953,   954,   955,   956,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   967,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     982,   983,   984,   985,   986,   991,   988,   989,   990,   995,
     996,   993,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,  1016,  1013,  1018,
    1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
    1030,  1031,  1029,  1032,  1033,  1036,  1037,  1035,  1038,  1039,
    1042,  1043,  1041,  1044,  1045,  1048,  1049,  1047,  1050,  1034,
    1040,  1046,  1051,  1053,  1052,  1054,  1055,  1058,  1059,  1060,
    1061,  1062,  1063,  1064,  1067,  1066,  1068,  1069,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,  1057,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1113,  1110,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1130,  1128,  1129,  1131,  1132,  -366,  1135,
     479,   661,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,    10,     0,     0,   564,   565,   566,     0,
       0,     0,     0,   551,     0,     0,     0,   555,   556,   557,
     558,   559,   560,   561,   562,   563,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     4,     3,
       5,     6,     7,     8,     9,     0,     0,   545,     0,   547,
       0,     0,   550,   552,   553,   554,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   529,     0,
       0,     0,   549,    11,    12,    13,    14,    15,    16,    17,
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
     118,   119,   120,   121,   122,   123,   124,   125,   532,   541,
     537,   533,   542,   538,   534,   543,   539,   535,   544,   540,
     536,   126,   127,   128,   129,   130,   131,   132,   133,   134,
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
     255,   256,   257,   258,   259,   260,   261,   262,   264,   263,
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
     525,   526,   527,   528,   530,   546,   548
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   369,   370,   371,   372,   373,   374
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,     3,   375,     4,     5,     6,     7,     8,     9,    10,
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
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   376,   392,   393,
     394,   395,   396,   402,   403,   404,   405,   368,   397,   398,
     399,   400,   401,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   500,   501,   502,   503,   504,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   548,   549,
     550,   551,   552,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   645,   646,   647,   648,   649,   664,   665,
     666,   667,   668,   687,   688,   689,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   746,   747,   748,   749,   750,   751,   752,
     753,   754,   755,   760,   761,   762,   763,   764,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   822,   823,   824,   825,   826,   827,   828,   449,   381,
     450,   451,   452,   779,   796,   780,   797,   781,   798,   875,
     878,   876,   879,   877,   880,   887,  1033,   888,  1034,   889,
    1035,  1030,  1031,  1036,   483,  1032,  1037,  1038,   484,   485,
     487,   489,   491,   486,   488,   490,   492,   497,   505,   585,
     587,   498,   506,   586,   588,   382,  1028,  1039,   386,   387,
    1029,  1040,   406,   407,   408,   409,   411,   412,   413,   414,
     416,   417,   418,   419,   421,   422,   423,   424,   426,   427,
     428,   429,   432,   433,   434,   435,   589,   590,   591,   592,
     840,   841,   842,   843,   388,   377,   379,   378,   380,   389,
     430,   390,   431,   436,   453,   437,   454,   455,   457,   456,
     458,   459,   461,   460,   462,   463,   465,   464,   466,   469,
     642,   470,   643,   721,   736,   722,   737,   844,   909,   845,
     913,   391,   914,   383,   410,   384,   415,   385,   420,   425,
     438,   467,   468,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   493,   494,   495,   496,   499,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   578,   579,     0,     0,
     580,   581,     0,   603,   582,   583,   584,   604,   605,   606,
     607,   908,   917,   611,   609,   608,   610,     0,   613,   612,
     617,   614,   615,   616,   618,   619,   620,   621,   915,   922,
     625,   623,   622,   624,     0,   632,   626,   627,   628,   629,
     630,     0,   631,   633,   634,   635,   636,   637,   638,   639,
     641,   640,   644,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   669,   670,   671,
     672,     0,     0,   673,   674,   675,   676,   677,   678,   679,
     921,   681,   910,   683,   680,   684,   682,   685,   686,   918,
     702,   719,   720,   718,   723,   724,   725,   738,   919,   927,
     739,   740,   741,   742,   743,   744,   745,   756,   757,   758,
     759,   765,   766,   767,   768,   769,     0,     0,     0,     0,
     770,   771,   772,   773,   774,   775,   776,   777,   778,   782,
     783,   784,   785,   786,   787,   788,   789,   911,  1445,   792,
       0,   790,   791,   799,   793,   794,   795,   800,   801,   802,
     803,   804,   805,   806,   807,   808,   829,   830,   831,     0,
       0,   832,   833,   834,   835,   837,   836,   838,   839,   846,
     847,   848,   849,   850,   851,   852,   853,   854,   855,   856,
     857,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,   871,   872,   873,   874,     0,     0,
     883,     0,   881,   882,   890,   884,   885,   886,   891,   892,
     893,   894,   895,   896,   897,   912,   916,   898,   901,   902,
     899,   900,   903,     0,   904,   905,     0,   906,   907,     0,
     920,     0,     0,   925,   923,   926,   924,   930,   928,   931,
     929,   932,   933,   979,     0,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   947,   948,
     949,   950,   951,   952,   953,     0,     0,   954,   955,   956,
     957,   958,   959,   980,   960,   961,   962,   963,   964,   965,
     966,   967,   968,   969,   970,   971,   972,   973,   974,   975,
     976,   977,     0,   981,   978,   983,   982,   985,   984,   987,
     986,   989,   988,   991,   990,   993,   992,   994,   995,   996,
     997,     0,   999,   998,  1000,  1001,  1002,  1003,  1004,  1005,
    1446,     0,  1006,  1007,  1008,  1009,  1010,  1011,     0,  1013,
    1012,  1015,  1014,  1017,  1016,  1019,  1018,  1021,  1020,  1022,
    1023,     0,  1026,  1024,  1025,  1027,  1041,  1042,  1043,  1045,
    1044,     0,  1048,  1046,  1049,  1047,  1050,  1053,  1051,  1054,
    1052,  1087,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,     0,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,     0,  1085,     0,  1086,  1089,  1090,  1088,
    1092,  1091,  1093,  1094,     0,  1095,  1096,  1097,  1098,  1099,
    1100,  1101,  1102,  1103,     0,     0,  1104,  1105,  1107,  1106,
    1114,  1109,  1108,  1110,  1112,  1111,  1115,  1116,  1113,  1117,
       0,  1121,  1118,  1119,  1120,  1123,  1122,  1124,  1125,  1126,
    1127,  1128,  1129,     0,  1130,     0,  1131,  1134,  1132,  1135,
    1133,  1136,  1139,  1137,  1140,  1138,  1141,  1142,  1143,  1144,
       0,  1145,  1146,  1147,  1149,  1148,     0,  1161,  1150,  1151,
    1152,  1153,  1154,  1155,  1156,  1157,     0,  1159,  1158,  1160,
    1162,  1201,  1163,  1164,  1165,  1166,  1168,  1167,  1169,  1170,
    1173,  1171,  1172,  1174,  1176,  1175,  1178,  1179,  1177,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,
    1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,
       0,     0,  1202,  1205,  1203,  1206,  1204,  1207,  1208,     0,
    1216,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1217,     0,
    1219,  1220,  1221,  1218,  1223,  1222,  1224,     0,  1225,  1228,
    1226,  1229,  1227,  1230,  1231,  1232,  1233,  1234,  1235,  1236,
    1237,     0,  1239,  1238,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,     0,  1255,
    1257,     0,  1254,  1256,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,     0,     0,
    1272,  1274,  1275,  1273,  1276,  1277,  1278,  1279,  1280,  1281,
    1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,
    1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,
    1302,  1303,  1304,  1305,     0,     0,     0,     0,  1306,  1307,
    1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,     0,     0,
    1328,     0,  1326,  1327,  1332,  1329,  1330,  1331,  1333,  1334,
    1335,  1336,  1337,  1338,  1339,  1340,  1341,  1342,     0,     0,
    1343,  1344,  1345,  1346,  1348,  1347,  1365,  1350,  1349,  1351,
    1353,  1352,  1366,  1355,  1354,  1356,  1358,  1357,  1367,  1360,
    1359,  1361,  1363,  1362,  1370,  1368,  1364,  1369,  1371,  1372,
    1373,  1374,  1375,  1413,     0,  1376,  1377,  1378,  1379,  1380,
    1381,  1383,  1382,  1384,  1385,  1386,  1387,  1388,  1389,  1390,
    1391,  1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,
    1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,
    1411,     0,  1414,  1412,     0,  1415,     0,  1419,  1416,  1417,
    1418,  1423,  1420,  1421,  1422,  1424,  1425,  1426,  1427,  1428,
    1429,  1430,  1431,  1432,  1433,     0,     0,  1434,  1437,  1438,
    1435,  1436,  1439,     0,  1440,  1441,     0,  1442,  1443,  1444
};

static const yytype_int16 yycheck[] =
{
       0,     1,   367,     3,     4,     5,     6,     7,     8,     9,
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
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   374,   367,   368,
     369,   370,   371,   368,   369,   370,   371,   377,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   376,
     369,   370,   371,   367,   367,   369,   369,   371,   371,   367,
     367,   369,   369,   371,   371,   367,   372,   369,   374,   371,
     376,   372,   373,   372,   367,   376,   375,   376,   371,   367,
     367,   367,   367,   371,   371,   371,   371,   367,   367,   367,
     367,   371,   371,   371,   371,   376,   372,   372,   367,   367,
     376,   376,   368,   369,   370,   371,   368,   369,   370,   371,
     368,   369,   370,   371,   368,   369,   370,   371,   368,   369,
     370,   371,   368,   369,   370,   371,   368,   369,   370,   371,
     368,   369,   370,   371,   371,   376,   376,   378,   378,   367,
     367,   369,   369,   367,   367,   369,   369,   367,   367,   369,
     369,   367,   367,   369,   369,   367,   367,   369,   369,   367,
     367,   369,   369,   367,   369,   369,   371,   367,   374,   369,
     372,   367,   374,   376,   367,   376,   367,   376,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,    -1,    -1,
     369,   369,    -1,   367,   371,   371,   371,   367,   367,   367,
     367,   372,   374,   367,   369,   371,   369,    -1,   369,   371,
     367,   371,   371,   371,   367,   367,   367,   367,   372,   374,
     367,   369,   371,   369,    -1,   367,   371,   371,   371,   369,
     371,    -1,   371,   371,   371,   371,   371,   367,   367,   371,
     371,   369,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,    -1,    -1,   369,   369,   367,   367,   367,   367,   367,
     373,   367,   376,   367,   371,   367,   371,   367,   369,   372,
     369,   367,   369,   371,   367,   367,   367,   367,   372,   374,
     369,   369,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,    -1,    -1,    -1,    -1,
     371,   371,   371,   371,   371,   367,   371,   371,   371,   367,
     367,   367,   367,   367,   367,   367,   367,   376,   379,   367,
      -1,   371,   371,   367,   371,   371,   371,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,    -1,
      -1,   369,   369,   367,   369,   367,   369,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,    -1,    -1,
     367,    -1,   371,   371,   367,   371,   371,   371,   367,   367,
     367,   367,   367,   367,   367,   376,   376,   369,   367,   367,
     371,   371,   367,    -1,   371,   371,    -1,   371,   371,    -1,
     372,    -1,    -1,   372,   375,   373,   376,   372,   375,   372,
     376,   372,   372,   375,    -1,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,    -1,    -1,   374,   374,   374,
     374,   372,   374,   376,   374,   374,   374,   374,   372,   374,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,    -1,   372,   374,   372,   374,   372,   374,   372,
     374,   372,   374,   372,   374,   372,   374,   372,   372,   372,
     372,    -1,   372,   374,   372,   372,   372,   372,   372,   372,
     379,    -1,   374,   374,   374,   374,   374,   374,    -1,   374,
     376,   374,   376,   374,   376,   374,   376,   372,   376,   372,
     372,    -1,   376,   374,   374,   372,   372,   376,   372,   374,
     373,    -1,   372,   375,   373,   376,   374,   372,   375,   372,
     376,   375,   374,   374,   372,   374,   372,   374,   372,   374,
     372,   374,   372,   374,   372,   374,   372,   374,   372,   374,
     372,   374,   372,   374,    -1,   374,   374,   374,   374,   372,
     372,   372,   372,    -1,   373,    -1,   374,   372,   372,   376,
     372,   374,   372,   374,    -1,   374,   374,   372,   372,   372,
     372,   372,   372,   372,    -1,    -1,   374,   373,   375,   374,
     372,   374,   376,   373,   375,   374,   372,   374,   376,   374,
      -1,   372,   376,   376,   376,   372,   376,   376,   372,   372,
     372,   372,   372,    -1,   373,    -1,   374,   372,   375,   373,
     376,   374,   372,   375,   372,   376,   372,   372,   372,   376,
      -1,   374,   374,   372,   374,   376,    -1,   372,   376,   376,
     376,   374,   374,   374,   374,   374,    -1,   374,   376,   374,
     376,   373,   376,   376,   374,   376,   372,   376,   376,   376,
     372,   376,   376,   372,   374,   376,   372,   374,   376,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
      -1,    -1,   374,   372,   375,   372,   376,   372,   372,    -1,
     376,   374,   374,   372,   372,   372,   372,   372,   372,    -1,
     372,   372,   372,   376,   372,   374,   373,    -1,   374,   372,
     375,   372,   376,   372,   372,   372,   372,   372,   372,   372,
     372,    -1,   372,   374,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,    -1,   372,
     372,    -1,   376,   374,   374,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,    -1,    -1,
     374,   372,   374,   376,   374,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,    -1,    -1,    -1,    -1,   376,   376,
     376,   376,   376,   372,   376,   376,   376,   372,   372,   376,
     372,   372,   372,   372,   372,   372,   372,   372,    -1,    -1,
     372,    -1,   376,   376,   372,   376,   376,   376,   372,   376,
     372,   372,   372,   372,   372,   372,   372,   372,    -1,    -1,
     374,   374,   374,   373,   375,   374,   372,   374,   376,   373,
     375,   374,   372,   374,   376,   373,   375,   374,   372,   374,
     376,   373,   375,   374,   372,   374,   376,   374,   374,   374,
     372,   372,   372,   376,    -1,   374,   374,   374,   374,   372,
     374,   372,   374,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,    -1,   372,   374,    -1,   374,    -1,   372,   376,   376,
     376,   372,   376,   376,   376,   372,   376,   372,   372,   372,
     372,   372,   372,   372,   372,    -1,    -1,   374,   372,   372,
     376,   376,   372,    -1,   376,   376,    -1,   376,   376,   374
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   381,     0,     1,     3,     4,     5,     6,     7,     8,
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
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   377,   382,
     383,   384,   385,   386,   387,   367,   374,   376,   378,   376,
     378,   376,   376,   376,   376,   376,   367,   367,   371,   367,
     369,   367,   367,   368,   369,   370,   371,   367,   368,   369,
     370,   371,   368,   369,   370,   371,   368,   369,   370,   371,
     367,   368,   369,   370,   371,   367,   368,   369,   370,   371,
     367,   368,   369,   370,   371,   367,   368,   369,   370,   371,
     367,   369,   368,   369,   370,   371,   367,   369,   367,   367,
     368,   369,   370,   371,   367,   368,   369,   370,   371,   367,
     369,   370,   371,   367,   369,   367,   369,   367,   369,   367,
     369,   367,   369,   367,   369,   367,   369,   367,   367,   367,
     369,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   371,   367,   371,   367,   371,   367,
     371,   367,   371,   367,   367,   367,   367,   367,   371,   367,
     367,   368,   369,   370,   371,   367,   371,   367,   368,   369,
     370,   371,   367,   368,   369,   370,   371,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   368,
     369,   370,   371,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   367,
     369,   369,   371,   371,   371,   367,   371,   367,   371,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   367,   367,   367,   367,   371,   369,
     369,   367,   371,   369,   371,   371,   371,   367,   367,   367,
     367,   367,   371,   369,   369,   367,   371,   371,   371,   369,
     371,   371,   367,   371,   371,   371,   371,   367,   367,   371,
     369,   371,   367,   369,   367,   367,   368,   369,   370,   371,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   368,   369,   370,   371,   367,
     367,   367,   367,   369,   369,   367,   367,   367,   367,   367,
     371,   367,   371,   367,   367,   367,   369,   367,   368,   369,
     370,   371,   367,   368,   369,   370,   371,   367,   368,   369,
     370,   371,   369,   367,   368,   369,   370,   371,   367,   368,
     369,   370,   371,   367,   368,   369,   370,   371,   371,   367,
     369,   367,   369,   367,   367,   367,   367,   368,   369,   370,
     371,   367,   368,   369,   370,   371,   369,   371,   367,   369,
     369,   367,   367,   367,   367,   367,   367,   368,   369,   370,
     371,   367,   368,   369,   370,   371,   367,   367,   367,   367,
     367,   368,   369,   370,   371,   367,   367,   367,   367,   367,
     371,   371,   371,   371,   371,   367,   371,   371,   371,   367,
     369,   371,   367,   367,   367,   367,   367,   367,   367,   367,
     371,   371,   367,   371,   371,   371,   367,   369,   371,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     368,   369,   370,   371,   367,   368,   369,   370,   371,   367,
     368,   369,   370,   371,   367,   368,   369,   370,   371,   367,
     367,   367,   369,   369,   367,   369,   369,   367,   367,   367,
     368,   369,   370,   371,   367,   369,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   369,   371,   367,   369,
     371,   371,   371,   367,   371,   371,   371,   367,   369,   371,
     367,   367,   367,   367,   367,   367,   367,   367,   369,   371,
     371,   367,   367,   367,   371,   371,   371,   371,   372,   374,
     376,   376,   376,   372,   374,   372,   376,   374,   372,   372,
     372,   373,   374,   375,   376,   372,   373,   374,   375,   376,
     372,   372,   372,   372,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   374,   374,   374,   374,   372,   374,
     374,   374,   374,   374,   372,   374,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   374,   375,
     376,   372,   374,   372,   374,   372,   374,   372,   374,   372,
     374,   372,   374,   372,   372,   372,   372,   372,   374,   372,
     372,   372,   372,   372,   372,   372,   374,   374,   374,   374,
     374,   374,   376,   374,   376,   374,   376,   374,   376,   374,
     376,   372,   372,   372,   374,   374,   376,   372,   372,   376,
     372,   373,   376,   372,   374,   376,   372,   375,   376,   372,
     376,   372,   376,   372,   373,   374,   375,   376,   372,   373,
     374,   375,   376,   372,   372,   374,   374,   372,   374,   372,
     374,   372,   374,   372,   374,   372,   374,   372,   374,   372,
     374,   372,   374,   372,   374,   372,   374,   374,   374,   374,
     374,   372,   372,   372,   372,   373,   374,   375,   376,   372,
     372,   374,   372,   372,   374,   374,   374,   372,   372,   372,
     372,   372,   372,   372,   374,   373,   374,   375,   376,   374,
     373,   374,   375,   376,   372,   372,   374,   374,   376,   376,
     376,   372,   376,   372,   376,   372,   372,   372,   372,   372,
     373,   374,   375,   376,   372,   373,   374,   375,   376,   372,
     372,   372,   372,   372,   376,   374,   374,   372,   376,   374,
     376,   376,   376,   374,   374,   374,   374,   374,   376,   374,
     374,   372,   376,   376,   376,   374,   376,   376,   372,   376,
     376,   376,   376,   372,   372,   376,   374,   376,   372,   374,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   373,   374,   375,   376,   372,   372,   372,   372,   374,
     374,   372,   372,   372,   372,   372,   376,   372,   376,   372,
     372,   372,   374,   372,   373,   374,   375,   376,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   374,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   376,   372,   374,   372,   374,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   374,   376,   372,   374,   374,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   376,   376,   376,   376,
     376,   372,   376,   376,   376,   372,   372,   376,   372,   372,
     372,   372,   372,   372,   372,   372,   376,   376,   372,   376,
     376,   376,   372,   372,   376,   372,   372,   372,   372,   372,
     372,   372,   372,   374,   374,   374,   373,   374,   375,   376,
     374,   373,   374,   375,   376,   374,   373,   374,   375,   376,
     374,   373,   374,   375,   376,   372,   372,   372,   374,   374,
     372,   374,   374,   372,   372,   372,   374,   374,   374,   374,
     372,   374,   374,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   374,   376,   372,   374,   376,   376,   376,   372,
     376,   376,   376,   372,   372,   376,   372,   372,   372,   372,
     372,   372,   372,   372,   374,   376,   376,   372,   372,   372,
     376,   376,   376,   376,   374,   379,   379
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   380,   381,   381,   382,   382,   382,   382,   382,   382,
     382,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   384,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   387,   387,   387
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     4,     2,     4,     3,
       2,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 1222 "pnfasm.ypp"
                                { yyerrok; }
#line 3935 "pnfasm.tab.cpp"
    break;

  case 11: /* instruction: IVERSION TVOID VOID  */
#line 1225 "pnfasm.ypp"
                                        { fprintf(output, "0 0 0\n"); }
#line 3941 "pnfasm.tab.cpp"
    break;

  case 12: /* instruction: IVERSION TVOID NUMBER  */
#line 1226 "pnfasm.ypp"
                                        { fprintf(output, "0 0 %s\n", yyvsp[0].getString().c_str()); }
#line 3947 "pnfasm.tab.cpp"
    break;

  case 13: /* instruction: IVOID TVOID VOID  */
#line 1227 "pnfasm.ypp"
                                        { fprintf(output, "1 0 0\n"); }
#line 3953 "pnfasm.tab.cpp"
    break;

  case 14: /* instruction: ICRASH TSTRING STRING  */
#line 1229 "pnfasm.ypp"
                {
		 fprintf(output, "2 4 ");

		 for (int i = 1; yyvsp[0][i] != '\"'; ++i)
                  fprintf(output, "%i ", yyvsp[0][i]);
		 fprintf(output, "0\n");
		}
#line 3965 "pnfasm.tab.cpp"
    break;

  case 15: /* instruction: IQUIT TVOID NUMBER  */
#line 1236 "pnfasm.ypp"
                                                { fprintf(output, "3 0 %s\n", yyvsp[0].getString().c_str()); }
#line 3971 "pnfasm.tab.cpp"
    break;

  case 16: /* instruction: IQUIT TNUMBER VOID  */
#line 1237 "pnfasm.ypp"
                                                { fprintf(output, "3 2 0\n"); }
#line 3977 "pnfasm.tab.cpp"
    break;

  case 17: /* instruction: IHALT TVOID VOID  */
#line 1238 "pnfasm.ypp"
                                                { fprintf(output, "4 0 0\n"); }
#line 3983 "pnfasm.tab.cpp"
    break;

  case 18: /* instruction: IPRINT TVOID VOID  */
#line 1239 "pnfasm.ypp"
                                                { fprintf(output, "5 0 0\n"); }
#line 3989 "pnfasm.tab.cpp"
    break;

  case 19: /* instruction: IPRINT TBOOLEAN BOOLEAN  */
#line 1240 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "5 1 1\n");
						 else
						  fprintf(output, "5 1 0\n");
					        }
#line 4000 "pnfasm.tab.cpp"
    break;

  case 20: /* instruction: IPRINT TNUMBER NUMBER  */
#line 1246 "pnfasm.ypp"
                                                { fprintf(output, "5 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4006 "pnfasm.tab.cpp"
    break;

  case 21: /* instruction: IPRINT TCHARACTER CHARACTER  */
#line 1247 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "5 3 %i\n", ch);
						}
#line 4016 "pnfasm.tab.cpp"
    break;

  case 22: /* instruction: IPRINT TSTRING STRING  */
#line 1252 "pnfasm.ypp"
                                                {
						 fprintf(output, "5 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4030 "pnfasm.tab.cpp"
    break;

  case 23: /* instruction: IPRINTLN TVOID VOID  */
#line 1261 "pnfasm.ypp"
                                                { fprintf(output, "6 0 0\n"); }
#line 4036 "pnfasm.tab.cpp"
    break;

  case 24: /* instruction: IPRINTLN TBOOLEAN BOOLEAN  */
#line 1262 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "6 1 1\n");
						 else
						  fprintf(output, "6 1 0\n");
					        }
#line 4047 "pnfasm.tab.cpp"
    break;

  case 25: /* instruction: IPRINTLN TNUMBER NUMBER  */
#line 1268 "pnfasm.ypp"
                                                { fprintf(output, "6 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4053 "pnfasm.tab.cpp"
    break;

  case 26: /* instruction: IPRINTLN TCHARACTER CHARACTER  */
#line 1269 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "6 3 %i\n", ch);
						}
#line 4063 "pnfasm.tab.cpp"
    break;

  case 27: /* instruction: IPRINTLN TSTRING STRING  */
#line 1274 "pnfasm.ypp"
                                                { 
						 fprintf(output, "6 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4077 "pnfasm.tab.cpp"
    break;

  case 28: /* instruction: IREAD TBOOLEAN VOID  */
#line 1283 "pnfasm.ypp"
                                                { fprintf(output, "7 1 0\n"); }
#line 4083 "pnfasm.tab.cpp"
    break;

  case 29: /* instruction: IREAD TNUMBER VOID  */
#line 1284 "pnfasm.ypp"
                                                { fprintf(output, "7 2 0\n"); }
#line 4089 "pnfasm.tab.cpp"
    break;

  case 30: /* instruction: IREAD TCHARACTER VOID  */
#line 1285 "pnfasm.ypp"
                                                { fprintf(output, "7 3 0\n"); }
#line 4095 "pnfasm.tab.cpp"
    break;

  case 31: /* instruction: IREAD TSTRING VOID  */
#line 1286 "pnfasm.ypp"
                                                { fprintf(output, "7 4 0\n"); }
#line 4101 "pnfasm.tab.cpp"
    break;

  case 32: /* instruction: ILOAD TBOOLEAN NUMBER  */
#line 1287 "pnfasm.ypp"
                                                { fprintf(output, "8 1 %s\n", yyvsp[0].getString().c_str()); }
#line 4107 "pnfasm.tab.cpp"
    break;

  case 33: /* instruction: ILOAD TNUMBER NUMBER  */
#line 1288 "pnfasm.ypp"
                                                { fprintf(output, "8 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4113 "pnfasm.tab.cpp"
    break;

  case 34: /* instruction: ILOAD TCHARACTER NUMBER  */
#line 1289 "pnfasm.ypp"
                                                { fprintf(output, "8 3 %s\n", yyvsp[0].getString().c_str()); }
#line 4119 "pnfasm.tab.cpp"
    break;

  case 35: /* instruction: ILOAD TSTRING NUMBER  */
#line 1290 "pnfasm.ypp"
                                                { fprintf(output, "8 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4125 "pnfasm.tab.cpp"
    break;

  case 36: /* instruction: ISTORE TVOID NUMBER  */
#line 1291 "pnfasm.ypp"
                                                { fprintf(output, "9 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4131 "pnfasm.tab.cpp"
    break;

  case 37: /* instruction: ILOADC TBOOLEAN NUMBER  */
#line 1292 "pnfasm.ypp"
                                                { fprintf(output, "10 1 %s\n", yyvsp[0].getString().c_str()); }
#line 4137 "pnfasm.tab.cpp"
    break;

  case 38: /* instruction: ILOADC TNUMBER NUMBER  */
#line 1293 "pnfasm.ypp"
                                                { fprintf(output, "10 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4143 "pnfasm.tab.cpp"
    break;

  case 39: /* instruction: ILOADC TCHARACTER NUMBER  */
#line 1294 "pnfasm.ypp"
                                                { fprintf(output, "10 3 %s\n", yyvsp[0].getString().c_str()); }
#line 4149 "pnfasm.tab.cpp"
    break;

  case 40: /* instruction: ILOADC TSTRING NUMBER  */
#line 1295 "pnfasm.ypp"
                                                { fprintf(output, "10 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4155 "pnfasm.tab.cpp"
    break;

  case 41: /* instruction: ISTOREC TVOID NUMBER  */
#line 1296 "pnfasm.ypp"
                                                { fprintf(output, "11 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4161 "pnfasm.tab.cpp"
    break;

  case 42: /* instruction: IELOAD TBOOLEAN VOID  */
#line 1297 "pnfasm.ypp"
                                                { fprintf(output, "12 1 0\n"); }
#line 4167 "pnfasm.tab.cpp"
    break;

  case 43: /* instruction: IELOAD TNUMBER VOID  */
#line 1298 "pnfasm.ypp"
                                                { fprintf(output, "12 2 0\n"); }
#line 4173 "pnfasm.tab.cpp"
    break;

  case 44: /* instruction: IELOAD TCHARACTER VOID  */
#line 1299 "pnfasm.ypp"
                                                { fprintf(output, "12 3 0\n"); }
#line 4179 "pnfasm.tab.cpp"
    break;

  case 45: /* instruction: IELOAD TSTRING VOID  */
#line 1300 "pnfasm.ypp"
                                                { fprintf(output, "12 4 0\n"); }
#line 4185 "pnfasm.tab.cpp"
    break;

  case 46: /* instruction: IESTORE TVOID VOID  */
#line 1301 "pnfasm.ypp"
                                                { fprintf(output, "13 0 0\n"); }
#line 4191 "pnfasm.tab.cpp"
    break;

  case 47: /* instruction: IELOADC TBOOLEAN VOID  */
#line 1302 "pnfasm.ypp"
                                                { fprintf(output, "14 1 0\n"); }
#line 4197 "pnfasm.tab.cpp"
    break;

  case 48: /* instruction: IELOADC TNUMBER VOID  */
#line 1303 "pnfasm.ypp"
                                                { fprintf(output, "14 2 0\n"); }
#line 4203 "pnfasm.tab.cpp"
    break;

  case 49: /* instruction: IELOADC TCHARACTER VOID  */
#line 1304 "pnfasm.ypp"
                                                { fprintf(output, "14 3 0\n"); }
#line 4209 "pnfasm.tab.cpp"
    break;

  case 50: /* instruction: IELOADC TSTRING VOID  */
#line 1305 "pnfasm.ypp"
                                                { fprintf(output, "14 4 0\n"); }
#line 4215 "pnfasm.tab.cpp"
    break;

  case 51: /* instruction: IESTOREC TVOID VOID  */
#line 1306 "pnfasm.ypp"
                                                { fprintf(output, "15 0 0\n"); }
#line 4221 "pnfasm.tab.cpp"
    break;

  case 52: /* instruction: IVLOAD TBOOLEAN NUMBER  */
#line 1307 "pnfasm.ypp"
                                                { fprintf(output, "16 1 %s\n", yyvsp[0].getString().c_str()); }
#line 4227 "pnfasm.tab.cpp"
    break;

  case 53: /* instruction: IVLOAD TNUMBER NUMBER  */
#line 1308 "pnfasm.ypp"
                                                { fprintf(output, "16 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4233 "pnfasm.tab.cpp"
    break;

  case 54: /* instruction: IVLOAD TCHARACTER NUMBER  */
#line 1309 "pnfasm.ypp"
                                                { fprintf(output, "16 3 %s\n", yyvsp[0].getString().c_str()); }
#line 4239 "pnfasm.tab.cpp"
    break;

  case 55: /* instruction: IVLOAD TSTRING NUMBER  */
#line 1310 "pnfasm.ypp"
                                                { fprintf(output, "16 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4245 "pnfasm.tab.cpp"
    break;

  case 56: /* instruction: IVSTORE TVOID VOID  */
#line 1311 "pnfasm.ypp"
                                                { fprintf(output, "17 0 0\n"); }
#line 4251 "pnfasm.tab.cpp"
    break;

  case 57: /* instruction: IVSTORE TNUMBER NUMBER  */
#line 1312 "pnfasm.ypp"
                                                { fprintf(output, "17 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4257 "pnfasm.tab.cpp"
    break;

  case 58: /* instruction: IVLOADC TBOOLEAN NUMBER  */
#line 1313 "pnfasm.ypp"
                                                { fprintf(output, "18 1 %s\n", yyvsp[0].getString().c_str()); }
#line 4263 "pnfasm.tab.cpp"
    break;

  case 59: /* instruction: IVLOADC TNUMBER NUMBER  */
#line 1314 "pnfasm.ypp"
                                                { fprintf(output, "18 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4269 "pnfasm.tab.cpp"
    break;

  case 60: /* instruction: IVLOADC TCHARACTER NUMBER  */
#line 1315 "pnfasm.ypp"
                                                { fprintf(output, "18 3 %s\n", yyvsp[0].getString().c_str()); }
#line 4275 "pnfasm.tab.cpp"
    break;

  case 61: /* instruction: IVLOADC TSTRING NUMBER  */
#line 1316 "pnfasm.ypp"
                                                { fprintf(output, "18 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4281 "pnfasm.tab.cpp"
    break;

  case 62: /* instruction: IVSTOREC TVOID VOID  */
#line 1317 "pnfasm.ypp"
                                                { fprintf(output, "19 0 0\n"); }
#line 4287 "pnfasm.tab.cpp"
    break;

  case 63: /* instruction: IVSTOREC TNUMBER NUMBER  */
#line 1318 "pnfasm.ypp"
                                                { fprintf(output, "19 4 %s\n", yyvsp[0].getString().c_str()); }
#line 4293 "pnfasm.tab.cpp"
    break;

  case 64: /* instruction: ISTOREA TVOID VOID  */
#line 1319 "pnfasm.ypp"
                                                { fprintf(output, "20 0 0\n"); }
#line 4299 "pnfasm.tab.cpp"
    break;

  case 65: /* instruction: IMODT TVOID VOID  */
#line 1320 "pnfasm.ypp"
                                                { fprintf(output, "21 0 0\n"); }
#line 4305 "pnfasm.tab.cpp"
    break;

  case 66: /* instruction: IMODT TBOOLEAN VOID  */
#line 1321 "pnfasm.ypp"
                                                { fprintf(output, "21 1 0\n"); }
#line 4311 "pnfasm.tab.cpp"
    break;

  case 67: /* instruction: IMODT TNUMBER VOID  */
#line 1322 "pnfasm.ypp"
                                                { fprintf(output, "21 2 0\n"); }
#line 4317 "pnfasm.tab.cpp"
    break;

  case 68: /* instruction: IMODT TCHARACTER VOID  */
#line 1323 "pnfasm.ypp"
                                                { fprintf(output, "21 3 0\n"); }
#line 4323 "pnfasm.tab.cpp"
    break;

  case 69: /* instruction: IMODT TSTRING VOID  */
#line 1324 "pnfasm.ypp"
                                                { fprintf(output, "21 4 0\n"); }
#line 4329 "pnfasm.tab.cpp"
    break;

  case 70: /* instruction: IMODCT TVOID VOID  */
#line 1325 "pnfasm.ypp"
                                                { fprintf(output, "22 0 0\n"); }
#line 4335 "pnfasm.tab.cpp"
    break;

  case 71: /* instruction: IMODCT TBOOLEAN VOID  */
#line 1326 "pnfasm.ypp"
                                                { fprintf(output, "22 1 0\n"); }
#line 4341 "pnfasm.tab.cpp"
    break;

  case 72: /* instruction: IMODCT TNUMBER VOID  */
#line 1327 "pnfasm.ypp"
                                                { fprintf(output, "22 2 0\n"); }
#line 4347 "pnfasm.tab.cpp"
    break;

  case 73: /* instruction: IMODCT TCHARACTER VOID  */
#line 1328 "pnfasm.ypp"
                                                { fprintf(output, "22 3 0\n"); }
#line 4353 "pnfasm.tab.cpp"
    break;

  case 74: /* instruction: IMODCT TSTRING VOID  */
#line 1329 "pnfasm.ypp"
                                                { fprintf(output, "22 4 0\n"); }
#line 4359 "pnfasm.tab.cpp"
    break;

  case 75: /* instruction: IADD TVOID VOID  */
#line 1330 "pnfasm.ypp"
                                                { fprintf(output, "23 0 0\n"); }
#line 4365 "pnfasm.tab.cpp"
    break;

  case 76: /* instruction: IADD TNUMBER NUMBER  */
#line 1331 "pnfasm.ypp"
                                                { fprintf(output, "23 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4371 "pnfasm.tab.cpp"
    break;

  case 77: /* instruction: IADD TCHARACTER CHARACTER  */
#line 1332 "pnfasm.ypp"
                                                        {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "23 3 %i\n", ch);
						}
#line 4381 "pnfasm.tab.cpp"
    break;

  case 78: /* instruction: IADD TSTRING STRING  */
#line 1337 "pnfasm.ypp"
                                                {		
						 fprintf(output, "23 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4392 "pnfasm.tab.cpp"
    break;

  case 79: /* instruction: ISUB TVOID VOID  */
#line 1343 "pnfasm.ypp"
                                                { fprintf(output, "24 0 0\n"); }
#line 4398 "pnfasm.tab.cpp"
    break;

  case 80: /* instruction: ISUB TNUMBER NUMBER  */
#line 1344 "pnfasm.ypp"
                                                { fprintf(output, "24 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4404 "pnfasm.tab.cpp"
    break;

  case 81: /* instruction: IMUL TVOID VOID  */
#line 1345 "pnfasm.ypp"
                                                { fprintf(output, "25 0 0\n"); }
#line 4410 "pnfasm.tab.cpp"
    break;

  case 82: /* instruction: IMUL TNUMBER NUMBER  */
#line 1346 "pnfasm.ypp"
                                                { fprintf(output, "25 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4416 "pnfasm.tab.cpp"
    break;

  case 83: /* instruction: IDIV TVOID VOID  */
#line 1347 "pnfasm.ypp"
                                                { fprintf(output, "26 0 0\n"); }
#line 4422 "pnfasm.tab.cpp"
    break;

  case 84: /* instruction: IDIV TNUMBER NUMBER  */
#line 1348 "pnfasm.ypp"
                                                { fprintf(output, "26 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4428 "pnfasm.tab.cpp"
    break;

  case 85: /* instruction: IMOD TVOID VOID  */
#line 1349 "pnfasm.ypp"
                                                { fprintf(output, "27 0 0\n"); }
#line 4434 "pnfasm.tab.cpp"
    break;

  case 86: /* instruction: IMOD TNUMBER NUMBER  */
#line 1350 "pnfasm.ypp"
                                                { fprintf(output, "27 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4440 "pnfasm.tab.cpp"
    break;

  case 87: /* instruction: IPOW TVOID VOID  */
#line 1351 "pnfasm.ypp"
                                                { fprintf(output, "28 0 0\n"); }
#line 4446 "pnfasm.tab.cpp"
    break;

  case 88: /* instruction: IPOW TNUMBER NUMBER  */
#line 1352 "pnfasm.ypp"
                                                { fprintf(output, "28 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4452 "pnfasm.tab.cpp"
    break;

  case 89: /* instruction: IROOT TVOID VOID  */
#line 1353 "pnfasm.ypp"
                                                { fprintf(output, "29 0 0\n"); }
#line 4458 "pnfasm.tab.cpp"
    break;

  case 90: /* instruction: IROOT TNUMBER NUMBER  */
#line 1354 "pnfasm.ypp"
                                                { fprintf(output, "29 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4464 "pnfasm.tab.cpp"
    break;

  case 91: /* instruction: IINC TVOID VOID  */
#line 1355 "pnfasm.ypp"
                                                { fprintf(output, "30 0 0\n"); }
#line 4470 "pnfasm.tab.cpp"
    break;

  case 92: /* instruction: IINC TNUMBER VOID  */
#line 1356 "pnfasm.ypp"
                                                { fprintf(output, "30 2 0\n"); }
#line 4476 "pnfasm.tab.cpp"
    break;

  case 93: /* instruction: IDEC TVOID VOID  */
#line 1357 "pnfasm.ypp"
                                                { fprintf(output, "31 0 0\n"); }
#line 4482 "pnfasm.tab.cpp"
    break;

  case 94: /* instruction: IEQU TVOID VOID  */
#line 1358 "pnfasm.ypp"
                                                { fprintf(output, "32 0 0\n"); }
#line 4488 "pnfasm.tab.cpp"
    break;

  case 95: /* instruction: INEQU TVOID VOID  */
#line 1359 "pnfasm.ypp"
                                                { fprintf(output, "33 0 0\n"); }
#line 4494 "pnfasm.tab.cpp"
    break;

  case 96: /* instruction: INEQU TNUMBER NUMBER  */
#line 1360 "pnfasm.ypp"
                                                { fprintf(output, "33 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4500 "pnfasm.tab.cpp"
    break;

  case 97: /* instruction: IGTR TVOID VOID  */
#line 1361 "pnfasm.ypp"
                                                { fprintf(output, "34 0 0\n"); }
#line 4506 "pnfasm.tab.cpp"
    break;

  case 98: /* instruction: ILSS TVOID VOID  */
#line 1362 "pnfasm.ypp"
                                                { fprintf(output, "35 0 0\n"); }
#line 4512 "pnfasm.tab.cpp"
    break;

  case 99: /* instruction: IGEQU TVOID VOID  */
#line 1363 "pnfasm.ypp"
                                                { fprintf(output, "36 0 0\n"); }
#line 4518 "pnfasm.tab.cpp"
    break;

  case 100: /* instruction: ILEQU TVOID VOID  */
#line 1364 "pnfasm.ypp"
                                                { fprintf(output, "37 0 0\n"); }
#line 4524 "pnfasm.tab.cpp"
    break;

  case 101: /* instruction: IAND TVOID VOID  */
#line 1365 "pnfasm.ypp"
                                                { fprintf(output, "38 0 0\n"); }
#line 4530 "pnfasm.tab.cpp"
    break;

  case 102: /* instruction: IOR TVOID VOID  */
#line 1366 "pnfasm.ypp"
                                                { fprintf(output, "39 0 0\n"); }
#line 4536 "pnfasm.tab.cpp"
    break;

  case 103: /* instruction: INOT TVOID VOID  */
#line 1367 "pnfasm.ypp"
                                                { fprintf(output, "40 0 0\n"); }
#line 4542 "pnfasm.tab.cpp"
    break;

  case 104: /* instruction: IGOTO TVOID NUMBER  */
#line 1368 "pnfasm.ypp"
                                                { fprintf(output, "41 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4548 "pnfasm.tab.cpp"
    break;

  case 105: /* instruction: ICGOTO TVOID NUMBER  */
#line 1369 "pnfasm.ypp"
                                                { fprintf(output, "42 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4554 "pnfasm.tab.cpp"
    break;

  case 106: /* instruction: IZGOTO TVOID NUMBER  */
#line 1370 "pnfasm.ypp"
                                                { fprintf(output, "43 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4560 "pnfasm.tab.cpp"
    break;

  case 107: /* instruction: IPGOTO TVOID NUMBER  */
#line 1371 "pnfasm.ypp"
                                                { fprintf(output, "44 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4566 "pnfasm.tab.cpp"
    break;

  case 108: /* instruction: INGOTO TVOID NUMBER  */
#line 1372 "pnfasm.ypp"
                                                { fprintf(output, "45 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4572 "pnfasm.tab.cpp"
    break;

  case 109: /* instruction: IGOTOL TVOID NUMBER  */
#line 1373 "pnfasm.ypp"
                                                { fprintf(output, "46 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4578 "pnfasm.tab.cpp"
    break;

  case 110: /* instruction: IGOTOL TSTRING STRING  */
#line 1374 "pnfasm.ypp"
                                                {
						 fprintf(output, "46 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4589 "pnfasm.tab.cpp"
    break;

  case 111: /* instruction: ICGOTOL TVOID NUMBER  */
#line 1380 "pnfasm.ypp"
                                                { fprintf(output, "47 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4595 "pnfasm.tab.cpp"
    break;

  case 112: /* instruction: ICGOTOL TSTRING STRING  */
#line 1382 "pnfasm.ypp"
                                                {
						 fprintf(output, "47 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4606 "pnfasm.tab.cpp"
    break;

  case 113: /* instruction: IZGOTOL TVOID NUMBER  */
#line 1388 "pnfasm.ypp"
                                                { fprintf(output, "48 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4612 "pnfasm.tab.cpp"
    break;

  case 114: /* instruction: IZGOTOL TSTRING STRING  */
#line 1390 "pnfasm.ypp"
                                                {
						 fprintf(output, "48 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4623 "pnfasm.tab.cpp"
    break;

  case 115: /* instruction: IPGOTOL TVOID NUMBER  */
#line 1396 "pnfasm.ypp"
                                                { fprintf(output, "49 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4629 "pnfasm.tab.cpp"
    break;

  case 116: /* instruction: IPGOTOL TSTRING STRING  */
#line 1398 "pnfasm.ypp"
                                                {
						 fprintf(output, "49 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4640 "pnfasm.tab.cpp"
    break;

  case 117: /* instruction: INGOTOL TVOID NUMBER  */
#line 1404 "pnfasm.ypp"
                                                { fprintf(output, "50 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4646 "pnfasm.tab.cpp"
    break;

  case 118: /* instruction: INGOTOL TSTRING STRING  */
#line 1406 "pnfasm.ypp"
                                                {
						 fprintf(output, "50 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4657 "pnfasm.tab.cpp"
    break;

  case 119: /* instruction: IST TVOID VOID  */
#line 1412 "pnfasm.ypp"
                                                { fprintf(output, "51 0 0\n"); }
#line 4663 "pnfasm.tab.cpp"
    break;

  case 120: /* instruction: IPUSH TVOID VOID  */
#line 1413 "pnfasm.ypp"
                                                { fprintf(output, "52 0 0\n"); }
#line 4669 "pnfasm.tab.cpp"
    break;

  case 121: /* instruction: IPOP TVOID VOID  */
#line 1414 "pnfasm.ypp"
                                                { fprintf(output, "53 0 0\n"); }
#line 4675 "pnfasm.tab.cpp"
    break;

  case 122: /* instruction: ICALL TVOID NUMBER  */
#line 1415 "pnfasm.ypp"
                                                { fprintf(output, "54 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4681 "pnfasm.tab.cpp"
    break;

  case 123: /* instruction: ICALLL TVOID NUMBER  */
#line 1416 "pnfasm.ypp"
                                                { fprintf(output, "55 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4687 "pnfasm.tab.cpp"
    break;

  case 124: /* instruction: ICALLL TSTRING STRING  */
#line 1418 "pnfasm.ypp"
                                                {
						 fprintf(output, "55 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 4698 "pnfasm.tab.cpp"
    break;

  case 125: /* instruction: IRET TVOID VOID  */
#line 1424 "pnfasm.ypp"
                                                { fprintf(output, "56 0 0\n"); }
#line 4704 "pnfasm.tab.cpp"
    break;

  case 126: /* instruction: ILBL TVOID VOID  */
#line 1426 "pnfasm.ypp"
                                                { fprintf(output, "58 0 0\n"); }
#line 4710 "pnfasm.tab.cpp"
    break;

  case 127: /* instruction: ILBL TSTRING STRING  */
#line 1427 "pnfasm.ypp"
                                                {
						 fprintf(output, "58 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");		
						}
#line 4721 "pnfasm.tab.cpp"
    break;

  case 128: /* instruction: IEPRINT TVOID VOID  */
#line 1433 "pnfasm.ypp"
                                                { fprintf(output, "59 0 0\n"); }
#line 4727 "pnfasm.tab.cpp"
    break;

  case 129: /* instruction: IEPRINT TBOOLEAN BOOLEAN  */
#line 1434 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "59 1 1\n");
						 else
						  fprintf(output, "59 1 0\n");
					        }
#line 4738 "pnfasm.tab.cpp"
    break;

  case 130: /* instruction: IEPRINT TNUMBER NUMBER  */
#line 1440 "pnfasm.ypp"
                                                        { fprintf(output, "59 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4744 "pnfasm.tab.cpp"
    break;

  case 131: /* instruction: IEPRINT TCHARACTER CHARACTER  */
#line 1441 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "59 3 %i\n", ch);
						}
#line 4754 "pnfasm.tab.cpp"
    break;

  case 132: /* instruction: IEPRINT TSTRING STRING  */
#line 1446 "pnfasm.ypp"
                                                { 
						 fprintf(output, "59 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4768 "pnfasm.tab.cpp"
    break;

  case 133: /* instruction: IEPRINTLN TVOID VOID  */
#line 1456 "pnfasm.ypp"
                                                { fprintf(output, "60 0 0\n"); }
#line 4774 "pnfasm.tab.cpp"
    break;

  case 134: /* instruction: IEPRINTLN TBOOLEAN BOOLEAN  */
#line 1457 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "60 1 1\n");
						 else
						  fprintf(output, "60 1 0\n");
					        }
#line 4785 "pnfasm.tab.cpp"
    break;

  case 135: /* instruction: IEPRINTLN TNUMBER NUMBER  */
#line 1463 "pnfasm.ypp"
                                                { fprintf(output, "60 2 %s\n", yyvsp[0].getString().c_str()); }
#line 4791 "pnfasm.tab.cpp"
    break;

  case 136: /* instruction: IEPRINTLN TCHARACTER CHARACTER  */
#line 1464 "pnfasm.ypp"
                                                        {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "60 3 %i\n", ch);
						}
#line 4801 "pnfasm.tab.cpp"
    break;

  case 137: /* instruction: IEPRINTLN TSTRING STRING  */
#line 1469 "pnfasm.ypp"
                                                { 
						 fprintf(output, "60 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 4815 "pnfasm.tab.cpp"
    break;

  case 138: /* instruction: IEND TVOID VOID  */
#line 1479 "pnfasm.ypp"
                                                { fprintf(output, "61 0 0"); }
#line 4821 "pnfasm.tab.cpp"
    break;

  case 139: /* instruction: IELBL TVOID VOID  */
#line 1480 "pnfasm.ypp"
                                                { fprintf(output, "62 0 0\n"); }
#line 4827 "pnfasm.tab.cpp"
    break;

  case 140: /* instruction: IEVLOAD TVOID NUMBER  */
#line 1481 "pnfasm.ypp"
                                                { fprintf(output, "63 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4833 "pnfasm.tab.cpp"
    break;

  case 141: /* instruction: IHEADD TVOID NUMBER  */
#line 1482 "pnfasm.ypp"
                                                { fprintf(output, "64 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4839 "pnfasm.tab.cpp"
    break;

  case 142: /* instruction: IHEREM TVOID VOID  */
#line 1483 "pnfasm.ypp"
                                                { fprintf(output, "65 0 0\n"); }
#line 4845 "pnfasm.tab.cpp"
    break;

  case 143: /* instruction: IHEED TVOID NUMBER  */
#line 1484 "pnfasm.ypp"
                                                { fprintf(output, "66 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4851 "pnfasm.tab.cpp"
    break;

  case 144: /* instruction: IHEGET TVOID VOID  */
#line 1485 "pnfasm.ypp"
                                                { fprintf(output, "67 0 0\n"); }
#line 4857 "pnfasm.tab.cpp"
    break;

  case 145: /* instruction: ISHEADD TVOID NUMBER  */
#line 1486 "pnfasm.ypp"
                                                { fprintf(output, "68 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4863 "pnfasm.tab.cpp"
    break;

  case 146: /* instruction: ISHEREM TVOID VOID  */
#line 1487 "pnfasm.ypp"
                                                { fprintf(output, "69 0 0\n"); }
#line 4869 "pnfasm.tab.cpp"
    break;

  case 147: /* instruction: ISHEED TVOID NUMBER  */
#line 1488 "pnfasm.ypp"
                                                { fprintf(output, "70 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4875 "pnfasm.tab.cpp"
    break;

  case 148: /* instruction: ISHEGET TVOID VOID  */
#line 1489 "pnfasm.ypp"
                                                { fprintf(output, "71 0 0\n"); }
#line 4881 "pnfasm.tab.cpp"
    break;

  case 149: /* instruction: IEADD TVOID NUMBER  */
#line 1490 "pnfasm.ypp"
                                                { fprintf(output, "72 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4887 "pnfasm.tab.cpp"
    break;

  case 150: /* instruction: IEREM TVOID VOID  */
#line 1491 "pnfasm.ypp"
                                                { fprintf(output, "73 0 0\n"); }
#line 4893 "pnfasm.tab.cpp"
    break;

  case 151: /* instruction: IEED TVOID NUMBER  */
#line 1492 "pnfasm.ypp"
                                                { fprintf(output, "74 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4899 "pnfasm.tab.cpp"
    break;

  case 152: /* instruction: IEGET TVOID VOID  */
#line 1493 "pnfasm.ypp"
                                                { fprintf(output, "75 0 0\n"); }
#line 4905 "pnfasm.tab.cpp"
    break;

  case 153: /* instruction: IEXADD TVOID NUMBER  */
#line 1494 "pnfasm.ypp"
                                                { fprintf(output, "76 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4911 "pnfasm.tab.cpp"
    break;

  case 154: /* instruction: IEXREM TVOID VOID  */
#line 1495 "pnfasm.ypp"
                                                { fprintf(output, "77 0 0\n"); }
#line 4917 "pnfasm.tab.cpp"
    break;

  case 155: /* instruction: IEXED TVOID NUMBER  */
#line 1496 "pnfasm.ypp"
                                                { fprintf(output, "78 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4923 "pnfasm.tab.cpp"
    break;

  case 156: /* instruction: IEXGET TVOID VOID  */
#line 1497 "pnfasm.ypp"
                                                { fprintf(output, "79 0 0\n"); }
#line 4929 "pnfasm.tab.cpp"
    break;

  case 157: /* instruction: IIADD TVOID NUMBER  */
#line 1498 "pnfasm.ypp"
                                                { fprintf(output, "80 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4935 "pnfasm.tab.cpp"
    break;

  case 158: /* instruction: IIREM TVOID VOID  */
#line 1499 "pnfasm.ypp"
                                                { fprintf(output, "81 0 0\n"); }
#line 4941 "pnfasm.tab.cpp"
    break;

  case 159: /* instruction: IIED TVOID NUMBER  */
#line 1500 "pnfasm.ypp"
                                                { fprintf(output, "82 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4947 "pnfasm.tab.cpp"
    break;

  case 160: /* instruction: IIGET TVOID VOID  */
#line 1501 "pnfasm.ypp"
                                                { fprintf(output, "83 0 0\n"); }
#line 4953 "pnfasm.tab.cpp"
    break;

  case 161: /* instruction: IHEVENT TVOID NUMBER  */
#line 1502 "pnfasm.ypp"
                                                { fprintf(output, "84 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4959 "pnfasm.tab.cpp"
    break;

  case 162: /* instruction: ISHEVENT TVOID NUMBER  */
#line 1503 "pnfasm.ypp"
                                                { fprintf(output, "85 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4965 "pnfasm.tab.cpp"
    break;

  case 163: /* instruction: IEVENT TVOID NUMBER  */
#line 1504 "pnfasm.ypp"
                                                { fprintf(output, "86 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4971 "pnfasm.tab.cpp"
    break;

  case 164: /* instruction: IEXCEPTION TVOID NUMBER  */
#line 1505 "pnfasm.ypp"
                                                { fprintf(output, "87 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4977 "pnfasm.tab.cpp"
    break;

  case 165: /* instruction: IINT TVOID NUMBER  */
#line 1506 "pnfasm.ypp"
                                                { fprintf(output, "88 0 %s\n", yyvsp[0].getString().c_str()); }
#line 4983 "pnfasm.tab.cpp"
    break;

  case 166: /* instruction: ITYPEOF TVOID VOID  */
#line 1507 "pnfasm.ypp"
                                                { fprintf(output, "89 0 0\n"); }
#line 4989 "pnfasm.tab.cpp"
    break;

  case 167: /* instruction: ICTYPEOF TVOID VOID  */
#line 1508 "pnfasm.ypp"
                                                { fprintf(output, "90 0 0\n"); }
#line 4995 "pnfasm.tab.cpp"
    break;

  case 168: /* instruction: ITLOAD TVOID VOID  */
#line 1509 "pnfasm.ypp"
                                                { fprintf(output, "91 0 0\n"); }
#line 5001 "pnfasm.tab.cpp"
    break;

  case 169: /* instruction: IALOAD TVOID VOID  */
#line 1510 "pnfasm.ypp"
                                                { fprintf(output, "92 0 0\n"); }
#line 5007 "pnfasm.tab.cpp"
    break;

  case 170: /* instruction: IALOAD TBOOLEAN BOOLEAN  */
#line 1512 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "92 1 1\n");
		 else
		  fprintf(output, "92 1 0\n");
		}
#line 5018 "pnfasm.tab.cpp"
    break;

  case 171: /* instruction: IALOAD TNUMBER NUMBER  */
#line 1518 "pnfasm.ypp"
                                                { fprintf(output, "92 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5024 "pnfasm.tab.cpp"
    break;

  case 172: /* instruction: IALOAD TCHARACTER CHARACTER  */
#line 1520 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "92 3 %i\n", ch);
		}
#line 5034 "pnfasm.tab.cpp"
    break;

  case 173: /* instruction: IALOAD TSTRING STRING  */
#line 1526 "pnfasm.ypp"
                {
		 fprintf(output, "92 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5048 "pnfasm.tab.cpp"
    break;

  case 174: /* instruction: IINLOAD TVOID VOID  */
#line 1535 "pnfasm.ypp"
                                                { fprintf(output, "93 0 0\n"); }
#line 5054 "pnfasm.tab.cpp"
    break;

  case 175: /* instruction: IICLOAD TVOID VOID  */
#line 1536 "pnfasm.ypp"
                                                { fprintf(output, "94 0 0\n"); }
#line 5060 "pnfasm.tab.cpp"
    break;

  case 176: /* instruction: IARLOAD TVOID NUMBER  */
#line 1537 "pnfasm.ypp"
                                                { fprintf(output, "95 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5066 "pnfasm.tab.cpp"
    break;

  case 177: /* instruction: IATOC TVOID VOID  */
#line 1538 "pnfasm.ypp"
                                                { fprintf(output, "96 0 0\n"); }
#line 5072 "pnfasm.tab.cpp"
    break;

  case 178: /* instruction: ISWITCH TVOID VOID  */
#line 1539 "pnfasm.ypp"
                                                { fprintf(output, "97 0 0\n"); }
#line 5078 "pnfasm.tab.cpp"
    break;

  case 179: /* instruction: IVADD TVOID NUMBER  */
#line 1540 "pnfasm.ypp"
                                                { fprintf(output, "98 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5084 "pnfasm.tab.cpp"
    break;

  case 180: /* instruction: ILADD TVOID NUMBER  */
#line 1541 "pnfasm.ypp"
                                                { fprintf(output, "99 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5090 "pnfasm.tab.cpp"
    break;

  case 181: /* instruction: IELADD TVOID NUMBER  */
#line 1542 "pnfasm.ypp"
                                                { fprintf(output, "100 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5096 "pnfasm.tab.cpp"
    break;

  case 182: /* instruction: IADD2V TVOID VOID  */
#line 1543 "pnfasm.ypp"
                                                { fprintf(output, "101 0 0\n"); }
#line 5102 "pnfasm.tab.cpp"
    break;

  case 183: /* instruction: IBTAND TVOID VOID  */
#line 1544 "pnfasm.ypp"
                                                { fprintf(output, "102 0 0\n"); }
#line 5108 "pnfasm.tab.cpp"
    break;

  case 184: /* instruction: IBTOR TVOID VOID  */
#line 1545 "pnfasm.ypp"
                                                { fprintf(output, "103 0 0\n"); }
#line 5114 "pnfasm.tab.cpp"
    break;

  case 185: /* instruction: IBTEXOR TVOID VOID  */
#line 1546 "pnfasm.ypp"
                                                { fprintf(output, "104 0 0\n"); }
#line 5120 "pnfasm.tab.cpp"
    break;

  case 186: /* instruction: IBTNOT TVOID VOID  */
#line 1547 "pnfasm.ypp"
                                                { fprintf(output, "105 0 0\n"); }
#line 5126 "pnfasm.tab.cpp"
    break;

  case 187: /* instruction: IBTSL TVOID VOID  */
#line 1548 "pnfasm.ypp"
                                                { fprintf(output, "106 0 0\n"); }
#line 5132 "pnfasm.tab.cpp"
    break;

  case 188: /* instruction: IBTSR TVOID VOID  */
#line 1549 "pnfasm.ypp"
                                                { fprintf(output, "107 0 0\n"); }
#line 5138 "pnfasm.tab.cpp"
    break;

  case 189: /* instruction: IVCHECK TVOID NUMBER  */
#line 1550 "pnfasm.ypp"
                                                { fprintf(output, "108 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5144 "pnfasm.tab.cpp"
    break;

  case 190: /* instruction: IVCHECK TBOOLEAN BOOLEAN  */
#line 1552 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "108 1 1\n");
		 else
		  fprintf(output, "108 1 0\n");
		}
#line 5155 "pnfasm.tab.cpp"
    break;

  case 191: /* instruction: IVCHECK TNUMBER NUMBER  */
#line 1558 "pnfasm.ypp"
                                                { fprintf(output, "108 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5161 "pnfasm.tab.cpp"
    break;

  case 192: /* instruction: IVCHECK TCHARACTER CHARACTER  */
#line 1560 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "108 3 %i\n", ch);
		}
#line 5171 "pnfasm.tab.cpp"
    break;

  case 193: /* instruction: IVCHECK TSTRING STRING  */
#line 1566 "pnfasm.ypp"
                {
		 fprintf(output, "108 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5185 "pnfasm.tab.cpp"
    break;

  case 194: /* instruction: IVSUPP TVOID NUMBER  */
#line 1575 "pnfasm.ypp"
                                                { fprintf(output, "109 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5191 "pnfasm.tab.cpp"
    break;

  case 195: /* instruction: IVSUPP TBOOLEAN BOOLEAN  */
#line 1577 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "109 1 1\n");
		 else
		  fprintf(output, "109 1 0\n");
		}
#line 5202 "pnfasm.tab.cpp"
    break;

  case 196: /* instruction: IVSUPP TNUMBER NUMBER  */
#line 1583 "pnfasm.ypp"
                                        { fprintf(output, "109 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5208 "pnfasm.tab.cpp"
    break;

  case 197: /* instruction: IVSUPP TCHARACTER CHARACTER  */
#line 1585 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "109 3 %i\n", ch);
		}
#line 5218 "pnfasm.tab.cpp"
    break;

  case 198: /* instruction: IVSUPP TSTRING STRING  */
#line 1591 "pnfasm.ypp"
                {
		 fprintf(output, "109 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5232 "pnfasm.tab.cpp"
    break;

  case 199: /* instruction: IVPRINT TVOID VOID  */
#line 1600 "pnfasm.ypp"
                                                { fprintf(output, "110 0 0\n"); }
#line 5238 "pnfasm.tab.cpp"
    break;

  case 200: /* instruction: IVPRINTLN TVOID VOID  */
#line 1601 "pnfasm.ypp"
                                                { fprintf(output, "111 0 0\n"); }
#line 5244 "pnfasm.tab.cpp"
    break;

  case 201: /* instruction: IISUPP TNUMBER NUMBER  */
#line 1602 "pnfasm.ypp"
                                                { fprintf(output, "112 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5250 "pnfasm.tab.cpp"
    break;

  case 202: /* instruction: ITSUPP TNUMBER NUMBER  */
#line 1603 "pnfasm.ypp"
                                                { fprintf(output, "113 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5256 "pnfasm.tab.cpp"
    break;

  case 203: /* instruction: ICOMMENT TSTRING STRING  */
#line 1605 "pnfasm.ypp"
                {
		 fprintf(output, "114 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5270 "pnfasm.tab.cpp"
    break;

  case 204: /* instruction: IFIMODE TSTRING STRING  */
#line 1615 "pnfasm.ypp"
                {
		 fprintf(output, "115 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5284 "pnfasm.tab.cpp"
    break;

  case 205: /* instruction: IFOMODE TSTRING STRING  */
#line 1625 "pnfasm.ypp"
                {
		 fprintf(output, "116 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5298 "pnfasm.tab.cpp"
    break;

  case 206: /* instruction: IFIOPEN TVOID VOID  */
#line 1634 "pnfasm.ypp"
                                                { fprintf(output, "117 0 0\n"); }
#line 5304 "pnfasm.tab.cpp"
    break;

  case 207: /* instruction: IFIOPEN TSTRING STRING  */
#line 1636 "pnfasm.ypp"
                {
		 fprintf(output, "117 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5318 "pnfasm.tab.cpp"
    break;

  case 208: /* instruction: IFOOPEN TVOID VOID  */
#line 1645 "pnfasm.ypp"
                                                { fprintf(output, "118 0 0\n"); }
#line 5324 "pnfasm.tab.cpp"
    break;

  case 209: /* instruction: IFOOPEN TSTRING STRING  */
#line 1647 "pnfasm.ypp"
                {
		 fprintf(output, "118 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 5338 "pnfasm.tab.cpp"
    break;

  case 210: /* instruction: IFREAD TBOOLEAN VOID  */
#line 1656 "pnfasm.ypp"
                                                { fprintf(output, "119 1 0\n"); }
#line 5344 "pnfasm.tab.cpp"
    break;

  case 211: /* instruction: IFREAD TNUMBER VOID  */
#line 1657 "pnfasm.ypp"
                                                { fprintf(output, "119 2 0\n"); }
#line 5350 "pnfasm.tab.cpp"
    break;

  case 212: /* instruction: IFREAD TCHARACTER VOID  */
#line 1658 "pnfasm.ypp"
                                                { fprintf(output, "119 3 0\n"); }
#line 5356 "pnfasm.tab.cpp"
    break;

  case 213: /* instruction: IFREAD TSTRING VOID  */
#line 1659 "pnfasm.ypp"
                                                { fprintf(output, "119 4 0\n"); }
#line 5362 "pnfasm.tab.cpp"
    break;

  case 214: /* instruction: IFPRINT TVOID VOID  */
#line 1660 "pnfasm.ypp"
                                                { fprintf(output, "120 0 0\n"); }
#line 5368 "pnfasm.tab.cpp"
    break;

  case 215: /* instruction: IFPRINT TBOOLEAN BOOLEAN  */
#line 1661 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "120 1 1\n");
						 else
						  fprintf(output, "120 1 0\n");
					        }
#line 5379 "pnfasm.tab.cpp"
    break;

  case 216: /* instruction: IFPRINT TNUMBER NUMBER  */
#line 1667 "pnfasm.ypp"
                                                { fprintf(output, "120 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5385 "pnfasm.tab.cpp"
    break;

  case 217: /* instruction: IFPRINT TCHARACTER CHARACTER  */
#line 1668 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "120 3 %i\n", ch);
						}
#line 5395 "pnfasm.tab.cpp"
    break;

  case 218: /* instruction: IFPRINT TSTRING STRING  */
#line 1673 "pnfasm.ypp"
                                                { 
						 fprintf(output, "120 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5409 "pnfasm.tab.cpp"
    break;

  case 219: /* instruction: IFPRINTLN TVOID VOID  */
#line 1682 "pnfasm.ypp"
                                                { fprintf(output, "121 0 0\n"); }
#line 5415 "pnfasm.tab.cpp"
    break;

  case 220: /* instruction: IFPRINTLN TBOOLEAN BOOLEAN  */
#line 1683 "pnfasm.ypp"
                                                {
						 if (yyvsp[0] == "true")
						  fprintf(output, "121 1 1\n");
						 else
						  fprintf(output, "121 1 0\n");
					        }
#line 5426 "pnfasm.tab.cpp"
    break;

  case 221: /* instruction: IFPRINTLN TNUMBER NUMBER  */
#line 1689 "pnfasm.ypp"
                                                { fprintf(output, "121 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5432 "pnfasm.tab.cpp"
    break;

  case 222: /* instruction: IFPRINTLN TCHARACTER CHARACTER  */
#line 1690 "pnfasm.ypp"
                                                        {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "121 3 %i\n", ch);
						}
#line 5442 "pnfasm.tab.cpp"
    break;

  case 223: /* instruction: IFPRINTLN TSTRING STRING  */
#line 1695 "pnfasm.ypp"
                                                { 
						 fprintf(output, "121 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5456 "pnfasm.tab.cpp"
    break;

  case 224: /* instruction: IFICLOSE TVOID VOID  */
#line 1704 "pnfasm.ypp"
                                                { fprintf(output, "122 0 0\n"); }
#line 5462 "pnfasm.tab.cpp"
    break;

  case 225: /* instruction: IFOCLOSE TVOID VOID  */
#line 1705 "pnfasm.ypp"
                                                { fprintf(output, "123 0 0\n"); }
#line 5468 "pnfasm.tab.cpp"
    break;

  case 226: /* instruction: IMEML TVOID VOID  */
#line 1706 "pnfasm.ypp"
                                                { fprintf(output, "124 0 0\n"); }
#line 5474 "pnfasm.tab.cpp"
    break;

  case 227: /* instruction: IFIEOF TVOID VOID  */
#line 1707 "pnfasm.ypp"
                                                { fprintf(output, "125 0 0\n"); }
#line 5480 "pnfasm.tab.cpp"
    break;

  case 228: /* instruction: IARNLOAD TVOID VOID  */
#line 1708 "pnfasm.ypp"
                                                { fprintf(output, "126 0 0\n"); }
#line 5486 "pnfasm.tab.cpp"
    break;

  case 229: /* instruction: IRDSTART1 TSTRING STRING  */
#line 1709 "pnfasm.ypp"
                                                { 
						 fprintf(output, "127 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5500 "pnfasm.tab.cpp"
    break;

  case 230: /* instruction: IRFROM1 TNUMBER NUMBER  */
#line 1718 "pnfasm.ypp"
                                                { fprintf(output, "128 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5506 "pnfasm.tab.cpp"
    break;

  case 231: /* instruction: IRTO1 TNUMBER NUMBER  */
#line 1719 "pnfasm.ypp"
                                                { fprintf(output, "129 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5512 "pnfasm.tab.cpp"
    break;

  case 232: /* instruction: IRDEND1 TVOID VOID  */
#line 1720 "pnfasm.ypp"
                                                { fprintf(output, "130 0 0\n"); }
#line 5518 "pnfasm.tab.cpp"
    break;

  case 233: /* instruction: IRSTART1 TSTRING STRING  */
#line 1721 "pnfasm.ypp"
                                                { 
						 fprintf(output, "131 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5532 "pnfasm.tab.cpp"
    break;

  case 234: /* instruction: IRANGE1 TNUMBER NUMBER  */
#line 1730 "pnfasm.ypp"
                                                { fprintf(output, "132 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5538 "pnfasm.tab.cpp"
    break;

  case 235: /* instruction: IREND1 TSTRING STRING  */
#line 1731 "pnfasm.ypp"
                                        { 
						 fprintf(output, "133 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5552 "pnfasm.tab.cpp"
    break;

  case 236: /* instruction: IRLOAD1 TSTRING STRING  */
#line 1740 "pnfasm.ypp"
                                                { 
						 fprintf(output, "134 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5566 "pnfasm.tab.cpp"
    break;

  case 237: /* instruction: IRSTORE1 TSTRING STRING  */
#line 1749 "pnfasm.ypp"
                                                { 
						 fprintf(output, "135 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5580 "pnfasm.tab.cpp"
    break;

  case 238: /* instruction: IHEADDB TVOID NUMBER  */
#line 1758 "pnfasm.ypp"
                                        { fprintf(output, "136 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5586 "pnfasm.tab.cpp"
    break;

  case 239: /* instruction: ISHEADDB TVOID NUMBER  */
#line 1759 "pnfasm.ypp"
                                        { fprintf(output, "137 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5592 "pnfasm.tab.cpp"
    break;

  case 240: /* instruction: IEADDB TVOID NUMBER  */
#line 1760 "pnfasm.ypp"
                                        { fprintf(output, "138 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5598 "pnfasm.tab.cpp"
    break;

  case 241: /* instruction: IEXADDB TVOID NUMBER  */
#line 1761 "pnfasm.ypp"
                                        { fprintf(output, "139 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5604 "pnfasm.tab.cpp"
    break;

  case 242: /* instruction: IIADDB TVOID NUMBER  */
#line 1762 "pnfasm.ypp"
                                        { fprintf(output, "140 0 %s\n", yyvsp[0].getString().c_str()); }
#line 5610 "pnfasm.tab.cpp"
    break;

  case 243: /* instruction: IRDSTART2 TSTRING STRING  */
#line 1763 "pnfasm.ypp"
                                                { 
						 fprintf(output, "141 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5624 "pnfasm.tab.cpp"
    break;

  case 244: /* instruction: IRFROM2 TNUMBER NUMBER  */
#line 1772 "pnfasm.ypp"
                                                { fprintf(output, "142 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5630 "pnfasm.tab.cpp"
    break;

  case 245: /* instruction: IRTO2 TNUMBER NUMBER  */
#line 1773 "pnfasm.ypp"
                                                { fprintf(output, "143 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5636 "pnfasm.tab.cpp"
    break;

  case 246: /* instruction: IRDEND2 TVOID VOID  */
#line 1774 "pnfasm.ypp"
                                                { fprintf(output, "144 0 0\n"); }
#line 5642 "pnfasm.tab.cpp"
    break;

  case 247: /* instruction: IRSTART2 TSTRING STRING  */
#line 1775 "pnfasm.ypp"
                                                { 
						 fprintf(output, "145 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5656 "pnfasm.tab.cpp"
    break;

  case 248: /* instruction: IRANGE2 TSTRING STRING  */
#line 1784 "pnfasm.ypp"
                                                { 
						 fprintf(output, "146 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5670 "pnfasm.tab.cpp"
    break;

  case 249: /* instruction: IRPREP2 TSTRING STRING  */
#line 1793 "pnfasm.ypp"
                                                { 
						 fprintf(output, "147 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5684 "pnfasm.tab.cpp"
    break;

  case 250: /* instruction: IRLOAD2 TNUMBER NUMBER  */
#line 1802 "pnfasm.ypp"
                                                { fprintf(output, "148 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5690 "pnfasm.tab.cpp"
    break;

  case 251: /* instruction: IESTART TSTRING STRING  */
#line 1803 "pnfasm.ypp"
                                                { 
						 fprintf(output, "149 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5704 "pnfasm.tab.cpp"
    break;

  case 252: /* instruction: IENAME TSTRING STRING  */
#line 1812 "pnfasm.ypp"
                                        { 
						 fprintf(output, "150 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5718 "pnfasm.tab.cpp"
    break;

  case 253: /* instruction: IEEND TVOID VOID  */
#line 1821 "pnfasm.ypp"
                                                { fprintf(output, "151 0 0\n"); }
#line 5724 "pnfasm.tab.cpp"
    break;

  case 254: /* instruction: IENUMS TSTRING STRING  */
#line 1822 "pnfasm.ypp"
                                                { 
						 fprintf(output, "152 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5738 "pnfasm.tab.cpp"
    break;

  case 255: /* instruction: IENUM TSTRING STRING  */
#line 1831 "pnfasm.ypp"
                                                { 
						 fprintf(output, "153 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5752 "pnfasm.tab.cpp"
    break;

  case 256: /* instruction: ISENUM TSTRING STRING  */
#line 1840 "pnfasm.ypp"
                                                { 
						 fprintf(output, "154 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5766 "pnfasm.tab.cpp"
    break;

  case 257: /* instruction: IEPREP TSTRING STRING  */
#line 1849 "pnfasm.ypp"
                                                { 
						 fprintf(output, "155 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5780 "pnfasm.tab.cpp"
    break;

  case 258: /* instruction: ILOADE TVOID VOID  */
#line 1858 "pnfasm.ypp"
                                                { fprintf(output, "156 0 0\n"); }
#line 5786 "pnfasm.tab.cpp"
    break;

  case 259: /* instruction: ISTOREE TVOID VOID  */
#line 1859 "pnfasm.ypp"
                                                { fprintf(output, "157 0 0\n"); }
#line 5792 "pnfasm.tab.cpp"
    break;

  case 260: /* instruction: IASTART TSTRING STRING  */
#line 1860 "pnfasm.ypp"
                                                { 
						 fprintf(output, "158 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5806 "pnfasm.tab.cpp"
    break;

  case 261: /* instruction: IAEND TNUMBER NUMBER  */
#line 1869 "pnfasm.ypp"
                                                { fprintf(output, "159 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5812 "pnfasm.tab.cpp"
    break;

  case 262: /* instruction: IAPREP TSTRING STRING  */
#line 1870 "pnfasm.ypp"
                                        { 
						 fprintf(output, "160 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 5826 "pnfasm.tab.cpp"
    break;

  case 263: /* instruction: IAIPREP TNUMBER NUMBER  */
#line 1879 "pnfasm.ypp"
                                                { fprintf(output, "161 2 %s\n", yyvsp[0].getString().c_str()); }
#line 5832 "pnfasm.tab.cpp"
    break;

  case 264: /* instruction: IAIPREP TVOID VOID  */
#line 1880 "pnfasm.ypp"
                                                { fprintf(output, "161 0 0\n"); }
#line 5838 "pnfasm.tab.cpp"
    break;

  case 265: /* instruction: ILOADIA TVOID VOID  */
#line 1881 "pnfasm.ypp"
                                                { fprintf(output, "162 0 0\n"); }
#line 5844 "pnfasm.tab.cpp"
    break;

  case 266: /* instruction: ISTOREIA TVOID VOID  */
#line 1882 "pnfasm.ypp"
                                                { fprintf(output, "163 0 0\n"); }
#line 5850 "pnfasm.tab.cpp"
    break;

  case 267: /* instruction: ISTOREIA TBOOLEAN VOID  */
#line 1883 "pnfasm.ypp"
                                                { fprintf(output, "163 1 0\n"); }
#line 5856 "pnfasm.tab.cpp"
    break;

  case 268: /* instruction: ISTOREIA TNUMBER VOID  */
#line 1884 "pnfasm.ypp"
                                                { fprintf(output, "163 2 0\n"); }
#line 5862 "pnfasm.tab.cpp"
    break;

  case 269: /* instruction: ISTOREIA TCHARACTER VOID  */
#line 1885 "pnfasm.ypp"
                                                { fprintf(output, "163 3 0\n"); }
#line 5868 "pnfasm.tab.cpp"
    break;

  case 270: /* instruction: ISTOREIA TSTRING VOID  */
#line 1886 "pnfasm.ypp"
                                                { fprintf(output, "163 4 0\n"); }
#line 5874 "pnfasm.tab.cpp"
    break;

  case 271: /* instruction: IALENGTH TVOID VOID  */
#line 1887 "pnfasm.ypp"
                                                { fprintf(output, "164 0 0\n"); }
#line 5880 "pnfasm.tab.cpp"
    break;

  case 272: /* instruction: IAPRINT TVOID VOID  */
#line 1888 "pnfasm.ypp"
                                                { fprintf(output, "165 0 0\n"); }
#line 5886 "pnfasm.tab.cpp"
    break;

  case 273: /* instruction: IDUP TVOID VOID  */
#line 1889 "pnfasm.ypp"
                                                { fprintf(output, "166 0 0\n"); }
#line 5892 "pnfasm.tab.cpp"
    break;

  case 274: /* instruction: ICDUP TVOID VOID  */
#line 1890 "pnfasm.ypp"
                                                { fprintf(output, "167 0 0\n"); }
#line 5898 "pnfasm.tab.cpp"
    break;

  case 275: /* instruction: IIF TVOID VOID  */
#line 1891 "pnfasm.ypp"
                                                { fprintf(output, "168 0 0\n"); }
#line 5904 "pnfasm.tab.cpp"
    break;

  case 276: /* instruction: IENDIF TVOID VOID  */
#line 1892 "pnfasm.ypp"
                                                { fprintf(output, "169 0 0\n"); }
#line 5910 "pnfasm.tab.cpp"
    break;

  case 277: /* instruction: IIFELSE TVOID VOID  */
#line 1893 "pnfasm.ypp"
                                                { fprintf(output, "170 0 0\n"); }
#line 5916 "pnfasm.tab.cpp"
    break;

  case 278: /* instruction: IENDIFELSE TVOID VOID  */
#line 1894 "pnfasm.ypp"
                                                { fprintf(output, "171 0 0\n"); }
#line 5922 "pnfasm.tab.cpp"
    break;

  case 279: /* instruction: IEIF TVOID VOID  */
#line 1895 "pnfasm.ypp"
                                                { fprintf(output, "172 0 0\n"); }
#line 5928 "pnfasm.tab.cpp"
    break;

  case 280: /* instruction: IIFBEGIN TVOID VOID  */
#line 1896 "pnfasm.ypp"
                                                { fprintf(output, "173 0 0\n"); }
#line 5934 "pnfasm.tab.cpp"
    break;

  case 281: /* instruction: IIFEND TVOID VOID  */
#line 1897 "pnfasm.ypp"
                                                { fprintf(output, "174 0 0\n"); }
#line 5940 "pnfasm.tab.cpp"
    break;

  case 282: /* instruction: ISWITCH2 TVOID VOID  */
#line 1898 "pnfasm.ypp"
                                                { fprintf(output, "175 0 0\n");	}
#line 5946 "pnfasm.tab.cpp"
    break;

  case 283: /* instruction: ISWBEGIN TVOID VOID  */
#line 1899 "pnfasm.ypp"
                                                { fprintf(output, "176 0 0\n");	}
#line 5952 "pnfasm.tab.cpp"
    break;

  case 284: /* instruction: ISWEND TVOID VOID  */
#line 1900 "pnfasm.ypp"
                                                { fprintf(output, "177 0 0\n");	}
#line 5958 "pnfasm.tab.cpp"
    break;

  case 285: /* instruction: ISWCASE TVOID VOID  */
#line 1901 "pnfasm.ypp"
                                                { fprintf(output, "178 0 0\n"); }
#line 5964 "pnfasm.tab.cpp"
    break;

  case 286: /* instruction: ISWCASE TBOOLEAN BOOLEAN  */
#line 1902 "pnfasm.ypp"
                                                { fprintf(output, "178 1 %s\n", yyvsp[0].getString().c_str());	}
#line 5970 "pnfasm.tab.cpp"
    break;

  case 287: /* instruction: ISWCASE TNUMBER NUMBER  */
#line 1903 "pnfasm.ypp"
                                                { fprintf(output, "178 2 %s\n", yyvsp[0].getString().c_str());	}
#line 5976 "pnfasm.tab.cpp"
    break;

  case 288: /* instruction: ISWCASE TCHARACTER CHARACTER  */
#line 1904 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "178 3 %i\n", ch);
						}
#line 5986 "pnfasm.tab.cpp"
    break;

  case 289: /* instruction: ISWCASE TSTRING STRING  */
#line 1909 "pnfasm.ypp"
                                                { 
						 fprintf(output, "178 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6000 "pnfasm.tab.cpp"
    break;

  case 290: /* instruction: ISWCBEGIN TVOID VOID  */
#line 1918 "pnfasm.ypp"
                                                { fprintf(output, "179 0 0\n");	}
#line 6006 "pnfasm.tab.cpp"
    break;

  case 291: /* instruction: ISWCEND TVOID VOID  */
#line 1919 "pnfasm.ypp"
                                                { fprintf(output, "180 0 0\n");	}
#line 6012 "pnfasm.tab.cpp"
    break;

  case 292: /* instruction: ISWDEFAULT TVOID VOID  */
#line 1920 "pnfasm.ypp"
                                                { fprintf(output, "181 0 0\n");	}
#line 6018 "pnfasm.tab.cpp"
    break;

  case 293: /* instruction: ISWBREAK TVOID VOID  */
#line 1921 "pnfasm.ypp"
                                                { fprintf(output, "182 0 0\n");	}
#line 6024 "pnfasm.tab.cpp"
    break;

  case 294: /* instruction: ILOADSP TNUMBER NUMBER  */
#line 1922 "pnfasm.ypp"
                                                { fprintf(output, "183 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6030 "pnfasm.tab.cpp"
    break;

  case 295: /* instruction: ISTORESP TNUMBER NUMBER  */
#line 1923 "pnfasm.ypp"
                                                { fprintf(output, "184 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6036 "pnfasm.tab.cpp"
    break;

  case 296: /* instruction: ILOADSTACK TVOID VOID  */
#line 1924 "pnfasm.ypp"
                                                { fprintf(output, "185 0 0\n"); }
#line 6042 "pnfasm.tab.cpp"
    break;

  case 297: /* instruction: ISTORESTACK TVOID VOID  */
#line 1925 "pnfasm.ypp"
                                                { fprintf(output, "186 0 0\n"); }
#line 6048 "pnfasm.tab.cpp"
    break;

  case 298: /* instruction: IATOSP TVOID VOID  */
#line 1926 "pnfasm.ypp"
                                                { fprintf(output, "187 0 0\n"); }
#line 6054 "pnfasm.tab.cpp"
    break;

  case 299: /* instruction: ISPTOA TVOID VOID  */
#line 1927 "pnfasm.ypp"
                                                { fprintf(output, "188 0 0\n"); }
#line 6060 "pnfasm.tab.cpp"
    break;

  case 300: /* instruction: IPATCH TVOID VOID  */
#line 1928 "pnfasm.ypp"
                                                { fprintf(output, "189 0 0\n"); }
#line 6066 "pnfasm.tab.cpp"
    break;

  case 301: /* instruction: INATIVE TSTRING STRING  */
#line 1929 "pnfasm.ypp"
                                                { 
						 fprintf(output, "190 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6080 "pnfasm.tab.cpp"
    break;

  case 302: /* instruction: IFRET TVOID VOID  */
#line 1938 "pnfasm.ypp"
                                                { fprintf(output, "191 0 0\n"); }
#line 6086 "pnfasm.tab.cpp"
    break;

  case 303: /* instruction: IFCALL TSTRING STRING  */
#line 1939 "pnfasm.ypp"
                                                { 
						 fprintf(output, "192 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6100 "pnfasm.tab.cpp"
    break;

  case 304: /* instruction: IFCPARAMS TVOID VOID  */
#line 1948 "pnfasm.ypp"
                                                { fprintf(output, "193 0 0\n"); }
#line 6106 "pnfasm.tab.cpp"
    break;

  case 305: /* instruction: IFECPARAMS TVOID VOID  */
#line 1949 "pnfasm.ypp"
                                                { fprintf(output, "194 0 0\n"); }
#line 6112 "pnfasm.tab.cpp"
    break;

  case 306: /* instruction: IFECALL TVOID VOID  */
#line 1950 "pnfasm.ypp"
                                                { fprintf(output, "195 0 0\n"); }
#line 6118 "pnfasm.tab.cpp"
    break;

  case 307: /* instruction: IPNUM TNUMBER NUMBER  */
#line 1951 "pnfasm.ypp"
                                                { fprintf(output, "196 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6124 "pnfasm.tab.cpp"
    break;

  case 308: /* instruction: IPARAMF TVOID VOID  */
#line 1952 "pnfasm.ypp"
                                                { fprintf(output, "197 0 0\n"); }
#line 6130 "pnfasm.tab.cpp"
    break;

  case 309: /* instruction: IPARAMF TBOOLEAN BOOLEAN  */
#line 1954 "pnfasm.ypp"
                                                {
			 			 if (yyvsp[0] == "true")
		 	  			  fprintf(output, "197 1 1\n");
			 			 else
			  			  fprintf(output, "197 1 0\n");
						}
#line 6141 "pnfasm.tab.cpp"
    break;

  case 310: /* instruction: IPARAMF TNUMBER NUMBER  */
#line 1960 "pnfasm.ypp"
                                                { fprintf(output, "197 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6147 "pnfasm.tab.cpp"
    break;

  case 311: /* instruction: IPARAMF TCHARACTER CHARACTER  */
#line 1962 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "197 3 %i\n", ch);
						}
#line 6157 "pnfasm.tab.cpp"
    break;

  case 312: /* instruction: IPARAMF TSTRING STRING  */
#line 1968 "pnfasm.ypp"
                                                {		
						 fprintf(output, "197 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6168 "pnfasm.tab.cpp"
    break;

  case 313: /* instruction: IPARAMF2 TVOID VOID  */
#line 1974 "pnfasm.ypp"
                                                { fprintf(output, "198 0 0\n"); }
#line 6174 "pnfasm.tab.cpp"
    break;

  case 314: /* instruction: IPARAMF2 TBOOLEAN VOID  */
#line 1975 "pnfasm.ypp"
                                                { fprintf(output, "198 1 0\n"); }
#line 6180 "pnfasm.tab.cpp"
    break;

  case 315: /* instruction: IPARAMF2 TNUMBER VOID  */
#line 1976 "pnfasm.ypp"
                                                { fprintf(output, "198 2 0\n"); }
#line 6186 "pnfasm.tab.cpp"
    break;

  case 316: /* instruction: IPARAMF2 TCHARACTER VOID  */
#line 1977 "pnfasm.ypp"
                                                { fprintf(output, "198 3 0\n"); }
#line 6192 "pnfasm.tab.cpp"
    break;

  case 317: /* instruction: IPARAMF2 TSTRING VOID  */
#line 1978 "pnfasm.ypp"
                                                { fprintf(output, "198 4 0\n"); }
#line 6198 "pnfasm.tab.cpp"
    break;

  case 318: /* instruction: IPARAMF3 TVOID VOID  */
#line 1979 "pnfasm.ypp"
                                                { fprintf(output, "199 0 0\n"); }
#line 6204 "pnfasm.tab.cpp"
    break;

  case 319: /* instruction: IPARAMF3 TBOOLEAN VOID  */
#line 1980 "pnfasm.ypp"
                                                { fprintf(output, "199 1 0\n"); }
#line 6210 "pnfasm.tab.cpp"
    break;

  case 320: /* instruction: IPARAMF3 TNUMBER VOID  */
#line 1981 "pnfasm.ypp"
                                                { fprintf(output, "199 2 0\n"); }
#line 6216 "pnfasm.tab.cpp"
    break;

  case 321: /* instruction: IPARAMF3 TCHARACTER VOID  */
#line 1982 "pnfasm.ypp"
                                                { fprintf(output, "199 3 0\n"); }
#line 6222 "pnfasm.tab.cpp"
    break;

  case 322: /* instruction: IPARAMF3 TSTRING VOID  */
#line 1983 "pnfasm.ypp"
                                                { fprintf(output, "199 4 0\n"); }
#line 6228 "pnfasm.tab.cpp"
    break;

  case 323: /* instruction: IRNUM TNUMBER NUMBER  */
#line 1984 "pnfasm.ypp"
                                                { fprintf(output, "200 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6234 "pnfasm.tab.cpp"
    break;

  case 324: /* instruction: IRETURNF TVOID VOID  */
#line 1985 "pnfasm.ypp"
                                                { fprintf(output, "201 0 0\n"); }
#line 6240 "pnfasm.tab.cpp"
    break;

  case 325: /* instruction: IRETURNF TBOOLEAN VOID  */
#line 1986 "pnfasm.ypp"
                                                { fprintf(output, "201 1 0\n"); }
#line 6246 "pnfasm.tab.cpp"
    break;

  case 326: /* instruction: IRETURNF TNUMBER VOID  */
#line 1987 "pnfasm.ypp"
                                                { fprintf(output, "201 2 0\n"); }
#line 6252 "pnfasm.tab.cpp"
    break;

  case 327: /* instruction: IRETURNF TCHARACTER VOID  */
#line 1988 "pnfasm.ypp"
                                                { fprintf(output, "201 3 0\n"); }
#line 6258 "pnfasm.tab.cpp"
    break;

  case 328: /* instruction: IRETURNF TSTRING VOID  */
#line 1989 "pnfasm.ypp"
                                                { fprintf(output, "201 4 0\n"); }
#line 6264 "pnfasm.tab.cpp"
    break;

  case 329: /* instruction: IRETURNF2 TVOID VOID  */
#line 1990 "pnfasm.ypp"
                                                { fprintf(output, "202 0 0\n"); }
#line 6270 "pnfasm.tab.cpp"
    break;

  case 330: /* instruction: IRETURNF2 TBOOLEAN VOID  */
#line 1991 "pnfasm.ypp"
                                                { fprintf(output, "202 1 0\n"); }
#line 6276 "pnfasm.tab.cpp"
    break;

  case 331: /* instruction: IRETURNF2 TNUMBER VOID  */
#line 1992 "pnfasm.ypp"
                                                { fprintf(output, "202 2 0\n"); }
#line 6282 "pnfasm.tab.cpp"
    break;

  case 332: /* instruction: IRETURNF2 TCHARACTER VOID  */
#line 1993 "pnfasm.ypp"
                                                { fprintf(output, "202 3 0\n"); }
#line 6288 "pnfasm.tab.cpp"
    break;

  case 333: /* instruction: IRETURNF2 TSTRING VOID  */
#line 1994 "pnfasm.ypp"
                                                { fprintf(output, "202 4 0\n"); }
#line 6294 "pnfasm.tab.cpp"
    break;

  case 334: /* instruction: IRETURNF3 TVOID VOID  */
#line 1995 "pnfasm.ypp"
                                                { fprintf(output, "203 0 0\n"); }
#line 6300 "pnfasm.tab.cpp"
    break;

  case 335: /* instruction: IRETURNF3 TBOOLEAN VOID  */
#line 1996 "pnfasm.ypp"
                                                { fprintf(output, "203 1 0\n"); }
#line 6306 "pnfasm.tab.cpp"
    break;

  case 336: /* instruction: IRETURNF3 TNUMBER VOID  */
#line 1997 "pnfasm.ypp"
                                                { fprintf(output, "203 2 0\n"); }
#line 6312 "pnfasm.tab.cpp"
    break;

  case 337: /* instruction: IRETURNF3 TCHARACTER VOID  */
#line 1998 "pnfasm.ypp"
                                                { fprintf(output, "203 3 0\n"); }
#line 6318 "pnfasm.tab.cpp"
    break;

  case 338: /* instruction: IRETURNF3 TSTRING VOID  */
#line 1999 "pnfasm.ypp"
                                                { fprintf(output, "203 4 0\n"); }
#line 6324 "pnfasm.tab.cpp"
    break;

  case 339: /* instruction: IFNAME TSTRING STRING  */
#line 2002 "pnfasm.ypp"
                                                {		
						 fprintf(output, "204 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6335 "pnfasm.tab.cpp"
    break;

  case 340: /* instruction: IRETURNV TVOID VOID  */
#line 2008 "pnfasm.ypp"
                                                { fprintf(output, "205 0 0\n"); }
#line 6341 "pnfasm.tab.cpp"
    break;

  case 341: /* instruction: IFNCLOAD TNUMBER NUMBER  */
#line 2009 "pnfasm.ypp"
                                                { fprintf(output, "206 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6347 "pnfasm.tab.cpp"
    break;

  case 342: /* instruction: IFNCSTORE TVOID VOID  */
#line 2010 "pnfasm.ypp"
                                                { fprintf(output, "207 0 0\n"); }
#line 6353 "pnfasm.tab.cpp"
    break;

  case 343: /* instruction: IFNCSTORE TNUMBER NUMBER  */
#line 2011 "pnfasm.ypp"
                                                { fprintf(output, "207 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6359 "pnfasm.tab.cpp"
    break;

  case 344: /* instruction: IFNCNEW TVOID VOID  */
#line 2012 "pnfasm.ypp"
                                                { fprintf(output, "208 0 0\n"); }
#line 6365 "pnfasm.tab.cpp"
    break;

  case 345: /* instruction: IFNCDELETE TVOID VOID  */
#line 2013 "pnfasm.ypp"
                                                { fprintf(output, "209 0 0\n"); }
#line 6371 "pnfasm.tab.cpp"
    break;

  case 346: /* instruction: IFNCSNAME TVOID VOID  */
#line 2014 "pnfasm.ypp"
                                                { fprintf(output, "210 0 0\n"); }
#line 6377 "pnfasm.tab.cpp"
    break;

  case 347: /* instruction: IFNCSRET TVOID VOID  */
#line 2015 "pnfasm.ypp"
                                                { fprintf(output, "211 0 0\n"); }
#line 6383 "pnfasm.tab.cpp"
    break;

  case 348: /* instruction: IFNCSRET TBOOLEAN VOID  */
#line 2016 "pnfasm.ypp"
                                                { fprintf(output, "211 1 0\n"); }
#line 6389 "pnfasm.tab.cpp"
    break;

  case 349: /* instruction: IFNCSRET TNUMBER VOID  */
#line 2017 "pnfasm.ypp"
                                                { fprintf(output, "211 2 0\n"); }
#line 6395 "pnfasm.tab.cpp"
    break;

  case 350: /* instruction: IFNCSRET TCHARACTER VOID  */
#line 2018 "pnfasm.ypp"
                                                { fprintf(output, "211 3 0\n"); }
#line 6401 "pnfasm.tab.cpp"
    break;

  case 351: /* instruction: IFNCSRET TSTRING VOID  */
#line 2019 "pnfasm.ypp"
                                                { fprintf(output, "211 4 0\n"); }
#line 6407 "pnfasm.tab.cpp"
    break;

  case 352: /* instruction: IFNCSPARAM TVOID VOID  */
#line 2020 "pnfasm.ypp"
                                                { fprintf(output, "212 0 0\n"); }
#line 6413 "pnfasm.tab.cpp"
    break;

  case 353: /* instruction: IFNCSPARAM TBOOLEAN VOID  */
#line 2021 "pnfasm.ypp"
                                                { fprintf(output, "212 1 0\n"); }
#line 6419 "pnfasm.tab.cpp"
    break;

  case 354: /* instruction: IFNCSPARAM TNUMBER VOID  */
#line 2022 "pnfasm.ypp"
                                                { fprintf(output, "212 2 0\n"); }
#line 6425 "pnfasm.tab.cpp"
    break;

  case 355: /* instruction: IFNCSPARAM TCHARACTER VOID  */
#line 2023 "pnfasm.ypp"
                                                { fprintf(output, "212 3 0\n"); }
#line 6431 "pnfasm.tab.cpp"
    break;

  case 356: /* instruction: IFNCSPARAM TSTRING VOID  */
#line 2024 "pnfasm.ypp"
                                                { fprintf(output, "212 4 0\n"); }
#line 6437 "pnfasm.tab.cpp"
    break;

  case 357: /* instruction: IFNCSDEF TNUMBER NUMBER  */
#line 2025 "pnfasm.ypp"
                                                { fprintf(output, "213 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6443 "pnfasm.tab.cpp"
    break;

  case 358: /* instruction: IFNCSDEF TSTRING STRING  */
#line 2026 "pnfasm.ypp"
                                                {		
						 fprintf(output, "213 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 6454 "pnfasm.tab.cpp"
    break;

  case 359: /* instruction: IFNCGNAME TVOID VOID  */
#line 2032 "pnfasm.ypp"
                                                { fprintf(output, "214 0 0\n"); }
#line 6460 "pnfasm.tab.cpp"
    break;

  case 360: /* instruction: IFNCGRET TNUMBER NUMBER  */
#line 2033 "pnfasm.ypp"
                                                { fprintf(output, "215 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6466 "pnfasm.tab.cpp"
    break;

  case 361: /* instruction: IFNCGPARAM TNUMBER NUMBER  */
#line 2034 "pnfasm.ypp"
                                                { fprintf(output, "216 2 %s\n", yyvsp[0].getString().c_str()); }
#line 6472 "pnfasm.tab.cpp"
    break;

  case 362: /* instruction: IFNCGDEF TVOID VOID  */
#line 2035 "pnfasm.ypp"
                                                { fprintf(output, "217 0 0\n"); }
#line 6478 "pnfasm.tab.cpp"
    break;

  case 363: /* instruction: IFNCPOINT TVOID VOID  */
#line 2036 "pnfasm.ypp"
                                                { fprintf(output, "218 0 0\n"); }
#line 6484 "pnfasm.tab.cpp"
    break;

  case 364: /* instruction: IFNCLENGTH TVOID VOID  */
#line 2037 "pnfasm.ypp"
                                                { fprintf(output, "219 0 0\n"); }
#line 6490 "pnfasm.tab.cpp"
    break;

  case 365: /* instruction: IFNCSYNCR TVOID VOID  */
#line 2038 "pnfasm.ypp"
                                                { fprintf(output, "220 0 0\n"); }
#line 6496 "pnfasm.tab.cpp"
    break;

  case 366: /* instruction: IFNCFIND TVOID VOID  */
#line 2039 "pnfasm.ypp"
                                                { fprintf(output, "221 0 0\n"); }
#line 6502 "pnfasm.tab.cpp"
    break;

  case 367: /* instruction: IFNCFRET TVOID VOID  */
#line 2040 "pnfasm.ypp"
                                                { fprintf(output, "222 0 0\n"); }
#line 6508 "pnfasm.tab.cpp"
    break;

  case 368: /* instruction: IFNCFRET TBOOLEAN VOID  */
#line 2041 "pnfasm.ypp"
                                                { fprintf(output, "222 1 0\n"); }
#line 6514 "pnfasm.tab.cpp"
    break;

  case 369: /* instruction: IFNCFRET TNUMBER VOID  */
#line 2042 "pnfasm.ypp"
                                                { fprintf(output, "222 2 0\n"); }
#line 6520 "pnfasm.tab.cpp"
    break;

  case 370: /* instruction: IFNCFRET TCHARACTER VOID  */
#line 2043 "pnfasm.ypp"
                                                { fprintf(output, "222 3 0\n"); }
#line 6526 "pnfasm.tab.cpp"
    break;

  case 371: /* instruction: IFNCFRET TSTRING VOID  */
#line 2044 "pnfasm.ypp"
                                                { fprintf(output, "222 4 0\n"); }
#line 6532 "pnfasm.tab.cpp"
    break;

  case 372: /* instruction: IFNCFPARAM TVOID VOID  */
#line 2045 "pnfasm.ypp"
                                                { fprintf(output, "223 0 0\n"); }
#line 6538 "pnfasm.tab.cpp"
    break;

  case 373: /* instruction: IFNCFPARAM TBOOLEAN VOID  */
#line 2046 "pnfasm.ypp"
                                                { fprintf(output, "223 1 0\n"); }
#line 6544 "pnfasm.tab.cpp"
    break;

  case 374: /* instruction: IFNCFPARAM TNUMBER VOID  */
#line 2047 "pnfasm.ypp"
                                                { fprintf(output, "223 2 0\n"); }
#line 6550 "pnfasm.tab.cpp"
    break;

  case 375: /* instruction: IFNCFPARAM TCHARACTER VOID  */
#line 2048 "pnfasm.ypp"
                                                { fprintf(output, "223 3 0\n"); }
#line 6556 "pnfasm.tab.cpp"
    break;

  case 376: /* instruction: IFNCFPARAM TSTRING VOID  */
#line 2049 "pnfasm.ypp"
                                                { fprintf(output, "223 4 0\n"); }
#line 6562 "pnfasm.tab.cpp"
    break;

  case 377: /* instruction: IFNCFBRET TVOID VOID  */
#line 2050 "pnfasm.ypp"
                                                { fprintf(output, "224 0 0\n"); }
#line 6568 "pnfasm.tab.cpp"
    break;

  case 378: /* instruction: IFNCFBPARAM TVOID VOID  */
#line 2051 "pnfasm.ypp"
                                                { fprintf(output, "225 0 0\n"); }
#line 6574 "pnfasm.tab.cpp"
    break;

  case 379: /* instruction: IFNCDEFAULT TVOID VOID  */
#line 2052 "pnfasm.ypp"
                                                { fprintf(output, "226 0 0\n"); }
#line 6580 "pnfasm.tab.cpp"
    break;

  case 380: /* instruction: IFNCDEFAULT2 TVOID VOID  */
#line 2053 "pnfasm.ypp"
                                                { fprintf(output, "227 0 0\n"); }
#line 6586 "pnfasm.tab.cpp"
    break;

  case 381: /* instruction: IFNCSDEFAULTV TVOID VOID  */
#line 2054 "pnfasm.ypp"
                                                { fprintf(output, "228 0 0\n"); }
#line 6592 "pnfasm.tab.cpp"
    break;

  case 382: /* instruction: IFNCSDEFAULTV TBOOLEAN VOID  */
#line 2055 "pnfasm.ypp"
                                                { fprintf(output, "228 1 0\n"); }
#line 6598 "pnfasm.tab.cpp"
    break;

  case 383: /* instruction: IFNCSDEFAULTV TNUMBER VOID  */
#line 2056 "pnfasm.ypp"
                                                { fprintf(output, "228 2 0\n"); }
#line 6604 "pnfasm.tab.cpp"
    break;

  case 384: /* instruction: IFNCSDEFAULTV TCHARACTER VOID  */
#line 2057 "pnfasm.ypp"
                                                { fprintf(output, "228 3 0\n"); }
#line 6610 "pnfasm.tab.cpp"
    break;

  case 385: /* instruction: IFNCSDEFAULTV TSTRING VOID  */
#line 2058 "pnfasm.ypp"
                                                { fprintf(output, "228 4 0\n"); }
#line 6616 "pnfasm.tab.cpp"
    break;

  case 386: /* instruction: IFNCSDEFAULTV2 TVOID VOID  */
#line 2059 "pnfasm.ypp"
                                                { fprintf(output, "229 0 0\n"); }
#line 6622 "pnfasm.tab.cpp"
    break;

  case 387: /* instruction: IFNCGDEFAULTV2 TVOID VOID  */
#line 2060 "pnfasm.ypp"
                                                { fprintf(output, "230 0 0\n"); }
#line 6628 "pnfasm.tab.cpp"
    break;

  case 388: /* instruction: IFNCDEFAULTSYNC TVOID VOID  */
#line 2061 "pnfasm.ypp"
                                                { fprintf(output, "231 0 0\n"); }
#line 6634 "pnfasm.tab.cpp"
    break;

  case 389: /* instruction: INTIMES TVOID VOID  */
#line 2062 "pnfasm.ypp"
                                                { fprintf(output, "232 0 0\n"); }
#line 6640 "pnfasm.tab.cpp"
    break;

  case 390: /* instruction: ICMP TVOID VOID  */
#line 2063 "pnfasm.ypp"
                                                { fprintf(output, "233 0 0\n"); }
#line 6646 "pnfasm.tab.cpp"
    break;

  case 391: /* instruction: IRUN TSTRING STRING  */
#line 2064 "pnfasm.ypp"
                                                { 
						 fprintf(output, "234 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6660 "pnfasm.tab.cpp"
    break;

  case 392: /* instruction: IJRUN TSTRING STRING  */
#line 2073 "pnfasm.ypp"
                                                { 
						 fprintf(output, "235 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6674 "pnfasm.tab.cpp"
    break;

  case 393: /* instruction: IPNFRUN TSTRING STRING  */
#line 2082 "pnfasm.ypp"
                                                { 
						 fprintf(output, "236 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6688 "pnfasm.tab.cpp"
    break;

  case 394: /* instruction: ISTRUCT TSTRING STRING  */
#line 2091 "pnfasm.ypp"
                                                { 
						 fprintf(output, "237 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6702 "pnfasm.tab.cpp"
    break;

  case 395: /* instruction: ISTRUCTVAR TSTRING STRING  */
#line 2100 "pnfasm.ypp"
                                                { 
						 fprintf(output, "238 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6716 "pnfasm.tab.cpp"
    break;

  case 396: /* instruction: IENDSTRUCT TVOID VOID  */
#line 2109 "pnfasm.ypp"
                                        { fprintf(output, "239 0 0\n"); }
#line 6722 "pnfasm.tab.cpp"
    break;

  case 397: /* instruction: ISTRUCTNAME TSTRING STRING  */
#line 2110 "pnfasm.ypp"
                                                { 
						 fprintf(output, "240 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6736 "pnfasm.tab.cpp"
    break;

  case 398: /* instruction: ISTRUCTONAME TSTRING STRING  */
#line 2119 "pnfasm.ypp"
                                                { 
						 fprintf(output, "241 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6750 "pnfasm.tab.cpp"
    break;

  case 399: /* instruction: ISTRUCTD TSTRING STRING  */
#line 2128 "pnfasm.ypp"
                                                { 
						 fprintf(output, "242 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6764 "pnfasm.tab.cpp"
    break;

  case 400: /* instruction: ISTRUCTUSE TVOID VOID  */
#line 2137 "pnfasm.ypp"
                                                { 
						 fprintf(output, "243 0 0\n");
						}
#line 6772 "pnfasm.tab.cpp"
    break;

  case 401: /* instruction: ISTRUCTUSE TNUMBER VOID  */
#line 2140 "pnfasm.ypp"
                                                {	
						fprintf(output, "243 2 0\n");
						}
#line 6780 "pnfasm.tab.cpp"
    break;

  case 402: /* instruction: ISTRUCTUSE TSTRING STRING  */
#line 2143 "pnfasm.ypp"
                                                { 
						 fprintf(output, "243 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6794 "pnfasm.tab.cpp"
    break;

  case 403: /* instruction: ISTRUCTUSING TVOID VOID  */
#line 2152 "pnfasm.ypp"
                                                { 
						 fprintf(output, "244 0 0\n");
						}
#line 6802 "pnfasm.tab.cpp"
    break;

  case 404: /* instruction: ISTRUCTUSINGNAME TVOID VOID  */
#line 2155 "pnfasm.ypp"
                                                { 
						 fprintf(output, "245 0 0\n");
						}
#line 6810 "pnfasm.tab.cpp"
    break;

  case 405: /* instruction: ISTRUCTGET TVOID VOID  */
#line 2158 "pnfasm.ypp"
                                                { 
						 fprintf(output, "246 0 0\n");
						}
#line 6818 "pnfasm.tab.cpp"
    break;

  case 406: /* instruction: ISTRUCTPUT TVOID VOID  */
#line 2161 "pnfasm.ypp"
                                                { 
						 fprintf(output, "247 0 0\n");
						}
#line 6826 "pnfasm.tab.cpp"
    break;

  case 407: /* instruction: ISTRUCTTYPE TVOID VOID  */
#line 2165 "pnfasm.ypp"
                                                { 
						 fprintf(output, "248 0 0\n");
						}
#line 6834 "pnfasm.tab.cpp"
    break;

  case 408: /* instruction: ISTRUCTTYPE2 TVOID VOID  */
#line 2168 "pnfasm.ypp"
                                                { 
						 fprintf(output, "249 0 0\n");
						}
#line 6842 "pnfasm.tab.cpp"
    break;

  case 409: /* instruction: ISTRUCTNAME2 TVOID VOID  */
#line 2171 "pnfasm.ypp"
                                                { 
						 fprintf(output, "250 0 0\n");
						}
#line 6850 "pnfasm.tab.cpp"
    break;

  case 410: /* instruction: ISTRUCTNAME3 TVOID VOID  */
#line 2174 "pnfasm.ypp"
                                                { 
						 fprintf(output, "251 0 0\n");
						}
#line 6858 "pnfasm.tab.cpp"
    break;

  case 411: /* instruction: IUNION TSTRING STRING  */
#line 2178 "pnfasm.ypp"
                                        { 
						 fprintf(output, "252 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6872 "pnfasm.tab.cpp"
    break;

  case 412: /* instruction: IUNIONVAR TSTRING STRING  */
#line 2187 "pnfasm.ypp"
                                                { 
						 fprintf(output, "253 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6886 "pnfasm.tab.cpp"
    break;

  case 413: /* instruction: IENDUNION TVOID VOID  */
#line 2196 "pnfasm.ypp"
                                        { fprintf(output, "254 0 0\n"); }
#line 6892 "pnfasm.tab.cpp"
    break;

  case 414: /* instruction: IUNIONNAME TSTRING STRING  */
#line 2197 "pnfasm.ypp"
                                                { 
						 fprintf(output, "255 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6906 "pnfasm.tab.cpp"
    break;

  case 415: /* instruction: IUNIONONAME TSTRING STRING  */
#line 2206 "pnfasm.ypp"
                                                { 
						 fprintf(output, "256 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6920 "pnfasm.tab.cpp"
    break;

  case 416: /* instruction: IUNIOND TSTRING STRING  */
#line 2215 "pnfasm.ypp"
                                                { 
						 fprintf(output, "257 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6934 "pnfasm.tab.cpp"
    break;

  case 417: /* instruction: IUNIONUSE TVOID VOID  */
#line 2224 "pnfasm.ypp"
                                                { 
						 fprintf(output, "258 0 0\n");
						}
#line 6942 "pnfasm.tab.cpp"
    break;

  case 418: /* instruction: IUNIONUSE TNUMBER VOID  */
#line 2227 "pnfasm.ypp"
                                                {	
						fprintf(output, "258 2 0\n");
						}
#line 6950 "pnfasm.tab.cpp"
    break;

  case 419: /* instruction: IUNIONUSE TSTRING STRING  */
#line 2230 "pnfasm.ypp"
                                                { 
						 fprintf(output, "258 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 6964 "pnfasm.tab.cpp"
    break;

  case 420: /* instruction: IUNIONUSING TVOID VOID  */
#line 2239 "pnfasm.ypp"
                                                { 
						 fprintf(output, "259 0 0\n");
						}
#line 6972 "pnfasm.tab.cpp"
    break;

  case 421: /* instruction: IUNIONUSINGNAME TVOID VOID  */
#line 2242 "pnfasm.ypp"
                                                { 
						 fprintf(output, "260 0 0\n");
						}
#line 6980 "pnfasm.tab.cpp"
    break;

  case 422: /* instruction: IUNIONGET TVOID VOID  */
#line 2245 "pnfasm.ypp"
                                                { 
						 fprintf(output, "261 0 0\n");
						}
#line 6988 "pnfasm.tab.cpp"
    break;

  case 423: /* instruction: IUNIONPUT TVOID VOID  */
#line 2248 "pnfasm.ypp"
                                                { 
						 fprintf(output, "262 0 0\n");
						}
#line 6996 "pnfasm.tab.cpp"
    break;

  case 424: /* instruction: IUNIONTYPE TVOID VOID  */
#line 2252 "pnfasm.ypp"
                                        { 
						 fprintf(output, "263 0 0\n");
						}
#line 7004 "pnfasm.tab.cpp"
    break;

  case 425: /* instruction: IUNIONTYPE2 TVOID VOID  */
#line 2255 "pnfasm.ypp"
                                                { 
						 fprintf(output, "264 0 0\n");
						}
#line 7012 "pnfasm.tab.cpp"
    break;

  case 426: /* instruction: IUNIONNAME2 TVOID VOID  */
#line 2258 "pnfasm.ypp"
                                                { 
						 fprintf(output, "265 0 0\n");
						}
#line 7020 "pnfasm.tab.cpp"
    break;

  case 427: /* instruction: IUNIONNAME3 TVOID VOID  */
#line 2261 "pnfasm.ypp"
                                                { 
						 fprintf(output, "266 0 0\n");
						}
#line 7028 "pnfasm.tab.cpp"
    break;

  case 428: /* instruction: IMODE TVOID NUMBER  */
#line 2265 "pnfasm.ypp"
                                                { 
						 fprintf(output, "267 0 0\n");
						}
#line 7036 "pnfasm.tab.cpp"
    break;

  case 429: /* instruction: IEXTMODE TVOID NUMBER  */
#line 2269 "pnfasm.ypp"
                                                { 
						 fprintf(output, "268 0 %s\n", yyvsp[0].getString().c_str());
						}
#line 7044 "pnfasm.tab.cpp"
    break;

  case 430: /* instruction: IMCHECK TVOID NUMBER  */
#line 2273 "pnfasm.ypp"
                                                { fprintf(output, "269 0 %s\n", yyvsp[0].getString().c_str()); }
#line 7050 "pnfasm.tab.cpp"
    break;

  case 431: /* instruction: IMCHECK TBOOLEAN BOOLEAN  */
#line 2275 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "269 1 1\n");
		 else
		  fprintf(output, "269 1 0\n");
		}
#line 7061 "pnfasm.tab.cpp"
    break;

  case 432: /* instruction: IMCHECK TNUMBER NUMBER  */
#line 2281 "pnfasm.ypp"
                                                { fprintf(output, "269 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7067 "pnfasm.tab.cpp"
    break;

  case 433: /* instruction: IMCHECK TCHARACTER CHARACTER  */
#line 2283 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "269 3 %i\n", ch);
		}
#line 7077 "pnfasm.tab.cpp"
    break;

  case 434: /* instruction: IMCHECK TSTRING STRING  */
#line 2289 "pnfasm.ypp"
                {
		 fprintf(output, "269 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 7091 "pnfasm.tab.cpp"
    break;

  case 435: /* instruction: IMSUPP TVOID NUMBER  */
#line 2298 "pnfasm.ypp"
                                                { fprintf(output, "270 0 %s\n", yyvsp[0].getString().c_str()); }
#line 7097 "pnfasm.tab.cpp"
    break;

  case 436: /* instruction: IMSUPP TBOOLEAN BOOLEAN  */
#line 2300 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "270 1 1\n");
		 else
		  fprintf(output, "270 1 0\n");
		}
#line 7108 "pnfasm.tab.cpp"
    break;

  case 437: /* instruction: IMSUPP TNUMBER NUMBER  */
#line 2306 "pnfasm.ypp"
                                        { fprintf(output, "270 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7114 "pnfasm.tab.cpp"
    break;

  case 438: /* instruction: IMSUPP TCHARACTER CHARACTER  */
#line 2308 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "270 3 %i\n", ch);
		}
#line 7124 "pnfasm.tab.cpp"
    break;

  case 439: /* instruction: IMSUPP TSTRING STRING  */
#line 2314 "pnfasm.ypp"
                {
		 fprintf(output, "270 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 7138 "pnfasm.tab.cpp"
    break;

  case 440: /* instruction: IMEXTCHECK TVOID NUMBER  */
#line 2323 "pnfasm.ypp"
                                                        { fprintf(output, "271 0 %s\n", yyvsp[0].getString().c_str()); }
#line 7144 "pnfasm.tab.cpp"
    break;

  case 441: /* instruction: IMEXTCHECK TBOOLEAN BOOLEAN  */
#line 2325 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "271 1 1\n");
		 else
		  fprintf(output, "271 1 0\n");
		}
#line 7155 "pnfasm.tab.cpp"
    break;

  case 442: /* instruction: IMEXTCHECK TNUMBER NUMBER  */
#line 2331 "pnfasm.ypp"
                                                { fprintf(output, "271 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7161 "pnfasm.tab.cpp"
    break;

  case 443: /* instruction: IMEXTCHECK TCHARACTER CHARACTER  */
#line 2333 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "271 3 %i\n", ch);
		}
#line 7171 "pnfasm.tab.cpp"
    break;

  case 444: /* instruction: IMEXTCHECK TSTRING STRING  */
#line 2339 "pnfasm.ypp"
                {
		 fprintf(output, "271 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 7185 "pnfasm.tab.cpp"
    break;

  case 445: /* instruction: IMEXTSUPP TVOID NUMBER  */
#line 2348 "pnfasm.ypp"
                                                        { fprintf(output, "272 0 %s\n", yyvsp[0].getString().c_str()); }
#line 7191 "pnfasm.tab.cpp"
    break;

  case 446: /* instruction: IMEXTSUPP TBOOLEAN BOOLEAN  */
#line 2350 "pnfasm.ypp"
                {
		 if (yyvsp[0] == "true")
		  fprintf(output, "272 1 1\n");
		 else
		  fprintf(output, "272 1 0\n");
		}
#line 7202 "pnfasm.tab.cpp"
    break;

  case 447: /* instruction: IMEXTSUPP TNUMBER NUMBER  */
#line 2356 "pnfasm.ypp"
                                                { fprintf(output, "272 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7208 "pnfasm.tab.cpp"
    break;

  case 448: /* instruction: IMEXTSUPP TCHARACTER CHARACTER  */
#line 2358 "pnfasm.ypp"
                {
		 char * dup = strdup(yyvsp[0].getString().c_str());
		 int ch = (int)dup[1];
		 fprintf(output, "272 3 %i\n", ch);
		}
#line 7218 "pnfasm.tab.cpp"
    break;

  case 449: /* instruction: IMEXTSUPP TSTRING STRING  */
#line 2364 "pnfasm.ypp"
                {
		 fprintf(output, "272 4 ");
		 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
                 {
		  if (yyvsp[0][i] != '\"')
                   fprintf(output, "%d ", (int)(yyvsp[0][i]));
		 }
		 fprintf(output, "0\n");
		}
#line 7232 "pnfasm.tab.cpp"
    break;

  case 450: /* instruction: ICPY TVOID VOID  */
#line 2374 "pnfasm.ypp"
                                                { 
						 fprintf(output, "273 0 0\n");
						}
#line 7240 "pnfasm.tab.cpp"
    break;

  case 451: /* instruction: IADDSEG TVOID VOID  */
#line 2378 "pnfasm.ypp"
                                                { 
						 fprintf(output, "274 0 0\n");
						}
#line 7248 "pnfasm.tab.cpp"
    break;

  case 452: /* instruction: IREMSEG TVOID VOID  */
#line 2382 "pnfasm.ypp"
                                                { 
						 fprintf(output, "275 0 0\n");
						}
#line 7256 "pnfasm.tab.cpp"
    break;

  case 453: /* instruction: ICOLLSEG TNUMBER NUMBER  */
#line 2386 "pnfasm.ypp"
                                                { fprintf(output, "276 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7262 "pnfasm.tab.cpp"
    break;

  case 454: /* instruction: IEXPSEG TNUMBER NUMBER  */
#line 2388 "pnfasm.ypp"
                                                { fprintf(output, "277 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7268 "pnfasm.tab.cpp"
    break;

  case 455: /* instruction: ICPYSEG TVOID VOID  */
#line 2390 "pnfasm.ypp"
                                                { 
						 fprintf(output, "278 0 0\n");
						}
#line 7276 "pnfasm.tab.cpp"
    break;

  case 456: /* instruction: ISEGLOAD TNUMBER NUMBER  */
#line 2394 "pnfasm.ypp"
                                                { fprintf(output, "279 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7282 "pnfasm.tab.cpp"
    break;

  case 457: /* instruction: ISEGSTORE TNUMBER NUMBER  */
#line 2396 "pnfasm.ypp"
                                                { fprintf(output, "280 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7288 "pnfasm.tab.cpp"
    break;

  case 458: /* instruction: ISEGPUSH TVOID VOID  */
#line 2398 "pnfasm.ypp"
                                                { 
						 fprintf(output, "281 0 0\n");
						}
#line 7296 "pnfasm.tab.cpp"
    break;

  case 459: /* instruction: ISEGPOP TVOID VOID  */
#line 2402 "pnfasm.ypp"
                                                { 
						 fprintf(output, "282 0 0\n");
						}
#line 7304 "pnfasm.tab.cpp"
    break;

  case 460: /* instruction: ISEGTOP TVOID VOID  */
#line 2406 "pnfasm.ypp"
                                                { 
						 fprintf(output, "283 0 0\n");
						}
#line 7312 "pnfasm.tab.cpp"
    break;

  case 461: /* instruction: ISEGVLOAD TBOOLEAN NUMBER  */
#line 2409 "pnfasm.ypp"
                                                { fprintf(output, "284 1 %s\n", yyvsp[0].getString().c_str()); }
#line 7318 "pnfasm.tab.cpp"
    break;

  case 462: /* instruction: ISEGVLOAD TNUMBER NUMBER  */
#line 2410 "pnfasm.ypp"
                                                        { fprintf(output, "284 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7324 "pnfasm.tab.cpp"
    break;

  case 463: /* instruction: ISEGVLOAD TCHARACTER NUMBER  */
#line 2411 "pnfasm.ypp"
                                                { fprintf(output, "284 3 %s\n", yyvsp[0].getString().c_str()); }
#line 7330 "pnfasm.tab.cpp"
    break;

  case 464: /* instruction: ISEGVLOAD TSTRING NUMBER  */
#line 2412 "pnfasm.ypp"
                                                        { fprintf(output, "284 4 %s\n", yyvsp[0].getString().c_str()); }
#line 7336 "pnfasm.tab.cpp"
    break;

  case 465: /* instruction: ISEGVSTORE TVOID VOID  */
#line 2413 "pnfasm.ypp"
                                                { fprintf(output, "285 0 0\n"); }
#line 7342 "pnfasm.tab.cpp"
    break;

  case 466: /* instruction: ISEGVSTORE TNUMBER NUMBER  */
#line 2414 "pnfasm.ypp"
                                                { fprintf(output, "285 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7348 "pnfasm.tab.cpp"
    break;

  case 467: /* instruction: IMSG TVOID NUMBER  */
#line 2415 "pnfasm.ypp"
                                    { fprintf(output, "286 0 %s\n", yyvsp[0].getString().c_str()); }
#line 7354 "pnfasm.tab.cpp"
    break;

  case 468: /* instruction: ILOOP TVOID VOID  */
#line 2416 "pnfasm.ypp"
                                        { fprintf(output, "287 0 0\n"); }
#line 7360 "pnfasm.tab.cpp"
    break;

  case 469: /* instruction: IELOOP TVOID VOID  */
#line 2417 "pnfasm.ypp"
                                        { fprintf(output, "288 0 0\n"); }
#line 7366 "pnfasm.tab.cpp"
    break;

  case 470: /* instruction: IWHILE TVOID VOID  */
#line 2418 "pnfasm.ypp"
                                        { fprintf(output, "289 0 0\n"); }
#line 7372 "pnfasm.tab.cpp"
    break;

  case 471: /* instruction: IWHILEB TVOID VOID  */
#line 2419 "pnfasm.ypp"
                                        { fprintf(output, "290 0 0\n"); }
#line 7378 "pnfasm.tab.cpp"
    break;

  case 472: /* instruction: IWHILEE TVOID VOID  */
#line 2420 "pnfasm.ypp"
                                        { fprintf(output, "291 0 0\n"); }
#line 7384 "pnfasm.tab.cpp"
    break;

  case 473: /* instruction: IWHILEBB TVOID VOID  */
#line 2421 "pnfasm.ypp"
                                        { fprintf(output, "292 0 0\n"); }
#line 7390 "pnfasm.tab.cpp"
    break;

  case 474: /* instruction: IWHILEBBB TVOID VOID  */
#line 2422 "pnfasm.ypp"
                                        { fprintf(output, "293 0 0\n"); }
#line 7396 "pnfasm.tab.cpp"
    break;

  case 475: /* instruction: IWHILEBBE TVOID VOID  */
#line 2423 "pnfasm.ypp"
                                        { fprintf(output, "294 0 0\n"); }
#line 7402 "pnfasm.tab.cpp"
    break;

  case 476: /* instruction: IUNTIL TVOID VOID  */
#line 2424 "pnfasm.ypp"
                                            { fprintf(output, "295 0 0\n"); }
#line 7408 "pnfasm.tab.cpp"
    break;

  case 477: /* instruction: IUNTILB TVOID VOID  */
#line 2425 "pnfasm.ypp"
                                        { fprintf(output, "296 0 0\n"); }
#line 7414 "pnfasm.tab.cpp"
    break;

  case 478: /* instruction: IUNTILE TVOID VOID  */
#line 2426 "pnfasm.ypp"
                                        { fprintf(output, "297 0 0\n"); }
#line 7420 "pnfasm.tab.cpp"
    break;

  case 479: /* instruction: IUNTILBB TVOID VOID  */
#line 2427 "pnfasm.ypp"
                                        { fprintf(output, "298 0 0\n"); }
#line 7426 "pnfasm.tab.cpp"
    break;

  case 480: /* instruction: IUNTILBBB TVOID VOID  */
#line 2428 "pnfasm.ypp"
                                        { fprintf(output, "299 0 0\n"); }
#line 7432 "pnfasm.tab.cpp"
    break;

  case 481: /* instruction: IUNTILBBE TVOID VOID  */
#line 2429 "pnfasm.ypp"
                                        { fprintf(output, "300 0 0\n"); }
#line 7438 "pnfasm.tab.cpp"
    break;

  case 482: /* instruction: IFOR TVOID VOID  */
#line 2430 "pnfasm.ypp"
                                        { fprintf(output, "301 0 0\n"); }
#line 7444 "pnfasm.tab.cpp"
    break;

  case 483: /* instruction: IFORINIT TVOID VOID  */
#line 2431 "pnfasm.ypp"
                                        { fprintf(output, "302 0 0\n"); }
#line 7450 "pnfasm.tab.cpp"
    break;

  case 484: /* instruction: IFORCOND TVOID VOID  */
#line 2432 "pnfasm.ypp"
                                        { fprintf(output, "303 0 0\n"); }
#line 7456 "pnfasm.tab.cpp"
    break;

  case 485: /* instruction: IFORINC TVOID VOID  */
#line 2433 "pnfasm.ypp"
                                        { fprintf(output, "304 0 0\n"); }
#line 7462 "pnfasm.tab.cpp"
    break;

  case 486: /* instruction: IFORB TVOID VOID  */
#line 2434 "pnfasm.ypp"
                                        { fprintf(output, "305 0 0\n"); }
#line 7468 "pnfasm.tab.cpp"
    break;

  case 487: /* instruction: IFORE TVOID VOID  */
#line 2435 "pnfasm.ypp"
                                        { fprintf(output, "306 0 0\n"); }
#line 7474 "pnfasm.tab.cpp"
    break;

  case 488: /* instruction: IFORBB TVOID VOID  */
#line 2436 "pnfasm.ypp"
                                        { fprintf(output, "307 0 0\n"); }
#line 7480 "pnfasm.tab.cpp"
    break;

  case 489: /* instruction: IFORBBINIT TVOID VOID  */
#line 2437 "pnfasm.ypp"
                                        { fprintf(output, "308 0 0\n"); }
#line 7486 "pnfasm.tab.cpp"
    break;

  case 490: /* instruction: IFORBBCOND TVOID VOID  */
#line 2438 "pnfasm.ypp"
                                        { fprintf(output, "309 0 0\n"); }
#line 7492 "pnfasm.tab.cpp"
    break;

  case 491: /* instruction: IFORBBINC TVOID VOID  */
#line 2439 "pnfasm.ypp"
                                        { fprintf(output, "310 0 0\n"); }
#line 7498 "pnfasm.tab.cpp"
    break;

  case 492: /* instruction: IFORBBB TVOID VOID  */
#line 2440 "pnfasm.ypp"
                                        { fprintf(output, "311 0 0\n"); }
#line 7504 "pnfasm.tab.cpp"
    break;

  case 493: /* instruction: IFORBBE TVOID VOID  */
#line 2441 "pnfasm.ypp"
                                        { fprintf(output, "312 0 0\n"); }
#line 7510 "pnfasm.tab.cpp"
    break;

  case 494: /* instruction: IFOREVER TVOID VOID  */
#line 2442 "pnfasm.ypp"
                                        { fprintf(output, "313 0 0\n"); }
#line 7516 "pnfasm.tab.cpp"
    break;

  case 495: /* instruction: IFOREVERE TVOID VOID  */
#line 2443 "pnfasm.ypp"
                                        { fprintf(output, "314 0 0\n"); }
#line 7522 "pnfasm.tab.cpp"
    break;

  case 496: /* instruction: IBREAK TVOID VOID  */
#line 2444 "pnfasm.ypp"
                                        { fprintf(output, "315 0 0\n"); }
#line 7528 "pnfasm.tab.cpp"
    break;

  case 497: /* instruction: IBREAK TNUMBER NUMBER  */
#line 2445 "pnfasm.ypp"
                                        { fprintf(output, "315 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7534 "pnfasm.tab.cpp"
    break;

  case 498: /* instruction: IBREAK TSTRING STRING  */
#line 2446 "pnfasm.ypp"
                                { 
						 fprintf(output, "315 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7548 "pnfasm.tab.cpp"
    break;

  case 499: /* instruction: ICONTINUE TVOID VOID  */
#line 2455 "pnfasm.ypp"
                                        { fprintf(output, "316 0 0\n"); }
#line 7554 "pnfasm.tab.cpp"
    break;

  case 500: /* instruction: ICONTINUE TNUMBER NUMBER  */
#line 2456 "pnfasm.ypp"
                                           { fprintf(output, "316 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7560 "pnfasm.tab.cpp"
    break;

  case 501: /* instruction: ICONTINUE TSTRING STRING  */
#line 2457 "pnfasm.ypp"
                                        { 
						 fprintf(output, "316 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7574 "pnfasm.tab.cpp"
    break;

  case 502: /* instruction: ICLASS TSTRING STRING  */
#line 2466 "pnfasm.ypp"
                                        { 
						 fprintf(output, "317 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7588 "pnfasm.tab.cpp"
    break;

  case 503: /* instruction: ICLASSVAR TSTRING STRING  */
#line 2475 "pnfasm.ypp"
                                                { 
						 fprintf(output, "318 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7602 "pnfasm.tab.cpp"
    break;

  case 504: /* instruction: IENDCLASS TVOID VOID  */
#line 2484 "pnfasm.ypp"
                                        { fprintf(output, "319 0 0\n"); }
#line 7608 "pnfasm.tab.cpp"
    break;

  case 505: /* instruction: ICLASSNAME TSTRING STRING  */
#line 2485 "pnfasm.ypp"
                                                { 
						 fprintf(output, "320 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7622 "pnfasm.tab.cpp"
    break;

  case 506: /* instruction: ICLASSONAME TSTRING STRING  */
#line 2494 "pnfasm.ypp"
                                                { 
						 fprintf(output, "321 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7636 "pnfasm.tab.cpp"
    break;

  case 507: /* instruction: ICLASSD TSTRING STRING  */
#line 2503 "pnfasm.ypp"
                                                { 
						 fprintf(output, "322 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7650 "pnfasm.tab.cpp"
    break;

  case 508: /* instruction: ICLASSUSE TVOID VOID  */
#line 2512 "pnfasm.ypp"
                                                { 
						 fprintf(output, "323 0 0\n");
						}
#line 7658 "pnfasm.tab.cpp"
    break;

  case 509: /* instruction: ICLASSUSE TNUMBER VOID  */
#line 2515 "pnfasm.ypp"
                                                {	
						fprintf(output, "323 2 0\n");
						}
#line 7666 "pnfasm.tab.cpp"
    break;

  case 510: /* instruction: ICLASSUSE TSTRING STRING  */
#line 2518 "pnfasm.ypp"
                                                { 
						 fprintf(output, "323 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7680 "pnfasm.tab.cpp"
    break;

  case 511: /* instruction: ICLASSUSING TVOID VOID  */
#line 2527 "pnfasm.ypp"
                                                { 
						 fprintf(output, "324 0 0\n");
						}
#line 7688 "pnfasm.tab.cpp"
    break;

  case 512: /* instruction: ICLASSUSINGNAME TVOID VOID  */
#line 2530 "pnfasm.ypp"
                                                { 
						 fprintf(output, "325 0 0\n");
						}
#line 7696 "pnfasm.tab.cpp"
    break;

  case 513: /* instruction: ICLASSGET TVOID VOID  */
#line 2533 "pnfasm.ypp"
                                                { 
						 fprintf(output, "326 0 0\n");
						}
#line 7704 "pnfasm.tab.cpp"
    break;

  case 514: /* instruction: ICLASSPUT TVOID VOID  */
#line 2536 "pnfasm.ypp"
                                                { 
						 fprintf(output, "327 0 0\n");
						}
#line 7712 "pnfasm.tab.cpp"
    break;

  case 515: /* instruction: ICLASSTYPE TVOID VOID  */
#line 2540 "pnfasm.ypp"
                                        { 
						 fprintf(output, "328 0 0\n");
						}
#line 7720 "pnfasm.tab.cpp"
    break;

  case 516: /* instruction: ICLASSTYPE2 TVOID VOID  */
#line 2543 "pnfasm.ypp"
                                                { 
						 fprintf(output, "329 0 0\n");
						}
#line 7728 "pnfasm.tab.cpp"
    break;

  case 517: /* instruction: ICLASSNAME2 TVOID VOID  */
#line 2546 "pnfasm.ypp"
                                                { 
						 fprintf(output, "330 0 0\n");
						}
#line 7736 "pnfasm.tab.cpp"
    break;

  case 518: /* instruction: ICLASSNAME3 TVOID VOID  */
#line 2549 "pnfasm.ypp"
                                                { 
						 fprintf(output, "331 0 0\n");
						}
#line 7744 "pnfasm.tab.cpp"
    break;

  case 519: /* instruction: ICLASSMETHOD TNUMBER NUMBER  */
#line 2552 "pnfasm.ypp"
                                              { fprintf(output, "328 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7750 "pnfasm.tab.cpp"
    break;

  case 520: /* instruction: ICLASSMETHOD2 TSTRING STRING  */
#line 2553 "pnfasm.ypp"
                                                { 
						 fprintf(output, "332 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7764 "pnfasm.tab.cpp"
    break;

  case 521: /* instruction: ICLASSMETHODCALL TSTRING STRING  */
#line 2562 "pnfasm.ypp"
                                                { 
						 fprintf(output, "333 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"');
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7778 "pnfasm.tab.cpp"
    break;

  case 522: /* instruction: ICLASSMETHODCPARAMS TVOID VOID  */
#line 2571 "pnfasm.ypp"
                                                                { fprintf(output, "334 0 0\n"); }
#line 7784 "pnfasm.tab.cpp"
    break;

  case 523: /* instruction: ICLASSMETHODECPARAMS TVOID VOID  */
#line 2572 "pnfasm.ypp"
                                                                { fprintf(output, "335 0 0\n"); }
#line 7790 "pnfasm.tab.cpp"
    break;

  case 524: /* instruction: ICLASSMETHODECALL TVOID VOID  */
#line 2573 "pnfasm.ypp"
                                                        { fprintf(output, "336 0 0\n"); }
#line 7796 "pnfasm.tab.cpp"
    break;

  case 525: /* instruction: ICLASSEXTENDACCESS TSTRING STRING  */
#line 2574 "pnfasm.ypp"
                                                { 
						 fprintf(output, "337 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7810 "pnfasm.tab.cpp"
    break;

  case 526: /* instruction: ICLASSEXTEND TSTRING STRING  */
#line 2583 "pnfasm.ypp"
                                        { 
						 fprintf(output, "338 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7824 "pnfasm.tab.cpp"
    break;

  case 527: /* instruction: ICLASSIMPLEMENTACCESS TSTRING STRING  */
#line 2592 "pnfasm.ypp"
                                                { 
						 fprintf(output, "339 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7838 "pnfasm.tab.cpp"
    break;

  case 528: /* instruction: ICLASSIMPLEMENT TSTRING STRING  */
#line 2601 "pnfasm.ypp"
                                                { 
						 fprintf(output, "340 4 ");
						 for (unsigned long i = 0; i < yyvsp[0].length(); ++i)
						 {
						  if (yyvsp[0][i] != '\"')
						   fprintf(output, "%d ", (int)(yyvsp[0][i]));
						 }
						 fprintf(output, "0\n");
						}
#line 7852 "pnfasm.tab.cpp"
    break;

  case 529: /* instruction: ASMVERSION TVOID VOID  */
#line 2611 "pnfasm.ypp"
                                                { /* Do nothing... */ }
#line 7858 "pnfasm.tab.cpp"
    break;

  case 530: /* instruction: PNF NUMBER NUMBER NUMBER  */
#line 2612 "pnfasm.ypp"
                                                { fprintf(output, "%s %s %s\n", yyvsp[-2].getString().c_str(), yyvsp[-1].getString().c_str(), yyvsp[0].getString().c_str()); }
#line 7864 "pnfasm.tab.cpp"
    break;

  case 532: /* variable: IVAR TVOID VOID  */
#line 2622 "pnfasm.ypp"
                                                { fprintf(output, "57 0 0\n"); }
#line 7870 "pnfasm.tab.cpp"
    break;

  case 533: /* variable: IVAR TBOOLEAN BOOLEAN  */
#line 2624 "pnfasm.ypp"
                                                {
			 			 if (yyvsp[0] == "true")
		 	  			  fprintf(output, "57 1 1\n");
			 			 else
			  			  fprintf(output, "57 1 0\n");
						}
#line 7881 "pnfasm.tab.cpp"
    break;

  case 534: /* variable: IVAR TNUMBER NUMBER  */
#line 2630 "pnfasm.ypp"
                                                { fprintf(output, "57 2 %s\n", yyvsp[0].getString().c_str()); }
#line 7887 "pnfasm.tab.cpp"
    break;

  case 535: /* variable: IVAR TCHARACTER CHARACTER  */
#line 2632 "pnfasm.ypp"
                                                {
			 			 char * dup = strdup(yyvsp[0].getString().c_str());
			 			 int ch = (int)dup[1];
			 			 fprintf(output, "57 3 %i\n", ch);
						}
#line 7897 "pnfasm.tab.cpp"
    break;

  case 536: /* variable: IVAR TSTRING STRING  */
#line 2638 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 4 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7908 "pnfasm.tab.cpp"
    break;

  case 537: /* variable: IVAR TBOOLEAN VOID  */
#line 2644 "pnfasm.ypp"
                                                { fprintf(output, "57 1 0\n"); }
#line 7914 "pnfasm.tab.cpp"
    break;

  case 538: /* variable: IVAR TNUMBER VOID  */
#line 2645 "pnfasm.ypp"
                                                { fprintf(output, "57 2 0\n"); }
#line 7920 "pnfasm.tab.cpp"
    break;

  case 539: /* variable: IVAR TCHARACTER VOID  */
#line 2646 "pnfasm.ypp"
                                                { fprintf(output, "57 3 0\n"); }
#line 7926 "pnfasm.tab.cpp"
    break;

  case 540: /* variable: IVAR TSTRING VOID  */
#line 2647 "pnfasm.ypp"
                                                { fprintf(output, "57 4 0\n"); }
#line 7932 "pnfasm.tab.cpp"
    break;

  case 541: /* variable: IVAR TVOID STRING  */
#line 2649 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 0 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7943 "pnfasm.tab.cpp"
    break;

  case 542: /* variable: IVAR TBOOLEAN STRING  */
#line 2656 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 1 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7954 "pnfasm.tab.cpp"
    break;

  case 543: /* variable: IVAR TNUMBER STRING  */
#line 2663 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 2 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7965 "pnfasm.tab.cpp"
    break;

  case 544: /* variable: IVAR TCHARACTER STRING  */
#line 2670 "pnfasm.ypp"
                                                {		
						 fprintf(output, "57 3 ");				 
		 	 			 for (unsigned long i = 1; yyvsp[0][i] != '"'; ++i)
				  	  	  fprintf(output, "%i ", (int)yyvsp[0][i]);
		 	 			 fprintf(output, "0\n");
						}
#line 7976 "pnfasm.tab.cpp"
    break;

  case 545: /* pp: PINCLUDE STRING  */
#line 2679 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#include %s\n", yyvsp[0].getString().c_str()); }
#line 7982 "pnfasm.tab.cpp"
    break;

  case 546: /* pp: PINCLUDE "<" STRING ">"  */
#line 2680 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#include <%s>\n", yyvsp[-2].getString().c_str()); }
#line 7988 "pnfasm.tab.cpp"
    break;

  case 547: /* pp: PIMPORT STRING  */
#line 2681 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#import %s \n", yyvsp[0].getString().c_str()); }
#line 7994 "pnfasm.tab.cpp"
    break;

  case 548: /* pp: PIMPORT "<" STRING ">"  */
#line 2682 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#import <%s> \n", yyvsp[-2].getString().c_str()); }
#line 8000 "pnfasm.tab.cpp"
    break;

  case 549: /* pp: PDEFINE STRING STRING  */
#line 2683 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#define %s %s\n", yyvsp[-1].getString().c_str(), yyvsp[0].getString().c_str()); }
#line 8006 "pnfasm.tab.cpp"
    break;

  case 550: /* pp: PMACRO STRING  */
#line 2684 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#macro %s\n", yyvsp[0].getString().c_str()); }
#line 8012 "pnfasm.tab.cpp"
    break;

  case 551: /* pp: PENDM  */
#line 2685 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#endm\n"); }
#line 8018 "pnfasm.tab.cpp"
    break;

  case 552: /* pp: PUNDEF STRING  */
#line 2686 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#undef %s\n", yyvsp[0].getString().c_str()); }
#line 8024 "pnfasm.tab.cpp"
    break;

  case 553: /* pp: PIFDEF STRING  */
#line 2687 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#ifdef %s\n", yyvsp[0].getString().c_str()); }
#line 8030 "pnfasm.tab.cpp"
    break;

  case 554: /* pp: PIFNDEF STRING  */
#line 2688 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#ifndef %s\n", yyvsp[0].getString().c_str()); }
#line 8036 "pnfasm.tab.cpp"
    break;

  case 555: /* pp: PELSE  */
#line 2689 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#else\n"); }
#line 8042 "pnfasm.tab.cpp"
    break;

  case 556: /* pp: PENDIF  */
#line 2690 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "#endif\n"); }
#line 8048 "pnfasm.tab.cpp"
    break;

  case 557: /* pp: PPDATE  */
#line 2691 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_DATE()\n"); }
#line 8054 "pnfasm.tab.cpp"
    break;

  case 558: /* pp: PPTIME  */
#line 2692 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_TIME()\n"); }
#line 8060 "pnfasm.tab.cpp"
    break;

  case 559: /* pp: PPLINE  */
#line 2693 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_LINE()\n"); }
#line 8066 "pnfasm.tab.cpp"
    break;

  case 560: /* pp: PPFILE  */
#line 2694 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_FILE()\n"); }
#line 8072 "pnfasm.tab.cpp"
    break;

  case 561: /* pp: PPCDATE  */
#line 2695 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_CDATE()\n"); }
#line 8078 "pnfasm.tab.cpp"
    break;

  case 562: /* pp: PPCTIME  */
#line 2696 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "_CTIME()\n"); }
#line 8084 "pnfasm.tab.cpp"
    break;

  case 563: /* pp: PPCOMMENT  */
#line 2697 "pnfasm.ypp"
                                          { if (mode == 1 || mode == 2) fprintf(output, "\' %s\n", yyvsp[0].getString().c_str()); }
#line 8090 "pnfasm.tab.cpp"
    break;

  case 564: /* directive: BIN  */
#line 2700 "pnfasm.ypp"
                        { mode = 0; }
#line 8096 "pnfasm.tab.cpp"
    break;

  case 565: /* directive: PBIN  */
#line 2701 "pnfasm.ypp"
                        { mode = 1; }
#line 8102 "pnfasm.tab.cpp"
    break;

  case 566: /* directive: LIB  */
#line 2702 "pnfasm.ypp"
                        { mode = 2; }
#line 8108 "pnfasm.tab.cpp"
    break;


#line 8112 "pnfasm.tab.cpp"

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

#line 2705 "pnfasm.ypp"

/* Additional C/C++ Code */
void yyerror(char const * c)
{
 cout << "* ERROR: " << yylineno << ": " << c << endl;
}
