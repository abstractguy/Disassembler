// conversion_management.c
#include "conversion_management.h"

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

record *hex_file_to_records(char *file) {
  record *records = NULL;
  unsigned short int i, size = 0, substring_size;
  unsigned char *bytevector = NULL, *new_bytevector = NULL, file_checksum = 0;
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

    file_checksum += (unsigned char)bytevector[bytevector[0] + 4];
    if (bytevector[3]) {
      assert(!((unsigned char)file_checksum - bytevector[bytevector[0] + 4]));
    } checksum(bytevector);

    new_bytevector = create_bytevector(bytevector[0]);
    copy_bytes(new_bytevector, &bytevector[4], bytevector[0]);

    records = create_record((unsigned short int)bytevector[0], bytes_to_word(bytevector[1], bytevector[2]), bytevector[3], new_bytevector, records);

    destroy_bytevector(bytevector);
  }
 
  destroy_strings(strings, size);
  return records;
}

record *align_instruction(record *forward) {
  record *temporary = NULL;
  unsigned char *bytecode = NULL;
 
  if (forward->next && (forward->address + forward->size) == forward->next->address) {
    bytecode = create_bytevector(forward->size + forward->next->size);
    copy_bytes(bytecode, forward->bytecode, forward->size);
    copy_bytes(&bytecode[forward->size], forward->next->bytecode, forward->next->size);
    temporary = create_record(forward->size + forward->next->size, forward->address, forward->mode, bytecode, forward->next->next);
    forward = destroy_record(destroy_record(forward));
    return align_instruction(temporary);
  } else {
    if (!forward->size) forward = destroy_record(forward);
    return forward;
  }
}

record *align_instructions(record *record) {
  return record_for_each(align_instruction, record);
}

record *extract_instruction(record *forward) {
  record *backward = NULL;
  unsigned char size;

  if (forward) {
    size = instruction_size(forward->bytecode[0]);
    if (forward->size != size && forward->mode != END) {
      backward = copy_record_from_offset(forward, size, 0, copy_record_from_offset(forward, forward->size - size, size, forward->next));
      forward = destroy_record(forward);
      forward = backward;
    }
  } return forward;
}
 
record *extract_instructions(char *file) {
  return record_for_each(extract_instruction, align_instructions(hex_file_to_records(file)));
}
