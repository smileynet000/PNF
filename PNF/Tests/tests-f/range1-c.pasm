VERSION TVOID 0V


PRINTLN TSTRING "Defining a range..."
RDSTART1 TSTRING "a"
RFROM1 TNUMBER 0
RTO1 TNUMBER 4
RDEND1 TVOID 0V


PRINTLN TSTRING "Implementing a range..."
RSTART1 TSTRING "a"
RANGE1 TNUMBER 3
REND1 TSTRING "a"


PRINTLN TSTRING "Testing load and store..."
RLOAD1 TSTRING "a"
PRINT TSTRING "Range 1 value: "
PRINTLN TVOID 0V

PRINT TSTRING "Enter a number: "
READ TNUMBER 0V
RSTORE1 TSTRING "a"

RLOAD1 TSTRING "a"
PRINT TSTRING "Range 1 value: "
PRINTLN TVOID 0V


PRINTLN TSTRING "Quitting..."

QUIT TVOID 0


END TVOID 0V