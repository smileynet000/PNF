VERSION TVOID 0V


ALOAD TNUMBER 0
VSTORE TVOID 0V
PRINT TSTRING "How many hellos?: "
READ TNUMBER 0V
ATOC TVOID 0V
VADD TVOID 0
SWITCH TVOID 0V
STOREA TVOID 0V
ATOC TVOID 0V
ALOAD TNUMBER 0
SWITCH TVOID 0V
PUSH TVOID 0V
LBL TSTRING "do_while_body_1"
POP TVOID 0V
PRINTLN TSTRING "Hello!"
DEC TVOID 0V
SWITCH TVOID 0V
LBL TSTRING "do_while_test_1"
SWITCH TVOID 0V
PUSH TVOID 0V
GTR TVOID 0V
CGOTOL TSTRING "do_while_body_1"
GOTOL TSTRING "do_while_end_1"
LBL TSTRING "do_while_end_1"
SWITCH TVOID 0V
PRINT TSTRING "Counter is output: "
PRINTLN TVOID 0V
QUIT TVOID 0


END TVOID 0V