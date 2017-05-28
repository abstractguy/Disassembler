// file_management.h
 
#ifndef FILE_MANAGEMENT_H
  #define FILE_MANAGEMENT_H
  #include <stdio.h>
  #include <stdlib.h>
  #include <assert.h>
 
  int file_size(FILE *);
  extern char *file_to_array(char *, char *);
#endif
