/*
Exercise 2-5.
Write any(s1, s2), a function that returns the index of the first character in s1
that also appears in s2. Return -1 if no character from s2 is found in s1.
The standard library function strpbrk performs a similar search, but returns
a pointer to the matching character instead of its index.

Author: Wiktor Stojek
*/
#include <stdio.h>
#include <limits.h>
int any(char s1[], char s2[])
{
    // similar idea as in ex2-4
    // the code explains itself
    int i, k;
    // characters in s2
    char s2_has[UCHAR_MAX + 1];

    for (k = 0; k < UCHAR_MAX + 1; k++)
        s2_has[k] = 0;

    for (k = 0; s2[k] != '\0'; k++)
        s2_has[(unsigned char)s2[k]] = 1;

    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s2_has[(unsigned char)s1[i]])
            return i;
    }
    return -1;
}
int main()
{
    int a = any("abcdefg", "efg");
    int b = any("abcdefg", "z");

    printf("%d %d\n", a, b); // expected: 4 -1

    return 0;
}