// string_management.c
#include "string_management.h"

void checksum(unsigned char *bytevector) {
  unsigned char size = bytevector[0] + 4, sum = 0;
  if (!bytevector[3]) {
    for (unsigned char i = 0; i < size; i++) {
      sum = (unsigned char)(sum + bytevector[i]) % 256;
    } assert(!((unsigned char)(~sum + 1) - bytevector[size]));
  }
}

char **string_separate(char *string, char *delimiters) {
  char *token = NULL, **strings = create_strings(char_count(string, ':'));

  if ((token = strtok(string, delimiters))) {
    for (unsigned short int i = 0; token; i++, token = strtok(NULL, delimiters)) {
      strings[i] = strdup(token);
    }
  } return strings;
}
 
unsigned short int char_count(char *string, char character) {
  unsigned short int size = 0;
  for (unsigned short int i = 0; string[i]; i++) {
    if (string[i] == character) size++;
  } return size;
}
 
unsigned char ASCII_to_byte(char *ASCII) {
  char *string = (char *)create_bytevector(3);
  unsigned char byte;
  //copy_bytes((unsigned char *)string, (unsigned char *)ASCII, 3);
  strncpy(string, ASCII, 2);
  byte = (unsigned char)strtoul(string, NULL, 16);
  destroy_bytevector((unsigned char *)string);
  return byte;
}
