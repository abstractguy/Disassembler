// instruction_set.c

#include "instruction_set.h"

extern record *unroll_subrecord_addresses(record *records) {
  record *record_block = NULL;
  unsigned char instruction, instruction_size;

  if (records) {
    for (int i = records->size; i >= 0; i -= instruction_size) {
      instruction = records->bytecode[i];
      instruction_size = operands(instruction) + 1;
      record_block = create_record(instruction_size, records->address + i, records->mode, &records->bytecode[i], 0, record_block);
    }

    records = replace_record_with_record_block(records, record_block);
  }

  return record_block;
}

extern record *unroll_all_subrecord_addresses(record *records) {
  record *subrecords = records;
  records = unroll_subrecord_addresses(records);
  while ((subrecords = unroll_subrecord_addresses(records->record)));
  return subrecords;
}

/*
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
*/

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
