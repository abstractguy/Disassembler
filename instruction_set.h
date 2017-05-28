// instruction_set.h
 
#ifndef INSTRUCTION_SET_H
  #define INSTRUCTION_SET_H
 
  typedef enum {
    NOP, AJMP_addr11, LJMP_addr16,
    RR_A, INC_A, INC_direct,
    INC_at_R0, INC_at_R1, INC_R0,
    INC_R1, INC_R2, INC_R3, INC_R4,
    INC_R5, INC_R6, INC_R7,
    JBC_bit_offset, ACALL_addr11,
    LCALL_addr16, RRC_A, DEC_A,
    DEC_direct, DEC_at_R0,
    DEC_at_R1, DEC_R0, DEC_R1,
    DEC_R2, DEC_R3, DEC_R4,
    DEC_R5, DEC_R6, DEC_R7,
    JB_bit_offset, AJMP_addr11,
    RET, RL_A, ADD_A_immed,
    ADD_A_direct, ADD_A_at_R0,
    ADD_A_at_R1, ADD_A_R0,
    ADD_A_R1, ADD_A_R2,
    ADD_A_R3, ADD_A_R4,
    ADD_A_R5, ADD_A_R6,
    ADD_A_R7, JNB_bit_offset,
    ACALL_addr11, RETI, RLC_A,
    ADDC_A_immed, ADDC_A_direct,
    ADDC_A_at_R0, ADDC_A_at_R1,
    ADDC_A_R0, ADDC_A_R1,
    ADDC_A_R2, ADDC_A_R3,
    ADDC_A_R4, ADDC_A_R5,
    ADDC_A_R6, ADDC_A_R7,
    JC_offset, AJMP_addr11,
    ORL_direct_A, ORL_direct_immed,
    ORL_A_immed, ORL_A_direct,
    ORL_A_at_R0, ORL_A_at_R1,
    ORL_A_R0, ORL_A_R1,
    ORL_A_R2, ORL_A_R3,
    ORL_A_R4, ORL_A_R5,
    ORL_A_R6, ORL_A_R7,
    JNC_offset, ACALL_addr11,
    ANL_direct_A, ANL_direct_immed,
    ANL_A_immed, ANL_A_direct,
    ANL_A_at_R0, ANL_A_at_R1,
    ANL_A_R0, ANL_A_R1,
    ANL_A_R2, ANL_A_R3,
    ANL_A_R4, ANL_A_R5,
    ANL_A_R6, ANL_A_R7,
    JZ_offset, AJMP_addr11,
    XRL_direct_A, XRL_direct_immed,
    XRL_A_immed, XRL_A_direct,
    XRL_A_at_R0, XRL_A_at_R1,
    XRL_A_R0, XRL_A_R1, XRL_A_R2,
    XRL_A_R3, XRL_A_R4, XRL_A_R5,
    XRL_A_R6, XRL_A_R7, JNZ_offset,
    ACALL_addr11, ORL_C_bit,
    JMP_at_A_plus_DPTR,
    MOV_A_immed,
    MOV_direct_immed,
    MOV_at_R0_immed,
    MOV_at_R1_immed,
    MOV_R0_immed, MOV_R1_immed,
    MOV_R2_immed, MOV_R3_immed,
    MOV_R4_immed, MOV_R5_immed,
    MOV_R6_immed, MOV_R7_immed,
    SJMP_offset, AJMP_addr11,
    ANL_C_bit,
    MOVC_A_at_A_plus_PC,
    DIV_A_B, MOV_direct_direct,
    MOV_direct_at_R0,
    MOV_direct_at_R1, MOV_direct_R0,
    MOV_direct_R1, MOV_direct_R2,
    MOV_direct_R3, MOV_direct_R4,
    MOV_direct_R5, MOV_direct_R6,
    MOV_direct_R7,
    MOV_DPTR_immed,
    ACALL_addr11, MOV_bit_C,
    MOVC_A_at_A_plus_DPTR,
    SUBB_A_immed, SUBB_A_direct,
    SUBB_A_at_R0, SUBB_A_at_R1,
    SUBB_A_R0, SUBB_A_R1,
    SUBB_A_R2, SUBB_A_R3,
    SUBB_A_R4, SUBB_A_R5,
    SUBB_A_R6, SUBB_A_R7,
    ORL_C_not_bit, AJMP_addr11,
    MOV_C_bit, INC_DPTR, MUL_A_B,
    RESERVED, MOV_at_R0_direct,
    MOV_at_R1_direct, MOV_R0_direct,
    MOV_R1_direct, MOV_R2_direct,
    MOV_R3_direct, MOV_R4_direct,
    MOV_R5_direct, MOV_R6_direct,
    MOV_R7_direct, ANL_C_not_bit,
    ACALL_addr11, CPL_bit, CPL_C,
    CJNE_A_immed_offset,
    CJNE_A_direct_offset,
    CJNE_at_R0_immed_offset,
    CJNE_at_R1_immed_offset,
    CJNE_R0_immed_offset,
    CJNE_R1_immed_offset,
    CJNE_R2_immed_offset,
    CJNE_R3_immed_offset,
    CJNE_R4_immed_offset,
    CJNE_R5_immed_offset,
    CJNE_R6_immed_offset,
    CJNE_R7_immed_offset,
    PUSH_direct, AJMP_addr11,
    CLR_bit, CLR_C, SWAP_A,
    XCH_A_direct, XCH_A_at_R0,
    XCH_A_at_R1, XCH_A_R0,
    XCH_A_R1, XCH_A_R2,
    XCH_A_R3, XCH_A_R4,
    XCH_A_R5, XCH_A_R6,
    XCH_A_R7, POP_direct,
    ACALL_addr11, SETB_bit,
    SETB_C, DA_A, DNJZ_R0_offset,
    DNJZ_R1_offset, DNJZ_R2_offset,
    DNJZ_R3_offset, DNJZ_R4_offset,
    DNJZ_R5_offset, DNJZ_R6_offset,
    DNJZ_R7_offset,
    MOVX_A_at_DPTR, AJMP_addr11,
    MOVX_A_at_R0, MOVX_A_at_R1,
    CLR_A, MOV_A_direct,
    MOV_A_at_R0, MOV_A_at_R1,
    MOV_A_R0, MOV_A_R1,
    MOV_A_R2, MOV_A_R3,
    MOV_A_R4, MOV_A_R5,
    MOV_A_R6, MOV_A_R7,
    MOVX_at_DPTR_A, ACALL_addr11,
    MOVX_at_R0_A, MOVX_at_R1_A,
    CPL_A, MOV_direct_A,
    MOV_at_R0_A, MOV_at_R1_A,
    MOV_R0_A, MOV_R1_A,
    MOV_R1_A, MOV_R2_A,
    MOV_R3_A, MOV_R4_A,
    MOV_R5_A, MOV_R6_A,
    MOV_R7_A
  } bytecode;
 
  typedef struct {
    bytecode bytecode;
    unsigned short int address;
    unsigned char bytes, *arguments;
    char *mnemonic;
  } instruction;
#endif
 
 
 
instruction decode(unsigned char opcode) {
  if ((opcode & 0x1F) == 0x11) {
    switch (opcode >> 5) {
      case 0: return ACALL_addr11_0;
      case 1: return ACALL_addr11_1;
      case 2: return ACALL_addr11_2;
      case 3: return ACALL_addr11_3;
      case 4: return ACALL_addr11_4;
      case 5: return ACALL_addr11_5;
      case 6: return ACALL_addr11_6;
      case 7: return ACALL_addr11_7;
    }
  } else if ((opcode & 0xF8) == 0x28) {
    switch (opcode & 0x07) {
      case 0: return ADD_A_R0;
      case 1: return ADD_A_R1;
      case 2: return ADD_A_R2;
      case 3: return ADD_A_R3;
      case 4: return ADD_A_R4;
      case 5: return ADD_A_R5;
      case 6: return ADD_A_R6;
      case 7: return ADD_A_R7;
    }
  } else if ((opcode & 0xFC) == 0x24) {
    switch (opcode & 0x03) {
      case 0: return ADD_A_immed;
      case 1: return ADD_A_direct;
      case 2: return ADD_A_at_R0;
      case 3: return ADD_A_at_R1;
    }
  } else if ((opcode & 0xF8) == 0x38) {
    switch (opcode & 0x07) {
      case 0: return ADDC_A_R0;
      case 1: return ADDC_A_R1;
      case 2: return ADDC_A_R2;
      case 3: return ADDC_A_R3;
      case 4: return ADDC_A_R4;
      case 5: return ADDC_A_R5;
      case 6: return ADDC_A_R6;
      case 7: return ADDC_A_R7;
    }
  } else if ((opcode & 0xFC) == 0x34) {
    switch (opcode & 0x03) {
      case 0: return ADDC_A_immed;
      case 1: return ADDC_A_direct;
      case 2: return ADDC_A_at_R0;
      case 3: return ADDC_A_at_R1;
    }
  } else if ((opcode & 0x1F) == 0x01) {
    switch (opcode >> 5) {
      case 0: return AJMP_addr11_0;
      case 1: return AJMP_addr11_1;
      case 2: return AJMP_addr11_2;
      case 3: return AJMP_addr11_3;
      case 4: return AJMP_addr11_4;
      case 5: return AJMP_addr11_5;
      case 6: return AJMP_addr11_6;
      case 7: return AJMP_addr11_7;
    }
  } else if ((opcode & 0xF8) == 0x58) {
    switch (opcode & 0x07) {
      case 0: return ANL_A_R0;
      case 1: return ANL_A_R1;
      case 2: return ANL_A_R2;
      case 3: return ANL_A_R3;
      case 4: return ANL_A_R4;
      case 5: return ANL_A_R5;
      case 6: return ANL_A_R6;
      case 7: return ANL_A_R7;
    }
  } else if ((opcode & 0xFC) == 0x54) {
    switch (opcode & 0x03) {
      case 0: return ANL_A_immed;
      case 1: return ANL_A_direct;
      case 0: return ANL_A_at_R0;
      case 0: return ANL_A_at_R1;
    }
  } else if ((opcode & 0x
    
  }
}
 
 
 
 
 
 
unsigned char operands(unsigned char opcode) {
  assert(opcode != 0xA5);
  switch (opcode) {
    case 0x02:
    case 0x10:
    case 0x12:
    case 0x20:
    case 0x30:
    case 0x43:
    case 0x53:
    case 0x63:
    case 0x75:
    case 0x85:
    case 0x90:
    case 0xB4:
    case 0xD5: return 2;
    case 0x00:
    case 0x04:
    case 0x14:
    case 0x22:
    case 0x32:
    case 0x73:
    case 0x83:
    case 0x84:
    case 0xA3:
    case 0xA4:
    case 0xC4:
    case 0xD3
    case 0xD4:
    case 0xD6:
    case 0xD7:
    case 0xE0:
    case 0xE2:
    case 0xE4:
    case 0xF0:
    case 0xF2:
    case 0xF4: return 0;
    default:
      if ((opcode > 0xB3) && (opcode < 0xC0)) return 2;
      else switch (opcode & 0x0F) {
        case 0x00:
        case 0x01:
        case 0x02:
        case 0x04:
        case 0x05: return 1;
        case 0x03: return 0;
        default:
          switch (opcode & 0xF0) {
            case 0x60:
            case 0x70:
            case 0xA0:
            case 0xD0: return 1;
            default: return 0;
          }
      }
  }
}

