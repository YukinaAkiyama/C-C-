#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

int ans = 0;

BiTree CreateBiTree()//����������
{
    ElemType x;
    BiTree T;
    scanf_s("%c", &x);
    if (x == '#')  //�����롮#��ʱ��ʾ����Ϊ��
        T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = x;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    return T;
}

void Leaf(BiTree T)//�������ͳ��Ҷ�ӽڵ���Ŀ
{
    if (T != NULL)
    {
        Leaf(T->lchild);
        Leaf(T->rchild);
        if (T->lchild == NULL && T->rchild == NULL)
            ans++;
    }

}

int main()
{

    BiTree root = CreateBiTree();
    Leaf(root);
    printf("%d\n", ans);

    return 0;
}
