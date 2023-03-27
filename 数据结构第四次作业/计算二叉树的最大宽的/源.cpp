#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

//定义二叉树
typedef struct BiTNode
{
    char data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

typedef BiTree ElemType;	//把队列的元素定义为树
///

//
//定义队列
typedef struct
{
    ElemType data[MAXSIZE];
    int front, rear;
}SeqQueue, * PSeqQueue;

//队列的基本操作
void InitQueue(PSeqQueue Q);

void InQueue(PSeqQueue Q, ElemType* e);

void OutQueue(PSeqQueue Q, ElemType* e);

int IsEmpty(PSeqQueue Q);

int IsFull(PSeqQueue Q);


//树的基本操作
void CreateTree(BiTree* T);

//顺便实现树的层次遍历
void LevelOrder(BiTree T);

//求二叉树的最大宽度
int Width(BiTree T);

//输出结点
void visit(BiTree T);

int main()
{
    BiTree T = 0;
    int width;

    printf("请构造一棵二叉树（#表示空）:");
    CreateTree(&T);

    printf("层次遍历序列：\n");
    LevelOrder(T);
    putchar('\n');

    width = Width(T);
    printf("树的最大宽度为：%d\n", width);

    return 0;
}

void visit(BiTNode* p)
{
    printf("%c ", p->data);
}

//使用先序遍历构建二叉树
void CreateTree(BiTree* T)
{
    char ch;

    scanf_s("%c", &ch);

    if (ch == '#')
    {
        (*T) = NULL;

        return;
    }
    else
    {
        (*T) = (BiTree)malloc(sizeof(BiTNode));
        memcpy(&(*T)->data, &ch, sizeof(char));
        (*T)->lchild = (*T)->rchild = NULL;

        CreateTree(&(*T)->lchild);
        CreateTree(&(*T)->rchild);
    }
}

//树的层次遍历
void LevelOrder(BiTree T)
{

    SeqQueue Q;
    ElemType e = T;

    InitQueue(&Q);

    InQueue(&Q, &e);

    while (IsEmpty(&Q) != 1)
    {
        OutQueue(&Q, &e);
        visit(e);

        if (e->lchild != NULL)
        {
            InQueue(&Q, &e->lchild);
        }

        if (e->rchild != NULL)
        {
            InQueue(&Q, &e->rchild);
        }
    }
}

void InitQueue(PSeqQueue Q)
{
    if (Q == NULL)  return;

    Q->front = Q->rear = 0;
    memset(Q->data, 0, sizeof(ElemType) * MAXSIZE);
}

//使用的是循环队列
void InQueue(PSeqQueue Q, ElemType* e)
{
    if (Q == NULL || e == NULL)     return;

    if (!IsFull(Q))
    {
        memcpy(&Q->data[Q->rear], e, sizeof(ElemType));
        Q->rear = (Q->rear + 1) % MAXSIZE;
    }
}

void OutQueue(PSeqQueue Q, ElemType* e)
{
    if (Q == NULL)  return;

    if (!IsEmpty(Q))
    {
        memcpy(e, &Q->data[Q->front], sizeof(ElemType));
        Q->front = (Q->front + 1) % MAXSIZE;
    }
}

int IsEmpty(PSeqQueue Q)
{
    if (Q->rear == Q->front)        return 1;

    return 0;
}

int IsFull(PSeqQueue Q)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)  return 1;

    return 0;
}

int Width(BiTree T)
{
    if (T == NULL)  return 0;                       //树空宽度为0

    SeqQueue Q;
    int temp = 0, last = 0, max = 0;                //暂存temp层的宽度用来和最大值比较，last一层的最后一个结点在队列中的位置
    ElemType e = T;

    InitQueue(&Q);

    InQueue(&Q, &e);

    while (Q.front <= last)
    {
        OutQueue(&Q, &e);
        temp++;

        if (e->lchild != NULL)
        {
            InQueue(&Q, &e->lchild);
        }

        if (e->rchild != NULL)
        {
            InQueue(&Q, &e->rchild);
        }

        if (Q.front > last)
        {
            last = Q.rear - 1;

            max = max > temp ? max : temp;
            temp = 0;
        }
    }

    return max;
}

