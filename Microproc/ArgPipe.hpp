#include "macros.h"

using namespace std;

#ifndef ARGPIPE
#define ARGPIPE

class ArgPipe:public sc_module{
  public:
    sc_in<bool> clk;

    sc_in< sc_uint<ARGUMENTSZ> > inData;
    sc_uint< ARGUMENTSZ > data;
    sc_out< sc_uint<ARGUMENTSZ> > outData;

    SC_CTOR(ArgPipe){
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





~ArgPipe(){

}
};

#endif//ARGPIPE
