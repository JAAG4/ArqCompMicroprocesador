#include <systemc.h>
#include "Fetch.hpp"
#include "DecodingSelection.hpp"
#include "ual.hpp"

#include "DataPipe.hpp"
#include "ArgPipe.hpp"
#include "OpcodePipe.hpp"
#include "InstructionPipe.hpp"


int sc_main(int argv, char* argc[]) {

  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  Fetch fet("fetch");
  Selection dec("D&S");
  Ual ual("alu");

  InstrPipe pipeF2D("pF2D");//Instruction pipe from Fetch to Decode
  OpcodePipe pipeD2U_O("p0D2U");//Opcode pipe from Decode to ALU
  DataPipe pipeD2U_D1("pDD2U"),pipeD2U_D2("pDD2U");//Data Pipe from Selection to ALU
  ArgPipe pipeD2U_A1("pAD2U"),pipeD2U_A2("pAD2U");

  sc_signal<sc_uint<ISZ>> instr_sg_0,instr_sg_1;
  sc_signal<sc_uint<OPCODESIZE>> opcode_sig_0,opcode_sig_1;
  sc_signal<sc_uint<PRECISION>> data_sig_0,data_sig_1,data_sig_2;
  sc_signal<sc_uint<ARGUMENTSZ>> arg_sig_a,arg_sig_a_1,arg_sig_b;

// ----==== Fetch ====----

  fet.instruction(instr_sg_0);
  pipeF2D.inData(instr_sg_0);

// ----==== Fetch to Decode ====----

  pipeF2D.outData(instr_sg_1);
  dec.fetchedInstruction(instr_sg_1);

// ----==== Decode ====----

dec.fetchedInstruction(instr_sg_1);
dec.opcode(opcode_sig_0);


// ----==== Decode to ALU ====----


// ----==== Clocks ====----

  fet.clk(clock);
  dec.clk(clock);
  //ual.clk(clock);

  pipeF2D.clk(clock);
  pipeF2D.clk(clock);
  pipeD2U_O.clk(clock);
  pipeD2U_D1.clk(clock);
  pipeD2U_D2.clk(clock);
  pipeD2U_A1.clk(clock);
  pipeD2U_A2.clk(clock);



  sc_start();
  return 0;
}
