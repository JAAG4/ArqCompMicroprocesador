#include <AND_GATE.h>
#include <NOT_GATE.h>

#ifndef DECODER2_4
#define DECODER2_4

SC_MODULE(Decoder2_4){
//2 to 4 Decoder2_4
Not* notG1;
Not* notG2;

And* andG1;
And* andG2;
And* andG3;
And* andG4;


sc_in<bool> a;
sc_in<bool> b;

sc_out<bool> o1;
sc_out<bool> o2;
sc_out<bool> o3;
sc_out<bool> o4;

sc_signal<bool> sNot_a, sNot_b ;

  SC_CTOR(Decoder2_4){
    notG1 = new Not("notG1");
    notG2 = new Not("notG2");

    andG1 = new And("andG1");
    andG2 = new And("andG2");
    andG3 = new And("andG3");
    andG4 = new And("andG4");


    //not entradas & señales
    notG1->a(a);
    notG2->a(b);

    notG1->b(sNot_a);
    notG2->b(sNot_b);

    //And Entradas & señales
    andG1->a(sNot_a);
    andG1->b(sNot_b);

    andG2->a(sNot_a);
    andG2->b(b);

    andG3->a(a);
    andG3->b(sNot_b);

    andG4->a(a);
    andG4->b(b);

    //salidas
    andG1->c(o1);
    andG2->c(o2);
    andG3->c(o3);
    andG4->c(o4);
  }


  ~Decoder2_4(){
    delete notG1;
    delete notG2;

    delete andG1;
    delete andG2;
    delete andG3;
    delete andG4;
  }
};

#endif //DECODER2_4
