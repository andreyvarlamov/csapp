#include <stdio.h>
#include <assert.h>

// 2.61 A)
int any_bit_one(unsigned x) {
    unsigned one_bits = x & -1;
    int any_one_bits = !!one_bits;
    return any_one_bits;
}

void any_bit_one_test() {
    printf("\nTesting any_bit_one()...\n\n");

    {
        unsigned input = 11232892;
        int result = any_bit_one(input);
        printf("any_bit_one(0x%08X) = %d\n", input, result);
        assert(result == 1);
    }
  
    {
        unsigned input = 0;
        int result = any_bit_one(input);
        printf("any_bit_one(0x%08X) = %d\n", input, result);
        assert(result == 0);
    }
}

// 2.61 B)
int any_bit_zero(unsigned x) {
    unsigned zero_bits = ~x & -1;
    int any_zero_bits = !!zero_bits;
    return any_zero_bits;
}

void any_bit_zero_test() {
    printf("\nTesting any_bit_zero()...\n\n");

    {
        unsigned input = 0;
        int result = any_bit_zero(input);
        printf("any_bit_zero(0x%08X) = %d\n", input, result);
        assert(result == 1);
    }
  
    {
        unsigned input = 11232892;
        int result = any_bit_zero(input);
        printf("any_bit_zero(0x%08X) = %d\n", input, result);
        assert(result == 1);
    }

    {
        unsigned input = -1;
        int result = any_bit_zero(input);
        printf("any_bit_zero(0x%08X) = %d\n", input, result);
        assert(result == 0);
    }
}

// 2.61 C)
int any_lsb_bit_one(unsigned x) {
    unsigned lsb_one_bits = x & 0xFF;
    int any_lsb_one_bits = !!lsb_one_bits;
    return any_lsb_one_bits;
}

void any_lsb_bit_one_test() {
    printf("\nTesting any_lsb_bit_one()...\n\n");
  
    {
        unsigned input = 0x10;
        int result = any_lsb_bit_one(input);
        printf("any_lsb_bit_one(0x%08X) = %d\n", input, result);
        assert(result == 1);
    }

    {
        unsigned input = 0xFF;
        int result = any_lsb_bit_one(input);
        printf("any_lsb_bit_one(0x%08X) = %d\n", input, result);
        assert(result == 1);
    }

    {
        unsigned input = 0xFF00;
        int result = any_lsb_bit_one(input);
        printf("any_lsb_bit_one(0x%08X) = %d\n", input, result);
        assert(result == 0);
    }
}

// 2.61 D)
int any_msb_bit_zero(unsigned x) {
    int shift_bits = (sizeof(unsigned) - 1) << 3;
    unsigned msb_zero_bits = ~(x >> shift_bits) & 0xFF;
    int any_msb_zero_bits = !!msb_zero_bits;
    return any_msb_zero_bits;
}

void any_msb_bit_zero_test() {
    printf("\nTesting any_msb_bit_zero()...\n\n");
  
    {
        unsigned input = 0x1;
        int result = any_msb_bit_zero(input);
        printf("any_msb_bit_zero(0x%08X) = %d\n", input, result);
        assert(result == 1);
    }

    {
        unsigned input = 0xFE000000;
        int result = any_msb_bit_zero(input);
        printf("any_msb_bit_zero(0x%08X) = %d\n", input, result);
        assert(result == 1);
    }

    {
        unsigned input = 0xFF000000;
        int result = any_msb_bit_zero(input);
        printf("any_msb_bit_zero(0x%08X) = %d\n", input, result);
        assert(result == 0);
    }
}

int main(int argc, char **argv) {
    any_bit_one_test();
    any_bit_zero_test();
    any_lsb_bit_one_test();
    any_msb_bit_zero_test();
}
