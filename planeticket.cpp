#include "planeticket.h"

planeTicket::planeTicket(string firstName, string lastName, string seatNumber, string CardHeld, string classType, bool specialNeeds, bool military)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->seatNumber = seatNumber;
	this->cardType = CardHeld;
	this->classType = classType;
	this->specialNeeds = specialNeeds;
	this->military = military;
    this->priority = 0;
}

//overloader to check ticket data
ostream& operator<<(ostream &os, planeTicket& ticket){
	os << ticket.firstName << " " << ticket.lastName << ", ";
	os << ticket.seatNumber << " ";
	os << ticket.cardType << ", ";
	os << ticket.classType << ", ";
    os << (ticket.specialNeeds ? "true" : "false") << ", ";
    os << (ticket.military ? "true" : "false");
	os << endl;
	return os;
}

string planeTicket::getSeatNumber() const
{
	return seatNumber;
}

string planeTicket::getClass() const
{
	return classType;
}

//Determining priority using integer values representing the priority of a ticket method:

int planeTicket::getPriority() const{

    int priority = 0;

    // Preboarding priority
    if (specialNeeds || military || (classType == "FirstClass" && cardType == "ELITE"))
        priority = 10;

    //Boarding Group 1
    else if (cardType == "ELITE" || classType == "FirstClass")
        priority = 8;
    //Boarding Group 2
    else if (classType == "Business" || cardType == "GOLD")
        priority = 6;
    //Boarding Group 3
    else if (classType == "Economy" && cardType == "SILVER")
        priority = 4;
    //Boarding Group 4 & 5
    else {
        if (seatNumber[1] == '1' || seatNumber[1] == '2'){
            priority = 2;
        }
        else
            priority = 0;
    }

   return priority;
}

bool planeTicket::operator <(const planeTicket& otherticket) const{

    return getPriority() < otherticket.getPriority();
}

bool planeTicket::operator >(const planeTicket& otherticket) const{

    return getPriority() > otherticket.getPriority();
}
