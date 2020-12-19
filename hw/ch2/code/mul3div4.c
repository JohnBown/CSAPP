#include <assert.h>
#include <limits.h>

int divide_power2(int x, int k)
{
    int m = INT_MIN;
    int b = (1 << k) - 1;
    int x_ = x;
    (x & m) && (x_ += b);
    return (x_) >> k;
}

int mul3div4(int x)
{
    int mul3 = (x << 1) + x;
    return divide_power2(mul3, 2);
}

int main(int argc, char *argv[])
{
    int x = 0x87654321;
    assert(mul3div4(x) == x * 3 / 4);
    return 0;
}