VERSION TVOID 0V


PRINTLN TSTRING "Before subroutine!"
CALLL TSTRING "subtest"
PRINTLN TSTRING "After subroutine!"
QUIT TVOID 0
LBL TSTRING "subtest"
PRINTLN TSTRING "In subroutine!"
RET TVOID 0V

END TVOID 0V