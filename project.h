//PROPONOWANY SZABLON KLAS W NASZYM PROJEKCIE

#include <iostream>
#ifndef KAL_H
#define KAL_H

class Date
{
private:
	unsigned int unixTime;
	DateFormatter:: DateFormatter *format;

public:
	Date(int year,int month,int day);
	Date( unsigned int time=0):unixTime(time){};
	Date(const Date & D );
	Date operator+(int n);
	Date & operator+=(int n);
	Date operator-(int n);
	Date & operator-=(int n);
	friend operator+(int n, const Date & D);
	Date operator+(const Date & D);
	bool operator==(const Date & D);
	bool operator!=(const Date & D);
	Date & operator=(const Date & D);
	friend std::ostream & operator<<(std:: ostream & os, const Date & D);
	void ZmianaFormatu(DateFormatter * format);
	ostream & Wypisz(DateFormatter & format) const ;
	{
        format->os(unixTime);
	}
// Interfejs???
// DateFormatter- Interfejs , tzn. klasa posiadaj¹ca tylko i wy³¹cznie metody wirtualne i żadnych pól
// ComputerDateFormatter i GermanDateFormatter-  klasy implementuj¹ce  interfejs tzn.  dziedzicz¹ce publicznie interfejs

};

class DateFormatter
{
public:
  std:: ostream & os( unsigned int ) const =0;
};

class ComputerDateFormatter : public(DateFormatter)
{
    public:
    std:: ostream & os(unsigned int) const;
};

class GermanDateFormatter : public(DateFormatter)
{
public:
    std::ostream & os (unsigned int) const;

};

#endif
