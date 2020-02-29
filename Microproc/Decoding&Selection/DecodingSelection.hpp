#include <systemc.h>
#include "macros.h"
#ifndef SELECTION
#define SELECTION

SC_MODULE(Selection){
  sc_in<sc_uint<ISZ>> fetchedInstruction;
  sc_out< sc_uint<OPCODESIZE> > opcode;
  sc_out< sc_uint<> > arg1,arg2;
  sc_in<bool>clk;

  void decode(){   if(false){return;}
    int begg,opcodeEnd,arg1End,arg2End,arg1beg
,arg2beg = 0;
    //begg = ISZ-1;
    //opcodeEnd = ISZ-OPCODESIZE;
    //arg1beg=opcodeEnd-1;
    //arg1End=opcodeEnd-ARGUMENTSZ;
    //arg2beg=arg1End-1;
    //arg2End=0;
begg = 0;
opcodeEnd = OPCODESIZE-1;
arg1beg= opcodeEnd+1;
arg1End= arg1beg+ARGUMENTSZ-1;
arg2beg= arg1End+1;
arg2End= arg2beg-1+ARGUMENTSZ;

//std::cout<< begg<<";"<< opcodeEnd<<";"<< arg1beg<<";"<< arg1End<<";"<< arg2beg<<";"<< arg2End<<";"<< '\n';

    opcode = fetchedInstruction.read().range(opcodeEnd,begg);
    arg1 = fetchedInstruction.read().range(arg1End,arg1beg);
    arg2 = fetchedInstruction.read().range(arg2End,arg2beg);
  }

    SC_CTOR(Selection){
        SC_METHOD(decode);
        sensitive << clk << fetchedInstruction;
    }

    ~Selection(){}
};

#endif//SELECTION
