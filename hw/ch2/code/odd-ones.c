#include <stdio.h>
#include <assert.h>

size_t mask[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};

#define ROUND(x, c) ((x & mask[c]) + ((x & ~mask[c]) >> (1 << c)))

int odd_ones(unsigned x) // method 1
{
    x = ROUND(x, 0);
    x = ROUND(x, 1);
    x = ROUND(x, 2);
    x = ROUND(x, 3);
    x = ROUND(x, 4);
    return x & 0x1;
}

int odd_ones_(unsigned x) // method 2
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
}

int main(int argc, char *argv[])
{
    assert(odd_ones(0x10101011));
    assert(!odd_ones(0x01010101));

    assert(odd_ones_(0x10101011));
    assert(!odd_ones_(0x01010101));
    return 0;
}