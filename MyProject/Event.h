#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

enum EventType {UNSPECIFIED=1, CONCERT, MOVIE, SPORTS, THEATER};

class Event {
private:
    string name = "";
    string date = "";
    EventType type = EventType::UNSPECIFIED;

public:

 // Setters //

    void setName(const string newName);

    void setDate(const string newDate);

    void setType(const EventType newType);

// Getters //

    string getName() const;

    string getDate() const;

    string getType() const;


// Class Constructor //

    Event(string name, EventType type, string date);

    Event(string name, EventType type);


 // Copy Constructor //
    Event(const Event& object);

 // Destructor //
    ~Event();

 // Displaying information //
    void printInfo();

 // Overloading operator = //
    void operator=(const Event source);

};