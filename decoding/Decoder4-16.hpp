#include "Decoder2-4.hpp"
#include <array>
#ifndef DECODER4_16
#define DECODER4_16
SC_MODULE(Decoder4_16){

std::array<  And*, 16  > andGates;

Decoder2_4* decA;
Decoder2_4* decB;

std::array<  sc_in<bool>, 4  > in;


std::array<  sc_out<bool>, 16  > outs;

std::array< sc_signal<bool>, 4 > sigA;
std::array< sc_signal<bool>, 4 > sigB;


  SC_CTOR(Decoder4_16){
    for(int j=0;j<16;j++)
      andGates.at(j) = new And("andgates");

    decA = new Decoder2_4("decA");
    decB = new Decoder2_4("decB");

    //in
    decA->a( in.at(0) );
    decA->b( in.at(1) );

    decB->a( in.at(2) );
    decB->b( in.at(3) );


    //mid
    decA->o1( sigA.at(0) );
    decA->o2( sigA.at(1) );
    decA->o3( sigA.at(2) );
    decA->o4( sigA.at(3) );

    decB->o1( sigB.at(0) );
    decB->o2( sigB.at(1) );
    decB->o3( sigB.at(2) );
    decB->o4( sigB.at(3) );

    int i = 0;
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        andGates.at(i)->a( sigA.at(j) );
        andGates.at(i)->b( sigB.at(k) );
        i++;
      }
    }


    //outs
    for(int j=0;j<16;j++)
      andGates.at(j)->c( outs.at(j) );


  }


  ~Decoder4_16(){
  delete decA;
  delete decB;

  for(int j=0;j<16;j++)
    delete andGates.at(j);
  }
};
# endif //DECODER4_16
