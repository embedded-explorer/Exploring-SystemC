//----------------------------------------------------------------------
// Main Function for Melay FSM to detect 101 overlapping sequence
//----------------------------------------------------------------------

#include "systemc.h"
#include "melay_fsm_101.h"
#include "driver.h"
#include "monitor.h"

// Main Function
int sc_main( int argc, char* argv[]){
  sc_signal <bool> rst_i, d_i, y_o;
  sc_clock clk_i("Clock", 5, SC_NS, 0.5);

  melay_fsm_101 fsm("dut");
  driver drv("driver");
  monitor mon("monitor");
  fsm.clk_i(clk_i); fsm.rst_i(rst_i); fsm.d_i(d_i); fsm.y_o(y_o);
  drv.clk_i(clk_i); drv.rst_i(rst_i); drv.d_i(d_i);
  mon.clk_i(clk_i); mon.rst_i(rst_i); mon.d_i(d_i); mon.y_o(y_o)

  //Waveform
  sc_trace_file *Tf;
  Tf = sc_create_vcd_trace_file("traces");
  sc_trace(Tf, clk_i, "clk_i");
  sc_trace(Tf, rst_i, "rst_i");
  sc_trace(Tf, d_i, "d_i");
  sc_trace(Tf, y_o, "y_o");
  sc_start(100,SC_NS);
  sc_close_vcd_trace_file(Tf);
  return 0; 
}