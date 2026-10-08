;=============================================================================
; RX V3 Assembler
;=============================================================================

;==============
;SETUP
;==============
define RX RX
element RX.reg
element RX.R : RX.reg + 1;Register
element RX.A : RX.reg + 2;Accumulator
element RX.C : RX.reg + 4;Control

element RX.DR : RX.reg  + 8;Double Precision Floating Point
element RX.DRH : RX.reg + 8;DP FP High
element RX.DRL : RX.reg + 8;DP FP Low
element RX.DRC : RX.reg + 8;DP FP Control

;registers
repeat 16, i:0
   element R#i#?: RX.R + i
end repeat
SP = R0

;accumulators
element A0: RX.A + 0
element A1: RX.A + 1
ACC0 = A0
ACC1 = A1


;control registers
iterate <name, val>, PSW,0, PC,1, USP,2, FPSW,3, BPSW,8, BPC,9, ISP,10, FINTV,11, INTB,12, EXTB,13
   element name?: RX.C + val
end iterate

;dp registers
repeat 16, i:0
   element DR#i#?:  RX.DR  + i
   element DRH#i#?: RX.DRH + i
   element DRL#i#?: RX.DRL + i
end repeat

;dp control registers
iterate <name, val>, DPSW,0, DCMR,1, DECNT,2, DEPC,3
   element name?: RX.DRC + val
end iterate


define RX.ubyte?  :5
define RX.byte?   :1
define RX.uword?  :6
define RX.word?   :2
define RX.long?   :4
define RX.double? :8

define @dst @dst
define @src @src
define @src2 @src2
define @aux @aux
define @aux2 @aux2

;====================
;HELPER MACROS
;====================
iterate context, @dst, @src, @src2, @aux, @aux2
   namespace context
             iterate name, size, sext, type, reg, reg2, reg_count, imm, imm_size, disp, disp_size, unresolved
                define name
             end iterate

             calminstruction RX.parse_operand#context operand
                local prefix, suffix
                compute size, 4
                compute disp_size, 0
                compute imm_size, 0
                compute sext, 0
                compute reg_count, 0
                compute reg, 0

                match , operand
                jno main
                compute type, ''
                exit
               main:
                transform operand

                match prefix suffix, operand
                jno no_size_prefix
                transform prefix, RX
                jno no_size_prefix
                match :size, prefix
                jno no_size_prefix
                arrange operand, suffix
                check size > 4
                jyes adjust_size
                jump no_size_prefix

               adjust_size:
                compute sext, 1
                compute size, size - 4

               no_size_prefix:
                match [address], operand
                jyes memory_operand

               immediate_operand:
                compute type, 'imm'
                compute imm, +operand

                compute unresolved, 0
                check defined operand
                jyes operand_resolved
                compute unresolved, 1

               operand_resolved:
                check imm eq (imm element 1)
                jno operand_ready
                check 1 metadataof (1 metadataof imm) relativeto RX.reg
                jyes register_operand

               operand_ready:
                check type = 'imm'
                jno exit_parse
                check imm >= -80h & imm < 80h
                jyes imm_8
                check imm >= -8000h & imm < 8000h
                jyes imm_16
                check imm >= -800000h & imm < 800000h
                jyes imm_24
                check imm > 0FFFFFFFFh
                jyes err_imm_big
                compute imm_size, 0
                exit

               imm_8:
                compute imm_size, 1
                exit

               imm_16:
                compute imm_size, 2
                exit

               imm_24:
                compute imm_size, 3
                exit

               err_imm_big:
                err 'Immediate greater than 2^32-1'
                exit

               exit_parse:
                exit

               register_operand:
                compute disp_size, 3 ;default value in encoding 'ld = 11' '00' also valid
                compute reg, 0 scaleof (1 metadataof imm)
                compute reg_type, 1 metadataof (1 metadataof imm) - RX.reg
                check reg_type = 1
                jyes gp_reg
                check reg_type = 2
                jyes acc_reg
                check reg_type = 4
                jyes ctrl_reg
                check reg_type = 8
                jyes dp_reg
                err "unknown register type"
                exit

               gp_reg:
                compute type, 'reg'
                exit

               acc_reg:
                compute type, 'acc'
                exit

               ctrl_reg:
                compute type, 'creg'
                exit

               dp_reg:
                check (1 metadataof imm) relativeto RX.DRH
                jyes dp_high_reg
                check (1 metadataof imm) relativeto RX.DRL
                jyes dp_low_reg
                check (1 metadataof imm) relativeto RX.DRC
                jyes dp_ctrl_reg
                compute type, 'dp'
                exit

               dp_high_reg:
                compute type, 'dph'
                exit

               dp_low_reg:
                compute type, 'dpl'
                exit

               dp_ctrl_reg:
                compute type, 'dpc'
                exit

               memory_operand:
                compute type, 'mem'
                compute address_registers, 0
                compute i, 1
                compute address, address

               extract_registers:
                check i > elementsof address
                jyes registers_extracted
                check 1 metadataof (i metadataof address) relativeto RX.reg
                jno next_term
                compute address_registers, address_registers + (i elementof address) * (i scaleof address)

               next_term:
                compute i, i + 1
                jump extract_registers

               registers_extracted:
                compute disp, address - address_registers
                compute reg_count, elementsof address_registers
                check reg_count = 0
                jyes find_disp_size
                check reg_count = 1
                jyes one_register
                check reg_count = 2
                jyes two_registers
                err "Too many registers in memory operand"
                exit

               two_registers:
                compute reg2, 0 scaleof( 1 metadataof( 2 elementof address_registers))
                compute reg2_type, (1 metadataof (2 metadataof address_registers)) - RX.reg
                check reg2_type = 1
                jyes one_register
                jump err_mem_type

               one_register:
                compute reg, 0 scaleof(1 metadataof( 1 elementof address_registers))
                compute reg_type, (1 metadataof (1 metadataof address_registers)) - RX.reg
                check reg_type = 1 | reg_type = 8
                jyes find_disp_size

               err_mem_type:
                err 'Register memory operand(s) must be R0-15'
                exit

               find_disp_size:
                 check disp relativeto 0
                 jno disp_16
                 check disp = 0
                 jyes disp_zero
                 check disp < 0
                 jyes err_disp_neg

                 compute tmp_div, disp / size
                 compute tmp, tmp_div * size
                 check tmp = disp
                 jno err_disp_align
                 compute disp, tmp_div

                 check disp <= 0FFh
                 jyes disp_8
                 check disp <= 0FFFFh
                 jyes disp_16

                err_disp_big:
                 err 'Displacement too large'
                 exit

                disp_zero:
                 compute disp_size, 0
                 exit

                disp_8:
                 compute disp_size, 1
                 exit

                disp_16:
                 compute disp_size, 2
                 exit

                err_disp_neg:
                 err 'Displacement is negative'
                 exit

               err_disp_align:
                err 'Displacement alignment error'

             end calminstruction

   end namespace
end iterate

;=====================
;INSTRUCTIONS
;=====================

iterate <name, opcode>, BRK,0h, NOP,3h, RTS,2h
   calminstruction name?
      emit 1, opcode
   end calminstruction
end iterate

iterate <name, opcode>, RTE,957Fh, RTFI,947Fh, SATR,937Fh, SCMPU,837Fh, SMOVB,8B7Fh, SMOVF,8F7Fh,\
                        SMOVU,877Fh, WAIT,967Fh

   calminstruction name?
      emit 2, opcode
   end calminstruction
end iterate

calminstruction POP? dst*
   call RX.parse_operand@dst, dst

   check @dst.type = 'reg'
   jno invalid_dst
   emit 2, 0B07Eh or (@dst.reg shl 8)
   exit

  invalid_dst:
   err 'Invalid destination'
   exit
end calminstruction

calminstruction PUSH? src*
   call RX.parse_operand@src, src

   check @src.type = 'reg'
   jyes is_reg
   check @src.type = 'mem'
   jno invalid_src

  is_mem:
   check @src.sext = 0
   jno invalid_size
   compute sz, @src.size - 1
   compute ld, @src.disp_size
   check sz = 3
   jno emit_mem_op
   compute sz, sz - 1

  emit_mem_op:
   emit 1, 0F4h or ld
   emit 1, 08h or (@src.reg shl 4) or sz
   emit ld, @src.disp
   exit

  is_reg:
   compute sz, @src.size - 1
   check sz = 3
   jno emit_reg_op
   compute sz, sz - 1

  emit_reg_op:
   emit 1, 7Eh
   emit 1, 80h or (sz shl 4) or @src.reg
   exit

  invalid_size:
   err 'Invalid size'
   exit

  invalid_src:
   err 'Invalid source'
   exit
end calminstruction

iterate <name, basecode>, PUSHC,0C07Eh, POPC,0E07Eh
   calminstruction name? dst*
      call RX.parse_operand@dst, dst

      check @dst.type = 'creg'
      jyes good_reg
      err 'Invalid operand'
      exit

     good_reg:
      compute opcode, basecode or (@dst.reg shl 8)
      emit 2, opcode
      exit
   end calminstruction
end iterate

iterate <name, opcode>, PUSHM,6Eh, POPM,6Fh
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg' & @src.type = 'reg'
      jno invalid_argument
      check @dst.reg = 0 & @src.reg = 0
      jyes invalid_register
      check @dst.reg <= @src.reg
      jno invalid_order
      emit 1, opcode
      emit 1, (@dst.reg shl 4) or @src.reg
      exit

     invalid_order:
      err 'First register must be greater than second'
      exit

     invalid_argument:
      err 'Invalid operand type. R1-15 only'
      exit

     invalid_register:
      err 'R0 is invalid for this instruction'
   end calminstruction
end iterate

iterate <name, basecode>, JMP,007Fh, JSR,107Fh
   calminstruction name? src*
      call RX.parse_operand@src, src

      check @src.type = 'reg'
      jyes good_reg
      err 'Invalid source'
      exit

     good_reg:
      compute opcode, basecode or (@src.reg shl 8)
      emit 2, opcode
   end calminstruction
end iterate

iterate <name, basecode>, SAT,307Eh, POP,0B07Eh, ROLC,507Eh, RORC,407Eh
   calminstruction name? dst*
      call RX.parse_operand@dst, dst

      check @dst.type = 'reg'
      jyes good_reg
      err 'Invalid destination'
      exit

     good_reg:
      compute opcode, basecode or (@dst.reg shl 8)
      emit 2, opcode
   end calminstruction
end iterate

iterate <name, basecode>, MULHI,00FDh, MULLO,01FDh, MULLH,02FDh, EMULA,03FDh,\
                          MACHI,04FDh, MACLO,05FDh, MACLH,06FDh, EMACA,07FDh,\
                          MSBHI,44FDh, MSBLO,45FDh, MSBLH,46FDh, EMSBA,47FDh

   calminstruction name? dst*, src*, src2*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src
      call RX.parse_operand@src2, src2

      check @dst.type = 'acc' & @src.type = 'reg' & @src2.type = 'reg'
      jyes good_reg
      err 'Invalid operand'
      exit

     good_reg:
      compute opcode, basecode or (@dst.reg shl 11)
      emit 2, opcode
      compute regs, @src.reg shl 4 or @src2.reg
      emit 1, regs
   end calminstruction
end iterate

iterate <name, basecode>, MVTACHI,00h, MVTACLO,10h, MVTACGU,30h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @src.type = 'reg' & @dst.type = 'acc'
      jyes good_reg
      err 'Invalid operand'
      exit

     good_reg:
      emit 2, 17FDh
      compute opcode, (@src.reg or basecode) or @dst.reg shl 7
      emit 1, opcode
   end calminstruction
end iterate

iterate <name, basecode>, MVFACHI,00h, MVFACLO,10h, MVFACMI,20h, MVFACGU,30h
   calminstruction name? dst*, src*, aux*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src
      call RX.parse_operand@aux, aux

      check @dst.type = 'reg' & @src.type = 'acc' & @aux.type = 'imm'
      jyes good_operands
      err 'Invalid operand'
      exit

     good_operands:
      compute opcode1, 1Eh
      compute opcode2, basecode or @src.reg shl 7
      check @aux.imm = 0
      jyes shift_zero
      check @aux.imm = 1
      jyes shift_one
      check @aux.imm = 2
      jyes shift_two
      err 'Shift value outside range'
      exit

     shift_one:
      compute opcode2, opcode2 or 1  shl 6

     shift_zero:
      compute opcode1, opcode1 or 1

     shift_two:
      compute opcode2, opcode2 or @dst.reg

      emit 1, 0FDh
      emit 1, opcode1
      emit 1, opcode2
   end calminstruction
end iterate

iterate <name, basecode>, RACL,0019h, RACW,0018h, RDACL,4019h, RDACW,4018h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'acc' & @src.type = 'imm'
      jyes good_operands
      err 'Invalid operand'
      exit

     good_operands:
      compute opcode, basecode or (@dst.reg shl 15)
      check @src.imm = 1
      jyes shift_one
      check @src.imm = 2
      jyes shift_two
      err 'Shift value outside range'
      exit

     shift_two:
      compute opcode, opcode or (1 shl 4)

     shift_one:
      emit 1, 0FDh
      emit 2, opcode
   end calminstruction
end iterate

iterate <name, basecode1, basecode2>, ABS,207Eh,0FFCh, NOT,007Eh,3BFCh, NEG,107Eh,07FCh
   calminstruction name? dst*, src
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg'
      jyes valid_dst
      err 'Invalid destination'
      exit

     valid_dst:
      check @src.type = ''
      jyes one_operand
      check @src.type = 'reg'
      jyes two_operand
      err 'Invalid source'
      exit

     one_operand:
      compute opcode, basecode1 or (@dst.reg shl 8)
      emit 2, opcode
      exit

     two_operand:
      emit 2, basecode2
      compute regs, @src.reg shl 4 or @dst.reg
      emit 1, regs

   end calminstruction
end iterate

calminstruction SBB? dst*, src*
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src

   check @dst.type = 'reg'
   jno invalid
   check @src.type = 'reg'
   jyes reg_reg
   check @src.type = 'mem'
   jyes reg_mem
   err 'Invalid source'

  reg_reg:
   emit 2, 03FCh
   compute regs, @src.reg shl 4 or @dst.reg
   emit 1, regs
   exit

  reg_mem:
   compute ld, @src.disp_size
   emit 2, 0A006h or (ld shl 8)
   emit 2, (@src.reg shl 4 or @dst.reg) shl 8
   emit ld, @src.disp
   exit

  invalid:
   err 'Invalid destination'
end calminstruction

calminstruction ADC? dst*, src*
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src

   check @dst.type = 'reg'
   jno invalid
   check @src.type = 'imm'
   jyes reg_imm
   check @src.type = 'reg'
   jyes reg_reg
   check @src.type = 'mem'
   jyes reg_mem
   err 'Invalid source'
   exit

  reg_imm:
   compute opcode, 70FDh or (@src.imm_size shl 10)
   emit 2, opcode
   emit 1, 20h or @dst.reg
   compute imm_bytes, @src.imm_size
   check imm_bytes = 0
   jno emit_imm
   compute imm_bytes, 4

  emit_imm:
   emit imm_bytes, @src.imm
   exit

  reg_reg:
   emit 2, 0BFCh
   compute regs, @src.reg shl 4 or @dst.reg
   emit 1, regs
   exit

  reg_mem:
   check @src.size = 4
   jyes good_size
   err 'Size must be long'
   exit

  good_size:
   compute ld, @src.disp_size
   compute opcode, 0A006h or (ld shl 8)
   compute regs, @src.reg shl 4 or @dst.reg
   emit 2, opcode
   emit 2, (regs shl 8) or 2
   emit ld, @src.disp
   exit

  invalid:
   err 'Invalid destination'
end calminstruction

iterate <name, basecode1, basecode2, basecode3>, DIVU,9070h,0024h,0920h, DIV,8070h,0020h,0820h,\
                                                 EMULU,7070h,001Ch,0720h, EMUL,6070h,0018h,0620h,\
                                                 TST,0C070h,0054h,0C20h, MAX,4070h,0010h,0420h,\
                                                 MIN,5070h,0014h,0520h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg'
      jno invalid
      check @src.type = 'imm'
      jyes reg_imm
      check @src.type = 'reg'
      jyes reg_reg
      check @src.type = 'mem'
      jyes reg_mem
      err 'Invalid source'
      exit

     reg_imm:
      emit 1, 0FDh
      compute opcode, (basecode1 or @src.imm_size shl 2)
      compute opcode, opcode or (@dst.reg shl 8)
      emit 2, opcode
      compute imm_bytes, @src.imm_size
      check imm_bytes = 0
      jno emit_imm
      compute imm_bytes, 4

     emit_imm:
      emit imm_bytes, @src.imm
      exit

     reg_reg:
      emit 1, 0FCh
      compute ld, @src.disp_size
      compute opcode, basecode2 or ld
      compute regs, (@src.reg shl 4) or @dst.reg
      emit 2, opcode or (regs shl 8)
      check ld = 3
      jyes done
      emit ld, @src.disp

     done:
      exit

     reg_mem:
      local mx

      check @src.size = 1 & @src.sext = 1
      jyes reg_reg
      emit 1, 06h
      compute ld, @src.disp_size
      compute opcode, basecode3 or ld
      check @src.sext = 1
      jyes memex_uword
      check @src.size <= 2
      jyes memex_B_W
      compute mx, 2
      jump emit_rest

     memex_B_W:
      compute mx, @src.size - 1
      jump emit_rest

     memex_uword:
      compute mx, 3

     emit_rest:
      emit 2, opcode or (mx shl 6)
      compute regs, @src.reg shl 4 or @dst.reg
      emit 1, regs
      emit ld, @src.disp
      exit

     invalid:
      err 'Invalid destination'
   end calminstruction
end iterate

calminstruction SUB? dst*, src*, src2
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src
   call RX.parse_operand@src2, src2

   check @dst.type = 'reg'
   jno invalid_dst
   check @src2.type = ''
   jyes two_operand
   check @src2.type = 'reg' & @src.type = 'reg'
   jno invalid_src
   emit 1, 0FFh
   emit 1, @dst.reg
   emit 1, (@src.reg shl 4) or @src2.reg
   exit

  two_operand:
   check @src.type = 'imm'
   jyes reg_imm
   check @src.type = 'reg'
   jyes reg_reg
   check @src.type = 'mem'
   jyes reg_mem
   jump invalid_src

  reg_imm:
   check @src.imm >= 0 & @src.imm <= 15
   jno invalid_imm
   emit 1, 60h
   compute opcode, (@src.imm shl 4) or @dst.reg
   emit 1, opcode
   exit

  reg_reg:
   compute ld, @src.disp_size
   emit 1, 40h or ld
   compute regs, (@src.reg shl 4) or @dst.reg
   emit 1, regs
   check ld = 3
   jyes done
   emit ld, @src.disp

  done:
   exit

  reg_mem:
   local mx

   check @src.size = 1 & @src.sext = 1
   jyes reg_reg
   emit 1, 06h
   compute ld, @src.disp_size
   check @src.sext = 1
   jyes memex_uword
   check @src.size <= 2
   jyes memex_B_W
   compute mx, 2
   jump emit_rest

  memex_B_W:
   compute mx, @src.size - 1
   jump emit_rest

  memex_uword:
   compute mx, 3

  emit_rest:
   emit 1, ld or (mx shl 6)
   compute regs, @src.reg shl 4 or @dst.reg
   emit 1, regs
   emit ld, @src.disp
   exit

  invalid_imm:
   err 'Immediate not in range 0..15'
   exit

  invalid_src:
   err 'Invalid source'
   exit

  invalid_dst:
   err 'Invalid destination'
end calminstruction

calminstruction ADD? dst*, src*, src2
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src
   call RX.parse_operand@src2, src2

   check @dst.type = 'reg'
   jno invalid_dst
   check @src2.type = ''
   jno three_operand
   check @src.type = 'imm'
   jyes reg_imm
   check @src.type = 'reg'
   jyes reg_reg
   check @src.type = 'mem'
   jno invalid_src

   local mx

   check @src.size = 1 & @src.sext = 1
   jyes reg_reg
   emit 1, 06h
   compute ld, @src.disp_size
   check @src.sext = 1
   jyes memex_uword
   check @src.size <= 2
   jyes memex_B_W
   compute mx, 2
   jump emit_rest

  memex_B_W:
   compute mx, @src.size - 1
   jump emit_rest

  memex_uword:
   compute mx, 3

  emit_rest:
   emit 1, 08h or ld or (mx shl 6)
   compute regs, @src.reg shl 4 or @dst.reg
   emit 1, regs
   emit ld, @src.disp
   exit

  reg_reg:
   compute ld, @src.disp_size
   emit 1, 48h or ld
   emit 1, @src.reg shl 4 or @dst.reg
   check ld = 3
   jyes done
   emit ld, @src.disp
  done:
   exit

  three_operand:
   check @src2.type = 'imm'
   jyes reg_reg_imm
   check @src2.type = 'reg'
   jno invalid_src
   emit 1, 0FFh
   emit 1, 20h or @dst.reg
   compute regs, (@src.reg shl 4) or @src2.reg
   emit 1, regs
   exit

  reg_imm:
   check @src.imm >= 0 & @src.imm <= 15
   jno adjust_regs
   emit 1, 62h
   emit 1, @src.imm shl 4 or @dst.reg
   exit

  adjust_regs:       ;add R1,25 --> add R1,R1,25
   compute @src2.imm, @src.imm
   compute @src2.imm_size, @src.imm_size
   compute @src.reg, @dst.reg

  reg_reg_imm:
   compute li, @src2.imm_size
   emit 1, 70h or li
   emit 1, (@src.reg shl 4) or @dst.reg
   check li = 0
   jno emit_imm
   compute li, 4

  emit_imm:
   emit li, @src2.imm
   exit

  invalid_src:
   err 'Invalid source'
   exit

  invalid_dst:
   err 'Invalid destination'
end calminstruction

iterate <name, basecode1, basecode2, basecode3, basecode4, basecode5>, MUL,63h,10h,4Ch,0Ch,30h,\
                                                                       AND,64h,20h,50h,10h,40h,\
                                                                       OR ,65h,30h,54h,14h,50h
   calminstruction name? dst*, src*, src2
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src
      call RX.parse_operand@src2, src2

      check @dst.type = 'reg'
      jno invalid_dst
      check @src2.type = ''
      jno three_operand
      check @src.type = 'imm'
      jyes reg_imm
      check @src.type = 'reg'
      jyes reg_reg
      check @src.type = 'mem'
      jno invalid_src

      local mx

      check @src.size = 1 & @src.sext = 1
      jyes reg_reg
      emit 1, 06h
      compute ld, @src.disp_size
      check @src.sext = 1
      jyes memex_uword
      check @src.size <= 2
      jyes memex_B_W
      compute mx, 2
      jump emit_rest

     memex_B_W:
      compute mx, @src.size - 1
      jump emit_rest

     memex_uword:
      compute mx, 3

     emit_rest:
      emit 1, basecode4 or ld or (mx shl 6)
      compute regs, @src.reg shl 4 or @dst.reg
      emit 1, regs
      emit ld, @src.disp
      exit

     reg_reg:
      compute ld, @src.disp_size
      emit 1, basecode3 or ld
      emit 1, @src.reg shl 4 or @dst.reg
      check ld = 3
      jyes done
      emit ld, @src.disp
     done:
      exit

     reg_imm:
      check @src.imm >= 0 & @src.imm <= 15
      jno reg_imm4
      emit 1, basecode1
      emit 1, @src.imm shl 4 or @dst.reg
      exit

     reg_imm4:
      compute li, @src.imm_size
      emit 1, 74h or li
      emit 1, basecode2 or @dst.reg
      check li = 0
      jno emit_reg_imm
      compute li, 4

     emit_reg_imm:
      emit li, @src.imm
      exit

     three_operand:
      check @src2.type = 'reg' & @src.type = 'reg'
      jno invalid_src
      emit 1, 0FFh
      emit 1, basecode5 or @dst.reg
      compute regs, (@src.reg shl 4) or @src2.reg
      emit 1, regs
      exit

     invalid_src:
      err 'Invalid source'
      exit

     invalid_dst:
      err 'Invalid destination'
   end calminstruction
end iterate

calminstruction XOR? dst*, src*, src2
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src
   call RX.parse_operand@src2, src2

   check @dst.type = 'reg'
   jno invalid_dst
   check @src2.type = ''
   jno three_operand
   check @src.type = 'reg'
   jyes reg_reg
   check @src.type = 'imm'
   jyes reg_imm
   check @src.type = 'mem'
   jno invalid_src

   local mx

   check @src.size = 1 & @src.sext = 1
   jyes reg_reg
   emit 1, 06h
   compute ld, @src.disp_size
   check @src.sext = 1
   jyes memex_uword
   check @src.size <= 2
   jyes memex_B_W
   compute mx, 2
   jump emit_rest

  memex_B_W:
   compute mx, @src.size - 1
   jump emit_rest

  memex_uword:
   compute mx, 3

  emit_rest:
   emit 1, 20h or ld or (mx shl 6)
   emit 1, 0Dh
   emit 1,  @src.reg shl 4 or @dst.reg
   emit ld, @src.disp
   exit

  reg_reg:
   compute ld, @src.disp_size
   emit 2, 34FCh or (ld shl 8)
   emit 1, (@src.reg shl 4) or @dst.reg
   check ld = 3
   jno emit_disp
   exit

  emit_disp:
   emit ld, @src.disp
   exit

  reg_imm:
   compute li, @src.imm_size
   emit 2, 70FDh or (li shl 10)
   emit 1, 0D0h or @dst.reg
   check li = 0
   jno emit_imm
   compute li, 4

  emit_imm:
   emit li, @src.imm
   exit

  three_operand:
   check @src.type = 'reg' & @src2.type = 'reg'
   jno invalid_src
   emit 2, 60FFh or (@dst.reg shl 8)
   emit 1, (@src.reg shl 4) or @src2.reg
   exit

  invalid_dst:
   err 'Invalid destination'
   exit

  invalid_src:
   err 'Invalid source'
end calminstruction

calminstruction CMP? src*, src2*
   call RX.parse_operand@src, src
   call RX.parse_operand@src2, src2

   check @src.type = 'reg'
   jno invalid_src
   check @src2.type = 'reg'
   jyes reg_reg
   check @src2.type = 'imm'
   jyes reg_imm
   check @src2.type = 'mem'
   jno invalid_src2

   local mx

   check @src2.size = 1 & @src2.sext = 1
   jyes reg_reg
   emit 1, 06h
   compute ld, @src2.disp_size
   check @src2.sext = 1
   jyes memex_uword
   check @src2.size <= 2
   jyes memex_B_W
   compute mx, 2
   jump emit_rest

  memex_B_W:
   compute mx, @src2.size - 1
   jump emit_rest

  memex_uword:
   compute mx, 3

  emit_rest:
   emit 1, 04h or ld or (mx shl 6)
   emit 1,  @src2.reg shl 4 or @src.reg
   emit ld, @src2.disp
   exit

  reg_reg:
   compute ld, @src2.disp_size
   emit 1, 44h or ld
   emit 1, (@src2.reg shl 4) or @src.reg
   check ld = 3
   jno emit_disp
   exit

  emit_disp:
   emit ld, @src2.disp
   exit

  reg_imm:
   compute li, @src2.imm_size
   check @src2.imm >= 0
   jno reg_imm_sx
   check @src2.imm <= 0Fh
   jyes reg_imm4
   check @src2.imm <= 0FFh
   jno reg_imm_sx
   emit 2, 5075h or (@src.reg shl 8)
   emit 1, @src2.imm
   exit

  reg_imm4:
   emit 1, 61h
   emit 1, (@src2.imm shl 4) or @src.reg
   exit

  reg_imm_sx:
   emit 1, 74h or li
   emit 1, @src.reg
   check li = 0
   jno emit_imm
   compute li, 4

  emit_imm:
   emit li, @src2.imm
   exit

  invalid_src:
   err 'Invalid Source'
   exit

  invalid_src2:
   err 'Invalid second source'
end calminstruction

calminstruction RMPA? size
   compute sz, 2

   match , size
   jyes default

   match =byte, size
   jyes size_byte
   match =word, size
   jyes size_word
   match =long, size
   jyes default

   err 'Invalid size specifier'
   exit

  size_byte:
   compute sz, 0
   jump default

  size_word:
   compute sz, 1

  default:
   emit 2, 8C7Fh or (sz shl 8)

end calminstruction

calminstruction RTSD? dst*, src, src2
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src
   call RX.parse_operand@src2, src2

   check @dst.type = 'imm'
   jyes one_operand
   check @dst.type = 'reg' & @src.type = 'reg' & @src2.type = 'imm'
   jno invalid_operands
   compute tmp, @src2.imm
   check tmp mod 4 = 0
   check tmp >= 0 & tmp <= 4*255
   jno invalid_imm
   check @dst.reg = 0 | @src.reg = 0
   jyes invalid_reg
   check @dst.reg <= @src.reg
   jno invalid_order

   emit 1, 3Fh
   emit 1, (@dst.reg shl 4) or @src.reg
   emit 1, tmp shr 2
   exit

  one_operand:
   compute tmp, @dst.imm
   check tmp mod 4 = 0
   check @dst.imm >= 0 & @dst.imm <= 4*255
   jno invalid_imm

   emit 1,67h
   emit 1, tmp shr 2
   exit

  invalid_order:
   err 'Reg1 must be <= reg2'
   exit
  invalid_reg:
   err 'Register 0 is invalid for this instruction'
   exit

  invalid_imm:
   err 'immediate not in range'
   exit

  invalid_operands:
   err 'Invalid operand'
end calminstruction

iterate <name, opcode>, REVL,67h, REVW,65h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg' & @src.type = 'reg'
      jno invalid_type
      emit 1, 0FDh
      emit 1, opcode
      emit 1, @src.reg shl 4 or @dst.reg
      exit

      invalid_type:
      err 'Source and Destination must be R0-15'
   end calminstruction
end iterate

iterate <name, opcode>, SUNTIL,80h, SWHILE,84h
   calminstruction name? size
      compute sz, 2

      match , size
      jyes default

      match =byte, size
      jyes size_byte
      match =word, size
      jyes size_word
      match =long, size
      jyes default

      err 'Invalid size specifier'
      exit

     size_byte:
      compute sz, 0
      jump default

     size_word:
      compute sz, 1

     default:
      emit 1, 7Fh
      emit 1, opcode or sz
   end calminstruction
end iterate

calminstruction MOVCO? dst*, src*
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src

   check @dst.type = 'mem' & @src.type = 'reg'
   jno invalid_operand
   emit 2, 27FDh
   emit 1, (@dst.reg shl 4) or @src.reg
   exit

  invalid_operand:
   err 'Invalid operand'
end calminstruction

calminstruction MOVLI? dst*, src*
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src

   check @dst.type = 'reg' & @src.type = 'mem'
   jno invalid_operand
   emit 2, 27FDh
   emit 1, @dst shl 4 or @src.reg
   exit

  invalid_operand:
   err 'Invalid operand'
end calminstruction

iterate <name, basecode>, CLRPSW,0B0h, SETPSW,0A0h
   calminstruction name? dst*
      local flag

      match =C, dst
      jyes carry
      match =Z, dst
      jyes zero
      match =S, dst
      jyes sign
      match =O, dst
      jyes overflow
      match =I, dst
      jyes interrupt_enable
      match =U, dst
      jno invalid_operand
      compute flag, 9
      jump emit_opcode

     carry:
      compute flag, 0
      jump emit_opcode

     zero:
      compute flag, 1
      jump emit_opcode

     sign:
      compute flag, 2
      jump emit_opcode

     overflow:
      compute flag, 3
      jump emit_opcode

     interrupt_enable:
      compute flag, 8

     emit_opcode:
      compute opcode, basecode or flag
      emit 1, 7Fh
      emit 1, opcode
      exit

     invalid_operand:
      err 'Valid flags are: C, Z, S, O, I, U'
   end calminstruction
end iterate

calminstruction INT? src*
   call RX.parse_operand@src, src

   check @src.type = 'imm'
   jno invalid_operand
   check @src.imm >= -128 & @src.imm <= 255
   jno invalid_size
   emit 2, 6075h
   emit 1, @src.imm
   exit

  invalid_operand:
   err 'Operand must be imm:8'
   exit

  invalid_size:
   err 'Operand must be byte sized'
end calminstruction

iterate <name, basecode1, basecode2>, ROTL,6E00h,66h, ROTR,6C00h,64h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg'
      jno invalid_dst
      check @src.type = 'imm'
      jyes shift_imm
      check @src.type = 'reg'
      jno invalid_src

      emit 1, 0FDh
      emit 1, basecode2
      emit 1, (@src.reg shl 4) or @dst.reg
      exit

     shift_imm:
      check @src.imm >= 0 & @src.imm < 32
      jyes in_range
      err 'Immediate outside range 0..31'
      exit

     in_range:
      compute opcode, basecode1 or (@src.imm shl 4) or @dst.reg
      emit 1, 0FDh
      emit 2, opcode bswap 2
      exit

     invalid_src:
      err 'Invalid source'
      exit

     invalid_dst:
      err 'Invalid destination'
   end calminstruction
end iterate

iterate <name, basecode1, basecode2, basecode3>, SHAR,6A00h,61h,0A0h, SHLL,6C00h,62h,0C0h,\
                                                 SHLR,6800h,60h,0A0h
   calminstruction name? dst*, src*, src2
      call RX.parse_operand@dst, dst
      check @dst.type = 'reg'
      jno invalid_dst
      call RX.parse_operand@src, src
      call RX.parse_operand@src2, src2

      check @src2.type = ''
      jyes two_operand
      check @src2.type = 'imm' & @src.type = 'reg'
      jno invalid_src
      check @src2.imm >= 0 & @src2.imm < 32
      emit 1, 0FDh
      emit 1, basecode3 or @src2.imm
      emit 1, (@src.reg shl 4) or @dst.reg
      exit

     two_operand:
      check @src.type = 'reg'
      jyes reg_reg
      check @src.type = 'imm'
      jno invalid_src
      check @src.imm >= 0 & @src.imm < 32
      jno out_range
      compute opcode, basecode1 or (@src.imm shl 4) or @dst.reg
      emit 2, opcode bswap 2
      exit

     reg_reg:
      emit 1, 0FDh
      emit 1, basecode2
      emit 1, (@src.reg shl 4) or @dst.reg
      exit

     out_range:
      err 'Immediate outside range 0..31'
      exit

     invalid_dst:
      err 'Invalid_destination'
      exit

     invalid_src:
      err 'Invalid source'
   end calminstruction
end iterate

iterate <name, basecode1, basecode2>, STZ,0E0h,4Bh, STNZ,0F0h,4Fh
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src
      check @dst.type = 'reg'
      jno invalid_dst
      check @src.type = 'imm'
      jyes reg_imm
      check @src.type = 'reg'
      jno invalid_src
      emit 1, 0FCh
      emit 1, basecode2
      emit 1, (@src.reg shl 4) or @dst.reg
      exit

     reg_imm:
      compute li, @src.imm_size
      emit 2, 70FDh or (li shl 10)
      emit 1, basecode1 or @dst.reg
      check li = 0
      jno emit_imm
      compute li, 4

     emit_imm:
      emit li, @src.imm
      exit

     invalid_dst:
      err 'Invalid destination'
      exit

     invalid_src:
      err 'Invalid source'
   end calminstruction
end iterate

calminstruction PUSH? src*
   call RX.parse_operand@src, src
   check @src.type = 'reg'
   jyes push_reg
   check @src.type = 'mem'
   jno invalid_operand
   compute sz, @src.size - 1
   check sz = 3
   jno not_long
   compute sz, sz - 1

  not_long:
   compute ld, @src.disp_size
   emit 1, 0F4h or ld
   emit 1, 08h or (@src.reg shl 4) or sz
   emit ld, @src.disp
   exit

  push_reg:
   compute sz, @src.size - 1
   check sz = 3
   jno not_default
   compute sz, sz - 1

  not_default:
   emit 1, 7Eh
   emit 1, 80h or (sz shl 4) or @src.reg
   exit

  invalid_operand:
   err 'Invalid operand'
end calminstruction

calminstruction MVTIPL? src*
   call RX.parse_operand@src, src

   check @src.type = 'imm'
   jno invalid_src
   check @src.imm >= 0 & @src.imm <= 15
   jno imm_too_big
   emit 2, 7075h
   emit 1, @src.imm
   exit

  imm_too_big:
   err 'Immediate outside range 0..15'
   exit

  invalid_src:
   err 'Invalid source'
end calminstruction

calminstruction MVFC? dst*, src*
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src

   check @dst.type = 'reg' & @src.type = 'creg'
   jno invalid_operand
   emit 2, 6AFDh
   emit 1, (@src.reg shl 4) or @dst.reg
   exit

  invalid_operand:
   err 'Invalid operand'
end calminstruction

calminstruction MVTC? dst*, src*
   call RX.parse_operand@dst, dst
   call RX.parse_operand@src, src

   check @dst.type = 'creg'
   jno invalid_dst
   check @dst.reg = 1
   jyes invalid_dst
   check @src.type = 'reg'
   jyes reg_reg
   check @src.type = 'imm'
   jno invalid_src
   emit 1, 0FDh
   compute sz, @src.imm_size
   emit 1, 73h or (sz shl 2)
   emit 1, @dst.reg
   check sz = 0
   jno no_adjust
   compute sz, 4

  no_adjust:
   emit sz, @src.imm
   exit

  reg_reg:
   emit 2, 68FDh
   emit 1, (@src.reg shl 4) or @dst.reg
   exit

  invalid_dst:
   err 'Invalid destination'
   exit

  invalid_src:
   err 'Invalid source'
end calminstruction

iterate <name, basecode1, basecode2>, RSTR,0F0h,0D0h, SAVE,0E0h,0C0h
   calminstruction name? src*
      call RX.parse_operand@src, src

      check @src.type = 'reg'
      jyes fmt_reg
      check @src.type = 'imm'
      jno invalid_src
      check @src.imm >= 0 & @src.imm <= 255 ;Processor dependent (usually 16)
      jno imm_too_big
      emit 2, 76FDh
      emit 1, basecode1
      emit 1, @src.imm
      exit

     fmt_reg:
      emit 2, 76FDh
      emit 1, basecode2 or @src.reg
      emit 1, 0
      exit

     imm_too_big:
      err 'Immediate outside range 0..255'
      exit

     invalid_src:
      err 'Invalid source'
   end calminstruction
end iterate

iterate <name, basecode>, EQ,00h, Z,00h, NE,01h, NZ,01h, GEU,02h, C,02h, LTU,03h, GTU,04h, LEU,05h,\
                          PZ,06h, N,07h, GE,08h,LT,09h, GT,0Ah, LE,0Bh, O,0Ch, NO,0Dh

   calminstruction SC#name? dst*
      call RX.parse_operand@dst, dst
      check @dst.type = 'reg' & @dst.size = 4
      jyes fmt_reg
      check @dst.type ='mem'
      jno invalid_dst
      compute sz, @dst.size - 1
      check sz = 3
      jno emit_op

     fmt_reg:
      compute sz, 2

     emit_op:
      compute ld, @dst.disp_size
      emit 1, 0FCh
      emit 1, 0D0h or (sz shl 2) or ld
      emit 1, (@dst.reg shl 4) or basecode
      emit ld, @dst.disp
      exit

     bad_size:
      err 'Incorrect size for register destination'
      exit

     invalid_dst:
      err 'Invalid destination'
   end calminstruction


   calminstruction BM#name? dst*, src*
      local default_dst

      call RX.parse_operand@src, src
      check @src.type = 'imm'
      jno invalid_src
      check @src.imm >= 0 & @src.imm <= 32
      jno imm_too_big

      match =[suffix, dst
      jyes prepend_default_size
      match prefix suffix, dst
      jyes size_exists

     prepend_default_size:
      arrange default_dst, =byte dst
      call RX.parse_operand@dst, default_dst
      jump do_checks

     size_exists:
      call RX.parse_operand@dst, dst

     do_checks:
      check @dst.type = 'mem' & @dst.size = 1
      jyes imm_mem
      check @dst.type ='reg'
      jno invalid_dst
      emit 1, 0FDh
      emit 1, 0E0h or @src.imm
      emit 1, basecode shl 4 or @dst.reg
      exit

     imm_mem:
      check @src.imm < 8
      jno imm_too_big
      compute ld, @dst.disp_size
      emit 1, 0FCh
      emit 1, 0E0h or (@src.imm shl 2) or ld
      emit 1, (@dst.reg shl 4) or basecode
      emit ld, @dst.disp
      exit

     invalid_dst:
      err 'Invalid destination'
      exit

     imm_too_big:
      err 'Immediate outside range 0..31'
      exit

     invalid_src:
      err 'Invalid source'
   end calminstruction

   calminstruction B#name? src*
      local target, prev_size, pred_target, line_num, state_sym, current_size

      call RX.parse_operand@src, src
      check @src.type = 'imm'
      jno invalid_src

      check @src.imm relativeto $
      jno invalid_src

      compute target, @src.imm - $

      compute line_num, __line__
      arrange state_sym, =bcnd_line_#line_num

      compute prev_size, 2
      check defined state_sym
      jno predict
      compute prev_size, state_sym

     predict:
      check basecode <= 1   ;fluff
      jyes cond_eq_ne

     cond_other:
      check target >= -80h & target < 80h
      jyes bcnd_8
      err 'Target of branch outside range'
      exit

     cond_eq_ne:
      check @src.unresolved
      jyes bcnd_16

      compute pred_target, target - prev_size

      check (pred_target+1) >= 3 & (pred_target+1) <= 10
      jyes bcnd_3
      check (pred_target+2) >= -80h & (pred_target+2) < 80h
      jyes bcnd_8
      check (pred_target+3) >= -8000h & (pred_target+3) < 8000h
      jyes bcnd_16
      err 'Target of branch outside range'
      exit

     bcnd_3:
      compute current_size, 1
      publish state_sym, current_size
      emit 1, 10h or (basecode shl 3) or (target and 07h)
      exit

     bcnd_8:
      compute current_size, 2
      publish state_sym, current_size
      emit 1, 20h or basecode
      emit 1, target
      exit

     bcnd_16:
      compute current_size, 3
      publish state_sym, current_size
      emit 1, 3Ah or basecode
      emit 2, target
      exit

     invalid_src:
      err 'Invalid source'
   end calminstruction
end iterate

calminstruction XCHG? dst*, src*
   call RX.parse_operand@dst, dst

   check @dst.type = 'reg'
   jno invalid_dst
   call RX.parse_operand@src, src
   check @src.type = 'reg'
   jyes reg_reg
   check @src.type = 'mem'
   jno invalid_src

   local mx

   check @src.size = 1 & @src.sext = 1
   jyes reg_reg
   compute ld, @src.disp_size
   check @src.sext = 1
   jyes memex_uword
   check @src.size <= 2
   jyes memex_B_W
   compute mx, 2
   jump emit_reg_mem

  memex_B_W:
   compute mx, @src.size - 1
   jump emit_reg_mem

  memex_uword:
   compute mx, 3

  emit_reg_mem:
   emit 1, 06h
   emit 1, 20h or (mx shl 6) or ld
   emit 1, 10h
   emit 1, (@src.reg shl 4) or @dst.reg
   emit ld, @src.disp
   exit

  reg_reg:
   compute ld, @src.disp_size
   emit 1, 0FCh
   emit 1, 40h or ld
   emit 1, (@src.reg shl 4) or @dst.reg
   check ld = 3
   jyes done_reg_reg
   emit ld, @src.disp

  done_reg_reg:
   exit

  invalid_src:
   err 'Invalid source'
   exit

  invalid_dst:
   err 'Invalid destination'
end calminstruction

iterate <name, basecode1, basecode2, basecode3, basecode4>, BSET,00F0h,60FCh,78h,60FCh,\
                                                            BTST,00F4h,68FCh,7Ch,68FCh,\
                                                            BCLR,08F0h,64FCh,7Ah,64FCh
   calminstruction name? dst*, src*
      call RX.parse_operand@src, src
      check @src.type = 'reg' | @src.type = 'imm'
      jno invalid_src

      match =[suffix, dst
      jyes prepend_default_size
      match prefix suffix, dst
      jyes size_exists

     prepend_default_size:
      arrange default_dst, =byte dst
      call RX.parse_operand@dst, default_dst
      jump do_checks

     size_exists:
      call RX.parse_operand@dst, dst

     do_checks:
      check @dst.size = 1 & @dst.type = 'mem'
      jyes mem_dst
      check @dst.type = 'reg'
      jno invalid_dst
      check @src.type = 'imm'
      jyes reg_imm

     reg_reg:
      emit 2, basecode4 or (03h shl 8)
      emit 1, (@dst.reg shl 4) or @src.reg
      exit

     reg_imm:
      check @src.imm >= 0 & @src.imm < 32
      jno imm_bad
      compute immMSB, @src.imm shr 4
      compute opcode, basecode3 or immMSB
      emit 1, opcode
      emit 1, ((@src.imm and 15) shl 4) or @dst.reg
      exit

     mem_dst:
      check @src.type = 'imm'
      jyes mem_imm

     mem_reg:
      compute ld, @dst.disp_size
      emit 2, basecode2 or (ld shl 8)
      emit 1, (@dst.reg shl 4) or @src.reg
      emit ld, @dst.disp
      exit

     mem_imm:
      check @src.imm >= 0 & @src.imm < 8
      jno imm_bad
      compute ld, @dst.disp_size
      emit 2, basecode1 or (@src.imm shl 8) or (@dst.reg shl 12) or ld
      emit ld, @dst.disp
      exit

     imm_bad:
      err 'Immediate outside encodeable range'
      exit

     invalid_src:
      err 'Invalid source'
      exit

     invalid_dst:
      err 'Invalid destination'
   end calminstruction
end iterate

calminstruction BNOT? dst*, src*
   call RX.parse_operand@src, src
   check @src.type = 'reg' | @src.type = 'imm'
   jno invalid_src

   match =[suffix, dst
   jyes prepend_default_size
   match prefix suffix, dst
   jyes size_exists

  prepend_default_size:
   arrange default_dst, =byte dst
   call RX.parse_operand@dst, default_dst
   jump do_checks

  size_exists:
   call RX.parse_operand@dst, dst

  do_checks:
   check @dst.size = 1 & @dst.type = 'mem'
   jyes mem_dst
   check @dst.type = 'reg'
   jno invalid_dst
   check @src.type = 'imm'
   jyes reg_imm
   ;fallthrough

  reg_reg:
   emit 2, 6FFCh
   emit 1, (@dst.reg shl 4) or @src.reg
   exit

  reg_imm:
   check @src.imm >= 0 & @src.imm < 32
   jno imm_bad
   emit 2, 0E0FDh or (@src.imm shl 8)
   emit 1, 0F0h or @dst.reg
   exit

  mem_dst:
   check @src.type = 'imm'
   jyes mem_imm

  mem_reg:
   compute ld, @dst.disp_size
   emit 2, 6CFCh or (ld shl 8)
   emit 1, (@dst.reg shl 4) or @src.reg
   emit ld, @dst.disp
   exit

  mem_imm:
   check @src.imm >= 0 & @src.imm < 8
   jno imm_bad
   compute ld, @dst.disp_size
   emit 1, 0FCh
   emit 1, 0E0h or (@src.imm shl 2) or ld
   emit 1, (@dst.reg shl 4) or 0Fh
   emit ld, @dst.disp
   exit

  imm_bad:
   err 'Immediate outside encodeable range'
   exit

  invalid_src:
   err 'Invalid source'
   exit

  invalid_dst:
   err 'Invalid destination'
end calminstruction

iterate <name, basecode1, basecode2, basecode3>, FADD,20h,88h,0A0h, FMUL,30h,8Ch,0B0h,\
                                                 FSUB,00h,80h,80h
   calminstruction name? dst*, src*, src2
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src
      call RX.parse_operand@src2, src2

      check @dst.type = 'reg'
      jno invalid_dst
      check @src.size = 4
      jno bad_size
      check @src2.type = ''
      jyes two_operand
      check @src2.type = 'reg' & @src.type = 'reg'
      jno invalid_src

     reg_reg_reg:
      emit 1, 0FFh
      emit 1, basecode3 or @dst.reg
      emit 1, (@src.reg shl 4) or @src2.reg
      exit

     two_operand:
      check @src.type = 'reg' | @src.type = 'mem'
      jyes emit_op
      check @src.type = 'imm'
      jno invalid_src

     reg_imm:
      emit 2, 72FDh
      emit 1, basecode1 or @dst.reg
      emit 4, @src.imm
      exit

     emit_op:
      compute ld, @src.disp_size
      emit 1, 0FCh
      emit 1, basecode2 or ld
      emit 1, (@src.reg shl 4) or @dst.reg
      check ld = 3
      jyes done_reg_src
      emit ld, @src.disp

     done_reg_src:
      exit

     bad_size:
      err 'Size must be long'
      exit

     invalid_dst:
      err 'Invalid destination'
      exit

     invalid_src:
      err 'Invalid source'
   end calminstruction
end iterate

iterate <name, basecode>, FSQRT,0A0h, ROUND,98h, FTOI,94h, FTOU,0A4h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg'
      jno invalid_dst
      check @src.type = 'mem' | @src.type = 'reg'
      jno invalid_src

     emit_op:
      compute ld, @src.disp_size
      emit 1, 0FCh
      emit 1, basecode or ld
      emit 1, (@src.reg shl 4) or @dst.reg
      check ld = 3
      jyes done
      emit ld, @src.disp

     done:
      exit

     invalid_dst:
      err 'Invalid destination'
      exit

     invalid_src:
      err 'Invalid source'
   end calminstruction
end iterate

iterate <name, basecode1, basecode2>, FCMP,10h,84h, FDIV,40h,90h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg'
      jno invalid_dst
      check @src.type = 'reg' | @src.type = 'mem'
      jyes reg_src
      check @src.type = 'imm'
      jno invalid_src

     reg_imm:
      emit 2, 72FDh
      emit 1, basecode1 or @dst.reg
      emit 4, @src.imm
      exit

     reg_src:
      compute ld, @src.disp_size
      emit 1, 0FCh
      emit 1, basecode2 or ld
      check ld = 3
      jyes done
      emit ld, @src.disp

     done:
      exit

     invalid_dst:
      err 'Invalid destination'
      exit

     invalid_src:
      err 'Invalid source'
   end calminstruction
end iterate

iterate <name, basecode1, basecode2>, ITOF,44h,11h, UTOF,54h,15h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg'
      jno invalid_dst
      check @src.type = 'reg'
      jyes reg_reg
      check @src.type = 'mem'
      jno invalid_src

      local mx

      check @src.size = 1 & @src.sext = 1
      jyes reg_reg
      compute ld, @src.disp_size
      check @src.sext = 1
      jyes memex_uword
      check @src.size <= 2
      jyes memex_B_W
      compute mx, 2
      jump emit_reg_mem

     memex_B_W:
      compute mx, @src.size - 1
      jump emit_reg_mem

     memex_uword:
      compute mx, 3

     emit_reg_mem:
      emit 1, 06h
      emit 1, 20h or (mx shl 6) or ld
      emit 1, basecode2
      emit 1, (@src.reg shl 4) or @dst.reg
      emit ld, @src.disp
      exit

     reg_reg:
      compute ld, @src.disp_size
      emit 1, 0FCh
      emit 1, basecode1 or ld
      emit 1, (@src.reg shl 4) or @dst.reg
      check ld = 3
      jyes done
      emit ld, @src.disp

     done:
      exit

     invalid_dst:
      err 'Invalid destination'
      exit

     invalid_src:
      err 'Invalid source'
   end calminstruction
end iterate

iterate <name, basecode>, BFMOV,5Eh, BFMOVZ,5Ah
   calminstruction name? dst*, src*, width*, dlsb*, slsb*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg'
      jno invalid_dst
      check @src.type = 'reg'
      jno invalid_src

      call RX.parse_operand@src2, width
      call RX.parse_operand@aux, dlsb
      call RX.parse_operand@aux2, slsb

      check @src2.type = 'imm' & @aux.type = 'imm' & @aux2.type = 'imm'
      jno invalid_arg

      check @src2.imm >= 0 & @aux.imm >= 0 & @aux2.imm >= 0
      jno err_imm
      check @src2.imm < 32 & @aux.imm < 32 & @aux2.imm < 32
      jno err_imm

      compute dlsb_width, (@aux.imm + @src2.imm) and 1Fh
      compute dlsb_slsb, (@aux.imm - @aux2.imm) and 1Fh
      compute val, (dlsb_width shl 10) or (@aux.imm shl 5) or dlsb_slsb

      emit 1, 0FCh
      emit 1, basecode
      emit 1, (@src.reg shl 4) or @dst.reg
      emit 2, val
      exit

     invalid_arg:
      err 'width/dlsb/slsb must be immediate'
      exit

     err_imm:
      err 'Immediate outside range 0..31'
      exit

     invalid_src:
      err 'Invalid source register'
      exit

     invalid_dst:
      err 'Invalid destination'
   end calminstruction
end iterate

calminstruction MOVU? dst*, src*
   local tmp_src, ad

   arrange tmp_src, src
   compute ad, 4
   call RX.parse_operand@dst, dst

   check @dst.type = 'reg'
   jno invalid_dst

   match prefix? =- =[ suffix =], src
   jyes pre_dec
   match prefix? =[ suffix =]=+, src
   jyes post_inc

   match =[ suffix =], src
   jyes reg_mem_prepend
   match prefix suffix, src
   jyes size_exists
   jump reg_mem_prepend

  post_inc:
   compute ad, 2
   match , prefix
   jyes post_pre_prepend
   arrange tmp_src, prefix =[ suffix =]
   jump size_exists

  pre_dec:
   compute ad, 3
   match , prefix
   jyes post_pre_prepend
   arrange tmp_src, prefix =[ suffix =]
   jump size_exists

  post_pre_prepend:
   arrange tmp_src, =word =[ suffix =]
   jump size_exists

  reg_mem_prepend:
   arrange tmp_src, =word tmp_src

  size_exists:
   call RX.parse_operand@src, tmp_src

  parsed_src:
   check @src.size > 2
   jyes invalid_prefix
   check @src.reg_count > 1
   jyes indexed_load
   check ad
   jyes load_w_pre_post

  reg_mem:
   check @src.type = 'mem'
   jno large_reg_mem
   check @src.reg < 8 & @dst.reg < 8 & @src.disp < 32
   jyes small_reg_mem

  large_reg_mem:
   compute sz, @src.size - 1
   compute ld, @src.disp_size
   emit 1, 58h or (sz shl 2) or ld
   emit 1, (@src.reg shl 4) or @dst.reg
   check ld = 3
   jyes emit_done
   emit ld, @src.disp

  emit_done:
   exit

  small_reg_mem: ; 1011sddd drrrdrrr
   compute sz, @src.size - 1
   compute dlsb, @src.disp and 1
   compute d2lsb, @src.disp and 2
   emit 1, 0B0h or (sz shl 3) or (@src.disp shr 2)
   emit 1, (d2lsb shl 6) or (dlsb shl 3) or (@src.reg shl 4) or @dst.reg
   exit

  indexed_load:
   check @src.disp_size = 0
   jno invalid_src
   compute sz, @src.size - 1
   emit 1, 0FEh
   emit 1, 0C0h or (sz shl 4) or @src.reg2
   emit 1, (@src.reg shl 4) or @dst.reg
   exit

  load_w_pre_post:
   check @src.disp_size = 0
   jno invalid_src
   compute sz, @src.size - 1
   emit 1, 0FDh
   emit 1, 30h or (ad shl 2) or sz
   emit 1, (@src.reg shl 4) or @dst.reg
   exit

  invalid_dst:
   err 'Invalid destination'
   exit

  invalid_prefix:
   err 'Invalid prefix. Must be byte/word'
   exit

  invalid_src:
   err 'Invalid source'
end calminstruction

calminstruction MOV? dst*, src*
   local ad, tmp_src, tmp_dst
   compute ad, 4
   arrange tmp_dst, dst
   arrange tmp_src, src

  pre_post_src:
   match prefix? =- =[ suffix =], src
   jyes pre_dec_src
   match prefix? =[ suffix =] =+, src
   jno pre_post_dst

  post_inc_src:
   compute ad, 2
   arrange tmp_src, prefix =[ suffix =]
   jump pre_post_dst

  pre_dec_src:
   compute ad, 3
   arrange tmp_src, prefix =[ suffix =]

  pre_post_dst:
   match prefix? =- =[ suffix =], dst
   jyes pre_dec_dst
   match prefix? =[ suffix =] =+, dst
   jno parse_operands

  post_inc_dst:
   check ad = 4
   jno invalid_pre_post
   compute ad, 0
   arrange tmp_dst, prefix =[ suffix =]
   jump parse_operands

  pre_dec_dst:
   check ad = 4
   jno invalid_pre_post
   compute ad, 1
   arrange tmp_dst, prefix =[ suffix =]

  parse_operands:
   call RX.parse_operand@dst, tmp_dst
   call RX.parse_operand@src, tmp_src
   check @dst.type = 'reg' | @dst.type = 'mem'
   jno invalid_dst

   compute sz, @dst.size
   check @src.size < sz
   jno sz_calculated
   compute sz, @src.size

  sz_calculated:
   compute sz, sz - 1
   check sz = 3
   jno operand_checks
   compute sz, 2

  operand_checks:
   check @dst.type = 'reg'
   jyes fmt_reg_src

  fmt_mem_src:
   compute ld, @dst.disp_size
   check @src.type = 'reg'
   jyes fmt_mem_reg
   check @src.type = 'imm'
   jyes fmt_mem_imm
   check @src.type = 'mem'
   jno invalid_src

  fmt_mem_mem:
   check @dst.size = @src.size
   jno invalid_size
   compute lds, @src.disp_size
   emit 1, 0C0h or (sz shl 4) or (ld shl 2) or lds
   emit 1, (@src.reg shl 4) or @dst.reg
   emit lds, @src.disp
   emit ld, @dst.disp
   exit

  fmt_mem_imm:
   compute li, @src.imm_size
   check (sz > 0 & @src.imm < 0) | @src.imm < -80h | @src.imm > 0FFh | @dst.disp >= 32 | @dst.reg > 7
   jyes fmt_mem_imm_s
   compute dmsb, @dst.disp and 10h
   emit 1, 3Ch or sz
   emit 1, (dmsb shl 3) or (@dst.disp and 0Fh) or (@dst.reg shl 4)
   emit li, @src.imm
   exit

  fmt_mem_imm_s:
   emit 1, 0F8h or ld
   emit 1, (@dst.reg shl 4) or (li shl 2) or sz
   emit ld, @dst.disp
   check li = 0
   jno fin_mem_imm_s
   compute li, 4

  fin_mem_imm_s:
   emit li, @src.imm
   exit

  fmt_mem_reg:
   check @dst.reg_count > 1
   jyes fmt_indexed_store
   check ad < 2
   jyes fmt_pre_post_store
   check @dst.disp < 32 & @src.reg < 8 & @dst.reg < 8
   jyes fmt_mem_reg_small
   compute ld, @dst.disp_size
   emit 1, 0C3h or (sz shl 4) or (ld shl 2)
   emit 1, (@dst.reg shl 4) or @src.reg
   emit ld, @dst.disp
   exit

  fmt_mem_reg_small:
   compute dlsb, @dst.disp and 1
   compute d2lsb, @dst.disp and 2
   emit 1, 80h or (sz shl 4) or (@dst.disp shr 2)
   emit 1, (d2lsb shl 6) or (@dst.reg shl 4) or (dlsb shl 3) or @src.reg
   exit

  fmt_indexed_store:
   emit 1, 0FEh
   emit 1, (sz shl 4) or @dst.reg2
   emit 1, (@dst.reg shl 4) or @src.reg
   exit

  fmt_pre_post_store:
   emit 1, 0FDh
   emit 1, 20h or (ad shl 2) or sz
   emit 1, (@dst.reg shl 4) or @src.reg
   exit

  fmt_reg_src:
   check @src.type = 'reg'
   jyes fmt_reg_reg
   check @src.type = 'imm'
   jyes fmt_reg_imm
   check @src.type = 'mem'
   jyes fmt_reg_mem
   err 'Invalid source'
   exit

  fmt_reg_reg:
   emit 1, 0CFh or (sz shl 4)
   emit 1, (@src.reg shl 4) or @dst.reg
   exit

  fmt_reg_imm:
   compute li, @src.imm_size
   check @src.imm < 0 | @src.imm > 255
   jyes fmt_reg_imm_s
   check @src.imm < 16
   jyes fmt_reg_imm_u4
   check @src.imm < 128 ; see ISA pg.138
   jyes fmt_reg_imm_u8
   check @src.sext = 0 ;???????
   jno fmt_reg_imm_s

  fmt_reg_imm_u8:
   emit 1, 75h
   emit 1, 40h or @dst.reg
   emit 1, @src.imm
   exit

  fmt_reg_imm_u4:
   emit 1, 66h
   emit 1, (@src.imm shl 4) or @dst.reg
   exit

  fmt_reg_imm_s:
   emit 1, 0FBh
   emit 1, 02h or (@dst.reg shl 4) or (li shl 2)
   check li = 0
   jno fin_reg_imm_s
   compute li, 4

  fin_reg_imm_s:
   emit li, @src.imm
   exit

  fmt_reg_mem:
   check @src.reg_count > 1
   jyes fmt_indexed_load
   check ad > 1 & ad < 4
   jyes fmt_pre_post_load
   check @src.disp < 32 & @src.reg < 8 & @dst.reg < 8
   jyes fmt_reg_mem_small
   compute ld, @src.disp_size
   emit 1, 0CCh or (sz shl 4) or ld
   emit 1, (@src.reg shl 4) or @dst.reg
   emit ld, @src.disp
   exit

  fmt_reg_mem_small:
   compute dlsb, @src.disp and 1
   compute d2lsb, @src.disp and 2
   emit 1, 88h or (sz shl 4) or (@src.disp shr 2)
   emit 1, (d2lsb shl 6) or (@src.reg shl 4) or (dlsb shl 3) or @dst.reg
   exit

  fmt_indexed_load:
   emit 1, 0FEh
   emit 1, 40h or (sz shl 4) or @src.reg2
   emit 1, (@src.reg shl 4) or @dst.reg
   exit

  fmt_pre_post_load:
   emit 1, 0FDh
   emit 1, 20h or (ad shl 2) or sz
   emit 1, (@src.reg shl 4) or @dst.reg
   exit

  invalid_dst:
   err 'Invalid destination'
   exit

  invalid_pre_post:
   err 'Invalid_operand'
   exit

  invalid_size:
   err 'Invalid size. Mem-Mem operations require same size for each operand'
   exit

  invalid_src:
   err 'Invalid source'
end calminstruction

calminstruction BSR? src*
   local target

   call RX.parse_operand@src, src
   check @src.type = 'reg'
   jyes bsr_reg
   check @src.type = 'imm'
   jno invalid_src

   compute target, @src.imm - $
   check @src.unresolved
   jyes bsr_16
   check target >= -8000h & target < 8000h
   jyes bsr_16
   check target >= -800000h & target < 800000h
   jyes bsr_24
   err 'Target of branch is too far'
   exit

  bsr_reg:
   emit 1, 7Fh
   emit 1, 50h or @src.reg
   exit

  bsr_16:
   emit 1, 39h
   emit 2, target
   exit

  bsr_24:
   emit 1, 05h
   emit 3, target
   exit

  invalid_src:
    err 'Invalid source'
end calminstruction

calminstruction BRA? src*
   local target, prev_size, pred_target, line_num, state_sym, current_size

   call RX.parse_operand@src, src
   check @src.type = 'reg'
   jyes bra_reg
   check @src.type = 'imm'
   jno invalid_src

   check @src.imm relativeto $
   jno invalid_src

   compute target, @src.imm - $

   compute line_num, __line__
   arrange state_sym, =bra_line_#line_num

   compute prev_size, 2
   check defined state_sym
   jno predict
   compute prev_size, state_sym

  predict:
   check @src.unresolved
   jyes bra_16

   compute pred_target, target - prev_size

   check (pred_target+1) >= 3 & (pred_target+1) <= 10
   jyes bra_3
   check (pred_target+2) >= -80h & (pred_target+2) < 80h
   jyes bra_8
   check (pred_target+3) >= -8000h & (pred_target+3) < 8000h
   jyes bra_16
   check (pred_target+4) >= -800000h & (pred_target+4) < 800000h
   jyes bra_24

   err 'Target of branch outside range'
   exit

  bra_reg:
   emit 1, 7Fh
   emit 1, 40h or @src.reg
   exit

  bra_3:
   compute current_size, 1
   publish state_sym, current_size
   emit 1, 08h or (target and 07h)
   exit

  bra_8:
   compute current_size, 2
   publish state_sym, current_size
   emit 1, 2Eh
   emit 1, target
   exit

  bra_16:
   compute current_size, 3
   publish state_sym, current_size
   emit 1, 38h
   emit 2, target
   exit

  bra_24:
   compute current_size, 4
   publish state_sym, current_size
   emit 1, 04h
   emit 3, target
   exit

  invalid_src:
   err 'Invalid source'
end calminstruction

;=============================================
;Double-Prescision Floating-Point Coprocessor
;=============================================

calminstruction MVFDR?
   emit 3, 1B9075h
   exit
end calminstruction

iterate <name, basecode>, UTOD,0D80h, ITOD,0980h, FTOD,0A80h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'dp' & @src.type = 'reg'
      jyes emit_code
      err 'Invalid operand(s)'
      exit

     emit_code:
      compute opcode, basecode or (@dst.reg shl 12) or @src.reg
      emit 2, 77FDh
      emit 2, opcode
      exit

   end calminstruction
end iterate

iterate <name, basecode>, DTOU,090Dh, DTOI,080Dh, DTOF,0C0Dh, DROUND,0D0Dh, DSQRT,000Dh,\
                          DNEG,020Ch, DABS,010Ch

   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'dp' & @src.type = 'dp'
      jyes emit_code
      err 'Invalid operand(s)'
      exit

     emit_code:
      compute opcode, basecode or (@dst.reg shl 12) or (@src.reg shl 4)
      emit 2, 9076h
      emit 2, opcode
      exit

   end calminstruction
end iterate

iterate <name, basecode>, MVTDC,77h, MVFDC,75h
   calminstruction name? dst*, src*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src

      check @dst.type = 'reg' & @src.type = 'dpc'
      jyes reg_order_a
      check @dst.type = 'dpc' & @src.type = 'reg'
      jyes reg_order_b
      err 'Invalid operand(s)'
      exit

     reg_order_a:
      compute opcode, 0480h or @dst.reg or (@src.reg shl 12)
      jump emit_code

     reg_order_b:
      compute opcode, 0480h or (@dst.reg shl 12) or @src.reg

     emit_code:
      emit 1, 0FDh
      emit 1, basecode
      emit 2, opcode
      exit

   end calminstruction
end iterate

iterate <name, basecode>, UN,01h, EQ,02h, LT,04h, LE,06h
   calminstruction DCMP#name? src2*, src*
      call RX.parse_operand@src2, src2
      call RX.parse_operand@src, src

      check @src2.type = 'dp' & @src.type = 'dp'
      jyes emit_code
      err 'Invalid operand(s)'
      exit

     emit_code:
      emit 2, 9076h
      emit 1, 01h or (@src2.reg shl 4)
      emit 1, (basecode shl 4) or @src.reg
      exit

   end calminstruction
end iterate

iterate <name, basecode>, DADD,00h, DSUB,01h, DMUL,02h, DDIV,05h
   calminstruction name? dst*, src*, src2
      call RX.parse_operand@dst, dst
      call RX.parse_operand@src, src
      call RX.parse_operand@src2, src2

      check @dst.type = 'dp' & @src.type = 'dp' & @src2.type = 'dp'
      jyes emit_code
      err 'Invalid operand(s)'
      exit

     emit_code:
      emit 2, 9076h
      emit 1, basecode or (@src2.reg shl 4)
      emit 1, @src.reg or (@dst.reg shl 4)
      exit

   end calminstruction
end iterate

iterate <name, basecode>, DPUSHM,00h, DPOPM,08h
   calminstruction name? dst*, aux*
      call RX.parse_operand@dst, dst
      call RX.parse_operand@aux, aux

      check @dst.type = 'dp' & @aux.type = 'dp'
      jyes emit_code_reg
      check @dst.type = 'dpc' & @aux.type = 'dpc'
      jyes emit_code_ctrl
      err 'Invalid operand(s)'
      exit

     emit_code_reg:
      check @aux.reg >= @dst.reg
      jno bad_reg_order
      compute nm, @aux.reg - @dst.reg
      emit 1, 75h
      emit 1, 0B0h or basecode
      emit 1, (@dst.reg shl 4) or nm
      exit

     emit_code_ctrl:
      compute nm, @aux.reg - @dst.reg
      emit 1, 75h
      emit 1, 0A0h or basecode
      emit 1, (@dst.reg shl 4) or nm
      exit

     bad_reg_order:
      err ''
      exit
   end calminstruction
end iterate

calminstruction DMOV? dst*, src*
   local tmp_src, tmp_dst

   arrange tmp_src, src
   arrange tmp_dst, dst

   match =[suffix, src
   jyes prepend_src
   match prefix suffix, src
   jyes sz_exists_src

  prepend_src:
   arrange tmp_src, =double src

  sz_exists_src:
   match =[suffix, dst
   jyes prepend_dst
   match prefix suffix, dst
   jyes sz_exists_both

  prepend_dst:
   arrange tmp_dst, =double dst

  sz_exists_both:
   call RX.parse_operand@src, tmp_src
   call RX.parse_operand@dst, tmp_dst


   check @src.size = 4 & @dst.size = 4
   jno invalid_size
   check @src.sext = 1 & @dst.sext = 1
   jyes sz_d
   check @src.type = 'reg'
   jyes dpx_reg_l
   check @src.type = 'dph'| @src.type = 'dpl'
   jyes reg_dpx_l
   check @src.type = 'imm'
   jno invalid_src
   jump dpx_imm_l

  sz_d:
   check @src.type = 'reg'
   jyes dpx_reg_d
   check @src.type = 'dp'
   jyes x_dp_d
   check @src.type = 'imm'
   jyes dpx_imm_d
   check @src.type = 'mem'
   jyes dp_mem_d
   jump invalid_src

  x_dp_d:
   check @dst.type = 'mem'
   jyes mem_dp_d
   check @dst.type = 'dp'
   jno invalid_dst
   emit 2, 9076h
   emit 1, (@src.reg shl 4) or 0Ch
   emit 1, (@dst.reg shl 4)
   exit

  dp_mem_d:
   check @dst.type = 'dp'
   jno invalid_dst
   compute ld, @src.disp_size
   emit 2, 0C8FCh or (ld shl 8)
   emit 1, 08h or (@src.reg shl 4)
   emit ld, @src.disp
   emit 1, (@dst.reg shl 4)
   exit

  mem_dp_d:
   compute ld, @dst.disp_size
   emit 2, 78FCh or (ld shl 8)
   emit 1, @dst.reg shl 4 or 08h
   emit ld, @dst.disp
   emit 1, (@src.reg shl 4)
   exit

  reg_dpx_l:
   check @dst.type = 'reg'
   jno invalid_dst
   check @src.type = 'dph'
   jyes reg_dph_l
   compute opcode, 00h
   jump emit_reg_dpx

  reg_dph_l:
   compute opcode, 02h

  emit_reg_dpx:
   emit 2, 75FDh
   emit 1, 80h or @dst.reg
   emit 1, opcode or (@src.reg shl 4)
   exit

  dpx_reg_d:
   check @dst.type = 'dph'
   jno invalid_dst
   compute opcode, 03h
   jump emit_dpx_reg

  dpx_reg_l:
   check @dst.type = 'dph'
   jyes dph_reg_l
   check @dst.type = 'dpl'
   jno invalid_dst
   compute opcode, 00h
   jump emit_dpx_reg

  dph_reg_l:
   compute opcode, 02h

  emit_dpx_reg:
   emit 2, 77FDh
   emit 1, 80h or @src.reg
   emit 1, opcode or (@dst.reg shl 4)
   exit

  dpx_imm_d:
   check @dst.type = 'dph'
   jno invalid_dst
   compute opcode, 03h
   jump emit_dpx_imm

  dpx_imm_l:
   check @dst.type = 'dph'
   jyes dph_imm_l
   check @dst.type = 'dpl'
   jno invalid_dst
   compute opcode, 00h
   jump emit_dpx_imm

  dph_imm_l:
   compute opcode, 02h

  emit_dpx_imm:
   emit 2, 03F9h
   emit 1, (@dst.reg shl 4) or opcode
   emit 4, @src.imm
   exit

  invalid_size:
   err 'Invalid size modifier(s)'
   exit

  invalid_dst:
   err 'Invalid destination'
   exit

  invalid_src:
   err 'Invalid source'
   exit
end calminstruction

btst R1, 16