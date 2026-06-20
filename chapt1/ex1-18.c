/*
Exercise 1-18: strip trailing spaces/tabs from each line of input, and drop
lines that end up entirely blank.
Author: Wiktor Stojek
*/
#include <stdio.h>
int getline_tr(char line[], int lim)
{

    int c;
    int len;

    for (len = 0; len < (lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); len++)
        line[len] = c;

    /* shrink len back past any trailing blanks/tabs, effectively trimming them */
    while ((len > 0) && (line[len - 1] == '\t' || line[len - 1] == ' '))
    {
        len--;
    }

    if (c == '\n')
    {
        line[len] = '\n';
        len++;
    }

    line[len] = '\0';

    return len;
}
int main()
{
    char line[128];
    int len = 0;
    while (len = getline_tr(line, 128))
    {
        /* nothing left but the newline means the line was entirely blank: drop it */
        if (line[len - 1] == '\n' && len == 1)
        {
            printf("Line deleted\n");
            continue;
        }
        printf("Line (%d): %s", len, line);
    }
    return 0;
}