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
	vcdp->chgBus  (c+1,(vlTOPp->Top__DOT__imm___05FT_46_data),32);
    }
}

void VTop::traceChgThis__3(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+2,((((3U != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
			      & (~ (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40)))
			      ? ((IData)(4U) + vlTOPp->Top__DOT__dpath__DOT__pc_reg)
			      : (((((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
				    >> 3U) & (3U != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))) 
				  & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40))
				  ? ((IData)(4U) + 
				     (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
				      + ((((0x8000U 
					    & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
					    ? 0x7fffU
					    : 0U) << 0x11U) 
					 | ((0x1fffcU 
					     & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_161) 
						<< 2U)) 
					    | ((0x8000U 
						& (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
					        ? 3U
					        : 0U)))))
				  : ((((~ ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
					   >> 3U)) 
				       & (3U != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))) 
				      & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40))
				      ? ((0xf0000000U 
					  & vlTOPp->Top__DOT__dpath__DOT__pc_reg) 
					 | (0xffffffcU 
					    & (((0x10U 
						 & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
						 ? vlTOPp->Top__DOT___GEN_27
						 : 0U) 
					       << 2U)))
				      : (((3U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
					  & (~ (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40)))
					  ? 0U : ((IData)(4U) 
						  + vlTOPp->Top__DOT__dpath__DOT__pc_reg)))))),32);
	vcdp->chgBus  (c+3,(((IData)(4U) + (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
					    + ((((0x8000U 
						  & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
						  ? 0x7fffU
						  : 0U) 
						<< 0x11U) 
					       | ((0x1fffcU 
						   & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_161) 
						      << 2U)) 
						  | ((0x8000U 
						      & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
						      ? 3U
						      : 0U)))))),32);
	vcdp->chgBus  (c+4,(((0xf0000000U & vlTOPp->Top__DOT__dpath__DOT__pc_reg) 
			     | (0xffffffcU & (((0x10U 
						& (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
					        ? vlTOPp->Top__DOT___GEN_27
					        : 0U) 
					      << 2U)))),32);
    }
}

void VTop::traceChgThis__4(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+5,(vlTOPp->Top__DOT___GEN_27),32);
	vcdp->chgBit  (c+6,((1U & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
				   >> 6U))));
	vcdp->chgBit  (c+7,((0x7ffU != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))));
	vcdp->chgBit  (c+8,(vlTOPp->Top__DOT__cpath__DOT___T_40));
	vcdp->chgBit  (c+9,((1U & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
				   >> 7U))));
	vcdp->chgBit  (c+10,((1U & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
				    >> 0xaU))));
	vcdp->chgBit  (c+11,((1U & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
				    >> 3U))));
	vcdp->chgBus  (c+12,(vlTOPp->Top__DOT__cpath__DOT___T_153),3);
	vcdp->chgBit  (c+13,((1U & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
				    >> 9U))));
	vcdp->chgBit  (c+14,((1U & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
				    >> 8U))));
	vcdp->chgBus  (c+15,((0x1fU & (vlTOPp->Top__DOT___GEN_27 
				       >> 0xbU))),5);
	vcdp->chgBus  (c+16,((0x1fU & (vlTOPp->Top__DOT___GEN_27 
				       >> 0x10U))),5);
	vcdp->chgBus  (c+17,((0x1fU & (vlTOPp->Top__DOT___GEN_27 
				       >> 0x15U))),5);
	vcdp->chgBus  (c+18,(vlTOPp->Top__DOT__cpath__DOT___T_161),16);
	vcdp->chgBus  (c+19,((0x3ffffffU & ((0x10U 
					     & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
					     ? vlTOPp->Top__DOT___GEN_27
					     : 0U))),26);
	vcdp->chgBit  (c+20,((1U & ((6U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))
				     ? (0U == vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2)
				     : (IData)((vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_20 
						>> 0x1fU))))));
	vcdp->chgBus  (c+21,(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__out),32);
	vcdp->chgBus  (c+22,(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_46_data),32);
	vcdp->chgBus  (c+23,(vlTOPp->Top__DOT__dmm___05FT_50_data),32);
	vcdp->chgBus  (c+24,(vlTOPp->Top__DOT__imm___05FT_34_data),32);
	vcdp->chgBit  (c+25,(vlTOPp->Top__DOT___T_21));
	vcdp->chgBus  (c+26,(vlTOPp->Top__DOT__dmm___05FT_39_data),32);
	vcdp->chgBus  (c+27,((0x3ffU & (vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__out 
					>> 2U))),10);
	vcdp->chgBus  (c+28,(vlTOPp->Top__DOT__dmm___05FT_61_data),32);
	vcdp->chgBit  (c+29,(vlTOPp->Top__DOT___T_26));
	vcdp->chgBit  (c+30,(vlTOPp->Top__DOT___GEN_32));
	vcdp->chgBus  (c+31,(vlTOPp->Top__DOT__cpath__DOT___T_83),11);
	vcdp->chgBit  (c+32,((1U & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
				    >> 4U))));
	vcdp->chgBus  (c+33,((7U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))),3);
	vcdp->chgBit  (c+34,((1U & (((~ ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
					 >> 2U)) & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83)) 
				    | (((IData)(vlTOPp->Top__DOT__cpath__DOT___T_96) 
					& (vlTOPp->Top__DOT___GEN_27 
					   >> 1U)) 
				       & (~ vlTOPp->Top__DOT___GEN_27))))));
	vcdp->chgBit  (c+35,((1U & (((~ ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
					 >> 2U)) & 
				     (~ ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
					 >> 1U))) | 
				    ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_96) 
				     & (~ vlTOPp->Top__DOT___GEN_27))))));
	vcdp->chgBit  (c+36,((1U & ((((~ ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
					  >> 2U)) & 
				      ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
				       >> 1U)) | ((
						   ((((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						      >> 2U) 
						     & (~ 
							(vlTOPp->Top__DOT___GEN_27 
							 >> 3U))) 
						    & (vlTOPp->Top__DOT___GEN_27 
						       >> 2U)) 
						   & (~ 
						      (vlTOPp->Top__DOT___GEN_27 
						       >> 1U))) 
						  & vlTOPp->Top__DOT___GEN_27)) 
				    | ((((((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
					   >> 2U) & 
					  (vlTOPp->Top__DOT___GEN_27 
					   >> 3U)) 
					 & (~ (vlTOPp->Top__DOT___GEN_27 
					       >> 2U))) 
					& (vlTOPp->Top__DOT___GEN_27 
					   >> 1U)) 
				       & (~ vlTOPp->Top__DOT___GEN_27))))));
	vcdp->chgBus  (c+37,(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data),32);
	vcdp->chgBus  (c+38,(((0x100U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
			       ? vlTOPp->Top__DOT__dmm___05FT_50_data
			       : vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__out)),32);
	vcdp->chgBus  (c+39,(vlTOPp->Top__DOT__dpath__DOT___T_119),32);
	vcdp->chgBus  (c+40,((0x1fU & ((0x400U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
				        ? (vlTOPp->Top__DOT___GEN_27 
					   >> 0xbU)
				        : (vlTOPp->Top__DOT___GEN_27 
					   >> 0x10U)))),5);
	vcdp->chgBus  (c+41,(((((0x8000U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
				 ? 0x7fffU : 0U) << 0x11U) 
			      | ((0x1fffcU & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_161) 
					      << 2U)) 
				 | ((0x8000U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
				     ? 3U : 0U)))),32);
	vcdp->chgBus  (c+42,(((8U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
			       ? ((((0x8000U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
				     ? 0x1ffffU : 0U) 
				   << 0xfU) | (0x7fffU 
					       & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161)))
			       : (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))),32);
	vcdp->chgBit  (c+43,((3U != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))));
	vcdp->chgBus  (c+44,(((IData)(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_11)
			       ? (~ vlTOPp->Top__DOT__dpath__DOT___T_119)
			       : vlTOPp->Top__DOT__dpath__DOT___T_119)),32);
	vcdp->chgBus  (c+45,(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2),32);
	vcdp->chgBus  (c+46,((IData)(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_20)),32);
	vcdp->chgBus  (c+47,((((1U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))
			        ? vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2
			        : 0U) | (((1U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
					  | (0U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)))
					  ? (vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data 
					     & vlTOPp->Top__DOT__dpath__DOT___T_119)
					  : 0U))),32);
    }
}

void VTop::traceChgThis__5(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+48,(vlTOPp->Top__DOT__dpath__DOT__pc_reg),32);
	vcdp->chgBus  (c+49,((0xffU & (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
				       >> 2U))),8);
	vcdp->chgBus  (c+50,(vlTOPp->Top__DOT__clk_cnt),32);
	vcdp->chgBus  (c+51,(((IData)(4U) + vlTOPp->Top__DOT__dpath__DOT__pc_reg)),32);
	vcdp->chgBus  (c+52,(vlTOPp->Top__DOT__dpath__DOT__RegFile[0]),32);
	vcdp->chgBus  (c+53,(vlTOPp->Top__DOT__dpath__DOT__RegFile[1]),32);
	vcdp->chgBus  (c+54,(vlTOPp->Top__DOT__dpath__DOT__RegFile[2]),32);
	vcdp->chgBus  (c+55,(vlTOPp->Top__DOT__dpath__DOT__RegFile[3]),32);
	vcdp->chgBus  (c+56,(vlTOPp->Top__DOT__dpath__DOT__RegFile[4]),32);
	vcdp->chgBus  (c+57,(vlTOPp->Top__DOT__dpath__DOT__RegFile[5]),32);
	vcdp->chgBus  (c+58,(vlTOPp->Top__DOT__dpath__DOT__RegFile[6]),32);
	vcdp->chgBus  (c+59,(vlTOPp->Top__DOT__dpath__DOT__RegFile[7]),32);
	vcdp->chgBus  (c+60,(vlTOPp->Top__DOT__dpath__DOT__RegFile[8]),32);
	vcdp->chgBus  (c+61,(vlTOPp->Top__DOT__dpath__DOT__RegFile[9]),32);
	vcdp->chgBus  (c+62,(vlTOPp->Top__DOT__dpath__DOT__RegFile[10]),32);
	vcdp->chgBus  (c+63,(vlTOPp->Top__DOT__dpath__DOT__RegFile[11]),32);
	vcdp->chgBus  (c+64,(vlTOPp->Top__DOT__dpath__DOT__RegFile[12]),32);
	vcdp->chgBus  (c+65,(vlTOPp->Top__DOT__dpath__DOT__RegFile[13]),32);
	vcdp->chgBus  (c+66,(vlTOPp->Top__DOT__dpath__DOT__RegFile[14]),32);
	vcdp->chgBus  (c+67,(vlTOPp->Top__DOT__dpath__DOT__RegFile[15]),32);
	vcdp->chgBus  (c+68,(vlTOPp->Top__DOT__dpath__DOT__RegFile[16]),32);
	vcdp->chgBus  (c+69,(vlTOPp->Top__DOT__dpath__DOT__RegFile[17]),32);
	vcdp->chgBus  (c+70,(vlTOPp->Top__DOT__dpath__DOT__RegFile[18]),32);
	vcdp->chgBus  (c+71,(vlTOPp->Top__DOT__dpath__DOT__RegFile[19]),32);
	vcdp->chgBus  (c+72,(vlTOPp->Top__DOT__dpath__DOT__RegFile[20]),32);
	vcdp->chgBus  (c+73,(vlTOPp->Top__DOT__dpath__DOT__RegFile[21]),32);
	vcdp->chgBus  (c+74,(vlTOPp->Top__DOT__dpath__DOT__RegFile[22]),32);
	vcdp->chgBus  (c+75,(vlTOPp->Top__DOT__dpath__DOT__RegFile[23]),32);
	vcdp->chgBus  (c+76,(vlTOPp->Top__DOT__dpath__DOT__RegFile[24]),32);
	vcdp->chgBus  (c+77,(vlTOPp->Top__DOT__dpath__DOT__RegFile[25]),32);
	vcdp->chgBus  (c+78,(vlTOPp->Top__DOT__dpath__DOT__RegFile[26]),32);
	vcdp->chgBus  (c+79,(vlTOPp->Top__DOT__dpath__DOT__RegFile[27]),32);
	vcdp->chgBus  (c+80,(vlTOPp->Top__DOT__dpath__DOT__RegFile[28]),32);
	vcdp->chgBus  (c+81,(vlTOPp->Top__DOT__dpath__DOT__RegFile[29]),32);
	vcdp->chgBus  (c+82,(vlTOPp->Top__DOT__dpath__DOT__RegFile[30]),32);
	vcdp->chgBus  (c+83,(vlTOPp->Top__DOT__dpath__DOT__RegFile[31]),32);
    }
}

void VTop::traceChgThis__6(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+84,(vlTOPp->clock));
	vcdp->chgBit  (c+85,(vlTOPp->reset));
	vcdp->chgBit  (c+86,(vlTOPp->io_boot));
	vcdp->chgBit  (c+87,(vlTOPp->io_test_im_wr));
	vcdp->chgBit  (c+88,(vlTOPp->io_test_im_rd));
	vcdp->chgBus  (c+89,(vlTOPp->io_test_im_addr),32);
	vcdp->chgBus  (c+90,(vlTOPp->io_test_im_in),32);
	vcdp->chgBus  (c+91,(vlTOPp->io_test_im_out),32);
	vcdp->chgBit  (c+92,(vlTOPp->io_test_dm_wr));
	vcdp->chgBit  (c+93,(vlTOPp->io_test_dm_rd));
	vcdp->chgBus  (c+94,(vlTOPp->io_test_dm_addr),32);
	vcdp->chgBus  (c+95,(vlTOPp->io_test_dm_in),32);
	vcdp->chgBus  (c+96,(vlTOPp->io_test_dm_out),32);
	vcdp->chgBit  (c+97,(vlTOPp->io_valid));
	vcdp->chgBus  (c+98,((0xffU & (vlTOPp->io_test_im_addr 
				       >> 2U))),8);
	vcdp->chgBus  (c+99,((0x3ffU & (vlTOPp->io_test_dm_addr 
					>> 2U))),10);
    }
}
