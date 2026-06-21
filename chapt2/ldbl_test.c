/*
Helper for ex2-1.c.

The exercise asks us to derive long double's min/max,
but the standard gives no portable name for its raw storage layout.
This dumps the actual bytes behind LDBL_MIN/LDBL_MAX on this machine 
(x86-64 glibc: 80-bit extended precision padded to 16 bytes) 
so we know which bytes are the mantissa, which are the exponent+sign,
and which are unused padding - then rebuilds each value
from a byte array to confirm the layout is understood
correctly before reusing the same trick in ex2-1.c.
*/
#include <stdio.h>
#include <float.h>

void print_bytes(long double x)
{
    unsigned char *p = (unsigned char *)&x;

    printf("%Le\n", x);
    printf("sizeof(long double) = %zu\n", sizeof x);

    for (size_t i = 0; i < sizeof x; ++i)
        printf("%02X ", p[i]);

    putchar('\n');
}

int main(void)
{
    long double x = LDBL_MIN;

    printf("LDBL_MIN:\n");
    print_bytes(x);

    unsigned char pure_evil_min[16] = {
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80,
        0x01, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00};

    long double y = *(long double *)pure_evil_min;

    printf("constructed LDBL_MIN:\n");
    printf("%Le\n\n", y);

    long double max = LDBL_MAX;

    printf("LDBL_MAX:\n");
    print_bytes(max);

    unsigned char pure_evil_max[16] = {
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFE, 0x7F,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00};

    long double z = *(long double *)pure_evil_max;

    printf("constructed LDBL_MAX:\n");
    printf("%Le\n", z);

    return 0;
}