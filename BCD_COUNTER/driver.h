//----------------------------------------------------------------------
// Driver for BCD Counter
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(driver){
  
  // Signal Decleration
  sc_out <bool>     rst_i;
  sc_out <bool>     enable_i;
  sc_out <bool>     load_i;
  sc_out <sc_uint<4>> data_i;

  // Drive the Inputs
  void inputs(){
    // Initialize inputs to known values
    rst_i.write(false);
    enable_i.write(false);
    load_i.write(false);
    data_i.write(false);
    
    // Apply Reset
    wait(7, SC_NS);
    rst_i.write(true);
    wait(10, SC_NS);
    rst_i.write(false);

    // Enable counter and allow to rollover
    wait(10, SC_NS);
    enable_i.write(true);
    wait(100, SC_NS);
    
    // Check parallel load
    load_i.write(true);
    data_i.write(random()%10);
    wait(10, SC_NS);
    load_i.write(false);
  }

  // Constructor
  SC_CTOR(driver){
    SC_THREAD(inputs);
  }

};