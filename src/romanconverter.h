#ifndef _ROMAN_CONVERTER_H
#define _ROMAN_CONVERTER_H

struct RomanConverter {

};

typedef struct RomanConverter RomanConverter;

RomanConverter * romanconverter_create();
void romanconverter_free(RomanConverter  * converter);
int const romanconverter_convert(char * romanNumeral);

int adjustForPreviousChar(int index, char * previous, char* check, int adjustment, int totalSoFar);

#endif
