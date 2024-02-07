#ifndef C_LINK_QUEUE_H
#define C_LINK_QUEUE_H

#include <stdlib.h>
#include <assert.h>

typedef char ElemType;

/*链式队列*/
typedef struct qnode
{
    ElemType data;
    struct qnode *next;
} QNode;

typedef struct
{
    QNode *front;
    QNode *rear;
} Queue;

Queue *init()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void destory(Queue *q)
{
    QNode *p = q->front, *r;
    if (p != NULL) /*释放数据结点占用空间*/
    {
        r = p->next;
        while (r != NULL)
        {
            free(p);
            p = r;
            r = p->next;
        }
    }
    free(q); /*释放头结点占用空间*/
}

int getLength(Queue *q)
{
    int n = 0;
    QNode *p = q->front;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    return (n);
}

int isEmpty(Queue *q)
{
    return q->rear == NULL;
}

void push(Queue *q, ElemType value)
{
    QNode *s = (QNode *)malloc(sizeof(QNode));
    s->data = value;
    s->next = NULL;
    if (q->rear == NULL) /*若链队为空,则新结点是队首结点又是队尾结点*/
        q->front = q->rear = s;
    else
    {
        q->rear->next = s; /*将*s结点链到队尾,rear指向它*/
        q->rear = s;
    }
}

ElemType pop(Queue *q)
{
    assert(q->rear != NULL);
    QNode *t;
    if (q->front == q->rear) /*队列中只有一个结点时*/
    {
        t = q->front;
        q->front = q->rear = NULL;
    }
    else /*队列中有多个结点时*/
    {
        t = q->front;
        q->front = q->front->next;
    }
    ElemType value = t->data;
    free(t);
    return value;
}

#endif // C_QUEUE_H