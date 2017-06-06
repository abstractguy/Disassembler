// text_management.c

#include "text_management.h"

unsigned char *create_bytevector(unsigned short int size) {
  unsigned char *bytevector = NULL;
  assert(bytevector = calloc(size, sizeof(unsigned char)));
  return bytevector;
}

void destroy_bytevector(unsigned char *bytevector) {
  if (bytevector) free(bytevector);
  bytevector = NULL;
}

unsigned char *copy_bytevector(unsigned char *old_bytevector, unsigned short int size) {
  unsigned char *new_bytevector = create_bytevector(size);
  memcpy(new_bytevector, old_bytevector, sizeof(unsigned char) * size);
  return new_bytevector;
}

unsigned char *concatenate_bytevectors(unsigned char *bytevector1, unsigned short int size1, unsigned char *bytevector2, unsigned short int size2) {
  unsigned char *bytevector = create_bytevector(size1 + size2);
  memcpy(bytevector, bytevector1, size1);
  memcpy(&bytevector[size1], bytevector2, size2);
  return bytevector;
}

char **create_strings(unsigned short int size) {
  char **strings = NULL;
  assert(strings = calloc(size, sizeof(unsigned char *)));
  return strings;
}

void destroy_strings(char **strings, int size) {
  int i = size;
  if (strings) {
    while (i--) if (strings[i]) free(strings[i]);
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

char **separate_record_strings(char *array, int size) {
  return string_separate(create_strings(size), &array[1], "\r\n:");
}

int char_count(char *string, char character) {
  int size = 0;
  for (int i = 0; string[i]; i++) if (string[i] == character) size++;
  return size;
}

unsigned char ASCII_to_byte(char *ASCII) {
  char *string = (char *)create_bytevector(3);
  unsigned char byte;
  strncpy(string, ASCII, 2);
  byte = (unsigned char)strtoul(string, NULL, 16);
  destroy_bytevector((unsigned char *)string);
  return byte;
}
