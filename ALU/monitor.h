//----------------------------------------------------------------------
// 4-Bit ALU Monitor
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(monitor){

  // Inputs
  sc_in <sc_uint<2>> opcode;
  sc_in <sc_uint<4>> operand_a;
  sc_in <sc_uint<4>> operand_b;
  sc_in <sc_uint<4>> result;
  
  // Function to monitor
  void display(){
    cout << "Opcode :" << opcode \
         << " Operand A :" << operand_a \
         << " Operand B :" << operand_b \
         << " Result :" << result << endl;
  }

  SC_CTOR(monitor){
    SC_METHOD(display);
    sensitive << opcode << operand_a << operand_b << result;
  }
};