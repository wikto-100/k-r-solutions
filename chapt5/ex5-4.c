/*
Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.
*/
#include <stdio.h>
int strend(char *s, char *t)
{
    int nt = 0, ns = 0;
    while (*s)
    {
        s++; // end of s
        ns++;
    }
    while (*t)
    {
        t++; // end of t
        nt++;
    }
    if (nt > ns)
        return 0;
    // go backwards comparing until they are not equal.
    while (nt > 0)
    {
        if (*--s != *--t)
            return 0;
        nt--;
    }
    return 1;
}

int main()
{

    char s[] = "";
    char t[] = "";

    printf("%d\n", strend(s, t));

    return 0;
}