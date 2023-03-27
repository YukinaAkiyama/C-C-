#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
//�������Ա�
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
} LNode, * LinkList;
// ��ʼ��
Status InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}
//�����ȡֵ
Status AssigList(LinkList& L)
{
	LinkList p, t;
	p = L;
	int e, i, n = 0;
	printf("��˵��Ҫ���뼸��Ԫ��\n");
	scanf_s("%d", &i);
	printf("��˵��Ҫ�����ֵ��");
	while (1)
	{
		scanf_s("%d", &e);
		t = new LNode;
		t->data = e;
		t->next = NULL;
		p->next = t;
		p = t;
		n++;
		if (n == i)
			break;
	}
	return OK;
}
//ȡ���ֵ
Status MAX(LinkList& L)
{
	int a;
	if (!L->next)
		return L->data;
	a = MAX(L->next);
	return a >= L->data ? a : L->data;
}
//����
Status Length(LinkList& L)
{
	if (!L->next)
		return 1;
	else
		return Length(L->next) + 1;
}
//��ƽ��ֵ
float Average(LinkList& L, int n)
{
	float b;
	if (!L->next)
		return L->data;
	else
	{
		b = Average(L->next, n - 1);
		return (b * (n - 1) + L->data) / n;
	}
}
int main()
{
	int a, n;
	float b;
	LinkList L;
	InitList(L);
	AssigList(L);
	a = MAX(L->next);
	printf("�����������ǣ�%d\n", a);
	a = Length(L->next);
	n = a;
	printf("���ĸ���Ϊ��%d\n", a);
	b = Average(L->next, n);
	printf("����Ԫ�ص�ƽ��ֵΪ��%f\n", b);
	return 0;
}

