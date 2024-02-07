
#ifndef C_LINK_STACK_H
#define C_LINK_STACK_H

#include <stdlib.h>
#include <assert.h>

typedef char ElemType;

typedef struct linknode
{
    ElemType data;         /*数据域*/
    struct linknode *next; /*指针域*/
} Stack;

Stack *init()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->next = NULL;
    return s;
}

void destory(Stack *s)
{
    Stack *p = s->next;
    while (p != NULL)
    {
        free(s);
        s = p;
        p = p->next;
    }
}

int getLength(Stack *s)
{
    int length = 0;
    Stack *p = s->next;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

int isEmpty(Stack *s)
{
    return s->next == NULL;
}

void push(Stack *s, ElemType value)
{
    assert(s != NULL);
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = value;
    p->next = s->next;
    s->next = p;
}

ElemType pop(Stack *s)
{
    assert(s != NULL && s->next != NULL); /*栈空的情况*/
    Stack *p = s->next;                   /*p指向第一个数据结点*/
    ElemType value = p->data;
    s->next = p->next;
    free(p);
    return value;
}

#endif