#include <stdio.h>

/*
  2.73 ◆◆
  Write code for a function with the following prototype:

  // Addition that saturates to TMin or TMax
  int saturating_add(int x, int y);

  Instead of overflowing the way normal two’s-complement addition does, sat-
  urating addition returns TMax when there would be positive overflow, and TMin
  when there would be negative overflow. Saturating arithmetic is commonly used
  in programs that perform digital signal processing.

  Your function should follow the bit-level integer coding rules (page 164).
*/

int saturating_add(int x, int y) {
    // underflow when MSB of x = 1 and MSB of y = 1, but MSB of x + y = 0
    //           going over the 1000 [...] to 0111 [...] threshold
    //           saturate to 1000 [...]
    // overflow  when MSB of x = 0 and MSB of y = 0, but MSB of x + y = 1
    //           going over the 0111 [...] to 1000 [...] threshold
    //           saturate to 0111 [...]

    int sum = x + y;
    int overflow_mask = ~x & ~y & sum & 0x80000000; // if overflow -- 0x80000000; if no overflow -- 0x00000000;
    int underflow_mask = x & y & ~sum & 0x80000000; // if underflow -- 0x80000000; if no underflow -- 0x00000000;

    // if overflow, replace the result with 0x7FFFFFFF;
    // overflow_mask - 1 = either 0x7FFFFFFF (overflow) or 0xFFFFFFFF (no overflow);
    // 0xFFFFFFFF mask -> result = sum
    // 0x7FFFFFFF mask -> result = 0x7FFFFFFF
    // if underflow, replace the result with 0x80000000; -- underflow_mask
    // underflow_mask = either 0x80000000 (underflow) or 0x00000000 (no underflow);
    // 0x00000000 mask -> result = sum
    // 0x80000000 mask -> result = 0x80000000

    // ...

    // sum & overflow_mask | underflow_mask = sum if no overflow and no underflow
    //                                      = zero out MSB if overflow -- also need to set all LSBs to 1
    //                                      = enable MSB if underflow -- also need to set all LSBs to 0

    // ...

    sum = (sum & ~overflow_mask) | ((overflow_mask >> 31) & 0x7FFFFFFF);
    sum = (sum & ~(underflow_mask >> 31)) | underflow_mask;

    return sum;
}

#define TEST_CASE(A, B) printf("saturating_add(0x%08X, 0x%08X) = 0x%08X; saturating_add(%d, %d) = %d;\n", A, B, saturating_add(A, B), A, B, saturating_add(A, B));

int main() {
    TEST_CASE(0x100, 0x100);
    TEST_CASE(0x7FFFFFFF, 0x7FFFFFFF);
    TEST_CASE(0x80000000, 0x80000000);
    TEST_CASE(-190892, -12988);
    TEST_CASE(0xF0000000, 0xF0000000);
    return 0;
}

#undef TEST_CASE
