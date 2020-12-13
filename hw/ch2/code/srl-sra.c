#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    size_t mask = (~0) << ((sizeof(int) << 3) - k);
    return xsra & ~mask;
}

int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;
    size_t sign, mask;
    sign = 1 << ((sizeof(int) << 3) - k - 1);
    sign = sign & xsrl;
    sign = 0 - !!sign;
    mask = sign << ((sizeof(int) << 3) - k);
    return xsrl | mask;
}

int main(int argc, char *argv[])
{
    unsigned test_u = 0x12345678;
    int test_i = 0x12345678;
    int k = 4;

    assert(srl(test_u, 4) == test_u >> 4);
    assert(sra(test_i, 4) == test_i >> 4);

    test_u = 0x87654321;
    test_i = 0x87654321;

    assert(srl(test_u, 4) == test_u >> 4);
    assert(sra(test_i, 4) == test_i >> 4);
    return 0;
}