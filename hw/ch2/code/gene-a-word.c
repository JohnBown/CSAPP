#include <stdio.h>

int main(int argc, char *argv[])
{
    size_t msk = 0xFF;
    size_t x = 0x89ABCDEF;
    size_t y = 0x76543210;

    size_t res = (x & msk) + (y & ~msk);
    printf("%X\n", res);
}