// text_management.c
 
#include "text_management.h"
 
extern int char_count(char *string, char character) {
  int size = 0;
  for (int i = 0; string[i]; i++) if (string[i] == character) size++;
  return size;
}
 
unsigned char ASCII_to_byte(char *ASCII) {
  char *string = NULL;
  unsigned char byte;
  assert(string = (char *)calloc(3, sizeof(char)));
  strncpy(string, ASCII, 2);
  byte = (unsigned char)strtoul(string, NULL, 16);
  free(string);
  return byte;
}
 
extern void destroy_array(char *array) {if (array) free(array);}
 
char **create_strings(char *array, int size) {
  char **strings = NULL;
 
  assert(strings = (char **)malloc(sizeof(char *) * size));
 
  strings = string_separate(strings, &array[1], "\r\n:");
 
  return strings;
}
 
void destroy_strings(char **strings, int size) {
  if (strings) {
    while (size--) free(strings[size]);
    free(strings);
  }
}
 
char **string_separate(char **strings, char *string, char *delimiters) {
  int i = 1;
  char *token = NULL;
 
  if ((token = strtok(string, delimiters))) strings[0] = strdup(token);
  while ((token = strtok(NULL, delimiters))) strings[i++] = strdup(token);
 
  return strings;
}
 
record *create_record(record *record, unsigned char size, unsigned short int address, mode mode, unsigned char *bytecode, unsigned char checksum) {
  //record *record = NULL;
 
  //assert(record = (record *)malloc(sizeof(record)));
 
  record->bytecode = NULL;
 
  assert(record->bytecode = (unsigned char *)malloc(sizeof(unsigned char) * size));
 
  record->size = size;
  record->address = address;
  record->mode = mode;
  memcpy(record->bytecode, bytecode, size);
  record->checksum = checksum;
 
  return record;
}
 
extern void destroy_record(record *record) {
  if (record) {
    if (record->bytecode) free(record->bytecode);
    free(record);
  }
}
 
record *build_record_from_string(record *record, char *string) {
  unsigned char i, size = strlen(string) / 2, *bytevector = NULL;
 
  assert(bytevector = (unsigned char *)calloc(size, sizeof(unsigned char)));
 
  for (i = 0; i < size; i++) bytevector[i] = ASCII_to_byte(&string[i * 2]);
 
  record = create_record(record, bytevector[0], ((unsigned short int) bytevector[1] << 8) + (unsigned short int) bytevector[2], bytevector[3], &bytevector[4], bytevector[bytevector[0] + 4]);
 
  free(bytevector);
 
  return record;
}
 
record **reconstruct_records(char *array, int size) {
  char **strings = NULL;
  record **records = NULL;
 
  strings = create_strings(array, size);
 
  //assert(strings = (char **)malloc(sizeof(char *) * size));
 
  //assert(records = (record **)malloc(sizeof(record *)));
 
  assert(records = (record **)malloc(sizeof(record *) + sizeof(record) * size));
 
  //strings = string_separate(strings, &array[1], "\r\n:");
 
  for (int i = 0; i < size; i++) {
    assert(records[i] = (record *)malloc(sizeof(record)));
    records[i] = build_record_from_string(records[i], strings[i]);
    //free(strings[i]);
  }
 
  //free(strings);
 
  destroy_strings(strings, size);
 
  return records;
}
