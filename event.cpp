#include <iostream>
#include <string>
#include <ctime>
#include "event.h"
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

Event::Event()
{
	this->name = "";
	Location l;
	this->location = l;
	this->year = 0;
	this->month = 0;
	this->day = 0;
	this->hour = 0;
}

Event::Event(string name, Location location, int year, int month, int day, int hour)
{
	bool dateValid = this->checkDate(year, month, day, hour);
	if (!dateValid) {
		cout << "Invalid date";
	}
	else {
		this->name = name;
		this->location = location;
		this->year = year;
		this->month = month;
		this->day = day;
		this->hour = hour;
	}
}

string Event::getName()
{
	return this->name;
}

void Event::setName(string name)
{
	if (isupper(name[0])) {
		this->name = name;
	}
	else cout << "The event name should start with an upper character";
}

Location Event::getLocation()
{
	return this->location;
}

void Event::setLocation(Location location)
{
	this->location = location;
}
int Event::getYear()
{
	return this->year;
}

void Event::setYear(int year)
{
	this->year = year;
}

int Event::getMonth()
{
	return this->month;
}

void Event::setMonth(int month)
{
	this->month = month;
}

int Event::getDay()
{
	return this->day;
}

void Event::setDay(int day)
{
	this->day = day;
}

int Event::getHour()
{
	return this->hour;
}

void Event::setHour(int hour)
{
	this->hour = hour;
}


bool Event::checkDate(int year, int month, int day, int hour)
{

		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day <= 0 || day > 31)) {
			return false;
		}
		else
			if (month == 4 || month == 6 || month == 9 || month == 11 && (day <= 0 || day > 30)) {
				return false;
			}
			else
				if (month == 2)
				{
					if (year % 4 == 0) {
						if (day <= 0 || day > 29) {
							return false;
						}
					}
					else if (day <= 0 || day > 28) {
						return false;
					}
				}

	if (hour < 0 || hour > 24) {
		return false;
	}

	return true;
}
//Event::Event(const Event& e)
//{
//	this->name = e.name;
//	this->location = e.location;
//	this->year = e.year;
//	this->month = e.month;
//	this->day = e.day;
//	this->hour = e.hour;
//}

ostream& operator<<(ostream& out, Event e)
{
	cout << endl;
	out << "Name: " << e.name << endl;
	out << "Location: " << e.location << endl;
	out << "Year:" << e.year << endl;
	out << "Month: " << e.month << endl;
	out << "Day: " << e.day << endl;
	out << "Hour: " << e.hour << endl;
	return out;
}
istream& operator>>(istream& in, Event& e)
{
	cout << endl;
	cout << "Enter name: ";
	cin >> e.name;
	cout << "Enter location: ";
	cin >> e.location;
	cout << "Enter year: ";
	cin >> e.year;
	cout << "Enter month: ";
	cin >> e.month;
	cout << "Enter day: ";
	cin >> e.day;
	cout << "Enter hour: ";
	cin >> e.hour;
	return in;
}