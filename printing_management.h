// printing_management.h
 
#ifndef PRINTING_MANAGEMENT_H
  #define PRINTING_MANAGEMENT_H
  #include "instruction_set.h"
 
  static char *instructions[256];

  unsigned short int bytes_to_word(unsigned char, unsigned char);
  unsigned short int addr11_to_addr16(record *);
  extern void print_instruction(record *);
#endif
