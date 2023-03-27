#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

struct jcb
{
    char name[10];//��ҵ��
    char status;


    int arrtime;//����ʱ��
    int reqtime;//Ҫ�����ʱ��
    int startime;//����ʱ��
    int finitime;//���ʱ��
    float waittime;//�ȴ�ʱ��
    float TAtime, TAWtime;//��תʱ�� ��Ȩ��תʱ��
    float rp;
}jobarr[24], jobfin[24], job[24];

int ReadFile()
{
    int m = 0;
    int i = 0;
    FILE* fp;     //�����ļ�ָ��
    fp = fopen_s("Ifile.txt","w+");  //���ļ�
    if (fp == NULL)
    {
        printf("File open error !\n");
        //        exit(0);
    }
    printf("\n id    ��ҵ����ʱ��     ��ҵ��������Ҫʱ��\n");
    while (!feof(fp))
    {
        fscanf_s(fp, "%s%d%d", job[i].name, &job[i].arrtime, &job[i].reqtime);  //fscanf_s()���������ݶ���
        printf("\n%3s%12d%15d\n", job[i].name, job[i].arrtime, job[i].reqtime);  //�������Ļ
        i++;
    };
    if (fclose(fp))     //�ر��ļ�
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
    srand((unsigned)time(0));  //����seed��rand()�����ӣ�������ʼ��rand()����ʼֵ��
    //������ҵ��
    n = rand() % 23 + 5;
    for (i = 0; i <= n; i++)
    {
        // job[i].name=i;
        sprintf_s(job[i].name, "%d", i);
        //��ҵ����ʱ��
        job[i].arrtime = rand() % 29 + 1;
        //��ҵ����ʱ��
        job[i].reqtime = rand() % 7 + 1;
    }
    printf("\n ��ҵ��     ��ҵ����ʱ��     ��ҵ��������Ҫʱ��");  // id
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
    printf("��������ҵ������");
    scanf_s("%d", &count);
    for (i = 0; i < count; i++)
    {
        printf("��%d����ҵ��\n", i + 1);
        printf("������ҵ����");
        scanf_s("%s", job[i].name);
        printf("����ʱ�䣺");
        scanf_s("%d", &job[i].arrtime);
        printf("Ҫ�����ʱ�䣺");
        scanf_s("%d", &job[i].reqtime);
        printf("\n");
    }
    return count;
}
void sort(struct jcb temp[24], int count)
{
    int i, j;
    struct jcb t;
    for (i = 0; i < count - 1; i++) //�����̵���ʱ����Ⱥ�����
    {                               //�����������ͬʱ���������Ļ�������������
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
void FCFS(struct jcb temp[24], int count)//�ȵ��ȷ����㷨
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
    printf("��ҵ�� ����ʱ�� ��ʼʱ�� Ҫ�����ʱ�� ����ʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��\n");
    for (i = 0; i < count; i++)
    {
        printf("N%d\t%s\t%d\t\t%d\t%d\t%d\t%0.2f\t%0.2f\n", i + 1, job[i].name, job[i].arrtime, job[i].reqtime, job[i].startime, job[i].finitime, job[i].TAtime, job[i].TAWtime);
    }
    printf("ƽ����תʱ���ǣ�%0.2f\n", averageruntime / count);
    printf("ƽ����תʱ���ǣ�%0.2f\n", averageruntimerun / count);
}

void SJF(struct jcb temp[24], int count)//����ҵ�����㷨
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
    printf("��ҵ�� ����ʱ�� ��ʼʱ�� Ҫ�����ʱ�� ����ʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��\n");
    for (i = 0; i < count; i++)
    {
        printf("N%d\t%s\t%d\t\t%d\t%d\t%d\t%0.2f\t%0.2f\n", i + 1, job[i].name, job[i].arrtime, job[i].reqtime, job[i].startime, job[i].finitime, job[i].TAtime, job[i].TAWtime);
    }
    printf("ƽ����תʱ���ǣ�%0.2f\n", averageruntime / count);
    printf("ƽ����תʱ���ǣ�%0.2f\n", averageruntimerun / count);
}

void HRRN(struct jcb temp[24], int count)//��Ӧ�ȸ��������㷨
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
    printf("��ҵ�� ����ʱ�� ��ʼʱ�� Ҫ�����ʱ�� ����ʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��\n");
    for (i = 0; i < count; i++)
    {
        printf("N%d\t%s\t%d\t\t%d\t%d\t%d\t%0.2f\t%0.2f\n", i + 1, job[i].name, job[i].arrtime, job[i].reqtime, job[i].startime, job[i].finitime, job[i].TAtime, job[i].TAWtime);
    }
    printf("ƽ����תʱ���ǣ�%0.2f\n", averageruntime / count);
    printf("ƽ����תʱ���ǣ�%0.2f\n", averageruntimerun / count);
}

int main()
{
    int i, count, select, s, sel;
    printf("************************************\n");
    printf("   1.�����ı�д������\n");
    printf("   2.����α������Ĳ�������\n");
    printf("   3.�����Լ�����ģ������\n");
    printf("************************************\n\n");
    printf("��ѡ��˵��\n");
    scanf_s("%d", &s);
    if (s == 1)
        ReadFile();
    else if (s == 2)
        Pseudo_random_number();
    else if (s == 3)
        own_input();
    printf("��ҵ����Ŀ��");
    scanf_s("%d", &count);
    do {
        printf("-----------------��ѡ����ҵ�����㷨------------------\n");
        printf("1:���������ȷ��� (FCFS) �����㷨\n2:���ö���ҵ���� (SJF) �����㷨\n3:������Ӧ�ȸ������� (HRRN) �����㷨\n");
        printf("��ѡ��");
        scanf_s("%d", &select);

        while (select < 1 || select>3)
        {
            printf("������������������:");
            scanf_s("%d", &select);

        }
        printf("\n��������ʱ�������δ�ﵽ������\n");
        printf("\t��ҵ��\t����ʱ��\tҪ�����ʱ��\n");
        for (i = 0; i < count; i++)
        {
            printf("N%d\t%s\t%d\t\t%d\n", i + 1, job[i].name, job[i].arrtime, job[i].reqtime);
        }


        if (select == 1)
        {
            printf("------�����ȷ��� (FCFS) �����㷨------\n");
            FCFS(job, count);

        }
        else if (select == 2)
        {
            printf("------����ҵ���� (SJF)�����㷨------\n");
            SJF(job, count);

        }
        else if (select == 3)
        {
            printf("------��Ӧ�ȸ������� (HRRN)�����㷨------\n");
            HRRN(job, count);

        }
        printf("1.������ҵ�����㷨  0.����\n");
        printf("��ѡ��1��0��");
        scanf_s("%d", &sel);
    } while (sel == 1);

    return 0;
}