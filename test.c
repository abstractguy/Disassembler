// test.c
 
#include "text_management.h"
 
int main(int argc, char *argv[]) {
  int i, size;
  char *array = NULL;
  record **records = NULL;
 
  assert(argc == 2);
  array = file_to_array(array, argv[1]);
  size = char_count(array, ':');
 
  records = reconstruct_records(array, size);
 
  for (i = 0; i < size; i++) {
    printf("size: %u, address: 0x%4.4X, ", records[i]->size, records[i]->address);
 
    switch (records[i]->mode) {
      case DATA: printf("record mode: DATA"); break;
      case END: printf("record mode: END");   break;
      case EXTENDED: printf("record mode: EXTENDED");
    }
 
    if (records[i]->size) {
      printf("\nbytecode: ");
      for (int j = 0; j < records[i]->size; j++) printf("%.2X", records[i]->bytecode[j]);
    }
 
    printf("\nchecksum: 0x%X\n\n", records[i]->checksum);
 
    destroy_record(records[i]);
  }
 
  printf("\n\n");
 
  free(array);
  free(records);
 
  return 0;
}
