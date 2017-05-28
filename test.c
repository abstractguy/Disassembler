// test.c
 
#include "text_management.h"
 
int main(int argc, char *argv[]) {
  record_list *_record_list = NULL;
  record *record = NULL;
 
  assert(argc == 2);

  _record_list = hex_file_to_record_list(argv[1]);

  do {
    record = _record_list->record;
    printf("size: %u, address: 0x%4.4X, ", record->size, record->address);
 
    switch (record->mode) {
      case DATA: printf("record mode: DATA"); break;
      case END: printf("record mode: END");   break;
      case EXTENDED: printf("record mode: EXTENDED");
    }
 
    if (record->size) {
      printf("\nbytecode: ");
      for (int j = 0; j < record->size; j++) printf("%.2X", record->bytecode[j]);
    }

    printf("\nchecksum: 0x%X\n\n", record->checksum);

    destroy_record(record);
  } while ((_record_list = destroy_record_list(_record_list)));

  printf("\n\n");

  return 0;
}
