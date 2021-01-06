#include "../lib/random.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "float-negate.h"

unsigned f2u(float f)
{
    return *(unsigned *)&f;
}

float u2f(unsigned u)
{
    return *(float *)&u;
}

int main(int argc, char *argv[])
{
    init_seed();

    for (unsigned n = 0, round = 0; !round; n++)
    {
        if (n == 0xFFF)
        {
            round++;
        }

        unsigned r = random_int();
        printf("r:\t0x%.8X\t%d\n", r, r);

        float f = u2f(r);
        printf("f:\t0x%.8X\t%.50f\n", f2u(f), f);

        if (isnan(f))
        {
            assert(float_negate(r) == r);
        }
        else
        {
            assert(u2f(float_negate(r)) == -f);
        }

        printf("\n");
    }
}