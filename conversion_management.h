// conversion_management.h
#ifndef CONVERSION_MANAGEMENT_H
  #define CONVERSION_MANAGEMENT_H
  #include <string.h>
  #include "instruction_management.h"
  #include "file_management.h"

  #define RECORD_CHECKSUM (unsigned char)bytevector[bytevector[0] + 4]

  void print_instruction(record *);
  extern record *hex_file_to_records(char *);
  record *align_instruction(record *);
  record *extract_instruction(record *);
#endif
