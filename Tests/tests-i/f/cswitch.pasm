VERSION TVOID 0V


ALOAD TNUMBER 0
VSTORE TVOID 0V
PRINT TSTRING "Enter a number: "
READ TNUMBER 0V
ATOC TVOID 0V
VADD TVOID 0
SWITCH TVOID 0V
STOREA TVOID 0V
VLOAD TNUMBER 1
ATOC TVOID 0V
LBL TSTRING "skip_switch_case_1_1"
ALOAD TNUMBER 0
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_1"
GOTOL TSTRING "skip_switch_case_1_2"
LBL TSTRING "switch_case_1_1"
PRINTLN TSTRING "Too small!"
GOTOL TSTRING "after_switch_1"
GOTOL TSTRING "switch_case_1_2"
LBL TSTRING "skip_switch_case_1_2"
ALOAD TNUMBER 5
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_2"
GOTOL TSTRING "skip_switch_case_1_3"
LBL TSTRING "switch_case_1_2"
PRINTLN TSTRING "Good job!"
GOTOL TSTRING "switch_case_1_3"
LBL TSTRING "skip_switch_case_1_3"
ALOAD TNUMBER 4
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_3"
GOTOL TSTRING "skip_switch_case_1_4"
LBL TSTRING "switch_case_1_3"
PRINTLN TSTRING "Nice pick!"
GOTOL TSTRING "switch_case_1_4"
LBL TSTRING "skip_switch_case_1_4"
ALOAD TNUMBER 3
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_4"
GOTOL TSTRING "skip_switch_case_1_5"
LBL TSTRING "switch_case_1_4"
PRINTLN TSTRING "Excelent!"
GOTOL TSTRING "switch_case_1_5"
LBL TSTRING "skip_switch_case_1_5"
ALOAD TNUMBER 2
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_5"
GOTOL TSTRING "skip_switch_case_1_6"
LBL TSTRING "switch_case_1_5"
PRINTLN TSTRING "Masterful!"
GOTOL TSTRING "switch_case_1_6"
LBL TSTRING "skip_switch_case_1_6"
ALOAD TNUMBER 1
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_6"
GOTOL TSTRING "default_switch_1"
LBL TSTRING "switch_case_1_6"
PRINTLN TSTRING "Incredible!"
GOTOL TSTRING "after_switch_1"
GOTOL TSTRING "switch_case_1_7"
GOTOL TSTRING "default_switch_1"
LBL TSTRING "default_switch_1"
PRINTLN TSTRING "Too big!"
LBL TSTRING "after_switch_1"
QUIT TVOID 0


END TVOID 0V