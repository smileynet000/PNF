#!/bin/sh


# Copyright 2019 Dennis Earl Smiley
#
# This file is part of pnfha.
#
#    pnfha is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    pnfha is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with pnfha.  If not, see <https://www.gnu.org/licenses/>.



# Clean
rm -r -f *.cpp

# Compile
bison -t -opnfha.tab.cpp pnfha.ypp

flex -opnfha.cpp pnfha.lpp

g++ pnfha.cpp -opnfha -lfl -Wno-write-strings
