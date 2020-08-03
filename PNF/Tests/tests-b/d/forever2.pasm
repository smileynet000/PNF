VERSION TVOID 0V


GOTOL TSTRING "end_1_1"
GOTOL TSTRING "end_1"


; Begin iffalse_or_end :1
LBL TSTRING "iffalse_or_end_1"


LBL TSTRING "end_1_1"
LBL TSTRING "forever_1"
; Begin if :1
ALOAD TBOOLEAN true
CGOTOL TSTRING "iftrue_1"
GOTOL TSTRING "iffalse_or_end_1"


; Begin if code :1
LBL TSTRING "iftrue_1"
GOTOL TSTRING "forever_end_1"
GOTOL TSTRING "end_1_1"
GOTOL TSTRING "end_1"


; Begin iffalse_or_end :1
LBL TSTRING "iffalse_or_end_1"


LBL TSTRING "end_1_1"
PRINTLN TSTRING "a..."
GOTOL TSTRING "forever_1"
LBL TSTRING "forever_end_1"
QUIT TVOID 0

END TVOID 0V