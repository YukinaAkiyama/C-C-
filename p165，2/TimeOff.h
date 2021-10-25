//
//  numday.h
//  165_2
//
//  Created by MacKenia on 2021/5/14.
//
#include <iostream>
#ifndef numday_h
#define numday_h

class numdays
{
private:
    float hour;
    float day;
public:
    numdays();
    numdays(float);
    void converse(const bool&);
    numdays& operator+(numdays&);
    numdays& operator-(numdays&);
    numdays& operator+(int);
    numdays& operator-(int);
    bool operator==(const float);
    float operator++(int);
    float operator--(int);
    float operator++();
    float operator--();
    float da();
    int hou();
    friend std::ostream& operator<<(std::ostream&, numdays&);
    friend std::istream& operator>>(std::istream&, numdays&);
};

class timeoff
{
private:
    char name[10];
    int number;
    numdays* maxSickDays;
    numdays* sickTaken;
    numdays* maxVacation;
    numdays* vacTaken;
    numdays* maxUnpaid;
    numdays* unpaidTaken;
public:
    timeoff(float, float, float, float, float, float);
    ~timeoff();
    int maxSick();
    void showAll();
    bool operator==(const char*);
    bool operator==(const int);
    float check(int);
};

#endif /* numday_h */
