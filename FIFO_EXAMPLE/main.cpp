//----------------------------------------------------------------------
// Testbench for FIFO example
//----------------------------------------------------------------------

#include "systemc.h"
#include "fifo_example.h"

int sc_main(int argc, char *argv[]){
  
  // Instantiate FIFO
  fifo_example fifo_inst("fifo_example");
  sc_start(10, SC_NS);
  
  return 0;
}
