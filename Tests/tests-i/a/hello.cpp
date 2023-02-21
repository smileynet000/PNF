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
  mem.put(3, 55);
  mem.put(4, 4);
  mem.put(5, 104);
  mem.put(6, 101);
  mem.put(7, 108);
  mem.put(8, 108);
  mem.put(9, 111);
  mem.put(10, 95);
  mem.put(11, 119);
  mem.put(12, 111);
  mem.put(13, 114);
  mem.put(14, 108);
  mem.put(15, 100);
  mem.put(16, 0);
  mem.put(17, 3);
  mem.put(18, 0);
  mem.put(19, 0);
  mem.put(20, 58);
  mem.put(21, 4);
  mem.put(22, 104);
  mem.put(23, 101);
  mem.put(24, 108);
  mem.put(25, 108);
  mem.put(26, 111);
  mem.put(27, 95);
  mem.put(28, 119);
  mem.put(29, 111);
  mem.put(30, 114);
  mem.put(31, 108);
  mem.put(32, 100);
  mem.put(33, 0);
  mem.put(34, 6);
  mem.put(35, 4);
  mem.put(36, 72);
  mem.put(37, 101);
  mem.put(38, 108);
  mem.put(39, 108);
  mem.put(40, 111);
  mem.put(41, 32);
  mem.put(42, 87);
  mem.put(43, 111);
  mem.put(44, 114);
  mem.put(45, 108);
  mem.put(46, 100);
  mem.put(47, 33);
  mem.put(48, 0);
  mem.put(49, 56);
  mem.put(50, 0);
  mem.put(51, 0);
  mem.put(52, 61);
  mem.put(53, 0);
  mem.put(54, 0);


  program.getmem().setmem(mem.getmem());
  program.loads3();
  program.loads2();
  program.check();
  int ret = program.execute();
  return ret;
}
