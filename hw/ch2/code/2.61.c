#include <stdio.h>
#include <assert.h>

int A(int x)
{
    return !~x;
}

int B(int x)
{
    return !x;
}

int C(int x)
{
    return A(x | ~0xFF);
}

int D(int x)
{
    return B(x >> ((sizeof(int) - 1) << 3));
}

int main(int argc, char *argv[])
{
    int ones = ~0;
    int zeros = 0;

    assert(A(ones));
    assert(!B(ones));
    assert(C(ones));
    assert(!D(ones));

    assert(!A(zeros));
    assert(B(zeros));
    assert(!C(zeros));
    assert(D(zeros));

    assert(!A(0x1234ff));
    assert(!B(0x1234ff));
    assert(C(0x1234ff));
    assert(D(0x1234ff));

    assert(!A(0x1234));
    assert(!B(0x1234));
    assert(!C(0x1234));
    assert(D(0x1234));

    return 0;
}