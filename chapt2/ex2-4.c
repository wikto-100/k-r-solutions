/*
Exercise 2-4.
Write another version of squeeze(s1, s2) that removes from s1 every character that also appears in s2.
Author: Wiktor Stojek
*/
#include <stdio.h>
#include <limits.h>
// for reference
void sq(char s[], char c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    // characters in s2 to be deleted from s1
    char tbd[UCHAR_MAX + 1];

    // initially keep every character (initialize memory to 0)
    for (k = 0; k < UCHAR_MAX + 1; k++)
        tbd[k] = 0;

    // mark character codes extant in s2
    for (k = 0; s2[k] != '\0'; k++)
        tbd[(unsigned char)s2[k]] = 1;

    // copy only characters not marked
    for (i = j = 0; s1[i] != '\0'; i++)
        if (!tbd[(unsigned char)s1[i]])
            s1[j++] = s1[i];

    s1[j] = '\0';
    // time complexity is O(n + m)
}
int main()
{
    char qbf[] = "the quick brown fox jumps over lazy dog\n";
    squeeze(qbf, "tqbfjol");
    printf("%s", qbf); // expected: he uick rwn x umps ver azy dg\n
    return 0;
}