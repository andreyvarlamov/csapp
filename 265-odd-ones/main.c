#include <stdio.h>

/*
  2.65 ◆◆◆◆
  Write code to implement the following function:
  int odd_ones(unsigned x);
  Your function should follow the bit-level integer coding rules (page 164),
  except that you may assume that data type int has w = 32 bits.
  Your code should contain a total of at most 12 arithmetic, bitwise, and logical
  operations.
*/

/* Return 1 when x contains an odd number of 1s; 0 otherwise. Assume w=32 */
int odd_ones(unsigned x) {
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    int result = (x & 0b1);
    return result;
}

int main() {
    {
	unsigned x = 0b1;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0b11;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0b111;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0b1111;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0b11111;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0b111111;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0b0;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0x80000000;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0xC0000000;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0xE0000000;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0xF0000000;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0xF8000000;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0xFC000000;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0xFE000000;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0xFF000000;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    {
	unsigned x = 0xFFFFFFFF;
	int result = odd_ones(x);
	printf("odd_ones(0b%032b) = %d\n", x, result);
    }

    return 0;
}
