//----------------------------------------------------------------------
// BCD Counter with load
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(bcd_counter){
  
  // Port DEcleration
  sc_in  <bool>     clk_i;
  sc_in  <bool>     rst_i;
  sc_in  <bool>     enable_i;
  sc_in  <bool>     load_i;
  sc_in  <sc_uint<4>> data_i;
  sc_out <sc_uint<4>> count_o;

  // Counter Logic
  void counter_process(){
    if(rst_i.read()){
    // When Reset is applied
      count_o.write(0);
    }
    else{
      if(enable_i.read()){
        // When Enabled
        if(load_i.read()){
        // When load is high
          count_o.write(data_i.read());
        }
        else if(count_o.read() == 9){
        // Clear when count reaches 9
          count_o.write(0);
        }
        else{
        // Increment count
          count_o.write(count_o.read() + 1);
        }
      }
      else{
        count_o.write(count_o.read());
      }
    }
  }

  // Constructor
  SC_CTOR(bcd_counter){
    SC_METHOD(counter_process);
    sensitive <<clk_i.pos();
  }

};