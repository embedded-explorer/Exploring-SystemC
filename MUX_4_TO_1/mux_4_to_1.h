//----------------------------------------------------------------------
// 4 TO 1 Multiplexer Implementation
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(mux_4_to_1){

  // Port Decleration
  sc_in<sc_bv<4>> i_i; // 4-Bit Input
  sc_in<sc_bv<2>> s_i; // 2-Bit Select Line
  sc_out<bool> y_o; // Output
  
  // Multiplexer Logic
  void mux(){
    
    // Convert bit vector to int
    int select_value = s_i.read().to_uint();
    sc_bv<4> in = i_i.read();
    
    switch(select_value){
      case 0  : y_o.write(in[0].to_bool());
                   break;
      case 1  : y_o.write(in[1].to_bool());
                   break;
      case 2  : y_o.write(in[2].to_bool());
                   break;
      case 3  : y_o.write(in[3].to_bool());
                   break;
      default : y_o.write(false);
    }
  }

  // Constructor
  SC_CTOR(mux_4_to_1){
    SC_METHOD(mux);
    sensitive <<i_i <<s_i;
  }

};