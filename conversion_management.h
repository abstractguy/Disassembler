// conversion_management.h
#ifndef CONVERSION_MANAGEMENT_H
  #define CONVERSION_MANAGEMENT_H
  #include <string.h>
  #include "instruction_management.h"

  record *hex_file_to_records(char *);
  record *align_instruction(record *);
  record *align_instructions(record *);
  record *extract_instruction(record *);
  record *extract_instructions(char *);
#endif
