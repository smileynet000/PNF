VERSION TVOID 1


FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TVOID 0V
FNCSPARAM TVOID 0V
ALOAD TSTRING "a"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "a_rVOID_VOID"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TNUMBER 0
FNCSPARAM TNUMBER 0V
ALOAD TSTRING "b"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "b_rVOID_NUMBER"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TSTRING ""
FNCSPARAM TSTRING 0V
PNUM TNUMBER 1
ALOAD TNUMBER 0
FNCSPARAM TNUMBER 0V
ALOAD TSTRING "c"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "c_rVOID_STRING_NUMBER"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TSTRING ""
FNCSPARAM TSTRING 0V
PNUM TNUMBER 1
ALOAD TNUMBER 0
FNCSPARAM TNUMBER 0V
PNUM TNUMBER 2
ALOAD TNUMBER 0
FNCSPARAM TNUMBER 0V
ALOAD TSTRING "d"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "d_rVOID_STRING_NUMBER_NUMBER"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TVOID 0V
FNCSPARAM TVOID 0V
ALOAD TSTRING "e"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "e_rVOID_VOID"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TVOID 0V
FNCSPARAM TVOID 0V
ALOAD TSTRING "f"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "f_rVOID_VOID"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TSTRING ""
FNCSPARAM TSTRING 0V
ALOAD TSTRING "g"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "g_rVOID_STRING"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TVOID 0V
FNCSPARAM TVOID 0V
ALOAD TSTRING "h"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "h_rVOID_VOID"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TBOOLEAN false
FNCSPARAM TBOOLEAN 0V
ALOAD TSTRING "i"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "i_rVOID_BOOLEAN"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
PNUM TNUMBER 0
ALOAD TVOID 0V
FNCSPARAM TVOID 0V
ALOAD TSTRING "j"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "j_rVOID_VOID"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
RNUM TNUMBER 0
ALOAD TNUMBER 0
FNCSRET TNUMBER 0V
PNUM TNUMBER 0
ALOAD TVOID 0V
FNCSPARAM TVOID 0V
ALOAD TSTRING "k"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "k_rNUMBER_VOID"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
RNUM TNUMBER 0
ALOAD TBOOLEAN false
FNCSRET TBOOLEAN 0V
PNUM TNUMBER 0
ALOAD TVOID 0V
FNCSPARAM TVOID 0V
ALOAD TSTRING "l"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "l_rBOOLEAN_VOID"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
FNCNEW TVOID 0V
RNUM TNUMBER 0
ALOAD TNUMBER 0
FNCSRET TNUMBER 0V
RNUM TNUMBER 1
ALOAD TBOOLEAN false
FNCSRET TBOOLEAN 0V
PNUM TNUMBER 0
ALOAD TVOID 0V
FNCSPARAM TVOID 0V
ALOAD TSTRING "m"
FNCSNAME TVOID 0V
FNCSDEF TSTRING "m_rNUMBER_rBOOLEAN_VOID"
FNCSTORE TVOID 0V
FNCDELETE TVOID 0V
GOTOL TSTRING "a_rVOID_VOID_END"
LBL TSTRING "a_rVOID_VOID"
PRINTLN TSTRING "a()"
FRET TVOID 0V
LBL TSTRING "a_rVOID_VOID_END"
GOTOL TSTRING "b_rVOID_NUMBER_END"
LBL TSTRING "b_rVOID_NUMBER"
PRINTLN TSTRING "b()"
ALOAD TNUMBER 77
FNCLOAD TNUMBER 1
PNUM TNUMBER 0
FNCSPARAM TNUMBER 0V
FNCSTORE TNUMBER 1
PRINT TCHARACTER '"'
PNUM TNUMBER 0
ALOAD TNUMBER 1
PARAMF2 TNUMBER 0V
PRINT TVOID 0V
PRINTLN TCHARACTER '"'
FRET TVOID 0V
LBL TSTRING "b_rVOID_NUMBER_END"
GOTOL TSTRING "c_rVOID_STRING_NUMBER_END"
LBL TSTRING "c_rVOID_STRING_NUMBER"
PRINTLN TSTRING "c()"
FRET TVOID 0V
LBL TSTRING "c_rVOID_STRING_NUMBER_END"
GOTOL TSTRING "d_rVOID_STRING_NUMBER_NUMBER_END"
LBL TSTRING "d_rVOID_STRING_NUMBER_NUMBER"
PRINTLN TSTRING "d()"
FRET TVOID 0V
LBL TSTRING "d_rVOID_STRING_NUMBER_NUMBER_END"
GOTOL TSTRING "e_rVOID_VOID_END"
LBL TSTRING "e_rVOID_VOID"
PRINTLN TSTRING "e()"
FRET TVOID 0V
LBL TSTRING "e_rVOID_VOID_END"
GOTOL TSTRING "f_rVOID_VOID_END"
LBL TSTRING "f_rVOID_VOID"
PRINTLN TSTRING "f()"
FRET TVOID 0V
LBL TSTRING "f_rVOID_VOID_END"
GOTOL TSTRING "g_rVOID_STRING_END"
LBL TSTRING "g_rVOID_STRING"
PRINTLN TSTRING "g()"
FRET TVOID 0V
LBL TSTRING "g_rVOID_STRING_END"
GOTOL TSTRING "h_rVOID_VOID_END"
LBL TSTRING "h_rVOID_VOID"
PRINTLN TSTRING "h()"
FCALL TSTRING "a"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 0
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 0
ALOAD TNUMBER 0
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
FRET TVOID 0V
LBL TSTRING "h_rVOID_VOID_END"
GOTOL TSTRING "i_rVOID_BOOLEAN_END"
LBL TSTRING "i_rVOID_BOOLEAN"
PRINTLN TSTRING "i()"
PNUM TNUMBER 0
ALOAD TNUMBER 8
PARAMF2 TBOOLEAN 0V
PRINTLN TVOID 0V
FRET TVOID 0V
LBL TSTRING "i_rVOID_BOOLEAN_END"
GOTOL TSTRING "j_rVOID_VOID_END"
LBL TSTRING "j_rVOID_VOID"
PRINTLN TSTRING "j()"
FCALL TSTRING "h"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 0
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 0
ALOAD TNUMBER 0
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
FRET TVOID 0V
LBL TSTRING "j_rVOID_VOID_END"
GOTOL TSTRING "k_rNUMBER_VOID_END"
LBL TSTRING "k_rNUMBER_VOID"
PRINTLN TSTRING "k()"
FNCLOAD TNUMBER 10
RNUM TNUMBER 0
ALOAD TNUMBER 76
FNCSRET TNUMBER 0V
FNCSTORE TVOID 0V
FRET TVOID 0V
LBL TSTRING "k_rNUMBER_VOID_END"
GOTOL TSTRING "l_rBOOLEAN_VOID_END"
LBL TSTRING "l_rBOOLEAN_VOID"
PRINTLN TSTRING "l()"
FNCLOAD TNUMBER 11
RNUM TNUMBER 0
ALOAD TBOOLEAN true
FNCSRET TBOOLEAN 0V
FNCSTORE TVOID 0V
FRET TVOID 0V
LBL TSTRING "l_rBOOLEAN_VOID_END"
GOTOL TSTRING "m_rNUMBER_rBOOLEAN_VOID_END"
LBL TSTRING "m_rNUMBER_rBOOLEAN_VOID"
PRINTLN TSTRING "m()"
FNCLOAD TNUMBER 12
RNUM TNUMBER 0
ALOAD TNUMBER 75
FNCSRET TNUMBER 0V
FNCSTORE TVOID 0V
FNCLOAD TNUMBER 12
RNUM TNUMBER 1
ALOAD TBOOLEAN true
FNCSRET TBOOLEAN 0V
FNCSTORE TVOID 0V
FRET TVOID 0V
LBL TSTRING "m_rNUMBER_rBOOLEAN_VOID_END"
FCALL TSTRING "a"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 7
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 7
ALOAD TNUMBER 7
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
FCALL TSTRING "b"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 0
PNUM TNUMBER 0
FNCSPARAM TNUMBER 0V
FNCSTORE TNUMBER 0
ALOAD TNUMBER 0
PNUM TNUMBER 0
PARAMF TNUMBER 1
FECPARAMS TVOID 0V
FECALL TVOID 0V
FCALL TSTRING "c"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 1
PNUM TNUMBER 0
FNCSPARAM TSTRING 0V
FNCSTORE TNUMBER 1
ALOAD TNUMBER 1
PNUM TNUMBER 0
PARAMF TSTRING "true"
FNCSPARAM TNUMBER 0V
FNCSTORE TNUMBER 1
ALOAD TNUMBER 1
PNUM TNUMBER 1
PARAMF TNUMBER 77
FECPARAMS TVOID 0V
FECALL TVOID 0V
FCALL TSTRING "d"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 2
PNUM TNUMBER 0
FNCSPARAM TSTRING 0V
FNCSTORE TNUMBER 2
ALOAD TNUMBER 2
PNUM TNUMBER 0
PARAMF TSTRING "M"
FNCSPARAM TNUMBER 0V
FNCSTORE TNUMBER 2
ALOAD TNUMBER 2
PNUM TNUMBER 1
PARAMF TNUMBER 76
FNCSPARAM TNUMBER 0V
FNCSTORE TNUMBER 2
ALOAD TNUMBER 2
PNUM TNUMBER 2
PARAMF TNUMBER 79
FECPARAMS TVOID 0V
FECALL TVOID 0V
FCALL TSTRING "e"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 3
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 3
ALOAD TNUMBER 3
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
FCALL TSTRING "f"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 4
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 4
ALOAD TNUMBER 4
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
FCALL TSTRING "g"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 5
PNUM TNUMBER 0
FNCSPARAM TSTRING 0V
FNCSTORE TNUMBER 5
ALOAD TNUMBER 5
PNUM TNUMBER 0
PARAMF TSTRING "O"
FECPARAMS TVOID 0V
FECALL TVOID 0V
FCALL TSTRING "h"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 6
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 6
ALOAD TNUMBER 6
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
FCALL TSTRING "i"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 7
PNUM TNUMBER 0
FNCSPARAM TBOOLEAN 0V
FNCSTORE TNUMBER 7
ALOAD TNUMBER 7
PNUM TNUMBER 0
PARAMF TBOOLEAN true
FECPARAMS TVOID 0V
FECALL TVOID 0V
FCALL TSTRING "j"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 8
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 8
ALOAD TNUMBER 8
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
PRINTLN TSTRING ""
RNUM TNUMBER 0
RETURNF2 TNUMBER 0V
FCALL TSTRING "k"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 9
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 9
ALOAD TNUMBER 9
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
RNUM TNUMBER 0
RETURNV TVOID 0V
PRINT TSTRING "The value returned was: "
PRINTLN TVOID 0V
PRINTLN TSTRING ""
RNUM TNUMBER 0
RETURNF2 TBOOLEAN 0V
FCALL TSTRING "l"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 10
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 10
ALOAD TNUMBER 10
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
RNUM TNUMBER 0
RETURNV TVOID 0V
PRINT TSTRING "The value returned was: "
PRINTLN TVOID 0V
PRINTLN TSTRING ""
RNUM TNUMBER 0
RETURNF2 TNUMBER 0V
RNUM TNUMBER 1
RETURNF2 TBOOLEAN 0V
FCALL TSTRING "m"
FCPARAMS TVOID 0V
FNCLOAD TNUMBER 11
PNUM TNUMBER 0
FNCSPARAM TVOID 0V
FNCSTORE TNUMBER 11
ALOAD TNUMBER 11
PNUM TNUMBER 0
PARAMF TVOID 0V
FECPARAMS TVOID 0V
FECALL TVOID 0V
RNUM TNUMBER 0
RETURNV TVOID 0V
PRINT TSTRING "The first return value was: "
PRINTLN TVOID 0V
RNUM TNUMBER 1
RETURNV TVOID 0V
PRINT TSTRING "The second return value was: "
PRINTLN TVOID 0V
QUIT TVOID 0


END TVOID 0V