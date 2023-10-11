#include <stdio.h>

struct student
{
    int id;
    char *name;
};

void printStu(struct student *stu)
{
    printf("student info :id: %d,name:%s\n", stu->id, stu->name);
}

// gcc c_gnu_struct_test.c && ./a.out
int main()
{
    // 指定初始化
    struct student stu = {
        .id = 104,
        .name = "mcc"};
    printStu(&stu);

    // 指定初始化:部分赋值
    struct student stu2 = {
        .name = "lisi"};
    printStu(&stu2);
    return 0;
}