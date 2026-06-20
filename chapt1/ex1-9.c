/*
Exercise 1-9: copy input to output, collapsing every run of consecutive blanks
into a single blank.
Author: Wiktor Stojek
*/
#include <stdio.h>
int main()
{
    int c;
    int blc = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t' || c == ' ')
        {
            blc++;
            continue;
        }
        if(blc > 0) putchar(' ');
        putchar(c);
        blc = 0;
    }
    return 0;
}