#include <stdlib.h>
#include <string.h>

#include "integerconverter.h"

static int adjustForPreviousChar(int index, char previous, char check, int adjustment, int totalSoFar)
{
  if (index > 0 && previous == check)
  {
    totalSoFar -= adjustment;
  }

  return totalSoFar;
}

int const romanconverter_convertToInt(char * romanNumeral) {

  int convertedNum = 0;
  int i;

  for(i = 0; i < strlen(romanNumeral); i++)
  {
    if (romanNumeral[i] == 'I') {
      convertedNum += 1;
    } else if (romanNumeral[i] == 'V') {
      convertedNum += 5;
      convertedNum = adjustForPreviousChar(i, romanNumeral[i - 1], 'I', 2, convertedNum);
    } else if (romanNumeral[i] == 'X') {
      convertedNum += 10;
      convertedNum = adjustForPreviousChar(i, romanNumeral[i - 1], 'I', 2, convertedNum);
    } else if (romanNumeral[i] == 'L') {
      convertedNum += 50;
      convertedNum = adjustForPreviousChar(i, romanNumeral[i - 1], 'X', 20, convertedNum);
    } else if (romanNumeral[i] == 'C') {
      convertedNum += 100;
      convertedNum = adjustForPreviousChar(i, romanNumeral[i - 1], 'X', 20, convertedNum);
    } else if (romanNumeral[i] == 'D') {
      convertedNum += 500;
      convertedNum = adjustForPreviousChar(i, romanNumeral[i - 1], 'C', 200, convertedNum);
    } else if (romanNumeral[i] == 'M') {
      convertedNum += 1000;
      convertedNum = adjustForPreviousChar(i, romanNumeral[i - 1], 'C', 200, convertedNum);
    }
  }

  return convertedNum;
}
