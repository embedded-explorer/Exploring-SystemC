//----------------------------------------------------------------------
// 4-Bit ALU Implementation
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(alu){
  
  // Port List
  sc_in  <sc_uint<2>> opcode;
  sc_in  <sc_uint<4>> operand_a;
  sc_in  <sc_uint<4>> operand_b;
  sc_out <sc_uint<4>> result;
  
  // Logic Implementation
  void compute_result(){
    switch(opcode.read()){
      case 0 : result.write(operand_a.read() + operand_b.read());
      break;
      case 1 : result.write(operand_a.read() - operand_b.read());
      break;
      case 2 : result.write(operand_a.read() << operand_b.read());
      break;
      case 3 : result.write(operand_a.read() >> operand_b.read());
      break;
      default: result.write(0); 
    }
  }
  
  // Constructor
  SC_CTOR(alu){
    SC_METHOD(compute_result);
    sensitive << opcode << operand_a << operand_b;
  }
};