/*
Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.
*/
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 128
int _getline(char line[], int lim)
{

    int i, c;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}
int atoi(char s[])
{
    int n, val, pwr;
    for (n = 0; isdigit(s[n]); n++) // ensure that last is a digit
        ;
    val = 0;
    pwr = 1;
    for (int i = n - 1; i >= 0 && isdigit(s[i]); i--) // ensure we read only digits
    {
        val = val + pwr * (s[i] - '0');
        pwr *= 10;
    }
    return val; // btw, there is 0 point in doing this backwards
}
double atof(char s[])
{
    double val, power;
    int i, sign, esign, exp;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10 * val + (s[i] - '0');
    }
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = val * 10 + (s[i] - '0');
        power *= 10;
    }
    if (tolower(s[i]) == 'e')
    {
        i++;
        esign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            i++;
        // + => power = power/10
        // - => power = power  * 10
        exp = atoi(s + i);
        printf("exp result %d\n", exp);
        while (exp-- > 0)
        {
            power = (esign == 1) ? power / 10 : power * 10;
        }
    }
    return (sign * val / power);
}

int main()
{
    double val, atof(char[]);
    char line[MAXLINE];
    val = 0.0;
    while (_getline(line, MAXLINE) > 0)
    {
        printf("value=\t%g\n", val += atof(line));
    }
    return 0;
}
