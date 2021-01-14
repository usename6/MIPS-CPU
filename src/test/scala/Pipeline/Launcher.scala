package Pipeline

import chisel3._
import chisel3.iotesters.Driver
import utils.ercesiMIPSRunner

object Launcher {
  val tests = Map(
    "Top" -> { (backendName: String) =>
      Driver(() => new Top(), backendName) 
      {
        (c) => new PipelineTopTests(c)
      }
    }
  )

  def main(args: Array[String]): Unit = {
    ercesiMIPSRunner(tests, args) 
  }
}
