#include "Event.h"

// Setters //

    void Event::setName(string newName) {
        this->name = newName;
    }

    void Event::setDate(string newDate) {
        this->date = newDate;
    }

    void Event::setType(EventType newType) {
        this->type = newType;
    }

// Getters //

    string Event::getName() const {
        return this->name;
    }

    string Event::getDate() const {
        return this->date;
    }
   
    string Event::getType() const {
        switch (this->type) {
        case UNSPECIFIED:
            return "Unspecified";
        case CONCERT:
            return "Concert";
        case MOVIE:
            return "Movie";
        case THEATER:
            return "Theater";
        case SPORTS:
            return "Sports";
        }
    }

// Class Constructor //

    Event::Event(string name, EventType type, string date) {
        this->setName(name);
        this->setDate(date);
        this->setType(type);
    }

    Event::Event(string name, EventType type) {
        this->setName(name);
        this->setType(type);
    }

// Copy Constructor //

    Event::Event(const Event& object) {
        this->name = object.name;
        this->date = object.date;
        this->type = object.type;
    }

// Displaying information //

    void Event::printInfo() {
        cout << endl;
        cout << "Event information:" << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Type: " << this->getType() << endl;
        if(this->date != "")
            cout << "Date: " << this->getDate() << endl;
    }

// Destructor //

    Event::~Event() {

    }

// Overloading operator = //

    void Event::operator=(const Event source) {
        this->name = source.name;
        this->date = source.date;
        this->type = source.type;
    }