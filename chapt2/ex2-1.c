/*
Exercise 2-1: find the min/max range of char, short, int, and long, signed
and unsigned, first via the standard library's constants and then by direct
computation. As a bonus, work out the ranges of the floating-point types too.
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    // all types in c
    char mi_c = 0, ma_c = 0;
    unsigned char mi_uc = 0, ma_uc = 0;
    short mi_s = 0, ma_s = 0;
    unsigned short mi_us = 0, ma_us = 0;
    int mi_i = 0, ma_i = 0;
    unsigned int mi_ui = 0, ma_ui = 0;
    long mi_l = 0, ma_l = 0;
    unsigned long mi_ul = 0, ma_ul = 0;
    long long mi_ll = 0, ma_ll = 0;
    unsigned long long mi_ull = 0, ma_ull = 0;
    float mi_f = 0.0f, ma_f = 0.0f;
    double mi_d = 0.0L, ma_d = 0.0L;
    long double mi_ld = 0.0L, ma_ld = 0.0L;

    printf("--- Library constants ---\n");
    printf("char min: %d\tchar max:%d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char min: %d\tunsigned char max:%d\n", 0, UCHAR_MAX);
    printf("short min: %d\tshort max:%d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short min: %d\tunsigned short max:%d\n", 0, USHRT_MAX);
    printf("int min: %d\tint max:%d\n", INT_MIN, INT_MAX);
    printf("unsigned int min: %u\tunsigned int max:%u\n", 0, UINT_MAX);
    printf("long min: %ld\tlong max:%ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long min: %lu\tunsigned long max:%lu\n", 0UL, ULONG_MAX);
    printf("long long min: %lld\tlong long max:%lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long min: %llu\tunsigned long long max:%llu\n", 0ULL, ULLONG_MAX);
    printf("float min: %e\tfloat max:%e\n", FLT_MIN, FLT_MAX);
    printf("double min: %e\tdouble max:%e\n", DBL_MIN, DBL_MAX);
    printf("long double min: %Le\tlong double max:%Le\n", LDBL_MIN, LDBL_MAX);
    printf("\n--- Manually computed constans ---\n");
    // I assume I know the bit widths for each type, and that this is a 2-cmpl machine

    // char / signed char (8-bit, 2's cmpl)
    mi_c = 0x1u << 7; // (0x1 << 8) = 10000000b, this is 2's complement minimum (-2^n)
    ma_c = 0x7F;      // 0x7F = 01111111b, this is 2's complement maximum (=2^n-1 + ... + 2^0 )
                      // similarly for other signed types

    // unsigned char (8-bit)
    ma_uc = 0xFFu;
    mi_uc = 0x0;

    // short (16-bit, 2's cmpl)
    mi_s = 0x1U << 15;
    ma_s = 0x7FFF;

    // unsigned short (16-bit)
    mi_us = 0x0;
    ma_us = 0xFFFFU;

    // int (32-bit, 2's cmpl)
    mi_i = 0x1u << 31;
    ma_i = 0x7FFFFFFF;

    // unsigned int (32-bit)
    mi_ui = 0;
    ma_ui = 0xFFFFFFFFU;

    // long (64-bit, 2's cmpl)
    mi_l = 0x1UL << 63;
    ma_l = (0x7FFFFFFFUL << 32) | 0xFFFFFFFFUL;

    // unsigned long (64-bit)
    mi_ul = 0;
    ma_ul = (0xFFFFFFFFUL << 32) | 0xFFFFFFFFUL;

    // long (64-bit, 2's cmpl)
    mi_l = 0x1UL << 63;
    ma_l = (0x7FFFFFFFUL << 32) | 0xFFFFFFFFUL;

    // unsigned long long (64-bit)
    mi_ul = 0;
    ma_ul = (0xFFFFFFFFUL << 32) | 0xFFFFFFFFUL;
    /*note: long long turns out to be the same as long*/

    // float
    // here we use the IEEE-754 standard
    // v = (-1)^s * 2^(m - 127) * (1.f)
    // [1bit s | 8bit m | 23bit f|]
    mi_f;
    // maximum for s=0, m = 127 (in bits 11111110 - 127 = 254 because 255 is infinity), f = 2^23-1 (all 23 bits are 1's)
    unsigned int hack_bits = 0x7F7FFFFFU;
    // 1. reference the address of hack_bits obtaining unsigned int pointer
    // 2. cast that pointer to a float pointer
    // 3. dereference that pointer
    ma_f = *(float *)&hack_bits; // evil hack

    // double
    mi_d;
    ma_d;

    // long double
    mi_ld;
    ma_ld;

    printf("char min: %d\tchar max:%d\n", mi_c, ma_c);
    printf("unsigned char min: %d\tunsigned char max:%d\n", mi_uc, ma_uc);
    printf("short min: %d\tshort max:%d\n", mi_s, ma_s);
    printf("unsigned short min: %d\tunsigned short max:%d\n", mi_us, ma_us);
    printf("int min: %d\tint max:%d\n", mi_i, ma_i);
    printf("unsigned int min: %u\tunsigned int max:%u\n", mi_ui, ma_ui);
    printf("long min: %ld\tlong max:%ld\n", mi_l, ma_l);
    printf("unsigned long min: %lu\tunsigned long max:%lu\n", mi_ul, ma_ul);
    printf("long long min: %lld\tlong long max:%lld\n", mi_ll, ma_ll);
    printf("unsigned long long min: %llu\tunsigned long long max:%llu\n", mi_ull, ma_ull);
    printf("float min: %e\tfloat max:%e\n", mi_f, ma_f);
    printf("double min: %e\tdouble max:%e\n", mi_d, ma_d);
    printf("long double min: %Le\tlong double max:%Le\n", mi_ld, ma_ld);
    return 0;
}