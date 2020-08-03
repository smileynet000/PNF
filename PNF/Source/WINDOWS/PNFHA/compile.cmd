@ECHO OFF


REM Copyright 2019 Dennis Earl Smiley

REM This file is part of pnfha.

REM    pnfha is free software: you can redistribute it and/or modify
REM    it under the terms of the GNU General Public License as published by
REM    the Free Software Foundation, either version 3 of the License, or
REM    (at your option) any later version.

REM    pnfha is distributed in the hope that it will be useful,
REM    but WITHOUT ANY WARRANTY; without even the implied warranty of
REM    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM    GNU General Public License for more details.

REM    You should have received a copy of the GNU General Public License
REM    along with pnfha.  If not, see <https://www.gnu.org/licenses/>.
 
 
REM CHANGELOG
REM =========
 
REM 5/25/15 Origional a-a-j - 1. The first version.
REM			      2. Made it clean first...
REM			      3. Need -fpermissive


ECHO Cleaning...
DEL *.cpp 2> NUL
DEL *.exe 2> NUL

ECHO Bison...
bison -t -opnfha.tab.cpp pnfha.ypp

ECHO Flex...
flex -opnfha.cpp pnfha.lpp

ECHO C++...
g++ pnfha.cpp -opnfha.exe -lfl -Wno-write-strings -fpermissive -static