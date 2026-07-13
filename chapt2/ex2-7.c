/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
Author: Wiktor Stojek
*/
#include <stdio.h>
unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ~(~0u << n) << (p - n + 1);
    // (x & ~mask) | (~x & mask) = x ^ mask
    return x ^ mask;
}
int main()
{
    unsigned x = 0xdeadbabf;
    x = invert(x, 11, 8);
    printf("inverted: 0x%08x\n", x);
    return 0;
}