// record_management.h

#ifndef RECORD_MANAGEMENT_H
  #define RECORD_MANAGEMENT_H
  #include "file_management.h"
  #include "text_management.h"

  record *copy_record_from_offset(record *, unsigned short int, unsigned short int, record *);
  record *reverse_records(record *);
  record *align_instructions(record *);
  extern record *hex_file_to_records(char *);
  extern record *print_record(record *);
#endif
