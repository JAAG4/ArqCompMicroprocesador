#include <fstream>
#include <string>

using namespace std;

#ifndef FETCH
#define FETCH

#define MI_filename "in.txt"

SC_MODULE (Fetch) {
  ifstream MI;
  sc_in<bool> clk, connection;
  sc_out< sc_uint<14> > instruction;

  void fetch() {
    string line;
    getline(MI,line);
    sc_uint<14> temp;
    for (int i = 0; i < 14; ++i)
      temp[i] = line[14-(i+1)]-'0';
    instruction = temp;
  }

  SC_CTOR (Fetch) {
    MI.open(MI_filename);
    SC_METHOD(fetch);
    sensitive<<clk.neg();
  }

  ~Fetch() {
    MI.close();
  }
};

#endif//FETCH
