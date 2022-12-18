#include <iostream>
#include <string>
#include <ctime>
#include "ticket.h"
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

Ticket::Ticket():basePrice(0)
{
	this->id = time(0);
	Event e;
	this->event = e;
	this->price = 0;
	Client c;
	this->client = c;
	Ticket::noTickets++;
}

Ticket::Ticket(Event event, double price, Client client, double bp): basePrice(bp)
{
	this->id = time(0);
	this->event = event;
	this->price = basePrice + price;
	this->client = client;
	Ticket::noTickets++;
	//cout << noTickets << endl;
}

int Ticket::getId()
{
	return this->id;
}
//void Ticket::setId(int id)
//{
//	this->id = id;
//}

Event Ticket::getEvent()
{
	return this->event;
}

void Ticket::setEvent(Event event)
{
	this->event = event;
}

double Ticket:: getPrice()
{
	return this->price;
}

void Ticket::setPrice(double price)
{	
	this->price = basePrice + price;
}

Client Ticket::getClient()
{
	return this->client;
}

void Ticket::setClient(Client client)
{
	this->client = client;
}

ostream& operator<<(ostream& out, Ticket t)
{
	out << "Id: " << t.id << endl;
	out << "Price: " << t.price << endl;
	out << "Client: " << t.client << endl;
	out << "Event: " << t.event << endl;
	return out;
}

int Ticket::noTickets = 0;