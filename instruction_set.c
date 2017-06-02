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

record *extract_instruction(record *forward) {
  record *temporary = NULL;
  //record *backward = NULL;
  unsigned char instruction_size;

  instruction_size = operands(forward->bytecode[0]) + 1;

  if ((forward->size != instruction_size) && (forward->mode != END)) {
    temporary = copy_record(forward);
    forward = destroy_record(forward);
    temporary->record = forward;
    forward = create_record(temporary->size - instruction_size, temporary->address + instruction_size, temporary->mode, &(temporary->bytecode[instruction_size]), temporary->checksum, forward);
    forward = create_record(instruction_size, temporary->address, temporary->mode, temporary->bytecode, temporary->checksum, forward);
  }

  return forward;
}
