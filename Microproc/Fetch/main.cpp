#include <systemc.h>
#include <string>

#include "Fetch.hpp"
#include "Testbench.h"
#include "InstructionPipe.hpp"
#include "PlusOne.hpp"
#include "MUX_PC.hpp"
#include "DataPipe.hpp"
#include "ProgramCounter.hpp"


int sc_main(int argv, char* argc[]) {
  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  Fetch ft("fetch");
  Testbench tb("testbench");
  ProgramCounter pc("pc");

  sc_signal< sc_uint<ISZ> > instruction_sg;
  sc_signal<sc_uint<PRECISION>> pcAddr_sg, wbDir_sg;
  sc_signal<bool> enable_sg;

  pc.nextAddr(pcAddr_sg);
  ft.pc(pcAddr_sg);
  tb.pc(pcAddr_sg);

  pc.inAddr(wbDir_sg);
  tb.wbDir(wbDir_sg);

  pc.enable(enable_sg);
  tb.enable(enable_sg);


  tb.instruction(instruction_sg);
  ft.instruction(instruction_sg);


  ft.clk(clock);
  tb.clk(clock);
  pc.clk(clock);
  sc_start();
  return 0;
}
