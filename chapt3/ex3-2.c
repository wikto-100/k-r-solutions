/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.
*/
#include <stdio.h>
void escape(char t[], char s[])
{
    int i, j, c;
    for (i = j = 0; (c = t[i]) != '\0'; i++)
    {
        switch (c)
        {
        case '\\':
            s[j++] = '\\';
            s[j++] = '\\';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\b':
            s[j++] = '\\';
            s[j++] = 'b';
            break;
        default:
            s[j++] = c;
            break;
        };
    }
    s[j] = '\0';
}
void unescape(char t[], char s[])
{
    int i, j, c;
    int is_esc = 0;
    for (i = j = 0; (c = t[i]) != '\0'; i++)
    {
        if (is_esc)
        {
            switch (c)
            {
            case '\\':
                s[j++] = '\\';
                break;
            case 't':
                s[j++] = '\t';
                break;
            case 'n':
                s[j++] = '\n';
                break;
            case 'b':
                s[j++] = '\b';
                break;
            }
            is_esc = 0;
        }
        else if (c == '\\')
            is_esc = 1;
        else
            s[j++] = c;
    }
    if (is_esc)
        s[j++] = '\\';
    s[j] = '\0';
}
int main()
{
    char t[] = "test\tstr\bing\\";
    char s[100];
    char z[100];

    escape(t, s);
    printf("input: %s\n", t);
    printf("output: %s\n", s);
    unescape(s, z);
    printf("input: %s\n", s);
    printf("output: %s\n", z);

    return 0;
}