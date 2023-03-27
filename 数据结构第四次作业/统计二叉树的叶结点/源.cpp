#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

int ans = 0;

BiTree CreateBiTree()//建立二叉树
{
    ElemType x;
    BiTree T;
    scanf_s("%c", &x);
    if (x == '#')  //当输入‘#’时表示子树为空
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

void Leaf(BiTree T)//后序遍历统计叶子节点数目
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
