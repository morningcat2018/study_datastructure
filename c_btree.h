#ifndef C_B_TREE_H
#define C_B_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MaxSize 100
typedef char ElemType;

/**
 * 二叉树
 */
typedef struct node
{
    ElemType data;       /*数据元素*/
    struct node *lchild; /*指向左孩子*/
    struct node *rchild; /*指向右孩子*/
} BTNode;

/*由str串创建二叉链*/
BTNode *CreateBTNode(char *str)
{
    BTNode *root = NULL; /*建立的二叉树初始时为空*/
    BTNode *St[MaxSize];
    BTNode *p = NULL;

    int top = -1, k, j = 0;
    char ch;

    ch = str[j];
    while (ch != '\0') /*str未扫描完时循环*/
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break; /*为左结点*/
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break; /*为右结点*/
        default:
            if (ch < 'A' || ch > 'Z')
            {
                // printf("忽略该值%c\n", ch);
                break;
            }
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = NULL;
            p->rchild = NULL;
            if (root == NULL)
            {
                /*p指向二叉树的根结点*/
                root = p;
            }
            else /*已建立二叉树根结点*/
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
    return root;
}

/*返回data域为x的结点指针*/
BTNode *FindNode(BTNode *b, ElemType x)
{
    BTNode *p;
    if (b == NULL)
        return NULL;
    else if (b->data == x)
        return b;
    else
    {
        p = FindNode(b->lchild, x);
        if (p != NULL)
            return p;
        else
            return FindNode(b->rchild, x);
    }
}

/*返回*p结点的左孩子结点指针*/
BTNode *LchildNode(BTNode *p)
{
    return p->lchild;
}

/*返回*p结点的右孩子结点指针*/
BTNode *RchildNode(BTNode *p)
{
    return p->rchild;
}

/*以括号表示法输出二叉树*/
void DispBTNode(BTNode *b)
{
    if (b == NULL)
    {
        return;
    }
    printf("%c", b->data);
    if (b->lchild != NULL || b->rchild != NULL)
    {
        printf("(");
        DispBTNode(b->lchild);
        if (b->rchild != NULL)
            printf(",");
        DispBTNode(b->rchild);
        printf(")");
    }
}

/*先序遍历的递归算法*/
void PreOrder(BTNode *b)
{
    if (b != NULL)
    {
        printf("%c ", b->data); /*访问根结点*/
        PreOrder(b->lchild);    /*递归访问左子树*/
        PreOrder(b->rchild);    /*递归访问右子树*/
    }
}

void PreOrder1(BTNode *b)
{
    BTNode *p;
    struct
    {
        BTNode *pt;
        int tag;
    } St[MaxSize];
    int top = -1;
    top++;
    St[top].pt = b;
    St[top].tag = 1;
    while (top > -1) /*栈不空时循环*/
    {
        if (St[top].tag == 1) /*不能直接访问的情况*/
        {
            p = St[top].pt;
            top--;
            if (p != NULL)
            {
                top++; /*右孩子进栈*/
                St[top].pt = p->rchild;
                St[top].tag = 1;
                top++; /*左孩子进栈*/
                St[top].pt = p->lchild;
                St[top].tag = 1;
                top++; /*根结点进栈*/
                St[top].pt = p;
                St[top].tag = 0;
            }
        }
        if (St[top].tag == 0) /*直接访问的情况*/
        {
            printf("%c ", St[top].pt->data);
            top--;
        }
    }
}

void PreOrder2(BTNode *b)
{
    BTNode *St[MaxSize], *p;
    int top = -1;
    if (b != NULL)
    {
        top++; /*根结点入栈*/
        St[top] = b;
        while (top > -1) /*栈不为空时循环*/
        {
            p = St[top]; /*退栈并访问该结点*/
            top--;
            printf("%c ", p->data);
            if (p->rchild != NULL) /*右孩子入栈*/
            {
                top++;
                St[top] = p->rchild;
            }
            if (p->lchild != NULL) /*左孩子入栈*/
            {
                top++;
                St[top] = p->lchild;
            }
        }
        printf("\n");
    }
}

/*中序遍历的递归算法*/
void InOrder(BTNode *b)
{
    if (b != NULL)
    {
        InOrder(b->lchild);     /*递归访问左子树*/
        printf("%c ", b->data); /*访问根结点*/
        InOrder(b->rchild);     /*递归访问右子树*/
    }
}

void InOrder1(BTNode *b)
{
    BTNode *p;
    struct
    {
        BTNode *pt;
        int tag;
    } St[MaxSize];
    int top = -1;
    top++;
    St[top].pt = b;
    St[top].tag = 1;
    while (top > -1) /*栈不空时循环*/
    {
        if (St[top].tag == 1) /*不能直接访问的情况*/
        {
            p = St[top].pt;
            top--;
            if (p != NULL)
            {
                top++; /*右孩子进栈*/
                St[top].pt = p->rchild;
                St[top].tag = 1;
                top++; /*根结点进栈*/
                St[top].pt = p;
                St[top].tag = 0;
                top++; /*左孩子进栈*/
                St[top].pt = p->lchild;
                St[top].tag = 1;
            }
        }
        if (St[top].tag == 0) /*直接访问的情况*/
        {
            printf("%c ", St[top].pt->data);
            top--;
        }
    }
}

void InOrder2(BTNode *b)
{
    BTNode *St[MaxSize], *p;
    int top = -1;
    if (b != NULL)
    {
        p = b;
        while (top > -1 || p != NULL)
        {
            while (p != NULL)
            {
                top++;
                St[top] = p;
                p = p->lchild;
            }
            if (top > -1)
            {
                p = St[top];
                top--;
                printf("%c ", p->data);
                p = p->rchild;
            }
        }
        printf("\n");
    }
}

/*后序遍历的递归算法*/
void PostOrder(BTNode *b)
{
    if (b != NULL)
    {
        PostOrder(b->lchild);   /*递归访问左子树*/
        PostOrder(b->rchild);   /*递归访问右子树*/
        printf("%c ", b->data); /*访问根结点*/
    }
}

void PostOrder1(BTNode *b)
{
    BTNode *p;
    struct
    {
        BTNode *pt;
        int tag;
    } St[MaxSize];
    int top = -1;
    top++;
    St[top].pt = b;
    St[top].tag = 1;
    while (top > -1) /*栈不空时循环*/
    {
        if (St[top].tag == 1) /*不能直接访问的情况*/
        {
            p = St[top].pt;
            top--;
            if (p != NULL)
            {
                top++; /*根结点进栈*/
                St[top].pt = p;
                St[top].tag = 0;
                top++; /*右孩子进栈*/
                St[top].pt = p->rchild;
                St[top].tag = 1;
                top++; /*左孩子进栈*/
                St[top].pt = p->lchild;
                St[top].tag = 1;
            }
        }
        if (St[top].tag == 0) /*直接访问的情况*/
        {
            printf("%c ", St[top].pt->data);
            top--;
        }
    }
}

void PostOrder2(BTNode *b)
{
    BTNode *St[MaxSize];
    BTNode *p;
    int flag, top = -1; /*栈指针置初值*/
    if (b != NULL)
    {
        do
        {
            while (b != NULL) /*将t的所有左结点入栈*/
            {
                top++;
                St[top] = b;
                b = b->lchild;
            }
            p = NULL; /*p指向当前结点的前一个已访问的结点*/
            flag = 1; /*设置b的访问标记为已访问过*/
            while (top != -1 && flag)
            {
                b = St[top];        /*取出当前的栈顶元素*/
                if (b->rchild == p) /*右子树不存在或已被访问,访问之*/
                {
                    printf("%c ", b->data); /*访问*b结点*/
                    top--;
                    p = b; /*p指向则被访问的结点*/
                }
                else
                {
                    b = b->rchild; /*t指向右子树*/
                    flag = 0;      /*设置未被访问的标记*/
                }
            }
        } while (top != -1);
        printf("\n");
    }
}

// 层次遍历
void TraverseLevel(BTNode *b)
{
    BTNode *Qu[MaxSize]; /*定义循环队列*/
    int front, rear;     /*定义队首和队尾指针*/
    front = rear = 0;    /*置队列为空队列*/
    if (b != NULL)
        printf("%c ", b->data);
    rear++; /*结点指针进入队列*/
    Qu[rear] = b;
    while (rear != front) /*队列不为空*/
    {
        front = (front + 1) % MaxSize;
        b = Qu[front];         /*队头出队列*/
        if (b->lchild != NULL) /*输出左孩子,并入队列*/
        {
            printf("%c ", b->lchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->lchild;
        }
        if (b->rchild != NULL) /*输出右孩子,并入队列*/
        {
            printf("%c ", b->rchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->rchild;
        }
    }
    printf("\n");
}

/*求二叉树b的深度*/
int BTNodeDepth(BTNode *b)
{
    int lchilddep, rchilddep;
    if (b == NULL)
        return (0); /*空树的高度为0*/
    else
    {
        lchilddep = BTNodeDepth(b->lchild); /*求左子树的高度为lchilddep*/
        rchilddep = BTNodeDepth(b->rchild); /*求右子树的高度为rchilddep*/
        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
    }
}

/*求二叉树b的宽度*/
int BTWidth(BTNode *b)
{
    struct
    {
        int lno;     /*结点的层次编号*/
        BTNode *p;   /*结点指针*/
    } Qu[MaxSize];   /*定义顺序非循环队列*/
    int front, rear; /*定义队首和队尾指针*/
    int lnum, max, i, n;
    front = rear = 0; /*置队列为空队*/
    if (b != NULL)
    {
        rear++;
        Qu[rear].p = b;       /*根结点指针入队*/
        Qu[rear].lno = 1;     /*根结点的层次编号为1*/
        while (rear != front) /*队列不为空*/
        {
            front++;
            b = Qu[front].p; /*队头出队*/
            lnum = Qu[front].lno;
            if (b->lchild != NULL) /*左孩子入队*/
            {
                rear++;
                Qu[rear].p = b->lchild;
                Qu[rear].lno = lnum + 1;
            }
            if (b->rchild != NULL) /*右孩子入队*/
            {
                rear++;
                Qu[rear].p = b->rchild;
                Qu[rear].lno = lnum + 1;
            }
        }
        max = 0;
        lnum = 1;
        i = 1;
        while (i <= rear)
        {
            n = 0;
            while (i <= rear && Qu[i].lno == lnum)
            {
                n++;
                i++;
            }
            lnum = Qu[i].lno;
            if (n > max)
                max = n;
        }
        return max;
    }
    else
        return 0;
}

/*求二叉树b的结点个数*/
int Nodes(BTNode *b)
{
    int num1, num2;
    if (b == NULL)
        return 0;
    else if (b->lchild == NULL && b->rchild == NULL)
        return 1;
    else
    {
        num1 = Nodes(b->lchild);
        num2 = Nodes(b->rchild);
        return (num1 + num2 + 1);
    }
}

/*求二叉树b的叶子结点个数*/
int LeafNodes(BTNode *b)
{
    int num1, num2;
    if (b == NULL)
        return 0;
    else if (b->lchild == NULL && b->rchild == NULL)
        return 1;
    else
    {
        num1 = LeafNodes(b->lchild);
        num2 = LeafNodes(b->rchild);
        return (num1 + num2);
    }
}

#endif