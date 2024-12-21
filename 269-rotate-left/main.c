#include <stdio.h>

/*
  2.69 ◆◆◆
  Write code for a function with the following prototype:
  Your function should follow the bit-level integer coding rules (page 164). Be
  careful of the case n = 0.
*/

/*
 * Do rotating left shift. Assume 0 <= n < w
 * Examples when x = 0x12345678 and w = 32:
 * n=4 -> 0x23456781, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(unsigned) << 3;
    int left_shift_amount = n;
    int right_shift_amount = w - n; // n can be 0 --> w can be 32. Split into 2 shifts
    unsigned result = (x << left_shift_amount) | (x >> (right_shift_amount - 1) >> 1);
    return result;
}

#define TEST_CASE(X, N) printf("rotate_left(0x%08X, %2d) = 0x%08X\n", X, N, rotate_left(X, N));

int main() {
    TEST_CASE(0x12345678, 4);
    TEST_CASE(0x12345678, 20);
    TEST_CASE(0x12345678, 32);
    TEST_CASE(0x12345678, 5);
    TEST_CASE(0x12345678, 0);
    return 0;
}

#undef TEST_CASE
