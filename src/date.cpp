#include "date.h"
#include <iostream>

//Metody Bartka

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

Date& Date::operator+=(const int days)
{
    unixDays=unixDays+days;
    return *this;
}
Date& Date::operator-=(const int days)
{
	unixDays=unixDays-days;
    return *this;
}
 const Date operator+(const Date& prevDate, int days)
{
    Date newDate;
    newDate.unixDays=prevDate.unixDays+days;
    return newDate;
}
bool operator==(const Date& D1, const Date& D2);
{

    if (D1.unixDays!=D2.unixDays) return 0
    else return 1
}
 bool operator!=(const Date&, const Date&)
{
	    if (D1.unixDays!=D2.unixDays) return 1
	    else return 0
}



string GermanDateFormatter::format(Date& date)
    {
      string result;
      const int yearLength = 365;

    unsigned int years = 1970+((unixDays-unixDays%yearLength)/yearLength)
    string  year= '.'+to_string(years);

    int months;

    string month;

    for(int i=1;i<13;i++)
    {
        if (date.unixDays-yearLength*years)<=monthDate[i])
        {
                        months=i;
                        break;

        }


    }
    if (months<10) month='.0'+to_string(months)
            else month='.'+to_string(months);

    unsigned int days=date.unixDays-((years-1970)*yearLength+monthDate[i-1]);

    string day;
     if (days<10) day='0'+to_string(days)
            else day=to_string(days);
    result=day+month+year;
    return result;
    }


};
