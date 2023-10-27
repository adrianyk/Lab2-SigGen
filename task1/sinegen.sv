// from lecture 4 slide 22

module sinegen #(
        parameter   A_WIDTH = 8,
                    D_WIDTH = 8
)(
    // interface signals
    input  logic               clk,    // clock
    input  logic               rst,    // reset
    input  logic               en ,    // enable
    input  logic [D_WIDTH-1:0] incr,   // increment for address counter
    output logic [D_WIDTH-1:0] dout    // output data
);

    logic   [A_WIDTH-1:0]      address;    // interconnect wire

counter addrCounter (
    .clk (clk),     // all the .clk and .rst and .en etc are inputs to/output of the counter, it's like saying counter.clk = clk where the clk in counter.clk is the input to the counter and clk is the signal from this top sv file that we're passing to counter
    .rst (rst),
    .en (en),
    .incr (incr),
    .count (address)
);

rom sineRom (
    .clk (clk),
    .addr (address),
    .dout (dout)
);

endmodule
