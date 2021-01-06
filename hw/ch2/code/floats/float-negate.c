#include "float-negate.h"

float_bits float_negate(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NAN = (exp == 0xFF) && (frac != 0);

    if (is_NAN)
    {
        return f;
    }

    return (~sign) << 31 | exp << 23 | frac;
}
