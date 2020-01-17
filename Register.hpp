#include "macros.h"

using namespace std;

#ifndef REGISTER
#define REGISTER

SC_MODULE(Register){

sc_in<bool> clk;

sc_in< sc_uint<INSTRUCTION_SIZE> > inData;
sc_uint< INSTRUCTION_SIZE > data;
sc_out< sc_uint<INSTRUCTION_SIZE> > outData;

void read(){//clk+
  if (clk) {
    outData = data;
  }
  return;
}


void write(){//clk-
  if (!clk) {
    data = inData;
  }
}


SC_CTOR(Register){
  SC_METHOD(read); sensitive<<clk.pos();

  SC_METHOD(write); sensitive<<clk.neg();
}


~Register(){

}
};

#endif//REGISTER
