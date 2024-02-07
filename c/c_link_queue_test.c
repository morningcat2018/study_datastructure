#include <stdio.h>
#include "c_link_queue.h"

// gcc c_link_queue_test.c && ./a.out
int main()
{

	printf("(1)初始化链队q\n");
	Queue *q = init();
	printf("(2)依次进链队元素a,b,c\n");
	push(q, 'a');
	push(q, 'b');
	push(q, 'c');
	push(q, 'd');
	push(q, 'g');
	printf("(3)链队为%s\n", (isEmpty(q) ? "空" : "非空"));
	printf("(4)链队q的元素个数:%d\n", getLength(q));
	printf("(5)出链队序列:");
	while (!isEmpty(q))
	{
		char value = pop(q);
		printf("%c ", value);
	}
	printf("\n");
	printf("(6)释放链队\n");
	destory(q);
	return 0;
}
