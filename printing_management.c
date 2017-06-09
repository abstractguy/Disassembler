// printing_management.c
#include "printing_management.h"

  static char *instructions[256] = {
    "NOP\n",
    "AJMP 0x%4.4X\n",
    "LJMP 0x%4.4X\n",
    "RR A\n",
    "INC A\n",
    "INC 0x%X2.2\n",
    "INC @R0\n",
    "INC @R1\n",
    "INC R0\n",
    "INC R1\n",
    "INC R2\n",
    "INC R3\n",
    "INC R4\n",
    "INC R5\n",
    "INC R6\n",
    "INC R7\n",
    "JBC 0x%2.2X, 0x%2.2X\n",
    "ACALL 0x%4.4X\n",
    "LCALL 0x%4.4X\n",
    "RRC A\n",
    "DEC A\n",
    "DEC 0x%2.2X\n",
    "DEC @R0\n",
    "DEC @R1\n",
    "DEC R0\n",
    "DEC R1\n",
    "DEC R2\n",
    "DEC R3\n",
    "DEC R4\n",
    "DEC R5\n",
    "DEC R6\n",
    "DEC R7\n",
    "JB 0x%2.2X, 0x%2.2X\n",
    "AJMP 0x%4.4X\n",
    "RET\n",
    "RL A\n",
    "ADD A, 0x%2.2X\n",
    "ADD A, 0x%2.2X\n",
    "ADD A, @R0\n",
    "ADD A, @R1\n",
    "ADD A, R0\n",
    "ADD A, R1\n",
    "ADD A, R2\n",
    "ADD A, R3\n",
    "ADD A, R4\n",
    "ADD A, R5\n",
    "ADD A, R6\n",
    "ADD A, R7\n",
    "JNB 0x%2.2X, 0x%2.2X\n",
    "ACALL 0x%4.4X\n",
    "RETI\n",
    "RLC A\n",
    "ADDC A, 0x%2.2X\n",
    "ADDC A, 0x%2.2X\n",
    "ADDC A, @R0\n",
    "ADDC A, @R1\n",
    "ADDC A, R0\n",
    "ADDC A, R1\n",
    "ADDC A, R2\n",
    "ADDC A, R3\n",
    "ADDC A, R4\n",
    "ADDC A, R5\n",
    "ADDC A, R6\n",
    "ADDC A, R7\n",
    "JC 0x%2.2X\n",
    "AJMP 0x%4.4X\n",
    "ORL 0x%2.2X, A\n",
    "ORL 0x%2.2X, 0x%2.2X\n",
    "ORL A, 0x%2.2X\n",
    "ORL A, 0x%2.2X\n",
    "ORL A, @R0\n",
    "ORL A, @R1\n",
    "ORL A, R0\n",
    "ORL A, R1\n",
    "ORL A, R2\n",
    "ORL A, R3\n",
    "ORL A, R4\n",
    "ORL A, R5\n",
    "ORL A, R6\n",
    "ORL A, R7\n",
    "JNC 0x%2.2X\n",
    "ACALL 0x%4.4X\n",
    "ANL 0x%2.2X, A\n",
    "ANL 0x%2.2X, 0x%2.2X\n",
    "ANL A, 0x%2.2X\n",
    "ANL A, 0x%2.2X\n",
    "ANL A, @R0\n",
    "ANL A, @R1\n",
    "ANL A, R0\n",
    "ANL A, R1\n",
    "ANL A, R2\n",
    "ANL A, R3\n",
    "ANL A, R4\n",
    "ANL A, R5\n",
    "ANL A, R6\n",
    "ANL A, R7\n",
    "JZ 0x%2.2X\n",
    "AJMP 0x%4.4X\n",
    "XRL 0x%2.2X, A\n",
    "XRL 0x%2.2X, 0x%2.2X\n",
    "XRL A, 0x%2.2X\n",
    "XRL A, 0x%2.2X\n",
    "XRL A, @R0\n",
    "XRL A, @R1\n",
    "XRL A, R0\n",
    "XRL A, R1\n",
    "XRL A, R2\n",
    "XRL A, R3\n",
    "XRL A, R4\n",
    "XRL A, R5\n",
    "XRL A, R6\n",
    "XRL A, R7\n",
    "JNZ 0x%2.2X\n",
    "ACALL 0x%4.4X\n",
    "ORL C, 0x%2.2X\n",
    "JMP @A+DPTR\n",
    "MOV A, 0x%2.2X\n",
    "MOV 0x%2.2X, 0x%2.2X\n",
    "MOV @R0, 0x%2.2X\n",
    "MOV @R1, 0x%2.2X\n",
    "MOV R0, 0x%2.2X\n",
    "MOV R1, 0x%2.2X\n",
    "MOV R2, 0x%2.2X\n",
    "MOV R3, 0x%2.2X\n",
    "MOV R4, 0x%2.2X\n",
    "MOV R5, 0x%2.2X\n",
    "MOV R6, 0x%2.2X\n",
    "MOV R7, 0x%2.2X\n",
    "SJMP 0x%2.2X\n",
    "AJMP 0x%4.4X\n",
    "ANL C, %u\n",
    "MOVC A, @A+PC\n",
    "DIV A, B\n",
    "MOV 0x%2.2X, 0x%2.2X\n",
    "MOV 0x%2.2X, @R0\n",
    "MOV 0x%2.2X, @R1\n",
    "MOV 0x%2.2X, R0\n",
    "MOV 0x%2.2X, R1\n",
    "MOV 0x%2.2X, R2\n",
    "MOV 0x%2.2X, R3\n",
    "MOV 0x%2.2X, R4\n",
    "MOV 0x%2.2X, R5\n",
    "MOV 0x%2.2X, R6\n",
    "MOV 0x%2.2X, R7\n",
    "MOV DPTR, 0x%4.4X\n",
    "ACALL 0x%4.4X\n",
    "MOV %u, C\n",
    "MOVC A, @A+DPTR\n",
    "SUBB A, 0x%2.2X\n",
    "SUBB A, 0x%2.2X\n",
    "SUBB A, @R0\n",
    "SUBB A, @R1\n",
    "SUBB A, R0\n",
    "SUBB A, R1\n",
    "SUBB A, R2\n",
    "SUBB A, R3\n",
    "SUBB A, R4\n",
    "SUBB A, R5\n",
    "SUBB A, R6\n",
    "SUBB A, R7\n",
    "ORL C, /%u\n",
    "AJMP 0x%4.4X\n",
    "MOV C, %u\n",
    "INC DPTR\n",
    "MUL A, B\n",
    "RESERVED\n",
    "MOV @R0, 0x%2.2X\n",
    "MOV @R1, 0x%2.2X\n",
    "MOV R0, 0x%2.2X\n",
    "MOV R1, 0x%2.2X\n",
    "MOV R2, 0x%2.2X\n",
    "MOV R3, 0x%2.2X\n",
    "MOV R4, 0x%2.2X\n",
    "MOV R5, 0x%2.2X\n",
    "MOV R6, 0x%2.2X\n",
    "MOV R7, 0x%2.2X\n",
    "ANL C, /%u\n",
    "ACALL 0x%4.4X\n",
    "CPL %u\n",
    "CPL C\n",
    "CJNE A, 0x%2.2X, 0x%2.2X\n",
    "CJNE A, 0x%2.2X, 0x%2.2X\n",
    "CJNE @R0, 0x%2.2X, 0x%2.2X\n",
    "CJNE @R1, 0x%2.2X, 0x%2.2X\n",
    "CJNE R0, 0x%2.2X, 0x%2.2X\n",
    "CJNE R1, 0x%2.2X, 0x%2.2X\n",
    "CJNE R2, 0x%2.2X, 0x%2.2X\n",
    "CJNE R3, 0x%2.2X, 0x%2.2X\n",
    "CJNE R4, 0x%2.2X, 0x%2.2X\n",
    "CJNE R5, 0x%2.2X, 0x%2.2X\n",
    "CJNE R6, 0x%2.2X, 0x%2.2X\n",
    "CJNE R7, 0x%2.2X, 0x%2.2X\n",
    "PUSH 0x%2.2X\n",
    "AJMP 0x%4.4X\n",
    "CLR %u\n",
    "CLR C\n",
    "SWAP A\n",
    "XCH A, 0x%2.2X\n",
    "XCH A, @R0\n",
    "XCH A, @R1\n",
    "XCH A, R0\n",
    "XCH A, R1\n",
    "XCH A, R2\n",
    "XCH A, R3\n",
    "XCH A, R4\n",
    "XCH A, R5\n",
    "XCH A, R6\n",
    "XCH A, R7\n",
    "POP 0x%2.2X\n",
    "ACALL 0x%4.4X\n",
    "SETB %u\n",
    "SETB C\n",
    "DA A\n",
    "DJNZ 0x%2.2X, 0x%2.2X\n",
    "XCHD A, @R0\n",
    "XCHD A, @R1\n",
    "DJNZ R0, 0x%2.2X\n",
    "DJNZ R1, 0x%2.2X\n",
    "DJNZ R2, 0x%2.2X\n",
    "DJNZ R3, 0x%2.2X\n",
    "DJNZ R4, 0x%2.2X\n",
    "DJNZ R5, 0x%2.2X\n",
    "DJNZ R6, 0x%2.2X\n",
    "DJNZ R7, 0x%2.2X\n",
    "MOVX A, @DPTR\n",
    "AJMP 0x%4.4X\n",
    "MOVX A, @R0\n",
    "MOVX A, @R1\n",
    "MOV A, 0x%2.2X\n",
    "MOV A, @R0\n",
    "MOV A, @R1\n",
    "MOV A, R0\n",
    "MOV A, R1\n",
    "MOV A, R2\n",
    "MOV A, R3\n",
    "MOV A, R4\n",
    "MOV A, R5\n",
    "MOV A, R6\n",
    "MOV A, R7\n",
    "MOVX @DPTR, A\n",
    "ACALL 0x%4.4X\n",
    "MOVX @R0, A\n",
    "MOVX @R1, A\n",
    "CPL A\n",
    "MOV 0x%2.2X, A\n",
    "MOV @R0, A\n",
    "MOV @R1, A\n",
    "MOV R0, A\n",
    "MOV R1, A\n",
    "MOV R2, A\n",
    "MOV R3, A\n",
    "MOV R4, A\n",
    "MOV R5, A\n",
    "MOV R6, A\n",
    "MOV R7, A\n"
 };

unsigned short int bytes_to_word(unsigned char byte1, unsigned char byte0) {
  return ((unsigned short int)byte1 << 8) + (unsigned short int)byte0;
}

unsigned short int addr11_to_addr16(record *record) {
  return ((record->address + 2) & 0xF800) + ((record->bytecode[0] & 0x00E0) << 3) + record->bytecode[1];
}

extern void print_instruction(record *record) {
  unsigned char *bytecode = record->bytecode, instruction;
  instruction = bytecode[0];
  printf("0x%4.4X\t", record->address);

  for (unsigned short int i = 0; i < 4; i++) {
    if (i < record->size) printf("%2.2X ", record->bytecode[i]);
    else printf("   ");
  }

  switch (instruction) {
    case 0x00:
    case 0x03:
    case 0x04:
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x09:
    case 0x0A:
    case 0x0B:
    case 0x0C:
    case 0x0D:
    case 0x0E:
    case 0x0F:
    case 0x13:
    case 0x14:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x1F:
    case 0x22:
    case 0x23:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x32:
    case 0x33:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3B:
    case 0x3C:
    case 0x3D:
    case 0x3E:
    case 0x3F:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
    case 0x5D:
    case 0x5E:
    case 0x5F:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6A:
    case 0x6B:
    case 0x6C:
    case 0x6D:
    case 0x6E:
    case 0x6F:
    case 0x73:
    case 0x83:
    case 0x84:
    case 0x93:
    case 0x96:
    case 0x97:
    case 0x98:
    case 0x99:
    case 0x9A:
    case 0x9B:
    case 0x9C:
    case 0x9D:
    case 0x9E:
    case 0x9F:
    case 0xA3:
    case 0xA4:
    case 0xA5:
    case 0xB3:
    case 0xC3:
    case 0xC4:
    case 0xC6:
    case 0xC7:
    case 0xC8:
    case 0xC9:
    case 0xCA:
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
    case 0xD3:
    case 0xD4:
    case 0xD6:
    case 0xD7:
    case 0xE0:
    case 0xE2:
    case 0xE3:
    case 0xE4:
    case 0xE6:
    case 0xE7:
    case 0xE8:
    case 0xE9:
    case 0xEA:
    case 0xEB:
    case 0xEC:
    case 0xED:
    case 0xEE:
    case 0xEF:
    case 0xF0:
    case 0xF2:
    case 0xF3:
    case 0xF4:
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    case 0xFB:
    case 0xFC:
    case 0xFD:
    case 0xFE:
    case 0xFF: printf(instructions[instruction]); break;
    case 0x01:
    case 0x11:
    case 0x21:
    case 0x31:
    case 0x41:
    case 0x51:
    case 0x61:
    case 0x71:
    case 0x81:
    case 0x91:
    case 0xA1:
    case 0xB1:
    case 0xC1:
    case 0xD1:
    case 0xE1:
    case 0xF1: printf(instructions[instruction], addr11_to_addr16(record)); break;
    case 0x02:
    case 0x12:
    case 0x90: printf(instructions[instruction], bytes_to_word(bytecode[1], bytecode[2])); break;
    case 0x10:
    case 0x20:
    case 0x30:
    case 0x43:
    case 0x53:
    case 0x63:
    case 0x75:
    case 0x85:
    case 0xB4:
    case 0xB5:
    case 0xB6:
    case 0xB7:
    case 0xB8:
    case 0xB9:
    case 0xBA:
    case 0xBB:
    case 0xBC:
    case 0xBD:
    case 0xBE:
    case 0xBF:
    case 0xD5: printf(instructions[instruction], bytecode[1], bytecode[2]); break;
    case 0x05:
    case 0x15:
    case 0x24:
    case 0x25:
    case 0x34:
    case 0x35:
    case 0x40:
    case 0x42:
    case 0x44:
    case 0x45:
    case 0x50:
    case 0x52:
    case 0x54:
    case 0x55:
    case 0x60:
    case 0x62:
    case 0x64:
    case 0x65:
    case 0x70:
    case 0x72:
    case 0x74:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7A:
    case 0x7B:
    case 0x7C:
    case 0x7D:
    case 0x7E:
    case 0x7F:
    case 0x80:
    case 0x82:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8A:
    case 0x8B:
    case 0x8C:
    case 0x8D:
    case 0x8E:
    case 0x8F:
    case 0x92:
    case 0x94:
    case 0x95:
    case 0xA0:
    case 0xA2:
    case 0xA6:
    case 0xA7:
    case 0xA8:
    case 0xA9:
    case 0xAA:
    case 0xAB:
    case 0xAC:
    case 0xAD:
    case 0xAE:
    case 0xAF:
    case 0xB0:
    case 0xB2:
    case 0xC0:
    case 0xC2:
    case 0xC5:
    case 0xD0:
    case 0xD2: printf(instructions[instruction], bytecode[1]); break;
    case 0xD8:
    case 0xD9:
    case 0xDA:
    case 0xDB:
    case 0xDC:
    case 0xDD:
    case 0xDE:
    case 0xDF: printf("Bytecode size: %u...\t", record->size); printf(instructions[instruction], bytecode[1]); break;
    case 0xE5:
    case 0xF5: printf(instructions[instruction], bytecode[1]); break;
    default: printf("Failed instruction: %2.2X\n", instruction); assert(0);
  }
}
