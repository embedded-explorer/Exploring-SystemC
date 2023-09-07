//----------------------------------------------------------------------
// 2 to 4 Decoder Implementation
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(decoder_2_to_4){

  // Port Decleration
  sc_in<bool> en_i; // Enable Input
  sc_in<sc_bv<2>> i_i; // 2-Bit Input
  sc_out<sc_bv<4>> y_o; // 4-Bit Output
  
  // Multiplexer Logic
  void decoder(){
    
    // Convert bit vector to int
    sc_uint<8> in = i_i.read().to_uint();
    
    if(en_i.read()){
      switch(in){
        case 0  : y_o.write("0001");
                  break;
        case 1  : y_o.write("0010");
                  break;
        case 2  : y_o.write("0100");
                  break;
        case 3  : y_o.write("1000");
                  break;
        default : y_o.write("0000");
      }
    }
    else {
      y_o.write("0000");
    }
  }

  // Constructor
  SC_CTOR(decoder_2_to_4){
    SC_METHOD(decoder);
    sensitive <<en_i <<i_i;
  }

};