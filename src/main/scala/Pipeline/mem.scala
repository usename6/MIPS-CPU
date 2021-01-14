package Pipeline

import chisel3._
import chisel3.iotesters.Driver
import chisel3.util._
import java.io.PrintWriter
object MemFN
{
	def FN_LB	=  1.U(4.W)
	def FN_LBU	=  2.U(4.W)
	def FN_LH	=  3.U(4.W)
	def FN_LHU	=  4.U(4.W)
	def FN_LW	=  5.U(4.W)
	def FN_SB	=  6.U(4.W)
	def FN_SH	=  7.U(4.W)
	def FN_SW	=  8.U(4.W)
	def FN_NOP	=  0.U(4.W)
}
import MemFN._
class MemIO extends Bundle()
{
	val Write_En	= Input(Bool())
	val Read_En	= Input(Bool())
	val data_In	= Input(UInt(32.W))
	val mem_addr	= Input(UInt(32.W))
	val data_Out	= Output(UInt(32.W))
	val Memctr	= Input(UInt(4.W))	
}
class Mem extends Module()
{
	val io 	= IO(new MemIO)
	val mem = Mem(8192,UInt(32.W))
	val mem_addr = io.mem_addr % 8888.U
	val read_data = Wire(UInt(32.W))
	val write_data = Wire(UInt(32.W))
	when(io.Read_En)				//读使能信号为真
	{
		read_data  :=  mem(mem_addr)
		when(io.Memctr === FN_LB)				// sign extend
		{
			io.data_Out := Cat(Fill(24,read_data(7)),read_data(7,0))
		}
		when(io.Memctr === FN_LBU)			        // unsigned extend 
		{
			io.data_Out := Cat("b0".U(24.W),read_data(7,0))
		}
		when(io.Memctr === FN_LH)
		{
			io.data_Out := Cat(Fill(24,read_data(7)),read_data(7,0))
		}
		when(io.Memctr === FN_LHU)
		{
			io.data_Out := Cat(Fill(16,read_data(15)),read_data(15,0))
		}
		when(io.Memctr === FN_LW)
		{
			io.data_Out := read_data
		}
	}
	when(io.Write_En)				//写使能信号为真
	{
		write_data := io.data_In
		when(io.Memctr === FN_SB)
		{
			mem(mem_addr) := Cat("b0".U(24.W),write_data(7,0))
		}
		when(io.Memctr === FN_SH)
		{
			mem(mem_addr) := Cat("b0".U(16.W),write_data(15,0))
		}
		when(io.Memctr === FN_SW)
		{
			//printf("mem(0x%x) = 0x%x\n",io.mem_addr,mem(io.mem_addr))
			mem(mem_addr) := write_data
		} 
	}
}
