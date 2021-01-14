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
    VL_SIG8(__Vdlyvset__Top__DOT__imm__v0,0,0);
    VL_SIG8(__Vdlyvset__Top__DOT__dmm__DOT__mem__v0,0,0);
    VL_SIG16(__Vdlyvdim0__Top__DOT__imm__v0,11,0);
    VL_SIG16(__Vdlyvdim0__Top__DOT__dmm__DOT__mem__v0,13,0);
    //char	__VpadToAlign10[2];
    VL_SIG(__Vdlyvval__Top__DOT__imm__v0,31,0);
    VL_SIG(__Vdly__Top__DOT__clk_cnt,31,0);
    VL_SIG(__Vdlyvval__Top__DOT__dmm__DOT__mem__v0,31,0);
    // Body
    __Vdlyvset__Top__DOT__dmm__DOT__mem__v0 = 0U;
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:199
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
	    VL_FWRITEF(0x80000002U,"in1 = %10# , in2 = %10# aluout = %10#\n",
		       32,vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data,
		       32,vlTOPp->Top__DOT__dpath__DOT___T_108,
		       32,(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data 
			   & vlTOPp->Top__DOT__dpath__DOT___T_108));
	}
    }
    __Vdly__Top__DOT__clk_cnt = vlTOPp->Top__DOT__clk_cnt;
    __Vdlyvset__Top__DOT__imm__v0 = 0U;
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:258
    if ((1U & ((~ (IData)(vlTOPp->Top__DOT___T_123)) 
	       & (~ (IData)(vlTOPp->Top__DOT___T_123))))) {
	vlTOPp->Top__DOT__dmm__DOT____Vlvbound1 = vlTOPp->io_test_dm_in;
	if ((0x22b7U >= (0x3fffU & (vlTOPp->io_test_dm_addr 
				    >> 2U)))) {
	    __Vdlyvval__Top__DOT__dmm__DOT__mem__v0 
		= vlTOPp->Top__DOT__dmm__DOT____Vlvbound1;
	    __Vdlyvset__Top__DOT__dmm__DOT__mem__v0 = 1U;
	    __Vdlyvdim0__Top__DOT__dmm__DOT__mem__v0 
		= (0x3fffU & (vlTOPp->io_test_dm_addr 
			      >> 2U));
	}
    }
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:414
    __Vdly__Top__DOT__clk_cnt = ((IData)(vlTOPp->reset)
				  ? 0U : vlTOPp->Top__DOT___T_142);
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if (VL_UNLIKELY(((IData)(vlTOPp->Top__DOT___T_95) 
			 & (~ (IData)(vlTOPp->reset))))) {
	    VL_FWRITEF(0x80000002U,"io.test_im_addr = 0x%x\n",
		       30,(0x3fffffffU & (vlTOPp->io_test_im_addr 
					  >> 2U)));
	}
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if (VL_UNLIKELY(((IData)(vlTOPp->Top__DOT___T_95) 
			 & (~ (IData)(vlTOPp->reset))))) {
	    VL_FWRITEF(0x80000002U,"io.test_in_im = 0x%x\n",
		       32,vlTOPp->io_test_im_in);
	}
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if (VL_UNLIKELY(((IData)(vlTOPp->Top__DOT___T_95) 
			 & (~ (IData)(vlTOPp->reset))))) {
	    VL_FWRITEF(0x80000002U,"imm_data = 0x%x\n",
		       32,vlTOPp->Top__DOT__imm___05FT_108_data);
	}
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
	    VL_FWRITEF(0x80000002U,"Cyc=%10#, pc=0x%x, Inst=0x00000000, boot=%1#, dmem_in = 0x%x, rd_dmm=0x%x, Mem_wr=0\n",
		       32,vlTOPp->Top__DOT__clk_cnt,
		       32,vlTOPp->Top__DOT__dpath__DOT__pc_reg,
		       1,(IData)(vlTOPp->io_boot),32,
		       vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_52_data,
		       32,vlTOPp->io_test_dm_out);
	}
    }
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:410
    if (vlTOPp->Top__DOT___T_95) {
	__Vdlyvval__Top__DOT__imm__v0 = vlTOPp->io_test_im_in;
	__Vdlyvset__Top__DOT__imm__v0 = 1U;
	__Vdlyvdim0__Top__DOT__imm__v0 = (0xfffU & 
					  (vlTOPp->io_test_im_addr 
					   >> 2U));
    }
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:192
    // ALWAYSPOST at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:260
    if (__Vdlyvset__Top__DOT__dmm__DOT__mem__v0) {
	vlTOPp->Top__DOT__dmm__DOT__mem[__Vdlyvdim0__Top__DOT__dmm__DOT__mem__v0] 
	    = __Vdlyvval__Top__DOT__dmm__DOT__mem__v0;
    }
    vlTOPp->Top__DOT__clk_cnt = __Vdly__Top__DOT__clk_cnt;
    // ALWAYSPOST at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:411
    if (__Vdlyvset__Top__DOT__imm__v0) {
	vlTOPp->Top__DOT__imm[__Vdlyvdim0__Top__DOT__imm__v0] 
	    = __Vdlyvval__Top__DOT__imm__v0;
    }
    // ALWAYSPOST at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:192
    vlTOPp->Top__DOT__dpath__DOT__RegFile[0U] = 0U;
    vlTOPp->Top__DOT___T_142 = ((IData)(1U) + vlTOPp->Top__DOT__clk_cnt);
    // ALWAYS at /home/usename6/ercesiMIPS/test_run_dir/SingleCycle.Launcher1554891941/Top.v:187
    vlTOPp->Top__DOT__dpath__DOT__pc_reg = ((IData)(vlTOPp->reset)
					     ? 0U : vlTOPp->Top__DOT__dpath__DOT___T_107);
    vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data 
	= vlTOPp->Top__DOT__dpath__DOT__RegFile[0U];
    vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_52_data 
	= vlTOPp->Top__DOT__dpath__DOT__RegFile[0U];
    vlTOPp->Top__DOT__imm___05FT_133_data = vlTOPp->Top__DOT__imm
	[(0xfffU & (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
		    >> 2U))];
}

VL_INLINE_OPT void VTop::_combo__TOP__2(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__2\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT___T_123 = ((IData)(vlTOPp->io_boot) 
				& (IData)(vlTOPp->io_test_dm_rd));
    vlTOPp->Top__DOT___T_95 = ((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_im_wr));
    vlTOPp->Top__DOT__dmm__DOT__mem___05FT_10_data 
	= ((0x22b7U >= (0x3fffU & (vlTOPp->io_test_dm_addr 
				   >> 2U))) ? vlTOPp->Top__DOT__dmm__DOT__mem
	   [(0x3fffU & (vlTOPp->io_test_dm_addr >> 2U))]
	    : 0U);
    vlTOPp->Top__DOT__imm___05FT_108_data = vlTOPp->Top__DOT__imm
	[(0xfffU & (vlTOPp->io_test_im_addr >> 2U))];
    vlTOPp->Top__DOT__imm___05FT_121_data = vlTOPp->Top__DOT__imm
	[(0xfffU & (vlTOPp->io_test_im_addr >> 2U))];
}

void VTop::_settle__TOP__3(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__3\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT___T_123 = ((IData)(vlTOPp->io_boot) 
				& (IData)(vlTOPp->io_test_dm_rd));
    vlTOPp->Top__DOT___T_95 = ((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_im_wr));
    vlTOPp->Top__DOT__dmm__DOT__mem___05FT_10_data 
	= ((0x22b7U >= (0x3fffU & (vlTOPp->io_test_dm_addr 
				   >> 2U))) ? vlTOPp->Top__DOT__dmm__DOT__mem
	   [(0x3fffU & (vlTOPp->io_test_dm_addr >> 2U))]
	    : 0U);
    vlTOPp->Top__DOT___T_142 = ((IData)(1U) + vlTOPp->Top__DOT__clk_cnt);
    vlTOPp->Top__DOT__imm___05FT_108_data = vlTOPp->Top__DOT__imm
	[(0xfffU & (vlTOPp->io_test_im_addr >> 2U))];
    vlTOPp->Top__DOT__imm___05FT_121_data = vlTOPp->Top__DOT__imm
	[(0xfffU & (vlTOPp->io_test_im_addr >> 2U))];
    vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data 
	= vlTOPp->Top__DOT__dpath__DOT__RegFile[0U];
    vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_52_data 
	= vlTOPp->Top__DOT__dpath__DOT__RegFile[0U];
    vlTOPp->Top__DOT__imm___05FT_133_data = vlTOPp->Top__DOT__imm
	[(0xfffU & (vlTOPp->Top__DOT__dpath__DOT__pc_reg 
		    >> 2U))];
    vlTOPp->io_test_dm_out = ((IData)(vlTOPp->Top__DOT___T_123)
			       ? vlTOPp->Top__DOT__dmm__DOT__mem___05FT_10_data
			       : 0U);
    vlTOPp->io_test_im_out = (((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_im_rd))
			       ? vlTOPp->Top__DOT__imm___05FT_121_data
			       : 0U);
    vlTOPp->Top__DOT__dpath__DOT___T_108 = ((IData)(vlTOPp->io_boot)
					     ? 0U : vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_52_data);
}

VL_INLINE_OPT void VTop::_combo__TOP__4(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__4\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_test_dm_out = ((IData)(vlTOPp->Top__DOT___T_123)
			       ? vlTOPp->Top__DOT__dmm__DOT__mem___05FT_10_data
			       : 0U);
    vlTOPp->io_test_im_out = (((IData)(vlTOPp->io_boot) 
			       & (IData)(vlTOPp->io_test_im_rd))
			       ? vlTOPp->Top__DOT__imm___05FT_121_data
			       : 0U);
    vlTOPp->Top__DOT__dpath__DOT___T_108 = ((IData)(vlTOPp->io_boot)
					     ? 0U : vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_52_data);
    vlTOPp->Top__DOT__dpath__DOT___T_107 = ((1U == 
					     ((IData)(vlTOPp->io_boot)
					       ? 0U
					       : 1U))
					     ? ((IData)(4U) 
						+ vlTOPp->Top__DOT__dpath__DOT__pc_reg)
					     : (((2U 
						  == 
						  ((IData)(vlTOPp->io_boot)
						    ? 0U
						    : 1U)) 
						 & (IData)(
							   (VL_ULL(3) 
							    & (((QData)((IData)(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data)) 
								+ (QData)((IData)(vlTOPp->Top__DOT__dpath__DOT___T_108))) 
							       >> 0x1fU))))
						 ? 
						((IData)(4U) 
						 + vlTOPp->Top__DOT__dpath__DOT__pc_reg)
						 : 
						((3U 
						  == 
						  ((IData)(vlTOPp->io_boot)
						    ? 0U
						    : 1U))
						  ? 
						 (0xf0000000U 
						  & vlTOPp->Top__DOT__dpath__DOT__pc_reg)
						  : 
						 ((0U 
						   == 
						   ((IData)(vlTOPp->io_boot)
						     ? 0U
						     : 1U))
						   ? 0U
						   : 
						  ((IData)(4U) 
						   + vlTOPp->Top__DOT__dpath__DOT__pc_reg)))));
}

void VTop::_settle__TOP__5(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__5\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__dpath__DOT___T_107 = ((1U == 
					     ((IData)(vlTOPp->io_boot)
					       ? 0U
					       : 1U))
					     ? ((IData)(4U) 
						+ vlTOPp->Top__DOT__dpath__DOT__pc_reg)
					     : (((2U 
						  == 
						  ((IData)(vlTOPp->io_boot)
						    ? 0U
						    : 1U)) 
						 & (IData)(
							   (VL_ULL(3) 
							    & (((QData)((IData)(vlTOPp->Top__DOT__dpath__DOT__RegFile___05FT_51_data)) 
								+ (QData)((IData)(vlTOPp->Top__DOT__dpath__DOT___T_108))) 
							       >> 0x1fU))))
						 ? 
						((IData)(4U) 
						 + vlTOPp->Top__DOT__dpath__DOT__pc_reg)
						 : 
						((3U 
						  == 
						  ((IData)(vlTOPp->io_boot)
						    ? 0U
						    : 1U))
						  ? 
						 (0xf0000000U 
						  & vlTOPp->Top__DOT__dpath__DOT__pc_reg)
						  : 
						 ((0U 
						   == 
						   ((IData)(vlTOPp->io_boot)
						     ? 0U
						     : 1U))
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
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
	    Top__DOT__imm[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Top__DOT__imm___05FT_108_data = VL_RAND_RESET_I(32);
    Top__DOT__imm___05FT_121_data = VL_RAND_RESET_I(32);
    Top__DOT__imm___05FT_133_data = VL_RAND_RESET_I(32);
    Top__DOT___T_95 = VL_RAND_RESET_I(1);
    Top__DOT___T_123 = VL_RAND_RESET_I(1);
    Top__DOT__clk_cnt = VL_RAND_RESET_I(32);
    Top__DOT___T_142 = VL_RAND_RESET_I(32);
    Top__DOT__dpath__DOT__pc_reg = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    Top__DOT__dpath__DOT__RegFile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Top__DOT__dpath__DOT__RegFile___05FT_51_data = VL_RAND_RESET_I(32);
    Top__DOT__dpath__DOT__RegFile___05FT_52_data = VL_RAND_RESET_I(32);
    Top__DOT__dpath__DOT___T_107 = VL_RAND_RESET_I(32);
    Top__DOT__dpath__DOT___T_108 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<8888; ++__Vi0) {
	    Top__DOT__dmm__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Top__DOT__dmm__DOT__mem___05FT_10_data = VL_RAND_RESET_I(32);
    Top__DOT__dmm__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VTop::_configure_coverage(VTop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
