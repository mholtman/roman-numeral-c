#ifndef _ROMAN_CONVERTER_H
#define _ROMAN_CONVERTER_H

struct RomanConverter {

};

typedef struct RomanConverter RomanConverter;

RomanConverter * romanconverter_create();
void romanconverter_free(RomanConverter  * converter);

#endif
