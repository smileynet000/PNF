/*
    Copyright 2023 Dennis Earl Smiley

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

 2/7/23 Origional a 	- The first version.
*/
#include <desLib/deslib.hpp>


class ASTNode
{
 protected:
  ASTNode * itsleft;
  ASTNode * itsBackLeft;
  ASTNode * itsright;
  ASTNode * itsBackRight;

  String itstype;
  PNF_Variable itsvalue;


 public:
  ASTNode(int n = 0);


  ~ASTNode();

  
  String type();
  void type(String t);

  PNF_Variable value();
  void value(PNF_Variable v);

  ASTNode * left();
  ASTNode * right();
  void left(ASTNode * a);
  void right(ASTNode * a);

  ASTNode * itsBackLeft();
  ASTNode * itsBackRight():
};


ASTNode::ASTNode(int n = 0)
{
 itsType = "";
 PNF_Void v;
 itsvalue.put(v);
 itsleft = NULL;
 itsBAckLeft = NULL;
 itsright = NULL;
 itsBackRight = NULL;
}


ASTNode::~ASTNode()
{

}
 
String ASTNode::type()
{
 return itsType;
}

void ASTNode::type(String t)
{
 itsType = t;
}

PNF_Variable ASTNode::value()
{
 return itsValue;
}

void ASTNode::value(PNF_Variable v)
{
 itsValue = v;
}

ASTNode * ASTNode::left()
{
 return itsLeft;
}

ASTNode * ASTNode::right()
{
 return itsRight;
}

void ASTNode::left(ASTNode * a)
{
 itsLeft = a;
 left()-itsBackLeft = &this;
}

void ASTNode::right(ASTNode * a)
{
 itsRight = a;
  right()-itsBackRight = &this;
}

ASTNode * ASTNode::itsBackLeft()
{
 return itsBackLeft;
}

ASTNode * ASTNode::itsBackRight()
{
 return itsBAckRight;
}
