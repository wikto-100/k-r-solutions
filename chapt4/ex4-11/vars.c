#include "calc.h"
static double vars[26];
static int is_assigned[26];
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