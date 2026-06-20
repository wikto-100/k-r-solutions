/*
Exercise 1-4: print the same kind of table, but going from Celsius to Fahrenheit instead.
Author: Wiktor Stojek
*/
#include <stdio.h>
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
    fahr = lower;
    printf("Celsius-Farentheit Table\n");
    while (fahr <= upper)
    {
        /* fahr is iterated, celsius derived from it, but columns printed as celsius then fahr */
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("\t%3.0f %6.1f\n", celsius, fahr);
        fahr = fahr + step;
    }
}