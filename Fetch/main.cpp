#include <systemc.h>
#include <string>

#include "Fetch.h"
#include "Testbench.h"
#include "Register.hpp"

int sc_main(int argv, char* argc[]) {
  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  Fetch ft("fetch");
  Testbench tb("tb");

  Register pipe1("p1");
  Register pipe2("p2");

  sc_signal< sc_uint<14> > instruction_sg , pipe12_sg , pipe23_sg;
  sc_signal<bool> connection_sg;


  ft.instruction(instruction_sg);
  ft.clk(clock);
	ft.connection(connection_sg);

  tb.instruction(instruction_sg);
  tb.clk(clock);
  tb.connection(connection_sg);

  tb.p1(pipe12_sg);
  tb.p2(pipe23_sg);

  pipe1.inData(instruction_sg);
  pipe1.outData(pipe12_sg);
  pipe1.clk(clock);

  pipe2.inData(pipe12_sg);
  pipe2.outData(pipe23_sg);
  pipe2.clk(clock);

  sc_start();
  return 0;
}
