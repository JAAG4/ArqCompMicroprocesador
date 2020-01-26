#ifndef NOT_GATE
#define NOT_GATE

SC_MODULE (Not){

  sc_in   <bool> a ;
  sc_out  <bool> b ;

  void func(){
    b.write( !(a.read() ) ) ;
  }

  SC_CTOR(Not){
    SC_METHOD(func);
    sensitive << a ;
  }
};

#endif
