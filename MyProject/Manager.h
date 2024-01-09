#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Location.h"
#include "Event.h"
#include "Ticket.h"

class Manager {
protected:
    Manager** objects = nullptr;
    int noObjects = 0;

public:

    // Function to read data from binary files
    virtual void readBinaryFiles() = 0;

    // Function to write data to binary files
    virtual void writeBinaryFiles() = 0;

    // Function to read data from text files
    virtual void readTextFiles() = 0;

    // Function to write data to text files
    virtual void writeTextFiles() = 0;

    // Add object
    void addObject(Manager* newObject);

    // Display object
    virtual void printInfo() = 0;
};
