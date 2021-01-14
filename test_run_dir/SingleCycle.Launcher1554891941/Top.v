`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif

module CtlPath(
  input  [31:0] io_Inst,
  input         io_boot,
  output [1:0]  io_ctl_PC_sel,
  output        io_ctl_ALUsrc
);
  wire  _T_23;
  wire  _GEN_0;
  wire [1:0] _GEN_5;
  assign _T_23 = io_boot == 1'h0;
  assign _GEN_0 = _T_23 ? 1'h0 : 1'h1;
  assign _GEN_5 = _T_23 ? 2'h1 : 2'h0;
  assign io_ctl_PC_sel = _GEN_5;
  assign io_ctl_ALUsrc = _GEN_0;
endmodule
module ALU9(
  input  [31:0] io_in1,
  input  [31:0] io_in2,
  output [31:0] io_ALUout,
  output        io_cmp_out
);
  wire [32:0] _T_18;
  wire [31:0] _T_19;
  wire [32:0] _T_25;
  wire [31:0] adder_out;
  wire [31:0] logic_out;
  wire  _T_34;
  wire  _T_35;
  wire  _T_36;
  wire  _T_37;
  wire  _GEN_1;
  wire [31:0] _T_56;
  wire [63:0] _GEN_15;
  assign _T_18 = io_in1 + io_in2;
  assign _T_19 = _T_18[31:0];
  assign _T_25 = _T_19 + 32'h0;
  assign adder_out = _T_25[31:0];
  assign _T_34 = io_in1[31];
  assign _T_35 = io_in2[31];
  assign _T_36 = _T_34 != _T_35;
  assign _T_37 = adder_out[31];
  assign _GEN_1 = _T_36 ? _T_37 : _T_37;
  assign _T_56 = io_in1 & io_in2;
  assign _GEN_15 = {{32'd0}, logic_out};
  assign io_ALUout = _GEN_15[31:0];
  assign io_cmp_out = _GEN_1;
  assign logic_out = _T_56;
endmodule
module DatPath(
  input         clock,
  input         reset,
  output [31:0] io_imem_addr,
  output [31:0] io_dmem_datIn,
  input  [1:0]  io_ctl_PC_sel,
  input         io_ctl_ALUsrc,
  output        io_dat_zero
);
  wire [31:0] BusA;
  wire [31:0] BusB;
  wire [31:0] BusWr;
  wire [31:0] pc_next;
  wire [31:0] pc_plus4;
  wire [31:0] pc_br;
  wire [31:0] alu9_io_in1;
  wire [31:0] alu9_io_in2;
  wire [31:0] alu9_io_ALUout;
  wire  alu9_io_cmp_out;
  reg [31:0] pc_reg;
  reg [31:0] _RAND_0;
  reg [31:0] RegFile [0:31];
  reg [31:0] _RAND_1;
  wire [31:0] RegFile__T_51_data;
  wire [4:0] RegFile__T_51_addr;
  wire [31:0] RegFile__T_52_data;
  wire [4:0] RegFile__T_52_addr;
  wire [31:0] RegFile__T_49_data;
  wire [4:0] RegFile__T_49_addr;
  wire  RegFile__T_49_mask;
  wire  RegFile__T_49_en;
  wire [31:0] RegFile__T_55_data;
  wire [4:0] RegFile__T_55_addr;
  wire  RegFile__T_55_mask;
  wire  RegFile__T_55_en;
  wire [31:0] _T_56;
  wire [3:0] _T_69;
  wire [29:0] _T_71;
  wire [31:0] j_target;
  wire [32:0] _T_83;
  wire [31:0] _T_84;
  wire [32:0] _T_85;
  wire [31:0] _T_86;
  wire [32:0] _T_88;
  wire [31:0] _T_89;
  wire  _T_95;
  wire  _T_97;
  wire  _T_98;
  wire  _T_100;
  wire  _T_102;
  wire [31:0] _T_104;
  wire [31:0] _T_105;
  wire [31:0] _T_106;
  wire [31:0] _T_107;
  wire [31:0] _T_108;
  wire  _T_111;
  ALU9 alu9 (
    .io_in1(alu9_io_in1),
    .io_in2(alu9_io_in2),
    .io_ALUout(alu9_io_ALUout),
    .io_cmp_out(alu9_io_cmp_out)
  );
  assign RegFile__T_51_addr = 5'h0;
  assign RegFile__T_51_data = RegFile[RegFile__T_51_addr];
  assign RegFile__T_52_addr = 5'h0;
  assign RegFile__T_52_data = RegFile[RegFile__T_52_addr];
  assign RegFile__T_49_data = 32'h0;
  assign RegFile__T_49_addr = 5'h0;
  assign RegFile__T_49_mask = 1'h1;
  assign RegFile__T_49_en = 1'h1;
  assign RegFile__T_55_data = BusWr;
  assign RegFile__T_55_addr = 5'h0;
  assign RegFile__T_55_mask = 1'h0;
  assign RegFile__T_55_en = 1'h0;
  assign _T_56 = alu9_io_ALUout;
  assign _T_69 = pc_reg[31:28];
  assign _T_71 = {_T_69,26'h0};
  assign j_target = {_T_71,2'h0};
  assign _T_83 = pc_reg + 32'h4;
  assign _T_84 = _T_83[31:0];
  assign _T_85 = pc_reg + 32'h0;
  assign _T_86 = _T_85[31:0];
  assign _T_88 = _T_86 + 32'h4;
  assign _T_89 = _T_88[31:0];
  assign _T_95 = io_ctl_PC_sel == 2'h1;
  assign _T_97 = io_ctl_PC_sel == 2'h2;
  assign _T_98 = _T_97 & io_dat_zero;
  assign _T_100 = io_ctl_PC_sel == 2'h3;
  assign _T_102 = io_ctl_PC_sel == 2'h0;
  assign _T_104 = _T_102 ? 32'h0 : pc_plus4;
  assign _T_105 = _T_100 ? j_target : _T_104;
  assign _T_106 = _T_98 ? pc_br : _T_105;
  assign _T_107 = _T_95 ? pc_plus4 : _T_106;
  assign _T_108 = io_ctl_ALUsrc ? 32'h0 : BusB;
  assign _T_111 = reset == 1'h0;
  assign io_imem_addr = pc_reg;
  assign io_dmem_datIn = BusB;
  assign io_dat_zero = alu9_io_cmp_out;
  assign BusA = RegFile__T_51_data;
  assign BusB = RegFile__T_52_data;
  assign BusWr = _T_56;
  assign pc_next = _T_107;
  assign pc_plus4 = _T_84;
  assign pc_br = _T_89;
  assign alu9_io_in1 = BusA;
  assign alu9_io_in2 = _T_108;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  `ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{$random}};
  pc_reg = _RAND_0[31:0];
  `endif // RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 32; initvar = initvar+1)
    RegFile[initvar] = _RAND_1[31:0];
  `endif // RANDOMIZE_MEM_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (reset) begin
      pc_reg <= 32'h0;
    end else begin
      pc_reg <= pc_next;
    end
    if(RegFile__T_49_en & RegFile__T_49_mask) begin
      RegFile[RegFile__T_49_addr] <= RegFile__T_49_data;
    end
    if(RegFile__T_55_en & RegFile__T_55_mask) begin
      RegFile[RegFile__T_55_addr] <= RegFile__T_55_data;
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_111) begin
          $fwrite(32'h80000002,"in1 = %d , in2 = %d aluout = %d\n",alu9_io_in1,alu9_io_in2,alu9_io_ALUout);
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
module Mem(
  input         clock,
  input         io_Write_En,
  input         io_Read_En,
  input  [31:0] io_data_In,
  input  [31:0] io_mem_addr,
  output [31:0] io_data_Out
);
  reg [31:0] mem [0:8887];
  reg [31:0] _RAND_0;
  wire [31:0] mem__T_10_data;
  wire [13:0] mem__T_10_addr;
  reg [31:0] _RAND_1;
  wire [31:0] mem__T_12_data;
  wire [13:0] mem__T_12_addr;
  wire  mem__T_12_mask;
  wire  mem__T_12_en;
  wire [13:0] _T_9;
  wire [31:0] _GEN_3;
  wire [13:0] _T_11;
  assign mem__T_10_addr = _T_9;
  `ifndef RANDOMIZE_GARBAGE_ASSIGN
  assign mem__T_10_data = mem[mem__T_10_addr];
  `else
  assign mem__T_10_data = mem__T_10_addr >= 14'h22b8 ? _RAND_1[31:0] : mem[mem__T_10_addr];
  `endif // RANDOMIZE_GARBAGE_ASSIGN
  assign mem__T_12_data = io_data_In;
  assign mem__T_12_addr = _T_11;
  assign mem__T_12_mask = io_Write_En;
  assign mem__T_12_en = io_Write_En;
  assign _T_9 = io_mem_addr[13:0];
  assign _GEN_3 = mem__T_10_data;
  assign _T_11 = io_mem_addr[13:0];
  assign io_data_Out = _GEN_3;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  _RAND_0 = {1{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 8888; initvar = initvar+1)
    mem[initvar] = _RAND_0[31:0];
  `endif // RANDOMIZE_MEM_INIT
  _RAND_1 = {1{$random}};
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if(mem__T_12_en & mem__T_12_mask) begin
      mem[mem__T_12_addr] <= mem__T_12_data;
    end
  end
endmodule
module Top(
  input         clock,
  input         reset,
  input         io_boot,
  input         io_test_im_wr,
  input         io_test_im_rd,
  input  [31:0] io_test_im_addr,
  input  [31:0] io_test_im_in,
  output [31:0] io_test_im_out,
  input         io_test_dm_wr,
  input         io_test_dm_rd,
  input  [31:0] io_test_dm_addr,
  input  [31:0] io_test_dm_in,
  output [31:0] io_test_dm_out
);
  wire [31:0] cpath_io_Inst;
  wire  cpath_io_boot;
  wire [1:0] cpath_io_ctl_PC_sel;
  wire  cpath_io_ctl_ALUsrc;
  wire  dpath_clock;
  wire  dpath_reset;
  wire [31:0] dpath_io_imem_addr;
  wire [31:0] dpath_io_dmem_datIn;
  wire [1:0] dpath_io_ctl_PC_sel;
  wire  dpath_io_ctl_ALUsrc;
  wire  dpath_io_dat_zero;
  reg [31:0] imm [0:4095];
  reg [31:0] _RAND_0;
  wire [31:0] imm__T_108_data;
  wire [11:0] imm__T_108_addr;
  wire [31:0] imm__T_121_data;
  wire [11:0] imm__T_121_addr;
  wire [31:0] imm__T_133_data;
  wire [11:0] imm__T_133_addr;
  wire [31:0] imm__T_98_data;
  wire [11:0] imm__T_98_addr;
  wire  imm__T_98_mask;
  wire  imm__T_98_en;
  wire  dmm_clock;
  wire  dmm_io_Write_En;
  wire  dmm_io_Read_En;
  wire [31:0] dmm_io_data_In;
  wire [31:0] dmm_io_mem_addr;
  wire [31:0] dmm_io_data_Out;
  wire  _T_95;
  wire [29:0] _T_96;
  wire [11:0] _T_97;
  wire  _T_102;
  wire [11:0] _T_107;
  wire [29:0] _T_114;
  wire  _T_118;
  wire [11:0] _T_120;
  wire [31:0] _GEN_14;
  wire  _T_123;
  wire [31:0] _GEN_16;
  wire [29:0] _GEN_17;
  wire  _GEN_18;
  wire  _T_129;
  wire [29:0] _T_131;
  wire [11:0] _T_132;
  reg [31:0] clk_cnt;
  reg [31:0] _RAND_1;
  wire [32:0] _T_141;
  wire [31:0] _T_142;
  CtlPath cpath (
    .io_Inst(cpath_io_Inst),
    .io_boot(cpath_io_boot),
    .io_ctl_PC_sel(cpath_io_ctl_PC_sel),
    .io_ctl_ALUsrc(cpath_io_ctl_ALUsrc)
  );
  DatPath dpath (
    .clock(dpath_clock),
    .reset(dpath_reset),
    .io_imem_addr(dpath_io_imem_addr),
    .io_dmem_datIn(dpath_io_dmem_datIn),
    .io_ctl_PC_sel(dpath_io_ctl_PC_sel),
    .io_ctl_ALUsrc(dpath_io_ctl_ALUsrc),
    .io_dat_zero(dpath_io_dat_zero)
  );
  Mem dmm (
    .clock(dmm_clock),
    .io_Write_En(dmm_io_Write_En),
    .io_Read_En(dmm_io_Read_En),
    .io_data_In(dmm_io_data_In),
    .io_mem_addr(dmm_io_mem_addr),
    .io_data_Out(dmm_io_data_Out)
  );
  assign imm__T_108_addr = _T_107;
  assign imm__T_108_data = imm[imm__T_108_addr];
  assign imm__T_121_addr = _T_120;
  assign imm__T_121_data = imm[imm__T_121_addr];
  assign imm__T_133_addr = _T_132;
  assign imm__T_133_data = imm[imm__T_133_addr];
  assign imm__T_98_data = io_test_im_in;
  assign imm__T_98_addr = _T_97;
  assign imm__T_98_mask = _T_95;
  assign imm__T_98_en = _T_95;
  assign _T_95 = io_boot & io_test_im_wr;
  assign _T_96 = io_test_im_addr[31:2];
  assign _T_97 = _T_96[11:0];
  assign _T_102 = reset == 1'h0;
  assign _T_107 = _T_96[11:0];
  assign _T_114 = io_test_dm_addr[31:2];
  assign _T_118 = io_boot & io_test_im_rd;
  assign _T_120 = _T_96[11:0];
  assign _GEN_14 = _T_118 ? imm__T_121_data : 32'h0;
  assign _T_123 = io_boot & io_test_dm_rd;
  assign _GEN_16 = _T_123 ? dmm_io_data_Out : 32'h0;
  assign _GEN_17 = _T_123 ? _T_114 : _T_114;
  assign _GEN_18 = _T_123 ? 1'h0 : 1'h1;
  assign _T_129 = io_boot == 1'h0;
  assign _T_131 = dpath_io_imem_addr[31:2];
  assign _T_132 = _T_131[11:0];
  assign _T_141 = clk_cnt + 32'h1;
  assign _T_142 = _T_141[31:0];
  assign io_test_im_out = _GEN_14;
  assign io_test_dm_out = _GEN_16;
  assign cpath_io_Inst = 32'h0;
  assign cpath_io_boot = io_boot;
  assign dpath_io_ctl_PC_sel = cpath_io_ctl_PC_sel;
  assign dpath_io_ctl_ALUsrc = cpath_io_ctl_ALUsrc;
  assign dpath_clock = clock;
  assign dpath_reset = reset;
  assign dmm_io_Write_En = _GEN_18;
  assign dmm_io_Read_En = _T_123;
  assign dmm_io_data_In = io_test_dm_in;
  assign dmm_io_mem_addr = {{2'd0}, _GEN_17};
  assign dmm_clock = clock;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  _RAND_0 = {1{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 4096; initvar = initvar+1)
    imm[initvar] = _RAND_0[31:0];
  `endif // RANDOMIZE_MEM_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  clk_cnt = _RAND_1[31:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if(imm__T_98_en & imm__T_98_mask) begin
      imm[imm__T_98_addr] <= imm__T_98_data;
    end
    if (reset) begin
      clk_cnt <= 32'h0;
    end else begin
      clk_cnt <= _T_142;
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_95 & _T_102) begin
          $fwrite(32'h80000002,"io.test_im_addr = 0x%h\n",_T_96);
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_95 & _T_102) begin
          $fwrite(32'h80000002,"io.test_in_im = 0x%h\n",io_test_im_in);
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_95 & _T_102) begin
          $fwrite(32'h80000002,"imm_data = 0x%h\n",imm__T_108_data);
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_102) begin
          $fwrite(32'h80000002,"Cyc=%d, pc=0x%h, Inst=0x%h, boot=%d, dmem_in = 0x%h, rd_dmm=0x%h, Mem_wr=%d\n",clk_cnt,dpath_io_imem_addr,cpath_io_Inst,cpath_io_boot,dpath_io_dmem_datIn,io_test_dm_out,1'h0);
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
