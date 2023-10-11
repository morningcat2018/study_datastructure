#include <stdio.h>

#define swap(a, b)             \
    do                         \
    {                          \
        typeof(a) __tmp = (a); \
        (a) = (b);             \
        (b) = __tmp;           \
    } while (0)

// gcc c_gnu_typeof.c && ./a.out
int main(void)
{
    int i;
    typeof(i) j = 20;
    typeof(int *) a;

    int f();
    typeof(f()) k;
    printf("%d \n", k);
    return 0;
}