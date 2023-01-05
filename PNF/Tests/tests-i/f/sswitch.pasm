VERSION TVOID 0V


ALOAD TSTRING "Dennis"
VSTORE TVOID 0V
ALOAD TSTRING "Dennis"
ATOC TVOID 0V
LBL TSTRING "skip_switch_case_1_1"
ALOAD TSTRING "Dennis"
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_1"
GOTOL TSTRING "skip_switch_case_1_2"
LBL TSTRING "switch_case_1_1"
PRINTLN TSTRING "Cool name!"
GOTOL TSTRING "after_switch_1"
LBL TSTRING "skip_switch_case_1_2"
ALOAD TSTRING "Amy"
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_2"
GOTOL TSTRING "skip_switch_case_1_3"
LBL TSTRING "switch_case_1_2"
PRINTLN TSTRING "That's my sister!"
GOTOL TSTRING "after_switch_1"
LBL TSTRING "skip_switch_case_1_3"
ALOAD TSTRING "Michael"
EQU TVOID 0V
CGOTOL TSTRING "switch_case_1_3"
GOTOL TSTRING "default_switch_1"
LBL TSTRING "switch_case_1_3"
PRINTLN TSTRING "He's my friend!"
GOTOL TSTRING "after_switch_1"
GOTOL TSTRING "default_switch_1"
LBL TSTRING "default_switch_1"
PRINTLN TSTRING "I didn't recognize the name."
GOTOL TSTRING "after_switch_1"
LBL TSTRING "after_switch_1"
QUIT TVOID 0


END TVOID 0V