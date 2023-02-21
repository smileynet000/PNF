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
 
 5/25/15 Origional a - The first version.
 6/26/15 Original a-a - 1. Fixed bugs...
			2. Fixed bugs...
			3. Fixed bugs...
			4. Fixed bugs...
*/
// Includes go here
#include <stdlib.h>

#undef OS_WINDOWS
#define OS_LINUX

#ifdef OS_WINDOWS
 #include <windows.h>
#endif
#include "../pnf.hpp"


// Namespaces we use go here
using namespace std;


// Function prototypes go here...
void file2cpp(char * input, char * output, char * vname, char * vtype);


// Main program goes here
int main(int argc, char ** argv)
{
 if (argc < 3)
 {
  error(ERRORMSG, "Wrong Arguments.");
  return -1;
 }
  bool four = false;
  char * PNFHPP = getenv("PNFHPP");
  
  if (PNFHPP == NULL)
  {
   if (argc == 4)
    four = true;
   else
   {
    error(ERRORMSG, "No PNFHPP enviroment variable. This must point to the HPP path.");
    return -1;
   }
  }

  if (four)
   PNFHPP = argv[3];
  
  int cp = 0;
  #ifdef OS_WINDOWS
   cp = CopyFile(PNFHPP, ".\\pnf.hpp", TRUE);

  if (cp == 0)
   error(WARNINGMSG, "Cannot copy file. Does the file already exist?");
  #endif
  
  
  Array<String> args;
  for (unsigned long i = 0, j = i + 1; i != argc; ++i, ++j)
  {
   args[i] = argv[i];
   
   if (j != argc)
    args.insert();
  }
  args.remove(2);
  PNF program(args);
    
  program.setProgram(argv[1]);
    
 
  program.load();
  program.check();
  Memory m = program.getmem();


  fout.open(argv[2]);

  if (!fout)
   cout << "* ERROR: Cannot open output file.\n";


  fout << "#include \"";
  #ifdef OS_LINUX
   fout << PNFHPP << "\"\n\n\n";
  #endif // OS_LINUX
  #ifdef OS_WINDOWS
   fout << "pnf.hpp\"\n\n\n";
  #endif // OS_WINDOWS


  fout << "int main(int argc, char ** argv)\n";
  fout << "{\n";
  fout << "  Array<String> args;\n";
  fout << "\n";
  fout << "  args[0] = \"(COMPILED)\";\n";
  fout << "  for (unsigned long i = 0, j = 1; i < argc; ++i, ++j)\n";
  fout << "  {\n";
  fout << "   args.insert();\n";
  fout << "\n";
  fout << "   args[j] = argv[i];\n";
  fout << "  }\n";
  fout << "\n";
  fout << "  PNF program(args);\n\n\n";
    
  fout << "  Memory mem;\n";
  for (unsigned long i = 0; i < m.length(); ++i)
  {
   fout << "  mem.put(" << i << ", " << m.get(i) << ");" << endl;
  }
  fout << "\n\n";
  fout << "  program.getmem().setmem(mem.getmem());\n";
  fout << "  program.loads3();\n";
  fout << "  program.loads2();\n";
  fout << "  program.check();\n";
  fout << "  char * strs;\n";
  fout << "  int ret = strtol(program.execute().getString().c_str(), &strs, 10);\n";
  fout << "  return ret;\n";
  fout << "}\n";

  fout.close();


 return 0;
}


// Other Functions go here
void file2cpp(char * input, char * output, char * vname, char * vtype)
{
 ifstream fin(input);
 ofstream fout(output);

 fout << vtype << " " << vname << " = { ";
 char ch;
 while (!fin.eof())
 {
  fin >> ch;
  fout << (int)ch << ", ";
 }
 fout << "0 };";
 fin.close();
 fout.close();
}
