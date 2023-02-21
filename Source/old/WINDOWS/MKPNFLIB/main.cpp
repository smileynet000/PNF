/*
 Program: 	MKPNFLIB

 File: main.cpp

 Description: Makes a PNF library from a regular PNF file...

 Author: Dennis Earl Smiley

 Enviroment: Dev-C++ 5.5.3

 Notes:

 Revisons: 4/1/17 Origional a - The first version.
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
// #Defines go here...
#define T_Main


// Includes go here...
#include <desLib/deslib.hpp>


// Classes go here...


// Global variables go here...


// Function prototypes go here...


// Functions go here...
int Main(Array<String> args)
{
 if (args.length() == 3)
 {
  fin.open(args[1].getString().c_str());
  if (!fin)
  {
   error(ERRORMSG, (char *)"Cannot open file for reading.");
   return 1;
  }
  
  fout.open(args[2].getString().c_str());
  if (!fout)
  {
   error(ERRORMSG, (char *)"Cannot open file for output.");
   return 1;
  }
  
  
  String signature;
  fin >> signature;
  
  if (signature != (char *)"!@.PNF")
  {
   error(ERRORMSG, (char *)"Wrong signature.");
   return 1;
  }
  
  double num;
  unsigned long i = 1;
  while (!fin.eof())
  {
   fin >> num;
   if (num == 61)
    break;
   
    
   fout << num;
   
   fout << " ";
   if (i == 2 && num == 4)
   {
   	while (num != 0)
   	{
   	 fin >> num;
   	 fout << num << " ";
   	}
   	fout << endl;
   	i = 1;
   	continue;
   }
   if (i == 3)
   {
    fout << endl;
    i = 1;
   }
   ++i;
  }
  

  fin.close();
  fout.close();
  
  
  return 0;
 }
 else
 {
  error(ERRORMSG, (char *)"Wrong arguments.");
  
  return 1;
 }
}
