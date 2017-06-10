// record_management.c

#include "record_management.h"

char **string_separate(char *string, char *delimiters) {
  char *token = NULL, **strings = create_strings(char_count(string, ':'));

  if ((token = strtok(string, delimiters)))
    for (unsigned short int i = 0; token; i++, token = strtok(NULL, delimiters))
      strings[i] = strdup(token);
 
  return strings;
}
 
unsigned short int char_count(char *string, char character) {
  unsigned short int size = 0;
  for (unsigned short int i = 0; string[i]; i++) if (string[i] == character) size++;
  return size;
}
 
unsigned char ASCII_to_byte(char *ASCII) {
  char *string = (char *)create_bytevector(3);
  unsigned char byte;
  //copy_string((unsigned char *)string, (unsigned char *)ASCII);
  strncpy(string, ASCII, 2);
  byte = (unsigned char)strtoul(string, NULL, 16);
  destroy_bytevector((unsigned char *)string);
  return byte;
}

record *copy_record_from_offset(record *records, unsigned short int size, unsigned short int offset, record *next) {
  return create_record(size, records->address + offset, records->mode, &records->bytecode[offset], records->checksum, next);
}
 
record *reverse_records(record *forward) {
  record *backward = NULL, *next = NULL;
 
  while (forward) {
    next            = forward->record;
    forward->record = backward;
    backward        = forward;
    forward         = next;
  }
 
  return backward;
}

record *align_instructions(record *forward) {
  record *temporary = NULL, *backward = NULL;
  unsigned char *bytecode = NULL;
 
  while (forward) {
    if (forward->record && (forward->address + forward->size) == forward->record->address) {

      bytecode = create_bytevector(forward->size + forward->record->size);

      copy_bytes(bytecode, forward->bytecode, forward->size);
      copy_bytes(&bytecode[forward->size], forward->record->bytecode, forward->record->size);

      temporary = create_record(forward->size + forward->record->size, forward->address, forward->mode, bytecode, (unsigned char)(forward->checksum + forward->record->checksum), forward->record->record);

      destroy_bytevector(bytecode);

      forward = destroy_record(destroy_record(forward));
      forward = temporary;

    } else {

      if (forward->size) {
        backward = create_record(forward->size, forward->address, forward->mode, forward->bytecode, forward->checksum, backward);
      }
      forward = destroy_record(forward);
    }
  } return reverse_records(backward);
}
 
extern record *hex_file_to_records(char *file) {
  record *records = NULL;
  unsigned short int i, size = 0, substring_size;
  unsigned char *bytevector = NULL;
  char *array = NULL, **strings = NULL;
 
  array          = file_to_array(file);
  assert(   size = i = char_count(array, ':'));
  strings        = string_separate(array, "\r\n:");
 
  destroy_bytevector((unsigned char *)array);
 
  while (i--) {
 
    substring_size = strlen(strings[i]) / 2;
    bytevector     = create_bytevector(substring_size);
 
    for (unsigned short int j = 0; j < substring_size; j++) {
      bytevector[j] = ASCII_to_byte(&strings[i][j * 2]);
    }
 
    records = create_record((unsigned short int)bytevector[0], ((unsigned short int)bytevector[1] << 8) + (unsigned short int)bytevector[2], bytevector[3], &bytevector[4], bytevector[bytevector[0] + 4], records);
 
    destroy_bytevector(bytevector);
  }
 
  destroy_strings(strings, size);
 
  return align_instructions(records);
}
 
extern record *print_record(record *record) {
  printf("size: %u, address: 0x%4.4X, ", record->size, record->address);
 
  switch (record->mode) {
    case DATA: printf("record mode: DATA"); break;
    case END: printf("record mode: END");
  }
 
  if (record->size) {
    printf("\nbytecode: ");
    for (unsigned short int j = 0; j < record->size; j++)
      printf("%.2X", record->bytecode[j]);
  }
 
  printf("\nchecksum: 0x%X\n\n", record->checksum);
 
  return destroy_record(record);
}
