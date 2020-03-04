#ifndef UAL_H
#define UAL_H


#include <systemc.h>
#include <iostream>
#include "macros.h"
SC_MODULE(Ual){

  sc_in< sc_uint<OPCODESIZE> > op_id;
  sc_in< sc_uint< PRECISION > > firstOperator;
  sc_in< sc_uint< PRECISION > > secondOperator;
  sc_out< sc_uint< PRECISION > > result;

  SC_CTOR(Ual){
    SC_METHOD(operation)
      sensitive << firstOperator << secondOperator << op_id;
  }

  void operation(){

    switch( op_id.read() ){

      default: result.write(0); break;

      


      case  SUM:
        //Addition operation
        result.write( firstOperator.read() + secondOperator.read() );
        break;


      case SUB:
        //Substraction operation (only unsigned integers)
        if(firstOperator.read() > secondOperator.read())
          result.write(  firstOperator.read() - secondOperator.read() );
        else
          result.write( secondOperator.read() - firstOperator.read() );
        break;


      case MULT:
        //Multiplication operation
        result.write( firstOperator.read() * secondOperator.read() );
        break;


      case DIV:
        //Division operation
        if(secondOperator.read()==0 || firstOperator.read()==0){
          result.write(0);
        }
        else{
          result.write( firstOperator.read() / secondOperator.read() );
        }
          break;


      ///Comparision operations

      case JEQ:
        //Commpare if two numbers are equal (Jump)
        result.write( firstOperator.read() == secondOperator.read() );
        break;


      case JNEQ:
        //Commpare if two numbers are NOT equal (Jump)
        result.write( firstOperator.read() != secondOperator.read() );
        break;

        case JZ:
        //If first Operator equals zero, jump
          result.write( firstOperator.read() == 0 );
        break;

      case JNZ:
      //If first Operator doesn't equal zero, jump
        result.write( firstOperator.read() != 0 );
      break;

      ///Logical operations

      case AND:
        result.write( firstOperator.read() and secondOperator.read() );
        break;


      case OR:
        result.write( firstOperator.read() or secondOperator.read() );
        break;


    }
  }

};

#endif// UAL_H
