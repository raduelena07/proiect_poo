#include <iostream>
#include <string>
#include <ctime>
#include "category.h"
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

class Location
{
private:
	string address;
	int noCategories;
	Category* categories;
	string name;
public:
	Location();
	Location(string address, int noCategories, Category* categories, string name);
	string getAddress();
	void setAddress(string address);
	int getNoCategories();
	void getNoCategories(int noCategories);
	Category* getCategories();
	void getCategories(Category* categories);
	string getName();
	void setName(string name);
	Location(const Location& l);
	Location& operator=(Location& l);
	friend ostream& operator<<(ostream&, Location l);
	friend istream& operator>>(istream& in, Location& c);
	~Location();
};
