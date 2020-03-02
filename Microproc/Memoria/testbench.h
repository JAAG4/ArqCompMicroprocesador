#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include <iostream>
#include <macros.h>

using namespace std;

SC_MODULE(testbench) {
	sc_in <sc_uint<16> > data_out;
	sc_out<sc_uint<16> > data_in;
	sc_out<sc_uint<4> > dir;

	sc_in<bool> clk;
	sc_out<bool> enable;

	void test() {
		bool enable_;
		int data_in_;
		int dir_ = 0;
		cout << "Valor de clk pasado: " << clk.read() << "\n";
		while(dir_>=0 && dir_<=PRECISION-1) {
			cout << "enable: ";
			cin >> enable_;

			cout << "dir: ";
			cin >> dir_;
			
			cout << "data_in: ";
			cin >> data_in_;

			enable = enable_;
			dir = dir_;
			data_in = data_in_;
			
			wait();
			cout << "Valor del clk pasado: " << clk.read() << "\n";
		}
		sc_stop();
	}

	SC_CTOR(testbench) {
		cout << "\n\n";
		SC_THREAD(test);
		sensitive << clk;
	}
};

#endif
