#ifndef String2_hpp
#define String2_hpp


/*
* This code was based off of code in Sam's Teach Yourself C++ in Just 21 Days *
*/


/*
Copyright (C) 2022 Dennis Earl Smiley


This file is part of PNF.

PNF is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

PNF is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with desLib.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
CHANGELOG
=========
3/1/22 Original a - 1. The first version.
*/


class String2
{
 private:

         
 public:
         char * str;


        String2();
        String2(char * s);
        String2(char c);
        String2(unsigned long l);

        String2(const String2 & r);
        
        ~String2();
        
        
        char & operator[](unsigned long offset);
        char operator[](unsigned long offset) const;
        String2 operator+(String2 s);
        String2 operator+(char c);
        void operator+=(String2 s);
        void operator+=(char * s);
        void operator+=(char c);
        
        bool operator==(String2 s);
        bool operator!=(String2 s);
        bool operator<(String2 s);
        bool operator>(String2 s);
        bool operator<=(String2 s);
        bool operator>=(String2 s);
        
        String2 operator=(const String2 & s);
        
        
        char * getString();
        
        void setString();
        void setString(char * s);


        unsigned long length();
        unsigned long size();

        unsigned long begin();
        unsigned long end();
        unsigned long rbegin();
        unsigned long rend();

        void clear();
        
        void insert();
        void remove();
        
        void insert(unsigned long offset, char d);
        void remove(unsigned long offset);


        void from_long(unsigned long l);


        String2 reverse();
};


#endif // String2_hpp
