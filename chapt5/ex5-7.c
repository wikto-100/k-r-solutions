#include <stdio.h>
#include <string.h>

#define MAXLINES 100000
#define MAXLINE  10
#define ALLOCSIZE (MAXLINES * MAXLINE)

/*
 * 1: store lines in the 2D array supplied by main
 * 0: store lines using alloc()
 */
#define USE_ARRAY_STORAGE 1

char *lineptr[MAXLINES];

int get_line(char line[], int limit);

int readlines_array(
    char *lineptr[],
    char linearr[][MAXLINE],
    int maxlines
);

int readlines_alloc(
    char *lineptr[],
    int maxlines
);

void writelines(char *lineptr[], int nlines);
void quicksort(char *lineptr[], int left, int right);
void swap(char *lineptr[], int i, int j);

char *alloc(int size);


/* Storage used by the alloc-based version */

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int size)
{
    if (allocbuf + ALLOCSIZE - allocp >= size) {
        allocp += size;
        return allocp - size;
    }

    return NULL;
}


int main(void)
{
    int nlines;

#if USE_ARRAY_STORAGE

    char linearr[MAXLINES][MAXLINE];

    nlines = readlines_array(
        lineptr,
        linearr,
        MAXLINES
    );

#else

    nlines = readlines_alloc(
        lineptr,
        MAXLINES
    );

#endif

    if (nlines < 0) {
        printf("error: input too large to sort\n");
        return 1;
    }

    quicksort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);

    return 0;
}


/* Exercise 5-7 version */

int readlines_array(
    char *lineptr[],
    char linearr[][MAXLINE],
    int maxlines
)
{
    int len;
    int nlines = 0;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (nlines >= maxlines)
            return -1;

        if (line[len - 1] == '\n')
            line[len - 1] = '\0';

        strcpy(linearr[nlines], line);
        lineptr[nlines] = linearr[nlines];

        nlines++;
    }

    return nlines;
}


/* Original alloc-based version */

int readlines_alloc(char *lineptr[], int maxlines)
{
    int len;
    int nlines = 0;
    char *destination;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (nlines >= maxlines)
            return -1;

        if (line[len - 1] == '\n')
            line[len - 1] = '\0';

        /*
         * len includes either the removed newline or enough
         * room for the terminating null character.
         */
        destination = alloc(len);

        if (destination == NULL)
            return -1;

        strcpy(destination, line);
        lineptr[nlines] = destination;

        nlines++;
    }

    return nlines;
}


void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}


int get_line(char line[], int limit)
{
    int c;
    int i = 0;

    /*
     * Reserve one position for the terminating '\0'.
     */
    while (
        i < limit - 1 &&
        (c = getchar()) != EOF &&
        c != '\n'
    ) {
        line[i++] = (char)c;
    }

    if (c == '\n')
        line[i++] = (char)c;

    line[i] = '\0';

    return i;
}


void quicksort(char *values[], int left, int right)
{
    int i;
    int last;

    if (left >= right)
        return;

    swap(values, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++) {
        if (strcmp(values[i], values[left]) < 0)
            swap(values, ++last, i);
    }

    swap(values, left, last);

    quicksort(values, left, last - 1);
    quicksort(values, last + 1, right);
}


void swap(char *values[], int i, int j)
{
    char *temporary = values[i];

    values[i] = values[j];
    values[j] = temporary;
}