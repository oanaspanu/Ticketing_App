#include "Manager.h"

using namespace std;

class Menu {
protected:
    Manager** objects = nullptr;
    int noObjects = 0;
    
public:
    ~Menu();

    void showMenu();
    void addObject(Manager* newObject);
};
