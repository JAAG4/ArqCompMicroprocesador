#ifndef MEMORIA
#define MEMORIA

#include <systemc.h>
#include <iostream>
#include <iomanip>
#include <macros.h>
#include <cmath>

using namespace std;

SC_MODULE(Memoria) {

	sc_in <sc_uint<ARGUMENTSZ> > dirIn;
	sc_in <sc_uint<PRECISION> > dataIn;
	sc_out <sc_uint<PRECISION> > dataOut;

	sc_uint<PRECISION> data[ MEMSZ ];

	sc_in <bool> enable;
	sc_in <bool> clk;

	void read() {//-
		if (clk.read() == 0) {
			dataOut = data[dirIn.read()];

			//cout << "Leyendo: data[" << dir.read() << "] almacena " << data[dir.read()] << "\n";
		}
	}

	void write() {//+
		if (clk.read() && enable.read()) {
			data[dirIn.read()] = dataIn.read();
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
