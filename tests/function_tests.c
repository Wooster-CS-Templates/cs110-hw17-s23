#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../dice.h"

void test_all_same_probability(size_t side_count, size_t dice_count,
                               size_t roll_count, double expected) {
  double tolerance = 0.0002;

  double result = all_same_probability(side_count, dice_count, roll_count);

  if (!(result <= expected + tolerance && result >= expected - tolerance)) {
    printf("Test Failed:\n");
    printf("For %zu sides, %zu dice, and %zu rolls, expected all_same_probability to return a value within %lf of %lf, but it returned %lf\n", side_count, dice_count, roll_count, tolerance, expected, result);
    exit(1);
  }
}

void print_array(unsigned int *dice, size_t size) {
  putchar('{');
  for (size_t i = 0; i < size; i++) {
    printf("%i", dice[i]);
    if (i < size - 1) {
      putchar(',');
    }
  }
  putchar('}');
}

void test_are_all_same(unsigned int *dice, size_t size, bool expected) {
  if (!(are_all_same(dice, size) == expected)) {
    printf("When given the array ");
    print_array(dice, size);
    printf(", expected are_all_same() to return ");
    if (expected) {
      printf("true");
    }
    else {
      printf("false");
    }
    printf(", but it returned ");
    if (expected) {
      printf("false");
    }
    else {
      printf("true");
    }
    printf("\n");
    exit(1);
  }
}

int main() {
  printf("Running tests for all_same_probability()\n");
  test_all_same_probability(6, 1, 100, 1);
  test_all_same_probability(4, 3, 100000000, 0.0625);

  printf("Running tests for are_all_same()\n");
  unsigned int one[] = {1};
  test_are_all_same(one, 1, true);

  unsigned int one_two[] = {1, 2};
  test_are_all_same(one_two, 2, false);

  unsigned int one_one[] = {1, 1};
  test_are_all_same(one_one, 2, true);

  unsigned int two_one[] = {2, 1};
  test_are_all_same(two_one, 2, false);

  unsigned int one_one_two[] = {1, 1, 2};
  test_are_all_same(one_one_two, 3, false);

  unsigned int one_two_one[] = {1, 2, 1};
  test_are_all_same(one_two_one, 3, false);

  unsigned int two_one_one[] = {2, 1, 1};
  test_are_all_same(two_one_one, 3, false);

  unsigned int one_one_one[] = {1, 1, 1};
  test_are_all_same(one_one_one, 3, true);

  printf("All tests passed!\n");
  return 0;
}
