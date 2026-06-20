/*
Exercise 1-5: print the conversion table top to bottom in reverse, starting
at 300 degrees and counting down to 0.
Author: Wiktor Stojek
*/
#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
    for (fahr = upper; fahr >= lower; fahr -= step)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("\t%3.0f %6.1f\n", fahr, celsius);
    }
}