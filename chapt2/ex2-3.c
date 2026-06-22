/*
Exercise 2-3: implement htoi(s) - parse a hex string (optionally prefixed
with 0x/0X, digits 0-9 and a-f/A-F) and return its integer value.
Author: Wiktor Stojek
*/
#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 12 // for integer "0xXXXXXXXXU\0"
int htoi(char s[])
{
    // we are sure that s is a valid hex string of lower characters (no newline)
    int i, len;
    int hexval, hexmul, hex;
    len = i = 0;
    hexval = 0;
    hexmul = 1;

    // compute lenght
    while (s[len] != '\0')
        len++;
    // interpret decimal value
    while (i < len && s[len - i - 1] != 'x')
    {
        hex = s[len - i - 1];
        if (hex >= 'a' && hex <= 'f')
            hex = hex - 'W'; // ascii[a] = 97, ascii[W] = 87 =>  97-87 = 10
        else if (isdigit(hex))
            hex = hex - '0';
        hexval += hexmul * hex;
        hexmul *= 16;
        i++;
    }
    return hexval;
}
int hex_getline(char line[], int lim)
{

    int i, c, low;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {

        low = tolower(c);
        if (i == 1 && low == 'x')
        {
            if (line[0] == '0')
                line[1] = 'x';
            else
                return -1;
        }
        else
        {
            if (low >= 'a' && low <= 'f' || isdigit(c))
                line[i] = low;
            else
                return -1;
        }
    }
    // omit newline, check if empty
    if (i == 0 || line[i - 1] == 'x')
        return -1;
    line[i] = '\0';
    return i;
}
int main()
{
    char str[MAXSIZE];
    int c, l;
    l = hex_getline(str, MAXSIZE);
    if (l == -1)
    {
        printf("not a valid hex number\n");
        return 0;
    }
    int x = htoi(str);

    printf("dec: %d\n", x);
}