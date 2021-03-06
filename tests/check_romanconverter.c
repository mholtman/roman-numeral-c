#include <stdlib.h>
#include <check.h>
#include "check_romanconverter.h"
#include "../src/romanconverter.h"
#include "../src/integerconverter.h"
#include "../src/romancalculator.h"

START_TEST(test_can_convert_I_to_1)
 {
   ck_assert_int_eq(integerconverter_convertToInt("I"), 1);
 }
END_TEST

START_TEST(test_can_convert_II_to_2)
{
  ck_assert_int_eq(integerconverter_convertToInt("II"), 2);
}
END_TEST

START_TEST(test_can_convert_V_to_5)
{
  ck_assert_int_eq(integerconverter_convertToInt("V"), 5);
}
END_TEST

START_TEST(test_can_convert_IV_to_4)
{
  ck_assert_int_eq(integerconverter_convertToInt("IV"), 4);
}
END_TEST

START_TEST(test_can_convert_VIII_to_8)
{
  ck_assert_int_eq(integerconverter_convertToInt("VIII"), 8);
}
END_TEST

START_TEST(test_can_convert_X_to_10)
{
  ck_assert_int_eq(integerconverter_convertToInt("X"), 10);
}
END_TEST

START_TEST(test_can_convert_IX_to_9)
{
  ck_assert_int_eq(integerconverter_convertToInt("IX"), 9);
}
END_TEST

START_TEST(test_can_convert_XLIX_to_49)
{
  ck_assert_int_eq(integerconverter_convertToInt("XLIX"), 49);
}
END_TEST

START_TEST(test_can_convert_XCIX_to_99)
{
  ck_assert_int_eq(integerconverter_convertToInt("XCIX"), 99);
}
END_TEST

START_TEST(test_can_convert_CDXCIX_to_499)
{
  ck_assert_int_eq(integerconverter_convertToInt("CDXCIX"), 499);
}
END_TEST

START_TEST(test_can_convert_CMXCIX_to_999)
{
  ck_assert_int_eq(integerconverter_convertToInt("CMXCIX"), 999);
}
END_TEST

START_TEST(test_can_convert_MCMLXXVI_to_1976)
{
  ck_assert_int_eq(integerconverter_convertToInt("MCMLXXVI"), 1976);
}
END_TEST


Suite * roman_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("RomanToInteger");

  /* Core test case */
  tc_core = tcase_create("Core");

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

START_TEST(test_can_convert_3390_to_MMMCCCXC)
{
  char * actual = romanconverter_convertToRoman(3390);

  ck_assert_str_eq(actual, "MMMCCCXC");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3350_to_MMMCCCL)
{
  char * actual = romanconverter_convertToRoman(3350);

  ck_assert_str_eq(actual, "MMMCCCL");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3340_to_MMMCCCXL)
{
  char * actual = romanconverter_convertToRoman(3340);

  ck_assert_str_eq(actual, "MMMCCCXL");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3330_to_MMMCCCXXX)
{
  char * actual = romanconverter_convertToRoman(3330);

  ck_assert_str_eq(actual, "MMMCCCXXX");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3339_to_MMMCCCXXXIX)
{
  char * actual = romanconverter_convertToRoman(3339);

  ck_assert_str_eq(actual, "MMMCCCXXXIX");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3335_to_MMMCCCXXXV)
{
  char * actual = romanconverter_convertToRoman(3335);

  ck_assert_str_eq(actual, "MMMCCCXXXV");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3334_to_MMMCCCXXXIV)
{
  char * actual = romanconverter_convertToRoman(3334);

  ck_assert_str_eq(actual, "MMMCCCXXXIV");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3333_to_MMMCCCXXXIII)
{
  char * actual = romanconverter_convertToRoman(3333);

  ck_assert_str_eq(actual, "MMMCCCXXXIII");

  free(actual);
}
END_TEST

START_TEST(test_can_convert_3888_to_MMMDCCCLXXXVIII)
{
  char * actual = romanconverter_convertToRoman(3888);

  ck_assert_str_eq(actual, "MMMDCCCLXXXVIII");

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
  tcase_add_test(tc_basic, test_can_convert_3390_to_MMMCCCXC);
  tcase_add_test(tc_basic, test_can_convert_3350_to_MMMCCCL);
  tcase_add_test(tc_basic, test_can_convert_3340_to_MMMCCCXL);
  tcase_add_test(tc_basic, test_can_convert_3330_to_MMMCCCXXX);
  tcase_add_test(tc_basic, test_can_convert_3339_to_MMMCCCXXXIX);
  tcase_add_test(tc_basic, test_can_convert_3335_to_MMMCCCXXXV);
  tcase_add_test(tc_basic, test_can_convert_3334_to_MMMCCCXXXIV);
  tcase_add_test(tc_basic, test_can_convert_3333_to_MMMCCCXXXIII);
  tcase_add_test(tc_basic, test_can_convert_3888_to_MMMDCCCLXXXVIII);

  suite_add_tcase(s, tc_basic);

  return s;

}

START_TEST(test_can_add_two_numbers)
{
  char actual[16];
  romancalculator_addition("LIX", "XLI", actual);
  ck_assert_str_eq(actual, "C");
}
END_TEST

START_TEST(test_can_subtract_two_numbers)
{
  char actual[16];
  romancalculator_subtraction("C", "XLI", actual);
  ck_assert_str_eq(actual, "LIX");
}
END_TEST


Suite * operations_suite(void)
{
  Suite *s;
  TCase *tc_addition;
  TCase *tc_subtraction;

  s = suite_create("Operations");

  tc_addition = tcase_create("Addition");

  tcase_add_test(tc_addition, test_can_add_two_numbers);

  tc_subtraction = tcase_create("Subtraction");

  tcase_add_test(tc_subtraction, test_can_subtract_two_numbers);

  suite_add_tcase(s, tc_addition);
  suite_add_tcase(s, tc_subtraction);

  return s;

}
