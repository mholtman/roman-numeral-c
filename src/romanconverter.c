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

int const romanconverter_convert(char * romanNumeral) {

  int convertedNum = 0;
  int i;

  for(i = 0; i < strlen(romanNumeral); i++)
  {
    if (strncmp(&romanNumeral[i], "I" , 1) == 0) {
      convertedNum += 1;
    } else {
      convertedNum += 5;
    }
  }

  return convertedNum;
}
