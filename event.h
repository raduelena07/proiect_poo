#include <iostream>
#include <string>
#include <ctime>
#include "location.h"
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

class Event
{
private:
	string name;
	Location location;
	int year;
	int month;
	int day;
	int hour;
public:
	Event();
	Event(string nume, Location locatie, int year, int month, int day, int hour);
	string getName();
	void setName(string name);
	Location getLocation();
	void setLocation(Location location);
	int getYear();
	void setYear(int year);
	int getMonth();
	void setMonth(int month);
	int getDay();
	void setDay(int day);
	int getHour();
	void setHour(int hour);
	bool checkDate(int year, int month, int day, int hour);
	/*Event(const Event& e);
	Event& operator=(Event& l);*/
	friend ostream& operator<<(ostream& out, Event e);
	friend istream& operator>>(istream& in, Event& e);
};
