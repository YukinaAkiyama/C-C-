#include <iostream>

using namespace std;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;

int InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return 1;
}

void TraveList(LinkList L)
{
	LNode* p;
	p = L->next;

	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 尾插法建立链表
void CreateList(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	LNode* r;
	r = L;
	for (int i = 0; i < n; i++)
	{
		printf("请输入链表第%d个元素的值:", i + 1);
		LNode* s;
		s = new LNode;
		scanf_s("%d", &s->data);
		s->next = NULL;
		r->next = s;
		r = s;
	}
}

// 链表分解
void DisCompose(LinkList& L1, LinkList& L2, LinkList& L3)
{
	LNode* p;
	p = L1->next;      // p为工作指针

	L2 = L1;
	L2->next = NULL;   // L2表初始化

	L3 = new LNode;   // 为L3申请结点空间
	L3->next = NULL;    // L3初始化为空表

	while (p != NULL)
	{
		LNode* r;
		r = p->next;      // 暂存p的后继
		if (p->data < 0)
		{
			p->next = L2->next;
			L2->next = p;       // 将小于0的结点链入L2表, 前插法
		}
		else if (p->data > 0)
		{
			p->next = L3->next;
			L3->next = p;
		}           // 将大于等于0的结点链入C表, 前插法

		p = r;   // p指向新的待处理结点
	}
}

int main()
{
	LinkList L1, L2, L3;

	if (InitList(L1))
	{
		printf("L1初始化成功!\n");
	}
	else
	{
		printf("L1初始化失败!\n");
	}

	printf("请输入L1的长度:");
	int n1;
	scanf_s("%d", &n1);
	CreateList(L1, n1);
	TraveList(L1);

	DisCompose(L1, L2, L3);
	printf("链表分解为L2、L3:\n");
	printf("L2: ");
	TraveList(L2);
	printf("L3: ");
	TraveList(L3);

	system("pause");

	return 0;
}
