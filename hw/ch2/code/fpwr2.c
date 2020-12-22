#include <assert.h>
#include <math.h>

float u2f(int x)
{
    return *(float *)&x;
}

float fpwr2(int x)
{
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

    if (x <)
    {
        /* Too small. Return 0.0 */
        exp = ;
        frac = ;
    }
    else if (x <)
    {
        /* Denormalized result */
        exp = ;
        frac = ;
    }
    else if (x <)
    {
        /* Normalized result. */
        exp = ;
        frac = ;
    }
    else
    {
        /* Too big. Return +∞ */
        exp = ;
        frac = ;
    }

    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return u2f(u);
}

int main(int argc, char *argv[])
{
    assert(fpwr2(0) == powf(2, 0));
    assert(fpwr2(100) == powf(2, 100));
    assert(fpwr2(-100) == powf(2, -100));
    assert(fpwr2(10000) == powf(2, 10000));
    assert(fpwr2(-10000) == powf(2, -10000));
    return 0;
}