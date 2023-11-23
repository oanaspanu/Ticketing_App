#pragma once

enum Zone {GENERAL=1, FIRST_ROW, VIP};

class Location {
private:
	int maxSeats;
	int noRows;
	int* seatsPerRow;
	Zone zoneName;

public:

};