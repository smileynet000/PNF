VERSION TVOID 0V


; Begin if :1
ALOAD TBOOLEAN true
CGOTOL TSTRING "iftrue_1"
GOTOL TSTRING "iffalse_or_end_1"


; Begin if code :1
LBL TSTRING "iftrue_1"
PRINTLN TSTRING "a..."
; End if code :1
GOTOL TSTRING "iffalse_or_end_1"


; Begin iffalse_or_end :1
LBL TSTRING "iffalse_or_end_1"
QUIT TVOID 0

END TVOID 0V