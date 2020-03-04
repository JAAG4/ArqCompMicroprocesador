#ifndef TESTBENCH
#define TESTBENCH
#include "macros.h"
#include "tools.hpp"
SC_MODULE(MainTestbench){
  sc_in<bool> clk;

  sc_in< sc_uint<ISZ> > ins_fetch,ins_p1;
  sc_in< sc_uint<ARGUMENTSZ> > a1_dec,a2_dec,a3_dec,arg_a_d,arg_b_d,dRes_alu;
  sc_in< sc_uint<OPCODESIZE> > opcd_dec;
  sc_in< sc_uint<PRECISION> > sel_r1,sel_r2;

  sc_in< sc_uint<PRECISION> > ar_dirW,ar_data_in;
  sc_in<bool> ar_enable,en_m;

  sc_in< sc_uint<OPCODESIZE> > pD2P_OpI,pD2P_OpO,opcd_2Alu;

  sc_in< sc_uint<PRECISION> > dat2_2alu,datR_alu,dirIn_mem,dataIn_mem,dat1_2alu,dataOut_m;
  sc_in< sc_uint<PRECISION> > st1i,st1o,st2i,st2o;

  

 

  void test(){

    std::cout << "----MainTestbench----" << '\n';

    for (int i = 0; i < 20; i++) {
      wait();
      print();
    }

    sc_stop();
  }
  void print(){
    cout << '\n'<< '\n';
    cout << "clk:" <<clk<<"|count:"<<clkc<< '\n';
    cout<<"ins_fetch:";printBinary(ins_fetch);cout<<'\n';
    cout<<"ins_p1:";printBinary(ins_p1);cout<<"\n\n";
    cout<<"a1_dec:";printBinary(a1_dec);cout<<'\n';
    cout<<"a2_dec:";printBinary(a2_dec);cout<<'\n';
    cout<<"a3_dec:";printBinary(a3_dec);cout<<'\n';
    cout<<"opcd_dec:";printBinary(opcd_dec);cout<<"||";pOPCD(opcd_dec);cout<<'\n';
    cout<<"sel_r1:";printBinary(sel_r1);cout<<"||"<<sel_r1<<'\n';
    cout<<"sel_r2:";printBinary(sel_r2);cout<<"||"<<sel_r2<<"\n\n";

    cout<<"st1i:";printBinary(st1i);cout<<'\n';
    cout<<"st1o:";printBinary(st1o);cout<<'\n';


    cout<<"ar_dirW:";printBinary(ar_dirW);cout<<'\n';
    cout<<"ar_data_in:";printBinary(ar_data_in);cout<<"||"<<ar_data_in<<'\n';
    cout<<"ar_enable:"<<ar_enable;cout<<'\n';
    cout<<"pD2P_OpI:"; printBinary(pD2P_OpI);cout<<'\n';
    cout<<"pD2P_OpO:"; printBinary(pD2P_OpO);cout<<'\n';
    cout<<"opcd_2Alu:"; printBinary(opcd_2Alu);cout<<'\n';
    cout<<"dat1_2alu:"; printBinary(dat1_2alu);cout<<'\n';
    cout<<"arg_b_d:"; printBinary(arg_b_d);cout<<"\n\n";

    cout<<"dat1_2alu:"; printBinary(dat1_2alu);cout<<'\n';
    cout<<"dat2_2alu:"; printBinary(dat2_2alu);cout<<'\n';
    cout<<"dRes_alu:"; printBinary(dRes_alu);cout<<"\n\n";

    cout<<"st2i:"; printBinary(st2i);cout<<'\n';
    cout<<"st2o:"; printBinary(st2o);cout<<'\n';

    cout<<"dirIn_mem:"; printBinary(dirIn_mem);cout<<'\n';
    cout<<"dataIn_mem:"; printBinary(dataIn_mem);cout<<'\n';
    cout<<"en_m:"<<en_m;cout<<'\n';
    cout<<"dataOut_m:"; printBinary(dataOut_m);cout<<"\n\n";






  }
  void log(){clkc+=1;}
  SC_CTOR(MainTestbench){
    SC_THREAD(test);
    sensitive<<clk;
    SC_METHOD(log);
    sensitive<<clk;
  }


};

#endif
