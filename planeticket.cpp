#include "planeticket.h"

planeTicket::planeTicket(string seatNumber, string CardHeld, string classType, bool specialNeeds, bool military)
{
	this->seatNumber = seatNumber;
	this->CardHeld = CardHeld;
	this->classType = classType;
	this->specialNeeds = specialNeeds;
	this->military = military;
}

bool planeTicket::operator <(planeTicket otherticket)
{
	return false;
}

string planeTicket::getSeatNumber()
{
	return seatNumber;
}

string planeTicket::getClass()
{
	return classType;
}