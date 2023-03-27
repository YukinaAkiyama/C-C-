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

// β�巨��������
void CreateList(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	LNode* r;
	r = L;
	for (int i = 0; i < n; i++)
	{
		printf("�����������%d��Ԫ�ص�ֵ:", i + 1);
		LNode* s;
		s = new LNode;
		scanf_s("%d", &s->data);
		s->next = NULL;
		r->next = s;
		r = s;
	}
}

// ����ֽ�
void DisCompose(LinkList& L1, LinkList& L2, LinkList& L3)
{
	LNode* p;
	p = L1->next;      // pΪ����ָ��

	L2 = L1;
	L2->next = NULL;   // L2���ʼ��

	L3 = new LNode;   // ΪL3������ռ�
	L3->next = NULL;    // L3��ʼ��Ϊ�ձ�

	while (p != NULL)
	{
		LNode* r;
		r = p->next;      // �ݴ�p�ĺ��
		if (p->data < 0)
		{
			p->next = L2->next;
			L2->next = p;       // ��С��0�Ľ������L2��, ǰ�巨
		}
		else if (p->data > 0)
		{
			p->next = L3->next;
			L3->next = p;
		}           // �����ڵ���0�Ľ������C��, ǰ�巨

		p = r;   // pָ���µĴ�������
	}
}

int main()
{
	LinkList L1, L2, L3;

	if (InitList(L1))
	{
		printf("L1��ʼ���ɹ�!\n");
	}
	else
	{
		printf("L1��ʼ��ʧ��!\n");
	}

	printf("������L1�ĳ���:");
	int n1;
	scanf_s("%d", &n1);
	CreateList(L1, n1);
	TraveList(L1);

	DisCompose(L1, L2, L3);
	printf("����ֽ�ΪL2��L3:\n");
	printf("L2: ");
	TraveList(L2);
	printf("L3: ");
	TraveList(L3);

	system("pause");

	return 0;
}
