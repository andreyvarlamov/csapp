#include <stdio.h>

/*
  2.68 ◆◆
  Write code for a function with the following prototype:
  Your function should follow the bit-level integer coding rules (page 164). Be
  careful of the case n = w.
*/

/*
 * Mask with least signficant n bits set to 1
 * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */
int lower_one_mask(int n) {
    int mask = (1 << (n - 1) << 1) - 1;
    return mask;
}

#define TEST_CASE(X) printf("lower_one_mask(%2d) = 0x%08x\n", X, lower_one_mask(X));

int main() {
    TEST_CASE(6);
    TEST_CASE(17);
    TEST_CASE(3);
    TEST_CASE(1);
    TEST_CASE(32);
    return 0;
}

#undef TEST_CASE
