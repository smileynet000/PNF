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