VERSION TVOID 1
EXTMODE TVOID 1


PRINTLN TSTRING "test"

ALOAD TNUMBER 1
ATOC TVOID 0V
ALOAD TNUMBER 2
SWITCH TVOID 0V
EQU TVOID 0V
CGOTOL TSTRING "done"
GOTOL TSTRING "test1"


LBL TSTRING "test1"
PRINTLN TSTRING "test1"

ALOAD TNUMBER 5
ATOC TVOID 0V
ALOAD TNUMBER 1
SWITCH TVOID 0V
NEQU TVOID 0V
CGOTOL TSTRING "test2"
GOTOL TSTRING "done"

LBL TSTRING "test2"
PRINTLN TSTRING "test2"

LBL TSTRING "done"
PRINTLN TSTRING "done!"
QUIT TVOID 0


END TVOID 0V