#include <fstream>
#include <string>
#include <iostream>
#include "macros.h"

/*
Al hacer un salto, se "escapa" una Instrucción (en vez de ser instantaneo,al recibir el dato)
*/

using namespace std;

#ifndef FETCH
#define FETCH


SC_MODULE (Fetch) {
  ifstream instrMem;

  sc_in<bool> clk;

  sc_out< sc_uint<ISZ> > instruction;
  sc_in< sc_uint<PRECISION> > newAddr;
  sc_in<bool>enableNewPC;
  sc_out< sc_uint<PRECISION> >pc_log;

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
    if( clk.read()==0 ) {  cout<<"???";return;  }
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
    //cout<<"fetch:"<<pc<<"||"<<newAddr.read()<<"|"<<enableNewPC<<endl;

    instrMem.seekg(pci,ios::beg);

    if (instrMem.eof()) {cout<<"READING ERROR"<<endl;
    instruction=0;
      return;
    }

    instrMem.read(temp,ISZ);

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
