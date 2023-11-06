//----------------------------------------------------------------------
// D Flip Flop With Asynchronous Reset
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(dff){
  
  // Port DEcleration
  sc_in<bool>  clk_i;
  sc_in<bool>  rst_i;
  sc_in<bool>  d_i;
  sc_out<bool> q_o;
  sc_out<bool> q_n_o;

  // DFF Logic
  void dff_logic(){
    if(rst_i.read()){
    // When Reset is applied
      q_o.write(false);
      q_n_o.write(true);
    }
    else{
      q_o.write(d_i.read());
      q_n_o.write(!d_i.read());
    }
    
    
  }

  // Constructor
  SC_CTOR(dff){
    SC_METHOD(dff_logic);
    sensitive <<clk_i.pos() <<rst_i;
  }

};