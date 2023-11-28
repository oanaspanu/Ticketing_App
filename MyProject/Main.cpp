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
	Ticket ticket1("User1", PREMIUM), ticket2("User2");

	cout << "Cinema seats reserved: " << cinema.getNoSeats() << endl;
	cout << "Movie name: " << movie1.getName() << endl;

	cinema.printInfo();
	movie1.printInfo();

	cout << endl;
	cout << "Ticket id: " << ticket1.getId() << endl;
	cout << "Ticket User Name: " << ticket1.getUserName() << endl;
	cout << "Ticket price type: " << ticket1.getPrice() << endl;
	cout << "Ticket is valid? " << ticket1.getValidation() << endl;
	cout << endl;
	cout << "Ticket id: " << ticket2.getId() << endl;
	cout << "Ticket User Name: " << ticket2.getUserName() << endl;
	cout << endl;
	
	for (int i = 0; i < Ticket::NO_IDS; i++)
		cout << Ticket::USED_IDS[i] << ' ';
	cout << endl;
	cout << "No of ids: " << Ticket::NO_IDS;

	return 0;
}