//----------------------------------------------------------------------
// Driver for DFF
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(driver){
  
  // Signal Decleration
  sc_out<bool> rst_i;
  sc_out<bool> d_i;

  // Drive the Inputs
  void inputs(){
    // Initialize inputs to known values
    rst_i.write(false);
    d_i.write(false);
    
    // Apply Reset
    wait(7, SC_NS);
    rst_i.write(true);
    wait(10, SC_NS);
    rst_i.write(false);

    // Change D INput
    wait(10, SC_NS);
    d_i.write(true);
    wait(20, SC_NS);
    d_i.write(false);
    wait(10, SC_NS);
    
    // Change D and Apply Reset
    wait(10, SC_NS);
    d_i.write(true);
    wait(20, SC_NS);
    rst_i.write(true);
    wait(10, SC_NS);
    
  }

  // Constructor
  SC_CTOR(driver){
    SC_THREAD(inputs);
  }

};