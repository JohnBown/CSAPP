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

int main(int argc, char *argv[])
{
    int x = 0x80000007;
    assert(divide_power2(x, 1) == x / 2);
    assert(divide_power2(x, 2) == x / 4);
    return 0;
}