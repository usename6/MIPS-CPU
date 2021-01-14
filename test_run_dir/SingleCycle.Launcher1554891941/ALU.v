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

module ALU(
  input         clock,
  input         reset,
  input  [31:0] io_a,
  input  [31:0] io_b,
  input  [3:0]  io_op,
  input  [4:0]  io_shamt,
  output [31:0] io_out,
  output        io_zero
);
  wire  _T_9;
  wire [31:0] _T_10;
  wire  _T_12;
  wire [31:0] _T_13;
  wire  _T_15;
  wire [31:0] _T_17;
  wire  _T_19;
  wire [31:0] _T_20;
  wire  _T_22;
  wire [32:0] _T_23;
  wire [31:0] _T_24;
  wire  _T_26;
  wire [32:0] _T_27;
  wire [32:0] _T_28;
  wire [31:0] _T_29;
  wire  _T_31;
  wire [62:0] _GEN_10;
  wire [62:0] _T_32;
  wire  _T_34;
  wire [31:0] _T_35;
  wire  _T_37;
  wire  _T_38;
  wire  _T_40;
  wire [62:0] _T_42;
  wire [62:0] _GEN_0;
  wire [62:0] _GEN_1;
  wire [62:0] _GEN_2;
  wire [62:0] _GEN_3;
  wire [62:0] _GEN_4;
  wire [62:0] _GEN_5;
  wire [62:0] _GEN_6;
  wire [62:0] _GEN_7;
  wire [62:0] _GEN_8;
  wire [62:0] _GEN_9;
  wire  _T_48;
  assign _T_9 = io_op == 4'h0;
  assign _T_10 = io_a & io_b;
  assign _T_12 = io_op == 4'h1;
  assign _T_13 = io_a | io_b;
  assign _T_15 = io_op == 4'h2;
  assign _T_17 = ~ _T_13;
  assign _T_19 = io_op == 4'h3;
  assign _T_20 = io_a ^ io_b;
  assign _T_22 = io_op == 4'h4;
  assign _T_23 = io_a + io_b;
  assign _T_24 = _T_23[31:0];
  assign _T_26 = io_op == 4'h5;
  assign _T_27 = io_a - io_b;
  assign _T_28 = $unsigned(_T_27);
  assign _T_29 = _T_28[31:0];
  assign _T_31 = io_op == 4'h6;
  assign _GEN_10 = {{31'd0}, io_b};
  assign _T_32 = _GEN_10 << io_shamt;
  assign _T_34 = io_op == 4'h7;
  assign _T_35 = io_b >> io_shamt;
  assign _T_37 = io_op == 4'h8;
  assign _T_38 = io_a < io_b;
  assign _T_40 = io_op == 4'h9;
  assign _T_42 = _GEN_10 << 5'h10;
  assign _GEN_0 = _T_40 ? _T_42 : 63'h0;
  assign _GEN_1 = _T_37 ? {{62'd0}, _T_38} : _GEN_0;
  assign _GEN_2 = _T_34 ? {{31'd0}, _T_35} : _GEN_1;
  assign _GEN_3 = _T_31 ? _T_32 : _GEN_2;
  assign _GEN_4 = _T_26 ? {{31'd0}, _T_29} : _GEN_3;
  assign _GEN_5 = _T_22 ? {{31'd0}, _T_24} : _GEN_4;
  assign _GEN_6 = _T_19 ? {{31'd0}, _T_20} : _GEN_5;
  assign _GEN_7 = _T_15 ? {{31'd0}, _T_17} : _GEN_6;
  assign _GEN_8 = _T_12 ? {{31'd0}, _T_13} : _GEN_7;
  assign _GEN_9 = _T_9 ? {{31'd0}, _T_10} : _GEN_8;
  assign _T_48 = _T_29 == 32'h0;
  assign io_out = _GEN_9[31:0];
  assign io_zero = _T_48;
endmodule
