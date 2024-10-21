#include <iostream>
#include <string>
#include "planeTicket.h"
#pragma once

using namespace std;

class Plane : public planeTicket {
public:

	Plane();
	void printFirstClass();
	void printBusiness();
	void printCabin();
	void printPlane();

	int getSeatNum(char seatChar);
	void boardPlane(planeTicket ticket);

private:
	int numSeats = 62;
	string fseats[13];
	string bseats[21];
	string eseats[31];
};

