/*
Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.
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

int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;                                                // consume initial whitespace
    if (!isdigit(c) && c != EOF && c != '-' && c != '+') // NaN
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') // consume sign
    {
        int t = c;
        c = getch();
        if (!isdigit(c))
        {
            if (c != EOF)
                ungetch(c);

            ungetch(t);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) // get value
        *pn = 10 * *pn + (c - '0');
    *pn *= sign; // apply sign
    if (c != EOF)
        ungetch(c); // dont remove additional characters from input
    return c;       // last character of input
}

int main()
{

    int val = 0;
    int lastc = 0;
    while (lastc != EOF)
    {
        lastc = getint(&val);
        if (lastc == 0)
            getch();
        else
            printf("number: %d, last character ASCII %d\n", val, lastc);
    }
    return 0;
}