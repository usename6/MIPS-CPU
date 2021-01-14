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
  output        io_MemWr,
  output        io_valid,
  output        io_ctl_nPC_sel,
  output        io_ctl_RegWr,
  output        io_ctl_RegDst,
  output        io_ctl_ExtOp,
  output [2:0]  io_ctl_ALUctr,
  output        io_ctl_ALUsrc,
  output        io_ctl_MemtoReg,
  output [4:0]  io_ctl_Rd,
  output [4:0]  io_ctl_Rt,
  output [4:0]  io_ctl_Rs,
  output [15:0] io_ctl_Imm16,
  output [25:0] io_ctl_Imm26,
  input         io_dat_zero
);
  wire [10:0] ctl_signle;
  wire  Jump;
  wire [2:0] ALUop;
  wire  ALUctr2;
  wire  ALUctr1;
  wire  ALUctr0;
  wire  _T_30;
  wire  _T_31;
  wire  _T_32;
  wire  _T_33;
  wire  _T_34;
  wire  _T_36;
  wire  _T_38;
  wire  _T_39;
  wire  _T_40;
  wire  _T_41;
  wire  _T_42;
  wire [2:0] _T_43;
  wire [5:0] _T_46;
  wire  _T_48;
  wire  _T_50;
  wire  _T_51;
  wire  _T_55;
  wire  _T_59;
  wire  _T_63;
  wire  _T_67;
  wire  _T_71;
  wire  _T_74;
  wire [10:0] _T_76;
  wire [10:0] _T_77;
  wire [10:0] _T_78;
  wire [10:0] _T_79;
  wire [10:0] _T_80;
  wire [10:0] _T_81;
  wire [10:0] _T_82;
  wire [10:0] _T_83;
  wire  _T_85;
  wire  _T_88;
  wire  _T_89;
  wire  _T_90;
  wire  _T_91;
  wire  _T_92;
  wire  _T_94;
  wire  _T_95;
  wire  _T_96;
  wire  _T_97;
  wire  _T_98;
  wire  _T_99;
  wire  _T_100;
  wire  _T_101;
  wire  _T_102;
  wire  _T_105;
  wire  _T_106;
  wire  _T_107;
  wire  _T_114;
  wire  _T_115;
  wire  _T_119;
  wire  _T_121;
  wire  _T_122;
  wire  _T_123;
  wire  _T_125;
  wire  _T_127;
  wire  _T_128;
  wire  _T_130;
  wire  _T_131;
  wire  _T_134;
  wire  _T_137;
  wire  _T_139;
  wire  _T_142;
  wire  _T_143;
  wire  _T_145;
  wire [1:0] _T_150;
  wire [2:0] _T_151;
  wire [2:0] _T_152;
  wire [2:0] _T_153;
  wire  _T_155;
  wire  _T_158;
  wire [15:0] _T_160;
  wire [15:0] _T_161;
  wire [25:0] _T_164;
  wire [25:0] _T_166;
  wire [4:0] _T_167;
  wire [4:0] _T_168;
  wire [4:0] _T_169;
  assign _T_30 = ctl_signle[10];
  assign _T_31 = ctl_signle[9];
  assign _T_32 = ctl_signle[8];
  assign _T_33 = ctl_signle[7];
  assign _T_34 = ctl_signle[6];
  assign _T_36 = ctl_signle[5];
  assign _T_38 = io_dat_zero & _T_36;
  assign _T_39 = Jump ? _T_36 : _T_38;
  assign _T_40 = io_boot ? 1'h0 : _T_39;
  assign _T_41 = ctl_signle[4];
  assign _T_42 = ctl_signle[3];
  assign _T_43 = ctl_signle[2:0];
  assign _T_46 = io_Inst[31:26];
  assign _T_48 = _T_46 == 6'h0;
  assign _T_50 = io_Inst != 32'h0;
  assign _T_51 = _T_48 & _T_50;
  assign _T_55 = _T_46 == 6'hd;
  assign _T_59 = _T_46 == 6'h23;
  assign _T_63 = _T_46 == 6'h2b;
  assign _T_67 = _T_46 == 6'h4;
  assign _T_71 = _T_46 == 6'h2;
  assign _T_74 = io_Inst == 32'h0;
  assign _T_76 = _T_74 ? 11'h0 : 11'h7ff;
  assign _T_77 = _T_71 ? 11'h37 : _T_76;
  assign _T_78 = _T_67 ? 11'h29 : _T_77;
  assign _T_79 = _T_63 ? 11'h248 : _T_78;
  assign _T_80 = _T_59 ? 11'h388 : _T_79;
  assign _T_81 = _T_55 ? 11'h282 : _T_80;
  assign _T_82 = _T_51 ? 11'h484 : _T_81;
  assign _T_83 = io_boot ? 11'h8 : _T_82;
  assign _T_85 = ctl_signle == 11'h7ff;
  assign _T_88 = _T_85 ? 1'h0 : 1'h1;
  assign _T_89 = ALUop[2];
  assign _T_90 = ~ _T_89;
  assign _T_91 = ALUop[0];
  assign _T_92 = _T_90 & _T_91;
  assign _T_94 = io_Inst[2];
  assign _T_95 = ~ _T_94;
  assign _T_96 = _T_89 & _T_95;
  assign _T_97 = io_Inst[1];
  assign _T_98 = _T_96 & _T_97;
  assign _T_99 = io_Inst[0];
  assign _T_100 = ~ _T_99;
  assign _T_101 = _T_98 & _T_100;
  assign _T_102 = _T_92 | _T_101;
  assign _T_105 = ALUop[1];
  assign _T_106 = ~ _T_105;
  assign _T_107 = _T_90 & _T_106;
  assign _T_114 = _T_96 & _T_100;
  assign _T_115 = _T_107 | _T_114;
  assign _T_119 = _T_90 & _T_105;
  assign _T_121 = io_Inst[3];
  assign _T_122 = ~ _T_121;
  assign _T_123 = _T_89 & _T_122;
  assign _T_125 = _T_123 & _T_94;
  assign _T_127 = ~ _T_97;
  assign _T_128 = _T_125 & _T_127;
  assign _T_130 = _T_128 & _T_99;
  assign _T_131 = _T_119 | _T_130;
  assign _T_134 = _T_89 & _T_121;
  assign _T_137 = _T_134 & _T_95;
  assign _T_139 = _T_137 & _T_97;
  assign _T_142 = _T_139 & _T_100;
  assign _T_143 = _T_131 | _T_142;
  assign _T_145 = ctl_signle == 11'h8;
  assign _T_150 = {ALUctr2,ALUctr1};
  assign _T_151 = {_T_150,ALUctr0};
  assign _T_152 = _T_74 ? 3'h0 : _T_151;
  assign _T_153 = _T_145 ? 3'h3 : _T_152;
  assign _T_155 = ALUop == 3'h4;
  assign _T_158 = _T_155 | Jump;
  assign _T_160 = io_Inst[15:0];
  assign _T_161 = _T_158 ? 16'h0 : _T_160;
  assign _T_164 = io_Inst[25:0];
  assign _T_166 = Jump ? _T_164 : 26'h0;
  assign _T_167 = io_Inst[25:21];
  assign _T_168 = io_Inst[20:16];
  assign _T_169 = io_Inst[15:11];
  assign io_MemWr = _T_34;
  assign io_valid = _T_88;
  assign io_ctl_nPC_sel = _T_40;
  assign io_ctl_RegWr = _T_33;
  assign io_ctl_RegDst = _T_30;
  assign io_ctl_ExtOp = _T_42;
  assign io_ctl_ALUctr = _T_153;
  assign io_ctl_ALUsrc = _T_31;
  assign io_ctl_MemtoReg = _T_32;
  assign io_ctl_Rd = _T_169;
  assign io_ctl_Rt = _T_168;
  assign io_ctl_Rs = _T_167;
  assign io_ctl_Imm16 = _T_161;
  assign io_ctl_Imm26 = _T_166;
  assign ctl_signle = _T_83;
  assign Jump = _T_41;
  assign ALUop = _T_43;
  assign ALUctr2 = _T_102;
  assign ALUctr1 = _T_115;
  assign ALUctr0 = _T_143;
endmodule
module ALU9(
  input  [31:0] io_in1,
  input  [31:0] io_in2,
  input  [2:0]  io_ALUctr,
  output [31:0] io_ALUout,
  output        io_cmp_out
);
  wire  _T_8;
  wire  _T_10;
  wire  _T_11;
  wire [31:0] _T_12;
  wire [31:0] in2_inv;
  wire [31:0] in1_xor_in2;
  wire [32:0] _T_13;
  wire [31:0] _T_14;
  wire [31:0] _GEN_0;
  wire [32:0] _T_20;
  wire [31:0] adder_out;
  wire  _T_24;
  wire  _T_25;
  wire  _T_26;
  wire  _T_27;
  wire  _T_28;
  wire  _T_33;
  wire  _T_34;
  wire  _T_36;
  wire [31:0] _T_38;
  wire  _T_42;
  wire  _T_43;
  wire [31:0] _T_44;
  wire [31:0] _T_46;
  wire [31:0] logic_out;
  wire  _T_48;
  wire  _T_51;
  wire [31:0] out;
  assign _T_8 = io_ALUctr == 3'h6;
  assign _T_10 = io_ALUctr == 3'h7;
  assign _T_11 = _T_8 | _T_10;
  assign _T_12 = ~ io_in2;
  assign in2_inv = _T_11 ? _T_12 : io_in2;
  assign in1_xor_in2 = io_in1 ^ io_in2;
  assign _T_13 = io_in1 + in2_inv;
  assign _T_14 = _T_13[31:0];
  assign _GEN_0 = {{31'd0}, _T_11};
  assign _T_20 = _T_14 + _GEN_0;
  assign adder_out = _T_20[31:0];
  assign _T_24 = in1_xor_in2 == 32'h0;
  assign _T_25 = io_in1[31];
  assign _T_26 = io_in2[31];
  assign _T_27 = _T_25 != _T_26;
  assign _T_28 = adder_out[31];
  assign _T_33 = _T_27 ? _T_28 : _T_28;
  assign _T_34 = _T_8 ? _T_24 : _T_33;
  assign _T_36 = io_ALUctr == 3'h1;
  assign _T_38 = _T_36 ? in1_xor_in2 : 32'h0;
  assign _T_42 = io_ALUctr == 3'h0;
  assign _T_43 = _T_36 | _T_42;
  assign _T_44 = io_in1 & io_in2;
  assign _T_46 = _T_43 ? _T_44 : 32'h0;
  assign logic_out = _T_38 | _T_46;
  assign _T_48 = io_ALUctr == 3'h2;
  assign _T_51 = _T_48 | _T_8;
  assign out = _T_51 ? adder_out : logic_out;
  assign io_ALUout = out;
  assign io_cmp_out = _T_34;
endmodule
module DatPath(
  input         clock,
  input         reset,
  output [31:0] io_imem_addr,
  output [31:0] io_dmem_addr,
  output [31:0] io_dmem_datIn,
  input  [31:0] io_dmem_datOut,
  input         io_ctl_nPC_sel,
  input         io_ctl_RegWr,
  input         io_ctl_RegDst,
  input         io_ctl_ExtOp,
  input  [2:0]  io_ctl_ALUctr,
  input         io_ctl_ALUsrc,
  input         io_ctl_MemtoReg,
  input  [4:0]  io_ctl_Rd,
  input  [4:0]  io_ctl_Rt,
  input  [4:0]  io_ctl_Rs,
  input  [15:0] io_ctl_Imm16,
  input  [25:0] io_ctl_Imm26,
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
  wire [2:0] alu9_io_ALUctr;
  wire [31:0] alu9_io_ALUout;
  wire  alu9_io_cmp_out;
  reg [31:0] pc_reg;
  reg [31:0] _RAND_0;
  reg [31:0] RegFile [0:31];
  reg [31:0] _RAND_1;
  wire [31:0] RegFile__T_45_data;
  wire [4:0] RegFile__T_45_addr;
  wire [31:0] RegFile__T_46_data;
  wire [4:0] RegFile__T_46_addr;
  wire [31:0] RegFile__T_43_data;
  wire [4:0] RegFile__T_43_addr;
  wire  RegFile__T_43_mask;
  wire  RegFile__T_43_en;
  wire [31:0] RegFile__T_49_data;
  wire [4:0] RegFile__T_49_addr;
  wire  RegFile__T_49_mask;
  wire  RegFile__T_49_en;
  wire [4:0] reg_indx;
  wire [31:0] _T_50;
  wire  _T_51;
  wire [14:0] _T_55;
  wire [14:0] _T_56;
  wire [1:0] _T_61;
  wire [29:0] _T_62;
  wire [31:0] br_sext;
  wire [3:0] _T_63;
  wire [29:0] _T_65;
  wire [31:0] j_target;
  wire [16:0] _T_70;
  wire [31:0] _T_72;
  wire [31:0] _T_75;
  wire [31:0] Imm32;
  wire [32:0] _T_77;
  wire [31:0] _T_78;
  wire [32:0] _T_79;
  wire [31:0] _T_80;
  wire [32:0] _T_82;
  wire [31:0] _T_83;
  wire  _T_85;
  wire  pc4_en;
  wire  _T_91;
  wire  _T_92;
  wire  _T_97;
  wire  _T_100;
  wire  _T_102;
  wire  _T_105;
  wire  _T_108;
  wire  _T_110;
  wire  _T_113;
  wire [31:0] _T_115;
  wire [31:0] _T_116;
  wire [31:0] _T_117;
  wire [31:0] _T_118;
  wire [31:0] _T_119;
  ALU9 alu9 (
    .io_in1(alu9_io_in1),
    .io_in2(alu9_io_in2),
    .io_ALUctr(alu9_io_ALUctr),
    .io_ALUout(alu9_io_ALUout),
    .io_cmp_out(alu9_io_cmp_out)
  );
  assign RegFile__T_45_addr = io_ctl_Rs;
  assign RegFile__T_45_data = RegFile[RegFile__T_45_addr];
  assign RegFile__T_46_addr = io_ctl_Rt;
  assign RegFile__T_46_data = RegFile[RegFile__T_46_addr];
  assign RegFile__T_43_data = 32'h0;
  assign RegFile__T_43_addr = 5'h0;
  assign RegFile__T_43_mask = 1'h1;
  assign RegFile__T_43_en = 1'h1;
  assign RegFile__T_49_data = BusWr;
  assign RegFile__T_49_addr = reg_indx;
  assign RegFile__T_49_mask = io_ctl_RegWr;
  assign RegFile__T_49_en = io_ctl_RegWr;
  assign reg_indx = io_ctl_RegDst ? io_ctl_Rd : io_ctl_Rt;
  assign _T_50 = io_ctl_MemtoReg ? io_dmem_datOut : alu9_io_ALUout;
  assign _T_51 = io_ctl_Imm16[15];
  assign _T_55 = _T_51 ? 15'h7fff : 15'h0;
  assign _T_56 = io_ctl_Imm16[14:0];
  assign _T_61 = _T_51 ? 2'h3 : 2'h0;
  assign _T_62 = {_T_55,_T_56};
  assign br_sext = {_T_62,_T_61};
  assign _T_63 = pc_reg[31:28];
  assign _T_65 = {_T_63,io_ctl_Imm26};
  assign j_target = {_T_65,2'h0};
  assign _T_70 = _T_51 ? 17'h1ffff : 17'h0;
  assign _T_72 = {_T_70,_T_56};
  assign _T_75 = {16'h0,io_ctl_Imm16};
  assign Imm32 = io_ctl_ExtOp ? _T_72 : _T_75;
  assign _T_77 = pc_reg + 32'h4;
  assign _T_78 = _T_77[31:0];
  assign _T_79 = pc_reg + br_sext;
  assign _T_80 = _T_79[31:0];
  assign _T_82 = _T_80 + 32'h4;
  assign _T_83 = _T_82[31:0];
  assign _T_85 = io_ctl_ALUctr == 3'h3;
  assign pc4_en = _T_85 ? 1'h0 : 1'h1;
  assign _T_91 = io_ctl_nPC_sel == 1'h0;
  assign _T_92 = pc4_en & _T_91;
  assign _T_97 = io_ctl_ExtOp & pc4_en;
  assign _T_100 = _T_97 & io_ctl_nPC_sel;
  assign _T_102 = io_ctl_ExtOp == 1'h0;
  assign _T_105 = _T_102 & pc4_en;
  assign _T_108 = _T_105 & io_ctl_nPC_sel;
  assign _T_110 = pc4_en == 1'h0;
  assign _T_113 = _T_110 & _T_91;
  assign _T_115 = _T_113 ? 32'h0 : pc_plus4;
  assign _T_116 = _T_108 ? j_target : _T_115;
  assign _T_117 = _T_100 ? pc_br : _T_116;
  assign _T_118 = _T_92 ? pc_plus4 : _T_117;
  assign _T_119 = io_ctl_ALUsrc ? Imm32 : BusB;
  assign io_imem_addr = pc_reg;
  assign io_dmem_addr = alu9_io_ALUout;
  assign io_dmem_datIn = BusB;
  assign io_dat_zero = alu9_io_cmp_out;
  assign BusA = RegFile__T_45_data;
  assign BusB = RegFile__T_46_data;
  assign BusWr = _T_50;
  assign pc_next = _T_118;
  assign pc_plus4 = _T_78;
  assign pc_br = _T_83;
  assign alu9_io_in1 = BusA;
  assign alu9_io_in2 = _T_119;
  assign alu9_io_ALUctr = io_ctl_ALUctr;
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
    if(RegFile__T_43_en & RegFile__T_43_mask) begin
      RegFile[RegFile__T_43_addr] <= RegFile__T_43_data;
    end
    if(RegFile__T_49_en & RegFile__T_49_mask) begin
      RegFile[RegFile__T_49_addr] <= RegFile__T_49_data;
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
  output [31:0] io_test_dm_out,
  output        io_valid
);
  wire [31:0] cpath_io_Inst;
  wire  cpath_io_boot;
  wire  cpath_io_MemWr;
  wire  cpath_io_valid;
  wire  cpath_io_ctl_nPC_sel;
  wire  cpath_io_ctl_RegWr;
  wire  cpath_io_ctl_RegDst;
  wire  cpath_io_ctl_ExtOp;
  wire [2:0] cpath_io_ctl_ALUctr;
  wire  cpath_io_ctl_ALUsrc;
  wire  cpath_io_ctl_MemtoReg;
  wire [4:0] cpath_io_ctl_Rd;
  wire [4:0] cpath_io_ctl_Rt;
  wire [4:0] cpath_io_ctl_Rs;
  wire [15:0] cpath_io_ctl_Imm16;
  wire [25:0] cpath_io_ctl_Imm26;
  wire  cpath_io_dat_zero;
  wire  dpath_clock;
  wire  dpath_reset;
  wire [31:0] dpath_io_imem_addr;
  wire [31:0] dpath_io_dmem_addr;
  wire [31:0] dpath_io_dmem_datIn;
  wire [31:0] dpath_io_dmem_datOut;
  wire  dpath_io_ctl_nPC_sel;
  wire  dpath_io_ctl_RegWr;
  wire  dpath_io_ctl_RegDst;
  wire  dpath_io_ctl_ExtOp;
  wire [2:0] dpath_io_ctl_ALUctr;
  wire  dpath_io_ctl_ALUsrc;
  wire  dpath_io_ctl_MemtoReg;
  wire [4:0] dpath_io_ctl_Rd;
  wire [4:0] dpath_io_ctl_Rt;
  wire [4:0] dpath_io_ctl_Rs;
  wire [15:0] dpath_io_ctl_Imm16;
  wire [25:0] dpath_io_ctl_Imm26;
  wire  dpath_io_dat_zero;
  reg [31:0] imm [0:255];
  reg [31:0] _RAND_0;
  wire [31:0] imm__T_34_data;
  wire [7:0] imm__T_34_addr;
  wire [31:0] imm__T_46_data;
  wire [7:0] imm__T_46_addr;
  wire [31:0] imm__T_24_data;
  wire [7:0] imm__T_24_addr;
  wire  imm__T_24_mask;
  wire  imm__T_24_en;
  reg [31:0] dmm [0:1023];
  reg [31:0] _RAND_1;
  wire [31:0] dmm__T_39_data;
  wire [9:0] dmm__T_39_addr;
  wire [31:0] dmm__T_50_data;
  wire [9:0] dmm__T_50_addr;
  wire [31:0] dmm__T_61_data;
  wire [9:0] dmm__T_61_addr;
  wire [31:0] dmm__T_29_data;
  wire [9:0] dmm__T_29_addr;
  wire  dmm__T_29_mask;
  wire  dmm__T_29_en;
  wire [31:0] dmm__T_53_data;
  wire [9:0] dmm__T_53_addr;
  wire  dmm__T_53_mask;
  wire  dmm__T_53_en;
  wire  _T_21;
  wire [29:0] _T_22;
  wire [7:0] _T_23;
  wire  _T_26;
  wire [29:0] _T_27;
  wire [9:0] _T_28;
  wire  _T_31;
  wire [7:0] _T_33;
  wire [31:0] _GEN_13;
  wire  _T_36;
  wire [9:0] _T_38;
  wire [31:0] _GEN_18;
  wire  _T_42;
  wire [29:0] _T_44;
  wire [7:0] _T_45;
  wire [31:0] _T_47;
  wire [29:0] _T_48;
  wire [9:0] _T_49;
  wire [9:0] _T_52;
  wire  _GEN_22;
  wire [31:0] _GEN_23;
  wire [31:0] _GEN_27;
  wire [31:0] _GEN_29;
  wire  _GEN_32;
  reg [31:0] clk_cnt;
  reg [31:0] _RAND_2;
  wire [32:0] _T_57;
  wire [31:0] _T_58;
  wire [9:0] _T_60;
  wire  _T_64;
  CtlPath cpath (
    .io_Inst(cpath_io_Inst),
    .io_boot(cpath_io_boot),
    .io_MemWr(cpath_io_MemWr),
    .io_valid(cpath_io_valid),
    .io_ctl_nPC_sel(cpath_io_ctl_nPC_sel),
    .io_ctl_RegWr(cpath_io_ctl_RegWr),
    .io_ctl_RegDst(cpath_io_ctl_RegDst),
    .io_ctl_ExtOp(cpath_io_ctl_ExtOp),
    .io_ctl_ALUctr(cpath_io_ctl_ALUctr),
    .io_ctl_ALUsrc(cpath_io_ctl_ALUsrc),
    .io_ctl_MemtoReg(cpath_io_ctl_MemtoReg),
    .io_ctl_Rd(cpath_io_ctl_Rd),
    .io_ctl_Rt(cpath_io_ctl_Rt),
    .io_ctl_Rs(cpath_io_ctl_Rs),
    .io_ctl_Imm16(cpath_io_ctl_Imm16),
    .io_ctl_Imm26(cpath_io_ctl_Imm26),
    .io_dat_zero(cpath_io_dat_zero)
  );
  DatPath dpath (
    .clock(dpath_clock),
    .reset(dpath_reset),
    .io_imem_addr(dpath_io_imem_addr),
    .io_dmem_addr(dpath_io_dmem_addr),
    .io_dmem_datIn(dpath_io_dmem_datIn),
    .io_dmem_datOut(dpath_io_dmem_datOut),
    .io_ctl_nPC_sel(dpath_io_ctl_nPC_sel),
    .io_ctl_RegWr(dpath_io_ctl_RegWr),
    .io_ctl_RegDst(dpath_io_ctl_RegDst),
    .io_ctl_ExtOp(dpath_io_ctl_ExtOp),
    .io_ctl_ALUctr(dpath_io_ctl_ALUctr),
    .io_ctl_ALUsrc(dpath_io_ctl_ALUsrc),
    .io_ctl_MemtoReg(dpath_io_ctl_MemtoReg),
    .io_ctl_Rd(dpath_io_ctl_Rd),
    .io_ctl_Rt(dpath_io_ctl_Rt),
    .io_ctl_Rs(dpath_io_ctl_Rs),
    .io_ctl_Imm16(dpath_io_ctl_Imm16),
    .io_ctl_Imm26(dpath_io_ctl_Imm26),
    .io_dat_zero(dpath_io_dat_zero)
  );
  assign imm__T_34_addr = _T_33;
  assign imm__T_34_data = imm[imm__T_34_addr];
  assign imm__T_46_addr = _T_45;
  assign imm__T_46_data = imm[imm__T_46_addr];
  assign imm__T_24_data = io_test_im_in;
  assign imm__T_24_addr = _T_23;
  assign imm__T_24_mask = _T_21;
  assign imm__T_24_en = _T_21;
  assign dmm__T_39_addr = _T_38;
  assign dmm__T_39_data = dmm[dmm__T_39_addr];
  assign dmm__T_50_addr = _T_49;
  assign dmm__T_50_data = dmm[dmm__T_50_addr];
  assign dmm__T_61_addr = _T_60;
  assign dmm__T_61_data = dmm[dmm__T_61_addr];
  assign dmm__T_29_data = io_test_dm_in;
  assign dmm__T_29_addr = _T_28;
  assign dmm__T_29_mask = _T_26;
  assign dmm__T_29_en = _T_26;
  assign dmm__T_53_data = _GEN_23;
  assign dmm__T_53_addr = _T_52;
  assign dmm__T_53_mask = _GEN_32;
  assign dmm__T_53_en = _GEN_32;
  assign _T_21 = io_boot & io_test_im_wr;
  assign _T_22 = io_test_im_addr[31:2];
  assign _T_23 = _T_22[7:0];
  assign _T_26 = io_boot & io_test_dm_wr;
  assign _T_27 = io_test_dm_addr[31:2];
  assign _T_28 = _T_27[9:0];
  assign _T_31 = io_boot & io_test_im_rd;
  assign _T_33 = _T_22[7:0];
  assign _GEN_13 = _T_31 ? imm__T_34_data : 32'h0;
  assign _T_36 = io_boot & io_test_dm_rd;
  assign _T_38 = _T_27[9:0];
  assign _GEN_18 = _T_36 ? dmm__T_39_data : 32'h0;
  assign _T_42 = io_boot == 1'h0;
  assign _T_44 = dpath_io_imem_addr[31:2];
  assign _T_45 = _T_44[7:0];
  assign _T_47 = io_boot ? 32'h0 : imm__T_46_data;
  assign _T_48 = dpath_io_dmem_addr[31:2];
  assign _T_49 = _T_48[9:0];
  assign _T_52 = _T_48[9:0];
  assign _GEN_22 = cpath_io_MemWr;
  assign _GEN_23 = dpath_io_dmem_datIn;
  assign _GEN_27 = _T_42 ? _T_47 : 32'h0;
  assign _GEN_29 = dmm__T_50_data;
  assign _GEN_32 = _T_42 ? _GEN_22 : 1'h0;
  assign _T_57 = clk_cnt + 32'h1;
  assign _T_58 = _T_57[31:0];
  assign _T_60 = _T_27[9:0];
  assign _T_64 = reset == 1'h0;
  assign io_test_im_out = _GEN_13;
  assign io_test_dm_out = _GEN_18;
  assign io_valid = cpath_io_valid;
  assign cpath_io_Inst = _GEN_27;
  assign cpath_io_boot = io_boot;
  assign cpath_io_dat_zero = dpath_io_dat_zero;
  assign dpath_io_dmem_datOut = _GEN_29;
  assign dpath_io_ctl_nPC_sel = cpath_io_ctl_nPC_sel;
  assign dpath_io_ctl_RegWr = cpath_io_ctl_RegWr;
  assign dpath_io_ctl_RegDst = cpath_io_ctl_RegDst;
  assign dpath_io_ctl_ExtOp = cpath_io_ctl_ExtOp;
  assign dpath_io_ctl_ALUctr = cpath_io_ctl_ALUctr;
  assign dpath_io_ctl_ALUsrc = cpath_io_ctl_ALUsrc;
  assign dpath_io_ctl_MemtoReg = cpath_io_ctl_MemtoReg;
  assign dpath_io_ctl_Rd = cpath_io_ctl_Rd;
  assign dpath_io_ctl_Rt = cpath_io_ctl_Rt;
  assign dpath_io_ctl_Rs = cpath_io_ctl_Rs;
  assign dpath_io_ctl_Imm16 = cpath_io_ctl_Imm16;
  assign dpath_io_ctl_Imm26 = cpath_io_ctl_Imm26;
  assign dpath_clock = clock;
  assign dpath_reset = reset;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  _RAND_0 = {1{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    imm[initvar] = _RAND_0[31:0];
  `endif // RANDOMIZE_MEM_INIT
  _RAND_1 = {1{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 1024; initvar = initvar+1)
    dmm[initvar] = _RAND_1[31:0];
  `endif // RANDOMIZE_MEM_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  clk_cnt = _RAND_2[31:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if(imm__T_24_en & imm__T_24_mask) begin
      imm[imm__T_24_addr] <= imm__T_24_data;
    end
    if(dmm__T_29_en & dmm__T_29_mask) begin
      dmm[dmm__T_29_addr] <= dmm__T_29_data;
    end
    if(dmm__T_53_en & dmm__T_53_mask) begin
      dmm[dmm__T_53_addr] <= dmm__T_53_data;
    end
    if (reset) begin
      clk_cnt <= 32'h0;
    end else begin
      clk_cnt <= _T_58;
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_64) begin
          $fwrite(32'h80000002,"Cyc=%d, pc=0x%h, Inst=0x%h, boot=%d, dmem_in = 0x%h, rd_dmm=0x%h, dmm=0x%h\n",clk_cnt,dpath_io_imem_addr,cpath_io_Inst,cpath_io_boot,dpath_io_dmem_datIn,io_test_dm_out,dmm__T_61_data);
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
