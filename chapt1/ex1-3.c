/*
Exercise 1-3: add a header line above the Fahrenheit-Celsius conversion table.
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
    fahr = lower;
    printf("Farentheit-Celsius Table\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("\t%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}