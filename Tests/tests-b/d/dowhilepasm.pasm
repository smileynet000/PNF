VERSION TVOID 0V


ALOAD TNUMBER 0
VSTORE TVOID 0V
PRINT TSTRING "Loop until: "
READ TNUMBER 0V
VSTORE TVOID 0V
PRINTLN TSTRING ""

; Do...While loop...
LBL TSTRING "dowhile_body"
VADD TVOID 0
ADD2V TVOID 0V
PRINTLN TVOID 0V
VADD TVOID 0
ATOC TVOID 0V
VADD TVOID 0
ADD2V TVOID 0V
INC TVOID 0V
STOREA TVOID 0V
LBL TSTRING "dowhile_test"
VADD TVOID 1
ADD2V TVOID 0V
ATOC TVOID 0V
VADD TVOID 0
ADD2V TVOID 0V
LSS TVOID 0V
CGOTOL TSTRING "dowhile_body"
GOTOL TSTRING "dowhile_end"
LBL TSTRING "dowhile_end"

QUIT TVOID 0


END TVOID 0V