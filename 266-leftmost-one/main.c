#include <stdio.h>

/*
  2.66 ◆◆◆
  Write code to implement the following function:
  Your function should follow the bit-level integer coding rules (page 164),
  except that you may assume that data type int has w = 32 bits.
  Your code should contain a total of at most 15 arithmetic, bitwise, and logical
  operations.
  Hint: First transform x into a bit vector of the form [0 . . . 011 . . . 1].
*/

/*
 * Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
 * If x = 0, then return 0.
 */
unsigned leftmost_one(unsigned x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x ^= (x >> 1);
    return x;
}

/*
  Working through the algorithm:
  0010 1000 0100 1100 0010 1000 0100 1100
  0011 1100 0110 1110 0011 1100 0110 1110
  0011 1111 0111 1111 1011 1111 1111 1111
  0011 1111 1111 1111 1111 1111 1111 1111

  1000 0000 0000 0000 0000 0000 0000 0000
  1100 0000 0000 0000 0000 0000 0000 0000
  1111 0000 0000 0000 0000 0000 0000 0000
  1111 1111 0000 0000 0000 0000 0000 0000
  1111 1111 1111 1111 0000 0000 0000 0000
  1111 1111 1111 1111 1111 1111 1111 1111

  And some thinking:
  because it's OR, only the leftmost one will be propagating. that's
  the only one that matters, all the lower ones that are already one,
  will stay as one. so proving 0010 1111 works is no different from
  proving that 0010 0000 works. and the latter case we can think of as
  doubling ones every iteration, and if the number of operations is
  log2 w, we will cover all bits. the worst case - propagating one
  from the MSB - proves the other cases. and for MSB, for w = 8, there
  are 3 operations: 1000 0000 -> 1100 0000 -> 1111 0000 -> 1111 1111

  XOR in the end is an improvement on something I tried previously:
  add 1 and shift left. but that didn't work for the MSB case because
  of overflow. but this is much cleaner too:
  1111 1111 ^ 0111 1111
  0011 1111 ^ 0001 1111
*/

#define TEST_CASES							\
    X(0b00101000010011000010100001001100)				\
    X(0x80000000)							\
    X(0x00000001)							\
    X(0x00000002)							\
    X(0)								\
    X(~0)

int main() {
    #define X(INPUT) printf("leftmost_one(0b%032b) = 0b%032b\n", INPUT, leftmost_one(INPUT));
    TEST_CASES;
    #undef X

    return 0;
}
