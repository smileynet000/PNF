@ECHO OFF


REM This file is part of pnfhra.

REM    pnfhra is free software: you can redistribute it and/or modify
REM    it under the terms of the GNU General Public License as published by
REM    the Free Software Foundation, either version 3 of the License, or
REM    (at your option) any later version.

REM    pnfhra is distributed in the hope that it will be useful,
REM    but WITHOUT ANY WARRANTY; without even the implied warranty of
REM    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM    GNU General Public License for more details.

REM    You should have received a copy of the GNU General Public License
REM    along with pnfhra.  If not, see <https://www.gnu.org/licenses/>.
 
 
REM CHANGELOG
REM =========
 
REM 4/22/19 Origional a-a-j - 1. The first version.


ECHO Cleaning...
DEL *.cpp 2> NUL
DEL *.exe 2> NUL

ECHO Bison...
bison -t -opnfhra.tab.cpp pnfhra.ypp

ECHO Flex...
flex -opnfhra.cpp pnfhra.lpp

ECHO C++...
g++ pnfhra.cpp -opnfhra.exe -lfl -Wno-write-strings -static