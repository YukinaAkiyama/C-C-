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

//���򴴽�������
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
	if (!T1 && !T2)	//T1��T2��Ϊ��?
		return true;
	if (!T1 || !T2)	//T1��T2��һ��Ϊ�գ�һ�Ų�Ϊ��?
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
	printf("��������ڵ㣬��#����ڵ�\n");
	CreateBiTree(T1);
	getchar();   //�Ե��س�
	printf("�ٴ���һ��\n");
	getchar();  //�Ե��س�
	CreateBiTree(T2);
	getchar();  //�Ե��س�
	printf("�����ɹ�\n");
	if (check(T1, T2))
		printf("T1��T2���\n");
	else
		printf("T1��T2�����\n");

	return 0;
}
