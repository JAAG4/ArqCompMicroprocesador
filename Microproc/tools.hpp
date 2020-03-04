#include <iostream>
#include <string>

using namespace std;

void printBinary(sc_uint<PRECISION> a){
  for (int i = 0; i < PRECISION; ++i)
    cout << a.range(i,i);
}

void printBinary(sc_uint<INSTRUCTION_SIZE> a){
  for (int i = 0; i < INSTRUCTION_SIZE; ++i)
    cout << a.range(i,i);
}


void printBinary(sc_uint<OPCODESIZE> a){
  for (int i = 0; i < OPCODESIZE; ++i)
    cout << a.range(i,i);
}

void pOPCD(sc_uint<OPCODESIZE> a){

  switch(a){
    case SUM: cout<<"SUM";break;
    case SUB: cout<<"SUB";break;
    case MULT: cout<<"MULT";break;
    case DIV: cout<<"DIV";break;
    case LOAD: cout<<"LOAD";break;
    case STORE: cout<<"STORE";break;
    case JZ: cout<<"JZ";break;
    case JNZ: cout<<"JNZ";break;
    case JEQ: cout<<"JEQ";break;
    case JNEQ: cout<<"JNEQ";break;
    case AND: cout<<"AND";break;
    case OR: cout<<"OR";break;
    default: cout<<"STALL";break;

  }

}


