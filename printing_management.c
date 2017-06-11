// printing_management.c
#include "printing_management.h"

  static char *instructions[256] = {
    "NOP\n",
    "AJMP\t0x%4.4X\n",
    "LJMP\t0x%4.4X\n",
    "RR\t\tA\n",
    "INC\t\tA\n",
    "INC\t\t0x%X2.2\n",
    "INC\t\t@R0\n",
    "INC\t\t@R1\n",
    "INC\t\tR0\n",
    "INC\t\tR1\n",
    "INC\t\tR2\n",
    "INC\t\tR3\n",
    "INC\t\tR4\n",
    "INC\t\tR5\n",
    "INC\t\tR6\n",
    "INC\t\tR7\n",
    "JBC\t\t0x%2.2X,\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "LCALL\t0x%4.4X\n",
    "RRC\t\tA\n",
    "DEC\t\tA\n",
    "DEC\t\t0x%2.2X\n",
    "DEC\t\t@R0\n",
    "DEC\t\t@R1\n",
    "DEC\t\tR0\n",
    "DEC\t\tR1\n",
    "DEC\t\tR2\n",
    "DEC\t\tR3\n",
    "DEC\t\tR4\n",
    "DEC\t\tR5\n",
    "DEC\t\tR6\n",
    "DEC\t\tR7\n",
    "JB\t\t0x%2.2X,\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "RET\n\n",
    "RL\t\tA\n",
    "ADD\t\tA,\t0x%2.2X\n",
    "ADD\t\tA,\t0x%2.2X\n",
    "ADD\t\tA,\t@R0\n",
    "ADD\t\tA,\t@R1\n",
    "ADD\t\tA,\tR0\n",
    "ADD\t\tA,\tR1\n",
    "ADD\t\tA,\tR2\n",
    "ADD\t\tA,\tR3\n",
    "ADD\t\tA,\tR4\n",
    "ADD\t\tA,\tR5\n",
    "ADD\t\tA,\tR6\n",
    "ADD\t\tA,\tR7\n",
    "JNB\t\t0x%2.2X,\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "RETI\n\n",
    "RLC\t\tA\n",
    "ADDC\tA,\t0x%2.2X\n",
    "ADDC\tA,\t0x%2.2X\n",
    "ADDC\tA,\t@R0\n",
    "ADDC\tA,\t@R1\n",
    "ADDC\tA,\tR0\n",
    "ADDC\tA,\tR1\n",
    "ADDC\tA,\tR2\n",
    "ADDC\tA,\tR3\n",
    "ADDC\tA,\tR4\n",
    "ADDC\tA,\tR5\n",
    "ADDC\tA,\tR6\n",
    "ADDC\tA,\tR7\n",
    "JC\t\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "ORL\t\t0x%2.2X,\tA\n",
    "ORL\t\t0x%2.2X,\t0x%2.2X\n",
    "ORL\t\tA,\t0x%2.2X\n",
    "ORL\t\tA,\t0x%2.2X\n",
    "ORL\t\tA,\t@R0\n",
    "ORL\t\tA,\t@R1\n",
    "ORL\t\tA,\tR0\n",
    "ORL\t\tA,\tR1\n",
    "ORL\t\tA,\tR2\n",
    "ORL\t\tA,\tR3\n",
    "ORL\t\tA,\tR4\n",
    "ORL\t\tA,\tR5\n",
    "ORL\t\tA,\tR6\n",
    "ORL\t\tA,\tR7\n",
    "JNC\t\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "ANL\t\t0x%2.2X,\tA\n",
    "ANL\t\t0x%2.2X,\t0x%2.2X\n",
    "ANL\t\tA,\t0x%2.2X\n",
    "ANL\t\tA,\t0x%2.2X\n",
    "ANL\t\tA,\t@R0\n",
    "ANL\t\tA,\t@R1\n",
    "ANL\t\tA,\tR0\n",
    "ANL\t\tA,\tR1\n",
    "ANL\t\tA,\tR2\n",
    "ANL\t\tA,\tR3\n",
    "ANL\t\tA,\tR4\n",
    "ANL\t\tA,\tR5\n",
    "ANL\t\tA,\tR6\n",
    "ANL\t\tA,\tR7\n",
    "JZ\t\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "XRL\t\t0x%2.2X,\tA\n",
    "XRL\t\t0x%2.2X,\t0x%2.2X\n",
    "XRL\t\tA,\t0x%2.2X\n",
    "XRL\t\tA,\t0x%2.2X\n",
    "XRL\t\tA,\t@R0\n",
    "XRL\t\tA,\t@R1\n",
    "XRL\t\tA,\tR0\n",
    "XRL\t\tA,\tR1\n",
    "XRL\t\tA,\tR2\n",
    "XRL\t\tA,\tR3\n",
    "XRL\t\tA,\tR4\n",
    "XRL\t\tA,\tR5\n",
    "XRL\t\tA,\tR6\n",
    "XRL\t\tA,\tR7\n",
    "JNZ\t\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "ORL\t\tC,\t0x%2.2X\n",
    "JMP\t\t@A+DPTR\n",
    "MOV\t\tA,\t0x%2.2X\n",
    "MOV\t\t0x%2.2X,\t0x%2.2X\n",
    "MOV\t\t@R0,\t0x%2.2X\n",
    "MOV\t\t@R1,\t0x%2.2X\n",
    "MOV\t\tR0,\t0x%2.2X\n",
    "MOV\t\tR1,\t0x%2.2X\n",
    "MOV\t\tR2,\t0x%2.2X\n",
    "MOV\t\tR3,\t0x%2.2X\n",
    "MOV\t\tR4,\t0x%2.2X\n",
    "MOV\t\tR5,\t0x%2.2X\n",
    "MOV\t\tR6,\t0x%2.2X\n",
    "MOV\t\tR7,\t0x%2.2X\n",
    "SJMP\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "ANL\t\tC,\t0x%2.2X\n",
    "MOVC\tA,\t@A+PC\n",
    "DIV\t\tA,\tB\n",
    "MOV\t\t0x%2.2X,\t0x%2.2X\n",
    "MOV\t\t0x%2.2X,\t@R0\n",
    "MOV\t\t0x%2.2X,\t@R1\n",
    "MOV\t\t0x%2.2X,\tR0\n",
    "MOV\t\t0x%2.2X,\tR1\n",
    "MOV\t\t0x%2.2X,\tR2\n",
    "MOV\t\t0x%2.2X,\tR3\n",
    "MOV\t\t0x%2.2X,\tR4\n",
    "MOV\t\t0x%2.2X,\tR5\n",
    "MOV\t\t0x%2.2X,\tR6\n",
    "MOV\t\t0x%2.2X,\tR7\n",
    "MOV\t\tDPTR,\t0x%4.4X\n",
    "ACALL\t0x%4.4X\n",
    "MOV\t\t0x%2.2X,\tC\n",
    "MOVC\tA,\t@A+DPTR\n",
    "SUBB\tA,\t0x%2.2X\n",
    "SUBB\tA,\t0x%2.2X\n",
    "SUBB\tA,\t@R0\n",
    "SUBB\tA,\t@R1\n",
    "SUBB\tA,\tR0\n",
    "SUBB\tA,\tR1\n",
    "SUBB\tA,\tR2\n",
    "SUBB\tA,\tR3\n",
    "SUBB\tA,\tR4\n",
    "SUBB\tA,\tR5\n",
    "SUBB\tA,\tR6\n",
    "SUBB\tA,\tR7\n",
    "ORL\t\tC,\t/0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "MOV\t\tC,\t0x%2.2X\n",
    "INC\t\tDPTR\n",
    "MUL\t\tA,\tB\n",
    "RESERVED\n",
    "MOV\t\t@R0,\t0x%2.2X\n",
    "MOV\t\t@R1,\t0x%2.2X\n",
    "MOV\t\tR0,\t0x%2.2X\n",
    "MOV\t\tR1,\t0x%2.2X\n",
    "MOV\t\tR2,\t0x%2.2X\n",
    "MOV\t\tR3,\t0x%2.2X\n",
    "MOV\t\tR4,\t0x%2.2X\n",
    "MOV\t\tR5,\t0x%2.2X\n",
    "MOV\t\tR6,\t0x%2.2X\n",
    "MOV\t\tR7,\t0x%2.2X\n",
    "ANL\t\tC,\t/0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "CPL\t\t0x%2.2X\n",
    "CPL\t\tC\n",
    "CJNE\tA,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE\tA,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE\t@R0,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE\t@R1,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R0,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R1,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R2,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R3,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R4,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R5,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R6,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R7,\t0x%2.2X,\t0x%2.2X\n",
    "PUSH\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "CLR\t\t0x%2.2X\n",
    "CLR\t\tC\n",
    "SWAP\tA\n",
    "XCH\t\tA,\t0x%2.2X\n",
    "XCH\t\tA,\t@R0\n",
    "XCH\t\tA,\t@R1\n",
    "XCH\t\tA,\tR0\n",
    "XCH\t\tA,\tR1\n",
    "XCH\t\tA,\tR2\n",
    "XCH\t\tA,\tR3\n",
    "XCH\t\tA,\tR4\n",
    "XCH\t\tA,\tR5\n",
    "XCH\t\tA,\tR6\n",
    "XCH\t\tA,\tR7\n",
    "POP\t\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "SETB\t0x%2.2X\n",
    "SETB\tC\n",
    "DA\t\tA\n",
    "DJNZ\t0x%2.2X,\t0x%2.2X\n",
    "XCHD\tA,\t@R0\n",
    "XCHD\tA,\t@R1\n",
    "DJNZ\tR0,\t0x%2.2X\n",
    "DJNZ\tR1,\t0x%2.2X\n",
    "DJNZ\tR2,\t0x%2.2X\n",
    "DJNZ\tR3,\t0x%2.2X\n",
    "DJNZ\tR4,\t0x%2.2X\n",
    "DJNZ\tR5,\t0x%2.2X\n",
    "DJNZ\tR6,\t0x%2.2X\n",
    "DJNZ\tR7,\t0x%2.2X\n",
    "MOVX\tA,\t@DPTR\n",
    "AJMP\t0x%4.4X\n",
    "MOVX\tA,\t@R0\n",
    "MOVX\tA,\t@R1\n",
    "CLR\t\tA\n",
    "MOV\t\tA,\t0x%2.2X\n",
    "MOV\t\tA,\t@R0\n",
    "MOV\t\tA,\t@R1\n",
    "MOV\t\tA,\tR0\n",
    "MOV\t\tA,\tR1\n",
    "MOV\t\tA,\tR2\n",
    "MOV\t\tA,\tR3\n",
    "MOV\t\tA,\tR4\n",
    "MOV\t\tA,\tR5\n",
    "MOV\t\tA,\tR6\n",
    "MOV\t\tA,\tR7\n",
    "MOVX\t@DPTR,\tA\n",
    "ACALL\t0x%4.4X\n",
    "MOVX\t@R0,\tA\n",
    "MOVX\t@R1,\tA\n",
    "CPL\t\tA\n",
    "MOV\t\t0x%2.2X,\tA\n",
    "MOV\t\t@R0,\tA\n",
    "MOV\t\t@R1,\tA\n",
    "MOV\t\tR0,\tA\n",
    "MOV\t\tR1,\tA\n",
    "MOV\t\tR2,\tA\n",
    "MOV\t\tR3,\tA\n",
    "MOV\t\tR4,\tA\n",
    "MOV\t\tR5,\tA\n",
    "MOV\t\tR6,\tA\n",
    "MOV\t\tR7,\tA\n"
 };

// BYTE Registers
char *direct_to_string(unsigned char direct_byte) {
  char *direct_string = NULL;
  switch (direct_byte) {
    case 0x80: sprintf(direct_string, "P0"); break;
    case 0x81: sprintf(direct_string, "SP"); break;
    case 0x82: sprintf(direct_string, "DPL"); break;
    case 0x83: sprintf(direct_string, "DPH"); break;
    case 0x84: sprintf(direct_string, "DPL1"); break;
    case 0x85: sprintf(direct_string, "DPH1"); break;
    case 0x86: sprintf(direct_string, "DPS"); break;
    case 0x87: sprintf(direct_string, "PCON"); break;
    case 0x88: sprintf(direct_string, "TCON"); break;
    case 0x89: sprintf(direct_string, "TMOD"); break;
    case 0x8A: sprintf(direct_string, "TL0"); break;
    case 0x8B: sprintf(direct_string, "TL1"); break;
    case 0x8C: sprintf(direct_string, "TH0"); break;
    case 0x8D: sprintf(direct_string, "TH1"); break;
    case 0x8E: sprintf(direct_string, "CKCON"); break;
    case 0x90: sprintf(direct_string, "P1"); break;
    case 0x91: sprintf(direct_string, "EXIF"); break;
    case 0x96: sprintf(direct_string, "CKMOD"); break;
    case 0x98: sprintf(direct_string, "SCON0"); break;
    case 0x99: sprintf(direct_string, "SBUF0"); break;
    case 0x9D: sprintf(direct_string, "ACON"); break;
    case 0xA0: sprintf(direct_string, "P2"); break;
    case 0xA8: sprintf(direct_string, "IE"); break;
    case 0xA9: sprintf(direct_string, "SADDR0"); break;
    case 0xAA: sprintf(direct_string, "SADDR1"); break;
    case 0xB0: sprintf(direct_string, "P3"); break;
    case 0xB1: sprintf(direct_string, "IP1"); break;
    case 0xB8: sprintf(direct_string, "IP0"); break;
    case 0xB9: sprintf(direct_string, "SADEN0"); break;
    case 0xBA: sprintf(direct_string, "SADEN1"); break;
    case 0xC0: sprintf(direct_string, "SCON1"); break;
    case 0xC1: sprintf(direct_string, "SBUF1"); break;
    case 0xC2: sprintf(direct_string, "ROMSIZE"); break;
    case 0xC4: sprintf(direct_string, "PMR"); break;
    case 0xC5: sprintf(direct_string, "STATUS"); break;
    case 0xC7: sprintf(direct_string, "TA"); break;
    case 0xC8: sprintf(direct_string, "T2CON"); break;
    case 0xC9: sprintf(direct_string, "T2MOD"); break;
    case 0xCA: sprintf(direct_string, "RCAP2L"); break;
    case 0xCB: sprintf(direct_string, "RCAP2H"); break;
    case 0xCC: sprintf(direct_string, "TL2"); break;
    case 0xCD: sprintf(direct_string, "TH2"); break;
    case 0xD0: sprintf(direct_string, "PSW"); break;
    case 0xD5: sprintf(direct_string, "FCNTL"); break;
    case 0xD6: sprintf(direct_string, "FDATA"); break;
    case 0xD8: sprintf(direct_string, "WDCON"); break;
    case 0xE0: sprintf(direct_string, "A"); break;
    case 0xE8: sprintf(direct_string, "EIE"); break;
    case 0xF0: sprintf(direct_string, "B"); break;
    case 0xF1: sprintf(direct_string, "EIP1"); break;
    case 0xF8: sprintf(direct_string, "EIP0"); break;
    default:   sprintf(direct_string, "0x%2.2X", direct_byte);
  } return direct_string;
}

/*
// BIT Registers

// P0
sbit at 0x80 P0_0;
sbit at 0x81 P0_1;
sbit at 0x82 P0_2;
sbit at 0x83 P0_3;
sbit at 0x84 P0_4;
sbit at 0x85 P0_5;
sbit at 0x86 P0_6;
sbit at 0x87 P0_7;

// TCON
sbit at 0x88 IT0;
sbit at 0x89 IE0;
sbit at 0x8A IT1;
sbit at 0x8B IE1;
sbit at 0x8C TR0;
sbit at 0x8D TF0;
sbit at 0x8E TR1;
sbit at 0x8F TF1;

// P1
sbit at 0x90 P1_0;
sbit at 0x91 P1_1;
sbit at 0x92 P1_2;
sbit at 0x93 P1_3;
sbit at 0x94 P1_4;
sbit at 0x95 P1_5;
sbit at 0x96 P1_6;
sbit at 0x97 P1_7;

// SCON0
sbit at 0x98 RI_0;
sbit at 0x99 TI_0;
sbit at 0x9A RB8_0;
sbit at 0x9B TB8_0;
sbit at 0x9C REN_0;
sbit at 0x9D SM2_0;
sbit at 0x9E SM1_0;
sbit at 0x9F SM0_0;
sbit at 0x9F FE_0;

// P2
sbit at 0xA0 P2_0;
sbit at 0xA1 P2_1;
sbit at 0xA2 P2_2;
sbit at 0xA3 P2_3;
sbit at 0xA4 P2_4;
sbit at 0xA5 P2_5;
sbit at 0xA6 P2_6;
sbit at 0xA7 P2_7;

// IE
sbit at 0xA8 EX0;
sbit at 0xA9 ET0;
sbit at 0xAA EX1;
sbit at 0xAB ET1;
sbit at 0xAC ES0;
sbit at 0xAD ET2;
sbit at 0xAE ES1;
sbit at 0xAF EA;

// P3
sbit at 0xB0 P3_0;
sbit at 0xB1 P3_1;
sbit at 0xB2 P3_2;
sbit at 0xB3 P3_3;
sbit at 0xB4 P3_4;
sbit at 0xB5 P3_5;
sbit at 0xB6 P3_6;
sbit at 0xB7 P3_7;

// IP0
sbit at 0xB8 LPX0;
sbit at 0xB9 LPT0;
sbit at 0xBA LPX1;
sbit at 0xBB LPT1;
sbit at 0xBC LPS0;
sbit at 0xBD LPT2;
sbit at 0xBE LPS1;

// SCON1
sbit at 0xC0 RI_1;
sbit at 0xC1 TI_1;
sbit at 0xC2 RB8_1;
sbit at 0xC3 TB8_1;
sbit at 0xC4 REN_1;
sbit at 0xC5 SM2_1;
sbit at 0xC6 SM1_1;
sbit at 0xC7 SM0_1;

// T2CON
sbit at 0xC8 CP_RL_2;
sbit at 0xC9 C_T_2;
sbit at 0xCA TR_2;
sbit at 0xCB EXEN_2;
sbit at 0xCC TCLK;
sbit at 0xCD RCLK;
sbit at 0xCE EXF_2;
sbit at 0xCF TF_2;

// PSW
sbit at 0xD0 PARITY;
sbit at 0xD0 P;
sbit at 0xD1 F1;
sbit at 0xD2 OV;
sbit at 0xD3 RS0;
sbit at 0xD4 RS1;
sbit at 0xD5 F0;
sbit at 0xD6 AC;
sbit at 0xD7 CY;

// WDCON
sbit at 0xD8 RWT;
sbit at 0xD9 EWT;
sbit at 0xDA WTRF;
sbit at 0xDB WDIF;
sbit at 0xDC PFI;
sbit at 0xDD EPFI;
sbit at 0xDE POR;
sbit at 0xDF SMOD_1;

// EIE
sbit at 0xE8 EX2;
sbit at 0xE9 EX3;
sbit at 0xEA EX4;
sbit at 0xEB EX5;
sbit at 0xEC EWDI;

// EIP0
sbit at 0xF8 LPX2;
sbit at 0xF9 LPX3;
sbit at 0xFA LPX4;
sbit at 0xFB LPX5;
sbit at 0xFC LPWDI;
*/

static unsigned short int addr11_to_addr16(record *record) {
  return ((record->address + 2) & 0xF800) + ((record->bytecode[0] & 0x00E0) << 3) + record->bytecode[1];
}

extern void print_instruction(record *records) {
  unsigned char *bytecode = records->bytecode, instruction;
  instruction = bytecode[0];
  printf("0x%4.4X\t", records->address);

  for (unsigned short int i = 0; i < 4; i++) {
    if (i < records->size) printf("%2.2X ", records->bytecode[i]);
    else printf("   ");
  }

  switch (instruction_types[(unsigned char)records->bytecode[0]]) {
    case ONE_BYTE_INSTRUCTION:
      printf(instructions[instruction]);
      break;
    case ADDR_11:
      printf(instructions[instruction], addr11_to_addr16(records));
      break;
    case DIRECT:
    case IMMEDIATE:
    case OFFSET:
    case BIT:
    case NOT_BIT:
      printf(instructions[instruction], bytecode[1]);
      break;
    case ADDR_16:
    case IMMEDIATE_16:
      printf(instructions[instruction], bytes_to_word(bytecode[1], bytecode[2]));
      break;
    case BIT_OFFSET:
    case DIRECT_IMMEDIATE:
    case DIRECT_DIRECT:
    case IMMEDIATE_OFFSET:
    case DIRECT_OFFSET:
      printf(instructions[instruction], bytecode[1], bytecode[2]);
  }
}
