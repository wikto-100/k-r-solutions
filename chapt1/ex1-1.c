/*
Exercise 1-1: run a minimal greeting program, then deliberately break it piece
by piece to see what kind of compiler errors and warnings come up.
Author: Wiktor Stojek
*/
#include <stdio.h>

main()
{
    /* print the classic greeting, no newline */
    printf("Hello, world!");
}
/*
ex1-1.c:5:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
    5 | main()
      | ^~~~
*/