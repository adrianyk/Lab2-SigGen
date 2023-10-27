// from lecture 4 slide 22

module sinegen #(
        parameter   A_WIDTH = 8,
                    D_WIDTH = 8
)(
    // interface signals (now the sinewave generator has two outputs cuz the rom now has two outputs)
    input  logic               clk,    // clock
    input  logic               rst,    // reset
    input  logic               en ,    // enable
    input  logic [D_WIDTH-1:0] offset, // called offset instead of incr cuz makes more sense in this context
    output logic [D_WIDTH-1:0] dout1,  // output data 1
    output logic [D_WIDTH-1:0] dout2   // output data 2
);

    logic   [A_WIDTH-1:0]      address1;    // interconnect wire
    logic   [A_WIDTH-1:0]      address2;    // interconnect wire

counter addrCounter (
    .clk (clk),  // sending clk signal to the input clk of counter
    .rst (rst),  // sending rst signal to the input rst of counter
    .en (en),
    .offset (offset),
    .count1 (address1), // assigning count1 to be address1 (address1 = count1)
    .count2 (address2)  // assigning count2 to be address2 (address2 = count2)
);

rom2ports sineRom (
    .clk (clk),
    .addr1 (address1), // sending address1 signal to input addr1 of rom2ports
    .addr2 (address2), // sending address2 signal to input addr2 of rom2ports
    .dout1 (dout1),
    .dout2 (dout2)
);

endmodule
