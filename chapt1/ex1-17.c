/*
Exercise 1-17: print only the input lines that are longer than 80 characters.
Author: Wiktor Stojek
*/


// We use POSIX because i cant be bothered, or am too stupid
// cant tell
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{

    size_t bufsize = 128;
    /* POSIX getline() grows buffer/bufsize itself as needed, unlike K&R's hand-rolled version */
    char *buffer = (char *)malloc(bufsize);
    ssize_t llen;
    while ((llen = getline(&buffer, &bufsize, stdin)) != EOF)
    {
        if(llen > 80)
            printf("%s", buffer);
    }

    free(buffer);

    return 0;
}