// record_management.c
#include "record_management.h"

record *create_record(unsigned short int size, unsigned short int address, unsigned char *bytecode, record *next) {
  record *new_record = NULL;
  assert(new_record = malloc(sizeof(record)));

  new_record->size     = size;
  new_record->address  = address;
  new_record->bytecode = bytecode;
  new_record->next     = next;

  return new_record;
}

record *destroy_record(record *r1) {
  record *r2 = NULL;
  if (r1) {
    r2 = r1->next;
    if (r1->bytecode) free(r1->bytecode);
    r1->bytecode = NULL;
    free(r1);
    r1 = NULL;
  } return r2;
}

static inline record *record_reverse_for_each(record *(*function)(record *), record *r1) {
  record *r2, *r3 = NULL;
  while ((r2 = function(r1))) {
    r1 = r2->next;
    r2->next = r3;
    r3 = r2;
  } return r3;
}

static inline record *identity(record *record) {return record;}

record *record_reverse(record *record) {
  return record_reverse_for_each(identity, record);
}

record *record_for_each(record *(*function)(record *), record *record) {
  return record_reverse(record_reverse_for_each(function, record));
}
