#include "Ticket.h"

int const Ticket::MAX_ID = 899;
int const Ticket::MIN_ID = 100;
int* Ticket::USED_IDS = nullptr;
int Ticket::NO_IDS = 0;


void Ticket::addId(const int newId) const {
    int* newArray = new int[NO_IDS + 1];

    for (int i = 0; i < NO_IDS; i++)
        newArray[i] = USED_IDS[i];
    newArray[NO_IDS] = newId;
    NO_IDS += 1;

    delete USED_IDS;
    USED_IDS = newArray;
}

// Setters //
    void Ticket::setId(){
        if (this->id == 0) {
            int id = rand() % MAX_ID + MIN_ID;
            addId(id);
            this->id = id;
        }
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


// Getters //
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

    string Ticket::getValidation() const {
        if (this->isValid == 1)
            return "true";
        else
            return "false";
    }


// Class Constructor //
    Ticket::Ticket(string userName) {
        if (this->id == 0) {
            setId();
        }
        this->setUserName(userName);
        setValidation(this->id);
    }

    Ticket::Ticket(string userName, PriceType price) {
        if (this->id == 0) {
            setId();
        }
        this->setUserName(userName);
        this->setPriceType(price);
        setValidation(this->id);
    }

// Class Copy Constructor //
    Ticket::Ticket(const Ticket& object){
        this->userName = object.userName;
        this->price = object.price;
        this->isValid = object.isValid;
    }

// Destructor //
    Ticket::~Ticket() {}

// Displaying information //
    

// Overloading operator = //
   