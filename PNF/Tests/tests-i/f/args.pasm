VERSION TVOID 0V


ARNLOAD TVOID 0V
GOTOL TSTRING "default_switch_2"
ATOC TVOID 0V
LBL TSTRING "skip_switch_case_1_1"
ALOAD TNUMBER 4
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_1"
GOTOL TSTRING "skip_switch_case_1_2"
LBL TSTRING "switch_case_1_1"
ARLOAD TVOID 5
ATOC TVOID 0V
LBL TSTRING "skip_switch_case_2_1"
ALOAD TSTRING "a"
EQU TVOID 0V
CGOTOL TSTRING "switch_case_2_1"
GOTOL TSTRING "skip_switch_case_2_2"
LBL TSTRING "switch_case_2_1"
GOTOL TSTRING "after_switch_2"
GOTOL TSTRING "switch_case_2_2"
GOTOL TSTRING "default_switch_2"
LBL TSTRING "default_switch_2"
PRINTLN TSTRING "I don't know that name."
LBL TSTRING "after_switch_2"
GOTOL TSTRING "after_switch_2"
GOTOL TSTRING "switch_case_2_2"
GOTOL TSTRING "default_switch_2"
LBL TSTRING "default_switch_2"
PRINTLN TSTRING "* ERROR: Wrong arguments."
LBL TSTRING "after_switch_2"
QUIT TVOID 0


END TVOID 0V