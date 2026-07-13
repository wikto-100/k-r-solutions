/*
Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable.
*/
#include "calc.h"
// getop implementation
int getop(char s[])
{
    // post is the storage simulating buf and bufp at once
    // initialized once to 0
    // if getop is called again this does nothing
    static int post = 0;
    int i, c;
    int isnum;
    i = 0;
    isnum = 0;
    do
    {
        // if a pushback occurs
        if (post)
        {
            // get whats at the pushback value
            c = post;
            // unset it
            post = 0;
        }
        else
            c = getchar();
        s[0] = c;
    } while (c == ' ' || c == '\t'); // skip leading whitespace
    s[1] = '\0'; // because need to obtain a single operand like * + - / %...

    if (isalpha(c) && islower(c))
        return c;
    if (!isdigit(c) && c != '.' && c != '-') // could be .04343
        return c;                            // operand (not a number)

    // here we may have negative
    if (c == '-')
    {
        c = getchar();
        s[++i] = c;
    }
    if (isdigit(c))
    {
        isnum = 1;
        do
        {
            c = getchar();
            s[++i] = c;
        } while (isdigit(c));
    }
    if (c == '.')
    {
        // collect fractional part
        do
        {
            c = getchar();
            if (isdigit(c))
                isnum = 1;
            s[++i] = c;
        } while (isdigit(c));
    }
    s[i] = '\0';

    // if there was not a pushback yet
    if (!post && c != EOF)
        // then do a pushback (im losing my mind)
        post = c;
    return isnum ? '0' : '-';
}