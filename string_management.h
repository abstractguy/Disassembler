// string_management.h
#ifndef STRING_MANAGEMENT_H
  #define STRING_MANAGEMENT_H
  #include <string.h>
  #include "memory_management.h"
  #include "file_management.h"

  void checksum(unsigned char *);
  char **string_separate(char *, char *);
  unsigned char ASCII_to_byte(char *);
  unsigned short int char_count(char *, char);
#endif
