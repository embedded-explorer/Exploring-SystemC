//----------------------------------------------------------------------
// 4-Bit ALU Testbench
//----------------------------------------------------------------------

#include "systemc.h"
#include "alu.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]){
  
  // Signal decleration
  sc_signal <sc_uint<2>> opcode;
  sc_signal <sc_uint<4>> operand_a;
  sc_signal <sc_uint<4>> operand_b;
  sc_signal <sc_uint<4>> result;
  
  // Instantiation
  alu alu_inst("alu");
  driver drv_inst("driver");
  monitor mon_inst("monitor");
  
  alu_inst.opcode(opcode);
  alu_inst.operand_a(operand_a);
  alu_inst.operand_b(operand_b);
  alu_inst.result(result);
  
  drv_inst.opcode(opcode);
  drv_inst.operand_a(operand_a);
  drv_inst.operand_b(operand_b);
  
  mon_inst.opcode(opcode);
  mon_inst.operand_a(operand_a);
  mon_inst.operand_b(operand_b);
  mon_inst.result(result);
  
  // Add signals to VCD file
  sc_trace_file *Tf;
  Tf = sc_create_vcd_trace_file("trace");
  sc_trace(Tf, opcode, "opcode");
  sc_trace(Tf, operand_a, "operand_a");
  sc_trace(Tf, operand_b, "operand_b");
  sc_trace(Tf, result, "result");
  
  // End simulation
  sc_start(100, SC_NS);
  sc_close_vcd_trace_file(Tf);
  return 0;
}