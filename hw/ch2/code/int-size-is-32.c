#include <stdio.h>
#include <assert.h>

// /* The following code does not run properly on some machines */
// int bad_int_size_is_32()
// {
//     /* Set most significant bit (msb) of 32-bit machine */
//     int set_msb = 1 << 31;
//     /* Shift past msb of 32-bit word */
//     int beyond_msb = 1 << 32;
//     /* set_msb is nonzero when word size >= 32
//        beyond_msb is zero when word size <= 32 */
//     return set_msb && !beyond_msb;
// }

int int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_for_16bit()
{
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int main(int argc, char *argv[])
{
    assert(int_size_is_32);
    assert(int_size_is_32_for_16bit);
    return 0;
}