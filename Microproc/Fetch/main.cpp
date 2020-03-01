#include <systemc.h>
#include <string>

#include "Fetch.hpp"
#include "Testbench.h"
#include "InstructionPipe.hpp"
#include "PlusOne.hpp"
#include "MUX_PC.hpp"
#include "DataPipe.hpp"
int sc_main(int argv, char* argc[]) {
  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  Fetch ft("fetch");
  Testbench tb("testbench");
  PlusOne po("PlusOne");
  MuxPc mPC("MPC");
  DataPipe pc("PC");


  sc_signal< sc_uint<ISZ> > instruction_sg;
  sc_signal<sc_uint<PRECISION>> pc2po_sg, po2mux_sg, wb2mux_sg, mux2pc_sg, pc2ft_sg,pcOut_sg;
  sc_signal<bool>select_sg;


  pc.outData(pcOut_sg);
  po.inData(pcOut_sg);
  ft.pc(pcOut_sg);

  po.outData(po2mux_sg);
  mPC.inData_0(po2mux_sg);

  tb.wbData(wb2mux_sg);
  mPC.inData_1(wb2mux_sg);

  mPC.outData(mux2pc_sg);
  pc.inData(mux2pc_sg);


  tb.instruction(instruction_sg);
  ft.instruction(instruction_sg);

  tb.pc(pc2ft_sg);

  tb.select(select_sg);
  mPC.select(select_sg);

  ft.clk(clock);
  tb.clk(clock);
  mPC.clk(clock);
  po.clk(clock);
  pc.clk(clock);
  sc_start();
  return 0;
}
