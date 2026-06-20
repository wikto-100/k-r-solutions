/*
Exercise 1-6: confirm that the comparison getchar() != EOF always evaluates
to exactly 0 or 1.
Author: Wiktor Stojek
*/
#include <stdio.h>

int main()
{
    int c = getchar() != EOF;
    printf("%d\n", c);
}