

package Pipeline

import chisel3._
import chisel3.util._
import ALUFN._

class DatToCtlIo extends Bundle()
{
	val zero = Output(Bool())
}

class DPathIo extends Bundle()
{
	val Imm16		= Input(UInt(16.W))
	val Imm26		= Input(UInt(26.W))
	val dmem_rdata		= Input(UInt(32.W))
	val RegDst	 	= Input(Bool())
	val ALUsrc		= Input(Bool())
	val ALUctr		= Input(UInt(5.W))
	val ExtOp		= Input(Bool())
	val RegWr		= Input(Bool())
	val PC_addr		= Input(UInt(32.W))
	val Rt			= Input(UInt(32.W))
	val Rd			= Input(UInt(32.W))
	val MemtoReg		= Input(Bool())
	val CacheW		= Input(Bool())
	val CacheR		= Input(Bool())
	val ALUout		= Input(UInt(32.W))
	val wb_reg_indx		= Input(UInt(5.W))
	val wb_reg_datOut	= Input(UInt(32.W))
	val test_dm_wr		= Input(Bool())
	val test_dm_rd 		= Input(Bool())
	val test_dm_addr 	= Input(UInt(32.W))
	val test_dm_in 		= Input(UInt(32.W))
	val mem_datIn		= Input(UInt(32.W))
	val mem_addr		= Input(UInt(32.W))
	val boot 		= Input(Bool())
	val BusA		= Input(UInt(32.W))
	val BusB		= Input(UInt(32.W))
	val ForwardA		= Input(UInt(2.W))
	val ForwardB		= Input(UInt(2.W))
	val ForwardC		= Input(Bool())
	val rt_addr	 	= Input(UInt(5.W))
	val shamt		= Input(UInt(5.W))
	val Memctr		= Input(UInt(4.W))

	val dmem_addr		= Output(UInt(32.W))
	val dmem_datIn		= Output(UInt(32.W))
	val dmem_datOut		= Output(UInt(32.W))
	val BusA_dat		= Output(UInt(32.W))
	val BusB_dat    	= Output(UInt(32.W))
	val regindx     	= Output(UInt(5.W))
 	val regdatIn		= Output(UInt(32.W))
	val alu9_out		= Output(UInt(32.W))
	val ctl  		= Flipped(new CtltoDatIo)
	val dat  		= new DatToCtlIo()
	val test_dm_out 	= Output(UInt(32.W))
	val PC_sel		= Output(Bool())
	val PC_br 		= Output(UInt(32.W))
	val j_target		= Output(UInt(32.W))
	val br_zero		= Output(Bool())
	val CacheMiss		= Output(UInt(32.W))
	val CacheWork		= Output(UInt(32.W))
}

class DatPath extends Module 
{
	val io = IO(new DPathIo ())
	val BusA 	= Wire(UInt(32.W))
	val BusB 	= Wire(UInt(32.W))
	val BusWr 	= Wire(UInt(32.W))
	val pc_next 	= Wire(UInt(32.W))
	val pc_plus4	= Wire(UInt(32.W))
	val pc_br 	= Wire(UInt(32.W))

	val dcache = Module(new Cache())
	val alu9 = Module(new ALU9())
	val CacheMiss = RegInit(0.U(32.W))
	val CacheWork = RegInit(0.U(32.W))


	val RegFile = Mem(32, UInt(32.W))
	when(io.boot)
	{
		RegFile(1)	:= 0.U
		RegFile(2)	:= 0.U
		RegFile(3)	:= 0.U
		RegFile(4)	:= 0.U
		RegFile(5)	:= 0.U
		RegFile(6)	:= 0.U
		RegFile(7)	:= 0.U
		RegFile(8)	:= 0.U

		RegFile(9)	:= 0.U
		RegFile(10)	:= 0.U
		RegFile(11)	:= 0.U
		RegFile(12)	:= 0.U
		RegFile(13)	:= 0.U
		RegFile(14)	:= 0.U
		RegFile(15)	:= 0.U
		RegFile(16)	:= 0.U

		RegFile(17)	:= 0.U
		RegFile(18)	:= 0.U
		RegFile(19)	:= 0.U
		RegFile(20)	:= 0.U
		RegFile(21)	:= 0.U
		RegFile(22)	:= 0.U
		RegFile(23)	:= 0.U
		RegFile(24)	:= 0.U

		RegFile(25)	:= 0.U
		RegFile(26)	:= 0.U
		RegFile(27)	:= 0.U
		RegFile(28)	:= 0.U
		RegFile(29)	:= 0.U
		RegFile(30)	:= 0.U
		RegFile(31)	:= 0.U
		CacheWork	:= 0.U
		CacheMiss	:= 0.U
	}
	RegFile(0) := 0.U		// 0 寄存器永远是 0
    	
	//dec stage
	BusA := Mux(io.wb_reg_indx === io.ctl.Rs && io.ctl.Rs =/= 0.U,io.regdatIn,RegFile(io.ctl.Rs))
	BusB := Mux(io.wb_reg_indx === io.ctl.Rt && io.ctl.Rt =/= 0.U,io.regdatIn,RegFile(io.ctl.Rt))
	io.BusA_dat  := BusA
	io.BusB_dat  := BusB
	//EXE stage
// PC_Br && J_target cal
	val br_sext= Cat(Fill(15, io.Imm16(15)), io.Imm16(14, 0), Fill(2, io.Imm16(15)))
	val j_target = Cat(io.PC_addr(31, 28), io.Imm26, 0.U(2.W)) 					//cal j_target
	val Imm32	= Mux(io.ExtOp, Cat(Fill(17, io.Imm16(15)), io.Imm16(14, 0)),
					Cat("b0".U(16.W), io.Imm16(15, 0)))

	pc_br := io.PC_addr + br_sext + 4.U(32.W)		// cal pc_br

	io.j_target 	:= j_target
	io.PC_br	:= pc_br

//----------------------------------------//
//------------------ALU-------------------//
//----------------------------------------//
	alu9.io.shamt	:= io.shamt
	alu9.io.boot	:= io.boot
	val tmp_in1	= Wire(UInt(32.W))
	tmp_in1		:= io.BusA
	val tmp_in2	= Wire(UInt(32.W))
	tmp_in2		:= Mux(io.ALUsrc, Imm32, RegFile(io.rt_addr))
	val alu_out	= RegInit(0.U(32.W))
	alu_out 	:= alu9.io.ALUout
	alu9.io.ALUctr 	:= io.ALUctr
	//alu9.io.in1 	:= Mux(io.ForwardA,alu_out,tmp_in1)
	//alu9.io.in2 	:= Mux(io.ForwardB,alu_out,tmp_in2)
	when(io.ForwardA === 2.U)
	{
		alu9.io.in1	:=  alu_out
	}	
	when(io.ForwardA === 1.U)
	{
		alu9.io.in1	:= BusWr
	}
	when(io.ForwardA === 0.U)
	{
		alu9.io.in1	:= tmp_in1
	}
	
	when(io.ForwardB === 2.U)
	{
		alu9.io.in2	:= alu_out
	}	
	when(io.ForwardB === 1.U)
	{
		alu9.io.in2	:= BusWr
	}
	when(io.ForwardB === 0.U)
	{
		alu9.io.in2	:= tmp_in2
	}

	io.dat.zero 	:= alu9.io.cmp_out
	io.dmem_addr 	:= alu9.io.ALUout
	io.dmem_datIn 	:= io.BusB
	io.alu9_out	:= alu9.io.ALUout
	

	
	BusWr := Mux(io.MemtoReg, io.dmem_rdata, io.ALUout)
	io.regdatIn	:= BusWr
	io.br_zero	:= io.dat.zero
	
	// mem stage
	//printf("BusWr	=  0x%x\n", io.regdatIn)
	when(!io.boot)
	{
		/*printf("BusWr = 0x%x io.regdatIn = 0x%x io.wb_reg_indx = 0x%x,io.ctl.Rt = 0x%x, io.ctl.Rs = 0x%x\n ",BusWr,io.regdatIn,io.wb_reg_indx,io.ctl.Rt,io.ctl.Rs)
		printf("forwardA = %d ,forwardB = %d\n", io.ForwardA, io.ForwardB)
		printf("RegFile(0) = 0x%x\n",RegFile(0))
		printf("in1 = 0x%x , in2 = 0x%x aluout = 0x%x cmp_out = %d io.dmem_addr = 0x%x\n",alu9.io.in1,alu9.io.in2,io.alu9_out,alu9.io.cmp_out,io.dmem_addr % 888888.U)*/
		//if(io.MemWr == true.B)printf("	MemWr is true !\n")
		when (io.CacheW) 		//write
		{
			dcache.io.mem_addr 		:= io.mem_addr >> 2
			dcache.io.Write_En		:= true.B			
			dcache.io.Read_En		:= false.B
			dcache.io.data_In		:= io.mem_datIn
			dcache.io.Memctr		:= io.Memctr
			CacheWork			:= CacheWork + 1.U
			CacheMiss			:= Mux(dcache.io.cachemiss,CacheMiss + 1.U, CacheMiss)
		}
		when(!io.CacheR)			// read
		{
			dcache.io.mem_addr		:= io.mem_addr >> 2
			dcache.io.Write_En		:= false.B
			dcache.io.Read_En		:= true.B
			dcache.io.Memctr		:= io.Memctr
			io.dmem_datOut			:= dcache.io.data_Out
			io.CacheWork			:= CacheWork + 1.U
			CacheMiss			:= Mux(dcache.io.cachemiss,CacheMiss + 1.U, CacheMiss)

		}
	}
	io.CacheWork	:= CacheWork
	io.CacheMiss    := CacheMiss
	//write back stage
	io.regindx := Mux(io.RegDst, io.Rd, io.Rt)

	// Write Register
	when (io.RegWr === true.B && io.wb_reg_indx =/= 0.U) 
	{
		RegFile(io.wb_reg_indx) := BusWr
		//printf("io.wb_reg_indx = 0x%x\n",io.wb_reg_indx)
		//printf("io.wb_reg_datOut = 0x%x\n",BusWr)	
		//printf("$v0 = 0x%x, $a0 = 0x%x, $t0 = 0x%x, $t1 = 0x%x, $s0 = 0x%x, $s2 = 0x%x\n",RegFile(2),RegFile(4),RegFile(8),RegFile(9),RegFile(16),RegFile(18))
	}
}
