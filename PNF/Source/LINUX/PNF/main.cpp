/*
 Program: PNF

 File: main.cpp

 Description: A portable numbers format interpreter.

 Author: Dennis Earl Smiley

 Enviroment: g++ 4.3

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
 
 5/6/16 Origional a - The first version.

 5/3/19 Origional a-a - Made Linux compatable.
*/
// #Defines go here...
#define TEMPLATE_Main


// Includes go here...
#include <cstdlib>

#include "../pnf.hpp"


// Classes go here...


// Global variables go here...


// Function prototypes go here...
int Main(Array<String> args);


// Functions go here...
int main(int argc, char ** argv)
{
 Array<String> args(argc);

 for (unsigned long i = 0; i < argc; ++i)
  args[i] = argv[i];

 int ret = Main(args);


 return ret;
}

int Main(Array<String> args)
{
 if (args.length() < 2)
 {
  error(ERRORMSG, (char *)"Wrong Arguments.");
  return 1;
 }
 else if (args.length() >= 2)
 {
  char * value;
  char * strs;
  PNF program(args);
    
  program.load();
  program.loads2();
  program.check();
  String ret = program.execute();


  strcpy(value, ret.getString().c_str());
  long result = strtol(value, &strs, 10);

  return result;
 }
}
