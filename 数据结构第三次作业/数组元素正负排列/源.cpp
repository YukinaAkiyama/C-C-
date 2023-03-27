#include<stdio.h>

void Arrange(int A[], int n)
// n��������������A�У����㷨�����������������������и�����ǰ��
{
    int i = 0, j = n - 1, x;
    while (i < j)
    {
        while (i < j && A[i]>0)
            i++;
        while (i < j && A[j] < 0)
            j--;
        if (i < j)
        {
            x = A[i];
            A[i++] = A[j];
            A[j--] = x;
            //�任A[i]��A[j]
        }
    }
}

int main()
{
    int A[10], i;
    int n;
    printf("How many numbers do you want to arrange��\n");
    scanf_s("%d", &n);
    printf("Please enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
        scanf_s("%d", &A[i]);
    Arrange(A, 5);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}