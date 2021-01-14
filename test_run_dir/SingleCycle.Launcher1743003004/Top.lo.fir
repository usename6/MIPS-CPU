circuit Top : @[:@2.0]
  module CtlPath : @[:@3.2]
    input clock : Clock @[:@4.4]
    input reset : UInt<1> @[:@5.4]
    input io_Inst : UInt<32> @[:@6.4]
    input io_boot : UInt<1> @[:@6.4]
    output io_MemWr : UInt<1> @[:@6.4]
    output io_valid : UInt<1> @[:@6.4]
    output io_ctl_nPC_sel : UInt<1> @[:@6.4]
    output io_ctl_RegWr : UInt<1> @[:@6.4]
    output io_ctl_RegDst : UInt<1> @[:@6.4]
    output io_ctl_ExtOp : UInt<1> @[:@6.4]
    output io_ctl_ALUctr : UInt<3> @[:@6.4]
    output io_ctl_ALUsrc : UInt<1> @[:@6.4]
    output io_ctl_MemtoReg : UInt<1> @[:@6.4]
    output io_ctl_Rd : UInt<5> @[:@6.4]
    output io_ctl_Rt : UInt<5> @[:@6.4]
    output io_ctl_Rs : UInt<5> @[:@6.4]
    output io_ctl_Imm16 : UInt<16> @[:@6.4]
    output io_ctl_Imm26 : UInt<26> @[:@6.4]
    input io_dat_zero : UInt<1> @[:@6.4]
  
    wire ctl_signle : UInt<11> @[CtlPath.scala 49:31:@14.4]
    wire Jump : UInt<1> @[CtlPath.scala 51:39:@16.4]
    wire ALUop : UInt<3> @[CtlPath.scala 52:39:@18.4]
    wire ALUctr2 : UInt<1> @[CtlPath.scala 53:39:@20.4]
    wire ALUctr1 : UInt<1> @[CtlPath.scala 54:39:@22.4]
    wire ALUctr0 : UInt<1> @[CtlPath.scala 55:39:@24.4]
    node _T_30 = bits(ctl_signle, 10, 10) @[CtlPath.scala 60:46:@26.4]
    node _T_31 = bits(ctl_signle, 9, 9) @[CtlPath.scala 61:46:@28.4]
    node _T_32 = bits(ctl_signle, 8, 8) @[CtlPath.scala 62:46:@30.4]
    node _T_33 = bits(ctl_signle, 7, 7) @[CtlPath.scala 63:46:@32.4]
    node _T_34 = bits(ctl_signle, 6, 6) @[CtlPath.scala 64:54:@34.4]
    node _T_36 = bits(ctl_signle, 5, 5) @[CtlPath.scala 66:69:@36.4]
    node _T_37 = bits(ctl_signle, 5, 5) @[CtlPath.scala 66:99:@37.4]
    node _T_38 = and(io_dat_zero, _T_37) @[CtlPath.scala 66:87:@38.4]
    node _T_39 = mux(Jump, _T_36, _T_38) @[CtlPath.scala 66:52:@39.4]
    node _T_40 = mux(io_boot, UInt<1>("h0"), _T_39) @[CtlPath.scala 65:39:@40.4]
    node _T_41 = bits(ctl_signle, 4, 4) @[CtlPath.scala 67:54:@42.4]
    node _T_42 = bits(ctl_signle, 3, 3) @[CtlPath.scala 68:46:@44.4]
    node _T_43 = bits(ctl_signle, 2, 0) @[CtlPath.scala 69:54:@46.4]
    node _T_46 = bits(io_Inst, 31, 26) @[CtlPath.scala 73:33:@48.4]
    node _T_48 = eq(_T_46, UInt<6>("h0")) @[CtlPath.scala 73:42:@49.4]
    node _T_50 = neq(io_Inst, UInt<1>("h0")) @[CtlPath.scala 73:74:@50.4]
    node _T_51 = and(_T_48, _T_50) @[CtlPath.scala 73:63:@51.4]
    node _T_53 = bits(io_Inst, 31, 26) @[CtlPath.scala 75:33:@52.4]
    node _T_55 = eq(_T_53, UInt<6>("hd")) @[CtlPath.scala 75:42:@53.4]
    node _T_57 = bits(io_Inst, 31, 26) @[CtlPath.scala 76:33:@54.4]
    node _T_59 = eq(_T_57, UInt<6>("h23")) @[CtlPath.scala 76:42:@55.4]
    node _T_61 = bits(io_Inst, 31, 26) @[CtlPath.scala 77:33:@56.4]
    node _T_63 = eq(_T_61, UInt<6>("h2b")) @[CtlPath.scala 77:42:@57.4]
    node _T_65 = bits(io_Inst, 31, 26) @[CtlPath.scala 78:33:@58.4]
    node _T_67 = eq(_T_65, UInt<6>("h4")) @[CtlPath.scala 78:42:@59.4]
    node _T_69 = bits(io_Inst, 31, 26) @[CtlPath.scala 79:33:@60.4]
    node _T_71 = eq(_T_69, UInt<6>("h2")) @[CtlPath.scala 79:42:@61.4]
    node _T_74 = eq(io_Inst, UInt<1>("h0")) @[CtlPath.scala 80:34:@62.4]
    node _T_76 = mux(_T_74, UInt<1>("h0"), UInt<11>("h7ff")) @[Mux.scala 61:16:@63.4]
    node _T_77 = mux(_T_71, UInt<11>("h37"), _T_76) @[Mux.scala 61:16:@64.4]
    node _T_78 = mux(_T_67, UInt<11>("h29"), _T_77) @[Mux.scala 61:16:@65.4]
    node _T_79 = mux(_T_63, UInt<11>("h248"), _T_78) @[Mux.scala 61:16:@66.4]
    node _T_80 = mux(_T_59, UInt<11>("h388"), _T_79) @[Mux.scala 61:16:@67.4]
    node _T_81 = mux(_T_55, UInt<11>("h282"), _T_80) @[Mux.scala 61:16:@68.4]
    node _T_82 = mux(_T_51, UInt<11>("h484"), _T_81) @[Mux.scala 61:16:@69.4]
    node _T_83 = mux(io_boot, UInt<11>("h8"), _T_82) @[CtlPath.scala 71:26:@70.4]
    node _T_84 = bits(reset, 0, 0) @[CtlPath.scala 82:15:@72.4]
    node _T_86 = eq(_T_84, UInt<1>("h0")) @[CtlPath.scala 82:15:@73.4]
    node _T_88 = eq(ctl_signle, UInt<11>("h7ff")) @[CtlPath.scala 83:36:@77.4]
    node _T_91 = mux(_T_88, UInt<1>("h0"), UInt<1>("h1")) @[CtlPath.scala 83:24:@78.4]
    node _T_92 = bits(ALUop, 2, 2) @[CtlPath.scala 85:26:@80.4]
    node _T_93 = not(_T_92) @[CtlPath.scala 85:20:@81.4]
    node _T_94 = bits(ALUop, 0, 0) @[CtlPath.scala 85:37:@82.4]
    node _T_95 = and(_T_93, _T_94) @[CtlPath.scala 85:30:@83.4]
    node _T_96 = bits(ALUop, 2, 2) @[CtlPath.scala 85:49:@84.4]
    node _T_97 = bits(io_Inst, 2, 2) @[CtlPath.scala 85:63:@85.4]
    node _T_98 = not(_T_97) @[CtlPath.scala 85:55:@86.4]
    node _T_99 = and(_T_96, _T_98) @[CtlPath.scala 85:53:@87.4]
    node _T_100 = bits(io_Inst, 1, 1) @[CtlPath.scala 86:58:@88.4]
    node _T_101 = and(_T_99, _T_100) @[CtlPath.scala 86:49:@89.4]
    node _T_102 = bits(io_Inst, 0, 0) @[CtlPath.scala 86:72:@90.4]
    node _T_103 = not(_T_102) @[CtlPath.scala 86:64:@91.4]
    node _T_104 = and(_T_101, _T_103) @[CtlPath.scala 86:62:@92.4]
    node _T_105 = or(_T_95, _T_104) @[CtlPath.scala 85:41:@93.4]
    node _T_106 = bits(ALUop, 2, 2) @[CtlPath.scala 87:26:@95.4]
    node _T_107 = not(_T_106) @[CtlPath.scala 87:20:@96.4]
    node _T_108 = bits(ALUop, 1, 1) @[CtlPath.scala 87:38:@97.4]
    node _T_109 = not(_T_108) @[CtlPath.scala 87:32:@98.4]
    node _T_110 = and(_T_107, _T_109) @[CtlPath.scala 87:30:@99.4]
    node _T_111 = bits(ALUop, 2, 2) @[CtlPath.scala 87:50:@100.4]
    node _T_112 = bits(io_Inst, 2, 2) @[CtlPath.scala 87:64:@101.4]
    node _T_113 = not(_T_112) @[CtlPath.scala 87:56:@102.4]
    node _T_114 = and(_T_111, _T_113) @[CtlPath.scala 87:54:@103.4]
    node _T_115 = bits(io_Inst, 0, 0) @[CtlPath.scala 87:78:@104.4]
    node _T_116 = not(_T_115) @[CtlPath.scala 87:70:@105.4]
    node _T_117 = and(_T_114, _T_116) @[CtlPath.scala 87:68:@106.4]
    node _T_118 = or(_T_110, _T_117) @[CtlPath.scala 87:42:@107.4]
    node _T_119 = bits(ALUop, 2, 2) @[CtlPath.scala 88:26:@109.4]
    node _T_120 = not(_T_119) @[CtlPath.scala 88:20:@110.4]
    node _T_121 = bits(ALUop, 1, 1) @[CtlPath.scala 88:37:@111.4]
    node _T_122 = and(_T_120, _T_121) @[CtlPath.scala 88:30:@112.4]
    node _T_123 = bits(ALUop, 2, 2) @[CtlPath.scala 89:55:@113.4]
    node _T_124 = bits(io_Inst, 3, 3) @[CtlPath.scala 89:69:@114.4]
    node _T_125 = not(_T_124) @[CtlPath.scala 89:61:@115.4]
    node _T_126 = and(_T_123, _T_125) @[CtlPath.scala 89:59:@116.4]
    node _T_127 = bits(io_Inst, 2, 2) @[CtlPath.scala 89:82:@117.4]
    node _T_128 = and(_T_126, _T_127) @[CtlPath.scala 89:73:@118.4]
    node _T_129 = bits(io_Inst, 1, 1) @[CtlPath.scala 89:96:@119.4]
    node _T_130 = not(_T_129) @[CtlPath.scala 89:88:@120.4]
    node _T_131 = and(_T_128, _T_130) @[CtlPath.scala 89:86:@121.4]
    node _T_132 = bits(io_Inst, 0, 0) @[CtlPath.scala 89:109:@122.4]
    node _T_133 = and(_T_131, _T_132) @[CtlPath.scala 89:100:@123.4]
    node _T_134 = or(_T_122, _T_133) @[CtlPath.scala 88:41:@124.4]
    node _T_135 = bits(ALUop, 2, 2) @[CtlPath.scala 90:55:@125.4]
    node _T_136 = bits(io_Inst, 3, 3) @[CtlPath.scala 90:68:@126.4]
    node _T_137 = and(_T_135, _T_136) @[CtlPath.scala 90:59:@127.4]
    node _T_138 = bits(io_Inst, 2, 2) @[CtlPath.scala 90:82:@128.4]
    node _T_139 = not(_T_138) @[CtlPath.scala 90:74:@129.4]
    node _T_140 = and(_T_137, _T_139) @[CtlPath.scala 90:72:@130.4]
    node _T_141 = bits(io_Inst, 1, 1) @[CtlPath.scala 90:95:@131.4]
    node _T_142 = and(_T_140, _T_141) @[CtlPath.scala 90:86:@132.4]
    node _T_143 = bits(io_Inst, 0, 0) @[CtlPath.scala 90:109:@133.4]
    node _T_144 = not(_T_143) @[CtlPath.scala 90:101:@134.4]
    node _T_145 = and(_T_142, _T_144) @[CtlPath.scala 90:99:@135.4]
    node _T_146 = or(_T_134, _T_145) @[CtlPath.scala 89:114:@136.4]
    node _T_148 = eq(ctl_signle, UInt<11>("h8")) @[CtlPath.scala 91:41:@138.4]
    node _T_151 = eq(io_Inst, UInt<1>("h0")) @[CtlPath.scala 92:61:@139.4]
    node _T_153 = cat(ALUctr2, ALUctr1) @[Cat.scala 30:58:@140.4]
    node _T_154 = cat(_T_153, ALUctr0) @[Cat.scala 30:58:@141.4]
    node _T_155 = mux(_T_151, UInt<1>("h0"), _T_154) @[CtlPath.scala 92:52:@142.4]
    node _T_156 = mux(_T_148, UInt<2>("h3"), _T_155) @[CtlPath.scala 91:29:@143.4]
    node _T_158 = eq(ALUop, UInt<3>("h4")) @[CtlPath.scala 95:37:@145.4]
    node _T_160 = eq(Jump, UInt<1>("h1")) @[CtlPath.scala 95:55:@146.4]
    node _T_161 = or(_T_158, _T_160) @[CtlPath.scala 95:46:@147.4]
    node _T_163 = bits(io_Inst, 15, 0) @[CtlPath.scala 95:81:@148.4]
    node _T_164 = mux(_T_161, UInt<1>("h0"), _T_163) @[CtlPath.scala 95:28:@149.4]
    node _T_166 = eq(Jump, UInt<1>("h1")) @[CtlPath.scala 96:35:@151.4]
    node _T_167 = bits(io_Inst, 25, 0) @[CtlPath.scala 96:55:@152.4]
    node _T_169 = mux(_T_166, _T_167, UInt<1>("h0")) @[CtlPath.scala 96:28:@153.4]
    node _T_170 = bits(io_Inst, 25, 21) @[CtlPath.scala 98:29:@155.4]
    node _T_171 = bits(io_Inst, 20, 16) @[CtlPath.scala 99:29:@157.4]
    node _T_172 = bits(io_Inst, 15, 11) @[CtlPath.scala 100:29:@159.4]
    io_MemWr <= _T_34
    io_valid <= _T_91
    io_ctl_nPC_sel <= _T_40
    io_ctl_RegWr <= _T_33
    io_ctl_RegDst <= _T_30
    io_ctl_ExtOp <= _T_42
    io_ctl_ALUctr <= _T_156
    io_ctl_ALUsrc <= _T_31
    io_ctl_MemtoReg <= _T_32
    io_ctl_Rd <= _T_172
    io_ctl_Rt <= _T_171
    io_ctl_Rs <= _T_170
    io_ctl_Imm16 <= _T_164
    io_ctl_Imm26 <= _T_169
    ctl_signle <= _T_83
    Jump <= _T_41
    ALUop <= _T_43
    ALUctr2 <= _T_105
    ALUctr1 <= _T_118
    ALUctr0 <= _T_146
    printf(clock, and(and(UInt<1>("h1"), _T_86), UInt<1>("h1")), "ctl_signle = %x\n", ctl_signle) @[CtlPath.scala 82:15:@75.6]

  module ALU9 : @[:@162.2]
    input clock : Clock @[:@163.4]
    input reset : UInt<1> @[:@164.4]
    input io_in1 : UInt<32> @[:@165.4]
    input io_in2 : UInt<32> @[:@165.4]
    input io_ALUctr : UInt<3> @[:@165.4]
    output io_ALUout : UInt<32> @[:@165.4]
    output io_cmp_out : UInt<1> @[:@165.4]
  
    node _T_8 = eq(io_ALUctr, UInt<3>("h6")) @[ALU.scala 79:33:@170.4]
    node _T_10 = eq(io_ALUctr, UInt<3>("h7")) @[ALU.scala 79:53:@171.4]
    node _T_11 = or(_T_8, _T_10) @[ALU.scala 79:45:@172.4]
    node _T_12 = not(io_in2) @[ALU.scala 97:45:@173.4]
    node in2_inv = mux(_T_11, _T_12, io_in2) @[ALU.scala 97:26:@174.4]
    node in1_xor_in2 = xor(io_in1, io_in2) @[ALU.scala 98:34:@175.4]
    node _T_13 = add(io_in1, in2_inv) @[ALU.scala 99:32:@176.4]
    node _T_14 = tail(_T_13, 1) @[ALU.scala 99:32:@177.4]
    node _T_16 = eq(io_ALUctr, UInt<3>("h6")) @[ALU.scala 79:33:@178.4]
    node _T_18 = eq(io_ALUctr, UInt<3>("h7")) @[ALU.scala 79:53:@179.4]
    node _T_19 = or(_T_16, _T_18) @[ALU.scala 79:45:@180.4]
    node _T_20 = add(_T_14, _T_19) @[ALU.scala 99:42:@181.4]
    node adder_out = tail(_T_20, 1) @[ALU.scala 99:42:@182.4]
    node _T_22 = eq(io_ALUctr, UInt<3>("h6")) @[ALU.scala 105:37:@183.4]
    node _T_24 = eq(in1_xor_in2, UInt<1>("h0")) @[ALU.scala 105:61:@184.4]
    node _T_25 = bits(io_in1, 31, 31) @[ALU.scala 106:27:@185.4]
    node _T_26 = bits(io_in2, 31, 31) @[ALU.scala 106:41:@186.4]
    node _T_27 = neq(_T_25, _T_26) @[ALU.scala 106:32:@187.4]
    node _T_28 = bits(adder_out, 31, 31) @[ALU.scala 106:56:@188.4]
    node _T_29 = bits(adder_out, 31, 31) @[ALU.scala 107:30:@189.4]
    node _T_32 = mux(_T_29, UInt<1>("h1"), UInt<1>("h0")) @[ALU.scala 107:20:@190.4]
    node _T_33 = mux(_T_27, _T_28, _T_32) @[ALU.scala 106:20:@191.4]
    node _T_34 = mux(_T_22, _T_24, _T_33) @[ALU.scala 105:26:@192.4]
    node _T_36 = eq(io_ALUctr, UInt<3>("h1")) @[ALU.scala 110:35:@194.4]
    node _T_38 = mux(_T_36, in1_xor_in2, UInt<1>("h0")) @[ALU.scala 110:24:@195.4]
    node _T_40 = eq(io_ALUctr, UInt<3>("h1")) @[ALU.scala 111:19:@196.4]
    node _T_42 = eq(io_ALUctr, UInt<3>("h0")) @[ALU.scala 111:42:@197.4]
    node _T_43 = or(_T_40, _T_42) @[ALU.scala 111:29:@198.4]
    node _T_44 = and(io_in1, io_in2) @[ALU.scala 111:61:@199.4]
    node _T_46 = mux(_T_43, _T_44, UInt<1>("h0")) @[ALU.scala 111:8:@200.4]
    node logic_out = or(_T_38, _T_46) @[ALU.scala 110:64:@201.4]
    node _T_48 = eq(io_ALUctr, UInt<3>("h2")) @[ALU.scala 113:29:@202.4]
    node _T_50 = eq(io_ALUctr, UInt<3>("h6")) @[ALU.scala 113:53:@203.4]
    node _T_51 = or(_T_48, _T_50) @[ALU.scala 113:40:@204.4]
    node out = mux(_T_51, adder_out, logic_out) @[ALU.scala 113:18:@205.4]
    io_ALUout <= out
    io_cmp_out <= _T_34

  module DatPath : @[:@208.2]
    input clock : Clock @[:@209.4]
    input reset : UInt<1> @[:@210.4]
    output io_imem_addr : UInt<32> @[:@211.4]
    output io_dmem_addr : UInt<32> @[:@211.4]
    output io_dmem_datIn : UInt<32> @[:@211.4]
    input io_dmem_datOut : UInt<32> @[:@211.4]
    input io_ctl_nPC_sel : UInt<1> @[:@211.4]
    input io_ctl_RegWr : UInt<1> @[:@211.4]
    input io_ctl_RegDst : UInt<1> @[:@211.4]
    input io_ctl_ExtOp : UInt<1> @[:@211.4]
    input io_ctl_ALUctr : UInt<3> @[:@211.4]
    input io_ctl_ALUsrc : UInt<1> @[:@211.4]
    input io_ctl_MemtoReg : UInt<1> @[:@211.4]
    input io_ctl_Rd : UInt<5> @[:@211.4]
    input io_ctl_Rt : UInt<5> @[:@211.4]
    input io_ctl_Rs : UInt<5> @[:@211.4]
    input io_ctl_Imm16 : UInt<16> @[:@211.4]
    input io_ctl_Imm26 : UInt<26> @[:@211.4]
    output io_dat_zero : UInt<1> @[:@211.4]
  
    wire BusA : UInt<32> @[DatPath.scala 39:31:@216.4]
    wire BusB : UInt<32> @[DatPath.scala 40:31:@218.4]
    wire BusWr : UInt<32> @[DatPath.scala 41:31:@220.4]
    wire pc_next : UInt<32> @[DatPath.scala 42:27:@222.4]
    wire pc_plus4 : UInt<32> @[DatPath.scala 43:27:@224.4]
    wire pc_br : UInt<32> @[DatPath.scala 44:31:@226.4]
    inst alu9 of ALU9 @[DatPath.scala 46:26:@228.4]
    reg pc_reg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), pc_reg) @[DatPath.scala 48:29:@232.4]
    mem RegFile : @[DatPath.scala 50:26:@234.4]
      data-type => UInt<32>
      depth => 32
      read-latency => 0
      write-latency => 1
      reader => _T_45
      reader => _T_46
      writer => _T_43
      writer => _T_49
      read-under-write => undefined
    node reg_indx = mux(io_ctl_RegDst, io_ctl_Rd, io_ctl_Rt) @[DatPath.scala 59:27:@241.4]
    node _T_48 = eq(io_ctl_RegWr, UInt<1>("h1")) @[DatPath.scala 62:28:@242.4]
    node _GEN_0 = validif(_T_48, reg_indx) @[DatPath.scala 62:40:@243.4]
    node _GEN_1 = validif(_T_48, clock) @[DatPath.scala 62:40:@243.4]
    node _GEN_2 = mux(_T_48, UInt<1>("h1"), UInt<1>("h0")) @[DatPath.scala 62:40:@243.4]
    node _GEN_3 = validif(_T_48, BusWr) @[DatPath.scala 62:40:@243.4]
    node _T_50 = mux(io_ctl_MemtoReg, io_dmem_datOut, alu9.io_ALUout) @[DatPath.scala 66:21:@247.4]
    node _T_51 = bits(io_ctl_Imm16, 15, 15) @[DatPath.scala 71:47:@249.4]
    node _T_52 = bits(_T_51, 0, 0) @[Bitwise.scala 72:15:@250.4]
    node _T_55 = mux(_T_52, UInt<15>("h7fff"), UInt<15>("h0")) @[Bitwise.scala 72:12:@251.4]
    node _T_56 = bits(io_ctl_Imm16, 14, 0) @[DatPath.scala 71:66:@252.4]
    node _T_57 = bits(io_ctl_Imm16, 15, 15) @[DatPath.scala 71:95:@253.4]
    node _T_58 = bits(_T_57, 0, 0) @[Bitwise.scala 72:15:@254.4]
    node _T_61 = mux(_T_58, UInt<2>("h3"), UInt<2>("h0")) @[Bitwise.scala 72:12:@255.4]
    node _T_62 = cat(_T_55, _T_56) @[Cat.scala 30:58:@256.4]
    node br_sext = cat(_T_62, _T_61) @[Cat.scala 30:58:@257.4]
    node _T_63 = bits(pc_reg, 31, 28) @[DatPath.scala 72:34:@258.4]
    node _T_65 = cat(_T_63, io_ctl_Imm26) @[Cat.scala 30:58:@259.4]
    node j_target = cat(_T_65, UInt<2>("h0")) @[Cat.scala 30:58:@260.4]
    node _T_66 = bits(io_ctl_Imm16, 15, 15) @[DatPath.scala 73:70:@261.4]
    node _T_67 = bits(_T_66, 0, 0) @[Bitwise.scala 72:15:@262.4]
    node _T_70 = mux(_T_67, UInt<17>("h1ffff"), UInt<17>("h0")) @[Bitwise.scala 72:12:@263.4]
    node _T_71 = bits(io_ctl_Imm16, 14, 0) @[DatPath.scala 73:89:@264.4]
    node _T_72 = cat(_T_70, _T_71) @[Cat.scala 30:58:@265.4]
    node _T_74 = bits(io_ctl_Imm16, 15, 0) @[DatPath.scala 74:71:@266.4]
    node _T_75 = cat(UInt<16>("h0"), _T_74) @[Cat.scala 30:58:@267.4]
    node Imm32 = mux(io_ctl_ExtOp, _T_72, _T_75) @[DatPath.scala 73:30:@268.4]
    node _T_77 = add(pc_reg, UInt<32>("h4")) @[DatPath.scala 79:28:@270.4]
    node _T_78 = tail(_T_77, 1) @[DatPath.scala 79:28:@271.4]
    node _T_79 = add(pc_reg, br_sext) @[DatPath.scala 80:25:@273.4]
    node _T_80 = tail(_T_79, 1) @[DatPath.scala 80:25:@274.4]
    node _T_82 = add(_T_80, UInt<32>("h4")) @[DatPath.scala 80:35:@275.4]
    node _T_83 = tail(_T_82, 1) @[DatPath.scala 80:35:@276.4]
    node _T_85 = eq(io_ctl_ALUctr, UInt<3>("h3")) @[DatPath.scala 82:40:@278.4]
    node pc4_en = mux(_T_85, UInt<1>("h0"), UInt<1>("h1")) @[DatPath.scala 82:25:@279.4]
    node _T_89 = eq(pc4_en, UInt<1>("h1")) @[DatPath.scala 86:57:@280.4]
    node _T_91 = eq(io_ctl_nPC_sel, UInt<1>("h0")) @[DatPath.scala 87:65:@281.4]
    node _T_92 = and(_T_89, _T_91) @[DatPath.scala 86:68:@282.4]
    node _T_94 = eq(io_ctl_ExtOp, UInt<1>("h1")) @[DatPath.scala 88:63:@283.4]
    node _T_96 = eq(pc4_en, UInt<1>("h1")) @[DatPath.scala 88:85:@284.4]
    node _T_97 = and(_T_94, _T_96) @[DatPath.scala 88:74:@285.4]
    node _T_99 = eq(io_ctl_nPC_sel, UInt<1>("h1")) @[DatPath.scala 89:65:@286.4]
    node _T_100 = and(_T_97, _T_99) @[DatPath.scala 88:96:@287.4]
    node _T_102 = eq(io_ctl_ExtOp, UInt<1>("h0")) @[DatPath.scala 90:63:@288.4]
    node _T_104 = eq(pc4_en, UInt<1>("h1")) @[DatPath.scala 90:85:@289.4]
    node _T_105 = and(_T_102, _T_104) @[DatPath.scala 90:75:@290.4]
    node _T_107 = eq(io_ctl_nPC_sel, UInt<1>("h1")) @[DatPath.scala 91:65:@291.4]
    node _T_108 = and(_T_105, _T_107) @[DatPath.scala 90:96:@292.4]
    node _T_110 = eq(pc4_en, UInt<1>("h0")) @[DatPath.scala 92:57:@293.4]
    node _T_112 = eq(io_ctl_nPC_sel, UInt<1>("h0")) @[DatPath.scala 93:65:@294.4]
    node _T_113 = and(_T_110, _T_112) @[DatPath.scala 92:69:@295.4]
    node _T_115 = mux(_T_113, UInt<1>("h0"), pc_plus4) @[Mux.scala 61:16:@296.4]
    node _T_116 = mux(_T_108, j_target, _T_115) @[Mux.scala 61:16:@297.4]
    node _T_117 = mux(_T_100, pc_br, _T_116) @[Mux.scala 61:16:@298.4]
    node _T_118 = mux(_T_92, pc_plus4, _T_117) @[Mux.scala 61:16:@299.4]
    node _T_119 = mux(io_ctl_ALUsrc, Imm32, BusB) @[DatPath.scala 100:31:@303.4]
    io_imem_addr <= pc_reg
    io_dmem_addr <= alu9.io_ALUout
    io_dmem_datIn <= BusB
    io_dat_zero <= alu9.io_cmp_out
    BusA <= RegFile._T_45.data
    BusB <= RegFile._T_46.data
    BusWr <= _T_50
    pc_next <= _T_118
    pc_plus4 <= _T_78
    pc_br <= _T_83
    alu9.io_in1 <= BusA
    alu9.io_in2 <= _T_119
    alu9.io_ALUctr <= io_ctl_ALUctr
    alu9.clock <= clock
    alu9.reset <= reset
    pc_reg <= mux(reset, UInt<32>("h0"), pc_next)
    RegFile._T_45.addr <= io_ctl_Rs @[:@208.2]
    RegFile._T_45.en <= UInt<1>("h1") @[:@208.2]
    RegFile._T_45.clk <= clock @[:@208.2]
    RegFile._T_46.addr <= io_ctl_Rt @[:@208.2]
    RegFile._T_46.en <= UInt<1>("h1") @[:@208.2]
    RegFile._T_46.clk <= clock @[:@208.2]
    RegFile._T_43.addr <= UInt<1>("h0") @[:@208.2]
    RegFile._T_43.en <= UInt<1>("h1") @[:@208.2]
    RegFile._T_43.clk <= clock @[:@208.2]
    RegFile._T_43.data <= UInt<1>("h0") @[:@208.2]
    RegFile._T_43.mask <= UInt<1>("h1") @[:@208.2]
    RegFile._T_49.addr <= _GEN_0 @[:@208.2]
    RegFile._T_49.en <= _GEN_2 @[:@208.2]
    RegFile._T_49.clk <= _GEN_1 @[:@208.2]
    RegFile._T_49.data <= _GEN_3 @[:@208.2]
    RegFile._T_49.mask <= _GEN_2 @[:@208.2]

  module Top : @[:@309.2]
    input clock : Clock @[:@310.4]
    input reset : UInt<1> @[:@311.4]
    input io_boot : UInt<1> @[:@312.4]
    input io_test_im_wr : UInt<1> @[:@312.4]
    input io_test_im_rd : UInt<1> @[:@312.4]
    input io_test_im_addr : UInt<32> @[:@312.4]
    input io_test_im_in : UInt<32> @[:@312.4]
    output io_test_im_out : UInt<32> @[:@312.4]
    input io_test_dm_wr : UInt<1> @[:@312.4]
    input io_test_dm_rd : UInt<1> @[:@312.4]
    input io_test_dm_addr : UInt<32> @[:@312.4]
    input io_test_dm_in : UInt<32> @[:@312.4]
    output io_test_dm_out : UInt<32> @[:@312.4]
    output io_valid : UInt<1> @[:@312.4]
  
    inst cpath of CtlPath @[Top.scala 35:33:@317.4]
    inst dpath of DatPath @[Top.scala 36:33:@321.4]
    mem imm : @[Top.scala 43:22:@340.4]
      data-type => UInt<32>
      depth => 256
      read-latency => 0
      write-latency => 1
      reader => _T_34
      reader => _T_46
      writer => _T_24
      read-under-write => undefined
    mem dmm : @[Top.scala 44:22:@341.4]
      data-type => UInt<32>
      depth => 1024
      read-latency => 0
      write-latency => 1
      reader => _T_39
      reader => _T_50
      reader => _T_61
      writer => _T_29
      writer => _T_53
      read-under-write => undefined
    node _T_21 = and(io_boot, io_test_im_wr) @[Top.scala 48:23:@345.4]
    node _T_22 = shr(io_test_im_addr, 2) @[Top.scala 49:37:@347.6]
    node _T_23 = bits(_T_22, 7, 0) @[:@348.6]
    node _GEN_0 = validif(_T_21, _T_23) @[Top.scala 48:40:@346.4]
    node _GEN_1 = validif(_T_21, clock) @[Top.scala 48:40:@346.4]
    node _GEN_2 = mux(_T_21, UInt<1>("h1"), UInt<1>("h0")) @[Top.scala 48:40:@346.4]
    node _GEN_3 = validif(_T_21, io_test_im_in) @[Top.scala 48:40:@346.4]
    node _GEN_4 = mux(_T_21, UInt<1>("h0"), UInt<1>("h0")) @[Top.scala 48:40:@346.4]
    node _T_26 = and(io_boot, io_test_dm_wr) @[Top.scala 52:23:@353.4]
    node _T_27 = shr(io_test_dm_addr, 2) @[Top.scala 53:37:@355.6]
    node _T_28 = bits(_T_27, 9, 0) @[:@356.6]
    node _GEN_5 = validif(_T_26, _T_28) @[Top.scala 52:40:@354.4]
    node _GEN_6 = validif(_T_26, clock) @[Top.scala 52:40:@354.4]
    node _GEN_7 = mux(_T_26, UInt<1>("h1"), UInt<1>("h0")) @[Top.scala 52:40:@354.4]
    node _GEN_8 = validif(_T_26, io_test_dm_in) @[Top.scala 52:40:@354.4]
    node _GEN_9 = mux(_T_26, UInt<1>("h0"), _GEN_4) @[Top.scala 52:40:@354.4]
    node _T_31 = and(io_boot, io_test_im_rd) @[Top.scala 56:23:@361.4]
    node _T_32 = shr(io_test_im_addr, 2) @[Top.scala 57:55:@363.6]
    node _T_33 = bits(_T_32, 7, 0) @[:@364.6]
    node _GEN_10 = validif(_T_31, _T_33) @[Top.scala 56:40:@362.4]
    node _GEN_11 = validif(_T_31, clock) @[Top.scala 56:40:@362.4]
    node _GEN_12 = mux(_T_31, UInt<1>("h1"), UInt<1>("h0")) @[Top.scala 56:40:@362.4]
    node _GEN_13 = mux(_T_31, imm._T_34.data, UInt<1>("h0")) @[Top.scala 56:40:@362.4]
    node _GEN_14 = mux(_T_31, UInt<1>("h0"), _GEN_9) @[Top.scala 56:40:@362.4]
    node _T_36 = and(io_boot, io_test_dm_rd) @[Top.scala 60:23:@369.4]
    node _T_37 = shr(io_test_dm_addr, 2) @[Top.scala 61:55:@371.6]
    node _T_38 = bits(_T_37, 9, 0) @[:@372.6]
    node _GEN_15 = validif(_T_36, _T_38) @[Top.scala 60:40:@370.4]
    node _GEN_16 = validif(_T_36, clock) @[Top.scala 60:40:@370.4]
    node _GEN_17 = mux(_T_36, UInt<1>("h1"), UInt<1>("h0")) @[Top.scala 60:40:@370.4]
    node _GEN_18 = mux(_T_36, dmm._T_39.data, UInt<1>("h0")) @[Top.scala 60:40:@370.4]
    node _GEN_19 = mux(_T_36, UInt<1>("h0"), _GEN_14) @[Top.scala 60:40:@370.4]
    node _T_42 = eq(io_boot, UInt<1>("h0")) @[Top.scala 64:15:@377.4]
    node _T_44 = shr(dpath.io_imem_addr, 2) @[Top.scala 65:75:@379.6]
    node _T_45 = bits(_T_44, 7, 0) @[:@380.6]
    node _T_47 = mux(io_boot, UInt<1>("h0"), imm._T_46.data) @[Top.scala 65:37:@382.6]
    node _T_48 = shr(dpath.io_dmem_addr, 2) @[Top.scala 66:64:@384.6]
    node _T_49 = bits(_T_48, 9, 0) @[:@385.6]
    node _T_51 = shr(dpath.io_dmem_addr, 2) @[Top.scala 68:48:@389.8]
    node _T_52 = bits(_T_51, 9, 0) @[:@390.8]
    node _GEN_20 = validif(cpath.io_MemWr, _T_52) @[Top.scala 67:39:@388.6]
    node _GEN_21 = validif(cpath.io_MemWr, clock) @[Top.scala 67:39:@388.6]
    node _GEN_22 = mux(cpath.io_MemWr, UInt<1>("h1"), UInt<1>("h0")) @[Top.scala 67:39:@388.6]
    node _GEN_23 = validif(cpath.io_MemWr, dpath.io_dmem_datIn) @[Top.scala 67:39:@388.6]
    node _GEN_24 = validif(_T_42, _T_45) @[Top.scala 64:24:@378.4]
    node _GEN_25 = validif(_T_42, clock) @[Top.scala 64:24:@378.4]
    node _GEN_26 = mux(_T_42, UInt<1>("h1"), UInt<1>("h0")) @[Top.scala 64:24:@378.4]
    node _GEN_27 = mux(_T_42, _T_47, _GEN_19) @[Top.scala 64:24:@378.4]
    node _GEN_28 = validif(_T_42, _T_49) @[Top.scala 64:24:@378.4]
    node _GEN_29 = validif(_T_42, dmm._T_50.data) @[Top.scala 64:24:@378.4]
    node _GEN_30 = validif(_T_42, _GEN_20) @[Top.scala 64:24:@378.4]
    node _GEN_31 = validif(_T_42, _GEN_21) @[Top.scala 64:24:@378.4]
    node _GEN_32 = mux(_T_42, _GEN_22, UInt<1>("h0")) @[Top.scala 64:24:@378.4]
    node _GEN_33 = validif(_T_42, _GEN_23) @[Top.scala 64:24:@378.4]
    reg clk_cnt : UInt<32>, clock with :
      reset => (UInt<1>("h0"), clk_cnt) @[Top.scala 72:30:@395.4]
    node _T_57 = add(clk_cnt, UInt<1>("h1")) @[Top.scala 73:28:@396.4]
    node _T_58 = tail(_T_57, 1) @[Top.scala 73:28:@397.4]
    node _T_59 = shr(io_test_dm_addr, 2) @[Top.scala 82:37:@399.4]
    node _T_60 = bits(_T_59, 9, 0) @[:@400.4]
    node _T_62 = bits(reset, 0, 0) @[Top.scala 75:15:@402.4]
    node _T_64 = eq(_T_62, UInt<1>("h0")) @[Top.scala 75:15:@403.4]
    io_test_im_out <= _GEN_13
    io_test_dm_out <= _GEN_18
    io_valid <= cpath.io_valid
    cpath.io_Inst <= _GEN_27
    cpath.io_boot <= io_boot
    cpath.io_dat_zero <= dpath.io_dat_zero
    cpath.clock <= clock
    cpath.reset <= reset
    dpath.io_dmem_datOut <= _GEN_29
    dpath.io_ctl_nPC_sel <= cpath.io_ctl_nPC_sel
    dpath.io_ctl_RegWr <= cpath.io_ctl_RegWr
    dpath.io_ctl_RegDst <= cpath.io_ctl_RegDst
    dpath.io_ctl_ExtOp <= cpath.io_ctl_ExtOp
    dpath.io_ctl_ALUctr <= cpath.io_ctl_ALUctr
    dpath.io_ctl_ALUsrc <= cpath.io_ctl_ALUsrc
    dpath.io_ctl_MemtoReg <= cpath.io_ctl_MemtoReg
    dpath.io_ctl_Rd <= cpath.io_ctl_Rd
    dpath.io_ctl_Rt <= cpath.io_ctl_Rt
    dpath.io_ctl_Rs <= cpath.io_ctl_Rs
    dpath.io_ctl_Imm16 <= cpath.io_ctl_Imm16
    dpath.io_ctl_Imm26 <= cpath.io_ctl_Imm26
    dpath.clock <= clock
    dpath.reset <= reset
    imm._T_34.addr <= _GEN_10 @[:@309.2]
    imm._T_34.en <= _GEN_12 @[:@309.2]
    imm._T_34.clk <= _GEN_11 @[:@309.2]
    imm._T_46.addr <= _GEN_24 @[:@309.2]
    imm._T_46.en <= _GEN_26 @[:@309.2]
    imm._T_46.clk <= _GEN_25 @[:@309.2]
    imm._T_24.addr <= _GEN_0 @[:@309.2]
    imm._T_24.en <= _GEN_2 @[:@309.2]
    imm._T_24.clk <= _GEN_1 @[:@309.2]
    imm._T_24.data <= _GEN_3 @[:@309.2]
    imm._T_24.mask <= _GEN_2 @[:@309.2]
    dmm._T_39.addr <= _GEN_15 @[:@309.2]
    dmm._T_39.en <= _GEN_17 @[:@309.2]
    dmm._T_39.clk <= _GEN_16 @[:@309.2]
    dmm._T_50.addr <= _GEN_28 @[:@309.2]
    dmm._T_50.en <= _GEN_26 @[:@309.2]
    dmm._T_50.clk <= _GEN_25 @[:@309.2]
    dmm._T_61.addr <= _T_60 @[:@309.2]
    dmm._T_61.en <= UInt<1>("h1") @[:@309.2]
    dmm._T_61.clk <= clock @[:@309.2]
    dmm._T_29.addr <= _GEN_5 @[:@309.2]
    dmm._T_29.en <= _GEN_7 @[:@309.2]
    dmm._T_29.clk <= _GEN_6 @[:@309.2]
    dmm._T_29.data <= _GEN_8 @[:@309.2]
    dmm._T_29.mask <= _GEN_7 @[:@309.2]
    dmm._T_53.addr <= _GEN_30 @[:@309.2]
    dmm._T_53.en <= _GEN_32 @[:@309.2]
    dmm._T_53.clk <= _GEN_31 @[:@309.2]
    dmm._T_53.data <= _GEN_33 @[:@309.2]
    dmm._T_53.mask <= _GEN_32 @[:@309.2]
    clk_cnt <= mux(reset, UInt<32>("h0"), _T_58)
    printf(clock, and(and(UInt<1>("h1"), _T_64), UInt<1>("h1")), "Cyc=%d, pc=0x%x, Inst=0x%x, boot=%d, dmem_in = 0x%x, rd_dmm=0x%x, dmm=0x%x\n", clk_cnt, dpath.io_imem_addr, cpath.io_Inst, cpath.io_boot, dpath.io_dmem_datIn, io_test_dm_out, dmm._T_61.data) @[Top.scala 75:15:@405.6]
