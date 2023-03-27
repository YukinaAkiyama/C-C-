#include <stdio.h>
#include<stdlib.h>
 
typedef struct LNode
{
	int data;
	LNode *next;
}LNode,*LinkList;
 
//尾插法创建链表
int CreateList(LinkList &L,int n)
{
	LNode *p,*r;int i;
	L=new LNode;
	L->next=NULL;
	r=L;
	for(i=0;i<n;i++)
	{
		p=new LNode;
		scanf("%d",&p->data);
		p->next=NULL;r->next=p;
		r=p;
	}
	return 0;
}
 
 
 
//输出链表
void print(LinkList L)
{
	LinkList p;
	p=L->next;
	while(p)
	{
	  printf("%d ",p->data);
	  p=p->next;
	}
}
 
//合并
void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC)
{
 
	LNode *pa;LNode *pb;LNode *pc;
	pa=LA->next;pb=LB->next;
	LC=LA;
	pc=LC;
	while (pa&&pb)
	{
		if(pa->data<pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else if(pa->data>pb->data)
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		else
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	delete LB;
}
 
int main()
{
	LinkList LA;LinkList LB;LinkList LC;int n;
	printf("请输入需要创建的LA链表的长度：\n");
	scanf("%d",&n);
	printf("请依次输入需要存入的数据(尾插法且递增)：\n");
	CreateList (LA,n);
 
 
	printf("请输入需要创建的LB链表的长度：\n");
	scanf("%d",&n);
	printf("请依次输入需要存入的数据(尾插法且递增)：\n");
	CreateList (LB,n);
 
	printf("当前LA链表为：\n");
	print(LA);
	printf("\n");
	printf("当前LB链表为：\n");
	print(LB);
	printf("\n");
 
	MergeList_L(LA,LB,LC);
	printf("合并后的LC链表为：\n");
 
	print(LC);
	return 0;
}
