// main.c
#include "conversion_management.h"

int main(int argc, char *argv[]) {
  record *record = NULL;
  assert(argc == 2);
  record = hex_file_to_records(argv[1]);
  record = record_for_each(align_instruction, record);
  record = record_for_each(extract_instruction, record);
  while (record) {
    print_instruction(record);
    record = destroy_record(record);
  } return 0;
}
