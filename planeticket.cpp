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
//TO_DO: change boolean data to show false and true instead of 0 and 1
ostream& operator<<(ostream &os, planeTicket& ticket){
	os << ticket.firstName << " " << ticket.lastName << ", ";
	os << ticket.seatNumber << " ";
	os << ticket.cardType << ", ";
	os << ticket.classType << ", ";
    os << (ticket.specialNeeds ? "true" : "false") << ", ";
    os << (ticket.military ? "true" : "false");
	//os << ticket.specialNeeds << ", ";
	//os << ticket.military;
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

    /*
    // Class type priority
    if (classType == "FirstClass") {
        priority += 100;
    } else if (classType == "Business") {
        priority += 50;
    }

    // Loyalty status priority
    if (cardStatus == "GOLD") {
        priority += 10;
    } else if (cardStatus == "SILVER") {
        priority += 5;
    } */
   return priority;
}

bool planeTicket::operator <(const planeTicket& otherticket) const{

    return getPriority() < otherticket.getPriority();
}

bool planeTicket::operator >(const planeTicket& otherticket) const{

    return getPriority() > otherticket.getPriority();
}


/*
//Compare using boolean method:

//Determine if the current ticket has a lower priority than the other ticket.
bool planeTicket::operator <(const planeTicket& otherticket) const {
    // Preboarding priority comparison
    if ((specialNeeds && military) != (otherticket.specialNeeds && otherticket.military)) {
        return !(specialNeeds && military);
    }
    if (specialNeeds != otherticket.specialNeeds) {
        return !specialNeeds;
    }
    if (military != otherticket.military) {
        return !military;
    }

    // Class type comparison
    if (classType != otherticket.classType) {
        if (classType == "FirstClass") return false;              //returning false indicates it does not have lower priority.
        if (otherticket.classType == "FirstClass") return true;  //other ticket (otherticket) is FirstClass so return true.
                                                                //This indicates that the current ticket has lower priority.
        if (classType == "Business") return false;
        if (otherticket.classType == "Business") return true;
    }

    // Loyalty status comparison
    if (CardHeld != otherticket.CardHeld) {
        if (CardHeld == "GOLD") return false;
        if (otherticket.CardHeld == "GOLD") return true;
        if (CardHeld == "SILVER") return false;
        if (otherticket.CardHeld == "SILVER") return true;
    }

    // If all else is equal, return false
    return false;
}

bool planeTicket::operator >(const planeTicket& otherticket) const {
    // Preboarding priority comparison
    if ((specialNeeds && military) != (otherticket.specialNeeds && otherticket.military)) {
        return (specialNeeds && military);
    }
    if (specialNeeds != otherticket.specialNeeds) {
        return specialNeeds;
    }
    if (military != otherticket.military) {
        return military;
    }

    // Class type comparison
    if (classType != otherticket.classType) {
        if (classType == "FirstClass") return true;                     //Current Ticket returns True because it has higher priority.
        if (otherticket.classType == "FirstClass") return false;        //returning false indicates it does not have higher priority.
        if (classType == "Business") return true;
        if (otherticket.classType == "Business") return false;
    }

    // Loyalty status comparison
    if (CardHeld != otherticket.CardHeld) {
        if (CardHeld == "GOLD") return true;
        if (otherticket.CardHeld == "GOLD") return false;
        if (CardHeld == "SILVER") return true;
        if (otherticket.CardHeld == "SILVER") return false;
    }

    // If all else is equal, return false
    return false;
}

*/