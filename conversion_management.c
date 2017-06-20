// conversion_management.c
#include "conversion_management.h"
 
static unsigned short int bytes_to_word(unsigned char byte1, unsigned char byte0) {
  return ((unsigned short int)byte1 << 8) + (unsigned short int)byte0;
}
 
static unsigned short int addr11_to_addr16(record *record) {
  return ((record->address + 2) & 0xF800) + ((record->bytecode[0] & 0x00E0) << 3) + record->bytecode[1];
}
 
static unsigned char instruction_size(unsigned char bytecode) {
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
 
static void copy_bytes(unsigned char *destination, unsigned char *source, unsigned short int size) {
  for (unsigned short int i = 0; i < size; i++) {
    destination[i] = source[i];
  }
}
 
static unsigned char file_checksum = 0;
 
static void checksum(unsigned char *bytevector) {
  unsigned char size = bytevector[0] + 4, sum = 0;
  if (bytevector[3]) assert(!(file_checksum - RECORD_CHECKSUM));
  else {
    for (unsigned char i = 0; i < size; i++) {
      sum = (unsigned char)(sum + bytevector[i]);
    } assert(!((unsigned char)(~sum + 1) - bytevector[size]));
  }
}
 
static unsigned char ASCII_stream_to_byte(FILE *fp) {
  unsigned char string[3];
  string[0] = fgetc(fp);
  string[1] = fgetc(fp);
  string[2] = '\0';
  return (unsigned char)strtoul((char *)string, NULL, 16);
}
 
static unsigned char *file_pointer_to_record_bytevector(FILE *fp) {
  unsigned char *bytevector = NULL;
  unsigned short int size = (unsigned short int)ASCII_stream_to_byte(fp);
 
  bytevector = create_bytevector(4 + size);
 
  assert(((bytevector[0] = size)) <= 20);
 
  for (unsigned short int i = 1; i < size + 4; i++) {
    bytevector[i] = ASCII_stream_to_byte(fp);
  }
 
  return bytevector;
}
 
static record *copy_record_from_offset(record *records, unsigned short int size, unsigned short int offset, record *next) {
  unsigned char *bytecode = create_bytevector(size);
  copy_bytes(bytecode, &records->bytecode[offset], size);
  return create_record(size, records->address + offset, bytecode, next);
}
 
static record *bytevector_to_record(unsigned char *bytevector, record *old_record) {
  record *new_record = NULL;
  unsigned short int size = (unsigned short int)bytevector[0];
  unsigned char *new_bytevector = NULL;
  new_bytevector = create_bytevector(size);
  copy_bytes(new_bytevector, &bytevector[4], size);
  new_record = create_record(size, bytes_to_word(bytevector[1], bytevector[2]), new_bytevector, old_record);
  return new_record;
}
 
static record *file_pointer_to_record(FILE *fp, record *old_record) {
  record *new_record = NULL;
  unsigned char *bytevector = file_pointer_to_record_bytevector(fp);
  if (bytevector) {
    //checksum(bytevector);
    new_record = bytevector_to_record(bytevector, old_record);
    destroy_bytevector(bytevector);
  } return new_record;
}
 
static FILE *next_record_file_pointer(FILE * fp) {
  unsigned char i = 0;
  unsigned short int x;
  do {
    x = fgetc(fp);
    assert(++i < 44);
  } while (x != ':' && !feof(fp));
  assert(i);
  return fp;
}
 
record *hex_file_to_records(char *file) {
  FILE *fp = NULL;
  record *records = NULL;
  assert(fp = fopen(file, "r"));
  fp = next_record_file_pointer(fp);
  assert(!feof(fp));
  do {
    records = file_pointer_to_record(fp, records);
    fp = next_record_file_pointer(fp);
  } while (!feof(fp));
  fclose(fp);
  return record_reverse(destroy_record(records));
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
      printf(instructions[bytecode[0]], bytecode[1]);
      break;
    case BIT:
    case NOT_BIT:
      printf(instructions[bytecode[0]], SBIT[bytecode[1]]);
      break;
    case ADDR_16:
    case IMMEDIATE_16:
      printf(instructions[bytecode[0]], bytes_to_word(bytecode[1], bytecode[2]));
      break;
    case BIT_OFFSET:
      printf(instructions[bytecode[0]], SBIT[bytecode[1]], bytecode[2]);
      break;
    case DIRECT_DIRECT:
      printf(instructions[bytecode[0]], SFR[bytecode[1]], SFR[bytecode[2]]);
      break;
    case IMMEDIATE_OFFSET:
      printf(instructions[bytecode[0]], bytecode[1], bytecode[2]);
      break;
    case DIRECT_IMMEDIATE:
    case DIRECT_OFFSET:
      printf(instructions[bytecode[0]], SFR[bytecode[1]], bytecode[2]);
  }
}
 
record *align_instruction(record *forward) {
  record *temporary = NULL;
  unsigned char *bytecode = NULL;

  if (forward) {
    if (forward->next &&
         (forward->address + forward->size)
           == forward->next->address) {
      bytecode = create_bytevector(forward->size + forward->next->size);
      copy_bytes(bytecode, forward->bytecode, forward->size);
      copy_bytes(&bytecode[forward->size], forward->next->bytecode, forward->next->size);
      temporary = create_record(forward->size + forward->next->size, forward->address, bytecode, forward->next->next);
      forward = destroy_record(destroy_record(forward));
      forward = align_instruction(temporary);
    } else if (!forward->size) forward = destroy_record(forward);
 
    return forward;
  } else return NULL;

}
 
record *extract_instruction(record *forward) {
  record *backward = NULL;
  unsigned char size;
 
  if (forward) {
    size = instruction_size(forward->bytecode[0]);
    if (forward->size != size) {
      backward = copy_record_from_offset(forward, size, 0, copy_record_from_offset(forward, forward->size - size, size, forward->next));
      forward = destroy_record(forward);
      forward = backward;
    }
  } return forward;
}
