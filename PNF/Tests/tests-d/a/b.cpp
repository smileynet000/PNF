#include "pnf.hpp"


int main(int argc, char ** argv)
{
  PNF program(argc, argv);


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


  program.getmem().setmem(mem.getmem());
  program.loads2();
  program.check();
  int ret = program.execute();
  return ret;
}
