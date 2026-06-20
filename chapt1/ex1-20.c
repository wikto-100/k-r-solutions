/*
Exercise 1-20: implement detab, expanding each input tab into the right
number of spaces to reach the next fixed-width tab stop (every n columns).
Author: Wiktor Stojek
*/
#include <stdio.h>

int main()
{

    int c, col, n, spaces;
    col = 1;
    n = 4;
    spaces = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            col = 1;
            putchar('\n');
        }
        else if (c == '\t')
        {

            spaces = n - ((col - 1) % n);
            while (spaces-- > 0)
            {
                col++;
                putchar(' ');
            }
        }
        else
        {
            col++;
            putchar(c);
        }
    }

    return 0;
}