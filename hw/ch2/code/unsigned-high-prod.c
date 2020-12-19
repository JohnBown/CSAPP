#include <limits.h>
#include <assert.h>
#include <stdint.h>

int signed_high_prod(int x, int y)
{
    int64_t mul = (int64_t)x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int w = sizeof(int) << 3;
    unsigned o0 = signed_high_prod((int)x, (int)y);
    unsigned o1 = y & ((int)x >> (w - 1));
    unsigned o2 = x & ((int)y >> (w - 1));

    return o0 + o1 + o2;
}

unsigned another_unsigned_high_prod(unsigned x, unsigned y)
{
    uint64_t mul = (uint64_t)x * y;
    return mul >> 32;
}

int main(int argc, char *argv[])
{
    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;

    assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
    return 0;
}