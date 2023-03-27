#include<stdio.h>
#define maxSize 10

/* 顺序队类型定义 */
typedef struct {
	int data[maxSize];
	int front;// 队首指针
	int rear;// 队尾指针
} SqQueue;

/* 初始化队列 */
void initQueue(SqQueue& qu) {
	qu.front = qu.rear = 0;// 队首和队尾指针重合并指向0
}

/* 入队（从队头插入） */
/* &qu指的是要插入元素的队列；x指的是要插入的元素 */
int enQueue(SqQueue& qu, int x) {
	if (qu.rear == (qu.front - 1 + maxSize) % maxSize) { // 如果队满，则不能入队
		return 0;
	}
	else {
		/* 注意：这里是先入队，再修改指针 */
		qu.data[qu.front] = x;
		qu.front = (qu.front - 1 + maxSize) % maxSize;
		return 1;
	}
}

/* 出队（从队尾出队）
/* &qu指的是要出队的队列；&x指的是要存储出队元素的值 */
int deQueue(SqQueue& qu, int& x) {
	if (qu.rear == qu.front) { // 如果队空，就不能出队了
		return 0;
	}
	else {
		/* 注意：这里是先入队，再修改指针 */
		x = qu.data[qu.rear];
		qu.rear = (qu.rear - 1 + maxSize) % maxSize;
		return 1;
	}
}

/* 打印队列 */
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
		int m = enQueue(qu, nums[i]);// 将数组中的元素入队
	}
	printQueue(qu);// 打印队列
	printf("1出队");
	int x;
	deQueue(qu, x);// 将元素1出队
	printQueue(qu);// 打印队列
	return 0;
}