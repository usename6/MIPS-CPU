// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


//======================

void VALU::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&VALU::traceInit, &VALU::traceFull, &VALU::traceChg, this);
}
void VALU::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VALU* t=(VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VALU::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VALU* t=(VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void VALU::traceInitThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VALU::traceFullThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VALU::traceInitThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+1,"clock",-1);
	vcdp->declBit  (c+2,"reset",-1);
	vcdp->declBus  (c+3,"io_a",-1,31,0);
	vcdp->declBus  (c+4,"io_b",-1,31,0);
	vcdp->declBus  (c+5,"io_op",-1,3,0);
	vcdp->declBus  (c+6,"io_shamt",-1,4,0);
	vcdp->declBus  (c+7,"io_out",-1,31,0);
	vcdp->declBit  (c+8,"io_zero",-1);
	vcdp->declBit  (c+1,"ALU clock",-1);
	vcdp->declBit  (c+2,"ALU reset",-1);
	vcdp->declBus  (c+3,"ALU io_a",-1,31,0);
	vcdp->declBus  (c+4,"ALU io_b",-1,31,0);
	vcdp->declBus  (c+5,"ALU io_op",-1,3,0);
	vcdp->declBus  (c+6,"ALU io_shamt",-1,4,0);
	vcdp->declBus  (c+7,"ALU io_out",-1,31,0);
	vcdp->declBit  (c+8,"ALU io_zero",-1);
	// Tracing: ALU _T_9 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:24
	// Tracing: ALU _T_10 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:25
	// Tracing: ALU _T_12 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:26
	// Tracing: ALU _T_13 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:27
	// Tracing: ALU _T_15 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:28
	// Tracing: ALU _T_17 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:29
	// Tracing: ALU _T_19 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:30
	// Tracing: ALU _T_20 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:31
	// Tracing: ALU _T_22 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:32
	// Tracing: ALU _T_23 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:33
	// Tracing: ALU _T_24 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:34
	// Tracing: ALU _T_26 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:35
	// Tracing: ALU _T_27 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:36
	// Tracing: ALU _T_28 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:37
	// Tracing: ALU _T_29 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:38
	// Tracing: ALU _T_31 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:39
	// Tracing: ALU _GEN_10 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:40
	// Tracing: ALU _T_32 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:41
	// Tracing: ALU _T_34 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:42
	// Tracing: ALU _T_35 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:43
	// Tracing: ALU _T_37 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:44
	// Tracing: ALU _T_38 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:45
	// Tracing: ALU _T_40 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:46
	// Tracing: ALU _T_42 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:47
	// Tracing: ALU _GEN_0 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:48
	// Tracing: ALU _GEN_1 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:49
	// Tracing: ALU _GEN_2 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:50
	// Tracing: ALU _GEN_3 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:51
	// Tracing: ALU _GEN_4 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:52
	// Tracing: ALU _GEN_5 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:53
	// Tracing: ALU _GEN_6 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:54
	// Tracing: ALU _GEN_7 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:55
	// Tracing: ALU _GEN_8 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:56
	// Tracing: ALU _GEN_9 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:57
	// Tracing: ALU _T_48 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/ALU.v:58
    }
}

void VALU::traceFullThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->clock));
	vcdp->fullBit  (c+2,(vlTOPp->reset));
	vcdp->fullBus  (c+3,(vlTOPp->io_a),32);
	vcdp->fullBus  (c+4,(vlTOPp->io_b),32);
	vcdp->fullBus  (c+5,(vlTOPp->io_op),4);
	vcdp->fullBus  (c+6,(vlTOPp->io_shamt),5);
	vcdp->fullBus  (c+7,(vlTOPp->io_out),32);
	vcdp->fullBit  (c+8,(vlTOPp->io_zero));
    }
}
