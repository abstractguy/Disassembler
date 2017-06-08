// test.c
 
#include "printing_management.h"
 
int main(int argc, char *argv[]) {
  record *record = NULL;
  assert(argc == 2);
  record = extract_instructions(argv[1]);
  while (record) record = print_record(record);
  return 0;
}
