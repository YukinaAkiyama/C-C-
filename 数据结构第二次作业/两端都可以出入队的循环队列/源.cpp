#include<stdio.h>
#define maxSize 10

/* ˳������Ͷ��� */
typedef struct {
	int data[maxSize];
	int front;// ����ָ��
	int rear;// ��βָ��
} SqQueue;

/* ��ʼ������ */
void initQueue(SqQueue& qu) {
	qu.front = qu.rear = 0;// ���׺Ͷ�βָ���غϲ�ָ��0
}

/* ��ӣ��Ӷ�ͷ���룩 */
/* &quָ����Ҫ����Ԫ�صĶ��У�xָ����Ҫ�����Ԫ�� */
int enQueue(SqQueue& qu, int x) {
	if (qu.rear == (qu.front - 1 + maxSize) % maxSize) { // ����������������
		return 0;
	}
	else {
		/* ע�⣺����������ӣ����޸�ָ�� */
		qu.data[qu.front] = x;
		qu.front = (qu.front - 1 + maxSize) % maxSize;
		return 1;
	}
}

/* ���ӣ��Ӷ�β���ӣ�
/* &quָ����Ҫ���ӵĶ��У�&xָ����Ҫ�洢����Ԫ�ص�ֵ */
int deQueue(SqQueue& qu, int& x) {
	if (qu.rear == qu.front) { // ����ӿգ��Ͳ��ܳ�����
		return 0;
	}
	else {
		/* ע�⣺����������ӣ����޸�ָ�� */
		x = qu.data[qu.rear];
		qu.rear = (qu.rear - 1 + maxSize) % maxSize;
		return 1;
	}
}

/* ��ӡ���� */
void printQueue(SqQueue qu) {
	printf("\n");
	while (qu.rear != qu.front) {
		qu.front = (qu.front + 1) % maxSize;
		printf("%d\t", qu.data[qu.front]);
	}
	printf("\n");
}

int main() {
	SqQueue qu;
	initQueue(qu);
	int nums[] = { 1,2,3,4,5,6 };
	int n = 6;
	for (int i = 0; i < n; i++) {
		int m = enQueue(qu, nums[i]);// �������е�Ԫ�����
	}
	printQueue(qu);// ��ӡ����
	printf("1����");
	int x;
	deQueue(qu, x);// ��Ԫ��1����
	printQueue(qu);// ��ӡ����
	return 0;
}