//PROPONOWANY PRZEZE MNIE SZABLON KLAS - Bartek

#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
    private:
        unsigned int unixTime;
	static const int month[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    public:
        Date(int year,int month,int day);
        Date(unsigned int time = 0) : unixTime(time){};

        Date& operator+=(const int);
        Date& operator-=(const int);
        Date& operator=(const Date&);

        friend const Date operator+(int, const Date&); //n+D
        friend const Date operator+(const Date&, int); //D+n
        friend const Date operator-(const Date&, int); //D-n
        friend bool operator==(const Date&, const Date&);
        friend bool operator!=(const Date&, const Date&);
        friend std::ostream& operator<<(std::ostream&, const Date&);
};

class DateFormatter // nie wiem do końca po co - może nie o to chodziło
{
    public:
        virtual String format(Date& date) = 0;
};

class ComputerDateFormatter : public(DateFormatter)
{
    public:
        virtual String format(Date& date);
};

class GermanDateFormatter : public(DateFormatter)
{
    public:
        virtual String format(Date& date);
};

#endif
