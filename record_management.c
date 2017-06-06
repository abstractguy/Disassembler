// record_management.c
 
#include "record_management.h"
 
record *create_record(unsigned short int size, unsigned short int address, mode mode, unsigned char *bytecode, unsigned char checksum, record *old_record) {
  record *new_record = NULL;
  assert(new_record = malloc(sizeof(record)));
 
  new_record->size = size;
  new_record->address = address;
  new_record->mode = mode;
  new_record->bytecode = copy_bytevector(bytecode, size);
  new_record->checksum = checksum;
  new_record->record = old_record;
 
  return new_record;
}
 
extern record *destroy_record(record *old_record) {
  record *new_record = NULL;
  if (old_record) {
    new_record = old_record->record;
    if (old_record->bytecode) free(old_record->bytecode);
    old_record->bytecode = NULL;
    free(old_record);
    old_record = NULL;
  } return new_record;
}

record *copy_record(record *old_record) {
  return create_record(old_record->size, old_record->address, old_record->mode, old_record->bytecode, old_record->checksum, old_record->record);
}

record *reverse_records(record *forward) {
  record *backward = NULL;
 
  while (forward) {
    backward = create_record(forward->size, forward->address, forward->mode, forward->bytecode, forward->checksum, backward);
    forward = destroy_record(forward);
  }
 
  return backward;
}
 
record *build_record_from_string(char *string, record *next) {
  record *record = NULL;
  unsigned short int size = strlen(string) / 2;
  unsigned char *bytevector = NULL;
 
  bytevector = create_bytevector(size);
 
  for (unsigned short int i = 0; i < size; i++) bytevector[i] = ASCII_to_byte(&string[i * 2]);
 
  record = create_record((unsigned short int)bytevector[0], ((unsigned short int) bytevector[1] << 8) + (unsigned short int) bytevector[2], bytevector[3], &bytevector[4], bytevector[bytevector[0] + 4], next);

  destroy_bytevector(bytevector);
  return record;
}

extern record *hex_file_to_records(char *file) {
  record *records = NULL;
  unsigned short int size, i;
  char *array = file_to_array(file), **strings = NULL;

  size = i = char_count(array, ':');

  assert(size);
  strings = string_separate(array, "\r\n:");

  do {records = build_record_from_string(strings[--i], records);} while (i);

  destroy_bytevector((unsigned char *)array);
  destroy_strings(strings, size);

  return records;
}

record *align_records(record *forward) {
  record *temporary = NULL, *backward = NULL;
  unsigned char *bytecode = NULL;

  while (forward != NULL) {
    if (forward->record != NULL && (forward->address + forward->size) == forward->record->address) {
      bytecode = concatenate_bytevectors(forward->bytecode, forward->size, forward->record->bytecode, forward->record->size);

      temporary = create_record(forward->size + forward->record->size, forward->address, forward->mode, bytecode, (unsigned char)(forward->checksum + forward->record->checksum), forward->record->record);

      destroy_bytevector(bytecode);
      forward = destroy_record(destroy_record(forward));
      forward = temporary;

    } else {

      if (forward->size) backward = create_record(forward->size, forward->address, forward->mode, forward->bytecode, forward->checksum, backward);

      forward = destroy_record(forward);
    }
  }

  return reverse_records(backward);
}

extern void print_record(record *record) {
  printf("size: %u, address: 0x%4.4X, ", record->size, record->address);
 
  switch (record->mode) {
    case DATA: printf("record mode: DATA"); break;
    case END: printf("record mode: END");
  }
 
  if (record->size) {
    printf("\nbytecode: ");
    for (unsigned short int j = 0; j < record->size; j++)
      printf("%.2X", record->bytecode[j]);
  }
 
  printf("\nchecksum: 0x%X\n\n", record->checksum);
}
