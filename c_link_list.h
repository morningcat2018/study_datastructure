#ifndef C_LINK_LIST_H
#define C_LINK_LIST_H

// #include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
} ListNode;

// 初始化链表
ListNode *newList()
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    return head;
}

// 销毁链表
void destoryList(ListNode *head)
{
    ListNode *p, *q;
    p = head;
    q = p->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}

// 判空
int isEmpty(ListNode *head)
{
    return head->next == NULL;
}

// 长度
int getLength(ListNode *head)
{
    ListNode *p = head;
    int length = 0;
    while (p->next != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

ElemType valueOf(ListNode *head, int index)
{
    ListNode *p;
    int j = 0;
    for (p = head->next; p != NULL; p = p->next)
    {
        j++;
        if (j == index)
            return p->data;
    }
    return 0;
}

int indexOf(ListNode *head, ElemType value)
{
    ListNode *p;
    int flag = 0, i = 0;
    for (p = head->next; p != NULL; p = p->next)
    {
        i++;
        if (p->data == value)
        {
            return i;
        }
    }
    return -1;
}

int insertNode(ListNode *head, int index, ElemType value)
{
    assert(head != NULL);
    ListNode *p, *t;
    int j = 0;
    for (p = head; p != NULL; p = p->next)
    {
        j++;
        if (j == index)
        {
            t = (ListNode *)malloc(sizeof(ListNode));
            t->data = value;
            t->next = p->next;
            p->next = t;
            return 1;
        }
    }
    return 0;
}

void insert(ListNode *head, ElemType value)
{
    assert(head != NULL);
    ListNode *p, *t;
    for (p = head; p != NULL; p = p->next)
    {
        if (p->next == NULL)
        {
            t = (ListNode *)malloc(sizeof(ListNode));
            t->data = value;
            t->next = NULL;
            p->next = t;
            return;
        }
    }
}

int deleteNode(ListNode *head, int index)
{
    assert(head != NULL);
    ListNode *p = head, *q;
    int j = 0;
    for (p = head; p != NULL; p = p->next)
    {
        j++;
        if (j == index)
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
            return 1;
        }
    }
    return 0;
}

#endif // C_LINK_LIST_H