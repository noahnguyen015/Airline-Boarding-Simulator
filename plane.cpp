#include "plane.h"

Plane::Plane() {
	// fill up the values in 
	// ignore first entry 0 because of printing
	for (int i = 1; i < 31; i++) {
		if (i < 13) {
			fseats[i] = "[ ]";
			bseats[i] = "[ ]";
			eseats[i] = "[ ]";
		}
		else if (13 <= i < 21) {
			bseats[i] = "[ ]";
			eseats[i] = "[ ]";
		}
		else {
			eseats[i] = "[ ]";
		}
	}
}

void Plane::getTickets(){
	string ticketData[5];
	bool specialData[2];

	ifstream istream;
	ofstream ostream;
	int i = 0;
	int j = 0;
	int arridx = 0;

	istream.open("test.txt");

	while (istream >> ticketData[i]) {

		if(ticketData[i] == "false" ){

			if(j == 2) {
				j = 0;
				specialData[j] = false;

				j++;
			} 
			else {
				specialData[j] = false;
				j++;
			}
		}
		else {
			if(j == 2) {
				j = 0;
				specialData[j] = true;
				j++;
			} 
			else {
				specialData[j] = true;
				j++;
			}
		}

		i++;

		if(i == 5){
			planeTicket ticket(ticketData[0], ticketData[1], ticketData[2], specialData[0], specialData[1]);
			insertTicket(ticket);
			i = 0;
		}
	}
	istream.close();
}

void Plane::insertTicket (planeTicket ticket){
	tickets[ticketSize] = ticket;
	ticketSize++;
}

void Plane::printFirstClass()
{
	cout << "\t" << "|----------First Class----------|" << endl;

	//list the rows for visual help
	cout << "\t|\tA" << "   B" << "\t    C" << "   D" << "       |" << endl;

	for (int i = 1; i < 13; i++) {

		//for every first seat in a row, tab & space
		if (i % 4 == 1) 
			cout << "\t" << "|" << "      ";

		cout << fseats[i] << " ";

		if (i % 2 == 0) {
			if (i % 4 == 0)
				//for every 4 seats, go to new row, (spaces and | for box)
				cout << "     " << "|" << "\n";
			else
				//every 2 seats jump to new column
				cout << "    ";
		}
	}
	//line break between classes
	cout << "\t" << "|" << "---------Business Class--------" << "|" << endl;
}

void Plane::printBusiness()
{

	//list the rows for visual help
	cout << "\t|\tA" << "   B" << "\t    C" << "   D" << "       |" << endl;

	for (int i = 1; i < 21; i++) {
		//for every first seat in a row, tab & space
		if (i % 4 == 1)
			cout << "\t" << "|" << "      ";

		cout << bseats[i] << " ";

		if (i % 2 == 0) {
			if (i % 4 == 0)
				//for every 4 seats, go to new row, (spaces and | for box)
				cout << "     " << "|" << "\n";
			else
				//every 2 seats jump to new column
				cout << "    ";
		}
	}

	//line break between classes
	cout << "\t" << "|" << "---------Economy Class---------" << "|" << endl;
}

void Plane::printCabin()
{
	cout << "\t|   A" << "   B" <<"   C" << "\t    D" << "   E" << "   F" << "   |" << endl;

	for (int i = 1; i < 31; i++) {
		//for every first seat in a row, tab & space
		if (i % 6 == 1) 
			cout << "\t" << "|" << "  ";
		
		cout << eseats[i] <<" ";

		if (i % 3 == 0) {
			
			if (i % 6 == 0)
				//every 6 seats go to a new row
				cout << " " << "|" << "\n";
			else
				//every three seats go to a new column
				cout << "    ";
		}
	}
	//line break between classes
	cout << "\t" << "|" << "-------------------------------" << "|" << endl;
}

void Plane::printPlane() {
	printFirstClass();
	printBusiness();
	printCabin();

	cout << endl;
}

int Plane::getSeatNum(char seatChar)
{
	//basically converts a number characters to a number, we only need 1-6
	if (seatChar == '1')
		return 1;
	else if (seatChar == '2')
		return 2;
	else if (seatChar == '3')
		return 3;
	else if (seatChar == '4')
		return 4;
	else if (seatChar == '5')
		return 5;
	else if (seatChar == '6')
		return 6;
	else if (seatChar == '7')
		return 7;
	else if (seatChar == '8')
		return 8;
	else if (seatChar == '9')
		return 9;
	else
		return 0;
}		

void Plane::readTicket(){
	for(int i = 0; i < ticketSize; i++){
		cout << tickets[i];
		boardPlane(tickets[i]);
	}
}

void Plane::boardPlane(planeTicket ticket)
{
	//start at row '0' meaning first row
	//add by number of seats in a row to go to next seat in that section
	//sections A, B, C, etc..
	int rowNum = 0;
	string seatLetter = ticket.getSeatNumber();
	string seatChar;
	int ticketIdx = 0;

	string ticketClass = ticket.getClass();

	rowNum = getSeatNum(seatLetter[1]) - 1;

	if (ticketClass == "FirstClass" || ticketClass == "Business") {

		if (seatLetter[0] == 'A') 
			//calculates which row it will be on
			ticketIdx = 1 + (rowNum * 4);
		else if (seatLetter[0] == 'B') 
			ticketIdx = 2 + (rowNum * 4);
		else if (seatLetter[0] == 'C') 
			ticketIdx = 3 + (rowNum * 4);
		else if (seatLetter[0] == 'D') 
			ticketIdx = 4 + (rowNum * 4);

		//determine if the section is first class or business class
		(ticketClass == "FirstClass") ? fseats[ticketIdx] = "[X]" : bseats[ticketIdx] = "[X]";
	}
	else {
		//economy seats
		if (seatLetter[0] == 'A')
			ticketIdx = 1 + (rowNum * 4);
		else if (seatLetter[0] == 'B')
			ticketIdx = 2 + (rowNum * 4);
		else if (seatLetter[0] == 'C')
			ticketIdx = 3 + (rowNum * 4);
		else if (seatLetter[0] == 'D')
			ticketIdx = 4 + (rowNum * 4);
		else if (seatLetter[0] == 'E')
			ticketIdx = 5 + (rowNum * 4);
		else if (seatLetter[0] == 'F')
			ticketIdx = 6 + (rowNum * 4);

		
		eseats[ticketIdx] = "[X]";
	}
}
