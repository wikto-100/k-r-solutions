/*
Exercise 1-10: copy input to output, but make whitespace visible by spelling
out tabs as \t, backspaces as \b, and literal backslashes as \\.
Author: Wiktor Stojek
*/

#include <stdio.h>

int main()
{

    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
    return 0;
}