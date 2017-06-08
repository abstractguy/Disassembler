// file_management.c
#include "file_management.h"

unsigned short int file_size(FILE * fp) {
  unsigned short int end;
  fseek(fp, 0, SEEK_END);
  end = ftell(fp);
  rewind(fp);
  return end + 1;
}

char *file_to_array(char *file) {
  char *array = NULL;
  FILE *fp = NULL;
  unsigned short int i = 0;
  assert(fp = fopen(file, "r"));
  array = (char *)create_bytevector(file_size(fp) + 1);
  do {array[i] = fgetc(fp);} while (array[i++] != EOF);
  array[i - 1] = '\0';
  assert(fclose(fp) != EOF);
  return array;
}
