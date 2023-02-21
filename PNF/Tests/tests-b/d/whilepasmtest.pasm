VERSION TVOID 0V


GOTOL TSTRING "while_after_variables"
VAR TVOID 0 ; 29
VAR TVOID 0 ; 32
LBL TSTRING "while_after_variables"
PRINT TSTRING "Loop until: "
READ TNUMBER 0V
STORE TVOID 29 ; Contains number read...
ALOAD TNUMBER 0
ATOC TVOID 0V
LOAD TNUMBER 29
SWITCH TVOID 0V
STORE TVOID 32 ; Contains 0...
; Test
LBL TSTRING "while_test"
LOAD TNUMBER 32
LOADC TNUMBER 29
LSS TVOID 0V
CGOTOL TSTRING "while_body"
GOTOL TSTRING "while_end"
; Beginning of body
LBL TSTRING "while_body"
LOAD TNUMBER 32
; Body
PRINTLN TVOID 0V
INC TVOID 0V
STORE TVOID 32
; End of Body
GOTOL TSTRING "while_test"
; End of Loop
LBL TSTRING "while_end"


QUIT TVOID 0


END TVOID 0V