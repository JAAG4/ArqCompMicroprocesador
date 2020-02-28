#ifndef TESTBENCH
#define TESTBENCH
#include "macros.h"
SC_MODULE(Testbench){

  sc_in<bool> clk;

  sc_out<sc_uint<ISZ>> fetchedInstruction;
  sc_in< sc_uint<OPCODESIZE> > opcode;
  sc_in< sc_uint<PRECISION> > arg1,arg2;

  sc_uint<OPCODESIZE> opcode_aux;

  void print(){
    opcode_aux = opcode.read();
    switch (opcode_aux) {
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

      default:cout<<"UNNAMED_INSTRUCTION("<<opcode_aux<<")";break;
    }
    cout<<" < "<<arg1<<" > < "<<arg2<<" >"<< '\n';
  }


  void test(){
  cout<<"INSTRUCCIONES || DECODIFICACION"<<"\n";
    for (int i = 0; i < 20; i++) {
      fetchedInstruction = i;

      wait();
      print();
    }
    sc_stop();
  }


  SC_CTOR(Testbench){
    SC_THREAD(test);
    sensitive<<clk;
  }
};

#endif// TESTBENCH
