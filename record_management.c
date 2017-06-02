// record_management.c
 
#include "record_management.h"
 
record *create_record(unsigned char size, unsigned short int address, mode mode, unsigned char *bytecode, unsigned char checksum, record *old_record) {
  record *new_record = NULL;
  assert(new_record = (record *)malloc(sizeof(record)));

  new_record->size = size;
  new_record->address = address;
  new_record->mode = mode;
  new_record->bytecode = copy_bytecode(bytecode, size);
  new_record->checksum = checksum;
  new_record->record = old_record;
 
  return new_record;
}
 
extern record *destroy_record(record *old_record) {
  record *new_record = NULL;
  if (old_record) {
    new_record = old_record->record;
    if (old_record->bytecode) free(old_record->bytecode);
    free(old_record);
  } return new_record;
}

record *copy_record(record *old_record) {
  record *new_record = create_record(old_record->size, old_record->address, old_record->mode, old_record->bytecode, old_record->checksum, old_record->record);
  return new_record;
}

record *build_record_from_string(char *string, record *next) {
  record *record = NULL;
  unsigned char i, size = strlen(string) / 2, *bytevector = NULL;
 
  assert(bytevector = (unsigned char *)calloc(size, sizeof(unsigned char)));
 
  for (i = 0; i < size; i++) bytevector[i] = ASCII_to_byte(&string[i * 2]);
 
  record = create_record(bytevector[0], ((unsigned short int) bytevector[1] << 8) + (unsigned short int) bytevector[2], bytevector[3], &bytevector[4], bytevector[bytevector[0] + 4], next);
 
  free(bytevector);
  return record;
}
 
record *add_record(record *new_record, record *old_record) {
  new_record->record = old_record;
  old_record = new_record;
  return old_record;
}
 
record *get_last_record(record *records) {
  record *previous = NULL, *next = records;
 
  while (next) {
    previous = next;
    next = previous->record;
  }
 
  return previous;
}
 
record *replace_record_with_record_block(record *start, record *record_block) {
  record *end = get_last_record(record_block);
 
  if (end != record_block) {
    start = destroy_record(start);
    end->record = start;
    start->record = record_block;
  }
 
  return record_block;
}
 
extern record *hex_file_to_records(char *file) {
  record *records = NULL;
  char *array = NULL, **strings = NULL;
  int size, i;
 
  array = file_to_array(array, file);
  size = i = char_count(array, ':');
 
  assert(size);
  strings = create_strings(array, size);
  size = i;
  do {records = build_record_from_string(strings[--i], records);} while (i);
 
  destroy_array(array);
  destroy_strings(strings, size);
 
  return records;
}
 
extern void print_record(record *record) {
  printf("size: %u, address: 0x%4.4X, ", record->size, record->address);
 
  switch (record->mode) {
    case DATA: printf("record mode: DATA"); break;
    case END: printf("record mode: END");   break;
    case EXTENDED: printf("record mode: EXTENDED");
  }
 
  if (record->size) {
    printf("\nbytecode: ");
    for (int j = 0; j < record->size; j++) {
      printf("%.2X", record->bytecode[j]);
    }
  }
 
  printf("\nchecksum: 0x%X\n\n", record->checksum);
}
