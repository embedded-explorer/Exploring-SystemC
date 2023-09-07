//----------------------------------------------------------------------
// 4 TO 1 Multiplexer Driver
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(driver){ 
  
  // Signals to be driven
  sc_out<sc_bv<4>> i_i;
  sc_out<sc_bv<2>> s_i;
  
  // Function to apply inputs
  void inputs(){
    i_i.write("0010");

    s_i.write("00");
    wait(5,SC_NS);

    s_i.write("01");
    wait(5,SC_NS);

    s_i.write("10");
    wait(5,SC_NS);

    s_i.write("11");
    wait(5,SC_NS);
  }
  
  // Constructor
  SC_CTOR(driver){
    SC_THREAD(inputs);
    sensitive <<i_i <<s_i;
  }
};