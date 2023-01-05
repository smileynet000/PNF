VERSION TVOID 0V


ALOAD TNUMBER 5
VSTORE TVOID 0V
VLOAD TNUMBER 0
INC TVOID 0V
ATOC TVOID 0V
ALOAD TNUMBER 5
SWITCH TVOID 0V
EQU TVOID 0V
CGOTOL TSTRING "top_iftrue_1"
GOTOL TSTRING "top_iffalse_1"
LBL TSTRING "top_iftrue_1"
PRINT TSTRING "a = "
PRINTLN TNUMBER 5
GOTOL TSTRING "top_end_1"
LBL TSTRING "top_iffalse_1"
PRINTLN TSTRING "Other value."
GOTOL TSTRING "top_end_1"
LBL TSTRING "top_end_1"
; Begin if :1
ALOAD TBOOLEAN true
CGOTOL TSTRING "iftrue_1"
GOTOL TSTRING "iffalse_or_end_1"


; Begin if code :1
LBL TSTRING "iftrue_1"
PRINT TSTRING "a = "
PRINTLN TNUMBER 5
; End if code :1
GOTOL TSTRING "end_1"


; Begin iffalse_or_end :1
LBL TSTRING "iffalse_or_end_1"
PRINTLN TSTRING "Other value."
; End if or else code :1
GOTOL TSTRING "end_1"


LBL TSTRING "end_1"
; End if :1
QUIT TVOID 0


END TVOID 0V