/*
Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
*/
#include <stdio.h>
void strn_cpy(char *s, char *t, size_t n)
{
    while (n-- && (*s++ = *t++))
        ;
}
void strn_cat(char *s, char *t, size_t n)
{
    // concat first n characters from t to s
    while (*s)
        s++; // skip to null terminator

    while (n-- && *t)
        *s++ = *t++;
    *s = '\0';
}
int strn_cmp(char *s, char *t, size_t n)
{
    while (n > 0 && *s == *t)
    {
        if (*s == '\0')
            return 0;
        s++;
        t++;
        n--;
    }
    return n == 0 ? 0 : *s - *t;
}
int main()
{
    char s[] = "efgh", t[] = "abcd";
    strn_cpy(s, t, 2); // abgh
    strn_cat(s, t, 0); // abgha
    int d = strn_cmp(s, t, 3);

    printf("%s diff: %d (%c - %c)\n", s, d, s[2], t[2]);
}