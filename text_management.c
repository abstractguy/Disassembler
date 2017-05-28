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
  assert(string = (char *)calloc(3, sizeof(char) * 3));
  strncpy(string, ASCII, 2);
  byte = (unsigned char)strtoul(string, NULL, 16);
  free(string);
  return byte;
}

char **string_separate(char **strings, char *string, char *delimiters) {
  int i = 1;
  char *token = NULL;

  if ((token = strtok(string, delimiters))) strings[0] = strdup(token);
  while ((token = strtok(NULL, delimiters))) strings[i++] = strdup(token);

  return strings;
}

record *build_record_from_string(record *fields, char *string) {
  unsigned char i, size = strlen(string) / 2, *bytevector = NULL;

  assert(bytevector = (unsigned char *)malloc(sizeof(unsigned char) * size));
  for (i = 0; i < size; i++) bytevector[i] = ASCII_to_byte(&string[i * 2]);

  fields->bytecode = NULL;
  assert(fields->bytecode = (unsigned char *)malloc(sizeof(unsigned char) * bytevector[0]));

  fields->size = bytevector[0];
  fields->address = ((unsigned short int)bytevector[1] << 8) + (unsigned short int)bytevector[2];
  fields->mode = bytevector[3];
  fields->checksum = bytevector[fields->size + 4];

  memcpy(fields->bytecode, &bytevector[4], bytevector[0]);

  free(bytevector);

  return fields;
}

record **reconstruct_records(char *array, int size) {
  char **strings = NULL;
  record **records = NULL;

  assert(strings = (char **)malloc(sizeof(char *) * size));
  assert(records = (record **)malloc(sizeof(record *) * size));

  strings = string_separate(strings, &array[1], "\r\n:");

  for (int i = 0; i < size; i++) {
    assert(records[i] = (record *)malloc(sizeof(record)));
    records[i] = build_record_from_string(records[i], strings[i]);
    free(strings[i]);
  }

  free(strings);

  return records;
}
