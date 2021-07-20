@ECHO OFF


REM COPYRIGHT INFO
REM ==============
 
REM PNFASM_Compile Copyright (C) 2015 Dennis Earl Smiley
REM This software is distributed under the terms of des Software Liscense a - a-a-d or at your option, any later version. This software is alpha as of 5/25/15.
REM Contact info despersonal000@gmail.com
 
 
REM CHANGELOG
REM =========
 
REM 5/25/15 Origional a-a-j - 1. The first version.
REM			      2. Made it clean first...


ECHO Cleaning...
DEL *.cpp 2> NUL
DEL *.exe 2> NUL

ECHO Bison...
bison -t -opnfha.tab.cpp pnfha.ypp

ECHO Flex...
flex -opnfha.cpp pnfha.lpp

ECHO C++...
g++ pnfha.cpp -opnfha.exe -lfl -Wno-write-strings -static