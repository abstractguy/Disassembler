// conversion_management.h
#ifndef CONVERSION_MANAGEMENT_H
  #define CONVERSION_MANAGEMENT_H
  #include <string.h>
  #include "instruction_management.h"
  #include "file_management.h"

  void checksum(unsigned char *);
  char **string_separate(char *, char *);
  unsigned char ASCII_to_byte(char *);
  unsigned short int char_count(char *, char);

  record *hex_file_to_records(char *);
  record *align_instruction(record *);
  record *align_instructions(record *);
  record *extract_instruction(record *);
  record *extract_instructions(char *);
#endif
