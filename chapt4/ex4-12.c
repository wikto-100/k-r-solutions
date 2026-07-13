#include <stdio.h>
static int n; // in some other compilation unit
static void itoa_r(int n, char s[])
{
    if (n <= -10)
        itoa_r(n / 10, s);
    s[n++] = -(n % 10) + '0';
} // in some other compilation unit
void itoa(int n, char s[])
{
    n = 0;
    if (n >= 0)
        n = -n;
    else
        s[n++] = '-';
    itoa_r(n, s);
    s[n] = '\0';

} // exposed outside in a header

int main()
{
    int n = -100;
    char s[10];

    itoa(n, s);
    printf("%s\n", s);
    itoa(n, s);
    printf("%s\n", s);

    return 0;
}