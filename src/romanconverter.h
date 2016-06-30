#ifndef _ROMAN_CONVERTER_H
#define _ROMAN_CONVERTER_H

#include <stdlib.h>

struct RomanConverter {

};

typedef struct RomanConverter RomanConverter;

RomanConverter * romanconverter_create();
void romanconverter_free(RomanConverter  * converter);

char * romanconverter_convertToRoman(int integer);

#endif
