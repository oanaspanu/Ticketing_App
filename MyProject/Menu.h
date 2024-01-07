#pragma once
#include "Manager.h"
#include <iostream>

class Menu : public Manager  {
public:
    void showMenu();

private:
    void writeDataToFiles();

};
