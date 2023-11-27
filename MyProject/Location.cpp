#include "Location.h"


int Location::MAX_SEATS = 500;
int Location::COUNTER = 0;

// Setters (for writing the object)

    void Location::setSeats(const int newNoSeats, const int* newSeats) {
        if (newSeats == nullptr)
            throw exception("Invalid data.");

        if (COUNTER + newNoSeats > MAX_SEATS)
            throw exception("No seats available.");

        delete this->seats;

        this->seats = new int[newNoSeats];
        for (int i = 0; i < newNoSeats; i++)
            this->seats[i] = newSeats[i];

        this->noSeats = newNoSeats;
        COUNTER += newNoSeats;
    }

    void Location::setZoneName(const Zone newZoneName)
    {
        this->zoneName = newZoneName;
    }


// Getters (for reading the object)
    int* Location::getSeats() const {
        if (this->seats == nullptr || this->noSeats <= 0)
            throw exception("There is no seat set.");

        int* copy = new int[this->noSeats];
        for (int i = 0; i < this->noSeats; i++)
            copy[i] = this->seats[i];

        return copy;
    }

    int  Location::getNoSeats() const {
        return this->noSeats;
    }

    string  Location::getZoneName() const {
        switch (this->zoneName) {
        case NORMAL:
            return "Any";
        case FIRST_ROW:
            return "First-row";
        case VIP:
            return "VIP";
        }
    }


// Class Constructor
    Location::Location(Zone zoneName, int noSeats, int* seats) {
        this->setSeats(noSeats, seats);
        this->setZoneName(zoneName);
    }

    Location::Location(int noSeats, int* seats) {
        this->setSeats(noSeats, seats);
    }

// Class Copy Constructor 
    Location::Location(const Location& object) {
        this->zoneName = object.zoneName;

        this->seats = new int[object.noSeats];
        for (int i = 0; i < object.noSeats; i++)
            this->seats[i] = object.seats[i];

        this->noSeats = object.noSeats;
    }

// Destructor
    Location::~Location() {
        delete seats;
    } 

// Displaying information
    void Location::printInfo() {
        cout << endl;
        cout << "Zone selected: " << this->getZoneName() << endl;
        cout << "Number of seats selected: " << this->getNoSeats() << endl;
        if (seats != nullptr) {
            cout << "Seats selected: ";
            for (int i = 0; i < noSeats; i++)
                cout << seats[i] << ' ';
            cout << endl;
        }
    }
      
// Overloading operator =
    void Location::operator=(const Location source) {
        this->zoneName = source.zoneName;
        this->noSeats = source.noSeats;

        if (this->seats == source.seats) {
            return;     //same object
        }
        else {
            delete this->seats;
            this->seats = new int[this->noSeats];
            for (int i = 0; i < this->noSeats; i++)
                this->seats[i] = source.seats[i];

        }
    }