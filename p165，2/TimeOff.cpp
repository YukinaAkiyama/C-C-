#include "TimeOff.h"
#include <iostream>
using namespace std;

// numdays 成员

void numdays::converse(const bool& f)
{
    if (f) day = hour / 8;
    else hour = day * 8;
}

numdays::numdays(float a)
{
    day = a;
    hour = 0;
    converse(false);
}

numdays::numdays()
{
    day = 0;
    hour = 0;
    cin >> day;
    converse(false);
}

float numdays::da()
{
    return day;
}

int numdays::hou()
{
    return hour;
}

numdays& numdays::operator+(numdays& a)
{
    day += a.day;
    hour += a.hour;
    return *this;
}

numdays& numdays::operator-(numdays& a)
{
    day -= a.day;
    hour -= a.hour;
    return *this;
}

bool numdays::operator==(const float a)
{
    return day == a;
}

numdays& numdays::operator+(int a)
{
    hour += a;
    converse(true);
    return *this;
}

numdays& numdays::operator-(int a)
{
    hour -= a;
    converse(true);
    return *this;
}

float numdays::operator++()
{
    hour += 1;
    converse(true);
    return hour;
}

float numdays::operator--()
{
    hour -= 1;
    converse(true);
    return hour;
}

float numdays::operator--(int)
{
    float t = hour;
    hour -= 1;
    converse(true);
    return t;
}

float numdays::operator++(int)
{
    float t = hour;
    hour += 1;
    converse(true);
    return t;
}

ostream& operator<<(ostream& strm, numdays& a)
{
    cout << a.day << "天" << endl;
    return strm;
}

istream& operator>>(istream& strm, numdays& a)
{
    cout << "目前工作小时数为：" << a.hour << "，输入工作小时数：";
    cin >> a.hour;
    a.converse(true);
    return strm;
}



// timeoff 成员

timeoff::timeoff(float a, float b, float c, float d, float e, float f)
{
    cout << "请输入名称：";
    cin >> name;
    cout << "请输入编号：";
    cin >> number;
    maxSickDays = new numdays(a);
    sickTaken = new numdays(b);
    maxVacation = new numdays(c);
    while (maxVacation->hou() > 24)
    {
        cout << "休假时间超过24H,重新输入：" << endl;
        cin >> *maxVacation;
    }
    vacTaken = new numdays(d);
    maxUnpaid = new numdays(e);
    unpaidTaken = new numdays(f);
}

timeoff::~timeoff()
{
    delete unpaidTaken;
    delete maxUnpaid;
    delete vacTaken;
    delete maxVacation;
    delete sickTaken;
    delete maxSickDays;
}

int timeoff::maxSick()
{
    return maxSickDays->hou();
}

void timeoff::showAll()
{
    cout << "因生病可以不工作的最多天数：" << *maxSickDays;
    cout << "已因生病不工作的天数：" << *sickTaken;
    cout << "可带薪休假的最大天数：" << *maxVacation;
    cout << "已休假的天数：" << *vacTaken;
    cout << "不支付薪水的情况下的最大休假天数：" << *maxUnpaid;
    cout << "不支付薪水的情况下已休假的天数：" << *unpaidTaken;
}

bool timeoff::operator==(const char* a)
{
    for (int i = 0, j = 0; name[i] != '\0' || a[j] != '\0'; i++, j++)
    {
        if (name[i] != a[j]) return false;
    }
    return true;
}

bool timeoff::operator==(const int a)
{
    return number == a;
}

float timeoff::check(int a)
{
    switch (a) {
    case 1:
        return maxSickDays->da();
        break;
    case 2:
        return sickTaken->da();
        break;
    case 3:
        return maxVacation->da();
        break;
    case 4:
        return vacTaken->da();
        break;
    case 5:
        return maxUnpaid->da();
        break;
    case 6:
        return unpaidTaken->da();
        break;
    default:
        break;
    }
    return -1;
}