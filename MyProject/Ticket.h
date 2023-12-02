#pragma once

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

enum PriceType { SIMPLE = 20, PREMIUM = 40, DISCOUNT = 10 };

class Ticket {
private:
    static const int PRICE_S;
    static const int PRICE_P;
    static const int PRICE_D;
    static const int MAX_ID;
    static const int MIN_ID;
    static int* USED_IDS;
    static int NO_IDS;
    int id = 0;
    string userName = "";
    PriceType price = PriceType::SIMPLE;
    bool isValid = false;

    void setId();
    void setValidation();

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

    Ticket();

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

// Overloading operator >> //
    friend istream& operator>>(istream& input, Ticket& ticket);

// Overloading operator << //
    friend ostream& operator<<(ostream& output, const Ticket& ticket);

// Overloading operator [] //
    char& operator[] (int index);

// Overloading operator + //
    Ticket operator+ (string name);

    friend Ticket operator+ (string name, Ticket ticket);

// Overloading operator ++ (pre and post) //
    Ticket operator-- ();

    Ticket operator-- (int);

// Overloading operator ! //
    friend bool operator! (Ticket& ticket);

// Overloading operator > //
    bool operator> (Ticket& ticket);

// Overloading operator == //
    bool operator== (Ticket& ticket);

};