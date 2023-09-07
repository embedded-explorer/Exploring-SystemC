//----------------------------------------------------------------------
// 4 TO 1 Multiplexer Main
//----------------------------------------------------------------------

#include "systemc.h"
#include "mux_4_to_1.h"
#include "driver.h"
#include "monitor.h"

// Main Function
int sc_main( int argc, char* argv[]){
  sc_signal <sc_bv<4>> i_i;
  sc_signal <sc_bv<2>> s_i;
  sc_signal <bool> y_o;

  mux_4_to_1 mux("mux");
  driver drive("driver");
  monitor mon("monitor");
  mux.i_i(i_i); mux.s_i(s_i); mux.y_o(y_o);
  drive.i_i(i_i); drive.s_i(s_i);
  mon.i_i(i_i); mon.s_i(s_i); mon.y_o(y_o);

  //Waveform
  sc_trace_file *Tf;
  Tf = sc_create_vcd_trace_file("traces");
  sc_trace(Tf, i_i, "i_i");
  sc_trace(Tf, s_i, "s_i");
  sc_trace(Tf, y_o, "y_o");
  sc_start(30,SC_NS);
  sc_close_vcd_trace_file(Tf);
  return 0; 
}