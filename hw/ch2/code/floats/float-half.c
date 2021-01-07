#include "float-half.h"

float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned rest = f & 0x7FFFFFFF;

    int is_NAN_or_inf = (exp == 0xFF);

    if (is_NAN_or_inf)
    {
        return f;
    }

    int addition = (frac & 0x3) == 0x3;

    if (exp == 0)
    {
        frac >>= 1;
        frac += addition;
    }
    else if (exp == 1)
    {
        rest >>= 1;
        rest += addition;
        exp = (rest >> 23) & 0xFF;
        frac = rest & 0x7FFFFF;
    }
    else
    {
        exp -= 1;
    }

    return sign << 31 | exp << 23 | frac;
}