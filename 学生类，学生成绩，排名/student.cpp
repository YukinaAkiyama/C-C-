#include <iostream>
#include "student.h"
using namespace std;

float student::avg1 = 0, student::avg2 = 0, student::avg3 = 0;
int student::total = 0;
int student::rank[2][4] = { 0 };


student::student()
{
    cout << "ѧ��" << total + 1 << ":" << endl;
    cout << "���������۳ɼ���";
    cin >> theory;
    while (theory < 0 || theory>100)
    {
        cout << "�����������������۳ɼ���";
        cin >> theory;
    }
    cout << "����������ɼ���";
    cin >> operate;
    while (operate < 0 || operate>100)
    {
        cout << "������������������ɼ���";
        cin >> operate;
    }
    cout << "�������ʴ�ɼ���";
    cin >> qa;
    while (qa < 0 || qa>100)
    {
        cout << "���������������ʴ�ɼ���";
        cin >> qa;
    }
    cin.ignore();
    total++;
    avg1 += theory;
    avg2 += operate;
    avg3 += qa;
    for (int i = 0; i < total; i++)
    {
        if (!(total - 1))
        {
            rank[0][0] = theory + operate + qa;
            rank[1][0] = total;
        }
        else if (rank[0][i] <= (theory + operate + qa))
        {
            for (int j = 3; j > i; j--)
            {
                rank[1][j] = rank[1][j - 1];
                rank[0][j] = rank[0][j - 1];
            }
            rank[0][i] = theory + operate + qa;
            rank[1][i] = total;
            break;
        }
        else if (rank[0][i] >= (theory + operate + qa))
        {
            for (int j = 3; j > i + 1; j--)
            {
                rank[1][j] = rank[1][j - 1];
                rank[0][j] = rank[0][j - 1];
            }
            rank[0][i + 1] = theory + operate + qa;
            rank[1][i + 1] = total;
            break;
        }
    }
}

void printrank()
{
    for (int i = 1; i < 5; i++)
    {
        cout << "��" << i << "����ѧ��" << student::rank[1][i - 1] << endl;
    }
    return;
}

void printavg()
{
    cout << "����һ��ƽ����Ϊ��" << student::avg1 / student::total << endl;
    cout << "���ڶ���ƽ����Ϊ��" << student::avg2 / student::total << endl;
    cout << "��������ƽ����Ϊ��" << student::avg3 / student::total << endl;
    return;
}
