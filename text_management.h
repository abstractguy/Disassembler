// text_management.h

#ifndef TEXT_MANAGEMENT_H
  #define TEXT_MANAGEMENT_H
  #include "file_management.h"
  #include <string.h>

  unsigned char *create_bytevector(unsigned short int);
  void destroy_bytevector(unsigned char *);
  unsigned char *copy_bytevector(unsigned char *, unsigned short int);
  unsigned char *concatenate_bytevectors(unsigned char *, unsigned short int, unsigned char *, unsigned short int);

  char **create_strings(unsigned short int);
  void destroy_strings(char **, unsigned short int);
  char **string_separate(char *, char *);

  unsigned char ASCII_to_byte(char *);
  unsigned short int char_count(char *, char);
#endif
