#include "macros.h"

#ifndef DATAPIPE
#define DATAPIPE

using namespace std;

class DataPipe:public sc_module{
  public:
    sc_in<bool> clk;

    sc_in< sc_uint<PRECISION> > inData;
    sc_out< sc_uint<PRECISION> > outData;
    sc_uint< PRECISION > data;

    SC_CTOR(DataPipe){
      //data.write(0);
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





~DataPipe(){

}
};

#endif//DATAPIPE
