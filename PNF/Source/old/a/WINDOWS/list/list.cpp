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

5/3/19 Origional a-a-a - The first version.
*/


#include <desLib/deslib.hpp>


int main(int argc, char ** argv)
{
 if (argc == 3)
 {
  fin.open(argv[1]);
  fout.open(argv[2]);
  string line;
  for (unsigned long i = 1; getline(fin, line); ++i)
  {
   fout << i << ": " << line << endl;
  }
  fin.close();
  fout.close();
 }
 else
 {
  error(ERRORMSG, (char *)"input or output file not specified.");
  cout << "Usage:\n\n";
  cout << argv[0] << " <input file> <output file>\n";
 }
}
