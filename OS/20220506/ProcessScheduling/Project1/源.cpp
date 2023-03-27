#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

struct jcb
{
    char name[10];//作业名
    char status;


    int arrtime;//到达时间
    int reqtime;//要求服务时间
    int startime;//调度时间
    int finitime;//完成时间
    float waittime;//等待时间
    float TAtime, TAWtime;//周转时间 带权周转时间
    float rp;
}jobarr[24], jobfin[24], job[24];

int ReadFile()
{
    int m = 0;
    int i = 0;
    FILE* fp;     //定义文件指针
    fp = fopen_s("Ifile.txt","w+");  //打开文件
    if (fp == NULL)
    {
        printf("File open error !\n");
        //        exit(0);
    }
    printf("\n id    作业到达时间     作业运行所需要时间\n");
    while (!feof(fp))
    {
        fscanf_s(fp, "%s%d%d", job[i].name, &job[i].arrtime, &job[i].reqtime);  //fscanf_s()函数将数据读入
        printf("\n%3s%12d%15d\n", job[i].name, job[i].arrtime, job[i].reqtime);  //输出到屏幕
        i++;
    };
    if (fclose(fp))     //关闭文件
    {
        printf("Can not close the file !\n");
        //        exit(0);
    }
    m = i - 1;
    return m;

}
int Pseudo_random_number()
{
    int i, n;
    srand((unsigned)time(0));  //参数seed是rand()的种子，用来初始化rand()的起始值。
    //输入作业数
    n = rand() % 23 + 5;
    for (i = 0; i <= n; i++)
    {
        // job[i].name=i;
        sprintf_s(job[i].name, "%d", i);
        //作业到达时间
        job[i].arrtime = rand() % 29 + 1;
        //作业运行时间
        job[i].reqtime = rand() % 7 + 1;
    }
    printf("\n 作业名     作业到达时间     作业运行所需要时间");  // id
    for (i = 0; i <= n; i++)
    {
        printf("\n  %-d%12d%15d", i + 1, job[i].arrtime, job[i].reqtime);    //%3d\t        ,job[i].name
    }
    printf("\n");
    return n;
}
int own_input()
{
    int count, i;
    printf("请输入作业个数：");
    scanf_s("%d", &count);
    for (i = 0; i < count; i++)
    {
        printf("第%d个作业：\n", i + 1);
        printf("输入作业名：");
        scanf_s("%s", job[i].name);
        printf("到达时间：");
        scanf_s("%d", &job[i].arrtime);
        printf("要求服务时间：");
        scanf_s("%d", &job[i].reqtime);
        printf("\n");
    }
    return count;
}
void sort(struct jcb temp[24], int count)
{
    int i, j;
    struct jcb t;
    for (i = 0; i < count - 1; i++) //按进程到达时间的先后排序
    {                               //如果两个进程同时到达，按在屏幕先输入的先运行
        for (j = i + 1; j < count; j++)
        {
            if (temp[j].arrtime < temp[i].arrtime)
            {
                t = temp[j];
                temp[j] = temp[i];
                temp[i] = t;
            }

        }
    }

}
void FCFS(struct jcb temp[24], int count)//先到先服务算法
{
    int i = 0;
    float averageruntime = 0;
    float averageruntimerun = 0;
    sort(temp, count);
    temp[i].startime = temp[i].arrtime;
    temp[i].finitime = temp[i].reqtime + temp[i].startime;
    temp[i].TAtime = temp[i].finitime - temp[i].arrtime;
    temp[i].TAWtime = temp[i].TAtime / temp[i].reqtime;
    averageruntime = temp[i].TAtime;
    averageruntimerun = temp[i].TAWtime;
    for (i = 1; i < count; i++)
    {
        temp[i].startime = temp[i - 1].finitime;
        temp[i].finitime = temp[i].reqtime + temp[i].startime;
        temp[i].TAtime = temp[i].finitime - temp[i].arrtime;
        temp[i].TAWtime = temp[i].TAtime / temp[i].reqtime;
        averageruntime += temp[i].TAtime;
        averageruntimerun += temp[i].TAWtime;
    }
    printf("作业名 到达时间 开始时间 要求服务时间 调度时间 完成时间 周转时间 带权周转时间\n");
    for (i = 0; i < count; i++)
    {
        printf("N%d\t%s\t%d\t\t%d\t%d\t%d\t%0.2f\t%0.2f\n", i + 1, job[i].name, job[i].arrtime, job[i].reqtime, job[i].startime, job[i].finitime, job[i].TAtime, job[i].TAWtime);
    }
    printf("平均周转时间是：%0.2f\n", averageruntime / count);
    printf("平均周转时间是：%0.2f\n", averageruntimerun / count);
}

void SJF(struct jcb temp[24], int count)//短作业优先算法
{

    int i = 0, j;
    struct jcb t;
    float averageruntime = 0;
    float averageruntimerun = 0;
    sort(temp, count);
    temp[i].startime = temp[i].arrtime;
    temp[i].finitime = temp[i].reqtime + temp[i].startime;
    temp[i].TAtime = temp[i].finitime - temp[i].arrtime;
    temp[i].TAWtime = temp[i].TAtime / temp[i].reqtime;
    averageruntime = temp[i].TAtime;
    averageruntimerun = temp[i].TAWtime;
    for (i = 1; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (temp[j].reqtime < temp[i].reqtime)
            {
                t = temp[j];
                temp[j] = temp[i];
                temp[i] = t;
            }
        }
    }
    for (i = 1; i < count; i++)
    {
        temp[i].startime = temp[i - 1].finitime;
        temp[i].finitime = temp[i].reqtime + temp[i].startime;
        temp[i].TAtime = temp[i].finitime - temp[i].arrtime;
        temp[i].TAWtime = temp[i].TAtime / temp[i].reqtime;
        averageruntime += temp[i].TAtime;
        averageruntimerun += temp[i].TAWtime;
    }
    printf("作业名 到达时间 开始时间 要求服务时间 调度时间 完成时间 周转时间 带权周转时间\n");
    for (i = 0; i < count; i++)
    {
        printf("N%d\t%s\t%d\t\t%d\t%d\t%d\t%0.2f\t%0.2f\n", i + 1, job[i].name, job[i].arrtime, job[i].reqtime, job[i].startime, job[i].finitime, job[i].TAtime, job[i].TAWtime);
    }
    printf("平均周转时间是：%0.2f\n", averageruntime / count);
    printf("平均周转时间是：%0.2f\n", averageruntimerun / count);
}

void HRRN(struct jcb temp[24], int count)//响应比高者优先算法
{
    int i = 0, j;
    struct jcb t;
    float averageruntime = 0;
    float averageruntimerun = 0;
    sort(temp, count);
    temp[i].startime = temp[i].arrtime;
    temp[i].finitime = temp[i].reqtime + temp[i].startime;
    temp[i].TAtime = temp[i].finitime - temp[i].arrtime;
    temp[i].TAWtime = temp[i].TAtime / temp[i].reqtime;
    temp[i].waittime = temp[i].startime - temp[i].arrtime;
    temp[i].rp = temp[i].TAtime / temp[i].reqtime;
    averageruntime = temp[i].TAtime;
    averageruntimerun = temp[i].TAWtime;
    for (i = 1; i < count; i++)
    {
        temp[i].startime = temp[i - 1].finitime;
        temp[i].finitime = temp[i].reqtime + temp[i].startime;
        temp[i].waittime = temp[i].startime - temp[i].arrtime;
        temp[i].TAtime = temp[i].finitime - temp[i].arrtime;
        temp[i].TAWtime = temp[i].TAtime / temp[i].reqtime;
        temp[i].rp = temp[i].TAtime / temp[i].reqtime;
    }
    for (i = 1; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (temp[j].rp < temp[i].rp)
            {
                t = temp[j];
                temp[j] = temp[i];
                temp[i] = t;
            }

        }
    }
    for (i = 1; i < count; i++)
    {
        temp[i].startime = temp[i - 1].finitime;
        temp[i].finitime = temp[i].reqtime + temp[i].startime;
        temp[i].TAtime = temp[i].finitime - temp[i].arrtime;
        temp[i].TAWtime = temp[i].TAtime / temp[i].reqtime;
        averageruntime += temp[i].TAtime;
        averageruntimerun += temp[i].TAWtime;
    }
    printf("作业名 到达时间 开始时间 要求服务时间 调度时间 完成时间 周转时间 带权周转时间\n");
    for (i = 0; i < count; i++)
    {
        printf("N%d\t%s\t%d\t\t%d\t%d\t%d\t%0.2f\t%0.2f\n", i + 1, job[i].name, job[i].arrtime, job[i].reqtime, job[i].startime, job[i].finitime, job[i].TAtime, job[i].TAWtime);
    }
    printf("平均周转时间是：%0.2f\n", averageruntime / count);
    printf("平均周转时间是：%0.2f\n", averageruntimerun / count);
}

int main()
{
    int i, count, select, s, sel;
    printf("************************************\n");
    printf("   1.调用文本写入数据\n");
    printf("   2.调用伪随机数的产生数据\n");
    printf("   3.调用自己输入模拟数据\n");
    printf("************************************\n\n");
    printf("请选择菜单项：\n");
    scanf_s("%d", &s);
    if (s == 1)
        ReadFile();
    else if (s == 2)
        Pseudo_random_number();
    else if (s == 3)
        own_input();
    printf("作业的数目：");
    scanf_s("%d", &count);
    do {
        printf("-----------------请选择作业调度算法------------------\n");
        printf("1:采用先来先服务 (FCFS) 调度算法\n2:采用短作业优先 (SJF) 调度算法\n3:采用响应比高者优先 (HRRN) 调度算法\n");
        printf("请选择：");
        scanf_s("%d", &select);

        while (select < 1 || select>3)
        {
            printf("输入有误，请重新输入:");
            scanf_s("%d", &select);

        }
        printf("\n经按到达时间排序后，未达到队列是\n");
        printf("\t作业名\t到达时间\t要求服务时间\n");
        for (i = 0; i < count; i++)
        {
            printf("N%d\t%s\t%d\t\t%d\n", i + 1, job[i].name, job[i].arrtime, job[i].reqtime);
        }


        if (select == 1)
        {
            printf("------先来先服务 (FCFS) 调度算法------\n");
            FCFS(job, count);

        }
        else if (select == 2)
        {
            printf("------短作业优先 (SJF)调度算法------\n");
            SJF(job, count);

        }
        else if (select == 3)
        {
            printf("------响应比高者优先 (HRRN)调度算法------\n");
            HRRN(job, count);

        }
        printf("1.继续作业调度算法  0.结束\n");
        printf("请选择1或0：");
        scanf_s("%d", &sel);
    } while (sel == 1);

    return 0;
}