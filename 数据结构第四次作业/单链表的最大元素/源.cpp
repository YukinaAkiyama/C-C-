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
	cout << "请输入元素：\n";
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
			cout << "第" << i << "个结点，" << "值为" << p->data << endl;
		p = p->next;
	}
	cout << endl;
}
int main()
{
	int n1;
	LNode* la;

	cout << "请输入线性表的元素个数：";
	cin >> n1;
	CreateList_L(la, n1);
	cout << "链表中值最大的结点是：\n";
	Maxelem_L(la);
	return 0;
}