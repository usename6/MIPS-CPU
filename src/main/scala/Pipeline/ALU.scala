package Pipeline

import chisel3._
import chisel3.util._

object ALUFN
{
	//算术指令
	def FN_ADD      = 0.U(5.W)
	def FN_SUB	= 1.U(5.W)
	def FN_MULT	= 2.U(5.W)
	def FN_DIV 	= 3.U(5.W)
	def FN_SLT 	= 4.U(5.W)
	
	//逻辑指令 
	def FN_AND	= 5.U(5.W)
	def FN_OR	= 6.U(5.W)
	def FN_XOR 	= 7.U(5.W)
	def FN_NOR	= 8.U(5.W)
	def FN_BEQ	= FN_SUB
	def FN_NOP      = 9.U(5.W)
	def FN_LUI	= 10.U(5.W)
	def FN_LI	= 11.U(5.W)
	def FN_BNE	= 12.U(5.W)
	def FN_SLTU	= 13.U(5.W)
	def FN_MULTU	= 14.U(5.W)
	def FN_MFHI	= 15.U(5.W)
	def FN_MFLO	= 16.U(5.W)
	def FN_DIVU	= 17.U(5.W)
	def FN_MTHI	= 18.U(5.W)
	def FN_MTLO	= 19.U(5.W)
	def FN_SLLV	= 20.U(5.W)
	def FN_SLL	= 21.U(5.W)
	def FN_SRLV	= 22.U(5.W)
	def FN_SRL	= 23.U(5.W)
	def FN_SRAV	= 24.U(5.W)
	def FN_SRA	= 25.U(5.W)
	def FN_SLTIU	= 26.U(5.W)

	//def FN_MFLO	= 16.U(4.W)
	//移位指令

	//判断是加法还是减法 or 判断算术运算还是逻辑运算
    	def isSub(cmd: UInt) = (cmd === FN_SUB) || (cmd === FN_SLT)     //判断是否是SLT或减法运算
    	def is_arith(ctr: UInt) = (ctr === FN_ADD) || (ctr === FN_SUB)  || (ctr === FN_LUI) || (ctr === FN_LI)
	def is_logic(ctr: UInt) = (ctr === FN_AND) || (ctr === FN_OR) || (ctr === FN_XOR) || (ctr === FN_NOR) || (ctr === FN_BEQ) || (ctr === FN_BNE)
	def is_shift(ctr: UInt) = (ctr === FN_SLLV) || (ctr === FN_SLL) || (ctr === FN_SRLV) || (ctr === FN_SRL) || (ctr === FN_SRAV) || (ctr === FN_SRA)
}

import ALUFN._
class ALUio extends Bundle
{
	val in1  	= Input(UInt(32.W))
	val in2		= Input(UInt(32.W))
	val ALUctr 	= Input(UInt(5.W))
	val shamt	= Input(UInt(5.W))
	val boot 	= Input(Bool())
	val ALUout 	= Output(UInt(32.W))
	val cmp_out 	= Output(Bool())
}
class ALU9 extends Module
{
	val HI		= RegInit(0.U(32.W))
	val LO		= RegInit(0.U(32.W))
	val shang	= Wire(UInt(32.W))
	val shangs	= Wire(SInt(32.W))
	val mod		= Wire(UInt(32.W))
	val in1S	= Wire(SInt(32.W))
	val in2S	= Wire(SInt(32.W))
	val productS	= Wire(SInt(64.W))
	val sel1    = 1.U(32.W)
	val sel0    = 0.U(32.W)
	val io = IO(new ALUio)
	val cp_out  = Wire(Bool())
	val product = Wire(UInt(64.W))
	val arithmetic_out = Wire(UInt(32.W))
	val in2_inv = Mux(isSub(io.ALUctr), ~io.in2, io.in2)
	val in1_xor_in2 = io.in1 ^ io.in2
	val adder_out = io.in1 + in2_inv + isSub(io.ALUctr)
	val LUI_out   = Cat(io.in2(15,0),0.U(16.W))
	val shift_out	= Wire(UInt(32.W))
	val logic_out = Wire(UInt(32.W))
	val shin  = io.in2
	val shamt = io.in1(4,0)
	when(io.boot)
	{
		HI	:= 0.U
		LO	:= 0.U
	}
	when(io.ALUctr === FN_SRAV)
	{
		shift_out  := (Cat(shin(31),shin).asSInt >> shamt)(31,0)
	}
	when(io.ALUctr === FN_SRA)
	{
		shift_out  :=(Cat(shin(31),shin).asSInt >> io.shamt)(31,0)
	}
	when(io.ALUctr === FN_SLLV)
	{
		shift_out  :=	io.in2 << io.in1(4,0)
	}
	when(io.ALUctr === FN_SLL)
	{
		shift_out  :=	io.in2 << io.shamt
	}
	when(io.ALUctr === FN_SRLV)
	{
		shift_out  :=   io.in2 >> io.in1(4,0)
	}
	when(io.ALUctr === FN_SRL)
	{
		shift_out  :=   io.in2 >> io.shamt
	}
	when(io.ALUctr === FN_SLTU)
	{
		io.cmp_out := Mux(io.in1 > io.in2 || io.in1 === io.in2,false.B,true.B)
	}
	when(io.ALUctr === FN_ADD || io.ALUctr === FN_SUB)        //ADD & SUB 
	{
		arithmetic_out 	:= adder_out
		//printf("ADD or Sub\n")
	}
	when(io.ALUctr === FN_SLT)				  //SLT
	{
		//printf("SLT\n")
		//printf("adder_out = 0x%x\n",adder_out)
		//printf("io.in(31) = %d, io.in2(31) = %d\n",io.in1(31),io.in2(31))
		when(io.in1(31) != io.in2(31))
		{
			io.cmp_out := Mux(io.in1(31),true.B,false.B)
		}
		.otherwise
		{
			io.cmp_out := Mux(adder_out(31), true.B, false.B)
		}
	}
	when(io.ALUctr === FN_MULT)		          //MULT
	{
		productS :=  io.in1.toSInt * io.in2.toSInt
		HI 	:=  productS(63,32)
		LO	:=  productS(31,0)
	}
	when(io.ALUctr === FN_MULTU)
	{
		product :=  io.in1 * io.in2
		HI 	:=  product(63,32)
		LO	:=  product(31,0)
	}
	when(io.ALUctr === FN_MTHI)
	{
		HI	:= io.in1
	}
	when(io.ALUctr === FN_MTLO)
	{
		LO	:= io.in1
	}
	when(io.ALUctr === FN_DIV)				 //DIV
	{ 
		LO 	:=  (io.in1.asSInt / io.in2.asSInt)(31,0)
		HI	:=  (io.in1.asSInt % io.in2.asSInt)(31,0)
	}
	when(io.ALUctr === FN_DIVU)
	{
		HI	:= io.in1 % io.in2
		LO	:= io.in1 / io.in2
		//printf("shang = 0x%x mod = 0x%x\n",shang,mod)
	}
	when(io.ALUctr === FN_MFHI)
	{
		io.ALUout	:= 	HI
	}	

	when(io.ALUctr === FN_MFLO)
	{
		io.ALUout	:= 	LO
	}
	when(io.ALUctr === FN_AND)			        //AND
	{
		logic_out :=  io.in1 & io.in2
	}
	when(io.ALUctr === FN_OR)			        //OR
	{
		//printf("OR\n")
		logic_out :=  io.in1 | io.in2
	}
	when(io.ALUctr === FN_XOR)                        //XOR
	{
		logic_out :=  in1_xor_in2
	}
	when(io.ALUctr === FN_NOR)			       //NOR
	{
		logic_out :=  ~ (io.in1 | io.in2)
	}
	when(io.ALUctr === FN_BEQ)		               //BEQ
	{
		io.cmp_out  :=  (in1_xor_in2 === 0.U)
	}
	when(io.ALUctr === FN_BNE)			   //BNE
	{
		io.cmp_out  := ~(in1_xor_in2 === 0.U)
		printf("in1_xor_in2 = 0x%x\n",in1_xor_in2)
	}
	when(io.ALUctr === FN_LUI)			  //LUI
	{
		//printf("op is LUI\n")
		//val LUI_out	= Cat(io.in2(15,0))
		arithmetic_out := LUI_out
		//printf("io.in2 = 0x%x\n",io.in2(15,0))
		//printf("io.in2 = %d\n",(io.in2<<16))	
		//printf("io.in2 = %d\n",Cat(io.in2(15,0),sel0(15,0)))
		//printf("arithmetic_out = 0x%x\n",arithmetic_out)
	}
	when(io.ALUctr === FN_LI)			//LI
	{
		//printf("op is LI\n")
		//printf("arithmetic_out = 0x%x\n",arithmetic_out)
		arithmetic_out	:= io.in2
	}
	when(is_arith(io.ALUctr))
	{
		io.ALUout   :=   arithmetic_out
	}
	.elsewhen(io.ALUctr === FN_SLT || io.ALUctr === FN_SLTU)
	{
		io.ALUout   :=   Mux(io.cmp_out,sel1,sel0)
	}
	.elsewhen(is_logic(io.ALUctr))
	{
		io.ALUout   :=   logic_out
	} 
	.elsewhen(is_shift(io.ALUctr))
	{
		io.ALUout   := shift_out
	}
	//printf("thiS ALU unit ALUout = 0x%x\n",io.ALUout)
}
