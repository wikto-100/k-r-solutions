/*
Exercise 1-23: strip comments out of a C source file, while still handling
quoted strings and character constants correctly (comments don't nest).
Author: Wiktor Stojek
*/
#include <stdio.h>
#define PRINT 0
#define SLASH 1
#define SLCOMMENT 2
#define QUOTE 3
#define MLCOMMENT 4
#define CHAR 5
int main()
{
    int c;
    int last = 0;
    int is_escaped = 0;
    int state = PRINT;
    while ((c = getchar()) != EOF)
    {
        if (state == PRINT)
        {
            if (c == '/')
            {
                state = SLASH;
            }
            else if (c == '\'')
            {
                state = CHAR;
                putchar(c);
            }
            else if (c == '\"')
            {
                state = QUOTE;
                putchar(c);
            }
            else
            {
                putchar(c);
                state = PRINT;
            }
        }
        else if (state == QUOTE)
        {
            if (is_escaped)
            {
                putchar(c);
                state = QUOTE;
                is_escaped = 0;
            }
            else
            {
                is_escaped = (c == '\\');

                if (c == '\"')
                {
                    putchar(c);
                    state = PRINT;
                }
                else
                {
                    putchar(c);
                    state = QUOTE;
                }
            }
        }
        else if (state == CHAR)
        {
            if (is_escaped)
            {
                is_escaped = 0;
                state = CHAR;
                putchar(c);
            }
            else
            {
                is_escaped = (c == '\\');

                if (c == '\'')
                {
                    putchar(c);
                    state = PRINT;
                }
                else
                {
                    putchar(c);
                    state = CHAR;
                }
            }
        }
        else if (state == SLASH)
        {
            if (c == '/')
                state = SLCOMMENT;
            else if (c == '*')
                state = MLCOMMENT;
            else
            {
                putchar(last);
                putchar(c);
                state = PRINT;
            }
        }
        else if (state == SLCOMMENT)
        {
            if (c == '\n')
            {
                putchar(c);
                state = PRINT;
            }
            else
                state = SLCOMMENT;
        }
        else if (state == MLCOMMENT)
        {
            if (c == '/' && last == '*')
            {
                putchar(' ');
                state = PRINT;
            }
            else
                state = MLCOMMENT;
            if (c == '\n')
                putchar(c);
        }
        last = c;
    }
    return 0;
}