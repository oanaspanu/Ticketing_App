#include <fstream>
#include <iostream>
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include "Menu.h"

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
void processFile(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        throw FileOpenException();
    }

    // Process file
    

    inputFile.close();
}

int main(int argc, char* argv[]) {
    Menu menu;

    if (argc > 1) {
        processFile(argv[1]);
    }
    else {
        menu.showMenu();
    }

    return 0;
}