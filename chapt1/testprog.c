#include <stdio.h>

int main(void)
{
    // full-line comment
    int a = 3 / 2; // trailing comment

    printf("//"); // comment marker inside a string
    printf("text // more text");
    printf("escaped quote: \" // still string");
    printf("text \
        // more text");
    //\'"'" aaaa \// aaa
    char slash = '/'; // slash character
    char quote = '"';
    char apostrophe = '\'';
    char c = '/';
    char q = '"';

    int x = 1; // comment containing "quotes" and // more slashes
    int y = 2; ////// many slashes

    // comment immediately before newline
    int z = 3;

    /*
    Multiline ""
    comment
    */
    /* comment containing // markers */
    /* comment containing "quotes" and 'characters' */
    /******** many stars ********/

    int d1 = 4; /*
   comment starts after code
   and ends before more code
*/
    int e1 = 5;
    printf("escaped quote: \" /* still string */");
    printf("backslash: \\\\ /* still string */");

    int f1 = 6; /**/
    int g1 = 7;
    int /**/ value = 3;
    char ccc = '//';
    int x = 10 / '/';
    int x = 10/'/';

    printf("\\"); // remove this comment
    /*
       C comments do not nest:
       /* this does not begin a nested comment */
    return /*this number ->*/ 0; // final comment
}
