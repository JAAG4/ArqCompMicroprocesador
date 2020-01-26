#ifndef TESTBENCH
#define TESTBENCH
#include "macros.h"
SC_MODULE(Testbench){

  sc_in<bool> clk;

  std::array<  sc_out<bool>, 4  > in;

  std::array<  sc_in<bool>, 16  > outs;


  void print(){
    //cout<<in[0].read()<<in[1].read()<<in[2].read()<<in[3].read()<<'\n';
    for(int i=0;i<4;i++)
    cout<<in[i].read()<<" ";

    cout<<"||";

    sc_uint<16> aux;
    sc_uint<4> aux2;
    for(int i=0;i<16;i++){

      cout <<" "<<outs.at(i).read()<<" ";
      aux[i] = outs[i];
    }
    cout<<" | ";
    for(int i=0;i<4;i++)
      aux2[3-i]=in[i];
    //cout<<"a2: "<<aux2;
    switch (aux2) {
      case SUM:cout<<"SUM";break;
      case SUB:cout<<"SUB";break;
      case MULT:cout<<"MULT";break;
      case LOAD:cout<<"LOAD";break;
      case STORE:cout<<"STORE";break;
      case JZ:cout<<"JZ";break;
      case JNZ:cout<<"JNZ";break;
      case JN:cout<<"JN";break;
      case JEQ:cout<<"JEQ";break;
      
      default:cout<<"UNNAMED_INSTRUCTION("<<aux2<<")";break;
    }
    cout<< '\n';
  }


  void test(){
  cout<<"INSTRUCCIONES || DECODIFICACION"<<"\n";
  sc_uint<4> aux = 0;
  for(int ii=0 ; ii<16 ; ii++){

    for(int jj=0;jj<4;jj++){
      in[3-jj] = aux[jj];
    }
    aux +=1;
    //cout<<"aux:"<<aux<<"/"<<aux[0]<<aux[1]<<aux[2]<<aux[3]<<'\n';

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
