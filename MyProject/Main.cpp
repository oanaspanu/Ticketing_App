#include <stdio.h>
#include <iostream>
#include "Location.h"
#include "Event.h"
#include "Ticket.h"

using namespace std;

int main() {

	// clases test

	int seats[] = { 20, 21 };

	Location l1(6, 2, seats);
	Event e1("Movie 1", MOVIE, "01 jan 2023");
	Ticket t1("User1", PREMIUM), t2("User2"), t3("User3"), t4("User4");

	cout << "Cinema seats reserved: " << l1.getNoSeats() << endl;
	cout << "Event name: " << e1.getName() << endl;

	cout << "Ticket 1 id: " << t1.getId() << endl;
	cout << "Ticket 1 User Name: " << t1.getUserName() << endl;
	cout << "Ticket 1 price type: " << t1.getPrice() << endl;
	cout << "Ticket 1 is valid? " << t1.getValidation() << endl;
	cout << endl;

	cout << "Ticket 2 id: " << t2.getId() << endl;
	cout << "Ticket 2 User Name: " << t2.getUserName() << endl;
	cout << endl;
	cout << "Ticket 3 id: " << t3.getId() << endl;
	cout << "Ticket 4 id: " << t4.getId() << endl;


	//Check the static vector from Tickets
	/*for (int i = 0; i < Ticket::NO_IDS; i++)
		cout << Ticket::USED_IDS[i] << ' ';
	cout << endl;
	cout << "No of ids: " << Ticket::NO_IDS;
	*/

	cout << endl;
	l1.printInfo();
	e1.printInfo();
	t1.printInfo();
	cout << endl;
	cout << "---------------------------------------" << endl;

	//Testing location class overloading

	Location l2 = l1, l3;  // operator=
	cin >> l3;   //operator>>
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << l2;  //operator<<
	cout << endl;
	cout << l3;
	cout << "---------------------------------------" << endl;


	int a = l3[4];  //operator []
	cout << a;

	l2 = 5 + l2;  //operator+
	l1++;         //operator++
	++l3;

	float b = 5 + (float)l1;  //cast operator

	//operator>=
	if (l2 >= l3)
		cout << "l2 has more seats than l3." << endl;
	else
		cout << "l3 has more seats than l2" << endl;

	//operator==
	if (l1 == l2)
		cout << "l1 and l2 are in the same hall" << endl;
	else
		cout << "l1 and l2 are in different halls" << endl;





	return 0;
}