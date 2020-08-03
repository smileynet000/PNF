#include "pnf.hpp"


int main(int argc, char ** argv)
{
  Array<String> args;

  args[0] = "(COMPILED)";
  for (unsigned long i = 0, j = 1; i < argc; ++i, ++j)
  {
   args.insert();

   args[j] = argv[i];
  }

  char ** args2 = new char * [args.length()];
  unsigned long args2l = args.length();
  for (unsigned long i = 0; i < args2l; ++i)
  {
   args2[i] = (char *)args[i].getString().c_str();
  }

  PNF program(args2l, args2);


  Memory mem;
  mem.put(0, 0);
  mem.put(1, 0);
  mem.put(2, 0);
  mem.put(3, 6);
  mem.put(4, 4);
  mem.put(5, 72);
  mem.put(6, 101);
  mem.put(7, 108);
  mem.put(8, 108);
  mem.put(9, 111);
  mem.put(10, 32);
  mem.put(11, 87);
  mem.put(12, 111);
  mem.put(13, 114);
  mem.put(14, 108);
  mem.put(15, 100);
  mem.put(16, 33);
  mem.put(17, 0);
  mem.put(18, 3);
  mem.put(19, 0);
  mem.put(20, 0);
  mem.put(21, 61);
  mem.put(22, 0);
  mem.put(23, 0);


  program.getmem().setmem(mem.getmem());
  program.loads3();
  program.loads2();
  program.check();
  int ret = program.execute();
  return ret;
}
