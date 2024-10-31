#include "planeticket.h"

planeTicket::planeTicket(string firstName, string lastName, string seatNumber, string CardHeld, string classType, bool specialNeeds, bool military)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->seatNumber = seatNumber;
	this->CardHeld = CardHeld;
	this->classType = classType;
	this->specialNeeds = specialNeeds;
	this->military = military;
}

//overloader to check ticket data
//TO_DO: change boolean data to show false and true instead of 0 and 1
ostream& operator<<(ostream &os, planeTicket ticket){
	os << ticket.firstName << "/" << ticket.lastName << ", ";
	os << ticket.seatNumber << ", ";
	os << ticket.CardHeld << ", ";
	os << ticket.classType << ", ";
	os << ticket.specialNeeds << ", ";
	os << ticket.military;
	os << endl;
	return os;
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