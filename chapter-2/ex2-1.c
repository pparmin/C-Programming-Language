/*
Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int bytes_to_bits(int bytes);
long long pow(int base, int exponent);
double pow_float(double base, double exponent);


int main()
{
    printf("FROM HEADER FILES\n");
    printf("Maximum size of signed char: %d\n", CHAR_MAX);
    printf("Maximum size of signed int: %d\n", INT_MAX);
    printf("Maximum size of signed short: %d\n", SHRT_MAX);
    printf("Maximum size of signed long: %d\n", LONG_MAX);
    printf("Maximum size of unsigned char: %u\n", UCHAR_MAX);
    printf("Maximum size of unsigned int: %u\n", UINT_MAX);
    printf("Maximum size of unsigned short: %u\n", USHRT_MAX);
    printf("Maximum size of unsigned long: %u\n", ULONG_MAX);
    printf("Maximum size of float: %f\n", FLT_MAX);
    printf("Maximum size of double: %f\n", DBL_MAX);
    printf("\n");

    char ch;
    int i;
    short s;
    long l;
    unsigned char uch;
    unsigned int ui;
    unsigned short us;
    unsigned long ul;
    float f;
    double d;

    int test = 0x10;
    printf("test: %d", test);
    printf("COMPUTED SIZES\n");
    printf("Computed size of signed ch: %lld\n", pow(2, bytes_to_bits(sizeof(ch))));
    printf("Computed size of signed int: %lld\n", ((pow(2, bytes_to_bits(sizeof(i)))) / 2) - 1);
    printf("Computed size of signed short: %lld\n", pow(2, bytes_to_bits(sizeof(s))));
    printf("Computed size of signed long: %lld\n", ((pow(2, bytes_to_bits(sizeof(l)))) / 2) - 1);
    printf("Computed size of unsigned ch: %lld\n", pow(2, bytes_to_bits(sizeof(uch))));
    printf("Computed size of unsigned int: %lld\n", pow(2, bytes_to_bits(sizeof(ui))));
    printf("Computed size of unsigned short: %lld\n", pow(2, bytes_to_bits(sizeof(us))));
    printf("Computed size of unsigned long: %lld\n", pow(2, bytes_to_bits(sizeof(ul))));
    printf("Computed size of float: %f\n", pow_float(2.0, (double) bytes_to_bits(sizeof(f))));
    printf("Computed size of double: %f\n", pow_float(2.0, (double) bytes_to_bits(sizeof(d))));
}

int bytes_to_bits(int bytes)
{
    if (bytes == 1) return 8;
    else if (bytes == 2) return 16;
    else if (bytes == 4) return 32;
    else if (bytes == 8) return 64;
}

long long pow(int base, int exponent)
{
    long long result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

double pow_float(double base, double exponent)
{
    double result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}