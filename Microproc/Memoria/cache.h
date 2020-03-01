#ifndef CACHE_H
#define CACHE_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
#include <macros.h>

using namespace std;

SC_MODULE(cache) {
	
	sc_in <sc_uint<4> > dir;
	sc_in <sc_uint<2*PRECISION> > data_in;
	sc_out <sc_uint<2*PRECISION> > data_out;
	
	sc_uint<2*PRECISION> data[PRECISION];
	
	sc_in <bool> enable;
	sc_in <bool> clk;

	void read() {
		if (clk.read() == 0) {
			data_out = data[dir.read()];
			cout << "Leyendo: data[" << dir.read() << "] almacena " << data[dir.read()] << "\n";
		}
	}
	
	void write() {
		if (clk.read() && enable.read()) {
			data[dir.read()] = data_in.read();
			cout << "Escribiendo: data[" << dir.read() << "] = " << data[dir.read()] << "\n";
		}
	}

	SC_CTOR(cache) {
		SC_METHOD(read);
		sensitive << clk.neg(); 
		SC_METHOD(write);
		sensitive << clk.pos(); 
	}
};

#endif
