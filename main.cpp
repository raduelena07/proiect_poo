#include <iostream>
#include <string>
#include <ctime>
//#include "client.h"
//#include "category.h"
//#include "event.h"
//#include "location.h"
#include "ticket.h"
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	Location locatie1;
	Category categ1;
	unsigned int* locuri;
	locuri = new unsigned int[3];
	locuri[0] = 23;
	locuri[1] = 24;
	locuri[2] = 25;
	Category categ2 = Category("A", 3, locuri);
	Category categ3 = Category("B", 3, locuri);
	//cout << categ2;
	Category* categorii = new Category[3];
	categorii[0] = categ1;
	categorii[1] = categ2;
	categorii[2] = categ3;
	Location locatie2 = Location("Bucuresti", 3, categorii, "Circ");
	//cout << locatie2;
	//cin >> categ1;
	//cout << categ1;
	//cin >> locatie2;
	Event event1 = Event("Concert", locatie2, 2020, 9, 7, 3);
	/*cin >> event1;
	cout << event1;*/

	Client client1 = Client("Ion", "Andrei", "ionandrei@hgv.jhus", "0769213187");
	cout << client1;
	Ticket ticket1 = Ticket(event1, 20, client1, 10);
	//cout << ticket1;
	
	//char* str;
	//str = new char[strlen("a@b.") + 1];
	//strcpy(str, "a@b.");
	//cout<<Client::checkEmail(str);
	
	//Client::checkEmail("a@b.c");

	//int arr[] = { 4,5,76,1,22 };
	//int i1 = 1;
	//int i2 = 4;
	//int x = arr[2];
	//int i3 = 2;
}