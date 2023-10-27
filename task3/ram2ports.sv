// 512 x 8 bit dual-port RAM component

// from lecture 4 slide 25

// file name and module name HAS TO BE THE SAME

module ram2ports #(
    parameter   ADDRESS_WIDTH = 9, // 9 cuz this is a 512 x 8 bit RAM meaning there'll be 512 addresses so need 2^9 to access all of them
                DATA_WIDTH = 8
)(
    input logic                      clk,
    input logic                      write_en,
    input logic                      read_en,
    input logic  [ADDRESS_WIDTH-1:0] write_addr, // prev we had two ports (in the ROM) both were read ports, now we're just making one of them a write port and the other stays a read port
    input logic  [ADDRESS_WIDTH-1:0] read_addr,
    input logic  [DATA_WIDTH-1:0]    din,
    output logic [DATA_WIDTH-1:0]    dout
);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

always_ff @(posedge clk) begin
    if (write_en) ram_array[write_addr] <= din; 
    // if write_en is high, we wanna write the data we receive (din) to the location in the RAM with address value write_addr

    else if (read_en) dout <= ram_array[read_addr]; 
    // if read_en is high, we wanna read from the location in RAM with value read_addr and output it (dout)
end

endmodule
