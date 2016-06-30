#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "romanconverter.h"

RomanConverter * romanconverter_create() {
  struct RomanConverter *converter = malloc(sizeof(struct RomanConverter));

  return converter;
}

void romanconverter_free(RomanConverter * converter) {
    free(converter);
    converter = NULL;
}

char * romanconverter_convertToRoman(int integerToConvert) {

  char * buffer = calloc(16, sizeof(char));

  double leftover = integerToConvert;

  char * buffer_ptr = buffer;

  while (leftover >= 1000)
  {
    *buffer_ptr = 'M';
    buffer_ptr++;
    leftover -= 1000;
  }

  while (leftover >= 900)
  {
    *buffer_ptr = 'C';
    buffer_ptr++;
    *buffer_ptr = 'M';
    buffer_ptr++;
    leftover -= 900;
  }

  while (leftover >= 500)
  {
    *buffer_ptr = 'D';
    buffer_ptr++;
    leftover -= 500;
  }

  while (leftover >= 400)
  {
    *buffer_ptr = 'C';
    buffer_ptr++;
    *buffer_ptr = 'D';
    buffer_ptr++;
    leftover -= 400;
  }

  while (leftover >= 100)
  {
    *buffer_ptr = 'C';
    buffer_ptr++;
    leftover -= 100;
  }

  while (leftover >= 90)
  {
    *buffer_ptr = 'X';
    buffer_ptr++;
    *buffer_ptr = 'C';
    buffer_ptr++;
    leftover -= 90;
  }

  while (leftover >= 50)
  {
    *buffer_ptr = 'L';
    buffer_ptr++;
    leftover -= 50;
  }

  while (leftover >= 40)
  {
    *buffer_ptr = 'X';
    buffer_ptr++;
    *buffer_ptr = 'L';
    buffer_ptr++;
    leftover -= 40;
  }

  while (leftover >= 10)
  {
    *buffer_ptr = 'X';
    buffer_ptr++;
    leftover -= 10;
  }

  while (leftover >= 9)
  {
    *buffer_ptr = 'I';
    buffer_ptr++;
    *buffer_ptr = 'X';
    buffer_ptr++;
    leftover -= 9;
  }

  while (leftover >= 5)
  {
    *buffer_ptr = 'V';
    buffer_ptr++;
    leftover -= 5;
  }

  while (leftover >= 4)
  {
    *buffer_ptr = 'I';
    buffer_ptr++;
    *buffer_ptr = 'V';
    buffer_ptr++;
    leftover -= 4;
  }

  while (leftover >= 1)
  {
    *buffer_ptr = 'I';
    buffer_ptr++;
    leftover -= 1;
  }

  char * romanToReturn = calloc(strlen(buffer + 1), sizeof(char));
  strcpy(romanToReturn, buffer);

  free(buffer);

  return romanToReturn;
}
