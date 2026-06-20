/*
Exercise 1-22: wrap long input lines after the last non-blank character
before column n, and handle the edge cases sensibly - very long lines, or
no blank/tab to break on before that column.
Author: Wiktor Stojek
*/
#include <stdio.h>

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
            blank++;
        }
        else if (c == '\t')
        {
            blank += tabspace(col + blank);
        }
        else
        {
            // if we add col + blank > n then we need to insert newline
            if (col + blank > n)
            {
                col = 1;
                blank = 0;
                putchar('\n');
            }
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