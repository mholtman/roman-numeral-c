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

int const romanconverter_convertToInt(char * romanNumeral) {

  int convertedNum = 0;
  int i;

  for(i = 0; i < strlen(romanNumeral); i++)
  {
    if (strncmp(&romanNumeral[i], "I" , 1) == 0) {
      convertedNum += 1;
    } else if (strncmp(&romanNumeral[i], "V" , 1) == 0) {
      convertedNum += 5;
      convertedNum = adjustForPreviousChar(i, &romanNumeral[i - 1], "I", 2, convertedNum);
    } else if (strncmp(&romanNumeral[i], "X" , 1) == 0) {
      convertedNum += 10;
      convertedNum = adjustForPreviousChar(i, &romanNumeral[i - 1], "I", 2, convertedNum);
    } else if (strncmp(&romanNumeral[i], "L" , 1) == 0) {
      convertedNum += 50;
      convertedNum = adjustForPreviousChar(i, &romanNumeral[i - 1], "X", 20, convertedNum);
    } else if (strncmp(&romanNumeral[i], "C" , 1) == 0) {
      convertedNum += 100;
      convertedNum = adjustForPreviousChar(i, &romanNumeral[i - 1], "X", 20, convertedNum);
    } else if (strncmp(&romanNumeral[i], "D" , 1) == 0) {
      convertedNum += 500;
      convertedNum = adjustForPreviousChar(i, &romanNumeral[i - 1], "C", 200, convertedNum);
    } else if (strncmp(&romanNumeral[i], "M" , 1) == 0) {
      convertedNum += 1000;
      convertedNum = adjustForPreviousChar(i, &romanNumeral[i - 1], "C", 200, convertedNum);
    }
  }

  return convertedNum;
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

  char * romanToReturn = calloc(strlen(buffer + 1), sizeof(char));
  strcpy(romanToReturn, buffer);

  free(buffer);

  return romanToReturn;
}



int adjustForPreviousChar(int index, char * previous, char* check, int adjustment, int totalSoFar)
{
  if (index > 0 && strncmp(previous, check, 1) == 0)
  {
    totalSoFar -= adjustment;
  }

  return totalSoFar;
}
