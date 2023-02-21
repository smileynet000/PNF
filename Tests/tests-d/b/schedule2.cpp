#include "pnf.hpp"


int main(int argc, char ** argv)
{
  PNF program(argc, argv);


  Memory mem;
  mem.put(0, 0);
  mem.put(1, 0);
  mem.put(2, 0);
  mem.put(3, 117);
  mem.put(4, 4);
  mem.put(5, 115);
  mem.put(6, 99);
  mem.put(7, 104);
  mem.put(8, 101);
  mem.put(9, 100);
  mem.put(10, 117);
  mem.put(11, 108);
  mem.put(12, 101);
  mem.put(13, 46);
  mem.put(14, 116);
  mem.put(15, 120);
  mem.put(16, 116);
  mem.put(17, 0);
  mem.put(18, 47);
  mem.put(19, 4);
  mem.put(20, 119);
  mem.put(21, 111);
  mem.put(22, 114);
  mem.put(23, 107);
  mem.put(24, 101);
  mem.put(25, 100);
  mem.put(26, 0);
  mem.put(27, 46);
  mem.put(28, 4);
  mem.put(29, 110);
  mem.put(30, 111);
  mem.put(31, 116);
  mem.put(32, 95);
  mem.put(33, 119);
  mem.put(34, 111);
  mem.put(35, 114);
  mem.put(36, 107);
  mem.put(37, 101);
  mem.put(38, 100);
  mem.put(39, 0);
  mem.put(40, 58);
  mem.put(41, 4);
  mem.put(42, 119);
  mem.put(43, 111);
  mem.put(44, 114);
  mem.put(45, 107);
  mem.put(46, 101);
  mem.put(47, 100);
  mem.put(48, 0);
  mem.put(49, 58);
  mem.put(50, 4);
  mem.put(51, 97);
  mem.put(52, 0);
  mem.put(53, 119);
  mem.put(54, 4);
  mem.put(55, 0);
  mem.put(56, 96);
  mem.put(57, 0);
  mem.put(58, 0);
  mem.put(59, 125);
  mem.put(60, 0);
  mem.put(61, 0);
  mem.put(62, 47);
  mem.put(63, 4);
  mem.put(64, 99);
  mem.put(65, 0);
  mem.put(66, 46);
  mem.put(67, 4);
  mem.put(68, 98);
  mem.put(69, 0);
  mem.put(70, 58);
  mem.put(71, 4);
  mem.put(72, 98);
  mem.put(73, 0);
  mem.put(74, 97);
  mem.put(75, 0);
  mem.put(76, 0);
  mem.put(77, 6);
  mem.put(78, 0);
  mem.put(79, 0);
  mem.put(80, 46);
  mem.put(81, 4);
  mem.put(82, 97);
  mem.put(83, 0);
  mem.put(84, 58);
  mem.put(85, 4);
  mem.put(86, 99);
  mem.put(87, 0);
  mem.put(88, 122);
  mem.put(89, 0);
  mem.put(90, 0);
  mem.put(91, 46);
  mem.put(92, 4);
  mem.put(93, 100);
  mem.put(94, 111);
  mem.put(95, 110);
  mem.put(96, 101);
  mem.put(97, 0);
  mem.put(98, 58);
  mem.put(99, 4);
  mem.put(100, 110);
  mem.put(101, 111);
  mem.put(102, 116);
  mem.put(103, 95);
  mem.put(104, 119);
  mem.put(105, 111);
  mem.put(106, 114);
  mem.put(107, 107);
  mem.put(108, 101);
  mem.put(109, 100);
  mem.put(110, 0);
  mem.put(111, 6);
  mem.put(112, 4);
  mem.put(113, 102);
  mem.put(114, 105);
  mem.put(115, 108);
  mem.put(116, 101);
  mem.put(117, 32);
  mem.put(118, 110);
  mem.put(119, 111);
  mem.put(120, 116);
  mem.put(121, 32);
  mem.put(122, 102);
  mem.put(123, 111);
  mem.put(124, 117);
  mem.put(125, 110);
  mem.put(126, 100);
  mem.put(127, 46);
  mem.put(128, 0);
  mem.put(129, 46);
  mem.put(130, 4);
  mem.put(131, 100);
  mem.put(132, 111);
  mem.put(133, 110);
  mem.put(134, 101);
  mem.put(135, 0);
  mem.put(136, 58);
  mem.put(137, 4);
  mem.put(138, 100);
  mem.put(139, 111);
  mem.put(140, 110);
  mem.put(141, 101);
  mem.put(142, 0);
  mem.put(143, 3);
  mem.put(144, 0);
  mem.put(145, 0);
  mem.put(146, 61);
  mem.put(147, 0);
  mem.put(148, 0);


  program.getmem().setmem(mem.getmem());
  program.loads3();
  program.loads2();
  program.check();
  int ret = program.execute();
  return ret;
}
