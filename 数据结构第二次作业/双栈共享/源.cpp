#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define INIT_SIZE 5
#define INCREASE_SIZE 2
#define OVERFLOW -1
#define EMPTY_ELEM -1

typedef int ElemType;
typedef int status;
typedef struct {
    int top[2], bot[2];//栈顶和栈底指针
    ElemType* v;//栈数组
    int m;//栈最大可容纳元素个数
} DblStack;

//数组初始化要使用malloc, 否则只是进行了声明, 未开辟空间无法存储内容
void initDblStack(DblStack& stack) {
    ElemType* arr = (ElemType*)malloc(sizeof(ElemType) * INIT_SIZE);
    stack.v = arr;
    stack.m = INIT_SIZE;
    stack.top[0] = 0;
    stack.bot[0] = 0;
    stack.top[1] = stack.m - 1;
    stack.bot[1] = stack.m - 1;
}

status isEmpty(DblStack stack) {
    if (stack.top[0] == stack.bot[0] && stack.top[1] == stack.bot[1]) {
        return 1;
    }
    return 0;
}


status isFull(DblStack stack) {
    if (stack.top[1] - stack.top[0] <= -1 || stack.top[1] < 0 || stack.top[0] > stack.m - 1) {
        return 1;
    }
    return 0;
}

//右栈稍麻烦, 需要一些计算步骤处理
void extendCapacity(DblStack& stack) {
    ElemType* new_arr = (ElemType*)malloc(sizeof(ElemType) * (stack.m + INCREASE_SIZE));
    int new_size = stack.m + INCREASE_SIZE;
    int i, j;
    for (i = stack.bot[0]; i < stack.top[0]; i++) {
        new_arr[i] = stack.v[i];
    }

    int n = stack.bot[1] - stack.top[1];
    for (j = new_size - 1, i = stack.m - 1; j > new_size - 1 - n; j--, i--) {
        new_arr[j] = stack.v[i];
    }
    //重新计算右栈
    stack.bot[1] = new_size - 1;
    stack.top[1] = stack.bot[1] - n;
    stack.m = new_size;

    ElemType* old_arr = stack.v;
    stack.v = new_arr;
    free(old_arr);
}

status pushLeft(DblStack& stack, ElemType e) {
    if (isFull(stack) == TRUE) extendCapacity(stack);
    stack.v[stack.top[0]] = e;
    stack.top[0]++;
    return OK;
}

status pushRight(DblStack& stack, ElemType e) {
    if (isFull(stack) == TRUE) extendCapacity(stack);
    stack.v[stack.top[1]] = e;
    stack.top[1]--;
    return OK;
}

ElemType popLeft(DblStack& stack) {
    if (isEmpty(stack) == TRUE)return ERROR;
    if (stack.top[0] <= stack.bot[0])return ERROR;
    ElemType e = stack.v[--stack.top[0]];
    stack.v[stack.top[0]] = EMPTY_ELEM;
    return e;
}

ElemType popRight(DblStack& stack) {
    if (isEmpty(stack) == TRUE)return ERROR;
    if (stack.top[1] >= stack.bot[1])return ERROR;
    ElemType e = stack.v[++stack.top[1]];
    stack.v[stack.top[1]] = EMPTY_ELEM;
    return e;
}

void printDblStack(DblStack stack) {
    for (int i = 0; i < stack.m; i++) {
        printf("|%d|\t", stack.v[i]);
    }
    printf("\n");
}


//测试
int main() {
    DblStack stack;
    initDblStack(stack);
    printf("stack is Empty:%d\n", isEmpty(stack));

    pushLeft(stack, 1);
    pushLeft(stack, 2);
    pushLeft(stack, 3);
    pushLeft(stack, 1010);

    pushRight(stack, 5);
    pushRight(stack, 4);
    pushRight(stack, 3);
    pushRight(stack, 2);

    pushLeft(stack, 4);
    pushLeft(stack, 4);
    printDblStack(stack);

    printf("%d\n", popLeft(stack));
    printf("%d\n", popLeft(stack));
    printf("%d\n", popRight(stack));
    printDblStack(stack);

    return 0;
}