// file_management.c
#include "file_management.h"
 
int file_size(FILE * fp) {
  int end;
  fseek(fp, 0, SEEK_END);
  end = ftell(fp);
  rewind(fp);
  return end + 1;
}
 
extern char *file_to_array(char *array, char *file) {
  FILE *fp = NULL;
  int i = 0;
  assert(fp = fopen(file, "r"));
  assert(array = (char *)calloc(file_size(fp) + 1, sizeof(char)));
  do {array[i] = fgetc(fp);} while (array[i++] != EOF);
  array[i - 1] = '\0';
  assert(fclose(fp) != EOF);
  return array;
}
