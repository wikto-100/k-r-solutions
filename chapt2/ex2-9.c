/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.
*/

/*
1. explanation
x &= (x-1) <=> x = x & (x-1)
let k be the minimum bit position s.t. x_k = 1, then
x = [(x_n) (x_{n-1}) ... (x_{k+1}) (1) (0) (0) ... (0)],
notice in 2's complement,
x - 1 = x + [(1) (1) ... (1) (1)],
performing the addition
        (1)     (1)           (1)
    (x_n) (x_{n-1}) ... (x_{k+1}) (1) (0) (0) ... (0)
+     (1)       (1) ...       (1) (1) (1) (1) ... (1)
-------------------------------------------------
    (x_n) (x_{n-1}) ... (x_{k+1}) (0) (1) (1) ... (1)
the k-th bit produces a carry value of 1,
regardless of value of x_{k+1}...x_n, a carry chain of 2 1-bits is created.
therefore bits on the left of k-th bit remain unchanged
then, performing the operation x = x & (x-1) yields
x = (x_n) (x_{n-1}) ... (x_{k+1}) (0) (0) (0) ...  (0)
                               ^-- k-th bit
since k was defined as the rightmost 1 bit, and it is now 0
hence this correctly explains this behaviour
*/
#include <stdio.h>
int bitcount(unsigned x)
{
    if (x == 0)
        return 0;
    int res = 0;
    // this version is faster since
    // the operation x &= (x - 1) is performed |{x_i in x : x_i=1}-1| times
    while (x &= (x - 1))
        ++res;
    return res + 1;
}
int main()
{

    unsigned x = 2137;
    printf("%d\n", bitcount(x)); // expected: 5 (100001011001)
}