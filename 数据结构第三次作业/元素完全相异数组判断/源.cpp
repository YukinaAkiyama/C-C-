#include <stdio.h>

void Input(int* a, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf_s("%d", &a[i * n + j]);
}

void Judge(int* a, int m, int n)
{
	int i, j, k, p;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
				if (a[i * n + k] == a[i * n + j])
				{
					printf("No!They are partly the same!\n");
					return;
				}
			for (p = i + 1; p < m; p++)
			{
				for (k = 0; k < n; k++)
				{

					if (a[p * n + k] == a[i * n + j])
					{
						printf("No!They are partly the same!\n");
						return;
					}
				}
			}
		}
	}
	printf("Yes!They are different from each other!\n");
}

int main(void)
{
	int a[100], m, n, num;    //用指针，如果for循环会有行宽限制				num:数组个数;m,n:数组大小.
	printf("Please enter the number of two-dimensional arrays to be entered!\n");
	scanf_s("%d", &num);
	getchar();  //吃掉回车
	while (num--)
	{
		printf("Enter m, n to determine the size of the two-dimensional array!\n");
		scanf_s("%d %d", &m, &n);
		printf("Please enter an array!\n");
		getchar();
		Input(a, m, n);
		Judge(a, m, n);
	}
	return 0;
}
