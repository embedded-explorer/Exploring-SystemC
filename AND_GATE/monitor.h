//----------------------------------------------------------------------
// 2 Input AND Gate Monitor
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(monitor){

  sc_in<bool> a_i,b_i,y_o;

  void mon(){
    cout << "Inputs: "<<a_i <<b_i << " Output: "<<y_o <<endl;
  }

  SC_CTOR(monitor){
    SC_METHOD(mon);
    sensitive <<a_i <<b_i;
  }
};