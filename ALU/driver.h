//----------------------------------------------------------------------
// 4-Bit ALU Driver
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(driver){
  
  // Outputs
  sc_out <sc_uint<2>> opcode;
  sc_out <sc_uint<4>> operand_a;
  sc_out <sc_uint<4>> operand_b;
  
  // Function to drive
  void output(){
    
    // Test Addition
    opcode.write(0);
    operand_a.write(5);
    operand_b.write(4);
    wait(10, SC_NS);
    
    operand_a.write(3);
    operand_b.write(2);
    wait(10, SC_NS);
    
    // Test Subtraction
    opcode.write(1);
    operand_a.write(5);
    operand_b.write(4);
    wait(10, SC_NS);
    
    operand_a.write(3);
    operand_b.write(2);
    wait(10, SC_NS);
    
    // Test Left Shift
    opcode.write(2);
    operand_a.write(5);
    operand_b.write(1);
    wait(10, SC_NS);
    
    operand_a.write(2);
    operand_b.write(3);
    wait(10, SC_NS);
    
    // Test Right Shift
    opcode.write(3);
    operand_a.write(5);
    operand_b.write(1);
    wait(10, SC_NS);
    
    operand_a.write(3);
    operand_b.write(2);
    wait(10, SC_NS);
  }

  SC_CTOR(driver){
    SC_THREAD(output);
  }
};