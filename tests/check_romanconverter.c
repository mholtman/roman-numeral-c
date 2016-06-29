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
   ck_assert_int_eq(romanconverter_convertToInt("I"), 1);
 }
END_TEST

START_TEST(test_can_convert_II_to_2)
{
  ck_assert_int_eq(romanconverter_convertToInt("II"), 2);
}
END_TEST

START_TEST(test_can_convert_V_to_5)
{
  ck_assert_int_eq(romanconverter_convertToInt("V"), 5);
}
END_TEST

START_TEST(test_can_convert_IV_to_4)
{
  ck_assert_int_eq(romanconverter_convertToInt("IV"), 4);
}
END_TEST

START_TEST(test_can_convert_VIII_to_8)
{
  ck_assert_int_eq(romanconverter_convertToInt("VIII"), 8);
}
END_TEST

START_TEST(test_can_convert_X_to_10)
{
  ck_assert_int_eq(romanconverter_convertToInt("X"), 10);
}
END_TEST

START_TEST(test_can_convert_IX_to_9)
{
  ck_assert_int_eq(romanconverter_convertToInt("IX"), 9);
}
END_TEST

START_TEST(test_can_convert_XLIX_to_49)
{
  ck_assert_int_eq(romanconverter_convertToInt("XLIX"), 49);
}
END_TEST

START_TEST(test_can_convert_XCIX_to_99)
{
  ck_assert_int_eq(romanconverter_convertToInt("XCIX"), 99);
}
END_TEST

START_TEST(test_can_convert_CDXCIX_to_499)
{
  ck_assert_int_eq(romanconverter_convertToInt("CDXCIX"), 499);
}
END_TEST

START_TEST(test_can_convert_CMXCIX_to_999)
{
  ck_assert_int_eq(romanconverter_convertToInt("CMXCIX"), 999);
}
END_TEST

START_TEST(test_can_convert_MCMLXXVI_to_1976)
{
  ck_assert_int_eq(romanconverter_convertToInt("MCMLXXVI"), 1976);
}
END_TEST


Suite * roman_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("RomanToInteger");

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
  tcase_add_test(tc_core, test_can_convert_CDXCIX_to_499);
  tcase_add_test(tc_core, test_can_convert_CMXCIX_to_999);
  tcase_add_test(tc_core, test_can_convert_MCMLXXVI_to_1976);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_can_convert_3000_to_MMM)
{
  char * actual = romanconverter_convertToRoman(3000);

  ck_assert_str_eq(actual, "MMM");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3900_to_MMMCM)
{
  char * actual = romanconverter_convertToRoman(3900);

  ck_assert_str_eq(actual, "MMMCM");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3500_to_MMMD)
{
  char * actual = romanconverter_convertToRoman(3500);

  ck_assert_str_eq(actual, "MMMD");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3400_to_MMMCD)
{
  char * actual = romanconverter_convertToRoman(3400);

  ck_assert_str_eq(actual, "MMMCD");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3300_to_MMMCCC)
{
  char * actual = romanconverter_convertToRoman(3300);

  ck_assert_str_eq(actual, "MMMCCC");

  free(actual);
}
END_TEST

Suite * integer_suite(void)
{
  Suite *s;
  TCase *tc_basic;

  s = suite_create("IntegerToRoman");

  tc_basic = tcase_create("Basic");

  tcase_add_test(tc_basic, test_can_convert_3000_to_MMM);
  tcase_add_test(tc_basic, test_can_convert_3900_to_MMMCM);
  tcase_add_test(tc_basic, test_can_convert_3500_to_MMMD);
  tcase_add_test(tc_basic, test_can_convert_3400_to_MMMCD);
  tcase_add_test(tc_basic, test_can_convert_3300_to_MMMCCC);

  suite_add_tcase(s, tc_basic);

  return s;

}

int main(void){
  int number_failed;
  Suite *s;
  Suite *intToRoman;

  SRunner *sr;

  s = roman_suite();
  intToRoman = integer_suite();
  sr = srunner_create(s);
  srunner_add_suite(sr, intToRoman);


  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
