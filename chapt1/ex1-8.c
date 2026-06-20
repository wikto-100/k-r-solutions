/*
Exercise 1-8: count how many space characters, tabs, and newlines show up in the input.
Author: Wiktor Stojek
*/
#include <stdio.h>

int main()
{
    int c;
    int blc = 0;
    int nlc = 0;
    int tabc = 0;
    /* read and classify each character until end of input */
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nlc;
        else if (c == '\t')
            ++tabc;
        else if (c == ' ')
            ++blc;
    }
    printf("#newlines: %d\n", nlc);
    printf("#tabs: %d\n", tabc);
    printf("#blanks: %d\n", blc);

    return 0;
}