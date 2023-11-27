#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

enum Zone { NORMAL = 1, FIRST_ROW, VIP };

class Location {
private:
    static int MAX_SEATS;
    static int COUNTER;
    int noSeats = 0;
    int* seats = nullptr;
    Zone zoneName = Zone::NORMAL;

public:
    // Setters
    void setSeats(const int newNoSeats, const int* newSeats);

    void setZoneName(const Zone newZoneName);


    // Getters
    int* getSeats() const;

    int getNoSeats() const;

    string getZoneName() const;


    // Class Constructor
    Location(Zone zoneName, int noSeats, int* seats);

    Location(int noSeats, int* seats);

    // Class Copy Constructor 
    Location(const Location& object);
 
        // Destructor
    ~Location();

    // Displaying information
    void printInfo();

    // Overloading operator =
    void operator=(const Location source);
};


