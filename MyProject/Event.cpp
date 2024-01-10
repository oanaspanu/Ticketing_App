#include "Event.h"

int Event::MIN_DATE = 0;
int Event::MAX_DAY = 30; // convention 30 days per month
int Event::MAX_MONTH = 12;
int Event::MIN_YEAR = 2024;
int Event::MAX_YEAR = 2030;

void Event::addDays(int value) {
    if ((this->day + value) > MAX_DAY) {
        this->day = this->day + value - MAX_DAY;
        addMonths(1);
    }
    else
        this->day = this->day + value;
}

void Event::addMonths(int value) {
    if ((this->month + value) > MAX_MONTH) {
        this->month = this->month + value - MAX_MONTH;
        addYears(1);
    }
    else
        this->month = this->month + value;
}

void Event::addYears(int value) {
    if ((this->year + value) < MIN_YEAR && (this->year + value) > MAX_YEAR)
        throw exception("Invalid year.");

    this->year = this->year + value;
}

// Setters //

    void Event::setName(string newName) {
        if (!newName.empty())
            this->name = newName;
        else
            throw exception("Invalid data.");
    }

    void Event::setDay(int newDay) {
        if (newDay <= MIN_DATE || newDay > MAX_DAY)
            throw exception("Invalid day.");

        this->day = newDay;
    }

    void Event::setMonth(int newMonth) {
        if (newMonth <= MIN_DATE || newMonth > MAX_MONTH)
            throw exception("Invalid month.");

        this->month = newMonth;
    }

    void Event::setYear(int newYear) {
        if (newYear < MIN_YEAR || newYear > MAX_YEAR)
            throw exception("Invalid year.");

        this->year = newYear;
    }

    void Event::setType(EventType newType) {
        this->type = newType;
    }

    void Event::setDescription(string newDescription) {
        if (!newDescription.empty())
            this->description = newDescription;
        else
            throw exception("Invalid data.");
        
    }


// Getters //

    string Event::getName() const {
        return this->name;
    }

    int Event::getDay() const {
        return this->day;
    }

    int Event::getMonth() const {
        return this->month;
    }

    int Event::getYear() const {
        return this->year;
    }
   
    string Event::getType() const {
        switch (this->type) {
        case UNSPECIFIED:
            return "Unspecified";
        case CONCERT:
            return "Concert";
        case MOVIE:
            return "Movie";
        case THEATER:
            return "Theater";
        case SPORTS:
            return "Sports";
        default:
            return "Unknown";
        }
    }

    string Event::getDescription() const{
        return this->description;
    }


// Class Constructor //

    Event::Event() {

    }
    Event::Event(string name, EventType type, int day, int month, int year, string description) {
        this->setName(name);
        this->setDay(day);
        this->setMonth(month);
        this->setYear(year);
        this->setType(type);
        this->setDescription(description);
    }

    Event::Event(string name, EventType type, int day, int month, int year) {
        this->setName(name);
        this->setType(type);
        this->setDay(day);
        this->setMonth(month);
        this->setYear(year);
    }

// Copy Constructor //

    Event::Event(const Event& object) {
        this->name = object.name;
        this->day = object.day;
        this->month = object.month;
        this->year = object.year;
        this->type = object.type;
        this->description = object.description;
    }

// Displaying information //

    void Event::printInfo() {
        cout << endl;
        cout << "-- Event information --" << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Type: " << this->getType() << endl;
        if (this->day !=0 && this->month !=0 && this->year !=0)
            cout << "Date: " << this->getDay() << "/ " << this->getMonth() << "/ " << this->getYear() << endl;
        if(this->description != "")
            cout << "Description: " << this->getDescription() << endl;
    }

// Destructor //

    Event::~Event() {

    }

// Overloading operator = //

    void Event::operator=(const Event source) {
        this->name = source.name;
        this->day = source.day;
        this->month = source.month;
        this->year = source.year;
        this->type = source.type;
        this->description = source.description;
    }

// Overloading operator >> //
    istream& operator>>(istream& input, Event& event) {
        cout << "-- New event --" << endl;
        cout << "Enter name: ";
        string name;
        input >> name;
        event.setName(name);

        cout << "Enter day: ";
        int day;
        input >> day;
        event.setDay(day);

        cout << "Enter month: ";
        int month;
        input >> month;
        event.setMonth(month);


        cout << "Enter year: ";
        int year;
        input >> year;
        event.setYear(year);

        cout << "Enter event type (Unspecified=0, Concert=1, Movie=2, Sports=3, Theater=4): ";
        int type;
        input >> type;
        if(type == 0)
            event.setType(UNSPECIFIED);
        else if (type == 1)
            event.setType(CONCERT);
        else if (type == 2)
            event.setType(MOVIE);
        else if (type == 3)
            event.setType(SPORTS);
        else if(type == 4)
            event.setType(THEATER);

        cout << "Enter description: ";
        string description;
        input >> description;
        event.setDescription(description);

        return input;
    }

// Overloading operator << //
    ostream& operator<<(ostream& output, const Event& event) {
        output << endl;
        output << "-- Event information --" << endl;
        output << "Name: " << event.getName() << endl;
        output << "Type: " << event.getType() << endl;
        if (event.day != 0 && event.month != 0 && event.year != 0)
            output << "Date: " << event.getDay() << "/ " << event.getMonth() << "/ " << event.getYear() << endl;
        if (event.description != "")
            output << "Description: " << event.getDescription() << endl;

        return output;
       }

// Overloading operator + //
       Event Event::operator+ (int newDay) {
           Event copy = *this;
           copy.addDays(newDay);
           return copy;
    }

       Event operator+ (int newDay, Event event) {
           return event + newDay;
    }

// Overloading operator ++ (pre and post) //
       Event Event::operator++ () {
          this->addDays(1);
          return *this;
    }

       Event Event::operator++ (int) {
           Event copy = *this;
           this->addDays(1);
           return copy;
    }

// Overloading cast operator //
       Event::operator float() {
           return (float)this->day;
    }

// Overloading operator ! //
       bool operator! (Event& event) {
           if (event.day == 0)
               return true;
           else
               return false;
    }

// Overloading operator < //
       bool Event::operator < (Event& event) {
           if (this->year < event.year)
               return true;
           else 
               return false;

           if (this->year == event.year)
               if (this->month < event.month)
                   return true;
               else
                   return false;

           if (this->year == event.year && this->month == event.month)
               if (this->day < event.day)
                   return true;
               else
                   return false;
    }

// Overloading operator == //
       bool Event::operator== (Event& event) {
           if (this->year == event.year && this->month == event.month && this->day == event.day)
               return true;
           else
               return false;
    }

       // Read Binary Files 
       void Event::readBinaryFiles(string filename) {
           ifstream inputFile(filename, ios::in | ios::binary);
           if (!inputFile) {
               throw exception("Error opening binary file for reading");
           }

           inputFile.read((char*)&this->name, sizeof(string));
           inputFile.read((char*)&this->type, sizeof(EventType));
           inputFile.read((char*)&this->day, sizeof(int));
           inputFile.read((char*)&this->month, sizeof(int));
           inputFile.read((char*)&this->year, sizeof(int));
           inputFile.read((char*)&this->description, sizeof(string));

           inputFile.close();
       }

       // Write Binary Files
       void Event::writeBinaryFiles() {
           ofstream outputFile("event_data.bin", ios::out | ios::binary | ios::app);
           if (outputFile.is_open()) {
               outputFile.write((char*)&this->name, sizeof(string));
               outputFile.write((char*)&this->type, sizeof(EventType));
               outputFile.write((char*)&this->day, sizeof(int));
               outputFile.write((char*)&this->month, sizeof(int));
               outputFile.write((char*)&this->year, sizeof(int));
               outputFile.write((char*)&this->description, sizeof(string));
           }
           outputFile.close();
       }

       // Read Text Files 
       void Event::readTextFiles(string filename) {
           ifstream inputFile(filename, ios::in);

           if (!inputFile.is_open()) {
               cout << "\nError opening text file for reading. The file is not here.";
           }
           else {
               cout << "\nText file for reading is available.";
               while (!inputFile.eof()) {
                   string Name;
                   inputFile >> Name;
                   this->name = Name;

                   int Type;
                   inputFile >> Type;
                   if (type == 0)
                       this->setType(UNSPECIFIED);
                   else if (type == 1)
                       this->setType(CONCERT);
                   else if (type == 2)
                       this->setType(MOVIE);
                   else if (type == 3)
                       this->setType(SPORTS);
                   else if (type == 4)
                       this->setType(THEATER);

                   int Day;
                   inputFile >> Day;
                   this->day = Day;

                   int Month;
                   inputFile >> Month;
                   this->month = Month;

                   int Year;
                   inputFile >> Year;
                   this->year = Year;

                   string Description;
                   inputFile >> Description;
                   this->description = Description;

               }
           }
           inputFile.close();
       }

       // Write Text Files
       void Event::writeTextFiles() {
           ofstream outputFile("event_data.txt", ios::out | ios::app);
           if (outputFile.is_open()) {
               outputFile << this->name << " " << this->type << " " << this->day << " " << this->month <<" "<< this->year <<" "<< this->description << "\n";
           }
           outputFile.close();
       }