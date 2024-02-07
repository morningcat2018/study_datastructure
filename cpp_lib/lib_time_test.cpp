#include <cstdio>
#include <ctime>
#include <cstdlib>

// g++ lib_time_test.cpp -Wformat-invalid-specifier && ./a.out
int main()
{
    // 基于当前系统的当前日期/时间
    time_t now = time(0); // 当前时间戳(秒)
    printf("当前时间戳(秒)=%ld\n", now);
    time_t seconds = time(NULL);
    printf("当前时间戳(秒)=%ld\n", seconds);

    clock_t start_t, finish_t;
    start_t = clock(); // 返回clock函数执行起（一般为程序的开头），处理器时钟所使用的时间
    printf("开始时间:%ld\n", start_t);
    // do something
    finish_t = clock();
    double total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC; // 将时间转换为秒
    printf("CPU 占用的总时间：%f\n", total_t);

    time_t curtime;
    time(&curtime);
    printf("当前时间 = %s", ctime(&curtime));

    //setenv("TZ", "Asia/Shanghai", 1);       // 设置时区为东八区
    //tzset(); // 更新时区设置
    time_t timestamp = 1680664271;          // 时间戳
    struct tm *tm_ptr = localtime(&timestamp); // 将时间戳转换为本地时间
    char buffer[32];
    // strftime(buffer, 32, "%Y%0m%0e_%H%M%S", tm_ptr); // 以年月日_时分秒的形式表示当前时间
    strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", tm_ptr); // 格式化输出时间
    printf("%s\n", buffer);
    return 0;
}