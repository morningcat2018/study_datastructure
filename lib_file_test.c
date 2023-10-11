#include <stdio.h>
#include <stdlib.h>

// gcc lib_file_test.c
int main()
{
    FILE *fp = fopen("file1", "w+");
    if (fp == NULL)
    {
        printf("文件打开失败");
        return -1;
    }

    int x = 101;
    fprintf(fp, "%d\n", x);
    const char *str = "Hello C ";
    fprintf(fp, "%s\n", str);
    char c = 'Q';
    fprintf(fp, "%c\n", c);
    fclose(fp);

    FILE *fp_r = fopen("file1", "r");
    FILE *fp_w = fopen("file1_w", "w");
    if (fp_r == NULL || fp_w == NULL)
    {
        printf("文件打开失败");
        return -1;
    }
    char ch;
    while ((ch = getc(fp_r)) != EOF)
    {
        // putchar(ch); // 输出字符到控制台
        putc(ch, stdout); // 与上诉代码作用相同
        // 输出字符到 fp2
        putc(ch, fp_w);
    }
    fclose(fp_r);
    fclose(fp_w);

    return 0;
}