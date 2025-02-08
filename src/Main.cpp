#include <fstream>
#include <iostream>
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include "Menu.h"
#include "Manager.h"

using namespace std;

// Custom exception classes
class FileOpenException : public exception {
public:
    const char* what() const noexcept override {
        return "Unable to open file";
    }
};

class FileProcessingException : public exception {
public:
    const char* what() const noexcept override {
        return "Error processing file";
    }
};

// Process files
void processFile(const string& file) {
    ifstream inputFile(file);
    int choice;
    Event event;
    Location location;
    Ticket ticket;
    Menu menu;

    if (!inputFile.is_open()) {
        throw FileOpenException();
    }

    cout << "What does the file contains?";
    cout << "\n1.Location";
    cout << "\n2.Event";
    cout << "\n3.Ticket";
    cin >> choice;
    if (choice == 1) {
        location.readTextFiles(file);
        cout << location;
    }
    else if (choice == 2) {
        event.readTextFiles(file);
        cout << event;
    }
    else if (choice == 3) {
        ticket.readTextFiles(file);
        cout << ticket;
    }
    else
        cout << "Invalid number.";
   
    inputFile.close();
}


int main(int argc, char* argv[]) {
  
    if (argc > 1) {
        processFile(argv[1]);
    }
    else {
        Menu menu;
        menu.showMenu();
    }

    return 0;
}