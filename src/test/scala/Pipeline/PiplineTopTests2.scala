package Pipeline

import chisel3.iotesters.PeekPokeTester
import java.io.PrintWriter
import java.io.File
import scala.io.Source
import scala.collection.mutable.ArrayBuffer

class PipelineTopTests(c: Top) extends PeekPokeTester(c) {

    //def addr_out    =  0x00004000
    val file        = new File("TestFiles")
    var inst_amount = 0
    var cycles      = 0
    var IPC         = 0
    var inst_last   = 0
    def base_addr   = 0
    var passed_num	= 0
    var no_passe_num= 0
    var test_num	= 0

    val no_passe_files = new ArrayBuffer[File]
    val no_passe_files_num = new ArrayBuffer[Int]

    def asUInt(InInt: Int) = (BigInt(InInt >>> 1) << 1) + (InInt & 1)

     // Reset the CPU
    def TopBoot() = {
        poke(c.io.test_wr, 1)
        poke(c.io.test_addr, 0)
        poke(c.io.test_inst, 0)
        // poke(c.io.test_dm_wr, 0)
        step(1)
    }

    def WriteImm (filename : File) = {

        var addr = 0
        var Inst = 0
        for (line <- Source.fromFile(filename).getLines){
           Inst = Integer.parseUnsignedInt(line, 16)
           poke(c.io.test_wr, 1)
           poke(c.io.test_addr, addr*4 + base_addr)
           poke(c.io.test_inst, asUInt(Inst))

           addr = addr + 1

           inst_amount = inst_amount + 1

           inst_last = Inst
           step(1)
        }
        poke(c.io.test_wr, 0)
    }

    def RunCpu (defcycle : Int, filename : File, test_num : Int) = 
    {

        var flag = 0
        var lastflag = 0
        //for (i <- 0 until defcycle)
       // {
        
          //poke(c.io.test_dm_wr, 0)
        
           while(lastflag < 1&&cycles< 20005/**peek(c.io.MEM_WB_inst) != (inst_last)*/) 
           {
                if(peek(c.io.MEM_WB_inst) == (inst_last)){
                    lastflag = lastflag +1
                }  
                poke(c.io.test_wr, 0)

                cycles = cycles + 1
                printf( "file = %s    cycles = %3d    MEM_WB_inst == %x    ", filename, cycles, peek(c.io.MEM_WB_inst) )
                if(peek(c.io.MEM_WB_inst) == 0 ) {
                    printf("??\t")
                }else {
                    printf("!! ")
                }
                printf( "inst_last == %x\n", inst_last )

                if( peek(c.io.MEM_WB_inst) == 0x26730001 ) {
                    flag = 1
                    printf("get s3reg,flag = %d\n",flag)
                    poke(c.io.test_wr, 1)
                    poke(c.io.test_addr, 0)
                    poke(c.io.test_inst, 0)
                }


                step(1)
           }
       // } 
       if(peek(c.io.CacheWork) != 0)
	{
		//val miss = peek(c.io.CacheMiss)
		//val tot  = peek(c.io.CacheWork)
		printf("Cache hit ratio = %.6f\n",peek(c.io.CacheMiss)/peek(c.io.CacheWork))    //精确到0.01
	}
        if ( flag == 1 ){
        	printf("the test file : %s is right!\n", filename)
        	printf("inst_amount = %3d    clycles = %3d    IPC = %.6f\n", inst_amount, cycles, (inst_amount * 1.0) /cycles )
        	passed_num = passed_num + 1
        }else {
        	printf("the test file : %s is wrong!\n", filename)
        	no_passe_files.insert(no_passe_num, filename)
        	no_passe_files_num.insert(no_passe_num, test_num)
        	no_passe_num = no_passe_num + 1
        }
    }

    def SubFile(dir: File): Iterator[File] = {
        val d = dir.listFiles.filter(_.isDirectory)
        val f = dir.listFiles.toIterator
        f ++ d.toIterator.flatMap(SubFile _)
    }

    //test all files in the TestFiles
    for( filename <- SubFile(file) )
    {
        printf("\nfilename = %s\n",filename)
        TopBoot()
        inst_amount = 0
        WriteImm(filename)
        cycles      = 0
        test_num = test_num + 1
        printf("\ntest_num : %2d\n", test_num)
 //       poke(c.io.rf_19_reset,1)
        step(1)
        //poke(c.io.rf_19_reset,0)
        RunCpu(20000, filename, test_num)
    }
    printf("\n\npassed_num: %2d  no_passe_num : %2d\n", passed_num, no_passe_num)
    if( no_passe_num > 0 ) {
    	printf("There are the no_passe_files:\n")
    	for(i <- 0 until no_passe_num) {
    		printf("%s in test_num %d\n", no_passe_files(i), no_passe_files_num(i))
    	}
    }
    printf("\n")
}
