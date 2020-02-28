#include <systemc.h>
#include <string>

#include "Testbench.hpp"
#include "Decoder4-16.hpp"

int sc_main(int argv, char* argc[]) {
  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  Decoder4_16 dec("dec");
  Testbench tb("tb");

  std::array< sc_signal<bool>,16 >sigOut;
  std::array< sc_signal<bool>,4 >sigIn;


  for(int j=0;j<4;j++){
    dec.in[j](sigIn[j]);
    tb.in[j](sigIn[j]);
    //std::cout << "connected in " <<j<< '\n';
  }

  for(int j=0;j<16;j++){
    dec.outs[j](sigOut[j]);
    tb.outs[j](sigOut[j]);
    //std::cout << "connected out " <<j<< '\n';
  }


  tb.clk(clock);
  std::cout << "CONNECTEDCLOCK" << '\n';
  sc_start();



  return 0;
}
