#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *runable(void *arg)
{
    printf("runable thread\n");
    return (void *)0;
}

int main()
{
    pthread_t sp;
    pthread_create(&sp, NULL, runable, NULL);
    printf("main thread\n");
    sleep(3);
    return 0;
}