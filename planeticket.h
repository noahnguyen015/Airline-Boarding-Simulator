#include <iostream>
#pragma once

using namespace std;


class planeTicket {
public:

	planeTicket() {};

	planeTicket(string firstName, string lastName, string seatNumber, string CardHeld, string classType, bool specialNeeds, bool military);

	friend ostream& operator <<(ostream &os, planeTicket& ticket);

	bool operator < ( const planeTicket& otherticket) const;
	bool operator > (const planeTicket& otherticket) const;
	string getSeatNumber() const;
	string getClass() const;
	int getPriority() const; // Function to get the priority value of a ticket

private:
	string firstName = "";
	string lastName = "";
	string seatNumber = "";
	string cardType = "";
	string classType = "";
	bool specialNeeds = false;
	bool military = false;
	int priority;
};

