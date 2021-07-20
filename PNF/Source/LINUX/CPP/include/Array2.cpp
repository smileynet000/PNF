#ifndef Array2_cpp
#define Array2_cpp


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


#include "Array2.hpp"

#include <desLib/deslib.hpp>


template <class T>        
Array2<T>::Array2(unsigned long s = 1)
{
 data = new T[s];
 size = s;
}

template <class T>
Array2<T>::Array2(const Array2 & r)
{
 size = r.size;
 delete[] data;
 data = new T[size];
 
 for (unsigned long i = 0; i < size; ++i)
  data[i] = r[i];
}

template <class T>       
Array2<T>::~Array2()
{
 delete[] data;
 data = NULL;
}       

template <class T>
T & Array2<T>::get(unsigned long s)
{
 if (s < length())
  return data[s];
 else
 {
  String s2;
  s2.from_long(s);
  throw Exception((String)"get: Index Out of Bounds. index = " + (String)s2 + (char *)"\n", (char *)__FILE__, __LINE__);
 }
}

template <class T>
void Array2<T>::put(T d, unsigned long s)
{
 if (s < length())
 {
  data[s] = d;
 }
 else
 {
  String s2;
  s2.from_long(s);
  throw Exception((String)"put: Index Out of Bounds. index = " + s2 + "\n", __FILE__, __LINE__);
 }
}

template <class T>
unsigned long Array2<T>::length() const
{
 return size;
}

template <class T>
Array2<T> Array2<T>::operator=(const Array2<T> & rhs)
{
 if (this == &rhs)
  return *this;
  
 size = rhs.length();
 data = new T[size];
 
 for (unsigned long i = 0; i < length(); ++i)
  data[i] = rhs.data[i];
  
  
 return (*this);
}

template <class T>
T & Array2<T>::operator[](unsigned long offSet)
{
 return get(offSet);
}

template <class T>
void Array2<T>::insert()
{
 T * temp = new T[size + 1];
 for (unsigned long i = 0; i < size; ++i)
  temp[i] = data[i];
 temp[size] = 0;
 
 ++size;
 data = new T[size];
 
 for (unsigned long i = 0; i < size; ++i)
  data[i] = temp[i];
}

template <>
void Array2<String>::insert()
{
 String * temp = new String[size + 1];
 for (unsigned long i = 0; i < size; ++i)
  temp[i] = data[i];
 temp[size + 1] = (char *)"";
 
 ++size;
 data = new String[size];
 
 for (unsigned long i = 0; i < size; ++i)
  data[i] = temp[i];
}

template <class T>
void Array2<T>::remove()
{
 T * temp = new T[size - 1];
 for (unsigned long i = 0; i < size - 1; ++i)
  temp[i] = data[i];
  
 --size;
 data = new T[size];
 
 for (unsigned long i = 0; i < size; ++i)
  data[i] = temp[i];
}

template <class T>
void Array2<T>::insert(T d, unsigned long offset)
{
 Array<T> d1;
 unsigned long len;
 
 if (offset == length())
  len = offset + 1;
 else if (offset > length())
  len = offset;
 else
  len = length();
  
 
 for (unsigned long i = 0; i < len; ++i)
 { 
  if (i == offset)
  {
   if (i != 0)
    d1.insert();
   d1[i] = d;
  }
  else
  {   
   if (i != 0)
    d1.insert();
    
   if (i >= length())
   {
   	d1[i] = 0;
   	continue;
   }
   
   d1[i] = data[i];
  }
 }
 
 for (unsigned long i = 0; i < d1.length(); ++i)
 {
  if (i >= length())
   insert();
  data[i] = d1[i];
 }
}

template <>
void Array2<String>::insert(String d, unsigned long offset)
{
 Array<String> d1;
 unsigned long len;
 
 if (offset == length())
  len = offset + 1;
 else if (offset > length())
  len = offset;
 else
  len = length();
  
  
 for (unsigned long i = 0; i < len; ++i)
 { 
  if (i == offset)
  {
   if (i != 0)
    d1.insert();
   d1[i] = d;
  }
  else
  {  
   if (i != 0)
    d1.insert();
    
   if (i >= length())
   {
   	d1[i] = (char *)"";
   	continue;
   }
   d1[i] = data[i];
  }
 }
 
 for (unsigned long i = 0; i < d1.length(); ++i)
 {
  if (i >= length())
   insert();
  data[i] = d1[i];
 }
}

template <class T>
void Array2<T>::remove(unsigned long offset)
{
 if (offset >= size)
  remove();
  
 T * d1 = new T[size - 1];
 for (unsigned long i = 0, j = 0; j < size - 1; ++i, ++j)
 {
  if (i == offset)
  {
   --j;
   continue;
  }
   
  d1[j] = data[i];
 }
 
 --size;
 data = new T[size];
 
 for (unsigned long i = 0; i < size; ++i)
  data[i] = d1[i];
}

template <class T>
void Array2<T>::copy(unsigned long d1, unsigned long d2)
{
 insert(data[d1], d2);
}

template <class T>
void Array2<T>::move(unsigned long d1, unsigned long d2)
{
 copy(d1, d2);
 data[d1] = 0;
}

template <>
void Array2<String>::move(unsigned long d1, unsigned long d2)
{
 copy(d1, d2);
 data[d1] = (char *)"";
}


#endif // Array2_cpp
