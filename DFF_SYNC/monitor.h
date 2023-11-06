//----------------------------------------------------------------------
// Monitor for DFF
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(monitor){

  // Signal Decleration
  sc_in<bool> clk_i;
  sc_in<bool> rst_i;
  sc_in<bool> d_i;
  sc_in<bool> q_o;
  sc_in<bool> q_n_o;

  // Function to Monitor Signals
  void check(){
    while(1){
      cout << "Reset: " <<rst_i <<" D " <<d_i <<" Q " <<q_o << " Qn " <<q_n_o <<endl;
      wait();
    }
  }

  // Constructor
  SC_CTOR(monitor){
    SC_THREAD(check);
    sensitive <<clk_i.pos();
  }

};