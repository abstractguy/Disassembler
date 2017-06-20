// record_management.h
#ifndef RECORD_MANAGEMENT_H
  #define RECORD_MANAGEMENT_H
  #include "memory_management.h"

  typedef enum {DATA, END} mode;

  typedef struct Record {
    struct Record *next;
    unsigned short int size, address;
    unsigned char *bytecode;
    mode mode;
  } record;

  record *create_record(unsigned short int, unsigned short int, mode, unsigned char *, record *);
  record *destroy_record(record *);
  record *record_reverse(record *);
  record *record_for_each(record *(*)(record *), record *);
#endif
