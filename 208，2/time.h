//
//  time.h
//  208_2
//
//  Created by MacKenia on 2021/5/26.
//

#include <iostream>

#ifndef time_h
#define time_h

class  time
{
private:
    int hour;
    int min;
    int sec;
public:
    //<<<<<< < Updated upstream
        time(int h, int m, int s) { hour = h; min = m; sec = s; }
    int gethour() { return hour; };
    int getmin() { return min; };
    int getsec() { return sec; };
    //====== =
        time();
    void con();
    void showAll();
    //>>>>>> > Stashed changes
};

class mlitime :public time
{
private:
    int mlihours;
    int milseconds;
public:
    mlitime(int, int);
    class overflowhour {};
    class overflowsec {};
};
#endif /* time_h */