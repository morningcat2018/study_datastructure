#include <cstdio>
#include <iostream>
#include <pthread.h>
#define NUM_THREADS 5

using namespace std;

struct ThreadArg
{
    int index;
    int value;
};

// 线程的运行函数
void *func(void *args)
{
    int t_arg = *static_cast<int *>(args);
    printf("thread :%d \n", t_arg);
    return 0;
}

// g++ lib_thread_test.cpp && ./a.out
int main()
{
    printf("thread start\n");

    // 定义线程的 id 变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    int t_arg[NUM_THREADS]; // 用数组来保存i的值
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        // 参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        // struct ThreadArg t_arg = ThreadArg();
        // t_arg.index = i;
        // t_arg.value = i + 1000;
        t_arg[i] = i; // 先保存i的值
        // cout << &t_arg[i] << endl;
        int ret = pthread_create(&tids[i], NULL, func, static_cast<void *>(&t_arg));
        if (ret != 0)
            printf("pthread_create error: error_code= %d\n", ret);
    }
    // join
    // pthread_join(tid, NULL);
    // 等各个线程退出后进程才结束
    pthread_exit(NULL);
    return 0;
}