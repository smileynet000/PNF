VERSION TVOID 0V


; Begin if :1
ALOAD TBOOLEAN false
CGOTOL TSTRING "iftrue_1"
GOTOL TSTRING "iffalse_or_end_1"


LBL TSTRING "iftrue_1"
VOID TVOID 0V
; End if code :1
GOTOL TSTRING "end_1"


LBL TSTRING "iffalse_or_end_1"
VOID TVOID 0V
; End if or else code :1
GOTOL TSTRING "end_1"


LBL TSTRING "end_1"
; End if :1

END TVOID 0V