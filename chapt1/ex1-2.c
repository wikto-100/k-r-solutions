/*
Exercise 1-2: try giving printf's format string a backslash escape that isn't
one of the standard ones, and see how the compiler and runtime react.
Author: Wiktor Stojek
*/

#include <stdio.h>

char main()
{
    /* \z is not a recognized escape sequence; compiler warns and prints it literally as 'z' */
    printf("Hello, world!\z");
}
/*
wiktor@wiktor-81q4:~/books/CPROG/chapt1$ gcc ex1-2.c
ex1-2.c: In function ‘main’:
ex1-2.c:10:29: warning: unknown escape sequence: '\z'
   10 |     printf("Hello, world!\z");
      |                             ^
wiktor@wiktor-81q4:~/books/CPROG/chapt1$ ./a.out 
Hello, world!z
*/