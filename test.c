// test.c
#include "printing_management.h"

int main(int argc, char *argv[]) {
  record *record = NULL;
  assert(argc == 2);
  record = hex_file_to_records(argv[1]);
  record = align_instructions(record);
  record = extract_instructions(record);
  while (record) {
    print_instruction(record);
    record = destroy_record(record);
  } return 0;
}
