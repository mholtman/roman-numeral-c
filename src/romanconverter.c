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
    } else if (strncmp(&romanNumeral[i], "V" , 1) == 0) {
      convertedNum += 5;
      if (i > 0 && strncmp(&romanNumeral[i - 1], "I", 1) == 0) {
        convertedNum -= 2;
      }
    } else if (strncmp(&romanNumeral[i], "X" , 1) == 0) {
      convertedNum += 10;
      if (i > 0 && strncmp(&romanNumeral[i - 1], "I", 1) == 0) {
        convertedNum -= 2;
      }
    }
  }

  return convertedNum;
}
