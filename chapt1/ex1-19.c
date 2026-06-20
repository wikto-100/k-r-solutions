/*
Exercise 1-19: write a reverse(s) function that flips a string in place, then
use it to reverse the input one line at a time.
Author: Wiktor Stojek
*/
#include <stdio.h>
/* reverses str[0..len-1] in place, mirroring pairs of characters from both ends */
void reverse(char str[], int len)
{
    if (len <= 1)
        return;
    for (int i = 0; i < len / 2; i++)
    {
        // x y
        // y x
        // x y
        /* skip swapping a trailing newline into the middle of the string */
        if (str[len - i - 1] == '\n')
            continue;
        /* classic XOR swap of str[i] and str[len-i-1], no temp variable needed */
        str[i] ^= str[len - i - 1];
        str[len - i - 1] ^= str[i];
        str[i] ^= str[len - i - 1];
    }
}
int getline_(char line[], int lim)
{
    int c, len;
    for (len = 0; (len < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); len++)
        line[len] = c;

    if (c == '\n')
    {
        line[len] = '\n';
        len++;
    }
    line[len] = '\0';
    return len;
}
int main()
{
    char line[128];
    int len;
    while (len = getline_(line, 128))
    {
        if (line[len - 1] == '\n')
            reverse(line, len - 1);
        else
            reverse(line, len);
        printf("%s\n", line);
    }

    return 0;
}