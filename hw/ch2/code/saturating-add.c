#include <limits.h>
#include <assert.h>

int saturating_add(int x, int y)
{
    int s, t, w;

    t = s = x + y;
    w = sizeof(int) << 3;
    x >>= w - 1;
    y >>= w - 1;
    t >>= w - 1;

    int pos_ovf = ~x & ~y & t;
    int neg_ovf = x & y & ~t;
    int no_ovf = ~(pos_ovf | neg_ovf);

    return (pos_ovf & INT_MAX) | (neg_ovf & INT_MIN) | (no_ovf & s);
}

int saturating_add_(int x, int y)
{
    int sum = x + y;
    int m = INT_MIN;

    int pos_ovf = !(x & m) && !(y & m) && (sum & m);
    int neg_ovf = (x & m) && (y & m) && !(sum & m);

    (pos_ovf && (sum = INT_MAX) || neg_ovf && (sum = INT_MIN));

    return sum;
}

int main(int argc, int argv[])
{
    assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
    assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
    assert(0x11 + 0x22 == saturating_add(0x11, 0x22));
    return 0;
}