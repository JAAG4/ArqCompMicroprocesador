#include "macros.h"

#ifndef PLUSONE
#define PLUSONE

using namespace std;

SC_MODULE(PlusOne){
  sc_in<bool> clk;

  sc_in< sc_uint<PRECISION> > inData;
  sc_uint< PRECISION > data;
  sc_out< sc_uint<PRECISION> > outData;

  void Exit(){//clk-
    if (!clk) {
      outData = (data + 1);
    }
    return;
  }

  void Enter(){//clk+
    if (clk) {
      data = inData;
    }
  }

  SC_CTOR(PlusOne){
    SC_METHOD(Exit); sensitive<<clk.neg();

    SC_METHOD(Enter); sensitive<<clk.pos();
  }


  ~PlusOne(){}
};

#endif//PLUSONE
