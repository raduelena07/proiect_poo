#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

class Client
{
private:
	string lastName;
	string firstName;
	char* email;
	string phoneNumber;

public:
	Client();

	Client(string lastName, string firstName, const char* email, string phoneNumber);

	string getlastName();

	void setlastName(string lastName);

	string getfirstName();

	void setFirstName(string firstName);

	char* getEmail();
	void setEmail(const char* email);

	string getPhoneNumber();

	void setPhoneNumber(string phoneNumber);

	Client(const Client& c);
	Client& operator=(Client& c);
	static bool checkEmail(const char* email);
	string getFullName();
	friend ostream& operator<<(ostream&, Client c);
	friend istream& operator>>(istream& in, Client& c);
	friend bool operator>(Client& c1, Client& c2);
	~Client();
};

