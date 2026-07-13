/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.
*/
#include <stdio.h>
#include <ctype.h>
void expand(char s1[], char s2[])
{
    int i, j, c;
    int left_r, right_r;
    for (i = 0, j = 0; (c = s1[i]) != '\0'; i++)
    {
        if (i > 0 && s1[i + 1] != '\0' && c == '-')
        {
            left_r = s1[i - 1];
            right_r = s1[i + 1];
            // could be that 0-a, a-9 that aren't valid regex
            // also upper - lower or lower - upper
            // Z-A is also not valid
            if (left_r < right_r &&
                ((isalpha(left_r) && isalpha(right_r) &&
                  ((isupper(left_r) && isupper(right_r)) || (islower(left_r) && islower(right_r)))) ||
                 (isdigit(left_r) && isdigit(right_r))))
            {
                while (left_r < right_r - 1)
                {
                    s2[j++] = ++left_r;
                }
            }
            else
            {
                s2[0] = '?';
                s2[1] = '\0';
                return;
            }
        }
        else
            s2[j++] = c;
    }
    s2[j] = '\0';
}

int main()
{
    char s1[] = "-The alphabet may be a-z or may be A-Z\
    \ndecimal digits are 1-9 hexadecimal 1-3-5-9A-F \n-";
    char s2[512];
    expand(s1, s2);
    printf("%s\n", s2);
}