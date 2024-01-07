#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Location.h"
#include "Event.h"
#include "Ticket.h"

class Manager {
public:
    vector<Event> events;
    vector<Location> locations;
    vector<Ticket> tickets;

    // Function to read data from binary files

    // Function to write data to binary files

    // Function to read data from text files

    // Function to write data to text files

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