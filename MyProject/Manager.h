#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Location.h"
#include "Event.h"
#include "Ticket.h"

class Manager {
public:
    Event** events = nullptr;
    Location* locations = nullptr;
    Ticket** tickets = nullptr;
    int noEvents = 0, noLocations = 0, noTickets = 0;

    // Function to read data from binary files
    void readBinaryFiles();

    // Function to write data to binary files
    void writeBinaryFiles();

    // Function to read data from text files
    void readTextFiles();

    // Function to write data to text files
    void writeTextFiles();

    // Add Event function
    void addEvent();

    // Add Location function
    void addLocation();

    // Add Ticket function
    void addTicket();

    // Display Events function
    void displayEvents();

    // Display Locations function
    void displayLocations();

    // Display Tickets function
    void displayTickets();
};