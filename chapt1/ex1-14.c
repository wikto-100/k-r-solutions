/*
Exercise 1-14: build a histogram showing how often each character appears in the input.
Author: Wiktor Stojek
*/
#include <stdio.h>

int main()
{

    int c, i, lc = 0;
    int hist[128]; // assume the input is ASCII
    // set hist to 0
    for (i = 0; i < 128; i++)
        hist[i] = 0;
    while ((c = getchar()) != EOF)
    {
        /* bump the count for this character's bucket, using its ASCII code as index */
        hist[c]++;
        lc = c;
    }
    /* tidy up the terminal if the last input line had no trailing newline */
    if(lc != '\n')
        putchar('\n');
    /* print the histogram while escaping special characters*/
    for (i = 0; i < 128; i++)
    {
        if (hist[i] > 0)
        {
            int code = i;
            /* render newline/tab as their escape form instead of raw control chars */
            if(code == '\n'){
                putchar('\\');
                putchar('n');
            }
            else if(code == '\t'){
                putchar('\\');
                putchar('t');
            }
            else{
                putchar(code);
            }
            putchar(':');
            putchar(' ');
            putchar(' ');

            for(int j = 0; j < hist[i]; j++){
                putchar('=');
            }
            printf(" (%d)\n", hist[i]);
        }
    }
    return 0;
}