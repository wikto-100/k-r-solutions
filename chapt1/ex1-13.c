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
    /* see ex1-20.c */
    int c, state, nw;
    int w_lens[128];
    int i;
    nw = 0;
    state = OUT;
    /* zero out the length-bucket array before counting */
    for (i = 0; i < 128; i++)
        w_lens[i] = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            /* if transitioned from non-whitespace
               to whitespace => the word just ended
               count the word
            */
            if (state == IN)
                ++nw;
            state = OUT;
        }
        else
        {
            state = IN;
            /* count the current word's length
               the current word corresponds to index nw,
               because we are counting words
            */
            ++w_lens[nw];
        }
    }
    if (state == IN)
    {
        /* input ended mid-word; count it too */
        putchar('\n');
        nw++;
    }
    /* horizontal histogram */
    printf("--- Word length histogram ---\n");
    printf("#:\tlength\n");
    /* one row per word, in input order; bar length equals that word's character count */
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