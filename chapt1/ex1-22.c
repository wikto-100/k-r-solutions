/*
Exercise 1-22: wrap long input lines after the last non-blank character
before column n, and handle the edge cases sensibly - very long lines, or
no blank/tab to break on before that column.
Author: Wiktor Stojek
*/
#include <stdio.h>

/* columns remaining from col to the next tab stop (tabs every 8 columns) */
int tabspace(int col)
{
    int tab = 8;
    return tab - ((col - 1) % tab);
}
int main()
{
    int c;
    int col = 1;
    int blank = 0;
    int n = 4;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            col = 1;
            blank = 0;
            putchar(c);
        }
        else if (c == ' ')
        {
            /* defer emitting the blank: it might end up being the fold point instead */
            blank++;
        }
        else if (c == '\t')
        {
            blank += tabspace(col + blank);
        }
        else
        {
            /* fold point: accumulated blanks for this line + current column
               would exceed the fold line (also when blank=0)
               then need to fold */
            if (col + blank > n)
            {
                col = 1;
                blank = 0;
                putchar('\n');
            }
            /* no fold needed yet: now actually emit the pending blanks before this character */
            while (blank > 0)
            {
                putchar(' ');
                col++;
                blank--;
            }
            col++;
            putchar(c);
        }
    }
    return 0;
}