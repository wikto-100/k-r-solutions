/*
Exercise 1-16: fix the longest-line program so it handles lines of any
length correctly, printing as much of the text as it can.
Author: Wiktor Stojek
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 16
int _getline(char line[], int lim)
{

    int c, len;
    len = 0;
    for (len; len < (lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); len++)
        line[len] = c;

    if (c == '\n')
    {
        line[len] = '\n';
        len++;
    }
    line[len] = '\0';

    return len;
}
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
int main()
{
    char line[MAXLEN];
    char *buf = malloc(MAXLEN);
    char *longest = malloc(MAXLEN);
    int cur_len = 0;
    int len, ml;
    len = ml = 0;
    int state = 0;

    while (len = _getline(line, MAXLEN))
    {
        //printf("Line: %s\n", line);
        char last = line[len - 1];
        //printf("Last: %c\n", last);

        if (last != '\n' && len == MAXLEN - 1)
        {
            buf = realloc(buf, (cur_len + len + 1));
            copy((buf + cur_len), line);
            cur_len += len;
        }
        else
        {
            buf = realloc(buf, (cur_len + len + 1));
            copy((buf + cur_len), line);

            //printf("cur_len: %d\n", cur_len + len);
            //printf("buf: %s\n", buf);

            if (cur_len + len > ml)
            {
                ml = cur_len + len;
                longest = realloc(longest, (ml + 1));
                copy(longest, buf);
            }
            cur_len = 0;
        }
    }
    if (cur_len > 0)
    {
        if (cur_len > ml)
        {
            ml = cur_len;
            longest = realloc(longest, (ml + 1));
            copy(longest, buf);
        }
    }
    if (ml > 0)
    {
        printf("Longest line (%d): %s\n", ml, longest);
    }
    return 0;
}