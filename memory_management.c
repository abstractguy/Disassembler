// memory_management.c

#include "memory_management.h"

unsigned char *create_bytevector(unsigned short int size) {
  unsigned char *bytevector = NULL;
  assert(bytevector = calloc(size, sizeof(unsigned char)));
  return bytevector;
}

void destroy_bytevector(unsigned char *bytevector) {
  if (bytevector) free(bytevector);
  bytevector = NULL;
}

char **create_strings(unsigned short int size) {
  char **strings = NULL;
  assert(strings = calloc(size, sizeof(unsigned char *)));
  return strings;
}

void destroy_strings(char **strings, unsigned short int size) {
  unsigned short int i = size;
  if (strings) {
    while (i--) if (strings[i]) free(strings[i]);
    free(strings);
  }
}

record *create_record(unsigned short int size, unsigned short int address, mode mode, unsigned char *bytecode, unsigned char checksum, record *old_record) {
  record *new_record = NULL;
  assert(new_record = malloc(sizeof(record)));

  new_record->size = size;
  new_record->address = address;
  new_record->mode = mode;

  new_record->bytecode = create_bytevector(size);
  memcpy(new_record->bytecode, bytecode, sizeof(unsigned char) * size);

  new_record->checksum = checksum;
  new_record->record = old_record;

  return new_record;
}

record *destroy_record(record *old_record) {
  record *new_record = NULL;
  if (old_record) {
    new_record = old_record->record;
    if (old_record->bytecode) free(old_record->bytecode);
    old_record->bytecode = NULL;
    free(old_record);
    old_record = NULL;
  } return new_record;
}
