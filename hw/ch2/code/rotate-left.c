#include <stdio.h>
#include <assert.h>

unsigned rotate_left(unsigned x, int n)
{
    size_t mask = (-1) << ((sizeof(int) << 3) - n);
    int x_head = (x & mask) >> ((sizeof(int) << 3) - n);
    int x_tail = (x & ~mask) << n;
    return x_head + x_tail;
}

int main(int argc, char *argv[])
{
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    assert(rotate_left(0x12345678, 0) == 0x12345678);
    return 0;
}