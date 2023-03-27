/*数据结构与算法-第二章线性表课后习题
*课本第53页2.10
*题目:已知长度为n的线性表A采用顺序存储结构,请写一个时间复杂度为o(n)、空间复杂度为o(1)的算法,
*     该算法可删除线性表中所有值为item的数据元素。
*编译环境:VC 6.0
*/
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
#define MAXSIZE 5
#define OVERFLOW -1
#define OK 1
#define listIncrement 2
#define num_stop -1
typedef int elemType;

typedef struct
{
	elemType *elem;
	int length;
	int listsize;
}Sqlist;
int initList(Sqlist &list)
{
	list.elem=new int[MAXSIZE];
	if(!list.elem)
		exit(OVERFLOW);
	list.length=0;
	list.listsize=MAXSIZE;
	return OK;
}
int ListInsert(Sqlist &list,int i,int num)
{
	int *newbase;
	if(i<1)return ERROR;
	if(list.length==list.listsize)//即将超越数组大小时重新动态分配数组大小
	{
		newbase=(int*)realloc(list.elem,(list.listsize+listIncrement)*sizeof(int));
		if(!newbase)
			exit(OVERFLOW);
		list.elem=newbase;
		list.listsize+=listIncrement;
	}
	list.elem[i-1]=num;
	++list.length;
	return OK;
}
void printList(Sqlist list)/*用于测试数据是否存储入顺序表*/
{
	for(int k=0;k<list.length;k++)
		printf("%d ",list.elem[k]);
}
void deleteList(Sqlist &list,int num)
{
	int len=list.length;
	elemType *str=list.elem;
	int front=0;
	while(front<len)
	{
		while(front<len && str[front]!=num)
			front++;//值不为num时,指针右移,为从顺序表开头一直顺数到为num的元素
		if(front<len)
			while(front<len && str[len]==num)
				len--;//为需要删除的数字时,线性表长度减1,为从顺序表尾部删除尾部连续的为num的元素
		if(front<len)
		{
			str[front]=str[len-1];//题目仅要求删去值为num的元素,并未要求元素顺序排列不变,因此大胆猜想将靠后的元素往前移动
			front++;//前指针右移
			len--;//后指针左移
			list.length--;//变换一次,顺序表长度-1
		}
	}
}
int main()
{
	Sqlist list1;
	int flag;
	int num,count=0;
	flag=initList(list1);
	printf("请输入若干数字,并以%d结束:\n",num_stop);
	scanf("%d",&num);
	count++;
	while(num!=-1)
	{
		flag=ListInsert(list1,count,num);
		scanf("%d",&num);
		count++;
	}
	printf("输入数字为：\n");printList(list1);printf("\n");
	printf("需要删除的数字为:\n");
	scanf("%d",&num);
	deleteList(list1,num);
	printf("删除后的线性表为:\n");
	printList(list1);
	printf("\n");
	return 0;
}
