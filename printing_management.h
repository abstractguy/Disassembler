// printing_management.h
 
#ifndef PRINTING_MANAGEMENT_H
  #define PRINTING_MANAGEMENT_H
  #include "instruction_set.h"
 
  static char **mnemonics[256];

  // Prototypes de fonctions ici -->
  char **extract_arguments(record *);
  
  // <-- Fin prototypes de fonctions.
#endif
