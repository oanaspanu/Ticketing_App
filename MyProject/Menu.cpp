#include "Menu.h";


void Menu::showMenu() {
        int choice;
        do {
            std::cout << "\n----- Menu -----\n";
            std::cout << "1. Add Event\n";
            std::cout << "2. Add Location\n";
            std::cout << "3. Add Ticket\n";
            std::cout << "4. Display Events\n";
            std::cout << "5. Display Locations\n";
            std::cout << "6. Display Tickets\n";
            std::cout << "7. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                addEvent();
                break;
            case 2:
                addLocation();
                break;
            case 3:
                addTicket();
                break;
            case 4:
                displayEvents();
                break;
            case 5:
                displayLocations();
                break;
            case 6:
                displayTickets();
                break;
            case 7:
                saveDataToFiles(); 
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 7);
    }

    void Menu::saveDataToFiles() {

    }