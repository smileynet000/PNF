VERSION TVOID 0V


; Begin if :1
ALOAD TBOOLEAN false
CGOTOL TSTRING "iftrue_1"
GOTOL TSTRING "iffalse_or_end_1"


; Begin if code :1
LBL TSTRING "iftrue_1"
VOID TVOID 0V
; End if code :1
GOTOL TSTRING "end_1"


; Begin iffalse_or_end :1
LBL TSTRING "iffalse_or_end_1"
; Begin if :2
ALOAD TBOOLEAN false
CGOTOL TSTRING "iftrue_2"
GOTOL TSTRING "iffalse_or_end_2"


; Begin if code :2
LBL TSTRING "iftrue_2"
VOID TVOID 0V
; End if code :2
GOTOL TSTRING "end_2"


; Begin iffalse_or_end :2
LBL TSTRING "iffalse_or_end_2"
VOID TVOID 0V
; End if or else code :2
GOTOL TSTRING "end_2"


LBL TSTRING "end_2"
; End if :2
; End if or else code :1
GOTOL TSTRING "end_1"


LBL TSTRING "end_1"
; End if :1

END TVOID 0V