#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

class Category
{
private:
	string name;
	int noSeats;
	unsigned int* seats;
public:
	Category();
	Category(string name, int noSeats);
	Category(string name, int noSeats, unsigned int* seats);
	string getName();
	void setName(string name);
	int getNoSeats();
	void setNoSeats(int noSeats);
	unsigned int* getSeats();
	void setSeats(unsigned int* seats);
	Category(const Category& c);
	Category& operator=(Category& c);
	bool isSeatFree(int seatIndex);
	bool allSeatsTaken();
	int operator[](int index);
	friend ostream& operator<<(ostream&, Category);
	friend istream& operator>>(istream& in, Category& c);
	~Category();
}; 
