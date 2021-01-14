// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


//======================

void VTop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VTop* t=(VTop*)userthis;
    VTop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VTop::traceChgThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 2U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VTop::traceChgThis__2(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_52_data),32);
	vcdp->chgBus  (c+2,(vlTOPp->Top__DOT__imm___05FT_133_data),32);
	vcdp->chgBus  (c+3,(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data),32);
    }
}

void VTop::traceChgThis__3(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+4,((1U & (IData)((VL_ULL(3) 
					   & (((QData)((IData)(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data)) 
					       + (QData)((IData)(vlTOPp->Top__DOT__dpath__DOT___T_108))) 
					      >> 0x1fU))))));
	vcdp->chgBus  (c+5,((vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data 
			     & vlTOPp->Top__DOT__dpath__DOT___T_108)),32);
	vcdp->chgBus  (c+6,((vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data 
			     + vlTOPp->Top__DOT__dpath__DOT___T_108)),32);
    }
}

void VTop::traceChgThis__4(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+7,(vlTOPp->Top__DOT__imm___05FT_108_data),32);
	vcdp->chgBus  (c+8,(vlTOPp->Top__DOT__imm___05FT_121_data),32);
	vcdp->chgBit  (c+9,(vlTOPp->Top__DOT___T_95));
	vcdp->chgBit  (c+10,((1U & (~ (IData)(vlTOPp->Top__DOT___T_123)))));
	vcdp->chgBit  (c+11,(vlTOPp->Top__DOT___T_123));
	vcdp->chgBus  (c+12,(vlTOPp->Top__DOT__dmm__DOT__mem___05FT_10_data),32);
	vcdp->chgBus  (c+13,(vlTOPp->Top__DOT__dpath__DOT___T_108),32);
    }
}

void VTop::traceChgThis__5(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+14,(vlTOPp->Top__DOT__dpath__DOT__pc_reg),32);
	vcdp->chgBus  (c+15,((0xfffU & (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
					>> 2U))),12);
	vcdp->chgBus  (c+16,(vlTOPp->Top__DOT__clk_cnt),32);
	vcdp->chgBus  (c+17,(((IData)(4U) + vlTOPp->Top__DOT__dpath__DOT__pc_reg)),32);
	vcdp->chgBus  (c+18,(vlTOPp->Top__DOT__dpath__DOT__RegFile[0]),32);
	vcdp->chgBus  (c+19,(vlTOPp->Top__DOT__dpath__DOT__RegFile[1]),32);
	vcdp->chgBus  (c+20,(vlTOPp->Top__DOT__dpath__DOT__RegFile[2]),32);
	vcdp->chgBus  (c+21,(vlTOPp->Top__DOT__dpath__DOT__RegFile[3]),32);
	vcdp->chgBus  (c+22,(vlTOPp->Top__DOT__dpath__DOT__RegFile[4]),32);
	vcdp->chgBus  (c+23,(vlTOPp->Top__DOT__dpath__DOT__RegFile[5]),32);
	vcdp->chgBus  (c+24,(vlTOPp->Top__DOT__dpath__DOT__RegFile[6]),32);
	vcdp->chgBus  (c+25,(vlTOPp->Top__DOT__dpath__DOT__RegFile[7]),32);
	vcdp->chgBus  (c+26,(vlTOPp->Top__DOT__dpath__DOT__RegFile[8]),32);
	vcdp->chgBus  (c+27,(vlTOPp->Top__DOT__dpath__DOT__RegFile[9]),32);
	vcdp->chgBus  (c+28,(vlTOPp->Top__DOT__dpath__DOT__RegFile[10]),32);
	vcdp->chgBus  (c+29,(vlTOPp->Top__DOT__dpath__DOT__RegFile[11]),32);
	vcdp->chgBus  (c+30,(vlTOPp->Top__DOT__dpath__DOT__RegFile[12]),32);
	vcdp->chgBus  (c+31,(vlTOPp->Top__DOT__dpath__DOT__RegFile[13]),32);
	vcdp->chgBus  (c+32,(vlTOPp->Top__DOT__dpath__DOT__RegFile[14]),32);
	vcdp->chgBus  (c+33,(vlTOPp->Top__DOT__dpath__DOT__RegFile[15]),32);
	vcdp->chgBus  (c+34,(vlTOPp->Top__DOT__dpath__DOT__RegFile[16]),32);
	vcdp->chgBus  (c+35,(vlTOPp->Top__DOT__dpath__DOT__RegFile[17]),32);
	vcdp->chgBus  (c+36,(vlTOPp->Top__DOT__dpath__DOT__RegFile[18]),32);
	vcdp->chgBus  (c+37,(vlTOPp->Top__DOT__dpath__DOT__RegFile[19]),32);
	vcdp->chgBus  (c+38,(vlTOPp->Top__DOT__dpath__DOT__RegFile[20]),32);
	vcdp->chgBus  (c+39,(vlTOPp->Top__DOT__dpath__DOT__RegFile[21]),32);
	vcdp->chgBus  (c+40,(vlTOPp->Top__DOT__dpath__DOT__RegFile[22]),32);
	vcdp->chgBus  (c+41,(vlTOPp->Top__DOT__dpath__DOT__RegFile[23]),32);
	vcdp->chgBus  (c+42,(vlTOPp->Top__DOT__dpath__DOT__RegFile[24]),32);
	vcdp->chgBus  (c+43,(vlTOPp->Top__DOT__dpath__DOT__RegFile[25]),32);
	vcdp->chgBus  (c+44,(vlTOPp->Top__DOT__dpath__DOT__RegFile[26]),32);
	vcdp->chgBus  (c+45,(vlTOPp->Top__DOT__dpath__DOT__RegFile[27]),32);
	vcdp->chgBus  (c+46,(vlTOPp->Top__DOT__dpath__DOT__RegFile[28]),32);
	vcdp->chgBus  (c+47,(vlTOPp->Top__DOT__dpath__DOT__RegFile[29]),32);
	vcdp->chgBus  (c+48,(vlTOPp->Top__DOT__dpath__DOT__RegFile[30]),32);
	vcdp->chgBus  (c+49,(vlTOPp->Top__DOT__dpath__DOT__RegFile[31]),32);
	vcdp->chgBus  (c+50,((0xf0000000U & vlTOPp->Top__DOT__dpath__DOT__pc_reg)),32);
    }
}

void VTop::traceChgThis__6(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+51,(vlTOPp->clock));
	vcdp->chgBit  (c+52,(vlTOPp->reset));
	vcdp->chgBit  (c+53,(vlTOPp->io_boot));
	vcdp->chgBit  (c+54,(vlTOPp->io_test_im_wr));
	vcdp->chgBit  (c+55,(vlTOPp->io_test_im_rd));
	vcdp->chgBus  (c+56,(vlTOPp->io_test_im_addr),32);
	vcdp->chgBus  (c+57,(vlTOPp->io_test_im_in),32);
	vcdp->chgBus  (c+58,(vlTOPp->io_test_im_out),32);
	vcdp->chgBit  (c+59,(vlTOPp->io_test_dm_wr));
	vcdp->chgBit  (c+60,(vlTOPp->io_test_dm_rd));
	vcdp->chgBus  (c+61,(vlTOPp->io_test_dm_addr),32);
	vcdp->chgBus  (c+62,(vlTOPp->io_test_dm_in),32);
	vcdp->chgBus  (c+63,(vlTOPp->io_test_dm_out),32);
	vcdp->chgBus  (c+64,(((IData)(vlTOPp->io_boot)
			       ? 0U : 1U)),2);
	vcdp->chgBit  (c+65,(vlTOPp->io_boot));
	vcdp->chgBus  (c+66,((0xfffU & (vlTOPp->io_test_im_addr 
					>> 2U))),12);
	vcdp->chgBus  (c+67,((0x3fffffffU & (vlTOPp->io_test_dm_addr 
					     >> 2U))),32);
	vcdp->chgBus  (c+68,(((1U == ((IData)(vlTOPp->io_boot)
				       ? 0U : 1U)) ? 
			      ((IData)(4U) + vlTOPp->Top__DOT__dpath__DOT__pc_reg)
			       : (((2U == ((IData)(vlTOPp->io_boot)
					    ? 0U : 1U)) 
				   & (IData)((VL_ULL(3) 
					      & (((QData)((IData)(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data)) 
						  + (QData)((IData)(vlTOPp->Top__DOT__dpath__DOT___T_108))) 
						 >> 0x1fU))))
				   ? ((IData)(4U) + vlTOPp->Top__DOT__dpath__DOT__pc_reg)
				   : ((3U == ((IData)(vlTOPp->io_boot)
					       ? 0U
					       : 1U))
				       ? (0xf0000000U 
					  & vlTOPp->Top__DOT__dpath__DOT__pc_reg)
				       : ((0U == ((IData)(vlTOPp->io_boot)
						   ? 0U
						   : 1U))
					   ? 0U : ((IData)(4U) 
						   + vlTOPp->Top__DOT__dpath__DOT__pc_reg)))))),32);
	vcdp->chgBus  (c+69,((0x3fffU & (vlTOPp->io_test_dm_addr 
					 >> 2U))),14);
    }
}
