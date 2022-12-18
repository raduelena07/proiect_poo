#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include"client.h"
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS


Client::Client()
{
	this->lastName = "";
	this->firstName = "";
	this->email = nullptr;
	this->phoneNumber = "";
}

Client::Client(string lastName, string firstName, const char* email, string phoneNumber)
{
	this->lastName = lastName;
	this->firstName = firstName;
	if (checkEmail(email) == 0) {
		cout << "Invalid email " << endl;
		return;
	}
	else {
		this->email = new char[strlen(email) + 1];
		strcpy(this->email, email);
	}
	strcpy(this->email, email);
	this->phoneNumber = phoneNumber;

}
string Client::getlastName()
{
	return this->lastName;
}

void Client::setlastName(string lastName)
{
	if (isupper(lastName[0])) {
		this->lastName = lastName;
	}
	else cout << "Your last name should start with an upper character";
}

string Client::getfirstName()
{
	return this->firstName;
}

void Client::setFirstName(string firstName)
{
	if (isupper(firstName[0])) {
		this->firstName = firstName;
	}
	else cout << "Your first name should start with an upper character";
}

char* Client::getEmail()
{
	return this->email;

}
void Client::setEmail(const char* email)
{
	if (checkEmail(email) == 0) {
		cout << "Invalid email " << endl;
		return;
	} else {
		this->email = new char[strlen(email) + 1];
		strcpy(this->email, email);
	}
}

string Client::getPhoneNumber()
{
	return this->phoneNumber;
}

void Client::setPhoneNumber(string phoneNumber)
{
	if (phoneNumber.length() == 10) {
		this->phoneNumber = phoneNumber;
	}
	else cout << "Invalid phone number!" << endl;
}

Client::Client(const Client& c) 
{
	this->lastName = c.lastName;
	this->firstName = c.firstName;
	this->email = new char[strlen(c.email) + 1];
	strcpy(this->email, c.email);
	this->phoneNumber = c.phoneNumber;

}


Client& Client::operator=(Client& c)
{
	if (this != &c) {
		delete[] email;
		this->lastName = c.lastName;
		this->firstName = c.firstName;
		this->email = new char[strlen(c.email) + 1];
		strcpy(this->email, c.email);
		this->phoneNumber = c.phoneNumber;
	}
	return *this;
}
 bool Client::checkEmail(const char* email)
{
	 if (email == NULL) {
		 return false;
	 }
	int indexar = -1;
	int indexdot = -1;
	for (int i = 0; i < strlen(email); i++) {
		if (email[i] == '@') {
			indexar = i;
		}
		if (email[i] == '.') {
			indexdot = i;
		}
	}
	if (indexar <= 0 || indexdot <= 0) {
		return false;
	}
	if (indexdot-indexar <= 1) {
		return false;
	}
	if (indexdot == strlen(email) - 1) {
		return false;
	}
	
	return true;
}

 string Client::getFullName() 
 {
	 return this->lastName + " " + this->firstName;
	 
 }

 bool operator>(Client& c1, Client& c2)
 {
	 return c1.getFullName() > c2.getFullName();
 }


ostream& operator<<(ostream& out, Client c)
{ 
	out << endl;
	out << "Email: " << (c.email != nullptr ? c.email : "") << endl;
	out << "Full name: " << c.getFullName() << endl;
	out << "Phone Number: " << c.phoneNumber << endl;
	return out;
}

istream& operator>>(istream& in, Client& c)
{
	cout << "Enter last name: ";
	in >> c.lastName;
	cout << "Enter first name: ";
	in >> c.firstName;
	cout << "Enter phone number ";
	in >> c.phoneNumber;
	cout << "Enter email ";
	/*string buffer;
	in >> buffer;
	c.email = new char[buffer.length() + 1];
	strcpy(c.email, buffer.c_str());*/
	char buffer[100];
	in >> buffer;
	c.email = new char[strlen(buffer) + 1];
	strcpy(c.email, buffer);
	return in;
}

Client::~Client() {
	delete[] email;
}
