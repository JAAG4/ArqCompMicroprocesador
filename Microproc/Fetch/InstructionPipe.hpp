#include "macros.h"

using namespace std;

#ifndef INSTRPIPE
#define INSTRPIPE

SC_MODULE(InstrPipe){

sc_in<bool> clk;

sc_in< sc_uint<INSTRUCTION_SIZE> > inData;
sc_uint< INSTRUCTION_SIZE > data;
sc_out< sc_uint<INSTRUCTION_SIZE> > outData;

void read(){//clk-
  if (!clk) {
    outData = data;
  }
  return;
}


void write(){//clk+
  if (clk) {
    data = inData;
  }
}


SC_CTOR(InstrPipe){
  SC_METHOD(read); sensitive<<clk.neg();

  SC_METHOD(write); sensitive<<clk.pos();
}


~InstrPipe(){

}
};

#endif//INSTRPIPE
