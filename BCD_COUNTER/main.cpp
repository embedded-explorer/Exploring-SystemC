//----------------------------------------------------------------------
// Main Function for BCD Counter
//----------------------------------------------------------------------

#include "systemc.h"
#include "bcd_counter.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[]){

  sc_signal  <bool>     rst_i;
  sc_signal  <bool>     enable_i;
  sc_signal  <bool>     load_i;
  sc_signal  <sc_uint<4>> data_i;
  sc_signal  <sc_uint<4>> count_o;
  sc_clock clk_i("clk_i", 10, SC_NS, 0.5);
 
  // Counter Instance
  bcd_counter counter("BCD Counter");
  counter.clk_i(clk_i);
  counter.rst_i(rst_i);
  counter.enable_i(enable_i);
  counter.load_i(load_i);
  counter.data_i(data_i);
  counter.count_o(count_o);
  
  // Driver Instance
  driver drv("driver");
  drv.rst_i(rst_i);
  drv.enable_i(enable_i);
  drv.load_i(load_i);
  drv.data_i(data_i);
  
  // Monitor Instance
  monitor mon("monitor");
  mon.clk_i(clk_i);
  mon.rst_i(rst_i);
  mon.enable_i(enable_i);
  mon.load_i(load_i);
  mon.data_i(data_i);
  mon.count_o(count_o);
  
  // Dump VCD File
  sc_trace_file *Tf;
  Tf = sc_create_vcd_trace_file("traces");
  sc_trace(Tf, clk_i, "clk_i");
  sc_trace(Tf, rst_i, "rst_i");
  sc_trace(Tf, enable_i, "enable_i");
  sc_trace(Tf, load_i, "load_i");
  sc_trace(Tf, data_i, "data_i");
  sc_trace(Tf, count_o, "count_o");

  sc_start(250, SC_NS);
  
  sc_close_vcd_trace_file(Tf);
  
  return 0;
}
