    #include "Manager.h"

    // Function to read data from binary files
    void Manager::readBinaryFiles() {
        std::ifstream eventFile("events.dat", ios::binary);
        std::ifstream locationFile("locations.dat", ios::binary);
        std::ifstream ticketFile("tickets.dat", ios::binary);

        if (!eventFile || !locationFile || !ticketFile) {
            throw exception ("Error opening binary files for reading.");
        }

        // Read events
        

        // Read locations
       

        // Read tickets
        

        eventFile.close();
        locationFile.close();
        ticketFile.close();
    }

    // Function to write data to binary files
    void Manager::writeBinaryFiles() {
        std::ofstream eventFile("events.dat", std::ios::binary);
        std::ofstream locationFile("locations.dat", std::ios::binary);
        std::ofstream ticketFile("tickets.dat", std::ios::binary);

        if (!eventFile || !locationFile || !ticketFile) {
            throw exception("Error opening binary files for writing.");
        }

        // Write events
        

        // Write locations
        

        // Write tickets
        

        eventFile.close();
        locationFile.close();
        ticketFile.close();
    }

    // Function to read data from text files
    void Manager::readTextFiles() {
        std::ifstream eventFile("events.txt");
        std::ifstream locationFile("locations.txt");
        std::ifstream ticketFile("tickets.txt");

        if (!eventFile || !locationFile || !ticketFile) {
            throw exception("Error opening text files for reading.");
        }

        // Read events

        // Read locations
        
        // Read tickets
  

        eventFile.close();
        locationFile.close();
        ticketFile.close();
    }

    // Function to write data to text files
    void Manager::writeTextFiles() {
        std::ofstream eventFile("events.txt");
        std::ofstream locationFile("locations.txt");
        std::ofstream ticketFile("tickets.txt");

        if (!eventFile || !locationFile || !ticketFile) {
            throw exception("Error opening text files for writing.");
        }

        // Write events
       

        // Write locations
        

        // Write tickets
       
        eventFile.close();
        locationFile.close();
        ticketFile.close();
    }

    // Add Event function
    void Manager::addEvent() {
        Event** newEvents = new Event * [noEvents + 1];
        for (int i = 0; i < noEvents; ++i) {
            newEvents[i] = events[i];
        }

        newEvents[noEvents] = new Event;
        cin >> *newEvents[noEvents];

        delete[] events;
        events = newEvents;
        ++noEvents;
    }

    // Add Location function
    void Manager::addLocation() {
        Location* newLocations = new Location[noLocations + 1];
        for (int i = 0; i < noLocations; ++i) {
            newLocations[i] = locations[i];
        }

        cin >> newLocations[noLocations];

        delete[] locations;
        locations = newLocations;
        ++noLocations;
    }

    // Add Ticket function
    void Manager::addTicket() {
        Ticket** newTickets = new Ticket * [noTickets + 1];
        for (int i = 0; i < noTickets; ++i) {
            newTickets[i] = tickets[i];
        }

        newTickets[noTickets] = new Ticket;
        cin >> *newTickets[noTickets];

        delete[] tickets;
        tickets = newTickets;
        ++noTickets;
    }

    // Display Events function
    void Manager::displayEvents() {
        for (int i = 0; i < noEvents; ++i) {
            cout << *events[i] << "\n";
        }
    }

    // Display Locations function
    void Manager::displayLocations() {
        for (int i = 0; i < noLocations; ++i) {
            cout << locations[i] << "\n";
        }
    }

    // Display Tickets function
    void Manager::displayTickets() {
        for (int i = 0; i < noTickets; ++i) {
            cout << *tickets[i] << "\n";
        }
    }
