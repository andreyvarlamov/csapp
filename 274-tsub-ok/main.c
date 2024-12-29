#include <stdio.h>

/*
  2.74 ◆◆
  Write a function with the following prototype:

  // Determine whether arguments can be subtracted without overflow
  int tsub_ok(int x, int y);

  This function should return 1 if the computation x-y does not overflow.
*/

// Determine whether arguments can be subtracted without overflow
int tsub_ok(int x, int y) {
    // Negate y, and check if addition overflows

    // However, note the case of y = Tmin
    // negation of Tmin inherently leads to overflow: if y = Tmin, then -y = Tmin
    // if x >= 0, its addition to the negated Tmin will be necessarily >= Tmax + 1

    // if x >= 0 && y == Tmin -> overflow
    // if x < 0 && y == Tmin -> good (Tmin negation itself overflows, but because of the negative x it underflows back)
    // if x > 0 && y_neg > 0 && sum <= 0 -> overflow
    // if x < 0 && y_neg < 0 && sum >= 0 -> underflow

    int sign_mask = 1 << ((sizeof(int) << 3) - 1);
    int t_min = sign_mask;

    int y_neg = -y;
    int sum = x + y_neg;

    int t_min_overflow = !(x & sign_mask) && (y == t_min);
    int t_min_good = !!(x & sign_mask) && (y == t_min);

    int overflow = !(x & sign_mask) && (x != 0) && !(y_neg & sign_mask) && (y_neg != 0) && (!!(sum & sign_mask) || (sum == 0));
    int underflow = !!(x & sign_mask) && !!(y_neg & sign_mask) && !(sum & sign_mask);

    return t_min_good || (!t_min_overflow && !overflow && !underflow);
}

#define TEST_CASE(X, Y) printf("tsub_ok(0x%08X, 0x%08X) = %d; 0x%08X - 0x%08X = 0x%08X\n", X, Y, tsub_ok(X, Y), X, Y, X - Y);

int main() {
    TEST_CASE(123, 5456);
    TEST_CASE(-123, -5456);
    TEST_CASE(123, -5456);
    TEST_CASE(-123, 5456);
    TEST_CASE(0, 0);
    TEST_CASE(-123, 0);
    TEST_CASE(0, -123);
    TEST_CASE(123, 0);
    TEST_CASE(0, 123);
    TEST_CASE(0, 0x80000000);
    TEST_CASE(1, 0x80000000);
    TEST_CASE(-1, 0x80000000);
    TEST_CASE(0x7FFFFFFF, 0x7FFFFFFF);
    TEST_CASE(0x90000000, 0x8FFFFFFF);
    TEST_CASE(0x80000000, 0x80000000);
    TEST_CASE(0x80000000, 1);
    TEST_CASE(0x80000000, -1);

    return 0;
}

#undef TEST_CASE
