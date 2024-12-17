#include <stdio.h>

/*
  2.64 ◆
  Write code to implement the following function:
  Your function should follow the bit-level integer coding rules (page 164),
  except that you may assume that data type int has w = 32 bits.
*/

/* Return 1 when any odd bit of x equals 1; 0 otherwise. Assume w=32 */
int any_odd_one(unsigned x) {
    // NOTE: 0xA = 0b1010
    unsigned odd_mask = 0xAAAAAAAA;
    return !!(x & odd_mask);
}

int main() {
    {
	unsigned x = 0b01010101;
	int result = any_odd_one(x);
	printf("any_odd_one(0b%b) = %d\n", x, result);
    }
    {
	unsigned x = 0b01010110;
	int result = any_odd_one(x);
	printf("any_odd_one(0b%b) = %d\n", x, result);
    }
}
