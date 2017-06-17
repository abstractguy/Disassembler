// instruction_management.c
#include "instruction_management.h"

instruction_type instruction_types[256] = {
  ONE_BYTE_INSTRUCTION,
  ADDR_11,
  ADDR_16,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  BIT_OFFSET,
  ADDR_11,
  ADDR_16,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  BIT_OFFSET,
  ADDR_11,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  IMMEDIATE,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  BIT_OFFSET,
  ADDR_11,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  IMMEDIATE,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  OFFSET,
  ADDR_11,
  DIRECT,
  DIRECT_IMMEDIATE,
  IMMEDIATE,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  OFFSET,
  ADDR_11,
  DIRECT,
  DIRECT_IMMEDIATE,
  IMMEDIATE,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  OFFSET,
  ADDR_11,
  DIRECT,
  DIRECT_IMMEDIATE,
  IMMEDIATE,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  OFFSET,
  ADDR_11,
  BIT,
  ONE_BYTE_INSTRUCTION,
  IMMEDIATE,
  DIRECT_IMMEDIATE,
  IMMEDIATE,
  IMMEDIATE,
  IMMEDIATE,
  IMMEDIATE,
  IMMEDIATE,
  IMMEDIATE,
  IMMEDIATE,
  IMMEDIATE,
  IMMEDIATE,
  IMMEDIATE,
  OFFSET,
  ADDR_11,
  BIT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  DIRECT_DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  IMMEDIATE_16,
  ADDR_11,
  BIT,
  ONE_BYTE_INSTRUCTION,
  IMMEDIATE,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  NOT_BIT,
  ADDR_11,
  BIT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  DIRECT,
  NOT_BIT,
  ADDR_11,
  BIT,
  ONE_BYTE_INSTRUCTION,
  IMMEDIATE_OFFSET,
  DIRECT_OFFSET,
  IMMEDIATE_OFFSET,
  IMMEDIATE_OFFSET,
  IMMEDIATE_OFFSET,
  IMMEDIATE_OFFSET,
  IMMEDIATE_OFFSET,
  IMMEDIATE_OFFSET,
  IMMEDIATE_OFFSET,
  IMMEDIATE_OFFSET,
  IMMEDIATE_OFFSET,
  IMMEDIATE_OFFSET,
  DIRECT,
  ADDR_11,
  BIT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  DIRECT,
  ADDR_11,
  BIT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  DIRECT_OFFSET,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  OFFSET,
  OFFSET,
  OFFSET,
  OFFSET,
  OFFSET,
  OFFSET,
  OFFSET,
  OFFSET,
  ONE_BYTE_INSTRUCTION,
  ADDR_11,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ADDR_11,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  DIRECT,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION,
  ONE_BYTE_INSTRUCTION
};

unsigned char instruction_size(unsigned char bytecode) {
  instruction_type type = instruction_types[bytecode];
  switch (type) {
    case ONE_BYTE_INSTRUCTION: return 1;
    case ADDR_11:
    case DIRECT:
    case IMMEDIATE:
    case OFFSET:
    case BIT:
    case NOT_BIT: return 2;
    case ADDR_16:
    case IMMEDIATE_16:
    case BIT_OFFSET:
    case DIRECT_IMMEDIATE:
    case DIRECT_DIRECT:
    case IMMEDIATE_OFFSET:
    case DIRECT_OFFSET: return 3;
    default: return 0;
  }
}

char *instructions[256] = {
  "NOP\n",
  "AJMP\t0x%4.4X\n",
  "LJMP\t0x%4.4X\n",
  "RR\t\tA\n",
  "INC\t\tA\n",
  "INC\t\t%s\n",
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
  "DEC\t\t%s\n",
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
  "ADD\t\tA,\t%s\n",
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
  "ADDC\tA,\t%s\n",
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
  "ORL\t\t%s,\tA\n",
  "ORL\t\t%s,\t0x%2.2X\n",
  "ORL\t\tA,\t0x%2.2X\n",
  "ORL\t\tA,\t%s\n",
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
  "ANL\t\t%s,\tA\n",
  "ANL\t\t%s,\t0x%2.2X\n",
  "ANL\t\tA,\t0x%2.2X\n",
  "ANL\t\tA,\t%s\n",
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
  "XRL\t\t%s,\tA\n",
  "XRL\t\t%s,\t0x%2.2X\n",
  "XRL\t\tA,\t0x%2.2X\n",
  "XRL\t\tA,\t%s\n",
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
  "MOV\t\t%s,\t0x%2.2X\n",
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
  "MOV\t\t%s,\t%s\n",
  "MOV\t\t%s,\t@R0\n",
  "MOV\t\t%s,\t@R1\n",
  "MOV\t\t%s,\tR0\n",
  "MOV\t\t%s,\tR1\n",
  "MOV\t\t%s,\tR2\n",
  "MOV\t\t%s,\tR3\n",
  "MOV\t\t%s,\tR4\n",
  "MOV\t\t%s,\tR5\n",
  "MOV\t\t%s,\tR6\n",
  "MOV\t\t%s,\tR7\n",
  "MOV\t\tDPTR,\t0x%4.4X\n",
  "ACALL\t0x%4.4X\n",
  "MOV\t\t0x%2.2X,\tC\n",
  "MOVC\tA,\t@A+DPTR\n",
  "SUBB\tA,\t0x%2.2X\n",
  "SUBB\tA,\t%s\n",
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
  "MOV\t\t@R0,\t%s\n",
  "MOV\t\t@R1,\t%s\n",
  "MOV\t\tR0,\t%s\n",
  "MOV\t\tR1,\t%s\n",
  "MOV\t\tR2,\t%s\n",
  "MOV\t\tR3,\t%s\n",
  "MOV\t\tR4,\t%s\n",
  "MOV\t\tR5,\t%s\n",
  "MOV\t\tR6,\t%s\n",
  "MOV\t\tR7,\t%s\n",
  "ANL\t\tC,\t/0x%2.2X\n",
  "ACALL\t0x%4.4X\n",
  "CPL\t\t0x%2.2X\n",
  "CPL\t\tC\n",
  "CJNE\tA,\t0x%2.2X,\t0x%2.2X\n",
  "CJNE\tA,\t%s,\t0x%2.2X\n",
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
  "PUSH\t%s\n",
  "AJMP\t0x%4.4X\n",
  "CLR\t\t0x%2.2X\n",
  "CLR\t\tC\n",
  "SWAP\tA\n",
  "XCH\t\tA,\t%s\n",
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
  "POP\t\t%s\n",
  "ACALL\t0x%4.4X\n",
  "SETB\t0x%2.2X\n",
  "SETB\tC\n",
  "DA\t\tA\n",
  "DJNZ\t%s,\t0x%2.2X\n",
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
  "MOV\t\tA,\t%s\n",
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
  "MOV\t\t%s,\tA\n",
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

// 0x80..0xFF
char *SFR[256] = {
  "0x00",
  "0x01",
  "0x02",
  "0x03",
  "0x04",
  "0x05",
  "0x06",
  "0x07",
  "0x08",
  "0x09",
  "0x0A",
  "0x0B",
  "0x0C",
  "0x0D",
  "0x0E",
  "0x0F",
  "0x10",
  "0x11",
  "0x12",
  "0x13",
  "0x14",
  "0x15",
  "0x16",
  "0x17",
  "0x18",
  "0x19",
  "0x1A",
  "0x1B",
  "0x1C",
  "0x1D",
  "0x1E",
  "0x1F",
  "0x20",
  "0x21",
  "0x22",
  "0x23",
  "0x24",
  "0x25",
  "0x26",
  "0x27",
  "0x28",
  "0x29",
  "0x2A",
  "0x2B",
  "0x2C",
  "0x2D",
  "0x2E",
  "0x2F",
  "0x30",
  "0x31",
  "0x32",
  "0x33",
  "0x34",
  "0x35",
  "0x36",
  "0x37",
  "0x38",
  "0x39",
  "0x3A",
  "0x3B",
  "0x3C",
  "0x3D",
  "0x3E",
  "0x3F",
  "0x40",
  "0x41",
  "0x42",
  "0x43",
  "0x44",
  "0x45",
  "0x46",
  "0x47",
  "0x48",
  "0x49",
  "0x4A",
  "0x4B",
  "0x4C",
  "0x4D",
  "0x4E",
  "0x4F",
  "0x50",
  "0x51",
  "0x52",
  "0x53",
  "0x54",
  "0x55",
  "0x56",
  "0x57",
  "0x58",
  "0x59",
  "0x5A",
  "0x5B",
  "0x5C",
  "0x5D",
  "0x5E",
  "0x5F",
  "0x60",
  "0x61",
  "0x62",
  "0x63",
  "0x64",
  "0x65",
  "0x66",
  "0x67",
  "0x68",
  "0x69",
  "0x6A",
  "0x6B",
  "0x6C",
  "0x6D",
  "0x6E",
  "0x6F",
  "0x70",
  "0x71",
  "0x72",
  "0x73",
  "0x74",
  "0x75",
  "0x76",
  "0x77",
  "0x78",
  "0x79",
  "0x7A",
  "0x7B",
  "0x7C",
  "0x7D",
  "0x7E",
  "0x7F",
  "P0",
  "SP",
  "DPL",
  "DPH",
  "DPL1",
  "DPH1",
  "DPS",
  "PCON",
  "TCON",
  "TMOD",
  "TL0",
  "TL1",
  "TH0",
  "TH1",
  "CKCON",
  "0x8F",
  "P1",
  "EXIF",
  "0x92",
  "0x93",
  "0x94",
  "0x95",
  "CKMOD",
  "0x97",
  "SCON0",
  "SBUF0",
  "0x9A",
  "0x9B",
  "0x9C",
  "ACON",
  "0x9E",
  "0x9F",
  "P2",
  "0xA1",
  "0xA2",
  "0xA3",
  "0xA4",
  "0xA5",
  "0xA6",
  "0xA7",
  "IE",
  "SADDR0",
  "SADDR1",
  "0xAB",
  "0xAC",
  "0xAD",
  "0xAE",
  "0xAF",
  "P3",
  "IP1",
  "0xB2",
  "0xB3",
  "0xB4",
  "0xB5",
  "0xB6",
  "0xB7",
  "IP0",
  "SADEN0",
  "SADEN1",
  "0xBB",
  "0xBC",
  "0xBD",
  "0xBE",
  "0xBF",
  "SCON1",
  "SBUF1",
  "ROMSIZE",
  "0xC3",
  "PMR",
  "STATUS",
  "0xC6",
  "TA",
  "T2CON",
  "T2MOD",
  "RCAP2L",
  "RCAP2H",
  "TL2",
  "TH2",
  "0xCE",
  "0xCF",
  "PSW",
  "0xD1",
  "0xD2",
  "0xD3",
  "0xD4",
  "FCNTL",
  "FDATA",
  "0xD7",
  "WDCON",
  "0xD9",
  "0xDA",
  "0xDB",
  "0xDC",
  "0xDD",
  "0xDE",
  "0xDF",
  "A",
  "0xE1",
  "0xE2",
  "0xE3",
  "0xE4",
  "0xE5",
  "0xE6",
  "0xE7",
  "EIE",
  "0xE9",
  "0xEA",
  "0xEB",
  "0xEC",
  "0xED",
  "0xEE",
  "0xEF",
  "B",
  "EIP1",
  "0xF2",
  "0xF3",
  "0xF4",
  "0xF5",
  "0xF6",
  "0xF7",
  "EIP0",
  "0xF9",
  "0xFA",
  "0xFB",
  "0xFC",
  "0xFD",
  "0xFE",
  "0xFF"
};

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

unsigned short int bytes_to_word(unsigned char byte1, unsigned char byte0) {
  return ((unsigned short int)byte1 << 8) + (unsigned short int)byte0;
}

static unsigned short int addr11_to_addr16(record *record) {
  return ((record->address + 2) & 0xF800) + ((record->bytecode[0] & 0x00E0) << 3) + record->bytecode[1];
}

void print_instruction(record *records) {
  unsigned char *bytecode = records->bytecode;
  printf("0x%4.4X\t", records->address);

  for (unsigned short int i = 0; i < 4; i++) {
    if (i < records->size) printf("%2.2X ", records->bytecode[i]);
    else printf("   ");
  }

  switch (instruction_types[(unsigned char)records->bytecode[0]]) {
    case ONE_BYTE_INSTRUCTION:
      printf(instructions[bytecode[0]]);
      break;
    case ADDR_11:
      printf(instructions[bytecode[0]], addr11_to_addr16(records));
      break;
    case DIRECT:
      printf(instructions[bytecode[0]], SFR[bytecode[1]]);
      break;
    case IMMEDIATE:
    case OFFSET:
    case BIT:
    case NOT_BIT:
      printf(instructions[bytecode[0]], bytecode[1]);
      break;
    case ADDR_16:
    case IMMEDIATE_16:
      printf(instructions[bytecode[0]], bytes_to_word(bytecode[1], bytecode[2]));
      break;
    case BIT_OFFSET:
      printf(instructions[bytecode[0]], bytecode[1], bytecode[2]);
      break;
    case DIRECT_DIRECT:
      printf(instructions[bytecode[0]], SFR[bytecode[1]], SFR[bytecode[2]]);
      break;
    case DIRECT_IMMEDIATE:
    case IMMEDIATE_OFFSET:
    case DIRECT_OFFSET:
      printf(instructions[bytecode[0]], SFR[bytecode[1]], bytecode[2]);
  }
}
