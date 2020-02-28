#ifndef TESTBENCH
#define TESTBENCH

#include <iomanip>

#include "macros.h"

SC_MODULE(Testbench) {
  sc_out<bool> connection;
  sc_in< sc_uint<14> > instruction;
  sc_in<bool> clk;


  sc_in< sc_uint<INSTRUCTION_SIZE> > p1,p2;


  void print() {
    cout << "\t\t  ";

    for (int i = 0; i < 14; ++i)
      cout << instruction.read().range(14-(i+1),14-(i+1));
    cout << "  | " << setw(5) << instruction.read() << " |  " << clk.read() <<"  | ";
    for (int i = 0; i < 14; ++i)
      cout << p1.read().range(14-(i+1),14-(i+1));
    cout << " | ";
    for (int i = 0; i < 14; ++i)
    cout << p2.read().range(14-(i+1),14-(i+1));
    cout <<"\n";
  }
  void test() {
    cout << "\n"
         << "\t\t Instrucción(BIN) | (DEC) | CLK | pipes      (p1 | p2)\n"
         << "\t\t----------------------------------------------------------------\n";

    for (int i = 0; i < INSTRUCTIONS; ++i) {
      wait();
      print();
    }


    sc_stop();
  }

  SC_CTOR(Testbench) {
      SC_THREAD(test);
      sensitive<<clk.neg();
  }
};

#endif//TESTBENCH
