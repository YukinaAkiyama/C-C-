//
//  time.cpp
//  208_2
//
//  Created by MacKenia on 2021/5/26.
//

#include "time.h"
using namespace std;

mlitime::mlitime(int a, int b) :time(a / 100, a % 100, b)
{
    //<<<<<< < Updated upstream
        if (a > 2359 || a < 0) throw overflowhour();
    if (b > 59 || b < 0) throw overflowsec();
    //====== =
        cout << "���������ʱ�䣺";
    cin >> milHours;
    cout << "�������룺";
    cin >> sec;
    //>>>>>> > Stashed changes
}

void time::con()
{
    hours = milHours / 100;
    min = milHours % 100;
}

void time::showAll()
{
    cout << "����ʱ��Ϊ��" << endl;
    cout << "" << milHours << endl;
    cout << "" << endl;
    cout << hours << "" << min << "" << sec << endl;
}