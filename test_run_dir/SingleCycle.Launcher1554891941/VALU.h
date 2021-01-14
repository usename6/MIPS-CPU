// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VALU_H_
#define _VALU_H_

#include "verilated.h"
class VALU__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VALU) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_op,3,0);
    VL_IN8(io_shamt,4,0);
    VL_OUT8(io_zero,0,0);
    //char	__VpadToAlign5[3];
    VL_IN(io_a,31,0);
    VL_IN(io_b,31,0);
    VL_OUT(io_out,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG(ALU__DOT___T_13,31,0);
    //char	__VpadToAlign28[4];
    VL_SIG64(ALU__DOT___T_27,32,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign52[4];
    VALU__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VALU& operator= (const VALU&);	///< Copying not allowed
    VALU(const VALU&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VALU(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VALU();
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
    static void _eval_initial_loop(VALU__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VALU__Syms* symsp, bool first);
  private:
    static QData	_change_request(VALU__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__1(VALU__Syms* __restrict vlSymsp);
    static void	_combo__TOP__3(VALU__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VALU__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VALU__Syms* __restrict vlSymsp);
    static void	_eval_initial(VALU__Syms* __restrict vlSymsp);
    static void	_eval_settle(VALU__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(VALU__Syms* __restrict vlSymsp);
    static void	traceChgThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
