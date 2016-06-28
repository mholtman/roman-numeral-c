#include "romanconverter.h"

RomanConverter * romanconverter_create() {
  struct RomanConverter *converter = malloc(sizeof(struct RomanConverter));

  return converter;
};

RomanConverter * romanconverter_free(RomanConverter * converter) {
    //free(converter);
}
