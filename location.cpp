#include <iostream>
#include <string>
#include <ctime>
#include "location.h"
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

Location::Location()
{
	this->address = "";
	this->noCategories = 0;
	this->categories = nullptr;
	this->name = "";
}

Location::Location(string address, int noCategories, Category* categories, string name)
{
	this->address = address;
	this->noCategories = noCategories;
	this->categories = new Category[noCategories];
	for (int i = 0; i < noCategories; i++) {
		this->categories[i] = categories[i];
	}
	this->name = name;
}

string Location::getAddress()
{
	return this->address;
}

void Location::setAddress(string address)
{
	this->address = address;
}

int Location::getNoCategories()
{
	return this->noCategories;
}

void Location::getNoCategories(int noCategories)
{
	if (noCategories > 0) {
		this->noCategories = noCategories;
	}
}

Category* Location::getCategories()
{
	return this->categories;
}

void Location::getCategories(Category* categories)
{
	this->categories = new Category[noCategories];
	for (int i = 0; i < noCategories; i++) {
		this->categories[i] = categories[i];
	}
}

string Location::getName()
{
	return this->name;
}

void Location::setName(string name)
{
	this->name = name;
}

Location::Location(const Location& l)
{
	this->address = l.address;
	this->noCategories = l.noCategories;
	this->categories = new Category[l.noCategories];
	for (int i = 0; i < noCategories; i++) {
		this->categories[i] = l.categories[i];
	}
	this->name = l.name;
}

Location& Location::operator=(Location& l)
{
	if (this != &l) {
		delete[] categories;
		this->address = l.address;
		this->noCategories = l.noCategories;
		this->categories = new Category[l.noCategories];
		for (int i = 0; i < noCategories; i++) {
			this->categories[i] = l.categories[i];
		}
		this->name = l.name;
	}
	return *this;
}

ostream& operator<<(ostream& out, Location l)
{
	out << endl;
	out << "Location details" << endl;
	out << "Name: " << l.name << endl;
	out << "Address: " << l.address << endl;
	out << "Categories: ";
	for (int i = 0; i < l.noCategories; i++) {
		//out << "Category " << i + 1 << " details:" << endl;
		out << l.categories[i];
	}
	return out;
}

istream& operator>>(istream& in, Location& l)
{
	cout << endl;
	cout << "Enter name: ";
	in >> l.name;
	cout << "Enter address: ";
	in >> l.address;
	cout << "Enter NoCategories: ";
	in >> l.noCategories;
	l.categories= new Category[l.noCategories];
	for (int i = 0; i < l.noCategories; i++) {
		cout << "Category" << i << ":";
		in >> l.categories[i];
	}
	return in;
}

Location::~Location()
{
	delete[] categories;
}