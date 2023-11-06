//----------------------------------------------------------------------
// Monitor for Melay FSM to detect 101 overlapping sequence
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(monitor){
  
  // Signal Decleration
  sc_in<bool> clk_i;
  sc_in<bool> rst_i;
  sc_in<bool> d_i;
  sc_in<bool> y_o;
  
  // Function to monitor signals
  void monitor_signals(){
	while(true){
	  cout << sc_time_stamp();
	  cout << "Reset" << rst_i.read;
	  cout << "Input" << d_i.read;
	  cout << "Output" << y_o.read;
	  cout << endl;
	  wait();
	}
  }
  
  // Constructor
  SC_CONT(){
	SC_THREAD(monitor_signals);
	sensitive <<clk_i.pos();
  }
};