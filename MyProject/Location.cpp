#include <iostream>

using namespace std;

enum Zone { GENERAL = 1, FIRST_ROW, VIP };

class Location {
private:
    static int maxSeats;
    static int COUNTER;
    int rows = 0;
    int* seatsPerRow = nullptr;
    Zone zoneName;

public:

    // Class Constructor
    Location(Zone zoneName, int rows, int* seats) {
        this->zoneName = zoneName;  //receve the zone
        this->rows = rows;          //receve the row
        
        if (rows <= 0 || seats == nullptr) {     //if the row number or seats number is incorect
            throw exception("Invalid data.");
        }


        if (COUNTER == maxSeats)                // if all the seats were taken
            cout << "No more seats available.";
        else  
        {
            COUNTER += rows;
            seatsPerRow = new int[rows];
            for (int i = 0; i < rows; ++i) {
                seatsPerRow[i] = seats[i];
            }
        }
    }


    // Copy Constructor
    Location(const Location& object) {
        this->rows = object.rows;
        this->zoneName = object.zoneName;

        seatsPerRow = new int[rows];
        for (int i = 0; i < rows; ++i) {
            seatsPerRow[i] = object.seatsPerRow[i];
        }
    }

    // Destructor
    ~Location() {
        delete[] seatsPerRow;
    }
    

};

int Location::maxSeats = 500;
int Location::COUNTER = 0;
