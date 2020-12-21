#include <assert.h>

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /**
     * judge : x <= y ?
     * ux == 0 && uy ==0    :-> 1
     * x < 0 && y >= 0      :-> 1
     * x < 0 && y < 0       :-> ux > uy
     * x >=0 && y >= 0      :-> ux <= uy
    */
    return (ux << 1 == 0 && uy << 1 == 0) ||
           (sx && !sy) ||
           (sx && sy && ux > uy) ||
           (!sx && !sy && ux <= uy);
}

int main(int argc, char *argv[])
{
    assert(float_le(-0, +0));
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-4, -0));
    assert(float_le(-4, 4));
    assert(!float_le(3, 0));
    assert(!float_le(-0, -4));
    assert(!float_le(4, -4));
    return 0;
}