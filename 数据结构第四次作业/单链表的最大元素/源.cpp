#include <iostream>
using namespace std;
typedef int Status;
typedef int elemtype;
#define OK 1
#define ERROR 0 
typedef struct LNode
{
	elemtype data;
	struct LNode* next;
}LNode, * LinkList;

void CreateList_L(LinkList& L, int n)
{
	int i;
	LNode* r, * p;
	L = new LNode;
	L->next = NULL;
	r = L;
	cout << "������Ԫ�أ�\n";
	for (i = 0; i < n; ++i)
	{
		p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
void Maxelem_L(LinkList& L)
{
	int max, i = 0;
	LNode* p = L->next;
	max = p->data;
	while (p)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;
	}
	p = L->next;
	while (p)
	{
		i++;
		if (p->data == max)
			cout << "��" << i << "����㣬" << "ֵΪ" << p->data << endl;
		p = p->next;
	}
	cout << endl;
}
int main()
{
	int n1;
	LNode* la;

	cout << "���������Ա��Ԫ�ظ�����";
	cin >> n1;
	CreateList_L(la, n1);
	cout << "������ֵ���Ľ���ǣ�\n";
	Maxelem_L(la);
	return 0;
}