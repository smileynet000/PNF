#include "../pnf.hpp"


int main(int argc, char ** argv)
{
  PNF program(argc, argv);


  Memory mem;
  mem.put(0, 0);
  mem.put(1, 0);
  mem.put(2, 0);
  mem.put(3, 6);
  mem.put(4, 3);
  mem.put(5, 97);
  mem.put(6, 3);
  mem.put(7, 0);
  mem.put(8, 0);
  mem.put(9, 60);
  mem.put(10, 0);
  mem.put(11, 0);


  program.getmem().setmem(mem.getmem());
  int ret = program.execute();
  return ret;
}
