#ifndef CACHE_H
#define CACHE_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
#include <macros.h>

using namespace std;

SC_MODULE(Memoria) {

	sc_in <sc_uint<ARGUMENTSZ> > dirR,dirW;
	sc_in <sc_uint<PRECISION> > data_in;
	sc_out <sc_uint<PRECISION> > dOut;

	sc_uint<PRECISION> data[ARGUMENTSZ];

	sc_in <bool> enable;
	sc_in <bool> clk;

	void read() {//-
		if (clk.read() == 0) {
			dOut = data[dirR1.read()];

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

	SC_CTOR(Memoria) {
		SC_METHOD(read);
		sensitive << clk.neg();
		SC_METHOD(write);
		sensitive << clk.pos();
	}
};

#endif
