#include <stdio.h>

// gcc c_gnu_expression.c && ./a.out
int main(void)
{
    int sum = 0;
    // 语句表达式
    // https://www.zhaixue.cc/c-arm/c-arm-express.html
    sum =
        ({
            int s = 0;
            for (int i = 0; i <= 10; i++)
                s = s + i;
            goto here;
            s;
        });
    printf("sum = %d\n", sum);
here:
    printf("here:\n");
    printf("sum = %d\n", sum);
    return 0;
}