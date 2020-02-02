#ifndef TESTBENCH
#define TESTBENCH

#include <iomanip>
#include "macros.h"
SC_MODULE(Testbench){

  sc_in<bool> clk;

  sc_out< sc_uint<4> > op_id;
  sc_out< sc_uint< PRECISION > > firstOperator;
  sc_out< sc_uint< PRECISION > > secondOperator;
  sc_in< sc_uint< PRECISION > > result;


  void print_op(){
    cout<<std::setw(9);
    switch( op_id.read() ){


      case SUM:cout<<"SUM";break;

      case SUB:cout<<"SUB";break;

      case MULT:cout<<"MULT";break;

      case DIV:cout<<"DIV";break;

      case LOAD:cout<<"LOAD";break;

      case STORE:cout<<"STORE";break;

      case JZ:cout<<"JZ";break;

      case JNZ:cout<<"JNZ";break;

      case JEQ:cout<<"JEQ";break;

      case JNEQ:cout<<"JNEQ";break;

      case AND:cout<<"AND";break;

      case OR:cout<<"OR";break;
      cout<<"\n";
    }
  }
  void print(){
    print_op();cout<<" | "<< std::setw(14) <<firstOperator.read()<<" | "<< std::setw(15)<<secondOperator.read()<<" | "<< std::setw(6)<<result.read()<<" || "<<clk.read()<<"\n";
  }


  void test(){
  cout<<"Operation | First Operator | Second Operator | Result || Clock"<<"\n";
    for (int i = 0; i < 12; i++) {
      op_id.write(i);

      for (int j = 0,k=18; j < 20; j++,k--) {
        firstOperator.write(j);
        secondOperator.write(k);
        wait();
        print();
      }
      cout<<"--------------------------------------------------------------\n";
    }

  sc_stop();
  }

  SC_CTOR(Testbench){
    SC_THREAD(test);
    sensitive<<clk;
  }
};

#endif// TESTBENCH
