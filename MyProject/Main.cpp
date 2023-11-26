#include <stdio.h>
#include <iostream>
#include "Location.h"
#include "Event.h"
#include "Ticket.h"

using namespace std;

int main() {

	// clases test

	int seats[] = { 20, 21 };

	Location cinema(2, seats);
	Event movie1("Barbie 2", "10 jan 2023");

	cout << "Cinema seats reserved: " << cinema.getNoSeats() << endl;
	cout << "Movie name: " << movie1.getName() << endl;

	cinema.printInfo();
	movie1.printInfo();

	return 0;
}