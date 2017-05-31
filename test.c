// test.c

#include "instruction_set.h"

int main(int argc, char *argv[]) {
  record *record = NULL;

  assert(argc == 2);
  record = hex_file_to_records(argv[1]);
  //record = unroll_subrecord_addresses(record);

  do {print_record(record);} while ((record = destroy_record(record)));

  return 0;
}
