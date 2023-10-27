#include "Vsinegen.h"  // cuz now top file is called sinegen
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp" // include vbuddy code

int main(int argc, char **argv, char **env) {
    int cyc_num; // cycle number/clock count
    int MAX_CYC_NUM = 1000000; // maximum cycle number/clock count
    int clk;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vsinegen* sinegen = new Vsinegen; // cuz now the instance of the device we're running is Vsinegen (sinegen.sv)

    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    sinegen->trace (tfp, 99);
    tfp->open ("sinegen.vcd");

    // init Vbuddy
    if (vbdOpen() != 1) return (-1);
    vbdHeader("Lab 2 Task 1: Sinegen");    

    // initialise simulation inputs
    sinegen->clk = 1;
    sinegen->rst = 0;
    sinegen->en = 1;
    // sinegen->incr = 1; // for task1 non-challenge part, sets incr to const 1

    // run simulation for however many clock cycles
    for (cyc_num=0; cyc_num<MAX_CYC_NUM; cyc_num++) { 
        
        //toggle clock
        for (clk=0; clk<2; clk++) {
            tfp->dump (2*cyc_num+clk);  
            sinegen->clk = !sinegen->clk; 
            sinegen->eval ();
        }

        // ++++ Send count value to Vbuddy

        // using plot display (plots the result which is the ROM output and shows the plot)
        vbdPlot(int (sinegen->dout), 0, 255);
        vbdCycle(cyc_num); // prints cycle count
        
        vbdCycle(cyc_num+1);
        // ---- end of Vbuddy output section

        // test yourself challenge
        sinegen->incr = vbdValue();
    
        // new way of terminating the program:
        // either simulation finished, or 'q' is pressed
        if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
            exit(0);                // ... exit if finish OR 'q' pressed
        }

    vbdClose();
    tfp->close();
    exit(0);
}