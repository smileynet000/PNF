#ifndef PNF_Types_hpp
#define PNF_Types_hpp
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
#include "Array2.cpp"
#include "String2.cpp"


// Forward declarations
class PNF_Basic_Object2;
class PNF_Struct;
class PNF_Union;
class PNF_Object2;


// Classes
class PNF_Void
{
 public:
        void put();
        void get() const;

        double to_mem();
        void from_mem(double i);

        void print();
        void eprint();
        void read();

        void fprint(ofstream & fout);
        void fread(ifstream & fin);


        PNF_Void operator=(const PNF_Void & v) const;
};

class PNF_Boolean
{
 protected:
           bool data;

 public:
        PNF_Boolean();
        PNF_Boolean(bool d);
        ~PNF_Boolean();


        void put(bool d);
        String get() const;

        double to_mem();
        void from_mem(double i);

        void print();
        void eprint();
        void read();

        void fprint(ofstream & fout);
        void fread(ifstream & fin);


        void opnot();
        void opand(bool b);
        void opor(bool b);


        PNF_Boolean operator=(const PNF_Boolean & b);
};

class PNF_Number
{
 protected:
           double data;


 public:
        PNF_Number();
        PNF_Number(double d);
        ~PNF_Number();

        void put(double d);
        double get() const;


        double to_mem();
        void from_mem(double d);

        void print();
        void eprint();
        void read();

        void fprint(ofstream & fout);
        void fread(ifstream & fin);


        void add(double d);
        void sub(double d);
        void mul(double d);
        void div(double d);
        void mod(double d);

        void pow(double d);
        void root(double d);
        void inc(double d);
        void dec(double d);


        PNF_Number operator=(const PNF_Number & n);
};

class PNF_Character
{
 protected:
           char data;


 public:
        PNF_Character();
        PNF_Character(char d);
        ~PNF_Character();

        void put(char d);
        char get() const;

        double to_mem();
        void from_mem(double c);

        void print();
        void eprint();
        void read();

        void fprint(ofstream & fout);
        void fread(ifstream & fin);


        void add(char d);
        void sub(char d);
        void mul(char d);
        void div(char d);
        void mod(char d);

        void pow(char d);
        void root(char d);
        void inc(char d);
        void dec(char d);


        PNF_Character operator=(const PNF_Character & c);
};

class PNF_String
{
 protected:
           String data;

 public:
        PNF_String();
        PNF_String(String d);
        ~PNF_String();

        void put(String d);
        String get() const;

        double * to_mem();
        void from_mem(double * w);

        void print();
        void eprint();
        void read();

        void fprint(ofstream & fout);
        void fread(ifstream & fin);


        void add(String d);


        PNF_String operator=(const PNF_String & s);
};

class PNF_Basic_Variable
{
 private:
         PNF_Void v;
         PNF_Boolean b;
         PNF_Number n;
         PNF_Character c;
         PNF_String s;


         long type;


 public:
 		PNF_Basic_Variable(int n = 0);
 		PNF_Basic_Variable(PNF_Void v);
 		PNF_Basic_Variable(PNF_Boolean b);
 		PNF_Basic_Variable(PNF_Number n);
 		PNF_Basic_Variable(PNF_Character c);
 		PNF_Basic_Variable(PNF_String s);

 		PNF_Basic_Variable(const PNF_Basic_Variable & v);


        long getType() const;
        void setType(long t);


        void put(PNF_Void v);
        void put(PNF_Boolean b);
        void put(PNF_Number n);
        void put(PNF_Character c);
        void put(PNF_String s);
        void put(const PNF_Basic_Variable & v);

        double * getm();
        void putm(double * d);

        void print();
        void println();
        void eprint();
        void eprintln();
        void read();

        void fprint(ofstream & fout);
        void fread(ifstream & fin);


        PNF_Void & to_Void();
        PNF_Boolean & to_boolean();
        PNF_Number & to_number();
        PNF_Character & to_character();
        PNF_String & to_string();


        PNF_Basic_Variable operator=(const PNF_Basic_Variable & v);
};

class PNF_Variable
{
 private:
         PNF_Basic_Variable itssimple;
         PNF_Basic_Variable * itspsimple;
         PNF_Basic_Variable * itsrsimple;
         Array<PNF_Basic_Variable> itsasimple;


         long itstype;


 public:
 		PNF_Variable(int n = 0);
 		PNF_Variable(PNF_Void v);
 		PNF_Variable(PNF_Boolean b);
 		PNF_Variable(PNF_Number n);
 		PNF_Variable(PNF_Character c);
 		PNF_Variable(PNF_String s);
 		PNF_Variable(PNF_Basic_Variable * pv, bool b = false);
 		PNF_Variable(Array<PNF_Basic_Variable> a);

 		PNF_Variable(const PNF_Variable & v);


        long getType() const;
        void setType(long t);


        void put(PNF_Void v);
        void put(PNF_Boolean b);
        void put(PNF_Number n);
        void put(PNF_Character c);
        void put(PNF_String s);
        void put(const PNF_Basic_Variable v);
        void put(PNF_Basic_Variable * pv, bool b = false);
        void put(Array<PNF_Basic_Variable> a);
        void put(const PNF_Variable & v);
        
        PNF_Basic_Variable getsimple() const;
        PNF_Basic_Variable * getpsimple() const;
        PNF_Basic_Variable * getrsimple() const;
        Array<PNF_Basic_Variable> getasimple() const;

        double * getm();
        void putm(double * d);

        void print();
        void println();
        void eprint();
        void eprintln();
        void read();

        void fprint(ofstream & fout);
        void fread(ifstream & fin);


        PNF_Void & to_Void();
        PNF_Boolean & to_boolean();
        PNF_Number & to_number();
        PNF_Character & to_character();
        PNF_String & to_string();
        PNF_Basic_Variable * to_psimple();
        PNF_Basic_Variable * to_rsimple();
        Array<PNF_Basic_Variable> to_asimple();


        PNF_Variable & operator=(const PNF_Variable & v);
};

class PNF_RangeD
{
 protected:
 	PNF_Number itsfrom;
 	PNF_Number itsto;
 	String itsname;
 	
 	
 	void PNF_RangeD_init(String nm, PNF_Number f, PNF_Number t);


 public:
 	PNF_RangeD(String nm, PNF_Number f, PNF_Number t);
 	PNF_RangeD(int e);
 	virtual ~PNF_RangeD();


 	String name();
 	void name(String n);


 	PNF_Number from();
 	void from(PNF_Number n);

 	PNF_Number to();
 	void to(PNF_Number n);
 	
 	virtual void print();
 	virtual void println();
};

class PNF_RangeT1 : public PNF_RangeD
{
 private:
 	PNF_Number data;
 	
 	
 	PNF_RangeT1_init(String nm, PNF_Number f, PNF_Number t, PNF_Number n);


 public:
 	PNF_RangeT1(String nm, PNF_Number f, PNF_Number t, PNF_Number n);
 	PNF_RangeT1(int e);
 	~PNF_RangeT1();


 	PNF_Number get();
 	bool put(PNF_Number n);
 	
 	virtual void print();
 	virtual void println();
};

class PNF_RangeT2 : public PNF_RangeD
{
 private:
  Array<PNF_RangeT1> data;


 public:
  PNF_RangeT2();
  PNF_RangeT2(unsigned long e);
  ~PNF_RangeT2();


  bool put(unsigned long index, PNF_Number d);
  PNF_Number get(unsigned long index);
  bool fill();


  unsigned long length();
  
  
  virtual void print();
  virtual void println();
};

class PNF_EnumD
{
 protected:
  Array<String> itsnames;
  String itsname;
  
  
  void PNF_EnumD_init(String name = (char *)"");


 public:
  PNF_EnumD(String name);
  PNF_EnumD(unsigned long e);
  ~PNF_EnumD();


  unsigned long length();

  String get(unsigned long index);
  void set(unsigned long index, String str);

  String name();
  void name(String name);

  Array<String> names();
  void names(Array<String> n);
};

class PNF_Enum : public PNF_EnumD
{
 protected:
  String itsvalue;
  
  
  void PNF_Enum_init(String value = (char *)"");


 public:
  PNF_Enum(String value);
  PNF_Enum(unsigned long e);

  ~PNF_Enum();

  String value();
  bool value(String v);
  
  void print();
  void println();
};

class PNF_Object
{
 private:
  PNF_Variable itssimple;
  PNF_RangeT1 itst1range;
  PNF_RangeT2 itst2range;
  PNF_Enum itsenum;

  PNF_Object_Type itstype;


 public:
  PNF_Object(unsigned long e);
  ~PNF_Object();


  PNF_Variable simple();
  void simple(PNF_Variable s);

  PNF_RangeT1 t1range();
  void t1range(PNF_RangeT1 t1);

  PNF_RangeT2 t2range();
  void t2range(PNF_RangeT2 t2);

  PNF_Enum Enum();
  void Enum(PNF_Enum e);

  PNF_Object_Type type();
  void type(PNF_Object_Type type);
  
  void print();
  void println();
};

class PNF_Basic_Object2
{
 protected:
  PNF_Variable itssimple;
  PNF_RangeT1 itst1range;
  PNF_RangeT2 itst2range;
  PNF_Enum itsenum;
  PNF_Struct * itsstruct;
  PNF_Union * itsunion;

  PNF_Type_Enum itstype;
  
  
  void PNF_Basic_Object2_init(const PNF_Variable & v);


 public:
  PNF_Basic_Object2(const PNF_Variable & v);
  PNF_Basic_Object2(const PNF_RangeT1 & v);
  PNF_Basic_Object2(const PNF_RangeT2 & v);
  PNF_Basic_Object2(const PNF_Enum & v);
  PNF_Basic_Object2(PNF_Struct * v);
  
  PNF_Basic_Object2(int i = 0);
  
  ~PNF_Basic_Object2();
  
  PNF_Basic_Object2(const PNF_Basic_Object2 & o);
  
  
  const PNF_Basic_Object2 & get() const;
  void put(const PNF_Basic_Object2 o);


  PNF_Variable & simple();
  void simple(PNF_Variable s);

  PNF_RangeT1 & t1range();
  void t1range(PNF_RangeT1 t1);

  PNF_RangeT2 & t2range();
  void t2range(PNF_RangeT2 t2);

  PNF_Enum & Enum();
  void Enum(PNF_Enum e);
  
  PNF_Struct * Struct();
  void Struct(PNF_Struct  * s);

  PNF_Union * Union();
  void Union(PNF_Union  * u);

  

  PNF_Type_Enum type();
  void type(PNF_Type_Enum type);
  
  
  void print();
  void println();

  void read();

  long getType() const;
  void setType(long t);
};

class PNF_Object2
{
 protected:
  PNF_Basic_Object2 itsobject;
  PNF_Basic_Object2 * itspobject;
  PNF_Basic_Object2 * itsrobject;
  Array<PNF_Basic_Object2 *> itsaobject;

  PNF_Type_Enum itstype;


 public:
  PNF_Object2(const PNF_Variable & v);
  PNF_Object2(const PNF_RangeT1 & v);
  PNF_Object2(const PNF_RangeT2 & v);
  PNF_Object2(const PNF_Enum & v);
  
  PNF_Object2(PNF_Basic_Object2 * v, bool f = false);
  PNF_Object2(Array<PNF_Basic_Object2 *> v);
  PNF_Object2(int i = 0);
  
  ~PNF_Object2();
  
  PNF_Object2(const PNF_Object2 & o);
  
  
  const PNF_Object2 & get() const;
  void put(const PNF_Object2 & o);


  PNF_Basic_Object2 & object();
  void object(const PNF_Basic_Object2 & o);
  
  PNF_Basic_Object2 * pobject();
  void pobject(PNF_Basic_Object2 * o);
  
  PNF_Basic_Object2 * robject();
  void robject(PNF_Basic_Object2 * o);
  
  Array<PNF_Basic_Object2 *> aobject();
  void aobject(Array<PNF_Basic_Object2 *> o);
  
  void aput(unsigned long index, const PNF_Basic_Object2 & o);
  PNF_Basic_Object2 aget(unsigned long index);
  
  unsigned long alength();
  
  void ainsert();
  void aremove();
  
  
  PNF_Type_Enum type();
  void type(PNF_Type_Enum e);
  
  
  void print();
  void println();

  void read();

  long getType() const;
  void setType(long t);
  
  
  PNF_Object2 & operator=(const PNF_Object2 & o);
};


template <class T>
class PNF_Array : public Array<T>
{
 private:
  String itsname;


 public:
  PNF_Array(unsigned long s);
  ~PNF_Array();


  String name();
  void name(String name);
};

class Param
{
 protected:
  String itsname;
  PNF_Variable itsparam;
  PNF_Variable itsdefault;


 public:
  Param(int i = 0);

  Param(const Param & p);


  String name();
  void name(String n);

  PNF_Variable & param();
  void param(PNF_Variable v);

  PNF_Variable & defaultv();
  void defaultv(PNF_Variable v);

  void syncdefault();
};

class Function
{
 protected:
  Array<Param> itsret;
  String itsname;
  Array<Param> itsparam;
  unsigned long itsdef;

 public:
  Function(int i = 0);

  Function(const Function & f);


  ~Function();


 PNF_Variable ret(unsigned long i);
 PNF_Variable retdefaultv(unsigned long i);
 Array<Param> rets();
 String name();
 String rname();
 Array<Param> params();
 PNF_Variable & param(unsigned long i);
 String pname(unsigned long i);
 PNF_Variable & defaultv(unsigned long i);
 unsigned long definition();

 void ret(unsigned long i, PNF_Variable r);
 void retdefaultv(unsigned long i, PNF_Variable r);
 void name(String n);
 void rname(String n);
 void params(Array<Param> p);
 void param(unsigned long i, PNF_Variable v);
 void pname(unsigned long i, String n);
 void defaultv(unsigned long i, PNF_Variable v);
 void definition(unsigned long d);

 void syncdefaultr(unsigned long i);
 void syncdefaultp(unsigned long i);

 String & mangle();
 String & unmangle();
};

class Function_Stack
{
 protected:
  Array2<Function> itsstk;

 
 public:
  Function_Stack(int i = 0);

  Array2<Function> get();
  
  void set(Array2<Function> f);

  void add_function(Function f);
  void add_function2(Function f);
  Function & get_function(unsigned long i);
  Function & get_function(String n, bool & f);
  Function & get_function2(unsigned long i);
  Function & last_function();
  void mod_function(unsigned long i, Function f);
  void mod_function2(unsigned long i, Function f);
  void remove_function(unsigned long i);

  unsigned long length();

 unsigned long find(String name);
 unsigned long find(String name, Array<String> rets, Array<String> params);
 unsigned long find2(String name, Array<String> rets, Array<String> params);
 unsigned long find_duplicate(Function f, bool & b);
};

class PNF_Struct
{
 protected:
  Array<PNF_Object2> itsmembers;
  Array<String> itsmembernames;
  unsigned long itsuse;
  String itsname;
  String2 itstype;
  
  
 public:
  PNF_Struct(int i = 0);
  
  bool Use(unsigned long u);
  bool Use(String name);
  unsigned long Using();
  String UsingName();
  
  String name();
  void name(const String & n);
  
  String type();
  void type(const String & n);
  
  PNF_Object2 & get();
  void put(PNF_Object2 & p, String name = "");
  
  void add();
  unsigned long mlength();
  void remove();
};

class PNF_Union : public PNF_Struct
{  
 public:
  PNF_Union(int i = 0);


  void put(PNF_Object2 & p, String name = "");
};


class PNF_Interface;


class PNF_Class : public PNF_Struct
{
 protected:
  Array2<PNF_VIEW_CONTROL> itsaccess;
  bool itsinclass;
  Function_Stack itsmethods;
  Array2<PNF_VIEW_CONTROL> itsmethodsaccess;
  PNF_VIEW_CONTROL itsallmethodsaccess;
  Array<String> itssubclasses;
 

 public:
  PNF_Class(int i = 0);


  PNF_VIEW_CONTROL getaccess();
  void setaccess(PNF_VIEW_CONTROL access);

  PNF_VIEW_CONTROL getfuncaccess(unsigned long i);
  void setfuncaccess(unsigned long i, PNF_VIEW_CONTROL access);

  PNF_VIEW_CONTROL getmethodsaccess();
  void setmethodsaccess(PNF_VIEW_CONTROL access);


  bool getinclass();
  bool inclass();
  

  void add();

  PNF_Object2 & get();
  void put(PNF_Object2 & p, String name = "");

  Function_Stack & methods();
  void put(unsigned long i, Function & f);
  Function & get(unsigned long i);

  String subclass(unsigned long i);
  void subclass(unsigned long i, String thesubclass);
  unsigned long subclass_length();

  unsigned long find_subclass(String thesubclass);


 void extend(PNF_VIEW_CONTROL access, PNF_Class & theclass);
 void implement(PNF_VIEW_CONTROL access, PNF_Interface & theinterface);
};

class PNF_Interface : public PNF_Class
{
 public:
  void implement(PNF_VIEW_CONTROL access, PNF_Interface & theinterface);
};

template <class T>
class Array3
{
 private:
         T * data;
         unsigned long size;
         
         
 public:
        Array3(unsigned long s);
        
        Array3(const Array3 & r);
        
        ~Array3();
        
        
        T & get(unsigned long s);
        void put(T d, unsigned long s);
        unsigned long length() const;
        
        Array3<T> & operator=(const Array3<T> & rhs);
        T & operator[](unsigned long offSet);
        
        void insert();
        void remove();
        
        void insert(T d, unsigned long offset);
        void remove(unsigned long offset);
        void copy(unsigned long d1, unsigned long d2);
        void move(unsigned long d1, unsigned long d2);
};

template <class T>
class Array4
{
 private:
         T * data;
         unsigned long size;
         
         
 public:
        Array4(unsigned long s);
        
        Array4(const Array4 & r);
        
        ~Array4();
        
        
        T & get(unsigned long s);
        void put(T d, unsigned long s);
        unsigned long length() const;
        
        Array4<T> & operator=(const Array4<T> & rhs);
        T & operator[](unsigned long offSet);
        
        void insert();
        void remove();
        
        void insert(T d, unsigned long offset);
        void remove(unsigned long offset);
        void copy(unsigned long d1, unsigned long d2);
        void move(unsigned long d1, unsigned long d2);
};

class PNF_BasicFeeling
{
 protected:
  Array<unsigned long> itsfeelings;
  Array<unsigned long> itsintensitys; // Purposely misspelled for ease of use. May change later...
  String itstrigger;

  unsigned long itsindex;

 public:
  PNF_BasicFeeling();

  PNF_BASIC_FEELING get_feeling(PNF_BASIC_FEELING i);
  unsigned long get_intensity(PNF_BASIC_FEELING i);
  String get_trigger();
  PNF_BASIC_FEELING get_index();

  void set_feeling(PNF_BASIC_FEELING i, PNF_BASIC_FEELING f);
  void set_intensity(PNF_BASIC_FEELING i, unsigned long it);
  void set_trigger(String t);
  void set_index(PNF_BASIC_FEELING i);
};

class PNF_Instinct
{
 protected:
  PNF_BasicFeeling itsfeelings;
  Function_Stack itsactions;


 public:
  PNF_Instinct(int i = 0);


 PNF_BasicFeeling & feeling();
 Function_Stack & action();
};


#include "PNF_Types.cpp"


#endif // PNF_Types_hpp
