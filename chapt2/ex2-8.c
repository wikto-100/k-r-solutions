/*
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.
 */
#include <stdio.h>
unsigned rightrot(unsigned x, int n)
{
    unsigned mask = x & ~(~0u << n);
    return (x >> n) | (mask << (32 - n)); // only place mask left
}
int main()
{
    unsigned x = 0xFACEB00C;
    int n = 16;
    x = rightrot(x, n);
    printf("x rotated by %d bit(s): 0x%08x\n", n, x);
    return 0;
}