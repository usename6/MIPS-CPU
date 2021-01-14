package Pipeline

import chisel3._
import chisel3.util._
import chisel3.iotesters.Driver
import java.io.PrintWriter
//import utils.ercesiMIPSRunner
class TopIO extends Bundle() {
    val test_wr     = Input(Bool())//1预先载入指令,0cpu工作
    val test_addr   = Input(UInt(32.W))
    val test_inst   = Input(UInt(32.W))
    val MEM_WB_inst  = Output(UInt(32.W)) 
    val CacheMiss   = Output(UInt(32.W))
    val CacheWork   = Output(UInt(32.W))
}
import Instructions._
class Top extends Module() 
{
	val io 		= IO(new TopIO())//in chisel3, io must be wrapped in IO(...) 
	val cpath	= Module(new CtlPath())
	val dpath 	= Module(new DatPath())
	val test_dmm_out = RegInit(0.U(32.W))
	val boot 	= (io.test_wr === true.B)
	val pc		= Module(new PC())
	cpath.io.ctl <> dpath.io.ctl
	cpath.io.dat <> dpath.io.dat
	cpath.io.boot 		:= boot
	dpath.io.boot 		:= boot
	io.CacheMiss		:= dpath.io.CacheMiss
	io.CacheWork		:= dpath.io.CacheWork

	val Reg_datIn			= Wire(UInt(32.W))
	val Reg_addr			= Wire(UInt(5.W))

	//risk
	val stallF			= RegInit(false.B)   // solve the data hazard  only for IF  stage
	val stallD			= RegInit(false.B)   // solve the data hazard  only for Dec stage
	val IFflush			= RegInit(false.B)   // solve the brunch hazard, give bubble to flush
	val IDflush			= RegInit(false.B)   // solve the brunch hazard, give bubble to flush
	val EXflush		 	= RegInit(false.B)
		
	//IF/ID reg
	val if_dec_reg_inst		= RegInit(0.U(32.W))
	val if_dec_reg_PC		= RegInit(0.U(32.W))
	val if_dec_reg_PC_en		= RegInit(true.B)	

	//ID/EX reg
	val dec_exe_reg_inst		= RegInit(0.U(32.W))
	val dec_exe_reg_PC		= RegInit(0.U(32.W))
	val dec_exe_reg_rd		= RegInit(0.U(32.W))
	val dec_exe_reg_rs		= RegInit(0.U(32.W))
	val dec_exe_reg_rt		= RegInit(0.U(32.W))
	val dec_exe_reg_BusA		= RegInit(0.U(32.W))
	val dec_exe_reg_BusB		= RegInit(0.U(32.W))
	val dec_exe_reg_imm32		= RegInit(0.U(32.W))
	val dec_exe_reg_CacheW		= RegInit(false.B)
	val dec_exe_reg_CacheR		= RegInit(false.B)
	val dec_exe_reg_RegWr		= RegInit(false.B)
	val dec_exe_reg_RegDst		= RegInit(false.B)
	val dec_exe_reg_ALUsrc		= RegInit(false.B)
	val dec_exe_reg_ALUctr		= RegInit(9.U(5.W))
	val dec_exe_reg_PC_sel		= RegInit(0.U(2.W))
	val dec_exe_reg_MemtoReg	= RegInit(false.B)
	val dec_exe_reg_Imm16		= RegInit(0.U(16.W))
	val dec_exe_reg_Imm26		= RegInit(0.U(26.W))
	val dec_exe_reg_ExtOp		= RegInit(false.B)
	val dec_exe_reg_PCsel		= RegInit(1.U(2.W))
	val dec_exe_reg_PC_en		= RegInit(true.B)
	val dec_exe_reg_shamt		= RegInit(0.U(5.W))
	val dec_exe_reg_Memctr		= RegInit(0.U(4.W))

	//EX/MEM reg
	val exe_mem_reg_inst		= RegInit(0.U(32.W))
	val exe_mem_reg_PC		= RegInit(0.U(32.W))
	val exe_mem_reg_rd		= RegInit(0.U(32.W))
	val exe_mem_reg_rs		= RegInit(0.U(32.W))
	val exe_mem_reg_rt		= RegInit(0.U(32.W))
	val exe_mem_reg_dmem_addr	= RegInit(0.U(32.W))
	val exe_mem_reg_datIn		= RegInit(0.U(32.W))
	val exe_mem_reg_regindx		= RegInit(0.U(5.W))
	val exe_mem_reg_regdatIn	= RegInit(0.U(32.W))
	val exe_mem_reg_CacheW		= RegInit(false.B)
	val exe_mem_reg_CacheR		= RegInit(false.B)
	val exe_mem_reg_RegWr		= RegInit(false.B)
	val exe_mem_reg_MemtoReg	= RegInit(false.B)
	val exe_mem_reg_ALUout		= RegInit(0.U(32.W))
	val exe_mem_reg_br_zero		= RegInit(false.B)
	val exe_mem_reg_PCsel		= RegInit(1.U(2.W))
	val exe_mem_reg_PC_br		= RegInit(0.U(32.W))
	val exe_mem_reg_j_target	= RegInit(0.U(32.W))
	val exe_mem_reg_PC_en		= RegInit(true.B)
	val exe_mem_reg_Memctr		= RegInit(0.U(4.W))
	
	//MEM/WB reg
	val mem_wb_reg_inst		= RegInit(0.U(32.W))
	val mem_wb_reg_PC		= RegInit(0.U(32.W))
	val mem_wb_reg_rd		= RegInit(0.U(32.W))
	val mem_wb_reg_rs		= RegInit(0.U(32.W))
	val mem_wb_reg_rt		= RegInit(0.U(32.W))
	val mem_wb_reg_regindx		= RegInit(0.U(5.W))
	val mem_wb_reg_regdatIn		= RegInit(0.U(32.W))
	val mem_wb_reg_RegWr		= RegInit(false.B)
	val mem_wb_reg_MemtoReg		= RegInit(false.B)
	val mem_wb_reg_ALUout		= RegInit(0.U(32.W))
	val mem_wb_reg_datOut		= RegInit(0.U(32.W))


	//val inst 	= Wire(UInt(32.W))
	val imm = Mem(8192,UInt(32.W))
	//val dmm = Mem(1024, UInt(32.W))
	val clk_cnt = RegInit(0.U(32.W))
/************************************/
/*  next PC unit		   */
/***********************************/

	val PC_addr 	= Wire(UInt(32.W))

	val pc_plus4 	= Wire(UInt(32.W))
	val pc_next  	= Wire(UInt(32.W))
	val pc_br    	= exe_mem_reg_PC_br
	val j_target 	= exe_mem_reg_j_target
	val imem_addr   = Wire(UInt(32.W))
	val zero 	= exe_mem_reg_br_zero

	val PC_en    = Wire(Bool())
	val PC_sel   = exe_mem_reg_PCsel
	PC_addr      := pc.io.PC_cur			//update PC_addr
	imem_addr    := pc.io.PC_cur
	cpath.io.Inst := 0.U
	pc_plus4 := PC_addr + 4.U(32.W)			// cal pc+4
	pc.io.boot := boot
	//printf("clk = %d , PC_sel = %d exe_mem_reg_PCsel = %d\n",clk_cnt,PC_sel,exe_mem_reg_PCsel)
	
	pc_next := MuxCase(pc_plus4,Array(
						(PC_sel === 1.U)                    ->pc_plus4,
						(PC_sel === 2.U && zero) 	    ->pc_br,   			//计算结果为0时并且此时是beq信号
				                (PC_sel === 3.U)		    ->j_target,
						(PC_sel === 0.U)		    ->PC_addr			// stay, for bubble
						))
	pc.io.PC_addr	:= Mux(boot,0.U,pc_next)
	pc.io.PC_en	:= Mux(boot,false.B,PC_en)
	// flush signal set
	IFflush := Mux((PC_sel === 3.U) || (PC_sel === 2.U && zero), true.B, false.B)
	IDflush := Mux((PC_sel === 3.U) || (PC_sel === 2.U && zero), true.B, false.B)
	EXflush	:= Mux((PC_sel === 3.U) || (PC_sel === 2.U && zero), true.B, false.B)
	when (boot)
	{
		imm(io.test_addr >> 2) := io.test_inst
		cpath.io.Inst 	   := 0.U
		PC_en		   := false.B
	} 
	when (!boot)
	{
		//printf("exe_mem_reg_regindx = 0x%x\n",exe_mem_reg_regindx)
		//printf("dec_exe_reg_rs = 0x%x\n",dec_exe_reg_rs)
		//printf("dec_exe_reg_rt = 0x%x\n",dec_exe_reg_rs)
		clk_cnt := clk_cnt + 1.U
		//printf("Cyc = %d,  ifetch_inst = 0x%x, cpath.io.inst = 0x%x, PC_addr = 0x%x\n",clk_cnt,if_dec_reg_inst,cpath.io.Inst,imem_addr)
	}

/**********************/
/* 	By pass	      */
/**********************/
	//Forward A
	when(exe_mem_reg_RegWr && exe_mem_reg_regindx =/= 0.U && (exe_mem_reg_regindx === dec_exe_reg_rs))
	{
		dpath.io.ForwardA	:= 	"b10".U(2.W)
	}
	.elsewhen(mem_wb_reg_RegWr && mem_wb_reg_regindx =/= 0.U && (mem_wb_reg_regindx === dec_exe_reg_rs))
	{
		dpath.io.ForwardA	:= 	"b01".U(2.W)
	}
	.otherwise
	{
		dpath.io.ForwardA	:= 	"b00".U(2.W)
	}

	//Forward B
	when(exe_mem_reg_RegWr && exe_mem_reg_regindx =/= 0.U && (exe_mem_reg_regindx === dec_exe_reg_rt) && dec_exe_reg_RegDst)
	{
		dpath.io.ForwardB	:=  	"b10".U(2.W)
	}
	.elsewhen(mem_wb_reg_RegWr && mem_wb_reg_regindx =/= 0.U && (mem_wb_reg_regindx === dec_exe_reg_rt)&& dec_exe_reg_RegDst)
	{
		dpath.io.ForwardB	:= 	"b01".U(2.W)
	}
	.otherwise
	{
		dpath.io.ForwardB	:= 	"b00".U(2.W)
	}

	//IF stage
	//如果不是是数据冒险的话，传数据给下一级
	when(!stallF && !boot && !IFflush)
	{
		if_dec_reg_PC		       := PC_addr
		if_dec_reg_inst 	       := imm(imem_addr >> 2)
		PC_en			       := true.B
		//printf("stallF out: if_dec_reg_inst = 0x%x\n",if_dec_reg_inst)
	}
	when((stallF || IFflush) && !boot)
	{
		PC_en	:= false.B
		//printf("stallF in: if_dec_reg_inst = 0x%x\n",if_dec_reg_inst)
	}
	cpath.io.Inst 		       := if_dec_reg_inst


	//DEC stage


	when(!stallD && !boot && !IDflush)
	{
		dec_exe_reg_CacheW	:= cpath.io.ctl.CacheW
		dec_exe_reg_CacheR	:= cpath.io.ctl.CacheR
		dec_exe_reg_RegWr	:= cpath.io.ctl.RegWr
		dec_exe_reg_RegDst	:= cpath.io.ctl.RegDst
		dec_exe_reg_ALUsrc	:= cpath.io.ctl.ALUsrc
		dec_exe_reg_ALUctr	:= cpath.io.ctl.ALUctr
		dec_exe_reg_MemtoReg	:= cpath.io.ctl.MemtoReg
		dec_exe_reg_ExtOp	:= cpath.io.ctl.ExtOp
		dec_exe_reg_PCsel	:= cpath.io.ctl.PC_sel
		dec_exe_reg_Memctr	:= cpath.io.ctl.Memctr
		
		dec_exe_reg_inst	:= if_dec_reg_inst
		dec_exe_reg_PC		:= if_dec_reg_PC
		dec_exe_reg_rs		:= cpath.io.ctl.Rs     
		dec_exe_reg_rt		:= cpath.io.ctl.Rt
		dec_exe_reg_rd		:= cpath.io.ctl.Rd
		dec_exe_reg_BusA	:= dpath.io.BusA_dat
		dec_exe_reg_BusB	:= dpath.io.BusB_dat
		dec_exe_reg_Imm16	:= cpath.io.ctl.Imm16
		dec_exe_reg_Imm26	:= cpath.io.ctl.Imm26
		dec_exe_reg_shamt	:= cpath.io.ctl.shamt
	}
	
	when((stallD || IDflush) && !boot)
	{
		dec_exe_reg_CacheW	:= false.B
		dec_exe_reg_CacheR	:= false.B
		dec_exe_reg_RegWr	:= false.B
		dec_exe_reg_RegDst	:= cpath.io.ctl.RegDst
		dec_exe_reg_ALUsrc	:= cpath.io.ctl.ALUsrc
		dec_exe_reg_ALUctr	:= cpath.io.ctl.ALUctr
		dec_exe_reg_MemtoReg	:= cpath.io.ctl.MemtoReg
		dec_exe_reg_ExtOp	:= cpath.io.ctl.ExtOp
		dec_exe_reg_PCsel	:= 0.U			// PC stay
	}
	dpath.io.shamt		:= dec_exe_reg_shamt
	dpath.io.rt_addr	:= dec_exe_reg_rt
	dpath.io.Imm16		:= dec_exe_reg_Imm16
	dpath.io.Imm26		:= dec_exe_reg_Imm26
	dpath.io.RegDst		:= dec_exe_reg_RegDst
	dpath.io.ALUsrc		:= dec_exe_reg_ALUsrc
	dpath.io.ALUctr		:= dec_exe_reg_ALUctr
	dpath.io.ExtOp		:= dec_exe_reg_ExtOp
	dpath.io.PC_addr	:= dec_exe_reg_PC
	dpath.io.Rd		:= dec_exe_reg_rd
	dpath.io.Rt		:= dec_exe_reg_rt
	dpath.io.BusA		:= dec_exe_reg_BusA
	dpath.io.BusB		:= dec_exe_reg_BusB
	exe_mem_reg_inst	:= dec_exe_reg_inst
	exe_mem_reg_PC		:= dec_exe_reg_PC
	exe_mem_reg_rs		:= dec_exe_reg_rs
	exe_mem_reg_rt		:= dec_exe_reg_rt
	exe_mem_reg_CacheW	:= dec_exe_reg_CacheW
	exe_mem_reg_CacheR	:= dec_exe_reg_CacheR
	exe_mem_reg_RegWr	:= dec_exe_reg_RegWr
	exe_mem_reg_MemtoReg	:= dec_exe_reg_MemtoReg
	exe_mem_reg_PCsel	:= dec_exe_reg_PCsel
	exe_mem_reg_br_zero	:= dpath.io.br_zero
	exe_mem_reg_PC_br	:= dpath.io.PC_br
	exe_mem_reg_j_target	:= dpath.io.j_target
	exe_mem_reg_Memctr	:= dec_exe_reg_Memctr
	dec_exe_reg_PC_en	:= if_dec_reg_PC_en

		

	//EX stage
	when(!boot)
	{
		//printf("exe_mem_reg_dmem_addr = 0x%x, dpath.io.dmem_addr = 0x%x, dpath.io.mem_addr = 0x%x\n",exe_mem_reg_dmem_addr,dpath.io.dmem_addr,dpath.io.mem_addr)
	}	
	exe_mem_reg_dmem_addr	:= dpath.io.dmem_addr
	exe_mem_reg_datIn	:= dpath.io.dmem_datIn
	exe_mem_reg_regindx	:= dpath.io.regindx
	exe_mem_reg_ALUout	:= dpath.io.alu9_out
	//printf("exe_mem_reg_ALUout = 0x%x, dpath.io.alu9_out 0x%x \n ",exe_mem_reg_ALUout, dpath.io.alu9_out)
	dpath.io.mem_datIn	:= exe_mem_reg_datIn		//mem dat
	dpath.io.mem_addr	:= exe_mem_reg_dmem_addr
	dpath.io.CacheW		:= exe_mem_reg_CacheW
	dpath.io.CacheR		:= exe_mem_reg_CacheR
	dpath.io.Memctr		:= exe_mem_reg_Memctr
	//WB stage
	mem_wb_reg_inst		:= exe_mem_reg_inst
	mem_wb_reg_PC		:= exe_mem_reg_PC
	mem_wb_reg_rs		:= exe_mem_reg_rs
	mem_wb_reg_rt		:= exe_mem_reg_rt
	mem_wb_reg_rd		:= exe_mem_reg_rd
	mem_wb_reg_regindx	:= exe_mem_reg_regindx
	mem_wb_reg_RegWr	:= exe_mem_reg_RegWr
	mem_wb_reg_MemtoReg	:= exe_mem_reg_MemtoReg
	mem_wb_reg_ALUout	:= exe_mem_reg_ALUout
	mem_wb_reg_datOut	:= dpath.io.dmem_datOut
	exe_mem_reg_PC_en	:= dec_exe_reg_PC_en

	when(EXflush && !boot)
	{
		mem_wb_reg_inst		:= 0.U
		mem_wb_reg_PC		:= 0.U
		mem_wb_reg_RegWr	:= false.B
		exe_mem_reg_PC_en	:= false.B
	}
	//PC_en			:= exe_mem_reg_PC_en
	dpath.io.wb_reg_indx	:= mem_wb_reg_regindx	
	dpath.io.RegWr		:= mem_wb_reg_RegWr
	dpath.io.MemtoReg	:= mem_wb_reg_MemtoReg
	dpath.io.ALUout		:= mem_wb_reg_ALUout
	dpath.io.dmem_rdata	:= mem_wb_reg_datOut
	io.MEM_WB_inst		:= mem_wb_reg_inst

		 //...
}
