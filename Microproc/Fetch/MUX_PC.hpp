#include "macros.h"

#ifndef MUXPC
#define MUXPC

SC_MODULE(MuxPc){//0 -> PC     1 -> Other

  sc_in<sc_uint<PRECISION>> inData_0, inData_1;
  sc_out<sc_uint<PRECISION>> outData;

  sc_in<bool> select;
  sc_in<bool> clk;

  sc_uint<PRECISION> data;
  SC_CTOR(MuxPc){
    SC_METHOD(Exit); sensitive<<clk.neg();

    SC_METHOD(Enter); sensitive<<clk.pos();
  }
  ~MuxPc(){}

  void Enter(){//+
    if (select==0) {  data=inData_0;  }
    else if (select==1) { data=inData_1; }
  }

  void Exit(){//-
    outData = data;
  }


};


#endif//MUXPC
