#include "plane.h"
#include <chrono>
#include <thread>
#include <algorithm>


Plane::Plane() :heapSize(0){
	// fill up the values in 
	// ignore first entry 0 because of printing
	for (int i = 1; i < 31; i++) {
		if (i < 13) {
			fseats[i] = "[ ]";
			bseats[i] = "[ ]";
			eseats[i] = "[ ]";
		}
		//else if (13 <= i < 21) 
		else if(i >= 13 && i < 21){
			bseats[i] = "[ ]";
			eseats[i] = "[ ]";
		}
		else {
			eseats[i] = "[ ]";
		}
	}
}

void Plane::getTickets(){
	string ticketData[7];				//ticketData holds the string data of the ticket/ keeps track of index, elements in a ticket		
	bool specialData[2];				//use to hold if the person has special needs

	ifstream istream;
	ofstream ostream;
	int i = 0;							//keep track of string data
	int j = 0;							//keep track of boolean data

	istream.open("test.txt");

	if (!istream) {
        cout << "Error opening file 'test.txt'" << endl;
        return;
    }

	while (istream >> ticketData[i]) {	//read each string in the file
		if(ticketData[i] == "false" ){	//check if it is one of the boolean data (true or false)
			if(j == 2) 					//if more than 2 (means you already recorded 2 elements)
				j = 0; 					//reset to 0
			specialData[j] = false; 	//false = 0
			j++;						
		}
		else {
			if(j == 2) 					//same but with true instead of false
				j = 0;
			specialData[j] = true;		//true = 1
			j++;
		}

		i++;

		if(i == 7){						//once big enough (meaning 7 elements are read, make a ticket)
			//generate a ticket
			planeTicket ticket(ticketData[0], ticketData[1], ticketData[2], ticketData[3], ticketData[4], specialData[0], specialData[1]);
			insertTicket(ticket);		//put ticket into array tickets 
			i = 0;						//reset to read 7 more elements
		}
	}
	istream.close();

	buildHeap();

}

void Plane::insertTicket (planeTicket ticket){
	tickets[ticketSize] = ticket;
    heapTickets[ticketSize] = ticket; // Add the ticket to the heap array
    ticketSize++;
    heapSize = ticketSize; // Update the size of the heap
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

/*USED FOR TESTING, can be altered/deleted later*/
/*void Plane::readTicket(){
	for(int i = 0; i < ticketSize; i++){
	  	cout << tickets[i];
		boardPlane(tickets[i]);	//grabs all tickets and boards them 
	}
}
*/

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
			ticketIdx = 1 + (rowNum * 6);
		else if (seatLetter[0] == 'B')
			ticketIdx = 2 + (rowNum * 6);
		else if (seatLetter[0] == 'C')
			ticketIdx = 3 + (rowNum * 6);
		else if (seatLetter[0] == 'D')
			ticketIdx = 4 + (rowNum * 6);
		else if (seatLetter[0] == 'E')
			ticketIdx = 5 + (rowNum * 6);
		else if (seatLetter[0] == 'F'){
			ticketIdx = 6 + (rowNum * 6);
		}

		eseats[ticketIdx] = "[X]";
	}
}

void Plane::buildHeap() {
    for (int index = heapSize / 2 - 1; index >= 0; index--) {
        heapify(index, heapSize - 1);
    }
}

void Plane::heapify(int low, int high) {
    int largeIndex;
    planeTicket temp = heapTickets[low]; // copy the root node of the subtree
    largeIndex = 2 * low + 1; // index of the left child

    while (largeIndex <= high) {
        if (largeIndex < high) {
            if (heapTickets[largeIndex] < heapTickets[largeIndex + 1]) {
                largeIndex = largeIndex + 1; // index of the largest child
            }
        }

        //if (temp < heapTickets[largeIndex]) { // subtree is already in a heap
		if(temp > heapTickets[largeIndex]){
            break;							//The condition if (temp < heapTickets[largeIndex]) should be
        } else {							//if (temp > heapTickets[largeIndex]) to maintain the max-heap property
            heapTickets[low] = heapTickets[largeIndex]; // move the larger child to the root
            low = largeIndex; // go to the subtree to restore the heap
            largeIndex = 2 * low + 1;
        }
    }

    heapTickets[low] = temp; // insert temp into the tree, that is, list
}

planeTicket Plane::extractMax() {
  	if (heapSize == 0) {
        return planeTicket(); // Return a default-constructed planeTicket as a sentinel value
    }

    planeTicket maxTicket = heapTickets[0];
    heapTickets[0] = heapTickets[heapSize - 1];
    heapSize--;
    heapify(0, heapSize - 1);

    return maxTicket;
}

void Plane::announcePassengers(){
	cout << "Hello passengers. We are now boarding and will be naming passengers for our flight." << endl; // BOARDING STARTS
	cout << "Please have your plane ticket and identification ready." << endl;
	this_thread::sleep_for(chrono::seconds(4));
	planeTicket highestPriorityTicket = extractMax(); //takes highest priority 

    cout <<"PREBOARDING: " << endl; //for military + special needs, military, special needs, and first class + elite passengers
	this_thread::sleep_for(chrono::seconds(2)); 
    while(highestPriorityTicket.getPriority() == 10){
        cout << "Boarding passenger: " << highestPriorityTicket;
        boardPlane(highestPriorityTicket);
		this_thread::sleep_for(chrono::seconds(1)); //1 second delay
        highestPriorityTicket = extractMax(); //gets next ticket for highest priority
    }

	cout <<"BOARDING PASSENGERS IN GROUP 1: " << endl;  //first class and elite passengers
	this_thread::sleep_for(chrono::seconds(2)); 
    while(highestPriorityTicket.getPriority() == 8){
        cout << "Boarding passenger: " << highestPriorityTicket;
        boardPlane(highestPriorityTicket);
		this_thread::sleep_for(chrono::seconds(1));
        highestPriorityTicket = extractMax(); //gets next ticket for highest priority
    }

	cout <<"BOARDING PASSENGERS IN GROUP 2: " << endl; //business and gold passengers
	this_thread::sleep_for(chrono::seconds(2)); 
    while(highestPriorityTicket.getPriority() == 6){
        cout << "Boarding passenger: " << highestPriorityTicket;
        boardPlane(highestPriorityTicket);
		this_thread::sleep_for(chrono::seconds(1));
        highestPriorityTicket = extractMax();
    }

	cout <<"BOARDING PASSENGERS IN GROUP 3: " << endl; //economy and silver passengers
	this_thread::sleep_for(chrono::seconds(2)); 
    while(highestPriorityTicket.getPriority() == 4){
        cout << "Boarding passenger: " << highestPriorityTicket;
        boardPlane(highestPriorityTicket);
		this_thread::sleep_for(chrono::seconds(1));
        highestPriorityTicket = extractMax();
    }

	cout <<"BOARDING PASSENGERS IN GROUP 4 and 5: " << endl; //everyone else
	this_thread::sleep_for(chrono::seconds(2)); 
    while(highestPriorityTicket.getPriority() == 2){
        cout << "Boarding passenger: " << highestPriorityTicket;
        boardPlane(highestPriorityTicket);
		this_thread::sleep_for(chrono::seconds(1));
        highestPriorityTicket = extractMax();
    }

	cout << "All passengers have been boarded." << endl;
}