#ifndef TESTBENCH
#define TESTBENCH
#include "macros.h"
#include "tools.hpp"
SC_MODULE(MainTestbench){
  sc_in<bool> clk;

  sc_in<sc_uint<ISZ>> ins_fetch,ins_p1;
  sc_in<sc_uint<ARGUMENTSZ>> a1_dec,a2_dec,a3_dec;
  sc_in<sc_uint<OPCODESIZE>> opcd_dec;
  sc_in<sc_uint<PRECISION>> sel_r1,sel_r2;

  void test(){

    std::cout << "----MainTestbench----" << '\n';

    for (int i = 0; i < 20; i++) {
      wait();
      print();
    }

    sc_stop();
  }
  void print(){
    cout << '\n'<< '\n';
    cout << "clk:" <<clk<<"|count:"<<clkc<< '\n';
    cout<<"ins_fetch:";printBinary(ins_fetch);cout<<'\n';
    cout<<"ins_p1:";printBinary(ins_p1);cout<<'\n';
    cout<<"a1_dec:";printBinary(a1_dec);cout<<'\n';
    cout<<"a2_dec:";printBinary(a2_dec);cout<<'\n';
    cout<<"a3_dec:";printBinary(a3_dec);cout<<'\n';
    cout<<"opcd_dec:";printBinary(opcd_dec);cout<<'\n';
    cout<<"sel_r1:";printBinary(sel_r1);cout<<'\n';
    cout<<"sel_r2:";printBinary(sel_r2);cout<<'\n';
  }
  void log(){clkc+=1;}
  SC_CTOR(MainTestbench){
    SC_THREAD(test);
    sensitive<<clk;
    SC_METHOD(log);
    sensitive<<clk;
  }


};

#endif
