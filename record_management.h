// record_management.h
#ifndef RECORD_MANAGEMENT_H
  #define RECORD_MANAGEMENT_H
  #include "string_management.h"

  typedef enum {DATA, END} mode;

  typedef struct Record {
    struct Record *next;
    unsigned short int size, address;
    unsigned char *bytecode;
    mode mode;
  } record;

  record *create_record(unsigned short int, unsigned short int, mode, unsigned char *, record *);
  record *destroy_record(record *);

  record *record_reverse_for_each(record *(*)(record *), record *);
  record *identity(record *);
  record *reverse_records(record *);

  record *copy_record_from_offset(record *, unsigned short int, unsigned short int, record *);
#endif
