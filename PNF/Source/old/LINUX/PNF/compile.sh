#! /bin/bash


# Copyright 2020 Dennis Earl Smiley

# This file is part of pnf.

#    pnf is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    pnf is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.

#    You should have received a copy of the GNU General Public License
#    along with pnfha.  If not, see <https://www.gnu.org/licenses/>.
 
 
# CHANGELOG
# =========
 
# 8/4/20 Origional a-a-a - 1. The first version.


echo Cleaning...
rm *.exe 2> /dev/null

echo C++...
g++ main.cpp -opnf -Wno-write-strings -fpermissive --static -g
