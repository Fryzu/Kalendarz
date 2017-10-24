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

//Metody MrauMrauChan

Date::Date(int year, int month, int day)
{
    int y;
    if(month==1)
        y=0;
    else
        y=month-2;
    unixDays=((year-1970)*365+day+monthDate[y]);
}

const Date operator-(const Date& D,int n)
{
    Date newDate;
    newDate.unixDays=D.unixDays-n;
    if (newDate.unixDays<0)
        newDate.unixDays=0;
    return newDate;

}

//Metody Pietra

ate& operator+=(const int days)
{
    unixTime=unixTime+86400*days;
    return *this;
}
Date& operator-=(const int days)
{
    unixTime=unixTime-86400*days;
    return *this;
}
 const Date operator+(const Date& prevDate, int days)
{
    Date newDate;
    newDate.unixTime=prevDate.unixTime+days;
    return newDate;
}
friend bool operator==(const Date& D1, const Date& D2);
{

    if ((D1.unixTime-D2.unixTime)>86400) return 0 //86400 to liczba sekund w ciagu dnia


    unsigned int days1=(D1.unixTime-(D1.unixTime%86400))/86400;
    unsigned int days2=(D2.unixTime-(D2.unixTime%86400))/86400;

    if (D1.unixTime>D2.unixTime) && (D1.unixTime-days*86400<D1.unixTime-D2.unixTime) return 0;
    if (D2.unixTime>D1.unixTime) && (D2.unixTime-days*86400>D2.unixTime-D1.unixTime) return 0;
    return 1;
}
friend bool operator!=(const Date&, const Date&)
{
    if ((D1.unixTime-D2.unixTime)>86400) return 1 //86400 to liczba sekund w ciagu dnia


    unsigned int days1=(D1.unixTime-(D1.unixTime%86400))/86400;
    unsigned int days2=(D2.unixTime-(D2.unixTime%86400))/86400;

    if (D1.unixTime>D2.unixTime) && (D1.unixTime-days*86400<D1.unixTime-D2.unixTime) return 1;
    if (D2.unixTime>D1.unixTime) && (D2.unixTime-days*86400>D2.unixTime-D1.unixTime) return 1;
    return 0;
}
class GermanDateFormatter : public DateFormatter
{
    public:

    virtual string format(Date& date)
    {
      string result;
      const int yearLength = 31536000;
      const int dayLength = 86400;

    unsigned int years = ((Date.unixTime-(Date.unixTime%yearLength))/yearLength);

    string  year= '.'+to_string(years);
    int months;
    string month;
    for(int i=1;i<13;i++)
    {
        if (date.unixTime<=monthDate[i]*dayLength)
        {
                        months=i;
                        break;

        }


    }
    if (months<10) month='.0'+to_string(months)
            else month='.'+to_string(months);

    unsigned int days=date.unixTime-(years*yearLength+monthDate[i-1]*dayLength);

    days=(days-days%dayLength)/dayLength+1;
    string day;
     if (days<10) day='0'+to_string(days)
            else day=to_string(months);
    result=day+month+year;
    return result;
    }


};
