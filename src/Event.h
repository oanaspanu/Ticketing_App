#pragma once

#include <stdio.h>
#include <iostream>
#include "Manager.h"

using namespace std;

enum EventType {UNSPECIFIED, CONCERT, MOVIE, SPORTS, THEATER};

class Event : public Manager {
private:
    static int MIN_DATE;
    static int MAX_DAY;
    static int MAX_MONTH;
    static int MIN_YEAR;
    static int MAX_YEAR;
    string name = "";
    int day = 0;
    int month = 0;
    int year = 0;
    EventType type = EventType::UNSPECIFIED;
    string description = "";

public:

    void addDays(int newDays);

    void addMonths(int newMonths);

    void addYears(int newYears);

 // Setters //

    void setName(const string newName);

    void setDay (const int newDay);

    void setMonth(const int newMonth);

    void setYear(const int newYear);

    void setType(const EventType newType);

    void setDescription(const string newDescription);


// Getters //

    string getName() const;

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    string getType() const;

    string getDescription() const;


// Class Constructor //

    Event();

    Event(string name, EventType type, int day, int month, int year, string description);

    Event(string name, EventType type, int day, int month, int year);


 // Copy Constructor //
    Event(const Event& object);

 // Destructor //
    ~Event();

 // Displaying information //
    void printInfo();

 // Overloading operator = //
    void operator=(const Event source);

// Overloading operator >> //
    friend istream& operator>>(istream& input, Event& event);

// Overloading operator << //
    friend ostream& operator<<(ostream& output, const Event& event);

// Overloading operator + //
    Event operator+ (int newDay);

    friend Event operator+ (int newDay, Event event);

// Overloading operator ++ (pre and post) //
    Event operator++ ();

    Event operator++ (int);

// Overloading cast operator //
    explicit operator float();

// Overloading operator ! //
    friend bool operator! (Event& event);

// Overloading operator < //
    bool operator< (Event& event);

// Overloading operator == //
    bool operator== (Event& event);

    // Read Binary Files 
    void readBinaryFiles(string filename);

    // Write Binary Files
    void writeBinaryFiles();

    // Read Text Files 
    void readTextFiles(string filename);

    // Write Text Files
    void writeTextFiles();
};