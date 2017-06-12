// record_management.c
#include "record_management.h"

record *record_reverse_map(record *(*function)(record *), record *forward) {
  record *current, *backward = NULL;
  while ((current = function(forward))) {
    forward = current->next;
    current->next = backward;
    backward = current;
  } return backward;
}

record *identity(record *record) {return record;}
 
record *reverse_records(record *record) {
  return record_reverse_map(identity, record);
}

record *copy_record_from_offset(record *records, unsigned short int size, unsigned short int offset, record *next) {
  return create_record(size, records->address + offset, records->mode, &records->bytecode[offset], records->checksum, next);
}

record *align_instruction(record *forward) {
  record *temporary = NULL;
  unsigned char *bytecode = NULL;
 
  if (forward->next && (forward->address + forward->size) == forward->next->address) {
 
    bytecode = create_bytevector(forward->size + forward->next->size);

    copy_bytes(bytecode, forward->bytecode, forward->size);

    copy_bytes(&bytecode[forward->size], forward->next->bytecode, forward->next->size);
 
    temporary = create_record(forward->size + forward->next->size, forward->address, forward->mode, bytecode, (unsigned char)(forward->checksum + forward->next->checksum), forward->next->next);

      destroy_bytevector(bytecode);

      forward = destroy_record(destroy_record(forward));
 
      return align_instruction(temporary);
  } else {
    if (!forward->size) forward = destroy_record(forward);
    return forward;
  }
}
 
record *align_instructions(record *forward) {
  return reverse_records(record_reverse_map(align_instruction, forward));
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

    records = create_record((unsigned short int)bytevector[0], bytes_to_word(bytevector[1], bytevector[2]), bytevector[3], &bytevector[4], bytevector[bytevector[0] + 4], records);

    destroy_bytevector(bytevector);
  }
 
  destroy_strings(strings, size);
  return align_instructions(records);
}
