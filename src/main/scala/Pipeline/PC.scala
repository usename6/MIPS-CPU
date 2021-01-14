package Pipeline

import chisel3._
import chisel3.util._
import chisel3.iotesters.Driver

class PCIO extends Bundle()
{
	val PC_addr 	= Input(UInt(32.W))
	val PC_en   	= Input(Bool())
	val boot	= Input(Bool())
	val PC_cur  	= Output(UInt(32.W))
}
class PC extends Module()
{
	val io = IO(new PCIO())
	val PC_reg = RegInit(0.U)
	val PC_stay = PC_reg
	//printf("PC_en = %d, io.PC_cur = %d io.PC_addr = 0x%x\n",io.PC_en,io.PC_cur,io.PC_addr)
	when(!io.boot)
	{
		PC_reg   := Mux(io.PC_en, io.PC_addr, PC_stay)
	}
	when(io.boot)
	{
		PC_reg	 := 0.U
	}
	io.PC_cur := PC_reg
}
