// memory_management.h
 
#ifndef MEMORY_MANAGEMENT_H
  #define MEMORY_MANAGEMENT_H
  #include <stdlib.h>
  #include <assert.h>
  #include <string.h>

  typedef enum {DATA, END} mode;

  typedef struct Record {
    unsigned short int size, address;
    unsigned char *bytecode, checksum;
    mode mode;
    struct Record *record;
  } record;

  unsigned char *create_bytevector(unsigned short int);
  void destroy_bytevector(unsigned char *);

  char **create_strings(unsigned short int);
  void destroy_strings(char **, unsigned short int);

  record *create_record(unsigned short int, unsigned short int, mode, unsigned char *, unsigned char, record *);
  record *destroy_record(record *);
#endif
