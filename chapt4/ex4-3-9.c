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
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

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
//
#define MAXOP 100
#define MAXST 100
#define BUFSIZE 100

// getop
int getop(char[]);

// getch, ungetch
int bufp = 0;
int buf[BUFSIZE];
/* 4-9:
 * No extra change is needed after 4-8.
 * It could break on systems where char stores values like 0-255:
 * pushing back EOF, usually -1, could come back as 255 instead of EOF.
 * Since sbuf is an int here, EOF can be stored as -1 and returned correctly.
 */
int sbuf;
int pushed;

int getch(void);
void ungetch(int);

// stack
unsigned sp = 0;
double stack[MAXST];

void push(double);
double pop(void);
void print_top(void);
void duplicate(void);
void swap_top(void);
void clear(void);

// variables
double vars[26];
int is_assigned[26];
double mrp;
char last;
void assign_var(char, double);
double get_var(char);

// getop implementation
int getop(char s[])
{
    int i, c;
    int isnum;
    i = 0;
    isnum = 0;
    do
    {
        c = getch();
        s[0] = c;
    } while (c == ' ' || c == '\t'); // skip leading whitespace
    s[1] = '\0'; // because need to obtain a single operand like * + - / %...

    if (isalpha(c) && islower(c))
        return c;
    if (!isdigit(c) && c != '.' && c != '-') // could be .04343
        return c;                            // operand (not a number)

    // here we may have negative
    if (c == '-')
    {
        c = getch();
        s[++i] = c;
    }
    if (isdigit(c))
    {
        isnum = 1;
        do
        {
            c = getch();
            s[++i] = c;
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
            s[++i] = c;
        } while (isdigit(c));
    }
    s[i] = '\0';

    ungetch(c);
    return isnum ? NUM : '-';
}

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

// stack fucntions implementation
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
// variable handling implementation
double get_var(char var)
{
    if (islower(var))
    {
        if (is_assigned[var - 'a'])
            return vars[var - 'a'];
        else
        {
            printf("get_var():\t new variable\n");
            return 0.0;
        }
    }
    else
    {
        printf("get_var():\t invalid variable\n");
        return 0.0;
    }
}
void assign_var(char var, double val)
{
    if (islower(var))
    {
        is_assigned[var - 'a'] = 1;
        vars[var - 'a'] = val;
    }
    else
        printf("assign_var():\tinvalid variable\n");
}
int main(void)
{
    int t;
    char eq[MAXOP];
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