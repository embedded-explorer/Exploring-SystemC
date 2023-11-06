//----------------------------------------------------------------------
// Melay FSM to detect 101 overlapping sequence
//----------------------------------------------------------------------

#include "systemc.h"

SC_MODULE(melay_fsm_101){
  
  // Port Decleration
  sc_in<bool>  clk_i;
  sc_in<bool>  rst_i;
  sc_in<bool>  d_i;
  sc_out<bool> y_o;
  
  sc_uint<2> curr_state;
  sc_unit<2> next_state;

  // Sequential State Change Logic
  void state_change(){
	if(rst.read()){
	  curr_state = 0;
	}
	else{
	  curr_state = next_state;
	}
  }
  
  // Combinational Next State Decoder and Output Logic
  void next_state_decoder(){
	switch(curr_state){
	  case 0  :
	    if(d_i.read()){
		// Move to next state when 1 is received
		  next_state = 1;
		  y_o = 0;
		}
		else{
		// Stay in same state until 1 is received
		  next_state = 0;
		  y_o = 0;
		}
	  break;
	  
	  case 1  :
	    if(!d_i.read()){
		// Move to next state when 0 is received
		  next_state = 2;
		  y_o = 0;
		}
		else{
		// Stay in same state until 0 is received
		  next_state = 1;
		  y_o = 0;
		}
	  break;
	  
	  case 2  :
	    if(d_i.read()){
		// Move to S1 if 1 is received, to detect next 1->01
		  next_state = 1;
		  y_o = 1;
		}
		else{
		// Move to S0 if 0 is received, detect fresh 101
		  next_state = 0;
		  y_o = 0;
		}
	  break;
	  
	  default :
		next_state = 0;
		y_o = 0;
	}
  }
  
  // Constructor
  SC_CONT(melay_fsm_101){
	// Sequential state change logic with synchronous reset
	SC_METHOD(state_change);
	sensitive <<clk_i.pos();
	// Combinational next state decoder logic
	SC_METHOD(next_state_decoder);
	sensitive <<d_i <<curr_state;
  }
  
};