/*
Exercise 1-14: build a histogram showing how often each character appears in the input.
Author: Wiktor Stojek
*/
#include <stdio.h>

int main()
{

    int c, i, lc = 0;
    int hist[128];
    // set hist to 0
    for (i = 0; i < 128; i++)
        hist[i] = 0;
    while ((c = getchar()) != EOF)
    {
        hist[c]++;
        lc = c;
    }
    if(lc != '\n')
        putchar('\n');
    for (i = 0; i < 128; i++)
    {
        if (hist[i] > 0)
        {
            int code = i;
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