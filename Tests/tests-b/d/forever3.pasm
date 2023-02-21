VERSION TVOID 0V


LBL TSTRING "forever_1"
; Begin if :1
ALOAD TBOOLEAN false
CGOTOL TSTRING "iftrue_1"
GOTOL TSTRING "iffalse_or_end_1"


; Begin if code :1
LBL TSTRING "iftrue_1"
GOTOL TSTRING "forever_end_1"
; End if code :1
GOTOL TSTRING "end_1"


; Begin iffalse_or_end :1
LBL TSTRING "iffalse_or_end_1"


LBL TSTRING "end_1_1"
PRINTLN TSTRING "a..."
; End if or else code :1
GOTOL TSTRING "end_1"


LBL TSTRING "end_1"
; End if :1
GOTOL TSTRING "forever_1"
LBL TSTRING "forever_end_1"
QUIT TVOID 0

END TVOID 0V