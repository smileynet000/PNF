VERSION TVOID 0V


ALOAD TSTRING "Chris"
ATOC TVOID 0V

ALOAD TSTRING "Dennis"
EQU TVOID 0V
CGOTOL TSTRING "Dennis"
ALOAD TSTRING "Chris"
EQU TVOID 0V
CGOTOL TSTRING "Chris"
GOTOL TSTRING "default"

LBL TSTRING "Dennis"
PRINTLN TSTRING "Dennis"
GOTOL TSTRING "after_switch"

LBL TSTRING "Chris"
PRINTLN TSTRING "Chris"
GOTOL TSTRING "after_switch"

LBL TSTRING "default"
PRINTLN TSTRING "Unknown name..."
GOTOL TSTRING "after_switch"


LBL TSTRING "after_switch"
QUIT TVOID 0


END TVOID 0V