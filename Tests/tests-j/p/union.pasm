VERSION TVOID 1


STRUCT TSTRING "a"
STRUCTVAR TSTRING "a"
STRUCTVAR TSTRING "b"
ENDSTRUCT TVOID 0V

STRUCTNAME TSTRING "a"
STRUCTD TSTRING "ainst"

STRUCTONAME TSTRING "ainst"
STRUCTUSE TSTRING "b"

STRUCTUSING TVOID 0V
PRINTLN TVOID 0V
STRUCTUSE TNUMBER 0V
STRUCTUSING TVOID 0V
PRINTLN TVOID 0V


ALOAD TSTRING "Hello World!"
STRUCTPUT TVOID 0V

ALOAD TSTRING "a"
PRINTLN TVOID 0V
PRINT TSTRING "("
STRUCTTYPE TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ") "
STRUCTNAME2 TVOID 0V
PRINT TVOID 0V
PRINT TSTRING "."
STRUCTUSINGNAME TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ": "
STRUCTGET TVOID 0V
PRINTLN TVOID 0V

STRUCTUSE TSTRING "a"
ALOAD TSTRING "Devon"
STRUCTPUT TVOID 0V

PRINT TSTRING "("
STRUCTTYPE TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ") "
STRUCTNAME2 TVOID 0V
PRINT TVOID 0V
PRINT TSTRING "."
STRUCTUSINGNAME TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ": "
STRUCTGET TVOID 0V
PRINTLN TVOID 0V

STRUCTUSE TSTRING "b"

PRINT TSTRING "("
STRUCTTYPE TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ") "
STRUCTNAME2 TVOID 0V
PRINT TVOID 0V
PRINT TSTRING "."
STRUCTUSINGNAME TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ": "
STRUCTGET TVOID 0V
PRINTLN TVOID 0V


PRINTLN TSTRING ""
PRINTLN TSTRING ""

UNION TSTRING "a"
UNIONVAR TSTRING "a"
UNIONVAR TSTRING "b"
ENDUNION TVOID 0V

UNIONNAME TSTRING "a"
UNIOND TSTRING "ainst"

UNIONONAME TSTRING "ainst"
UNIONUSE TSTRING "b"

UNIONUSING TVOID 0V
PRINTLN TVOID 0V
UNIONUSE TNUMBER 0V
UNIONUSING TVOID 0V
PRINTLN TVOID 0V


ALOAD TSTRING "Hello World!"
UNIONPUT TVOID 0V

ALOAD TSTRING "a"
PRINTLN TVOID 0V
PRINT TSTRING "("
UNIONTYPE TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ") "
UNIONNAME2 TVOID 0V
PRINT TVOID 0V
PRINT TSTRING "."
UNIONUSINGNAME TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ": "
UNIONGET TVOID 0V
PRINTLN TVOID 0V

UNIONUSE TSTRING "a"
ALOAD TSTRING "bbb"
UNIONPUT TVOID 0V

PRINT TSTRING "("
UNIONTYPE TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ") "
UNIONNAME2 TVOID 0V
PRINT TVOID 0V
PRINT TSTRING "."
UNIONUSINGNAME TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ": "
UNIONGET TVOID 0V
PRINTLN TVOID 0V

UNIONUSE TSTRING "b"

PRINT TSTRING "("
UNIONTYPE TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ") "
UNIONNAME2 TVOID 0V
PRINT TVOID 0V
PRINT TSTRING "."
UNIONUSINGNAME TVOID 0V
PRINT TVOID 0V
PRINT TSTRING ": "
UNIONGET TVOID 0V
PRINTLN TVOID 0V



QUIT TVOID 0


END TVOID 0V