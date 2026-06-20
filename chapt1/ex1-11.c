/*
Exercise 1-11: think through how you'd test the word-count program below -
which inputs are most likely to expose bugs?
Author: Wiktor Stojek
*/
#include <stdio.h>
// wc program
#define IN 1
#define OUT 0

int main()
{

    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc; /* count all characters */
        if (c == '\n')
            ++nl; /* count newlines */
        if (c == '\t' || c == ' ' || c == '\n') // ignore whitespace 
        // change state
            state = OUT;
        else if (state == OUT)
        {
            /* a word occurs whenever there is
               a transition from whitespace to non-whitespace
            */
            ++nw; /*count words*/
            state = IN;
        }
    }
    printf("%d %d %d\n", nc, nw, nl);
    return 0;
}
// example: trailing, leading whitespace
//       a           
// example: empty input
//
// example: only whitespace
//                          
// etc.