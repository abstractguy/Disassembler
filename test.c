// test.c

#include "instruction_set.h"
 
int main(int argc, char *argv[]) {
  record *record = NULL, *temporary = NULL;
  assert(argc == 2);
  record = extract_instructions(argv[1]);
  while ((print_record(record)));
  record = destroy_all_records(record);
  return 0;
}
