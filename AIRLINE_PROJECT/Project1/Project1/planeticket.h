#include <iostream>
#pragma once

using namespace std;


class planeTicket {
public:

	planeTicket() {};

	planeTicket(string seatNumber, string CardHeld, string classType, bool specialNeeds, bool military);

	bool operator < (planeTicket otherticket);
	string getSeatNumber();
	string getClass();

private:
	string seatNumber = "";
	string CardHeld = "";
	string classType = "";
	bool specialNeeds = false;
	bool military = false;
};

