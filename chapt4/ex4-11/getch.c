#include "calc.h"
#define BUFSIZE 100

// getch, ungetch
static int bufp = 0;
static int buf[BUFSIZE];
/* 4-9:
 * No extra change is needed after 4-8.
 * It could break on systems where char stores values like 0-255:
 * pushing back EOF, usually -1, could come back as 255 instead of EOF.
 * Since sbuf is an int here, EOF can be stored as -1 and returned correctly.
 */

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
void ungets(char s[])
{
    int n;

    if (bufp >= BUFSIZE)
        printf("ungets():\ttoo many characters\n");
    else
    {
        n = 0;
        while (s[n] != '\0')
            n++;
        if (bufp + n > BUFSIZE)
            printf("ungets():\ttoo many characters\n");
        else
            while (n > 0)
                buf[bufp++] = s[--n];
    }
}
