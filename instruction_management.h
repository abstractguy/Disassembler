// instruction_management.h
#ifndef INSTRUCTION_MANAGEMENT_H
  #define INSTRUCTION_MANAGEMENT_H
  #include "record_management.h"
  #include <stdio.h>

  typedef enum {
    ONE_BYTE_INSTRUCTION, ADDR_11, DIRECT, IMMEDIATE,
    OFFSET, BIT, NOT_BIT, ADDR_16, IMMEDIATE_16, BIT_OFFSET,
    DIRECT_IMMEDIATE, DIRECT_DIRECT, IMMEDIATE_OFFSET, DIRECT_OFFSET
  } instruction_type;

  unsigned short int bytevector_to_word(unsigned char *);
  void print_instruction(record *);
  void copy_bytes(unsigned char *, unsigned char *, unsigned short int);
  record *extract_instruction(record *);
#endif
