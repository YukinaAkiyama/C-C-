#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
//定义线性表
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
} LNode, * LinkList;
// 初始化
Status InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}
//链表的取值
Status AssigList(LinkList& L)
{
	LinkList p, t;
	p = L;
	int e, i, n = 0;
	printf("请说明要插入几个元素\n");
	scanf_s("%d", &i);
	printf("请说明要输入的值：");
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
//取最大值
Status MAX(LinkList& L)
{
	int a;
	if (!L->next)
		return L->data;
	a = MAX(L->next);
	return a >= L->data ? a : L->data;
}
//求结点
Status Length(LinkList& L)
{
	if (!L->next)
		return 1;
	else
		return Length(L->next) + 1;
}
//求平均值
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
	printf("输入的最大数是：%d\n", a);
	a = Length(L->next);
	n = a;
	printf("结点的个数为：%d\n", a);
	b = Average(L->next, n);
	printf("所有元素的平均值为：%f\n", b);
	return 0;
}

