//PROPONOWANY SZABLON KLAS W NASZYM PROJEKCIE

#include <iostream>
#ifndef KAL_H
#define KAL_H

class Date
{
private:
	unsigned int unixTime;

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
// Interfejs???



};



#endif
