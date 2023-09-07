//----------------------------------------------------------------------
// 2 Input AND Gate Main
//----------------------------------------------------------------------

#include "systemc.h"
#include "andgate.h"
#include "driver.h"
#include "monitor.h"

int sc_main( int argc, char* argv[]){
  sc_signal <bool> a_i, b_i, y_o;

  andgate agate("andgate");
  driver drive("driver");
  monitor mon("monitor");
  agate.a_i(a_i); agate.b_i(b_i); agate.y_o(y_o);
  drive.a_i(a_i); drive.b_i(b_i);
  mon.a_i(a_i); mon.b_i(b_i); mon.y_o(y_o);

  //Waveform
  sc_trace_file *Tf;
  Tf = sc_create_vcd_trace_file("traces");
  sc_trace(Tf, a_i, "a_i");
  sc_trace(Tf, b_i, "b_i");
  sc_trace(Tf, y_o, "y_o");
  sc_start(30,SC_NS);
  sc_close_vcd_trace_file(Tf);
  return 0; 
}