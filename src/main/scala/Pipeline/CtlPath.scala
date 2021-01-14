

package Pipeline

import chisel3._
import chisel3.util._
import scala.math._

import Instructions._
object ctlsignle
{
	//RegDst
	val RegDst_Y		= true.B		// -> Rd
	val RegDst_N		= false.B		// -> Rt
	val RegDst_X		= true.B		// -> X

	//ALUsrc
	val ALUsrc_Y		= true.B		// -> Imm32
	val ALUsrc_N		= false.B		// -> BusB
	val ALUsrc_X		= true.B		// -> X

	//MemtoReg
	val MemtoReg_Y		= true.B		// -> mem
	val MemtoReg_N		= false.B		// -> ALUout
	val MemtoReg_X		= false.B		// -> X

	//控制Reg的使能值
	val RegWr_Y		= true.B
	val RegWr_N		= false.B

	//Cache Write
	val CacheW_Y		= true.B
	val CacheW_N		= false.B

	//ExtOp
	val ExtOp_Y		= true.B
	val ExtOp_N		= false.B
	val ExtOp_X		= false.B
	
	//PC_sel
	val PC_plus4		= 1.U(2.W)
	val PC_br		= 2.U(2.W)
	val j_target		= 3.U(2.W)
	val PC_0		= 0.U(2.W)

	//ALUctr
	//算术指令
	val FN_ADD      	= 0.U(5.W)
	val FN_SUB		= 1.U(5.W)
	val FN_MULT		= 2.U(5.W)
	val FN_DIV 		= 3.U(5.W)
	val FN_SLT 		= 4.U(5.W)
	
	//逻辑指令 
	val FN_AND		= 5.U(5.W)
	val FN_OR		= 6.U(5.W)
	val FN_XOR 		= 7.U(5.W)
	val FN_NOR		= 8.U(5.W)
	val FN_BEQ		= FN_SUB
	val FN_NOP      	= 9.U(5.W)
	val FN_LUI		= 10.U(5.W)
	val FN_LI		= 11.U(5.W)
	val FN_BNE		= 12.U(5.W)
	val FN_SLTU		= 13.U(5.W)
	val FN_MULTU		= 14.U(5.W)
	val FN_MFHI		= 15.U(5.W)
	val FN_MFLO		= 16.U(5.W)
	val FN_DIVU		= 17.U(5.W)
	val FN_MTHI		= 18.U(5.W)
	val FN_MTLO		= 19.U(5.W)
	val FN_SLLV		= 20.U(5.W)
	val FN_SLL		= 21.U(5.W)
	val FN_SRLV		= 22.U(5.W)
	val FN_SRL		= 23.U(5.W)
	val FN_SRAV		= 24.U(5.W)
	val FN_SRA		= 25.U(5.W)

	//MEMCTR
	val Mem_LB		=  1.U(4.W)
	val Mem_LBU		=  2.U(4.W)
	val Mem_LH		=  3.U(4.W)
	val Mem_LHU		=  4.U(4.W)
	val Mem_LW		=  5.U(4.W)
	val Mem_SB		=  6.U(4.W)
	val Mem_SH		=  7.U(4.W)
	val Mem_SW		=  8.U(4.W)
	val Mem_NOP		=  0.U(4.W)

	//Cache read
	val CacheR_Y		= true.B
	val CacheR_N		= false.B
}
import ctlsignle._
object list_ctlsignle
{
	val default				  = List(RegDst_N, ALUsrc_N, MemtoReg_N, RegWr_N, CacheW_N, PC_plus4 ,ExtOp_N, FN_NOP, Mem_NOP, CacheR_N)
	val inst_list		= Array(
				  LI		->  List(RegDst_N, ALUsrc_Y, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_LI, Mem_NOP , CacheR_N),
				  ADD 		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_ADD, Mem_NOP ,CacheR_N),
			 	  ADDI		->  List(RegDst_N, ALUsrc_Y, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_ADD, Mem_NOP ,CacheR_N),
				  ADDU		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_ADD, Mem_NOP ,CacheR_N),		
			          ADDIU		->  List(RegDst_N, ALUsrc_Y, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_ADD, Mem_NOP ,CacheR_N),		

			          SUB		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SUB, Mem_NOP ,CacheR_N),
				  SUBU		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SUB, Mem_NOP ,CacheR_N),		
				  SLT		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SLT, Mem_NOP ,CacheR_N),
				  SLTI		->  List(RegDst_N, ALUsrc_Y, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_SLT, Mem_NOP ,CacheR_N),
				  SLTU		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SLTU, Mem_NOP,CacheR_N),
				  SLTIU		->  List(RegDst_N, ALUsrc_Y, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_SLTU, Mem_NOP,CacheR_N),
					
			          MULT		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_N, CacheW_N, PC_plus4, ExtOp_N, FN_MULT, Mem_NOP,CacheR_N),
				  MULTU		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_N, CacheW_N, PC_plus4, ExtOp_N, FN_MULTU,Mem_NOP,CacheR_N),
				  DIV		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_N, CacheW_N, PC_plus4, ExtOp_N, FN_DIV,  Mem_NOP,CacheR_N),
				  DIVU		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_N, CacheW_N, PC_plus4, ExtOp_N, FN_DIVU, Mem_NOP,CacheR_N),

				  MFHI		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_MFHI, Mem_NOP,CacheR_N),
				  MFLO		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_MFLO, Mem_NOP,CacheR_N),
				  MTHI		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_N, CacheW_N, PC_plus4, ExtOp_N, FN_MTHI, Mem_NOP,CacheR_N),
				  MTLO		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_N, CacheW_N, PC_plus4, ExtOp_N, FN_MTLO, Mem_NOP,CacheR_N),
	
				  SLLV		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SLLV, Mem_NOP,CacheR_N),
			          SLL		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SLL,  Mem_NOP,CacheR_N),
				  SRLV		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SRLV, Mem_NOP,CacheR_N),
			  	  SRL		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SRL,  Mem_NOP,CacheR_N),
				  SRAV		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SRAV, Mem_NOP,CacheR_N),
				  SRA      	->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_SRA,  Mem_NOP,CacheR_N),
				  		
				  LB		->  List(RegDst_N, ALUsrc_Y, MemtoReg_Y, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_ADD,  Mem_LB ,CacheR_Y),
			          LBU		->  List(RegDst_N, ALUsrc_Y, MemtoReg_Y, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_ADD,  Mem_LBU,CacheR_Y),
				  LH		->  List(RegDst_N, ALUsrc_Y, MemtoReg_Y, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_ADD,  Mem_LH ,CacheR_Y),
				  LHU		->  List(RegDst_N, ALUsrc_Y, MemtoReg_Y, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_ADD,  Mem_LHU,CacheR_Y),
				  SB		->  List(RegDst_Y, ALUsrc_Y, MemtoReg_N, RegWr_N, CacheW_Y, PC_plus4, ExtOp_Y, FN_ADD,  Mem_SB ,CacheR_N),
				  SH		->  List(RegDst_Y, ALUsrc_Y, MemtoReg_N, RegWr_N, CacheW_Y, PC_plus4, ExtOp_Y, FN_ADD,  Mem_SH ,CacheR_N),	
				  LW		->  List(RegDst_Y, ALUsrc_Y, MemtoReg_Y, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_ADD,  Mem_LW ,CacheR_Y),
				  SW		->  List(RegDst_X, ALUsrc_Y, MemtoReg_X, RegWr_N, CacheW_Y, PC_plus4, ExtOp_Y, FN_ADD,  Mem_SW ,CacheR_N),			

				  AND		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_AND,  Mem_NOP,CacheR_N),
				  ANDI		->  List(RegDst_N, ALUsrc_Y, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_AND,  Mem_NOP,CacheR_N),
				  OR		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_OR ,  Mem_NOP,CacheR_N),
			  	  NOR		->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_NOR,  Mem_NOP,CacheR_N),
				  XOR	        ->  List(RegDst_Y, ALUsrc_N, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_XOR,  Mem_NOP,CacheR_N),
				  XORI		->  List(RegDst_N, ALUsrc_Y, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_XOR,  Mem_NOP,CacheR_N),
				  LUI		->  List(RegDst_N, ALUsrc_Y, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_Y, FN_LUI,  Mem_NOP,CacheR_N),
				  BNE		->  List(RegDst_X, ALUsrc_N, MemtoReg_X, RegWr_N, CacheW_N, PC_br,    ExtOp_Y, FN_BNE,  Mem_NOP,CacheR_N),

				  ORI		->  List(RegDst_N, ALUsrc_Y, MemtoReg_N, RegWr_Y, CacheW_N, PC_plus4, ExtOp_N, FN_OR ,  Mem_NOP,CacheR_N),
				  BEQ		->  List(RegDst_X, ALUsrc_X, MemtoReg_X, RegWr_N, CacheW_N, PC_br,    ExtOp_Y, FN_BEQ,  Mem_NOP,CacheR_N),
				  J		->  List(RegDst_X, ALUsrc_X, MemtoReg_X, RegWr_N, CacheW_N, j_target, ExtOp_X, FN_NOP,  Mem_NOP,CacheR_N),
				  NOP		->  List(RegDst_N, ALUsrc_N, MemtoReg_N, RegWr_N, CacheW_N, PC_plus4, ExtOp_X, FN_NOP,  Mem_NOP,CacheR_N)
				  )
}
import list_ctlsignle._
class CtltoDatIo extends Bundle()
{
	//控制通路的控制信号
	val RegWr		= Output(Bool())
	val RegDst		= Output(Bool())
	val ExtOp		= Output(Bool())
	val PC_sel		= Output(UInt(2.W))
	val ALUctr		= Output(UInt(5.W))
	val ALUsrc		= Output(Bool())
	val MemtoReg		= Output(Bool())
	val CacheW		= Output(Bool())
	val CacheR		= Output(Bool())
	val Memctr 		= Output(UInt(4.W))
	
	//译码出来的信息
	val Rd 			= Output(UInt(5.W))
	val Rt 			= Output(UInt(5.W))
	val Rs 			= Output(UInt(5.W))
	val Imm16 		= Output(UInt(16.W))
	val Imm26		= Output(UInt(26.W))
	val shamt		= Output(UInt(5.W))
}

class CPathIo extends Bundle()
{
	val Inst 		= Input(UInt(32.W))
	val boot		= Input(Bool())
	val ctl 		= new CtltoDatIo()
	val dat 		= Flipped(new DatToCtlIo)
}

class CtlPath extends Module()
{
	//定义变量
	val io 			= IO(new CPathIo ())
	//初始化信号
	io.ctl.CacheW := 0.U
	io.ctl.CacheR := 0.U
	io.ctl.RegWr := false.B
	
	//ctl_signle和其他控制信号相连
	when(!io.boot)
	{
		val ctl_signle = ListLookup(io.Inst,list_ctlsignle.default,list_ctlsignle.inst_list)
		io.ctl.RegDst	        := ctl_signle(0)
		io.ctl.ALUsrc		:= ctl_signle(1)
		io.ctl.MemtoReg	        := ctl_signle(2)
		io.ctl.RegWr		:= ctl_signle(3)
		io.ctl.CacheW		:= ctl_signle(4)
		io.ctl.PC_sel		:= ctl_signle(5)
		io.ctl.ExtOp		:= ctl_signle(6)
		io.ctl.ALUctr		:= ctl_signle(7)
		io.ctl.Memctr		:= ctl_signle(8)
		io.ctl.CacheR		:= ctl_signle(9)
		//printf("decode check : cpath.io.Inst	= 0x%x\n",io.Inst)
		//if(io.Inst == ADDI) printf("Yes It is ADDI\n")
		//val io.ctl.RegDst :: io.ctl.ALUsrc :: io.ctl.MemtoReg :: io.ctl.RegWr :: io.ctl.MemWr :: io.ctl.PC_sel :: io.ctl.ExtOp :: io.ctl.ALUctr = ctl_signle
	}
	.otherwise
	{
		io.ctl.RegDst	 := RegDst_X
		io.ctl.ALUsrc    := ALUsrc_X
		io.ctl.MemtoReg	 := MemtoReg_X
		io.ctl.RegWr	 := RegWr_N
		io.ctl.CacheW	 := CacheW_N
		io.ctl.CacheR	 := CacheR_N
		io.ctl.PC_sel	 := PC_plus4
		io.ctl.ExtOp	 := ExtOp_X
		io.ctl.ALUctr    := FN_NOP
		io.ctl.Memctr    := Mem_NOP
	}
	/**/

	io.ctl.Imm16 := Mux(((io.Inst(31,26) === "b000000".U(6.W) && io.Inst =/= 0.U) || (io.Inst(31,26) === "b000010".U(6.W))), 0.U, io.Inst(15, 0))
	io.ctl.shamt := io.Inst(10,6)
	io.ctl.Imm26 := Mux((io.Inst(31,26) === "b000010".U(6.W)), io.Inst(25, 0), 0.U)

	io.ctl.Rs := io.Inst(25, 21)
	io.ctl.Rt := io.Inst(20, 16)
	io.ctl.Rd := io.Inst(15, 11)
	//printf("io.Inst = 0x%x\n",io.Inst)
	//printf(" Rs = 0x%x, Rt = 0x%x, Rd = 0x%x\n", io.ctl.Rs,io.ctl.Rt,io.ctl.Rd)
}
