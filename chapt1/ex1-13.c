/*
Exercise 1-13: build a histogram of word lengths from the input. Horizontal
bars are the easy version; vertical bars are the harder one.
Author: Wiktor Stojek
*/
#include <stdio.h>
#define IN 1
#define OUT 0
int main()
{

    int c, state, nw;
    int w_lens[128];
    int i;
    nw = 0;
    state = OUT;
    for (i = 0; i < 128; i++)
        w_lens[i] = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
                ++nw;
            state = OUT;
        }
        else
        {
            state = IN;
            ++w_lens[nw];
        }
    }
    if (state == IN)
    {
        putchar('\n');
        nw++;
    }
    printf("--- Word length histogram ---\n");
    printf("#:\tlength\n");
    for (i = 0; i < nw; i++)
    {
        printf("%d:\t", i + 1);
        for (int j = 0; j < w_lens[i]; j++)
        {
            putchar('=');
        }
        putchar('\n');
    }
    return 0;
}