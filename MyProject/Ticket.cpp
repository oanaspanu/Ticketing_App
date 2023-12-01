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
            bool ok;
            int newId;
            do {

                ok = 0;
                newId = rand() % MAX_ID + MIN_ID;
                for (int i = 0; i < NO_IDS; i++)
                    if (newId == USED_IDS[i])
                        ok = 1;
            } while (ok);
            addId(newId);
            this->id = newId;
        }
    }

    void Ticket::setValidation(const int newId) {
        if (USED_IDS == nullptr)
            throw exception("No id registered.");

        this->isValid = 0;
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
        this->id = object.id;
        this->userName = object.userName;
        this->price = object.price;
        this->isValid = object.isValid;
    }

// Destructor //
    Ticket::~Ticket() {}


// Displaying information //

    void Ticket::printInfo() {
        cout << endl;
        cout << "Ticket information:" << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "User name: " << this->getUserName() << endl;
        cout << "Price: " << this->getPrice() << endl;
        cout << "Is valid? " << (this->isValid ? "Yes" : "No") << endl;
    }

// Overloading operator = //

    void Ticket::operator=(const Ticket source) {
        this->setId();
        this->userName = source.userName;
        this->price = source.price;
        this->isValid = source.isValid;
    }