#include <stdio.h>
#include "c_link_stack.h"

// gcc c_link_stack_test.c && ./a.out
int main()
{
    printf("(1)初始化链栈s\n");
    Stack *s = init();
    printf("(2)链栈为%s\n", isEmpty(s) ? "空" : "非空");
    printf("(3)依次进链栈元素a,b,c,d,e\n");
    push(s, 'a');
    push(s, 'b');
    push(s, 'c');
    push(s, 'd');
    push(s, 'e');
    printf("(4)链栈为%s\n", isEmpty(s) ? "空" : "非空");
    printf("(5)链栈长度:%d\n", getLength(s));
    printf("(7)出链栈序列:");
    while (!isEmpty(s))
    {
        char v = pop(s);
        printf("%c ", v);
    }
    printf("\n");
    printf("(8)链栈为%s\n", isEmpty(s) ? "空" : "非空");
    printf("(9)释放链栈\n");
    destory(s);
    return 0;
}
