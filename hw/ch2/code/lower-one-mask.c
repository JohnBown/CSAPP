#include <assert.h>
#include <stdint.h>

int lower_one_mask(int n)
{
    int32_t x = INT32_MIN;
    x >>= (sizeof(int32_t) << 3) - n;
    return ~(x << 1);
}

int main(int argc, char *argv[])
{
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
    return 0;
}