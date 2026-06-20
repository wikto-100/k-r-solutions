/*
Exercise 1-7: print out whatever value EOF actually expands to on this system.
Author: Wiktor Stojek
*/
#include <stdio.h>

int main()
{

    int c = getchar();
    if (c == EOF)
        printf("EOF value: %d\n", c);
    else
    {
        printf("is not EOF: %c\n", c);
    }
}