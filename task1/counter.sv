// copied over from lab1 but need to modify to fit the new purpose

module counter #(
  parameter WIDTH = 8 // still gonna use an 8 bit counter so this is fine
)(
  // according to the top sv file sinegen.sv we need 5 interface signals which are:
  input  logic             clk,      // clock 
  input  logic             rst,      // reset 
  input  logic             en,       // enable
//input  logic             incr,     // mistake: I forgot to set incr to an 8bit signal, rn incr is just 1 bit, so no matter what incr actually is, it can only be 1 i.e. even if incr shud actually be 2, it will only stay at 1
  input  logic [WIDTH-1:0] incr,     // increment
  output logic [WIDTH-1:0] count     // count output

  // the picture of how the circuit looks like in slide 22 lec4 also tells u that the counter component has 5 signals (4 inputs incr, rst, en, clk and 1 output: count)
);

always_ff @ (posedge clk) 
    if (rst) count <= {WIDTH{1'b0}};
 // else     count <= count + {{WIDTH-1{1'b0}}, incr}; // changed the en to incr cuz this time incr determines how much the counter counts up
    else     count <= count + incr; // since incr is ady an 8 bit number, no need to concatenate with a string of zeros {WIDTH-1{1'b0}}
endmodule
