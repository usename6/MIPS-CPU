package Pipeline

import chisel3._
import chisel3.iotesters.Driver
import chisel3.util._
import java.io.PrintWriter

import MemFN._
object cachebit
{
	def is_a_bit(ctr:UInt)	  = (ctr === FN_LB) || (ctr === FN_LBU)
	def is_two_bit(ctr:UInt)  = (ctr === FN_LH) || (ctr === FN_LHU)
	def is_four_bit(ctr:UInt) = (ctr === FN_LW)
}
import cachebit._
class CacheIO extends Bundle()
{
	val Write_En	= Input(Bool())
	val Read_En	= Input(Bool())
	val data_In	= Input(UInt(32.W))
	val mem_addr	= Input(UInt(32.W))
	val boot	= Input(Bool())
	val data_Out	= Output(UInt(32.W))
	val Memctr	= Input(UInt(4.W))
	val cachemiss	= Output(Bool())	
}

class Cache extends Module()
{
	val io		= IO(new CacheIO())
	val cache 	= Mem(8,UInt(44.W))
	val dmm		= Module(new Mem())  //addr is 14 bit (2^13 === 8192)
	//cache inside:
	//***********************************//
	//  valid      tag           data    //
	//   43      42 - 32	     31-0    //
	//***********************************//
	val cacheaddr	= Wire(UInt(32.W))
	val content	= Wire(UInt(44.W))
	val data	= Wire(UInt(32.W))
	val wdata	= Wire(UInt(32.W))
	val rdata	= Wire(UInt(32.W))
	val tag		= Wire(UInt(11.W))
	val valid	= Wire(Bool())
	val signdat	= Wire(UInt(44.W))
	val unsigndat	= Wire(UInt(44.W))
	cacheaddr	:= io.mem_addr % 8.U			// 直接映射
	content		:= cache(cacheaddr) 
	tag		:= content(42,32)
	valid		:= content(43)
	
	when(io.boot)				 	// tag clear
	{
		cache(0)  := 0.U
		cache(1)  := 0.U
		cache(2)  := 0.U
		cache(3)  := 0.U
		cache(4)  := 0.U
		cache(5)  := 0.U
		cache(7)  := 0.U
	}	

	when(io.Write_En)				// write though
	{
		when(valid && tag === io.mem_addr(31,21))
		{
			io.cachemiss     := false.B
		}
		when((valid && tag =/= io.mem_addr(31,21)) || !valid)
		{
			io.cachemiss	 := true.B
		}
		when(io.Memctr === FN_SB)
		{
			cache(cacheaddr) := Cat("b1".U(1.W),io.mem_addr(13,3),"b0".U(24.W),wdata(7,0))
		}
		when(io.Memctr === FN_SH)
		{
			cache(cacheaddr) := Cat("b1".U(1.W),io.mem_addr(13,3),"b0".U(16.W),wdata(15,0))
		}
		when(io.Memctr === FN_SW)
		{
			cache(cacheaddr) := Cat("b1".U(1.W),io.mem_addr(13,3),"b0".U(16.W),wdata(31,0))
		} 
		dmm.io.mem_addr 	:= io.mem_addr >> 2
		dmm.io.Write_En		:= true.B			
		dmm.io.Read_En		:= false.B
		dmm.io.data_In		:= wdata
		dmm.io.Memctr		:= io.Memctr
	}
	when(io.Read_En)
	{
		when(valid && tag === io.mem_addr(31,21))	// is valid && is hit !!
		{
			io.cachemiss		:= false.B
			rdata			:= content(31,0)
		}
		when((valid && tag =/= io.mem_addr(31,21)) || !valid)  // is valid but not hit or is no valid
		{
			io.cachemiss		:= true.B
			dmm.io.mem_addr		:= io.mem_addr >> 2
			dmm.io.Write_En		:= false.B
			dmm.io.Read_En		:= true.B
			dmm.io.Memctr		:= io.Memctr
			rdata			:= dmm.io.data_Out
			when(is_a_bit(io.Memctr))				
			{
				unsigndat	    := Cat("b1".U(1.W),io.mem_addr(13,3),"b0".U(24.W),rdata(7,0))
				signdat	    	    := Cat("b1".U(1.W),io.mem_addr(13,3),Fill(24,rdata(7)),rdata(7,0))
				cache(cacheaddr)    := Mux(io.Memctr === FN_LB, signdat, unsigndat)
			}
			when(is_two_bit(io.Memctr))			       
			{
				unsigndat	    := Cat("b1".U(1.W),io.mem_addr(13,3),Fill(16,rdata(7)),rdata(15,0))
				signdat		    := Cat("b1".U(1.W),io.mem_addr(13,3),"b0".U(16.W),rdata(15,0))
				cache(cacheaddr)    := Mux(io.Memctr === FN_LH, signdat, unsigndat)
			}
			when(is_four_bit(io.Memctr))
			{
				unsigndat	    := Cat("b1".U(1.W),io.mem_addr(13,3),rdata(31,0))
				signdat		    := Cat("b1".U(1.W),io.mem_addr(13,3),rdata(31,0))
				cache(cacheaddr)    := signdat
			}	
		}
		//read cache
		when(io.Memctr === FN_LB)				// sign extend
		{
			io.data_Out := Cat(Fill(24,rdata(7)),rdata(7,0))
		}
		when(io.Memctr === FN_LBU)			        // unsigned extend 
		{
			io.data_Out := Cat("b0".U(24.W),rdata(7,0))
		}
		when(io.Memctr === FN_LHU)
		{
			io.data_Out := Cat(Fill(24,rdata(7)),rdata(15,0))
		}
		when(io.Memctr === FN_LW)
		{
			io.data_Out := rdata
		}
	}
}
