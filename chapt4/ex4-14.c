/*
Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.)
*/
#include <stdio.h>
#define swap(t, x, y)           \
    do                          \
    {                           \
        t __tmp;                \
        typeof(x) __x;          \
        typeof(y) __y;          \
        (void)(&__x == &__y);   \
        (void)(&__tmp == &__x); \
        (__tmp) = (x);          \
        (x) = (y);              \
        (y) = (__tmp);          \
    } while (0)

void reverse(char s[])
{
    int n, i;
    for (n = 0; s[n] != '\0'; n++)
        ;
    for (i = 0; i < n / 2; i++)
        swap(char, s[i], s[n - i - 1]);
}

int main()
{

    char *sp = "abcdefghijklmnoprstuwxyz";
    char *srp = "zyxwutsrponmlkjihgfedcba";

    char s[26] = "abcdefghijklmnoprstuwxyz";
    printf("%s\n", sp);
    swap(char *, sp, srp);
    printf("%s\n", sp);
    reverse(s);
    printf("%s\n", s);

    return 0;
}