#ifndef PNF_Types_cpp
#define PNF_Types_cpp
/*
    Copyright 2020 Dennis Earl Smiley

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
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

 9/5/20 Origional a 	- The first version.
*/


void PNF_Void::put()
{
 // Does nothing
}

void PNF_Void::get() const
{
 // Does nothing
}

double PNF_Void::to_mem()
{
 return 0;
}

void PNF_Void::from_mem(double i)
{
 if (i != 0)
  error(ERRORMSG, (char *)"Not Void.");
}

void PNF_Void::print()
{
 cout << 0;
}

void PNF_Void::fprint(ofstream & fout)
{
 fout << 0;
}

void PNF_Void::eprint()
{
 cerr << 0;
}

void PNF_Void::read()
{
 // Does nothing
}

void PNF_Void::fread(ifstream & fin)
{
 // Does nothing
}

PNF_Void PNF_Void::operator=(const PNF_Void & v) const
{
 if (this == &v)
  return *this;

 return (*this);
}


PNF_Boolean::PNF_Boolean()
{
 data = false;
}

PNF_Boolean::PNF_Boolean(bool d)
{
 data = d;
}

PNF_Boolean::~PNF_Boolean()
{

}

void PNF_Boolean::put(bool d)
{
 data = d;
}

String PNF_Boolean::get() const
{
 if (data == true)
  return (char *)"true";
 else
  return (char *)"false";
}

double PNF_Boolean::to_mem()
{
 return data;
}

void PNF_Boolean::from_mem(double i)
{
 data = (bool)i;
}

void PNF_Boolean::print()
{
 cout << get();
}

void PNF_Boolean::fprint(ofstream & fout)
{
 fout << get();
}

void PNF_Boolean::eprint()
{
 cerr << get();
}

void PNF_Boolean::read()
{
 string data2;

 cin >> data2;

 if (data2 == "false")
  data = false;
 else if (data2 == "true")
  data = true;
 else
  data = false;
}

void PNF_Boolean::fread(ifstream & fin)
{
 string data2;

 fin >> data2;

 if (data2 == "false")
  data = false;
 else if (data2 == "true")
  data = true;
 else
  data = false;
}

void PNF_Boolean::opnot()
{
 if (data == false)
  data = true;
 else if (data == true)
  data = false;
 else
  data = false;
}

void PNF_Boolean::opand(bool b)
{
 data = data && b;
}

void PNF_Boolean::opor(bool b)
{
 data = data || b;
}

PNF_Boolean PNF_Boolean::operator=(const PNF_Boolean & b)
{
 if (this == &b)
  return *this;

 data = b.data;


 return (*this);
}


PNF_Number::PNF_Number()
{
 data = 0;
}

PNF_Number::PNF_Number(double d)
{
 data = d;
}

PNF_Number::~PNF_Number()
{

}

void PNF_Number::put(double d)
{
 data = d;
}

double PNF_Number::get() const
{
 return data;
}

double PNF_Number::to_mem()
{
 return get();
}

void PNF_Number::from_mem(double d)
{
 put(d);
}

void PNF_Number::print()
{
 cout << data;
}

void PNF_Number::fprint(ofstream & fout)
{
 fout << data;
}

void PNF_Number::eprint()
{
 cerr << data;
}

void PNF_Number::read()
{
 cin >> data;
}

void PNF_Number::fread(ifstream & fin)
{
 fin >> data;
}

void PNF_Number::add(double d)
{
 data += d;
}

void PNF_Number::sub(double d)
{
 data -= d;
}

void PNF_Number::mul(double d)
{
 data *= d;
}

void PNF_Number::div(double d)
{
 data /= d;
}

void PNF_Number::mod(double d)
{
 long l = (long)data % (long)d;
 data = l;
}

void PNF_Number::pow(double d)
{
 data = ::pow(data, (int)d);
}

void PNF_Number::root(double d)
{
 if (d == 2)
  data = ::sqrt(data);
 else
 {
  int data2 = (int)data;
  for (int i = (int)d - 1; i != 0; --i)
   data2 = data2 / d;
  data = data2;
 }
}

void PNF_Number::inc(double d)
{
 data += d;
}

void PNF_Number::dec(double d)
{
 data -= d;
}

PNF_Number PNF_Number::operator=(const PNF_Number & n)
{
 if (this == &n)
  return *this;

 this->data = n.data;


 return (*this);
}


PNF_Character::PNF_Character()
{
 data = '\0';
}

PNF_Character::PNF_Character(char d)
{
 data = d;
}

PNF_Character::~PNF_Character()
{

}

void PNF_Character::put(char d)
{
 data = d;
}

char PNF_Character::get() const
{
 return data;
}

double PNF_Character::to_mem()
{
 return (double)data;
}

void PNF_Character::from_mem(double c)
{
 data = (char)c;
}

void PNF_Character::print()
{
 cout << data;
}

void PNF_Character::fprint(ofstream & fout)
{
 fout << data;
}

void PNF_Character::eprint()
{
 cerr << data;
}

void PNF_Character::read()
{
 cin >> data;
}

void PNF_Character::fread(ifstream & fin)
{
 fin >> data;
}

void PNF_Character::add(char d)
{
 data += d;
}

void PNF_Character::sub(char d)
{
 data -= d;
}

void PNF_Character::mul(char d)
{
 data *= d;
}

void PNF_Character::div(char d)
{
 data = data / d;
}

void PNF_Character::mod(char d)
{
 data = data % d;
}

void PNF_Character::pow(char d)
{
 double n1 = (int)data;
 double n2 = (int)d;
 double r;
 r = ::pow(n1, n2);
 int r2 = (int)r;
 data = (char)r2;
}

void PNF_Character::root(char d)
{
 double d2 = (double)d;
 if (d2 == 2)
  data = ::sqrt(data);
 else
 {
  int data2 = (int)data;
  for (int i = (int)d2 - 1; i != 0; --i)
   data2 = data2 / d2;
  data = data2;
 }
}

void PNF_Character::inc(char d)
{
 data += d;
}

void PNF_Character::dec(char d)
{
 data -= d;
}

PNF_Character PNF_Character::operator=(const PNF_Character & c)
{
 if (this == &c)
  return *this;

 this->data = c.data;


 return (*this);
}


PNF_String::PNF_String() : data((char *)"")
{
 
}

PNF_String::PNF_String(String d) : data(d)
{

}

PNF_String::~PNF_String()
{

}

void PNF_String::put(String d)
{
 data = d;
}

String PNF_String::get() const
{
 return data;
}

double * PNF_String::to_mem()
{
 double * ret = new double[data.size()];

 for (unsigned long i = 0; i < data.size(); ++i)
 {
  if ((data.getString().data()[i]) == '\0')
   break;
  ret[i] = (long)data.getString().data()[i];
 }
 ret[data.size()] = 0;


 return ret;
}

void PNF_String::from_mem(double * w)
{
 unsigned long i;
 for (i = 0; w[i] != 0; ++i)
  data[i] = (char)w[i];
}

void PNF_String::print()
{
 cout << data;
}

void PNF_String::fprint(ofstream & fout)
{
 fout << data;
}

void PNF_String::eprint()
{
 cerr << data;
}

void PNF_String::read()
{
 cin >> data;
}

void PNF_String::fread(ifstream & fin)
{
 fin >> data;
}

void PNF_String::add(String d)
{
 data += d;
}

PNF_String PNF_String::operator=(const PNF_String & s)
{
 if (this == &s)
  return *this;

 this->data = s.data;


 return (*this);
}


PNF_Basic_Variable::PNF_Basic_Variable(int n)
{
 type = TVOID;
}

PNF_Basic_Variable::PNF_Basic_Variable(PNF_Void v)
{
 put(v);
}

PNF_Basic_Variable::PNF_Basic_Variable(PNF_Boolean b)
{
 put(b);
}

PNF_Basic_Variable::PNF_Basic_Variable(PNF_Number n)
{
 put(n);
}

PNF_Basic_Variable::PNF_Basic_Variable(PNF_Character c)
{
 put(c);
}

PNF_Basic_Variable::PNF_Basic_Variable(PNF_String s)
{
 put(s);
}

PNF_Basic_Variable::PNF_Basic_Variable(const PNF_Basic_Variable & v)
{
 put(v);
}

long PNF_Basic_Variable::getType() const
{
 return type;
}

void PNF_Basic_Variable::setType(long t)
{
 long t2 = type;
 type = t;

 switch (t2)
 {
  case TVOID:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 // Do nothing...
   	}
   	break;

   	case TBOOLEAN:
   	{
         b = to_boolean();
   	}
   	break;

   	case TNUMBER:
   	{
   	 n = to_number();
   	}
   	break;

   	case TCHARACTER:
   	{
   	 c = to_character();
   	}
   	break;

   	case TSTRING:
   	{
   	 s = to_string();
   	}
   	break;
   }
  }
  break;

  case TBOOLEAN:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 v = to_Void();
   	}
   	break;

   	case TBOOLEAN:
   	{
   	 // Do nothing...
   	}
   	break;

   	case TNUMBER:
   	{
   	 n = to_number();
   	}
   	break;

   	case TCHARACTER:
   	{
   	 c = to_character();
   	}
   	break;

   	case TSTRING:
   	{
   	 s = to_string();
   	}
   	break;
   }
  }
  break;

  case TNUMBER:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 v = to_Void();
   	}
   	break;

   	case TBOOLEAN:
   	{
   	 b = to_boolean();
   	}
   	break;

   	case TNUMBER:
   	{
   	 // Do nothing...
   	}
   	break;

   	case TCHARACTER:
   	{
   	 c = to_character();
   	}
   	break;

   	case TSTRING:
   	{
   	 s = to_string();
   	}
   	break;
   }
  }
  break;

  case TCHARACTER:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 v = to_Void();
   	}
   	break;

   	case TBOOLEAN:
   	{
   	 b = to_boolean();
   	}
   	break;

   	case TNUMBER:
   	{
   	 n = to_number();
   	}
   	break;

   	case TCHARACTER:
   	{
   	 // Do nothing...
   	}
   	break;

   	case TSTRING:
   	{
   	 s = to_string();
   	}
   	break;
   }
  }
  break;

  case TSTRING:
  {
   switch (t)
   {
   	case TVOID:
   	{
   	 v = to_Void();
   	}
   	break;

   	case TBOOLEAN:
   	{
   	 b = to_boolean();
   	}
   	break;

   	case TNUMBER:
   	{
   	 n = to_number();
   	}
   	break;

   	case TCHARACTER:
   	{
   	 c = to_character();
   	}
   	break;

   	case TSTRING:
   	{
   	 // Do nothing...
   	}
   	break;
   }
  }
  break;


  default:
   break;
 }
}

void PNF_Basic_Variable::put(PNF_Void v)
{
 setType(TVOID);
 this->v = v;
}

void PNF_Basic_Variable::put(PNF_Boolean b)
{
 setType(TBOOLEAN);
 this->b = b;
}

void PNF_Basic_Variable::put(PNF_Number n)
{
 setType(TNUMBER);
 this->n = n;
}

void PNF_Basic_Variable::put(PNF_Character c)
{
 setType(TCHARACTER);
 this->c = c;
}

void PNF_Basic_Variable::put(PNF_String s)
{
 setType(TSTRING);
 this->s = s;
}

void PNF_Basic_Variable::put(const PNF_Basic_Variable & v)
{
 setType(v.getType());
 switch (getType())
 {
  case TVOID:
   put(v.to_Void());
   break;

  case TBOOLEAN:
   put(v.to_boolean());
   break;

  case TNUMBER:
   put(v.to_number());
   break;

  case TCHARACTER:
   put(v.to_character());
   break;

  case TSTRING:
   put(v.to_string());
   break;

  default:
  {
   error(ERRORMSG, (char *)"Invalid Type.");
  }
 }
}

double * PNF_Basic_Variable::getm()
{
 static double d = 0;
 double * ret = &d;

 switch (type)
 {
  case TVOID:
       *ret = v.to_mem();
       break;

  case TBOOLEAN:
       *ret = b.to_mem();
       break;

  case TNUMBER:
       *ret = n.to_mem();
       break;

  case TCHARACTER:
       *ret = c.to_mem();
       break;

  case TSTRING:
       ret = s.to_mem();
       break;
 };

 return ret;
}

void PNF_Basic_Variable::putm(double * d)
{
 switch (type)
 {
  case TVOID:
       v.from_mem(*d);
       break;

  case TBOOLEAN:
       b.from_mem(*d);
       break;

  case TNUMBER:
       n.from_mem(*d);
       break;

  case TCHARACTER:
       c.from_mem(*d);
       break;

  case TSTRING:
       s.from_mem(d);
       break;
 };
}

void PNF_Basic_Variable::print()
{
 switch (type)
 {
  case TVOID:
   v.print();
   break;

  case TBOOLEAN:
   b.print();
   break;

  case TNUMBER:
   n.print();
   break;

  case TCHARACTER:
   c.print();
   break;

  case TSTRING:
   s.print();
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Basic_Variable::println()
{
 switch (type)
 {
  case TVOID:
   v.print();
   cout << endl;
   break;

  case TBOOLEAN:
   b.print();
   cout << endl;
   break;

  case TNUMBER:
   n.print();
   cout << endl;
   break;

  case TCHARACTER:
   c.print();
   cout << endl;
   break;

  case TSTRING:
   s.print();
   cout << endl;
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Basic_Variable::fprint(ofstream & fout)
{
 switch (type)
 {
  case TVOID:
   v.fprint(fout);
   break;

  case TBOOLEAN:
   b.fprint(fout);
   break;

  case TNUMBER:
   n.fprint(fout);
   break;

  case TCHARACTER:
   c.fprint(fout);
   break;

  case TSTRING:
   s.fprint(fout);
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Basic_Variable::eprint()
{
 switch (type)
 {
  case TVOID:
   v.eprint();
   break;

  case TBOOLEAN:
   b.eprint();
   break;

  case TNUMBER:
   n.eprint();
   break;

  case TCHARACTER:
   c.eprint();
   break;

  case TSTRING:
   s.eprint();
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Basic_Variable::eprintln()
{
 switch (type)
 {
  case TVOID:
   v.eprint();
   cerr << endl;
   break;

  case TBOOLEAN:
   b.eprint();
   cerr << endl;
   break;

  case TNUMBER:
   n.eprint();
   cerr << endl;
   break;

  case TCHARACTER:
   c.eprint();
   cerr << endl;
   break;

  case TSTRING:
   s.eprint();
   cerr << endl;
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Basic_Variable::read()
{
 switch (getType())
 {
  case TVOID:
   v.read();
   break;

  case TBOOLEAN:
   b.read();
   break;

  case TNUMBER:
   n.read();
   break;

  case TCHARACTER:
   c.read();
   break;

  case TSTRING:
  {
   s.read();
   }
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

void PNF_Basic_Variable::fread(ifstream & fin)
{
 switch (getType())
 {
  case TVOID:
   v.fread(fin);
   break;

  case TBOOLEAN:
   b.fread(fin);
   break;

  case TNUMBER:
   n.fread(fin);
   break;

  case TCHARACTER:
   c.fread(fin);
   break;

  case TSTRING:
  {
   s.fread(fin);
   }
   break;

  default:
   error(ERRORMSG, (char *)"Invalid Type.");
   break;
 }
}

PNF_Void & PNF_Basic_Variable::to_Void()
{
 PNF_Void * v = new PNF_Void();
 return (*v);
}

PNF_Boolean & PNF_Basic_Variable::to_boolean()
{
 PNF_Boolean * b = new PNF_Boolean();

 switch (getType())
 {
  case TVOID:
       b->put(false);
       break;

  case TBOOLEAN:
       *b = this->b;
       break;

  case TNUMBER:
       b->put(n.get());
       break;

  case TCHARACTER:
  	   if (c.get() == 't')
  	    b->put(true);
  	   else if (c.get() == 'f')
  	    b->put(false);
  	   else
  	    b->put(false);
       break;

  case TSTRING:
  	   if (s.get().getString() == "true")
  	    b->put(true);
  	   else if (s.get().getString() == "false")
  	    b->put(false);
  	   else
  	    b->put(false);
       break;
 }

 return (*b);
}

PNF_Number & PNF_Basic_Variable::to_number()
{
 PNF_Number * n = new PNF_Number();

 switch (getType())
 {
  case TVOID:
       n->put(0);
       break;

  case TBOOLEAN:
       if (b.get().getString() == "true")
          n->put(1);
       else
          n->put(0);
       break;

  case TNUMBER:
       *n = this->n;
       break;

  case TCHARACTER:
       n->put(c.get());
       break;

  case TSTRING:
  {
   unsigned long value = 0;
   for (unsigned long i = 0; i < s.get().length(); ++i)
    value += (unsigned long)s.get()[i];
   n->put(value);
  }
  break;
 }

 return (*n);
}

PNF_Character & PNF_Basic_Variable::to_character()
{
 PNF_Character * c = new PNF_Character();

 switch (getType())
 {
  case TVOID:
       *c = '\0';
       break;

  case TBOOLEAN:
       if (b.get().getString() == "true")
        *c = 't';
       else
        *c = 'f';
       break;

  case TNUMBER:
       *c = (char)n.get();
       break;

  case TCHARACTER:
       *c = this->c;
       break;

  case TSTRING:
       *c = s.get()[0];
       break;
 }


 return (*c);
}

PNF_String & PNF_Basic_Variable::to_string()
{
 PNF_String * s = new PNF_String();

 switch (getType())
 {
  case TVOID:
       s->put((char *)"");
       break;

  case TBOOLEAN:
       *s = b.get();
       break;

  case TNUMBER:
       s->put((char)n.get());
       break;

  case TCHARACTER:
       s->put(c.get());
       break;

  case TSTRING:
       *s = this->s;
       break;
 }


 return (*s);
}

PNF_Basic_Variable PNF_Basic_Variable::operator=(const PNF_Basic_Variable & v)
{
 if (this == &v)
  return *this;

  this->v = v.v;
  this->b = v.b;
  this->n = v.n;
  this->c = v.c;
  this->s = v.s;
  this->type = v.type;

  return (*this);
}


PNF_Variable::PNF_Variable(int n)
{
 PNF_Void v;
 put(v);
}

PNF_Variable::PNF_Variable(PNF_Void v)
{
 put(v);
}

PNF_Variable::PNF_Variable(PNF_Boolean b)
{
 put(b);
}

PNF_Variable::PNF_Variable(PNF_Number n)
{
 put(n);
}

PNF_Variable::PNF_Variable(PNF_Character c)
{
 put(c);
}

PNF_Variable::PNF_Variable(PNF_String s)
{
 put(s);
}

PNF_Variable::PNF_Variable(PNF_Basic_Variable * pv, bool b)
{
 put(pv, b);
}

PNF_Variable::PNF_Variable(const PNF_Variable & v)
{
 put(v);
}

PNF_Variable::PNF_Variable(Array<PNF_Basic_Variable> a)
{
 put(a);
}

long PNF_Variable::getType() const
{
 return itstype;
}

void PNF_Variable::setType(long t)
{
 itstype = t;
}

void PNF_Variable::put(PNF_Void v)
{
 itssimple.put(v);
 itstype = TVOID;
 
 itspsimple = NULL;
 itsrsimple = NULL;
}

void PNF_Variable::put(PNF_Boolean b)
{
 itssimple.put(b);
 itstype = TBOOLEAN;
 
 itspsimple = NULL;
 itsrsimple = NULL;
}

void PNF_Variable::put(PNF_Number n)
{
 itssimple.put(n);
 itstype = TNUMBER;
 
 itspsimple = NULL;
 itsrsimple = NULL;
}

void PNF_Variable::put(PNF_Character c)
{
 itssimple.put(c);
 itstype = TCHARACTER;
 
 itspsimple = NULL;
 itsrsimple = NULL;
}

void PNF_Variable::put(PNF_String s)
{
 itssimple.put(s);
 itstype = TSTRING;
 
 itspsimple = NULL;
 itsrsimple = NULL;
}

void PNF_Variable::put(PNF_Basic_Variable v)
{
 itssimple.put(v);
 itstype = itssimple.getType();
 
 itspsimple = NULL;
 itsrsimple = NULL;
}

void PNF_Variable::put(PNF_Basic_Variable * pv, bool b)
{
 if (b == false)
 {
  itspsimple = pv;
  itstype = TPSIMPLE;
  
  itsrsimple = NULL;
 }
 else
 {
  itsrsimple = pv;
  itstype = TRSIMPLE;
  
  itspsimple = NULL;
 }
}

void PNF_Variable::put(Array<PNF_Basic_Variable> a)
{
 itsasimple = a;
 itstype = TASIMPLE;
}

void PNF_Variable::put(const PNF_Variable & v)
{
 itssimple = v.itssimple;
 itspsimple = v.itspsimple;
 itsrsimple = v.itsrsimple;
 itstype = v.itstype;
}
        
 PNF_Basic_Variable PNF_Variable::getsimple() const
 {
  switch (itstype)
  {
   case TVOID:
   case TBOOLEAN:
   case TNUMBER:
   case TCHARACTER:
   case TSTRING:
   {
    return itssimple;
   }
   break;
   
   case TPSIMPLE:
   case TDPSIMPLE:
   case TRSIMPLE:
   {
    PNF_Void v;
    PNF_Basic_Variable v2(v);
    return v2;
   }
   break;
   
   case TASIMPLE:
   {
    return itsasimple[0];
   }
   break;
   
   default:
    error(ERRORMSG, (char *)"Invalid Type.");
  }
 }
 
 PNF_Basic_Variable * PNF_Variable::getpsimple() const
 {
  switch (itstype)
  {
   case TVOID:
   case TBOOLEAN:
   case TNUMBER:
   case TCHARACTER:
   case TSTRING:
   {
    PNF_Void v;
    static PNF_Basic_Variable v2(v);
    static PNF_Basic_Variable * pv2 = &v2;
    return pv2;
   }
   break;
   
   case TPSIMPLE:
   case TDPSIMPLE:
   {
    return itspsimple;
   }
   break;
   
   case TRSIMPLE:
   {
    return NULL;
   }
   break;
   
   case TASIMPLE:
   {
    return NULL;
   }
   break;
  
   default:
    error(ERRORMSG, (char *)"Invalid Type.");
  }
 }
 
 PNF_Basic_Variable * PNF_Variable::getrsimple() const
 {
  switch (itstype)
  {
   case TVOID:
   case TBOOLEAN:
   case TNUMBER:
   case TCHARACTER:
   case TSTRING:
   {
    PNF_Void v;
    static PNF_Basic_Variable v2(v);
    static PNF_Basic_Variable * pv2 = &v2;
    return pv2;
   }
   break;
   
   case TDPSIMPLE:
   case TPSIMPLE:
   {
    return NULL;
   }
   break;
   
   case TRSIMPLE:
   {
    return itsrsimple;
   }
   break;
   
   case TASIMPLE:
   {
    return NULL;
   }
   break;
  
   default:
    error(ERRORMSG, (char *)"Invalid Type.");
  }
 }
 
Array<PNF_Basic_Variable> PNF_Variable::getasimple() const
{
 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
  {
   static Array<PNF_Basic_Variable> v;
   return v;
  }
  break;
   
  case TDPSIMPLE:
  case TPSIMPLE:
  {
   static Array<PNF_Basic_Variable> v;
   return v;
  }
  break;
   
  case TRSIMPLE:
  {
   static Array<PNF_Basic_Variable> v;
   return v;
  }
  break;
   
  case TASIMPLE:
  {
   return itsasimple;
  }
  break;
  
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 }
}

double * PNF_Variable::getm()
{
 double * ret = NULL;

 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
       ret = itssimple.getm();
       break;
       
  case TPSIMPLE:
  case TDPSIMPLE:
   ret = itspsimple->getm();
   break;
  
  case TRSIMPLE:
   ret = itsrsimple->getm();
   break;
   
  case TASIMPLE:
   ret = itsasimple[0].getm();
   break;
       
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 };

 return ret;
}

void PNF_Variable::putm(double * d)
{
 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
       itssimple.putm(d);
       break;
       
  case TPSIMPLE:
  case TDPSIMPLE:
   itspsimple->putm(d);
   break;
   
  case TRSIMPLE:
   itsrsimple->putm(d);
   break;
   
  case TASIMPLE:
   itsasimple[0].putm(d);
   break;
       
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 };
}

void PNF_Variable::print()
{
 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
   itssimple.print();
   break;
   
  case TPSIMPLE:
   cout << (int)itspsimple;
   break;
   
  case TDPSIMPLE:
   itspsimple->print();
   break;
   
  case TRSIMPLE:
   itsrsimple->print();
   break;
   
  case TASIMPLE:
  {
   for (unsigned long i = 0; i < itsasimple.length(); ++i)
    itsasimple[i].print();
  }
  break;
   
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 }
}

void PNF_Variable::println()
{
 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
   itssimple.println();
   break;
   
  case TPSIMPLE:
   cout << (int)itspsimple << endl;
   break;
   
  case TDPSIMPLE:
   itspsimple->println();
   break;
   
  case TRSIMPLE:
   itsrsimple->println();
   break;
   
  case TASIMPLE:
  {
   for (unsigned long i = 0; i < itsasimple.length(); ++i)
    itsasimple[i].print();
   cout << endl;
  }
  break;
   
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 }
}

void PNF_Variable::eprint()
{
 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
   itssimple.eprint();
   break;
   
  case TPSIMPLE:
   cerr << (int)itspsimple;
   break;
   
  case TDPSIMPLE:
   itspsimple->eprint();
   break;
   
  case TRSIMPLE:
   itsrsimple->eprint();
   break;
   
   case TASIMPLE:
  {
   for (unsigned long i = 0; i < itsasimple.length(); ++i)
    itsasimple[i].eprint();
  }
  break;
   
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 }
}

void PNF_Variable::eprintln()
{
 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
   itssimple.eprintln();
   break;
   
  case TPSIMPLE:
   cerr << (int)itspsimple << endl;
   break;
   
  case TDPSIMPLE:
   itspsimple->eprintln();
   break;
   
  case TRSIMPLE:
   itsrsimple->eprintln();
   break;
   
  case TASIMPLE:
  {
   for (unsigned long i = 0; i < itsasimple.length(); ++i)
    itsasimple[i].eprint();
   cerr << endl;
  }
  break;
   
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 }
}

void PNF_Variable::read()
{
 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
   itssimple.read();
   break;
   
  case TPSIMPLE:
  {
   PNF_Number n;
   n.read();
   itspsimple = (int)n.get();
  }
  break;
   
  case TDPSIMPLE:
   itspsimple->read();
   break;
   
  case TRSIMPLE:
   itsrsimple->read();
   break;
   
  case TASIMPLE:
  {
   for (unsigned long i = 0; i < itsasimple.length(); ++i)
   {
    cout << "?: ";
    itsasimple[i].read();
    cout << endl;
   }
  }
  break;
   
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 }
}

void PNF_Variable::fprint(ofstream & fout)
{
 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
   itssimple.fprint(fout);
   break;
   
  case TPSIMPLE:
   fout << (int)itspsimple;
   break;
   
  case TDPSIMPLE:
   itspsimple->fprint(fout);
   break;
   
  case TRSIMPLE:
   itsrsimple->fprint(fout);
   break;
   
  case TASIMPLE:
  {
   for (unsigned long i = 0; i < itsasimple.length(); ++i)
    itsasimple[i].fprint(fout);
  }
  break;
   
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 }
}

void PNF_Variable::fread(ifstream & fin)
{
 switch (itstype)
 {
  case TVOID:
  case TBOOLEAN:
  case TNUMBER:
  case TCHARACTER:
  case TSTRING:
   itssimple.fread(fin);
   break;
   
  case TPSIMPLE:
  {
   PNF_Number n;
   n.fread(fin);
   itspsimple = (int)n.get();
  }
  break;
   
  case TDPSIMPLE:
   itspsimple->fread(fin);
   break;
   
  case TRSIMPLE:
   itsrsimple->fread(fin);
   break;
   
  case TASIMPLE:
  {
   for (unsigned long i = 0; i < itsasimple.length(); ++i)
   {
    itsasimple[i].fread(fin);
   }
  }
  break;
   
  default:
   error(ERRORMSG, (char *)"Invalid Type.");
 }
}

PNF_Void & PNF_Variable::to_Void()
{
 return itssimple.to_Void();
}

PNF_Boolean & PNF_Variable::to_boolean()
{
 return itssimple.to_boolean();
}

PNF_Number & PNF_Variable::to_number()
{
 return itssimple.to_number();
}

PNF_Character & PNF_Variable::to_character()
{
 return itssimple.to_character();
}

PNF_String & PNF_Variable::to_string()
{
 return itssimple.to_string();
}

PNF_Basic_Variable * PNF_Variable::to_psimple()
{
 return itspsimple; 
}

PNF_Basic_Variable * PNF_Variable::to_rsimple()
{
 return itsrsimple;
}

Array<PNF_Basic_Variable> PNF_Variable::to_asimple()
{
 return itsasimple;
}

PNF_Variable & PNF_Variable::operator=(const PNF_Variable & v)
{
 put(v);
 return *this;
}


void PNF_RangeD::PNF_RangeD_init(String nm = (char *)"", PNF_Number f = -1, PNF_Number t = -1)
{
 itsname = nm;
 itsfrom = f;
 itsto = t;
}

PNF_RangeD::PNF_RangeD(String nm = (char *)"", PNF_Number f = -1, PNF_Number t = -1)
{
 PNF_RangeD_init(nm, f, t);
}

PNF_RangeD::PNF_RangeD(int e)
{
 PNF_RangeD_init();
}

PNF_RangeD::~PNF_RangeD()
{

}

String PNF_RangeD::name()
{
 return itsname;
}

void PNF_RangeD::name(String n)
{
 itsname = n;
}

PNF_Number PNF_RangeD::from()
{
 return itsfrom;
}

void PNF_RangeD::from(PNF_Number n)
{
 itsfrom = n;
}

PNF_Number PNF_RangeD::to()
{
 return itsto;
}

void PNF_RangeD::to(PNF_Number n)
{
 itsto = n;
}

void PNF_RangeD::print()
{
	
}

void PNF_RangeD::println()
{
	
}


PNF_RangeT1::PNF_RangeT1_init(String nm = (char *)"", PNF_Number f = -1, PNF_Number t = -1, PNF_Number n = 1)
{
 PNF_RangeD_init(nm, f, t);
 put(n);
}

PNF_RangeT1::PNF_RangeT1(String nm = (char *)"", PNF_Number f = -1,  PNF_Number t = -1, PNF_Number n = 0)
{
 PNF_RangeT1_init(nm, f, t, n);
}

PNF_RangeT1::PNF_RangeT1(int e)
{
 PNF_RangeT1_init();
}

PNF_RangeT1::~PNF_RangeT1()
{

}

PNF_Number PNF_RangeT1::get()
{
 return data;
}

bool PNF_RangeT1::put(PNF_Number n)
{
 bool ret = false;
 double f = itsfrom.get();
 double t = itsto.get();
 double d = n.get();

 if (d >= f && d <= t)
 {
  data.put(d);
  ret = true;
 }
 else if (f == -1 && t == -1)
  ret = false;
 else
  ret = false;


 return ret;
}

void PNF_RangeT1::print()
{
 cout << data.get();
}

void PNF_RangeT1::println()
{
 cout << data.get() << endl;
}


PNF_RangeT2::PNF_RangeT2()
{
 PNF_RangeD_init();
}

PNF_RangeT2::PNF_RangeT2(unsigned long e)
{
 PNF_RangeD_init();
}

PNF_RangeT2::~PNF_RangeT2()
{

}

bool PNF_RangeT2::put(unsigned long index, PNF_Number d)
{
 if (index >= data.length())
 {
  for (unsigned long i = data.length(); i <= index; ++i)
   data.insert();

  data[index].from(itsfrom);
  data[index].to(itsto);
  return data[index].put(d);
 }
 else
 {
  data[index].from(itsfrom);
  data[index].to(itsto);
  return data[index].put(d);
 }
}

PNF_Number PNF_RangeT2::get(unsigned long index)
{
 if (index >= data.length())
 {
  String num = (char *)"";
  num.from_long(index);
  String msg = "Type2 Range index out of bounds, index = " + num.getString();
  msg += (char *)"\n";
  error(ERRORMSG, msg);
 }
 else
  return data[index].get();
}

bool PNF_RangeT2::fill()
{
 bool ret = false;

 // * DEBUG: Might be bug, might need to be data.length(), instead of data.length() - 1
 for (unsigned long i = data.length() - 1; i > 0; --i)
  data.remove();

 double f = itsfrom.get();
 double t = itsto.get();
 double d = f;

 for (unsigned long i = 0; d >= f && d <= t; ++i, ++d)
 {
  ret = put(i, d);
 }

 return ret;
}

unsigned long PNF_RangeT2::length()
{
 return data.length();
}

void PNF_RangeT2::print()
{
 for (unsigned long i = 0; i < length(); ++i)
  cout << i << ": " << data[i].get().get();
}
 
void PNF_RangeT2::println()
{
 for (unsigned long i = 0; i < length(); ++i)
  cout << i << ": " << data[i].get().get() << endl;
}


void PNF_EnumD::PNF_EnumD_init(String name)
{
 itsname = (char *)"";
}

PNF_EnumD::PNF_EnumD(String name = (char *)"")
{
 PNF_EnumD_init();
}

PNF_EnumD::PNF_EnumD(unsigned long e)
{
 PNF_EnumD_init();
}

PNF_EnumD::~PNF_EnumD()
{

}

unsigned long PNF_EnumD::length()
{
 return itsnames.length();
}

String PNF_EnumD::get(unsigned long index)
{
 if (index > length())
 {
  error(ERRORMSG, (char *)"Bad Enum index.");
  return (char *)"";
 }
 else
  return itsnames[index];
}

void PNF_EnumD::set(unsigned long index, String str)
{
 if (index >= length())
 {
  for (unsigned long i = length(); i <= index; ++i)
   itsnames.insert();

  itsnames[index] = str;
 }
 else
  itsnames[index] = str;
}

String PNF_EnumD::name()
{
 return itsname;
}

void PNF_EnumD::name(String name)
{
 itsname = name;
}

Array<String> PNF_EnumD::names()
{
 return itsnames;
}

void PNF_EnumD::names(Array<String> n)
{
 itsnames = n;
}


void PNF_Enum::PNF_Enum_init(String value)
{
 itsvalue = value;
}

PNF_Enum::PNF_Enum(String value = (char *)"")
{
 PNF_Enum_init(value);
}

PNF_Enum::PNF_Enum(unsigned long e)
{
 PNF_Enum_init();
}

PNF_Enum::~PNF_Enum()
{

}

String PNF_Enum::value()
{
 return itsvalue;
}

bool PNF_Enum::value(String v)
{
 bool found = false;
 String n = (char *)"";
 for (unsigned long i = 0; i < itsnames.length(); ++i)
 {
  n = itsnames[i];
  if (v == n)
  {
   itsvalue = v;
   found = true;
   break;
  }
 }

 return found;
}

void PNF_Enum::print()
{
 cout << itsvalue;
}

void PNF_Enum::println()
{
 cout << itsvalue << endl;
}


PNF_Object::PNF_Object(unsigned long e = 0)
{
 itstype = TOSIMPLE;
}

PNF_Object::~PNF_Object()
{

}

PNF_Variable PNF_Object::simple()
{
 switch (type())
 {
  case TOSIMPLE:
   return itssimple;

  default:
   PNF_Number n(0);
   PNF_Variable v(n);
   return v;
 }
}

void PNF_Object::simple(PNF_Variable s)
{
 itstype = TOSIMPLE;

 PNF_Void v;
 itssimple.put(v);

 switch (s.getType())
 {
  case TVOID:
  {
   PNF_Void v;
   itssimple.put(v);
  }
  break;

  case TBOOLEAN:
  {
   itssimple.put(s.to_boolean());
  }
  break;

  case TNUMBER:
  {
   itssimple.put(s.to_number());
  }
  break;

  case TCHARACTER:
  {
   itssimple.put(s.to_character());
  }
  break;

  case TSTRING:
  {
   itssimple.put(s.to_string());
  }
  break;

  default:
   error(ERRORMSG, (char *)"Invalid type.");
 }
}

PNF_RangeT1 PNF_Object::t1range()
{
 switch (type())
 {
  case TORANGET1:
   return itst1range;

  default:
   PNF_RangeT1 r;
   return r;
 }
}

void PNF_Object::t1range(PNF_RangeT1 t1)
{
 itst1range = t1;
 itstype = TORANGET1;
}

PNF_RangeT2 PNF_Object::t2range()
{
 switch (type())
 {
  case TORANGET2:
   return itst2range;

  default:
   PNF_RangeT2 r;
   return r;
 }
}

void PNF_Object::t2range(PNF_RangeT2 t2)
{
 itst2range = t2;
 itstype = TORANGET2;
}

PNF_Enum PNF_Object::Enum()
{
 switch (type())
 {
  case TOENUM:
   return itsenum;

  default:
   PNF_Enum e;
   return e;
 }
}

void PNF_Object::Enum(PNF_Enum e)
{
 itsenum = e;
 itstype = TOENUM;
}

PNF_Object_Type PNF_Object::type()
{
 return itstype;
}

void PNF_Object::type(PNF_Object_Type type)
{
 itstype = type;
}

void PNF_Object::print()
{
 switch (type())
 {
  case TOSIMPLE:
   itssimple.print();
   break;
   
  case TORANGET1:
  	itst1range.print();
  	break;
  	
  case TORANGET2:
  	itst2range.print();
  	break;
  	
  case TOENUM:
  	itsenum.print();
  	break;
  	
  default:
   throw new Exception((char *)"Invalid Object Type.", (char *)__FILE__, __LINE__);
 }
}

void PNF_Object::println()
{
 switch (type())
 {
  case TOSIMPLE:
   itssimple.println();
   break;
   
  case TORANGET1:
  	itst1range.println();
  	break;
  	
  case TORANGET2:
  	itst2range.println();
  	break;
  	
  case TOENUM:
  	itsenum.println();
  	break;
  	
  default:
   throw new Exception((char *)"Invalid Object Type.", (char *)__FILE__, __LINE__);
 }
};


void PNF_Basic_Object2::PNF_Basic_Object2_init(const PNF_Variable & v)
{
 itssimple = v;
 itstype = TSIMPLE;
 itsstruct = NULL;
}

PNF_Basic_Object2::PNF_Basic_Object2(const PNF_Variable & v)
{
 PNF_Basic_Object2_init(v);
}

PNF_Basic_Object2::PNF_Basic_Object2(const PNF_RangeT1 & v) : itst1range(v), itstype(TRANGET1)
{

}

PNF_Basic_Object2::PNF_Basic_Object2(const PNF_RangeT2 & v) : itst2range(v), itstype(TRANGET2)
{

}

PNF_Basic_Object2::PNF_Basic_Object2(const PNF_Enum & v) : itsenum(v), itstype(TENUM)
{

}

PNF_Basic_Object2::PNF_Basic_Object2(PNF_Struct * v) : itsstruct(v), itstype(TSTRUCT)
{

}

PNF_Basic_Object2::PNF_Basic_Object2(int i)
{
 static PNF_Variable v;
 PNF_Basic_Object2_init(v);
}

PNF_Basic_Object2::~PNF_Basic_Object2()
{

}

PNF_Basic_Object2::PNF_Basic_Object2(const PNF_Basic_Object2 & o)
{
 put(o);
}

const PNF_Basic_Object2 & PNF_Basic_Object2::get() const
{
 return *this;
}

void PNF_Basic_Object2::put(const PNF_Basic_Object2 o)
{
 itssimple = o.itssimple;
 itst1range = o.itst1range;
 itst2range = o.itst2range;
 itsenum = o.itsenum;
 itstype = o.itstype;
}

PNF_Variable & PNF_Basic_Object2::simple()
{
 switch (type())
 {
  case TSIMPLE:
   return itssimple;
   
  default:
   PNF_Number n(0);
   PNF_Variable v(n);
   return v;
 }
}

void PNF_Basic_Object2::simple(PNF_Variable s)
{
 type(TSIMPLE);
 itssimple = s;
}

PNF_RangeT1 & PNF_Basic_Object2::t1range()
{
 switch (type())
 {
  case TRANGET1:
   return itst1range;
   
  default:
   static PNF_RangeT1 t;
   return t;
 }
}

void PNF_Basic_Object2::t1range(PNF_RangeT1 t1)
{
 type(TRANGET1);
 itst1range = t1;
}

PNF_RangeT2 & PNF_Basic_Object2::t2range()
{
 switch (type())
 {
  case TRANGET2:
   return itst2range;
   
  default:
   static PNF_RangeT2 t;
   return t;
 }
}

void PNF_Basic_Object2::t2range(PNF_RangeT2 t2)
{
 type(TRANGET2);
 itst2range = t2;
}

PNF_Enum & PNF_Basic_Object2::Enum()
{
 switch (type())
 {
  case TENUM:
   return itsenum;
   
  default:
   PNF_Enum e;
   return e;
 }
}
  
void PNF_Basic_Object2::Enum(PNF_Enum e)
{
 type(TENUM);
 itsenum = e;
}

PNF_Struct * PNF_Basic_Object2::Struct()
{
 return itsstruct;
}

void PNF_Basic_Object2::Struct(PNF_Struct * s)
{
 type(TSTRUCT);
 itsstruct = s;
}

PNF_Type_Enum PNF_Basic_Object2::type()
{
 return itstype;
}

void PNF_Basic_Object2::type(PNF_Type_Enum type)
{
 itstype = type;
}
  
void PNF_Basic_Object2::print()
{
 switch (type())
 {
  case TSIMPLE:
   itssimple.print();
   break;
   
  case TRANGET1:
   itst1range.print();
   break;
   
  case TRANGET2:
   itst2range.print();
   break;
   
  case TENUM:
   itsenum.print();
   break;
   
  default:
   error(ERRORMSG, (char *)"Invalid type.");
 }
}

void PNF_Basic_Object2::println()
{
 switch (type())
 {
  case TSIMPLE:
   itssimple.println();
   break;
   
  case TRANGET1:
   itst1range.println();
   break;
   
  case TRANGET2:
   itst2range.println();
   break;
   
  case TENUM:
   itsenum.println();
   break;
   
  default:
   error(ERRORMSG, (char *)"Invalid type.");
 }
}


PNF_Object2::PNF_Object2(const PNF_Variable & v)
{
 object(v);
}

PNF_Object2::PNF_Object2(const PNF_RangeT1 & v)
{
 object(v);
}

PNF_Object2::PNF_Object2(const PNF_RangeT2 & v)
{
 object(v);
}
PNF_Object2::PNF_Object2(const PNF_Enum & v)
{
 object(v);
}

PNF_Object2::PNF_Object2(PNF_Basic_Object2 * v, bool f)
{
 if (f == false)
 {
  pobject(v);
 }
 else
 {
  robject(v);
 }
}

PNF_Object2::PNF_Object2(Array<PNF_Basic_Object2 *> v)
{
 aobject(v);
}

PNF_Object2::PNF_Object2(int i)
{
 static PNF_Variable v;
 object(v);
}

PNF_Object2::~PNF_Object2()
{
}

PNF_Object2::PNF_Object2(const PNF_Object2 & o)
{
 put(o);
}

const PNF_Object2 & PNF_Object2::get() const
{
 return *this;
}

void PNF_Object2::put(const PNF_Object2 & o)
{
 itsobject = o.itsobject;
 itspobject = o.itspobject;
 itsrobject = o.itsrobject;
 itsaobject = o.itsaobject;
 itstype = o.itstype;
}

PNF_Basic_Object2 & PNF_Object2::object()
{
 switch (type())
 {
  case TOBJECT:
   return itsobject;
   
  default:
   error(ERRORMSG, (char *)"Invalid type.");
 }
}

void PNF_Object2::object(const PNF_Basic_Object2 & o)
{
 type(TOBJECT);
 itsobject = o;
 
 itspobject = NULL;
 itsrobject = NULL;
}
  
PNF_Basic_Object2 * PNF_Object2::pobject()
{
 switch (type())
 {
  case TPOBJECT:
  case TDOBJECT:
   return itspobject;
   
  default:
   error(ERRORMSG, (char *)"Invalid type.");
 }
}

void PNF_Object2::pobject(PNF_Basic_Object2 * o)
{
 type(TPOBJECT);
 itspobject = o;
 
 itsrobject = NULL;
}
  
PNF_Basic_Object2 * PNF_Object2::robject()
{
 switch (type())
 {
  case TROBJECT:
   return itsrobject;
   
  default:
   error(ERRORMSG, (char *)"Invalid type."); 
 }
}

void PNF_Object2::robject(PNF_Basic_Object2 * o)
{
 type(TROBJECT);
 itsrobject = o;
 
 itspobject = NULL;
}
  
Array<PNF_Basic_Object2 *> PNF_Object2::aobject()
{
 switch (type())
 {
  case TAOBJECT:
   return itsaobject;
   
  default:
   error(ERRORMSG, (char *)"Invalid type."); 
 }
}

void PNF_Object2::aobject(Array<PNF_Basic_Object2 *> o)
{
 type(TAOBJECT);
 itsaobject = o;
 
 itspobject = NULL;
 itsrobject = NULL;
}
  
void PNF_Object2::aput(unsigned long index, const PNF_Basic_Object2 & o)
{
 type(TAOBJECT);
 if (index >= alength())
 {
  for (unsigned j = alength(); index >= alength(); ++j)
  {
   ainsert();
   static PNF_Basic_Object2 v;
   PNF_Variable v2((PNF_Number)0);
   v.simple(v2);
   itsaobject.put(&v, j);
  }
 }
 
 itsaobject.put(&o, index);
}

PNF_Basic_Object2 PNF_Object2::aget(unsigned long index)
{
 type(TAOBJECT);
 if (index >= alength())
 {
  for (unsigned j = alength(); index >= alength(); ++j)
  {
   ainsert();
   static PNF_Basic_Object2 v;
   PNF_Variable v2((PNF_Number)0);
   v.simple(v2);
   itsaobject.put(&v, j);
  }
 }
 
 return *itsaobject.get(index);
}

unsigned long PNF_Object2::alength()
{
 type(TAOBJECT);
 return itsaobject.length();
}
  
void PNF_Object2::ainsert()
{
 type(TAOBJECT);
 itsaobject.insert();
}

void PNF_Object2::aremove()
{
 type(TAOBJECT);
 itsaobject.remove();
}
  
  
PNF_Type_Enum PNF_Object2::type()
{
 return itstype;
}

void PNF_Object2::type(PNF_Type_Enum e)
{
 itstype = e;
}
  
  
void PNF_Object2::print()
{
 switch (type())
 {
  case TOBJECT:
   itsobject.print();
   break;
   
  case TPOBJECT:
   cout << itspobject;
   break;
   
  case TDOBJECT:
   itspobject->print();
   break;
   
  case TROBJECT:
   itsrobject->print();
   break;
   
  case TAOBJECT:
  {
   for (unsigned long i = 0; i < alength(); ++i)
    itsaobject[i]->print();
  }
  break;
  
  default:
   error(ERRORMSG, (char *)"Invalid type.");
 }
}

void PNF_Object2::println()
{
 switch (type())
 {
  case TOBJECT:
   itsobject.println();
   break;
   
  case TPOBJECT:
   cout << itspobject << endl;
   break;
   
  case TDOBJECT:
   itspobject->println();
   break;
   
  case TROBJECT:
   itsrobject->println();
   break;
   
  case TAOBJECT:
  {
   for (unsigned long i = 0; i < alength(); ++i)
    itsaobject[i]->println();
  }
  break;
  
  default:
   error(ERRORMSG, (char *)"Invalid type.");
 }
}

PNF_Object2 & PNF_Object2::operator=(const PNF_Object2 & o)
{
 if (this == &o)
  return *this;
  
 put(o);
}


template <class T>
PNF_Array<T>::PNF_Array(unsigned long s = 1)
{
 itsname = (char *)"";
}

template <class T>
PNF_Array<T>::~PNF_Array()
{

}

template <class T>
String PNF_Array<T>::name()
{
 return itsname;
}

template <class T>
void PNF_Array<T>::name(String name)
{
 itsname = name;
}


PNF_Struct::PNF_Struct(int i) : itsname(""), itstype("")
{
 for (unsigned long i = 0; i < itsmembers.length(); ++i)
 {
  if (this == ((itsmembers[i]).object().Struct()))
  {
   error(ERRORMSG, (char *)"Incomplete type; recursion detected.");
   exit(-1);
  }
 }
}

bool PNF_Struct::Use(String name)
{
 bool found = false;
 for (unsigned long i = 0; i < itsmembers.length(); ++i)
 {
  if (itsmembernames[i] == name)
  {
   found = true;
   break;
  }
 }
 
 if (!found)
 {
  return false;
 }
 return true;
}

bool PNF_Struct::Use(unsigned long u)
{
 if (u >= itsmembers.length())
 {
  return false;
 }
  
 itsuse = u;
 return true;
}

unsigned long PNF_Struct::Using()
{
 return itsuse;
}

String PNF_Struct::name()
{
 return itsname;
}

void PNF_Struct::name(String n)
{
 itsname = n;
}

String PNF_Struct::type()
{
 return itstype;
}

void PNF_Struct::type(String n)
{
 itstype = n;
}
  
PNF_Object2 & PNF_Struct::get()
{
 return itsmembers[itsuse];
}

void PNF_Struct::put(const PNF_Object2 & p, String name)
{
 if (this == p.object().Struct())
 {
  error(ERRORMSG, (char *)"Incomplete type; recursion detected.");
  exit(-1);
 }
 itsmembers[itsuse] = p;
 itsmembernames[itsuse] = name;
}
  
void PNF_Struct::add()
{
 itsmembers.insert();
 itsmembernames.insert();
}

unsigned long PNF_Struct::mlength()
{
 return itsmembers.length();
}

void PNF_Struct::remove()
{
 itsmembers.remove();
 itsmembernames.remove();
}


#endif // PNF_Types_cpp
