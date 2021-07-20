/*
    Copyright 2019 Dennis Earl Smiley

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/*
 CHANGELOG
 =========

 5/25/15 Origional a 	- The first version.
 5/25/15 Origional a-a	- 1. Removed IADDSTORE instruction. 2 instructions did the same thing.
 						  2. Fixed a bug in FOMODE.
 						  3. Fixed a bug in memory.
 						  4. Fixed bugs...
 7/26/15 Original a-a-a   1. Added support for Type1 range.
 7/29/15 Original a-a-b   Fixed bugs...
 7/30/15 Original a-a-c   1. Fixed bugs...
 						  2. Added support for Type1 range implementation.
 						  3. Fixed bugs...
 						  4. Added support for RLOAD1 and RSTORE1.
 						  5. Fixed bugs...
 						  6. Added features to fix bugs...
 						  7. Fixed bugs...
						  8. Prepared to add support for type2 ranges
						  9. Added support for type2 ranges
						 10. Added support for type2 range implementations
						 11. Fixed bugs...
						 12. Added support for RPREP2 and RLOAD2
						 13. Fixed a bug: Forgot to set from and to of type2 range!
						 14. Fixed a bug: Need graceful crash for type2 range RLOAD2...
						 15. Added support for enums
						 16. Added support for enum implementations
						 17. Added support for other enum instructions
						 18. Fixed bugs...
						 19. Added exception handlers
						 20. Prepared to add arrays
						 21. Added support for arrays
						 22. Added support for arrays (stage 2)
						 23. Fixed bugs...
						 24. Added other array functions
						 25. Fixed bugs...
						 26. Fixed bugs...
						 27. Fixed bugs...
						 28. Fixed bugs...
						 29. Changed to work with new template.
						 30. Fixed bugs...
						 31. Changed to work with new template.
						 32. Fixed bugs...
						 33. Changed array to match changed design.
						 34. Fixed bugs...
						 35. Fixed bug 0.
						 
3/25/17 Origional a-a-d  			 1. Added support for preprocessor.
						 2. Fixed bugs...
						 3. Added new Array instructions.
						 4. Added IFs.

3/23/19 Origional a-a-e				 1. Added switches.
						 2. Added stack registers.
						 3. Added PATCH instruction.
						 4. Added NATIVE instruction.
						 5. Made work with class Array.

11/22/19 Origional a-a-f			1. Made new version
						2. Added FDEF, FDEF2, FEDEF2 and FEDEF instructions.
						3. Added function calls.
						4. Added more instructions for functions.
						5. Added documentation for instructions.
						6. An attempt at overloaded functions.
						7. Fixed bugs...
						8. Took out "extra" instructions.
						9. Debugged...
					       10. Debugged...
					       11. Removed extra instructions.
					       12. Debugged...
					       13. Finished debugging function parameters.
					       14. Debugged function parameters further...
					       15. Found the bug...
					       16. Added default values...
					       17. Added try...catch to PNF::execute()
					       18. Debugged...
					       19. Debugged...

8/20/20 Origional a-a-g -			1. Added NTIMES instruction.
						2. Added CMP instruction.
						3. Added RUN, JRUN & PNFRUN instructions.
						4. Added more basic types.
						5. Changed the type of %accumulator and %calc, to greatly enhance features. Not using anywhere 							   yet.
						6. Debugged...
						7. Plopped a struct definition in there.
						8. Because it wouldn't work, due to forward declarations, I restructured the files...
						9. Files restructured, for now.
					       10. Created structs instructions.
					       11. Debugged structs instructions...
					       12. Debugged...
					       13. Completed struct instructions.
					       14. Started working on unions
					       15. Finished work on unions
					       16. Added segments and some simple instructions for them.
					       17. Implemented segment instructions.
*/
#include <desLib/deslib.hpp>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <cctype>

#ifdef OS_WINDOWS
#include <process.h>
#endif // OS_WINDOWS


/*
 IVERSION   - Switches versions. Default version is 0V.
              VERSION TVOID 0V
	      VERSION TVOID 1

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

 IRDSTART1  - Marks the start of a type1 range.
 			  RDSTART1 TSTRING [name]

 IRFROM1    - Specifies the type1 range from value.
 			  RFROM1 TNUMBER [num]

 IRTO1		- Specifies the type1 range to value.
 			  RTO1 TNUMBER [num]

 IRDEND1	- Marks the end of a type1 range.
              RDEND1 TVOID 0V

 IRSTART1   - Marks the start of a type1 range implementation. Needs a definition name.
              RSTART1 TSTRING [defname]

 IRANGE1    - Specifies the range implementation value for a type1 range. To be valid, number MUST be within the range values...
 			  RANGE1 TNUMBER [num]

 IREND1     - Marks the end of the type1 range implementation, and names it.
 			  REND1 TSTRING [name]

 IRLOAD1    - Loads a value from a type1 range to %accumulator.
 			  RLOAD1 TSTRING [name]

 IRSTORE1   - Stores a value from %accumulator to a type1 range.
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

 IRDSTART2  - Marks the start of a type2 range.
 			  RDSTART2 TSTRING [name]

 IRFROM2    - Specifies the type2 range from value.
 			  RFROM2 TNUMBER [num]

 IRTO2		- Specifies the type2 range to value.
 			  RTO2 TNUMBER [num]

 IRDEND2	- Marks the end of a type2 range.
              RDEND2 TVOID 0V

 IRSTART2   - Marks the start of a type2 range implementation. Needs a definition name.
              RSTART2 TSTRING [defname]

 IRANGE2    - Specifies the range implementation value for a type2 range.
 			  RANGE2 TSTRING [name]

 IRPREP2	- Prepares the %rt2prep register...
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

 IEPREP		- Prepares the %etprep register...
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

 IAIPREP	- Prepares %aiprep register. If TVOID, uses %accumulator as number.
 			  AIPREP TNUMBER [num]
 			  AIPREP TVOID 0V

 ILOADIA	- Loads a value from an array to %accumulator
 			  LOADIA TVOID 0V

 ISTOREIA	- Stores a value from %accumulator to an array
 			  STOREIA TVOID 0V
 			  
 IALENGTH   - Puts the length of an Array in %accumulator.
 			  ALENGTH TVOID 0V
 			  
 IAPRINT	- Prints out the values of an Array.
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

 IPNUM        - Allows us to specify an actual parameter number.
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
#include "CPP/include/PNF_Enums.cpp"
#include "CPP/include/PNF_Types.hpp"

class PNF_Var
{
 private:
  unsigned long itsaddress;
  unsigned long itstype;


 public:
  PNF_Var(unsigned long e);
  ~PNF_Var();


  unsigned long address();
  void address(unsigned long address);

  unsigned long type();
  void type(unsigned long t);
};

PNF_Var::PNF_Var(unsigned long e = 0)
{
 itsaddress = e;
 itstype = TVOID;
}

PNF_Var::~PNF_Var()
{

}

unsigned long PNF_Var::address()
{
 return itsaddress;
}

void PNF_Var::address(unsigned long address)
{
 itsaddress = address;
}

unsigned long PNF_Var::type()
{
 return itstype;
}

void PNF_Var::type(unsigned long t)
{
 itstype = t;
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

class Segment
{
 protected:
  Memory itsmem;
  Stack itsstk;


 public:
  Segment(int i = 0);


  Memory & mem();
  void mem(const Memory mem);

  Stack & stk();
  void stk(const Stack stk);
};

Segment::Segment(int i)
{

}

Memory & Segment::mem()
{
 return itsmem;
}

void Segment::mem(const Memory mem)
{
 itsmem = mem;
}

Stack & Segment::stk()
{
 return itsstk;
}

void Segment::stk(const Stack stk)
{
 itsstk = stk;
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

Label::Label(unsigned long n = 0, String s = (char *)"")
{
 num = n;
 string = s;
}

void Label::setLabel(unsigned long n = 0, String s = (char *)"")
{
 num = n;
 string = s;
}

void Label::setNum(unsigned long n = 0)
{
 num = n;
}

void Label::setString(String s = (char *)"")
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
  bool felement;


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
 felement = true;
}

void ETable::add(unsigned long value)
{
 if (length() >= 1 && !felement)
 {
  table.insert();
 }
 else
  felement = false;

 table[(length() - 1)] = value;
}

void ETable::remove()
{
 table.remove();
}

void ETable::edit(unsigned long index, unsigned long value)
{
 if (index < length())
  table[index] = value;
 else
 {
  add(value);
 }
}

unsigned long ETable::get(unsigned long index)
{
 if (index >= length())
  return -1;
 return table[index];
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


 bool check(PNF_Variable v, double t);
};

PNF_Version::PNF_Version(unsigned long d = 0)
{
 PNF_Void v;
 base.put(v);
 top = d;
}

bool PNF_Version::check(PNF_Variable v, double t)
{
 if (t == top)
 {
  switch (base.getType())
  {
   case TVOID:
    if (v.getType() == TVOID) return true;
    break;

   case TBOOLEAN:
    if (base.to_boolean().get() == v.to_boolean().get()) return true;
    break;
    
   case TNUMBER:
    if (base.to_number().get() == v.to_number().get()) return true;
    break;

   case TCHARACTER:
    if (base.to_character().get() == v.to_character().get()) return true;
    break;

   case TSTRING:
    if (base.to_string().get() == v.to_string().get()) return true;
    break;

   default:
    return false;
  };
 }
 else
  return false;
}

class iftypestruct
{
 public:
  bool value;
  unsigned long scope;
  
  unsigned long ifb;
  unsigned long endif;
  unsigned long elseb;
  unsigned long endelse;
  unsigned long eif;
  
  iftypestruct(int n = 0);
};

iftypestruct::iftypestruct(int n)
{
 value = false;
 scope = 0;
 
 ifb = 0;
 endif = 0;
 elseb = 0;
 endelse = 0;
 eif = 0;
}

class ifstruct
{
 public:
  iftypestruct type;
  
  
  ifstruct(int n = 0);
};

ifstruct::ifstruct(int n)
{

}

class Param
{
 protected:
  String itsname;
  PNF_Variable itsparam;
  PNF_Variable itsdefault;


 public:
  Param(int i = 0);

  Param(const Param & p);


  String name();
  void name(String n);

  PNF_Variable & param();
  void param(PNF_Variable v);

  PNF_Variable & defaultv();
  void defaultv(PNF_Variable v);

  void syncdefault();
};

Param::Param(int i)
{
 itsname = (char *)"";
 PNF_Void v;
 itsparam.put(v);
 itsdefault.put(v);
}

Param::Param(const Param & p)
{
 itsname = p.itsname;
 itsparam = p.itsparam;
 itsdefault = p.itsdefault;
}

String Param::name()
{
 return itsname;
}

void Param::name(String n)
{
 itsname = n;
}

PNF_Variable & Param::param()
{
 return itsparam;
}

void Param::param(PNF_Variable v)
{
 switch (v.getType())
 {
  case TVOID:
   itsparam.put(v.to_Void());
   break;

  case TBOOLEAN:
  {
   PNF_Boolean b(v.to_boolean());
   itsparam.put(b);
  }
  break;

  case TNUMBER:
   itsparam.put(v.to_number());
   break;

  case TCHARACTER:
   itsparam.put(v.to_character());
   break;

  case TSTRING:
   itsparam.put(v.to_string());
   break;

  default:
   cout << "* ERROR: Invalid type.";
 }
}

PNF_Variable & Param::defaultv()
{
 return itsdefault;
}

void Param::defaultv(PNF_Variable v)
{
 switch (v.getType())
 {
  case TVOID:
   itsdefault.put(v.to_Void());
   break;

  case TBOOLEAN:
  {
   PNF_Boolean b(v.to_boolean());
   itsdefault.put(b);
  }
  break;

  case TNUMBER:
   itsdefault.put(v.to_number());
   break;

  case TCHARACTER:
   itsdefault.put(v.to_character());
   break;

  case TSTRING:
   itsdefault.put(v.to_string());
   break;

  default:
   cout << "* ERROR: Invalid type.";
 }

 syncdefault();
}

void Param::syncdefault()
{
 itsparam = itsdefault;
}

class Function
{
 protected:
  Array<Param> itsret;
  String itsname;
  Array<Param> itsparam;
  unsigned long itsdef;

 public:
  Function(int i = 0);

  Function(const Function & f);


  ~Function();


 PNF_Variable ret(unsigned long i);
 PNF_Variable retdefaultv(unsigned long i);
 Array<Param> rets();
 String name();
 String rname();
 Array<Param> params();
 PNF_Variable & param(unsigned long i);
 String pname(unsigned long i);
 PNF_Variable & defaultv(unsigned long i);
 unsigned long definition();

 void ret(unsigned long i, PNF_Variable r);
 void retdefaultv(unsigned long i, PNF_Variable r);
 void name(String n);
 void rname(String n);
 void params(Array<Param> p);
 void param(unsigned long i, PNF_Variable v);
 void pname(unsigned long i, String n);
 void defaultv(unsigned long i, PNF_Variable v);
 void definition(unsigned long d);

 void syncdefaultr(unsigned long i);
 void syncdefaultp(unsigned long i);

 String & mangle();
 String & unmangle();
};

Function::Function(int i) : itsdef(0)
{
 itsname = (char *)"";

 PNF_Variable v;
 itsparam[0].param(v);
 itsret[0].param(v);
}

Function::Function(const Function & f)
{
 itsname = f.itsname;
 itsret = f.itsret;
 itsparam = f.itsparam;
 itsdef = f.itsdef;
}

Function::~Function()
{

}

PNF_Variable Function::ret(unsigned long i)
{
 return itsret[i].param();
}

PNF_Variable Function::retdefaultv(unsigned long i)
{
 return itsret[i].defaultv();
}

Array<Param> Function::rets()
{
 return itsret;
}

String Function::name()
{
 return unmangle();
}

String Function::rname()
{
 return itsname;
}

Array<Param> Function::params()
{
 return itsparam;
}

PNF_Variable & Function::param(unsigned long i)
{
 return itsparam[i].param();
}

String Function::pname(unsigned long i)
{
 return itsparam[i].name();
}

PNF_Variable & Function::defaultv(unsigned long i)
{
 return itsparam[i].defaultv();
}

unsigned long Function::definition()
{
 return itsdef;
}

void Function::ret(unsigned long i, PNF_Variable r)
{
 for (unsigned long is = i; is > itsret.length() - 1; --is)
  itsret.insert();

 itsret[i].param(r);
}

void Function::retdefaultv(unsigned long i, PNF_Variable r)
{
 for (unsigned long is = i; is > itsret.length() - 1; --is)
  itsret.insert();

 itsret[i].defaultv(r);
}

void Function::name(String n)
{
 itsname = n;
 String str = mangle();
 itsname = str;
}

void Function::rname(String n)
{
 itsname = n;
}

void Function::params(Array<Param> p)
{
 itsparam = p;
}

void Function::param(unsigned long i, PNF_Variable v)
{
 for (unsigned long is = i; is > itsparam.length() - 1; --is)
  itsparam.insert();

 switch (v.getType())
 {
  case TVOID:
   itsparam[i].param(v.to_Void());
   break;

  case TBOOLEAN:
   itsparam[i].param(v.to_boolean());
   break;

  case TNUMBER:
   itsparam[i].param(v.to_number());
   break;

  case TCHARACTER:
   itsparam[i].param(v.to_character());
   break;

  case TSTRING:
   itsparam[i].param(v.to_string());
   break;

  default:
   cout << "* ERROR: Invalid type.\n";
 }
}

void Function::pname(unsigned long i, String n)
{
 for (unsigned long is = i; is > itsparam.length() - 1; --is)
  itsparam.insert();

 itsparam[i].name(n);
}

void Function::defaultv(unsigned long i, PNF_Variable v)
{
 for (unsigned long is = i; is > itsparam.length() - 1; --is)
  itsparam.insert();

 switch (v.getType())
 {
  case TVOID:
   itsparam[i].defaultv(v.to_Void());
   break;

  case TBOOLEAN:
   itsparam[i].defaultv(v.to_boolean());
   break;

  case TNUMBER:
   itsparam[i].defaultv(v.to_number());
   break;

  case TCHARACTER:
   itsparam[i].defaultv(v.to_character());
   break;

  case TSTRING:
   itsparam[i].defaultv(v.to_string());
   break;

  default:
   cout << "* ERROR: Invalid type.\n";
 }
}

void Function::definition(unsigned long d)
{
 itsdef = d;
}

void Function::syncdefaultr(unsigned long i)
{
 itsret[i].syncdefault();
}

void Function::syncdefaultp(unsigned long i)
{
 itsparam[i].syncdefault();
}

String & Function::mangle()
{
 String * str = new String();
 *str = unmangle();

 for (unsigned long i = 0; i < itsret.length(); ++i)
 {
  switch (itsret[i].param().getType())
  {
   case TVOID:
    *str += (char *)"_rVOID";
    break;

   case TBOOLEAN:
    *str += (char *)"_rBOOLEAN";
    break;

   case TNUMBER:
    *str += (char *)"_rNUMBER";
    break;

   case TCHARACTER:
    *str += (char *)"_rCHARACTER";
    break;

   case TSTRING:
    *str += (char *)"_rSTRING";
    break;

   default:
    *str += (char *)"_rNONE";
  }
 }

 for (unsigned long i = 0; i < itsparam.length(); ++i)
 {
  switch (itsparam[i].param().getType())
  {
   case TVOID:
    *str += (char *)"_VOID";
    break;

   case TBOOLEAN:
    *str += (char *)"_BOOLEAN";
    break;

   case TNUMBER:
    *str += (char *)"_NUMBER";
    break;

   case TCHARACTER:
    *str += (char *)"_CHARACTER";
    break;

   case TSTRING:
    *str += (char *)"_STRING";
    break;

   default:
    *str += (char *)"_NONE";
  }
 }

 return *str;
}

String & Function::unmangle()
{
 String *str = new String((char *)"");

 for (unsigned long i = 0; i < itsname.length(); ++i)
 {
  if (itsname[i] == '_')
   break;
  *str += itsname[i];
 }

 return *str;
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
  Function & get_function(unsigned long i);
  Function & get_function(String n, bool & f);
  Function & last_function();
  void mod_function(unsigned long i, Function f);

  unsigned long length();

 unsigned long find(String name);
 unsigned long find(String name, Array<String> rets, Array<String> params);
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
 try
 {
  mod_function(itsstk.length(), f);
 }
 catch (Exception e)
 {
  e.file((char *)__FILE__);
  e.line(__LINE__);
  e.display();
  exit(1);
 }
}

Function & Function_Stack::get_function(unsigned long i)
{
 for (unsigned long is = i; is > itsstk.length(); --is)
  itsstk.insert();

 return itsstk[i];
}

Function & Function_Stack::get_function(String n, bool & f)
{
 Function * itsnull = new Function();
 bool found = false;
 unsigned long i;
 for (i = 0; i < itsstk.length(); ++i)
 {
  String name = itsstk[i].rname();
  if (name == n)
  {
   found = true;
   break;
  }
 }

 if (found == false)
 {
  f = false;
  return *itsnull;
 }
 else
 {
  f = true;
  return itsstk[i];
 }
}

Function & Function_Stack::last_function()
{
 return itsstk[itsstk.length() - 1];
}

void Function_Stack::mod_function(unsigned long i, Function f)
{
 for (unsigned long j = i; j >= itsstk.length(); --i)
  itsstk.insert();

 itsstk[i] = f;
}

unsigned long Function_Stack::length()
{
 return itsstk.length();
}

unsigned long Function_Stack::find(String n)
{
 bool found = false;
 unsigned long i;
 for (i = 0; i < itsstk.length(); ++i)
 {
  String str = itsstk[i].name();
  if (str == n)
  {
   found = true;
   break;
  }
 }

 if (found == true)
  return i;
 else
  return -1;
}

unsigned long Function_Stack::find(String name, Array<String> rets, Array<String> params)
{
 rets.remove();
 params.remove();

 bool found = false;
 unsigned long i;
 for (i = 0; i < itsstk.length(); ++i)
 {
  bool params2 = false, params3 = false;
  String str = itsstk[i].rname();
  if (i == 0)
  {
   for (unsigned long j = 0; j < rets.length(); ++j)
   {
    if (j == 0)
     params3 = true;
    name += ((char *)"_r" + rets[j]);
   }

   if (params3 == false)
    name += (char *)"_rVOID";

   for (unsigned long j = 0; j < params.length(); ++j)
   {
    if (j == 0)
     params2 = true;
    name += ((char *)"_" + params[j]);
   }

   if (params2 == false)
    name += (char *)"_VOID";


   // DEBUG: cout << "str: " << str << " name: " << name << endl;
  }

  if (str == name)
  {
   found = true;
   break;
  }
 }

 if (found == true)
  return i;
 else
  return -1;
}

unsigned long Function_Stack::find_duplicate(Function f, bool & b)
{
 try
 {
  unsigned long ret;
  b = false;
  unsigned long i;
  for (i = 0; i < itsstk.length(); ++i)
  {
   if (itsstk[i].rname() == f.rname())
   {
    b = false;
    for (unsigned long j = 0; j < itsstk[i].rets().length(); ++j)
    {
     if (itsstk[i].ret(j).getm() == f.ret(j).getm())
     {
      for (unsigned k = 0; k < itsstk[i].params().length(); ++k)
      {
       if (itsstk[i].param(k).getm() != f.param(k).getm())
        b = true;
      }
     }
    }
   }
  }

  ret = i;
  return ret;
 }
 catch (Exception e)
 {
  e.file((char *)__FILE__);
  e.line(__LINE__);
  e.display();
  exit(1);
 }
}


class Registers
{
 public:
  bool quit;

  Memory extrai;
 
  unsigned long icount;

  unsigned long instruction;
  unsigned long type;
  unsigned long operand;
  unsigned long ninstruction;
  unsigned long pinstruction;
  unsigned long pins;

  unsigned long savins;
  unsigned long savins2;
  unsigned long savins3;

  unsigned long mins;
  unsigned long pmins;


  String iname;
  Array<String> args;


  unsigned long ecount;
  Array<PNF_Var> varcount;
  Array<Label> labels;
  Array<unsigned long> elabels;


  Array<PNF_RangeD> rt1defs;
  Array<PNF_RangeT1> rt1vars;

  Array<PNF_RangeD> rt2defs;
  Array<PNF_RangeT2> rt2vars;
  unsigned long rt2prep;


  Array<PNF_EnumD> edefs;
  unsigned long eptr;
  Array<PNF_Enum> evars;
  unsigned long eprep;

  Array< PNF_Array<PNF_Object> > avars;
  bool usingarray;
  bool inarray;
  unsigned long aoffset;
  unsigned long aoffset2;
  unsigned long aoffset3;
  String aprep;
  unsigned long aiprep;


  unsigned long evalue;
  ETable hevents;
  ETable shevents;
  ETable events;
  ETable exceptions;
  ETable interrupts;


  String type_of;


  PNF_Object2 accumulator;
  PNF_Object2 calc;

  PNF_Variable stackp;
  Stack savestack;

  PNF_Version version;
  Array<PNF_Version> sversion;

  Array<unsigned long> sinstruction;
  Array<unsigned long> stype;


  PNF_FMODE fimode;
  PNF_FMODE fomode;
 
 
  unsigned long ifcounter;
  bool ifcond;
  unsigned long eifsave;
  unsigned long ifscope;
  Array<ifstruct> inif;
  unsigned long ifindex;

  Array<unsigned long> switches;
  unsigned long switchcounter;
  unsigned long switchindex;
  bool switchcond;
  bool switcht;


  Function_Stack fpointer1;
  unsigned long fpointer1c;
  unsigned long fpointer1c2;
  Function * fpointer2;
  Function * fpointer3;
  String fname;
  String fname2;
  Array<String> frets;
  Array<String> fparams;
  Array<String> frets2;
  Array<String> fparams2;
  Array<String> frets3;
  Array<String> fparams3;
  unsigned long pnum;
  unsigned long rnum;

  bool infunc;
  unsigned long infuncc;
  bool inparams;
  unsigned long inparamsc;

  bool fdefaultv;
  PNF_Object2 fdefaultvalue;
 
 
  Array2<PNF_Struct> structs;
  Array2<PNF_Struct> ostructs;
  String struct_type;
  String struct_name;


  Array2<PNF_Union> unions;
  Array2<PNF_Union> ounions;
  String union_type;
  String union_name;


  PNF_Version mode;
  Array<PNF_Version> smode;

  PNF_Version extmode;
  Array<PNF_Version> sextmode;



 Registers();
 Registers(const Registers & r);

 Registers & operator=(const Registers & r);

 Registers & copy(const Registers & r);
};

Registers::Registers()
{

}

Registers::Registers(const Registers & r)
{
 this->copy(r);
}

Registers & Registers::operator=(const Registers & r)
{
 if (this == &r)
  return *this;

 return copy(r);
}

Registers & Registers::copy(const Registers & r)
{
 quit = r.quit;

 extrai = r.extrai;
 
 icount = r.icount;

 instruction = r.instruction;
 type = r.type;
 operand = r.operand;
 ninstruction = r.ninstruction;
 pinstruction = r.pinstruction;
 pins = r.pins;

 savins = r.savins;
 savins2 = r.savins2;
 savins3 = r.savins3;

 mins = r.mins;
 pmins = r.pmins;


 iname = r.iname;
 args = r.args;


 ecount = r.ecount;
 varcount = r.varcount;
 labels = r.labels;
 elabels = r.elabels;


 rt1defs = r.rt1defs;
 rt1vars = r.rt1vars;

 rt2defs = r.rt2defs;
 rt2vars = r.rt2vars;
 rt2prep = r.rt2prep;


 edefs = r.edefs;
 eptr = r.eptr;
 evars = r.evars;
 eprep = r.eprep;

  Array< PNF_Array<PNF_Object> > avars;
  bool usingarray;
  bool inarray;
  unsigned long aoffset;
  unsigned long aoffset2;
  unsigned long aoffset3;
  String aprep;
  unsigned long aiprep;


  unsigned long evalue;
  ETable hevents;
  ETable shevents;
  ETable events;
  ETable exceptions;
  ETable interrupts;


  String type_of;


  PNF_Object2 accumulator;
  PNF_Object2 calc;

  PNF_Variable stackp;
  Stack savestack;

  PNF_Version version;
  Array<PNF_Version> sversion;

  Array<unsigned long> sinstruction;
  Array<unsigned long> stype;


  PNF_FMODE fimode;
  PNF_FMODE fomode;
 
 
  unsigned long ifcounter;
  bool ifcond;
  unsigned long eifsave;
  unsigned long ifscope;
  Array<ifstruct> inif;
  unsigned long ifindex;

  Array<unsigned long> switches;
  unsigned long switchcounter;
  unsigned long switchindex;
  bool switchcond;
  bool switcht;


  Function_Stack fpointer1;
  unsigned long fpointer1c;
  unsigned long fpointer1c2;
  Function * fpointer2;
  Function * fpointer3;
  String fname;
  String fname2;
  Array<String> frets;
  Array<String> fparams;
  Array<String> frets2;
  Array<String> fparams2;
  Array<String> frets3;
  Array<String> fparams3;
  unsigned long pnum;
  unsigned long rnum;

  bool infunc;
  unsigned long infuncc;
  bool inparams;
  unsigned long inparamsc;

  bool fdefaultv;
  PNF_Object2 fdefaultvalue;
 
 
  Array2<PNF_Struct> structs;
  Array2<PNF_Struct> ostructs;
  String struct_type;
  String struct_name;
}


class ProgramState
{
 public:
  Registers reg;
  Memory mem;
  Stack stk;

 ProgramState();
};

ProgramState::ProgramState()
{

}


class PNF
{
 private:
         Memory mem;
         Registers reg;
         Stack stk;
         Stack substk;
	 Stack funcstk;

	Array<Segment> segments;


         ifstream pnffin;
         ofstream pnffout;


         String get_extension(String fileName);
         String strip_extension(String fileName);


        ProgramState builtin_breakpoint_exception(ProgramState state);
        ProgramState builtin_invalid_range1_exception(ProgramState state);
        ProgramState builtin_invalid_range2_exception(ProgramState state);
        ProgramState builtin_invalid_enum_exception(ProgramState state);


 public:
        PNF(Array<String> args);
        ~PNF();


        String getProgram();
        void setProgram(char * program);

        Memory & getmem();
        void setmem(Memory & mem);


        void crash(String str);


        void load();
        void loads2();
        void loads3();
        void preprocess();
        void check();
        String execute();
};


String PNF::get_extension(String fileName)
{
 unsigned long index = fileName.getString().find(".");
 if (index == string::npos)
  crash((char *)"File has No Extension.");

 String extension = fileName.getString().substr(index);


 return extension;
}

String PNF::strip_extension(String fileName)
{
 unsigned long index = fileName.getString().find(".");
 if (index == string::npos)
  crash((char *)"File has No Extension.");

 String stripped = fileName.getString().substr(0, index);


 return stripped;
}

PNF::PNF(Array<String> args)
{
 reg.icount = 0;
 reg.instruction = 0;
 reg.type = 0;
 reg.operand = 0;
 reg.type_of = (char *)"UNKNOWN"; // Initialized to UNKNOWN Value.

 reg.iname = args[0];
 for (unsigned long i = 1, j = 0; i < args.length(); ++i, ++j)
 {
  reg.args[j] = args[i];
  reg.args.insert();
 }
 reg.args.remove(reg.args.length() - 1);


 static PNF_Basic_Object2 temp;
 
 reg.accumulator.object(temp);

 reg.calc.object(temp);


 reg.aoffset = -1;
 reg.aoffset2 = 0;

 reg.inarray = false;
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
 reg.accumulator.object().simple().print();
 cout << endl;
 cout << "%calc                = ";
 reg.calc.object().simple().print();
 cout << endl;
 cout << "%iname               = " << reg.iname;
 cout << "\n\n";


 for (unsigned long i = 0; i < mem.length(); ++i)
  cout << "memory[" << i << "]: " << mem.get(i) << " extrai: " << reg.extrai.get(i) << endl;
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
 if (extension != (char *)".pnf" && extension != (char *)".pppnf")
  crash((char *)"Program has Invalid Extension.");

 if (extension == (char *)".pppnf")
  preprocess();
  
 fin.open((strip_extension(reg.args.get(0)) + (char *)".pnf").getString().c_str());
 if (!fin)
  crash((char *)"Program Not Found or File Not Readable.");
  

 String signature = (char *)"!@.PNF";
 String str = "";
 fin >> str;

 if (str == (char *)"")
  crash((char *)"Program Not Found or File Empty.");


 if (str == signature)
 {
  double num = 0;

  unsigned long i;
  for (i = 0; fin >> num; ++i)
  {
   mem.put(i, num);
   reg.extrai.put(i, 0);
  }
  reg.ecount = i;
 }
 else
  crash((char *)"Wrong Signature.");

 fin.close();


 // Load extra info for ifs...
 unsigned long ifcounter = 0;
 for (unsigned long i = 0; i != reg.ecount; i += 3)
 {
  if (mem.get(i + 1) == TSTRING)
  {
   unsigned long is = 0;
   for (is = i + 2; mem.get(is) != 0; ++is)
    ;
   ++is;
   i = is;
   i -= 3;
   continue;
  }

  if (mem.get(i) == IIF || mem.get(i) == IENDIF || mem.get(i) == IIFELSE || mem.get(i) == IENDIFELSE || mem.get(i) == IEIF)
  {
   if (mem.get(i) == IIF)
   {
     ++ifcounter;
     reg.inif.insert();
   }
  }
 }

 // Load extra info for switches...
 unsigned long switchcounter = 0;
 for (unsigned long i = 0; i != reg.ecount; i += 3)
 {
  if (mem.get(i + 1) == TSTRING && mem.get(i) != ISWITCH2)
  {
   unsigned long is = 0;
   for (is = i + 2; mem.get(is) != 0; ++is)
    ;
   ++is;
   i = is;
   i -= 3;
   continue;
  }

  if (mem.get(i) == ISWITCH2)
  {
    ++switchcounter;
  }
 }
}

void PNF::loads2()
{
 if (mem.get(0) != IVERSION)
  crash((char *)"Version Unkown.");
 if (mem.get(reg.ecount - 3) != IEND)
  crash((char *)"No END Instruction.");

 // Put the address of the variables in varcount.
 for (unsigned long j = 0, k = 0; j != reg.ecount; ++j)
 {
  if (mem.get(j) == IVAR)
  {
   reg.varcount[k].address(j + 2);
   reg.varcount[k].type(mem.get(j + 1));
   reg.varcount.insert();
   ++k;
  }
 }

 for (unsigned long j = 0, k = 0; j != reg.ecount; ++j)
 {
  if (mem.get(j) == ILBL && mem.get(j + 1) == TVOID && mem.get(j + 2) == 0)
  {
   Label l(j + 3, (char *)"");
   reg.labels.put(l, k);
   reg.labels.insert();
   ++k;
  }
  else if (mem.get(j) == ILBL && mem.get(j + 1) == TSTRING)
  {
   Label l2;
   String temp = (char *)"";
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

void PNF::preprocess()
{
 #ifdef OS_WINDOWS 
 _spawnl(_P_WAIT, "pnfpp.exe", "pnfpp.exe", (strip_extension(reg.args[0]) + (char *)".pppnf").getString().c_str(), 
 		 (strip_extension(reg.args[0]) + (char *)".pnf").getString().c_str(), NULL);
 #endif // OS_WINDOWS
 #ifdef OS_LINUX
 String str = (char *)"pnfpp " + (strip_extension(reg.args[0]) + (char *)".pppnf") + (strip_extension(reg.args[0]) + (char *)".pnf");
 system(str.getString().c_str());
 #endif // OS_LINUX
}

void PNF::check()
{
 // Not implemented yet.
}

String PNF::execute()
{
 try
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

 reg.sversion.insert();
 reg.sversion[1].base.put(v);
 reg.sversion[1].top = 1;

 // Modes
 PNF_Void m;
 reg.mode.base.put(m);
 reg.mode.top = 0;

  // Load the supported modes..
 reg.smode[0].base.put(m);
 reg.smode[0].top = 0;

 // EXT Modes
 PNF_Void m2;
 reg.extmode.base.put(m2);
 reg.extmode.top = 0;

  // Load the supported EXT Modes...
 reg.sextmode[0].base.put(m2);
 reg.sextmode[0].top = 0;



  // Load the supported instructions...
  for (unsigned long is = 0; is <= IENDI - 1; ++is)
  {
   if (is != 0)
    reg.sinstruction.insert();

   reg.sinstruction[is] = is;
  }

  // Load the supported types...
  for (unsigned long is = 0; is <= TENDT; ++is)
  {
   if (is != 0)
    reg.stype.insert();

   reg.stype[is] = is;
  }

  // Load fimode and fomode
  reg.fimode = FMIN;
  reg.fomode = FMOUT;

  // Load the previous instruction register
  reg.pinstruction = -1;

  // Load the saved instruction registers
  reg.savins = -1;
  reg.savins2 = -1;

  // Load the preperation registers
  reg.rt2prep = -1;
  reg.eprep = -1;

  // Load the usingarray register
  reg.usingarray = false;

  // Load the aoffset3 register
  reg.aoffset3 = 0;
  
  // Set up quit register
  reg.quit = false;

  // Set up ifs...
  reg.ifindex = 0;
  reg.ifscope = 0;
  reg.ifcounter = 0;
  reg.ifcond = false;
  reg.eifsave = 0;

 // Set up the function pointers...
 reg.fpointer1c = 0;
 reg.fpointer1c2 = 0;
 reg.fpointer2 = NULL;
 reg.fpointer3 = NULL;
 reg.fname = (char *)"";
 reg.fname2 = (char *)"";
 reg.pnum = 0;
 reg.rnum = 0;

 reg.infunc = false;
 reg.infuncc = 0;

 reg.inparams = false;
 reg.inparamsc = 0;

 reg.fdefaultv = false;
 
 // Set up structs
 reg.struct_type = "";
 reg.struct_name = "";

 // Set up unions
 reg.union_type = "";
 reg.union_name = "";


 
  
 // First pass of execution
 // Purpose is to prepare ifs
 for (unsigned long i = 0, j = 1, k = 2; !reg.quit; i += 3, j += 3, k += 3)
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
   case IEND:
   {
   	reg.quit = true;
   }
   break;
   
   
   default:
    if (reg.type == TSTRING)
   	{
   	 while (mem.get(k) != 0)
   	  ++k;
   	 i = k + 1;
   	 j = i + 1;
   	 k = i + 2;
   	 
   	 i -= 3, j -= 3, k -= 3;
   	}
   	break;
  }
 }
 
 
 // Reset registers
 reg.icount = 0;
 reg.quit = false;

 // Set up ifs...
 reg.ifindex = 0;
 reg.ifscope = 0;
 reg.ifcond = false;
 reg.eifsave = 0;

// Set up switches...
reg.switchindex = 0;
 
  
 // Second pass of execution
 // Purpose is to prepare ifs
 for (unsigned long i = 0, j = 1, k = 2; !reg.quit; i += 3, j += 3, k += 3)
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
   case IIF:
   {
    if (reg.ninstruction != IIFBEGIN)
     crash((char *)"Invalid IF.");


   ++reg.ifcounter;    
   for (unsigned long is = 0; is != reg.ecount; is += 3)
   {
    if (mem.get(is + 1) == TSTRING)
    {
     unsigned long is2 = 0;
     for (is2 = is + 2; mem.get(is2) != 0; ++is2)
      ;
     ++is2;
     is = is2;
     is -= 3;
     continue;
    }

    if (mem.get(is) == IIF || mem.get(is) == IENDIF || mem.get(is) == IIFELSE || mem.get(is) == IENDIFELSE || mem.get(is) == IEIF)
    {
     if (reg.extrai.get(is) == reg.ifcounter)
     {
      ++reg.ifcounter;
      reg.ifcond = true;
      reg.eifsave = reg.ifcounter;
      break;
     }
    }
   }

    reg.extrai.put(i, reg.ifcounter);
    reg.inif[reg.extrai.get(i)].type.ifb = i;
   }
   break;
   
   case IENDIF:
   {
    if (mem.get(i - 3) != IIFEND)
     crash((char *)"Invalid IF.");

    reg.extrai.put(i, reg.ifcounter);
    reg.inif[reg.extrai.get(i)].type.endif = i;
   }
   break;
   
   case IIFELSE:
   {
    if (reg.ninstruction != IIFBEGIN)
     crash((char *)"Invalid ELSE.");

    reg.extrai.put(i, reg.ifcounter);
    reg.inif[reg.extrai.get(i)].type.elseb = i;
   }
   break;
   
   case IENDIFELSE:
   {
    if (mem.get(i - 3) != IIFEND)
     crash((char *)"Invalid ELSE.");

    reg.extrai.put(i, reg.ifcounter);
    reg.inif[reg.extrai.get(i)].type.endelse = i;
   }
   break;
   
   case IEIF:
   {  
    reg.extrai.put(i, reg.ifcounter);

    reg.inif[reg.extrai.get(i)].type.eif = i;
    ++reg.ifindex;

    if (reg.ifcond == true && reg.eifsave == reg.ifcounter)
    {
     reg.ifcond = false;
     --reg.ifcounter;
    }
    --reg.ifcounter;
   }
   break;

   case IIFBEGIN:
   {
    ++reg.ifscope;
    reg.inif[reg.extrai.get(i)].type.scope = reg.ifscope;
   }
   break;

   case IIFEND:
   {
    --reg.ifscope;
    reg.inif[reg.extrai.get(i)].type.scope = reg.ifscope;
   }
   break;
   
   case IEND:
   {
   	reg.quit = true;
   }
   break;
   
   
   default:
    if (reg.type == TSTRING)
   	{
   	 while (mem.get(k) != 0)
   	  ++k;
   	 i = k + 1;
   	 j = i + 1;
   	 k = i + 2;
   	 
   	 i -= 3, j -= 3, k -= 3;
   	}
   	break;
  }
  
  
  // Load the previous instruction register
  reg.pinstruction = reg.instruction;
  reg.pins = reg.mins;  
 }
 
 
 // Reset registers
 reg.icount = 0;

 // Set up ifs...
 reg.ifindex = 0;
 reg.ifscope = 0;
 reg.ifcond = false;
 reg.eifsave = 0;

 // Set up switches...
 reg.switchcond = false;
 reg.switcht = false;

 
 // Last pass of execution
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
          PNF_Void v;
          reg.version.base.put(v);
          
	  switch (reg.operand)
	  {
	   case 0: // 0V
               if (reg.operand != 0)
                crash((char *)"Invalid VOID Value.");
               else
               {               	
               	reg.version.top = 0;
               }
	  break;

	  case 1:	   
	   reg.version.top = 1;


          if (reg.iname == (char *)"(COMPILED)")
          {
           // Load extra info for ifs...
           unsigned long ifcounter = 0;
           for (unsigned long i = 0; i != reg.ecount; i += 3)
           {
            if (mem.get(i + 1) == TSTRING)
            {
             unsigned long is = 0;
             for (is = i + 2; mem.get(is) != 0; ++is)
              ;
            ++is;
            i = is;
            i -= 3;
            continue;
           }

           if (mem.get(i) == IIF || mem.get(i) == IENDIF || mem.get(i) == IIFELSE || mem.get(i) == IENDIFELSE || mem.get(i) == IEIF)
           {
            if (mem.get(i) == IIF)
            {
             ++ifcounter;
             reg.inif.insert();
            }
           }
          }

          // Load extra info for switches...
          unsigned long switchcounter = 0;
          for (unsigned long i = 0; i != reg.ecount; i += 3)
          {
           if (mem.get(i + 1) == TSTRING && mem.get(i) != ISWITCH2)
           {
            unsigned long is = 0;
            for (is = i + 2; mem.get(is) != 0; ++is)
             ;
            ++is;
            i = is;
            i -= 3;
            continue;
           }

           if (mem.get(i) == ISWITCH2)
           {
            ++switchcounter;
           }
          }
         }
	}        
         break;

         default:
               crash((char *)"Invalid Type.");
        };
        break;

   case IVOID:
        switch (reg.type)
        {
         case TVOID:
               if (reg.operand != 0)
                crash((char *)"Invalid VOID Value.");
               else
                ; // Does Nothing...
               break;

         default:
               crash((char *)"Invalid Type.");
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
                 crash((char *)"Invalid Type.");
                 break;
        }
        break;

   case IQUIT:
   {
    PNF_Void v;
    bool s = reg.version.check(v, 1);

    if (s == false)
    {   
        switch (reg.type)
        {
         case TVOID:
          quitValue = reg.operand;
          quitFound = true;
          break;

         default:
          crash((char *)"Invalid Type.");
        }
   }
   else
   {
    PNF_Boolean b;
    for (unsigned long is = 0; is < reg.sinstruction.length(); ++is)
    {
     bool icheck = false;

     if (reg.sinstruction[is] == IPNFRUN)
     {
      icheck = true;
      b.put(icheck);
      break;
     }
     else
     {
      icheck = false;
      b.put(icheck);
     }
    }

    if (b.get() == "false")
     crash((char *)"PNFRUN Not Supported.");
     
     
     switch (reg.type)
        {
         case TVOID:
          quitValue = reg.operand;
          quitFound = true;
          break;
          
         case TNUMBER:
         {
          if (reg.operand != 0)
           crash((char *)"Invalid QUIT instruction.");
           
          quitValue = (int)reg.accumulator.object().simple().to_number().get();
          quitFound = true;
         }
         break;

         default:
          crash((char *)"Invalid Type.");
        }
   }
  }
  break;


   case IHALT:
        switch (reg.type)
        {
         case TVOID:
              if (reg.operand != 0)
               crash((char *)"Invalid VOID Value.");
              else
               for (;;)
                ;

         default:
          crash((char *)"Invalid Type.");
          break;
        };

   case IPRINT:
   {
        switch (reg.type)
        {
         case TVOID:
         {
          if (reg.operand != 0)
           crash((char *)"Invalid VOID Value.");
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
          crash((char *)"Invalid Type.");
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
               crash((char *)"Invalid VOID Value.");
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
          crash((char *)"Invalid Type.");
          break;
        };
   }
   break;

   case IREAD:
        reg.accumulator.object().simple().setType(reg.type);

        if (reg.operand != 0)
         crash((char *)"Invalid Parameter.");
        else
        {
         reg.accumulator.object().simple().read();
        }

        break;

   case ILOAD:
        {
         double m;
         double * pm;


         reg.accumulator.object().simple().setType(reg.type);

         switch (reg.accumulator.object().simple().getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.operand);
               pm = &m;

               reg.accumulator.object().simple().putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.operand);
               pm = &m;

               reg.accumulator.object().simple().putm(pm);
               break;

          case TCHARACTER:
               pm = &m;
               *pm = mem.get(reg.operand);
               reg.accumulator.object().simple().putm(pm);
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
               reg.accumulator.object().simple().put(str2);
          }
          break;

          default:
           crash((char *)"Invalid Type.");
           break;
         }
         break;
        }

   case ISTORE:
        {
         if (reg.type != 0)
          crash((char *)"Invalid Type Identifier.");

         double * pm;
         pm = reg.accumulator.object().simple().getm();

         switch (reg.accumulator.object().simple().getType())
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
           crash((char *)"Invalid Type.");
         }
        }
        break;

   case ILOADC:
        {
         double m;
         double * pm;


         reg.calc.object().simple().setType(reg.type);

         switch (reg.calc.object().simple().getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.operand);
               pm = &m;

               reg.calc.object().simple().putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.operand);
               pm = &m;

               reg.calc.object().simple().putm(pm);
               break;

          case TCHARACTER:
               pm = &m;
               *pm = mem.get(reg.operand);
               reg.calc.object().simple().putm(pm);
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
               reg.calc.object().simple().put(str2);
          }
          break;

          default:
           crash((char *)"Invalid Type.");
           break;
         }
         break;
        }

   case ISTOREC:
        {
         if (reg.type != 0)
          crash((char *)"Invalid Type Identifier.");

         double * pm;
         pm = reg.calc.object().simple().getm();

         switch (reg.calc.object().simple().getType())
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
           crash((char *)"Invalid Type.");
         }
        }
        break;

   case IELOAD:
        {
         double m;
         double * pm;


         reg.accumulator.object().simple().setType(reg.type);

         switch (reg.accumulator.object().simple().getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.ecount);
               pm = &m;

               reg.accumulator.object().simple().putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.ecount);
               pm = &m;

               reg.accumulator.object().simple().putm(pm);
               break;

          case TCHARACTER:
               pm = &m;
               *pm = mem.get(reg.ecount);
               reg.accumulator.object().simple().putm(pm);
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
               reg.accumulator.object().simple().put(str2);
          }
          break;

          default:
           crash((char *)"Invalid Type.");
           break;
         }
         break;
        }

   case IESTORE:
        {
         if (reg.operand != 0)
          crash((char *)"Invalid Operand.");
         if (reg.type != 0)
          crash((char *)"Invalid Type Identifier.");

         double * pm;
         pm = reg.accumulator.object().simple().getm();

         switch (reg.accumulator.object().simple().getType())
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
           crash((char *)"Invalid Type.");
         }
        }
        break;

   case IELOADC:
        {
         double m;
         double * pm;


         reg.calc.object().simple().setType(reg.type);

         switch (reg.calc.object().simple().getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.ecount);
               pm = &m;

               reg.calc.object().simple().putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.ecount);
               pm = &m;

               reg.calc.object().simple().putm(pm);
               break;

          case TCHARACTER:
               pm = &m;
               *pm = mem.get(reg.ecount);
               reg.calc.object().simple().putm(pm);
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
               reg.calc.object().simple().put(str2);
          }
          break;

          default:
           crash((char *)"Invalid Type.");
           break;
         }
         break;
        }

case IESTOREC:
        {
         if (reg.operand != 0)
          crash((char *)"Invalid Operand.");
         if (reg.type != 0)
          crash((char *)"Invalid Type Identifier.");

         double * pm;
         pm = reg.calc.object().simple().getm();

         switch (reg.calc.object().simple().getType())
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
           crash((char *)"Invalid Type.");
         }
        }
        break;

  case IVLOAD:
        {
         double m;
         double * pm;


         reg.accumulator.object().simple().setType(reg.type);
         reg.operand = reg.varcount.get(reg.operand).address();

         switch (reg.accumulator.object().simple().getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.operand);
               pm = &m;

               reg.accumulator.object().simple().putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.operand);
               pm = &m;

               reg.accumulator.object().simple().putm(pm);
               break;

          case TCHARACTER:
               pm = &m;
               *pm = mem.get(reg.operand);
               reg.accumulator.object().simple().putm(pm);
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
               reg.accumulator.object().simple().put(str2);
          }
          break;

          default:
           crash((char *)"Invalid Type.");
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
            crash((char *)"Invalid Operand.");

           long j = reg.ecount;
           mem.put(j, IVAR);
           mem.put(j + 1, TVOID);
           double * pm;
           pm = reg.accumulator.object().simple().getm();


           reg.varcount.insert();
           reg.varcount.put(j + 2, reg.varcount.length() - 1);

           switch (reg.accumulator.object().simple().getType())
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
             mem.put((j + 2) + i, 0);
             reg.ecount += 3;
             break;


            default:
             crash((char *)"Invalid Type.");
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
           long j = reg.varcount.get(reg.operand).address();
           double * pm;
           pm = reg.accumulator.object().simple().getm();

           switch (reg.accumulator.object().simple().getType())
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
             crash((char *)"Invalid Type.");
            }
           }
           break;

           default:
            crash((char *)"Invalid Type Identifier.");
            break;
          }
         }
         break;

  case IVLOADC:
        {
         double m;
         double * pm;


         reg.calc.object().simple().setType(reg.type);
         reg.operand = reg.varcount.get(reg.operand).address();

         switch (reg.calc.object().simple().getType())
         {
          case TBOOLEAN:
               m = mem.get(reg.operand);
               pm = &m;

               reg.calc.object().simple().putm(pm);
               break;

          case TNUMBER:
               m = mem.get(reg.operand);
               pm = &m;

               reg.calc.object().simple().putm(pm);
               break;

          case TCHARACTER:
               pm = &m;
               *pm = mem.get(reg.operand);
               reg.calc.object().simple().putm(pm);
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
               reg.calc.object().simple().put(str2);
          }
          break;

          default:
           crash((char *)"Invalid Type.");
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
            crash((char *)"Invalid Operand.");

           long j = reg.ecount;
           mem.put(j, IVAR);
           mem.put(j + 1, TVOID);
           double * pm;
           pm = reg.calc.object().simple().getm();


           reg.varcount.insert();
           reg.varcount.put(j + 2, reg.varcount.length() - 1);

           switch (reg.calc.object().simple().getType())
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
             crash((char *)"Invalid Type.");
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
           long j = reg.varcount.get(reg.operand).address();
           double * pm;
           pm = reg.calc.object().simple().getm();

           switch (reg.calc.object().simple().getType())
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
             crash((char *)"Invalid Type.");
            }
           }
           break;

           default:
            crash((char *)"Invalid Type Identifier.");
            break;
          }
         }
         break;

   case ISTOREA:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid STOREA instruction.");

   	unsigned long address = (unsigned long)reg.calc.object().simple().to_number().get();
   	String str = reg.accumulator.object().simple().to_string().get();
   	
   	unsigned long j = address;
   	for (unsigned long i = 0; i < str.length(); ++i, ++j)
   	 mem.put(j, (unsigned long)str[i]);
   	mem.put(j, 0);
   }
   break;

   case IMODT:
        {
         if (reg.operand == 0)
          reg.accumulator.object().simple().setType(reg.type);
         else
          crash((char *)"Invalid Operand.");
        }
        break;

   case IMODCT:
        {
         if (reg.operand == 0)
          reg.calc.object().simple().setType(reg.type);
         else
          crash((char *)"Invalid Operand.");
        }
        break;

   case IADD:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           switch (reg.accumulator.object().simple().getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.object().simple().to_number();
             tn.add(reg.calc.object().simple().to_number().get());
             reg.accumulator.object().simple().put(tn);
             break;
            }

            case TSTRING:
            {
             PNF_String ts = reg.accumulator.object().simple().to_string();
             ts.add(reg.calc.object().simple().to_string().get());
             reg.accumulator.object().simple().put(ts);
             break;
            }

            default:
             crash((char *)"Invalid ADD Instruction.");
             break;
           }
          }
          else
           crash((char *)"Invalid ADD Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            reg.accumulator.object().simple().to_number().add(reg.operand);
           }
           break;

           case TCHARACTER:
            reg.accumulator.object().simple().to_character().add(reg.operand);
            break;

           case TSTRING:
           {
            unsigned long i2 = 0;
            for (i2 = k; mem.get(i2) != 0; ++i2)
             reg.accumulator.object().simple().to_character().add((char)mem.get(i2));
            i = i2;
            j = i + 1;
            k = i + 2;
           }
           break;

           default:
            crash((char *)"Invalid ADD Instruction.");
          }
         }
        }
        break;

   case ISUB:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           switch (reg.accumulator.object().simple().getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.object().simple().to_number();
             tn.sub(reg.calc.object().simple().to_number().get());
             reg.accumulator.object().simple().put(tn);
             break;
            }

            default:
             crash((char *)"Invalid SUB Instruction.");
             break;
           }
          }
          else
           crash((char *)"Invalid SUB Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.object().simple().to_number().sub(reg.operand);
            break;

           default:
            crash((char *)"Invalid SUB Instruction.");
          }
         }
         break;
        }

   case IMUL:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           switch (reg.accumulator.object().simple().getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.object().simple().to_number();
             tn.mul(reg.calc.object().simple().to_number().get());
             reg.accumulator.object().simple().put(tn);
             break;
            }

            default:
             crash((char *)"Invalid MUL Instruction.");
             break;
           }
          }
          else
           crash((char *)"Invalid MUL Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.object().simple().to_number().mul(reg.operand);
            break;

           default:
            crash((char *)"Invalid MUL Instruction.");
          }
         }
         break;
        }

   case IDIV:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           switch (reg.accumulator.object().simple().getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.object().simple().to_number();
             tn.div(reg.calc.object().simple().to_number().get());
             reg.accumulator.object().simple().put(tn);
             break;
            }

            default:
             crash((char *)"Invalid DIV Instruction.");
             break;
           }
          }
          else
           crash((char *)"Invalid DIV Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.object().simple().to_number().div(reg.operand);
            break;

           default:
            crash((char *)"Invalid DIV Instruction.");
          }
         }
         break;
        }

        case IMOD:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           switch (reg.accumulator.object().simple().getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.object().simple().to_number();
             tn.mod(reg.calc.object().simple().to_number().get());
             reg.accumulator.object().simple().put(tn);
             break;
            }

            default:
             crash((char *)"Invalid MOD Instruction.");
             break;
           }
          }
          else
           crash((char *)"Invalid MOD Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.object().simple().to_number().sub(reg.operand);
            break;

           default:
            crash((char *)"Invalid MOD Instruction.");
          }
         }
         break;
        }

   case IPOW:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           switch (reg.accumulator.object().simple().getType())
           {
            case TNUMBER:
            {
             PNF_Number tn = reg.accumulator.object().simple().to_number();
             tn.pow(reg.calc.object().simple().to_number().get());
             reg.accumulator.object().simple().put(tn);
             break;
            }

            default:
             crash((char *)"Invalid POW Instruction.");
             break;
           }
          }
          else
           crash((char *)"Invalid POW Instruction.");
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.object().simple().to_number().pow(reg.operand);
            break;

           default:
            crash((char *)"Invalid POW Instruction.");
          }
         }
         break;
        }

   case IROOT:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          switch (reg.accumulator.object().simple().getType())
          {
           case TNUMBER:
           {
            PNF_Number tn = reg.accumulator.object().simple().to_number();
            tn.root(reg.accumulator.object().simple().to_number().get());
            reg.accumulator.object().simple().put(tn);
            break;
           }

           default:
            crash((char *)"Invalid ROOT Instruction.");
            break;
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
            reg.accumulator.object().simple().to_number().root(reg.operand);
            break;

           default:
            crash((char *)"Invalid ROOT Instruction.");
          }
         }
        }
        break;

   case IINC:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          switch (reg.accumulator.object().simple().getType())
          {
           case TNUMBER:
           {
            PNF_Number tn = reg.accumulator.object().simple().to_number();
            tn.inc(1);
            reg.accumulator.object().simple().put(tn);
            break;
           }

           default:
            crash((char *)"Invalid INC Instruction.");
            break;
          }
         }
         else
          crash((char *)"Invalid INC Instruction.");
        }
        break;

   case IDEC:
        {
         if (reg.operand == 0 && reg.type == 0)
         {
          switch (reg.accumulator.object().simple().getType())
          {
           case TNUMBER:
           {
            PNF_Number tn = reg.accumulator.object().simple().to_number();
            tn.dec(1);
            reg.accumulator.object().simple().put(tn);
            break;
           }

           default:
            crash((char *)"Invalid DEC Instruction.");
            break;
          }
         }
         else
          crash((char *)"Invalid DEC Instruction.");
        }
        break;

   case IEQU:
        {
         if (reg.type == TVOID && reg.operand == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           bool b = (reg.accumulator.object().simple().to_number().get() == reg.calc.object().simple().to_number().get());
           PNF_Boolean b2;
           b2.put(b);
           reg.accumulator.object().simple().put(b2);
          }
         }
         else
         {
          switch (reg.type)
          {
           case TBOOLEAN:
           {
             bool b = (reg.accumulator.object().simple().to_boolean().get().getString() == "true" ? true : false);
             bool b2 = (reg.operand == 0 ? false : true);
             bool b3 = b && b2;
             PNF_Boolean b4;
             b4.put(b3);
             reg.accumulator.object().simple().put(b4);
            }
            break;

           case TNUMBER:
           {
            bool b = (reg.accumulator.object().simple().to_number().get() == reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.object().simple().to_character().get() == (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           default:
            crash((char *)"Invalid Type.");
          }
         }
        }
        break;

   case INEQU:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           bool b = (reg.accumulator.object().simple().to_number().get() != reg.calc.object().simple().to_number().get());
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
          }
         }
         else
         {
          switch (reg.type)
          {
           case TBOOLEAN:
           {
             bool b = (reg.accumulator.object().simple().to_boolean().get().getString() != "true" ? true : false);
             bool b2 = (reg.operand == 0 ? false : true);
             bool b3 = b && b2;
             PNF_Boolean b4;
             b4.put(b3);
             reg.accumulator.object().simple().put(b4);
            }
            break;

           case TNUMBER:
           {
            bool b = (reg.accumulator.object().simple().to_number().get() != reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.object().simple().to_character().get() != (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           default:
            crash((char *)"Invalid Type.");
          }
         }
        }
        break;

   case IGTR:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           bool b = (reg.accumulator.object().simple().to_number().get() > reg.calc.object().simple().to_number().get());
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            bool b = (reg.accumulator.object().simple().to_number().get() > reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.object().simple().to_character().get() > (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           default:
            crash((char *)"Invalid Type.");
          }
         }
        }
        break;

   case ILSS:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           bool b = (reg.accumulator.object().simple().to_number().get() < reg.calc.object().simple().to_number().get());
           PNF_Boolean b2;
           b2.put(b);
           reg.accumulator.object().simple().put(b2);
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            bool b = (reg.accumulator.object().simple().to_number().get() < reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.object().simple().to_character().get() < (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           default:
            crash((char *)"Invalid Type.");
          }
         }
        }
        break;

   case IGEQU:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           bool b = (reg.accumulator.object().simple().to_number().get() >= reg.calc.object().simple().to_number().get());
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            bool b = (reg.accumulator.object().simple().to_number().get() >= reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.object().simple().to_character().get() >= (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           default:
            crash((char *)"Invalid Type.");
          }
         }
        }
        break;

   case ILEQU:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           bool b = (reg.accumulator.object().simple().to_number().get() <= reg.calc.object().simple().to_number().get());
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
          }
         }
         else
         {
          switch (reg.type)
          {
           case TNUMBER:
           {
            bool b = (reg.accumulator.object().simple().to_number().get() <= reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           case TCHARACTER:
           {
            bool b = (reg.accumulator.object().simple().to_character().get() <= (char)reg.operand);
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
           break;

           default:
            crash((char *)"Invalid Type.");
          }
         }
        }
        break;

   case IAND:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           bool b = (reg.accumulator.object().simple().to_boolean().get().getString() == "true" && reg.calc.object().simple().to_boolean().get().getString() == "true");
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
          }
         }
        }
        break;

        case IOR:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          if (reg.accumulator.object().simple().getType() == reg.calc.object().simple().getType())
          {
           bool b = (reg.accumulator.object().simple().to_boolean().get().getString() == "true" || reg.calc.object().simple().to_boolean().get().getString() == "true");
           if (b == true)
           {
            PNF_Boolean b2;
            b2.put(b);
            reg.accumulator.object().simple().put(b2);
           }
          }
         }
        }
        break;

        case INOT:
        {
	 PNF_Void v;
         bool s = reg.version.check(v, 1);

         if (s == true)
	 {
 	  PNF_Boolean b;
	  for (unsigned long is = 0; is < reg.sinstruction.length(); ++is)
   	  {
   	   bool icheck = false;

   	   if (reg.sinstruction[is] == ICMP)
   	   {
   	    icheck = true;
   	    b.put(icheck);
   	    break;
   	   }
   	   else
   	   {
   	    icheck = false;
   	    b.put(icheck);
   	   }
   	  }

	  if (b.get() == "false")
	   crash((char *)"CMP Not Supported.");

          if (reg.type == 0 && reg.operand == 0)
          {
	   PNF_Boolean b2;
           if (reg.accumulator.object().simple().to_boolean().get() == "true")
	   {
	    b2.put(false);
            reg.accumulator.object().simple().put(b2);
           }
           else
	   {
	    b2.put(true);
            reg.accumulator.object().simple().put(b2);
	   }
          }
	 }
	 else if (s == false)
	 {
	  if (reg.type == 0 && reg.operand == 0)
          {
	   PNF_Boolean b2;
           if (reg.accumulator.object().simple().to_boolean().get() == "true")
	   {
            reg.accumulator.object().simple().to_boolean().put(false);
           }
           else
	   {
            reg.accumulator.object().simple().to_boolean().put(true);
	   }
          }
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
         crash((char *)"Invalid GOTO.");
        break;

  case ICGOTO:
        if (reg.type == 0)
        {
         if (reg.accumulator.object().simple().to_boolean().get().getString() == "true")
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
         crash((char *)"Invalid CGOTO.");
        break;

   case IZGOTO:
        if (reg.accumulator.object().simple().to_number().get() == 0)
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
          crash((char *)"Invalid ZGOTO.");
        }
        break;

   case IPGOTO:
        if (reg.accumulator.object().simple().to_number().get() > 0)
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
          crash((char *)"Invalid PGOTO.");
        }
        break;

   case INGOTO:
        if (reg.accumulator.object().simple().to_number().get() < 0)
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
          crash((char *)"Invalid NGOTO.");
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
         String lblname = (char *)"";
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
         crash((char *)"Invalid GOTOL.");
        break;

  case ICGOTOL:
        if (reg.type == 0)
        {
         if (reg.accumulator.object().simple().to_boolean().get().getString() == "true")
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
         if (reg.accumulator.object().simple().to_boolean().get().getString() == "true")
         {
          String lblname = (char *)"";
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
         crash((char *)"Invalid CGOTOL.");
        break;

   case IZGOTOL:
        if (reg.accumulator.object().simple().to_number().get() == 0)
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
          String lblname = (char *)"";
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
          crash((char *)"Invalid ZGOTOL.");
        }
        break;

   case IPGOTOL:
        if (reg.accumulator.object().simple().to_number().get() > 0)
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
          String lblname = (char *)"";
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
          crash((char *)"Invalid PGOTOL.");
        }
        break;

   case INGOTOL:
        if (reg.accumulator.object().simple().to_number().get() < 0)
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
          String lblname = (char *)"";
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
          crash((char *)"Invalid NGOTOL.");
        }
        break;

   case IST:
        {
         if (reg.type == 0 && reg.operand == 0)
         {
          reg.calc.object().simple().to_number().dec(1);
          if (reg.calc.object().simple().to_number().get() == 0)
           reg.accumulator.object().simple().put(reg.calc.object().simple().to_number());
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
                   stk.push(reg.accumulator.object().simple());
                  }
                  break;

          default:
                  crash((char *)"Invalid PUSH.");
                  break;
         }
        }
        else
            crash((char *)"Invalid PUSH.");
        break;

       case IPOP:
        {
         if (reg.operand == 0)
         {
          switch (reg.type)
          {
           case TVOID:
           {
                   reg.accumulator.object().simple() = stk.top();
                   stk.pop();
                   break;
           }

           default:
                   crash((char *)"Invalid POP.");
                   break;
          }
         }
         else
             crash((char *)"Invalid POP.");
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
         crash((char *)"Invalid CALL.");
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
         String lblname = (char *)"";
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
         crash((char *)"Invalid CALLL.");
        break;

       case IRET:
        if (reg.type == 0 && reg.operand == 0)
        {
         PNF_Variable v = (substk.top());
         i = (unsigned long)v.to_number().get();
		 if (i == -1)
          crash((char *)"Could Not Return.");

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
         crash((char *)"Invalid RET.");

        break;


   case IVAR:
        {
         PNF_Void v;
         bool s = reg.version.check(v, 1);

	 try
	 {
	  if (s == true && reg.infunc == true)
	  {           
	   if (reg.operand != 0)
            crash((char *)"Invalid VAR instruction.");
	   
  	   ++reg.infuncc;
	   switch (reg.type)
	   {
	    case TVOID:
	    {
	     PNF_Void v2;
	     PNF_Variable v3(v2);

 	    reg.fpointer1.get_function(reg.fpointer1.length() - 1).ret(reg.infuncc - 1, v3);
 	    }
	    break;

	    case TBOOLEAN:
	    {
	     PNF_Boolean b(false);
	     PNF_Variable v2(b);

	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).ret(reg.infuncc - 1, v2);
	    }
	    break;

	    case TNUMBER:
	    {
	     PNF_Number n(0);
	     PNF_Variable v2(n);

	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).ret(reg.infuncc - 1, v2);
	    }
	    break;

	    case TCHARACTER:
	    {
	     PNF_Character c('\0');
	     PNF_Variable v2(c);

	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).ret(reg.infuncc - 1, v2);
	    }
	    break;

	    case TSTRING:
	    {
	     PNF_String str((char *)"");
	     PNF_Variable v2(str);

	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).ret(reg.infuncc - 1, v2);
	    }
	    break;

	    default:
	     crash((char *)"Invalid type.");
	   }
	   reg.fpointer1.get_function(reg.fpointer1.length() - 1).name(reg.fname);

           break;
          } else if (s == true && reg.inparams == true)
          {
 	   ++reg.inparamsc;
	   switch (reg.type)
	   {
	    case TVOID:
	    {
	     PNF_Void v;
	     PNF_Variable v2(v);
	     String str = (char *)"";

	     unsigned long is;
	     for (is = k; mem.get(is) != 0; ++is)
	      str += (char)mem.get(is);

	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).pname(reg.inparamsc - 1, str);
	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).param(reg.inparamsc - 1, v2);
	     i = is + 1;
             j = i + 1;
             k = j + 1;
	     i -= 3, j -= 3, k -= 3;
	    }
	    break;

	    case TBOOLEAN:
	    {
	     PNF_Boolean b;
	     PNF_Variable v(b);
	     String str = (char *)"";

	     unsigned long is;
	     for (is = k; mem.get(is) != 0; ++is)
	      str += (char)mem.get(is);

 	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).pname(reg.inparamsc - 1, str);
	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).param(reg.inparamsc - 1, v);
	     i = is + 1;
             j = i + 1;
             k = j + 1;
	     i -= 3, j -= 3, k -= 3;
	    }
	    break;

	    case TNUMBER:
	    {
	     PNF_Number n;
	     PNF_Variable v(n);
	     String str = (char *)"";

	     unsigned long is;
	     for (is = k; mem.get(is) != 0; ++is)
	      str += (char)mem.get(is);

	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).pname(reg.inparamsc - 1, str);
	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).param(reg.inparamsc - 1, v);
	     i = is + 1;
             j = i + 1;
             k = j + 1;
	     i -= 3, j -= 3, k -= 3;
	    }
	    break;

	    case TCHARACTER:
	    {
	     PNF_Character c;
	     PNF_Variable v(c);
	     String str = (char *)"";

	     unsigned long is;
	     for (is = k; mem.get(is) != 0; ++is)
	      str += (char)mem.get(is);

	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).pname(reg.inparamsc - 1, str);
	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).param(reg.inparamsc - 1, v);
	     i = is + 1;
             j = i + 1;
             k = j + 1;
	     i -= 3, j -= 3, k -= 3;
	    }
	    break;

	    case TSTRING:
	    {
	     PNF_String s;
	     PNF_Variable v(s);
	     String str = (char *)"";

	     unsigned long is;
	     for (is = k; mem.get(is) != 0; ++is)
	      str += (char)mem.get(is);

	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).pname(reg.inparamsc - 1, str);
	     reg.fpointer1.get_function(reg.fpointer1.length() - 1).param(reg.inparamsc - 1, v);
	     i = is + 1;
             j = i + 1;
             k = j + 1;
	     i -= 3, j -= 3, k -= 3;
	    }
	    break;


	    default:
	     crash((char *)"Invalid type.");
	   }
	   reg.fpointer1.get_function(reg.fpointer1.length() - 1).name(reg.fname);

 	   break;
	  }
	 }
	 catch (Exception e)
	 {
	  e.file((char *)__FILE__);
	  e.line(__LINE__);
	  e.display();
	  exit(1);
	 }

         if (reg.type == TSTRING)
         {
          // Skip the variable. Work done on loads2...
          unsigned is;
          for (is = k; mem.get(is) != 0; ++is)
           ;

          i = is + 1;
   	  j = i + 1;
          k = i + 2;

          i = i - 3;
          j = i + 1;
          k = i + 2;
	 }
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
           crash((char *)"Invalid VOID Value.");
          else
          {
           reg.accumulator.object().simple().eprint();
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
          crash((char *)"Invalid Type.");
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
               crash((char *)"Invalid VOID Value.");
              else
              {
               reg.accumulator.object().simple().eprintln();
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
          crash((char *)"Invalid Type.");
          break;
        };
   }
        break;

   case IEND:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash((char *)"Invalid END instruction.");
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
     crash((char *)"Invalid Type.");
    else
     reg.evalue = (unsigned long)reg.operand;
   }
   break;

   case IHEADD:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.hevents.add(reg.operand);
   }
   break;

   case IHEREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash((char *)"Invalid Type or Void Value.");
    else
     reg.hevents.remove();
   }
   break;

   case IHEED:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.hevents.edit(reg.evalue, reg.operand);
   }
   break;

   case IHEGET:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.evalue = reg.hevents.get(reg.operand);
   }
   break;

   case ISHEADD:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.shevents.add(reg.operand);
   }
   break;

   case ISHEREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash((char *)"Invalid Type or Void Value.");
    else
     reg.shevents.remove();
   }
   break;

   case ISHEED:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.shevents.edit(reg.evalue, reg.operand);
   }
   break;

   case ISHEGET:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.evalue = reg.shevents.get(reg.operand);
   }
   break;

   case IEADD:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.events.add(reg.operand);
   }
   break;

   case IEREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash((char *)"Invalid Type or Void Value.");
    else
     reg.events.remove();
   }
   break;

   case IEED:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.events.edit(reg.evalue, reg.operand);
   }
   break;

   case IEGET:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.evalue = reg.events.get(reg.operand);
   }
   break;

   case IEXADD:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.exceptions.add(reg.operand);
   }
   break;

   case IEXREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash((char *)"Invalid Type or Void Value.");
    else
     reg.exceptions.remove();
   }
   break;

   case IEXED:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
    {
     reg.exceptions.edit(reg.evalue, reg.operand);
    }
   }
   break;

   case IEXGET:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.evalue = reg.exceptions.get(reg.operand);
   }
   break;

   case IIADD:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.interrupts.add(reg.operand);
   }
   break;

   case IIREM:
   {
    if (reg.type != TVOID && reg.operand != 0)
     crash((char *)"Invalid Type or Void Value.");
    else
     reg.interrupts.remove();
   }
   break;

   case IIED:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
     reg.interrupts.edit(reg.evalue, reg.operand);
   }
   break;

   case IIGET:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
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
     crash((char *)"Invalid HEVENT.");
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
     crash((char *)"Invalid SHEVENT.");
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
     crash((char *)"Invalid EVENT.");
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
     crash((char *)"Invalid EXCEPTION.");
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
     crash((char *)"Invalid INT.");
   }
   break;

   case ITYPEOF:
   {
   	if (reg.type != TVOID && reg.operand != 0)
   	 crash((char *)"Invalid TYPEOF.");

   	long ttype = reg.accumulator.object().simple().getType();
   	String type;
   	switch (ttype)
   	{
   	 case TVOID:
   	  type = (char *)"VOID";
   	  break;

   	 case TBOOLEAN:
   	  type = (char *)"BOOLEAN";
   	  break;

   	 case TNUMBER:
   	  type = (char *)"NUMBER";
   	  break;

   	 case TCHARACTER:
   	  type = (char *)"CHARACTER";
   	  break;

   	 case TSTRING:
   	  type = (char *)"STRING";
   	  break;

   	 default:
   	  type = (char *)"UNKNOWN";
   	  break;
   	}
   	reg.type_of = type;
   }
   break;

   case ICTYPEOF:
   {
   	if (reg.type != TVOID && reg.operand != 0)
   	 crash((char *)"Invalid CTYPEOF.");

   	long ttype = reg.calc.object().simple().getType();
   	String type;
   	switch (ttype)
   	{
   	 case TVOID:
   	  type = (char *)"VOID";
   	  break;

   	 case TBOOLEAN:
   	  type = (char *)"BOOLEAN";
   	  break;

   	 case TNUMBER:
   	  type = (char *)"NUMBER";
   	  break;

   	 case TCHARACTER:
   	  type = (char *)"CHARACTER";
   	  break;

   	 case TSTRING:
   	  type = (char *)"STRING";
   	  break;

   	 default:
   	  type = (char *)"UNKNOWN";
   	  break;
   	}
   	reg.type_of = type;
   }
   break;

   case ITLOAD:
   {
   	if (reg.type != TVOID && reg.operand != 0)
   	 crash((char *)"Invalid TLOAD.");

   	reg.accumulator.object().simple().put(reg.type_of);
   }
   break;


   case IALOAD:
   {
    PNF_Void v;
    bool s = reg.version.check(v, 1);

    if (s == false)
    {
   	switch (reg.type)
   	{
   	 case TVOID:
   	 {
   	  if (reg.operand != 0)
   	   crash((char *)"Invalid VOID Value.");

   	  PNF_Void v;
   	  reg.accumulator.object().simple().put(v);
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
   	  reg.accumulator.object().simple().put(b);
   	 }
   	 break;

   	 case TNUMBER:
   	 {
   	  PNF_Number n(mem.get(k));
   	  reg.accumulator.object().simple().put(n);
   	 }
   	 break;

   	 case TCHARACTER:
   	 {
   	  PNF_Character c(reg.operand);
   	  reg.accumulator.object().simple().put(c);
   	 }
   	 break;

   	 case TSTRING:
   	 {
   	  String str = (char *)"";
   	  unsigned long is;
   	  for (is = k; mem.get(is) != 0; ++is)
   	  {
   	   str += (char)mem.get(is);
   	  }
   	  PNF_String s(str);
   	  reg.accumulator.object().simple().put(s);


      i = is + 1;
      j = i + 1;
      k = i + 2;

      i = i - 3;
      j = i + 1;
      k = i + 2;
   	 }
   	 break;

   	 default:
   	  crash((char *)"Invalid Type.");
   	  break;
   	}
    }
    else
    {
   	switch (reg.type)
   	{
   	 case TVOID:
   	 {
   	  if (reg.operand != 0)
   	   crash((char *)"Invalid VOID Value.");

   	  PNF_Void v;
   	  reg.accumulator.object().simple().put(v);
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
   	  reg.accumulator.object().simple().put(b);
   	 }
   	 break;

   	 case TNUMBER:
   	 {
   	  PNF_Number n(reg.operand);
   	  reg.accumulator.object().simple().put(n);
   	 }
   	 break;

   	 case TCHARACTER:
   	 {
   	  PNF_Character c(reg.operand);
   	  reg.accumulator.object().simple().put(c);
   	 }
   	 break;

   	 case TSTRING:
   	 {
   	  String str = (char *)"";
   	  unsigned long is;
   	  for (is = k; mem.get(is) != 0; ++is)
   	  {
   	   str += (char)mem.get(is);
   	  }
   	  PNF_String s(str);
   	  reg.accumulator.object().simple().put(s);


      i = is + 1;
      j = i + 1;
      k = i + 2;

      i = i - 3;
      j = i + 1;
      k = i + 2;
   	 }
   	 break;

   	 default:
   	  crash((char *)"Invalid Type.");
   	  break;
   	}
    }
   }
   break;


   case IINLOAD:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid INLOAD instruction.");

   	PNF_String s(reg.iname);
   	reg.accumulator.object().simple().put(s);
   }
   break;


   case IICLOAD:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid ICLOAD instruction.");

   	PNF_Number n(reg.icount);
   	reg.accumulator.object().simple().put(n);
   }
   break;


   case IARLOAD:
   {
   	if (reg.type != TVOID)
   	 crash((char *)"Invalid ARLOAD instruction.");

   	PNF_String s(reg.args.get(reg.operand));
   	reg.accumulator.object().simple().put(s);
   }
   break;


   case IATOC:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid ATOC instruction.");

   	reg.calc = reg.accumulator;
   }
   break;


   case ISWITCH:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid SWITCH instruction.");

   	PNF_Variable v = reg.accumulator.object().simple();
   	reg.accumulator = reg.calc;
   	reg.calc.object().simple() = v;
   }
   break;


   case IVADD:
   {
   	if (reg.type == TVOID)
   	{
   	PNF_Number n(reg.varcount.get(reg.operand).address());
   	reg.accumulator.object().simple().put(n);
    }
    else
     crash((char *)"Invalid VADD instruction.");
   }
   break;


   case ILADD:
   {
   	if (reg.type != 0)
   	 crash((char *)"Invalid LADD instruction.");

   	PNF_Number n(reg.labels.get(reg.operand).getNum());
   	reg.accumulator.object().simple().put(n);
   }
   break;


   case IELADD:
   {
   	if (reg.type != 0)
   	 crash((char *)"Invalid ELADD instruction.");

   	PNF_Number n(reg.elabels.get(reg.operand));
   	reg.accumulator.object().simple().put(n);
   }
   break;

   case IADD2V:
   {
   	if (reg.type == TVOID && reg.operand == 0)
   	{
   	 unsigned long address = (unsigned long)reg.accumulator.object().simple().to_number().get();
   	 double value = mem.get(address);

   	 PNF_Number n(value);
   	 reg.accumulator.object().simple().put(n);
   	}
   	else
   	 crash((char *)"Invalid ADD2V instruction.");
   }
   break;

   case IBTAND:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid BTAND instruction.");

   	unsigned long n1 = (unsigned long)reg.accumulator.object().simple().to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.object().simple().to_number().get();
   	unsigned long n3 = n1 & n2;
   	PNF_Number n(n3);
   	reg.accumulator.object().simple().put(n);
   }
   break;


   case IBTOR:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid BTOR instruction.");

   	unsigned long n1 = (unsigned long)reg.accumulator.object().simple().to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.object().simple().to_number().get();
   	unsigned long n3 = n1 | n2;
   	PNF_Number n(n3);
   	reg.accumulator.object().simple().put(n);
   }
   break;


   case IBTEXOR:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid BTEXOR instruction.");

   	unsigned long n1 = (unsigned long)reg.accumulator.object().simple().to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.object().simple().to_number().get();
   	unsigned long n3 = n1 ^ n2;
   	PNF_Number n(n3);
   	reg.accumulator.object().simple().put(n);
   }
   break;


   case IBTNOT:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid BTNOT instruction.");

   	unsigned long n1 = (unsigned long)reg.accumulator.object().simple().to_number().get();
   	unsigned long n3 = ~n1;
   	PNF_Number n(n3);
   	reg.accumulator.object().simple().put(n);
   }
   break;


   case IBTSL:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid BTSL instruction.");

   	unsigned long n1 = (unsigned long)reg.accumulator.object().simple().to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.object().simple().to_number().get();
   	unsigned long n3 = n1 << n2;
   	PNF_Number n(n3);
   	reg.accumulator.object().simple().put(n);
   }
   break;


   case IBTSR:
   {
   	if (reg.type != 0 || reg.operand != 0)
   	 crash((char *)"Invalid BTSR instruction.");

   	unsigned long n1 = (unsigned long)reg.accumulator.object().simple().to_number().get();
   	unsigned long n2 = (unsigned long)reg.calc.object().simple().to_number().get();
   	unsigned long n3 = n1 >> n2;
   	PNF_Number n(n3);
   	reg.accumulator.object().simple().put(n);
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
   	   reg.accumulator.object().simple().put(b);
   	  }
   	  else
   	  {
   	   vcheck = false;
   	   b.put(vcheck);
   	   reg.accumulator.object().simple().put(b);
   	  }
   	 }
   	 break;

   	 default:
   	 {
   	  vcheck = false;
   	  b.put(vcheck);
   	  reg.accumulator.object().simple().put(b);
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
        reg.accumulator.object().simple().put(b);
        goto endloop;
       }
   	   else
   	   {
        vcheck = false;
        b.put(vcheck);
        reg.accumulator.object().simple().put(b);
       }
   	  }
      break;

      default:
      {
       vcheck = false;
   	   b.put(vcheck);
   	   reg.accumulator.object().simple().put(b);
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
   	 crash((char *)"Invalid VPRINT instruction.");

   	reg.version.base.print();
   	cout << " " << reg.version.top;
   }
   break;

   case IVPRINTLN:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash((char *)"Invalid VPRINTLN instruction.");

   	reg.version.base.print();
   	cout << " " << reg.version.top << endl;
   }
   break;

   case IISUPP:
   {
   	if (reg.type != TNUMBER)
   	 crash((char *)"Invalid ISUPP instruction.");

   	for (unsigned long is = 0; is < reg.sinstruction.length(); ++is)
   	{
   	 bool icheck = false;
   	 PNF_Boolean b;

   	 if (reg.sinstruction[is] == reg.operand)
   	 {
   	  icheck = true;
   	  b.put(icheck);
   	  reg.accumulator.object().simple().put(b);
   	  break;
   	 }
   	 else
   	 {
   	  icheck = false;
   	  b.put(icheck);
   	  reg.accumulator.object().simple().put(b);
   	 }
   	}
   }
   break;

   case ITSUPP:
   {
   	if (reg.type != TNUMBER)
   	 crash((char *)"Invalid TSUPP instruction.");

   	for (unsigned long is = 0; is < reg.stype.length(); ++is)
   	{
   	 bool tcheck = false;
   	 PNF_Boolean b;

   	 if (reg.stype[is] == reg.operand)
   	 {
   	  tcheck = true;
   	  b.put(tcheck);
   	  reg.accumulator.object().simple().put(b);
   	  break;
   	 }
   	 else
   	 {
   	  tcheck = false;
   	  b.put(tcheck);
   	  reg.accumulator.object().simple().put(b);
   	 }
   	}
   }
   break;

   case ICOMMENT:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid COMMENT instruction.");
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
   	String str = (char *)"";

   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid FIMODE instruction.");
   	else
   	{
  	 unsigned long is = 0;
     for (is = k; mem.get(is) != 0; ++is)
      str += (char)mem.get(is);

     if (str == (char *)"in")
      reg.fimode = FMIN;
     else if (str == (char *)"binary")
      reg.fimode = FMBINARY;
     else
      crash((char *)"Invalid file input mode.");

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
   	String str = (char *)"";

   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid FOMODE instruction.");
   	else
   	{
  	 unsigned long is = 0;
     for (is = k; mem.get(is) != 0; ++is)
      str += (char)mem.get(is);

     if (str == (char *)"out")
      reg.fomode = FMOUT;
     else if (str == (char *)"binary")
      reg.fomode = FMBINARY;
     else if (str == (char *)"ate")
      reg.fomode = FMATE;
     else if (str == (char *)"app")
      reg.fomode = FMAPP;
     else if (str == (char *)"trunc")
      reg.fomode = FMTRUNC;
     else
      crash((char *)"Invalid file output mode.");

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
   	String str = (char *)"";
   	bool worked;

   	switch (reg.type)
   	{
   	 case TVOID:
   	 {
   	  if (reg.operand != 0)
   	   crash((char *)"Invalid FIOPEN instruction.");
   	  else
   	  {
   	   str = reg.accumulator.object().simple().to_string().get();
   	   switch (reg.fimode)
       {
        case FMIN:
         pnffin.open(str.getString().c_str(), ifstream::in);
         break;

        case FMBINARY:
         pnffin.open(str.getString().c_str(), ifstream::binary);
         break;

        default:
         crash((char *)"Invalid file input mode.");
       }
       worked = (pnffin.is_open());
       PNF_Boolean b(worked);
       reg.accumulator.object().simple().put(b);
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
        crash((char *)"Invalid file input mode.");
      }
      worked = (pnffin.is_open());
      PNF_Boolean b(worked);
      reg.accumulator.object().simple().put(b);

      i = is + 1;
      j = i + 1;
      k = i + 2;

      i = i - 3;
      j = i + 1;
      k = i + 2;
   	 }
   	 break;

   	 default:
   	  crash((char *)"Invalid FIOPEN instruction.");
   	}
   }
   break;

   case IFOOPEN:
   {
   	String str = (char *)"";
   	bool worked;

   	switch (reg.type)
   	{
   	 case TVOID:
   	 {
   	  if (reg.operand != 0)
   	   crash((char *)"Invalid file output mode.");
   	  else
   	  {
   	   str = reg.accumulator.object().simple().to_string().get();
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
         crash((char *)"Invalid file output mode.");
       }
       worked = (pnffout.is_open());
       PNF_Boolean b(worked);
       reg.accumulator.object().simple().put(b);
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
        crash((char *)"Invalid file output mode.");
      }
      worked = (pnffout.is_open());
      PNF_Boolean b(worked);
      reg.accumulator.object().simple().put(b);

      i = is + 1;
      j = i + 1;
      k = i + 2;

      i = i - 3;
      j = i + 1;
      k = i + 2;
   	 }
   	 break;

   	 default:
   	  crash((char *)"Invalid FOOPEN instruction.");
    }
   }
   break;

   case IFREAD:
   {
    reg.accumulator.object().simple().setType(reg.type);

    if (reg.operand != 0)
     crash((char *)"Invalid Parameter.");
    else
    {
     reg.accumulator.object().simple().fread(pnffin);
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
       crash((char *)"Invalid VOID Value.");
      else
      {
       reg.accumulator.object().simple().fprint(pnffout);
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
      crash((char *)"Invalid Type.");
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
       crash((char *)"Invalid VOID Value.");
      else
      {
       reg.accumulator.object().simple().fprint(pnffout);
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
      crash((char *)"Invalid Type.");
      break;
    };
	pnffout << endl;
   }
   break;

   case IFICLOSE:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash((char *)"Invalid FICLOSE instruction.");

   	pnffin.close();
   }
   break;

   case IFOCLOSE:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash((char *)"Invalid FOCLOSE instruction.");

   	pnffout.close();
   }
   break;

   case IMEML:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash((char *)"Invalid MEML instruction.");

   	PNF_Number n(mem.length());
   	reg.accumulator.object().simple().put(n);
   }
   break;

   case IFIEOF:
   {
   	bool eof = false;

   	if (reg.type != TVOID || reg.operand != 0)
   	 crash((char *)"Invalid FIEOF instruction.");

   	eofstate = pnffin.eof();
   	if (eofstate && eofstate2)
   	 eof = true;
   	else if (eofstate && !eofstate2)
   	{
   	 eof = false;
   	 eofstate2 = true;
   	}
   	PNF_Boolean b(eof);
   	reg.accumulator.object().simple().put(b);
   }
   break;

   case IARNLOAD:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash((char *)"Invalid ARNLOAD instruction.");


   	PNF_Number n(reg.args.length());
   	reg.accumulator.object().simple().put(n);
   }
   break;

   case IRDSTART1:
   {
    if (reg.type != TSTRING)
     crash((char *)"Invalid RDSTART1 instruction.");

	String name = (char *)"";
    unsigned long is = 0;
    for (is = k; mem.get(is) != 0; ++is)
     name += (char)mem.get(is);

    String n;
    for (unsigned long is = 0; is < reg.rt1defs.length(); ++is)
    {
     n = reg.rt1defs[is].name();
	 if (n == name)
	  crash((char *)"T1 Range already defined.");
    }

    if (reg.rt1defs.length() > 1)
     reg.rt1defs.insert();

    reg.rt1defs[reg.rt1defs.length() - 1].name(name);


    reg.savins = reg.mins;
    reg.savins2 = reg.mins;

    i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IRFROM1:
   {
   	if (mem.get(reg.savins) != IRDSTART1)
   	 crash((char *)"Bad T1 Range Definition.");

   	if (reg.type != TNUMBER)
   	 crash((char *)"Invalid RFROM1 instruction.");


   	// Get the name of the T1 range...
   	String name = (char *)"";
   	unsigned long is = reg.savins, js = is + 1, ks = is + 2;
   	for (unsigned long is2 = ks; mem.get(is2) != 0; ++is2)
   	 name += (char)mem.get(is2);


   	// Set the from value...
   	bool found = false;
   	unsigned long index = 0;
   	String n;
   	unsigned long is2;
    for (is2 = 0; is2 < reg.rt1defs.length(); ++is2)
    {
     n = reg.rt1defs[is2].name();
	 if (n == name)
	 {
	  found = true;
	  index = is2;
	  break;
	 }
    }

	if (found == true)
	{
	 reg.rt1defs[index].from(reg.operand);
	}
	else
	 crash((char *)"Bad T1 Range Definition.");

	reg.savins = reg.mins;
   }
   break;

   case IRTO1:
   {
   	if (mem.get(reg.savins) != IRFROM1)
   	 crash((char *)"Bad T1 Range Definition.");

   	if (reg.type != TNUMBER)
   	 crash((char *)"Invalid RTO1 instruction.");


   	// Get the name of the T1 range...
   	String name = (char *)"";
   	unsigned long is = reg.savins2, js = is + 1, ks = is + 2;
   	for (unsigned long is2 = ks; mem.get(is2) != 0; ++is2)
   	 name += (char)mem.get(is2);


   	// Set the from value...
   	bool found = false;
   	unsigned long index = 0;
   	String n;
   	unsigned long is2;
    for (is2 = 0; is2 < reg.rt1defs.length(); ++is2)
    {
     n = reg.rt1defs[is2].name();
	 if (n == name)
	 {
	  found = true;
	  index = is2;
	  break;
	 }
    }

	if (found == true)
	{
	 reg.rt1defs[index].to(reg.operand);
	}
	else
	 crash((char *)"Bad T1 Range Definition.");

	reg.savins = reg.mins;
   }
   break;

   case IRDEND1:
   {
   	if (mem.get(reg.savins) != IRTO1)
   	 crash((char *)"Bad T1 Range Definition.");

   	if (reg.type != TVOID && reg.operand != 0)
   	 crash((char *)"Invalid RDEND1 instruction.");

   	// Work already done. Just a marker.
   }
   break;

   case IRSTART1:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid RSTART1 instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	String n = (char *)"";
   	bool found = false;
   	unsigned long index = 0;
   	for (unsigned long is2 = 0; is2 < reg.rt1defs.length(); ++is2)
   	{
   	 n = reg.rt1defs[is2].name();

   	 if (n == name)
   	 {
   	  found = true;
   	  index = is2;
   	  break;
   	 }
   	}

   	if (found == true)
   	{
   	 if (reg.rt1vars.length() > 1)
   	  reg.rt1vars.insert();

   	 reg.rt1vars[reg.rt1vars.length() - 1].from(reg.rt1defs[index].from());
   	 reg.rt1vars[reg.rt1vars.length() - 1].to(reg.rt1defs[index].to());
   	}
   	else
   	 crash((char *)"Range not defined.");


    reg.savins = reg.mins;


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IRANGE1:
   {
   	if (mem.get(reg.savins) != IRSTART1)
   	 crash((char *)"Bad T1 Range implementation.");

   	if (reg.type != TNUMBER)
   	 crash((char *)"Invalid RANGE1 instruction.");

   	bool ret = reg.rt1vars[reg.rt1vars.length() - 1].put(reg.operand);


   	reg.savins = reg.mins;


   	// Execute invalid range1 Exception
    if (ret == false)
    {
     unsigned long address = 1;

     address = reg.exceptions.get(address);
     if (address != -1)
     {
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

      state = builtin_invalid_range1_exception(state);

      reg = state.reg;
      mem = state.mem;
      stk = state.stk;
     }
    }
   }
   break;

   case IREND1:
   {
   	if (mem.get(reg.savins) != IRANGE1)
   	 crash((char *)"Bad T1 Range implementation.");

   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid REND1 instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	reg.rt1vars[reg.rt1vars.length() - 1].name(name);


   	if (reg.usingarray == true)
   	{
   	 unsigned long index = reg.avars.length() - 1;
   	 reg.avars[index][reg.avars[index].length() - 1].t1range(reg.rt1vars[reg.rt1vars.length() - 1]);
   	 reg.rt1vars.remove();
   	}


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IRLOAD1:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid RLOAD1 instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	bool found = false;
   	unsigned long index = 0;
   	for (unsigned long is2 = 0; is2 < reg.rt1vars.length(); ++is2)
   	{
   	 String n = reg.rt1vars[is2].name();
   	 if (n == name)
   	 {
   	  found = true;
   	  index = is2;
   	  break;
   	 }
   	}

   	if (found == true)
   	{
   	 PNF_Number n = reg.rt1vars[index].get();
   	 reg.accumulator.object().simple().put(n);
   	}
   	else
   	 crash((char *)"Range not implemented.");


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IRSTORE1:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid RSTORE1 instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	bool found = false;
   	unsigned long index = 0;
   	for (unsigned long is2 = 0; is2 < reg.rt1vars.length(); ++is2)
   	{
   	 String n = reg.rt1vars[is2].name();
   	 if (n == name)
   	 {
   	  found = true;
   	  index = is2;
   	  break;
   	 }
   	}

   	PNF_Number n = reg.accumulator.object().simple().to_number();
   	bool ret;
   	if (found == true)
   	{
   	 ret = reg.rt1vars[index].put(n);
   	}
   	else
   	{
   	 crash((char *)"Range not implemented.");
   	}


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;


    // Execute invalid range1 Exception
    if (ret == false)
    {
     unsigned long address = 1;

     address = reg.exceptions.get(address);
     if (address != -1)
     {
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

      state = builtin_invalid_range1_exception(state);

      reg = state.reg;
      mem = state.mem;
      stk = state.stk;
     }
    }
   }
   break;

   case IHEADDB:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
    {
     for (unsigned long is = 1; is <= reg.operand; ++is)
      reg.hevents.add(-1);
    }
   }
   break;

   case ISHEADDB:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
    {
     for (unsigned long is = 1; is <= reg.operand; ++is)
      reg.shevents.add(-1);
    }
   }
   break;

   case IEADDB:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
    {
     for (unsigned long is = 1; is <= reg.operand; ++is)
      reg.events.add(-1);
    }
   }
   break;

   case IEXADDB:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
    {
     for (unsigned long is = 1; is <= reg.operand; ++is)
      reg.exceptions.add(-1);
    }
   }
   break;

   case IIADDB:
   {
    if (reg.type != TVOID)
     crash((char *)"Invalid Type.");
    else
    {
     for (unsigned long is = 1; is <= reg.operand; ++is)
      reg.interrupts.add(-1);
    }
   }
   break;

   case IRDSTART2:
   {
    if (reg.type != TSTRING)
     crash((char *)"Invalid RDSTART2 instruction.");

	String name = (char *)"";
    unsigned long is = 0;
    for (is = k; mem.get(is) != 0; ++is)
     name += (char)mem.get(is);

    String n;
    for (unsigned long is = 0; is < reg.rt2defs.length(); ++is)
    {
     n = reg.rt2defs[is].name();
	 if (n == name)
	  crash((char *)"T2 Range already defined.");
    }

    if (reg.rt2defs.length() > 1)
     reg.rt2defs.insert();

    reg.rt2defs[reg.rt2defs.length() - 1].name(name);


    reg.savins = reg.mins;
    reg.savins2 = reg.mins;

    i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IRFROM2:
   {
   	if (mem.get(reg.savins) != IRDSTART2)
   	 crash((char *)"Bad T2 Range Definition.");

   	if (reg.type != TNUMBER)
   	 crash((char *)"Invalid RFROM2 instruction.");


   	// Get the name of the T2 range...
   	String name = (char *)"";
   	unsigned long is = reg.savins, js = is + 1, ks = is + 2;
   	for (unsigned long is2 = ks; mem.get(is2) != 0; ++is2)
   	 name += (char)mem.get(is2);


   	// Set the from value...
   	bool found = false;
   	unsigned long index = 0;
   	String n;
   	unsigned long is2;
    for (is2 = 0; is2 < reg.rt1defs.length(); ++is2)
    {
     n = reg.rt2defs[is2].name();
	 if (n == name)
	 {
	  found = true;
	  index = is2;
	  break;
	 }
    }

	if (found == true)
	{
	 reg.rt2defs[index].from(reg.operand);
	}
	else
	 crash((char *)"Bad T2 Range Definition.");

	reg.savins = reg.mins;
   }
   break;

   case IRTO2:
   {
   	if (mem.get(reg.savins) != IRFROM2)
   	 crash((char *)"Bad T2 Range Definition.");

   	if (reg.type != TNUMBER)
   	 crash((char *)"Invalid RTO2 instruction.");


   	// Get the name of the T2 range...
   	String name = (char *)"";
   	unsigned long is = reg.savins2, js = is + 1, ks = is + 2;
   	for (unsigned long is2 = ks; mem.get(is2) != 0; ++is2)
   	 name += (char)mem.get(is2);


   	// Set the from value...
   	bool found = false;
   	unsigned long index = 0;
   	String n;
   	unsigned long is2;
    for (is2 = 0; is2 < reg.rt2defs.length(); ++is2)
    {
     n = reg.rt2defs[is2].name();
	 if (n == name)
	 {
	  found = true;
	  index = is2;
	  break;
	 }
    }

	if (found == true)
	{
	 reg.rt2defs[index].to(reg.operand);
	}
	else
	 crash((char *)"Bad T2 Range Definition.");

	reg.savins = reg.mins;
   }
   break;

   case IRDEND2:
   {
   	if (mem.get(reg.savins) != IRTO2)
   	 crash((char *)"Bad T2 Range Definition.");

   	if (reg.type != TVOID && reg.operand != 0)
   	 crash((char *)"Invalid RDEND2 instruction.");

   	// Work already done. Just a marker.
   }
   break;

   case IRSTART2:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid RSTART2 instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	String n = (char *)"";
   	bool found = false;
   	unsigned long index = 0;
   	for (unsigned long is2 = 0; is2 < reg.rt2defs.length(); ++is2)
   	{
   	 n = reg.rt2defs[is2].name();

   	 if (n == name)
   	 {
   	  found = true;
   	  index = is2;
   	  break;
   	 }
   	}

   	if (found == true)
   	{
   	 if (reg.rt2vars.length() > 1)
   	  reg.rt2vars.insert();

   	 reg.rt2vars[reg.rt2vars.length() - 1].from(reg.rt2defs[index].from());
   	 reg.rt2vars[reg.rt2vars.length() - 1].to(reg.rt2defs[index].to());
   	}
   	else
   	 crash((char *)"Range not defined.");


    reg.savins = reg.mins;


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IRANGE2:
   {
   	if (mem.get(reg.savins) != IRSTART2)
   	 crash((char *)"Bad T2 Range implementation.");

   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid RANGE2 instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	reg.rt2vars[reg.rt2vars.length() - 1].name(name);
   	bool ret = reg.rt2vars[reg.rt2vars.length() - 1].fill();


   	// Execute invalid range2 Exception
    if (ret == false)
    {
     unsigned long address = 2;

     address = reg.exceptions.get(address);
     if (address != -1)
     {
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

      state = builtin_invalid_range2_exception(state);

      reg = state.reg;
      mem = state.mem;
      stk = state.stk;
     }
    }


   	if (reg.usingarray == true)
   	{
   	 unsigned long index = reg.avars.length() - 1;
   	 reg.avars[index][reg.avars[index].length() - 1].t2range(reg.rt2vars[reg.rt2vars.length() - 1]);
   	 reg.rt2vars.remove();
   	}

   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IRPREP2:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid RPREP2 instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	bool found = false;
   	unsigned long index = 0;
   	for (unsigned long is2 = 0; is2 < reg.rt2vars.length(); ++is2)
   	{
   	 String n = reg.rt2vars[is2].name();
   	 if (n == name)
   	 {
   	  found = true;
   	  index = is2;
   	  break;
   	 }
   	}

   	if (found == true)
   	 reg.rt2prep = index;
   	else
   	 crash((char *)"T2 Range not defined.");


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IRLOAD2:
   {
   	if (reg.type != TNUMBER)
   	 crash((char *)"Invalid RLOAD2 instruction.");

	if (reg.rt2prep == -1)
	 crash((char *)"First do RPREP2...");

	if (reg.operand >= reg.rt2vars[reg.rt2prep].length())
	 crash((char *)"RLOAD index out of bounds.");

   	PNF_Number num = reg.rt2vars[reg.rt2prep].get(reg.operand);
   	reg.accumulator.object().simple().put(num);
   }
   break;

   case IESTART:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid ESTART instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	reg.eptr = 0;
   	reg.edefs[reg.edefs.length() - 1].name(name);


	reg.savins = reg.mins;


     i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IENAME:
   {
   	if (mem.get(reg.savins) != IESTART && mem.get(reg.savins) != IENAME)
   	 crash((char *)"Bad Enum definition.");

   	if (reg.type != TSTRING)
   	 crash ((char *)"Invalid ENAME instruction.");

	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);


   	reg.edefs[reg.edefs.length() - 1].set(reg.eptr, name);
   	++reg.eptr;


   	reg.savins = reg.mins;


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IEEND:
   {
   	if (mem.get(reg.savins) != IENAME)
   	 crash((char *)"Bad Enum definition.");

   	if (reg.type != TVOID || reg.operand != 0)
   	 crash((char *)"Invalid EEND instruction.");

   	if (reg.edefs.length() >= 1)
   	 reg.edefs.insert();
   }
   break;

   case IENUMS:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid ENUMS instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);


   	bool found = false;
   	unsigned long index = 0;
   	for (unsigned long is2 = 0; is2 < reg.edefs.length(); ++is2)
   	{
   	 String n = reg.edefs[is2].name();

   	 if (n == name)
   	 {
   	  found = true;
   	  index = is2;
   	 }
   	}

   	if (found == false)
   	 crash((char *)"Enum not defined.");
   	else
   	{
   	 reg.evars[reg.evars.length() - 1].names(reg.edefs[index].names());
    }


   	reg.savins = reg.mins;


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IENUM:
   {
   	if (mem.get(reg.savins) != IENUMS)
   	 crash((char *)"Bad Enum implementation.");

   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid ENUM instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	bool ret = reg.evars[reg.evars.length() - 1].value(name);


   	// Execute invalid enum Exception
    if (ret == false)
    {
     unsigned long address = 3;

     address = reg.exceptions.get(address);
     if (address != -1)
     {
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

      state = builtin_invalid_enum_exception(state);

      reg = state.reg;
      mem = state.mem;
      stk = state.stk;
     }
    }


   	reg.savins = reg.mins;


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case ISENUM:
   {
   	if (mem.get(reg.savins) != IENUM)
   	 crash((char *)"Bad Enum implementation.");

   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid SENUM instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	reg.evars[reg.evars.length() - 1].name(name);


   	if (reg.evars.length() >= 1)
   	  reg.evars.insert();


   	reg.savins = reg.mins;


   	if (reg.usingarray == true)
   	{
   	 unsigned long index = reg.avars.length() - 1;
   	 reg.avars[index][reg.avars[index].length() - 1].Enum(reg.evars[reg.evars.length() - 1]);
   	 reg.evars.remove();
   	}


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IEPREP:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid EPREP instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);

   	bool found = false;
   	unsigned long index = 0;
   	for (unsigned long is2 = 0; is2 < reg.evars.length(); ++is2)
   	{
   	 String n = reg.evars[is2].name();
   	 if (n == name)
   	 {
   	  found = true;
   	  index = is2;
   	  break;
   	 }
   	}

   	if (found == true)
   	 reg.eprep = index;
   	else
   	 crash((char *)"Enum not defined.");


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case ILOADE:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash((char *)"Invalid LOADE instruction.");

	if (reg.eprep == -1)
	 crash((char *)"First do EPREP");

   	String str = reg.evars[reg.eprep].value();
    PNF_String str2(str);
    reg.accumulator.object().simple().put(str2);
   }
   break;

   case ISTOREE:
   {
   	if (reg.type != TVOID || reg.operand != 0)
   	 crash((char *)"Invalid STOREE instruction.");

   	if (reg.eprep == -1)
	 crash((char *)"First do EPREP");

   	String str = reg.accumulator.object().simple().to_string().get();
   	bool ret = reg.evars[reg.eprep].value(str);


   	// Execute invalid enum Exception
    if (ret == false)
    {
     unsigned long address = 3;

     address = reg.exceptions.get(address);
     if (address != -1)
     {
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

      state = builtin_invalid_enum_exception(state);

      reg = state.reg;
      mem = state.mem;
      stk = state.stk;
     }
    }
   }
   break;

   case IASTART:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid ASTART instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);


   	reg.avars[reg.avars.length() - 1].name(name);


   	reg.savins = reg.mins;


   	reg.inarray = true;


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IAEND:
   {
   	if (mem.get(reg.savins) != IASTART)
   	 crash((char *)"Bad Array implementation.");

   	if (reg.type != TNUMBER)
   	 crash((char *)"Invalid AEND instruction.");

   	for (unsigned index = reg.avars.length() - 1, i = 0; i < reg.operand - 1; ++i)
   	 reg.avars[index].insert();

   	reg.avars.insert();
   	reg.avars[reg.avars.length() - 1].name((char *)"");


   	reg.inarray = false;
   }
   break;

   case IAPREP:
   {
   	if (reg.type != TSTRING)
   	 crash((char *)"Invalid APREP instruction.");

   	String name = (char *)"";
   	unsigned long is;
   	for (is = k; mem.get(is) != 0; ++is)
   	 name += (char)mem.get(is);


   	reg.aprep = name;


   	reg.savins = reg.mins;


   	i = is + 1;
    j = i + 1;
    k = i + 2;

    i = i - 3;
    j = i + 1;
    k = i + 2;
   }
   break;

   case IAIPREP:
   {
   	if (mem.get(reg.savins) != IAPREP)
   	 crash((char *)"First do APREP");	 
   	 
   	switch (reg.type)
   	{
   	 case TNUMBER:
   	  reg.aiprep = reg.operand;
   	  break;
   	  
   	 case TVOID:
   	  reg.aiprep = (unsigned long)reg.accumulator.object().simple().to_number().get();
   	  break;
   	  
   	 default:
   	  crash((char *)"Invalid AIPREP instruction.");
   	}   	
   	reg.savins = reg.mins;
   }
   break;

   case ILOADIA:
   {
   	if (mem.get(reg.savins) != IAIPREP)
   	 crash((char *)"First do AIPREP");

   	if (reg.type != TVOID)
   	 crash((char *)"Invalid type.");


   	bool found = false;
   	unsigned long index = 0;
	String name = reg.aprep;
   	for (unsigned long is = 0; is < reg.avars.length(); ++is)
   	{
     String n = reg.avars[is].name();
     if (n == name)
     {
      found = true;
      index = is;
     }
   	}

   	if (found == true)
   	{
   	 switch (reg.avars[index][reg.aiprep].type())
   	 {
   	  case TOSIMPLE:
   	  {
       // Clear the accumulator...
       PNF_Void v;
       reg.accumulator.object().simple().put(v);

   	   reg.accumulator.object().simple().put(reg.avars[index][reg.aiprep].simple());
   	  }
   	  break;

   	  default:
   	   crash((char *)"Invalid Array type.");
   	 }
    }
    else
     crash((char *)"Array not found.");
   }
   break;

   case ISTOREIA:
   {
   	if (mem.get(reg.savins) != IAIPREP)
   	 crash((char *)"First do AIPREP");


   	if (reg.type != TVOID)
   	 crash((char *)"Invallid type.");


	bool found = false;
   	unsigned long index = 0;
	String name = reg.aprep;
   	for (unsigned long is = 0; is < reg.avars.length(); ++is)
   	{
     String n = reg.avars[is].name();
     if (n == name)
     {
      found = true;
      index = is;
     }
   	}

	if (found == true)
	{
  	 reg.avars[index][reg.aiprep].simple(reg.accumulator.object().simple());
	}
    else
     crash((char *)"Array not found.");
   }
   break;
   
   case IALENGTH:
   {
   	if (mem.get(reg.savins) != IAPREP)
   	 crash((char *)"First do APREP");


   	if (reg.type != TVOID && reg.operand != 0)
   	 crash((char *)"Invallid ALENGTH instruction.");


	bool found = false;
   	unsigned long index = 0;
	String name = reg.aprep;
   	for (unsigned long is = 0; is < reg.avars.length(); ++is)
   	{
     String n = reg.avars[is].name();
     if (n == name)
     {
      found = true;
      index = is;
     }
   	}

	if (found == true)
	{
	 PNF_Number n(reg.avars[index].length());
  	 reg.accumulator.object().simple().put(n);
	}
    else
     crash((char *)"Array not found.");
   }
   break;
   
   case IAPRINT:
   {
   	if (mem.get(reg.savins) != IAPREP)
   	 crash((char *)"First do APREP");


   	if (reg.type != TVOID && reg.operand != 0)
   	 crash((char *)"Invallid APRINT instruction.");


	bool found = false;
   	unsigned long index = 0;
	String name = reg.aprep;
   	for (unsigned long is = 0; is < reg.avars.length(); ++is)
   	{
     String n = reg.avars[is].name();
     if (n == name)
     {
      found = true;
      index = is;
     }
   	}

	if (found == true)
	{
	 for (unsigned long i = 0; i < reg.avars[index].length(); ++i)
	 {
	  cout << name << "[" << i << "]: ";
	  reg.avars[index][i].println();
     }
	}
    else
     crash((char *)"Array not found.");
   }
   break;
   
   case IDUP:
   {
   	if (reg.type != TVOID && reg.operand != 0)
   	 crash((char *)"Invalid DUP instruction.");
   	 
   	reg.accumulator = reg.calc;
   }
   break;
   
   case ICDUP:
   {
   	if (reg.type != TVOID && reg.operand != 0)
   	 crash((char *)"Invalid CDUP instruction.");
   	 
   	reg.calc = reg.accumulator;
   }
   break;
   
   case IIF:
   {
    if (reg.type != TVOID || reg.operand != 0)
     crash((char *)"Invalid IF instruction.");

    if (reg.accumulator.object().simple().to_boolean().get() == (char *)"true")
    {
     reg.inif[reg.extrai.get(i)].type.value = true;    
    }
    else
    {
     reg.inif[reg.extrai.get(i)].type.value = false;

     i = reg.inif[reg.extrai.get(i)].type.endif;
     j = i + 1;
     k = i + 2;

     i -= 3, j -= 3, k -= 3;
    }
   }
   break;
   
   case IENDIF:
   {
    if (reg.type != TVOID || reg.operand != 0)
     crash((char *)"Invalid ENDIF instruction.");

    if (!reg.inif[reg.extrai.get(i)].type.value)
    {
     if (reg.inif[reg.extrai.get(i)].type.elseb != 0)
     {
      i = reg.inif[reg.extrai.get(i)].type.elseb;
      j = i + 1;
      k = i + 2;

      i -= 3, j -= 3, k -= 3;
     }
     else if (reg.inif[reg.extrai.get(i)].type.endelse != 0)
     {
      i = reg.inif[reg.extrai.get(i)].type.endelse;
      j = i + 1;
      k = i + 2;

      i -= 3, j -= 3, k -= 3;
     }
     else
     {
      i = reg.inif[reg.extrai.get(i)].type.eif;
      j = i + 1;
      k = i + 2;

      i -= 3, j -= 3, k -= 3;
     }
    }
   }
   break;
   
   case IIFELSE:
   {
    if (reg.type != TVOID || reg.operand != 0)
     crash((char *)"Invalid IFELSE instruction.");

    if (reg.inif[reg.extrai.get(i)].type.value)
    {
     if (reg.inif[reg.extrai.get(i)].type.endelse != 0)
     {
      i = reg.inif[reg.extrai.get(i)].type.endelse;
      j = i + 1;
      k = i + 2;

      i -= 3, j -= 3, k -= 3;
     }
     else
     {
      i = reg.inif[reg.extrai.get(i)].type.endelse;
      j = i + 1;
      k = i + 2;

      i -= 3, j -= 3, k -= 3;
     }
    }
   }
   break;
   
   case IENDIFELSE:
   {
    if (reg.type != TVOID || reg.operand != 0)
     crash((char *)"Invalid ENDIFELSE instruction.");

    if (reg.ninstruction != IEIF)
     crash((char *)"Invalid ENDIFELSE instruction.");
   }
   break;
   
   case IEIF:
   {
    if (reg.type != TVOID || reg.operand != 0)
     crash((char *)"Invalid EIF instruction.");


    ++reg.ifindex;
   }
   break;

   case IIFBEGIN:
   {

   }
   break;

   case IIFEND:
   {

   }
   break;

   case ISWITCH2:
   {
    reg.switchcond = false;
    reg.switcht = false;

    if (reg.type != TVOID && reg.operand != 0)
     crash((char *)"Invalid SWITCH2.");

    unsigned long is;
    for (is = i; mem.get(is) != ISWEND || mem.get(is) != reg.ecount; ++is)
    {
     if (mem.get(is + 1) == TSTRING && mem.get(is) != ISWCASE)
     {
      while (mem.get(is + 2) != 0)
       ++is;
      continue;
     }

     if (mem.get(is) == ISWCASE)
     {   
       switch ((long)mem.get(is + 1))
       {
        case TBOOLEAN:
        {
	 if (reg.accumulator.object().simple().getType() != mem.get(is + 1))
	  crash((char *)"Invalid SWCASE type.");

         PNF_Boolean b((long)mem.get(is + 2));

         if (reg.accumulator.object().simple().to_boolean().get() == b.get())
          reg.switchcond = true;
        }
        break;

        case TNUMBER:
        {
	 if (reg.accumulator.object().simple().getType() != mem.get(is + 1))
	  crash((char *)"Invalid SWCASE type.");

	 PNF_Number n(mem.get(is + 2));

         if (reg.accumulator.object().simple().to_number().get() == n.get())
          reg.switchcond = true;
        }
        break;

        case TCHARACTER:
        {
	 if (reg.accumulator.object().simple().getType() != mem.get(is + 1))
	  crash((char *)"Invalid SWCASE type.");

	 PNF_Character c((long)mem.get(is + 2));

         if (reg.accumulator.object().simple().to_character().get() == c.get())
          reg.switchcond = true;
        }
        break;

        case TSTRING:
        {
	 if (reg.accumulator.object().simple().getType() != mem.get(is + 1))
	  crash((char *)"Invalid SWCASE type.");

         String str = (char *)"";
	 unsigned long is2;
         for (is2 = is + 2; mem.get(is2) != 0; ++is2)
          str += (char)mem.get(is2);
         ++is2;

         PNF_String s(str);
         
         if (reg.accumulator.object().simple().to_string().get() == s.get())
          reg.switchcond = true;
        }
        break;

        default:
        {
         crash((char *)"Invalid accumulator type on SWCASE.");
        }
       };

      if (!reg.switchcond)
      {
       while (!(mem.get(is) == ISWCEND))
        ++is;
       continue;
      }
      else if (reg.switchcond)
      {
       while (mem.get(is) != ISWCBEGIN)
        ++is;

       reg.switcht = true;
       break;
      }
     }

     if (reg.switchcond && mem.get(is) == ISWDEFAULT)
     {
      while (!(mem.get(is) == ISWCEND))
       ++is;
      break;
     }
     else if (!reg.switchcond && mem.get(is) == ISWDEFAULT)
     {
      while (mem.get(is) != ISWCBEGIN)
       ++is;

      reg.switcht = true;
      break;
     }
    }

    i = is;
    j = i + 1;
    k = i + 2;

    i -= 3, j -= 3, k -= 3;
   }
   break;

 case ISWBEGIN:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid SWBEGIN.");

  if (mem.get(i + 3) != ISWCASE && mem.get(i + 3) != ISWDEFAULT)
   crash((char *)"Invalid SWBEGIN.");
 }
 break;

 case ISWEND:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid SWEND.");

  if (mem.get(i - 3) != ISWCEND)
   crash((char *)"Invalid SWEND.");
 }
 break;

 case ISWCASE:
 {
  if (reg.switcht)
  {
   if (mem.get(i + 1) == TSTRING)
   {
    unsigned long is;
    for (is = i; mem.get(is) != 0; ++is)
     ;
    ++is;

    i = is;
    j = i + 1;
    k = i + 2;

    i -= 3, j -= 3, k -= 3;
   }
  }
 }
 break;

 case ISWCBEGIN:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid SWCBEGIN.");
 }
 break;

 case ISWCEND:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid SWCEND.");
 }
 break;

 case ISWDEFAULT:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid SWDEFAULT.");
 }
 break;

 case ISWBREAK:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid SWBREAK.");

  if (reg.switcht)
  {
   while (mem.get(i) != ISWEND)
    ++i;

   j = i + 1;
   k = i + 2;

   i -= 3, j -= 3, k -= 3;
  }
 }
 break;

  case ILOADSP:
  {
   if (reg.type != TNUMBER)
    crash((char *)"Invalid LOADSP instruction.");

   reg.savestack = stk;

   for (unsigned long is = 0; is != TNUMBER; ++is)
    stk.pop();
   reg.stackp = stk.pop();
   
   stk = reg.savestack;
  }
  break;

 case ISTORESP:
 {
  if (reg.type != TNUMBER)
   crash((char *)"Invalid STORESP instruction.");

  reg.savestack = stk;

  unsigned long is;
  for (is = 0; is != TNUMBER; ++is)
   ;

  for (unsigned long is2 = 0; is2 != is + 1; ++is2)
  {
   if (is2 == is)
   {
    stk.push(reg.accumulator.object().simple());
    break;
   }
   else
   {
    PNF_Variable v = reg.savestack.pop();
    stk.push(v);
   }
  }

  reg.savestack = stk;
 }
 break;

 case ILOADSTACK:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid LOADSTACK instruction.");

  stk = reg.savestack;
 }
 break;

 case ISTORESTACK:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid STORESTACK instruction.");

  reg.savestack = stk;
 }
 break;

 case IATOSP:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid ATOSP instruction.");

  reg.stackp = reg.accumulator.object().simple();
 }
 break;

 case ISPTOA:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid SPTOA instruction.");

  reg.accumulator.object().simple() = reg.stackp;
 }
 break;

 case IPATCH:
 {
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid patch.");

  if (reg.iname == (char *)"(COMPILED)")
  {
   // Load extra info for ifs...
   unsigned long ifcounter = 0;
   for (unsigned long i = 0; i != reg.ecount; i += 3)
   {
    if (mem.get(i + 1) == TSTRING)
    {
     unsigned long is = 0;
     for (is = i + 2; mem.get(is) != 0; ++is)
      ;
     ++is;
     i = is;
     i -= 3;
     continue;
    }

    if (mem.get(i) == IIF || mem.get(i) == IENDIF || mem.get(i) == IIFELSE || mem.get(i) == IENDIFELSE || mem.get(i) == IEIF)
    {
     if (mem.get(i) == IIF)
     {
       ++ifcounter;
       reg.inif.insert();
     }
    }
   }

   // Load extra info for switches...
   unsigned long switchcounter = 0;
   for (unsigned long i = 0; i != reg.ecount; i += 3)
   {
    if (mem.get(i + 1) == TSTRING && mem.get(i) != ISWITCH2)
    {
     unsigned long is = 0;
     for (is = i + 2; mem.get(is) != 0; ++is)
      ;
     ++is;
     i = is;
     i -= 3;
     continue;
    }

    if (mem.get(i) == ISWITCH2)
    {
     ++switchcounter;
    }
   }
  }
 }
 break;

 case INATIVE:
 {
  if (reg.type != TSTRING)
   crash((char *)"Invalid NATIVE instruction.");


  String str = (char *)"";
  unsigned long is;
  for (is = i + 2; mem.get(is) != 0; ++is)
  {
   str += mem.get(is);
  }
  ++is;

  system(((char *)".\\" + str + (char *)".exe").getString().c_str());

  i = is;
  j = i + 1;
  k = i + 2;
  i -= 3, j -= 3, k -= 3;
 }
 break;

 case IFRET:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type == 0 && reg.operand == 0)
  {
   PNF_Variable v2 = (funcstk.top());
   i = (unsigned long)v2.to_number().get();
   if (i == -1)
    crash((char *)"Could Not Return.");

   i += 3;
   funcstk.pop();

   // GOTO Address
   j = i + 1;
   k = i + 2;

   i = i - 3;
   j = i + 1;
   k = i + 2;
  }
  else
   crash((char *)"Invalid FRET.");
 }
 break;

 case IFCALL:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TSTRING)
   crash((char *)"Invalid FCALL instruction.");

  reg.fname = (char *)"";
  unsigned long is;
  for (is = k; mem.get(is) != 0; ++is)
   reg.fname += (char)mem.get(is);

  i = is + 1;
  j = i + 1;
  k = j + 1;
  i -= 3, j -= 3, k -= 3;
 }
 break;

 case IFCPARAMS:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FCPARAMS instruction.");
 }
 break;

 case IFECPARAMS:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FECPARAMS instruction.");
 }
 break;

 case IFECALL:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FECALL instruction.");

  unsigned long index = reg.fpointer1.find(reg.fname, reg.frets, reg.fparams);
  if (index == -1)
   crash((char *)"Function not found.");
  reg.fpointer3 = &reg.fpointer1.get_function(index);

  for (unsigned long is = reg.frets.length() - 1; is != 0; --is)
   reg.frets.remove();

  for (unsigned long is = reg.fparams.length() - 1; is != 0; --is)
   reg.fparams.remove();


  PNF_Number n(i);
  PNF_Variable v2(n);
  funcstk.push(v2);

  i = reg.fpointer3->definition();
  j = i + 1;
  k = j + 1;
  i -= 3, j -= 3, k -= 3;
 }
 break;

 case IPNUM:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TNUMBER)
   crash((char *)"Invalid PNUM instruction.");

  reg.pnum = reg.operand;
 }
 break;

 case IPARAMF:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  double d = reg.accumulator.object().simple().to_number().get();
  unsigned long index = (unsigned long)d;

  switch (reg.type)
  {
   case TVOID:
   {
    if (reg.operand != 0)
     crash((char *)"Invalid operand.");

    PNF_Void v2;
    PNF_Variable v3(v);

    reg.fpointer1.get_function(index).param(reg.pnum, v3);
    reg.fparams[reg.fparams.length() - 1] = (char *)"VOID";
    reg.fparams.insert();
   }
   break;

   case TBOOLEAN:
   {
    if (reg.operand != 0 && reg.operand != 1)
     crash((char *)"Invalid operand.");

    bool b = reg.operand == 0 ? false : true;
    PNF_Boolean b2;
    b2.put(b);
    PNF_Variable v2(b2);

    reg.fpointer3 = &reg.fpointer1.get_function(index);
    reg.fpointer3->param(reg.pnum, v2);
    reg.fparams[reg.fparams.length() - 1] = (char *)"BOOLEAN";
    reg.fparams.insert();
   }
   break;

   case TNUMBER:
   {
    PNF_Number n;
    n.put(reg.operand);
    PNF_Variable v2(n);

    reg.fpointer3 = &reg.fpointer1.get_function(index);
    reg.fpointer3->param(reg.pnum, v2);
    reg.fparams[reg.fparams.length() - 1] = (char *)"NUMBER";
    reg.fparams.insert();
   }
   break;

   case TCHARACTER:
   {
    char ch = (char)reg.operand;
    PNF_Variable v2((PNF_Character)ch);

    reg.fpointer1.get_function(index).param(reg.pnum, v2);
    reg.fparams[reg.fparams.length() - 1] = (char *)"CHARACTER";
    reg.fparams.insert();
   }
   break;

   case TSTRING:
   {
    PNF_String s;
    
    unsigned long is;
    String str = (char *)"";
    for (is = k; mem.get(is) != 0; ++is)
     str += (char)mem.get(is);

    s.put(str);
    
    PNF_Variable v2(s);

    reg.fpointer1.get_function(index).param(reg.pnum, v2);
    reg.fparams[reg.fparams.length() - 1] = (char *)"STRING";
    reg.fparams.insert();

    i = is + 1;
    j = i + 1;
    k = j + 1;
    i -= 3, j -= 3, k -= 3;
   }
   break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IPARAMF2:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.operand != 0)
   crash((char *)"Invalid PARAMF2 instruction.");

  switch (reg.type)
  {
   case TVOID:
   {
    PNF_Void v2;
    PNF_Variable v3;

    reg.accumulator.object().simple().put(v3);
   }
   break;

   case TBOOLEAN:
   {
    double d = reg.accumulator.object().simple().to_number().get();
    unsigned long index = (unsigned long)d;
    bool b2 = reg.fpointer1.get_function(index).param(reg.pnum).to_boolean().get() == (char *)"false" ? false : true;
    PNF_Boolean b(b2);
    PNF_Variable v2(b);
    reg.accumulator.object().simple().put(v2);
   }
   break;

   case TNUMBER:
   {
    double d = reg.accumulator.object().simple().to_number().get();
    unsigned long index = (unsigned long)d;
    PNF_Number n(reg.fpointer1.get_function(index).param(reg.pnum).to_number().get());
    PNF_Variable v2(n);
    reg.accumulator.object().simple().put(v2);
   }
   break;

   case TCHARACTER:
   {
    double d = reg.accumulator.object().simple().to_number().get();
    unsigned long index = (unsigned long)d;
    reg.accumulator.object().simple().put(reg.fpointer1.get_function(index).param(reg.pnum).to_character());
   }
   break;

   case TSTRING:
   {
    double d = reg.accumulator.object().simple().to_number().get();
    unsigned long index = (unsigned long)d;
    PNF_String s(reg.fpointer1.get_function(index).param(reg.pnum).to_string());
    PNF_Variable v2(s);
    reg.accumulator.object().simple().put(v2);
   }
   break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IPARAMF3:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.operand != 0)
   crash((char *)"Invalid PARAMF3 instruction.");

  switch (reg.type)
  {
   case TVOID:
   {
    reg.fparams[reg.fparams.length() - 1] = (char *)"VOID";
    reg.fparams.insert();
   }
   break;

   case TBOOLEAN:
   {
    reg.fparams[reg.fparams.length() - 1] = (char *)"BOOLEAN";
    reg.fparams.insert();
   }
   break;

   case TNUMBER:
   {
    reg.fparams[reg.fparams.length() - 1] = (char *)"NUMBER";
    reg.fparams.insert();
   }
   break;

   case TCHARACTER:
   {
    reg.fparams[reg.fparams.length() - 1] = (char *)"CHARACTER";
    reg.fparams.insert();
   }
   break;

   case TSTRING:
   {
    reg.fparams[reg.fparams.length() - 1] = (char *)"STRING";
    reg.fparams.insert();
   }
   break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IRNUM:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TNUMBER)
   crash((char *)"Invalid RNUM instruction.");

  reg.rnum = reg.operand;
 }
 break;

 case IRETURNF:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");


  if (reg.operand != 0)
   crash((char *)"Invalid RETURNF instruction.");


  reg.frets.remove();
  reg.fparams.remove();

  switch (reg.type)
  {
   case TVOID:
   {
    unsigned long index = reg.fpointer1.find(reg.fname, reg.frets, reg.fparams);

    if (index == -1)
     crash((char *)"Function not found.");

    reg.fpointer3 = &reg.fpointer1.get_function(index);
    reg.fpointer3->ret(reg.rnum, reg.accumulator.object().simple().to_Void());
   }
   break;

   case TBOOLEAN:
   {
    unsigned long index = reg.fpointer1.find(reg.fname, reg.frets, reg.fparams);

    if (index == -1)
     crash((char *)"Function not found.");

    reg.fpointer3 = &reg.fpointer1.get_function(index);
    reg.fpointer3->ret(reg.rnum, reg.accumulator.object().simple().to_boolean());
   }
   break;

   case TNUMBER:
   {
    unsigned long index = reg.fpointer1.find(reg.fname, reg.frets, reg.fparams);

    if (index == -1)
     crash((char *)"Function not found.");

    reg.fpointer3 = &reg.fpointer1.get_function(index);
    reg.fpointer3->ret(reg.rnum, reg.accumulator.object().simple().to_number());
   }
   break;

   case TCHARACTER:
   {
    unsigned long index = reg.fpointer1.find(reg.fname, reg.frets, reg.fparams);
\
    if (index == -1)
     crash((char *)"Function not found.");

    reg.fpointer3 = &reg.fpointer1.get_function(index);
    reg.fpointer3->ret(reg.rnum, reg.accumulator.object().simple().to_character());
   }
   break;

   case TSTRING:
   {
    unsigned long index = reg.fpointer1.find(reg.fname, reg.frets, reg.fparams);

    if (index == -1)
     crash((char *)"Function not found.");

    reg.fpointer3 = &reg.fpointer1.get_function(index);
    reg.fpointer3->ret(reg.rnum, reg.accumulator.object().simple().to_string());
   }
   break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IRETURNF2:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.operand != 0)
   crash((char *)"Invalid RETURNF2 instruction.");

  switch (reg.type)
  {
   case TVOID:
   {
    reg.frets[reg.frets.length() - 1] = (char *)"VOID";
    reg.frets.insert();
   }
   break;

   case TBOOLEAN:
   {
    reg.frets[reg.frets.length() - 1] = (char *)"BOOLEAN";
    reg.frets.insert();
   }
   break;

   case TNUMBER:
   {
    reg.frets[reg.frets.length() - 1] = (char *)"NUMBER";
    reg.frets.insert();
   }
   break;

   case TCHARACTER:
   {
    reg.frets[reg.frets.length() - 1] = (char *)"CHARACTER";
    reg.frets.insert();
   }
   break;

   case TSTRING:
   {
    reg.frets[reg.frets.length() - 1] = (char *)"STRING";
    reg.frets.insert();
   }
   break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IRETURNF3:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.operand != 0)
   crash((char *)"Invalid RETURNF3 instruction.");

  switch (reg.type)
  {
   case TVOID:
   {
    reg.frets2[reg.frets2.length() - 1] = (char *)"VOID";
    reg.frets2.insert();
   }
   break;

   case TBOOLEAN:
   {
    reg.frets2[reg.frets2.length() - 1] = (char *)"BOOLEAN";
    reg.frets2.insert();
   }
   break;

   case TNUMBER:
   {
    reg.frets2[reg.frets2.length() - 1] = (char *)"NUMBER";
    reg.frets2.insert();
   }
   break;

   case TCHARACTER:
   {
    reg.frets2[reg.frets2.length() - 1] = (char *)"CHARACTER";
    reg.frets2.insert();
   }
   break;

   case TSTRING:
   {
    reg.frets2[reg.frets2.length() - 1] = (char *)"STRING";
    reg.frets2.insert();
   }
   break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IFNAME:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TSTRING)
   crash((char *)"Invalid FNAME instruction.");

  unsigned long is;
  String str = (char *)"";
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);

  reg.fname = str;

  i = is + 1;
  j = i + 1;
  k = j + 1;
  i -= 3, j -= 3, k -= 3;
 }
 break;

 case IRETURNV:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid RETURNV instruction.");


  reg.accumulator.object().simple().put(reg.fpointer3->ret(reg.rnum));
 }
 break;

 case IFNCLOAD:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TNUMBER)
   crash((char *)"Invalid FNCLOAD instruction.");

  reg.fpointer2 = &reg.fpointer1.get_function(reg.operand);
 }
 break;

 case IFNCSTORE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  switch (reg.type)
  {
   case TVOID:
   {
    reg.fpointer1.add_function((*reg.fpointer2));
   }
   break;

   case TNUMBER:
   {
    reg.fpointer1.mod_function(reg.operand, (*reg.fpointer2));
   }
   break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IFNCNEW:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCNEW intruction.");

  reg.fpointer2 = new Function();
 }
 break;

 case IFNCDELETE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCDELETE intruction.");

  delete reg.fpointer2;
  reg.fpointer2 = NULL;
 }
 break;

 case IFNCSNAME:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCSNAME intruction.");

  reg.fpointer2->name(reg.accumulator.object().simple().to_string().get());
 }
 break;

 case IFNCSRET:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.operand != 0)
   crash((char *)"Invalid FNCSRET instruction.");

  switch (reg.type)
  {
   case TVOID:
   {
    PNF_Void v;
    PNF_Variable v2(v);

    reg.fpointer2->ret(reg.rnum, v2);
   }
   break;

   case TBOOLEAN:
   {
    PNF_Variable v(reg.accumulator.object().simple().to_boolean());

    reg.fpointer2->ret(reg.rnum, v);
   }
   break;

   case TNUMBER:
   {
    PNF_Variable v(reg.accumulator.object().simple().to_number());

    reg.fpointer2->ret(reg.rnum, v);
   }
   break;

   case TCHARACTER:
   {
    PNF_Variable v(reg.accumulator.object().simple().to_character());

    reg.fpointer2->ret(reg.rnum, v);
   }
   break;

   case TSTRING:
   {
    PNF_Variable v(reg.accumulator.object().simple().to_string());

    reg.fpointer2->ret(reg.rnum, v);

    unsigned long is;
    for (is = k; mem.get(is) != 0; ++is)
     ;
    i = is + 1, j = i + 1, k = j + 1;
    i -= 3, j -= 3, k -= 3;
   }
   break;


   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IFNCSPARAM:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.operand != 0)
   crash((char *)"Invalid FNCSPARAM instruction.");

  switch (reg.type)
  {
   case TVOID:
   {
    PNF_Void v;
    PNF_Variable v2(v);

    reg.fpointer2->param(reg.pnum, v2);

    reg.fparams3[reg.fparams3.length() - 1] = (char *)"VOID";
    reg.fparams3.insert();
   }
   break;

   case TBOOLEAN:
   {
    PNF_Variable v(reg.accumulator.object().simple().to_boolean());

    reg.fpointer2->param(reg.pnum, v);

    reg.fparams3[reg.fparams3.length() - 1] = (char *)"BOOLEAN";
    reg.fparams3.insert();
   }
   break;

   case TNUMBER:
   {
    PNF_Variable v(reg.accumulator.object().simple().to_number());

    reg.fpointer2->param(reg.pnum, v);

    reg.fparams3[reg.fparams3.length() - 1] = (char *)"NUMBER";
    reg.fparams3.insert();
   }
   break;

   case TCHARACTER:
   {
    PNF_Variable v(reg.accumulator.object().simple().to_character());

    reg.fpointer2->param(reg.pnum, v);

    reg.fparams3[reg.fparams3.length() - 1] = (char *)"CHARACTER";
    reg.fparams3.insert();
   }
   break;

   case TSTRING:
   {
    PNF_Variable v(reg.accumulator.object().simple().to_string());

    reg.fpointer2->param(reg.pnum, v);

    unsigned long is;
    for (is = k; mem.get(is) != 0; ++is)
     ;
    i = is + 1, j = i + 1, k = j + 1;
    i -= 3, j -= 3, k -= 3;

    reg.fparams3[reg.fparams3.length() - 1] = (char *)"STRING";
    reg.fparams3.insert();
   }
   break;


   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IFNCSDEF:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  switch (reg.type)
  {
   case TNUMBER:
   {
    reg.fpointer2->definition(reg.operand);
   }
   break;

   case TSTRING:
   {
    String str = (char *)"";
    unsigned long is;
    for (is = k; mem.get(is) != 0; ++is)
     str += mem.get(is);

    for (unsigned long is2 = 0; is2 < reg.labels.length(); ++is2)
    {
     if (reg.labels.get(is2).getString().getString() == str.getString())
     {
      reg.operand = reg.labels.get(is2).getNum();
      break;
     }
     else
      reg.operand = is + 1;
    }
    
    
    reg.fpointer2->definition(reg.operand);


    i = is + 1, j = i + 1, k = j + 1;
    i -= 3, j -= 3, k -= 3;
   }
   break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IFNCGNAME:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCGNAME instruction.");

  PNF_String str(reg.fpointer2->name());
  PNF_Variable v2(str);
  reg.accumulator.object().simple().put(v2);
 }
 break;

 case IFNCGRET:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TNUMBER)
   crash((char *)"Invalid FNCGRET instruction.");

  reg.accumulator.object().simple().put(reg.fpointer2->ret(reg.operand));
 }
 break;

 case IFNCGPARAM:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TNUMBER)
   crash((char *)"Invalid FNCGPARAM instruction.");

  reg.accumulator.object().simple().put(reg.fpointer2->param(reg.operand));
 }
 break;

 case IFNCGDEF:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCGNAME instruction.");

  PNF_Number n(reg.fpointer2->definition());
  PNF_Variable v2(n);
  reg.accumulator.object().simple().put(v2);
 }
 break;

 case IFNCPOINT:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
  
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCPOINT instruction.");

  unsigned long p = reg.accumulator.object().simple().to_number().get();
  reg.fpointer3 = &reg.fpointer1.get_function(p);
 }
 break;

 case IFNCLENGTH:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
  
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCPOINT instruction.");

  PNF_Number n(reg.fpointer1.length());
  PNF_Variable v2(n);
  reg.accumulator.object().simple().put(v2);
 }
 break;

 case IFNCSYNCR:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCSYNCR instruction.");

  reg.fname2 = reg.fname;
  reg.frets2 = reg.frets;
  reg.fparams2 = reg.fparams;
 }
 break;

 case IFNCFIND:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID)
   crash((char *)"Invalid FNCFIND instruction.");

 if (reg.operand != 0)
  crash((char *)"Invalid FNCFIND instruction.");

  String str = reg.accumulator.object().simple().to_string().get();
  unsigned long index = reg.fpointer1.find(str, reg.frets3, reg.fparams3);
  if (index == -1)
   crash((char *)"Function not found.");

  PNF_Number n(index);
  reg.accumulator.object().simple().put(n);


  for (unsigned long is = reg.frets3.length() - 1; is != 0; --is)
   reg.frets3.remove();

  for (unsigned long is = reg.fparams3.length() - 1; is != 0; --is)
   reg.fparams3.remove();
 }
 break;

 case IFNCFRET:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.operand != 0)
   crash((char *)"Invalid FNCFRET instruction.");

  switch (reg.type)
  {
   case TVOID:
    reg.frets3[reg.frets3.length() - 1] = (char *)"VOID";
    reg.frets3.insert();
    break;

   case TBOOLEAN:
    reg.frets3[reg.frets3.length() - 1] = (char *)"BOOLEAN";
    reg.frets3.insert();
    break;

   case TNUMBER:
    reg.frets3[reg.frets3.length() - 1] = (char *)"NUMBER";
    reg.frets3.insert();
    break;

   case TCHARACTER:
    reg.frets3[reg.frets3.length() - 1] = (char *)"CHARACTER";
    reg.frets3.insert();
    break;

   case TSTRING:
    reg.frets3[reg.frets3.length() - 1] = (char *)"STRING";
    reg.frets3.insert();
    break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IFNCFPARAM:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.operand != 0)
   crash((char *)"Invalid FNCFPARAM instruction.");

  switch (reg.type)
  {
   case TVOID:
    reg.fparams3[reg.fparams3.length() - 1] = (char *)"VOID";
    reg.fparams3.insert();
    break;

   case TBOOLEAN:
    reg.fparams3[reg.fparams3.length() - 1] = (char *)"BOOLEAN";
    reg.fparams3.insert();
    break;

   case TNUMBER:
    reg.fparams3[reg.fparams3.length() - 1] = (char *)"NUMBER";
    reg.fparams3.insert();
    break;

   case TCHARACTER:
    reg.fparams3[reg.fparams3.length() - 1] = (char *)"CHARACTER";
    reg.fparams3.insert();
    break;

   case TSTRING:
    reg.fparams3[reg.fparams3.length() - 1] = (char *)"STRING";
    reg.fparams3.insert();
    break;

   default:
    crash((char *)"Invalid type.");
  }
 }
 break;

 case IFNCFBRET:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCFPARAM instruction.");


  reg.frets3[reg.frets3.length() - 1] = (char *)"";
 }
 break;

 case IFNCFBPARAM:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCFPARAM instruction.");


  reg.fparams3[reg.fparams3.length() - 1] = (char *)"";
 }
 break;

 case IFNCDEFAULT:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCDEFAULT instruction.");

  reg.fdefaultv = true;
 }
 break;

 case IFNCDEFAULT2:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCDEFAULT2 instruction.");

  reg.fdefaultv = false;
 }
 break;

 case IFNCSDEFAULTV:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.operand != 0)
   crash((char *)"Invalid FNCSDEFAULTV instruction.");

  double d = reg.accumulator.object().simple().to_number().get();
  unsigned long index = (unsigned long)d;

  reg.fpointer3 = &reg.fpointer1.get_function(index);


  switch (reg.type)
  {
   case TVOID:
   {
    if (reg.fdefaultv)
    {
     reg.fparams[reg.fparams.length() - 1] = (char *)"VOID";
     reg.fparams.insert();
    }
   }
   break;

   case TBOOLEAN:
   {
    if (reg.fdefaultv)
    {
     reg.fparams[reg.fparams.length() - 1] = (char *)"BOOLEAN";
     reg.fparams.insert();
    }
   }
   break;

   case TNUMBER:
   {
    if (reg.fdefaultv)
    {
     reg.fparams[reg.fparams.length() - 1] = (char *)"NUMBER";
     reg.fparams.insert();
    }
   }
   break;

   case TCHARACTER:
   {
    if (reg.fdefaultv)
    {
     reg.fparams[reg.fparams.length() - 1] = (char *)"CHARACTER";
     reg.fparams.insert();
    }
   }
   break;

   case TSTRING:
   {
    if (reg.fdefaultv)
    {
     reg.fparams[reg.fparams.length() - 1] = (char *)"STRING";
     reg.fparams.insert();
    }
   }
   break;

   default:
    crash((char *)"Invalid Type.");
  }
 }
 break;

 case IFNCSDEFAULTV2:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCSDEFAULTV2 instruction.");

  if (reg.fdefaultv)
  {
   reg.fdefaultvalue = reg.accumulator;
   reg.fpointer2->defaultv(reg.pnum, reg.fdefaultvalue.object().simple());
  }
 }
 break;

 case IFNCGDEFAULTV2:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCGDEFAULTV2 instruction.");

  if (reg.fdefaultv)
  {
   reg.fdefaultvalue.object().simple().put(reg.fpointer2->defaultv(reg.pnum));
   reg.accumulator = reg.fdefaultvalue;
  }
 }
 break;

 case IFNCDEFAULTSYNC:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid FNCDEFAULTSYNC instruction.");

  reg.fpointer2->syncdefaultp(reg.pnum);
 }
 break;

 case INTIMES:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid NTIMES instruction.");


  String str = reg.accumulator.object().simple().to_string().get();
  String str2 = str;
  
  for (unsigned long i = 1; i < (unsigned long)reg.calc.object().simple().to_number().get(); ++i)
   str += str2;

  PNF_String str3(str);
  reg.accumulator.object().simple().put(str3);
 }
 break;

 case ICMP:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invalid CMP instruction.");


  double d = reg.accumulator.object().simple().to_number().get();
  double d2 = reg.calc.object().simple().to_number().get();

  bool b1 = d < d2;
  bool b2 = d == d2;
  bool b3 = d > d2;

  double result = 0;

  if (b1)
   result = -1;
  else if (b2)
   result = 0;
  else if (b3)
   result = 1;
  else
   crash((char *)"Bad data in CMP.");

  PNF_Number n(result);
  reg.accumulator.object().simple().put(n);
 }
 break;
 
 case IRUN:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
   
  if (reg.type != TSTRING)
   crash((char *)"Invalid RUN instruction.");
   
   
  String str = "";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
  
  int ret = system(str.getString().c_str());
  if (ret == -1)
   crash((char *)"Unable to run command.");
  ret = ret >> 8;
  PNF_Number n(ret);
  reg.accumulator.object().simple().put(n);
  
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case IJRUN:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
   
  if (reg.type != TSTRING)
   crash((char *)"Invalid JRUN instruction.");
   
   
  String str = (char *)"";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
  {
   str += (char)mem.get(is);
  }
   
  char * java = getenv("JRUN");
  if (java == NULL)
   crash((char *)"JRUN enviroment variable not set.");
 String java2 = java;
  
  String str2 = "\"" + java2  + "\"" +  " " + str;
  
  int ret = system(str2.getString().c_str());
  if (ret == -1)
   crash((char *)"Unable to run command.");
  ret = ret >> 8;

  PNF_Number n(ret);
  reg.accumulator.object().simple().put(n);
   
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case IPNFRUN:
 {
   PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
   
  if (reg.type != TSTRING)
   crash((char *)"Invalid PNFRUN instruction.");
   
   
  String str = "";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
   
 String pnf = "";
 #ifdef OS_WINDOWS
  pnf = "pnf";
 #endif // OS_WINDOWS
 #ifdef OS_LINUX
  pnf = "./pnf";
 #endif // OS_LINUX
  
  String str2 = pnf + " " + str;
  
  int ret = system(str2.getString().c_str());
  if (ret == -1)
   crash((char *)"Unable to run command.");
  ret = ret >> 8;

  PNF_Number n(ret);
  reg.accumulator.object().simple().put(n);

  
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case ISTRUCT:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
   
  if (reg.type != TSTRING)
   crash((char *)"Invalid STRUCT instruction.");
   
  String str = (char *)"";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
   
 
  reg.structs.insert();
  reg.structs[reg.structs.length() - 1].type(str);
   
  i = is + 1;
  j = i + 1;
  k = i + 2;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case ISTRUCTVAR:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
   
  if (reg.type != TSTRING)
   crash((char *)"Invaild STRUCTVAR instruction.");
  
   
  String str = (char *)"";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
  
   
  PNF_Object2 o;
  reg.structs[reg.structs.length() - 1].Use(reg.structs[reg.structs.length() - 1].mlength() - 1);
  reg.structs[reg.structs.length() - 1].put(o, str);
  reg.structs[reg.structs.length() - 1].add();
  
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case IENDSTRUCT:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
   
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild ENDSTRUCT instruction.");
 }
 break;
 
 case ISTRUCTNAME:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TSTRING)
   crash((char *)"Invaild STRUCTNAME instruction.");
  
   
  String str = (char *)"";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
  
   
  reg.struct_type = str;
  
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case ISTRUCTONAME:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TSTRING)
   crash((char *)"Invaild STRUCTONAME instruction.");
  
   
  String str = "";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
  
   
  reg.struct_name = str;
  
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case ISTRUCTD:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TSTRING)
   crash((char *)"Invaild STRUCTD instruction.");
  
   
  String str = (char *)"";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
  
   
  unsigned long is2 = 0;
  bool found = false;
  for (is2 = 0; is2 < reg.structs.length(); ++is2)
  {
   if (reg.structs[is2].type() == reg.struct_type)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"struct: " + reg.struct_type + " undefined.");
   
  reg.ostructs.insert();
  reg.ostructs[reg.ostructs.length() - 1] = reg.structs[is2];
  reg.ostructs[reg.ostructs.length() - 1].name(str);
  
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case ISTRUCTUSE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  switch (reg.type)
  {
   case TVOID:
   {
    if (reg.operand != 0)
     crash((char *)"Invaild STRUCTUSE instruction.");
  
    
    unsigned long is2;
    bool found = false;
    for (is2 = 0; is2 < reg.ostructs.length(); ++is2)
    {
     if (reg.ostructs[is2].name() == reg.struct_name)
     {
      found = true;
      break;
     }
    }
  
    if (!found)
     crash((char *)"object: " + reg.struct_name + " not found.");
   
    bool uvalue = reg.ostructs[is2].Use(reg.struct_name);

    if (!uvalue)
     crash(reg.struct_name + (char *)"." + reg.struct_name + (char *)": not found.");
   }
   break;

   case TNUMBER:
   {
    if (reg.operand != 0)
     crash((char *)"Invaild STRUCTUSE instruction.");

    unsigned long is2;
    bool found = false;
    for (is2 = 0; is2 < reg.ostructs.length(); ++is2)
    {
     if (reg.ostructs[is2].name() == reg.struct_name)
     {
      found = true;
      break;
     }
    }
  
    if (!found)
     crash((char *)"object: " + reg.struct_name + " not found.");
  
    bool uvalue = reg.ostructs[is2].Use((unsigned long)reg.accumulator.object().simple().to_number().get());

    char str1[1000];
    sprintf(str1, "%lu", (unsigned long)reg.accumulator.object().simple().to_number().get());
    String str = str1;

    if (!uvalue)
     crash(reg.struct_name + (char *)"." + str + (char *)": not found.");
   }
   break;

   case TSTRING:
   {
    String str = (char *)"";
    unsigned long is;
    for (is = k; mem.get(is) != 0; ++is)
     str += (char)mem.get(is);
  
    
    unsigned long is2;
    bool found = false;
    for (is2 = 0; is2 < reg.ostructs.length(); ++is2)
    {
     if (reg.ostructs[is2].name() == reg.struct_name)
     {
      found = true;
      break;
     }
    }
  
    if (!found)
     crash((char *)"object: " + reg.struct_name + " not found.");
   
    bool uvalue = reg.ostructs[is2].Use(str);
 
    if (!uvalue)
     crash(reg.struct_name + (char *)"." + str + (char *)": not found.");


    i = is + 1;
    j = i + 1;
    k = i + 2;

    i -= 3, j -= 3, k -= 3;
   }
   break;


   default:
    crash((char *)"Invalid STRUCTUSE instruction.");
  };
 }
 break;

 case ISTRUCTUSING:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild STRUCTUSING instruction.");

  unsigned long is2;
  bool found = false;
  for (is2 = 0; is2 < reg.ostructs.length(); ++is2)
  {
   if (reg.ostructs[is2].name() == reg.struct_name)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"object: " + reg.struct_name + " not found.");

  reg.accumulator.object().simple().put((PNF_Number)reg.ostructs[is2].Using());
 }
 break;

 case ISTRUCTUSINGNAME:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild STRUCTUSINGNAME instruction.");

  unsigned long is2;
  bool found = false;
  for (is2 = 0; is2 < reg.ostructs.length(); ++is2)
  {
   if (reg.ostructs[is2].name() == reg.struct_name)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"object: " + reg.struct_name + " not found.");

  reg.accumulator.object().simple().put(reg.ostructs[is2].UsingName());
 }
 break;

 case ISTRUCTGET:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild STRUCTGET instruction.");

  unsigned long is2;
  bool found = false;
  for (is2 = 0; is2 < reg.ostructs.length(); ++is2)
  {
   if (reg.ostructs[is2].name() == reg.struct_name)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"object: " + reg.struct_name + " not found.");

  reg.accumulator.object(reg.ostructs[is2].get().object());
 }
 break;

case ISTRUCTPUT:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild STRUCTPUT instruction.");

  unsigned long is2;
  bool found = false;
  for (is2 = 0; is2 < reg.ostructs.length(); ++is2)
  {
   if (reg.ostructs[is2].name() == reg.struct_name)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"object: " + reg.struct_name + " not found.");

  reg.ostructs[is2].put(reg.accumulator, reg.ostructs[is2].UsingName());
 }
 break;

 case ISTRUCTTYPE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild STRUCTTYPE instruction.");

  reg.accumulator.object().simple().put(reg.struct_type);
 }
 break;

 case ISTRUCTTYPE2:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild STRUCTTYPE2 instruction.");

  reg.struct_type = reg.accumulator.object().simple().to_string().get();
 }
 break;

 case ISTRUCTNAME2:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild STRUCTNAME2 instruction.");

  reg.accumulator.object().simple().put(reg.struct_name);
 }
 break;

 case ISTRUCTNAME3:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild STRUCTNAME3 instruction.");

  reg.struct_name = reg.accumulator.object().simple().to_string().get();
 }
 break;

 case IUNION:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
   
  if (reg.type != TSTRING)
   crash((char *)"Invalid UNION instruction.");
   
  String str = (char *)"";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
   
 
  reg.unions.insert();
  reg.unions[reg.unions.length() - 1].type(str);
   
  i = is + 1;
  j = i + 1;
  k = i + 2;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case IUNIONVAR:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
   
  if (reg.type != TSTRING)
   crash((char *)"Invaild UNIONVAR instruction.");
  
   
  String str = (char *)"";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
  
   
  PNF_Object2 o;
  reg.unions[reg.unions.length() - 1].Use(reg.unions[reg.unions.length() - 1].mlength() - 1);
  reg.unions[reg.unions.length() - 1].put(o, str);
  reg.unions[reg.unions.length() - 1].add();
  
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case IENDUNION:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");
   
  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild ENDUNION instruction.");
 }
 break;
 
 case IUNIONNAME:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TSTRING)
   crash((char *)"Invaild UNIONNAME instruction.");
  
   
  String str = (char *)"";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
  
   
  reg.union_type = str;
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case IUNIONONAME:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TSTRING)
   crash((char *)"Invaild UNIONONAME instruction.");
  
   
  String str = "";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
  
   
  reg.union_name = str;
  
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case IUNIOND:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TSTRING)
   crash((char *)"Invaild UNIOND instruction.");
  
   
  String str = (char *)"";
  unsigned long is = 0;
  for (is = k; mem.get(is) != 0; ++is)
   str += (char)mem.get(is);
  
   
  unsigned long is2 = 0;
  bool found = false;
  for (is2 = 0; is2 < reg.unions.length(); ++is2)
  {
   if (reg.unions[is2].type() == reg.union_type)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"struct: " + reg.union_type + " undefined.");
   
  reg.ounions.insert();
  reg.ounions[reg.unions.length() - 1] = reg.unions[is2];
  reg.ounions[reg.unions.length() - 1].name(str);
  
  
  i = is + 1;
  j = i + 1;
  k = j + 1;
  
  i -= 3, j -= 3, k -= 3;
 }
 break;
 
 case IUNIONUSE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  switch (reg.type)
  {
   case TVOID:
   {
    if (reg.operand != 0)
     crash((char *)"Invaild UNIONSUSE instruction.");
  
    
    unsigned long is2;
    bool found = false;
    for (is2 = 0; is2 < reg.unions.length(); ++is2)
    {
     if (reg.unions[is2].name() == reg.union_name)
     {
      found = true;
      break;
     }
    }
  
    if (!found)
     crash((char *)"object: " + reg.union_name + " not found.");
   
    bool uvalue = reg.ounions[is2].Use(reg.union_name);

    if (!uvalue)
     crash(reg.union_name + (char *)"." + reg.union_name + (char *)": not found.");
   }
   break;

   case TNUMBER:
   {
    if (reg.operand != 0)
     crash((char *)"Invaild UNIONUSE instruction.");

    unsigned long is2;
    bool found = false;
    for (is2 = 0; is2 < reg.ounions.length(); ++is2)
    {
     if (reg.ounions[is2].name() == reg.union_name)
     {
      found = true;
      break;
     }
    }
  
    if (!found)
     crash((char *)"object: " + reg.union_name + " not found.");
  
    bool uvalue = reg.ounions[is2].Use((unsigned long)reg.accumulator.object().simple().to_number().get());

    char str1[1000];
    sprintf(str1, "%lu", (unsigned long)reg.accumulator.object().simple().to_number().get());
    String str = str1;

    if (!uvalue)
     crash(reg.union_name + (char *)"." + str + (char *)": not found.");
   }
   break;

   case TSTRING:
   {
    String str = (char *)"";
    unsigned long is;
    for (is = k; mem.get(is) != 0; ++is)
     str += (char)mem.get(is);
  
    
    unsigned long is2;
    bool found = false;
    for (is2 = 0; is2 < reg.ounions.length(); ++is2)
    {
     if (reg.ounions[is2].name() == reg.union_name)
     {
      found = true;
      break;
     }
    }
  
    if (!found)
     crash((char *)"object: " + reg.union_name + " not found.");
   
    bool uvalue = reg.ounions[is2].Use(str);
 
    if (!uvalue)
     crash(reg.union_name + (char *)"." + str + (char *)": not found.");


    i = is + 1;
    j = i + 1;
    k = i + 2;

    i -= 3, j -= 3, k -= 3;
   }
   break;


   default:
    crash((char *)"Invalid UNIONUSE instruction.");
  };
 }
 break;

 case IUNIONUSING:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild UNIONUSING instruction.");

  unsigned long is2;
  bool found = false;
  for (is2 = 0; is2 < reg.ounions.length(); ++is2)
  {
   if (reg.ounions[is2].name() == reg.union_name)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"object: " + reg.union_name + " not found.");

  reg.accumulator.object().simple().put((PNF_Number)reg.ounions[is2].Using());
 }
 break;

 case IUNIONUSINGNAME:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild UNIONUSINGNAME instruction.");

  unsigned long is2;
  bool found = false;
  for (is2 = 0; is2 < reg.ounions.length(); ++is2)
  {
   if (reg.ounions[is2].name() == reg.union_name)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"object: " + reg.union_name + " not found.");

  reg.accumulator.object().simple().put(reg.ounions[is2].UsingName());
 }
 break;

 case IUNIONGET:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild UNIONGET instruction.");

  unsigned long is2;
  bool found = false;
  for (is2 = 0; is2 < reg.unions.length(); ++is2)
  {
   if (reg.ounions[is2].name() == reg.union_name)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"object: " + reg.union_name + " not found.");

  reg.accumulator.object(reg.ounions[is2].get().object());
 }
 break;

case IUNIONPUT:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild UNIONPUT instruction.");

  unsigned long is2;
  bool found = false;
  for (is2 = 0; is2 < reg.ounions.length(); ++is2)
  {
   if (reg.ounions[is2].name() == reg.union_name)
   {
    found = true;
    break;
   }
  }
  
  if (!found)
   crash((char *)"object: " + reg.union_name + " not found.");

  reg.ounions[is2].put(reg.accumulator, reg.ounions[is2].UsingName());
 }
 break;

 case IUNIONTYPE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild UNIONTYPE instruction.");

  reg.accumulator.object().simple().put(reg.union_type);
 }
 break;

 case IUNIONTYPE2:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild UNIONTYPE2 instruction.");

  reg.union_type = reg.accumulator.object().simple().to_string().get();
 }
 break;

 case IUNIONNAME2:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild UNIONNAME2 instruction.");

  reg.accumulator.object().simple().put(reg.union_name);
 }
 break;

 case IUNIONNAME3:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild UNIONNAME3 instruction.");

  reg.union_name = reg.accumulator.object().simple().to_string().get();
 }
 break;

 case IMODE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild MODE instruction.");

  // One mode so far, so does nothing...
 }
 break;

 case IEXTMODE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild EXTMODE instruction.");

  // One extmode so far, so does nothing...
 }
 break;

   case IMCHECK:
   {
    PNF_Void v;
    bool s = reg.version.check(v, 1);

    if (s == false)
     crash((char *)"Invalid instruction. Not in this version.");


    bool vcheck = false;
    PNF_Boolean b;
    switch (reg.mode.base.getType())
    {
   	 case TVOID:
   	 {
   	  if ((unsigned long)reg.mode.top == reg.operand)
   	  {
   	   vcheck = true;
   	   b.put(vcheck);
   	   reg.accumulator.object().simple().put(b);
   	  }
   	  else
   	  {
   	   vcheck = false;
   	   b.put(vcheck);
   	   reg.accumulator.object().simple().put(b);
   	  }
   	 }
   	 break;

   	 default:
   	 {
   	  vcheck = false;
   	  b.put(vcheck);
   	  reg.accumulator.object().simple().put(b);
   	 }
    }
   }
   break;

   case IMSUPP:
   {
    PNF_Void v;
    bool s = reg.version.check(v, 1);

    if (s == false)
     crash((char *)"Invalid instruction. Not in this version.");


    bool vcheck = false;
    PNF_Boolean b;

    for (unsigned long l = 0; l < reg.smode.length(); ++l)
    {
     switch (reg.smode[l].base.getType())
     {
      case TVOID:
      {
   	   if ((unsigned long)reg.smode[l].top == reg.operand)
   	   {
   	   	vcheck = true;
        b.put(vcheck);
        reg.accumulator.object().simple().put(b);
        goto endloop2;
       }
   	   else
   	   {
        vcheck = false;
        b.put(vcheck);
        reg.accumulator.object().simple().put(b);
       }
   	  }
      break;

      default:
      {
       vcheck = false;
   	   b.put(vcheck);
   	   reg.accumulator.object().simple().put(b);
   	  }
     }
    }
    endloop2:
     ;
   }
   break;

   case IMEXTCHECK:
   {
    PNF_Void v;
    bool s = reg.version.check(v, 1);

    if (s == false)
     crash((char *)"Invalid instruction. Not in this version.");


    bool vcheck = false;
    PNF_Boolean b;
    switch (reg.extmode.base.getType())
    {
   	 case TVOID:
   	 {
   	  if ((unsigned long)reg.extmode.top == reg.operand)
   	  {
   	   vcheck = true;
   	   b.put(vcheck);
   	   reg.accumulator.object().simple().put(b);
   	  }
   	  else
   	  {
   	   vcheck = false;
   	   b.put(vcheck);
   	   reg.accumulator.object().simple().put(b);
   	  }
   	 }
   	 break;

   	 default:
   	 {
   	  vcheck = false;
   	  b.put(vcheck);
   	  reg.accumulator.object().simple().put(b);
   	 }
    }
   }
   break;

   case IMEXTSUPP:
   {
    PNF_Void v;
    bool s = reg.version.check(v, 1);

    if (s == false)
     crash((char *)"Invalid instruction. Not in this version.");


    bool vcheck = false;
    PNF_Boolean b;

    for (unsigned long l = 0; l < reg.sextmode.length(); ++l)
    {
     switch (reg.sextmode[l].base.getType())
     {
      case TVOID:
      {
   	   if ((unsigned long)reg.sextmode[l].top == reg.operand)
   	   {
   	   	vcheck = true;
        b.put(vcheck);
        reg.accumulator.object().simple().put(b);
        goto endloop3;
       }
   	   else
   	   {
        vcheck = false;
        b.put(vcheck);
        reg.accumulator.object().simple().put(b);
       }
   	  }
      break;

      default:
      {
       vcheck = false;
   	   b.put(vcheck);
   	   reg.accumulator.object().simple().put(b);
   	  }
     }
    }
    endloop3:
     ;
   }
   break;

 case ICPY:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild CPY instruction.");
  
  unsigned long addr1 = (unsigned long)reg.accumulator.object().simple().to_number().get();
  unsigned long addr2 = (unsigned long)reg.calc.object().simple().to_number().get();

  double m = mem.get(addr1);
  mem.put(addr2, m);
 }
 break;

 case IADDSEG:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild ADDSEG instruction.");

  segments.insert();
 }
 break;

 case IREMSEG:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild REMSEG instruction.");

  segments.remove();
 }
 break;

 case ICOLLSEG:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TNUMBER)
   crash((char *)"Invaild COLLSEG instruction.");

  mem = segments[reg.operand].mem();
  stk = segments[reg.operand].stk();

  i = -3;
  j = i + 1;
  k = i + 1;
 }
 break;

 case IEXPSEG:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TNUMBER)
   crash((char *)"Invaild EXPSEG instruction.");

  segments[reg.operand].mem(mem);
  segments[reg.operand].stk(stk);
 }
 break;

 case ICPYSEG:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild CPYSEG instruction.");

  unsigned long seg1 = (unsigned long)reg.accumulator.object().simple().to_number().get();
  unsigned long seg2 = (unsigned long)reg.calc.object().simple().to_number().get();

  segments[seg2] = segments[seg1];
 }
 break;

 case ISEGLOAD:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TNUMBER)
   crash((char *)"Invaild SEGLOAD instruction.");

  unsigned long seg = (unsigned long)reg.calc.object().simple().to_number().get();
  reg.accumulator.object().simple().put((PNF_Number)segments[seg].mem().get(reg.operand));
 }
 break;

 case ISEGSTORE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TNUMBER)
   crash((char *)"Invaild SEGLOAD instruction.");

  unsigned long seg = (unsigned long)reg.calc.object().simple().to_number().get();
  segments[seg].mem().put(reg.operand, reg.accumulator.object().simple().to_number().get());
 }
 break;

 case ISEGPUSH:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild SEGPUSH instruction.");

  unsigned long seg = (unsigned long)reg.calc.object().simple().to_number().get();
  segments[seg].stk().push(reg.accumulator.object().simple());
 }
 break;

 case ISEGPOP:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild SEGPOP instruction.");

  unsigned long seg = (unsigned long)reg.calc.object().simple().to_number().get();
  reg.accumulator = segments[seg].stk().pop();
 }
 break;

 case ISEGTOP:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  if (reg.type != TVOID && reg.operand != 0)
   crash((char *)"Invaild SEGTOP instruction.");

  unsigned long seg = (unsigned long)reg.calc.object().simple().to_number().get();
  reg.accumulator = segments[seg].stk().top();
 }
 break;

 case ISEGVLOAD:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  unsigned long seg = (unsigned long)reg.calc.object().simple().to_number().get();

  
	 double m;
         double * pm;


         reg.accumulator.object().simple().setType(reg.type);
         reg.operand = reg.varcount.get(reg.operand).address();

         switch (reg.accumulator.object().simple().getType())
         {
          case TBOOLEAN:
               m = segments[seg].mem().get(reg.operand);
               pm = &m;

               reg.accumulator.object().simple().putm(pm);
               break;

          case TNUMBER:
               m = segments[seg].mem().get(reg.operand);
               pm = &m;

               reg.accumulator.object().simple().putm(pm);
               break;

          case TCHARACTER:
               pm = &m;
               *pm = segments[seg].mem().get(reg.operand);
               reg.accumulator.object().simple().putm(pm);
               break;

          case TSTRING:
          {
               String str = (char *)"";
               for (unsigned long n = reg.operand; segments[seg].mem().get(n) != 0; ++n)
               {
                char ch = (char)segments[seg].mem().get(n);
                str += ch;
               }
               PNF_String str2(str.getString());
               reg.accumulator.object().simple().put(str2);
          }
          break;

          default:
           crash((char *)"Invalid Type.");
           break;
         }
         break;
 }
 break;

 case ISEGVSTORE:
 {
  PNF_Void v;
  bool s = reg.version.check(v, 1);

  if (s == false)
   crash((char *)"Invalid instruction. Not in this version.");

  unsigned long seg = (unsigned long)reg.calc.object().simple().to_number().get();


        switch (reg.type)
         {
          case TVOID:
          {
           if (reg.operand != 0)
            crash((char *)"Invalid Operand.");

           long j = (segments[seg].mem().length() - 4) < 0 ? (segments[seg].mem().length() - 1) : (segments[seg].mem().length() - 4);
           segments[seg].mem().put(j, IVAR);
           segments[seg].mem().put(j + 1, TVOID);
           double * pm;
           pm = reg.accumulator.object().simple().getm();


           reg.varcount.insert();
           reg.varcount.put(j + 2, reg.varcount.length() - 1);

           switch (reg.accumulator.object().simple().getType())
           {
            case TVOID:
             segments[seg].mem().put(j + 2, *pm);
             break;

            case TBOOLEAN:
             segments[seg].mem().put(j + 2, *pm);
             break;

            case TNUMBER:
             segments[seg].mem().put(j + 2, *pm);
             break;

            case TCHARACTER:
             segments[seg].mem().put(j + 2, *pm);
             break;

            case TSTRING:
             unsigned long i;
             for (i = 0; pm[i] != 0; ++i)
              segments[seg].mem().put((j + 2) + i, pm[i]);
             segments[seg].mem().put((j + 2) + i, 0);
             break;


            default:
             crash((char *)"Invalid Type.");
           }

           for (unsigned long j = 0, k = 0; j != segments[seg].mem().length(); ++j)
           {
            if (mem.get(j) == IVAR && mem.get(j + 1) == TVOID)
            {
      	     reg.varcount[k].address(j + 2);
             reg.varcount.put(j + 2, k);
             reg.varcount.insert();
             ++k;
            }
           }
          }
          break;

          case TNUMBER:
          {
           long j = reg.varcount.get(reg.operand).address();
           double * pm;
           pm = reg.accumulator.object().simple().getm();

           switch (reg.accumulator.object().simple().getType())
           {
            case TVOID:
             segments[seg].mem().put(j, *pm);
             break;

            case TBOOLEAN:
             segments[seg].mem().put(j, *pm);
             break;

            case TNUMBER:
             segments[seg].mem().put(j, *pm);
             break;

            case TCHARACTER:
             segments[seg].mem().put(j, *pm);
             break;

            case TSTRING:
             unsigned long i;
             for (i = 0; pm[i] != 0; ++i)
              segments[seg].mem().put((j) + i, pm[i]);
             break;


            default:
             crash((char *)"Invalid Type.");
            }
           }
           break;

           default:
            crash((char *)"Invalid Type Identifier.");
            break;
          }


    // Put the address of the variables in varcount.
    for (unsigned long j = 0, k = 0; j != segments[segments.length() - 1].mem().length(); ++j)
    {
     if (segments[segments.length() - 1].mem().get(j) == IVAR)
     {
      reg.varcount[k].address(j + 2);
      reg.varcount[k].type(segments[segments.length() - 1].mem().get(j + 1));
      reg.varcount.insert();
      ++k;
     }
    }
   }
   break;
   
   
   default:
    crash((char *)"Invalid Instruction.");
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



  // Load the previous instruction register
  reg.pinstruction = reg.instruction;
  reg.pins = reg.mins;


  // Quit if needed
  if (quitFound)
   exit(quitValue);


  // Variables
  if (inRet)
   inRet = false;
  }
 }
 catch (Exception e)
 {
  e.file(__FILE__);
  e.line(__LINE__);
  e.display();
  exit(-1);
 }
 catch (...)
 {
  error(ERRORMSG, "Uncaught Exception.");
  exit(-1);
 }
}

ProgramState PNF::builtin_breakpoint_exception(ProgramState state)
{
 // Nothing needed at this time...


 return state;
}

ProgramState PNF::builtin_invalid_range1_exception(ProgramState state)
{
 crash((char *)"Invalid Range1 Exception.");
}

ProgramState PNF::builtin_invalid_range2_exception(ProgramState state)
{
 crash((char *)"Invalid Range2 Exception.");
}

ProgramState PNF::builtin_invalid_enum_exception(ProgramState state)
{
 crash((char *)"Invalid Enum Exception.");
}
