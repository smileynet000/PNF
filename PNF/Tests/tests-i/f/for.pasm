VERSION TVOID 0V


LBL TSTRING "for_initialization_1"
ALOAD TNUMBER 1
ATOC TVOID 0V
ALOAD TNUMBER 6
LBL TSTRING "for_condition_1"
SWITCH TVOID 0V
PUSH TVOID 0V
LSS TVOID 0V
CGOTOL TSTRING "for_body_1"
GOTOL TSTRING "for_end_1"
LBL TSTRING "for_increment_statement_1"
INC TVOID 0V
SWITCH TVOID 0V
GOTOL TSTRING "for_condition_1"
LBL TSTRING "for_body_1"
POP TVOID 0V
PRINT TSTRING "%accumulator = "
PRINTLN TVOID 0V
GOTOL TSTRING "for_increment_statement_1"
LBL TSTRING "for_end_1"
QUIT TVOID 0


END TVOID 0V