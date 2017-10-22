#include "date.h"
#include <iostream>

Date::Date(int year, int month, int day)
{
    int y;
    if(month==1)
        y=0;
    else
        y=month-2;
    unixTime=((year-1970)*365+day+monthDate[y])*24*60*60;
}

Date& Date::operator=(const Date& toCopy)
{
    this->unixTime = toCopy.unixTime;

    return *this;
}

const Date operator+(int dateInteger, const Date& dateObject)
{
    Date result;
    result.unixTime = dateObject.unixTime + (dateInteger*86400);

    return result;
}

const Date operator-(const Date& D,int n)
{
    Date newDate;
    newDate.unixTime=D.unixTime-(n*24*60*60);
    return newDate;
}

std::ostream& operator<<(std::ostream& os, const Date& dateObject)
{
    os << dateObject.unixTime << std::endl;

    return os;
}

  string ComputerDateFormatter::format(Date& date)
  {
      //NIE SKOŃCZONE
      string result;
      const int yearLength = 31536000; 
      const int dayLength = 86400; 

      //year
      result << static_cast<int>(date.unixTime/yearLength);

      //month
      int x = date.unixTime % yearLength;

      //day
  }