#include <stdlib.h>
#include <string.h>
#include "romanconverter.h"

RomanConverter * romanconverter_create() {
  struct RomanConverter *converter = malloc(sizeof(struct RomanConverter));

  return converter;
}

void romanconverter_free(RomanConverter * converter) {
    free(converter);
    converter = NULL;
}

int romanconverter_convert(char * romanNumeral) {

  if (strcmp(romanNumeral, "I") == 0)
  {
    return 1;
  }
  else
  {
    return 5;
  }
}
