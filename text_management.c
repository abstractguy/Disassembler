// text_management.c

#include "text_management.h"

int char_count(char *string, char character) {
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
 
void destroy_array(char *array) {if (array) free(array);}

char **create_strings(char *array, int size) {
  char **strings = NULL;
  assert(strings = (char **)calloc(size, sizeof(char *)));
  strings = string_separate(strings, &array[1], "\r\n:");
  return strings;
}

void destroy_strings(char **strings, int size) {
  if (strings) {
    while (size--) if (strings[size]) free(strings[size]);
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
