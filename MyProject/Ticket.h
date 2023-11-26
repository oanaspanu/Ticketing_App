#pragma once

#include <stdio.h>
#include <iostream>
#include "Location.h"
#include "Event.h"

using namespace std;

enum PriceType { SIMPLE = 20, PREMIUM = 40, DISCOUNT = 10 };

class Ticket {
private:
    int id = 0;
    string userName = "";
    string event = "";
    PriceType type = PriceType::SIMPLE;
    int totalPrice = 0;
    bool isValid = false;
    Location location;
    Event event;

public:

    // Setters


    // Getters



    // Class Constructor


    // Copy Constructor


    // Destructor


};