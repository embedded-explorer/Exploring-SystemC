//----------------------------------------------------------------------
// 4 TO 1 Multiplexer Monitor
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(monitor){
  
  // Signals to be monitored
  sc_in<sc_bv<4>> i_i;
  sc_in<sc_bv<2>> s_i;
  sc_in<bool> y_o;
  
  // Function to monitor signals
  void mon(){
    cout << "Input: "<<i_i.read() << " Select: " <<s_i.read() << " Output: "<<y_o.read() <<endl;
  }
  
  // Constructor
  SC_CTOR(monitor){
    SC_METHOD(mon);
    sensitive <<i_i <<s_i <<y_o;
  }
};