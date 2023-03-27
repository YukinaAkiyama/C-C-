#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

//先序创建二叉树
void CreateBiTree(BiTree& T)
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

bool check(BiTNode* T1, BiTNode* T2)
{
	if (!T1 && !T2)	//T1和T2都为空?
		return true;
	if (!T1 || !T2)	//T1，T2有一颗为空，一颗不为空?
		return false;
	if (T1 && T2)
	{
		if (T1->data != T2->data)
			return false;
		bool	l = check(T1->lchild, T2->lchild);
		bool	r = check(T1->rchild, T2->rchild);
		return l && r;
	}
}




int main()
{
	BiTree T1 = NULL, T2 = NULL;
	printf("先序输入节点，以#虚设节点\n");
	CreateBiTree(T1);
	getchar();   //吃掉回车
	printf("再创建一棵\n");
	getchar();  //吃掉回车
	CreateBiTree(T2);
	getchar();  //吃掉回车
	printf("创建成功\n");
	if (check(T1, T2))
		printf("T1和T2相等\n");
	else
		printf("T1和T2不相等\n");

	return 0;
}
