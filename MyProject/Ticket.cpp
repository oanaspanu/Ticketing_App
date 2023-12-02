#include "Ticket.h"

const int PRICE_S = 20;
const int PRICE_P = 40;
const int PRICE_D = 10;
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

    void Ticket::setValidation() {
        if (USED_IDS == nullptr)
            throw exception("No id registered.");

        this->isValid = 0;
        for (int i = 0; i < NO_IDS; i++)
            if (this->id == USED_IDS[i])
                this->isValid = 1;
        }

    void Ticket::setUserName(const string newUserName) {
        if (!newUserName.empty())
            this->userName = newUserName;
        else
            throw exception("Invalid data.");
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

    Ticket::Ticket() {

    }

    Ticket::Ticket(string userName) {
        if (this->id == 0) {
            setId();
        }
        this->setUserName(userName);
        setValidation();
    }

    Ticket::Ticket(string userName, PriceType price) {
        if (this->id == 0) {
            setId();
        }
        this->setUserName(userName);
        this->setPriceType(price);
        setValidation();
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
        cout << "--Ticket information --" << endl;
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

// Overloading operator >> //
    istream& operator>>(istream& input, Ticket& ticket) {
        cout << "-- New ticket --" << endl;
        ticket.setId();

        cout << "Enter user name: ";
        string name;
        input >> name;
        ticket.setUserName(name);

        cout << "Enter price type (Simple = 20, Premium = 40, Discount = 10): ";
        int price;
        input >> price;
        if (price == PRICE_S)
            ticket.setPriceType(SIMPLE);
        else if (price == PRICE_P)
            ticket.setPriceType(PREMIUM);
        else if (price == PRICE_D)
            ticket.setPriceType(DISCOUNT);
        
        ticket.setValidation();

        return input;
    }

// Overloading operator << //
    ostream& operator<<(ostream& output, const Ticket& ticket) {
        output << endl;
        output << "-- Ticket information --" << endl;
        output << "ID: " << ticket.getId() << endl;
        output << "User name: " << ticket.getUserName() << endl;
        output << "Price: " << ticket.getPrice() << endl;
        output << "Is valid? " << (ticket.isValid ? "Yes" : "No") << endl;

        return output;
    }

// Overloading operator [] //
    char& Ticket::operator[] (int index) {

        if (this->userName != "" && index >= 0 && index < this->userName.length() )
            return this->userName[index];
        else
            throw exception("Index out of bounds");
    }

// Overloading operator + //
    Ticket Ticket::operator+ (string name) {
        string copy = this->getUserName();
        copy = copy + " " + name;
        return copy;
    }

    Ticket operator+ (string name, Ticket ticket) {
        string copy = ticket.getUserName();
        copy = name + " " + copy;
        return copy;
    }

// Overloading operator -- (pre and post) //
    Ticket Ticket::operator-- () {

        if (!this->userName.empty()) {
            this->userName.pop_back();
        }
            return *this;
    }

    Ticket Ticket::operator-- (int) {
        Ticket copy = *this;

        if (!this->userName.empty() )
            this->userName.pop_back();

        return copy;
    }

// Overloading operator ! //
    bool operator! (Ticket& ticket) {
        if (ticket.isValid == 1)
            return false;
        else
            return true;
    }

// Overloading operator > //
    bool Ticket::operator> (Ticket& ticket) {

        if ((float)this->price > (float)ticket.price)
            return true;
        else
            return false;
    }

// Overloading operator == //
    bool Ticket::operator== (Ticket& ticket) {
        if ((float)this->price == (float)ticket.price)
            return true;
        else
            return false;
    }
