/*
Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.
*/
#include <stdio.h>
void reverse(char s[])
{
    int n;
    int i;
    n = 0;
    while (s[n] != '\0')
        n++;
    for (i = 0; i < n / 2; i++)
    {
        int t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
}
void itoa(int n, char s[])
{
    int i = 0;
    int sign = n;
    if (n > 0)
        n = -n;
    do
    {
        s[i++] = -(n % 10) + '0';
    } while ((n /= 10) < 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
// i find this very annoying.
// the reason it wouldnt work is
// -0x80000000 = 0x7fffffff + 1 = overflow, ub. so no effect
// solution? dont invert n sign if negative, but do if positive

int main()
{
    char numc[100];
    int mi = 0x80000000;
    itoa(mi, numc);
    printf("%d: %s\n", mi, numc);
    return 0;
}