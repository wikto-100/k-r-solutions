/*
Exercise 1-24: scan a C source file for basic structural mistakes, like
mismatched parens/brackets/braces, while correctly skipping over quotes,
escape sequences, and comments.
Author: Wiktor Stojek
*/
#include <stdio.h>
int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        // unmatched parenths
        // im leaving this one out for now, will come back later
    }
    return 0;
}