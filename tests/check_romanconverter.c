#include <stdlib.h>
#include <check.h>
#include "../src/romanconverter.h"

START_TEST(test_roman_converter_create)
 {
     RomanConverter *converter;

     converter = romanconverter_create();

     ck_assert_msg(NULL != converter, "Converter not created! Failure!");

     romanconverter_free(converter);
 }
 END_TEST


Suite * roman_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("Roman");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_roman_converter_create);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = roman_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
