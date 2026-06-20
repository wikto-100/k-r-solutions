/*
Exercise 1-21: implement entab, the inverse of detab - replace runs of spaces
with the fewest tabs and spaces needed to land on the same column, using the
same tab stops.
Author: Wiktor Stojek
*/
#include <stdio.h>
#define OUT 1
#define IN 0
/* emits tabs/spaces to cover columns beg..end-1, preferring a tab whenever it actually saves space */
void entab(int beg, int end, int n)
{
    // tabstops inside beg--end
    while (beg < end)
    {
        /* a tab here would only reach the next column (no savings) or overshoot end: use a space instead */
        if ((n - (beg - 1) % n) == 1 || (n - (beg - 1) % n) > end - beg)
        {
            putchar(' ');
            beg++;
        }
        else
        {
            putchar('\t');
            beg += n - (beg - 1) % n;
        }
    }
}
int main()
{
    int c;
    int n;
    int beg, col;
    int state;
    col = 1;
    n = 8;
    beg = 0;
    state = IN;
    // any blank fills to the next tab stop
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            if (state == OUT)
                entab(beg, col, n);
            col = 1;
            state = IN;
            putchar(c);
        }
        else if (c == '\t')
        {
            /* entering a run of whitespace: remember where it started */
            if (state == IN)
                beg = col;
            col += n - ((col - 1) % n);
            state = OUT;
        }
        else if (c == ' ')
        {
            if (state == IN)
                beg = col;
            state = OUT;
            col++;
        }
        else
        {
            /* leaving whitespace (or starting fresh): flush the pending run as tabs/spaces first */
            if (state == OUT)
                entab(beg, col, n);
            col++;
            state = IN;
            putchar(c);
        }
    }
    /* flush any whitespace run still pending when input ends */
    if (state == OUT)
        entab(beg, col, n);

    return 0;
}