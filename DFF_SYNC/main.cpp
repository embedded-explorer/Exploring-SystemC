//----------------------------------------------------------------------
// Main Function for DFF
//----------------------------------------------------------------------

#include "systemc.h"
#include "dff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[]){

  sc_signal<bool> rst_i;
  sc_signal<bool> d_i;
  sc_signal<bool> q_o;
  sc_signal<bool> q_n_o;
  sc_clock clk_i("clk_i", 10, SC_NS, 0.5);
 
  dff dff_inst("d_flip_flop");
  driver drv("driver");
  monitor mon("monitor");

  dff_inst.clk_i(clk_i);
  dff_inst.rst_i(rst_i);
  dff_inst.d_i(d_i);
  dff_inst.q_o(q_o);
  dff_inst.q_n_o(q_n_o);

  drv.clk_i(clk_i);
  drv.rst_i(rst_i);
  drv.d_i(d_i);

  mon.clk_i(clk_i);
  mon.rst_i(rst_i);
  mon.d_i(d_i);
  mon.q_o(q_o);
  mon.q_n_o(q_n_o);

  sc_trace_file *Tf;
  Tf = sc_create_vcd_trace_file("traces");
  
  sc_trace(Tf, clk_i, "clk_i");
  sc_trace(Tf, rst_i, "rst_i");
  sc_trace(Tf, d_i, "d_i");
  sc_trace(Tf, q_o, "q_o");
  sc_trace(Tf, q_n_o, "q_n_o");

  sc_start(100, SC_NS);
  
  sc_close_vcd_trace_file(Tf);
  
  return 0;
}
