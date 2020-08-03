@ECHO OFF


REM Copyright 2019 Dennis Earl Smiley

REM This file is part of pnfasm.

REM    pnfasm is free software: you can redistribute it and/or modify
REM    it under the terms of the GNU General Public License as published by
REM    the Free Software Foundation, either version 3 of the License, or
REM    (at your option) any later version.

REM    pnfasm is distributed in the hope that it will be useful,
REM    but WITHOUT ANY WARRANTY; without even the implied warranty of
REM    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM    GNU General Public License for more details.

REM    You should have received a copy of the GNU General Public License
REM    along with pnfasm.  If not, see <https://www.gnu.org/licenses/>.
 
 
REM CHANGELOG
REM =========
 
REM 5/25/15 Origional a - 1. The first version.


ECHO Cleaning...
DEL *.cpp 2> NUL
DEL *.exe 2> NUL

ECHO Bison...
bison -t -opnfasm.tab.cpp pnfasm.ypp

ECHO Flex...
flex -opnfasm.cpp pnfasm.lpp

ECHO C++...
g++ pnfasm.cpp -o pnfasm.exe -lfl -Wno-write-strings -static