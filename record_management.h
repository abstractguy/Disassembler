// record_management.h

#ifndef RECORD_MANAGEMENT_H
  #define RECORD_MANAGEMENT_H
  #include "string_management.h"

  record *record_map(record *(*f)(record *), record *);
  record *identity(record *);
  record *reverse_records(record *);

  record *copy_record_from_offset(record *, unsigned short int, unsigned short int, record *);
  record *align_instructions(record *);
  extern record *hex_file_to_records(char *);
#endif
