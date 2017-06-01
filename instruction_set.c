// instruction_set.c

#include "instruction_set.h"

unsigned char operands(unsigned char opcode) {
  //assert(opcode != 0xA5);
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
    case 0xD3:
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

record *extract_instruction(record *records) {
  unsigned char size = records->size, instruction_size = operands(records->bytecode[0]) + 1, *bytecode = NULL, checksum;
  unsigned short int address;
  mode mode = records->mode;

  if ((size != instruction_size) && (mode != END)) {
    address = records->address;
    bytecode = copy_bytecode(records->bytecode, size);
    checksum = records->checksum;
    records = destroy_record(records);
    records = create_record(size - instruction_size, address + instruction_size, mode, &bytecode[instruction_size], checksum, records);
    records = create_record(instruction_size, address, mode, bytecode, checksum, records);
    free(bytecode);
  }

  return records;
}

/*
extern record *extract_instructions(record *records) {
  record *new_record = extract_instruction(records);

  if (new_record) new_record->record = extract_instructions(new_record->record);

  return new_record;
}
*/
