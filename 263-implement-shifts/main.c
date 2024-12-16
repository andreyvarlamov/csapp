#include <stdio.h>
#include <limits.h>

/*
  2.63 ◆◆◆
  Fill in code for the following C functions. Function srl performs a logical right
  shift using an arithmetic right shift (given by value xsra), followed by other oper-
  ations not including right shifts or division. Function sra performs an arithmetic
  right shift using a logical right shift (given by value xsrl), followed by other
  operations not including right shifts or division. You may use the computation
  8*sizeof(int) to determine w, the number of bits in data type int. The shift
  amount k can range from 0 to w − 1.
*/

static int w = 8 * sizeof(int);

int is_negative(unsigned x) {
    unsigned msb_1 = 1 << (w - 1);
    int is_negative = !!(msb_1 & x);
    return is_negative;
}

unsigned calculate_top_mask(int k) {
    // NOTE: e.g. for w = 8, k = 3:
    //       -1         - ((1 << 5) - 1)
    //       0b11111111 - ((0b00000001 << 5) - 1)
    //       0b11111111 -  (0b00100000 - 1)
    //       0b11111111 -   0b00011111
    //       = 0b11100000
    // NOTE: Multiply by k != 0 to prevent UB when k = 0, which would cause a shift by w
    unsigned top_mask = (k != 0) * (-1 - ((1 << (w - k)) - 1));
    return top_mask;
}

unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int)x >> k;
    unsigned result = xsra - is_negative(x) * calculate_top_mask(k);
    return result;
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned)x >> k;
    int result = xsrl + is_negative((unsigned)x) * calculate_top_mask(k);
    return result;
}

int main() {
    {
        unsigned x = (unsigned)-1;
        int k = 5;
        unsigned result = srl(x, k);
        printf("srl(0x%08X, %d) = 0x%08X\n", x, k, result);
    }

    {
        unsigned x = INT_MAX;
        int k = 5;
        unsigned result = srl(x, k);
        printf("srl(0x%08X, %d) = 0x%08X\n", x, k, result);
    }

    {
        unsigned x = (unsigned)-1;
        int k = 0;
        unsigned result = srl(x, k);
        printf("srl(0x%08X, %d) = 0x%08X\n", x, k, result);
    }

    {
        int x = -1;
        int k = 5;
        unsigned result = sra(x, k);
        printf("sra(0x%08X, %d) = 0x%08X\n", x, k, result);
    }

    {
        int x = INT_MAX;
        int k = 5;
        unsigned result = sra(x, k);
        printf("sra(0x%08X, %d) = 0x%08X\n", x, k, result);
    }

    {
        int x = -1;
        int k = 0;
        unsigned result = sra(x, k);
        printf("sra(0x%08X, %d) = 0x%08X\n", x, k, result);
    }

    return 0;
}
