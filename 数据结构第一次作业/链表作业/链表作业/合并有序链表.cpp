#include <stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	LNode* next;
}LNode, * LinkList;

//β�巨��������
int CreateList(LinkList& L, int n)
{
	LNode* p, * r; int i;
	L = new LNode;
	L->next = NULL;
	r = L;
	for (i = 0; i < n; i++)
	{
		p = new LNode;
		scanf_s("%d", &p->data);
		p->next = NULL; r->next = p;
		r = p;
	}
	return 0;
}



//�������
void print(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

//�ϲ�
void MergeList_L(LinkList& LA, LinkList& LB, LinkList& LC)
{

	LNode* pa; LNode* pb; LNode* pc;
	pa = LA->next; pb = LB->next;
	LC = LA;
	pc = LC;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	delete LB;
}

int main()
{
	LinkList LA; LinkList LB; LinkList LC; int n;
	printf("��������Ҫ������LA����ĳ��ȣ�\n");
	scanf_s("%d", &n);
	printf("������������Ҫ���������(β�巨�ҵ���)��\n");
	CreateList(LA, n);


	printf("��������Ҫ������LB����ĳ��ȣ�\n");
	scanf_s("%d", &n);
	printf("������������Ҫ���������(β�巨�ҵ���)��\n");
	CreateList(LB, n);

	printf("��ǰLA����Ϊ��\n");
	print(LA);
	printf("\n");
	printf("��ǰLB����Ϊ��\n");
	print(LB);
	printf("\n");

	MergeList_L(LA, LB, LC);
	printf("�ϲ����LC����Ϊ��\n");

	print(LC);
	return 0;
}
