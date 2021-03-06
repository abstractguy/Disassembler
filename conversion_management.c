// conversion_management.c
#include "conversion_management.h"

static void checksum(unsigned char *bytevector) {
  unsigned char size = bytevector[0] + 4, sum = 0;
  for (unsigned char i = 0; i <= size; i++) sum += bytevector[i];
  assert(!sum);
}

static unsigned char ASCII_stream_to_byte(FILE *fp) {
  unsigned char string[3] = {'\0', '\0', '\0'};
  string[0] = (unsigned char)fgetc(fp);
  string[1] = (unsigned char)fgetc(fp);
  return (unsigned char)strtoul((char *)string, NULL, 16);
}

static unsigned char *file_pointer_to_record_bytevector(FILE *fp) {
  unsigned char *bytevector = NULL;
  unsigned short int size = ASCII_stream_to_byte(fp);
  bytevector = create_bytevector(5 + size);
  assert(((bytevector[0] = size)) <= 20);
  for (unsigned short int i = 1; i < size + 5; i++)
    bytevector[i] = ASCII_stream_to_byte(fp);
  return bytevector;
}

static record *bytevector_to_record(unsigned char *b1, record *r1) {
  unsigned short int size = b1[0];
  unsigned char *b2 = create_bytevector(b1[0]);
  copy_bytes(b2, &b1[4], size);
  return create_record(size, bytevector_to_word(b1), b2, r1);
}

static record *file_pointer_to_record(FILE *fp, record *r1) {
  record *r2 = NULL;
  unsigned char *bytevector = file_pointer_to_record_bytevector(fp);
  checksum(bytevector);
  r2 = bytevector_to_record(bytevector, r1);
  destroy_bytevector(bytevector);
  return r2;
}

static FILE *next_record_file_pointer(FILE * fp) {
  unsigned char i = 0;
  do {assert(++i < 4);} while (fgetc(fp) != ':' && !feof(fp));
  return fp;
}

record *hex_file_to_records(char *file) {
  record *record = NULL;
  FILE *fp = NULL;
  assert(fp = fopen(file, "r"));
  assert(!feof(fp = next_record_file_pointer(fp)));
  do {record = file_pointer_to_record(fp, record);
  } while (!feof(fp = next_record_file_pointer(fp)));
  fclose(fp);
  return record_reverse(destroy_record(record));
}

static inline record *record_concatenate(record *r1, record *r2) {
  unsigned char *b1 = create_bytevector(r1->size + r2->size);
  copy_bytes(b1, r1->bytecode, r1->size);
  copy_bytes(&b1[r1->size], r2->bytecode, r2->size);
  return create_record(r1->size + r2->size, r1->address, b1, r2->next);
}

record *align_instruction(record *r1) {
  record *r2 = NULL;
  if (r1) {
    if (r1->next && (r1->address + r1->size) == r1->next->address) {
      r2 = record_concatenate(r1, r1->next);
      r1 = destroy_record(destroy_record(r1));
      r1 = align_instruction(r2);
    } else if (!r1->size) r1 = destroy_record(r1);
  } return r1;
}
