// memory_management.h
#ifndef MEMORY_MANAGEMENT_H
  #define MEMORY_MANAGEMENT_H
  #include <stdlib.h>
  #include <assert.h>

  unsigned char *create_bytevector(unsigned short int);
  void destroy_bytevector(unsigned char *);
#endif
