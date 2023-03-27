#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

//���������
typedef struct BiTNode
{
    char data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

typedef BiTree ElemType;	//�Ѷ��е�Ԫ�ض���Ϊ��
///

//
//�������
typedef struct
{
    ElemType data[MAXSIZE];
    int front, rear;
}SeqQueue, * PSeqQueue;

//���еĻ�������
void InitQueue(PSeqQueue Q);

void InQueue(PSeqQueue Q, ElemType* e);

void OutQueue(PSeqQueue Q, ElemType* e);

int IsEmpty(PSeqQueue Q);

int IsFull(PSeqQueue Q);


//���Ļ�������
void CreateTree(BiTree* T);

//˳��ʵ�����Ĳ�α���
void LevelOrder(BiTree T);

//��������������
int Width(BiTree T);

//������
void visit(BiTree T);

int main()
{
    BiTree T = 0;
    int width;

    printf("�빹��һ�ö�������#��ʾ�գ�:");
    CreateTree(&T);

    printf("��α������У�\n");
    LevelOrder(T);
    putchar('\n');

    width = Width(T);
    printf("���������Ϊ��%d\n", width);

    return 0;
}

void visit(BiTNode* p)
{
    printf("%c ", p->data);
}

//ʹ�������������������
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

//���Ĳ�α���
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

//ʹ�õ���ѭ������
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
    if (T == NULL)  return 0;                       //���տ��Ϊ0

    SeqQueue Q;
    int temp = 0, last = 0, max = 0;                //�ݴ�temp��Ŀ�����������ֵ�Ƚϣ�lastһ������һ������ڶ����е�λ��
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

