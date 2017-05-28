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
 
  typedef struct RecordList {
    record *record;
    struct RecordList *record_list;
  } record_list;
 
  extern int char_count(char *, char);
  unsigned char ASCII_to_byte(char *);
  char **string_separate(char **, char *, char *);
  extern void destroy_array(char *);
  char **create_strings(char *, int);
  void destroy_strings(char **, int);
  record *create_record(unsigned char, unsigned short int, mode, unsigned char *, unsigned char);
  extern void destroy_record(record *);
  extern record_list *destroy_record_list(record_list *);
  record *build_record_from_string(char *);
  record_list *push_record(record *, record_list *);
  extern record_list *hex_file_to_record_list(char *);
  //record **reconstruct_records(char *, int);
#endif
