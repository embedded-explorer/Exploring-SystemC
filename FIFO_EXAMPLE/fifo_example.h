//----------------------------------------------------------------------
// System Verilog FIFO Example
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(fifo_example){
  
  // Declare FIFO
  sc_fifo <int> packet_fifo;
  
  // Process for writing FIFO every 2ns
  void fifo_write(){
    int val;
    while(1){
      wait(2, SC_NS);
      val++;
      packet_fifo.write(val);
      cout << sc_time_stamp() \
           << " : WROTE : " << val \
           << " : AVAILABLE FREE SLOTS : " \
           << packet_fifo.num_free() << endl;
    }
  }
  
  // Process for reading FIFO every 3ns
  void fifo_read(){
    int val;
    while(1){
      wait(3, SC_NS);
      packet_fifo.read(val);
      cout << sc_time_stamp() \
           << " : READ : " << val \
           << " : OCCUPIED SLOTS : " \
           << packet_fifo.num_available() << endl;
    }
  }
  
  // Constructor (override FIFO SIZE to 25)
  SC_CTOR(fifo_example):packet_fifo(25){
    SC_THREAD(fifo_write);
    SC_THREAD(fifo_read);
  }

};