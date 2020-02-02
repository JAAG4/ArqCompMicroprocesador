#include <systemc.h>
#include "Testbench.hpp"
#include "ual.hpp"


int sc_main(int argv, char* argc[]) {

  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  Testbench tb("tb");
  Ual ual("ual");

  sc_signal< sc_uint<PRECISION> > result_sig, firstOp_sig, SecondOp_sig;
  sc_signal< sc_uint<4> > op_id_sig;

  tb.op_id(op_id_sig);
  ual.op_id(op_id_sig);

  tb.firstOperator(firstOp_sig);
  ual.firstOperator(firstOp_sig);

  tb.secondOperator(SecondOp_sig);
  ual.secondOperator(SecondOp_sig);

  tb.result(result_sig);
  ual.result(result_sig);


  tb.clk(clock);

  sc_start();
  return 0;
}
