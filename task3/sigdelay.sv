module sigdelay #(
    parameter A_WIDTH = 9, // max address width is 9
              D_WIDTH = 8  // max data width is still 8 cuz Vbuddy is only 8 bits max
)(
    // interface signals
    input logic clk,
    input logic rst,
    input logic en,
    input logic [D_WIDTH-1:0] offset,
    input logic write_en,
    input logic read_en,
    input logic mic_input, // need to feed the mic data into the component
    output logic [D_WIDTH-1:0] dout
);

    logic   [A_WIDTH-1:0] write_addr;
    logic   [A_WIDTH-1:0] read_addr;

counter addrCounter (
    .clk (clk),
    .rst (rst), 
    .en (en),
    .offset (offset),
    .count1 (write_addr), 
    .count2 (read_addr)
);

ram2ports micRAM (
    .clk (clk),
    .read_en (read_en),
    .write_en (write_en),
    .write_addr (write_addr), // sending address1 signal to input addr1 of rom2ports
    .read_addr (read_addr), // sending address2 signal to input addr2 of rom2ports
    .din (mic_input),
    .dout (dout)
);

endmodule
