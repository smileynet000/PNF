/*
 Program: PNF

 File: main.cpp

 Description: A portable numbers format interpreter.

 Author: Dennis Earl Smiley

 Enviroment: Dev-C++ 5.5.3

 Notes:
*/
/* 
Copyright 2019 Dennis Earl Smiley

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
 /*
 CHANGELOG
 =========
 
 5/6/16 Origional a - 1. The first version.
		              2. Applied a patch.
                      3. Fixed preprocessing...
*/
// #Defines go here...
#define T_Main
#define OS_LINUX


// Includes go here...
#include <cstring>

#include "../pnf.hpp"


// Classes go here...


// Global variables go here...


// Function prototypes go here...


// Functions go here...
int Main(Array<String> args)
{
 if (args.length() < 2)
 {
  error(ERRORMSG, (char *)"Wrong Arguments.");
  return 1;
 }
 else if (args.length() >= 2)
 {
  char * strs;
  PNF program(args);
    
  program.load();
  program.loads2();
  program.check();
  String ret = program.execute();

  long result = strtol(ret.getString().c_str(), &strs, 10);


  return result;
 }
}
