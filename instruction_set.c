// instruction_set.c
 
#include "instruction_set.h"
 
unsigned char instruction_size(unsigned char opcode) {
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
    case 0xD5: return 3;
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
    case 0xF4: return 1;
    default:
      if ((opcode > 0x89) && (opcode < 0x91)) return 2;
      else if ((opcode > 0xB3) && (opcode < 0xC0)) return 3;
      else switch (opcode & 0x0F) {
        case 0x00:
        case 0x01:
        case 0x02:
        case 0x04:
        case 0x05: return 2;
        case 0x03: return 1;
        default:
          switch (opcode & 0xF0) {
            case 0x60:
            case 0x70:
            case 0xA0:
            case 0xD0: return 2;
            default: return 1;
        }
    }
  }
}

record *extract_instructions(char *file) {
  record *forward  = hex_file_to_records(file);
  record *backward = NULL, *next = NULL;
  unsigned char size;

  while (forward) {
    size = instruction_size(forward->bytecode[0]);
    if (forward->size != size && forward->mode != END) {

      next = copy_record_from_offset(forward, forward->size - size, size, forward->record);

      backward = copy_record_from_offset(forward, size, 0, backward);

      forward = destroy_record(forward);
    } else {
      next            = forward->record;
      forward->record = backward;
      backward        = forward;
    }

    forward = next;
  }

  return reverse_records(backward);
}
