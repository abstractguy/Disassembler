// conversion_management.c
#include "conversion_management.h"

static char **create_strings(unsigned short int size) {
  char **strings = NULL;
  assert(strings = calloc(size, sizeof(unsigned char *)));
  return strings;
}

static void destroy_strings(char **strings, unsigned short int size) {
  unsigned short int i = size;
  if (strings) {
    while (i--) if (strings[i]) free(strings[i]);
    free(strings);
  }
}

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

static void checksum(unsigned char *bytevector, unsigned char file_checksum) {
  unsigned char size = bytevector[0] + 4, sum = 0;
  if (bytevector[3]) assert(!(file_checksum - RECORD_CHECKSUM));
  else {
    for (unsigned char i = 0; i < size; i++) {
      sum = (unsigned char)(sum + bytevector[i]);
    } assert(!((unsigned char)(~sum + 1) - bytevector[size]));
  }
}

static unsigned char ASCII_to_byte(char *ASCII) {
  char *string = (char *)create_bytevector(3);
  unsigned char byte;
  string[2] = '\0';
  copy_bytes((unsigned char *)string, (unsigned char *)ASCII, 2);
  byte = (unsigned char)strtoul(string, NULL, 16);
  destroy_bytevector((unsigned char *)string);
  return byte;
}

static unsigned char *string_to_bytevector(char *string) {
  unsigned char substring_size = strlen(string) / 2, *bytevector = NULL;
  bytevector = create_bytevector(substring_size);

  for (unsigned short int i = 0; i < substring_size; i++) {
    bytevector[i] = ASCII_to_byte(&string[i * 2]);
  }

  return bytevector;
}

static unsigned short int char_count(char *string, char character) {
  unsigned short int size = 0;
  for (unsigned short int i = 0; string[i]; i++) {
    if (string[i] == character) size++;
  } return size;
}

static unsigned short int record_count = 0;

static char **string_separate(char *string, char *delimiters) {
  char *token = NULL, **strings = create_strings(char_count(string, ':'));

  if ((token = strtok(string, delimiters))) {
    for (unsigned short int i = 0; token; i++, token = strtok(NULL, delimiters)) {
      strings[i] = strdup(token);
      record_count++;
    }
  } return strings;
}

static record *copy_record_from_offset(record *records, unsigned short int size, unsigned short int offset, record *next) {
  unsigned char *bytecode = create_bytevector(size);
  copy_bytes(bytecode, &records->bytecode[offset], size);
  return create_record(size, records->address + offset, records->mode, bytecode, next);
}

static record *create_record_from_bytevector(unsigned char *bytevector, record *old_record) {
  record *new_record = NULL;
  unsigned short int size = (unsigned short int)bytevector[0];
  unsigned char *new_bytevector = NULL;
  new_bytevector = create_bytevector(size);
  copy_bytes(new_bytevector, &bytevector[4], size);
  new_record = create_record(size, bytes_to_word(bytevector[1], bytevector[2]), bytevector[3], new_bytevector, old_record);
  return new_record;
}

static char **hex_file_to_record_strings(char *file) {
  char *array = file_to_array(file), **strings = NULL;
  strings = string_separate(array, "\r\n:");
  destroy_bytevector((unsigned char *)array);
  return strings;
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

extern record *hex_file_to_records(char *file) {
  record *records = NULL;
  unsigned short int size;
  unsigned char *bytevector = NULL, file_checksum = 0;
  char **strings = hex_file_to_record_strings(file);

  assert(size = record_count);

  while (size--) {
    bytevector = string_to_bytevector(strings[size]);
    checksum(bytevector, file_checksum += RECORD_CHECKSUM);
    records = create_record_from_bytevector(bytevector, records);
    destroy_bytevector(bytevector);
  }

  destroy_strings(strings, record_count);
  return records;
}

record *align_instruction(record *forward) {
  record *temporary = NULL;
  unsigned char *bytecode = NULL;
 
  if (forward->next && (forward->address + forward->size) == forward->next->address) {
    bytecode = create_bytevector(forward->size + forward->next->size);
    copy_bytes(bytecode, forward->bytecode, forward->size);
    copy_bytes(&bytecode[forward->size], forward->next->bytecode, forward->next->size);
    temporary = create_record(forward->size + forward->next->size, forward->address, forward->mode, bytecode, forward->next->next);
    forward = destroy_record(destroy_record(forward));
    forward = align_instruction(temporary);
  } else if (!forward->size) forward = destroy_record(forward);

  return forward;
}

record *extract_instruction(record *forward) {
  record *backward = NULL;
  unsigned char size;

  if (forward) {
    size = instruction_size(forward->bytecode[0]);
    if (forward->size != size && forward->mode != END) {
      backward = copy_record_from_offset(forward, size, 0, copy_record_from_offset(forward, forward->size - size, size, forward->next));
      forward = destroy_record(forward);
      forward = backward;
    }
  } return forward;
}
