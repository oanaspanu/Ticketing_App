#include "Ticket.h"

int const Ticket::MAX_ID = 899;
int const Ticket::MIN_ID = 100;
int* Ticket::USED_IDS = nullptr;
int Ticket::NO_IDS = 0;

// Setters
    void Ticket::setId(){
        srand(time(0));
        int id = rand() % MAX_ID + MIN_ID;
        addId(id);
        this->id = id;
        }

    void Ticket::addId(const int newId) const{
        int* newArray = new int[NO_IDS + 1];

        for (int i = 0; i < NO_IDS; i++)
            newArray[i] = USED_IDS[i];
        newArray[NO_IDS] = newId;
        NO_IDS += 1;

        delete USED_IDS;
        USED_IDS = newArray;
    }

    void Ticket::setValidation(const int newId) {
        if (USED_IDS == nullptr)
            throw exception("No id registered.");

        for (int i = 0; i < NO_IDS; i++)
            if (newId == USED_IDS[i])
                this->isValid = 1;
        }

    void Ticket::setUserName(const string newUserName) {
        this->userName = newUserName;
    }

    void Ticket::setPriceType(const PriceType newPrice) {
        this->price = newPrice;
    }

    void Ticket::setTotalPrice(const Location& newLocation, const PriceType newPrice) {
        int p = 1;
        int noSeats = newLocation.getNoSeats();
        switch (newPrice) {
        case SIMPLE:
            p = 20;
            break;
        case VIP:
            p = 40;
            break;
        case DISCOUNT:
            p = 10;
            break;
        }
        this->totalPrice = noSeats * p;
    }


// Getters
    int Ticket::getId() const {
        return this->id;
    }

    string Ticket::getUserName() const {
        return this->userName;
    }

    string Ticket::getPrice() const {
        switch (this->price) {
        case SIMPLE:
            return "Simple";
        case PREMIUM:
            return "Premium";
        case DISCOUNT:
            return "Discount";
        }
    }

    int Ticket::getTotalPrice() const {
        return this->totalPrice;
    }

    string Ticket::getValidation() const {
        if (this->isValid == 1)
            return "true";
        else
            return "false";
    }


// Class Constructor
    Ticket::Ticket(string userName, PriceType price, Location& location, Event& event) :location(location), event(event) {
        setId();
        this->setUserName(userName);
        this->setPriceType(price);
        setValidation(this->id);
        this->setLocaton(location);
        this->setEvent(event);
        setTotalPrice(location, price); 
    }

    Ticket::Ticket(string userName, Location& location, Event& event) :location(location), event(event) {
        setId();
        this->setUserName(userName);
        setValidation(this->id);
        this->setLocaton(location);
        this->setEvent(event);
        setTotalPrice(location, this->price);
    }

// Class Copy Constructor 
    Ticket::Ticket(const Ticket& object) :location(location), event(event) {
        this->userName = object.userName;
        this->price = object.price;
        this->totalPrice = object.totalPrice;
        this->isValid = object.isValid;
        this->location = object.location;
        this->event = object.event;
    }

// Destructor
    Ticket::~Ticket() {}

// Displaying information
    

// Overloading operator =
   
    