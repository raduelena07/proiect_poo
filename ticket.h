#include <iostream>
#include <string>
#include <ctime>
#include "event.h"
#include "client.h"
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

class Ticket
{
private:
	int id;
	Event event;
	const double basePrice = 10;
	double price;
	Client client;
	static int noTickets;
public:
	Ticket();
	Ticket(Event event, double price, Client client, double bp);
	int getId();
	void setId(int id);
	Event getEvent();
	void setEvent(Event event);
	double getPrice();
	void setPrice(double price);
	Client getClient();
	void setClient(Client client);
	friend ostream& operator<<(ostream& out, Ticket t);
	static int getNoTickets() {
		return noTickets;
	}
};
//int Ticket::noTickets;