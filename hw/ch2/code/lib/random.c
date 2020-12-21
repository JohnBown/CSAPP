#include <stdlib.h>
#include <time.h>
#include "random.h"

void init_seed(void)
{
    srand(time(NULL));
}

int random_int(void)
{
    int int_bits = sizeof(int) << 3;
    int i, r = 0;
    for (i = 0; i < int_bits; i++)
    {
        r |= rand() % 2;
        r <<= 1;
    }
    return r;
}