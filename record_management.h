// record_management.h
 
#ifndef RECORD_MANAGEMENT_H
  #define RECORD_MANAGEMENT_H
  #include "text_management.h"

  typedef enum {
    DATA, END, EXTENDED
  } mode;
 
  typedef struct Record {
    unsigned char size, *bytecode, checksum;
    unsigned short int address;
    mode mode;
    struct Record *record;
  } record;

  record *build_record_from_string(char *, record *);
  record *create_record(unsigned char, unsigned short int, mode, unsigned char *, unsigned char, record *);
  extern record *destroy_record(record *);
  extern record *hex_file_to_records(char *);
  extern void print_record(record *);
#endif
