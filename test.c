// test.c

#include "instruction_set.h"
 
int main(int argc, char *argv[]) {
  record *record = NULL;
  assert(argc == 2);
  record = extract_instructions(argv[1]);
  do {print_record(record);} while ((record = destroy_record(record)));
  return 0;
}
