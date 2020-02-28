#ifndef AND_GATE
#define AND_GATE

SC_MODULE (And){

  sc_in  <bool> a ;
  sc_in  <bool> b ;
  sc_out <bool> c ;


  void func(){
    c.write( a.read() & b.read() ) ;
  }


  SC_CTOR(And){
    SC_METHOD(func);
	sensitive << a << b ;
  }
};

#endif
