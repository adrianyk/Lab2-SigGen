// copied over from task1 but need to modify to fit the new purpose

module counter #(
  parameter WIDTH = 8 
)(
  input  logic             clk,      // clock 
  input  logic             rst,      // reset 
  input  logic             en,       // enable
  // input  logic [WIDTH-1:0] incr,     // increment
  input  logic [WIDTH-1:0] offset,   // called offset instead of incr cuz in this context it makes more sense to call it offset cuz we're trying to offset one wave from another rather than changing the freq
  output logic [WIDTH-1:0] count1,   // count output 1
  output logic [WIDTH-1:0] count2    // count output 2
); 

always_ff @ (posedge clk) 
    if (rst) begin
      count1 <= {WIDTH{1'b0}};
      count2 <= {WIDTH{1'b0}}; // need to set both counts to 0 when rst=1
    end
    else if (en) begin
         count1 <= count1 + 1; // count1 will just keep adding 1
         count2 <= count1 + 1 + offset; // count2 will be offset from count1 (+offset or -offset will give same result)
         // notice for count2 it's count1 + 1 + incr and NOT count2 + 1 + incr
         // if I did count2 <= count2+1+incr then I wud get the effect of task1: 
         // I wud just be changing the freq of the second plot by turning the rotor instead what I shud be doing is 
         // offsetting the second plot from the first plot
         // (if dun have the +1 in count2 then count2 will always be 1 behind count1)
         // Try it out to see what happens
    end

endmodule
