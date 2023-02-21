#ifndef Array2_hpp
#define Array2_hpp


/*
* This code was based off of code in Sam's Teach Yourself C++ in Just 21 Days *
*/


/*
Copyright (C) 2020 Dennis Earl Smiley


This file is part of pnf.

pnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

pnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with desLib.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
CHANGELOG
=========
7/26/15 Original a - The first version.
*/


template <class T>
class Array2
{
 private:
         T * data;
         unsigned long size;
         
         
 public:
        Array2(unsigned long s);
        
        Array2(const Array2 & r);
        
        ~Array2();
        
        
        T & get(unsigned long s);
        void put(T d, unsigned long s);
        unsigned long length() const;
        
        Array2<T> operator=(const Array2<T> & rhs);
        T & operator[](unsigned long offSet);
        
        void insert();
        void remove();
        
        void insert(T d, unsigned long offset);
        void remove(unsigned long offset);
        void copy(unsigned long d1, unsigned long d2);
        void move(unsigned long d1, unsigned long d2);
};


#endif // Array2_hpp
