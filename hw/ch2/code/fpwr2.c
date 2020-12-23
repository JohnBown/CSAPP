#include <assert.h>
#include <math.h>

float u2f(int x)
{
    return *(float *)&x;
}

unsigned f2u(float f)
{
    return *(unsigned *)&f;
}

float fpwr2(int x)
{
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

    int Bias = (pow(2, 8 - 1) - 1);

    if (x < 1 - Bias - 23) // -149
    {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    }
    else if (x < 1 - Bias) // -126
    {
        /* Denormalized result */
        exp = 1;
        frac = (1 << 23) >> (-(x + Bias - 1));
    }
    else if (x < 1 + (pow(2, 8) - 2) - Bias) // 128
    {
        /* Normalized result. */
        exp = x + Bias;
        frac = 0;
    }
    else
    {
        /* Too big. Return +∞ */
        exp = 0xFF;
        frac = 0;
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