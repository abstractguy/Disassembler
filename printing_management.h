// printing_management.h
 
#ifndef PRINTING_MANAGEMENT_H
  #define PRINTING_MANAGEMENT_H
  #include "instruction_set.h"
 
  static char **mnemonics[256];

  char **extract_arguments(record *);
  unsigned char *bytevector_to_string(unsigned char *, unsigned char);
  unsigned char *record_to_string(record *);
  void print_instruction(record *);
#endif
