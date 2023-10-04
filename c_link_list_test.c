#include <stdio.h>
#include "c_link_list.h"

void printList(ListNode *head)
{
    for (ListNode *p = head->next; p != NULL; p = p->next)
        printf("%c ", p->data);
    printf("\n");
}

// gcc c_link_list_test.c && ./a.out
int main()
{
    printf("（1）初始化单链表h\n");
    ListNode *head = newList();
    printf("（2）依次插入a,b,c,d,e元素\n");
    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'd');
    insert(head, 'e');
    printf("（3）输出单链表:");
    printList(head);
    printf("（4）获取链表长度:");
    printf("%d\n", getLength(head));
    printf("（5）是否为空:");
    printf("%d\n", isEmpty(head));
    printf("（6）查询特点位置的值");
    printf("%c\n", valueOf(head, 3));
    printf("（7）查询位置");
    printf("索引位置%d\n", indexOf(head, 'a'));
    printf("（8）插入节点\n");
    insertNode(head, 4, 'f');
    printf("（9）输出单链表:");
    printList(head);
    printf("（10）删除节点\n");
    deleteNode(head, 3);
    printf("（11）输出单链表:");
    printList(head);
    printf("（12）释放单链表\n");
    destoryList(head);
    return 0;
}
