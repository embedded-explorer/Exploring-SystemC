//----------------------------------------------------------------------
// Driver for Melay FSM to detect 101 overlapping sequence
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(driver){ 
  
  // Signal Decleration
  sc_in<bool>  clk_i;
  sc_out<bool> rst_i;
  sc_out<bool> d_i;
  
  // Function to drive inputs
  void drive_inputs(){
	
	// Initialize inputs to known values
	rst_i.write(false);
	d_i.write(false);
	
	// Apply Reset
	wait(2, SC_NS);
	rst_i.write(true);
	wait();
	rst_i.write(false);
	
	// Apply 1101100101
	d_i.write(true);
	wait();
	d_i.write(true);
	wait();
	d_i.write(false);
	wait();
	d_i.write(true);
	wait();
	d_i.write(true);
	wait();
	d_i.write(false);
	wait();
	d_i.write(false);
	wait();
	d_i.write(true);
	wait();
	d_i.write(false);
	wait();
	d_i.write(true);
	wait();
  }
  
  // Constructor
  SC_CONT(driver){
    SC_THREAD(drive_inputs);
	sensitive <<clk_i.pos();
  }
  
};