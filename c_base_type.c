#include <stdio.h>
#include <limits.h>

// gcc c_base_type.c && ./a.out
int main(int argc, char **argv)
{
    short s = 1;
    int i = 1000;
    long l = 1000000;
    char c = 'A';
    float f = 1.0;
    double d = 1.0;

    char char_max = CHAR_MAX;
    printf("char_max = %hd \n", char_max);
    printf("sizeof(char) = %lu \n", sizeof(char));

    short max_short = SHRT_MAX;
    printf("max_short = %hd \n", max_short);
    printf("sizeof(short) = %lu \n", sizeof(short));

    int max_int = INT_MAX;
    printf("max_int = %d \n", max_int);
    printf("max_int + 1 = %d \n", max_int + 1);
    printf("sizeof(int) = %lu \n", sizeof(int));

    long max_long = LONG_MAX;
    printf("max_long = %ld \n", max_long);
    printf("sizeof(long) = %lu \n", sizeof(long));

    long long max_longlong = LLONG_MAX;
    printf("max_long = %lld \n", max_longlong);
    printf("sizeof(long long) = %lu \n", sizeof(long long));

    return 0;
}