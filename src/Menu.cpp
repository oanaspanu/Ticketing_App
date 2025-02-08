#include "Menu.h"
#include "Location.h"
#include "Event.h"
#include "Ticket.h"

Menu::~Menu() {
    delete[] objects;
}

void Menu::showMenu() {
    int choice;
    int type;
    string Name;
    int Id;
    Event event;
    Location location;
    Ticket ticket;

    do {
        cout << "\n----- Menu -----\n";
        cout << "\nAdmin (0) or User (1)?\n";
        cout << "Enter your choice: ";
        cin >> type;

        if (type == 0) {
            cout << "1. Display Events\n";
            cout << "2. Display Locations\n";
            cout << "3. Display Tickets\n";
            cout << "4. Add Object\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
        }
        else {
            cout << "1. Display Events\n";
            cout << "2. Display Locations\n";
            cout << "3. Display Tickets\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            cout << "Enter event name: ";
            cin >> Name;
            for (int i = 0; i < noObjects; i++)
                if (event.getName() == Name)
                    event.printInfo();
                else
                    cout << "\nEvent not found.\n";
            if (noObjects == 0)
                cout << "\nEvent not found.\n";
            break;
        case 2:
            cout << "Enter user name: ";
            cin >> Name;
            for (int i = 0; i < noObjects; i++)
                if (location.getUserName() == Name)
                    location.printInfo();
                else
                    cout << "\nLocation not found.\n";
            if (noObjects == 0)
                cout << "\nLocation not found.\n";
            break;
        case 3:
            cout << "Enter id: ";
            cin >> Id;
            for (int i = 0; i < noObjects; i++)
                if (ticket.getId() == Id)
                    ticket.printInfo();
                else
                    cout << "\nTicket not found.\n";
            if(noObjects == 0)
                cout << "\nTicket not found.\n";

            break;
        case 4:
            type = 0;
            cout << "What type of object? Select a number: ";
            cout << "\n1.Location";
            cout << "\n2.Event";
            cout << "\n3.Ticket\n";
            cin >> type;
            if (type == 1) {
                cin >> location;
                addObject(&location);
            }
            else if (type == 2) {
                cin >> event;
                addObject(&event);
            }
            else if (type == 3) {
                cin >> ticket;
                addObject(&ticket);
            }
            else
                cout << "Invalid number.";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

void Menu::addObject (Manager* newObject) {
    Manager** newArray = new Manager * [noObjects + 1];

    for (int i = 0; i < noObjects; ++i) {
        newArray[i] = objects[i];
    }

    newArray[noObjects] = newObject;
    noObjects += 1;

    delete[] objects;
    objects = newArray;
}
