/*
Exercise 1-6: confirm that the comparison getchar() != EOF always evaluates
to exactly 0 or 1.
Author: Wiktor Stojek
*/
#include <stdio.h>

int main()
{
    /* relational expression evaluates to 1 (true) or 0 (false) */
    int c = getchar() != EOF;
    printf("%d\n", c);
}