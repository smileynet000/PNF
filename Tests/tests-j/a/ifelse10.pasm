VERSION TVOID 0V


ALOAD TBOOLEAN true
IF TVOID 0V
IFBEGIN TVOID 0V
PRINTLN TSTRING "if..."
ALOAD TBOOLEAN false
IF TVOID 0V
IFBEGIN TVOID 0V
PRINTLN TSTRING "subif..."
IFEND TVOID 0V
ENDIF TVOID 0V
EIF TVOID 0V
ALOAD TBOOLEAN false
IF TVOID 0V
IFBEGIN TVOID 0V
PRINTLN TSTRING "subif2 if..."
IFEND TVOID 0V
ENDIF TVOID 0V
IFELSE TVOID 0V
IFBEGIN TVOID 0V
PRINTLN TSTRING "subif2 else..."
ALOAD TBOOLEAN false
IF TVOID 0V
IFBEGIN TVOID 0V
PRINTLN TSTRING "subif2 else if..."
IFEND TVOID 0V
ENDIF TVOID 0V
IFELSE TVOID 0V
IFBEGIN TVOID 0V
PRINTLN TSTRING "subif2 else else..."
IFEND TVOID 0V
ENDIFELSE TVOID 0V
EIF TVOID 0V
IFEND TVOID 0V
ENDIFELSE TVOID 0V
EIF TVOID 0V
IFEND TVOID 0V
ENDIF TVOID 0V
IFELSE TVOID 0V
IFBEGIN TVOID 0V
PRINTLN TSTRING "else..."
IFEND TVOID 0V
ENDIFELSE TVOID 0V
EIF TVOID 0V
QUIT TVOID 0


END TVOID 0V