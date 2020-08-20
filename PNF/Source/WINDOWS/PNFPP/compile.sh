#! /bin/sh


# Copyright 2019 Dennis Earl Smiley

# This file is part of pnfpp.

#    pnfpp is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    pnfpp is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.

#    You should have received a copy of the GNU General Public License
#    along with pnfpp.  If not, see <https://www.gnu.org/licenses/>.
 
 
# CHANGELOG
# =========
 
# 5/25/15 Origional a - 1. The first version.


echo Cleaning...
rm *.cpp 2> NUL
rm *.exe 2> NUL

echo Bison...
bison -t -opnfpp.tab.cpp pnfpp.ypp

echo Flex...
flex -opnfpp.cpp pnfpp.lpp

echo C++...
g++ pnfpp.cpp -opnfpp -lfl -Wno-write-strings -static -fpermissive
