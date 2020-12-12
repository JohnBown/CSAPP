#include <stdio.h>

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
    printf("replace_byte(0x12345678, 2, 0xAB) --> 0x%X\n", replace_byte(0x12345678, 2, 0xAB));
    printf("replace_byte(0x12345678, 0, 0xAB) --> 0x%X\n", replace_byte(0x12345678, 0, 0xAB));
}