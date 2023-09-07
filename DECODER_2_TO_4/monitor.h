//----------------------------------------------------------------------
// 2 to 4 Decoder Monitor
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(monitor){
  
  // Signals to be monitored
  sc_in<bool> en_i;
  sc_in<sc_bv<2>> i_i;
  sc_in<sc_bv<4>> y_o;
  
  // Function to monitor signals
  void mon(){
    cout << "Enable: "<<en_i.read() \
         << " Input: " <<i_i.read() \
         << " Output: "<<y_o.read() \
         <<endl;
  }

  // Constructor
  SC_CTOR(monitor){
    SC_METHOD(mon);
    sensitive <<en_i <<i_i <<y_o;
  }
};
