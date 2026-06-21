/*
Exercise 2-1: find the min/max range of char, short, int, and long, signed
and unsigned, first via the standard library's constants and then by direct
computation. As a bonus, work out the ranges of the floating-point types too.

Disclaimer: this is probably not how the author intended for us to solve this -
nevertheless, it showcases what these types look like in binary and how they
can be manipulated directly. See ldbl_test.c for how the long double layout
used below was derived.
Author: Wiktor Stojek
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

    printf("\n--- Storage bit widths ---\n");
    printf("char storage bits: %zu\n", sizeof(char) * CHAR_BIT);
    printf("unsigned char storage bits: %zu\n", sizeof(unsigned char) * CHAR_BIT);
    printf("short storage bits: %zu\n", sizeof(short) * CHAR_BIT);
    printf("unsigned short storage bits: %zu\n", sizeof(unsigned short) * CHAR_BIT);
    printf("int storage bits: %zu\n", sizeof(int) * CHAR_BIT);
    printf("unsigned int storage bits: %zu\n", sizeof(unsigned int) * CHAR_BIT);
    printf("long storage bits: %zu\n", sizeof(long) * CHAR_BIT);
    printf("unsigned long storage bits: %zu\n", sizeof(unsigned long) * CHAR_BIT);
    printf("long long storage bits: %zu\n", sizeof(long long) * CHAR_BIT);
    printf("unsigned long long storage bits: %zu\n", sizeof(unsigned long long) * CHAR_BIT);
    printf("float storage bits: %zu\n", sizeof(float) * CHAR_BIT);
    printf("double storage bits: %zu\n", sizeof(double) * CHAR_BIT);
    printf("long double storage bits: %zu\n", sizeof(long double) * CHAR_BIT);

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

    /*note: long long turns out to be the same as long*/

    // long long (64-bit, 2's cmpl)
    mi_ll = 0x1UL << 63;
    ma_ll = (0x7FFFFFFFUL << 32) | 0xFFFFFFFFUL;

    // unsigned long long (64-bit)
    mi_ull = 0;
    ma_ull = (0xFFFFFFFFUL << 32) | 0xFFFFFFFFUL;

    // --- float: IEEE-754 binary32 ---
    // bit layout (MSB -> LSB): 1 sign | 8 exponent (bias 127) | 23 fraction
    // value = (-1)^sign * 2^(exponent_stored - 127) * 1.fraction
    // exponent_stored ranges over 1..254 for normalized numbers
    // (0 means subnormal/zero, 255 means inf/NaN, so both ends are reserved)

    // smallest positive normalized float: sign=0, exponent_stored=1 (real exponent -126), fraction=0
    // bits: 0 00000001 00000000000000000000000 == 0x00800000
    unsigned int hack_bits_f = 0x1U << 23;
    mi_f = *(float *)&hack_bits_f;

    // largest finite float: sign=0, exponent_stored=254 (real exponent 127; 255 is reserved),
    // fraction = all 1s -> mantissa = 2 - 2^-23
    // bits: 0 11111110 11111111111111111111111 == 0x7F7FFFFF
    hack_bits_f = 0x7F7FFFFFU;
    // reinterpret the raw bits as a float: take hack_bits_f's address, treat it as a
    // float pointer, then dereference - this reads the bit pattern without conversion
    ma_f = *(float *)&hack_bits_f;

    // --- double: IEEE-754 binary64 ---
    // same idea as float, just wider fields: 1 sign | 11 exponent (bias 1023) | 52 fraction
    // value = (-1)^sign * 2^(exponent_stored - 1023) * 1.fraction

    // smallest positive normalized double: exponent_stored=1 (real exponent -1022), fraction=0
    unsigned long hack_bits_d = 0x1UL << 52;
    mi_d = *(double *)&hack_bits_d;

    // largest finite double: exponent_stored=2046 (real exponent 1023; 2047 is reserved),
    // fraction = all 1s
    hack_bits_d = (0x7FEFFFFFUL << 32) | 0xFFFFFFFFUL;
    ma_d = *(double *)&hack_bits_d;

    // --- long double: x86 80-bit extended precision ---
    // glibc/x86-64 pads this to 16 bytes for alignment, but only the low 10 bytes
    // (80 bits) hold the actual value - the remaining 6 bytes are alignment padding
    // with unspecified ("garbage") content. There's no native 80-bit integer type,
    // so the value is built byte-by-byte and read back through a pointer cast.
    //
    // bit layout, low byte first (little-endian):
    //   bytes 0-7  (64 bits): mantissa, WITH an explicit integer bit - unlike float/double
    //                          there is no implicit leading 1, so normalized numbers need
    //                          that top mantissa bit set by hand
    //   bytes 8-9  (16 bits): 15-bit exponent (bias 16383) packed with 1 sign bit (MSB of byte 9)
    //   bytes 10-15          : padding, irrelevant to the value
    //
    // confirmed by dumping the raw bytes of an actual LDBL_MIN on this machine:
    //   00 00 00 00 00 00 00 80 01 00 | 02 7E E0 74 00 00
    //   <------ mantissa ------> <exp+sign> <---- padding ---->
    // i.e. mantissa = 0x8000000000000000 (integer bit set, fraction 0), exponent = 1, sign = 0

    unsigned char pure_evil[16] = {
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80, // mantissa ends here
        0x01, 0x00,             // exponent = 1 (smallest normalized), sign = 0
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00}; // padding, irrelevant to the value
    mi_ld = *(long double *)pure_evil;

    // largest normal long double: mantissa all 1s (integer bit + full fraction),
    // exponent_stored = 0x7FFE = 32766 (real exponent 16383; 0x7FFF is reserved), sign = 0
    unsigned char pure_evil_max[16] = {
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFE, 0x7F, // exponent = 0x7FFE, sign = 0
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00};
    ma_ld = *(long double *)pure_evil_max;

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