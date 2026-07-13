/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.
*/
#include <stdio.h>
void reverse(char s[])
{
    int n, i, t;
    n = 0;
    while (s[n] != '\0')
        n++;
    for (i = 0; i < n / 2; i++)
    {
        t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
}
void itob(int n, char s[], int b)
{
    // 0-9a-f
    int sign, i;
    sign = n < 0;
    i = 0;

    if (sign == 0)
        n = -n;
    if (b == 1)
    {
        do
            s[i++] = '0';
        while (++n < 0);
        if (sign == 1)
            s[i++] = '-';

        s[i] = '\0';
        reverse(s);
        return;
    }
    else if (b > 36 || b <= 0)
    {
        s[0] = '\0';
        return;
    }
    do
    {
        int dig = -(n % b);
        if (dig < 10)
            s[i++] = dig + '0';
        else if (dig >= 10)
            s[i++] = dig + 'W';

    } while ((n /= b) < 0);
    if (sign == 1)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main()
{

    int x = -111;
    int b = 10;
    char res[128];
    itob(x, res, b);
    printf("%s\n", res);
    return 0;
}