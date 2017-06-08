// printing_management.h
 
#ifndef PRINTING_MANAGEMENT_H
  #define PRINTING_MANAGEMENT_H
  #include "instruction_set.h"
 
  static char *instructions[256];

  char **extract_arguments(record *);
  unsigned short int bytes_to_word(unsigned char, unsigned char);
  unsigned short int addr11_to_addr16(record *);
  void print_no_operands(record *);
  void print_word(unsigned short int);
  void print_byte(record *, unsigned char);
  void print_bytes(record *, unsigned char, unsigned char);
  void print_instruction(record *);
#endif
