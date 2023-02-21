#! /bin/sh


# Copyright 2019 Dennis Earl Smiley

# This file is part of pnfasm.

#    pnfasm is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    pnfasm is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.

#    You should have received a copy of the GNU General Public License
#    along with pnfasm.  If not, see <https://www.gnu.org/licenses/>.
 
# CHANGELOG
# =========
 
# 5/25/15 Origional a - 1. The first version.


echo Cleaning...
rm *.cpp 2> /dev/null
rm *.exe 2> /dev/null

echo Bison...
bison -t -opnfasm.tab.cpp pnfasm.ypp

echo Flex...
flex -opnfasm.cpp pnfasm.lpp

echo C++...
g++ pnfasm.cpp -o pnfasm -lfl -Wno-write-strings -static -fpermissive -I "/usr/include"
