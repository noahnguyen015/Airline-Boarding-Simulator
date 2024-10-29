#include <iostream>
//#include <string>
#include <fstream>
#include "planeticket.h"
#pragma once

using namespace std;

class Plane : public planeTicket {
public:

	Plane();
	void getTickets();
	void insertTicket(planeTicket ticket);

	void printFirstClass();
	void printBusiness();
	void printCabin();
	void printPlane();

	int getSeatNum(char seatChar);
	void boardPlane(planeTicket ticket);
	void readTicket();

private:
	int numSeats = 62;
	int ticketSize = 0;
	string fseats[13];
	string bseats[21];
	string eseats[31];
	planeTicket tickets[62];
};

