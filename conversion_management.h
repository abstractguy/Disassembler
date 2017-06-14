// conversion_management.h
#ifndef CONVERSION_MANAGEMENT_H
  #define CONVERSION_MANAGEMENT_H
  #include <string.h>
  #include "instruction_management.h"
  #include "file_management.h"

  unsigned short int char_count(char *, char);

  extern record *hex_file_to_records(char *);
  record *align_instructions(record *);
  record *extract_instructions(record *);
#endif
