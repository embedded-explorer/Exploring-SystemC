//----------------------------------------------------------------------
// 2 to 4 Decoder Main
//----------------------------------------------------------------------

#include "systemc.h"
#include "decoder_2_to_4.h"
#include "driver.h"
#include "monitor.h"

// Main Function
int sc_main( int argc, char* argv[]){
  sc_signal <bool> en_i;
  sc_signal <sc_bv<2>> i_i;
  sc_signal <sc_bv<4>> y_o;

  decoder_2_to_4 decoder("decoder");
  driver drive("driver");
  monitor mon("monitor");
  decoder.en_i(en_i); decoder.i_i(i_i); decoder.y_o(y_o);
  drive.en_i(en_i); drive.i_i(i_i);
  mon.en_i(en_i); mon.i_i(i_i); mon.y_o(y_o);

  //Waveform
  sc_trace_file *Tf;
  Tf = sc_create_vcd_trace_file("traces");
  sc_trace(Tf, en_i, "en_i");
  sc_trace(Tf, i_i, "i_i");
  sc_trace(Tf, y_o, "y_o");
  sc_start(50,SC_NS);
  sc_close_vcd_trace_file(Tf);
  return 0;
}