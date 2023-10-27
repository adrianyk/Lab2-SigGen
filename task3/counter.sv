// copied over from task2 but need to modify to fit the new purpose

module counter #(
  parameter WIDTH = 9 // we need the counter to be 9 bits cuz need to count up to 512
)(
  input  logic             clk,      // clock 
  input  logic             rst,      // reset 
  input  logic             en,       // enable
  input  logic [WIDTH-2:0] offset,   // offset is still 8 bits cuz Vbuddy is only 8 bits
  output logic [WIDTH-1:0] count1,   // count output 1
  output logic [WIDTH-1:0] count2    // count output 2
); 

always_ff @ (posedge clk) 
    if (rst) begin
      count1 <= {WIDTH{1'b0}};
      count2 <= {WIDTH{1'b0}};
    end
    else if (en) begin
         count1 <= count1 + 1;
         count2 <= count1 + 1 + offset; 
    end

endmodule
