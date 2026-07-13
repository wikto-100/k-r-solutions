/*
 * Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
 * the modulus (%) operator and provisions for negative numbers.
 * Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
 * duplicate it, and to swap the top two elements. Add a command to clear the stack.
 * Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
 * Appendix B, Section 4.
 * Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
 * with single-letter names.) Add a variable for the most recently printed value.
 * Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
 * Should ungets know about buf and bufp, or should it just use ungetch?
 * Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
 * getch and ungetch accordingly.
 * Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
 * what their properties ought to be if an EOF is pushed back, then implement your design.

 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100
// commands
#define NUM '0'
#define PRINT 'P'
#define DUPL 'D'
#define SWAP 'S'
#define CLEAR 'C'
#define SIN '$'
#define POW '^'
#define EXP 'E'
#define EQ '='
#define MRP 'R'
int main(void)
{
    int t;
    char eq[MAXOP];
    char last;
    double mrp;

    while ((t = getop(eq)) != EOF)
    {
        switch (t)
        {
        case PRINT:
            print_top();
            break;
        case MRP:
            push(mrp);
            break;
        case DUPL:
            duplicate();
            break;
        case SWAP:
            swap_top();
            break;
        case CLEAR:
            clear();
            break;
        case NUM:
            push(atof(eq));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
        {
            double op2 = pop();
            push(pop() - op2);
            break;
        }
        case '*':
            push(pop() * pop());
            break;
        case '/':
        {
            double op2 = pop();
            double op1 = pop();
            if (op2 == 0.0)
                printf("main():\tdivision by 0\n");
            else
                push(op1 / op2);
            break;
        }
        case '%':
        {
            double op2 = pop();
            double op1 = pop();
            if ((int)op2 == 0)
                printf("main():\tmodulo by zero\n");
            else
                push(fmod(op1, op2));
            break;
        }
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
        {
            double op2 = pop();
            double op1 = pop();
            if ((int)op2 == 0 && (int)op1 == 0)
                printf("main():\t 0^0 undefined\n");
            else
                push(pow(op1, op2));
            break;
        }
        case EQ:
        {
            swap_top();
            assign_var(last, pop());
            pop();
            break;
        }
        case '\n':
            printf("result:");
            print_top();
            mrp = peek();
            break;
        default:
            if (islower(t)) // variable
            {
                last = t;
                push(get_var(last));
            }
            else
                printf("main():\tnot a valid expression: %s\n", eq);
            break;
        }
    }
}