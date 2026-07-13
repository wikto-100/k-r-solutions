/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.
*/
#include <stdio.h>
#include <string.h>
void reverse(char s[])
{
    int n, i, t;
    n = strlen(s);
    for (i = 0; i < n / 2; i++)
    {
        t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
}
void itoa(int n, char s[], int pad)
{
    int sign, i;
    i = 0;
    sign = n < 0;
    if (sign == 0)
        n = -n;
    do
    {
        s[i++] = -(n % 10) + '0';
    } while ((n /= 10) < 0);
    if (sign)
    {
        s[i++] = '-';
    }
    while (i < pad)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}
int main()
{
    char numc[100];
    int mi = 42;
    int pad = 10;
    itoa(mi, numc, pad);
    printf("%s\n", numc);
    return 0;
}