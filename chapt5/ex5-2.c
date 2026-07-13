/*
Exercise 5-2. Write getfloat, the floating-point analog of getint.
What type does getfloat return as its function value?
*/
#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 128
int bufp;
int buf[BUFSIZE];
int getch()
{
    if (bufp > 0)
        return buf[--bufp];
    return getchar();
}
void ungetch(int c)
{
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("ungetch():\tbuffer full, cannot unget %d\n", c);
}
int getfloat(float *pn)
{
    int c, sign;
    float power;
    while (isspace(c = getch()))
        ;                                                            // consume initial whitespace
    if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') // NaN
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') // consume sign
    {
        int t = c;
        c = getch();
        if (!isdigit(c) && c != '.')
        {
            if (c != EOF)
                ungetch(c);

            ungetch(t);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) // get value
        *pn = 10 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = *pn * 10 + (c - '0');
        power *= 10;
    }
    *pn *= sign / power; // apply sign
    if (c != EOF)
        ungetch(c); // dont remove additional characters from input
    return c;       // last character of input
}

int main()
{

    float val = 0;
    int lastc = 0;
    while (lastc != EOF)
    {
        lastc = getfloat(&val);
        if (lastc == 0)
            getch();
        else
            printf("number: %g, last character ASCII %d\n", val, lastc);
    }
    return 0;
}