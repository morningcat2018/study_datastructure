#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *runable(void *arg)
{
    int *p = (int *)arg;
    int param1 = *p;
    printf("runable thread : param=%d\n", param1);
    // return (void *)100;
    int *ret_val = (int *)malloc(sizeof(int));
    *ret_val = param1 * 2;
    pthread_exit((void *)ret_val);
}

// gcc p_thread_demo2.c && ./a.out
int main()
{
    pthread_t sp;
    int n = 42;
    pthread_create(&sp, NULL, runable, (void *)&n);
    printf("main thread\n");
    void *ret_val;
    pthread_join(sp, &ret_val);
    // printf("ret_val=%p\n", ret_val);
    printf("Thread returned value= %d\n", *(int *)ret_val);
    free(ret_val);
    return 0;
}