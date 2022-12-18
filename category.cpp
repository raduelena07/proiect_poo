 #include <iostream>
#include <string>
#include <ctime>
#include "category.h"
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

Category::Category()
{
	this->name = "";
	this->noSeats = 0;
	this->seats = nullptr;

}

Category::Category(string name, int noSeats)
{
	this->name = name;
	this->noSeats = noSeats;
	this->seats = new unsigned int[noSeats];
	for (int i = 0; i < noSeats; i++) {
		this->seats[i] = 0;
	}
}

Category::Category(string name, int noSeats, unsigned int* seats)
{
	this->name = name;
	this->noSeats = noSeats;
	this->seats = new unsigned int[noSeats];
	for (int i = 0; i < noSeats; i++) {
		this->seats[i] = seats[i];
	}
}

string Category::getName()
{
	return this->name;
}

void Category::setName(string name)
{
	this->name = name;
}

int Category::getNoSeats()
{
	return this->noSeats;
}

void Category::setNoSeats(int noSeats)
{
	if (noSeats > 0) {
		this->noSeats = noSeats;
	}
}

unsigned int* Category:: getSeats()
{
	return this->seats;
}

void Category::setSeats(unsigned int* seats)
{
	this->seats = new unsigned int[noSeats];
	for (int i = 0; i < noSeats; i++) {
		this->seats[i] = seats[i];
	}
}

Category::Category(const Category& c)
{
	this->name = c.name;
	this->noSeats = c.noSeats;
	this->seats = new unsigned int[c.noSeats];
	for (int i = 0; i < c.noSeats; i++) {
		this->seats[i] = c.seats[i];
	}
}

Category& Category::operator=(Category& c)
{
	if (this != &c) {
		delete[] seats;
		this->name = c.name;
		this->noSeats = c.noSeats;
		this->seats = new unsigned int[c.noSeats];
		for (int i = 0; i < c.noSeats; i++) {
			this->seats[i] = c.seats[i];
		}
	}
	return *this;
}

bool Category::isSeatFree(int seatIndex)
{
	return this->seats[seatIndex] == 0;
	
}

bool Category::allSeatsTaken()
{
	for (int i = 0; i < noSeats; i++) {
		if (this->seats[i] == 0) {
			return false;
		}
	}
	return true;
}

int Category::operator [](int index)
{
	if (index >= 0 && index < this->noSeats)
	{
		return this->seats[index];
	}
	else return -1;
}


ostream& operator<<(ostream& out, Category c)
{
	out << endl;
	out << "\tName: " << c.name << endl;
	out << "\tSeats:";
	if (c.noSeats != 0) {
		for (int i = 0; i < c.noSeats - 1; i++) {
			out << c.seats[i] << ",";
		}
		out << c.seats[c.noSeats - 1];
		return out;
	}
}

istream& operator>>(istream& in, Category& c)
{
	cout << endl;
	cout << "Enter name: ";
	in >> c.name;
	cout << "Enter NoSeats: ";
	in >> c.noSeats;
	c.seats = new unsigned int[c.noSeats];
	for (int i = 0; i < c.noSeats; i++) {
		cout << "Seats[" << i << "]=";
		in >> c.seats[i];
		
	}
	return in;
}


Category::~Category()
{
	delete[] seats;
}