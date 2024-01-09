#include"Manager.h"

// Add object
void Manager::addObject(Manager* newObject) {
    Manager** newArray = new Manager * [noObjects + 1];

    for (int i = 0; i < noObjects; ++i) {
        newArray[i] = objects[i];
    }

    newArray[noObjects] = newObject;
    noObjects += 1;

    delete[] objects;
    objects = newArray;
}
