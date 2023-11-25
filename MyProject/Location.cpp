#include <iostream>

using namespace std;

enum Zone { GENERAL = 1, FIRST_ROW, VIP };

class Location {
private:
    static int maxSeats;
    static int COUNTER;
    int noSeats = 0;
    int* seats = nullptr;
    Zone zoneName= Zone::GENERAL;

public:

    // Class Constructor
    Location(Zone zoneName, int noSeats, int* seats) {
       
    }


    // Copy Constructor
    Location(const Location& object) {
       
    }

    // Destructor
    ~Location() {
        delete[] seats;
    }
    

    // Getters

    int* getSeats() {

        if (this-> seats == nullptr )
            throw exception("There is no seat set. Try to reserve a seat first.");

        int* copy = new int[this->noSeats];
        for (int i = 0; i < this->noSeats; i++)
            copy[i] = this->seats[i];

        return copy;
    }

    int getNoSeats() {
        return this->noSeats;
    }

    string getZoneName() {
        switch (this->zoneName) {
        case GENERAL:
            return "General";
        case FIRST_ROW:
            return "First-row";
        case VIP:
            return "VIP";
        }
    }

};

int Location::maxSeats = 500;
int Location::COUNTER = 0;
