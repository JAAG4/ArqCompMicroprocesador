#ifndef CACHE_H
#define CACHE_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
#include <macros.h>

using namespace std;

SC_MODULE(ArchivoRegistros) {

	sc_in <sc_uint<ARGUMENTSZ> > dirR1,dirR2,dirW;
	sc_in <sc_uint<PRECISION> > data_in;
	sc_out <sc_uint<PRECISION> > dOut1,dOut2;

	sc_uint<PRECISION> data[ARGUMENTSZ];

	sc_in <bool> enable;
	sc_in <bool> clk;

	void read() {//-
		if (clk.read() == 0) {
			dOut1 = data[dirR1.read()];
      dOut2 = data[dirR2.read()];
			//cout << "Leyendo: data[" << dir.read() << "] almacena " << data[dir.read()] << "\n";
		}
	}

	void write() {//+
		if (clk.read() && enable.read()) {
			data[dirW.read()] = data_in.read();
			//cout << "Escribiendo: data[" << dir.read() << "] = " << data[dir.read()] << "\n";
		}
	}

  void save(){
    fstream aRlog("AR.bin",ios::binary);
  }

	SC_CTOR(ArchivoRegistros) {
		SC_METHOD(read);
		sensitive << clk.neg();
		SC_METHOD(write);
		sensitive << clk.pos();
	}
};

#endif
