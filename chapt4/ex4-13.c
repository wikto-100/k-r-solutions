/*
Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place.
*/
#include <stdio.h>
static void reverse_r(char s[], int left, int right)
{
    if (left >= right)
        return;
    int t = s[left];
    s[left] = s[right];
    s[right] = t;
    reverse_r(s, left + 1, right - 1);
} // other compilation unit
void reverse(char s[])
{
    int n = 0;
    while (s[n] != '\0')
        n++;
    reverse_r(s, 0, n - 1);
} // exposed out
int main()
{
    char s[100] = "abc";
    reverse(s);
    printf("\n%s\n", s);
    return 0;
}