#ifndef TESTBENCH
#define TESTBENCH

#include <iomanip>
#include <iostream>
#include "macros.h"
using namespace std;
SC_MODULE(Testbench) {

  sc_in<bool> clk;
  int clkc=0;
  sc_in< sc_uint<ISZ> > instruction;
  sc_in< sc_uint<PRECISION> > pc;

  sc_out<sc_uint<PRECISION>> wbDir;
  sc_out<bool> enable;

  void print() {
    cout<<"|"<<setw(2)<<pc.read().to_int()<<"|"<<" ";
    cout << "\t";

    for (int i = 0; i < 14; ++i)
      cout << instruction.read().range(14-(i+1),14-(i+1));

    cout << "  | " << setw(5) << instruction.read() << " |  ";
    cout<<"["<<clk<<"]["<<clkc<<"]";
    cout <<"\n";
  }
  void test() {
    cout << "\n"
         << "PC\tInstrucción(BIN) | (DEC) | CLK/t |"
         << "\n----------------------------------------------------------------\n";


    for (int i = 0; i < 10; i++) {
      wait();
      print();
    }
    cout<<"---WB---\n";
    wbDir.write(1);
    enable.write(1);
    wait();
    print();
    wait();
    print();
    wait();
    print();

    sc_stop();
  }

  void log(){clkc++;}

  SC_CTOR(Testbench) {
      SC_THREAD(test);
      sensitive<<clk.neg();
      SC_METHOD(log);
      sensitive<<clk.pos();
  }
};

#endif//TESTBENCH
