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
 
  assert(strings = (char **)calloc(size, sizeof(char *)));
 
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
 
record *create_record(unsigned char size, unsigned short int address, mode mode, unsigned char *bytecode, unsigned char checksum) {
  record *_record = NULL;
 
  assert(_record = (record *)calloc(1, sizeof(record)));
 
  _record->bytecode = NULL;
 
  assert(_record->bytecode = (unsigned char *)calloc(size, sizeof(unsigned char)));
 
  _record->size = size;
  _record->address = address;
  _record->mode = mode;
  memcpy(_record->bytecode, bytecode, size);
  _record->checksum = checksum;
 
  return _record;
}
 
extern void destroy_record(record *record) {
  if (record) {
    if (record->bytecode) free(record->bytecode);
    free(record);
  }
}
 
record *build_record_from_string(char *string) {
  record *record = NULL;
  unsigned char i, size = strlen(string) / 2, *bytevector = NULL;
 
  assert(bytevector = (unsigned char *)calloc(size, sizeof(unsigned char)));
 
  for (i = 0; i < size; i++) bytevector[i] = ASCII_to_byte(&string[i * 2]);
 
  record = create_record(bytevector[0], ((unsigned short int) bytevector[1] << 8) + (unsigned short int) bytevector[2], bytevector[3], &bytevector[4], bytevector[bytevector[0] + 4]);
 
  free(bytevector);
 
  return record;
}

record_list *push_record(record *record, record_list *_record_list) {
  record_list *new_record = NULL;

  assert(new_record = (record_list *)calloc(1, sizeof(record_list)));
 
  new_record->record = record;
  new_record->record_list = _record_list;
 
  return new_record;
}
 
extern record_list *destroy_record_list(record_list *_record_list) {
  record_list *next_record = NULL;

  if (_record_list) {
    next_record = _record_list->record_list;
    free(_record_list);
  }

  return next_record;
}
 
extern record_list *hex_file_to_record_list(char *file) {
  record_list *record_list = NULL;
  char *array = NULL, **strings = NULL;
  int size;
 
  array = file_to_array(array, file);
 
  size = char_count(array, ':');
 
  assert(size);
 
  strings = create_strings(array, size);
 
  do {record_list = push_record(build_record_from_string(strings[--size]), record_list);} while (size);
 
  destroy_array(array);
  destroy_strings(strings, size);
 
  return record_list;
}
