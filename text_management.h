// text_management.h
 
#ifndef TEXT_MANAGEMENT_H
  #define TEXT_MANAGEMENT_H
  #include "file_management.h"
  #include <string.h>
 
  typedef enum {
    DATA, END, EXTENDED
  } mode;
 
  typedef struct {
    unsigned char size, *bytecode, checksum;
    unsigned short int address;
    mode mode;
  } record;
 
  extern int char_count(char *, char);
  unsigned char ASCII_to_byte(char *);
  char **string_separate(char **, char *, char *);
  extern void destroy_array(char *);
  char **create_strings(char *, int);
  void destroy_strings(char **, int);
  record *create_record(record *, unsigned char, unsigned short int, mode, unsigned char *, unsigned char);
  extern void destroy_record(record *);
  record *build_record_from_string(record *, char *);
  record **reconstruct_records(char *, int);
#endif
