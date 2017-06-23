// conversion_management.h
#ifndef CONVERSION_MANAGEMENT_H
  #define CONVERSION_MANAGEMENT_H
  #include "instruction_management.h"

  #define RECORD_CHECKSUM (unsigned char)bytevector[bytevector[0] + 4]

  record *hex_file_to_records(char *), *align_instruction(record *);
#endif
