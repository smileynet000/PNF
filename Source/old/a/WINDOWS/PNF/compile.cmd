@ECHO OFF


REM Copyright 2020 Dennis Earl Smiley

REM This file is part of pnf.

REM    pnf is free software: you can redistribute it and/or modify
REM    it under the terms of the GNU General Public License as published by
REM    the Free Software Foundation, either version 3 of the License, or
REM    (at your option) any later version.

REM    pnf is distributed in the hope that it will be useful,
REM    but WITHOUT ANY WARRANTY; without even the implied warranty of
REM    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM    GNU General Public License for more details.

REM    You should have received a copy of the GNU General Public License
REM    along with pnfha.  If not, see <https://www.gnu.org/licenses/>.
 
 
REM CHANGELOG
REM =========
 
REM 8/4/20 Origional a-a-a - 1. The first version.


ECHO Cleaning...
DEL *.exe 2> NUL

ECHO C++...
g++ main.cpp -opnf.exe -Wno-write-strings -fpermissive -static
