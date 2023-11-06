//----------------------------------------------------------------------
// Monitor for BCD Counter
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(monitor){

  // Signal Decleration
  sc_in  <bool>     clk_i;
  sc_in  <bool>     rst_i;
  sc_in  <bool>     enable_i;
  sc_in  <bool>     load_i;
  sc_in  <sc_uint<4>> data_i;
  sc_in  <sc_uint<4>> count_o;

  // Function to Monitor Signals
  void check(){
    cout << "Reset: " << rst_i \
         << " Enable " << enable_i \
         << " Load " << load_i \
         << " Data " << data_i \
         << " Count " << count_o <<endl;
  }

  // Constructor
  SC_CTOR(monitor){
    SC_METHOD(check);
    sensitive <<clk_i.pos();
  }

};