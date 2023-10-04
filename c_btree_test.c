#include <stdio.h>
#include "c_btree.h"

void printNode(BTNode *node)
{
    if (node == NULL)
        return;
    BTNode *lp, *rp;
    lp = LchildNode(node);
    if (lp != NULL)
        printf("左孩子为%c ", lp->data);
    else
        printf("无左孩子 ");
    rp = RchildNode(node);
    if (rp != NULL)
        printf("右孩子为%c\n", rp->data);
    else
        printf("无右孩子\n");
}

// gcc c_btree_test.c && ./a.out
int main()
{
    BTNode *b = CreateBTNode("A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("创建树完成\n");
    printf("(1)输出二叉树:\n");
    DispBTNode(b);
    printf("\n(2)'H'结点:");
    printNode(FindNode(b, 'H'));
    printf("(3)二叉树b的深度:%d\n", BTNodeDepth(b));
    printf("(4)二叉树b的宽度:%d\n", BTWidth(b));
    printf("(5)二叉树b的结点个数:%d\n", Nodes(b));
    printf("(6)二叉树b的叶子结点个数:%d\n", LeafNodes(b));

    printf("\n层次遍历序列:");
    TraverseLevel(b);
    printf("\n先序遍历序列:");
    printf("\n递归算法法0:");
    PreOrder(b);
    printf("\n非递归算法1:");
    PreOrder1(b);
    printf("\n非递归算法2:");
    PreOrder2(b);
    printf("\n中序遍历序列:");
    printf("\n递归算法法0:");
    InOrder(b);
    printf("\n非递归算法1:");
    InOrder1(b);
    printf("\n非递归算法2:");
    InOrder2(b);
    printf("\n后序遍历序列:");
    printf("\n递归算法法0:");
    PostOrder(b);
    printf("\n非递归算法1:");
    PostOrder1(b);
    printf("\n非递归算法2:");
    PostOrder2(b);
    return 0;
}