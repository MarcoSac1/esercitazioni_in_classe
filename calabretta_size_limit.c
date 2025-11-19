#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>

int main(void) {
    printf("=== Informazioni generali ===\n");
    printf("CHAR_BIT (bit per byte): %d\n", CHAR_BIT);
    printf("\n");

    printf("=== bool (C99: <stdbool.h>) ===\n");
    printf("sizeof(bool) = %zu byte\n", sizeof(bool));
    printf("Valori possibili: false (0), true (1)\n");
    printf("\n");

    printf("=== char / signed char / unsigned char ===\n");
    printf("sizeof(char)        = %zu byte\n", sizeof(char));
    printf("CHAR_MIN            = %d\n", CHAR_MIN);
    printf("CHAR_MAX            = %d\n", CHAR_MAX);
    printf("sizeof(signed char) = %zu byte\n", sizeof(signed char));
    printf("SCHAR_MIN           = %d\n", SCHAR_MIN);
    printf("SCHAR_MAX           = %d\n", SCHAR_MAX);
    printf("sizeof(unsigned char) = %zu byte\n", sizeof(unsigned char));
    printf("UCHAR_MAX           = %u\n", UCHAR_MAX);
    printf("\n");

    printf("=== short / unsigned short ===\n");
    printf("sizeof(short)       = %zu byte\n", sizeof(short));
    printf("SHRT_MIN            = %d\n", SHRT_MIN);
    printf("SHRT_MAX            = %d\n", SHRT_MAX);
    printf("sizeof(unsigned short) = %zu byte\n", sizeof(unsigned short));
    printf("USHRT_MAX           = %u\n", USHRT_MAX);
    printf("\n");

    printf("=== int / unsigned int ===\n");
    printf("sizeof(int)         = %zu byte\n", sizeof(int));
    printf("INT_MIN             = %d\n", INT_MIN);
    printf("INT_MAX             = %d\n", INT_MAX);
    printf("sizeof(unsigned int) = %zu byte\n", sizeof(unsigned int));
    printf("UINT_MAX            = %u\n", UINT_MAX);
    printf("\n");

    printf("=== long / unsigned long ===\n");
    printf("sizeof(long)        = %zu byte\n", sizeof(long));
    printf("LONG_MIN            = %ld\n", LONG_MIN);
    printf("LONG_MAX            = %ld\n", LONG_MAX);
    printf("sizeof(unsigned long) = %zu byte\n", sizeof(unsigned long));
    printf("ULONG_MAX           = %lu\n", ULONG_MAX);
    printf("\n");

    printf("=== long long / unsigned long long ===\n");
    printf("sizeof(long long)   = %zu byte\n", sizeof(long long));
    printf("LLONG_MIN           = %lld\n", LLONG_MIN);
    printf("LLONG_MAX           = %lld\n", LLONG_MAX);
    printf("sizeof(unsigned long long) = %zu byte\n", sizeof(unsigned long long));
    printf("ULLONG_MAX          = %llu\n", ULLONG_MAX);
    printf("\n");

    printf("=== float ===\n");
    printf("sizeof(float)       = %zu byte\n", sizeof(float));
    printf("FLT_MIN             = %e\n", FLT_MIN);
    printf("FLT_MAX             = %e\n", FLT_MAX);
    printf("FLT_EPSILON         = %e\n", FLT_EPSILON);
    printf("Cifre di precisione decimale (~): %d\n", FLT_DIG);
    printf("\n");

    printf("=== double ===\n");
    printf("sizeof(double)      = %zu byte\n", sizeof(double));
    printf("DBL_MIN             = %e\n", DBL_MIN);
    printf("DBL_MAX             = %e\n", DBL_MAX);
    printf("DBL_EPSILON         = %e\n", DBL_EPSILON);
    printf("Cifre di precisione decimale (~): %d\n", DBL_DIG);
    printf("\n");

    printf("=== long double ===\n");
    printf("sizeof(long double) = %zu byte\n", sizeof(long double));
    printf("LDBL_MIN            = %Le\n", LDBL_MIN);
    printf("LDBL_MAX            = %Le\n", LDBL_MAX);
    printf("LDBL_EPSILON        = %Le\n", LDBL_EPSILON);
    printf("Cifre di precisione decimale (~): %d\n", LDBL_DIG);
    printf("\n");

    return 0;
}

