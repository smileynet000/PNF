VERSION TVOID 0V


PRINTLN TSTRING "Defining an array..."
ASTART TSTRING "a"
AEND TNUMBER 3


PRINTLN TSTRING "Testing load and store..."
ALOAD TSTRING "and"
APREP TSTRING "a"
AIPREP TNUMBER 0
STOREIA TVOID 0V

ALOAD TNUMBER 5
APREP TSTRING "a"
AIPREP TNUMBER 1
STOREIA TVOID 0V

ALOAD TCHARACTER 'c'
APREP TSTRING "a"
AIPREP TNUMBER 2
STOREIA TVOID 0V

PRINT TSTRING "a[0]: "
APREP TSTRING "a"
AIPREP TNUMBER 0
LOADIA TVOID 0V
PRINTLN TVOID 0V

PRINT TSTRING "a[1]: "
APREP TSTRING "a"
AIPREP TNUMBER 1
LOADIA TVOID 0V
PRINTLN TVOID 0V

PRINT TSTRING "a[2]: "
APREP TSTRING "a"
AIPREP TNUMBER 2
LOADIA TVOID 0V
PRINTLN TVOID 0V


PRINTLN TSTRING "Quiting..."
QUIT TVOID 0


END TVOID 0V