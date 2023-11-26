#include "Event.h"

// Setters
    void Event::setName(string newName) {
        this->name = newName;
    }

    void Event::setDate(string newDate) {
        this->date = newDate;
    }

// Getters
    string Event::getName() {
        return this->name;
    }

    string Event::getDate() {
        return this->date;
    }
   

// Class Constructor
    Event::Event(string name, string date) {
        this->setName(name);
        this->setDate(date);
    }

    Event::Event(string name) {
        this->setName(name);
    }

// Copy Constructor
    Event::Event(const Event& object) {

    }

// Displaying information
    void Event::printInfo() {
        cout << endl;
        cout << "Event name: " << this->getName() << endl;
        if(this->date != "")
            cout << "Date of the event: " << this->getDate() << endl;
    }

// Destructor
    Event::~Event() {

    }