VERSION TVOID 0V


ALOAD TNUMBER 5
VSTORE TVOID 0V
EQU TVOID 0V
CGOTOL TSTRING "top_iftrue_1"
GOTOL TSTRING "top_iffalse_1"
LBL TSTRING "top_iftrue_1"
PRINT TSTRING "a = "
PRINTLN TNUMBER 5
GOTOL TSTRING "top_end_1"
LBL TSTRING "top_iffalse_1"
VOID TVOID 0V
GOTOL TSTRING "top_end_1"
LBL TSTRING "top_end_1"
PRINTLN TSTRING "Done!"
QUIT TVOID 0


END TVOID 0V