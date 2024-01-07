#include "Manager.h"
    // Function to read data from binary files
   
    // Function to write data to binary files

    // Function to read data from text files

    // Function to write data to text files

    // Add Event function
    void Manager::addEvent() {
        Event event;
        cin >> event; 
        events.push_back(event);
    }

    // Add Location function
    void Manager::addLocation() {
        Location location;
        cin >> location; 
        locations.push_back(location);
    }

    // Add Ticket function
    void Manager::addTicket() {
        Ticket ticket;
        cin >> ticket; 
        tickets.push_back(ticket);
    }

    // Display Events function
    void Manager::displayEvents() {
        cout << "-------------------------\n";
        cout << "      Display Events\n";
        cout << "-------------------------\n";
        for (const auto& event : events) {
            cout<< event;
            cout << "-------------------------\n";
        }
    }

    // Display Locations function
    void Manager::displayLocations() {
        cout << "-------------------------\n";
        cout << "      Display Locations\n";
        cout << "-------------------------\n";
        for (const auto& location : locations) {
            cout << location;
            cout << "-------------------------\n";
        }
    }

    // Display Tickets function
    void Manager::displayTickets() {
        cout << "-------------------------\n";
        cout << "      Display Tickets\n";
        cout << "-------------------------\n";
        for (const auto& ticket : tickets) {
            cout << ticket;
            cout << "-------------------------\n";
        }
