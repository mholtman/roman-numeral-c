#include <stdlib.h>
#include <check.h>
#include "check_romanconverter.h"

int main(void){
  int number_failed;
  Suite *romanSuite;
  Suite *integerSuite;
  Suite *operationsSuite;

  SRunner *sr;

  romanSuite = roman_suite();
  integerSuite = integer_suite();
  operationsSuite = operations_suite();
  sr = srunner_create(romanSuite);
  srunner_add_suite(sr, integerSuite);
  srunner_add_suite(sr, operationsSuite);


  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
