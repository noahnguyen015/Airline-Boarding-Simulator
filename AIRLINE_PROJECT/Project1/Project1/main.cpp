#include <iostream>
#include "plane.h"

using namespace std;

int main() {

	Plane plane;
	
	plane.printPlane();

	planeTicket ticket1("A3", "GOLD", "FirstClass", false, false);
	planeTicket ticket2("B3", "GOLD", "Business", false, false);
	planeTicket ticket3("D1", "GOLD", "Economy", false, false);

	plane.boardPlane(ticket1);
	plane.boardPlane(ticket2);
	plane.boardPlane(ticket3);

	plane.printPlane();
}