//----------------------------------------------------------------------
// 2 Input AND Gate Driver
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(driver){ 

  sc_out<bool> a_i,b_i;

  void inputs(){
    a_i.write(false);
    b_i.write(false);
    wait(5,SC_NS);

    a_i.write(true);
    b_i.write(true);
    wait(5,SC_NS);

    a_i.write(true);
    b_i.write(false);
    wait(5,SC_NS);

    a_i.write(false);
    b_i.write(true);
    wait(5,SC_NS);

    a_i.write(true);
    b_i.write(true);
    wait(5,SC_NS);
  }

  SC_CTOR(driver){
    SC_THREAD(inputs);
    sensitive <<a_i <<b_i;
  }
};