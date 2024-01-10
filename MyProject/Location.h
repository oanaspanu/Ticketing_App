#pragma once

#include <stdio.h>
#include <iostream>
#include "Manager.h"

using namespace std;

enum Zone { NORMAL = 1, FIRST_ROW, VIP };

class Location : public Manager {
private:
    static int MAX_SEATS;
    static int MAX_HALLS;
    static int COUNTER;
    string userName = "";
    int noSeats = 0;
    int* seats = nullptr;
    Zone zoneName = Zone::NORMAL;
    int hall = 0;

public:

    void addSeat(int newSeat);

// Setters //

    void setUserName(const string userName);

    void setSeats(const int newNoSeats, const int* newSeats);

    void setZoneName(const Zone newZoneName);

    void setHall(const int newHall);


// Getters //

    string getUserName() const;

    int* getSeats() const;

    int getNoSeats() const;

    string getZoneName() const;

    int getHall() const;


// Class Constructor //

    Location();

    Location(string userName, int hall, Zone zoneName, int noSeats, int* seats);

    Location(string userName, int hall, int noSeats, int* seats);


// Class Copy Constructor  //
    Location(const Location& object);
 
// Destructor //
    ~Location();

// Displaying information //
    void printInfo();

// Overloading operator = //
    void operator=(const Location source);

// Overloading operator >> //
    friend istream& operator>>(istream& input, Location& location);

// Overloading operator << //
    friend ostream& operator<<(ostream& output, const Location& location);

// Overloading operator [] //
    int& operator[] (int index);

// Overloading operator + //
    Location operator+ (int newSeat);

    friend Location operator+ (int newSeat, Location location);

// Overloading operator ++ (pre and post) //
    Location operator++ ();

    Location operator++ (int);

// Overloading cast operator //
    explicit operator float();

// Overloading operator ! //
    friend bool operator! (Location& location);

// Overloading operator >= //
    bool operator>= (Location& location);

// Overloading operator == //
    bool operator== (Location& location);

    // Function to read data from binary files
    void readBinaryFiles(string filename);

    // Function to write data to binary files
    void writeBinaryFiles();

    // Function to read data from text files
    void readTextFiles(string filename);

    // Function to write data to text files
    void writeTextFiles();

};

