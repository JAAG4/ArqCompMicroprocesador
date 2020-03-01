#ifndef PROGCOUNT
#define PROGCOUNT

#include"macros.h"

//using namespace std;

SC_MODULE(ProgramCounter){

  sc_in<bool>clk;

  sc_out<sc_uint<PRECISION>>nextAddr;
  sc_in<sc_uint<PRECISION>>inAddr;
  sc_in<bool> enable;
  sc_uint<PRECISION>currAddr;

  void change_addr(){//-
  if (enable) {
    currAddr=inAddr;
  }
  else {
    currAddr+=1;
  }

  }

  void exit(){//+
    nextAddr = currAddr;
  }

  SC_CTOR(ProgramCounter){
    currAddr=0;
    SC_METHOD(change_addr);
    sensitive<<clk.neg();
    SC_METHOD(exit);
    sensitive<<clk.pos();
  }

  ~ProgramCounter(){}
};

#endif//PROGCOUNT
