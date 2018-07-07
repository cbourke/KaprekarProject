#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>

#include "kaprekarUtils.h"

/**
 * A convenience function to print test values in a
 * format matching cmocka's format.
 */
static void printFormattedValue(int value) {
  printf("[TEST VALUE]\n");
  printf("[%10d]\n", value);
}

/**
 * A negative test function: the input state
 * is expected to be a pointer to an integer that
 * is NOT a Kaprekar number
 */
static void negativeTest(void **state) {
  int testValue = *(*((int**) state));
  printFormattedValue(testValue);
  int testResult = isKaprekar(testValue);
  assert_false(testResult);
}

/**
 * A positive test function: the input state
 * is expected to be a pointer to an integer that
 * IS a Kaprekar number
 */
static void positiveTest(void **state) {
  int testValue = *(*((int**) state));
  printFormattedValue(testValue);
  int testResult = isKaprekar(testValue);
  assert_true(testResult);
}

/**
 * A generic test function: the input state
 * is expected to be a an array of two integer
 * values, the first a test value and the second
 * a boolean indicating if the test value is a
 * Kaprekar number (true) or not (false)
 */
static void testValue(void **state) {
  int *values =  *((int **) state);
  int testValue = values[0];
  int expectedResult = values[1];
  printFormattedValue(testValue);
  int testResult = isKaprekar(testValue);
  assert_int_equal(testResult, expectedResult);
}

int main(int argc, char **argv) {

  /* Positive test values: all 24 Kaprekar numbers between [1, 100,000] */
  int kaprekarNumbers[] = {1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962, 77778, 82656, 95121, 99999};

  /* Negative test values: 24 non-Kaprekar numbers */
  int nonKaprekarNumbers[] = {-10, -1, 0, 2, 3, 4, 5, 6, 7, 8,
                               10, 500, 2000, 7776, 7778, 10000, 25123, 26321,
                               75000, 38961, 38963, 95119, 95120, 95122};

  int testA[] = {142857, 1};
  int testB[] = {142858, 0};

  /* Lots-a copy-pasta here because these are macros, not
   * functions, so we cannot dynamically generate these tests
   */
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(testValue, &testA),
    cmocka_unit_test_prestate(testValue, &testB),

    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[0]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[1]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[2]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[3]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[4]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[5]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[6]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[7]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[8]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[9]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[10]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[11]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[12]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[13]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[14]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[15]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[16]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[17]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[18]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[19]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[20]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[21]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[22]),
    cmocka_unit_test_prestate(positiveTest, &kaprekarNumbers[23]),

    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[0]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[1]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[2]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[3]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[4]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[5]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[6]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[7]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[8]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[9]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[10]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[11]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[12]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[13]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[14]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[15]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[16]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[17]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[18]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[19]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[20]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[21]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[22]),
    cmocka_unit_test_prestate(negativeTest, &nonKaprekarNumbers[23])
  };

  return cmocka_run_group_tests(tests, NULL, NULL);

}
