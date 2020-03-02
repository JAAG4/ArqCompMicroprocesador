#include <fstream>
#include <string>
#include <iostream>
#include "macros.h"

using namespace std;

#ifndef FETCH
#define FETCH

#define instrMem_filename "in.bin"

SC_MODULE (Fetch) {
  ifstream instrMem;

  sc_in<bool> clk;

  sc_out< sc_uint<ISZ> > instruction;
  sc_in< sc_uint<PRECISION> > newAddr;
  sc_in<bool>enableNewPC;
  sc_out<sc_uint<PRECISION>>pc_log;

  sc_uint<PRECISION> pc;
  SC_CTOR (Fetch) {
    pc=0;
    instrMem.open(instrMem_filename,ios::binary);
    SC_METHOD(update_pc);
    sensitive<<clk.pos();
    SC_METHOD(fetch);
    sensitive<<clk.neg();
  }

  void update_pc(){//+
    if( clk.read()==0 ) {  cout<<clk<<"???";return;  }
    if(enableNewPC){
      pc = newAddr.read();
    }
    else{
      pc += 1;
    }
  }

  void fetch() {// -
    pc_log.write(pc);
    char temp[ISZ];
    sc_uint<ISZ> tempi;
    int pci = (pc * (ISZ)) ;
    //cout<<"byte<"<<pci<<">";

    instrMem.seekg(pci,ios::beg);

    if (instrMem.eof()) {cout<<"READING ERROR"<<endl;
    instruction=0;
      return;
    }

    instrMem.read(temp,ISZ);
    //std::cout << "temp"<<temp<< '\n';
    for (int i = 0; i < ISZ; i++) {
    tempi[ISZ-i-1] = temp[i] - '0';

    instruction = tempi;

    }
  }


  ~Fetch() {
    instrMem.close();
  }
};

#endif//FETCH
