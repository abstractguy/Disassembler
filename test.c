// test.c

#include "instruction_set.h"
 
int main(int argc, char *argv[]) {
  record *record = NULL;

  assert(argc == 2);

  record = hex_file_to_records(argv[1]);

  record = align_records(record);

  while (record) {
    record = extract_instruction(record);
    print_record(record);
    record = destroy_record(record);
  }

  return 0;
}
