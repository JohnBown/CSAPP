#include <assert.h>

int fits_bits(int x, int n) // method 2
{
    x >>= (n - 1);
    return !(x ^ 0 && ~x ^ 0); // (x == 0) || (~x == 0)
}

int fits_bits_(int x, int n) // method 2
{
    int c = ((sizeof(int) << 3) - n);
    return x == (x << c) >> c;
}

int main(int argc, char *argv[])
{
    assert(!fits_bits(0xFF, 8));
    assert(!fits_bits(~0xFF, 8));

    assert(fits_bits(0b0010, 3));
    assert(!fits_bits(0b1010, 3));
    assert(!fits_bits(0b0110, 3));

    assert(fits_bits(~0b11, 3));
    assert(!fits_bits(~0b01000011, 3));
    assert(!fits_bits(~0b111, 3));

    assert(!fits_bits_(0xFF, 8));
    assert(!fits_bits_(~0xFF, 8));

    assert(fits_bits_(0b0010, 3));
    assert(!fits_bits_(0b1010, 3));
    assert(!fits_bits_(0b0110, 3));

    assert(fits_bits_(~0b11, 3));
    assert(!fits_bits_(~0b01000011, 3));
    assert(!fits_bits_(~0b111, 3));
    return 0;
}