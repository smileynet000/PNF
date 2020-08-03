#!/bin/sh


# Copyright 2019 Dennis Earl Smiley
#
# This file is part of pnfpp.
#
#    pnfpp is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    pnfpp is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with pnfpp.  If not, see <https://www.gnu.org/licenses/>.


# Clean
rm -r -f *.cpp

# Compile
bison -t -opnfpp.tab.cpp pnfpp.ypp

flex -opnfpp.cpp pnfpp.lpp

g++ pnfpp.cpp -opnfpp -lfl -Wno-write-strings
