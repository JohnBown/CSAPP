#include <assert.h>
#include <string.h>
#include <stdlib.h>

void copy_int(int val, void *buf, int maxbytes)
{
    // 条件判断变成补码进行比较，避免maxbytes输入一个负值
    if (maxbytes >= (int)sizeof(val))
        memcpy(buf, (void *)&val, sizeof(val));
}

int main(int argc, char *argv[])
{
    int maxbytes = sizeof(int) * 10;
    void *buf = malloc(maxbytes);
    int val;

    val = 0x12345678;
    copy_int(val, buf, maxbytes);
    assert(*(int *)buf == val);

    val = 0xAABBCCDD;
    copy_int(val, buf, 0);
    assert(*(int *)buf != val);

    free(buf);
    return 0;
}