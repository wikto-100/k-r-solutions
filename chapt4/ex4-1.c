/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.
*/
#include <stdio.h>
#define MAXLINE 128
int _getline(char line[], int lim)
{
    int c, i;
    i = 0;
    while (--lim >= 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}
// returns rightmost occurence of t in s
int strindex(char s[], char t[])
{
    int i, j, k;
    int n, m;
    n = 0;
    m = 0;
    while (s[n] != '\0')
        ++n;
    while (t[m] != '\0')
        ++m;
    for (i = n - 1; i >= 0; i--)
    {
        for (j = i, k = m - 1; k >= 0 && j >= 0 && s[j] == t[k]; j--, k--)
            ;
        if (k == -1)
            return i - m + 1;
    }
    return -1;
}
int main()
{
    char line[MAXLINE];
    char pattern[] = "a";
    while (_getline(line, MAXLINE) > 0)
    {
        int i = strindex(line, pattern);
        printf("(at %d) %s", i, i >= 0 ? line : "not there\n");
    }

    return 0;
}