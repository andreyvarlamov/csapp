#include <stdio.h>

/*
  2.71 ◆
  You just started working for a company that is implementing a set of procedures
  to operate on a data structure where 4 signed bytes are packed into a 32-bit
  unsigned. Bytes within the word are numbered from 0 (least significant) to 3
  (most significant). You have been assigned the task of implementing a function
  for a machine using two’s-complement arithmetic and arithmetic right shifts with
  the following prototype:

  // Declaration of data type where 4 bytes are packed into an unsigned
  typedef unsigned packed_t;
  int xbyte(packed_t word, int bytenum);

  That is, the function will extract the designated byte and sign extend it to be
  a 32-bit int.
  Your predecessor (who was fired for incompetence) wrote the following code:
  // Failed attempt at xbyte
  int xbyte(packed_t word, int bytenum)
  {
      return (word >> (bytenum << 3)) & 0xFF;
  }

  A. What is wrong with this code?
  B. Give a correct implementation of the function that uses only left and right
  shifts, along with one subtraction.
*/

// A. The result will not be sign extended to a 32-bit int

// B. Correct implementation:
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    // 12 34 56 78
    // << 24 -> 78 00 00 00
    // >> 24 -> 00 00 00 78 -- bytenum 0
    // << 16 -> 56 78 00 00
    // >> 24 -> 00 00 00 56 -- bytenum 1
    // << 8  -> 34 56 78 00
    // >> 24 -> 00 00 00 34 -- bytenum 2
    // << 0  -> 12 34 56 78
    // >> 24 -> 00 00 00 12 -- bytenum 3

    // 12 80 56 78
    // << 8  -> 80 56 78 00
    // >> 24 -> FF FF FF 80 -- bytenum 2

    int shit_left_amount = (3 - bytenum) << 3;
    int result = (int)(word << shit_left_amount) >> 24;
    return result;
}

#define TEST_CASE(WORD, BYTENUM) printf("xbyte(0x%08X, %1d) = 0x%08X\n", WORD, BYTENUM, xbyte(WORD, BYTENUM));

int main() {
    TEST_CASE(0x12345678, 0);
    TEST_CASE(0x12345678, 1);
    TEST_CASE(0x12345678, 2);
    TEST_CASE(0x12345678, 3);
    TEST_CASE(0x12805678, 2);
}

#undef TEST_CASE
