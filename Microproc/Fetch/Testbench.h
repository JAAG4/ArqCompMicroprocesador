#ifndef TESTBENCH
#define TESTBENCH

#include <iomanip>
#include <iostream>
#include "macros.h"
using namespace std;
SC_MODULE(Testbench) {

  sc_in<bool> clk;
  int clkc;
  sc_in< sc_uint<ISZ> > instruction;
  sc_out< sc_uint<PRECISION> > pc;

  sc_out<sc_uint<PRECISION>> wbData;
  sc_out<bool> select;

  void print() {
    cout<<"|"<<setw(2)<<pc<<"|"<<" ";
    cout << "\t";

    for (int i = 0; i < 14; ++i)
      cout << instruction.read().range(14-(i+1),14-(i+1));

    cout << "  | " << setw(5) << instruction.read() << " |  ";
    cout<<"["<<clk<<"]["<<clkc<<"]";
    cout <<"\n";
  }
  void test() {
    cout << "\n"
         << "PC\t\t Instrucción(BIN) | (DEC) | CLK |"
         << "\t\t----------------------------------------------------------------\n";


    for (int i = 0; i < 10*3; i++) {
      wait();
      print();
    }

    wbData.write(0);
    select.write(1);

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
