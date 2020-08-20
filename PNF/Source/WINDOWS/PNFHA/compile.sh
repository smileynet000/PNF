#! /bin/sh


# Copyright 2019 Dennis Earl Smiley

# This file is part of pnfha.

#M    pnfha is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    pnfha is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.

#    You should have received a copy of the GNU General Public License
#    along with pnfha.  If not, see <https://www.gnu.org/licenses/>.
 
 
# CHANGELOG
# =========
 
# 5/25/15 Origional a-a-j - 1. The first version.
#			      2. Made it clean first...
#			      3. Need -fpermissive


echo Cleaning...
rm *.cpp 2> NUL
rm *.exe 2> NUL

echo Bison...
bison -t -opnfha.tab.cpp pnfha.ypp

echo Flex...
flex -opnfha.cpp pnfha.lpp

echo C++...
g++ pnfha.cpp -opnfha -lfl -Wno-write-strings -fpermissive -static -I "/usr/include"
