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

 START_TEST(test_roman_converter_destroy)
 {
   RomanConverter *converter;

   converter = romanconverter_create();

   romanconverter_free(converter);

   ck_assert_msg(NULL == converter, "Converter not destroyed! Oh Nooos!");
 }
 END_TEST

 START_TEST(test_can_convert_I_to_1)
 {
   ck_assert_int_eq(romanconverter_convert("I"), 1);
 }
END_TEST

START_TEST(test_can_convert_II_to_2)
{
  ck_assert_int_eq(romanconverter_convert("II"), 2);
}
END_TEST

START_TEST(test_can_convert_V_to_5)
{
  ck_assert_int_eq(romanconverter_convert("V"), 5);
}
END_TEST

START_TEST(test_can_convert_IV_to_4)
{
  ck_assert_int_eq(romanconverter_convert("IV"), 4);
}
END_TEST

START_TEST(test_can_convert_VIII_to_8)
{
  ck_assert_int_eq(romanconverter_convert("VIII"), 8);
}
END_TEST

START_TEST(test_can_convert_X_to_10)
{
  ck_assert_int_eq(romanconverter_convert("X"), 10);
}
END_TEST

START_TEST(test_can_convert_IX_to_9)
{
  ck_assert_int_eq(romanconverter_convert("IX"), 9);
}
END_TEST

START_TEST(test_can_convert_XLIX_to_49)
{
  ck_assert_int_eq(romanconverter_convert("XLIX"), 49);
}
END_TEST

START_TEST(test_can_convert_XCIX_to_99)
{
  ck_assert_int_eq(romanconverter_convert("XCIX"), 99);
}
END_TEST

Suite * roman_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("RomanToArabic");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_roman_converter_create);
  //tcase_add_test(tc_core, test_roman_converter_destroy);
  tcase_add_test(tc_core, test_can_convert_I_to_1);
  tcase_add_test(tc_core, test_can_convert_II_to_2);
  tcase_add_test(tc_core, test_can_convert_V_to_5);
  tcase_add_test(tc_core, test_can_convert_IV_to_4);
  tcase_add_test(tc_core, test_can_convert_VIII_to_8);
  tcase_add_test(tc_core, test_can_convert_X_to_10);
  tcase_add_test(tc_core, test_can_convert_IX_to_9);
  tcase_add_test(tc_core, test_can_convert_XLIX_to_49);
  tcase_add_test(tc_core, test_can_convert_XCIX_to_99);
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
