#include <iostream>
#include "data_h.h"
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

bool year1(int year)
{
    if((year%400==0)||(year%4==0&&year%100!=0))
        return true;
    else
        return false;
}
Data::Data()
{
    year = 0;
    month = 0;
    day = 0;
    hour = 0;
    minute = 0;
    second = 0;
}
Data::Data(int pass)
{
    pass += 8*3600;
    second = pass%60;
    int passminute = pass/60;
    minute = passminute%60;
    int passhour = passminute/60;
    hour = passhour%24;
    day = passhour/24;
    year = 1970;
    month = 1;
    while(day-366>=0||day-365>=0)
    {
        year++;
        if(year1(year))
            day-=366;
        else
            day-=365;
    }

    while(day-31>=0||day-30>=0||day-29>=0||day-28>=0)
    {

        switch(month)
        {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                day-=31;break;
            case 2:
                year1(year)?day-=29:day-=28;break;
            case 4:case 6:case 9:case 11:
                day-=30;break;
        }
        month++;
    }
    day++;
}
Data::Data(int y,int mon,int d,int h,int m,int s)
{
    year = y;
    month = mon;
    day = d;
    hour = h;
    minute = m;
    second = s;
}
int Data::getyear()
{
    return year;
}
int Data::getmonth()
{
    return month;
}
int Data::getday()
{
    return day;
}
int Data::gethour()
{
    return hour;
}
int Data::getminute()
{
    return minute;
}
int Data::getsecond()
{
    return second;
}
void Data::setData(int pass)
{
    pass += 8*3600;
    second = pass%60;
    int passminute = pass/60;
    minute = passminute%60;
    int passhour = passminute/60;
    hour = passhour%24;
    day = passhour/24;
    year = 1970;
    month = 1;
    while(day-366>=0||day-365>=0)
    {
        year++;
        if(year1(year))
            day-=366;
        else
            day-=365;
    }

    while(day-31>=0||day-30>=0||day-29>=0||day-28>=0)
    {

        switch(month)
        {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                day-=31;break;
            case 2:
                year1(year)?day-=29:day-=28;break;
            case 4:case 6:case 9:case 11:
                day-=30;break;
        }
        month++;
    }
    day++;
    return;
}
string Data::show()
{
        stringstream s,ss,sss;
        string s1,s2,s3;
        s<<year;
        s>>s1;
        ss<<month;
        ss>>s2;
        sss<<day;
        sss>>s3;
        return s1+"/"+s2+"/"+s3;
}
