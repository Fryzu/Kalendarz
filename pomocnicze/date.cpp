#include "date.h"
Date::Date(int year, int month, int day)
{
    int y;
    if(month==1)
        y=0;
    else
        y=month-2;
    unixTime=((year-1970)*365+day+monthDate[y])*24*60*60;
}

const Date operator-(const Date& D,int n)
{
    Date newDate;
    newDate.unixTime=D.unixTime-(n*24*60*60);
    if (newDate.unixTime<0)
        newDate.unixTime=0;
    return newDate;

}
