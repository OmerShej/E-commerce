#include "Date.h"


Date::Date() 
{
	year = month = day = 0;
}

Date::Date(int day, int month, int year)
	:day(day) , month(month), year(year) { }

void Date::showDate()const
{
	cout << "the date is: " << endl;
	cout << day << '/' << month << '/' << year << endl;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << "Date: " << date.day << "." << date.month << "." << date.year << endl;
	return os;
}