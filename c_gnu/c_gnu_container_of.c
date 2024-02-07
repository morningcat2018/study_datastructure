#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({    \
     const typeof( ((type *)0)->member ) *__mptr = (ptr); \
     (type *)( (char *)__mptr - offsetof(type,member) ); })

struct student
{
     int age;
     int num;
     int math;
};

// gcc c_gnu_container_of.c && ./a.out
int main(void)
{
     struct student stu = {18, 1, 2000};
     printf("%p \n", &stu);
     struct student *p = container_of(&stu.num, struct student, num);
     printf("%p \n", p);
     return 0;
}
