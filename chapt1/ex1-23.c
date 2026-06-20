/*
Exercise 1-23: strip comments out of a C source file, while still handling
quoted strings and character constants correctly (comments don't nest).
Author: Wiktor Stojek
*/
#include <stdio.h>
#define PRINT 0     /* normal code: pass characters through */
#define SLASH 1     /* just saw a single '/', deciding if it starts a comment */
#define SLCOMMENT 2 /* inside a // comment, omitting until newline */
#define QUOTE 3     /* inside a "..." string literal */
#define MLCOMMENT 4 /* inside a slash-star comment, omitting until star-slash */
#define CHAR 5      /* inside a '...' character constant */
int main()
{
    int c;
    int last = 0; /* previous character, needed to detect a closing star-slash and a deferred slash */
    int is_escaped = 0;
    int state = PRINT;
    while ((c = getchar()) != EOF)
    {
        if (state == PRINT)
        {
            /* a slash might just be division, or the start of // or a comment: hold off printing it */
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
                /* turned out not to be a comment after all: print the held-back slash plus this char */
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
            /* the closing marker just completed: end the comment, replacing it with one space */
            if (c == '/' && last == '*')
            {
                putchar(' ');
                state = PRINT;
            }
            else
                state = MLCOMMENT;
            /* preserve newlines inside the comment so line numbers downstream stay accurate */
            if (c == '\n')
                putchar(c);
        }
        last = c;
    }
    return 0;
}