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
int strindex_ptr(char *s, char *t)
{
    char *s_ptr, *t_ptr;

    int n, m;
    n = m = 0;
    s_ptr = s;
    t_ptr = t;
    while (*s_ptr)
    {
        n++;
        s_ptr++;
    }
    while (*t_ptr)
    {
        m++;
        t_ptr++;
    }
    if (m == 0)
        return n;
    if (m > n)
        return -1;
    reverse(s);
    reverse(t);
    int match = 0;
    char *s_beg = s;
    while (*s)
    {
        match = 0;
        for (t_ptr = t, s_ptr = s; *s_ptr && *t_ptr; s_ptr++, t_ptr++)
        {
            if (*t_ptr == *s_ptr)
                match++;
            else
                match = 0;
            if (match == m)
            {
                reverse(s_beg);
                reverse(t);
                return n - (s_ptr - s_beg) - 1;
            } // what index was t found in s
        }
        s++;
    }

    reverse(s_beg);
    reverse(t);
    return -1;
}
int strrindex_ptr(const char *s, const char *t)
{
    const char *s_end;
    const char *t_end = t;
    const char *start;
    const char *tp, *sp;

    for (s_end = s; *s_end; s_end++)
        ;
    for (t_end = t; *t_end; t_end++)
        ;

    if (/*length of t == 0*/ t_end == t)
        return (int)(s_end - s);
    if (/*length of s < length of t*/ (s_end - s) < (t_end - t))
        return -1;

    for (/*start looking where t would begin in s*/ start = s_end - (t_end - t); start >= s; start--)
    {
        sp = start;
        tp = t;
        while (*tp && *tp == *sp)
        {
            tp++;
            sp++;
        }

        if (tp == t_end)             // if we got to the end of t with the while loop
            return (int)(start - s); // the index is at start in s (where t begins in s)

        if (/* because the loop condition checks the first character*/ start == s)
            break;
    }
    return -1;
}
int sbuf;
int pushed;
// getch, ungetch implementation
int getch()
{
    if (pushed)
    {
        pushed = 0;
        return sbuf;
    }
    else
        return getchar();
}
void ungetch(int c)
{
    if (pushed)
        printf("ungetch():\ttoo many characters\n");
    else
    {
        pushed = 1;
        sbuf = c;
    }
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

    char *itoares = alloc(MAXLINE);
    get_line(line, MAXLINE);
    get_line(line2, MAXLINE);

    int num = atoi(line);

    itoa(num, itoares);
    printf("line=%s num=%d\n", line, num);
    printf("itoa(line)=%s\n", itoares);
    int found = strindex_ptr(line, line2);
    printf("found= %d\n", found);
    found = strrindex_ptr(line, line2);
    printf("found= %d\n", found);
    afree(itoares);
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