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


void printBinary(sc_uint<ARGUMENTSZ> a){
  for (int i = 0; i < ARGUMENTSZ; ++i)
    cout << a.range(i,i);
}
