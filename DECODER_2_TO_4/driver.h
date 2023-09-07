//----------------------------------------------------------------------
// 2 to 4 Decoder Driver
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(driver){ 
  
  // Signals to be driven
  sc_out<bool> en_i;
  sc_out<sc_bv<2>> i_i;
  
  // Function to apply inputs
  void inputs(){
    en_i.write(false);

    i_i.write("00");
    wait(5,SC_NS);

    i_i.write("01");
    wait(5,SC_NS);

    i_i.write("10");
    wait(5,SC_NS);

    i_i.write("11");
    wait(5,SC_NS);
    
    en_i.write(true);

    i_i.write("00");
    wait(5,SC_NS);

    i_i.write("01");
    wait(5,SC_NS);

    i_i.write("10");
    wait(5,SC_NS);

    i_i.write("11");
    wait(5,SC_NS);
  }
  
  // Constructor
  SC_CTOR(driver){
    SC_THREAD(inputs);
    sensitive <<en_i <<i_i;
  }
};