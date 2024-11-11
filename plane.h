#include <iostream>
#include <string>
#include <fstream>
#include "planeticket.h"
#pragma once

using namespace std;

class Plane : public planeTicket {
public:

	Plane();
	void simulateSeating();

private:

	void getTickets(string filename);
	void insertTicket(planeTicket ticket);


	int getSeatNum(char seatChar);
	void boardPlane(planeTicket ticket);

	void printFirstClass();
	void printBusiness();
	void printCabin();
	void printPlane();
	void takeoff(); 	//ascii art

	void buildHeap();
    void heapify(int low, int high);
    planeTicket extractMax(); // Function to extract the highest priority passenger
	void announcePassengers();

	int heapSize;
	int numSeats = 62;
	int ticketSize = 0;
	int numPassengers;
	string fseats[13];
	string bseats[21];
	string eseats[31];
	planeTicket tickets[62];

	planeTicket heapTickets[62]; // Fixed-size array to store tickets for heap operations
};

