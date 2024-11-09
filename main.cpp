#include <iostream>
#include "plane.h"
#include "planeticket.h"

using namespace std;

int main() {

	Plane plane;

	plane.getTickets();
	//plane.readTicket();

	cout << "Initial seating arrangement:" << endl;
    plane.printPlane();

	/*
	// Extract and board the highest priority passenger one at a time. This will show who is boarding and the plane map gets updated each time.
    while (plane.heapSize > 0) {
        planeTicket highestPriorityTicket = plane.extractMax();
        cout << "Boarding passenger: " << highestPriorityTicket;
        plane.boardPlane(highestPriorityTicket);

        // Print the updated seating arrangement after each boarding
        cout << "Updated seating arrangement:" << endl;
        plane.printPlane();
    }

    cout << "All passengers have been boarded." << endl;
	*/


   //Extract and board the highest priority passenger. This will show entire list of boarding passengers and one completed map.
    
    //while(plane.heapSize > 0){

    planeTicket highestPriorityTicket = plane.extractMax();
    cout <<"PREBOARDING: " << endl;
    while(highestPriorityTicket.getPriority() == 10){
        cout << "Boarding passenger: " << highestPriorityTicket;
        plane.boardPlane(highestPriorityTicket);
        highestPriorityTicket = plane.extractMax();
    }
 //   }

    cout << "All passengers have been boarded." << endl;

    cout << "Final seating arrangement:" << endl;
    plane.printPlane();

    return 0;
}