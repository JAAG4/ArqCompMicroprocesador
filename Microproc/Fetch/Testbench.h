#ifndef TESTBENCH
#define TESTBENCH

#include <iomanip>
#include <iostream>
#include "macros.h"
using namespace std;
SC_MODULE(Testbench) {

  sc_in<bool> clk;

  sc_in< sc_uint<ISZ> > instruction;
  sc_in< sc_uint<PRECISION> > pc_log;

  sc_out<sc_uint<PRECISION>> wbDir;
  sc_out<bool> enable;

  void print() {if(clk.read()==0)return;
    cout<<"|"<<setw(2)<<pc_log.read().to_int()<<"|"<<" ";
    cout << "\t";

    for (int i = 0; i < ISZ; ++i)
      cout << instruction.read().range(ISZ-(i+1),ISZ-(i+1));

    cout << "  | " << setw(5) << instruction.read() << " |  ";
    cout<<"["<<clk<<"]["<<clkc<<"]"<<"\tWBdir:"<<wbDir<<" e:"<<enable;
    cout <<"\n";
  }
  void test() {//-
    cout << "\n"
         << "PC\tInstrucción(BIN) | (DEC) | CLK/t |"
         << "\n----------------------------------------------------------------\n";


    for (int i = 0; i < 16; i++) {
      enable.write(0);
      wait();
      print();
      if(clk.read()==0&&clkc==5){
        cout<<"---WB---"<<"at["<<clk<<"]["<<clkc<<"]"<<endl;
        wbDir.write(1);
        enable.write(1);
        wait();
        print();
      }
    }
    wait();
    print();
    wait();
    print();

    sc_stop();
  }

  void log(){clkc++;}//+

  SC_CTOR(Testbench) {
      SC_THREAD(test);
      sensitive<<clk;
      SC_METHOD(log);
      sensitive<<clk.pos();
  }
};

#endif//TESTBENCH
