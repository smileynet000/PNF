VERSION TVOID 0V


ALOAD TNUMBER 0
VSTORE TVOID 0V
PRINT TSTRING "Loop until: "
READ TNUMBER 0V
VSTORE TVOID 0V
PRINTLN TSTRING ""
LBL TSTRING "for_initialization_1"
ALOAD TNUMBER 0
VSTORE TVOID 0V
LBL TSTRING "for_condition_1"
VADD TVOID 1
ADD2V TVOID 0V
ATOC TVOID 0V
VADD TVOID 2
ADD2V TVOID 0V
LSS TVOID 0V
CGOTOL TSTRING "for_body_1"
GOTOL TSTRING "for_end_1"
LBL TSTRING "for_increment_statement_1"
VADD TVOID 2
ATOC TVOID 0V
VADD TVOID 2
ADD2V TVOID 0V
INC TVOID 0V
STOREA TVOID 0V
GOTOL TSTRING "for_condition_1"
LBL TSTRING "for_body_1"
VADD TVOID 2
ADD2V TVOID 0V
PRINTLN TVOID 0V
GOTOL TSTRING "for_increment_statement_1"
LBL TSTRING "for_end_1"
QUIT TVOID 0

END TVOID 0V