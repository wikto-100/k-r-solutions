/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
Author: Wiktor Stojek
*/
#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    /*
    This expression may look like a wizard spell, but it is simple really
    the left part of | clears the p..(p-n+1) bits of x
    the right part of | selects the n rightmost bits of y and "shifts them into place"
    let me explain starting from the left part
    ~0u << n will set the register to all 1's except for the rightmost n bits
    so ~(~0u << n) will set the register to 0's except for the rightmost n bits
    then shifting that left by p-n+1 will move these n 1's into positions p..(p-n+1) creating a "mask"
    notice that the rest of the register outside of p..(p-n+1) still remains all 0's
    then we need to negate that "mask" since we want to zero out that part p..(p-n+1)
    in order to free it up for the bits of y so there's no mixup after the | operation
    doing an & operation with x and the "mask" will do exactly that
    now the right part is simpler, we already know what ~(~0u << n) does
    doing y & ~(~0u << n) will then select the n rightmost bits of y
    then these bits need to be shifted into that gap we made with &'ing x with the mask
    then the | operation places the bits of y into that p..(p-n+1) gap of 0's in x.
    */
    return (x & ~(~(~0u << n) << (p - n + 1))) | ((y & ~(~0u << n)) << (p - n + 1));
}
int main()
{

    unsigned x = 0xDEADBEEF;
    unsigned y = 0xCAFEBABE;
    int n = 12;
    int p = 11;
    printf("0x%x\n", setbits(x, p, n, y)); // expected: 0xdeadbabe

    return 0;
}