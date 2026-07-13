/*
Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.
*/
#include <stdio.h>
void str_cat(char *s, char *t)
{
    while (*s)
        s++;
    // we want *s = '\0'
    while (*t)
        *s++ = *t++;
    *s = '\0';
}

int main()
{

    char s[100] = "first string ";
    char t[] = "second string";
    str_cat(s, t);
    printf("%s\n", s);
    return 0;
}