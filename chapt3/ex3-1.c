/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define REP 100000
int binsearch(int x, int v[], int n)
{
    int high, low, mid;
    high = n - 1;
    low = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (v[mid] < x)
            low = mid + 1;
        else if (v[mid] > x)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
int fast_binsearch(int x, int v[], int n)
{
    if (n <= 0)
        return -1;
    int high, low, mid;
    high = n - 1;
    low = 0;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (v[mid] < x)
            // most certainly v[mid] != x, so we can skip it
            low = mid + 1;
        else // v[mid] >= x
            high = mid;
    }
    // only can be v[high] = x

    return (v[high] == x) ? high : -1;
}
void timeit(int (*f)(int x, int arr[], int n), int arr[], int n, const char name[])
{
    int i = -1;
    int x;
    clock_t begin, end;
    begin = clock();

    for (int r = 0; r < REP; r++)
    {
        x = rand() % n + 1;
        i = f(x, arr, n);
    }
    end = clock();

    double elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%s: value %d at index %d, time=%lf\n", name, x, i, elapsed);
}
int main()
{
    // I notice that fast_binsearch isn't at all faster
    // even though it does less comparisons
    // binsearch benefits from exiting early
    int n;
    int *arr = NULL;
    for (n = 1000; n <= 10000; n += 1000)
    {
        int *tmparr = realloc(arr, n * sizeof *arr);
        if (tmparr == NULL)
        {
            free(arr);
            return 1;
        }
        arr = tmparr;
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        timeit(binsearch, arr, n, "binsearch");
        timeit(fast_binsearch, arr, n, "fast_binsearch");
        putchar('\n');
    }
    free(arr);
    return 0;
}