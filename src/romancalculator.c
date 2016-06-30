#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "integerconverter.h"
#include "romanconverter.h"


int romancalculator_addition(char * firstNumber, char * secondNumber, char * romanNumeralOut)
{
  strcpy(romanNumeralOut, romanconverter_convertToRoman(integerconverter_convertToInt(firstNumber) + integerconverter_convertToInt(secondNumber)));

  return EXIT_SUCCESS;
}

char * romancalculator_subtraction(char * firstNumber, char * secondNumber)
{
  return romanconverter_convertToRoman(integerconverter_convertToInt(firstNumber) - integerconverter_convertToInt(secondNumber));
}
