#include <stdio.h>
#include <assert.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    if (i < 0 || i > sizeof(unsigned) - 1)
    {
        printf("wrony range...\n");
        return -1;
    }

    return (x & ~(0xFF << (i * 8))) | (b << (i * 8));
}

int main(int argc, char *argv[])
{
    assert(replace_byte(0x12345678, 2, 0xAB) == 0x12AB5678);
    assert(replace_byte(0x12345678, 0, 0xAB) == 0x123456AB);

    return 0;
}