// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsigdelay__Syms.h"


VL_ATTR_COLD void Vsigdelay___024root__trace_init_sub__TOP__0(Vsigdelay___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"en", false,-1);
    tracep->declBus(c+4,"offset", false,-1, 7,0);
    tracep->declBit(c+5,"write_en", false,-1);
    tracep->declBit(c+6,"read_en", false,-1);
    tracep->declBit(c+7,"mic_input", false,-1);
    tracep->declBus(c+8,"dout", false,-1, 7,0);
    tracep->pushNamePrefix("sigdelay ");
    tracep->declBus(c+12,"A_WIDTH", false,-1, 31,0);
    tracep->declBus(c+13,"D_WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"en", false,-1);
    tracep->declBus(c+4,"offset", false,-1, 7,0);
    tracep->declBit(c+5,"write_en", false,-1);
    tracep->declBit(c+6,"read_en", false,-1);
    tracep->declBit(c+7,"mic_input", false,-1);
    tracep->declBus(c+8,"dout", false,-1, 7,0);
    tracep->declBus(c+9,"write_addr", false,-1, 8,0);
    tracep->declBus(c+10,"read_addr", false,-1, 8,0);
    tracep->pushNamePrefix("addrCounter ");
    tracep->declBus(c+12,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"en", false,-1);
    tracep->declBus(c+4,"offset", false,-1, 7,0);
    tracep->declBus(c+9,"count1", false,-1, 8,0);
    tracep->declBus(c+10,"count2", false,-1, 8,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("micRAM ");
    tracep->declBus(c+12,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+13,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+5,"write_en", false,-1);
    tracep->declBit(c+6,"read_en", false,-1);
    tracep->declBus(c+9,"write_addr", false,-1, 8,0);
    tracep->declBus(c+10,"read_addr", false,-1, 8,0);
    tracep->declBus(c+11,"din", false,-1, 7,0);
    tracep->declBus(c+8,"dout", false,-1, 7,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vsigdelay___024root__trace_init_top(Vsigdelay___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root__trace_init_top\n"); );
    // Body
    Vsigdelay___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsigdelay___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsigdelay___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsigdelay___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsigdelay___024root__trace_register(Vsigdelay___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vsigdelay___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vsigdelay___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vsigdelay___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsigdelay___024root__trace_full_sub_0(Vsigdelay___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsigdelay___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root__trace_full_top_0\n"); );
    // Init
    Vsigdelay___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsigdelay___024root*>(voidSelf);
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsigdelay___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsigdelay___024root__trace_full_sub_0(Vsigdelay___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->rst));
    bufp->fullBit(oldp+3,(vlSelf->en));
    bufp->fullCData(oldp+4,(vlSelf->offset),8);
    bufp->fullBit(oldp+5,(vlSelf->write_en));
    bufp->fullBit(oldp+6,(vlSelf->read_en));
    bufp->fullBit(oldp+7,(vlSelf->mic_input));
    bufp->fullCData(oldp+8,(vlSelf->dout),8);
    bufp->fullSData(oldp+9,(vlSelf->sigdelay__DOT__write_addr),9);
    bufp->fullSData(oldp+10,(vlSelf->sigdelay__DOT__read_addr),9);
    bufp->fullCData(oldp+11,(vlSelf->mic_input),8);
    bufp->fullIData(oldp+12,(9U),32);
    bufp->fullIData(oldp+13,(8U),32);
}
