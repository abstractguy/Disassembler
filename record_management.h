// record_management.h

#ifndef RECORD_MANAGEMENT_H
  #define RECORD_MANAGEMENT_H
  #include <string.h>
  #include "memory_management.h"
  #include "file_management.h"

  char **string_separate(char *, char *);
  unsigned char ASCII_to_byte(char *);
  unsigned short int char_count(char *, char);

  record *copy_record_from_offset(record *, unsigned short int, unsigned short int, record *);
  record *reverse_records(record *);
  record *align_instructions(record *);
  extern record *hex_file_to_records(char *);
  extern record *print_record(record *);
#endif
