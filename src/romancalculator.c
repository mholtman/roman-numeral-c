#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "integerconverter.h"
#include "romanconverter.h"


char * romanconverter_addition(char * firstNumber, char * secondNumber)
{
  return romanconverter_convertToRoman(integerconverter_convertToInt(firstNumber) + integerconverter_convertToInt(secondNumber));
}

char * romanconverter_subtraction(char * firstNumber, char * secondNumber)
{
  return romanconverter_convertToRoman(integerconverter_convertToInt(firstNumber) - integerconverter_convertToInt(secondNumber));
}
