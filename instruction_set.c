// instruction_set.c

#include "instruction_set.h"

record *extract_instructions(char *file) {
  record *forward  = hex_file_to_records(file);
  record *backward = NULL, *next = NULL;
  unsigned char size;

  while (forward) {
    size = instruction_size(forward->bytecode[0]);
    if (forward->size != size && forward->mode != END) {

      next = copy_record_from_offset(forward, forward->size - size, size, forward->record);

      backward = copy_record_from_offset(forward, size, 0, backward);

      forward = destroy_record(forward);
    } else {
      next            = forward->record;
      forward->record = backward;
      backward        = forward;
    }

    forward = next;
  }

  return reverse_records(backward);
}
