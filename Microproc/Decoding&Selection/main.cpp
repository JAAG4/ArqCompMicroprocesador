#include <systemc.h>
#include <string>

#include "Testbench.hpp"
#include "DecodingSelection.hpp"

int sc_main(int argv, char* argc[]) {
  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  Selection dec("dec");
  Testbench tb("tb");

  sc_signal<sc_uint<ISZ>> fetchedInstruction_sg;
  sc_signal< sc_uint<OPCODESIZE> > opcode_sg;
  sc_signal< sc_uint<ARGUMENTSZ> > arg1_sg,arg2_sg;

  tb.arg1(arg1_sg);
  dec.arg1(arg1_sg);

  tb.arg2(arg2_sg);
  dec.arg2(arg2_sg);

  tb.opcode(opcode_sg);
  dec.opcode(opcode_sg);

  tb.fetchedInstruction(fetchedInstruction_sg);
  dec.fetchedInstruction(fetchedInstruction_sg);

  tb.clk(clock);
  dec.clk(clock);
  //std::cout << "CONNECTEDCLOCK" << '\n';
  sc_start();



  return 0;
}
