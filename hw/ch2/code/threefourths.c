#include <assert.h>
#include <limits.h>

/*
 * ever x equal front 30 bits f plus back 2 bits l,
 * so threefourths(x) = f/4*3 + l*3/4
 * fd4m3 will not overflow
 * lm3d4: (lm3<0 ? lm3+(1<<2)-1 : l) >> 2
 * https://github.com/DreamAndDead/CSAPP-3e-Solutions/blob/master/chapter2/code/threeforths.c
 */
int threefourths(int x)
{
    int is_neg = x & INT_MIN;
    int f = x & ~0x3;
    int l = x & 0x3;

    int fd4 = f >> 2;
    int fd4m3 = (fd4 << 1) + fd4;

    int lm3 = (l << 1) + l;
    int bias = (1 << 2) - 1;
    is_neg && (lm3 += bias);
    int lm3d4 = lm3 >> 2;
    return fd4m3 + lm3d4;
}

int main(int argc, char *argv[])
{
    assert(threefourths(8) == 6);
    assert(threefourths(9) == 6);
    assert(threefourths(10) == 7);
    assert(threefourths(11) == 8);
    assert(threefourths(12) == 9);

    assert(threefourths(-8) == -6);
    assert(threefourths(-9) == -6);
    assert(threefourths(-10) == -7);
    assert(threefourths(-11) == -8);
    assert(threefourths(-12) == -9);
    return 0;
}