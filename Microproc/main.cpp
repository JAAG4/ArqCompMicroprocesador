#include <systemc.h>

#include "MainTestbench.hpp"
#include "macros.h"

#include "Fetch.hpp"
#include "DecodingSelection.hpp"
#include "ArchivoRegistros.hpp"
#include "ual.hpp"
#include "Memoria.hpp"


#include "DataPipe.hpp"
#include "ArgPipe.hpp"
#include "OpcodePipe.hpp"
#include "InstructionPipe.hpp"
#include "Select2ALUPipe.hpp"
#include "WBPipe.hpp"

int sc_main(int argv, char* argc[]) {

  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  MainTestbench tb("tb");


  Fetch fet("fetch");
  Decoding dec("DS");
  ArchivoRegistros aR("ar");
  Ual ual("ual");
  Memoria mem("Memoria");

  InstrPipe pipeF2D("pF2D");//Instruction pipe from Fetch to Decode
  Ds2AluPipe pipeDs2Alu("pD2ALU");//Multi-pipe from DS to ALU 
  OpcodePipe pipeD2P_Op("pD2p_op");//delay pipe for the opcode

  DataPipe stall1("s1");
  DataPipe stall2("s2");
  WbPipe wbP("wbP");

  sc_signal< sc_uint<ISZ> > instr_sg_0,instr_sg_1;
  sc_signal< sc_uint<OPCODESIZE> > opcode_sig_0,opcode_sig_1;
  sc_signal< sc_uint<PRECISION> > pc_log_sg,data_sig_0,data_sig_1,data_sig_2,arg_sig_a_d,arg_sig_b_d,f_nAddr_sg,aR_W_d;
  sc_signal< sc_uint<ARGUMENTSZ> >  arg_sig_a,arg_sig_b,arg_sig_c,aR_W_add;
  sc_signal< bool > aR_enable_sg,f_enableNewPC_sg,memP_en_sg;


  sc_signal< sc_uint<OPCODESIZE> > opcd_alu_sg,opcd_sg_2Alu;
  sc_signal< sc_uint<PRECISION> > dat1_2alu_sg,dat2_2alu_sg,datR_alu_sg;


  sc_signal< sc_uint<PRECISION> > dataO_mem_sg,dataI_mem_sg,mem_dirIn_sg,a_c_sg_stl,ac_sg_stl2;
// ----==== Fetch ====----

  fet.instruction(instr_sg_0);
  pipeF2D.inData(instr_sg_0);
  tb.ins_fetch(instr_sg_0);
  fet.enableNewPC(f_enableNewPC_sg);
  fet.newAddr(f_nAddr_sg);

// ----==== Fetch to Decode ====----

  pipeF2D.outData(instr_sg_1);
  dec.fetchedInstruction(instr_sg_1);
  tb.ins_p1(instr_sg_1);
  fet.pc_log(pc_log_sg);

// ----==== Decode ====----

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

stall1.inData(arg_sig_c);
stall1.outData(a_c_sg_stl);
tb.st1i(arg_sig_c);
tb.st1o(a_c_sg_stl);

stall2.inData(a_c_sg_stl);
stall2.outData(ac_sg_stl2);
tb.st2i(a_c_sg_stl);
tb.st2o(ac_sg_stl2);
//SELECTION

aR.dOut1(arg_sig_a_d);
aR.dOut2(arg_sig_b_d);

tb.sel_r1(arg_sig_a_d);
tb.sel_r2(arg_sig_b_d);

aR.dirW(aR_W_add);
aR.data_in(aR_W_d);
aR.enable(aR_enable_sg);

tb.ar_dirW(aR_W_add);
tb.ar_data_in(aR_W_d);
tb.ar_enable(aR_enable_sg);


pipeD2P_Op.inData(opcode_sig_0);
pipeD2P_Op.outData(opcode_sig_1);

tb.pD2P_OpI(opcode_sig_0);
tb.pD2P_OpO(opcode_sig_1);


// ----==== Decode to ALU ====----
pipeDs2Alu.inData_Opcd(opcode_sig_1);
pipeDs2Alu.outData_Opcd(opcd_sg_2Alu);
ual.op_id(opcd_sg_2Alu);

tb.opcd_2Alu(opcd_sg_2Alu);

pipeDs2Alu.inData_A1(arg_sig_a_d);
pipeDs2Alu.outData_A1(dat1_2alu_sg);

tb.arg_a_d(arg_sig_a_d);
tb.arg_b_d(arg_sig_b_d);


pipeDs2Alu.inData_A2(arg_sig_b_d);
pipeDs2Alu.outData_A2(dat2_2alu_sg);

ual.firstOperator(dat1_2alu_sg);
ual.secondOperator(dat2_2alu_sg);
ual.result(datR_alu_sg);

tb.dat1_2alu(dat1_2alu_sg);
tb.dat2_2alu(dat2_2alu_sg);
tb.dRes_alu(datR_alu_sg);


pipeDs2Alu.outDir_A1(mem_dirIn_sg);
pipeDs2Alu.outDir_A2(p2p_diA2);
pipeDs2Alu.mem_en(memP_en_sg);

mem.dirIn(mem_dirIn_sg);
tb.dirIn_mem(mem_dirIn_sg);

mem.dataIn(dat2_2alu_sg);
tb.dataIn_mem(dat2_2alu_sg);

mem.dataOut(dataO_mem_sg);
tb.dataOut_m(dataO_mem_sg);

wbP.inmemDat(dataO_mem_sg);
wbP.inRS(datR_alu_sg);

wbP.WbData(aR_W_d);
wbP.clk(clock);

mem.enable(memP_en_sg);
tb.en_m(memP_en_sg);



// ----==== Clocks ====----

  tb.clk(clock);

  fet.clk(clock);
  dec.clk(clock);
  aR.clk(clock);
  mem.clk(clock);


  pipeF2D.clk(clock);
  pipeD2P_Op.clk(clock);
  pipeDs2Alu.clk(clock);



  sc_start();
  return 0;
}
