#pragma once

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Location.h"
#include "Event.h"

using namespace std;

enum PriceType { SIMPLE = 20, PREMIUM = 40, DISCOUNT = 10 };

class Ticket {
private:
    static const int MAX_ID;
    static const int MIN_ID;
    static int* USED_IDS;
    static int NO_IDS;
    int id = 0;
    string userName = "";
    PriceType price = PriceType::SIMPLE;
    bool isValid = false;

    void setId();
    void setValidation(const int newId);

public:

    void addId(const int newId) const;

// Setters //

    void setUserName(const string userName);

    void setPriceType(const PriceType newPrice);



// Getters //

    int getId() const;

    string getUserName() const;

    string getPrice() const;

    string getValidation() const;


// Class Constructor //

    Ticket(string userName, PriceType price);

    Ticket(string userName);


// Class Copy Constructor //
    Ticket(const Ticket& object);


// Destructor //
    ~Ticket();


// Displaying information //
    void printInfo();

// Overloading operator = //
    void operator=(const Ticket source);
};