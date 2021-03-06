//PROPONOWANY PRZEZE MNIE SZABLON KLAS - Bartek

#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date
{
  private:
    unsigned int unixDays;

  public:
    Date(int year, int month, int day); //MrauMrauChan
    Date(unsigned int time = 0) : unixDays(time - time % 86400){};

    Date &operator+=(const int);   //Pietro
    Date &operator-=(const int);   //Pietro
    Date &operator=(const Date &); //Fryzu

    unsigned int getUnixDays() {return unixDays;}; //for tests
    friend const Date operator+(int, const Date &);                //n+D Fryzu
    friend const Date operator+(const Date &, int);                //D+n Pietro
    friend const Date operator-(const Date &, int);                //D-n MrauMrauChan
    friend bool operator==(const Date &, const Date &);            //Pietro
    friend bool operator!=(const Date &, const Date &);            //Pietro
    friend std::ostream &operator<<(std::ostream &, const Date &); //Fryzu
};

class DateFormatter // nie wiem do końca po co - może nie o to chodziło
{
  public:
    virtual std::string format(Date &date) = 0;
};

class ComputerDateFormatter : public DateFormatter
{
  public:
    virtual std::string format(Date &date); //Fryzu
};

class GermanDateFormatter : public DateFormatter
{
  public:
    virtual std::string format(Date &date); //Pietro
};

//ComputerDateFormatter cdf;
//cout <<< cdf.format(d) << endl;

#endif
