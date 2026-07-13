
#ifndef CALC_H
#define CALC_H
#include <stdio.h>
#include <ctype.h>

// getop
int getop(char[]);

// stack
void push(double);
double pop(void);
void print_top(void);
double peek(void);
void duplicate(void);
void swap_top(void);
void clear(void);

// variables
void assign_var(char, double);
double get_var(char);

// getch
int getch(void);
void ungetch(int);

#endif