VERSION TVOID 0V


ALOAD TNUMBER 0
VSTORE TVOID 0V
PRINT TSTRING "Enter a number: "
READ TNUMBER 0V
ATOC TVOID 0V
VADD TVOID 0
SWITCH TVOID 0V
STOREA TVOID 0V
PRINT TSTRING "a: "
VADD TVOID 0
ADD2V TVOID 0V
PRINTLN TVOID 0V
VADD TVOID 0
ADD2V TVOID 0V
ATOC TVOID 0V
ALOAD TNUMBER 33
SWITCH TVOID 0V
EQU TVOID 0V
CGOTOL TSTRING "top_iftrue_1"
GOTOL TSTRING "top_iffalse_1"
LBL TSTRING "top_iftrue_1"
PRINTLN TSTRING "33"
GOTOL TSTRING "top_end_1"
LBL TSTRING "top_iffalse_1"
PRINTLN TSTRING "Not 33"
GOTOL TSTRING "top_end_1"
LBL TSTRING "top_end_1"
QUIT TVOID 0


END TVOID 0V