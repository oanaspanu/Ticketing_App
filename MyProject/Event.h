#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

class Event {
private:
    string name = "";
    string date = "";

public:

 // Setters
    void setName(const string newName);

    void setDate(const string newDate);

// Getters
    string getName();

    string getDate();


// Class Constructor
    Event(string name, string date);

    Event(string name);

 // Copy Constructor
    Event(const Event& object);

 // Displaying information
    void printInfo();

 // Destructor
    ~Event();

};