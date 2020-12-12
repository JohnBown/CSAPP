#include <stdio.h>

int is_little_endian()
{
    int i = 0x1;
    return *((char *)&i);
}

int main(int argc, char *argv[])
{
    if (is_little_endian())
        printf("little endian...\n");
    else
        printf("rbig endian...\n");

    return 0;
}