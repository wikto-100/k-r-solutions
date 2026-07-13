
#include "calc.h"
#define MAXST 100

// stack fucntions implementation
static unsigned sp = 0;
static double stack[MAXST];
void push(double d)
{
    if (sp < MAXST)
        stack[sp++] = d;
    else
        printf("push():\tstack is full, can't push %g\n", d);
}
double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else
    {
        printf("pop():\tstack empty\n");
        return 0.0;
    }
}
void print_top(void)
{
    if (sp > 0)
        printf("\t%.08g\n", stack[sp - 1]);
    else
        printf("print_top():\tstack empty\n");
}
double peek(void)
{
    if (sp > 0)
        return stack[sp - 1];
    else
    {
        printf("peek():\tstack empty\n");
        return 0.0;
    }
}
void duplicate(void)
{
    if (sp > 0)
        push(stack[sp - 1]);
    else
        printf("duplicate():\tstack empty\n");
}
void swap_top(void)
{
    if (sp <= 1)
        printf("swap_top():\t stack has <2 elements\n");
    else
    {
        double t = stack[sp - 1];
        stack[sp - 1] = stack[sp - 2];
        stack[sp - 2] = t;
    }
}
void clear(void)
{
    sp = 0;
}