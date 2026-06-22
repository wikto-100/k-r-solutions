#include <stdio.h>
/*
Exercise 2-2: rewrite the bounded line-reading loop (stop at lim-1 chars, a
newline, or EOF) so it relies on nested ifs/breaks instead of chaining the
condition with && and ||.
Author: Wiktor Stojek
*/
int main()
{

    int c;
    int i;
    int lim = 128;
    char s[128];
    for (i = 0; i < lim - 1; i++)
    {
        if ((c = getchar()) == '\n')
            break;
        if (c == EOF)
            break;
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    printf("%s", s);

    return 0;
}