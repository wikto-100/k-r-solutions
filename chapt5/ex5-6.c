/*
Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
(Chapter 4).
*/
#include <stdio.h>
#include <ctype.h>
#define MAXALLOC 10000
#define MAXLINE 128
static char allocbuf[MAXALLOC];
static char *allocp = allocbuf;
// getlineX atoiX itoaX reverseX strindex getop

int get_line(char *l, int lim)
{
    int c, n;
    n = 0;
    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *l++ = c;
        n++;
    }
    if (c == '\n')
    {
        *l++ = c;
        n++;
    }
    *l = '\0';
    return n;
}
void reverse(char *s)
{
    char *e, *b;
    b = e = s;
    while (*e)
        e++; // e should be at '\0' (s[n]) s is at s[0]
    if (e == b)
        return;
    while (b < --e)
    {
        char t = *b;
        *b = *e;
        *e = t;
        b++;
    }
}
int atoi(char *s)
{
    int val = 0;
    while (isspace(*s))
        s++;
    while (isdigit(*s))
    {
        val = 10 * val + (*s - '0');
        s++;
    }
    return val;
}
void itoa(int n, char *s)
{
    int sign = n;
    char *p = s;
    if (n > 0)
        n = -n;
    do
    {
        *p++ = -(n % 10) + '0';
    } while ((n /= 10) < 0);
    if (sign < 0)
    {
        *p++ = '-';
    }
    *p = '\0';
    reverse(s);
}
int strindex(char *s, char *t)
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
int getop(char *s)
{
    int c;
    int isnum;
    isnum = 0;
    do
    {
        c = getch();
        *s = c;
    } while (c == ' ' || c == '\t'); // skip leading whitespace
    *(s + 1) = '\0'; // because need to obtain a single operand like * + - / %...

    if (isalpha(c) && islower(c))
        return c;
    if (!isdigit(c) && c != '.' && c != '-') // could be .04343
        return c;                            // operand (not a number)

    // here we may have negative
    if (c == '-')
    {
        c = getch();
        *++s = c;
    }
    if (isdigit(c))
    {
        isnum = 1;
        do
        {
            c = getch();
            *++s = c;
        } while (isdigit(c));
    }
    if (c == '.')
    {
        // collect fractional part
        do
        {
            c = getch();
            if (isdigit(c))
                isnum = 1;
            *++s = c;
        } while (isdigit(c));
    }
    *s = '\0';

    ungetch(c);
    return isnum ? 0 : '-';
}
int main()
{
    char *alloc(size_t);
    void afree(char *);
    char *line = alloc(MAXLINE);
    char *line2 = alloc(MAXLINE);
    get_line(line, MAXLINE);
    int num = atoi(line);
    itoa(num, line2);
    printf("line=%s num=%d\n", line, num);
    printf("itoa(line)=%s\n", line2);

    afree(line2);
    afree(line);
}

char *alloc(size_t n)
{
    if (allocp + n >= allocbuf + MAXALLOC)
        return 0;
    allocp += n;
    return allocp - n;
}
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + MAXALLOC)
        allocp = p;
}