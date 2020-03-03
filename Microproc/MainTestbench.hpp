#ifndef TESTBENCH
#define TESTBENCH
#include "macros.h"
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
    cout<<"ins_fetch:"<<ins_fetch<<'\n';
    cout<<"ins_p1:"<<ins_p1<<'\n';
    cout<<"a1_dec:"<<a1_dec<<'\n';
    cout<<"a2_dec:"<<a2_dec<<'\n';
    cout<<"a3_dec:"<<a3_dec<<'\n';
    cout<<"opcd_dec:"<<opcd_dec<<'\n';
    cout<<"sel_r1:"<<sel_r1<<'\n';
    cout<<"sel_r2:"<<sel_r2<<'\n';
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
