#include "date.h"
#include <iostream>

//Metody Bartka

static const int monthDate[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

Date &Date::operator=(const Date &toCopy)
{
    this->unixDays = toCopy.unixDays;

    return *this;
}

const Date operator+(int dateInteger, const Date &dateObject)
{
    Date result;
    result.unixDays = dateObject.unixDays + dateInteger;

    return result;
}

std::ostream &operator<<(std::ostream &os, const Date &dateObject)
{
    os << dateObject.unixDays << std::endl;

    return os;
}

std::string ComputerDateFormatter::format(Date &date)
{
    std::string result;
    result = date.getUnixDays() / 365;
    result += "-";

    int dateDays = date.getUnixDays() % 365;
    for (int i = 0; i < 12; i++)
    {
        if (dateDays < monthDate[i])
        {
            result += i + 1;
            result += "-";
            if (i == 1)
                result += dateDays;
            else
                result += dateDays - monthDate[i - 1];
        }
    }

    return result;
}

//Metody MrauMrauChan

Date::Date(int year, int month, int day)
{
    int y;
    if (month == 1)
        y = 0;
    else
        y = month - 2;
    unixDays = ((year - 1970) * 365 + day + monthDate[y]);
}

const Date operator-(const Date &D, int n)
{
    Date newDate;
    newDate.unixDays = D.unixDays - n;
    if (newDate.unixDays < 0)
        newDate.unixDays = 0;
    return newDate;
}

//Metody Pietra

Date &Date::operator+=(const int days)
{
    unixDays = unixDays + days;
    return *this;
}
Date &Date::operator-=(const int days)
{
    unixDays = unixDays - days;
    return *this;
}
const Date operator+(const Date &prevDate, int days)
{
    Date newDate;
    newDate.unixDays = prevDate.unixDays + days;
    return newDate;
}
bool operator==(const Date &D1, const Date &D2)
{
    if (D1.unixDays != D2.unixDays)
        return 0; else return 1;
}
bool operator!=(const Date &D1, const Date &D2)
{
    if (D1.unixDays != D2.unixDays)
        return 1; else return 0;
}

/* coś nie smiga i nie chce sie kompilowac
string GermanDateFormatter::format(Date &date)
{
    string result;
    const int yearLength = 365;

    unsigned int years = 1970 + ((unixDays - unixDays % yearLength) / yearLength)
                                    string year = '.' + to_string(years);

    int months;

    std::string month;

    for (int i = 1; i < 13; i++)
    {
        if (date.unixDays - yearLength * years)<=monthDate[i])
            {
                months = i;
                break;
            }
    }
    if (months < 10)
        month = '.0' + to_string(months); 
    else 
        month = '.' + to_string(months);

    unsigned int days = date.unixDays - ((years - 1970) * yearLength + monthDate[i - 1]);

    string day;
    if (days < 10)
        day = '0' + to_string(days) else day = to_string(days);
    result = day + month + year;
    return result;
}
*/