#include "macros.h"

using namespace std;

#ifndef OPCODEPIPE
#define OPCODEPIPE

class OpcodePipe:public sc_module{
  public:
    sc_in<bool> clk;

    sc_in< sc_uint<OPCODESIZE> > inData;
    sc_uint< OPCODESIZE > data;
    sc_out< sc_uint<OPCODESIZE> > outData;

    SC_CTOR(OpcodePipe){
      //data=0;
      //inData=0;
      //outData=0;

      SC_METHOD(read); sensitive<<clk.neg();

      SC_METHOD(write); sensitive<<clk.pos();
    }

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





~OpcodePipe(){

}
};

#endif//OPCODEPIPE
