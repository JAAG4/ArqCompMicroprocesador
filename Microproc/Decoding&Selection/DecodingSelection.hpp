#include <systemc.h>
#include "macros.h"
#ifndef SELECTION
#define SELECTION

SC_MODULE(Decoding){
  sc_in<sc_uint<ISZ>> fetchedInstruction;
  sc_out< sc_uint<OPCODESIZE> > opcode;
  sc_out< sc_uint<ARGUMENTSZ> > arg1,arg2,arg3;
  sc_in<bool>clk;

  void decode(){   if(false){return;}
    int begg,opcodeEnd,arg1End,arg2End,arg3End,arg1beg
,arg2beg,arg3beg = 0;

begg = 0;
opcodeEnd = OPCODESIZE-1;
arg1beg = opcodeEnd+1;
arg1End = arg1beg+ARGUMENTSZ-1;
arg2beg = arg1End+1;
arg2End = arg2beg-1+ARGUMENTSZ;
arg3beg = arg2End+1;
arg3End = arg3beg-1+ARGUMENTSZ;


    opcode = fetchedInstruction.read().range(opcodeEnd,begg);
    arg1 = fetchedInstruction.read().range(arg1End,arg1beg);
    arg2 = fetchedInstruction.read().range(arg2End,arg2beg);
    arg3 = fetchedInstruction.read().range(arg3End,arg3beg);
  }

    SC_CTOR(Decoding){
        SC_METHOD(decode);
        sensitive << clk << fetchedInstruction;
    }

    ~Decoding(){}
};

#endif//SELECTION
