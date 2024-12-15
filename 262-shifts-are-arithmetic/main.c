#include <stdio.h>

/*
  2.62 ◆◆◆
  Write a function int_shifts_are_arithmetic() that yields 1 when run on a
  machine that uses arithmetic right shifts for data type int and yields 0 otherwise.
  Your code should work on a machine with any word size. Test your code on several
  machines.
 */

int int_shifts_are_arithmetic() {
    int shift_bits_amount = (sizeof(int) << 3) - 1;
    int msb_1 = 1 << shift_bits_amount;
    int shifted_right = msb_1 >> shift_bits_amount;
    int is_all_ones = shifted_right == -1;
    return is_all_ones;
}

int main(int argc, char **argv) {
    int result = int_shifts_are_arithmetic();
    printf("int_shifts_are_arithmetic() = %d\n", result);
    return 0;
}
