#ifndef DATA_H_H_INCLUDED
#define DATA_H_H_INCLUDED
#include <string>
using namespace std;
class Data
{
private:
    int year ,month,day,hour,minute,second;
public:
    Data();
    Data(int pass);
    Data(int y,int mon,int d,int h,int m,int s);
    int getyear();
    int getmonth();
    int getday();
    int gethour();
    int getminute();
    int getsecond();
    void setData(int pass);
    string show();
};


#endif // DATA_H_H_INCLUDED
