#include <limits.h>
#include <assert.h>

int tsub_ok(int x, int y)
{
    int sub = x - y;
    int m = INT_MIN;

    int is_tmin = !(y ^ INT_MIN);
    int pos_ovf = !(x & m) && (y & m) && (sub & m);
    int neg_ovf = (x & m) && !(y & m) && !(sub & m);

    // (is_tmin && (sub = INT_MAX) || pos_ovf && (sub = INT_MAX) || neg_ovf && (sub = INT_MIN));
    return !(is_tmin || pos_ovf || neg_ovf);
}

int main(int argc, char *argv[])
{

    assert(!tsub_ok(0x00, INT_MIN));
    assert(tsub_ok(0x00, 0x00));
}