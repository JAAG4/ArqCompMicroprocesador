#include <systemc.h>
#include "Fetch.hpp"
#include "DecodingSelection.hpp"
#include "ual.hpp"
int sc_main(int argv, char* argc[]) {

  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  sc_start();
  return 0;
}
