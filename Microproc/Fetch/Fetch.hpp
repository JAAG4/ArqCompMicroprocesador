#include <fstream>
#include <string>
#include <iostream>
#include "macros.h"

using namespace std;

#ifndef FETCH
#define FETCH

#define instrMem_filename "in.txt"

SC_MODULE (Fetch) {
  ifstream instrMem;

  sc_in<bool> clk;

  sc_out< sc_uint<ISZ> > instruction;
  sc_in< sc_uint<PRECISION> > pc;

  SC_CTOR (Fetch) {
    instrMem.open(instrMem_filename);

    SC_METHOD(fetch);
    sensitive<<clk.neg();
  }

  void fetch() {
    string temp;
    sc_uint<ISZ> tempi;
    int pci = pc.read().to_int() * (ISZ+2);
    cout<<"pc<"<<pci<<">";

    instrMem.seekg(pci);
    getline(instrMem,temp);

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
