/*
Exercise 1-15: move the Fahrenheit-to-Celsius math out of the table loop and
into its own conversion function.
Author: Wiktor Stojek
*/
#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */
/* extracted the Fahrenheit-to-Celsius formula into its own function */
float conv (float fahr){
    return (5.0 / 9.0) * (fahr - 32.0);
}
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
    for (fahr = upper; fahr >= lower; fahr -= step)
    {
        celsius = conv(fahr);
        printf("\t%3.0f %6.1f\n", fahr, celsius);
    }
}