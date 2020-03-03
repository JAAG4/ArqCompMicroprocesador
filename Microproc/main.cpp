#include <systemc.h>

#include "MainTestbench.hpp"
#include "macros.h"

#include "Fetch.hpp"
#include "DecodingSelection.hpp"
#include "ual.hpp"
#include "cache.h"

#include "DataPipe.hpp"
#include "ArgPipe.hpp"
#include "OpcodePipe.hpp"
#include "InstructionPipe.hpp"

int sc_main(int argv, char* argc[]) {

  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  MainTestbench tb("tb");


  Fetch fet("fetch");
  Decoding dec("DS");

  Cache aR("ar");

  InstrPipe pipeF2D("pF2D");//Instruction pipe from Fetch to Decode



  sc_signal<sc_uint<ISZ>> instr_sg_0,instr_sg_1;
  sc_signal<sc_uint<OPCODESIZE>> opcode_sig_0,opcode_sig_1;
  sc_signal<sc_uint<PRECISION>> data_sig_0,data_sig_1,data_sig_2,arg_sig_a_d,arg_sig_b_d,aR_W_d;
  sc_signal<sc_uint<ARGUMENTSZ>> arg_sig_a,arg_sig_b,arg_sig_c,aR_W_add;

// ----==== Fetch ====----

  fet.instruction(instr_sg_0);
  pipeF2D.inData(instr_sg_0);
  tb.ins_fetch(instr_sg_0);

// ----==== Fetch to Decode ====----

  pipeF2D.outData(instr_sg_1);
  dec.fetchedInstruction(instr_sg_1);
  tb.ins_p1(instr_sg_1);

// ----==== Decode ====----

dec.fetchedInstruction(instr_sg_1);
dec.opcode(opcode_sig_0);
tb.opcd_dec(opcode_sig_0);

dec.arg1(arg_sig_a);
aR.dirR1(arg_sig_a);
tb.a1_dec(arg_sig_a);

dec.arg2(arg_sig_b);
aR.dirR2(arg_sig_b);
tb.a2_dec(arg_sig_b);

dec.arg3(arg_sig_c);
tb.a3_dec(arg_sig_c);
//SELECTION

aR.dOut1(arg_sig_a_d);
aR.dOut2(arg_sig_b_d);

tb.sel_r1(arg_sig_a_d);
tb.sel_r2(arg_sig_b_d);

aR.dirW(aR_W_add);
aR.data_in(aR_W_d);

// ----==== Decode to ALU ====----


// ----==== Clocks ====----

  fet.clk(clock);
  dec.clk(clock);
  aR.clk(clock);

  pipeF2D.clk(clock);





  sc_start();
  return 0;
}
