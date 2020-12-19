#include <assert.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    int x = word << ((3 - bytenum) << 3);
    x >>= (3 << 3);
    return x;
}

int main(int argc, char *argv[])
{
    assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0x00112233, 2) == 0x11);
    return 0;
}