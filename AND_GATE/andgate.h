//----------------------------------------------------------------------
// 2 Input AND Gate Implementation
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(andgate){
    
  sc_in<bool> a_i;
  sc_in<bool> b_i;
  sc_out<bool> y_o;

  void compute_and(){
    y_o.write(a_i.read() && b_i.read());
  }

  SC_CTOR(andgate){
    SC_METHOD(compute_and);
    sensitive <<a_i <<b_i;
  }
};