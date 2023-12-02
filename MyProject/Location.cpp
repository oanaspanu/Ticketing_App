#include "Location.h"


int Location::MAX_SEATS = 500;
int Location::MAX_HALLS = 10;
int Location::COUNTER = 0;

void Location::addSeat(int newSeat) {
    int* newArray = new int[this->noSeats + 1];

    for (int i = 0; i < this->noSeats; i++)
        newArray[i] = this->seats[i];
    newArray[this->noSeats] = newSeat;
    this->noSeats += 1;

    delete this->seats;
    this->seats = newArray;
}


// Setters (for writing the object) //

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

    void Location::setHall(const int newHall) {
        if (newHall > MAX_HALLS  || newHall < 0)
            throw exception("Invalid data.");

        this->hall = newHall;
    }

// Getters (for reading the object) //

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

    int Location::getHall() const {
        return this->hall;
    }


// Class Constructor //

    Location::Location(){ }

    Location::Location(int hall, Zone zoneName, int noSeats, int* seats) {
        this->setSeats(noSeats, seats);
        this->setZoneName(zoneName);
        this->setHall(hall);
    }

    Location::Location(int hall, int noSeats, int* seats) {
        this->setSeats(noSeats, seats);
        this->setHall(hall);
    }

// Class Copy Constructor  //

    Location::Location(const Location& object) {
        this->zoneName = object.zoneName;
        this->hall = object.hall;

        this->seats = new int[object.noSeats];
        for (int i = 0; i < object.noSeats; i++)
            this->seats[i] = object.seats[i];

        this->noSeats = object.noSeats;
    }

// Destructor //

    Location::~Location() {
        delete seats;
    } 

// Displaying information //

    void Location::printInfo() {
        cout << endl;
        cout << "-- Location information --" << endl;
        cout << "Hall: " << this->getHall() << endl;
        cout << "Zone: " << this->getZoneName() << endl;
        cout << "Number of seats: " << this->getNoSeats() << endl;
        if (seats != nullptr) {
            cout << "Seats: ";
            for (int i = 0; i < noSeats; i++)
                cout << seats[i] << ' ';
            cout << endl;
        }
    }
      
// Overloading operator = //

    void Location::operator=(const Location source) {
        this->zoneName = source.zoneName;
        this->noSeats = source.noSeats;
        this->hall = source.hall;

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


// Overloading operator >> //

    istream& operator>>(istream& input, Location& location)
    {
        cout << "-- New location --" << endl;
        cout << "Enter hall: ";
        int hall;
        input >> hall;
        location.setHall(hall);

        cout << "Enter zone (Normal = 1, First row = 2, VIP = 3): ";
        int zone;
        input >> zone;
        if (zone == 1)
            location.setZoneName(NORMAL);
        else if (zone == 2)
            location.setZoneName(FIRST_ROW);
        else if (zone == 3)
            location.setZoneName(VIP);

        cout << "Enter the number of seats: ";
        input >> location.noSeats;

        if (Location::COUNTER + location.noSeats > Location::MAX_SEATS)
            cout << "No seats available.";

        location.seats = new int[location.noSeats];
        cout << "Enter seat numbers: ";
        for (int i = 0; i < location.noSeats; i++) {
            input >> location.seats[i];
        }

        Location::COUNTER += location.noSeats;

        return input;
    }


// Overloading operator << //

    ostream& operator<<(ostream& output, const Location& location) {
        output << endl;
        output << "-- Location information --" << endl;
        output << "Hall: " << location.getHall() << endl;
        output << "Zone: " << location.getZoneName() << endl;
        output << "Number of seats: " << location.getNoSeats() << endl;
        if (location.seats != nullptr) {
            output << "Seats: ";
            for (int i = 0; i < location.noSeats; i++)
                output << location.seats[i] << ' ';
            output << endl;
        }
        return output;
    }


// Overloading operator [] //

    int& Location::operator[] (int index){
        if (this->seats != nullptr && index >= 0 && index < this->noSeats)
            return this->seats[index];
        else
            throw exception("Index out of bounds");
    }


// Overloading operator + //

    Location Location::operator+ (int newSeat){
        Location copy = *this;
        copy.addSeat(newSeat);
        return copy;
    }

    Location operator+ (int newSeat, Location location) {
        return location + newSeat;
    }


// Overloading operator ++ (pre and post) //

    Location Location::operator++ () {
        this->addSeat(this->seats[this->noSeats] + 1); //and the following seat number in the seat vector
        return *this;
    }

    Location Location::operator++ (int) {
        Location copy = *this;
        this->addSeat(this->seats[this->noSeats] + 1);
        return copy;
    }


// Overloading cast operator //

    Location::operator float() {
        return (float) this->noSeats;
    }


// Overloading operator ! //

     bool operator! (Location& location) {
         if (location.getNoSeats() == 0)
             return true;
         else 
             return false;
    }
    

// Overloading operator >= //

     bool Location::operator>= (Location& location) {
         if (this->noSeats >= location.noSeats)
             return true;
         else
             return false;
    }


// Overloading operator == //

     bool Location::operator== (Location& location) {
         if (this->hall == location.hall)
             return true;
         else
             return false;
     }