#include<stdio.h>
int main()
{
    //n阶矩阵相乘
    int a[2][2] = { 1,2,3,4 };    //矩阵一
    int b[2][2] = { 5,6,7,8 };    //矩阵二
    int c[2][2] = { 0 };        //矩阵乘积保存
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
