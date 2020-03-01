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
  sc_in< sc_uint<PRECISION> > pc;

  SC_CTOR (Fetch) {
    instrMem.open(instrMem_filename,ios::binary);

    SC_METHOD(fetch);
    sensitive<<clk.neg();
  }

  void fetch() {
    char temp[ISZ];
    sc_uint<ISZ> tempi;
    int pci = (pc.read().to_int() * (ISZ)) ;
    cout<<"byte<"<<pci<<">";

    instrMem.seekg(pci,ios::beg);

    if (instrMem.eof()) {cout<<"READING ERROR"<<endl;
    instruction=0;
      return;
    }

    instrMem.read(temp,ISZ);
    std::cout << "temp"<<temp<< '\n';
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
