// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTop_H_
#define _VTop_H_

#include "verilated_heavy.h"
class VTop__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VTop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_boot,0,0);
    VL_IN8(io_test_im_wr,0,0);
    VL_IN8(io_test_im_rd,0,0);
    VL_IN8(io_test_dm_wr,0,0);
    VL_IN8(io_test_dm_rd,0,0);
    VL_OUT8(io_valid,0,0);
    VL_IN(io_test_im_addr,31,0);
    VL_IN(io_test_im_in,31,0);
    VL_OUT(io_test_im_out,31,0);
    VL_IN(io_test_dm_addr,31,0);
    VL_IN(io_test_dm_in,31,0);
    VL_OUT(io_test_dm_out,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(Top__DOT___T_21,0,0);
    VL_SIG8(Top__DOT___T_26,0,0);
    VL_SIG8(Top__DOT___GEN_32,0,0);
    VL_SIG8(Top__DOT__cpath__DOT___T_40,0,0);
    VL_SIG8(Top__DOT__cpath__DOT___T_96,0,0);
    VL_SIG8(Top__DOT__cpath__DOT___T_153,2,0);
    VL_SIG8(Top__DOT__dpath__DOT__alu9__DOT___T_11,0,0);
    //char	__VpadToAlign43[1];
    VL_SIG16(Top__DOT__cpath__DOT___T_83,10,0);
    VL_SIG16(Top__DOT__cpath__DOT___T_161,15,0);
    VL_SIG(Top__DOT__imm___05FT_34_data,31,0);
    VL_SIG(Top__DOT__imm___05FT_46_data,31,0);
    VL_SIG(Top__DOT__dmm___05FT_39_data,31,0);
    VL_SIG(Top__DOT__dmm___05FT_50_data,31,0);
    VL_SIG(Top__DOT__dmm___05FT_61_data,31,0);
    VL_SIG(Top__DOT___GEN_27,31,0);
    VL_SIG(Top__DOT__clk_cnt,31,0);
    VL_SIG(Top__DOT___T_58,31,0);
    VL_SIG(Top__DOT__dpath__DOT__pc_reg,31,0);
    VL_SIG(Top__DOT__dpath__DOT__RegFile___05FT_45_data,31,0);
    VL_SIG(Top__DOT__dpath__DOT__RegFile___05FT_46_data,31,0);
    VL_SIG(Top__DOT__dpath__DOT___T_118,31,0);
    VL_SIG(Top__DOT__dpath__DOT___T_119,31,0);
    VL_SIG(Top__DOT__dpath__DOT__alu9__DOT__in1_xor_in2,31,0);
    VL_SIG(Top__DOT__dpath__DOT__alu9__DOT__out,31,0);
    //char	__VpadToAlign108[4];
    VL_SIG64(Top__DOT__dpath__DOT__alu9__DOT___T_20,32,0);
    VL_SIG(Top__DOT__imm[256],31,0);
    VL_SIG(Top__DOT__dmm[1024],31,0);
    VL_SIG(Top__DOT__dpath__DOT__RegFile[32],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    //char	__VpadToAlign5373[3];
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VTop__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VTop& operator= (const VTop&);	///< Copying not allowed
    VTop(const VTop&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VTop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VTop();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VTop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VTop__Syms* symsp, bool first);
  private:
    static QData	_change_request(VTop__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__10(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__2(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__4(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__6(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__8(VTop__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VTop__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VTop__Syms* __restrict vlSymsp);
    static void	_eval_initial(VTop__Syms* __restrict vlSymsp);
    static void	_eval_settle(VTop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__11(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__7(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__9(VTop__Syms* __restrict vlSymsp);
    static void	traceChgThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__5(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__6(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
