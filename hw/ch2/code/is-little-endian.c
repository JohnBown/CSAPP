#include <stdio.h>
#include <assert.h>

int is_little_endian()
{
    int i = 0x1;
    return *((char *)&i);
}

int main(int argc, char *argv[])
{
    assert(is_little_endian());
    return 0;
}