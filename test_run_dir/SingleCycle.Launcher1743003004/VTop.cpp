// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop.h"              // For This
#include "VTop__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VTop) {
    VTop__Syms* __restrict vlSymsp = __VlSymsp = new VTop__Syms(this, name());
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VTop::__Vconfigure(VTop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VTop::~VTop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VTop::eval() {
    VTop__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VTop::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VTop::_eval_initial_loop(VTop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VTop::_sequent__TOP__1(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_sequent__TOP__1\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__Top__DOT__imm__v0,7,0);
    VL_SIG8(__Vdlyvset__Top__DOT__imm__v0,0,0);
    VL_SIG8(__Vdlyvset__Top__DOT__dmm__v0,0,0);
    VL_SIG8(__Vdlyvset__Top__DOT__dmm__v1,0,0);
    VL_SIG8(__Vdlyvdim0__Top__DOT__dpath__DOT__RegFile__v1,4,0);
    VL_SIG8(__Vdlyvset__Top__DOT__dpath__DOT__RegFile__v1,0,0);
    VL_SIG16(__Vdlyvdim0__Top__DOT__dmm__v0,9,0);
    VL_SIG16(__Vdlyvdim0__Top__DOT__dmm__v1,9,0);
    //char	__VpadToAlign14[2];
    VL_SIG(__Vdlyvval__Top__DOT__imm__v0,31,0);
    VL_SIG(__Vdlyvval__Top__DOT__dmm__v0,31,0);
    VL_SIG(__Vdlyvval__Top__DOT__dmm__v1,31,0);
    VL_SIG(__Vdly__Top__DOT__clk_cnt,31,0);
    VL_SIG(__Vdlyvval__Top__DOT__dpath__DOT__RegFile__v1,31,0);
    // Body
    __Vdlyvset__Top__DOT__dmm__v0 = 0U;
    __Vdlyvset__Top__DOT__dmm__v1 = 0U;
    __Vdlyvset__Top__DOT__dpath__DOT__RegFile__v1 = 0U;
    __Vdly__Top__DOT__clk_cnt = vlTOPp->Top__DOT__clk_cnt;
    __Vdlyvset__Top__DOT__imm__v0 = 0U;
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1743003004/Top.v:712
    if (vlTOPp->Top__DOT___T_26) {
	__Vdlyvval__Top__DOT__dmm__v0 = vlTOPp->io_test_dm_in;
	__Vdlyvset__Top__DOT__dmm__v0 = 1U;
	__Vdlyvdim0__Top__DOT__dmm__v0 = (0x3ffU & 
					  (vlTOPp->io_test_dm_addr 
					   >> 2U));
    }
    if (vlTOPp->Top__DOT___GEN_32) {
	__Vdlyvval__Top__DOT__dmm__v1 = vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_46_data;
	__Vdlyvset__Top__DOT__dmm__v1 = 1U;
	__Vdlyvdim0__Top__DOT__dmm__v1 = (0x3ffU & 
					  (vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__out 
					   >> 2U));
    }
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1743003004/Top.v:460
    if ((0x80U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))) {
	__Vdlyvval__Top__DOT__dpath__DOT__RegFile__v1 
	    = ((0x100U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
	        ? vlTOPp->Top__DOT__dmm___05FT_50_data
	        : vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__out);
	__Vdlyvset__Top__DOT__dpath__DOT__RegFile__v1 = 1U;
	__Vdlyvdim0__Top__DOT__dpath__DOT__RegFile__v1 
	    = (0x1fU & ((0x400U & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
			 ? (vlTOPp->Top__DOT___GEN_27 
			    >> 0xbU) : (vlTOPp->Top__DOT___GEN_27 
					>> 0x10U)));
    }
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1743003004/Top.v:719
    __Vdly__Top__DOT__clk_cnt = ((IData)(vlTOPp->reset)
				  ? 0U : vlTOPp->Top__DOT___T_58);
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
	    VL_FWRITEF(0x80000002U,"Cyc=%10#, pc=0x%x, Inst=0x%x, boot=%1#, dmem_in = 0x%x, rd_dmm=0x%x, dmm=0x%x\n",
		       32,vlTOPp->Top__DOT__clk_cnt,
		       32,vlTOPp->Top__DOT__dpath__DOT__pc_reg,
		       32,vlTOPp->Top__DOT___GEN_27,
		       1,(IData)(vlTOPp->io_boot),32,
		       vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_46_data,
		       32,vlTOPp->io_test_dm_out,32,
		       vlTOPp->Top__DOT__dmm___05FT_61_data);
	}
    }
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1743003004/Top.v:709
    if (vlTOPp->Top__DOT___T_21) {
	__Vdlyvval__Top__DOT__imm__v0 = vlTOPp->io_test_im_in;
	__Vdlyvset__Top__DOT__imm__v0 = 1U;
	__Vdlyvdim0__Top__DOT__imm__v0 = (0xffU & (vlTOPp->io_test_im_addr 
						   >> 2U));
    }
    // ALWAYSPOST at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1743003004/Top.v:713
    if (__Vdlyvset__Top__DOT__dmm__v0) {
	vlTOPp->Top__DOT__dmm[__Vdlyvdim0__Top__DOT__dmm__v0] 
	    = __Vdlyvval__Top__DOT__dmm__v0;
    }
    if (__Vdlyvset__Top__DOT__dmm__v1) {
	vlTOPp->Top__DOT__dmm[__Vdlyvdim0__Top__DOT__dmm__v1] 
	    = __Vdlyvval__Top__DOT__dmm__v1;
    }
    // ALWAYSPOST at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1743003004/Top.v:460
    vlTOPp->Top__DOT__dpath__DOT__RegFile[0U] = 0U;
    if (__Vdlyvset__Top__DOT__dpath__DOT__RegFile__v1) {
	vlTOPp->Top__DOT__dpath__DOT__RegFile[__Vdlyvdim0__Top__DOT__dpath__DOT__RegFile__v1] 
	    = __Vdlyvval__Top__DOT__dpath__DOT__RegFile__v1;
    }
    vlTOPp->Top__DOT__clk_cnt = __Vdly__Top__DOT__clk_cnt;
    // ALWAYSPOST at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1743003004/Top.v:710
    if (__Vdlyvset__Top__DOT__imm__v0) {
	vlTOPp->Top__DOT__imm[__Vdlyvdim0__Top__DOT__imm__v0] 
	    = __Vdlyvval__Top__DOT__imm__v0;
    }
    vlTOPp->Top__DOT___T_58 = ((IData)(1U) + vlTOPp->Top__DOT__clk_cnt);
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1743003004/Top.v:455
    vlTOPp->Top__DOT__dpath__DOT__pc_reg = ((IData)(vlTOPp->reset)
					     ? 0U : vlTOPp->Top__DOT__dpath__DOT___T_118);
    vlTOPp->Top__DOT__imm___05FT_46_data = vlTOPp->Top__DOT__imm
	[(0xffU & (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
		   >> 2U))];
}

VL_INLINE_OPT void VTop::_combo__TOP__2(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__2\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT___T_26 = ((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_dm_wr));
    vlTOPp->Top__DOT___T_21 = ((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_im_wr));
    vlTOPp->Top__DOT__dmm___05FT_61_data = vlTOPp->Top__DOT__dmm
	[(0x3ffU & (vlTOPp->io_test_dm_addr >> 2U))];
    vlTOPp->Top__DOT__dmm___05FT_39_data = vlTOPp->Top__DOT__dmm
	[(0x3ffU & (vlTOPp->io_test_dm_addr >> 2U))];
    vlTOPp->Top__DOT__imm___05FT_34_data = vlTOPp->Top__DOT__imm
	[(0xffU & (vlTOPp->io_test_im_addr >> 2U))];
}

void VTop::_settle__TOP__3(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__3\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT___T_26 = ((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_dm_wr));
    vlTOPp->Top__DOT___T_21 = ((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_im_wr));
    vlTOPp->Top__DOT__dmm___05FT_61_data = vlTOPp->Top__DOT__dmm
	[(0x3ffU & (vlTOPp->io_test_dm_addr >> 2U))];
    vlTOPp->Top__DOT__dmm___05FT_39_data = vlTOPp->Top__DOT__dmm
	[(0x3ffU & (vlTOPp->io_test_dm_addr >> 2U))];
    vlTOPp->Top__DOT___T_58 = ((IData)(1U) + vlTOPp->Top__DOT__clk_cnt);
    vlTOPp->Top__DOT__imm___05FT_34_data = vlTOPp->Top__DOT__imm
	[(0xffU & (vlTOPp->io_test_im_addr >> 2U))];
    vlTOPp->Top__DOT__imm___05FT_46_data = vlTOPp->Top__DOT__imm
	[(0xffU & (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
		   >> 2U))];
    vlTOPp->io_test_dm_out = (((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_dm_rd))
			       ? vlTOPp->Top__DOT__dmm___05FT_39_data
			       : 0U);
    vlTOPp->io_test_im_out = (((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_im_rd))
			       ? vlTOPp->Top__DOT__imm___05FT_34_data
			       : 0U);
    vlTOPp->Top__DOT___GEN_27 = ((IData)(vlTOPp->io_boot)
				  ? 0U : ((IData)(vlTOPp->io_boot)
					   ? 0U : vlTOPp->Top__DOT__imm___05FT_46_data));
}

VL_INLINE_OPT void VTop::_combo__TOP__4(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__4\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_test_dm_out = (((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_dm_rd))
			       ? vlTOPp->Top__DOT__dmm___05FT_39_data
			       : 0U);
    vlTOPp->io_test_im_out = (((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_im_rd))
			       ? vlTOPp->Top__DOT__imm___05FT_34_data
			       : 0U);
    vlTOPp->Top__DOT___GEN_27 = ((IData)(vlTOPp->io_boot)
				  ? 0U : ((IData)(vlTOPp->io_boot)
					   ? 0U : vlTOPp->Top__DOT__imm___05FT_46_data));
    vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data 
	= vlTOPp->Top__DOT__dpath__DOT__RegFile[(0x1fU 
						 & (vlTOPp->Top__DOT___GEN_27 
						    >> 0x15U))];
    vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_46_data 
	= vlTOPp->Top__DOT__dpath__DOT__RegFile[(0x1fU 
						 & (vlTOPp->Top__DOT___GEN_27 
						    >> 0x10U))];
    vlTOPp->Top__DOT__cpath__DOT___T_83 = ((IData)(vlTOPp->io_boot)
					    ? 8U : 
					   (((0U == 
					      (0x3fU 
					       & (vlTOPp->Top__DOT___GEN_27 
						  >> 0x1aU))) 
					     & (0U 
						!= vlTOPp->Top__DOT___GEN_27))
					     ? 0x484U
					     : ((0xdU 
						 == 
						 (0x3fU 
						  & (vlTOPp->Top__DOT___GEN_27 
						     >> 0x1aU)))
						 ? 0x282U
						 : 
						((0x23U 
						  == 
						  (0x3fU 
						   & (vlTOPp->Top__DOT___GEN_27 
						      >> 0x1aU)))
						  ? 0x388U
						  : 
						 ((0x2bU 
						   == 
						   (0x3fU 
						    & (vlTOPp->Top__DOT___GEN_27 
						       >> 0x1aU)))
						   ? 0x248U
						   : 
						  ((4U 
						    == 
						    (0x3fU 
						     & (vlTOPp->Top__DOT___GEN_27 
							>> 0x1aU)))
						    ? 0x29U
						    : 
						   ((2U 
						     == 
						     (0x3fU 
						      & (vlTOPp->Top__DOT___GEN_27 
							 >> 0x1aU)))
						     ? 0x37U
						     : 
						    ((0U 
						      == vlTOPp->Top__DOT___GEN_27)
						      ? 0U
						      : 0x7ffU))))))));
}

void VTop::_settle__TOP__5(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__5\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data 
	= vlTOPp->Top__DOT__dpath__DOT__RegFile[(0x1fU 
						 & (vlTOPp->Top__DOT___GEN_27 
						    >> 0x15U))];
    vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_46_data 
	= vlTOPp->Top__DOT__dpath__DOT__RegFile[(0x1fU 
						 & (vlTOPp->Top__DOT___GEN_27 
						    >> 0x10U))];
    vlTOPp->Top__DOT__cpath__DOT___T_83 = ((IData)(vlTOPp->io_boot)
					    ? 8U : 
					   (((0U == 
					      (0x3fU 
					       & (vlTOPp->Top__DOT___GEN_27 
						  >> 0x1aU))) 
					     & (0U 
						!= vlTOPp->Top__DOT___GEN_27))
					     ? 0x484U
					     : ((0xdU 
						 == 
						 (0x3fU 
						  & (vlTOPp->Top__DOT___GEN_27 
						     >> 0x1aU)))
						 ? 0x282U
						 : 
						((0x23U 
						  == 
						  (0x3fU 
						   & (vlTOPp->Top__DOT___GEN_27 
						      >> 0x1aU)))
						  ? 0x388U
						  : 
						 ((0x2bU 
						   == 
						   (0x3fU 
						    & (vlTOPp->Top__DOT___GEN_27 
						       >> 0x1aU)))
						   ? 0x248U
						   : 
						  ((4U 
						    == 
						    (0x3fU 
						     & (vlTOPp->Top__DOT___GEN_27 
							>> 0x1aU)))
						    ? 0x29U
						    : 
						   ((2U 
						     == 
						     (0x3fU 
						      & (vlTOPp->Top__DOT___GEN_27 
							 >> 0x1aU)))
						     ? 0x37U
						     : 
						    ((0U 
						      == vlTOPp->Top__DOT___GEN_27)
						      ? 0U
						      : 0x7ffU))))))));
    vlTOPp->io_valid = (0x7ffU != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83));
    vlTOPp->Top__DOT___GEN_32 = (1U & ((~ (IData)(vlTOPp->io_boot)) 
				       & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
					  >> 6U)));
    vlTOPp->Top__DOT__cpath__DOT___T_161 = (0xffffU 
					    & ((1U 
						& ((4U 
						    == 
						    (7U 
						     & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))) 
						   | ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						      >> 4U)))
					        ? 0U
					        : vlTOPp->Top__DOT___GEN_27));
    vlTOPp->Top__DOT__cpath__DOT___T_96 = (1U & (((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						  >> 2U) 
						 & (~ 
						    (vlTOPp->Top__DOT___GEN_27 
						     >> 2U))));
}

VL_INLINE_OPT void VTop::_combo__TOP__6(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__6\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_valid = (0x7ffU != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83));
    vlTOPp->Top__DOT___GEN_32 = (1U & ((~ (IData)(vlTOPp->io_boot)) 
				       & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
					  >> 6U)));
    vlTOPp->Top__DOT__cpath__DOT___T_161 = (0xffffU 
					    & ((1U 
						& ((4U 
						    == 
						    (7U 
						     & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))) 
						   | ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						      >> 4U)))
					        ? 0U
					        : vlTOPp->Top__DOT___GEN_27));
    vlTOPp->Top__DOT__cpath__DOT___T_96 = (1U & (((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						  >> 2U) 
						 & (~ 
						    (vlTOPp->Top__DOT___GEN_27 
						     >> 2U))));
    vlTOPp->Top__DOT__dpath__DOT___T_119 = ((0x200U 
					     & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
					     ? ((8U 
						 & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
						 ? 
						((((0x8000U 
						    & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
						    ? 0x1ffffU
						    : 0U) 
						  << 0xfU) 
						 | (0x7fffU 
						    & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161)))
						 : (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
					     : vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_46_data);
    vlTOPp->Top__DOT__cpath__DOT___T_153 = ((8U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
					     ? 3U : 
					    ((0U == vlTOPp->Top__DOT___GEN_27)
					      ? 0U : 
					     ((4U & 
					       ((((~ 
						   ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						    >> 2U)) 
						  & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83)) 
						 << 2U) 
						| (0xfffffffcU 
						   & ((((IData)(vlTOPp->Top__DOT__cpath__DOT___T_96) 
							<< 2U) 
						       & (vlTOPp->Top__DOT___GEN_27 
							  << 1U)) 
						      & ((~ vlTOPp->Top__DOT___GEN_27) 
							 << 2U))))) 
					      | ((2U 
						  & ((((~ 
							((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							 >> 2U)) 
						       & (~ 
							  ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							   >> 1U))) 
						      | ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_96) 
							 & (~ vlTOPp->Top__DOT___GEN_27))) 
						     << 1U)) 
						 | (1U 
						    & ((((~ 
							  ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							   >> 2U)) 
							 & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							    >> 1U)) 
							| ((((((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
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
							      >> 2U) 
							     & (vlTOPp->Top__DOT___GEN_27 
								>> 3U)) 
							    & (~ 
							       (vlTOPp->Top__DOT___GEN_27 
								>> 2U))) 
							   & (vlTOPp->Top__DOT___GEN_27 
							      >> 1U)) 
							  & (~ vlTOPp->Top__DOT___GEN_27))))))));
}

void VTop::_settle__TOP__7(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__7\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__dpath__DOT___T_119 = ((0x200U 
					     & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
					     ? ((8U 
						 & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
						 ? 
						((((0x8000U 
						    & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
						    ? 0x1ffffU
						    : 0U) 
						  << 0xfU) 
						 | (0x7fffU 
						    & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161)))
						 : (IData)(vlTOPp->Top__DOT__cpath__DOT___T_161))
					     : vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_46_data);
    vlTOPp->Top__DOT__cpath__DOT___T_153 = ((8U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
					     ? 3U : 
					    ((0U == vlTOPp->Top__DOT___GEN_27)
					      ? 0U : 
					     ((4U & 
					       ((((~ 
						   ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						    >> 2U)) 
						  & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83)) 
						 << 2U) 
						| (0xfffffffcU 
						   & ((((IData)(vlTOPp->Top__DOT__cpath__DOT___T_96) 
							<< 2U) 
						       & (vlTOPp->Top__DOT___GEN_27 
							  << 1U)) 
						      & ((~ vlTOPp->Top__DOT___GEN_27) 
							 << 2U))))) 
					      | ((2U 
						  & ((((~ 
							((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							 >> 2U)) 
						       & (~ 
							  ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							   >> 1U))) 
						      | ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_96) 
							 & (~ vlTOPp->Top__DOT___GEN_27))) 
						     << 1U)) 
						 | (1U 
						    & ((((~ 
							  ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							   >> 2U)) 
							 & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							    >> 1U)) 
							| ((((((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
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
							      >> 2U) 
							     & (vlTOPp->Top__DOT___GEN_27 
								>> 3U)) 
							    & (~ 
							       (vlTOPp->Top__DOT___GEN_27 
								>> 2U))) 
							   & (vlTOPp->Top__DOT___GEN_27 
							      >> 1U)) 
							  & (~ vlTOPp->Top__DOT___GEN_27))))))));
    vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2 
	= (vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data 
	   ^ vlTOPp->Top__DOT__dpath__DOT___T_119);
    vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_11 
	= ((6U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
	   | (7U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)));
}

VL_INLINE_OPT void VTop::_combo__TOP__8(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__8\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2 
	= (vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data 
	   ^ vlTOPp->Top__DOT__dpath__DOT___T_119);
    vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_11 
	= ((6U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
	   | (7U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)));
    vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_20 
	= (VL_ULL(0x1ffffffff) & ((QData)((IData)((vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data 
						   + 
						   ((IData)(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_11)
						     ? 
						    (~ vlTOPp->Top__DOT__dpath__DOT___T_119)
						     : vlTOPp->Top__DOT__dpath__DOT___T_119)))) 
				  + (QData)((IData)(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_11))));
}

void VTop::_settle__TOP__9(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__9\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_20 
	= (VL_ULL(0x1ffffffff) & ((QData)((IData)((vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data 
						   + 
						   ((IData)(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_11)
						     ? 
						    (~ vlTOPp->Top__DOT__dpath__DOT___T_119)
						     : vlTOPp->Top__DOT__dpath__DOT___T_119)))) 
				  + (QData)((IData)(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_11))));
    vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__out = 
	(((2U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
	  | (6U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)))
	  ? (IData)(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_20)
	  : (((1U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))
	       ? vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2
	       : 0U) | (((1U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
			 | (0U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)))
			 ? (vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data 
			    & vlTOPp->Top__DOT__dpath__DOT___T_119)
			 : 0U)));
    vlTOPp->Top__DOT__cpath__DOT___T_40 = (1U & ((~ (IData)(vlTOPp->io_boot)) 
						 & ((0x10U 
						     & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
						     ? 
						    ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						     >> 5U)
						     : 
						    (((6U 
						       == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))
						       ? 
						      (0U 
						       == vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2)
						       : (IData)(
								 (vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_20 
								  >> 0x1fU))) 
						     & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							>> 5U)))));
}

VL_INLINE_OPT void VTop::_combo__TOP__10(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__10\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__out = 
	(((2U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
	  | (6U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)))
	  ? (IData)(vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_20)
	  : (((1U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))
	       ? vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2
	       : 0U) | (((1U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
			 | (0U == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)))
			 ? (vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_45_data 
			    & vlTOPp->Top__DOT__dpath__DOT___T_119)
			 : 0U)));
    vlTOPp->Top__DOT__cpath__DOT___T_40 = (1U & ((~ (IData)(vlTOPp->io_boot)) 
						 & ((0x10U 
						     & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
						     ? 
						    ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						     >> 5U)
						     : 
						    (((6U 
						       == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))
						       ? 
						      (0U 
						       == vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2)
						       : (IData)(
								 (vlTOPp->Top__DOT__dpath__DOT__alu9__DOT___T_20 
								  >> 0x1fU))) 
						     & ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
							>> 5U)))));
    vlTOPp->Top__DOT__dmm___05FT_50_data = vlTOPp->Top__DOT__dmm
	[(0x3ffU & (vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__out 
		    >> 2U))];
    vlTOPp->Top__DOT__dpath__DOT___T_118 = (((3U != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
					     & (~ (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40)))
					     ? ((IData)(4U) 
						+ vlTOPp->Top__DOT__dpath__DOT__pc_reg)
					     : (((((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						   >> 3U) 
						  & (3U 
						     != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))) 
						 & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40))
						 ? 
						((IData)(4U) 
						 + 
						 (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
						  + 
						  ((((0x8000U 
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
							  : 0U)))))
						 : 
						((((~ 
						    ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						     >> 3U)) 
						   & (3U 
						      != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))) 
						  & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40))
						  ? 
						 ((0xf0000000U 
						   & vlTOPp->Top__DOT__dpath__DOT__pc_reg) 
						  | (0xffffffcU 
						     & (((0x10U 
							  & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
							  ? vlTOPp->Top__DOT___GEN_27
							  : 0U) 
							<< 2U)))
						  : 
						 (((3U 
						    == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
						   & (~ (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40)))
						   ? 0U
						   : 
						  ((IData)(4U) 
						   + vlTOPp->Top__DOT__dpath__DOT__pc_reg)))));
}

void VTop::_settle__TOP__11(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__11\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__dmm___05FT_50_data = vlTOPp->Top__DOT__dmm
	[(0x3ffU & (vlTOPp->Top__DOT__dpath__DOT__alu9__DOT__out 
		    >> 2U))];
    vlTOPp->Top__DOT__dpath__DOT___T_118 = (((3U != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
					     & (~ (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40)))
					     ? ((IData)(4U) 
						+ vlTOPp->Top__DOT__dpath__DOT__pc_reg)
					     : (((((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						   >> 3U) 
						  & (3U 
						     != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))) 
						 & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40))
						 ? 
						((IData)(4U) 
						 + 
						 (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
						  + 
						  ((((0x8000U 
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
							  : 0U)))))
						 : 
						((((~ 
						    ((IData)(vlTOPp->Top__DOT__cpath__DOT___T_83) 
						     >> 3U)) 
						   & (3U 
						      != (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153))) 
						  & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40))
						  ? 
						 ((0xf0000000U 
						   & vlTOPp->Top__DOT__dpath__DOT__pc_reg) 
						  | (0xffffffcU 
						     & (((0x10U 
							  & (IData)(vlTOPp->Top__DOT__cpath__DOT___T_83))
							  ? vlTOPp->Top__DOT___GEN_27
							  : 0U) 
							<< 2U)))
						  : 
						 (((3U 
						    == (IData)(vlTOPp->Top__DOT__cpath__DOT___T_153)) 
						   & (~ (IData)(vlTOPp->Top__DOT__cpath__DOT___T_40)))
						   ? 0U
						   : 
						  ((IData)(4U) 
						   + vlTOPp->Top__DOT__dpath__DOT__pc_reg)))));
}

void VTop::_eval(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_eval\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->_combo__TOP__6(vlSymsp);
    vlTOPp->_combo__TOP__8(vlSymsp);
    vlTOPp->_combo__TOP__10(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VTop::_eval_initial(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_eval_initial\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VTop::final() {
    VL_DEBUG_IF(VL_PRINTF("    VTop::final\n"); );
    // Variables
    VTop__Syms* __restrict vlSymsp = this->__VlSymsp;
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VTop::_eval_settle(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_eval_settle\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->_settle__TOP__7(vlSymsp);
    vlTOPp->_settle__TOP__9(vlSymsp);
    vlTOPp->_settle__TOP__11(vlSymsp);
}

VL_INLINE_OPT QData VTop::_change_request(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_change_request\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VTop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_boot = VL_RAND_RESET_I(1);
    io_test_im_wr = VL_RAND_RESET_I(1);
    io_test_im_rd = VL_RAND_RESET_I(1);
    io_test_im_addr = VL_RAND_RESET_I(32);
    io_test_im_in = VL_RAND_RESET_I(32);
    io_test_im_out = VL_RAND_RESET_I(32);
    io_test_dm_wr = VL_RAND_RESET_I(1);
    io_test_dm_rd = VL_RAND_RESET_I(1);
    io_test_dm_addr = VL_RAND_RESET_I(32);
    io_test_dm_in = VL_RAND_RESET_I(32);
    io_test_dm_out = VL_RAND_RESET_I(32);
    io_valid = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    Top__DOT__imm[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Top__DOT__imm___05FT_34_data = VL_RAND_RESET_I(32);
    Top__DOT__imm___05FT_46_data = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
	    Top__DOT__dmm[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Top__DOT__dmm___05FT_39_data = VL_RAND_RESET_I(32);
    Top__DOT__dmm___05FT_50_data = VL_RAND_RESET_I(32);
    Top__DOT__dmm___05FT_61_data = VL_RAND_RESET_I(32);
    Top__DOT___T_21 = VL_RAND_RESET_I(1);
    Top__DOT___T_26 = VL_RAND_RESET_I(1);
    Top__DOT___GEN_27 = VL_RAND_RESET_I(32);
    Top__DOT___GEN_32 = VL_RAND_RESET_I(1);
    Top__DOT__clk_cnt = VL_RAND_RESET_I(32);
    Top__DOT___T_58 = VL_RAND_RESET_I(32);
    Top__DOT__cpath__DOT___T_40 = VL_RAND_RESET_I(1);
    Top__DOT__cpath__DOT___T_83 = VL_RAND_RESET_I(11);
    Top__DOT__cpath__DOT___T_96 = VL_RAND_RESET_I(1);
    Top__DOT__cpath__DOT___T_153 = VL_RAND_RESET_I(3);
    Top__DOT__cpath__DOT___T_161 = VL_RAND_RESET_I(16);
    Top__DOT__dpath__DOT__pc_reg = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    Top__DOT__dpath__DOT__RegFile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Top__DOT__dpath__DOT__RegFile___05FT_45_data = VL_RAND_RESET_I(32);
    Top__DOT__dpath__DOT__RegFile___05FT_46_data = VL_RAND_RESET_I(32);
    Top__DOT__dpath__DOT___T_118 = VL_RAND_RESET_I(32);
    Top__DOT__dpath__DOT___T_119 = VL_RAND_RESET_I(32);
    Top__DOT__dpath__DOT__alu9__DOT___T_11 = VL_RAND_RESET_I(1);
    Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2 = VL_RAND_RESET_I(32);
    Top__DOT__dpath__DOT__alu9__DOT___T_20 = VL_RAND_RESET_Q(33);
    Top__DOT__dpath__DOT__alu9__DOT__out = VL_RAND_RESET_I(32);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VTop::_configure_coverage(VTop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
