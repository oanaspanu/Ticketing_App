#include <fstream>
#include <iostream>
#include "Location.h"
#include "Event.h"
#include "Ticket.h"

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

// Menu
void showMenu() {
    int choice;
    do {
        cout << "\n----- Menu -----\n";
        cout << "1. Add Event\n";
        cout << "2. Add Location\n";
        cout << "3. Add Ticket\n";
        cout << "4. Display Events\n";
        cout << "5. Display Locations\n";
        cout << "6. Display Tickets\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Add Event
            break;
        case 2:
            // Add Location
            break;
        case 3:
            // Add Ticket
            break;
        case 4:
            // Display Events
            break;
        case 5:
            // Display Locations
            break;
        case 6:
            // Display Tickets
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 7);
}


// Process files
void processFile(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        throw FileOpenException();
    }

    // Process file
    

    // Close the file
    inputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        processFile(argv[1]);
    }
    else {
        showMenu();
    }

    return 0;
}