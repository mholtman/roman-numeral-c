#include <stdlib.h>
#include <string.h>
#include "integerconverter.h"
#include "romanconverter.h"

int romancalculator_addition(char * firstNumber, char * secondNumber, char * romanNumeralOut)
{
  strncpy(romanNumeralOut, romanconverter_convertToRoman(integerconverter_convertToInt(firstNumber) + integerconverter_convertToInt(secondNumber)), 16);

  return EXIT_SUCCESS;
}

int romancalculator_subtraction(char * firstNumber, char * secondNumber, char * romanNumeralOut)
{
  strncpy(romanNumeralOut, romanconverter_convertToRoman(integerconverter_convertToInt(firstNumber) - integerconverter_convertToInt(secondNumber)), 16);

  return EXIT_SUCCESS;
}
