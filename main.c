// main.c
#include "instruction_management.h"

int main(int argc, char *argv[]) {
  record *records = NULL;
  assert(argc == 2);
  records = hex_file_to_records(argv[1]);
  records = record_for_each(align_instruction, records);
  records = record_for_each(extract_instruction, records);
  while (records) {
    print_instruction(records);
    records = destroy_record(records);
  } return 0;
}
