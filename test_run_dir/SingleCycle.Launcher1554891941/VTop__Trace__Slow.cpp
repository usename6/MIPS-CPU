// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


//======================

void VTop::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&VTop::traceInit, &VTop::traceFull, &VTop::traceChg, this);
}
void VTop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VTop* t=(VTop*)userthis;
    VTop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VTop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VTop* t=(VTop*)userthis;
    VTop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void VTop::traceInitThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VTop::traceFullThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VTop::traceInitThis__1(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+51,"clock",-1);
	vcdp->declBit  (c+52,"reset",-1);
	vcdp->declBit  (c+53,"io_boot",-1);
	vcdp->declBit  (c+54,"io_test_im_wr",-1);
	vcdp->declBit  (c+55,"io_test_im_rd",-1);
	vcdp->declBus  (c+56,"io_test_im_addr",-1,31,0);
	vcdp->declBus  (c+57,"io_test_im_in",-1,31,0);
	vcdp->declBus  (c+58,"io_test_im_out",-1,31,0);
	vcdp->declBit  (c+59,"io_test_dm_wr",-1);
	vcdp->declBit  (c+60,"io_test_dm_rd",-1);
	vcdp->declBus  (c+61,"io_test_dm_addr",-1,31,0);
	vcdp->declBus  (c+62,"io_test_dm_in",-1,31,0);
	vcdp->declBus  (c+63,"io_test_dm_out",-1,31,0);
	vcdp->declBit  (c+51,"Top clock",-1);
	vcdp->declBit  (c+52,"Top reset",-1);
	vcdp->declBit  (c+53,"Top io_boot",-1);
	vcdp->declBit  (c+54,"Top io_test_im_wr",-1);
	vcdp->declBit  (c+55,"Top io_test_im_rd",-1);
	vcdp->declBus  (c+56,"Top io_test_im_addr",-1,31,0);
	vcdp->declBus  (c+57,"Top io_test_im_in",-1,31,0);
	vcdp->declBus  (c+58,"Top io_test_im_out",-1,31,0);
	vcdp->declBit  (c+59,"Top io_test_dm_wr",-1);
	vcdp->declBit  (c+60,"Top io_test_dm_rd",-1);
	vcdp->declBus  (c+61,"Top io_test_dm_addr",-1,31,0);
	vcdp->declBus  (c+62,"Top io_test_dm_in",-1,31,0);
	vcdp->declBus  (c+63,"Top io_test_dm_out",-1,31,0);
	vcdp->declBus  (c+70,"Top cpath_io_Inst",-1,31,0);
	vcdp->declBit  (c+53,"Top cpath_io_boot",-1);
	vcdp->declBus  (c+64,"Top cpath_io_ctl_PC_sel",-1,1,0);
	vcdp->declBit  (c+65,"Top cpath_io_ctl_ALUsrc",-1);
	vcdp->declBit  (c+51,"Top dpath_clock",-1);
	vcdp->declBit  (c+52,"Top dpath_reset",-1);
	vcdp->declBus  (c+14,"Top dpath_io_imem_addr",-1,31,0);
	vcdp->declBus  (c+1,"Top dpath_io_dmem_datIn",-1,31,0);
	vcdp->declBus  (c+64,"Top dpath_io_ctl_PC_sel",-1,1,0);
	vcdp->declBit  (c+65,"Top dpath_io_ctl_ALUsrc",-1);
	vcdp->declBit  (c+4,"Top dpath_io_dat_zero",-1);
	// Tracing: Top imm // Ignored: Wide memory > --trace-max-array ents at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:290
	// Tracing: Top _RAND_0 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:291
	vcdp->declBus  (c+7,"Top imm__T_108_data",-1,31,0);
	vcdp->declBus  (c+66,"Top imm__T_108_addr",-1,11,0);
	vcdp->declBus  (c+8,"Top imm__T_121_data",-1,31,0);
	vcdp->declBus  (c+66,"Top imm__T_121_addr",-1,11,0);
	vcdp->declBus  (c+2,"Top imm__T_133_data",-1,31,0);
	vcdp->declBus  (c+15,"Top imm__T_133_addr",-1,11,0);
	vcdp->declBus  (c+57,"Top imm__T_98_data",-1,31,0);
	vcdp->declBus  (c+66,"Top imm__T_98_addr",-1,11,0);
	vcdp->declBit  (c+9,"Top imm__T_98_mask",-1);
	vcdp->declBit  (c+9,"Top imm__T_98_en",-1);
	vcdp->declBit  (c+51,"Top dmm_clock",-1);
	vcdp->declBit  (c+10,"Top dmm_io_Write_En",-1);
	vcdp->declBit  (c+11,"Top dmm_io_Read_En",-1);
	vcdp->declBus  (c+62,"Top dmm_io_data_In",-1,31,0);
	vcdp->declBus  (c+67,"Top dmm_io_mem_addr",-1,31,0);
	vcdp->declBus  (c+12,"Top dmm_io_data_Out",-1,31,0);
	// Tracing: Top _T_95 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:308
	// Tracing: Top _T_96 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:309
	// Tracing: Top _T_97 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:310
	// Tracing: Top _T_102 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:311
	// Tracing: Top _T_107 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:312
	// Tracing: Top _T_114 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:313
	// Tracing: Top _T_118 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:314
	// Tracing: Top _T_120 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:315
	// Tracing: Top _GEN_14 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:316
	// Tracing: Top _T_123 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:317
	// Tracing: Top _GEN_16 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:318
	// Tracing: Top _GEN_17 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:319
	// Tracing: Top _GEN_18 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:320
	// Tracing: Top _T_129 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:321
	// Tracing: Top _T_131 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:322
	// Tracing: Top _T_132 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:323
	vcdp->declBus  (c+16,"Top clk_cnt",-1,31,0);
	// Tracing: Top _RAND_1 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:325
	// Tracing: Top _T_141 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:326
	// Tracing: Top _T_142 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:327
	vcdp->declBus  (c+70,"Top cpath io_Inst",-1,31,0);
	vcdp->declBit  (c+53,"Top cpath io_boot",-1);
	vcdp->declBus  (c+64,"Top cpath io_ctl_PC_sel",-1,1,0);
	vcdp->declBit  (c+65,"Top cpath io_ctl_ALUsrc",-1);
	// Tracing: Top cpath _T_23 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:20
	// Tracing: Top cpath _GEN_0 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:21
	// Tracing: Top cpath _GEN_5 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:22
	vcdp->declBit  (c+51,"Top dpath clock",-1);
	vcdp->declBit  (c+52,"Top dpath reset",-1);
	vcdp->declBus  (c+14,"Top dpath io_imem_addr",-1,31,0);
	vcdp->declBus  (c+1,"Top dpath io_dmem_datIn",-1,31,0);
	vcdp->declBus  (c+64,"Top dpath io_ctl_PC_sel",-1,1,0);
	vcdp->declBit  (c+65,"Top dpath io_ctl_ALUsrc",-1);
	vcdp->declBit  (c+4,"Top dpath io_dat_zero",-1);
	vcdp->declBus  (c+3,"Top dpath BusA",-1,31,0);
	vcdp->declBus  (c+1,"Top dpath BusB",-1,31,0);
	vcdp->declBus  (c+5,"Top dpath BusWr",-1,31,0);
	vcdp->declBus  (c+68,"Top dpath pc_next",-1,31,0);
	vcdp->declBus  (c+17,"Top dpath pc_plus4",-1,31,0);
	vcdp->declBus  (c+17,"Top dpath pc_br",-1,31,0);
	vcdp->declBus  (c+3,"Top dpath alu9_io_in1",-1,31,0);
	vcdp->declBus  (c+13,"Top dpath alu9_io_in2",-1,31,0);
	vcdp->declBus  (c+5,"Top dpath alu9_io_ALUout",-1,31,0);
	vcdp->declBit  (c+4,"Top dpath alu9_io_cmp_out",-1);
	vcdp->declBus  (c+14,"Top dpath pc_reg",-1,31,0);
	// Tracing: Top dpath _RAND_0 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:82
	{int i; for (i=0; i<32; i++) {
		vcdp->declBus  (c+18+i*1,"Top dpath RegFile",(i+0),31,0);}}
	// Tracing: Top dpath _RAND_1 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:84
	vcdp->declBus  (c+3,"Top dpath RegFile__T_51_data",-1,31,0);
	vcdp->declBus  (c+71,"Top dpath RegFile__T_51_addr",-1,4,0);
	vcdp->declBus  (c+1,"Top dpath RegFile__T_52_data",-1,31,0);
	vcdp->declBus  (c+71,"Top dpath RegFile__T_52_addr",-1,4,0);
	vcdp->declBus  (c+70,"Top dpath RegFile__T_49_data",-1,31,0);
	vcdp->declBus  (c+71,"Top dpath RegFile__T_49_addr",-1,4,0);
	vcdp->declBit  (c+72,"Top dpath RegFile__T_49_mask",-1);
	vcdp->declBit  (c+72,"Top dpath RegFile__T_49_en",-1);
	vcdp->declBus  (c+5,"Top dpath RegFile__T_55_data",-1,31,0);
	vcdp->declBus  (c+71,"Top dpath RegFile__T_55_addr",-1,4,0);
	vcdp->declBit  (c+73,"Top dpath RegFile__T_55_mask",-1);
	vcdp->declBit  (c+73,"Top dpath RegFile__T_55_en",-1);
	// Tracing: Top dpath _T_56 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:97
	// Tracing: Top dpath _T_69 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:98
	// Tracing: Top dpath _T_71 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:99
	vcdp->declBus  (c+50,"Top dpath j_target",-1,31,0);
	// Tracing: Top dpath _T_83 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:101
	// Tracing: Top dpath _T_84 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:102
	// Tracing: Top dpath _T_85 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:103
	// Tracing: Top dpath _T_86 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:104
	// Tracing: Top dpath _T_88 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:105
	// Tracing: Top dpath _T_89 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:106
	// Tracing: Top dpath _T_95 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:107
	// Tracing: Top dpath _T_97 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:108
	// Tracing: Top dpath _T_98 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:109
	// Tracing: Top dpath _T_100 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:110
	// Tracing: Top dpath _T_102 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:111
	// Tracing: Top dpath _T_104 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:112
	// Tracing: Top dpath _T_105 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:113
	// Tracing: Top dpath _T_106 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:114
	// Tracing: Top dpath _T_107 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:115
	// Tracing: Top dpath _T_108 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:116
	// Tracing: Top dpath _T_111 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:117
	vcdp->declBus  (c+3,"Top dpath alu9 io_in1",-1,31,0);
	vcdp->declBus  (c+13,"Top dpath alu9 io_in2",-1,31,0);
	vcdp->declBus  (c+5,"Top dpath alu9 io_ALUout",-1,31,0);
	vcdp->declBit  (c+4,"Top dpath alu9 io_cmp_out",-1);
	// Tracing: Top dpath alu9 _T_18 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:35
	// Tracing: Top dpath alu9 _T_19 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:36
	// Tracing: Top dpath alu9 _T_25 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:37
	vcdp->declBus  (c+6,"Top dpath alu9 adder_out",-1,31,0);
	vcdp->declBus  (c+5,"Top dpath alu9 logic_out",-1,31,0);
	// Tracing: Top dpath alu9 _T_34 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:40
	// Tracing: Top dpath alu9 _T_35 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:41
	// Tracing: Top dpath alu9 _T_36 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:42
	// Tracing: Top dpath alu9 _T_37 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:43
	// Tracing: Top dpath alu9 _GEN_1 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:44
	// Tracing: Top dpath alu9 _T_56 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:45
	// Tracing: Top dpath alu9 _GEN_15 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:46
	vcdp->declBit  (c+51,"Top dmm clock",-1);
	vcdp->declBit  (c+10,"Top dmm io_Write_En",-1);
	vcdp->declBit  (c+11,"Top dmm io_Read_En",-1);
	vcdp->declBus  (c+62,"Top dmm io_data_In",-1,31,0);
	vcdp->declBus  (c+67,"Top dmm io_mem_addr",-1,31,0);
	vcdp->declBus  (c+12,"Top dmm io_data_Out",-1,31,0);
	// Tracing: Top dmm mem // Ignored: Wide memory > --trace-max-array ents at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:218
	// Tracing: Top dmm _RAND_0 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:219
	vcdp->declBus  (c+12,"Top dmm mem__T_10_data",-1,31,0);
	vcdp->declBus  (c+69,"Top dmm mem__T_10_addr",-1,13,0);
	// Tracing: Top dmm _RAND_1 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:222
	vcdp->declBus  (c+62,"Top dmm mem__T_12_data",-1,31,0);
	vcdp->declBus  (c+69,"Top dmm mem__T_12_addr",-1,13,0);
	vcdp->declBit  (c+10,"Top dmm mem__T_12_mask",-1);
	vcdp->declBit  (c+10,"Top dmm mem__T_12_en",-1);
	// Tracing: Top dmm _T_9 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:227
	// Tracing: Top dmm _GEN_3 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:228
	// Tracing: Top dmm _T_11 // Ignored: Inlined leading underscore at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:229
    }
}

void VTop::traceFullThis__1(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_52_data),32);
	vcdp->fullBus  (c+2,(vlTOPp->Top__DOT__imm___05FT_133_data),32);
	vcdp->fullBus  (c+3,(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data),32);
	vcdp->fullBit  (c+4,((1U & (IData)((VL_ULL(3) 
					    & (((QData)((IData)(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data)) 
						+ (QData)((IData)(vlTOPp->Top__DOT__dpath__DOT___T_108))) 
					       >> 0x1fU))))));
	vcdp->fullBus  (c+5,((vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data 
			      & vlTOPp->Top__DOT__dpath__DOT___T_108)),32);
	vcdp->fullBus  (c+6,((vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data 
			      + vlTOPp->Top__DOT__dpath__DOT___T_108)),32);
	vcdp->fullBus  (c+7,(vlTOPp->Top__DOT__imm___05FT_108_data),32);
	vcdp->fullBus  (c+8,(vlTOPp->Top__DOT__imm___05FT_121_data),32);
	vcdp->fullBit  (c+9,(vlTOPp->Top__DOT___T_95));
	vcdp->fullBit  (c+10,((1U & (~ (IData)(vlTOPp->Top__DOT___T_123)))));
	vcdp->fullBit  (c+11,(vlTOPp->Top__DOT___T_123));
	vcdp->fullBus  (c+12,(vlTOPp->Top__DOT__dmm__DOT__mem___05FT_10_data),32);
	vcdp->fullBus  (c+13,(vlTOPp->Top__DOT__dpath__DOT___T_108),32);
	vcdp->fullBus  (c+14,(vlTOPp->Top__DOT__dpath__DOT__pc_reg),32);
	vcdp->fullBus  (c+15,((0xfffU & (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
					 >> 2U))),12);
	vcdp->fullBus  (c+16,(vlTOPp->Top__DOT__clk_cnt),32);
	vcdp->fullBus  (c+17,(((IData)(4U) + vlTOPp->Top__DOT__dpath__DOT__pc_reg)),32);
	vcdp->fullBus  (c+18,(vlTOPp->Top__DOT__dpath__DOT__RegFile[0]),32);
	vcdp->fullBus  (c+19,(vlTOPp->Top__DOT__dpath__DOT__RegFile[1]),32);
	vcdp->fullBus  (c+20,(vlTOPp->Top__DOT__dpath__DOT__RegFile[2]),32);
	vcdp->fullBus  (c+21,(vlTOPp->Top__DOT__dpath__DOT__RegFile[3]),32);
	vcdp->fullBus  (c+22,(vlTOPp->Top__DOT__dpath__DOT__RegFile[4]),32);
	vcdp->fullBus  (c+23,(vlTOPp->Top__DOT__dpath__DOT__RegFile[5]),32);
	vcdp->fullBus  (c+24,(vlTOPp->Top__DOT__dpath__DOT__RegFile[6]),32);
	vcdp->fullBus  (c+25,(vlTOPp->Top__DOT__dpath__DOT__RegFile[7]),32);
	vcdp->fullBus  (c+26,(vlTOPp->Top__DOT__dpath__DOT__RegFile[8]),32);
	vcdp->fullBus  (c+27,(vlTOPp->Top__DOT__dpath__DOT__RegFile[9]),32);
	vcdp->fullBus  (c+28,(vlTOPp->Top__DOT__dpath__DOT__RegFile[10]),32);
	vcdp->fullBus  (c+29,(vlTOPp->Top__DOT__dpath__DOT__RegFile[11]),32);
	vcdp->fullBus  (c+30,(vlTOPp->Top__DOT__dpath__DOT__RegFile[12]),32);
	vcdp->fullBus  (c+31,(vlTOPp->Top__DOT__dpath__DOT__RegFile[13]),32);
	vcdp->fullBus  (c+32,(vlTOPp->Top__DOT__dpath__DOT__RegFile[14]),32);
	vcdp->fullBus  (c+33,(vlTOPp->Top__DOT__dpath__DOT__RegFile[15]),32);
	vcdp->fullBus  (c+34,(vlTOPp->Top__DOT__dpath__DOT__RegFile[16]),32);
	vcdp->fullBus  (c+35,(vlTOPp->Top__DOT__dpath__DOT__RegFile[17]),32);
	vcdp->fullBus  (c+36,(vlTOPp->Top__DOT__dpath__DOT__RegFile[18]),32);
	vcdp->fullBus  (c+37,(vlTOPp->Top__DOT__dpath__DOT__RegFile[19]),32);
	vcdp->fullBus  (c+38,(vlTOPp->Top__DOT__dpath__DOT__RegFile[20]),32);
	vcdp->fullBus  (c+39,(vlTOPp->Top__DOT__dpath__DOT__RegFile[21]),32);
	vcdp->fullBus  (c+40,(vlTOPp->Top__DOT__dpath__DOT__RegFile[22]),32);
	vcdp->fullBus  (c+41,(vlTOPp->Top__DOT__dpath__DOT__RegFile[23]),32);
	vcdp->fullBus  (c+42,(vlTOPp->Top__DOT__dpath__DOT__RegFile[24]),32);
	vcdp->fullBus  (c+43,(vlTOPp->Top__DOT__dpath__DOT__RegFile[25]),32);
	vcdp->fullBus  (c+44,(vlTOPp->Top__DOT__dpath__DOT__RegFile[26]),32);
	vcdp->fullBus  (c+45,(vlTOPp->Top__DOT__dpath__DOT__RegFile[27]),32);
	vcdp->fullBus  (c+46,(vlTOPp->Top__DOT__dpath__DOT__RegFile[28]),32);
	vcdp->fullBus  (c+47,(vlTOPp->Top__DOT__dpath__DOT__RegFile[29]),32);
	vcdp->fullBus  (c+48,(vlTOPp->Top__DOT__dpath__DOT__RegFile[30]),32);
	vcdp->fullBus  (c+49,(vlTOPp->Top__DOT__dpath__DOT__RegFile[31]),32);
	vcdp->fullBus  (c+50,((0xf0000000U & vlTOPp->Top__DOT__dpath__DOT__pc_reg)),32);
	vcdp->fullBit  (c+51,(vlTOPp->clock));
	vcdp->fullBit  (c+52,(vlTOPp->reset));
	vcdp->fullBit  (c+53,(vlTOPp->io_boot));
	vcdp->fullBit  (c+54,(vlTOPp->io_test_im_wr));
	vcdp->fullBit  (c+55,(vlTOPp->io_test_im_rd));
	vcdp->fullBus  (c+56,(vlTOPp->io_test_im_addr),32);
	vcdp->fullBus  (c+57,(vlTOPp->io_test_im_in),32);
	vcdp->fullBus  (c+58,(vlTOPp->io_test_im_out),32);
	vcdp->fullBit  (c+59,(vlTOPp->io_test_dm_wr));
	vcdp->fullBit  (c+60,(vlTOPp->io_test_dm_rd));
	vcdp->fullBus  (c+61,(vlTOPp->io_test_dm_addr),32);
	vcdp->fullBus  (c+62,(vlTOPp->io_test_dm_in),32);
	vcdp->fullBus  (c+63,(vlTOPp->io_test_dm_out),32);
	vcdp->fullBus  (c+64,(((IData)(vlTOPp->io_boot)
			        ? 0U : 1U)),2);
	vcdp->fullBit  (c+65,(vlTOPp->io_boot));
	vcdp->fullBus  (c+66,((0xfffU & (vlTOPp->io_test_im_addr 
					 >> 2U))),12);
	vcdp->fullBus  (c+67,((0x3fffffffU & (vlTOPp->io_test_dm_addr 
					      >> 2U))),32);
	vcdp->fullBus  (c+68,(((1U == ((IData)(vlTOPp->io_boot)
				        ? 0U : 1U))
			        ? ((IData)(4U) + vlTOPp->Top__DOT__dpath__DOT__pc_reg)
			        : (((2U == ((IData)(vlTOPp->io_boot)
					     ? 0U : 1U)) 
				    & (IData)((VL_ULL(3) 
					       & (((QData)((IData)(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data)) 
						   + (QData)((IData)(vlTOPp->Top__DOT__dpath__DOT___T_108))) 
						  >> 0x1fU))))
				    ? ((IData)(4U) 
				       + vlTOPp->Top__DOT__dpath__DOT__pc_reg)
				    : ((3U == ((IData)(vlTOPp->io_boot)
					        ? 0U
					        : 1U))
				        ? (0xf0000000U 
					   & vlTOPp->Top__DOT__dpath__DOT__pc_reg)
				        : ((0U == ((IData)(vlTOPp->io_boot)
						    ? 0U
						    : 1U))
					    ? 0U : 
					   ((IData)(4U) 
					    + vlTOPp->Top__DOT__dpath__DOT__pc_reg)))))),32);
	vcdp->fullBus  (c+69,((0x3fffU & (vlTOPp->io_test_dm_addr 
					  >> 2U))),14);
	vcdp->fullBus  (c+70,(0U),32);
	vcdp->fullBus  (c+71,(0U),5);
	vcdp->fullBit  (c+72,(1U));
	vcdp->fullBit  (c+73,(0U));
    }
}
