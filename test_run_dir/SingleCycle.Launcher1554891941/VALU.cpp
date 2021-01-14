// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU.h"              // For This
#include "VALU__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VALU) {
    VALU__Syms* __restrict vlSymsp = __VlSymsp = new VALU__Syms(this, name());
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VALU::__Vconfigure(VALU__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VALU::~VALU() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VALU::eval() {
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VALU::eval\n"); );
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

void VALU::_eval_initial_loop(VALU__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void VALU::_combo__TOP__1(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VALU::_combo__TOP__1\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ALU__DOT___T_13 = (vlTOPp->io_a | vlTOPp->io_b);
    vlTOPp->ALU__DOT___T_27 = (VL_ULL(0x1ffffffff) 
			       & ((QData)((IData)(vlTOPp->io_a)) 
				  - (QData)((IData)(vlTOPp->io_b))));
}

void VALU::_settle__TOP__2(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VALU::_settle__TOP__2\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ALU__DOT___T_13 = (vlTOPp->io_a | vlTOPp->io_b);
    vlTOPp->ALU__DOT___T_27 = (VL_ULL(0x1ffffffff) 
			       & ((QData)((IData)(vlTOPp->io_a)) 
				  - (QData)((IData)(vlTOPp->io_b))));
    vlTOPp->io_zero = (0U == (IData)(vlTOPp->ALU__DOT___T_27));
    vlTOPp->io_out = (IData)((VL_ULL(0x7fffffffffffffff) 
			      & ((0U == (IData)(vlTOPp->io_op))
				  ? (QData)((IData)(
						    (vlTOPp->io_a 
						     & vlTOPp->io_b)))
				  : ((1U == (IData)(vlTOPp->io_op))
				      ? (QData)((IData)(vlTOPp->ALU__DOT___T_13))
				      : ((2U == (IData)(vlTOPp->io_op))
					  ? (QData)((IData)(
							    (~ vlTOPp->ALU__DOT___T_13)))
					  : ((3U == (IData)(vlTOPp->io_op))
					      ? (QData)((IData)(
								(vlTOPp->io_a 
								 ^ vlTOPp->io_b)))
					      : ((4U 
						  == (IData)(vlTOPp->io_op))
						  ? (QData)((IData)(
								    (vlTOPp->io_a 
								     + vlTOPp->io_b)))
						  : 
						 ((5U 
						   == (IData)(vlTOPp->io_op))
						   ? (QData)((IData)(vlTOPp->ALU__DOT___T_27))
						   : 
						  ((6U 
						    == (IData)(vlTOPp->io_op))
						    ? 
						   ((QData)((IData)(vlTOPp->io_b)) 
						    << (IData)(vlTOPp->io_shamt))
						    : 
						   ((7U 
						     == (IData)(vlTOPp->io_op))
						     ? (QData)((IData)(
								       (vlTOPp->io_b 
									>> (IData)(vlTOPp->io_shamt))))
						     : 
						    ((8U 
						      == (IData)(vlTOPp->io_op))
						      ? (QData)((IData)(
									(vlTOPp->io_a 
									 < vlTOPp->io_b)))
						      : 
						     ((9U 
						       == (IData)(vlTOPp->io_op))
						       ? 
						      ((QData)((IData)(vlTOPp->io_b)) 
						       << 0x10U)
						       : VL_ULL(0)))))))))))));
}

VL_INLINE_OPT void VALU::_combo__TOP__3(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VALU::_combo__TOP__3\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_zero = (0U == (IData)(vlTOPp->ALU__DOT___T_27));
    vlTOPp->io_out = (IData)((VL_ULL(0x7fffffffffffffff) 
			      & ((0U == (IData)(vlTOPp->io_op))
				  ? (QData)((IData)(
						    (vlTOPp->io_a 
						     & vlTOPp->io_b)))
				  : ((1U == (IData)(vlTOPp->io_op))
				      ? (QData)((IData)(vlTOPp->ALU__DOT___T_13))
				      : ((2U == (IData)(vlTOPp->io_op))
					  ? (QData)((IData)(
							    (~ vlTOPp->ALU__DOT___T_13)))
					  : ((3U == (IData)(vlTOPp->io_op))
					      ? (QData)((IData)(
								(vlTOPp->io_a 
								 ^ vlTOPp->io_b)))
					      : ((4U 
						  == (IData)(vlTOPp->io_op))
						  ? (QData)((IData)(
								    (vlTOPp->io_a 
								     + vlTOPp->io_b)))
						  : 
						 ((5U 
						   == (IData)(vlTOPp->io_op))
						   ? (QData)((IData)(vlTOPp->ALU__DOT___T_27))
						   : 
						  ((6U 
						    == (IData)(vlTOPp->io_op))
						    ? 
						   ((QData)((IData)(vlTOPp->io_b)) 
						    << (IData)(vlTOPp->io_shamt))
						    : 
						   ((7U 
						     == (IData)(vlTOPp->io_op))
						     ? (QData)((IData)(
								       (vlTOPp->io_b 
									>> (IData)(vlTOPp->io_shamt))))
						     : 
						    ((8U 
						      == (IData)(vlTOPp->io_op))
						      ? (QData)((IData)(
									(vlTOPp->io_a 
									 < vlTOPp->io_b)))
						      : 
						     ((9U 
						       == (IData)(vlTOPp->io_op))
						       ? 
						      ((QData)((IData)(vlTOPp->io_b)) 
						       << 0x10U)
						       : VL_ULL(0)))))))))))));
}

void VALU::_eval(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VALU::_eval\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->_combo__TOP__3(vlSymsp);
}

void VALU::_eval_initial(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VALU::_eval_initial\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU::final() {
    VL_DEBUG_IF(VL_PRINTF("    VALU::final\n"); );
    // Variables
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU::_eval_settle(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VALU::_eval_settle\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VALU::_change_request(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VALU::_change_request\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VALU::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_a = VL_RAND_RESET_I(32);
    io_b = VL_RAND_RESET_I(32);
    io_op = VL_RAND_RESET_I(4);
    io_shamt = VL_RAND_RESET_I(5);
    io_out = VL_RAND_RESET_I(32);
    io_zero = VL_RAND_RESET_I(1);
    ALU__DOT___T_13 = VL_RAND_RESET_I(32);
    ALU__DOT___T_27 = VL_RAND_RESET_Q(33);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VALU::_configure_coverage(VALU__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VALU::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
