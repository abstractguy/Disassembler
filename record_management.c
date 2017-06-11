// record_management.c
#include "record_management.h"

record *record_map(record *(*function)(record *), record *forward) {
  record *current, *backward = NULL;
  while ((current = forward)) {
    forward = forward->record;
    current = function(current);
    current->record = backward;
    backward = current;
  } return backward;
}

record *identity(record *record) {return record;}
 
record *reverse_records(record *record) {
  return record_map(identity, record);
}

record *copy_record_from_offset(record *records, unsigned short int size, unsigned short int offset, record *next) {
  return create_record(size, records->address + offset, records->mode, &records->bytecode[offset], records->checksum, next);
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

    records = create_record((unsigned short int)bytevector[0], bytes_to_word(bytevector[1], bytevector[2]), bytevector[3], &bytevector[4], bytevector[bytevector[0] + 4], records);

    destroy_bytevector(bytevector);
  }
 
  destroy_strings(strings, size);
  return align_instructions(records);
}
