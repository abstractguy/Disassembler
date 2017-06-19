// conversion_management.h
#ifndef CONVERSION_MANAGEMENT_H
  #define CONVERSION_MANAGEMENT_H
  #include <string.h>
  #include "instruction_management.h"
  #include "file_management.h"

  #define RECORD_CHECKSUM (unsigned char)bytevector[bytevector[0] + 4]

  unsigned short int bytes_to_word(unsigned char, unsigned char);
  unsigned char instruction_size(unsigned char);
  unsigned short int addr11_to_addr16(record *);
  void print_instruction(record *);

  unsigned char ASCII_to_byte(char *);
  unsigned short int char_count(char *, char);

  extern record *hex_file_to_records(char *);
  record *align_instruction(record *);
  record *extract_instruction(record *);
#endif
