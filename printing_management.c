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

    // Rendu ici...
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
    "MOV R7, A\n";
 };









unsigned char **extract_arguments(record *record) {
  unsigned char **argument_strings = NULL;

  if (record->size > 0) {
    // Detruire apres utilisation -->
    argument_strings = create_strings(record->size - 1);
    // ...
  }

  return argument_strings;
}

unsigned char *bytevector_to_string(unsigned char *bytevector, unsigned char size) {
  // Detruire apres utilisation -->
  unsigned char *string = create_bytevector(size * 2 + 1);

  string[size - 1] = '\0';

  // ...

  return string;
}

unsigned char *record_to_string(record *record) {
  // Detruire apres utilisation -->
  unsigned char **strings = extract_arguments(record);
  unsigned char *string = NULL, string_size, i = 0;

  string_size = // ...

  // Detruire apres utilisation -->
  string = create_bytevector(string_size);

  // ...

  return string;
}

void print_instruction(record *record) {
  
}
