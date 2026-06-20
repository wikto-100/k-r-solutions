/*
Exercise 1-9: copy input to output, collapsing every run of consecutive blanks
into a single blank.
Author: Wiktor Stojek
*/
#include <stdio.h>
int main()
{
    int c;
    int blc = 0; /* count of consecutive blanks/tabs seen so far */

    while ((c = getchar()) != EOF)
    {
        if (c == '\t' || c == ' ')
        {
            /* omit the blanks/tabs sequence, just remember count */
            blc++;
            continue;
        }
        /* a sequence of blanks/tabs just ended: emit a single space for it */
        if(blc > 0) putchar(' ');
        putchar(c);
        blc = 0;
    }
    return 0;
}