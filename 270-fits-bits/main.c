#include <stdio.h>
#include <limits.h>

/*
  2.70 ◆◆
  Write code for the function with the following prototype:
  Your function should follow the bit-level integer coding rules (page 164).
*/

/*
 * Return 1 when x can be represented as an n-bit, 2’s-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */
int fits_bits(int x, int n) {
    int w = sizeof(int) << 3;
    int shift_amount = w - n; // n: (0, 32]; shift_amount: [0, 32)
    int shifted = x << shift_amount >> shift_amount;
    return x == shifted;
}

#define TEST_CASE(X_, N_) printf("fits_bits(0x%032b, %2d) = %d\n", X_, N_, fits_bits(X_, N_));

int main() {
    TEST_CASE(1, 1);
    TEST_CASE(1, 2);
    TEST_CASE(2, 1);
    TEST_CASE(2, 2);
    TEST_CASE(3, 2);
    TEST_CASE(-1, 31);
    TEST_CASE(-1, 2);
    TEST_CASE(-3, 3);
    TEST_CASE(9274339, 32);
    TEST_CASE(INT_MAX, 32);
    TEST_CASE(INT_MIN, 32);
    TEST_CASE(INT_MAX, 31);
    TEST_CASE(INT_MIN, 31);
    return 0;
}

#undef TEST_CASE
