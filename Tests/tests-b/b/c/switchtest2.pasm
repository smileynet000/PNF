VERSION TVOID 0V


ALOAD TSTRING "Dennis"
VSTORE TVOID 0V
ALOAD TSTRING "Dennis"
ATOC TVOID 0V
LBL TSTRING "skip_switch_case_1_1"
ALOAD TSTRING "Dennis"
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_1"
GOTO TSTRING "skip_switch_case_1_2"
LBL TSTRING "switch_case_1_1"
PRINTLN TSTRING "Dennis"
GOTOL TSTRING "after_switch_1"
LBL TSTRING "skip_switch_case_1_2"
ALOAD TSTRING "Chris"
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_2"
LBL TSTRING "switch_case_1_2"
PRINTLN TSTRING "Chris"
GOTOL TSTRING "after_switch_1"
GOTOL TSTRING "default_switch_1"
LBL TSTRING "default_switch_1"
PRINTLN TSTRING "Unknown name"
LBL TSTRING "after_switch_1"

END TVOID 0V