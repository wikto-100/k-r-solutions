/*
Exercise 1-12: print each word of the input on its own line.
Author: Wiktor Stojek
*/
#include <stdio.h>
#define IN 1
#define OUT 0
int main()
{
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF)
    {
        // if a character is blank
        if (c == ' ' || c == '\t' || c == '\n')
        {
            // the word just ended, print a newline
            if (state == IN)
            {
                putchar('\n');
            }
            // whenever we are encountering blank input, we are out of word
            state = OUT;
        }
        else // if its not a blank then just print it, and we are in the word
        {
            putchar(c);
            state = IN;
        }
    }
    return 0;
}