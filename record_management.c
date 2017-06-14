// record_management.c
#include "record_management.h"

record *create_record(unsigned short int size, unsigned short int address, mode mode, unsigned char *bytecode, record *old_record) {
  record *new_record = NULL;
  assert(new_record = malloc(sizeof(record)));

  new_record->size     = size;
  new_record->address  = address;
  new_record->mode     = mode;
  new_record->bytecode = bytecode;
  new_record->next     = old_record;

  return new_record;
}

record *destroy_record(record *old_record) {
  record *new_record = NULL;
  if (old_record) {
    new_record = old_record->next;
    if (old_record->bytecode) free(old_record->bytecode);
    old_record->bytecode = NULL;
    free(old_record);
    old_record = NULL;
  } return new_record;
}

static record *record_reverse_for_each(record *(*function)(record *), record *forward) {
  record *current, *backward = NULL;
  while ((current = function(forward))) {
    forward = current->next;
    current->next = backward;
    backward = current;
  } return backward;
}

static record *identity(record *record) {return record;}

record *record_for_each(record *(*function)(record *), record *record) {
  return record_reverse_for_each(identity, record_reverse_for_each(function, record));
}

record *copy_record_from_offset(record *records, unsigned short int size, unsigned short int offset, record *next) {
  unsigned char *bytecode = create_bytevector(size);
  copy_bytes(bytecode, &records->bytecode[offset], size);
  return create_record(size, records->address + offset, records->mode, bytecode, next);
}
